#include "PluginProcessor.hpp"
#include <cmath>
#include <algorithm>
#include <cstring>

namespace wbs::m7880 {

namespace {
    constexpr float kPi = 3.14159265358979323846f;
    constexpr float kTwoPi = 6.28318530717958647692f;

    const char* const kDefaultMnemonics[kNumIntercomKeys] = {
        "DIR ", // Key 1: Director
        "PROD", // Key 2: Producer
        "CAM1", // Key 3: Camera 1
        "CAM2", // Key 4: Camera 2
        "SND ", // Key 5: Sound / Audio
        "IFB1", // Key 6: Talent IFB
        "CR1 ", // Key A: Control Room 1
        "STU1", // Key B: Studio 1 Floor
        "HOST", // Key C: Talent Host
        "ALL "  // Key D: All Call / Page
    };
}

M7880PluginProcessor::M7880PluginProcessor()
    : engine::SharedPluginFrame("Ward-Beck M7880 Intercom Panel & IFB Station", "M7880") {
    // Intercom communication runs at native or 2x rate for low latency
    defaultOversampling_ = engine::OversamplingRate::None;

    // Initialize default keys
    for (size_t i = 0; i < kNumIntercomKeys; ++i) {
        std::strncpy(keys_[i].mnemonic, kDefaultMnemonics[i], 4);
        keys_[i].mnemonic[4] = '\0';
        keys_[i].talkActive = false;
        keys_[i].listenActive = (i == 0 || i == 1); // Default monitoring Director & Producer
        keys_[i].greenTally = keys_[i].listenActive;
        keys_[i].redTally = false;
    }
}

void M7880PluginProcessor::prepareModule(double hostRate, double /*oversampledRate*/, size_t /*maxBlockSize*/, size_t numChannels) {
    sampleRate_ = hostRate;
    numChannels_ = numChannels;

    micTransformer_.prepare(sampleRate_);

    for (size_t stage = 0; stage < 2; ++stage) {
        hpfCores_[stage].prepare(sampleRate_);
        lpfCores_[stage].prepare(sampleRate_);
    }
    presencePeakCore_.prepare(sampleRate_);

    for (size_t ch = 0; ch < engine::kMaxChannels; ++ch) {
        speakerResonanceCore_[ch].prepare(sampleRate_);
        speakerShelfCore_[ch].prepare(sampleRate_);
    }

    currentDuckGain_ = 1.0f;
    currentDuckDb_ = 0.0f;
    duckHoldSamplesRemaining_ = 0;
    gateOpen_ = false;
    gateEnvelope_ = 0.0f;
    gateGain_ = 0.0f;

    callChimeActive_ = false;
    callChimeSamplesRemaining_ = 0;
    callChimeTotalSamples_ = static_cast<size_t>(sampleRate_ * 0.400); // 400 ms chime

    clickSamplesRemaining_ = 0;
    clickSampleVal_ = 0.0f;

    updateParametersFromHost();
}

void M7880PluginProcessor::releaseModule() {
    micTransformer_.reset();
    for (size_t stage = 0; stage < 2; ++stage) {
        hpfCores_[stage].reset();
        lpfCores_[stage].reset();
    }
    presencePeakCore_.reset();

    for (size_t ch = 0; ch < engine::kMaxChannels; ++ch) {
        speakerResonanceCore_[ch].reset();
        speakerShelfCore_[ch].reset();
    }
}

void M7880PluginProcessor::updateParametersFromHost() noexcept {
    masterVolLin_ = std::pow(10.0f, masterVolumeDb_ / 20.0f);
    micGainLin_ = std::pow(10.0f, micGainDb_ / 20.0f);
    sidetoneLin_ = std::pow(10.0f, sidetoneDb_ / 20.0f);

    if (duckingDepthDb_ <= -59.0f) {
        duckingDepthLin_ = 0.0f; // Full Mute
    } else {
        duckingDepthLin_ = std::pow(10.0f, duckingDepthDb_ / 20.0f);
    }

    gateThresholdLin_ = std::pow(10.0f, gateThresholdDb_ / 20.0f);

    // Ballistics time constants
    // Attack: fast ~5 ms ramp down
    const float attSec = 0.005f;
    duckAttackCoeff_ = 1.0f - std::exp(-1.0f / (static_cast<float>(sampleRate_) * attSec));

    // Release: smooth variable restoration (50 to 2000 ms)
    const float relSec = std::max(0.05f, duckingReleaseMs_ * 0.001f);
    duckReleaseCoeff_ = 1.0f - std::exp(-1.0f / (static_cast<float>(sampleRate_) * relSec));

    // Update Comms Filter coefficients
    if (commsMode_ == CommsFilterMode::Telecom) {
        // 300 Hz HPF (18 dB/oct) + 3.4 kHz LPF (18 dB/oct) + 2.0 kHz Presence Peak (+3.5 dB)
        hpfCores_[0].update(300.0, 1.0, 0.0, engine::FilterType::HighPass18dB);
        hpfCores_[1].update(300.0, 0.5, 0.0, engine::FilterType::HighPass18dB);
        lpfCores_[0].update(3400.0, 1.0, 0.0, engine::FilterType::LowPass18dB);
        lpfCores_[1].update(3400.0, 0.5, 0.0, engine::FilterType::LowPass18dB);
        presencePeakCore_.update(2000.0, 1.8, 3.5, engine::FilterType::PeakingBell);
    } else if (commsMode_ == CommsFilterMode::Broadcast) {
        // 150 Hz HPF + 7.5 kHz LPF + 2.2 kHz Presence (+2.0 dB)
        hpfCores_[0].update(150.0, 0.9, 0.0, engine::FilterType::HighPass18dB);
        hpfCores_[1].update(150.0, 0.5, 0.0, engine::FilterType::HighPass18dB);
        lpfCores_[0].update(7500.0, 0.9, 0.0, engine::FilterType::LowPass18dB);
        lpfCores_[1].update(7500.0, 0.5, 0.0, engine::FilterType::LowPass18dB);
        presencePeakCore_.update(2200.0, 1.4, 2.0, engine::FilterType::PeakingBell);
    } else {
        // Flat / Bypass filter
        hpfCores_[0].update(20.0, 0.707, 0.0, engine::FilterType::HighPass18dB);
        hpfCores_[1].update(20.0, 0.707, 0.0, engine::FilterType::HighPass18dB);
        lpfCores_[0].update(20000.0, 0.707, 0.0, engine::FilterType::LowPass18dB);
        lpfCores_[1].update(20000.0, 0.707, 0.0, engine::FilterType::LowPass18dB);
        presencePeakCore_.update(1000.0, 1.0, 0.0, engine::FilterType::PeakingBell);
    }

    // Station Speaker Cabinet Biquad: 980 Hz resonance Q=2.4 (+6.0 dB), high shelf cut (-8 dB above 4.5 kHz)
    for (size_t ch = 0; ch < engine::kMaxChannels; ++ch) {
        speakerResonanceCore_[ch].update(980.0, 2.4, 6.0, engine::FilterType::PeakingBell);
        speakerShelfCore_[ch].update(4500.0, 0.707, -8.0, engine::FilterType::HighShelf);
    }
}

void M7880PluginProcessor::processModuleSlice(engine::AudioBlock& slice) noexcept {
    if (slice.numSamples == 0 || slice.numChannels == 0) return;

    if (bypass_) {
        currentDuckDb_ = 0.0f;
        currentDuckGain_ = 1.0f;
        return;
    }

    float* prgL = (slice.numChannels > 0) ? slice.getChannelPointer(0) : nullptr;
    float* prgR = (slice.numChannels > 1) ? slice.getChannelPointer(1) : prgL;
    const float* sideL = (slice.numChannels > 2) ? slice.getChannelPointer(2) : nullptr;
    const float* sideR = (slice.numChannels > 3) ? slice.getChannelPointer(3) : nullptr;

    // Check if any talk key is currently active
    bool anyKeyTalkActive = false;
    for (size_t k = 0; k < kNumIntercomKeys; ++k) {
        if (keys_[k].talkActive) {
            anyKeyTalkActive = true;
            keys_[k].redTally = true;
        } else {
            keys_[k].redTally = false;
        }
        keys_[k].greenTally = keys_[k].listenActive;
    }

    const size_t duckHoldMax = static_cast<size_t>(sampleRate_ * 0.100); // 100 ms hold

    const double invSampleRate = 1.0 / sampleRate_;
    const double chimeInc1 = 1000.0 * kTwoPi * invSampleRate;
    const double chimeInc2 = 2000.0 * kTwoPi * invSampleRate;

    // Speech generator pitch increments (180 Hz base voice + formants at 450 Hz and 1800 Hz)
    const double synthInc1 = 180.0 * kTwoPi * invSampleRate;
    const double synthInc2 = 450.0 * kTwoPi * invSampleRate;
    const double synthInc3 = 1800.0 * kTwoPi * invSampleRate;
    const double synthLfoInc = 3.5 * kTwoPi * invSampleRate; // Speech cadence modulation

    for (size_t i = 0; i < slice.numSamples; ++i) {
        // -------------------------------------------------------------
        // 1. Obtain Raw Microphone Signal
        // -------------------------------------------------------------
        float rawMic = 0.0f;
        if (micSource_ == MicSourceMode::Sidechain && sideL != nullptr) {
            rawMic = (sideR != nullptr) ? 0.5f * (sideL[i] + sideR[i]) : sideL[i];
        } else if (micSource_ == MicSourceMode::MainLeft && prgL != nullptr) {
            rawMic = prgL[i];
        } else if (micSource_ == MicSourceMode::TestGenerator) {
            // Generate synthetic voice when any Talk key is engaged or call is active
            if (anyKeyTalkActive || callChimeActive_) {
                synthPhase1_ += synthInc1;
                synthPhase2_ += synthInc2;
                synthPhase3_ += synthInc3;
                synthLfoPhase_ += synthLfoInc;
                if (synthPhase1_ >= kTwoPi) synthPhase1_ -= kTwoPi;
                if (synthPhase2_ >= kTwoPi) synthPhase2_ -= kTwoPi;
                if (synthPhase3_ >= kTwoPi) synthPhase3_ -= kTwoPi;
                if (synthLfoPhase_ >= kTwoPi) synthLfoPhase_ -= kTwoPi;

                const float voiceMod = 0.5f + 0.5f * std::sin(static_cast<float>(synthLfoPhase_));
                rawMic = 0.35f * voiceMod * (
                    0.5f * std::sin(static_cast<float>(synthPhase1_)) +
                    0.3f * std::sin(static_cast<float>(synthPhase2_)) +
                    0.2f * std::sin(static_cast<float>(synthPhase3_))
                );
            } else {
                rawMic = 0.0f;
            }
        }

        // -------------------------------------------------------------
        // 2. Preamp Gain & Discrete Transformer Warmth
        // -------------------------------------------------------------
        float micPre = rawMic * micGainLin_;
        micPre = micTransformer_.processSample(micPre, 1.0f, 0.12f);

        // -------------------------------------------------------------
        // 3. Noise Gate & Downward Expander
        // -------------------------------------------------------------
        const float micAbs = std::abs(micPre);
        // Fast detector
        if (micAbs > gateEnvelope_) {
            gateEnvelope_ = micAbs;
        } else {
            gateEnvelope_ = (gateEnvelope_ * 0.999f) + (micAbs * 0.001f);
        }

        const bool shouldOpen = (gateEnvelope_ >= gateThresholdLin_) || (micSource_ == MicSourceMode::TestGenerator && anyKeyTalkActive);
        if (shouldOpen) {
            gateOpen_ = true;
            // 1 ms smooth gate opening
            gateGain_ += (1.0f - gateGain_) * 0.05f;
        } else {
            // 100 ms smooth decay to -40 dB (0.01)
            gateGain_ += (0.01f - gateGain_) * 0.0008f;
            if (gateGain_ < 0.015f) gateOpen_ = false;
        }

        float micGated = micPre * gateGain_;

        // -------------------------------------------------------------
        // 4. Speech Bandpass & Presence Equalization
        // -------------------------------------------------------------
        if (commsMode_ != CommsFilterMode::Flat) {
            micGated = hpfCores_[0].processSample(micGated);
            micGated = hpfCores_[1].processSample(micGated);
            micGated = lpfCores_[0].processSample(micGated);
            micGated = lpfCores_[1].processSample(micGated);
            micGated = presencePeakCore_.processSample(micGated);
        }

        // -------------------------------------------------------------
        // 5. Speech Compressor & Brickwall Limiter
        // -------------------------------------------------------------
        // Fast soft-saturation limiter to keep speech consistent and intelligible
        float micLimited = std::tanh(micGated * 1.5f) * 0.667f;

        // -------------------------------------------------------------
        // 6. Call Alert Chime Generation
        // -------------------------------------------------------------
        float chimeSignal = 0.0f;
        if (callChimeSamplesRemaining_ > 0) {
            callChimeActive_ = true;
            callChimePhase1_ += chimeInc1;
            callChimePhase2_ += chimeInc2;
            if (callChimePhase1_ >= kTwoPi) callChimePhase1_ -= kTwoPi;
            if (callChimePhase2_ >= kTwoPi) callChimePhase2_ -= kTwoPi;

            const float env = static_cast<float>(callChimeSamplesRemaining_) / static_cast<float>(callChimeTotalSamples_);
            chimeSignal = env * env * (
                0.6f * std::sin(static_cast<float>(callChimePhase1_)) +
                0.4f * std::sin(static_cast<float>(callChimePhase2_))
            ) * 0.45f;

            --callChimeSamplesRemaining_;
            if (callChimeSamplesRemaining_ == 0) {
                callChimeActive_ = false;
            }
        }

        // -------------------------------------------------------------
        // 7. Mechanical Switch Click Transient
        // -------------------------------------------------------------
        float clickSignal = 0.0f;
        if (clickSamplesRemaining_ > 0) {
            clickSignal = clickSampleVal_ * (static_cast<float>(clickSamplesRemaining_) / 96.0f);
            --clickSamplesRemaining_;
        }

        // -------------------------------------------------------------
        // 8. Global Talk & IFB Ducking Logic
        // -------------------------------------------------------------
        const bool talkEngaged = anyKeyTalkActive || callChimeActive_;
        talkActiveGlobal_ = talkEngaged;

        if (talkEngaged) {
            duckHoldSamplesRemaining_ = duckHoldMax;
            // Ramp down to duckingDepthLin_
            currentDuckGain_ += (duckingDepthLin_ - currentDuckGain_) * duckAttackCoeff_;
        } else {
            if (duckHoldSamplesRemaining_ > 0) {
                --duckHoldSamplesRemaining_;
            } else {
                // Hold expired: smoothly restore program to 1.0
                currentDuckGain_ += (1.0f - currentDuckGain_) * duckReleaseCoeff_;
            }
        }

        currentDuckDb_ = (currentDuckGain_ > 1e-4f) ? (20.0f * std::log10(currentDuckGain_)) : -60.0f;

        // -------------------------------------------------------------
        // 9. Apply Ducking to Program Audio
        // -------------------------------------------------------------
        float inL = (prgL != nullptr) ? prgL[i] : 0.0f;
        float inR = (prgR != nullptr) ? prgR[i] : 0.0f;

        float outL = inL * currentDuckGain_;
        float outR = inR * currentDuckGain_;

        // -------------------------------------------------------------
        // 10. Inject Talkback, Sidetone, Chime & Click into Cue
        // -------------------------------------------------------------
        float talkbackMix = 0.0f;
        if (talkEngaged) {
            talkbackMix += micLimited * sidetoneLin_;
        }
        talkbackMix += chimeSignal;
        talkbackMix += clickSignal;

        outL += talkbackMix;
        outR += talkbackMix;

        // -------------------------------------------------------------
        // 11. Station Speaker Acoustic Resonance Emulation
        // -------------------------------------------------------------
        if (speakerMode_ == SpeakerCabMode::StationSpeaker) {
            outL = speakerResonanceCore_[0].processSample(outL);
            outL = speakerShelfCore_[0].processSample(outL);
            outR = speakerResonanceCore_[1].processSample(outR);
            outR = speakerShelfCore_[1].processSample(outR);
        }

        // -------------------------------------------------------------
        // 12. Master Volume
        // -------------------------------------------------------------
        outL *= masterVolLin_;
        outR *= masterVolLin_;

        if (prgL != nullptr) prgL[i] = outL;
        if (prgR != nullptr) prgR[i] = outR;
    }
}

void M7880PluginProcessor::updateMeters(const engine::AudioBlock& audioBlock) noexcept {
    if (audioBlock.numSamples == 0 || audioBlock.numChannels == 0) return;

    float pL = 0.0f, pR = 0.0f, pMic = 0.0f;
    const float* ptrL = audioBlock.getChannelPointer(0);
    const float* ptrR = (audioBlock.numChannels > 1) ? audioBlock.getChannelPointer(1) : ptrL;

    for (size_t i = 0; i < audioBlock.numSamples; ++i) {
        pL = std::max(pL, std::abs(ptrL[i]));
        pR = std::max(pR, std::abs(ptrR[i]));
    }

    if (audioBlock.numChannels > 2) {
        const float* ptrM = audioBlock.getChannelPointer(2);
        for (size_t i = 0; i < audioBlock.numSamples; ++i) {
            pMic = std::max(pMic, std::abs(ptrM[i]));
        }
    } else {
        pMic = (talkActiveGlobal_ || gateOpen_) ? 0.45f : 0.0f;
    }

    prgPeak_[0] = (prgPeak_[0] * 0.85f) + (pL * 0.15f);
    prgPeak_[1] = (prgPeak_[1] * 0.85f) + (pR * 0.15f);
    micPeak_ = (micPeak_ * 0.85f) + (pMic * 0.15f);
    outPeak_[0] = prgPeak_[0];
    outPeak_[1] = prgPeak_[1];
}

void M7880PluginProcessor::triggerClickTransient() noexcept {
    if (!mechanicalClicks_) return;
    clickSamplesRemaining_ = 96; // ~2ms at 48kHz
    clickSampleVal_ = 0.18f;
}

void M7880PluginProcessor::triggerCallChime() noexcept {
    callChimeSamplesRemaining_ = callChimeTotalSamples_;
    callChimeActive_ = true;
    callChimePhase1_ = 0.0;
    callChimePhase2_ = 0.0;
    triggerClickTransient();
}

void M7880PluginProcessor::setKeyTalk(size_t keyIndex, bool active) noexcept {
    if (keyIndex >= kNumIntercomKeys) return;
    if (keys_[keyIndex].talkActive != active) {
        keys_[keyIndex].talkActive = active;
        triggerClickTransient();
    }
}

void M7880PluginProcessor::setKeyListen(size_t keyIndex, bool active) noexcept {
    if (keyIndex >= kNumIntercomKeys) return;
    if (keys_[keyIndex].listenActive != active) {
        keys_[keyIndex].listenActive = active;
        triggerClickTransient();
    }
}

void M7880PluginProcessor::toggleKeyTalk(size_t keyIndex) noexcept {
    if (keyIndex >= kNumIntercomKeys) return;
    keys_[keyIndex].talkActive = !keys_[keyIndex].talkActive;
    triggerClickTransient();
}

void M7880PluginProcessor::toggleKeyListen(size_t keyIndex) noexcept {
    if (keyIndex >= kNumIntercomKeys) return;
    keys_[keyIndex].listenActive = !keys_[keyIndex].listenActive;
    triggerClickTransient();
}

void M7880PluginProcessor::setKeyMnemonic(size_t keyIndex, const char* mnemonic) noexcept {
    if (keyIndex >= kNumIntercomKeys || mnemonic == nullptr) return;
    std::strncpy(keys_[keyIndex].mnemonic, mnemonic, 4);
    keys_[keyIndex].mnemonic[4] = '\0';
}

const IntercomKeyData& M7880PluginProcessor::getKey(size_t keyIndex) const noexcept {
    if (keyIndex < kNumIntercomKeys) return keys_[keyIndex];
    return keys_[0];
}

void M7880PluginProcessor::setMasterVolume(float volDb) noexcept {
    masterVolumeDb_ = std::clamp(volDb, -60.0f, 12.0f);
    updateParametersFromHost();
}

void M7880PluginProcessor::setMicGain(float gainDb) noexcept {
    micGainDb_ = std::clamp(gainDb, -20.0f, 30.0f);
    updateParametersFromHost();
}

void M7880PluginProcessor::setSidetoneLevel(float levelDb) noexcept {
    sidetoneDb_ = std::clamp(levelDb, -60.0f, 0.0f);
    updateParametersFromHost();
}

void M7880PluginProcessor::setDuckingDepth(float depthDb) noexcept {
    duckingDepthDb_ = std::clamp(depthDb, -60.0f, 0.0f);
    updateParametersFromHost();
}

void M7880PluginProcessor::setDuckingRelease(float releaseMs) noexcept {
    duckingReleaseMs_ = std::clamp(releaseMs, 50.0f, 2000.0f);
    updateParametersFromHost();
}

void M7880PluginProcessor::setGateThreshold(float threshDb) noexcept {
    gateThresholdDb_ = std::clamp(threshDb, -70.0f, -20.0f);
    updateParametersFromHost();
}

void M7880PluginProcessor::setCommsFilterMode(CommsFilterMode mode) noexcept {
    commsMode_ = mode;
    updateParametersFromHost();
}

void M7880PluginProcessor::setSpeakerMode(SpeakerCabMode mode) noexcept {
    speakerMode_ = mode;
    updateParametersFromHost();
}

void M7880PluginProcessor::setMicSource(MicSourceMode source) noexcept {
    micSource_ = source;
}

void M7880PluginProcessor::setBypass(bool bypassed) noexcept {
    bypass_ = bypassed;
}

void M7880PluginProcessor::setPttLatchMode(bool latching) noexcept {
    pttLatchMode_ = latching;
}

void M7880PluginProcessor::setMechanicalClicks(bool enabled) noexcept {
    mechanicalClicks_ = enabled;
}

float M7880PluginProcessor::getProgramPeak(size_t ch) const noexcept {
    return (ch < engine::kMaxChannels) ? prgPeak_[ch] : 0.0f;
}

float M7880PluginProcessor::getMicPeak() const noexcept {
    return micPeak_;
}

float M7880PluginProcessor::getOutputPeak(size_t ch) const noexcept {
    return (ch < engine::kMaxChannels) ? outPeak_[ch] : 0.0f;
}

} // namespace wbs::m7880

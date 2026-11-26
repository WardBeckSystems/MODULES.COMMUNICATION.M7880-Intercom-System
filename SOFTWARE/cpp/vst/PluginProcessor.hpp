#pragma once

#include "../core/SharedPluginFrame.hpp"
#include "../core/StateVariableCore.hpp"
#include "../core/NonLinearCore.hpp"
#include "../core/BallisticsCore.hpp"
#include "../core/PluginTelemetryShm.hpp"

#include <array>
#include <string>
#include <atomic>
#include <cmath>

namespace wbs::m7880 {

constexpr size_t kNumIntercomKeys = 10;

enum class CommsFilterMode : int {
    Flat = 0,
    Broadcast = 1, // 150 Hz HPF - 7.5 kHz LPF + 2.2 kHz presence peak
    Telecom = 2    // 300 Hz HPF - 3.4 kHz LPF + 2.0 kHz presence peak
};

enum class SpeakerCabMode : int {
    Headset = 0,       // Direct / Flat monitoring
    StationSpeaker = 1 // 3" Metal Cabinet Resonant Cavity
};

enum class MicSourceMode : int {
    Sidechain = 0,     // External Sidechain (Ch 2 & 3)
    MainLeft = 1,      // Mono Mic on Ch 0, Program on Ch 1
    TestGenerator = 2  // Internal speech synthesizer / 1 kHz voice test signal
};

struct IntercomKeyData {
    char mnemonic[5]{ "DIR " };
    bool talkActive{ false };
    bool listenActive{ false };
    bool greenTally{ false }; // Incoming call / listen active
    bool redTally{ false };   // Transmit / PTT active
};

class M7880PluginProcessor : public engine::SharedPluginFrame {
public:
    M7880PluginProcessor();
    ~M7880PluginProcessor() override = default;

    void prepareModule(double hostRate, double oversampledRate, size_t maxBlockSize, size_t numChannels) override;
    void releaseModule() override;
    void updateParametersFromHost() noexcept override;
    void processModuleSlice(engine::AudioBlock& slice) noexcept override;
    void updateMeters(const engine::AudioBlock& audioBlock) noexcept override;

    // Parameter Controls
    void setMasterVolume(float volDb) noexcept;
    void setMicGain(float gainDb) noexcept;
    void setSidetoneLevel(float levelDb) noexcept;
    void setDuckingDepth(float depthDb) noexcept;
    void setDuckingRelease(float releaseMs) noexcept;
    void setGateThreshold(float threshDb) noexcept;
    void setCommsFilterMode(CommsFilterMode mode) noexcept;
    void setSpeakerMode(SpeakerCabMode mode) noexcept;
    void setMicSource(MicSourceMode source) noexcept;
    void setBypass(bool bypassed) noexcept;
    void setPttLatchMode(bool latching) noexcept;
    void setMechanicalClicks(bool enabled) noexcept;

    // Triggers & Keys
    void triggerCallChime() noexcept;
    void setKeyTalk(size_t keyIndex, bool active) noexcept;
    void setKeyListen(size_t keyIndex, bool active) noexcept;
    void toggleKeyTalk(size_t keyIndex) noexcept;
    void toggleKeyListen(size_t keyIndex) noexcept;
    void setKeyMnemonic(size_t keyIndex, const char* mnemonic) noexcept;

    // Queries for GUI & Host Automation / Telemetry
    [[nodiscard]] float getMasterVolume() const noexcept { return masterVolumeDb_; }
    [[nodiscard]] float getMicGain() const noexcept { return micGainDb_; }
    [[nodiscard]] float getSidetoneLevel() const noexcept { return sidetoneDb_; }
    [[nodiscard]] float getDuckingDepth() const noexcept { return duckingDepthDb_; }
    [[nodiscard]] float getDuckingRelease() const noexcept { return duckingReleaseMs_; }
    [[nodiscard]] float getGateThreshold() const noexcept { return gateThresholdDb_; }
    [[nodiscard]] CommsFilterMode getCommsFilterMode() const noexcept { return commsMode_; }
    [[nodiscard]] SpeakerCabMode getSpeakerMode() const noexcept { return speakerMode_; }
    [[nodiscard]] MicSourceMode getMicSource() const noexcept { return micSource_; }
    [[nodiscard]] bool getBypass() const noexcept { return bypass_; }
    [[nodiscard]] bool getPttLatchMode() const noexcept { return pttLatchMode_; }
    [[nodiscard]] bool getMechanicalClicks() const noexcept { return mechanicalClicks_; }

    [[nodiscard]] float getDuckingGainReductionDb() const noexcept { return currentDuckDb_; }
    [[nodiscard]] bool isGateOpen() const noexcept { return gateOpen_; }
    [[nodiscard]] bool isTalkActive() const noexcept { return talkActiveGlobal_; }
    [[nodiscard]] bool isCallChimeActive() const noexcept { return callChimeActive_; }

    [[nodiscard]] const IntercomKeyData& getKey(size_t keyIndex) const noexcept;
    [[nodiscard]] float getProgramPeak(size_t ch) const noexcept;
    [[nodiscard]] float getMicPeak() const noexcept;
    [[nodiscard]] float getOutputPeak(size_t ch) const noexcept;

private:
    void triggerClickTransient() noexcept;

    // Speech Bandpass & Presence Filters (ZDF State Variable Filters)
    engine::StateVariableFilterCore hpfCores_[2]; // 2nd + 1st order for 18 dB/oct
    engine::StateVariableFilterCore lpfCores_[2];
    engine::StateVariableFilterCore presencePeakCore_;

    // Station Speaker Cabinet Simulation (Resonant Biquads)
    engine::StateVariableFilterCore speakerResonanceCore_[engine::kMaxChannels];
    engine::StateVariableFilterCore speakerShelfCore_[engine::kMaxChannels];

    // Non-linear transformer emulation for mic preamp
    engine::NonLinearTransformerCore micTransformer_;

    // Parameters
    float masterVolumeDb_{ 0.0f };
    float masterVolLin_{ 1.0f };
    float micGainDb_{ 0.0f };
    float micGainLin_{ 1.0f };
    float sidetoneDb_{ -18.0f };
    float sidetoneLin_{ 0.12589f };
    float duckingDepthDb_{ -20.0f };
    float duckingDepthLin_{ 0.1f };
    float duckingReleaseMs_{ 350.0f };
    float gateThresholdDb_{ -45.0f };
    float gateThresholdLin_{ 0.00562f };
    CommsFilterMode commsMode_{ CommsFilterMode::Broadcast };
    SpeakerCabMode speakerMode_{ SpeakerCabMode::Headset };
    MicSourceMode micSource_{ MicSourceMode::TestGenerator };
    bool bypass_{ false };
    bool pttLatchMode_{ true };
    bool mechanicalClicks_{ true };

    // Keys State
    std::array<IntercomKeyData, kNumIntercomKeys> keys_;

    // Dynamic DSP state
    bool talkActiveGlobal_{ false };
    bool gateOpen_{ false };
    float gateEnvelope_{ 0.0f };
    float gateGain_{ 0.0f };

    // Ducking envelope
    float currentDuckGain_{ 1.0f };
    float currentDuckDb_{ 0.0f };
    size_t duckHoldSamplesRemaining_{ 0 };
    float duckAttackCoeff_{ 0.01f };
    float duckReleaseCoeff_{ 0.0005f };

    // Call Chime Generator
    bool callChimeActive_{ false };
    size_t callChimeSamplesRemaining_{ 0 };
    size_t callChimeTotalSamples_{ 0 };
    double callChimePhase1_{ 0.0 };
    double callChimePhase2_{ 0.0 };

    // Mechanical Switch Click Generator
    size_t clickSamplesRemaining_{ 0 };
    float clickSampleVal_{ 0.0f };

    // Internal Speech Test Generator (Synthesizes modulated voice formant)
    double synthPhase1_{ 0.0 };
    double synthPhase2_{ 0.0 };
    double synthPhase3_{ 0.0 };
    double synthLfoPhase_{ 0.0 };

    // Metering
    float prgPeak_[engine::kMaxChannels]{ 0.0f };
    float micPeak_{ 0.0f };
    float outPeak_[engine::kMaxChannels]{ 0.0f };
};

} // namespace wbs::m7880

// Copyright (c) 2026 Ward-Beck Systems (Ward-Beck.com - Ward-Beck.ca). All rights reserved.
// M7880: its part of 2030.env/vst/clap_wrapper/ClapModuleRegistry.cpp (suite index 10).

// --- descriptor ---
static const clap_plugin_descriptor_t s_desc_m7880 = {
    CLAP_VERSION,
    "ca.wbsps.m7880_intercom_panel",
    "Ward-Beck M7880 Intercom Panel",
    "Ward-Beck Systems Preservation Society",
    "https://wbsps.ca",
    "",
    "https://wbsps.ca/contact",
    "1.0.0",
    "Iconic MicroCOM II/III broadcast intercom station with IFB auto-ducking, speech shaping, and 10-key matrix panel",
    kMixingFeatures
};

// --- parameters ---
std::vector<ParameterInfo> buildM7880Params() {
    std::vector<ParameterInfo> p;
    // 0: Master Volume
    p.push_back({
        0, "Master Volume", "Monitoring", -60.0, 12.0, 0.0,
        CLAP_PARAM_IS_AUTOMATABLE,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m7880::M7880PluginProcessor*>(f)->setMasterVolume(static_cast<float>(val)); },
        [](engine::SharedPluginFrame* f) { return static_cast<double>(static_cast<m7880::M7880PluginProcessor*>(f)->getMasterVolume()); },
        [](double v) { char buf[32]; std::snprintf(buf, sizeof(buf), "%+.1f dB", v); return std::string(buf); },
        nullptr
    });
    // 1: Mic Gain
    p.push_back({
        1, "Mic Gain", "Input", -20.0, 30.0, 0.0,
        CLAP_PARAM_IS_AUTOMATABLE,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m7880::M7880PluginProcessor*>(f)->setMicGain(static_cast<float>(val)); },
        [](engine::SharedPluginFrame* f) { return static_cast<double>(static_cast<m7880::M7880PluginProcessor*>(f)->getMicGain()); },
        [](double v) { char buf[32]; std::snprintf(buf, sizeof(buf), "%+.1f dB", v); return std::string(buf); },
        nullptr
    });
    // 2: Sidetone Level
    p.push_back({
        2, "Sidetone Level", "Monitoring", -60.0, 0.0, -18.0,
        CLAP_PARAM_IS_AUTOMATABLE,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m7880::M7880PluginProcessor*>(f)->setSidetoneLevel(static_cast<float>(val)); },
        [](engine::SharedPluginFrame* f) { return static_cast<double>(static_cast<m7880::M7880PluginProcessor*>(f)->getSidetoneLevel()); },
        [](double v) { char buf[32]; std::snprintf(buf, sizeof(buf), "%+.1f dB", v); return std::string(buf); },
        nullptr
    });
    // 3: IFB Duck Depth
    p.push_back({
        3, "IFB Duck Depth", "Ducking", -60.0, 0.0, -20.0,
        CLAP_PARAM_IS_AUTOMATABLE,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m7880::M7880PluginProcessor*>(f)->setDuckingDepth(static_cast<float>(val)); },
        [](engine::SharedPluginFrame* f) { return static_cast<double>(static_cast<m7880::M7880PluginProcessor*>(f)->getDuckingDepth()); },
        [](double v) { return (v <= -59.0) ? "Mute" : (std::to_string(static_cast<int>(v)) + " dB"); },
        nullptr
    });
    // 4: Duck Release
    p.push_back({
        4, "Duck Release", "Ducking", 50.0, 2000.0, 350.0,
        CLAP_PARAM_IS_AUTOMATABLE,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m7880::M7880PluginProcessor*>(f)->setDuckingRelease(static_cast<float>(val)); },
        [](engine::SharedPluginFrame* f) { return static_cast<double>(static_cast<m7880::M7880PluginProcessor*>(f)->getDuckingRelease()); },
        [](double v) { char buf[32]; std::snprintf(buf, sizeof(buf), "%.0f ms", v); return std::string(buf); },
        nullptr
    });
    // 5: Gate Threshold
    p.push_back({
        5, "Gate Threshold", "Dynamics", -70.0, -20.0, -45.0,
        CLAP_PARAM_IS_AUTOMATABLE,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m7880::M7880PluginProcessor*>(f)->setGateThreshold(static_cast<float>(val)); },
        [](engine::SharedPluginFrame* f) { return static_cast<double>(static_cast<m7880::M7880PluginProcessor*>(f)->getGateThreshold()); },
        [](double v) { char buf[32]; std::snprintf(buf, sizeof(buf), "%.1f dB", v); return std::string(buf); },
        nullptr
    });
    // 6: Comms EQ Mode
    p.push_back({
        6, "Comms EQ Mode", "Filter", 0.0, 2.0, 1.0,
        CLAP_PARAM_IS_AUTOMATABLE | CLAP_PARAM_IS_STEPPED,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m7880::M7880PluginProcessor*>(f)->setCommsFilterMode(static_cast<m7880::CommsFilterMode>(static_cast<int>(val))); },
        [](engine::SharedPluginFrame* f) { return static_cast<double>(static_cast<m7880::M7880PluginProcessor*>(f)->getCommsFilterMode()); },
        [](double v) {
            int m = static_cast<int>(v);
            if (m == 0) return "Flat (Wideband)";
            if (m == 1) return "Broadcast (150Hz-7.5kHz)";
            return "Telecom (300Hz-3.4kHz)";
        },
        nullptr
    });
    // 7: Speaker Mode
    p.push_back({
        7, "Speaker Mode", "Monitoring", 0.0, 1.0, 0.0,
        CLAP_PARAM_IS_AUTOMATABLE | CLAP_PARAM_IS_STEPPED,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m7880::M7880PluginProcessor*>(f)->setSpeakerMode(static_cast<m7880::SpeakerCabMode>(static_cast<int>(val))); },
        [](engine::SharedPluginFrame* f) { return static_cast<double>(static_cast<m7880::M7880PluginProcessor*>(f)->getSpeakerMode()); },
        [](double v) { return (v >= 0.5) ? "Station Speaker (980Hz Res)" : "Headset (Direct)"; },
        nullptr
    });
    // 8: Mic Source
    p.push_back({
        8, "Mic Source", "Input", 0.0, 2.0, 2.0,
        CLAP_PARAM_IS_AUTOMATABLE | CLAP_PARAM_IS_STEPPED,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m7880::M7880PluginProcessor*>(f)->setMicSource(static_cast<m7880::MicSourceMode>(static_cast<int>(val))); },
        [](engine::SharedPluginFrame* f) { return static_cast<double>(static_cast<m7880::M7880PluginProcessor*>(f)->getMicSource()); },
        [](double v) {
            int s = static_cast<int>(v);
            if (s == 0) return "Ext Sidechain (Ch 3/4)";
            if (s == 1) return "Main Left (Mono Mic)";
            return "Test Speech Generator";
        },
        nullptr
    });
    // 9: Call Chime
    p.push_back({
        9, "Call Chime", "Signaling", 0.0, 1.0, 0.0,
        CLAP_PARAM_IS_AUTOMATABLE | CLAP_PARAM_IS_STEPPED,
        [](engine::SharedPluginFrame* f, double val) { if (val >= 0.5) static_cast<m7880::M7880PluginProcessor*>(f)->triggerCallChime(); },
        [](engine::SharedPluginFrame* f) { return static_cast<m7880::M7880PluginProcessor*>(f)->isCallChimeActive() ? 1.0 : 0.0; },
        [](double v) { return (v >= 0.5) ? "CHIME!" : "Idle"; },
        nullptr
    });
    // 10: Bypass
    p.push_back({
        10, "Bypass", "Utility", 0.0, 1.0, 0.0,
        CLAP_PARAM_IS_AUTOMATABLE | CLAP_PARAM_IS_BYPASS | CLAP_PARAM_IS_STEPPED,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m7880::M7880PluginProcessor*>(f)->setBypass(val >= 0.5); },
        [](engine::SharedPluginFrame* f) { return static_cast<m7880::M7880PluginProcessor*>(f)->getBypass() ? 1.0 : 0.0; },
        [](double v) { return (v >= 0.5) ? "Bypassed" : "Active"; },
        nullptr
    });
    // 11: PTT Latch Mode
    p.push_back({
        11, "PTT Mode", "Control", 0.0, 1.0, 1.0,
        CLAP_PARAM_IS_AUTOMATABLE | CLAP_PARAM_IS_STEPPED,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m7880::M7880PluginProcessor*>(f)->setPttLatchMode(val >= 0.5); },
        [](engine::SharedPluginFrame* f) { return static_cast<m7880::M7880PluginProcessor*>(f)->getPttLatchMode() ? 1.0 : 0.0; },
        [](double v) { return (v >= 0.5) ? "Latch Toggle" : "Momentary"; },
        nullptr
    });
    // 12: Mechanical Clicks
    p.push_back({
        12, "Mech Clicks", "Control", 0.0, 1.0, 1.0,
        CLAP_PARAM_IS_AUTOMATABLE | CLAP_PARAM_IS_STEPPED,
        [](engine::SharedPluginFrame* f, double val) { static_cast<m7880::M7880PluginProcessor*>(f)->setMechanicalClicks(val >= 0.5); },
        [](engine::SharedPluginFrame* f) { return static_cast<m7880::M7880PluginProcessor*>(f)->getMechanicalClicks() ? 1.0 : 0.0; },
        [](double v) { return (v >= 0.5) ? "Enabled" : "Disabled"; },
        nullptr
    });

    const char* const kKeyNames[10] = { "DIR", "PROD", "CAM1", "CAM2", "SND", "IFB1", "CR1", "STU1", "HOST", "ALL" };
    for (uint32_t k = 0; k < 10; ++k) {
        char nameBuf[64];
        std::snprintf(nameBuf, sizeof(nameBuf), "Key %u (%s) Talk", k + 1, kKeyNames[k]);
        p.push_back({
            13 + k, nameBuf, "Keypad Talk", 0.0, 1.0, 0.0,
            CLAP_PARAM_IS_AUTOMATABLE | CLAP_PARAM_IS_STEPPED,
            [k](engine::SharedPluginFrame* f, double val) { static_cast<m7880::M7880PluginProcessor*>(f)->setKeyTalk(k, val >= 0.5); },
            [k](engine::SharedPluginFrame* f) { return static_cast<m7880::M7880PluginProcessor*>(f)->getKey(k).talkActive ? 1.0 : 0.0; },
            [](double v) { return (v >= 0.5) ? "TALK" : "Off"; },
            nullptr
        });
    }

    for (uint32_t k = 0; k < 10; ++k) {
        char nameBuf[64];
        std::snprintf(nameBuf, sizeof(nameBuf), "Key %u (%s) Listen", k + 1, kKeyNames[k]);
        const double defVal = (k == 0 || k == 1) ? 1.0 : 0.0;
        p.push_back({
            23 + k, nameBuf, "Keypad Listen", 0.0, 1.0, defVal,
            CLAP_PARAM_IS_AUTOMATABLE | CLAP_PARAM_IS_STEPPED,
            [k](engine::SharedPluginFrame* f, double val) { static_cast<m7880::M7880PluginProcessor*>(f)->setKeyListen(k, val >= 0.5); },
            [k](engine::SharedPluginFrame* f) { return static_cast<m7880::M7880PluginProcessor*>(f)->getKey(k).listenActive ? 1.0 : 0.0; },
            [](double v) { return (v >= 0.5) ? "LISTEN" : "Mute"; },
            nullptr
        });
    }

    return p;
}

// --- instance ---
        case 10:
            inst = new ClapPluginInstance(
                &s_desc_m7880, host,
                []() { return std::make_unique<m7880::M7880PluginProcessor>(); },
                buildM7880Params(),
                10
            );
            break;


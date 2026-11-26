// M7880: its block of 2030.env/vst/core/CircuitDiagramDefinitions.hpp.

        case 10: // M7880 Intercom Panel & IFB Station
            d.modelCode = "M7880";
            d.circuitTitle = "Ward-Beck MicroCOM M7880 Broadcast Intercom Station";
            d.theoreticalExplanation =
                "Hardware recreation of the iconic Ward-Beck MicroCOM II M7880 10-key broadcast station. Combines speech bandpass filtering, "
                "noise gate expansion, speech leveling compression, automatic IFB program ducking, call alert chime, and station speaker resonance.";
            d.nodes = {
                { "MIC_IN", "Mic Preamp",   "Gain & Sat",     { 10, 20, 85, 48 }, true, Palette::CopperWire },
                { "GATE",   "Noise Gate",   "Expander Slew",  { 105, 20, 90, 48 }, true, Palette::CircuitBorder },
                { "BP_EQ",  "Comms Filter", "300Hz-3.4kHz",   { 205, 20, 95, 48 }, true, Palette::CircuitHighlight },
                { "KEYPAD", "M7880 Matrix", "10 PTT Keys",    { 310, 20, 95, 48 }, true, Palette::TextGold },
                { "IFB",    "IFB Ducker",   "-20dB Auto-Duck",{ 415, 20, 95, 48 }, true, Palette::LedAmber },
                { "SPK",    "Acoustic Cab", "980Hz Resonator",{ 520, 20, 90, 48 }, true, Palette::LedGreen }
            };
            d.wires = {
                { "MIC_IN", "GATE", "Voice Preamp" },
                { "GATE", "BP_EQ", "Rumble Free" },
                { "BP_EQ", "KEYPAD", "Speech Comms" },
                { "KEYPAD", "IFB", "PTT Key Engage" },
                { "IFB", "SPK", "Ducked Cue" }
            };
            break;

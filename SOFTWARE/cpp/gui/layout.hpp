// M7880: its block of 2030.env/vst/core/ModuleGuiLayouts.hpp (176 x 770 = the faceplate).

        case 10: { // M7880 Broadcast Intercom Station & IFB Ducker (2RU 19" Rackmount: 880 x 240)
            m.title = "M7880 Broadcast Intercom Station";
            m.subtitle = "MicroCOM II/III Matrix Panel, IFB Ducker & Speech Processor";
            m.modelCode = "M7880";
            m.width = 880.0f;
            m.height = 240.0f;
            m.isRackmount = true;
            m.isIntercomStation = true;

            // Gooseneck Mic XLR connector on left
            m.gooseneckRect = { 60.0f, 130.0f, 45.0f, 45.0f };

            // Left Knobs: MIC GAIN, SIDETONE
            m.knobs.push_back({ 1, "MIC GAIN", "dB", 145.0f, 85.0f, 20.0f, -20.0, 30.0, 0.0, false, KnobStyle::WbsElmaWing, Palette::ElmaRed });
            m.knobs.push_back({ 2, "SIDETONE", "dB", 145.0f, 165.0f, 20.0f, -60.0, 0.0, -18.0, false, KnobStyle::WbsElmaPointer, Palette::ElmaSlate });

            // 10 Intercom Keys in Center
            const char* const mnemonics[10] = { "DIR ", "PROD", "CAM1", "CAM2", "SND ", "IFB1", "CR1 ", "STU1", "HOST", "ALL " };
            for (size_t k = 0; k < 10; ++k) {
                const float kx = 205.0f + static_cast<float>(k) * 44.0f;
                const float ky = 55.0f;
                GuiIntercomKey key;
                key.keyIndex = static_cast<uint32_t>(k);
                key.mnemonic = mnemonics[k];
                key.bounds = { kx, ky, 38.0f, 125.0f };
                key.paddleBounds = { kx + 2.0f, ky + 45.0f, 34.0f, 75.0f };
                key.isFunctionKey = (k >= 6);
                key.talkActive = false;
                key.listenActive = (k == 0 || k == 1);
                key.greenTally = key.listenActive;
                key.redTally = false;
                m.intercomKeys.push_back(key);
            }

            // Right-Center DSP & Ducking Controls
            m.duckingMeterRect = { 660.0f, 45.0f, 14.0f, 140.0f }; // Vertical IFB Ducking Meter
            m.knobs.push_back({ 3, "DUCK DEPTH", "dB", 715.0f, 75.0f, 18.0f, -60.0, 0.0, -20.0, false, KnobStyle::WbsElmaWing, Palette::ElmaAmber });
            m.knobs.push_back({ 4, "RELEASE", "ms", 715.0f, 145.0f, 18.0f, 50.0, 2000.0, 350.0, false, KnobStyle::WbsElmaPointer, Palette::ElmaSlate });

            // Right Station Controls: Speaker Grille & Monitor Volume
            m.speakerGrilleRect = { 765.0f, 45.0f, 50.0f, 50.0f };
            m.knobs.push_back({ 0, "MONITOR VOL", "dB", 790.0f, 145.0f, 22.0f, -60.0, 12.0, 0.0, false, KnobStyle::WbsElmaWing, Palette::ElmaBlue });

            // Push buttons: CALL CHIME, SPK/HEADSET, COMMS FILTER
            m.buttons.push_back({ 9, "CALL", { 60.0f, 65.0f, 45.0f, 24.0f }, false, ButtonStyle::MomentaryPush, Palette::LedRed });
            m.buttons.push_back({ 7, "SPK", { 765.0f, 105.0f, 35.0f, 20.0f }, false, ButtonStyle::LatchingPush, Palette::LedGreen });
            m.buttons.push_back({ 6, "COMMS EQ", { 60.0f, 95.0f, 45.0f, 22.0f }, true, ButtonStyle::LatchingPush, Palette::LedAmber });

            m.themeToggleRect = { 730.0f, 205.0f, 120.0f, 22.0f };
            m.webRemoteRect = { 540.0f, 205.0f, 180.0f, 22.0f };
            m.bottomScrewRect = { 18.0f - 14.0f, 222.0f - 14.0f, 28.0f, 28.0f };
            break;
        }

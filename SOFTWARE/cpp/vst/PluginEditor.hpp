#pragma once
#include "PluginProcessor.hpp"

namespace wbs::m7880 {

class M7880PluginEditor {
public:
    explicit M7880PluginEditor(M7880PluginProcessor& processor)
        : processor_(processor) {}

    void paint() const noexcept;
    void resized() noexcept;

    int getWidth() const noexcept { return 880; }
    int getHeight() const noexcept { return 240; }

private:
    M7880PluginProcessor& processor_;
};

} // namespace wbs::m7880

// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// This FILE is dual-licensed. You are free to choose between:
//
//     - The GNU General Public License v3 (or any later version)
//     - The Mozilla Public License v2
//
// SPDX-License-Identifier: GPL-3.0-or-later OR MPL-2.0
// -----------------------------------------------------------------------------

#pragma once

#include "LogicAnalyzerTypes.h"
#include "SubComponent.h"
#include "Colors.h"

namespace tiara {

class LogicAnalyzer final : public SubComponent {

    friend class VICII;
    friend class TIA;

    // Number of logic analyzer channels
    static constexpr isize cnt = 4;

    Descriptions descriptions = {{

        .name           = "LogicAnalyzer",
        .description    = "Logic Analyzer",
        .shell          = "la"
    }};

    Options options = {

        OPT_LA_ENABLE,
        OPT_LA_MODE,
        OPT_LA_OPACITY,
        OPT_LA_CHANNEL0,
        OPT_LA_CHANNEL1,
        OPT_LA_CHANNEL2,
        OPT_LA_CHANNEL3
    };

    // Current configuration
    LogicAnalyzerConfig config = { };

    // Observed signals
    Probe probe[cnt];

    // Color lookup table (4 different shades for each color)
    u32 color[4][cnt];

    
    //
    // Methods
    //
    
public:
    
    LogicAnalyzer(Atari &ref);

    LogicAnalyzer& operator= (const LogicAnalyzer& other) {

        CLONE_ARRAY(probe)
        CLONE_ARRAY(color[0])
        CLONE_ARRAY(color[1])
        CLONE_ARRAY(color[2])
        CLONE_ARRAY(color[3])

        CLONE(config)

        return *this;
    }


    //
    // Methods from Serializable
    //

public:

    template <class T>
    void serialize(T& worker)
    {
        if (isResetter(worker)) return;

        worker

        << probe
        << color

        << config.enable
        << config.displayMode
        << config.opacity;

    } SERIALIZERS(serialize);


    //
    // Methods from CoreComponent
    //

public:

    const Descriptions &getDescriptions() const override { return descriptions; }

private:

    void _dump(Category category, std::ostream& os) const override;


    //
    // Methods from Configurable
    //

public:

    const LogicAnalyzerConfig &getConfig() const { return config; }
    const Options &getOptions() const override { return options; }
    i64 getOption(Option opt) const override;
    void checkOption(Option opt, i64 value) override;
    void setOption(Option opt, i64 value) override;


    //
    // Managing colors
    //

    void setColor(isize channel, GpuColor color);
    void setColor(isize channel, RgbColor color);
    void setColor(isize channel, u32 abgr);

    
    //
    // Visualizing DMA
    //
    
public:
    
    // Visualizes a memory access by drawing into the DMA debuger texture
    // void visualizeDma(isize offset, u8 data, MemAccess type);
    // void visualizeDma(u32 *ptr, u8 data, MemAccess type);
    
    // Superimposes the debug output onto the current scanline
    void computeOverlay(u32 *emuTexture, u32 *dmaTexture);
};

}

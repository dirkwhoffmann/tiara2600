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

#include "MonitorTypes.h"
// #include "TIATypes.h"
#include "AtariTypes.h"
#include "SubComponent.h"

namespace tiara {

class Monitor final : public SubComponent {

    Descriptions descriptions = {
        {
            .type           = MonitorClass,
            .name           = "Monitor",
            .description    = "Computer Monitor",
            .shell          = "monitor"
        }
    };

    Options options = {

        OPT_MON_PALETTE,
        OPT_MON_BRIGHTNESS,
        OPT_MON_CONTRAST,
        OPT_MON_SATURATION,
        OPT_MON_HCENTER,
        OPT_MON_VCENTER,
        OPT_MON_HZOOM,
        OPT_MON_VZOOM,
        OPT_MON_UPSCALER,
        OPT_MON_BLUR,
        OPT_MON_BLUR_RADIUS,
        OPT_MON_BLOOM,
        OPT_MON_BLOOM_RADIUS,
        OPT_MON_BLOOM_BRIGHTNESS,
        OPT_MON_BLOOM_WEIGHT,
        OPT_MON_DOTMASK,
        OPT_MON_DOTMASK_BRIGHTNESS,
        OPT_MON_SCANLINES,
        OPT_MON_SCANLINE_BRIGHTNESS,
        OPT_MON_SCANLINE_WEIGHT,
        OPT_MON_DISALIGNMENT,
        OPT_MON_DISALIGNMENT_H,
        OPT_MON_DISALIGNMENT_V
    };

    // Current configuration
    MonitorConfig config = { };

    // Lookup table for all 128 Atari color
    u32 color[128]{};


    //
    // Methods
    //

public:

    Monitor(Atari &ref) : SubComponent(ref) { }

    Monitor& operator= (const Monitor& other) {

        CLONE(config)

        return *this;
    }

    //
    // Methods from Serializable
    //

public:

    template <class T> void serialize(T& worker) {

        if (isResetter(worker)) return;

        worker

        << config.palette
        << config.brightness
        << config.contrast
        << config.saturation

        << config.hCenter
        << config.vCenter
        << config.hZoom
        << config.vZoom

        << config.upscaler

        << config.blur
        << config.blurRadius

        << config.bloom
        << config.bloomRadius
        << config.bloomBrightness
        << config.bloomWeight

        << config.dotmask
        << config.dotMaskBrightness

        << config.scanlines
        << config.scanlineBrightness
        << config.scanlineWeight

        << config.disalignment
        << config.disalignmentH
        << config.disalignmentV;


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

    const MonitorConfig &getConfig() const { return config; }
    const Options &getOptions() const override { return options; }
    i64 getOption(Option opt) const override;
    void checkOption(Option opt, i64 value) override;
    void setOption(Option opt, i64 value) override;


    //
    // Computing color values
    //

public:

    // Updates the color palette
    void updateColors();

    // Computes a C64 color in 32 bit big-endian ABGR format
    u32 getColor(isize nr) { return color[nr]; }

    // Draws a palette image
    void drawPalette(u32 *dst, isize blockWidth, isize blockHeight, isize gap) const;

private:

    // Adjusts the RGBA value according to the selected color parameters
    void adjustRGB(u8 &r, u8 &g, u8 &b);
};

}

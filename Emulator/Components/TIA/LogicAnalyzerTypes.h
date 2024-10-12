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
/// @file

#pragma once

#include "Reflection.h"

namespace tiara {

//
// Enumerations
//

/// Logic analyzer probes
enum_long(PROBE)
{
    // Logic board
    PROBE_ADDR_BUS,                     ///< Address bus
    PROBE_DATA_BUS,                     ///< Data bus

    // TIA
    PROBE_PHI1,                         ///< PHI1 (Horizontal counter)
    PROBE_PHI2,                         ///< PHI2 (Horizontal counter)
    PROBE_RDY,                          ///< Ready signal
    PROBE_VSYNC,                        ///< Vertical Sync
    PROBE_VBLANK,                       ///< Vertical Blank

    // PIA
    PROBE_INTIM,                        ///< Interval timer
};
typedef PROBE Probe;

struct ProbeEnum : util::Reflection<ProbeEnum, Probe> {

    static constexpr long minVal = 0;
    static constexpr long maxVal = PROBE_INTIM;

    static const char *prefix() { return "PROBE"; }
    static const char *_key(long value)
    {
        switch (value) {

            case PROBE_ADDR_BUS:    return "ADDR_BUS";
            case PROBE_DATA_BUS:    return "DATA_BUS";
            case PROBE_PHI1:        return "PHI1";
            case PROBE_PHI2:        return "PHI2";
            case PROBE_RDY:         return "RDY";
            case PROBE_VSYNC:       return "VSYNC";
            case PROBE_VBLANK:      return "VBLANK";
            case PROBE_INTIM:       return "INTIM";
        }
        return "???";
    }
};

/// Logic analyzer display mode
enum_long(LA_DISPLAY_MODE)
{
    LA_DISPLAY_MODE_FG_LAYER,           ///< Modulate the foreground layer
    LA_DISPLAY_MODE_BG_LAYER,           ///< Modulate the background layer
    LA_DISPLAY_MODE_ODD_EVEN_LAYERS     ///< Modulate both layers
};
typedef LA_DISPLAY_MODE LaDisplayMode;

struct LaDisplayModeEnum : util::Reflection<LaDisplayModeEnum, LaDisplayMode> {
    
    static constexpr long minVal = 0;
    static constexpr long maxVal = LA_DISPLAY_MODE_ODD_EVEN_LAYERS;
    
    static const char *prefix() { return "LA_DISPLAY_MODE"; }
    static const char *_key(long value)
    {
        switch (value) {
                
            case LA_DISPLAY_MODE_FG_LAYER:         return "FG_LAYER";
            case LA_DISPLAY_MODE_BG_LAYER:         return "BG_LAYER";
            case LA_DISPLAY_MODE_ODD_EVEN_LAYERS:  return "ODD_EVEN_LAYERS";
        }
        return "???";
    }
};


//
// Structures
//

typedef struct
{
    bool enable;
    LaDisplayMode displayMode;
    u8 opacity;
}
LogicAnalyzerConfig;

typedef struct
{
    u16 addrBus;
    u8 dataBus;
    bool phi1;
    bool phi2;
    bool rdy;
    bool vsync;
    bool vblank;
    u8 intim;
}
RecordedSignals;

}

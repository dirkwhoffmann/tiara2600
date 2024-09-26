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

enum_long(CRT_TYPE)
{
    // Cartridges with a defined CRT ID (values must match)
    CRT_NORMAL             = 0,
    CRT_SIMONS_BASIC       = 4,

    CRT_NONE
};
typedef CRT_TYPE CartridgeType;

struct CartridgeTypeEnum : util::Reflection<CartridgeTypeEnum, CartridgeType> {

    static constexpr long minVal = 0;
    static constexpr long maxVal = CRT_NONE;

    static const char *prefix() { return "CRT"; }
    static const char *_key(long value)
    {
        switch (value) {

            case CRT_NORMAL:             return "NORMAL";
            case CRT_SIMONS_BASIC:       return "SIMONS_BASIC";
            case CRT_NONE:               return "NONE";
        }
        return "???";
    }
};


//
// Structures
//

typedef struct
{
    CartridgeType type;
    const char *title;

    isize memory;
    bool  battery;

    isize buttons;
    const char *button1;
    const char *button2;

    isize switches;
    const char *switchLeft;
    const char *switchNeutral;
    const char *switchRight;

    isize leds;

    bool needsExecution;
}
CartridgeTraits;

typedef struct
{
    CartridgeType type; // DEPRECATED
    bool supported;
    bool gameLineInCrtFile;
    bool exromLineInCrtFile;
    isize numPackets;
    isize switchPos;
    bool led;
}
CartridgeInfo;

typedef struct
{
    u16 size;
    u16 loadAddress;
}
CartridgeRomInfo;

}

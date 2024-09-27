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

/// TIA chip revision
enum_long(TIA_REV)
{
    TIA_NTSC,
    TIA_PAL,
    TIA_SECAM
};
typedef TIA_REV TIARevision;

struct TIARevisionEnum : util::Reflection<TIARevisionEnum, TIARevision> {

    static constexpr long minVal = 0;
    static constexpr long maxVal = TIA_SECAM;

    static const char *prefix() { return "TIA"; }
    static const char *_key(long value)
    {
        switch (value) {

            case TIA_NTSC:      return "NTSC";
            case TIA_PAL:       return "PAL";
            case TIA_SECAM:     return "SECAM";
        }
        return "???";
    }
};


//
// Structures
//

typedef struct
{
    // Video standard
    double fps;
}
TIATraits;

typedef struct
{
    // Silicon
    TIARevision revision;
    bool powerSave;

    // Visibility
    // bool hideBall;

    // Cheating
    // bool checkCollisions;
}
TIAConfig;

typedef struct
{
    // Counters
    u16 posx;
    u16 posy;
}
TIAInfo;

typedef struct
{
    // Speed optimizations
    // isize fastPaths;
}
TIAStats;

}

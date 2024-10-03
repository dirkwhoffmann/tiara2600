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

enum_long(CART_TYPE)
{
    CART_NONE,

    CART_0840,
    CART_0FA0,
    CART_2IN1,
    CART_4IN1,
    CART_8IN1,
    CART_16IN1,
    CART_32IN1,
    CART_64IN1,
    CART_128IN1,
    CART_2K,
    CART_3E,
    CART_3EX,
    CART_3EP,
    CART_3F,
    CART_4A50,
    CART_4K,        // Standard Atari Cartridge
    CART_4KSC,
    CART_AR,
    CART_BF,
    CART_BFSC,
    CART_BUS,
    CART_CDF,
    CART_CM,
    CART_CTY,
    CART_CV,
    CART_DF,
    CART_DFSC,
    CART_DPC,
    CART_DPCP,
    CART_E0,
    CART_E7,
    CART_EF,
    CART_EFSC,
    CART_F0,
    CART_F4,
    CART_F4SC,
    CART_F6,
    CART_F6SC,
    CART_F8,
    CART_F8SC,
    CART_FA,
    CART_FA2,
    CART_FC,
    CART_FE,
    CART_MDM,
    CART_MVC,
    CART_SB,
    CART_TVBOY,
    CART_UA,
    CART_UASW,
    CART_WD,
    CART_WDSW,
    CART_X07,

    CART_UNKNOWN
};
typedef CART_TYPE CartType;

struct CartTypeEnum : util::Reflection<CartTypeEnum, CartType> {

    static constexpr long minVal = 0;
    static constexpr long maxVal = CART_UNKNOWN;

    static const char *prefix() { return "CART"; }
    static const char *_key(long value)
    {
        switch (value) {

            case CART_NONE:     return "NONE";

            case CART_0840:     return "0840";
            case CART_0FA0:     return "0FA0";
            case CART_2IN1:     return "2IN1";
            case CART_4IN1:     return "4IN1";
            case CART_8IN1:     return "8IN1";
            case CART_16IN1:    return "16IN1";
            case CART_32IN1:    return "32IN1";
            case CART_64IN1:    return "64IN1";
            case CART_2K:       return "2K";
            case CART_3E:       return "3E";
            case CART_3EX:      return "3EX";
            case CART_3EP:      return "3EP";
            case CART_3F:       return "3F";
            case CART_4K:       return "4K";
            case CART_4KSC:     return "4KSC";
            case CART_AR:       return "AR";
            case CART_BF:       return "BF";
            case CART_BFSC:     return "BFSC";
            case CART_BUS:      return "BUS";
            case CART_CDF:      return "CDF";
            case CART_CM:       return "CM";
            case CART_CTY:      return "CTY";
            case CART_CV:       return "CV";
            case CART_DF:       return "DF";
            case CART_DFSC:     return "DFSC";
            case CART_DPC:      return "DPC";
            case CART_DPCP:     return "DPCP";
            case CART_E0:       return "E0";
            case CART_E7:       return "E7";
            case CART_EF:       return "EF";
            case CART_EFSC:     return "EFSC";
            case CART_F0:       return "F0";
            case CART_F4:       return "F4";
            case CART_F4SC:     return "F4SC";
            case CART_F6:       return "F6";
            case CART_F6SC:     return "F6SC";
            case CART_F8:       return "F8";
            case CART_F8SC:     return "F8SC";
            case CART_FA:       return "FA";
            case CART_FA2:      return "FA2";
            case CART_FC:       return "FC";
            case CART_FE:       return "FE";
            case CART_MDM:      return "MDM";
            case CART_MVC:      return "MVC";
            case CART_SB:       return "SB";
            case CART_TVBOY:    return "TVBOY";
            case CART_UA:       return "UA";
            case CART_UASW:     return "UASW";
            case CART_WD:       return "WD";
            case CART_WDSW:     return "WDSW";
            case CART_X07:      return "X07";

            case CART_UNKNOWN:  return "UNKNOWN";
        }
        return "???";
    }
};


//
// Structures
//

typedef struct {

    CartType cartType;
    const char *md5;
    const char *name;
    const char *manufacturer;
    const char *type;
    const char *model;
    const char *format;
    const char *note;
    const char *left;
    const char *right;
    bool phosphor;
    bool swapPorts;
    bool swapPaddles;
}
CartTraits;

/*
typedef struct
{
    CartridgeType type;
}
CartridgeTraits;
*/

typedef struct
{

}
CartridgeInfo;

}

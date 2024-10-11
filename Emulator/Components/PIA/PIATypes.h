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
#include "AtariTypes.h"

namespace tiara {


/// PIA registers
enum_long(PIA_REGISTER)
{
    PIA_SWCHA,      ///< 00   11111111  Port A; input or output (read or write)
    PIA_SWACNT,     ///< 01   11111111  Port A DDR, 0= input, 1=output
    PIA_SWCHB,      ///< 02   11111111  Port B; console switches (read only)
    PIA_SWBCNT,     ///< 03   11111111  Port B DDR (hardwired as input)
    PIA_INTIM,      ///< 04   11111111  Timer output (read only)
    PIA_INSTAT,     ///< 05   11......  Timer Status (read only, undocumented)

    PIA_06,         ///< 06   unused
    PIA_07,         ///< 07   unused
    PIA_08,         ///< 08   unused
    PIA_09,         ///< 09   unused
    PIA_0A,         ///< 0A   unused
    PIA_0B,         ///< 0B   unused
    PIA_0C,         ///< 0C   unused
    PIA_0D,         ///< 0D   unused
    PIA_0E,         ///< 0E   unused
    PIA_0F,         ///< 0F   unused
    PIA_10,         ///< 10   unused
    PIA_11,         ///< 11   unused
    PIA_12,         ///< 12   unused
    PIA_13,         ///< 13   unused

    PIA_TIM1T,      ///< 14   11111111  set 1 clock interval (838 nsec/interval)
    PIA_TIM8T,      ///< 15   11111111  set 8 clock interval (6.7 usec/interval)
    PIA_TIM64T,     ///< 16   11111111  set 64 clock interval (53.6 usec/interval)
    PIA_T1024T,     ///< 17   11111111  set 1024 clock interval (858.2 usec/interval)

    PIA_18,         ///< 18   unused
    PIA_19,         ///< 19   unused
    PIA_1A,         ///< 1A   unused
    PIA_1B,         ///< 1B   unused
    PIA_1C,         ///< 1C   unused
    PIA_1D,         ///< 1D   unused
    PIA_1E,         ///< 1E   unused
    PIA_1F,         ///< 1F   unused

    // Placeholder
    PIA_VOID
};
typedef PIA_REGISTER PIARegister;

struct PIARegisterEnum : util::Reflection<PIARegisterEnum, PIARegister> {

    static constexpr long minVal = 0;
    static constexpr long maxVal = PIA_VOID;

    static const char *prefix() { return "PIA"; }
    static const char *_key(long value)
    {
        switch (value) {

            case PIA_SWCHA:     return "SWCHA";
            case PIA_SWACNT:    return "SWACNT";
            case PIA_SWCHB:     return "SWCHB";
            case PIA_SWBCNT:    return "SWBCNT";
            case PIA_INTIM:     return "INTIM";
            case PIA_INSTAT:    return "INSTAT";

            case PIA_06:        return "06";
            case PIA_07:        return "07";
            case PIA_08:        return "08";
            case PIA_09:        return "09";
            case PIA_0A:        return "0A";
            case PIA_0B:        return "0B";
            case PIA_0C:        return "0C";
            case PIA_0D:        return "0D";
            case PIA_0E:        return "0E";
            case PIA_0F:        return "0F";
            case PIA_10:        return "10";
            case PIA_11:        return "11";
            case PIA_12:        return "12";
            case PIA_13:        return "13";

            case PIA_TIM1T:     return "TIM1T";
            case PIA_TIM8T:     return "TIM8T";
            case PIA_TIM64T:    return "TIM64T";
            case PIA_T1024T:    return "T1024T";

            case PIA_18:        return "18";
            case PIA_19:        return "19";
            case PIA_1A:        return "1A";
            case PIA_1B:        return "1B";
            case PIA_1C:        return "1C";
            case PIA_1D:        return "1D";
            case PIA_1E:        return "1E";
            case PIA_1F:        return "1F";

            case PIA_VOID:      return "VOID";
        }
        return "???";
    }
};

//
// Structures
//

typedef struct
{

}
PIAConfig;

typedef struct
{

}
PIAInfo;

typedef struct
{

}
PIAStats;

}

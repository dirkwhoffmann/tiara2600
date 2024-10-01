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
// Constants
//

constexpr u16 TIA_MASK   = 0b0001'0000'1000'0000;
constexpr u16 TIA_MATCH  = 0b0000'0000'0000'0000;

constexpr u16 RAM_MASK   = 0b0001'0010'1000'0000;
constexpr u16 RAM_MATCH  = 0b0000'0000'1000'0000;

constexpr u16 RIOT_MASK  = 0b0001'0010'1000'0000;
constexpr u16 RIOT_MATCH = 0b0000'0010'1000'0000;

constexpr u16 CART_MASK  = 0b0001'0000'0000'0000;
constexpr u16 CART_MATCH = 0b0001'0000'0000'0000;


//
// Enumerations
//

/// Memory type
enum_long(M_TYPE)
{
    M_NONE,         ///< Unmapped
    M_TIA,          ///< Custom IC
    M_RIOT,         ///< Custom IC
    M_RAM,          ///< RAM
    M_CART          ///< Cartridge
};
typedef M_TYPE MemoryType;

struct MemoryTypeEnum : util::Reflection<MemoryTypeEnum, MemoryType> {

    static constexpr long minVal = 1;
    static constexpr long maxVal = M_NONE;

    static const char *prefix() { return "M"; }
    static const char *_key(long value)
    {
        switch (value) {

            case M_NONE:    return "NONE";
            case M_TIA:     return "TIA";
            case M_RIOT:    return "RIOT";
            case M_RAM:     return "RAM";
            case M_CART:    return "CART";
        }
        return "???";
    }
};

/// Ram startup pattern
enum_long(RAM_PATTERN)
{
    RAM_PATTERN_ZEROES,     ///< Initialize with all zeroes
    RAM_PATTERN_ONES,       ///< Initialize with all ones
    RAM_PATTERN_RANDOM      ///< Initialize with pseudo-random values
};
typedef RAM_PATTERN RamPattern;

struct RamPatternEnum : util::Reflection<RamPatternEnum, RamPattern> {

    static constexpr long minVal = 0;
    static constexpr long maxVal = RAM_PATTERN_RANDOM;

    static const char *prefix() { return "RAM_PATTERN"; }
    static const char *_key(long value)
    {
        switch (value) {

            case RAM_PATTERN_ZEROES: return "ZEROES";
            case RAM_PATTERN_ONES:   return "ONES";
            case RAM_PATTERN_RANDOM: return "RANDOM";
        }
        return "???";
    }
};


//
// Structures
//

typedef struct
{
    RamPattern ramPattern;
    bool heatmap; 
}
MemConfig;

typedef struct
{
    u8   bankMap;

    MemoryType peekSrc[32];
    MemoryType vicPeekSrc[32];
}
MemInfo;

typedef struct
{
    isize reads[65536];
    isize writes[65536];
}
MemStats;

}

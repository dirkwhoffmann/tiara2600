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

#include "AudioTypes.h"
// #include "Reflection.h"

namespace tiara {

//
// Enumerations
//

/// TIA chip revision
enum_long(TIA_REV)
{
    TIA_NTSC,       //! Native NTSC gaming console
    TIA_PAL,        //! Native PAL gaming console
    TIA_SECAM,      //! Native SECAM gaming console
    TIA_NTSC50,     //! Hybrid model (PAL console with NTSC colors)
    TIA_PAL60,      //! Hybrid model (NTSC console with PAL colors)
    TIA_SECAM60     //! Hybrid model (NTSC console with SECAM colors)
};
typedef TIA_REV TIARevision;

struct TIARevisionEnum : util::Reflection<TIARevisionEnum, TIARevision> {

    static constexpr long minVal = 0;
    static constexpr long maxVal = TIA_SECAM60;

    static const char *prefix() { return "TIA"; }
    static const char *_key(long value)
    {
        switch (value) {

            case TIA_NTSC:      return "NTSC";
            case TIA_PAL:       return "PAL";
            case TIA_SECAM:     return "SECAM";
            case TIA_NTSC50:    return "NTSC50";
            case TIA_PAL60:     return "PAL60";
            case TIA_SECAM60:   return "SECAM60";
        }
        return "???";
    }
};


/// TIA color palette
enum_long(TIA_PALETTE)
{
    TIA_PALETTE_NTSC,   //! NTSC color palette
    TIA_PALETTE_PAL,    //! PAL color palette
    TIA_PALETTE_SECAM   //! SECAM color palette
};
typedef TIA_PALETTE TIAPalette;

struct TIAPaletteEnum : util::Reflection<TIAPaletteEnum, TIAPalette> {

    static constexpr long minVal = 0;
    static constexpr long maxVal = TIA_PALETTE_SECAM;

    static const char *prefix() { return "TIA_PALETTE"; }
    static const char *_key(long value)
    {
        switch (value) {

            case TIA_PALETTE_NTSC:  return "NTSC";
            case TIA_PALETTE_PAL:   return "PAL";
            case TIA_PALETTE_SECAM: return "SECAM";
        }
        return "???";
    }
};


/// TIA registers
enum_long(TIA_REGISTER)
{
    // Writable
    TIA_VSYNC,      ///< 00   ......1.   vertical sync set-clear
    TIA_VBLANK,     ///< 01   11....1.   vertical blank set-clear
    TIA_WSYNC,      ///< 02   <strobe>   wait for leading edge of horizontal blank
    TIA_RSYNC,      ///< 03   <strobe>   reset horizontal sync counter
    TIA_NUSIZ0,     ///< 04   ..111111   number-size player-missile 0
    TIA_NUSIZ1,     ///< 05   ..111111   number-size player-missile 1
    TIA_COLUP0,     ///< 06   1111111.   color-lum player 0 and missile 0
    TIA_COLUP1,     ///< 07   1111111.   color-lum player 1 and missile 1
    TIA_COLUPF,     ///< 08   1111111.   color-lum playfield and ball
    TIA_COLUBK,     ///< 09   1111111.   color-lum background
    TIA_CTRLPF,     ///< 0A   ..11.111   control playfield ball size & collisions
    TIA_REFP0,      ///< 0B   ....1...   reflect player 0
    TIA_REFP1,      ///< 0C   ....1...   reflect player 1
    TIA_PF0,        ///< 0D   1111....   playfield register byte 0
    TIA_PF1,        ///< 0E   11111111   playfield register byte 1
    TIA_PF2,        ///< 0F   11111111   playfield register byte 2
    TIA_RESP0,      ///< 10   <strobe>   reset player 0
    TIA_RESP1,      ///< 11   <strobe>   reset player 1
    TIA_RESM0,      ///< 12   <strobe>   reset missile 0
    TIA_RESM1,      ///< 13   <strobe>   reset missile 1
    TIA_RESBL,      ///< 14   <strobe>   reset ball
    TIA_AUDC0,      ///< 15   ....1111   audio control 0
    TIA_AUDC1,      ///< 16   ....1111   audio control 1
    TIA_AUDF0,      ///< 17   ...11111   audio frequency 0
    TIA_AUDF1,      ///< 18   ...11111   audio frequency 1
    TIA_AUDV0,      ///< 19   ....1111   audio volume 0
    TIA_AUDV1,      ///< 1A   ....1111   audio volume 1
    TIA_GRP0,       ///< 1B   11111111   graphics player 0
    TIA_GRP1,       ///< 1C   11111111   graphics player 1
    TIA_ENAM0,      ///< 1D   ......1.   graphics (enable) missile 0
    TIA_ENAM1,      ///< 1E   ......1.   graphics (enable) missile 1
    TIA_ENABL,      ///< 1F   ......1.   graphics (enable) ball
    TIA_HMP0,       ///< 20   1111....   horizontal motion player 0
    TIA_HMP1,       ///< 21   1111....   horizontal motion player 1
    TIA_HMM0,       ///< 22   1111....   horizontal motion missile 0
    TIA_HMM1,       ///< 23   1111....   horizontal motion missile 1
    TIA_HMBL,       ///< 24   1111....   horizontal motion ball
    TIA_VDELP0,     ///< 25   .......1   vertical delay player 0
    TIA_VDELP1,     ///< 26   .......1   vertical delay player 1
    TIA_VDELBL,     ///< 27   .......1   vertical delay ball
    TIA_RESMP0,     ///< 28   ......1.   reset missile 0 to player 0
    TIA_RESMP1,     ///< 29   ......1.   reset missile 1 to player 1
    TIA_HMOVE,      ///< 2A   <strobe>   apply horizontal motion
    TIA_HMCLR,      ///< 2B   <strobe>   clear horizontal motion registers
    TIA_CXCLR,      ///< 2C   <strobe>   clear collision latches

    // Unmapped
    TIA_2D,         ///< 2D   unused
    TIA_2E,         ///< 2E   unused
    TIA_2F,         ///< 2F   unused

    // Readable
    TIA_CXM0P,      ///< 30   11......   read collision M0-P1, M0-P0 (Bit 7,6
    TIA_CXM1P,      ///< 31   11......   read collision M1-P0, M1-P1
    TIA_CXP0FB,     ///< 32   11......   read collision P0-PF, P0-BL
    TIA_CXP1FB,     ///< 33   11......   read collision P1-PF, P1-BL
    TIA_CXM0FB,     ///< 34   11......   read collision M0-PF, M0-BL
    TIA_CXM1FB,     ///< 35   11......   read collision M1-PF, M1-BL
    TIA_CXBLPF,     ///< 36   1.......   read collision BL-PF, unused
    TIA_CXPPMM,     ///< 37   11......   read collision P0-P1, M0-M1
    TIA_INPT0,      ///< 38   1.......   read pot port
    TIA_INPT1,      ///< 39   1.......   read pot port
    TIA_INPT2,      ///< 3A   1.......   read pot port
    TIA_INPT3,      ///< 3B   1.......   read pot port
    TIA_INPT4,      ///< 3C   1.......   read input
    TIA_INPT5,      ///< 3D   1.......   read input

    // Unmapped
    TIA_3E,         ///< 3E  unused
    TIA_3F,         ///< 3F  unused

    // Placeholder
    TIA_VOID
};
typedef TIA_REGISTER TIARegister;

struct TIARegisterEnum : util::Reflection<TIARegisterEnum, TIARegister> {

    static constexpr long minVal = 0;
    static constexpr long maxVal = TIA_VOID;

    static const char *prefix() { return "TIA"; }
    static const char *_key(long value)
    {
        switch (value) {

            case TIA_VSYNC:     return "VSYNC";
            case TIA_VBLANK:    return "VBLANK";
            case TIA_WSYNC:     return "WSYNC";
            case TIA_RSYNC:     return "RSYNC";
            case TIA_NUSIZ0:    return "NUSIZ0";
            case TIA_NUSIZ1:    return "NUSIZ1";
            case TIA_COLUP0:    return "COLUP0";
            case TIA_COLUP1:    return "COLUP1";
            case TIA_COLUPF:    return "COLUPF";
            case TIA_COLUBK:    return "COLUBK";
            case TIA_CTRLPF:    return "CTRLPF";
            case TIA_REFP0:     return "REFP0";
            case TIA_REFP1:     return "REFP1";
            case TIA_PF0:       return "PF0";
            case TIA_PF1:       return "PF1";
            case TIA_PF2:       return "PF2";
            case TIA_RESP0:     return "RESP0";
            case TIA_RESP1:     return "RESP1";
            case TIA_RESM0:     return "RESM0";
            case TIA_RESM1:     return "RESM1";
            case TIA_RESBL:     return "RESBL";
            case TIA_AUDC0:     return "AUDC0";
            case TIA_AUDC1:     return "AUDC1";
            case TIA_AUDF0:     return "AUDF0";
            case TIA_AUDF1:     return "AUDF1";
            case TIA_AUDV0:     return "AUDV0";
            case TIA_AUDV1:     return "AUDV1";
            case TIA_GRP0:      return "GRP0";
            case TIA_GRP1:      return "GRP1";
            case TIA_ENAM0:     return "ENAM0";
            case TIA_ENAM1:     return "ENAM1";
            case TIA_ENABL:     return "ENABL";
            case TIA_HMP0:      return "HMP0";
            case TIA_HMP1:      return "HMP1";
            case TIA_HMM0:      return "HMM0";
            case TIA_HMM1:      return "HMM1";
            case TIA_HMBL:      return "HMBL";
            case TIA_VDELP0:    return "VDELP0";
            case TIA_VDELP1:    return "VDELP1";
            case TIA_VDELBL:    return "VDELBL";
            case TIA_RESMP0:    return "RESMP0";
            case TIA_RESMP1:    return "RESMP1";
            case TIA_HMOVE:     return "HMOVE";
            case TIA_HMCLR:     return "HMCLR";
            case TIA_CXCLR:     return "CXCLR";

            case TIA_2D:        return "2D";
            case TIA_2E:        return "2E";
            case TIA_2F:        return "2F";

            case TIA_CXM0P:     return "CXM0P";
            case TIA_CXM1P:     return "CXM1P";
            case TIA_CXP0FB:    return "CXP0FB";
            case TIA_CXP1FB:    return "CXP1FB";
            case TIA_CXM0FB:    return "CXM0FB";
            case TIA_CXM1FB:    return "CXM1FB";
            case TIA_CXBLPF:    return "CXBLPF";
            case TIA_CXPPMM:    return "CXPPMM";
            case TIA_INPT0:     return "INPT0";
            case TIA_INPT1:     return "INPT1";
            case TIA_INPT2:     return "INPT2";
            case TIA_INPT3:     return "INPT3";
            case TIA_INPT4:     return "INPT4";
            case TIA_INPT5:     return "INPT5";

            case TIA_3E:        return "3E";
            case TIA_3F:        return "3F";

            case TIA_VOID:      return "VOID";
        }
        return "???";
    }
};

enum_long(TIA_OBJECT)
{
    TIA_PF,         ///< Playfield
    TIA_BL,         ///< Ball
    TIA_M0,         ///< First missile
    TIA_M1,         ///< Second missile
    TIA_P0,         ///< First player
    TIA_P1          ///< Second player
};
typedef TIA_OBJECT TIAObject;

struct TIAObjectEnum : util::Reflection<TIAObjectEnum, TIAObject> {

    static constexpr long minVal = 0;
    static constexpr long maxVal = TIA_P1;

    static const char *prefix() { return "TIA"; }
    static const char *_key(long value)
    {
        switch (value) {

            case TIA_PF:    return "PF";
            case TIA_BL:    return "BL";
            case TIA_M0:    return "M0";
            case TIA_P0:    return "P0";
            case TIA_P1:    return "P1";
        }
        return "???";
    }
};


enum_i8(TIA_COLOR)
{
    TIA_COLOR_P0,   ///< Player 0 and Missile 0
    TIA_COLOR_P1,   ///< Player 1 and Missile 1
    TIA_COLOR_PF,   ///< Playfield
    TIA_COLOR_BK    ///< Background
};
typedef TIA_COLOR TIAColor;

struct TIAColorEnum : util::Reflection<TIAColorEnum, TIAColor> {

    static constexpr long minVal = 0;
    static constexpr long maxVal = TIA_COLOR_BK;

    static const char *prefix() { return "TIA_COLOR"; }
    static const char *_key(long value)
    {
        switch (value) {

            case TIA_COLOR_P0:  return "P0";
            case TIA_COLOR_P1:  return "P1";
            case TIA_COLOR_PF:  return "PF";
            case TIA_COLOR_BK:  return "BK";
        }
        return "???";
    }
};


//
// Structures
//

typedef struct
{
    // Chip revision and color palette
    TIARevision revision;
    TIAPalette palette;

    // Clock frequency and frame refresh rate
    isize cpuFrequency;
    isize cpuCyclesPerFrame;
    isize fps;

    // Total canvas size (including unvisible areas)
    isize width;
    isize height;

    // Dimensions of the HBLANK and VBLANK areas
    isize hblankWidth;
    isize vblankHeight;

    // Dimensions of the visible screen area
    isize visibleWidth;
    isize visibleHeight;
}
TIATraits;

typedef struct
{
    // Silicon
    TIARevision revision;
    bool autoDetect;

    // Collision checking mask
    u16 collMask;

    // Register protection mask
    u64 lockMask;

    // Register watch mask
    u64 watchMask;

}
TIAConfig;

typedef struct
{
    // Beam position
    isize posx;
    isize posy;

    // Registers
    u8 regs[64];

    // Audio units
    AudioInfo audio0;
    AudioInfo audio1;
}
TIAInfo;

typedef struct
{
    AudioStats audio0;
    AudioStats audio1;
}
TIAStats;

}

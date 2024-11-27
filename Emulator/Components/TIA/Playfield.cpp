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

#include "config.h"
#include "Playfield.h"
#include "TIA.h"

namespace tiara {

u8
Playfield::spyPF0() const
{
    // 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
    // -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- xx xx xx xx

    return (u8)(playfield & 0x000F << 4);
}

u8
Playfield::spyPF1() const
{
    // 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
    // -- -- -- -- -- -- -- -- xx xx xx xx xx xx xx xx -- -- -- --
    //                               (reversed)

    return (u8)REVERSE_BYTE((u8)(playfield >> 4 & 0xFF));
}

u8
Playfield::spyPF2() const
{
    // 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
    // xx xx xx xx xx xx xx xx -- -- -- -- -- -- -- -- -- -- -- --

    return (u8)(playfield >> 12 & 0xFF);
}

void
Playfield::setPF0(u8 val)
{
    // 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
    // -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- xx xx xx xx

    u32 bits = u32(val) >> 4;
    playfield = (playfield & 0xFFFF0) | bits;
}

void
Playfield::setPF1(u8 val) {

    // 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
    // -- -- -- -- -- -- -- -- xx xx xx xx xx xx xx xx -- -- -- --
    //                               (reversed)

    u32 bits = u32(REVERSE_BYTE(val)) << 4;
    playfield = (playfield & 0xFF00F) | bits;
}

void
Playfield::setPF2(u8 val) {

    // 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
    // xx xx xx xx xx xx xx xx -- -- -- -- -- -- -- -- -- -- -- --

    u32 bits = u32(val) << 12;
    playfield = (playfield & 0x00FFF) | bits;
}

bool
Playfield::get() const
{
    return pf.get();
}

void
Playfield::execute(const TIA &tia)
{
    auto phi1 = tia.hc.phi1();
    auto phi2 = tia.hc.phi2();
    auto curr = tia.hc.current;

    // Shift bit selection masks
    if (phi2) { fwdMask <<= 1; bwdMask >>= 1; }

    // Reset masks at the proper horizontal positions
    if (curr == 16) { fwdMask = 0x00001; }
    if (curr == 36) { ref ? (bwdMask = 0x80000) : (fwdMask = 0x00001); }

    // Feed the dual-phase latch
    pf.execute(phi1, phi2, playfield & (fwdMask | bwdMask));
}

}

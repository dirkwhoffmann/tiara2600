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
#include "Atari.h"

namespace tiara {

u8
StdCartridge::spypeek(u16 addr)
{
    return rom[addr % rom.size];
}

void
StdCartridge::execute()
{
    if (cs) {

        if (rw) {

            auto addr = atari.addrBus & 0xFFF;
            printf("Reading from %x -> %x \n", atari.addrBus, rom[addr]);
            cpu.concludeRead(rom[addr]);
        }

        cs = 0;
    }
}

void
StdCartridge::endOfFrame()
{

}

}

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
#include "PIA.h"
#include "Emulator.h"
#include "IOUtils.h"

namespace tiara {

u8
PIA::peek(u16 addr)
{
    if ((addr & RAM_MASK) == RAM_MATCH) return ram[addr & 0x7F];

    return peek(PIARegister(addr & 0x1F));
}

u8
PIA::peek(PIARegister reg)
{
    u8 result;

    switch (reg) {

        case 0x04: case 0x0C: case 0x14: case 0x1C:
        case 0x06: case 0x0E: case 0x16: case 0x1E:

            if (timer != 0xFF) CLR_BIT(instat, 7);
            REPLACE_BIT(enable, 7, GET_BIT(reg, 3));
            result = timer;
            break;

        case 0x05: case 0x0D: case 0x15: case 0x1D:
        case 0x07: case 0x0F: case 0x17: case 0x1F:

            result = instat;
            instat &= 0x80;
            break;

        default:

            result = spypeek(reg);
            break;
    }

    return result;
}

u8
PIA::spypeek(u16 addr) const
{
    if ((addr & RAM_MASK) == RAM_MATCH) return ram[addr & 0x7F];

    return spypeek(PIARegister(addr & 0x1F));
}

u8
PIA::spypeek(PIARegister reg) const
{
    switch (reg) {

        case 0x00: case 0x08: case 0x10: case 0x18: return pa;
        case 0x01: case 0x09: case 0x11: case 0x19: return ddra;
        case 0x02: case 0x0A: case 0x12: case 0x1A: return pa;
        case 0x03: case 0x0B: case 0x13: case 0x1B: return ddra;
        case 0x04: case 0x0C: case 0x14: case 0x1C: return timer;
        case 0x05: case 0x0D: case 0x15: case 0x1D: return instat;
        case 0x06: case 0x0E: case 0x16: case 0x1E: return timer;
        case 0x07: case 0x0F: case 0x17: case 0x1F: return instat;

        default:
            fatalError;
    }
}

void
PIA::poke(PIARegister reg, u8 val, Cycle delay)
{
    if (delay) {

        assert(!atari.hasEvent<SLOT_REG>());
        atari.scheduleRel<SLOT_REG>(delay, REG_WRITE_PIA, HI_LO(reg, val));
        return;
    }

    switch(reg) {

        case 0x00: pokePRA(val); break;
        case 0x01: pokeDDRA(val); break;
        case 0x02: pokePRB(val); break;
        case 0x03: pokeDDRB(val); break;
        case 0x04: pokeEDGCTL(0); break;
        case 0x05: pokeEDGCTL(1); break;
        case 0x06: pokeEDGCTL(2); break;
        case 0x07: pokeEDGCTL(3); break;
        case 0x08: pokePRA(val); break;
        case 0x09: pokeDDRA(val); break;
        case 0x0A: pokePRB(val); break;
        case 0x0B: pokeDDRB(val); break;
        case 0x0C: pokeEDGCTL(0); break;
        case 0x0D: pokeEDGCTL(1); break;
        case 0x0E: pokeEDGCTL(2); break;
        case 0x0F: pokeEDGCTL(3); break;
        case 0x10: pokePRA(val); break;
        case 0x11: pokeDDRA(val); break;
        case 0x12: pokePRB(val); break;
        case 0x13: pokeDDRB(val); break;
        case 0x14: pokeTIMxT(1, val, false); break;
        case 0x15: pokeTIMxT(8, val, false); break;
        case 0x16: pokeTIMxT(64, val, false); break;
        case 0x17: pokeTIMxT(1024, val, false); break;
        case 0x18: pokePRA(val); break;
        case 0x19: pokeDDRA(val); break;
        case 0x1A: pokePRB(val); break;
        case 0x1B: pokeDDRB(val); break;
        case 0x1C: pokeTIMxT(1, val, true); break;
        case 0x1D: pokeTIMxT(8, val, true); break;
        case 0x1E: pokeTIMxT(64, val, true); break;
        case 0x1F: pokeTIMxT(1024, val, true); break;

        default:
            fatalError;
    }
}

void
PIA::pokePRA(u8 val)
{
    pra = val;
    updatePA();
}

void
PIA::pokeDDRA(u8 val)
{
    ddra = val;
    updatePA();
}

void
PIA::pokePRB(u8 val)
{
    prb = val;
    updatePB();
}

void
PIA::pokeDDRB(u8 val)
{
    ddrb = val;
    updatePB();

}

void
PIA::pokeTIMxT(isize x, u8 val, bool irqEnable)
{
    interval = x;
    timer = val;
    REPLACE_BIT(enable, 7, irqEnable);
    CLR_BIT(instat, 7);
    counter = 0;
}

void
PIA::pokeEDGCTL(u8 val)
{
    edgctrl = val & 0b11;
}

void
PIA::updatePA()
{
    updatePA((ddra & pra) | (~ddra & pa));
}

void
PIA::updatePA(u8 val)
{
    if (GET_BIT(edgctrl, 0) == 0 && RISING_EDGE_BIT(pa, val, 7)) {
        instat |= 0x40;
    }
    if (GET_BIT(edgctrl, 0) == 1 && FALLING_EDGE_BIT(pa, val, 7)) {
        instat |= 0x40;
    }
    pa = val;
}

void
PIA::updatePB()
{
    updatePB((ddrb & prb) | (~ddrb & pb));
}

void
PIA::updatePB(u8 val)
{
    pb = val;
}

template <bool debug> void
PIA::execute()
{
    // Interval timer logic
    if (GET_BIT(instat, 7)) {

        if (timer != 0x80) timer--;

    } else if ((counter & (interval - 1)) == 0) {

        if (timer == 0) instat |= 0x80;
        timer--;
    }
    counter++;

    /*
    if (cs) {

        auto addr = atari.addrBus & 0x7F;
        auto data = atari.dataBus;

        if (csram) {

            if (rw) {
                cpu.concludeRead(ram[addr]);
            } else {
                ram[addr] = data;
            }

        } else {

            if (rw) {
                cpu.concludeRead(0);
            } else {

            }
        }
        
        cs = 0;
    }
    */
}
template void PIA::execute<false>();
template void PIA::execute<true>();

void
PIA::eofHandler()
{

}

}

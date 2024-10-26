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
PIA::peekRam(u16 addr)
{
    return ram[addr & 0x7F];
}

u8
PIA::peekReg(PIARegister reg)
{
    u8 result;

    switch (reg) {

        case 0x04: case 0x0C: case 0x14: case 0x1C:
        case 0x06: case 0x0E: case 0x16: case 0x1E:

            if (timer != 0xFF) CLR_BIT(instat, 7);
            REPLACE_BIT(intena, 7, GET_BIT(reg, 3));
            result = timer;
            break;

        case 0x05: case 0x0D: case 0x15: case 0x1D:
        case 0x07: case 0x0F: case 0x17: case 0x1F:

            result = instat;
            CLR_BIT(instat, 7);
            break;

        default:

            result = spyReg(reg);
            break;
    }

    debug(PIA_REG_DEBUG, "PIA::peek(%s) = %02x\n", PIARegisterEnum::key(reg), result);

    return result;
}

u8
PIA::spyRam(u16 addr) const
{
    return ram[addr & 0x7F];
}

u8
PIA::spyReg(PIARegister reg) const
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
PIA::pokeRam(u16 addr, u8 val)
{
    ram[addr & 0x7F] = val;
}

void
PIA::pokeReg(PIARegister reg, u8 val, Cycle delay)
{
    assert_enum(PIARegister, reg);

    if (delay) {

        debug(PIA_REG_DEBUG, "PIA::poke(%s, %02x) delayed by %lld cycles\n",
              PIARegisterEnum::key(reg), val, delay);

        assert(!atari.hasEvent<SLOT_REG>());
        atari.scheduleRel<SLOT_REG>(delay, REG_WRITE_PIA, HI_LO(reg, val));
        return;
    }

    debug(PIA_REG_DEBUG, "PIA::poke(%s, %02x)\n", PIARegisterEnum::key(reg), val);

    // 000x x0xx: IO
    // 0001 x1xx: Interval timer
    // 0000 x1xx: Edge detect control

    switch(reg) {

        case 0x00: case 0x08: case 0x10: case 0x18:

            pokePRA(val);
            break;

        case 0x01: case 0x09: case 0x11: case 0x19:

            pokeDDRA(val);
            break;

        case 0x02: case 0x0A: case 0x12: case 0x1A:

            pokePRB(val);
            break;

        case 0x03: case 0x0B: case 0x13: case 0x1B:

            pokeDDRB(val);
            break;

        case 0x04: case 0x05: case 0x06: case 0x07:
        case 0x0C: case 0x0D: case 0x0E: case 0x0F:

            pokeEDGCTL(reg & 0x3);
            break;

        case 0x14:  pokeTIMxT(1, val, false); break;
        case 0x15:  pokeTIMxT(8, val, false); break;
        case 0x16:  pokeTIMxT(64, val, false); break;
        case 0x17:  pokeTIMxT(1024, val, false); break;
        case 0x1C:  pokeTIMxT(1, val, true); break;
        case 0x1D:  pokeTIMxT(8, val, true); break;
        case 0x1E:  pokeTIMxT(64, val, true); break;
        case 0x1F:  pokeTIMxT(1024, val, true); break;

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
    REPLACE_BIT(intena, 7, irqEnable);
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
    updatePA((ddra & pra) | (~ddra & paExternal()));
}

void
PIA::updatePA(u8 val)
{
    // Check for a rising or falling edge on PA7
    if (GET_BIT(edgctrl, 0) == 0 && RISING_EDGE_BIT(pa, val, 7)) {
        SET_BIT(instat, 6);
    }
    if (GET_BIT(edgctrl, 0) == 1 && FALLING_EDGE_BIT(pa, val, 7)) {
        SET_BIT(instat, 6);
    }
    pa = val;
}

void
PIA::updatePB()
{
    updatePB((ddrb & prb) | (~ddrb & pbExternal()));
    // trace(true, "updatePB %x %x %x\n", prb, ddrb, pbExternal());
}

void
PIA::updatePB(u8 val)
{
    pb = val;
}

u8
PIA::paExternal() const
{
    return 0xFF;
}

u8
PIA::pbExternal() const
{
    u8 result = 0xFF;

    if (atari.slider[SLIDER_RESET]) CLR_BIT(result, 0);
    if (atari.slider[SLIDER_SELECT]) CLR_BIT(result, 1);
    if (atari.slider[SLIDER_COLOR]) CLR_BIT(result, 3);
    if (atari.slider[SLIDER_DIFFA]) CLR_BIT(result, 6);
    if (atari.slider[SLIDER_DIFFB]) CLR_BIT(result, 7);

    return result;
}

template <bool debug> void
PIA::execute()
{
    // Interval timer logic
    if (GET_BIT(instat, 7)) {

        if (timer != 0x80) timer--;

    } else if ((counter & (interval - 1)) == 0) {

        if (timer == 0) SET_BIT(instat, 7);
        timer--;
    }
    counter++;
}
template void PIA::execute<false>();
template void PIA::execute<true>();

void
PIA::sofHandler()
{

}

void
PIA::eofHandler()
{

}

}

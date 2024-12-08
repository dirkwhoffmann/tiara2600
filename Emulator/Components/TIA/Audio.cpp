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
#include "Audio.h"
#include "Atari.h"
#include "AudioPort.h"

namespace tiara {

void
Audio::_dump(Category category, std::ostream& os) const
{
    using namespace util;

    if (category == Category::Config) {

        dumpConfig(os);
    }
}

void
Audio::_didReset(bool hard)
{
    poly4 = 0b1111;
    poly5 = 0b11111;
}

void
Audio::cacheInfo(AudioInfo &result) const
{
    result.audv = audv;
    result.audf = audf;
    result.audc = audc;
    result.fdiv = fdiv;
    result.poly4 = poly4;
    result.poly5 = poly5;
}

void
Audio::cacheStats(AudioStats &result) const
{

}

void
Audio::pokeAUDC(u8 val)
{
    debug(AUDREG_DEBUG, "pokeAUDC%ld(%02X)\n", objid, val);

    audc = val & 0x0F;
}

void
Audio::pokeAUDF(u8 val)
{
    debug(AUDREG_DEBUG, "pokeAUDF%ld(%02X)\n", objid, val);

    audf = val & 0x1F;
}

void
Audio::pokeAUDV(u8 val)
{
    debug(AUDREG_DEBUG, "pokeAUDV%ld(%02X)\n", objid, val);

    audv = val & 0x0F;
}

void
Audio::execute()
{
    // Only proceed if this is not the run-ahead instance
    if (atari.objid != 0) return;

    // Get the proper sampler for this audio unit
    Sampler &sampler = audioPort.sampler[objid];

    bool c2 = bool(poly5 & 0b00100);
    bool c4 = bool(poly5 & 0b10000);
    bool c5 = bool(poly4 & 0b0001);
    bool c7 = bool(poly4 & 0b0100);
    bool c8 = bool(poly4 & 0b1000);

    // Generate a new sound sample
    u8 sample = c8 ? 16 * audv : 0;

    // Add a sample to the sample buffer
    if (!sampler.isFull()) {
        sampler.append(cpu.clock, sample);
    } else {
        trace(AUD_DEBUG, "Sample buffer is full\n");
    }

    // Run the frequency divider (controled by the AUDF register)
    if (fdiv != audf) {

        fdiv = (fdiv + 1) & 0x1F;
        return;
    }
    fdiv = 0;

    //
    // Check the control register
    //

    bool p4Clk;
    u8 inBit;

    // Catch the (easy) AUDC == 0 case
    if (audc == 0) {

        poly4 = (poly4 << 1 &  0b1111) | 1;
        poly5 = (poly5 << 1 & 0b11111) | 1;
        return;
    }

    switch (audc & 0b11) {

        case 0b00:

            inBit = (c8 ^ c4) | (poly4 == 0 & poly5 == 0);
            p4Clk = true;
            break;

        case 0b01:

            inBit = (c2 ^ c4) | (poly5 == 0);
            p4Clk = true;
            break;

        case 0b10:

            inBit = (c2 ^ c4) | (poly5 == 0);
            p4Clk = (poly5 & 0b01111) == 0b01000;
            break;

        case 0b11:

            inBit = (c2 ^ c4) | (poly5 == 0);
            p4Clk = (poly5 & 0b10000) == 0b10000;
            break;

        default:
            fatalError;
    }

    //
    // Clock the polynomial counters
    //

    poly5 = (poly5 << 1 & 0b11111) | inBit;

    if (p4Clk) {

        switch (audc >> 2) {

            case 0b00:

                inBit = (c7 ^ c8) | (poly4 == 0);
                break;

            case 0b01:

                inBit = !c5;
                break;

            case 2:

                inBit = c4;
                break;

            case 3:

                inBit = !c7 | ((poly4 & 0b111) == 0b101);
                break;

            default:
                fatalError;
        }

        poly4 = (poly4 << 1 & 0b1111) | inBit;
    }
}

}

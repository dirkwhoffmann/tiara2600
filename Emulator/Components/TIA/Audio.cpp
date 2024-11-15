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
Audio::execute()
{
    // Only proceed if this is not the run-ahead instance
    if (atari.objid != 0) return;

    // Get the proper sampler for this audio unit
    Sampler &sampler = audioPort.sampler[objid];

    /*

    // Generate a new sound sample
    u8 sample = (poly4 & 0x8) ? audvol : 0;

    // Add a sample th the sample buffer
    if (!sampler.isFull()) {
        sampler.append(cpu.clock, sample);
    } else {
        trace(AUD_DEBUG, "Sample buffer is full\n");
    }
    */

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
    auto c2 = !!(poly5 & 0x04);
    auto c4 = !!(poly5 & 0x10);
    auto c8 = !!(poly4 & 0x08);

    switch (audc & 0b11) {

        case 0b00:

            inBit = audc == 0 ? 1 : (c8 ^ c4) | (poly4 == 0 && poly5 == 0);
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

    poly5 = ((poly5 << 1) & 0b11111) | inBit;

    if (p4Clk) {

        auto c5 = !!(poly4 & 0x01);
        auto c7 = !!(poly4 & 0x04);
        auto c8 = !!(poly4 & 0x08);

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

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
#include "Atari.h"
// #include "CPU.h"
#include "IOUtils.h"

namespace tiara {

PIA::PIA(Atari &ref) : SubComponent(ref)
{

}

void
PIA::_didReset(bool hard)
{
    static constexpr u8 atari7800[128] = {

        // Taken from Stella
        0xA9, 0x00, 0xAA, 0x85, 0x01, 0x95, 0x03, 0xE8,
        0xE0, 0x2A, 0xD0, 0xF9, 0x85, 0x02, 0xA9, 0x04,
        0xEA, 0x30, 0x23, 0xA2, 0x04, 0xCA, 0x10, 0xFD,
        0x9A, 0x8D, 0x10, 0x01, 0x20, 0xCB, 0x04, 0x20,
        0xCB, 0x04, 0x85, 0x11, 0x85, 0x1B, 0x85, 0x1C,
        0x85, 0x0F, 0xEA, 0x85, 0x02, 0xA9, 0x00, 0xEA,
        0x30, 0x04, 0x24, 0x03, 0x30, 0x09, 0xA9, 0x02,
        0x85, 0x09, 0x8D, 0x12, 0xF1, 0xD0, 0x1E, 0x24,
        0x02, 0x30, 0x0C, 0xA9, 0x02, 0x85, 0x06, 0x8D,
        0x18, 0xF1, 0x8D, 0x60, 0xF4, 0xD0, 0x0E, 0x85,
        0x2C, 0xA9, 0x08, 0x85, 0x1B, 0x20, 0xCB, 0x04,
        0xEA, 0x24, 0x02, 0x30, 0xD9, 0xA9, 0xFD, 0x85,
        0x08, 0x6C, 0xFC, 0xFF, 0xEA, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
    };

    if (hard) {

        switch (config.ramPattern) {

            case RAM_PATTERN_ZEROES:
            {
                memset(ram, 0x00, 1298);
                break;
            }
            case RAM_PATTERN_ONES:
            {
                memset(ram, 0xFF, 1298);
                break;
            }
            case RAM_PATTERN_ATARI_7800:
            {
                memcpy(ram, atari7800, 128);
                break;
            }
            case RAM_PATTERN_RANDOM:
            {
                auto ran = atari.random();
                for (isize i = 0; i < 128; i++, ran = atari.random(ran)) ram[i] = (u8)ran;
                break;
            }
            default:
                fatalError;
        }
    }
}

void
PIA::_dump(Category category, std::ostream& os) const
{
    using namespace util;

    if (category == Category::Config) {

        dumpConfig(os);
    }

    if (category == Category::Registers) {

        /*
        os << std::endl;
        os << tab("Counter A") << hex(counterA) << std::endl;
        os << tab("Latch A") << hex(latchA) << std::endl;
        os << tab("Data register A") << hex(PRA) << std::endl;
        os << tab("Data port direction A") << hex(DDRA) << std::endl;
        os << tab("Data port A") << hex(PA) << std::endl;
        os << tab("Control register A") << hex(CRA) << std::endl;
        os << std::endl;
        os << tab("Counter B") << hex(counterB) << std::endl;
        os << tab("Latch B") << hex(latchB) << std::endl;
        os << tab("Data register B") << hex(PRB) << std::endl;
        os << tab("Data port direction B") << hex(DDRB) << std::endl;
        os << tab("Data port B") << hex(PB) << std::endl;
        os << tab("Control register B") << hex(CRB) << std::endl;
        os << std::endl;
        os << tab("Interrupt control reg") << hex(icr) << std::endl;
        os << tab("Interrupt mask reg") << hex(imr) << std::endl;
        os << std::endl;
        os << tab("SDR") << hex(sdr) << std::endl;
        os << tab("serCounter") << dec(serCounter) << std::endl;
        os << std::endl;
        */
    }

    if (category == Category::State) {

        /*
        os << tab("Sleeping") << bol(sleeping) << std::endl;
        os << tab("Tiredness") << dec(tiredness) << std::endl;
        os << tab("Sleep cycle") << dec(sleepCycle) << std::endl;
        os << tab("Wakeup cycle") << dec(wakeUpCycle) << std::endl;
        os << tab("CNT") << dec(CNT) << std::endl;
        os << tab("INT") << dec(INT) << std::endl;
        */
    }
}

void
PIA::cacheInfo(PIAInfo &result) const
{
    /*
    result.portA.port = computePA();
    result.portA.reg = PRA;
    result.portA.dir = DDRA;

    result.portB.port = computePB();
    result.portB.reg = PRB;
    result.portB.dir = DDRB;
    */
}

void
PIA::cacheStats(PIAStats &result) const
{

}

i64
PIA::getOption(Option opt) const
{
    switch (opt) {

        case OPT_RAM_INIT_PATTERN:  return config.ramPattern;

        default:
            fatalError;
    }
}

void
PIA::checkOption(Option opt, i64 value)
{
    switch (opt) {

        case OPT_RAM_INIT_PATTERN:

            if (!RamPatternEnum::isValid(value)) {
                throw Error(VC64ERROR_OPT_INV_ARG, RamPatternEnum::keyList());
            }
            return;

        default:
            throw Error(VC64ERROR_OPT_UNSUPPORTED);
    }
}

void
PIA::setOption(Option opt, i64 value)
{
    checkOption(opt, value);

    switch (opt) {

        case OPT_RAM_INIT_PATTERN:

            config.ramPattern = (RamPattern)value;
            return;

        default:
            fatalError;
    }
}

}

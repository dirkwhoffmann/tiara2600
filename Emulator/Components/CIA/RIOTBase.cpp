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
#include "RIOT.h"
#include "CPU.h"
#include "IOUtils.h"

namespace tiara {

RIOT::RIOT(C64 &ref) : SubComponent(ref)
{

}

void
RIOT::_didReset(bool hard)
{

}

void
RIOT::_dump(Category category, std::ostream& os) const
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
RIOT::cacheInfo(RIOTInfo &result) const
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
RIOT::cacheStats(RIOTStats &result) const
{

}

i64
RIOT::getOption(Option option) const
{
    fatalError;
}

void
RIOT::checkOption(Option opt, i64 value)
{
    throw Error(VC64ERROR_OPT_UNSUPPORTED);
}

void
RIOT::setOption(Option opt, i64 value)
{
    fatalError;
}

}

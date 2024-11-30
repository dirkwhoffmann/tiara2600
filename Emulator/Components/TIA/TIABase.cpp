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
#include "TIA.h"
#include "Atari.h"
#include "IOUtils.h"

namespace tiara {

TIA::TIA(Atari &ref) : SubComponent(ref)
{
    subComponents = std::vector<CoreComponent *> {

        &audio[0],
        &audio[1]
    };
}

void
TIA::cacheInfo(TIAInfo &result) const
{
    result.posx = x;
    result.posy = y;

    for (isize i = 0; i < 64; i++) {
        result.regs[i] = spy(TIARegister(i));
    }
}

void
TIA::cacheStats(TIAStats &result) const
{

}

void
TIA::_dump(Category category, std::ostream& os) const
{
    using namespace util;

    if (category == Category::Config) {

        dumpConfig(os);
    }

    if (category == Category::State) {

        os << tab("X");
        os << dec(0) << std::endl;
        os << tab("Y");
        os << dec(0) << std::endl;
    }

    if (category == Category::Registers) {

        os << tab("AUDC0");
        os << hex(audio[0].audc) << std::endl;
        os << tab("AUDC1");
        os << hex(audio[1].audc) << std::endl;
        os << tab("AUDF0");
        os << hex(audio[0].audf) << std::endl;
        os << tab("AUDF1");
        os << hex(audio[1].audf) << std::endl;
        os << tab("AUDV0");
        os << hex(audio[0].audv) << std::endl;
        os << tab("AUDV1");
        os << hex(audio[1].audv) << std::endl;
    }
}

i64
TIA::getOption(Option opt) const
{
    switch (opt) {

        case OPT_TIA_REVISION:        return config.revision;
        case OPT_TIA_COLLISIONS:      return config.collMask;
        case OPT_TIA_REGLOCK:         return config.lockMask;
        case OPT_TIA_POWER_SAVE:      return config.powerSave;

        default:
            fatalError;
    }
}

void
TIA::checkOption(Option opt, i64 value)
{
    switch (opt) {

        case OPT_TIA_REVISION:

            if (!TIARevisionEnum::isValid(value)) {
                throw Error(VC64ERROR_OPT_INV_ARG, TIARevisionEnum::keyList());
            }
            break;

        case OPT_TIA_COLLISIONS:

            if (value < 0 || value > 0xFFFF) {
                throw Error(VC64ERROR_OPT_INV_ARG, "0x0000...0xFFFF");
            }
            break;

        case OPT_TIA_REGLOCK:
        case OPT_TIA_POWER_SAVE:

            break;

        default:
            throw Error(VC64ERROR_OPT_UNSUPPORTED);
    }
}

void
TIA::setOption(Option opt, i64 value)
{
    checkOption(opt, value);

    switch (opt) {

        case OPT_TIA_REVISION:

            if (config.revision != TIARevision(value)) {

                config.revision = TIARevision(value);
                monitor.updateColors();
                msgQueue.put(MSG_TIA_REVISION, value);
            }
            break;

        case OPT_TIA_COLLISIONS:

            config.collMask = u16(value);
            break;

        case OPT_TIA_REGLOCK:

            config.lockMask = u64(value);
            break;

        case OPT_TIA_POWER_SAVE:

            config.powerSave = bool(value);
            break;

        default:
            fatalError;
    }
}

}

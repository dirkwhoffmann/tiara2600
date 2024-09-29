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
#include "IOUtils.h"

namespace tiara {

TIA::TIA(C64 &ref) : SubComponent(ref)
{
    // initFuncTable();
}

void
TIA::cacheInfo(TIAInfo &result) const
{
    result.posx = 0;
    result.posy = 0;
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

    }
}

i64
TIA::getOption(Option option) const
{
    switch (option) {

        case OPT_TIA_REVISION:        return config.revision;
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
            return;

        case OPT_TIA_POWER_SAVE:

            return;

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

            config.revision = TIARevision(value);
            return;

        case OPT_TIA_POWER_SAVE:

            config.powerSave = bool(value);
            return;

        default:
            fatalError;
    }
}

}

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
#include "Memory.h"
#include "Atari.h"
#include "IOUtils.h"

namespace tiara {

void
Memory::_dump(Category category, std::ostream& os) const
{
    using namespace util;

    if (category == Category::Config) {

        dumpConfig(os);
    }

    if (category == Category::State) {

    }
}

void
Memory::cacheInfo(MemInfo &result) const
{
    {   SYNCHRONIZED

        for (isize i = 0; i < 32; i++) result.peekSrc[i] = peekSrc[i];
    }
}

i64
Memory::getOption(Option option) const
{
    switch (option) {

        case OPT_MEM_INIT_PATTERN:  return config.ramPattern;
        case OPT_MEM_HEATMAP:       return config.heatmap;

        default:
            fatalError;
    }
}

void
Memory::checkOption(Option opt, i64 value)
{
    switch (opt) {

        case OPT_MEM_INIT_PATTERN:

            if (!RamPatternEnum::isValid(value)) {
                throw Error(VC64ERROR_OPT_INV_ARG, RamPatternEnum::keyList());
            }
            return;

        case OPT_MEM_HEATMAP:

            return;

        default:
            throw Error(VC64ERROR_OPT_UNSUPPORTED);
    }
}

void
Memory::setOption(Option opt, i64 value)
{
    checkOption(opt, value);
    
    switch (opt) {

        case OPT_MEM_INIT_PATTERN:

            config.ramPattern = (RamPattern)value;
            return;

        case OPT_MEM_HEATMAP:

            config.heatmap = (bool)value;
            return;

        default:
            fatalError;
    }
}

}

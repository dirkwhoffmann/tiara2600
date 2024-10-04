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
#include "LogicAnalyzer.h"
#include "TIA.h"
#include "MsgQueue.h"

namespace tiara {

void
LogicAnalyzer::_dump(Category category, std::ostream& os) const
{
    using namespace util;

    if (category == Category::Config) {

        dumpConfig(os);
    }
}

i64
LogicAnalyzer::getOption(Option option) const
{
    switch (option) {

        case OPT_LA_ENABLE:     return (i64)config.enable;
        case OPT_LA_MODE:       return (i64)config.displayMode;
        case OPT_LA_OPACITY:    return (i64)config.opacity;
        case OPT_LA_CHANNEL0:   return (i64)probe[0];
        case OPT_LA_CHANNEL1:   return (i64)probe[1];
        case OPT_LA_CHANNEL2:   return (i64)probe[2];
        case OPT_LA_CHANNEL3:   return (i64)probe[3];

        default:
            fatalError;
    }
}

void
LogicAnalyzer::checkOption(Option opt, i64 value)
{
    switch (opt) {

        case OPT_LA_ENABLE:

            return;

        case OPT_LA_MODE:

            if (!LaDisplayModeEnum::isValid(value)) {
                throw Error(VC64ERROR_OPT_INV_ARG, LaDisplayModeEnum::keyList());
            }
            return;

        case OPT_LA_OPACITY:
        case OPT_LA_CHANNEL0:
        case OPT_LA_CHANNEL1:
        case OPT_LA_CHANNEL2:
        case OPT_LA_CHANNEL3:

            return;

        default:
            throw Error(VC64ERROR_OPT_UNSUPPORTED);
    }
}

void
LogicAnalyzer::setOption(Option opt, i64 value)
{
    checkOption(opt, value);

    switch (opt) {

        case OPT_LA_ENABLE:

            config.enable = value;
            tia.resetDmaTextures();
            tia.resetEmuTextures();
            msgQueue.put(MSG_DMA_DEBUG, value);
            return;

        case OPT_LA_MODE:

            config.displayMode = (LaDisplayMode)value;
            return;

        case OPT_LA_OPACITY:     config.opacity = (u8)value; return;
        case OPT_LA_CHANNEL0:    probe[0] = (Probe)value; return;
        case OPT_LA_CHANNEL1:    probe[1] = (Probe)value; return;
        case OPT_LA_CHANNEL2:    probe[2] = (Probe)value; return;
        case OPT_LA_CHANNEL3:    probe[3] = (Probe)value; return;

        default:
            fatalError;
    }
}

}

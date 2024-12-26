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
#include "IOUtils.h"
#include "TIA.h"
#include "MsgQueue.h"

namespace tiara {

void
LogicAnalyzer::_dump(Category category, std::ostream& os) const
{
    using namespace util;

    auto print = [&]() {

        for (int i = 0; i < beamtraps.elements(); i++) {

            auto bp = *beamtraps.guardNr(i);
            auto v = std::to_string(HI_WORD(bp.addr));
            auto h = std::to_string(LO_WORD(bp.addr));
            os << tab("Beamtrap " + std::to_string(i));
            os << "(" + v + "," + h + ")";

            if (!bp.enabled) os << " (Disabled)";
            else if (bp.ignore) os << " (Disabled for " << dec(bp.ignore) << " hits)";
            os << std::endl;
        }
    };

    if (category == Category::Config) {

        dumpConfig(os);
    }

    if (category == Category::Beamtraps) {

        if (beamtraps.elements()) {
            print();
        } else {
            os << "No beamtraps set" << std::endl;
        }
    }
}

i64
LogicAnalyzer::getOption(Option option) const
{
    switch (option) {

        case OPT_LA_ENABLE:     return (i64)config.enable;
        case OPT_LA_CHANNEL0:   return (i64)channel[0];
        case OPT_LA_CHANNEL1:   return (i64)channel[1];
        case OPT_LA_CHANNEL2:   return (i64)channel[2];
        case OPT_LA_CHANNEL3:   return (i64)channel[3];
        case OPT_LA_PROBE0:     return (i64)probe[0];
        case OPT_LA_PROBE1:     return (i64)probe[1];
        case OPT_LA_PROBE2:     return (i64)probe[2];
        case OPT_LA_PROBE3:     return (i64)probe[3];
        case OPT_LA_MODE:       return (i64)config.displayMode;
        case OPT_LA_OPACITY:    return (i64)config.opacity;

        default:
            fatalError;
    }
}

void
LogicAnalyzer::checkOption(Option opt, i64 value)
{
    switch (opt) {

        case OPT_LA_ENABLE:
        case OPT_LA_CHANNEL0:
        case OPT_LA_CHANNEL1:
        case OPT_LA_CHANNEL2:
        case OPT_LA_CHANNEL3:

            return;

        case OPT_LA_PROBE0:
        case OPT_LA_PROBE1:
        case OPT_LA_PROBE2:
        case OPT_LA_PROBE3:

            if (!ProbeEnum::isValid(value)) {
                throw Error(TIARA_ERROR_OPT_INV_ARG, ProbeEnum::keyList());
            }
            return;

        case OPT_LA_MODE:

            if (!LaDisplayModeEnum::isValid(value)) {
                throw Error(TIARA_ERROR_OPT_INV_ARG, LaDisplayModeEnum::keyList());
            }
            return;

        case OPT_LA_OPACITY:

            return;

        default:
            throw Error(TIARA_ERROR_OPT_UNSUPPORTED);
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
            break;

        case OPT_LA_CHANNEL0:   channel[0] = (bool)value; break;
        case OPT_LA_CHANNEL1:   channel[1] = (bool)value; break;
        case OPT_LA_CHANNEL2:   channel[2] = (bool)value; break;
        case OPT_LA_CHANNEL3:   channel[3] = (bool)value; break;

        case OPT_LA_PROBE0:     probe[0] = (Probe)value; break;
        case OPT_LA_PROBE1:     probe[1] = (Probe)value; break;
        case OPT_LA_PROBE2:     probe[2] = (Probe)value; break;
        case OPT_LA_PROBE3:     probe[3] = (Probe)value; break;

        case OPT_LA_MODE:

            config.displayMode = (LaDisplayMode)value;
            break;

        case OPT_LA_OPACITY:

            config.opacity = (u8)value;
            break;

        default:
            fatalError;
    }
}

}

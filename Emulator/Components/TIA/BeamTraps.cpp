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
#include "BeamTraps.h"
#include "Atari.h"

namespace tiara {

Beamtraps::Beamtraps(TIA& ref) : GuardList(ref.atari), tia(ref)
{

}

void
Beamtraps::setNeedsCheck(bool value)
{
    // printf("Beamtraps::setNeedsCheck(%d)\n", value);
    scheduleNextEvent();
}

void
Beamtraps::processEvent()
{
    printf("Beamtraps::serviceEvent()\n");
    tia.atari.setFlag(RL::BEAMTRAP);
    scheduleNextEvent();
}

void
Beamtraps::scheduleNextEvent()
{
    atari.cancel<SLOT_BTR>();

    for (isize i = 0, next = INT_MAX; i < elements(); i++) {

        if (const auto guard = guardNr(i); guard->enabled) {

            auto v = HI_WORD(guard->addr);
            auto h = LO_WORD(guard->addr);
            auto d = tia.diff(v, h) - 3;

            if (d > 0 && d < next) {

                next = d;
                atari.scheduleRel<SLOT_BTR>((d + 2) / 3, BTR_TRIGGER);
            }
        }
    }
}

void Beamtraps::sofHandler()
{
    scheduleNextEvent();
}

}

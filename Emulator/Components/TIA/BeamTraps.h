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

#include "GuardList.h"

#pragma once

namespace tiara {

class Beamtraps : public GuardList {

    class TIA &tia;

public:

    Beamtraps(TIA& ref);
    virtual ~Beamtraps() { }

    void setNeedsCheck(bool value) override;

    //
    // Processing events and commands
    //

public:

    // Processes an event from the BTR_SLOT
    void processEvent();

    // Schedules the next beam trap event
    void scheduleNextEvent();

    // Start-of-frame handler
    void sofHandler();
};

}

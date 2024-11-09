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

#pragma once

#include "TIAComponents.h"
#include "TIATypes.h"
#include "SubComponent.h"
#include "Constants.h"

namespace tiara {

class Missile final : CoreObject {

    const char *objectName() const { return "Missile"; }

    DualPhaseCounter<39> counter;
    isize siz{};
    bool ena{};
    bool resmp{};
    DualPhaseDelay<bool> start1;
    DualPhaseDelay<bool> start2;

public:

    void pokeNUSIZ(u8 val) { siz = (val >> 4) & 0x03; }
    void pokeENAM(u8 val) { ena = val & 0x02; }
    void pokeRESMP(u8 val) { resmp = val & 0x02; }

    bool get() const;

    void alwaysinline execute(bool clk, bool rst, class Player &player);
};

}

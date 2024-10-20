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

class Ball final : CoreObject {

    DualPhaseCounter<39> counter;
    DualPhaseDelay<bool> start2;
    bool blen[2]{};
    isize blsiz{};
    bool blvd{};

    const char *objectName() const { return "Ball"; }

public:

    void pokeENABL(u8 val) { blen[0] = GET_BIT(val, 1); }
    void pokeVDELBL(u8 val) { blvd = GET_BIT(val, 0); }
    void pokeCTLRPF(u8 val) { blsiz = val >> 4 & 0x3; }
    void vshift() { blen[1] = blen[0]; }

    bool get() const;

    void alwaysinline execute(bool clk, bool rst);
};

}

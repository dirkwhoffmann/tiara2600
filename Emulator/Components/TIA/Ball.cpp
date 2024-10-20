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
#include "Ball.h"

namespace tiara {

bool
Ball::get() const
{
    // Adapted from Jigo2600
    if (blen[blvd]) {

        auto start1 = counter.res;

        if (start1) {
            return (blsiz >= 2) || ((blsiz >= 1) && (counter.phase >= 2)) || (counter.phase == 2);
        } else if (start2.get()) {
            return blsiz == 3;
        }
    }
    return false;
}

void
Ball::execute(bool clk, bool rst)
{
    counter.execute(clk, rst);
    auto start1 = counter.res;
    start2.execute(counter.phi1(), counter.phi2(), start1);
}

}

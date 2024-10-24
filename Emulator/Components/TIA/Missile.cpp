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
#include "Missile.h"

namespace tiara {

bool
Missile::get() const
{
    if (ena && !resmp) {

        if (start1.get()) {
            return (siz >= 2) || ((siz >= 1) & (counter.phase >= 2)) || (counter.phase == 2);
        } else if (start2.get()) {
            return (siz == 3);
        }
    }
    return false;
}

void
Missile::execute(bool clk, bool rst)
{
    counter.execute(clk, rst); // TODO: || (rst && PL.getRESMP()));
    auto phi1 = counter.phi1();
    auto phi2 = counter.phi2();
    auto curr = counter.current;

    isize nusiz = 1; // PL.getNUSIZ();

    start1.execute(phi1, phi2, ((curr == 39)) ||
                 ((curr == 3) && (nusiz == 1 || nusiz == 3)) ||
                 ((curr == 7) && (nusiz == 2 || nusiz == 3 || nusiz == 6)) ||
                 ((curr == 15) && (nusiz == 4 || nusiz == 6)));
    start2.execute(phi1 , phi2, start1.get());
}

}

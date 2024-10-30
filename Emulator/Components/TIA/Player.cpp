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
#include "Player.h"

namespace tiara {

void
Player::execute(bool clk, bool rst)
{
    auto phi1 = counter.phi1();
    auto phi2 = counter.phi2();

    if (clk) {

        if (ena) {

            if (sc < 8) {
                sc++;
            } else if (start.get()) {
                sc = 0;
            }
        }
        if (nusiz == 5) {
            ena = (phi1 || phi2);
        } else if (nusiz == 7) {
            ena = phi2;
        } else {
            ena = true;
        }
    }

    counter.execute(clk, rst);
    phi1 = counter.phi1();
    phi2 = counter.phi2();

    auto current = counter.current;

    start.execute(phi1, phi2, (current == 39)
                  ? 1
                  : 2 * (((current == 3) && (nusiz == 1 || nusiz == 3)) ||
                         ((current == 7) &&
                          (nusiz == 2 || nusiz == 3 || nusiz == 6)) ||
                         ((current == 15) && (nusiz == 4 || nusiz == 6))));
}

bool
Player::get() const
{
    return sc < 8 ? GET_BIT(grp[vdelp], refp ? sc : 7 - sc) : false;
}

}

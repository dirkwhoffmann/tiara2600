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

#include "TIATypes.h"

namespace tiara {

template <int max> class DualPhaseCounter {

public:

    // Counter value
    isize current{};

    // Phase counter
    isize phase{};

    // Reset line
    bool res{};

    // Latched reset value
    bool resl{};

    void execute(bool clk, bool rst) {

        if (rst) {

            // Reset the phase counter and the latched reset value
            phase = 0;
            resl = true;
            return;
        }
        if (clk) {

            // Advance the phase counter
            phase = (phase + 1) & 0b11;

            // Advance or reset the actual counter
            if (phase == 2) {

                res = resl | (current == max);
                current = res ? 0 : current + 1;
                resl = false;
            }
        }
    }

    bool phi1() const { return phase == 0; }
    bool phi2() const { return phase == 2; }
};

}

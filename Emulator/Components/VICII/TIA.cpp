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
#include "TIA.h"

namespace tiara {

template <bool debug> void
TIA::execute()
{
    for (isize ccylce = 0; ccylce < 3; ccylce++) {

        // Check for the "Start HBlank" signal
        bool shb = hc.res;

        // Advance the beam position
        x++; if (shb && hc.phi2()) { x = 0; y++; }

        

    }
}

template void TIA::execute<false>();
template void TIA::execute<true>();

}

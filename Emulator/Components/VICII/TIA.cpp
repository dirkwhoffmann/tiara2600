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

#include "VICII.h"

namespace tiara {

template <bool debug> void
TIA::execute()
{
    for (isize ccylce = 0; ccylce < 3; ccylce++) {

        // Clock the horizontal counter
        hc.execute(true, false);

        // Check for the "Start HBlank" signal
        bool shb = hc.res;

        // Advance the beam position
        if (shb && hc.phi2()) { x = 0; y++; }

        // Remove later
        if (y == Texture::height) y = 0;

        // For now: Visualize the counter in the logic analyzer
        assert(x < Texture::width);
        assert(y < Texture::height);
        auto *p = vic.dmaTexture + y * Texture::width + x;

        /*
        *p =
        hc.phase == 0 ? 0xFF444444 :
        hc.phase == 1 ? 0xFF888888 :
        hc.phase == 2 ? 0xFFAAAAAA : 0xFFFFFFFF;
        */
        if (hc.phi1()) *p = 0xFF0000FF;
        if (hc.phi2()) *p = 0xFF00FFFF;

        x++;
    }
}

template void TIA::execute<false>();
template void TIA::execute<true>();

}

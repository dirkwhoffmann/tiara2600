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
#include "C64.h"

namespace tiara {

void
TIA::_initialize()
{

}

void
TIA::_didReset(bool hard)
{
    if (hard) {

        clearStats();

        // Reset the beam position
        x = y = 0;

        // Reset counters
        hc = { .phase = 1, .current = 56, .resl = false, .res = true };

        // Reset the screen buffers
        resetEmuTextures();
        resetDmaTextures();
        emuTexture = emuTexture1;
        dmaTexture = dmaTexture1;
    }
}

void
TIA::_trackOn()
{

}

void
TIA::_trackOff()
{

}

void
TIA::updatePalette()
{

}

u32 *
TIA::getTexture() const
{
    return emuTexture == emuTexture1 ? emuTexture2 : emuTexture1;
}

u32 *
TIA::getDmaTexture() const
{
    return dmaTexture == dmaTexture1 ? dmaTexture2 : dmaTexture1;
}

void
TIA::resetEmuTexture(isize nr)
{
    assert(nr == 1 || nr == 2);

    if (nr == 1) { resetTexture(emuTexture1); }
    if (nr == 2) { resetTexture(emuTexture2); }
}

void
TIA::resetDmaTexture(isize nr)
{
    assert(nr == 1 || nr == 2);

    u32 *p = nr == 1 ? dmaTexture1 : dmaTexture2;

    for (isize i = 0; i < Texture::height * Texture::width; i++) {
        p[i] = 0xFF000000;
    }
}

void
TIA::resetTexture(u32 *p)
{
    // Draw a checkerboard pattern
    for (isize y = 0; y < Texture::height; y++) {

        for (isize x = 0; x < Texture::width; x++) {

            isize pos = y * Texture::width + x;
            p[pos] = (y / 4) % 2 == (x / 3) % 2 ? 0xFF222222 : 0xFF444444;
        }
    }
}

void
TIA::drawPixel(isize x, isize y, u32 color)
{
    assert(x < Texture::width);
    assert(y < Texture::height);

    emuTexture[y * Texture::width + x] = color;
}

void
TIA::drawDebugPixel(isize x, isize y, u32 color)
{
    assert(x < Texture::width);
    assert(y < Texture::height);

    dmaTexture[y * Texture::width + x] = color;
}

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
        if (y == Texture::height) {

            y = 0;
            eofHandler();
            c64.setFlag(RL::SYNC_THREAD);
        }

        // For now: Visualize the counter in the logic analyzer
        assert(x < Texture::width);
        assert(y < Texture::height);
        /*
        *p =
        hc.phase == 0 ? 0xFF444444 :
        hc.phase == 1 ? 0xFF888888 :
        hc.phase == 2 ? 0xFFAAAAAA : 0xFFFFFFFF;
        */
        if (hc.phi1()) drawDebugPixel(x, y, 0xFF0000FF);
        if (hc.phi2()) drawDebugPixel(x, y, 0xFF00FFFF);

        x++;
    }
}
template void TIA::execute<false>();
template void TIA::execute<true>();

void
TIA::eofHandler()
{
    // Only proceed if the current frame hasn't been executed in headless mode
    if (c64.getHeadless()) return;

    // Run the logic Analyzer if enabled
    bool debug = logicAnalyzer.config.dmaDebug;
    if (debug) logicAnalyzer.computeOverlay(emuTexture, dmaTexture);

    // Switch texture buffers
    if (emuTexture == emuTexture1) {

        assert(dmaTexture == dmaTexture1);
        emuTexture = emuTexture2;
        dmaTexture = dmaTexture2;
        if (debug) { resetEmuTexture(2); resetDmaTexture(2); }

    } else {

        assert(emuTexture == emuTexture2);
        assert(dmaTexture == dmaTexture2);
        emuTexture = emuTexture1;
        dmaTexture = dmaTexture1;
        if (debug) { resetEmuTexture(1); resetDmaTexture(1); }
    }
}

}
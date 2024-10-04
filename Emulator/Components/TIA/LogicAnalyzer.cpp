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
#include "LogicAnalyzer.h"
#include "Emulator.h"

namespace tiara {

LogicAnalyzer::LogicAnalyzer(Atari &ref) : SubComponent(ref)
{

}

void
LogicAnalyzer::setColor(isize channel, GpuColor gpuColor)
{
    assert(channel < cnt);

    color[0][channel] = gpuColor.shade(0.3).abgr;
    color[1][channel] = gpuColor.shade(0.1).abgr;
    color[2][channel] = gpuColor.tint(0.1).abgr;
    color[3][channel] = gpuColor.tint(0.3).abgr;
}

void
LogicAnalyzer::setColor(isize channel, RgbColor color)
{
    setColor(channel, GpuColor(color));
}

void
LogicAnalyzer::setColor(isize channel, u32 abgr)
{
    // abgr &= 0x00FFFFFF;
    // abgr |= 0xFF000000;
    setColor(channel, GpuColor(abgr));
}

void
LogicAnalyzer::recordSignals()
{
    auto *p = tia.dmaTexture + tia.y * Texture::width + tia.x;

    for (isize i = cnt - 1; i >= 0; i--) {

        if (channel[i]) {

            switch (probe[i]) {

                case PROBE_PHI1:

                    if (tia.hc.phi1()) *p = color[0][i];
                    break;

                case PROBE_PHI2:

                    if (tia.hc.phi2()) *p = color[0][i];
                    break;

                case PROBE_RDY:

                    if (!tia.rdy) *p = color[0][i];
                    break;

                case PROBE_VSYNC:

                    if (tia.vs) *p = color[0][i];
                    break;

                case PROBE_VBLANK:

                    if (tia.vb) *p = color[0][i];
                    break;

                default:
                    fatalError;
            }
        }
    }
}

void
LogicAnalyzer::computeOverlay(u32 *emuTexture, u32 *dmaTexture)
{
    double weight = config.opacity / 255.0;
    
    switch (config.displayMode) {

        case LA_DISPLAY_MODE_FG_LAYER:

            for (isize y = 0; y < Texture::height; y++) {

                u32 *emu = emuTexture + (y * Texture::width);
                u32 *dma = dmaTexture + (y * Texture::width);

                for (isize x = 0; x < Texture::width; x++) {

                    if ((dma[x] & 0xFFFFFF) == 0) continue;
                    
                    GpuColor emuColor = emu[x];
                    GpuColor dmaColor = dma[x];
                    GpuColor mixColor = emuColor.mix(dmaColor, weight);
                    emu[x] = mixColor.abgr;
                }
            }
            break;

        case LA_DISPLAY_MODE_BG_LAYER:

            for (isize y = 0; y < Texture::height; y++) {

                u32 *emu = emuTexture + (y * Texture::width);
                u32 *dma = dmaTexture + (y * Texture::width);

                for (isize x = 0; x < Texture::width; x++) {

                    if ((dma[x] & 0xFFFFFF) != 0) {
                        emu[x] = dma[x];
                    } else {
                        GpuColor emuColor = emu[x];
                        GpuColor mixColor = emuColor.shade(weight);
                        emu[x] = mixColor.abgr;
                    }
                }
            }
            break;

        case LA_DISPLAY_MODE_ODD_EVEN_LAYERS:

            for (isize y = 0; y < Texture::height; y++) {

                u32 *emu = emuTexture + (y * Texture::width);
                u32 *dma = dmaTexture + (y * Texture::width);

                for (isize x = 0; x < Texture::width; x++) {

                    GpuColor emuColor = emu[x];
                    GpuColor dmaColor = dma[x];
                    GpuColor mixColor = dmaColor.mix(emuColor, weight);
                    emu[x] = mixColor.abgr;
                }
            }
            break;
            
        default:
            fatalError;
    }
}

}

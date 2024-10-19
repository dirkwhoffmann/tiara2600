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

const RecordedSignals *
LogicAnalyzer::getData(isize line) const
{
    assert(line < Texture::height);
    return data[line];
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
    auto x = tia.x;
    auto y = tia.y;

    // Record signals
    data[y][x].addrBus = atari.addrBus;
    data[y][x].dataBus = atari.dataBus;
    data[y][x].phi1 = tia.hc.phi1();
    data[y][x].phi2 = tia.hc.phi2();
    data[y][x].rdy = tia.rdy;
    data[y][x].vsync = tia.vs;
    data[y][x].vblank = tia.vb;
    data[y][x].hblank = tia.hb.get();
    data[y][x].intim = pia.spyReg(PIA_INTIM);

    // Update the overlay texture
    auto *p = tia.dmaTexture + tia.y * Texture::width + tia.x;

    for (isize i = cnt - 1; i >= 0; i--) {

        if (channel[i]) {

            switch (probe[i]) {

                case PROBE_NONE:
                case PROBE_ADDR_BUS:
                case PROBE_DATA_BUS:

                    break;

                case PROBE_PHI1:

                    if (data[y][x].phi1) *p = color[0][i];
                    break;

                case PROBE_PHI2:

                    if (data[y][x].phi2) *p = color[0][i];
                    break;

                case PROBE_RDY:

                    if (!data[y][x].rdy) *p = color[0][i];
                    break;

                case PROBE_VSYNC:

                    if (data[y][x].vsync) *p = color[0][i];
                    break;

                case PROBE_VBLANK:

                    if (data[y][x].vblank) *p = color[0][i];
                    break;

                case PROBE_HBLANK:

                    if (!data[y][x].hblank) *p = color[0][i];
                    break;

                case PROBE_INTIM:

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

void
LogicAnalyzer::sofHandler(isize y)
{
    assert(y < Texture::height);
    
    beamtraps.sofHandler();

    // y can wrap over in the middle of a scanline. Copy the already recorded
    // part of the current line over to line 0.
    for (isize i = 0; i < tia.getX(); i++) data[0][i] = data[y][i];
}

void
LogicAnalyzer::eofHandler()
{

}

}

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
#include "DmaDebugger.h"
#include "Emulator.h"

namespace tiara {

DmaDebugger::DmaDebugger(C64 &ref) : SubComponent(ref)
{

}

void
DmaDebugger::setDmaDebugColor(MemAccess type, GpuColor color)
{
    assert_enum(MemAccess, type);
    
    config.dmaColor[type] = color.abgr;

    debugColor[type][0] = color.shade(0.3).abgr;
    debugColor[type][1] = color.shade(0.1).abgr;
    debugColor[type][2] = color.tint(0.1).abgr;
    debugColor[type][3] = color.tint(0.3).abgr;
}

void
DmaDebugger::setDmaDebugColor(MemAccess type, RgbColor color)
{
    setDmaDebugColor(type, GpuColor(color));
}

/*
void
DmaDebugger::visualizeDma(isize offset, u8 data, MemAccess type)
{
    visualizeDma((u32 *)vic.dmaTexturePtr + offset, data, type);
}

void
DmaDebugger::visualizeDma(u32 *p, u8 data, MemAccess type)
{
    if (config.dmaChannel[type]) {
        
        p[3] = debugColor[type][data & 0b11]; data >>= 2;
        p[2] = debugColor[type][data & 0b11]; data >>= 2;
        p[1] = debugColor[type][data & 0b11]; data >>= 2;
        p[0] = debugColor[type][data & 0b11];
    }
}
 */

void
DmaDebugger::computeOverlay(u32 *emuTexture, u32 *dmaTexture)
{
    double weight = config.dmaOpacity / 255.0;
    
    switch (config.dmaDisplayMode) {

        case DMA_DISPLAY_MODE_FG_LAYER:

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

        case DMA_DISPLAY_MODE_BG_LAYER:
            
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

        case DMA_DISPLAY_MODE_ODD_EVEN_LAYERS:
            
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

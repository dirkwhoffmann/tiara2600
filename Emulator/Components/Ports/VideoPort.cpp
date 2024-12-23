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
#include "VideoPort.h"
#include "TIA.h"

namespace tiara {

VideoPort::VideoPort(Atari &ref) : SubComponent(ref)
{

};

TIARevision
VideoPort::predict() const
{
    auto current = tia.getConfig().revision;

    if (pal == 32) return current == TIA_SECAM ? TIA_SECAM : TIA_PAL;
    if (ntsc == 32) return TIA_NTSC;

    return current;
}

u32 *
VideoPort::getTexture() const
{
    if (isPoweredOff()) {
        return config.whiteNoise ? getNoiseTexture() : getBlankTexture();
    } else {
        return tia.getTexture();
    }
}

u32 *
VideoPort::getDmaTexture() const
{
    return tia.getDmaTexture();
}

u32 *
VideoPort::getNoiseTexture() const
{
    static u32 *noise = nullptr;
    constexpr isize noiseSize = 16 * 512 * 512;

    if (!noise) {

        noise = new u32[noiseSize];

        for (isize i = 0; i < noiseSize; i++) {
            noise[i] = rand() % 2 ? 0xFF000000 : 0xFFFFFFFF;
        }
    }

    int offset = rand() % (512 * 512);
    return noise + offset;
}

u32 *
VideoPort::getBlankTexture() const
{
    static u32 *blank = nullptr;

    if (!blank) {

        blank = new u32[Texture::height * Texture::width];

        for (isize i = 0; i < Texture::height * Texture::width; i++) {
            blank[i] = 0xFF000000;
        }
    }

    return blank;
}

void
VideoPort::eofHandler()
{
    const isize tolerance = 20;
    auto y = tia.y;

    if (y > NTSC::HEIGHT - tolerance && y < NTSC::HEIGHT + tolerance) {

        if (ntsc <= 32) ntsc++;
        if (pal > 0) pal--;
    }
    if (y > PAL::HEIGHT - tolerance && y < PAL::HEIGHT + tolerance) {

        if (ntsc > 0) ntsc--;
        if (pal <= 32) pal++;
    }
}

}

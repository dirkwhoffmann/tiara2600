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
#include "Monitor.h"
#include "TIA.h"
#include <cmath>

namespace tiara {

// Base colors (from jigo2600)
static u32 baseColor[3][128] = {
    {
        // NTSC
        0xFF000000, 0xFF404040, 0xFF6C6C6C, 0xFF909090, 0xFFB0B0B0, 0xFFC8C8C8, 0xFFDCDCDC,
        0xFFECECEC, 0xFF444400, 0xFF646410, 0xFF848424, 0xFFA0A034, 0xFFB8B840, 0xFFD0D050,
        0xFFE8E85C, 0xFFFCFC68, 0xFF702800, 0xFF844414, 0xFF985C28, 0xFFAC783C, 0xFFBC8C4C,
        0xFFCCA05C, 0xFFDCB468, 0xFFECC878, 0xFF841800, 0xFF983418, 0xFFAC5030, 0xFFC06848,
        0xFFD0805C, 0xFFE09470, 0xFFECA880, 0xFFFCBC94, 0xFF880000, 0xFF9C2020, 0xFFB03C3C,
        0xFFC05858, 0xFFD07070, 0xFFE08888, 0xFFECA0A0, 0xFFFCB4B4, 0xFF78005C, 0xFF8C2074,
        0xFFA03C88, 0xFFB0589C, 0xFFC070B0, 0xFFD084C0, 0xFFDC9CD0, 0xFFECB0E0, 0xFF480078,
        0xFF602090, 0xFF783CA4, 0xFF8C58B8, 0xFFA070CC, 0xFFB484DC, 0xFFC49CEC, 0xFFD4B0FC,
        0xFF140084, 0xFF302098, 0xFF4C3CAC, 0xFF6858C0, 0xFF7C70D0, 0xFF9488E0, 0xFFA8A0EC,
        0xFFBCB4FC, 0xFF000088, 0xFF1C209C, 0xFF3840B0, 0xFF505CC0, 0xFF6874D0, 0xFF7C8CE0,
        0xFF90A4EC, 0xFFA4B8FC, 0xFF00187C, 0xFF1C3890, 0xFF3854A8, 0xFF5070BC, 0xFF6888CC,
        0xFF7C9CDC, 0xFF90B4EC, 0xFFA4C8FC, 0xFF002C5C, 0xFF1C4C78, 0xFF386890, 0xFF5084AC,
        0xFF689CC0, 0xFF7CB4D4, 0xFF90CCE8, 0xFFA4E0FC, 0xFF003C2C, 0xFF1C5C48, 0xFF387C64,
        0xFF509C80, 0xFF68B494, 0xFF7CD0AC, 0xFF90E4C0, 0xFFA4FCD4, 0xFF003C00, 0xFF205C20,
        0xFF407C40, 0xFF5C9C5C, 0xFF74B474, 0xFF8CD08C, 0xFFA4E4A4, 0xFFB8FCB8, 0xFF143800,
        0xFF345C1C, 0xFF507C38, 0xFF6C9850, 0xFF84B468, 0xFF9CCC7C, 0xFFB4E490, 0xFFC8FCA4,
        0xFF2C3000, 0xFF4C501C, 0xFF687034, 0xFF848C4C, 0xFF9CA864, 0xFFB4C078, 0xFFCCD488,
        0xFFE0EC9C, 0xFF442800, 0xFF644818, 0xFF846830, 0xFFA08444, 0xFFB89C58, 0xFFD0B46C,
        0xFFE8CC7C, 0xFFFCE08C

    },{

        // PAL
        0xFF000000, 0xFF282828, 0xFF505050, 0xFF747474, 0xFF949494, 0xFFB4B4B4, 0xFFD0D0D0,
        0xFFECECEC, 0xFF000000, 0xFF282828, 0xFF505050, 0xFF747474, 0xFF949494, 0xFFB4B4B4,
        0xFFD0D0D0, 0xFFECECEC, 0xFF805800, 0xFF947020, 0xFFA8843C, 0xFFBC9C58, 0xFFCCAC70,
        0xFFDCC084, 0xFFECD09C, 0xFFFCE0B0, 0xFF445C00, 0xFF5C7820, 0xFF74903C, 0xFF8CAC58,
        0xFFA0C070, 0xFFB0D484, 0xFFC4E89C, 0xFFD4FCB0, 0xFF703400, 0xFF885020, 0xFFA0683C,
        0xFFB48458, 0xFFC89870, 0xFFDCAC84, 0xFFECC09C, 0xFFFCD4B0, 0xFF006414, 0xFF208034,
        0xFF3C9850, 0xFF58B06C, 0xFF70C484, 0xFF84D89C, 0xFF9CE8B4, 0xFFB0FCC8, 0xFF700014,
        0xFF882034, 0xFFA03C50, 0xFFB4586C, 0xFFC87084, 0xFFDC849C, 0xFFEC9CB4, 0xFFFCB0C8,
        0xFF005C5C, 0xFF207474, 0xFF3C8C8C, 0xFF58A4A4, 0xFF70B8B8, 0xFF84C8C8, 0xFF9CDCDC,
        0xFFB0ECEC, 0xFF70005C, 0xFF842074, 0xFF943C88, 0xFFA8589C, 0xFFB470B0, 0xFFC484C0,
        0xFFD09CD0, 0xFFE0B0E0, 0xFF003C70, 0xFF1C5888, 0xFF3874A0, 0xFF508CB4, 0xFF68A4C8,
        0xFF7CB8DC, 0xFF90CCEC, 0xFFA4E0FC, 0xFF580070, 0xFF6C2088, 0xFF803CA0, 0xFF9458B4,
        0xFFA470C8, 0xFFB484DC, 0xFFC49CEC, 0xFFD4B0FC, 0xFF002070, 0xFF1C3C88, 0xFF3858A0,
        0xFF5074B4, 0xFF6888C8, 0xFF7CA0DC, 0xFF90B4EC, 0xFFA4C8FC, 0xFF3C0080, 0xFF542094,
        0xFF6C3CA8, 0xFF8058BC, 0xFF9470CC, 0xFFA884DC, 0xFFB89CEC, 0xFFC8B0FC, 0xFF000088,
        0xFF20209C, 0xFF3C3CB0, 0xFF5858C0, 0xFF7070D0, 0xFF8484E0, 0xFF9C9CEC, 0xFFB0B0FC,
        0xFF000000, 0xFF282828, 0xFF505050, 0xFF747474, 0xFF949494, 0xFFB4B4B4, 0xFFD0D0D0,
        0xFFECECEC, 0xFF000000, 0xFF282828, 0xFF505050, 0xFF747474, 0xFF949494, 0xFFB4B4B4,
        0xFFD0D0D0, 0xFFECECEC

    },{

        // SECAM
        0xFF000000, 0xFF2121FF, 0xFFF03C79, 0xFFFF50FF, 0xFF7FFF00, 0xFF7FFFFF, 0xFFFFFF3F,
        0xFFFFFFFF, 0xFF000000, 0xFF2121FF, 0xFFF03C79, 0xFFFF50FF, 0xFF7FFF00, 0xFF7FFFFF,
        0xFFFFFF3F, 0xFFFFFFFF, 0xFF000000, 0xFF2121FF, 0xFFF03C79, 0xFFFF50FF, 0xFF7FFF00,
        0xFF7FFFFF, 0xFFFFFF3F, 0xFFFFFFFF, 0xFF000000, 0xFF2121FF, 0xFFF03C79, 0xFFFF50FF,
        0xFF7FFF00, 0xFF7FFFFF, 0xFFFFFF3F, 0xFFFFFFFF, 0xFF000000, 0xFF2121FF, 0xFFF03C79,
        0xFFFF50FF, 0xFF7FFF00, 0xFF7FFFFF, 0xFFFFFF3F, 0xFFFFFFFF, 0xFF000000, 0xFF2121FF,
        0xFFF03C79, 0xFFFF50FF, 0xFF7FFF00, 0xFF7FFFFF, 0xFFFFFF3F, 0xFFFFFFFF, 0xFF000000,
        0xFF2121FF, 0xFFF03C79, 0xFFFF50FF, 0xFF7FFF00, 0xFF7FFFFF, 0xFFFFFF3F, 0xFFFFFFFF,
        0xFF000000, 0xFF2121FF, 0xFFF03C79, 0xFFFF50FF, 0xFF7FFF00, 0xFF7FFFFF, 0xFFFFFF3F,
        0xFFFFFFFF, 0xFF000000, 0xFF2121FF, 0xFFF03C79, 0xFFFF50FF, 0xFF7FFF00, 0xFF7FFFFF,
        0xFFFFFF3F, 0xFFFFFFFF, 0xFF000000, 0xFF2121FF, 0xFFF03C79, 0xFFFF50FF, 0xFF7FFF00,
        0xFF7FFFFF, 0xFFFFFF3F, 0xFFFFFFFF, 0xFF000000, 0xFF2121FF, 0xFFF03C79, 0xFFFF50FF,
        0xFF7FFF00, 0xFF7FFFFF, 0xFFFFFF3F, 0xFFFFFFFF, 0xFF000000, 0xFF2121FF, 0xFFF03C79,
        0xFFFF50FF, 0xFF7FFF00, 0xFF7FFFFF, 0xFFFFFF3F, 0xFFFFFFFF, 0xFF000000, 0xFF2121FF,
        0xFFF03C79, 0xFFFF50FF, 0xFF7FFF00, 0xFF7FFFFF, 0xFFFFFF3F, 0xFFFFFFFF, 0xFF000000,
        0xFF2121FF, 0xFFF03C79, 0xFFFF50FF, 0xFF7FFF00, 0xFF7FFFFF, 0xFFFFFF3F, 0xFFFFFFFF,
        0xFF000000, 0xFF2121FF, 0xFFF03C79, 0xFFFF50FF, 0xFF7FFF00, 0xFF7FFFFF, 0xFFFFFF3F,
        0xFFFFFFFF, 0xFF000000, 0xFF2121FF, 0xFFF03C79, 0xFFFF50FF, 0xFF7FFF00, 0xFF7FFFFF,
        0xFFFFFF3F, 0xFFFFFFFF
    }
};

void
Monitor::updateColors()
{
    isize rev = tia.getConfig().revision;
    assert(rev >= 0 && rev <= 2);

    // Iterate through all 128 colors
    for (isize i = 0; i < 128; i++) {

        u8 b = (baseColor[rev][i] >> 0) & 0xFF;
        u8 g = (baseColor[rev][i] >> 8) & 0xFF;
        u8 r = (baseColor[rev][i] >> 16) & 0xFF;

        // Adjust the base color according to the current video settings
        adjustRGB(r, g, b);

        // Update the lookup table
        color[i] = HI_HI_LO_LO(0xFF, b, g, r);
    }
}

u32
Monitor::getColor(isize nr)
{
    assert(nr >= 0 && nr <= 127);
    return color[nr];
}

void
Monitor::adjustRGB(u8 &r, u8 &g, u8 &b)
{
    // Normalize adjustment parameters
    double brightness =  config.brightness - 50.0;
    double contrast = config.contrast / 100.0;
    double saturation = config.saturation / 50.0;

    // Convert RGB to YUV
    double y =  0.299 * r + 0.587 * g + 0.114 * b;
    double u = -0.147 * r - 0.289 * g + 0.436 * b;
    double v =  0.615 * r - 0.515 * g - 0.100 * b;

    // Adjust saturation
    u *= saturation;
    v *= saturation;

    // Apply contrast
    y *= contrast;
    u *= contrast;
    v *= contrast;

    // Apply brightness
    y += brightness;

    // Translate to monochrome if applicable
    switch(config.palette) {

        case PALETTE_BLACK_WHITE:
            u = 0.0;
            v = 0.0;
            break;

        case PALETTE_PAPER_WHITE:
            u = -128.0 + 120.0;
            v = -128.0 + 133.0;
            break;

        case PALETTE_GREEN:
            u = -128.0 + 29.0;
            v = -128.0 + 64.0;
            break;

        case PALETTE_AMBER:
            u = -128.0 + 24.0;
            v = -128.0 + 178.0;
            break;

        case PALETTE_SEPIA:
            u = -128.0 + 97.0;
            v = -128.0 + 154.0;
            break;

        default:
            assert(config.palette == PALETTE_COLOR);
    }

    // Convert YUV to RGB
    double newR = y             + 1.140 * v;
    double newG = y - 0.396 * u - 0.581 * v;
    double newB = y + 2.029 * u;
    newR = std::max(std::min(newR, 255.0), 0.0);
    newG = std::max(std::min(newG, 255.0), 0.0);
    newB = std::max(std::min(newB, 255.0), 0.0);

    // Apply Gamma correction for PAL models
    /*
     r = gammaCorrect(r, 2.8, 2.2);
     g = gammaCorrect(g, 2.8, 2.2);
     b = gammaCorrect(b, 2.8, 2.2);
     */

    r = u8(newR);
    g = u8(newG);
    b = u8(newB);
}

void
Monitor::drawPalette(u32 *dst, isize w, isize h, isize gap) const
{
    isize width = 8 * w + 9 * gap;
    isize height = 16 * h + 17 * gap;
    u32 gapColor = 0xFF000000;

    auto drawBlock = [&](isize y, isize x, u32 color) {

        for (isize i = 0; i < h; i++) {
            u32 *p = dst + (y + i) * width + x;
            for (isize j = 0; j < w; j++) { p[j] = color; }
        }
    };

    // Clear buffer
    for (isize i = 0; i < width * height; i++) dst[i] = gapColor;

    // Draw color blocks
    for (isize y = 0; y < 16; y++) {
        for (isize x = 0; x < 8; x++) {
            drawBlock(y * h + (y + 1) * gap, x * w + (x + 1) * gap, color[8 * y + x]);
        }
    }
}


}

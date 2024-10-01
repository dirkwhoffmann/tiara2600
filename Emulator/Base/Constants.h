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
/// @file
///
#pragma once

#include "BasicTypes.h"

/** Tiara project namespace
 */
namespace tiara {

static const long TIA_CYCLES_PER_LINE   = 228;
static const long CPU_CYCLES_PER_LINE   = 76;

static const long FIRST_VISIBLE_PIXEL   = 68;
static const long FIRST_VISIBLE_LINE    = 40;
static const long VISIBLE_WIDTH         = 160;

namespace NTSC {

static const long FPS                   = 50;

static const long TIA_CLOCK_FREQUENCY   = 3579545;   ///< Color clock frequency in Hz
static const long TIA_CYCLES_PER_SEC    = TIA_CLOCK_FREQUENCY;

static const long CPU_CLOCK_FREQUENCY   = 1193182;   ///< Color clock divided by three
static const long CPU_CYCLES_PER_SEC    = CPU_CLOCK_FREQUENCY;

static const long TIA_CYCLES_PER_LINE   = tiara::TIA_CYCLES_PER_LINE;
static const long CPU_CYCLES_PER_LINE   = tiara::CPU_CYCLES_PER_LINE;

static const long WIDTH                 = tiara::TIA_CYCLES_PER_LINE;
static const long HEIGHT                = 262;
static const long FIRST_VISIBLE_PIXEL   = tiara::FIRST_VISIBLE_PIXEL;
static const long FIRST_VISIBLE_LINE    = tiara::FIRST_VISIBLE_LINE;
static const long VISIBLE_WIDTH         = tiara::VISIBLE_WIDTH;
static const long VISIBLE_HEIGHT        = 192;

}
namespace PAL {

static const long FPS                   = 60;

static const long TIA_CLOCK_FREQUENCY   = 3546894;   ///< Color clock frequency in Hz
static const long TIA_CYCLES_PER_SEC    = TIA_CLOCK_FREQUENCY;

static const long CPU_CLOCK_FREQUENCY   = 1182298;   ///< Color clock divided by three
static const long CPU_CYCLES_PER_SEC    = CPU_CLOCK_FREQUENCY;

static const long TIA_CYCLES_PER_LINE   = tiara::TIA_CYCLES_PER_LINE;
static const long CPU_CYCLES_PER_LINE   = tiara::CPU_CYCLES_PER_LINE;

static const long WIDTH                 = tiara::TIA_CYCLES_PER_LINE;
static const long HEIGHT                = 312;
static const long FIRST_VISIBLE_PIXEL   = tiara::FIRST_VISIBLE_PIXEL;
static const long FIRST_VISIBLE_LINE    = tiara::FIRST_VISIBLE_LINE;
static const long VISIBLE_WIDTH         = tiara::VISIBLE_WIDTH;
static const long VISIBLE_HEIGHT        = 228;

}

/*
// Horizontal parameters (measured in pixels)
static const long HBLANK_PIXELS_LEFT    = 104;      ///< Left HBLANK width in pixels
static const long BORDER_PIXELS_LEFT    = 32;       ///< Left border width in pixels
static const long CANVAS_PIXELS         = 320;      ///< Main canvas width in pixels
static const long BORDER_PIXELS_RIGHT   = 32;       ///< Right border width in pixels
static const long HBLANK_PIXELS_RIGHT   = 16;       ///< Right HBLANK width in pixels

// Derived values
static const long FIRST_VISIBLE_PIXEL   = 104;      ///< 104
static const long VISIBLE_PIXELS        = 384;      ///<       32 + 320 + 32
static const long LAST_VISIBLE_PIXEL    = 487;      ///< 104 + 32 + 320 + 31
static const long PIXELS_PER_LINE       = 504;      ///< 104 + 32 + 320 + 32 + 16

// Vertical parameters
static const long FIRST_VISIBLE_LINE    = 16;       ///< First line after VBLANK
*/


/** NTSC related constants
 */
/*
namespace NTSC {

// Clock frequency in Hz
static const long CLOCK_FREQUENCY       = 1022727;  ///< Clock frequency in Hz
static const long CYCLES_PER_SECOND     = CLOCK_FREQUENCY;  ///< CPU cycles per seconds

// Pixel aspect ratios
static const double ASPECT_RATIO        = 0.7500;   ///< Pixel aspect ratio

// Horizontal parameters (measured in cycles)
static const long HBLANK_CYCLES_LEFT    = 13;       ///< Left HBLANK width in cycles
static const long BORDER_CYCLES_LEFT    = 4;        ///< Left border width in cycles
static const long CANVAS_CYCLES         = 40;       ///< Main canvas width in cycles
static const long BORDER_CYCLES_RIGHT   = 4;        ///< Right border width in cycles
static const long HBLANK_CYCLES_RIGHT   = 4;        ///< Right HBLANK width in cycles

// Derived values
static const long CYCLES_PER_LINE       = 65;       ///< 13 + 4 + 40 + 4 + 4

// Horizontal parameters (measured in pixels)
static const long HBLANK_PIXELS_LEFT    = 104;      ///< Left HBLANK width in pixels
static const long BORDER_PIXELS_LEFT    = 32;       ///< Left border width in pixels
static const long CANVAS_PIXELS         = 320;      ///< Main canvas width in pixels
static const long BORDER_PIXELS_RIGHT   = 32;       ///< Right border width in pixels
static const long HBLANK_PIXELS_RIGHT   = 32;       ///< Right HBLANK width in pixels

// Derived values
static const long FIRST_VISIBLE_PIXEL   = 104;      ///< 104
static const long VISIBLE_PIXELS        = 384;      ///<       32 + 320 + 32
static const long LAST_VISIBLE_PIXEL    = 487;      ///< 104 + 32 + 320 + 31
static const long PIXELS_PER_LINE       = 520;      ///< 104 + 32 + 320 + 32 + 32

// Vertical parameters
static const long FIRST_VISIBLE_LINE    = 16;       ///< First line after VBLANK

}
*/

/** Emulator texture parameters
 */
namespace Texture {

/// Height of the emulator texture in texels
static const long height                    = 312;

/// Width of the emulator texture in texels
// static const long width                     = 520;
static const long width                     = 228;

}

}

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

#pragma once

#include "BasicTypes.h"
#include "SamplerTypes.h"

namespace tiara {

//
// Structures
//

typedef struct
{
    // Selects how the audio buffer is resampled to match the target frequency
    SamplingMethod sampling;
    
    // Channel volumes
    i64 vol[4];

    // Channel pan factors
    i64 pan[4];

    // Master volume (left and right channel)
    i64 volL;
    i64 volR;
}

AudioPortConfig;

typedef struct
{

}
AudioPortInfo;

typedef struct
{
    // Current ring buffer fill level
    double fillLevel;

    // Number of buffer underflows since power up
    u64 bufferUnderflows;

    // Number of buffer overflows since power up
    u64 bufferOverflows;
}
AudioPortStats;

}

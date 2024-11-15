/// -----------------------------------------------------------------------------
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

#pragma once

// #include "BasicTypes.h"
#include "SamplerTypes.h"
#include "AtariTypes.h"
#include "Constants.h"
#include "RingBuffer.h"
#include "Reflection.h"

namespace tiara {

/* This buffer type temporarily stores the sound samples produced by TIA's
 * audio circuit. Each sample is tagged with the cycle in which the sample
 * has been generated. The timing information will be picked up by the
 * resampler to generate to actual waveform in the frequency required by the
 * host machine.
 */

struct Sampler : util::SortedRingBuffer <i16, Texture::texels> {

    // Initializes the ring buffer with a single dummy element
    void reset();

    // Interpolates a sound sample for the specified target cycle
    template <SamplingMethod method> i16 interpolate(Cycle clock);

    // Returns true if there are at least two sound samples
    bool isActive() { return count() != 1; }
};

}

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
#include "Emulator.h"

namespace tiara {

bool
AudioPort::isMuted() const
{
    if (volL.isFading() || volR.isFading()) return false;
    return volL + volR == 0.0 || vol[0] + vol[1] + vol[2] + vol[3] == 0.0;
}

/*
void
AudioPort::alignWritePtr()
{
    this->align(this->cap() / 2);
}
*/

void
AudioPort::handleBufferUnderflow()
{
    // There are two common scenarios in which buffer underflows occur:
    //
    // (1) The consumer runs slightly faster than the producer.
    // (2) The producer is halted or not startet yet.

    // Wipe out the buffer and reset the write pointer
    stream.clear(SamplePair{0,0});
    stream.alignWritePtr();

    // Determine the elapsed seconds since the last pointer adjustment
    auto elapsedTime = util::Time::now() - lastAlignment;
    lastAlignment = util::Time::now();

    // Check for condition (1)
    if (elapsedTime.asSeconds() > 10.0) {

        /*
        // Increase the sample rate based on what we've measured
        sampleRateCorrection += count() / elapsedTime.asSeconds();
         */
        stats.bufferUnderflows++;
        warn("Last underflow: %f seconds ago\n", elapsedTime.asSeconds());
        // warn("New sample rate correction: %f\n", sampleRateCorrection);
    }
}

void
AudioPort::handleBufferOverflow()
{
    // There are two common scenarios in which buffer overflows occur:
    //
    // (1) The consumer runs slightly slower than the producer
    // (2) The consumer is halted or not startet yet

    // Reset the write pointer
    stream.alignWritePtr();

    // Determine the number of elapsed seconds since the last adjustment
    auto elapsedTime = util::Time::now() - lastAlignment;
    lastAlignment = util::Time::now();

    // Adjust the sample rate, if condition (1) holds
    if (elapsedTime.asSeconds() > 10.0) {

        /*
        // Decrease the sample rate based on what we've measured
        sampleRateCorrection -= count() / elapsedTime.asSeconds();
         */
        stats.bufferOverflows++;
        warn("Last overflow: %f seconds ago\n", elapsedTime.asSeconds());
        // warn("New sample rate correction: %f\n", sampleRateCorrection);
    }
}

/*
void
AudioPort::clamp(isize maxSamples)
{
    SYNCHRONIZED

    while (count() > maxSamples) read();
}
*/
/*
void
AudioPort::generateSamples()
{
    SYNCHRONIZED

}
*/

void
AudioPort::fadeOut()
{
    stream.eliminateCracks();
    volL.current = 0;
    volR.current = 0;
}

isize
AudioPort::copyMono(float *buffer, isize n)
{
    // Copy sound samples
    auto cnt = stream.copyMono(buffer, n);
    stats.consumedSamples += cnt;

    // Check for a buffer underflow
    if (cnt < n) handleBufferUnderflow();

    return cnt;
}

isize
AudioPort::copyStereo(float *left, float *right, isize n)
{
    // Inform the sample rate detector about the number of requested samples
    // detector.feed(n);

    // Copy sound samples
    auto cnt = stream.copyStereo(left, right, n);
    stats.consumedSamples += cnt;

    // Check for a buffer underflow
    if (cnt < n) handleBufferUnderflow();

    return cnt;
}

isize
AudioPort::copyInterleaved(float *buffer, isize n)
{
    // Copy sound samples
    auto cnt = stream.copyInterleaved(buffer, n);
    stats.consumedSamples += cnt;

    // Check for a buffer underflow
    if (cnt < n) handleBufferUnderflow();

    return cnt;
}

}

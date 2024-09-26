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

void
AudioPort::alignWritePtr()
{
    this->align(this->cap() / 2);
}

void
AudioPort::handleBufferUnderflow()
{
    // There are two common scenarios in which buffer underflows occur:
    //
    // (1) The consumer runs slightly faster than the producer.
    // (2) The producer is halted or not startet yet.

    trace(AUDBUF_DEBUG, "BUFFER UNDERFLOW (r: %ld w: %ld)\n", r, w);

    // Wipe out the buffer and reset the write pointer
    clear(SamplePair{0,0});
    alignWritePtr();

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

    trace(AUDBUF_DEBUG, "BUFFER OVERFLOW (r: %ld w: %ld)\n", r, w);

    // Reset the write pointer
    alignWritePtr();

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

void 
AudioPort::clamp(isize maxSamples)
{
    SYNCHRONIZED

    while (count() > maxSamples) read();
}

void
AudioPort::generateSamples()
{
    SYNCHRONIZED

}

void
AudioPort::fadeOut()
{
    SYNCHRONIZED

    debug(AUDVOL_DEBUG, "Fading out (%ld samples)...\n", count());

    volL.set(0.0);
    volR.set(0.0);

    float scale = 1.0f;
    float delta = 1.0f / count();

    // Rescale the existing samples
    for (isize i = begin(); i != end(); i = next(i)) {

        scale -= delta;
        assert(scale >= -0.1 && scale < 1.0);

        elements[i].l *= scale;
        elements[i].r *= scale;
    }

    // Wipe out the rest of the buffer
    for (isize i = end(); i != begin(); i = next(i)) {

        elements[i] = SamplePair { 0, 0 };
    }
}



isize
AudioPort::copyMono(float *buffer, isize n)
{
    {   SYNCHRONIZED

        // Be silent when the recorder is running (fill with zeroes)
        if (recorder.isRecording()) {

            for (isize i = 0; i < n; i++) { *buffer++ = 0; }
            return 0;
        }

        // Check for buffer underflows
        if (auto cnt = count(); cnt < n) {

            // Copy all we have and stepwise lower the volume to minimize cracks
            for (isize i = 0; i < cnt; i++) {

                SamplePair pair = read();
                *buffer++ = (pair.l + pair.r) * float(cnt - i) / float(cnt);
            }
            assert(isEmpty());

            // Fill the rest with zeroes
            for (isize i = cnt; i < n; i++) *buffer++ = 0;

            // Realign the ring buffer
            handleBufferUnderflow();

            return cnt;
        }

        // The standard case: We have enough samples. Copy the requested number
        for (isize i = 0; i < n; i++) {

            SamplePair pair = read();
            *buffer++ = pair.l + pair.r;
        }

        return n;
    }
}

isize
AudioPort::copyStereo(float *left, float *right, isize n)
{
    {   SYNCHRONIZED

        // Be silent when the recorder is running (fill with zeroes)
        if (recorder.isRecording()) {

            for (isize i = 0; i < n; i++) { *left++ = *right++ = 0; }
            return 0;
        }

        // Check for buffer underflows
        if (auto cnt = count(); cnt < n) {

            // Copy all we have and stepwise lower the volume to minimize cracks
            for (isize i = 0; i < cnt; i++) {

                SamplePair pair = read();
                *left++ = pair.l * float(cnt - i) / float(cnt);
                *right++ = pair.r * float(cnt - i) / float(cnt);
            }
            assert(isEmpty());

            // Fill the rest with zeroes
            for (isize i = cnt; i < n; i++) *left++ = *right++ = 0;

            // Realign the ring buffer
            handleBufferUnderflow();

            return cnt;
        }

        // The standard case: We have enough samples. Copy the requested number
        for (isize i = 0; i < n; i++) {

            SamplePair pair = read();
            *left++ = pair.l;
            *right++ = pair.r;
        }

        return n;
    }
}

isize
AudioPort::copyInterleaved(float *buffer, isize n)
{
    {   SYNCHRONIZED

        // Be silent when the recorder is running (fill with zeroes)
        if (recorder.isRecording()) {

            // Fill with zeroes
            for (isize i = 0; i < n; i++) { *buffer++ = 0; }
            return 0;
        }

        // Check for buffer underflows
        if (auto cnt = count(); cnt < n) {

            // Copy all we have and stepwise lower the volume to minimize cracks
            for (isize i = 0; i < cnt; i++) {

                SamplePair pair = read();
                *buffer++ = pair.l * float(cnt - i) / float(cnt);
                *buffer++ = pair.r * float(cnt - i) / float(cnt);
            }
            assert(isEmpty());

            // Fill the rest with zeroes
            for (isize i = cnt; i < n; i++) { *buffer++ = 0; *buffer++ = 0; }

            // Realign the ring buffer
            handleBufferUnderflow();

            return cnt;
        }

        // We have enough samples. Copy over the requested number
        for (isize i = 0; i < n; i++) {

            SamplePair pair = read();
            *buffer++ = pair.l;
            *buffer++ = pair.r;
        }
        
        return n;
    }
}

}

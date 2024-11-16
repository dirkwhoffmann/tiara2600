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

void
AudioPort::synthesize(Cycle clock, Cycle target)
{
    assert(target > clock);

    // Do not synthesize anything if this is the run-ahead instance
    if (atari.objid != 0) return;

    // Determine the number of elapsed cycles per audio sample
    double cps = double(atari.clockFrequency()) / sampleRate;

    // Determine how many samples we need to produce
    double exact = (double)(target - clock) / cps + fraction;

    // Extract the integer part and remember the rest
    double count; fraction = std::modf(exact, &count);

    // Synthesize samples
    synthesize(clock, (long)count, cps);
}

void
AudioPort::synthesize(Cycle clock, long count, double cyclesPerSample)
{
    if (muted != isMuted()) {

        // Remember the new state
        muted = isMuted();

        // Send the MUTE message
        msgQueue.put(MSG_MUTE, muted);
    }

    stream.mutex.lock();

    // Check for a buffer overflow
    if (stream.count() + count >= stream.cap()) handleBufferOverflow();

    // Check if we can take a fast path
    /*
    if (config.idleFastPath) {

        if (muted) {

            // Fill with zeroes
            for (isize i = 0; i < count; i++) stream.write( SamplePair { 0, 0 } );
            stats.idleSamples += count;
            stream.mutex.unlock();
            return;
        }
        if (!sampler[0].isActive() && !sampler[1].isActive()) {

            // Repeat the most recent sample
            auto latest = stream.isEmpty() ? SamplePair() : stream.latest();
            for (isize i = 0; i < count; i++) stream.write(latest);
            stats.idleSamples += count;
            stream.mutex.unlock();
            return;
        }
    }
    */

    // Take the slow path
    switch (config.sampling) {

        case SMP_NONE:      synthesize <SMP_NONE>    (clock, count, cyclesPerSample); break;
        case SMP_NEAREST:   synthesize <SMP_NEAREST> (clock, count, cyclesPerSample); break;
        case SMP_LINEAR:    synthesize <SMP_LINEAR>  (clock, count, cyclesPerSample); break;

        default:
            fatalError;
    }

    stream.mutex.unlock();
}

template <SamplingMethod method> void
AudioPort::synthesize(Cycle clock, long count, double cyclesPerSample)
{
    assert(count > 0);

    float vol0 = vol[0]; float pan0 = pan[0];
    float vol1 = vol[1]; float pan1 = pan[1];
    bool fading = volL.isFading() || volR.isFading();
    double cycle = (double)clock;

    for (isize i = 0; i < count; i++) {

        float ch0 = sampler[0].interpolate <method> (Cycle(cycle)) * vol0;
        float ch1 = sampler[1].interpolate <method> (Cycle(cycle)) * vol1;

        // Compute left and right channel output
        double l = ch0 * (1 - pan0) + ch1 * (1 - pan1);
        double r = ch0 * pan0 + ch1 * pan1;

        // Modulate the master volume
        if (fading) { volL.shift(); volR.shift(); }

        // Apply master volume
        l *= volL;
        r *= volR;

        // Prevent hearing loss
        assert(std::abs(l) < 1.0);
        assert(std::abs(r) < 1.0);

        // Write sample into ringbuffer
        stream.write( SamplePair { float(l), float(r) } );

        cycle += cyclesPerSample;
    }

    stats.producedSamples += count;
}

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

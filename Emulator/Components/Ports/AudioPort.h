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

#pragma once

#include "AudioPortTypes.h"
#include "SubComponent.h"
#include "Animated.h"
#include "AudioStream.h"
#include "Chrono.h"
#include "Concurrency.h"
#include "RingBuffer.h"
#include "Sampler.h"

/* Architecture of the audio pipeline
 *
 *     TIA                             Audio port
 *   --------    ------------------------------------------------------
 *  |        |  |                                                      |
 *  | Audio  |  |    ---------                                         |
 *  |  unit -|--|-->| Sampler |-> vol ->|                              |
 *  |     0  |  |    ---------          |     pan     --------------   |
 *  |        |  |                       |--> l vol ->| Audio Stream |--|--> GUI
 *  | Audio  |  |    ---------          |    r vol    --------------   |
 *  |  unit -|--|-->| Sampler |-> vol ->|                              |
 *  |     1  |  |    ---------                                         |
 *  |        |  |                                                      |
 *   --------    ------------------------------------------------------
 */

namespace tiara {

class AudioPort final : public SubComponent, public Inspectable<AudioPortInfo, AudioPortStats> {

    Descriptions descriptions = {{

        .type           = AudioPortClass,
        .name           = "Audio",
        .description    = "Audio Port",
        .shell          = "audio"
    }};

    Options options = {

        OPT_AUD_VOL0,
        OPT_AUD_VOL1,
        OPT_AUD_PAN0,
        OPT_AUD_PAN1,
        OPT_AUD_VOL_L,
        OPT_AUD_VOL_R
    };

    // Current configuration
    AudioPortConfig config = { };

    // Current sample rate
    // double sampleRate = 44100;

    // Fraction of a sample that hadn't been generated in synthesize
    double fraction = 0.0;

    // Time stamp of the last write pointer alignment
    util::Time lastAlignment;

    // Records the number of requested samples and their time stamps
    util::RingBuffer<double, 16> requests;

    // Sample rate adjustment
    double sampleRateCorrection = 0.0;

    // Channel volumes
    float vol[2] = { };

    // Panning factors
    float pan[2] ={ };

    // Master volumes (fadable)
    util::Animated<float> volL;
    util::Animated<float> volR;

    // Used to determine if a MSG_MUTE should be send
    bool muted = false;

    // (sample rate prediction)
    // isize cnt = 0;
    // util::Time base = 0;


    //
    // Subcomponents
    //

public:

    // Inputs (one Sampler for each channel)
    Sampler sampler[2] = {

        Sampler(),
        Sampler()
    };

    // Output buffer
    AudioStream stream;


    //
    // Methods
    //

public:

    AudioPort(Atari &ref) : SubComponent(ref) { };

    AudioPort& operator= (const AudioPort& other) {

        CLONE(lastAlignment)
        CLONE(config)

        return *this;
    }

    // Resets the output buffer
    void clear();


    //
    // Methods from Serializable
    //

public:
    
    template <class T>
    void serialize(T& worker)
    {
        if (isResetter(worker)) return;

        worker

        << config.vol
        << config.pan
        << config.volL
        << config.volR;

    } SERIALIZERS(serialize);


    //
    // Methods from CoreComponent
    //

public:

    const Descriptions &getDescriptions() const override { return descriptions; }

private:

    void _dump(Category category, std::ostream& os) const override;
    void _didLoad() override;
    void _didReset(bool hard) override;
    void _powerOn() override;
    void _run() override;
    void _pause() override;
    void _warpOn() override;
    void _warpOff() override;
    void _focus() override;
    void _unfocus() override;


    //
    // Methods from Inspectable
    //

public:

    void cacheInfo(AudioPortInfo &result) const override;
    void cacheStats(AudioPortStats &result) const override;


    //
    // Methods from Configurable
    //

public:

    const AudioPortConfig &getConfig() const { return config; }
    const Options &getOptions() const override { return options; }
    i64 getOption(Option opt) const override;
    void checkOption(Option opt, i64 value) override;
    void setOption(Option opt, i64 value) override;

    // void setSampleRate(double hz);


    //
    // Analyzing
    //

public:

    // Returns true if the output volume is zero
    bool isMuted() const;


    //
    // Generating audio streams
    //

public:

    // Generates new sound samples
    void synthesize(Cycle clock, Cycle target);

private:

    void synthesize(Cycle clock, long count, double cyclesPerSample);
    template <SamplingMethod method>
    void synthesize(Cycle clock, long count, double cyclesPerSample);

    // Handles a buffer underflow or overflow
    void handleBufferUnderflow();
    void handleBufferOverflow();


    //
    // Generating audio samples
    //

public:

    // Generates samples
    // void generateSamples();

    // Returns the sample rate adjustment
    double getSampleRateCorrection() { return sampleRateCorrection; }


    //
    // Controlling volume
    //

public:

    // Rescale the existing samples to gradually fade out (to avoid cracks)
    void fadeOut();

    // Gradually decrease the master volume to zero
    void mute(isize steps = 0) { volL.fadeOut(steps); volR.fadeOut(steps); }

    // Gradually inrease the master volume to max
    void unmute(isize steps = 0) { volL.fadeIn(steps); volR.fadeIn(steps); }


    //
    // Reading audio samples
    //
    
public:
    
    /* Copies n audio samples into a memory buffer. These functions mark the
     * final step in the audio pipeline. They are used to copy the generated
     * sound samples into the buffers of the native sound device. The function
     * returns the number of copied samples.
     */
    isize copyMono(float *buffer, isize n);
    isize copyStereo(float *left, float *right, isize n);
    isize copyInterleaved(float *buffer, isize n);

private:

    // Experimental (sample rate prediction)
    void recordRequest(isize n);

    // Experimental (sample rate prediction)
    double sampleRate() const;
    double predictSampleRate() const;
};

}

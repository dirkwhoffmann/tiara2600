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
#include "AudioPort.h"
#include "Emulator.h"
#include "IOUtils.h"

namespace tiara {

void
AudioPort::_dump(Category category, std::ostream& os) const
{
    using namespace util;

    if (category == Category::Config) {

        dumpConfig(os);
    }

    if (category == Category::State) {

        os << tab("Master volume left");
        os << flt(volL.current) << " (0 ... " << flt(volL.maximum) << ")" << std::endl;
        os << tab("Master volume right");
        os << flt(volR.current) << " (0 ... " << flt(volR.maximum) << ")" << std::endl;
        os << tab("Channel 0 volume");
        os << flt(vol[0]) << std::endl;
        os << tab("Channel 1 volume");
        os << flt(vol[1]) << std::endl;
        os << tab("Channel 0 pan");
        os << flt(pan[0]) << std::endl;
        os << tab("Channel 1 pan");
        os << flt(pan[1]) << std::endl;
        os << tab("Sample rate correction");
        os << flt(sampleRateCorrection) << " Hz" << std::endl;
    }
}

void
AudioPort::cacheInfo(AudioPortInfo &result) const
{

}

void
AudioPort::cacheStats(AudioPortStats &result) const
{
    {   SYNCHRONIZED
        
        stats.fillLevel = stream.fillLevel();
    }
}

void
AudioPort::_didLoad()
{
    // Reset samplers
    sampler[0].reset();
    sampler[1].reset();
}

void
AudioPort::_didReset(bool hard)
{
    SYNCHRONIZED

    // Reset samplers
    sampler[0].reset();
    sampler[1].reset();

    // Clear the sample buffer
    clear();

    // Clear statistics
    if (hard) clearStats();
}

void 
AudioPort::_powerOn()
{
    sampleRateCorrection = 0.0;
}

void
AudioPort::_run()
{
    if (!emulator.isWarping()) unmute(10000);
}

void
AudioPort::_pause()
{
    fadeOut();
    mute(0);
}

void
AudioPort::_warpOn()
{
    fadeOut();
    mute(0);
}

void
AudioPort::_warpOff()
{
    if (emulator.isRunning()) unmute(10000);
}

void
AudioPort::_focus()
{
    if (emulator.isRunning() && !emulator.isWarping()) unmute(100000);
}

void
AudioPort::_unfocus()
{
    mute(100000);
}

void
AudioPort::clear()
{
    debug(AUDBUF_DEBUG, "Clearing the audio sample buffer\n");

    // Wipe out the ringbuffer
    stream.wipeOut();
    stream.alignWritePtr();
}

i64
AudioPort::getOption(Option option) const
{
    switch (option) {

        case OPT_AUD_SAMPLING:  return config.sampling;
        case OPT_AUD_VOL0:      return config.vol[0];
        case OPT_AUD_VOL1:      return config.vol[1];
        case OPT_AUD_PAN0:      return config.pan[0];
        case OPT_AUD_PAN1:      return config.pan[1];
        case OPT_AUD_VOL_L:     return config.volL;
        case OPT_AUD_VOL_R:     return config.volR;

        default:
            fatalError;
    }
}

void
AudioPort::checkOption(Option opt, i64 value)
{
    switch (opt) {

        case OPT_AUD_SAMPLING:

            if (!SamplingMethodEnum::isValid(value)) {
                throw Error(TIARA_ERROR_OPT_INV_ARG, SamplingMethodEnum::keyList());
            }
            return;

        case OPT_AUD_VOL1:
        case OPT_AUD_VOL0:

            return;

        case OPT_AUD_PAN1:
        case OPT_AUD_PAN0:

            return;

        case OPT_AUD_VOL_L:
        case OPT_AUD_VOL_R:

            return;

        default:
            throw Error(TIARA_ERROR_OPT_UNSUPPORTED);
    }
}

void
AudioPort::setOption(Option opt, i64 value)
{
    checkOption(opt, value);

    isize channel = 0;

    switch (opt) {

        case OPT_AUD_SAMPLING:

            config.sampling = (SamplingMethod)value;
            return;

        case OPT_AUD_VOL1: channel++;
        case OPT_AUD_VOL0:

            config.vol[channel] = std::clamp(value, 0LL, 100LL);
            vol[channel] = powf(config.vol[channel] / 100.0f, 1.4f) * 0.000025f;
            if (emscript) vol[channel] *= 0.15f;
            return;

        case OPT_AUD_PAN1: channel++;
        case OPT_AUD_PAN0:

            config.pan[channel] = value;
            pan[channel] = float(0.5 * (sin(config.pan[channel] * M_PI / 200.0) + 1));
            return;

        case OPT_AUD_VOL_L:

            config.volL = std::clamp(value, 0LL, 100LL);
            volL.maximum = powf((float)config.volL / 50, 1.4f);
            return;

        case OPT_AUD_VOL_R:

            config.volR = std::clamp(value, 0LL, 100LL);
            volR.maximum = powf((float)config.volR / 50, 1.4f);
            return;

        default:
            fatalError;
    }
}

/*
void
AudioPort::setSampleRate(double hz)
{
    // Set the sample rate or get it from the detector if none is provided
    if (hz != 0.0) {

        sampleRate = hz;
        debug(AUD_DEBUG, "setSampleRate(%.2f)\n", sampleRate);

    } else {

        // sampleRate = detector.sampleRate();
        // trace(AUD_DEBUG, "setSampleRate(%.2f) (predicted)\n", sampleRate);
        sampleRate = 44100;
        debug(AUD_DEBUG, "setSampleRate(%.2f) (assumed)\n", sampleRate);
    }
}
*/

}

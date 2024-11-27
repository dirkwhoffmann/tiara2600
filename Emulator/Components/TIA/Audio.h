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

#include "AudioTypes.h"
#include "SubComponent.h"
#include "Constants.h"

namespace tiara {

/*
 This class implements the audio circuitry of the TIA chip. TIA features two
 audio circuits of this kind that operate independently of each other.

 The audio unit is driven by a dual-phase clock signal called (AΦ1,AΦ2) in the
 TIA schematics. The clock signal is derived by TIA's horizontal counter, clocking
 the audio circuitry two times per scanline.

 The audio circuit runs the clock signal through a frequency divider which is
 controlled by the AUDF register. The frequency divider is driven by modulo-32
 counter running from 0 ... 31. Whenever the counter value matches the contents
 of the AUDF register, the counter is reset and a clock pulse is generated that
 triggers the rest of the audio circuitry. The clock signal produced by the frequency
 divider is labelled (TΦ1,TΦ2) in the TIA schematics.

 (TΦ1,TΦ2) drives two interconnected polynomial counters, poly4 and poly5, that are controled by the
 AUDC register. poly4 comprises five dual-pahse delay elements, and poly5 consists of four SR flip-flops. The last bits of poly5 is the emitted audo signal, linearly scaled by the current value of the volume register AUDV.

 On each shift-register pulse, poly4 shifts all bits one position to the right and
 feeds in a new bit on the left. The shifted-in bit depends on the contents of the AUDC register.

 */
class Audio final : public SubComponent {

    friend class TIA;

    Descriptions descriptions = {
        {
            .type           = AudioClass,
            .name           = "Audio0",
            .description    = "Audio Unit 0",
            .shell          = "audio0"
        },
        {
            .type           = AudioClass,
            .name           = "Audio1",
            .description    = "Audio Unit 1",
            .shell          = "audio1"
        }
    };

    Options options = {

    };

    // Current configuration
    AudioConfig config{};

    //
    // Registers
    //

    // Audio volume (AUDV)
    u8 audv = 0;

    // Audio frequency (AUDF)
    u8 audf = 0;

    // Audio control (AUDC)
    u8 audc = 0;


    //
    // Internals
    //

    // Couter that implements the frequency divider
    u8 fdiv = 0;

    // Polynomial counters
    u8 poly5 = 0;
    u8 poly4 = 0;


    //
    // Methods
    //

public:

    // Audio(Atari &ref);
    using SubComponent::SubComponent;

    Audio& operator= (const Audio& other) {

        CLONE(config)

        return *this;
    }


    //
    // Methods from Serializable
    //

public:

    template <class T>
    void serialize(T& worker)
    {
        if (isResetter(worker)) return;

        /*
        worker

        << probe
        << color

        << config.enable
        << config.displayMode
        << config.opacity;
        */

    } SERIALIZERS(serialize);


    //
    // Methods from CoreComponent
    //

public:

    const Descriptions &getDescriptions() const override { return descriptions; }

private:

    void _dump(Category category, std::ostream& os) const override;
    void _didReset(bool hard) override;
    

    //
    // Methods from Configurable
    //

public:

    const AudioConfig &getConfig() const { return config; }
    const Options &getOptions() const override { return options; }
    // i64 getOption(Option opt) const override;
    // void checkOption(Option opt, i64 value) override;
    // void setOption(Option opt, i64 value) override;


    //
    // Accessing registers
    //

public:

    u8 getAUDC() const { return audc; }
    u8 getAUDF() const { return audf; }
    u8 getAUDV() const { return audv; }

    void pokeAUDC(u8 val);
    void pokeAUDF(u8 val);
    void pokeAUDV(u8 val);


    //
    // Execution
    //

public:

    void execute();

private:

    void executePoly();


    //
    // Handlers
    //

public:

    // Frame handlers
    void sofHandler(isize y);
    void eofHandler();
};

}

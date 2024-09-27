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

#include "TIAComponents.h"
#include "SubComponent.h"
#include "C64Types.h"

namespace tiara {

class TIA final : public SubComponent, public Inspectable<TIAInfo, TIAStats> {

    Descriptions descriptions = {
        {
            .type           = TIAClass,
            .name           = "TIA",
            .description    = "Television Interface Adaptor",
            .shell          = "tia"
        }
    };

    static constexpr TIATraits traits[3] = {
        {
            // NTSC
            .fps      = 60
        },
        {
            // PAL
            .fps      = 50
        },
        {
            // SECAM
            .fps      = 50
        },
    };

    Options options = {

        OPT_TIA_REVISION,
        OPT_TIA_POWER_SAVE
    };

    // Current configuration
    TIAConfig config = { };

    // The horizontal counter
    DualPhaseCounter<56> hc { .phase = 1, .current = 56, .resl = false, .res = true };

    
    //
    // Methods
    //

public:

    TIA(C64 &ref);

    TIA& operator= (const TIA& other) {

        CLONE(config)

        // CLONE(...)

        return *this;
    }


    //
    // Methods from Serializable
    //

public:

    template <class T> void serialize(T& worker) {

        // worker
        //
        // << xxx;

        if (isResetter(worker)) return;

        // worker
        //
        // << config.xxx;

    } SERIALIZERS(serialize);


    //
    // Methods from CoreComponent
    //

public:

    const Descriptions &getDescriptions() const override { return descriptions; }

private:

    void _dump(Category category, std::ostream& os) const override;


    //
    // Methods from Inspectable
    //

private:

    void cacheInfo(TIAInfo &result) const override;
    void cacheStats(TIAStats &result) const override;


    //
    // Methods from Configurable
    //

public:

    const TIAConfig &getConfig() const { return config; }
    const Options &getOptions() const override { return options; }
    i64 getOption(Option opt) const override;
    void checkOption(Option opt, i64 value) override;
    void setOption(Option opt, i64 value) override;


    //
    // Executing
    //

public:

    // Executes three color clock cycles
    template <bool> void execute();
};

}

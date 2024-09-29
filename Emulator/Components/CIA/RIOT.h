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

#include "RIOTTypes.h"
#include "AtariTypes.h"
#include "SubComponent.h"

namespace tiara {

class RIOT : public SubComponent, public Inspectable<RIOTInfo, RIOTStats> {

    friend class TOD;
    friend class ParCable;

    Descriptions descriptions = {{

        .type           = RIOTClass,
        .name           = "RIOT",
        .description    = "6532 RAM Input/Output Timer",
        .shell          = "riot"
    }};

    Options options{ };
    RIOTConfig config = { };


    //
    // Initializing
    //

public:

    RIOT(Atari &ref);

    RIOT& operator= (const RIOT& other) {

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
    // Methods from Inspectable
    //

public:

    void cacheInfo(RIOTInfo &result) const override;
    void cacheStats(RIOTStats &result) const override;


    //
    // Methods from Configurable
    //

public:

    const RIOTConfig &getConfig() const { return config; }
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

    // End-of-frame handler
    void eofHandler();
};

}

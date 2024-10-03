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

#include "PIATypes.h"
#include "AtariTypes.h"
#include "SubComponent.h"

namespace tiara {

class PIA : public SubComponent, public Inspectable<PIAInfo, PIAStats> {

    friend class TOD;
    friend class ParCable;

    Descriptions descriptions = {{

        .type           = PIAClass,
        .name           = "PIA",
        .description    = "Peripheral Interface Adapter",
        .shell          = "pia"
    }};

    Options options{ };
    PIAConfig config = { };

    // Random Access Memory
    u8 ram[128];


    //
    // Chip interface
    //

    public:

    // Chip Select (1 = selected)
    bool cs;
    bool csram;

    // Read-write (1 = read)
    bool rw;


    //
    // Initializing
    //

public:

    PIA(Atari &ref);

    PIA& operator= (const PIA& other) {

        CLONE_ARRAY(ram);

        return *this;
    }


    //
    // Methods from Serializable
    //

    public:

    template <class T>
    void serialize(T& worker)
    {
        worker

        << ram;

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

    void cacheInfo(PIAInfo &result) const override;
    void cacheStats(PIAStats &result) const override;


    //
    // Methods from Configurable
    //

public:

    const PIAConfig &getConfig() const { return config; }
    const Options &getOptions() const override { return options; }
    i64 getOption(Option opt) const override;
    void checkOption(Option opt, i64 value) override;
    void setOption(Option opt, i64 value) override;


    //
    // Accessing registers and memory
    //

    u8 peek(u16 addr);
    u8 spypeek(u16 addr) const;


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

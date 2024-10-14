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

    Options options{

        OPT_RAM_INIT_PATTERN
    };
    
    PIAConfig config{};

    // Memory
    u8 ram[128]{};

    // Peripheral data registers
    u8 pra{};
    u8 prb{};

    // Data directon registers
    u8 ddra{};
    u8 ddrb{};

    // Interval timer
    u8 timer{};
    isize counter{};
    isize interval{};

    // Interrupt registers (enable and status)
    u8 intena{};
    u8 instat{};
    
    // Edge control (PA7 interrupts)
    u8 edgctrl{};


    //
    // Chip interface
    //

public:

    // Chip Select (1 = selected)
    // bool cs{};
    // bool csram{};

    // Read-write (1 = read)
    // bool rw{};

    // Data ports
    u8 pa{};
    u8 pb{};


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

        worker

        << config.ramPattern;

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
    void checkOption(Option opt, i64 val) override;
    void setOption(Option opt, i64 val) override;


    //
    // Accessing registers and memory
    //

public:

    u8 peekRam(u16 addr);
    u8 peekReg(PIARegister reg);

    u8 spyRam(u16 addr) const;
    u8 spyReg(PIARegister reg) const;

    void pokeRam(u16 addr, u8 val);
    void pokeReg(PIARegister reg, u8 val, Cycle delay = 0);

private:

    void pokePRA(u8 val);
    void pokeDDRA(u8 val);
    void pokePRB(u8 val);
    void pokeDDRB(u8 val);
    void pokeTIMxT(isize x, u8 val, bool enable);
    void pokeEDGCTL(u8 val);

    void updatePA();
    void updatePA(u8 val);
    void updatePB();
    void updatePB(u8 val);


    //
    // Executing
    //

public:

    // Executes three color clock cycles
    template <bool> void execute();

    // Frame handlers
    void sofHandler();
    void eofHandler();
};

}

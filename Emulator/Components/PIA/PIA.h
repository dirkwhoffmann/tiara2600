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
    u8 pra = 0;
    u8 prb = 0;

    // Data directon registers
    u8 ddra = 0;
    u8 ddrb = 0;

    // Interval timer
    u8 timer = 0;
    isize counter = 0;
    isize interval = 0;

    /* Interrupt registers (enable and status)
     *
     *   Bit 6: PA7 interrupt
     *   Bit 7: Timer interrupt
     *
     * All other bits are unused.
     */
    u8 intena = 0;
    u8 instat = 0;

    // Edge control bit 0 (PA7 interrupts)
    bool posEdgeDetect = false;


    //
    // Chip interface
    //

public:

    // Data ports
    u8 pa = 0;
    u8 pb = 0;


    //
    // Initializing
    //

public:

    PIA(Atari &ref);

    PIA& operator= (const PIA& other) {

        CLONE_ARRAY(ram)
        
        CLONE(pra)
        CLONE(prb)
        CLONE(ddra)
        CLONE(ddrb)
        CLONE(timer)
        CLONE(counter)
        CLONE(interval)
        CLONE(intena)
        CLONE(instat)
        CLONE(posEdgeDetect)
        CLONE(pa)
        CLONE(pb)
        
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

        << ram
        
        << pra
        << prb
        << ddra
        << ddrb
        << timer
        << counter
        << interval
        << intena
        << instat
        << posEdgeDetect
        << pa
        << pb;

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
    u8 peekReg(u16 addr);

    u8 spyRam(u16 addr) const;
    u8 spyReg(u16 addr) const;

    void pokeRam(u16 addr, u8 val);
    void pokeReg(u16 addr, u8 val, Cycle delay = 0);

private:

    void pokePRA(u8 val);
    void pokeDDRA(u8 val);
    void pokePRB(u8 val);
    void pokeDDRB(u8 val);
    void pokeTIMxT(isize x, u8 val, bool enable);


    //
    // Managing the I/O ports
    //

public:

    void updatePA();
    void updatePB();

private:

    void updatePA(u8 val);
    void updatePB(u8 val);

private:

    u8 paExternal() const;
    u8 pbExternal() const;


    //
    // Handling console switches
    //

    

    //
    // Executing
    //

public:

    // Executes three color clock cycles
    template <bool fastPaths> void execute();

    // Frame handlers
    void sofHandler();
    void eofHandler();
};

}

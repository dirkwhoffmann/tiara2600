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

#include "CPUTypes.h"
#include "SubComponent.h"
#include "CmdQueue.h"
#include "GuardList.h"
#include "Peddle.h"

using namespace tiara::peddle;

namespace tiara {

class CPU final : public Peddle, public Inspectable<CPUInfo> {

    friend class Atari;

    Descriptions descriptions = {{

        .type           = CPUClass,
        .name           = "CPU",
        .description    = "Central Processing Unit",
        .shell          = "cpu"
    }};

    Options options = {

    };

public:

    // Breakpoints, Watchpoints, Catchpoints
    GuardList breakpoints;
    GuardList watchpoints;

    /* Processor port
     *
     * Clock cycles when floating pins reach zero. Bit 3, 6, and 7 of the
     * processor port need special attention. When the direction of these bits
     * changes from output to input, there will be no external signal driving
     * them. As a result, these bits will be in a floating state and act as
     * capacitors. They will discharge slowly and eventually reach zero. These
     * variables are used to indicate when the zero level is reached. All three
     * variables are queried in externalPortBits() and comply to the following
     * rules:
     *
     *    dischargeCycleBit > current cycle => bit reads as 1
     *                                         (if configured as input)
     *    otherwise                         => bit reads as 0
     *                                         (if configured as input)
     */
    i64 dischargeCycleBit3;
    i64 dischargeCycleBit6;
    i64 dischargeCycleBit7;

    /* Discharging times for bit 3, 6, and 7 as seen in other emulators. In
     * reality, the discharge delay depend on both CPU temperature and how
     * long the output was 1 befor the bit became an input.
     */
    static constexpr i64 dischargeCyclesVICE = 350000;
    static constexpr i64 dischargeCyclesHOXS = 246312;


    //
    // Methods
    //
    
public:
    
    CPU(Atari& ref);
    CPU(CPURevision cpuModel, Atari& ref);

    // void setID(isize id) { this->id = id; }

    CPU& operator= (const CPU& other) {

        CLONE(flags)
        CLONE(next)

        CLONE(reg)

        CLONE(rdyLine)
        CLONE(rdyLineUp)
        CLONE(rdyLineDown)
        CLONE(nmiLine)
        CLONE(irqLine)
        CLONE(edgeDetector)
        CLONE(levelDetector)
        CLONE(doNmi)
        CLONE(doIrq)
        CLONE(dischargeCycleBit3)
        CLONE(dischargeCycleBit6)
        CLONE(dischargeCycleBit7)

        CLONE(clock)

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

        << flags
        << next

        << reg.pc
        << reg.pc0
        << reg.sp
        << reg.a
        << reg.x
        << reg.y
        << reg.adl
        << reg.adh
        << reg.idl
        << reg.d
        << reg.ovl
        << reg.sr.n
        << reg.sr.v
        << reg.sr.b
        << reg.sr.d
        << reg.sr.i
        << reg.sr.z
        << reg.sr.c
        << reg.pport.data
        << reg.pport.direction

        << rdyLine
        << rdyLineUp
        << rdyLineDown
        << nmiLine
        << irqLine
        << edgeDetector
        << levelDetector
        << doNmi
        << doIrq
        << dischargeCycleBit3
        << dischargeCycleBit6
        << dischargeCycleBit7;

        if (isSoftResetter(worker)) return;

        worker

        << clock;

    } SERIALIZERS(serialize);


    //
    // Methods from CoreComponent
    //

public:
    
    const Descriptions &getDescriptions() const override { return descriptions; }

private:

    void _dump(Category category, std::ostream& os) const override;
    void _didReset(bool hard) override;
    void _trackOn() override;
    void _trackOff() override;


    //
    // Methods from Inspectable
    //

public:

    void cacheInfo(CPUInfo &result) const override;


    //
    // Methods from Configurable
    //

public:

    const Options &getOptions() const override { return options; }
    

    //
    // Methods from Peddle
    //

public:

    virtual u8 read(u16 addr) override;
    virtual void write(u16 addr, u8 val) override;
    virtual u16 readResetVector() override;
    virtual u8 readDasm(u16 addr) const override;

    virtual void cpuDidJam() override;
    virtual void breakpointReached(u16 addr) const override;
    virtual void watchpointReached(u16 addr) const override;
    virtual void instructionLogged() const override;
    virtual void jumpedTo(u16 addr) const override;


    //
    // Changing state
    //

    // Continues program execution at the specified address
    void jump(u16 addr);


    //
    // Interpreting processor port bits
    //

public:
    
    bool getLoram() const { return readPort() & 0x1; }
    bool getHiram() const { return readPort() & 0x2; }
    bool getCharen() const { return readPort() & 0x4; }


    //
    // Processing commands
    //

public:

    // Processes a command from the command queue
    void processCommand(const Cmd &cmd);
};

}

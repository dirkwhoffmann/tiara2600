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

#include "MemoryTypes.h"
#include "MemoryDebugger.h"
#include "SubComponent.h"
#include "Heatmap.h"

namespace tiara {

class Memory final : public SubComponent, public Inspectable<MemInfo, MemStats> {

    friend class Heatmap;

    Descriptions descriptions = {{

        .type           = MemoryClass,
        .name           = "Memory",
        .description    = "C64 Memory",
        .shell          = "memory"
    }};

    Options options = {

        OPT_MEM_INIT_PATTERN,
        OPT_MEM_HEATMAP,
    };

    // Current configuration
    MemConfig config{};

public:

    // Subcomponents
    MemoryDebugger debugger = MemoryDebugger(c64);

    // Address decoding table
    MemoryType peekSrc[64];
    MemoryType pokeTarget[64];

    // Random Access Memory
    u8 ram[128];

    // Indicates if watchpoints should be checked
    bool checkWatchpoints = false;

    // Debugging
    Heatmap heatmap;


    //
    // Methods
    //

public:

    Memory(Atari &ref);

    Memory& operator= (const Memory& other) {

        CLONE_ARRAY(ram)

        CLONE_ARRAY(peekSrc)
        CLONE_ARRAY(pokeTarget)

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
        if (isSoftResetter(worker)) return;

        worker

        << ram;

        if (isResetter(worker)) return;

        worker

        << peekSrc
        << pokeTarget

        << config.ramPattern;

    }

    void operator << (SerResetter &worker) override { serialize(worker); }
    void operator << (SerChecker &worker) override { serialize(worker); }
    void operator << (SerCounter &worker) override;
    void operator << (SerReader &worker) override;
    void operator << (SerWriter &worker) override;


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

    const MemConfig &getConfig() const { return config; }
    const Options &getOptions() const override { return options; }
    i64 getOption(Option opt) const override;
    void checkOption(Option opt, i64 value) override;
    void setOption(Option opt, i64 value) override;


    //
    // Methods from Inspectable
    //

public:

    void cacheInfo(MemInfo &result) const override;


    //
    // Accessing
    //

public:

    // Erases the RAM with the provided init pattern
    void eraseWithPattern(RamPattern pattern);

    // Returns the current peek source of the specified memory address
    MemoryType getPeekSource(u16 addr) { return peekSrc[(addr & 0x1FFF) >> 7]; }

    // Returns the current poke target of the specified memory address
    MemoryType getPokeTarget(u16 addr) { return pokeTarget[(addr & 0x1FFF) >> 7]; }

    // Reads a value from memory
    u8 peek(u16 addr, MemoryType source);
    u8 peek(u16 addr) { return peek(addr, peekSrc[(addr & 0x1FFF) >> 7]); }
    u8 peekZP(u8 addr) { return peek(u16(addr)); }
    u8 peekStack(u8 sp);

    // Reads a value from memory and discards the result (idle access)
    void peekIdle(u16 addr) { (void)peek(addr); }
    void peekZPIdle(u8 addr) { (void)peekZP(addr); }
    void peekStackIdle(u8 sp) { (void)peekStack(sp); }

    // Reads a value from memory without side effects
    u8 spypeek(u16 addr, MemoryType source) const;
    u8 spypeek(u16 addr) const { return spypeek(addr, peekSrc[(addr & 0x1FFF) >> 7]); }

    // Writing a value into memory
    void poke(u16 addr, u8 value, MemoryType target);
    void poke(u16 addr, u8 value) { poke(addr, value, pokeTarget[(addr & 0x1FFF) >> 7]); }
    void pokeZP(u8 addr, u8 value) { poke(addr, value); }
    void pokeStack(u8 sp, u8 value);

    // Reads a vector address from memory
    u16 resetVector() const;

    // Returns a string representations for a portion of memory
    string memdump(u16 addr, isize num, bool hex, isize pads, MemoryType src) const;
    string hexdump(u16 addr, isize num, isize pads, MemoryType src) const;
    string decdump(u16 addr, isize num, isize pads, MemoryType src) const;
    string txtdump(u16 addr, isize num, MemoryType src) const;

    // Convenience wrappers
    string memdump(u16 addr, isize num, bool hex) { return memdump(addr, num, hex, 1, peekSrc[addr >> 12]); }
    string hexdump(u16 addr, isize num) { return hexdump(addr, num, 1, peekSrc[addr >> 12]); }
    string decdump(u16 addr, isize num) { return decdump(addr, num, 1, peekSrc[addr >> 12]); }
    string txtdump(u16 addr, isize num) { return txtdump(addr, num, peekSrc[addr >> 12]); }

    // Dumps a portion of memory to a stream
    void memDump(std::ostream& os, u16 addr, isize numLines = 16, bool hex = true);


    //
    // Executing
    //

    void endFrame();
};

}

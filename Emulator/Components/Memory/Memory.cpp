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
#include "Memory.h"
#include "Emulator.h"
#include "IOUtils.h"

#include <random>

namespace tiara {

Memory::Memory(Atari &ref) : SubComponent(ref)
{
    auto decode = [&](u16 addr) {

        if ((addr & TIA_MASK) == TIA_MATCH) return M_TIA;
        if ((addr & RAM_MASK) == RAM_MATCH) return M_RAM;
        if ((addr & PIA_MASK) == PIA_MATCH) return M_PIA;

        return M_CRT;
    };

    for (isize i = 0; i < 64; i++) {
        peekSrc[i] = pokeTarget[i] = decode(u16(i << 7));
    }
}

void
Memory::_didReset(bool hard)
{
    if (hard) {

        // Erase RAM
        eraseWithPattern(config.ramPattern);
    }
}

void 
Memory::operator << (SerCounter &worker)
{
    serialize(worker);
}

void 
Memory::operator << (SerReader &worker)
{
    serialize(worker);
}

void 
Memory::operator << (SerWriter &worker)
{
    serialize(worker);
}

void
Memory::eraseWithPattern(RamPattern pattern)
{
    /*
    switch (pattern) {
                        
        case RAM_PATTERN_ZEROES:
            
            for (isize i = 0; i < isizeof(ram); i++)
                ram[i] = 0;
            
            break;
            
        case RAM_PATTERN_ONES:
            
            for (isize i = 0; i < isizeof(ram); i++)
                ram[i] = 0xFF;
            
            break;
            
        case RAM_PATTERN_RANDOM:
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(0, 0xFF);
            
            for (isize i = 0; i < isizeof(ram); i++)
                ram[i] = (u8)distrib(gen);
            
            break;
        }
        default:
            fatalError;
    }
    */
}

u8
Memory::peek(u16 addr, MemoryType source)
{
    printf("Peek(%x) (%s)\n", addr, MemoryTypeEnum::key(source));

    assert(addr <= 0x1FFF);

    if (config.heatmap) stats.reads[addr]++;

    atari.addrBus = addr;
    
    switch(source) {
            
        case M_TIA:     tia.cs = 1; tia.rw = 1; break;
        case M_PIA:     pia.cs = 1; pia.csram = 0; pia.rw = 1; break;
        case M_RAM:     pia.cs = 1; pia.csram = 1; pia.rw = 1; break;
        case M_CRT:     cartPort.cart->cs = 1; cartPort.cart->rw = 1; break;

        default:
            fatalError;
    }

    return 0;
}

u8
Memory::spypeek(u16 addr, MemoryType source) const
{
    addr &= 0x1FFF;

    switch(source) {

        case M_TIA: return tia.spypeek(addr);
        case M_PIA:
        case M_RAM: return pia.spypeek(addr);
        case M_CRT: return cartPort.cart->spypeek(addr);

        default:
            fatalError;
    }
}

void
Memory::poke(u16 addr, u8 value, MemoryType target)
{
    assert(addr <= 0x1FFF);

    if (config.heatmap) stats.writes[addr]++;

    switch(target) {

        case M_TIA:     tia.cs = 1; tia.rw = 0; break;
        case M_PIA:     pia.cs = 1; pia.csram = 0; pia.rw = 0; break;
        case M_RAM:     pia.cs = 1; pia.csram = 1; pia.rw = 0; break;
        case M_CRT:     cartPort.cart->cs = 1; cartPort.cart->rw = 0; break;

        default:
            fatalError;
    }
}

string
Memory::memdump(u16 addr, isize num, bool hex, isize pads, MemoryType src) const
{
    char result[128];
    char *p = result;
    
    assert(num <= 16);
    
    if (src == M_NONE) {
        
        for (isize i = 0; i < num; i++) {

            for (isize j = 0; j < pads; j++) *p++ = ' ';
            *p++ = '-'; *p++ = '-';
        }
        *p = 0;
        
    } else {
        
        for (isize i = 0; i < num; i++) {

            for (isize j = 0; j < pads; j++) *p++ = ' ';

            if (hex) {
                util::sprint8x(p, spypeek(addr++, src));
                p += 2;
            } else {
                util::sprint8d(p, spypeek(addr++, src));
                p += 3;
            }
        }
    }
    
    return string(result);
}

string
Memory::hexdump(u16 addr, isize num, isize pads, MemoryType src) const
{
    return memdump(addr, num, true, pads, src);
}

string
Memory::decdump(u16 addr, isize num, isize pads, MemoryType src) const
{
    return memdump(addr, num, false, pads, src);
}

string
Memory::txtdump(u16 addr, isize num, MemoryType src) const
{
    char result[17];
    char *p = result;
    
    assert(num <= 16);
    
    if (src != M_NONE) {
        
        for (isize i = 0; i < num; i++) {
            
            u8 byte = spypeek(addr++, src);
            
            if (byte >= 65 && byte <= 90) { *p++ = byte; continue; }
            if (byte >= 32 && byte <= 57) { *p++ = byte; continue; }
            *p++ = '.';
        }
    }
    *p = 0;
    
    return string(result);
}

void
Memory::memDump(std::ostream& os, u16 addr, isize numLines, bool hex)
{
    addr &= ~0xF;

    os << std::setfill('0') << std::hex << std::uppercase << std::right;

    for (isize i = 0, count = 16; i < numLines; i++) {

        os << std::setw(4) << isize(addr);
        os << ": ";
        os << memdump(addr, count, hex);
        os << "  ";
        os << txtdump(addr, count);
        os << std::endl;

        U16_INC(addr, count);
    }
}

void 
Memory::endFrame()
{
    if (config.heatmap) {
        heatmap.update(*this);
    }
}


}

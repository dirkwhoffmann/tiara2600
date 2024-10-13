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
#include "PeddleConfig.h"
#include "CPU.h"
#include "CartPort.h"
#include "Emulator.h"
#include "IOUtils.h"

namespace tiara {

CPU::CPU(Atari& ref) : Peddle(ref),
breakpoints(emulator.main, debugger.breakpoints),
watchpoints(emulator.main, debugger.watchpoints)
{

}

CPU::CPU(CPURevision cpuModel, Atari& ref) : CPU(ref)
{
    setModel(cpuModel);
}

void
CPU::cpuDidJam()
{
    atari.signalJammed();
}

void
CPU::breakpointReached(u16 addr) const
{
    atari.signalBreakpoint();
}

void
CPU::watchpointReached(u16 addr) const
{
    atari.signalWatchpoint();
}

void
CPU::instructionLogged() const
{

}

void
CPU::jumpedTo(u16 addr) const
{
    msgQueue.put(MSG_CPU_JUMPED, CpuMsg { .pc = addr } );
}

void
CPU::jump(u16 addr)
{
    {   SUSPENDED

        debugger.jump(addr);
    }
}

void 
CPU::processCommand(const Cmd &cmd)
{
    switch (cmd.type) {
            
        case CMD_CPU_BRK:
            
            cpu.next = BRK;
            cpu.reg.pc0 = cpu.reg.pc - 1;
            break;
            
        case CMD_CPU_NMI:
            
            if (cmd.value) {
                cpu.pullDownNmiLine(INTSRC_EXP);
            } else {
                cpu.releaseNmiLine(INTSRC_EXP);
            }
            break;

        default:
            fatalError;
    }
}


//
// Memory API
//

u8
CPU::read(u16 addr)
{
    return mem.peek(addr);
}

void
CPU::write(u16 addr, u8 val)
{
    mem.poke(addr, val);
}

u8
CPU::readDasm(u16 addr) const
{
    return mem.spy(addr);
}

u16
CPU::readResetVector()
{
    return cartPort.resetVector();
}

#if PEDDLE_SIMPLE_MEMORY_API == false

namespace tiara::peddle {

#define CHECK_WATCHPOINT \
if constexpr (PEDDLE_ENABLE_WATCHPOINTS) { \
if ((flags & CPU_CHECK_WP) && debugger.watchpointMatches(addr)) { \
watchpointReached(addr); \
}}

template <CPURevision C> u8
Peddle::read(u16 addr)
{
    CHECK_WATCHPOINT

    if (hasProcessorPort<C>()) {

        if (addr < 2) return addr ? readPort() : readPortDir();
    }
    return read(addr & addrMask<C>());
}
template u8 Peddle::read<MOS_6502>(u16 addr);
template u8 Peddle::read<MOS_6507>(u16 addr);
template u8 Peddle::read<MOS_6510>(u16 addr);
template u8 Peddle::read<MOS_8502>(u16 addr);

template <CPURevision C> u8
Peddle::readZeroPage(u8 addr)
{
    CHECK_WATCHPOINT

    switch (C) {

        case MOS_6510: return mem.peekZP(addr);
        case MOS_6502: return id == 1 ? drive8.mem.peekZP(addr) : drive9.mem.peekZP(addr);

        default:
            fatalError;
    }
}
template u8 Peddle::readZeroPage<MOS_6502>(u8 addr);
template u8 Peddle::readZeroPage<MOS_6507>(u8 addr);
template u8 Peddle::readZeroPage<MOS_6510>(u8 addr);
template u8 Peddle::readZeroPage<MOS_8502>(u8 addr);

template <CPURevision C> u8
Peddle::readStack(u8 addr)
{
    CHECK_WATCHPOINT

    switch (C) {

        case MOS_6510: return mem.peekStack(addr);
        case MOS_6502: return id == 1 ? drive8.mem.peekStack(addr) : drive9.mem.peekStack(addr);

        default:
            fatalError;
    }
}
template u8 Peddle::readStack<MOS_6502>(u8 addr);
template u8 Peddle::readStack<MOS_6507>(u8 addr);
template u8 Peddle::readStack<MOS_6510>(u8 addr);
template u8 Peddle::readStack<MOS_8502>(u8 addr);

template <CPURevision C> void
Peddle::readIdle(u16 addr)
{
    if (PEDDLE_EMULATE_IDLE_ACCESSES) {

        CHECK_WATCHPOINT

        switch (C) {

            case MOS_6510: return mem.peekIdle(addr);
            case MOS_6502: return id == 1 ? drive8.mem.peekIdle(addr) : drive9.mem.peekIdle(addr);

            default:
                fatalError;
        }
    }
}
template void Peddle::readIdle<MOS_6502>(u16 addr);
template void Peddle::readIdle<MOS_6507>(u16 addr);
template void Peddle::readIdle<MOS_6510>(u16 addr);
template void Peddle::readIdle<MOS_8502>(u16 addr);

template <CPURevision C> void
Peddle::readZeroPageIdle(u8 addr)
{
    if (PEDDLE_EMULATE_IDLE_ACCESSES) {

        CHECK_WATCHPOINT

        switch (C) {

            case MOS_6510: return mem.peekZPIdle(addr);
            case MOS_6502: return id == 1 ? drive8.mem.peekZPIdle(addr) : drive9.mem.peekZPIdle(addr);

            default:
                fatalError;
        }
    }
}
template void Peddle::readZeroPageIdle<MOS_6502>(u8 addr);
template void Peddle::readZeroPageIdle<MOS_6507>(u8 addr);
template void Peddle::readZeroPageIdle<MOS_6510>(u8 addr);
template void Peddle::readZeroPageIdle<MOS_8502>(u8 addr);

template <CPURevision C> void
Peddle::readStackIdle(u8 addr)
{
    if (PEDDLE_EMULATE_IDLE_ACCESSES) {

        CHECK_WATCHPOINT

        switch (C) {

            case MOS_6510: return mem.peekStackIdle(addr);
            case MOS_6502: return id == 1 ? drive8.mem.peekStackIdle(addr) : drive9.mem.peekStackIdle(addr);

            default:
                fatalError;
        }
    }
}
template void Peddle::readStackIdle<MOS_6502>(u8 addr);
template void Peddle::readStackIdle<MOS_6507>(u8 addr);
template void Peddle::readStackIdle<MOS_6510>(u8 addr);
template void Peddle::readStackIdle<MOS_8502>(u8 addr);


template <CPURevision C> void
Peddle::write(u16 addr, u8 val)
{
    CHECK_WATCHPOINT

    switch (C) {

        case MOS_6510: return mem.poke(addr, val);
        case MOS_6502: return id == 1 ? drive8.mem.poke(addr, val) : drive9.mem.poke(addr, val);

        default:
            fatalError;
    }
}
template void Peddle::write<MOS_6502>(u16 addr, u8 val);
template void Peddle::write<MOS_6507>(u16 addr, u8 val);
template void Peddle::write<MOS_6510>(u16 addr, u8 val);
template void Peddle::write<MOS_8502>(u16 addr, u8 val);

template <CPURevision C> void
Peddle::writeZeroPage(u8 addr, u8 val)
{
    CHECK_WATCHPOINT

    switch (C) {

        case MOS_6510: return mem.pokeZP(addr, val);
        case MOS_6502: return id == 1 ? drive8.mem.pokeZP(addr, val) : drive9.mem.pokeZP(addr, val);

        default:
            fatalError;
    }
}
template void Peddle::writeZeroPage<MOS_6502>(u8 addr, u8 val);
template void Peddle::writeZeroPage<MOS_6507>(u8 addr, u8 val);
template void Peddle::writeZeroPage<MOS_6510>(u8 addr, u8 val);
template void Peddle::writeZeroPage<MOS_8502>(u8 addr, u8 val);

template <CPURevision C> void
Peddle::writeStack(u8 addr, u8 val)
{
    CHECK_WATCHPOINT

    switch (C) {

        case MOS_6510: return mem.pokeStack(addr, val);
        case MOS_6502: return id == 1 ? drive8.mem.pokeStack(addr, val) : drive9.mem.pokeStack(addr, val);

        default:
            fatalError;
    }
}
template void Peddle::writeStack<MOS_6502>(u8 addr, u8 val);
template void Peddle::writeStack<MOS_6507>(u8 addr, u8 val);
template void Peddle::writeStack<MOS_6510>(u8 addr, u8 val);
template void Peddle::writeStack<MOS_8502>(u8 addr, u8 val);

template <CPURevision C> u16
Peddle::readResetVector()
{
    u16 addr = 0xFFFC & addrMask<C>();
    return u16(read<C>(addr) | read<C>(addr + 1) << 8);
}
template u16 Peddle::readResetVector<MOS_6502>();
template u16 Peddle::readResetVector<MOS_6507>();
template u16 Peddle::readResetVector<MOS_6510>();
template u16 Peddle::readResetVector<MOS_8502>();

}

#endif

}

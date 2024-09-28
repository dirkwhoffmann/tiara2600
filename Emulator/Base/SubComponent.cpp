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
#include "SubComponent.h"
#include "Emulator.h"

namespace tiara {

References::References(C64& ref) :

audioPort(ref.audioPort),
c64(ref),
cia1(ref.cia1),
cia2(ref.cia2),
port1(ref.port1),
port2(ref.port2),
cpu(ref.cpu),
expansionPort(ref.expansionport),
host(ref.host),
dmaDebugger(ref.dmaDebugger),
mem(ref.mem),
monitor(ref.monitor),
msgQueue(ref.msgQueue),
recorder(ref.recorder),
regressionTester(ref.regressionTester),
remoteManager(ref.remoteManager),
retroShell(ref.retroShell),
tia(ref.tia),
videoPort(ref.videoPort)
{

};

SubComponent::SubComponent(C64& ref) : CoreComponent(ref.emulator), References(ref) { };
SubComponent::SubComponent(C64& ref, isize id) : CoreComponent(ref.emulator, id), References(ref) { };

void
SubComponent::prefix(isize level, const char *component, isize line) const
{
    c64.prefix(level, component, line);
}

}

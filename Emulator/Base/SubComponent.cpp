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

References::References(Atari& ref) :

audioPort(ref.audioPort),
atari(ref),
pia(ref.pia),
port1(ref.port1),
port2(ref.port2),
cpu(ref.cpu),
host(ref.host),
logicAnalyzer(ref.logicAnalyzer),
mem(ref.mem),
monitor(ref.monitor),
msgQueue(ref.msgQueue),
regressionTester(ref.regressionTester),
remoteManager(ref.remoteManager),
retroShell(ref.retroShell),
tia(ref.tia),
videoPort(ref.videoPort)
{

};

SubComponent::SubComponent(Atari& ref) : CoreComponent(ref.emulator), References(ref) { };
SubComponent::SubComponent(Atari& ref, isize id) : CoreComponent(ref.emulator, id), References(ref) { };

void
SubComponent::prefix(isize level, const char *component, isize line) const
{
    atari.prefix(level, component, line);
}

}

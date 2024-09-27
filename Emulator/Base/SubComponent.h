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

#include "CoreComponent.h"

namespace tiara {

class References {

protected:

    class AudioPort &audioPort;
    class C64 &c64;
    class CIA1 &cia1;
    class CIA2 &cia2;
    class ControlPort &port1;
    class ControlPort &port2;
    class CPU &cpu;
    class ExpansionPort &expansionPort;
    class Host &host;
    class Memory &mem;
    class Monitor &monitor;
    class MsgQueue &msgQueue;
    class Recorder &recorder;
    class RegressionTester &regressionTester;
    class RemoteManager &remoteManager;
    class RetroShell &retroShell;
    class TIA &tia;
    class VICII &vic;
    class VideoPort &videoPort;

public:

    References(C64& ref);
};

class SubComponent : public CoreComponent, public References {

public:

    SubComponent(C64& ref);
    SubComponent(C64& ref, isize id);

    void prefix(isize level, const char *component, isize line) const override;
};

}

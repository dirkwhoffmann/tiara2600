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
    class Atari &atari;
    class PIA &pia;
    class CartPort &cartPort;
    class ControlPort &port1;
    class ControlPort &port2;
    class CPU &cpu;
    class Host &host;
    class LogicAnalyzer &logicAnalyzer;
    class Memory &mem;
    class Monitor &monitor;
    class MsgQueue &msgQueue;
    class RegressionTester &regressionTester;
    class RemoteManager &remoteManager;
    class RetroShell &retroShell;
    class TIA &tia;
    class VideoPort &videoPort;

public:

    References(Atari& ref);
};

class SubComponent : public CoreComponent, public References {

public:

    SubComponent(Atari& ref);
    SubComponent(Atari& ref, isize id);

    void prefix(isize level, const char *component, isize line) const override;
};

}

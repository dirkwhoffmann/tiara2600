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

#include "BasicTypes.h"


//
// Enumerations
//

enum_long(COMP_TYPE)
{
    GenericClass,

    // Components
    C64Class,
    CPUClass,
    CIAClass,
    HostClass,
    MemoryClass,
    PIAClass,
    SIDClass,
    SIDBridgeClass,
    TIAClass,
    TODClass,
    VIAClass,

    // Ports
    AudioPortClass,
    ControlPortClass,
    ExpansionPortClass,
    VideoPortClass,

    // Peripherals
    CartridgeClass,
    DriveClass,
    DriveMemoryClass,
    JoystickClass,
    MonitorClass,
    MouseClass,
    PaddleClass,
    ParCableClass
};
typedef COMP_TYPE CType;

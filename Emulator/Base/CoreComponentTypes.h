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
    AtariClass,
    CPUClass,
    HostClass,
    MemoryClass,
    PIAClass,
    TIAClass,
    TODClass,

    // Ports
    CartPortClass,
    AudioPortClass,
    ControlPortClass,
    VideoPortClass,

    // Peripherals
    CartridgeClass,
    JoystickClass,
    MonitorClass,
    MouseClass,
    PaddleClass,

    // Misc
    DetectorClass
};
typedef COMP_TYPE CType;

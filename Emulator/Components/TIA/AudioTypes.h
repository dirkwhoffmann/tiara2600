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
/// @file

#pragma once

#include "Reflection.h"

namespace tiara {

//
// Structures
//

typedef struct
{

}
AudioConfig;

typedef struct
{
    // Registers
    u8 audv;
    u8 audf;
    u8 audc;

    // Counters
    u8 fdiv;
    
    // Shift registers
    u8 poly5;
    u8 poly4;
}
AudioInfo;

typedef struct
{

}
AudioStats;

}

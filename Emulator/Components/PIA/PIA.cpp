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
#include "PIA.h"
#include "Emulator.h"
#include "IOUtils.h"

namespace tiara {

u8
PIA::spypeek(u16 addr)
{
    if ((addr & RAM_MASK) == RAM_MATCH) {

        return ram[addr & 0x7F];
    }
    switch (PIARegister(addr)) {

        default:
            return 0;
    }
}

template <bool debug> void
PIA::execute()
{

}
template void PIA::execute<false>();
template void PIA::execute<true>();

void
PIA::eofHandler()
{

}

}

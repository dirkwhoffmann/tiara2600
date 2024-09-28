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
#include "RIOT.h"
#include "Emulator.h"
#include "IOUtils.h"

namespace tiara {

template <bool debug> void
RIOT::execute()
{

}
template void RIOT::execute<false>();
template void RIOT::execute<true>();

void
RIOT::eofHandler()
{

}

}

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
#include "Cartridge.h"
#include "Atari.h"

namespace tiara {

bool
Cartridge::isSupportedType(CartridgeType type)
{
    if (FORCE_CRT_UNSUPPORTED) return false;

    switch (type) {

        case CRT_NONE:
        case CRT_NORMAL:

            return true;
            
        default:
            break;
    }

    return false;
}

Cartridge *
Cartridge::makeWithType(Atari &c64, CartridgeType type)
{
    Cartridge *cart;

    switch (type) {

        case CRT_NONE:              cart = new Cartridge(c64); break;
        case CRT_NORMAL:            cart = new Cartridge(c64); break;
        // case CRT_SIMONS_BASIC:      cart = new SimonsBasic(c64); break;

        default:
            throw Error(VC64ERROR_CRT_UNSUPPORTED, std::to_string(type));
    }

    cart->init();
    return cart;
}

Cartridge *
Cartridge::makeWithFile(Atari &c64, const RomFile &file)
{
    // Try to create the cartridge
    Cartridge *cart = makeWithType(c64, CRT_NORMAL);

    if (CRT_DEBUG) cart->dump(Category::State);
    return cart;
}

Cartridge::Cartridge(Atari &ref) : SubComponent(ref)
{
    trace(CRT_DEBUG, "Creating cartridge at address %p...\n", (void *)this);
}

Cartridge::~Cartridge()
{
    trace(CRT_DEBUG, "Releasing cartridge...\n");
    dealloc();
}

void
Cartridge::dealloc()
{

}

void
Cartridge::init()
{
    trace(CRT_DEBUG, "Initializing cartridge...\n");
}

void 
Cartridge::cacheInfo(CartridgeInfo &result) const
{

}

}

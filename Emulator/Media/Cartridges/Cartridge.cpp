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

        case CART_4K:

            return true;
            
        default:
            break;
    }

    return false;
}

std::unique_ptr<Cartridge>
Cartridge::makeWithType(Atari &c64, CartridgeType type)
{
    std::unique_ptr<Cartridge> cart;

    switch (type) {

        case CART_4K:           cart = std::make_unique<StdCartridge>(c64); break;
        default:                cart = std::make_unique<Cartridge>(c64); break;
    }

    cart->init();
    return cart;
}

std::unique_ptr<Cartridge>
Cartridge::makeWithFile(Atari &c64, const CartFile &file)
{
    // Create the cartridge
    auto cart = makeWithType(c64, file.traits.cartType);

    // Copy traits and other information
    cart->traits = file.traits;
    cart->predictedCartType = file.traits.cartType;

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

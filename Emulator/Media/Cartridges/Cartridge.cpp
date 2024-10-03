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
Cartridge::isSupportedType(CartType type)
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
Cartridge::makeWithType(Atari &c64, CartType type)
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
Cartridge::makeWithFile(Atari &atari, const CartFile &file)
{
    // Create a new cartridge with the proper subclass
    auto newCart = makeWithType(atari, file.traits.cartType);

    // Copy file contents
    newCart->rom = file.data;
    newCart->traits = file.traits;
    newCart->predictedCartType = file.traits.cartType;

    if (CART_DEBUG) newCart->dump(Category::State);
    return newCart;
}

Cartridge::Cartridge(Atari &ref) : SubComponent(ref)
{
    trace(CART_DEBUG, "Creating cartridge at address %p...\n", (void *)this);
}

Cartridge::~Cartridge()
{
    trace(CART_DEBUG, "Releasing cartridge...\n");
    dealloc();
}

void
Cartridge::dealloc()
{

}

void
Cartridge::init()
{
    trace(CART_DEBUG, "Initializing cartridge...\n");
}

void 
Cartridge::cacheInfo(CartridgeInfo &result) const
{

}

}

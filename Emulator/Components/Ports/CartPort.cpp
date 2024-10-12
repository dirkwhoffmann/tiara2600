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
#include "CartPort.h"

namespace tiara {

CartPort::CartPort(Atari &ref) : SubComponent(ref)
{

};

void
CartPort::attachCartridge(const fs::path &path, bool reset)
{
    CartFile file(path);
    attachCartridge(file, reset);
}

void
CartPort::attachCartridge(const MediaFile &file, bool reset)
{
    SUSPENDED

    try {

        const auto &romFile = dynamic_cast<const CartFile &>(file);
        auto newCartridge = Cartridge::makeWithFile(atari, romFile);
        cart = std::move(newCartridge);

        if (reset) hardReset();

    } catch (...) {

        throw Error(VC64ERROR_FILE_TYPE_MISMATCH);
    }
}

void
CartPort::detachCartridge()
{
    SUSPENDED

    cart = std::make_unique<Cartridge>(atari);
}

void
CartPort::revertCartType()
{
    setCartType(cart->predictedCartType);
}

void
CartPort::setCartType(CartType newType)
{
    debug(CART_DEBUG, "Setting cartridge type to %s\n", CartTypeEnum::key(newType));

    if (cart->traits.cartType != newType) {

        SUSPENDED

        // Create a new cartridge with the proper subclass
        auto newCart = Cartridge::makeWithType(atari, newType);

        // Copy contents from the old cartridge
        newCart->rom = cart->rom;
        newCart->traits = cart->traits;
        newCart->predictedCartType = cart->predictedCartType;

        // Assign the new type
        newCart->traits.cartType = newType;

        // Plug in the new cartridge
        cart = std::move(newCart);
    }
}

u16
CartPort::resetVector() const
{
    return LO_HI(cart->spy(0xFFFC), cart->spy(0xFFFD));
}

}

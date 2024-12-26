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

void
CartPort::_dump(Category category, std::ostream& os) const
{
    using namespace util;

    if (category == Category::Config) {

        dumpConfig(os);

    } else {

        cart->_dump(category, os);
    }
}

void
CartPort::_isReady() const
{
    if (cart->traits.cartType == CART_NONE) throw Error(TIARA_ERROR_CART_MISSING);
}

i64
CartPort::getOption(Option option) const
{
    switch (option) {

        case OPT_CART_TYPE: return cart->traits.cartType;

        default:
            fatalError;
    }
}

void
CartPort::checkOption(Option opt, i64 value)
{
    switch (opt) {

        case OPT_CART_TYPE:

            if (!CartTypeEnum::isValid(value)) {
                throw Error(TIARA_ERROR_OPT_INV_ARG, CartTypeEnum::keyList());
            }
            return;

        default:
            throw Error(TIARA_ERROR_OPT_UNSUPPORTED);
    }
}

void
CartPort::setOption(Option opt, i64 value)
{
    checkOption(opt, value);

    switch (opt) {

        case OPT_CART_TYPE:

            setCartType(CartType(value));
            return;

        default:
            fatalError;
    }
}

}

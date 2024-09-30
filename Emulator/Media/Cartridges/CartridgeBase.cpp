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
#include "IOUtils.h"

namespace tiara {

void
Cartridge::_dump(Category category, std::ostream& os) const
{
    using namespace util;

    if (category == Category::State) {

        os << tab("Cartridge type") << CartridgeTypeEnum::key(traits.cartType) << std::endl;
        os << tab("MD5") << traits.md5 << std::endl;
        os << tab("Name") << traits.name << std::endl;
        os << tab("Manufacturer") << traits.manufacturer << std::endl;
        os << tab("Type") << traits.type << std::endl;
        os << tab("Model") << traits.model << std::endl;
        os << tab("Format") << traits.format << std::endl;
        os << tab("Note") << traits.note << std::endl;
        os << tab("Left") << traits.left << std::endl;
        os << tab("Right") << traits.right << std::endl;
        os << tab("Phosphor") << bol(traits.phosphor) << std::endl;
        os << tab("SwapPorts") << bol(traits.swapPorts) << std::endl;
        os << tab("SwapPaddles") << bol(traits.swapPaddles) << std::endl;
    }
}

}

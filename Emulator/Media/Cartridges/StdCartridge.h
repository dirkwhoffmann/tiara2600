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

#include "Cartridge.h"

namespace tiara {

class StdCartridge final : public Cartridge {

public:

    using Cartridge::Cartridge;

    virtual CartridgeType getCartridgeType() const override { return CRT_NORMAL; }

private:

    // void _didReset(bool hard) override;

};

}

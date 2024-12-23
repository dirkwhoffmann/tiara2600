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

#include <iostream>

namespace tiara {

enum class Category
{
    BankMap,
    Beamtraps,
    Breakpoints,
    Checksums,
    Config,
    Current,
    Debug,
    Defaults,
    Properties,
    Registers,
    RunAhead,
    Slots,
    State,
    Stats,
    Summary,
    Watchpoints
};

class Dumpable {

public:

    virtual ~Dumpable() = default;
    virtual void _dump(Category category, std::ostream& ss) const { }

    void dump(Category category, std::ostream& ss) const;
    void dump(Category category) const;
};

}

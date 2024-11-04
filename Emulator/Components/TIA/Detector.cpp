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
#include "Detector.h"
#include "TIA.h"

namespace tiara {

void
Detector::_dump(Category category, std::ostream& os) const
{
    using namespace util;

    if (category == Category::Config) {

        dumpConfig(os);
    }
}

void
Detector::eofHandler()
{
    const isize tolerance = 20;
    auto y = tia.y;

    if (y > NTSC::HEIGHT - tolerance && y < NTSC::HEIGHT + tolerance) {

        if (ntsc <= 32) ntsc++;
        if (pal > 0) pal--;
    }
    if (y > PAL::HEIGHT - tolerance && y < PAL::HEIGHT + tolerance) {

        if (ntsc > 0) ntsc--;
        if (pal <= 32) pal++;
    }

}

TIARevision
Detector::predict() const
{
    auto current = tia.getConfig().revision;

    if (pal == 32) return current == TIA_SECAM ? TIA_SECAM : TIA_PAL;
    if (ntsc == 32) return TIA_NTSC;

    return current;
}

}

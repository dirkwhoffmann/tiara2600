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

#include "TIAComponents.h"
#include "TIATypes.h"
#include "SubComponent.h"
#include "Constants.h"

namespace tiara {

class Missile final : CoreObject, public Serializable {

    const char *objectName() const override { return "Missile"; }

    DualPhaseCounter<39> counter;
    isize siz = 0;
    bool ena = false;
    bool resmp = false;
    DualPhaseDelay<bool> start1;
    DualPhaseDelay<bool> start2;

public:

    Missile& operator= (const Missile& other) {
        
        CLONE(counter);
        CLONE(siz);
        CLONE(ena);
        CLONE(resmp);
        CLONE(start1);
        CLONE(start2);

        return *this;
    }
    
    template <class T>
    void serialize(T& worker)
    {
        worker

        << counter
        << siz
        << ena
        << resmp
        << start1
        << start2;

    } SERIALIZERS(serialize);

    u8 spyNUSIZ() const { return (u8)siz; }
    u8 spyENAM() const { return ena ? 0x02 : 0x00; }
    u8 spyRESMP() const { return resmp ? 0x02 : 0x00; }

    void pokeNUSIZ(u8 val) { siz = (val >> 4) & 0x03; }
    void pokeENAM(u8 val) { ena = val & 0x02; }
    void pokeRESMP(u8 val) { resmp = val & 0x02; }

    bool get() const;

    void alwaysinline execute(bool clk, bool rst, class Player &player);
};

}

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

class Player final : CoreObject, public Serializable {

    const char *objectName() const override { return "Player"; }

    DualPhaseCounter<39> counter;
    DualPhaseDelay<isize> start;
    u8 grp[2] {};
    isize sc = 0;
    isize nusiz= 0;
    bool vdelp = false;
    bool ena = false;
    bool refp = false;


    //
    // Methods from Serializable
    //

public:

    template <class T>
    void serialize(T& worker)
    {
        worker

        << counter
        << start
        << grp
        << sc
        << nusiz
        << vdelp
        << ena
        << refp;

    } SERIALIZERS(serialize);

    void pokeNUSIZ(u8 val) { nusiz = val & 0x7; }
    void pokeGRP(u8 val) { grp[0] = val; }
    void pokeVDELP(u8 val) { vdelp = val & 0x1; }
    void pokeREFP(u8 val) { refp = val & 0x8; }
    void vshift() { grp[1] = grp[0]; }

    isize getNUSIZ() const { return nusiz; }
    u8 getGRP() const { return grp[0]; }
    u8 getVDELP() const { return vdelp; }
    u8 getREFP() const { return refp; }
    bool getRESMP() const { return ena && (sc == 1) && (start.get() == 1); }

    bool get() const;

    void alwaysinline execute(bool clk, bool rst);
};

}

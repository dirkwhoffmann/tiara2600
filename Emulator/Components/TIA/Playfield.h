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

class Playfield final : CoreObject, public Serializable {

    // The 20-bit playfield register
    u32 playfield = 0;

    // PF line (playfield serial graphics output)
    DualPhaseDelay<bool> pf{};

    // REF bit (reflect playfield bit in CTRLPF)
    bool ref = false;

    // Bit selection masks
    u32 fwdMask = 0;
    u32 bwdMask = 0;

public:

    const char *objectName() const override { return "Playfield"; }
    
    Playfield& operator= (const Playfield& other) {
        
        CLONE(playfield);
        CLONE(pf);
        CLONE(ref);
        CLONE(fwdMask);
        CLONE(bwdMask);
        
        return *this;
    }
    
    template <class T>
    void serialize(T& worker)
    {
        worker

        << playfield
        << pf
        << ref
        << fwdMask
        << bwdMask;

    } SERIALIZERS(serialize);

public:

    u8 spyPF0() const;
    u8 spyPF1() const;
    u8 spyPF2() const;

    void setPF0(u8 val);
    void setPF1(u8 val);
    void setPF2(u8 val);

    void setREF(bool val) { ref = val; }
    bool get() const;

    template <bool fastPath, bool phi1, bool phi2> void alwaysinline execute(const class TIA &tia, isize curr)
    {
        // Shift bit selection masks
        if (phi2) { fwdMask <<= 1; bwdMask >>= 1; }

        // Reset masks at the proper horizontal positions
        if (curr == 16) { fwdMask = 0x00001; }
        if (curr == 36) { ref ? (bwdMask = 0x80000) : (fwdMask = 0x00001); }

        // Feed the dual-phase latch
        pf.execute(phi1, phi2, playfield & (fwdMask | bwdMask));
    }
};

}

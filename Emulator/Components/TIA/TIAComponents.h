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

#include "TIATypes.h"
#include "Serializable.h"

namespace tiara {

template <typename T>
class DualPhaseDelay : public Serializable {

    T t[2];

public:

    template <class W>
    void serialize(W& worker)
    {
        worker << t;

    } SERIALIZERS(serialize);

    void execute(bool phi1, bool phi2, T val, bool reset = false) {

        // Run the pipeline
        if (phi1) { t[0] = val; } else if (phi2) { t[1] = t[0]; }

        // Emulate the reset line
        if (reset) { t[1] = T(0); }
    }

    T get() const { return t[1]; }
};

template <typename T>
class DualPhaseDelayLatch : public DualPhaseDelay<T> {

public:

    void execute(bool phi1, bool phi2, T val, bool reset = false) {

        DualPhaseDelay<T>::execute(phi1, phi2, val | this->get(), reset);
    }
};


/* The dual-phase counter is a central building block of the TIA design. In
 * total, five counters of this type are utilized:
 *
 *   - The horizontal counter
 *   - The two player counters
 *   - The two missile counters
 *   - The ball counter
 *
 * Each counter consists of two parts:
 *
 *  1. The dual-phase clock generator. It takes the clock signal CLK and a
 *     reset signal RES as inputs and outputs a dual-phase clock signal
 *     (phi1,phi2) and RESL, a latched version of RES.
 *
 *     Phase: | 0 | 1 | 2 | 3 | 0 | 1 | 2 | 3 | 0 | 1 | 2 | 3 |
 *
 *     Phi1:   ---             ---             ---
 *            | 1 | 0   0   0 | 1 | 0   0   0 | 1 | 0   0   0
 *                  -----------     -----------    ------------
 *     Phi2:           ---             ---             ---
 *              0   0 | 1 | 0   0   0 | 1 | 0   0   0 | 1 | 0
 *            --------     -----------     -----------     ----
 *
 * 2. The actual counter. The couter is advanced via phi2. It either increments
 *    by one or resets. A reset is triggered by RESL or on overflow.
 */
template <int max> class DualPhaseCounter : public Serializable {

public:

    // Phase counter
    isize phase = 0;

    // Counter value
    isize current = 0;

    // Reset line
    bool res = false;

    // Latched reset value
    bool resl = false;

    template <class W>
    void serialize(W& worker)
    {
        worker

        << phase
        << current
        << res
        << resl;

    } SERIALIZERS(serialize);

    bool phi1() const { return phase == 0; }
    bool phi2() const { return phase == 2; }

    void execute(bool clk, bool rst) {

        if (rst) {

            // Reset the phase counter
            phase = 0;

            // Latch the reset signal
            resl = true;

        } else if (clk) {

            execute();
        }
    }

    void execute() {

        // Advance the phase counter
        phase = (phase + 1) & 0b11;

        // Advance or reset the actual counter
        if (phase == 2) {

            res = resl | (current == max);
            current = res ? 0 : current + 1;
            resl = false;
        }
    }
};

/* The purpose of the SEC logic is to synchronize the strobe signal HMOVE with
 * the horizontal dual-phase clock. It produces the dual-phase pulse called
 * SEC in the TIA schematics. */

class SEC : public Serializable {

    friend class TIA;

    // Pipeline
    bool s0{}, s1{};

    // HMOVEL latch
    bool hmovel = false;

public:

    template <class W>
    void serialize(W& worker)
    {
        worker

        << s0
        << s1
        << hmovel;

    } SERIALIZERS(serialize);

    bool get() const { return s1; }

    template <bool fastPath, bool phi1, bool phi2>
    void execute(bool hmove) {

        // Latch the HMOVE signal
        hmovel |= hmove;

        // On phi2, transfer s0 to s1
        if (phi2) { s1 = s0; }

        // On phi1, clear the latch if s1 equals 1 and feed the result into s0
        if (phi1) { hmovel &= !s1; s0 = hmovel; }
    }
};

/* Extra clocking logic
 *
 */

class ExtraClock : public Serializable {

    friend class TIA;
    
    bool ena[2]{};
    isize hm{};

public:

    template <class W>
    void serialize(W& worker)
    {
        worker

        << ena
        << hm;

    } SERIALIZERS(serialize);

    template <bool fastPath, bool phi1, bool phi2>
    void execute(bool sec, isize hmc) {

        if constexpr (phi1) {

            bool rst = (hmc == hm);
            ena[0] = (ena[1] | sec) & !rst;
        }

        if constexpr (phi2) {

            ena[1] = ena[0];
        }
    }

    u8 spyHM() const { return u8(hm) & 0x0F << 4; }
    void setHM(u8 data = 0) { hm = 8 + ((i8)data >> 4); }
    void resetHM() { hm = 8; }
    bool enabled() const { return ena[1]; }
};

}

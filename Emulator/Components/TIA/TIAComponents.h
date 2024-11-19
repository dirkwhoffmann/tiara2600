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

/*
 *
 */
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

        // Check for the reset signal
        if (reset) { t[1] = T(0); }
    }

    T get() const { return t[1]; }
    // T neg() const { return ~t[1]; }
};

/*
 *
 */
template <typename T>
class DualPhaseDelayLatch : public DualPhaseDelay<T> {

public:

    void execute(bool phi1, bool phi2, T val, bool reset = false) {

        DualPhaseDelay<T>::execute(phi1, phi2, val | this->get(), reset);
    }
};


/*
 *
 */
template <int max> class DualPhaseCounter : public Serializable {

public:

    // Counter value
    isize current{};

    // Phase counter
    isize phase{};

    // Reset line
    bool res{};

    // Latched reset value
    bool resl{};

public:

    template <class W>
    void serialize(W& worker)
    {
        worker

        << current
        << phase
        << res
        << resl;

    } SERIALIZERS(serialize);

    void execute(bool clk, bool rst) {

        if (rst) {

            // Reset the phase counter and the latched reset value
            phase = 0;
            resl = true;
            return;
        }
        if (clk) {

            // Advance the phase counter
            phase = (phase + 1) & 0b11;

            // Advance or reset the actual counter
            if (phase == 2) {

                res = resl | (current == max);
                current = res ? 0 : current + 1;
                resl = false;
            }
        }
    }

    bool phi1() const { return phase == 0; }
    bool phi2() const { return phase == 2; }
};

/* The purpose of the SEC logic is to synchronize the strobe signal HMOVE with
 * the horizontal dual-phase clock. It produces the dual-phase pulse called
 * SEC in the TIA schematics. */

class SEC : public Serializable {

    // Pipeline
    bool s0{}, s1{};

    // HMOVEL latch
    bool hmovel{};

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

    void execute(bool phi1, bool phi2, bool hmove) {

        // On phi2, transfer s0 to s1
        if (phi2) { s1 = s0; }

        // Latch the HMOVE signal
        hmovel |= hmove;

        // On phi1, clear the latch if s1 == 1 and feed the result back to s0
        if (phi1) { hmovel &= !s1; s0 = hmovel; }
    }

};

/* Extra clocking logic
 *
 */

class ExtraClock : public Serializable {

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

    void execute(bool phi1, bool phi2, bool sec, isize hmc) {

        if (phi1) {

            bool rst = (hmc == hm);
            ena[0] = (ena[1] | sec) & !rst;

        } else if (phi2) {

            ena[1] = ena[0];
        }
    }

    void setHM(u8 data = 0) { hm = 8 + ((i8)data >> 4); }
    void resetHM() { hm = 8; }
    bool enabled() const { return ena[1]; }
};

}

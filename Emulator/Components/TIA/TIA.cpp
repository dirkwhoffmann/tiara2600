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
#include "TIA.h"
#include "Atari.h"

namespace tiara {

// REMOVE ASAP
static u32 oldcx = 0;

void
TIA::_initialize()
{
    for (isize obj = 0; obj < 64; obj++) {

        bool pf = obj & (1 << TIA_PF);
        bool bl = obj & (1 << TIA_BL);
        bool m0 = obj & (1 << TIA_M0);
        bool m1 = obj & (1 << TIA_M1);
        bool p0 = obj & (1 << TIA_P0);
        bool p1 = obj & (1 << TIA_P1);

        u32 collision =
        (m0 && p0) << 0  | // CXM0P
        (m0 && p1) << 1  | //
        (m1 && p1) << 2  | // CXM1P
        (m1 && p0) << 3  | //
        (p0 && bl) << 4  | // CXP0FB
        (p0 && pf) << 5  | //
        (p1 && bl) << 6  | // CXP1FB
        (p1 && pf) << 7  | //
        (m0 && bl) << 8  | // CXM0FB
        (m0 && pf) << 9  | //
        (m1 && bl) << 10 | // CXM1FB
        (m1 && pf) << 11 | //
        /* unused */       // CXBLPF
        (bl && pf) << 13 | //
        (m0 && m1) << 14 | // CXPPMM
        (p0 && p1) << 15 ; //

        for (isize pfp = 0; pfp < 2; pfp++) {
            for (isize score = 0; score < 2; score++) {
                for (isize side = 0; side < 2; side++) {

                    TIAColor pfcolor =
                    score ? (side ? TIA_COLOR_PM1 : TIA_COLOR_PM0) : TIA_COLOR_PF;

                    if (pfp) {

                        lookup[pfp][score][side][obj].color =
                        pf || bl ? pfcolor :        // Highest Priority PF, BL
                        p0 || m0 ? TIA_COLOR_PM0 :  // Second Highest P0, M0
                        p1 || m1 ? TIA_COLOR_PM1 :  // Third Highest P1, M1
                        TIA_COLOR_BK;               // Lowest Priority BK

                    } else {

                        lookup[pfp][score][side][obj].color =
                        p0 || m0 ? TIA_COLOR_PM0 :  // Highest Priority P0, M0
                        p1 || m1 ? TIA_COLOR_PM1 :  // Second Highest P1, M1
                        pf || bl ? pfcolor  :       // Third Highest PF, BL
                        TIA_COLOR_BK;               // Lowest Priority BK

                    }

                    lookup[pfp][score][side][obj].collison = collision;
                }
            }
        }
    }
}

void
TIA::_didReset(bool hard)
{
    if (hard) {

        clearStats();

        // Reset the beam position
        x = y = 0;

        // Reset counters
        hc = { .phase = 1, .current = 56, .resl = false, .res = true };

        // Reset latches
        rdy = true;

        // Reset signals
        strobe = TIA_VOID;

        // Reset the screen buffers
        resetEmuTextures();
        resetDmaTextures();
        emuTexture = emuTexture1;
        dmaTexture = dmaTexture1;
    }
}

void
TIA::_trackOn()
{

}

void
TIA::_trackOff()
{

}

isize
TIA::diff(isize y, isize x)
{
    return (y - this->y) * TIA_CYCLES_PER_LINE + (x - this->x);
}

u32 *
TIA::getTexture() const
{
    return emuTexture == emuTexture1 ? emuTexture2 : emuTexture1;
}

u32 *
TIA::getDmaTexture() const
{
    return dmaTexture == dmaTexture1 ? dmaTexture2 : dmaTexture1;
}

void
TIA::resetEmuTexture(isize nr)
{
    assert(nr == 1 || nr == 2);

    if (nr == 1) { resetTexture(emuTexture1); }
    if (nr == 2) { resetTexture(emuTexture2); }
}

void
TIA::resetDmaTexture(isize nr)
{
    assert(nr == 1 || nr == 2);

    u32 *p = nr == 1 ? dmaTexture1 : dmaTexture2;

    for (isize i = 0; i < Texture::height * Texture::width; i++) {
        p[i] = 0xFF000000;
    }
}

void
TIA::resetTexture(u32 *p)
{
    // Draw a checkerboard pattern
    for (isize y = 0; y < Texture::height; y++) {

        for (isize x = 0; x < Texture::width; x++) {

            isize pos = y * Texture::width + x;
            p[pos] = (y / 4) % 2 == (x / 3) % 2 ? 0xFF222222 : 0xFF444444;
        }
    }
}

void
TIA::drawPixel(isize x, isize y, u32 color)
{
    assert(x < Texture::width);
    assert(y < Texture::height);

    emuTexture[y * Texture::width + x] = color;
}

void
TIA::drawDebugPixel(isize x, isize y, u32 color)
{
    assert(x < Texture::width);
    assert(y < Texture::height);

    dmaTexture[y * Texture::width + x] = color;
}

u8
TIA::peek(u16 addr)
{
    return spy(addr);
}

u8
TIA::spy(u16 addr) const
{
    auto setCX = [&](u8 val) { return u8((val & 0xC0) | (atari.dataBus & 0x3F)); };
    auto setINP = [&](bool val) { return u8((atari.dataBus & 0x3F) | (val ? 0x80 : 0x00)); };
    auto mask = [&]() { return 0; }; // cx & config.collisionMask; };

    switch (TIARegister(addr)) {

        case TIA_COLUP0:    return colup0;
        case TIA_COLUP1:    return colup1;
        case TIA_COLUPF:    return colupf;
        case TIA_COLUBK:    return colubk;

        case TIA_CTRLPF:    return ctrlpf;

        case TIA_CXM0P:     return setCX(u8(mask() << 6));
        case TIA_CXM1P:     return setCX(u8(mask() << 4));
        case TIA_CXP0FB:    return setCX(u8(mask() << 2));
        case TIA_CXP1FB:    return setCX(u8(mask() << 0));
        case TIA_CXM0FB:    return setCX(u8(mask() >> 2));
        case TIA_CXM1FB:    return setCX(u8(mask() >> 4));
        case TIA_CXBLPF:    return setCX(u8(mask() >> 6));
        case TIA_CXPPMM:    return setCX(u8(mask() >> 8));

        case TIA_INPT0:     return setINP(0);
        case TIA_INPT1:     return setINP(0);
        case TIA_INPT2:     return setINP(0);
        case TIA_INPT3:     return setINP(0);
        case TIA_INPT4:     return setINP(GET_BIT(port1.getTiaBits(), 4));
        case TIA_INPT5:     return setINP(GET_BIT(port1.getTiaBits(), 5));

        default:
            return 0;
    }
}

void
TIA::poke(TIARegister reg, u8 val)
{
    poke(reg, val, 0);
}

void
TIA::poke(TIARegister reg, u8 val, Cycle delay)
{
    auto unsupported = [&]() {
        debug(TIA_REG_DEBUG,
              "Ignoring write to TIA register %s\n", TIARegisterEnum::key(reg));
    };

    if (delay) {

        debug(TIA_REG_DEBUG, "%s = %02X (in %lld cycles)\n", TIARegisterEnum::key(reg), val, delay);

        assert(!atari.hasEvent<SLOT_REG>());
        atari.scheduleRel<SLOT_REG>(delay, REG_WRITE_TIA, HI_LO(reg, val));
        return;
    }

    debug(TIA_REG_DEBUG, "%s = %02X\n", TIARegisterEnum::key(reg), val);

    dataBus = val;

    switch(reg) {

        case TIA_VSYNC:

            vsedge = RISING_EDGE(vs, val & 0x02);
            vs = val & 0x02;
            break;

        case TIA_VBLANK:    strobe = reg; break;
        case TIA_WSYNC:     strobe = reg; break;
        case TIA_NUSIZ0:    p0.pokeNUSIZ(val); m0.pokeNUSIZ(val); break;
        case TIA_NUSIZ1:    p1.pokeNUSIZ(val); m1.pokeNUSIZ(val); break;

        case TIA_COLUP0:

            colup0 = val & 0b11111110;
            rgba[TIA_COLOR_PM0] = monitor.getColor(colup0 >> 1);
            break;

        case TIA_COLUP1:

            colup1 = val & 0b11111110;
            rgba[TIA_COLOR_PM1] = monitor.getColor(colup1 >> 1);
            break;

        case TIA_COLUPF:

            colupf = val & 0b11111110;
            rgba[TIA_COLOR_PF] = monitor.getColor(colupf >> 1);
            break;

        case TIA_COLUBK:

            colubk = val & 0b11111110;
            rgba[TIA_COLOR_BK] = monitor.getColor(colubk >> 1);
            break;

        case TIA_CTRLPF:

            ctrlpf = val & 0b00110111;
            score = !!GET_BIT(val, 1);
            pfp = !!GET_BIT(val, 2);
            pf.setREF(val & 0b00000001);
            bl.pokeCTLRPF(val);
            break;

        case TIA_REFP0:     p0.pokeREFP(val); break;
        case TIA_REFP1:     p1.pokeREFP(val); break;
        case TIA_PF0:       pf.setPF0(val); break;
        case TIA_PF1:       pf.setPF1(val); break;
        case TIA_PF2:       pf.setPF2(val); break;
        case TIA_RESP0:     strobe = reg; break;
        case TIA_RESP1:     strobe = reg; break;
        case TIA_RESM0:     strobe = reg; break;
        case TIA_RESM1:     strobe = reg; break;
        case TIA_RESBL:     strobe = reg; break;

        case TIA_AUDC0:
        case TIA_AUDC1:
        case TIA_AUDF0:
        case TIA_AUDF1:
        case TIA_AUDV0:
        case TIA_AUDV1:

            unsupported();
            break;

        case TIA_GRP0:      p0.pokeGRP(val); break;
        case TIA_GRP1:      bl.vshift(); p1.pokeGRP(val); break;
        case TIA_ENAM0:     m0.pokeENAM(val); break;
        case TIA_ENAM1:     m1.pokeENAM(val); break;
        case TIA_ENABL:     bl.pokeENABL(val); break;
        case TIA_HMP0:      strobe = reg; break;
        case TIA_HMP1:      strobe = reg; break;
        case TIA_HMM0:      strobe = reg; break;
        case TIA_HMM1:      strobe = reg; break;
        case TIA_HMBL:      strobe = reg; break;
        case TIA_VDELP0:    unsupported(); break;
        case TIA_VDELP1:    unsupported(); break;
        case TIA_VDELBL:    bl.pokeVDELBL(val); break;
        case TIA_RESMP0:    m0.pokeRESMP(val); break;
        case TIA_RESMP1:    m1.pokeRESMP(val); break;
        case TIA_HMOVE:     strobe = reg; break;

        case TIA_HMCLR:

            blec.resetHM();
            p0ec.resetHM();
            p1ec.resetHM();
            m0ec.resetHM();
            m1ec.resetHM();
            break;

        case TIA_CXCLR:

            cx = 0;
            break;

        case TIA_CXM0P:
        case TIA_CXM1P:
        case TIA_CXP0FB:
        case TIA_CXP1FB:
        case TIA_CXM0FB:
        case TIA_CXM1FB:
        case TIA_CXBLPF:
        case TIA_CXPPMM:
        case TIA_INPT0:
        case TIA_INPT1:
        case TIA_INPT2:
        case TIA_INPT3:
        case TIA_INPT4:
        case TIA_INPT5:

            xfiles("Write to read-only TIA register %s\n", TIARegisterEnum::key(reg));
            break;

        default:
            xfiles("Write to unmapped TIA register %s\n", TIARegisterEnum::key(reg));

    }
}

template <bool debug> void
TIA::execute()
{
    // Emulate three color cycles
    execute <debug, 0> ();
    execute <debug, 1> ();
    execute <debug, 2> ();

    // VSYNC logic
    if (vsedge) {

        atari.eofHandler();
    }
}
template void TIA::execute<false>();
template void TIA::execute<true>();

template <bool debug, isize cycle> void
TIA::execute()
{
    //
    if constexpr (cycle == 2) { strobe = TIA_VOID; }

    // Clock the horizontal counter
    hc.execute(true, false);
    bool phi1 = hc.phi1();
    bool phi2 = hc.phi2();

    // Check for the "Start HBlank" signal
    bool shb = hc.res;

    if (shb && hc.phi2()) {

        x = 0;
        y++;

        // Force a VSYNC event if have reached the texure end
        if (y == Texture::height) {

            // debug(true, "EMERGENCY VSYNC\n");
            y = 0;
            vsedge = true;
        }
    }


    //
    // HM logic
    //

    if (phi2 && (hmc > 0 || sec.get())) hmc = (hmc + 1) & 0xF;


    //
    // SEC logic
    //

    // if (strobe == TIA_HMOVE) trace(true, "strobe == HMOVE\n");
    sec.execute(phi1, phi2, strobe == TIA_HMOVE);
    secl = (secl & !shb) | sec.get();


    //
    // Extra-clock logic
    //

    blec.execute(phi1, phi2, sec.get(), hmc);
    m0ec.execute(phi1, phi2, sec.get(), hmc);
    m1ec.execute(phi1, phi2, sec.get(), hmc);
    p0ec.execute(phi1, phi2, sec.get(), hmc);
    p1ec.execute(phi1, phi2, sec.get(), hmc);


    //
    // HB logic
    //

    hb.execute(phi1, phi2, hc.current == (secl ? 18 : 16), shb);
    auto motck = hb.get();


    //
    // RDY logic
    //

    if (strobe == TIA_WSYNC && rdy) {
        // trace(true, "RDY down\n");
        rdy = false; cpu.pullDownRdyLine();
    }
    if (shb && !rdy) {
        // trace(true, "RDY up\n");
        rdy = true; cpu.releaseRdyLine();
    }


    //
    // Playfield logic
    //

    pf.execute(*this);


    //
    // TIA objects (extra cycles)
    //

    /*
     auto blecEnabled = false;
     auto m0ecEnabled = false;
     auto m1ecEnabled = false;
     auto p0ecEnabled = false;
     auto p1ecEnabled = false;
     */
    auto blecEnabled = phi1 && blec.enabled();
    auto m0ecEnabled = phi1 && m0ec.enabled();
    auto m1ecEnabled = phi1 && m1ec.enabled();
    auto p0ecEnabled = phi1 && p0ec.enabled();
    auto p1ecEnabled = phi1 && p1ec.enabled();

    if (blecEnabled) bl.execute(true, strobe == TIA_RESBL);
    if (m0ecEnabled) m0.execute(true, strobe == TIA_RESM0);
    if (m1ecEnabled) m1.execute(true, strobe == TIA_RESM1);
    if (p0ecEnabled) p0.execute(true, strobe == TIA_RESP0);
    if (p1ecEnabled) p1.execute(true, strobe == TIA_RESP1);


    //
    // Collision logic
    //

    isize index =
    (pf.get() ? (1 << TIA_PF) : 0) |
    (bl.get() ? (1 << TIA_BL) : 0) |
    (m0.get() ? (1 << TIA_M0) : 0) |
    (m1.get() ? (1 << TIA_M1) : 0) |
    (p0.get() ? (1 << TIA_P0) : 0) |
    (p1.get() ? (1 << TIA_P1) : 0) ;

    bool right = (x >= 148);
    auto lup = lookup[pfp][score][right][index]; // TODO: [PFP][SCORE][RIGHT]
    cx |= lup.collison;

    if (oldcx != cx) {
        trace(true, "Collision %x!!!\n", cx);
        oldcx = cx;
    }

    //
    // Drawing
    //

    assert(x < Texture::width);
    assert(y < Texture::height);

    if (hb.get()) {

        TIAColor color = lup.color;
        assert(color >= 0 && color < 4);
        emuTexture[y * Texture::width + x] = rgba[color];

    } else {

        emuTexture[y * Texture::width + x] = 0xFF000000;
    }

    //
    // TIA objects (normal cycles)
    //

    blecEnabled = phi1 && blec.enabled();
    m0ecEnabled = phi1 && m0ec.enabled();
    m1ecEnabled = phi1 && m1ec.enabled();
    p0ecEnabled = phi1 && p0ec.enabled();
    p1ecEnabled = phi1 && p1ec.enabled();

    bl.execute(motck && !blecEnabled, strobe == TIA_RESBL);
    m0.execute(motck && !m0ecEnabled, strobe == TIA_RESM0);
    m1.execute(motck && !m1ecEnabled, strobe == TIA_RESM1);
    p0.execute(motck && !p0ecEnabled, strobe == TIA_RESP0);
    p1.execute(motck && !p1ecEnabled, strobe == TIA_RESP1);


    //
    // Strobes
    //

    if (cycle == 0) {

        switch (strobe) {

            case TIA_VBLANK:

                vb = atari.dataBus & 0x02;
                break;

            case TIA_HMP0:  p0ec.setHM(dataBus); break;
            case TIA_HMP1:  p1ec.setHM(dataBus); break;
            case TIA_HMM0:  m0ec.setHM(dataBus); break;
            case TIA_HMM1:  m1ec.setHM(dataBus); break;
            case TIA_HMBL:  blec.setHM(dataBus); break;

            default:

                break;
        }
    }


    //
    // Logic analyzer
    //

    logicAnalyzer.recordSignals();


    //
    // Beam position
    //

    x++;
}

void
TIA::sofHandler()
{
    y = 0;
    vsedge = false;
}

void
TIA::eofHandler()
{
    // Only proceed if the current frame hasn't been executed in headless mode
    if (atari.getHeadless()) return;

    // Colorize the emulator texture

    // Compute the overlay texture (logic analyzer)
    bool debug = logicAnalyzer.config.enable;
    if (debug) logicAnalyzer.computeOverlay(emuTexture, dmaTexture);

    // Switch texture buffers
    if (emuTexture == emuTexture1) {

        assert(dmaTexture == dmaTexture1);
        emuTexture = emuTexture2;
        dmaTexture = dmaTexture2;
        if (debug) { resetEmuTexture(2); resetDmaTexture(2); }

    } else {

        assert(emuTexture == emuTexture2);
        assert(dmaTexture == dmaTexture2);
        emuTexture = emuTexture1;
        dmaTexture = dmaTexture1;
        if (debug) { resetEmuTexture(1); resetDmaTexture(1); }
    }
}

}

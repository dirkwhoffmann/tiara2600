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
#include "Emulator.h"

namespace tiara {

isize
TIA::diff(isize y, isize x)
{
    return (y - this->y) * TIA_CYCLES_PER_LINE + (x - this->x);
}

/*
void
TIA::setColor(TIARegister reg, u8 r, u8 g, u8 b)
{
    auto dist = [&](u8 r2, u8 g2, u8 b2) {

        // https://stackoverflow.com/questions/9018016/how-to-compare-two-colors-for-similarity-difference
        long rmean = ((long)r + (long)r2) / 2;
        long dr = (long)r - (long)r2;
        long dg = (long)g - (long)g2;
        long db = (long)b - (long)b2;
        return sqrt((((512+rmean)*dr*dr)>>8) + 4*dg*dg + (((767-rmean)*db*db)>>8));
    };

    auto distance = [&](isize color) {

        auto abgr = monitor.getColor(color);
        return dist(NIBBLE0(abgr), NIBBLE1(abgr), NIBBLE2(abgr));
    };

    trace(true, "setColor (%s,%x,%x,%x)\n", TIARegisterEnum::key(reg), r, g, b);

    // Iterate through all colors and find the best match

    isize bestMatch = 0;
    double minDistance = distance(0);

    for (isize i = 1; i < 128; i++) {

        auto d = distance(i);
        if (d < minDistance) { minDistance = d; bestMatch = i; }
    }

    auto abgr = monitor.getColor(bestMatch);
    assert(reg == TIA_COLUP0 || reg == TIA_COLUP1 || reg == TIA_COLUPF || reg == TIA_COLUBK);
    poke(reg, u8(bestMatch << 1));
}
*/

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
    return spy(TIARegister((addr & 0x0F) | 0x30));
}

u8
TIA::spy(TIARegister reg) const
{
    auto setCX = [&](u8 val) { return u8((val & 0xC0) | (atari.dataBus & 0x3F)); };
    auto mask = [&]() { return cx & config.collMask; };

    switch (reg) {

        case TIA_VSYNC:     return vs;
        case TIA_VBLANK:    return vblank;
        case TIA_WSYNC:     return strobe == reg ? 1 : 0;
        case TIA_RSYNC:     return strobe == reg ? 1 : 0;
        case TIA_NUSIZ0:    return (u8)p0.getNUSIZ();
        case TIA_NUSIZ1:    return (u8)p1.getNUSIZ();
        case TIA_COLUP0:    return colup0;
        case TIA_COLUP1:    return colup1;
        case TIA_COLUPF:    return colupf;
        case TIA_COLUBK:    return colubk;
        case TIA_CTRLPF:    return ctrlpf;
        case TIA_REFP0:     return p0.getREFP();
        case TIA_REFP1:     return p1.getREFP();
        case TIA_PF0:       return pf.spyPF0();
        case TIA_PF1:       return pf.spyPF1();
        case TIA_PF2:       return pf.spyPF2();
        case TIA_RESP0:     return strobe == reg ? 1 : 0;
        case TIA_RESP1:     return strobe == reg ? 1 : 0;
        case TIA_RESM0:     return strobe == reg ? 1 : 0;
        case TIA_RESM1:     return strobe == reg ? 1 : 0;
        case TIA_RESBL:     return strobe == reg ? 1 : 0;
        case TIA_AUDC0:     return audio[0].getAUDC();
        case TIA_AUDC1:     return audio[1].getAUDC();
        case TIA_AUDF0:     return audio[0].getAUDF();
        case TIA_AUDF1:     return audio[1].getAUDF();
        case TIA_AUDV0:     return audio[0].getAUDV();
        case TIA_AUDV1:     return audio[1].getAUDV();
        case TIA_GRP0:      return p0.getGRP();
        case TIA_GRP1:      return p1.getGRP();
        case TIA_ENAM0:     return m0.spyENAM();
        case TIA_ENAM1:     return m1.spyENAM();
        case TIA_ENABL:     return bl.spyENABL();
        case TIA_HMP0:      return p0ec.spyHM();
        case TIA_HMP1:      return p1ec.spyHM();
        case TIA_HMM0:      return m0ec.spyHM();
        case TIA_HMM1:      return m1ec.spyHM();
        case TIA_HMBL:      return blec.spyHM();
        case TIA_VDELP0:    return p0.getVDELP();
        case TIA_VDELP1:    return p1.getVDELP();
        case TIA_VDELBL:    return bl.spyVDELBL();
        case TIA_RESMP0:    return m0.spyRESMP();
        case TIA_RESMP1:    return m1.spyRESMP();
        case TIA_HMOVE:     return strobe == reg ? 1 : 0;
        case TIA_HMCLR:     return strobe == reg ? 1 : 0;
        case TIA_CXCLR:     return strobe == reg ? 1 : 0;

        case TIA_CXM0P:     return setCX(u8(mask() << 6));
        case TIA_CXM1P:     return setCX(u8(mask() << 4));
        case TIA_CXP0FB:    return setCX(u8(mask() << 2));
        case TIA_CXP1FB:    return setCX(u8(mask() << 0));
        case TIA_CXM0FB:    return setCX(u8(mask() >> 2));
        case TIA_CXM1FB:    return setCX(u8(mask() >> 4));
        case TIA_CXBLPF:    return setCX(u8(mask() >> 6));
        case TIA_CXPPMM:    return setCX(u8(mask() >> 8));
        case TIA_INPT0:     return inpt[0] | (atari.dataBus & 0x3F);
        case TIA_INPT1:     return inpt[1] | (atari.dataBus & 0x3F);
        case TIA_INPT2:     return inpt[2] | (atari.dataBus & 0x3F);
        case TIA_INPT3:     return inpt[3] | (atari.dataBus & 0x3F);
        case TIA_INPT4:     return inpt[4] | (atari.dataBus & 0x3F);
        case TIA_INPT5:     return inpt[5] | (atari.dataBus & 0x3F);

        default:

            debug(TIA_REG_DEBUG,
                  "Ignoring READ from TIA register %lx (%s)\n", reg, TIARegisterEnum::key(reg));

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
    if (config.lockMask & (1LL << reg)) {

        debug(TIA_REG_DEBUG, "Blocking write to %s\n", TIARegisterEnum::key(reg));
        return;
    }

    if (config.watchMask & (1LL << reg)) {

        atari.signalWatchpoint();
        debug(TIA_REG_DEBUG, "Interrupting write to %s\n", TIARegisterEnum::key(reg));
        return;
    }

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
            rgba[TIA_COLOR_P0] = monitor.getColor(colup0 >> 1);
            break;

        case TIA_COLUP1:

            colup1 = val & 0b11111110;
            rgba[TIA_COLOR_P1] = monitor.getColor(colup1 >> 1);
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

        case TIA_AUDC0:     audio[0].pokeAUDC(val); break;
        case TIA_AUDC1:     audio[1].pokeAUDC(val); break;
        case TIA_AUDF0:     audio[0].pokeAUDF(val); break;
        case TIA_AUDF1:     audio[1].pokeAUDF(val); break;
        case TIA_AUDV0:     audio[0].pokeAUDV(val); break;
        case TIA_AUDV1:     audio[1].pokeAUDV(val); break;

        case TIA_GRP0:      p0.pokeGRP(val); p1.vshift(); break;
        case TIA_GRP1:      p1.pokeGRP(val); p0.vshift(); bl.vshift(); break;
        case TIA_ENAM0:     m0.pokeENAM(val); break;
        case TIA_ENAM1:     m1.pokeENAM(val); break;
        case TIA_ENABL:     bl.pokeENABL(val); break;
        case TIA_HMP0:      strobe = reg; break;
        case TIA_HMP1:      strobe = reg; break;
        case TIA_HMM0:      strobe = reg; break;
        case TIA_HMM1:      strobe = reg; break;
        case TIA_HMBL:      strobe = reg; break;
        case TIA_VDELP0:    p0.pokeVDELP(val); break;
        case TIA_VDELP1:    p1.pokeVDELP(val); break;
        case TIA_VDELBL:    bl.pokeVDELBL(val); break;
        case TIA_RESMP0:    m0.pokeRESMP(val); break;
        case TIA_RESMP1:    m1.pokeRESMP(val); break;
        case TIA_HMOVE:     strobe = reg; break;

        case TIA_HMCLR:

            blec.setHM(0);
            p0ec.setHM(0);
            p1ec.setHM(0);
            m0ec.setHM(0);
            m1ec.setHM(0);
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

void
TIA::updateInpt()
{
    inpt[4] = inptLatched ? inpt[4] : 0x80;
    inpt[4] &= port1.getTiaBits();

    inpt[5] = inptLatched ? inpt[5] : 0x80;
    inpt[5] &= port2.getTiaBits();
}

template <bool fastPath> void
TIA::execute()
{
    // Cycle 0
    hc.execute();
    hc.phi1() ? execute <fastPath, 1, 0> (0) :
    hc.phi2() ? execute <fastPath, 0, 1> (0) : execute <fastPath, 0, 0> (0);

    // Cycle 1
    hc.execute();
    hc.phi1() ? execute <fastPath, 1, 0> (1) :
    hc.phi2() ? execute <fastPath, 0, 1> (1) : execute <fastPath, 0, 0> (1);

    strobe = TIA_VOID;

    // Cycle 2
    hc.execute();
    hc.phi1() ? execute <fastPath, 1, 0> (2) :
    hc.phi2() ? execute <fastPath, 0, 1> (2) : execute <fastPath, 0, 0> (2);

    // VSYNC logic
    if (vsedge) { atari.eofHandler(); }
}
template void TIA::execute<false>();
template void TIA::execute<true>();

template <bool fastPath, bool phi1, bool phi2> void
TIA::execute(isize cycle)
{
    //
    // SHB logic (Start HBlank)
    //

    bool shb = hc.res;

    if (phi2 && shb) {

        x = 0;
        y++;

        // Force a VSYNC event if have reached the texure end
        if (y == Texture::height) {

            debug(TIA_DEBUG, "Emergency VSYNC\n");
            y = 0;
            vsedge = true;
        }
    }


    //
    // HM logic (Horizontal Motion)
    //
    //             ---             ---             ---
    //     Phi2   | 1 | 0   0   0 | 1 | 0   0   0 | 1 | 0   0   0
    //                 -----------     -----------    ------------
    //             ---------------
    //     SEC    | 1   1   1   1 | 0   0   0   0   0   0   0   0
    //                             -------------------------------
    //
    //     HMC     <0> <0> <0> <0> <1> <1> <1> <1> <2> <2> <2> <2>
    //
    //                             ... <15> <15> <15> <15> <0> <0> <0> <0> ...

    if (phi2 && (hmc > 0 || sec.get())) hmc = (hmc + 1) & 0xF;


    //
    // Extra-clocking logic
    //

    sec.execute <fastPath, phi1, phi2> (strobe == TIA_HMOVE);

    if (sec.get()) {

        // Latch the SEC signal
        secl = true;

        // Emulate the extra-clocking logic
        blec.execute <fastPath, phi1, phi2> (true, hmc);
        m0ec.execute <fastPath, phi1, phi2> (true, hmc);
        m1ec.execute <fastPath, phi1, phi2> (true, hmc);
        p0ec.execute <fastPath, phi1, phi2> (true, hmc);
        p1ec.execute <fastPath, phi1, phi2> (true, hmc);

    } else {

        // Reset the SEC latch at the beginning of the horizontal blank area
        secl &= !shb;

        // Emulate the extra-clocking logic
        blec.execute <fastPath, phi1, phi2> (false, hmc);
        m0ec.execute <fastPath, phi1, phi2> (false, hmc);
        m1ec.execute <fastPath, phi1, phi2> (false, hmc);
        p0ec.execute <fastPath, phi1, phi2> (false, hmc);
        p1ec.execute <fastPath, phi1, phi2> (false, hmc);
    }


    //
    // HB logic (Horizontal Blank)
    //

    hb.execute(phi1, phi2, hc.current == (secl ? 18 : 16), shb);
    auto motck = hb.get();


    //
    // RDY logic
    //

    if (rdy) {

        if (strobe == TIA_WSYNC) {

            rdy = false;
            cpu.pullDownRdyLine();
        }

    } else {

        if (shb) {

            rdy = true;
            cpu.releaseRdyLine();
        }
    }


    //
    // Audio logic
    //

    if (phi2 && (hc.current == 9 || hc.current == 37)) {

        audio[0].execute();
        audio[1].execute();
    }


    //
    // Playfield logic
    //

    pf.execute <fastPath, phi1, phi2> (*this, hc.current);


    //
    // TIA objects (extra cycles)
    //

    auto blecEnabled = phi1 && blec.enabled();
    auto m0ecEnabled = phi1 && m0ec.enabled();
    auto m1ecEnabled = phi1 && m1ec.enabled();
    auto p0ecEnabled = phi1 && p0ec.enabled();
    auto p1ecEnabled = phi1 && p1ec.enabled();

    if (blecEnabled) bl.execute(true, strobe == TIA_RESBL);
    if (m0ecEnabled) m0.execute(true, strobe == TIA_RESM0, p0);
    if (m1ecEnabled) m1.execute(true, strobe == TIA_RESM1, p1);
    if (p0ecEnabled) p0.execute(true, strobe == TIA_RESP0);
    if (p1ecEnabled) p1.execute(true, strobe == TIA_RESP1);


    //
    // Drawing and collison detection
    //

    if (!vb) {

        assert(x < Texture::width);
        assert(y < Texture::height);

        isize index =
        (pf.get() ? (1 << TIA_PF) : 0) |
        (bl.get() ? (1 << TIA_BL) : 0) |
        (m0.get() ? (1 << TIA_M0) : 0) |
        (m1.get() ? (1 << TIA_M1) : 0) |
        (p0.get() ? (1 << TIA_P0) : 0) |
        (p1.get() ? (1 << TIA_P1) : 0) ;

        cx |= collisonTable[index];

        if (hb.get()) {

            TIAColor color = colorTable[pfp][score][x >= 148][index];
            assert(color >= 0 && color < 4);

            emuTexture[y * Texture::width + x] = rgba[color];

        } else {

            emuTexture[y * Texture::width + x] = 0xFF000000;
        }

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
    m0.execute(motck && !m0ecEnabled, strobe == TIA_RESM0, p0);
    m1.execute(motck && !m1ecEnabled, strobe == TIA_RESM1, p1);
    p0.execute(motck && !p0ecEnabled, strobe == TIA_RESP0);
    p1.execute(motck && !p1ecEnabled, strobe == TIA_RESP1);


    //
    // Strobes
    //

    if (cycle == 0) {

        switch (strobe) {

            case TIA_VBLANK:

                vblank = atari.dataBus & 0b11000010;

                vb = atari.dataBus & 0x02;
                inptLatched = atari.dataBus & 0x40;
                updateInpt();
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

    if (emulator.isTracking()) logicAnalyzer.recordSignals();


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
    if (tia.getConfig().revision != videoPort.predict()) {
        trace(true, "Switching to %s\n", TIARevisionEnum::key(videoPort.predict()));
        setOption(OPT_TIA_REVISION, videoPort.predict());
    }

    // Only proceed if the current frame hasn't been executed in headless mode
    if (atari.getHeadless()) return;

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

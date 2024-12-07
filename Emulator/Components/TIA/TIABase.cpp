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
#include "IOUtils.h"

namespace tiara {

TIA::TIA(Atari &ref) : SubComponent(ref)
{
    subComponents = std::vector<CoreComponent *> {

        &audio[0],
        &audio[1]
    };
}

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
        // unused          // CXBLPF
        (bl && pf) << 13 | //
        (m0 && m1) << 14 | // CXPPMM
        (p0 && p1) << 15 ; //

        collisonTable[obj] = collision;

        for (isize pfp = 0; pfp < 2; pfp++) {
            for (isize score = 0; score < 2; score++) {
                for (isize side = 0; side < 2; side++) {

                    TIAColor pfcolor =
                    score ? (side ? TIA_COLOR_P1 : TIA_COLOR_P0) : TIA_COLOR_PF;

                    if (pfp) {

                        colorTable[pfp][score][side][obj] =
                        pf || bl ? pfcolor :        // Highest Priority PF, BL
                        p0 || m0 ? TIA_COLOR_P0 :   // Second Highest P0, M0
                        p1 || m1 ? TIA_COLOR_P1 :   // Third Highest P1, M1
                        TIA_COLOR_BK;               // Lowest Priority BK

                    } else {

                        colorTable[pfp][score][side][obj] =
                        p0 || m0 ? TIA_COLOR_P0 :   // Highest Priority P0, M0
                        p1 || m1 ? TIA_COLOR_P1 :   // Second Highest P1, M1
                        pf || bl ? pfcolor  :       // Third Highest PF, BL
                        TIA_COLOR_BK;               // Lowest Priority BK

                    }
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
        hc.phase = 1;
        hc.current = 56;
        hc.resl = false;
        hc.res = true;

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

void
TIA::cacheInfo(TIAInfo &result) const
{
    result.posx = x;
    result.posy = y;

    for (isize i = 0; i < 64; i++) {
        result.regs[i] = spy(TIARegister(i));
    }
}

void
TIA::cacheStats(TIAStats &result) const
{

}

void
TIA::_dump(Category category, std::ostream& os) const
{
    using namespace util;

    auto dumpReg = [&](TIARegister reg) {

        std::vector<string> vec;

        if (config.lockMask & (1LL << reg)) vec.push_back("locked");
        if (config.watchMask & (1LL << reg)) vec.push_back("watched");
        auto attributes = util::concat(vec, ", ");

        std::stringstream ss;
        ss << TIARegisterEnum::key(reg) << " (0x" << std::hex << reg << ")";
        os << tab(ss.str());

        os << hex(spy(reg));
        if (attributes != "") os << " (" << attributes << ")";
        os << std::endl;
    };

    if (category == Category::Config) {

        dumpConfig(os);
    }

    if (category == Category::State) {

        os << tab("X");
        os << dec(0) << std::endl;
        os << tab("Y");
        os << dec(0) << std::endl;
    }

    if (category == Category::Registers) {

        os << "Writable registers:" << std::endl << std::endl;
        for (isize i = 0x00; i < 0x2D; i++) { dumpReg(TIARegister(i)); }
        os << std::endl;
        os << "Readable registers:" << std::endl << std::endl;
        for (isize i = 0x30; i < 0x3E; i++) { dumpReg(TIARegister(i)); }
    }
}

i64
TIA::getOption(Option opt) const
{
    switch (opt) {

        case OPT_TIA_REVISION:        return config.revision;
        case OPT_TIA_AUTO_DETECT:     return config.autoDetect;
        case OPT_TIA_COLLISIONS:      return config.collMask;
        case OPT_TIA_REG_LOCK:        return config.lockMask;
        case OPT_TIA_REG_WATCH:       return config.watchMask;

        default:
            fatalError;
    }
}

void
TIA::checkOption(Option opt, i64 value)
{
    switch (opt) {

        case OPT_TIA_REVISION:

            if (!TIARevisionEnum::isValid(value)) {
                throw Error(VC64ERROR_OPT_INV_ARG, TIARevisionEnum::keyList());
            }
            break;

        case OPT_TIA_AUTO_DETECT:

            break;

        case OPT_TIA_COLLISIONS:

            if (value < 0 || value > 0xFFFF) {
                throw Error(VC64ERROR_OPT_INV_ARG, "0x0000...0xFFFF");
            }
            break;

        case OPT_TIA_REG_LOCK:
        case OPT_TIA_REG_WATCH:

            break;

        default:
            throw Error(VC64ERROR_OPT_UNSUPPORTED);
    }
}

void
TIA::setOption(Option opt, i64 value)
{
    checkOption(opt, value);

    switch (opt) {

        case OPT_TIA_REVISION:

            if (config.revision != TIARevision(value)) {

                config.revision = TIARevision(value);
                monitor.updateColors();
                msgQueue.put(MSG_TIA_REVISION, value);
            }
            break;

        case OPT_TIA_AUTO_DETECT:

            config.autoDetect = bool(value);
            break;

        case OPT_TIA_COLLISIONS:

            config.collMask = u16(value);
            break;

        case OPT_TIA_REG_LOCK:

            config.lockMask = u64(value);
            break;

        case OPT_TIA_REG_WATCH:

            config.watchMask = u64(value);
            break;

        default:
            fatalError;
    }
}

}

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
#include "Atari.h"
#include "Option.h"
#include "Emulator.h"
#include "IOUtils.h"

namespace tiara {

Atari::Atari(class Emulator& ref, isize id) : CoreComponent(ref, id)
{    
    trace(RUN_DEBUG, "Creating virtual C64\n");

    subComponents = std::vector<CoreComponent *> {

        &host,
        &mem,
        &cpu,
        &riot,
        &audioPort,
        &videoPort,
        &port1,
        &port2,
        &monitor,
        &remoteManager,
        &logicAnalyzer,
        &retroShell,
        &regressionTester,
        &tia
    };

    // Assign a unique ID to the CPU
    cpu.setID(0);
}

Atari::~Atari()
{
    trace(RUN_DEBUG, "Destructing virtual C64\n");
}


//
// Methods from Dumpable
//

void
Atari::_dump(Category category, std::ostream& os) const
{
    using namespace util;
    auto append = [&](const string &s1, const string &s2) {
        return s1.empty() ? s2 : s1 + ", " + s2;
    };

    if (category == Category::Config) {

        dumpConfig(os);
    }

    if (category == Category::State) {

        os << tab("Power");
        os << bol(isPoweredOn()) << std::endl;
        os << tab("Running");
        os << bol(isRunning()) << std::endl;
        os << tab("Suspended");
        os << bol(isSuspended()) << std::endl;
        os << tab("Warping");
        os << bol(emulator.isWarping()) << std::endl;
        os << tab("Tracking");
        os << bol(emulator.isTracking()) << std::endl;
        os << std::endl;

        string str = "";
        if (flags & RL::WARP_ON)        str = append(str, "WARP_ON");
        if (flags & RL::WARP_OFF)       str = append(str, "WARP_OFF");
        if (flags & RL::BREAKPOINT)     str = append(str, "BREAKPOINT");
        if (flags & RL::WATCHPOINT)     str = append(str, "WATCHPOINT");
        if (flags & RL::CPU_JAM)        str = append(str, "CPU_JAM");
        if (flags & RL::SINGLE_STEP)    str = append(str, "SINGLE_STEP");

        os << tab("Runloop flags");
        os << (str.empty() ? "-" : str) << std::endl;
        os << std::endl;

        os << tab("Ultimax mode");
        os << bol(getUltimax()) << std::endl;
        os << std::endl;

        os << tab("Frame");
        os << dec(frame) << std::endl;
        os << tab("CPU progress");
        os << dec(cpu.clock) << " Cycles" << std::endl;
    }

    if (category == Category::Summary) {

        auto tiaRev = (TIARevision)emulator.get(OPT_TIA_REVISION);

        os << tab("TIA");
        os << TIARevisionEnum::key(tiaRev) << std::endl;
    }

    if (category == Category::Checksums) {

        for (auto &c : subComponents) {

            os << tab(c->objectName());
            os << hex(c->checksum(false))  << "  " << dec(c->size()) << " bytes";
            os << std::endl;

            for (auto &cc : c->subComponents) {

                os << tab(cc->objectName());
                os << hex(cc->checksum(true)) << "  " << dec(cc->size()) << " bytes";
                os << std::endl;
            }
        }
    }

    if (category == Category::Current) {

        os << std::setfill('0') << std::uppercase << std::hex << std::left;
        os << " PC  SR AC XR YR SP  NV-BDIZC" << std::endl;
        os << std::setw(4) << isize(cpu.reg.pc0) << " ";
        os << std::setw(2) << isize(cpu.getP()) << " ";
        os << std::setw(2) << isize(cpu.reg.a) << " ";
        os << std::setw(2) << isize(cpu.reg.x) << " ";
        os << std::setw(2) << isize(cpu.reg.y) << " ";
        os << std::setw(2) << isize(cpu.reg.sp) << "  ";
        os << (cpu.getN() ? "1" : "0");
        os << (cpu.getV() ? "1" : "0");
        os << "1";
        os << (cpu.getB() ? "1" : "0");
        os << (cpu.getD() ? "1" : "0");
        os << (cpu.getI() ? "1" : "0");
        os << (cpu.getZ() ? "1" : "0");
        os << (cpu.getC() ? "1" : "0");
        os << std::endl;
    }
}


//
// Methods from Configurable
//

i64
Atari::getOption(Option opt) const
{
    switch (opt) {

        case OPT_ATARI_WARP_BOOT:         return config.warpBoot;
        case OPT_ATARI_WARP_MODE:         return config.warpMode;
        case OPT_ATARI_SPEED_BOOST:      return config.speedBoost;
        case OPT_ATARI_VSYNC:             return config.vsync;
        case OPT_ATARI_RUN_AHEAD:         return config.runAhead;
        case OPT_ATARI_SNAP_AUTO:         return config.snapshots;
        case OPT_ATARI_SNAP_DELAY:        return config.snapshotDelay;
        case OPT_ATARI_SNAP_COMPRESS:     return config.compressSnapshots;

        default:
            fatalError;
    }
}

void
Atari::checkOption(Option opt, i64 value)
{
    switch (opt) {

        case OPT_ATARI_WARP_BOOT:

            return;

        case OPT_ATARI_WARP_MODE:

            if (!WarpModeEnum::isValid(value)) {
                throw Error(VC64ERROR_OPT_INV_ARG, WarpModeEnum::keyList());
            }
            return;

        case OPT_ATARI_SPEED_BOOST:

            if (value < 50 || value > 200) {
                throw Error(VC64ERROR_OPT_INV_ARG, "50...200");
            }
            return;

        case OPT_ATARI_VSYNC:

            return;

        case OPT_ATARI_RUN_AHEAD:

            if (value < 0 || value > 12) {
                throw Error(VC64ERROR_OPT_INV_ARG, "0...12");
            }
            return;

        case OPT_ATARI_SNAP_AUTO:

            return;

        case OPT_ATARI_SNAP_DELAY:

            if (value < 10 || value > 3600) {
                throw Error(VC64ERROR_OPT_INV_ARG, "10...3600");
            }
            return;

        case OPT_ATARI_SNAP_COMPRESS:

            return;

        default:
            throw Error(VC64ERROR_OPT_UNSUPPORTED);
    }
}

void
Atari::setOption(Option opt, i64 value)
{
    checkOption(opt, value);

    switch (opt) {

        case OPT_ATARI_WARP_BOOT:

            config.warpBoot = isize(value);
            return;

        case OPT_ATARI_WARP_MODE:

            config.warpMode = WarpMode(value);
            return;

        case OPT_ATARI_VSYNC:

            config.vsync = bool(value);
            return;

        case OPT_ATARI_SPEED_BOOST:

            config.speedBoost = isize(value);
            updateClockFrequency();
            return;

        case OPT_ATARI_RUN_AHEAD:

            config.runAhead = isize(value);
            return;

        case OPT_ATARI_SNAP_AUTO:

            config.snapshots = bool(value);
            scheduleNextSNPEvent();
            return;

        case OPT_ATARI_SNAP_DELAY:

            config.snapshotDelay = isize(value);
            scheduleNextSNPEvent();
            return;

        case OPT_ATARI_SNAP_COMPRESS:

            config.compressSnapshots = bool(value);
            return;

        default:
            fatalError;
    }
}

}
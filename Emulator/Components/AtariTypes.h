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
/// @file

#pragma once

#include "Reflection.h"

namespace tiara {

//
// Type aliases
//

typedef i64 Cycle;


//
// Enumerations
//

enum_long(WARP_MODE)
{
    WARP_AUTO,
    WARP_NEVER,
    WARP_ALWAYS
};
typedef WARP_MODE WarpMode;

struct WarpModeEnum : util::Reflection<WarpModeEnum, WarpMode>
{
    static constexpr long minVal = 0;
    static constexpr long maxVal = WARP_ALWAYS;

    static const char *prefix() { return "WARP"; }
    static const char *_key(long value)
    {
        switch (value) {

            case WARP_AUTO:     return "WARP_AUTO";
            case WARP_NEVER:    return "WARP_NEVER";
            case WARP_ALWAYS:   return "WARP_ALWAYS";
        }
        return "???";
    }
};

enum_long(SLOT)
{
    // Primary slots
    SLOT_REG,                       // Register change
    SLOT_PIA,                       // PIA
    SLOT_SEC,                       // Enables secondary slots

    // Secondary slots
    SLOT_TER,                       // Enables tertiary slots

    // Tertiary slots
    SLOT_EXP,                       // Expansion port
    SLOT_SNP,                       // Snapshots
    SLOT_RSH,                       // Retro Shell
    SLOT_KEY,                       // Auto-typing
    SLOT_SRV,                       // Remote server manager
    SLOT_DBG,                       // Debugging (Regression tester)
    SLOT_BTR,                       // Beam traps
    SLOT_ALA,                       // Alarms (set by the GUI)
    SLOT_INS,                       // Handles periodic calls to inspect()

    SLOT_COUNT
};
typedef SLOT EventSlot;

struct EventSlotEnum : util::Reflection<EventSlotEnum, EventSlot>
{
    static constexpr long minVal = 0;
    static constexpr long maxVal = SLOT_COUNT - 1;

    static const char *prefix() { return "SLOT"; }
    static const char *_key(long value)
    {
        switch (value) {

            case SLOT_REG:      return "REG";
            case SLOT_PIA:      return "PIA";
            case SLOT_SEC:      return "SEC";

            case SLOT_TER:      return "TER";

            case SLOT_SNP:      return "SNP";
            case SLOT_RSH:      return "RSH";
            case SLOT_KEY:      return "KEY";
            case SLOT_SRV:      return "SRV";
            case SLOT_DBG:      return "DBG";
            case SLOT_BTR:      return "BTR";
            case SLOT_ALA:      return "ALA";
            case SLOT_INS:      return "INS";

            case SLOT_COUNT:    return "???";
        }
        return "???";
    }
};

enum_i8(EventID)
{
    EVENT_NONE          = 0,

    //
    // Events in the primary event table
    //

    // REG slot
    REG_WRITE_TIA       = 1,
    REG_WRITE_PIA,
    REG_EVENT_COUNT,
    
    // CIA slots
    CIA_EXECUTE         = 1,
    CIA_WAKEUP,
    CIA_EVENT_COUNT,

    // SEC slot
    SEC_TRIGGER         = 1,
    SEC_EVENT_COUNT,

    //
    // Events in secondary event table
    //

    // SEC slot
    TER_TRIGGER         = 1,
    TER_EVENT_COUNT,

    //
    // Events in tertiary event table
    //

    // Expansion port
    EXP_REU_INITIATE    = 1,
    EXP_REU_PREPARE,
    EXP_REU_STASH,
    EXP_REU_FETCH,
    EXP_REU_SWAP,
    EXP_REU_VERIFY,
    EXP_REU_AUTOLOAD,
    EXP_REU_FINALIZE,
    EXP_EVENT_COUNT,

    // Disk change
    DCH_INSERT          = 1,
    DCH_EJECT,
    DCH_EVENT_COUNT,

    // Snapshots
    SNP_TAKE             = 1,
    SNP_EVENT_COUNT,

    // Retro shell
    RSH_WAKEUP          = 1,
    RSH_EVENT_COUNT,

    // Auto typing
    KEY_AUTO_TYPE       = 1,
    KEY_EVENT_COUNT,

    // Remote server manager
    SRV_LAUNCH_DAEMON   = 1,
    SRV_EVENT_COUNT,

    // Alarm event slot
    DBG_WATCHDOG        = 1,
    DBG_EVENT_COUNT,

    // Beamtrap event slot
    BTR_TRIGGER         = 1,
    BTR_EVENT_COUNT,
    
    // Alarm event slot
    ALA_TRIGGER         = 1,
    ALA_EVENT_COUNT,

    // Inspector slot
    INS_C64             = 1,
    INS_CPU,
    INS_MEM,
    INS_TIA,
    INS_PIA,
    INS_SID,
    INS_EVENTS,
    INS_EVENT_COUNT
};

typedef u32 RunLoopFlags;

namespace RL {

const u32 STOP              = (1 << 0);
const u32 WARP_ON           = (1 << 1);
const u32 WARP_OFF          = (1 << 2);
const u32 BREAKPOINT        = (1 << 3);
const u32 WATCHPOINT        = (1 << 4);
const u32 BEAMTRAP          = (1 << 5);
const u32 CPU_JAM           = (1 << 6);
const u32 STEP_CYCLE        = (1 << 7);
const u32 STEP_INSTRUCTION  = (1 << 8);
const u32 STEP_LINE         = (1 << 9);
const u32 STEP_FRAME        = (1 << 10);
const u32 SYNC_THREAD       = (1 << 11);
}


//
// Structures
//

typedef struct
{
    //! After a reset, the emulator runs in warp mode for this amout of seconds
    isize warpBoot;

    //! Warp mode
    WarpMode warpMode;

    //! Emulator speed in percent (100 is native speed)
    isize speedBoost;

    //! Vertical Synchronization
    bool vsync;

    //! Number of run-ahead frames (0 = run-ahead is disabled)
    isize runAhead;

    //! Enable auto-snapshots
    bool snapshots;

    //! Delay between two auto-snapshots in seconds
    isize snapshotDelay;

    //! Indicates whether snapshots should be stored in compressed form
    bool compressSnapshots;
}
AtariConfig;

typedef struct
{
    u32 crc32;
    u64 fnv64;

    const char *title;
    const char *subtitle;
    const char *revision;

    bool isCommodoreRom;
    bool isPatchedRom;
    bool isMega65Rom;
}
RomInfo;

typedef struct
{
    EventSlot slot;
    EventID eventId;
    const char *eventName;

    // Trigger cycle of the event
    Cycle trigger;
    Cycle triggerRel;

    // Trigger frame relative to the current frame
    long frameRel;

    // The trigger cycle translated to a beam position.
    long vpos;
    long hpos;
}
EventSlotInfo;

typedef struct
{
    Cycle cpuProgress;
    i64 frame;
    RunLoopFlags flags;

    // long vpos;
    // long hpos;

    // Events
    EventSlotInfo slotInfo[SLOT_COUNT];
}
AtariInfo;

}

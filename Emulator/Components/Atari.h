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

#include "AtariTypes.h"
#include "MsgQueue.h"
#include "Thread.h"

// Components
#include "Memory.h"
#include "TIA.h"
#include "PIA.h"
#include "CPU.h"

// Ports
#include "CartPort.h"
#include "AudioPort.h"
#include "VideoPort.h"
#include "ControlPort.h"

// Peripherals
#include "Monitor.h"

// Cartridges
#include "Cartridges.h"

// Media files
#include "Snapshot.h"
#include "CartFile.h"

// Misc
#include "Host.h"
#include "RegressionTester.h"
#include "RemoteManager.h"
#include "LogicAnalyzer.h"
#include "RetroShell.h"
#include "RshServer.h"

namespace tiara {

//
// Macros and constants
//

// Checks the category of an event slot
static constexpr bool isPrimarySlot(isize s) { return s <= SLOT_SEC; }
static constexpr bool isSecondarySlot(isize s) { return s > SLOT_SEC && s <= SLOT_TER; }
static constexpr bool isTertiarySlot(isize s) { return s > SLOT_TER; }

// Time stamp used for messages that never trigger
static constexpr Cycle NEVER = INT64_MAX;

// Inspection interval in seconds (interval between INS_xxx events)
static constexpr double inspectionInterval = 0.1;


class Atari final : public CoreComponent, public Inspectable<AtariInfo> {

    friend class Emulator;

    Descriptions descriptions = {
        {
            .type           = AtariClass,
            .name           = "Atari",
            .description    = "Atari 2600",
            .shell          = "atari"
        },
        {
            .type           = AtariClass,
            .name           = "Atari[run-ahead]",
            .description    = "Atari 2600",
            .shell          = ""
        }
    };

    Options options = {

        OPT_ATARI_WARP_MODE,
        OPT_ATARI_SPEED_BOOST,
        OPT_ATARI_VSYNC,
        OPT_ATARI_RUN_AHEAD,
        OPT_ATARI_FAST_PATHS,
        OPT_ATARI_SNAP_AUTO,
        OPT_ATARI_SNAP_DELAY,
        OPT_ATARI_SNAP_COMPRESS
    };
    
private:

    // The current configuration
    AtariConfig config = {};

    // Result of the latest inspection
    mutable EventSlotInfo slotInfo[SLOT_COUNT];


    //
    // Subcomponents
    //

public:

    // Host system information
    Host host = Host(*this);

    // Components
    Memory mem = Memory(*this);
    CPU cpu = CPU(MOS_6507, *this);
    PIA pia = PIA(*this);
    TIA tia = TIA(*this);

    // Ports
    CartPort cartPort = CartPort(*this);
    AudioPort audioPort = AudioPort(*this);
    VideoPort videoPort = VideoPort(*this);
    ControlPort port1 = ControlPort(*this, PORT_1);
    ControlPort port2 = ControlPort(*this, PORT_2);

    // Sliders (console switches)
    bool slider[5]{};

    // Peripherals
    Monitor monitor = Monitor(*this);
    
    // Gateway to the GUI
    MsgQueue msgQueue = MsgQueue();

    // Misc
    LogicAnalyzer logicAnalyzer = LogicAnalyzer(*this);
    RetroShell retroShell = RetroShell(*this);
    RemoteManager remoteManager = RemoteManager(*this);
    RegressionTester regressionTester = RegressionTester(*this);


    //
    // Event scheduler
    //

public:

    // Trigger cycle
    Cycle trigger[SLOT_COUNT] = { };

    // The event identifier
    EventID eventid[SLOT_COUNT] = { };

    // An optional data value
    i64 data[SLOT_COUNT] = { };

    // Next trigger cycle
    Cycle nextTrigger = NEVER;


    //
    // Emulator thread
    //

private:

    /* Run loop flags. This variable is checked at the end of each runloop
     * iteration. Most of the time, the variable is 0 which causes the runloop
     * to repeat. A value greater than 0 means that one or more runloop control
     * flags are set. These flags are flags processed and the loop either
     * repeats or terminates depending on the provided flags.
     */
    RunLoopFlags flags = 0;


    //
    // Storage
    //

private:

    typedef struct { Cycle trigger; i64 payload; } Alarm;
    std::vector<Alarm> alarms;


    //
    // Buses
    //

public:
    
    // Address bus
    u16 addrBus;

    // Data bus
    u8 dataBus;

    /// Read/write line (0 = write)
    bool rw;

    
    //
    // State
    //

public:

    // The total number of frames drawn since power up
    i64 frame = 0;

private:

    /* Indicates if headless mode is activated. If yes, the pixel drawing code
     * is skipped. Headless mode is used to accelerate warp mode and to speed
     * up the computation of some frames in run-ahead mode.
     */
    bool headless = false;

    /* Indicates whether the state has been altered by an external event.
     * This flag is used to determine whether the run-ahead instance needs to
     * be recreated.
     */
    // bool isDirty = false;
    
    // Duration of a CPU cycle in 1/10 nano seconds
    i64 durationOfOneCycle;

    // Target address for step mode
    std::optional<u16> stepTo = { };


    //
    // Static methods
    //

public:

    // Returns a version string for this release
    static string version();

    // Returns a build number string for this release
    static string build();

    // Returns a textual description for an event
    static const char *eventName(EventSlot slot, EventID id);

    // Converts a time span to an (approximate) cycle count
    static Cycle usec(isize delay) { return Cycle(delay * 1LL); }
    static Cycle msec(isize delay) { return Cycle(delay * 1000LL); }
    static Cycle sec(double delay) { return Cycle(delay * 1000000LL); }


    //
    // Methods
    //

public:

    Atari(class Emulator& ref, isize id);
    ~Atari();

private:

    void initialize();


    //
    // Operators
    //

public:

    Atari& operator= (const Atari& other) {

        CLONE(mem)
        CLONE(cpu)
        CLONE(pia)
        CLONE(tia)
        CLONE(audioPort)
        CLONE(videoPort)
        CLONE(port1)
        CLONE(port2)
        CLONE(monitor)
        CLONE(logicAnalyzer)
        CLONE(retroShell)
        CLONE(regressionTester)

        CLONE_ARRAY(trigger)
        CLONE_ARRAY(eventid)
        CLONE_ARRAY(data)
        CLONE(nextTrigger)
        CLONE(frame)

        CLONE(durationOfOneCycle)

        CLONE(config)

        return *this;
    }


    //
    // Methods from Serializable
    //

public:

    template <class T>
    void serialize(T& worker)
    {
        worker

        << trigger
        << eventid
        << data
        << nextTrigger
        << frame;

        if (isResetter(worker)) return;

        worker

        << durationOfOneCycle

        << config.warpMode
        << config.vsync
        << config.speedBoost
        << config.snapshots
        << config.snapshotDelay
        << config.runAhead;
    }

    void operator << (SerResetter &worker) override;
    void operator << (SerChecker &worker) override { serialize(worker); }
    void operator << (SerCounter &worker) override { serialize(worker); }
    void operator << (SerReader &worker) override { serialize(worker); }
    void operator << (SerWriter &worker) override { serialize(worker); }


    //
    // Methods from CoreComponent
    //

public:

    const Descriptions &getDescriptions() const override { return descriptions; }
    void prefix(isize level, const char *component, isize line) const override;

private:

    void _dump(Category category, std::ostream& os) const override;

    void _didReset(bool hard) override;
    void _powerOn() override;
    void _powerOff() override;
    void _run() override;
    void _pause() override;
    void _halt() override;
    void _warpOn() override;
    void _warpOff() override;
    void _trackOn() override;
    void _trackOff() override;


    //
    // Methods from Inspectable
    //

public:

    void cacheInfo(AtariInfo &result) const override;

    u64 getAutoInspectionMask() const;
    void setAutoInspectionMask(u64 mask);



    //
    // Methods from Configurable
    //

public:

    const AtariConfig &getConfig() const { return config; }
    const Options &getOptions() const override { return options; }
    
    i64 getOption(Option opt) const override;
    void checkOption(Option opt, i64 value) override;
    void setOption(Option opt, i64 value) override;
    
    // Exports the current configuration to a script file
    void exportConfig(const fs::path &path) const;
    void exportConfig(std::ostream& stream) const;


    //
    // Main API for configuring the emulator
    //

public:

    // Queries an option
    i64 get(Option opt, isize objid = 0) const throws;

    // Checks an option
    void check(Option opt, i64 value, const std::vector<isize> objids = { }) throws;

    // Sets an option
    void set(Option opt, i64 value, const std::vector<isize> objids = { }) throws;

    // Convenience wrappers
    void set(Option opt, const string &value, const std::vector<isize> objids = { }) throws;
    void set(const string &opt, const string &value, const std::vector<isize> objids = { }) throws;

public: // private

    // Returns the target component for an option
    Configurable *routeOption(Option opt, isize objid);
    const Configurable *routeOption(Option opt, isize objid) const;

    // Overrides a config option if the corresponding debug option is enabled
    i64 overrideOption(Option opt, i64 value) const;


    //
    // Analyzing
    //

public:

    // Return the current frame count
    i64 getFrame() const { return frame; }

    // Headless mode
    bool getHeadless() const { return headless; }
    void setHeadless(bool value) { headless = value; }

    // Returns the native refresh rate (differs between PAL and NTSC)
    double nativeRefreshRate() const;

    // Returns the native clock frequency (differs between PAL and NTSC)
    i64 nativeClockFrequency() const;

    // Returns the emulated refresh rate
    double refreshRate() const;

    // Returns the clock frequency based on the emulated refresh rate
    i64 clockFrequency() const;
    

    //
    // Handling sliders (console switches)
    //

    bool getSlider(Slider s) const;
    void setSlider(Slider s, bool val);
    void setSlider(Slider s, bool val, double delay);


    //
    // Emulating
    //

public:
    
    // Updates the clock frequency and all variables derived from it
    void updateClockFrequency();

private:

    // Called by the Emulator class in it's own update function
    void update(CmdQueue &queue);

    // Emulates a frame
    void computeFrame();
    template <bool fastPaths> void computeFrame();

    // void processFlags();

    // Fast-forward the run-ahead instance
    void fastForward(isize frames);


    //
    // Controlling the run loop
    //

public:

    /* Sets or clears a flag for controlling the run loop. The functions are
     * thread-safe and can be called safely from outside the emulator thread.
     */
    void setFlag(u32 flags);
    void clearFlag(u32 flags);

    // Convenience wrappers
    void signalBreakpoint() { setFlag(RL::BREAKPOINT); }
    void signalWatchpoint() { setFlag(RL::WATCHPOINT); }
    void signalJammed() { setFlag(RL::CPU_JAM); }
    void signalStop() { setFlag(RL::STOP); }

    // Executes a single clock cycle.
    // void executeOneCycle();

public:

    //
    // Handlers
    //

    // Start-of-frame handler
    void sofHandler();

    // End-of-frame handler
    void eofHandler();


    //
    // Managing commands and events
    //

public:

    // Processes a command from the command queue
    void processCommand(const Cmd &cmd);

    // Processes all pending events
    void processEvents(Cycle cycle);

    // Returns true iff the specified slot contains any event
    template<EventSlot s> bool hasEvent() const { return this->eventid[s] != (EventID)0; }

    // Returns true iff the specified slot contains a specific event
    template<EventSlot s> bool hasEvent(EventID id) const { return this->eventid[s] == id; }

    // Returns true iff the specified slot contains a pending event
    template<EventSlot s> bool isPending() const { return this->trigger[s] != NEVER; }

    // Returns true iff the specified slot contains a due event
    template<EventSlot s> bool isDue(Cycle cycle) const { return cycle >= this->trigger[s]; }

    // Schedules an event in certain ways
    template<EventSlot s> void scheduleAbs(Cycle cycle, EventID id)
    {
        this->trigger[s] = cycle;
        this->eventid[s] = id;

        if (cycle < nextTrigger) nextTrigger = cycle;

        if constexpr (isTertiarySlot(s)) {
            if (cycle < trigger[SLOT_TER]) trigger[SLOT_TER] = cycle;
        }
        if constexpr (isSecondarySlot(s) || isTertiarySlot(s)) {
            if (cycle < trigger[SLOT_SEC]) trigger[SLOT_SEC] = cycle;
        }
    }

    template<EventSlot s> void scheduleAbs(Cycle cycle, EventID id, i64 data)
    {
        scheduleAbs<s>(cycle, id);
        this->data[s] = data;
    }

    template<EventSlot s> void rescheduleAbs(Cycle cycle)
    {
        trigger[s] = cycle;
        if (cycle < nextTrigger) nextTrigger = cycle;

        if constexpr (isTertiarySlot(s)) {
            if (cycle < trigger[SLOT_TER]) trigger[SLOT_TER] = cycle;
        }
        if constexpr (isSecondarySlot(s) || isTertiarySlot(s)) {
            if (cycle < trigger[SLOT_SEC]) trigger[SLOT_SEC] = cycle;
        }
    }

    template<EventSlot s> void scheduleImm(EventID id)
    {
        scheduleAbs<s>(cpu.clock, id);
    }

    template<EventSlot s> void scheduleImm(EventID id, i64 data)
    {
        scheduleAbs<s>(cpu.clock, id);
        this->data[s] = data;
    }

    template<EventSlot s> void scheduleRel(Cycle cycle, EventID id) {
        scheduleAbs<s>(cpu.clock + cycle, id);
    }

    template<EventSlot s> void scheduleRel(Cycle cycle, EventID id, i64 data) {
        scheduleAbs<s>(cpu.clock + cycle, id, data);
    }

    template<EventSlot s> void rescheduleRel(Cycle cycle) {
        rescheduleAbs<s>(cpu.clock + cycle);
    }

    template<EventSlot s> void scheduleInc(Cycle cycle, EventID id)
    {
        scheduleAbs<s>(trigger[s] + cycle, id);
    }

    template<EventSlot s> void scheduleInc(Cycle cycle, EventID id, i64 data)
    {
        scheduleAbs<s>(trigger[s] + cycle, id);
        this->data[s] = data;
    }

    template<EventSlot s> void rescheduleInc(Cycle cycle)
    {
        rescheduleAbs<s>(trigger[s] + cycle);
    }

    template<EventSlot s> void cancel()
    {
        eventid[s] = (EventID)0;
        data[s] = 0;
        trigger[s] = NEVER;
    }

private:

    // Processes a register event
    void processREGEvent();

    // Services an inspection event
    void processINSEvent();


    //
    // Handling snapshots
    //

public:

    // Takes a snapshot
    MediaFile *takeSnapshot();

    // Loads the current state from a snapshot file
    void loadSnapshot(const MediaFile &snapshot) throws;

private:

    // Services a snapshot event
    void processSNPEvent(EventID id);

    // Schedules the next snapshot event
    void scheduleNextSNPEvent();

    // Services a console switch event
    void processSWIEvent(EventID id);


    //
    // Handling cartridges
    //

public:

    /*
    // Attaches a cartrige
    void attachCartridge(const fs::path &path, bool reset = true) throws;
    void attachCartridge(const MediaFile &file, bool reset = true);

    // Detaches the current cartridge
    void detachCartridge();

    // Changed the current cartridge type
    void setCartType(CartType newType);

    // Reverts to the predicted cartridge type
    void revertCartType();
    */


    //
    // Handling Roms
    //

private:

    // Returns a revision string if a Mega65 Rom is installed
    // const char *mega65BasicRev() const;
    // const char *mega65KernalRev() const;

public:

    // Installs a Rom
    [[deprecated]] void loadRom(const fs::path &path) throws;
    [[deprecated]] void loadRom(const MediaFile &file);

    // Erases an installed Rom or all Roms
    [[deprecated]] void deleteRoms();

    
    //
    // Flashing files
    //

    // Flashes a single file into memory
    void flash(const MediaFile &file) throws;


    //
    // Handling alarms
    //

public:

    /* Alarms are scheduled notifications set by the client (GUI). Once the
     * trigger cycle of an alarm has been reached, the emulator sends a
     * MSG_ALARM to the client.
     */
    void setAlarmAbs(Cycle trigger, i64 payload);
    void setAlarmRel(Cycle trigger, i64 payload);

    // Services an alarm event
    void processAlarmEvent();

private:

    // Schedules the next alarm event
    void scheduleNextAlarm();


    //
    // Miscellaneous
    //

public:

    // Translates the current clock cycle into pseudo-random number
    u32 random();

    // Translates seed into a pseudo-random number
    u32 random(u32 seed);
};

}

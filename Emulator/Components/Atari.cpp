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
#include "Emulator.h"
#include "Checksum.h"
#include "IOUtils.h"
#include <algorithm>
#include <queue>

namespace tiara {

string
Atari::version()
{
    string result;

    result = std::to_string(VER_MAJOR) + "." + std::to_string(VER_MINOR);
    if constexpr (VER_SUBMINOR > 0) result += "." + std::to_string(VER_SUBMINOR);
    if constexpr (VER_BETA > 0) result += 'b' + std::to_string(VER_BETA);

    return result;
}

string
Atari::build()
{
    string db = debugBuild ? " [DEBUG BUILD]" : "";

    return version() + db + " (" + __DATE__ + " " + __TIME__ + ")";
}

const char *
Atari::eventName(EventSlot slot, EventID id)
{
    assert_enum(EventSlot, slot);

    switch (slot) {

        case SLOT_PIA:

            switch (id) {
                case EVENT_NONE:    return "none";
                case CIA_EXECUTE:   return "CIA_EXECUTE";
                case CIA_WAKEUP:    return "CIA_WAKEUP";
                default:            return "*** INVALID ***";
            }
            break;

        case SLOT_REG:

            switch (id) {
                case EVENT_NONE:    return "none";
                case REG_WRITE_TIA: return "REG_WRITE_TIA";
                case REG_WRITE_PIA: return "REG_WRITE_PIA";
                default:            return "*** INVALID ***";
            }
            break;

        case SLOT_SEC:

            switch (id) {

                case EVENT_NONE:    return "none";
                case SEC_TRIGGER:   return "SEC_TRIGGER";
                default:            return "*** INVALID ***";
            }
            break;

        case SLOT_TER:

            switch (id) {

                case EVENT_NONE:    return "none";
                case TER_TRIGGER:   return "TER_TRIGGER";
                default:            return "*** INVALID ***";
            }
            break;

        case SLOT_EXP:

            switch (id) {

                case EVENT_NONE:        return "none";
                case EXP_REU_INITIATE:  return "EXP_REU_INITIATE";
                case EXP_REU_PREPARE:   return "EXP_REU_PREPARE";
                case EXP_REU_STASH:     return "EXP_REU_STASH";
                case EXP_REU_FETCH:     return "EXP_REU_FETCH";
                case EXP_REU_SWAP:      return "EXP_REU_SWAP";
                case EXP_REU_VERIFY:    return "EXP_REU_VERIFY";
                case EXP_REU_AUTOLOAD:  return "EXP_REU_AUTOLOAD";
                case EXP_REU_FINALIZE:  return "EXP_REU_FINALIZE";
                default:                return "*** INVALID ***";
            }
            break;

        case SLOT_SNP:

            switch (id) {

                case EVENT_NONE:        return "none";
                case SNP_TAKE:          return "SNP_TAKE";
                default:                return "*** INVALID ***";
            }
            break;

        case SLOT_RSH:

            switch (id) {

                case EVENT_NONE:        return "none";
                case RSH_WAKEUP:        return "RSH_WAKEUP";
                default:                return "*** INVALID ***";
            }
            break;

        case SLOT_SWI:

            switch (id) {

                case EVENT_NONE:    return "none";
                case SWI_ON:        return "SWI_ON";
                case SWI_OFF:       return "SWI_OFF";
                default:            return "*** INVALID ***";
            }
            break;

        case SLOT_SRV:

            switch (id) {

                case EVENT_NONE:        return "none";
                case SRV_LAUNCH_DAEMON: return "SRV_LAUNCH_DAEMON";
                default:                return "*** INVALID ***";
            }
            break;

        case SLOT_DBG:

            switch (id) {

                case EVENT_NONE:    return "none";
                case DBG_WATCHDOG:  return "DBG_WATCHDOG";
                default:            return "*** INVALID ***";
            }
            break;

        case SLOT_BTR:

            switch (id) {

                case EVENT_NONE:    return "none";
                case BTR_TRIGGER:   return "BTR_TRIGGER";
                default:            return "*** INVALID ***";
            }
            break;

        case SLOT_ALA:

            switch (id) {

                case EVENT_NONE:    return "none";
                case ALA_TRIGGER:   return "ALA_TRIGGER";
                default:            return "*** INVALID ***";
            }
            break;

        case SLOT_INS:

            switch (id) {

                case EVENT_NONE:    return "none";
                case INS_C64:       return "INS_C64";
                case INS_CPU:       return "INS_CPU";
                case INS_MEM:       return "INS_MEM";
                case INS_TIA:       return "INS_TIA";
                case INS_PIA:       return "INS_PIA";
                case INS_EVENTS:    return "INS_EVENTS";
                default:            return "*** INVALID ***";
            }
            break;

        default:
            fatalError;
    }
}

void
Atari::prefix(isize level, const char *component, isize line) const
{
    if (level) {

        if (objid == 1) fprintf(stderr, "[Run-ahead] ");

        if (level >= 3) {

            fprintf(stderr, "[%lld] (%3ld,%3ld) ", frame, tia.getY(), tia.getX());
        }
        if (level >= 4) {

            fprintf(stderr, "%04X ", cpu.getPC0());
        }
        if (level >= 5) {

            fprintf(stderr, "<%s%s> ", (cpu.irqLine ? "I" : "i"), (cpu.nmiLine ? "N" : "n"));
        }
        if (level >= 2) {

            fprintf(stderr, "%s:%ld ", component, line);
        }
    }
}

void
Atari::_didReset(bool hard)
{
    flags |= RL::SYNC_THREAD;

    // Inform the GUI
    msgQueue.put(MSG_RESET);
}

void
Atari::initialize()
{
    CoreComponent::initialize();
}

void
Atari::operator << (SerResetter &worker)
{
    auto insEvent = eventid[SLOT_INS];

    // Reset all items
    serialize(worker);

    // Initialize all event slots
    for (isize i = 0; i < SLOT_COUNT; i++) {

        trigger[i] = NEVER;
        eventid[i] = (EventID)0;
        data[i] = 0;
    }

    // Schedule initial events
    scheduleAbs<SLOT_PIA>(cpu.clock, CIA_EXECUTE);
    scheduleRel<SLOT_SRV>(Atari::sec(0.5), SRV_LAUNCH_DAEMON);
    if (insEvent) scheduleRel <SLOT_INS> (0, insEvent);
    scheduleNextSNPEvent();

    flags = 0;
}

double
Atari::nativeRefreshRate() const
{
    return tia.getTraits().fps;
}

i64
Atari::nativeClockFrequency() const
{
    return tia.getTraits().cpuFrequency;
}

double
Atari::refreshRate() const
{
    if (config.vsync) {

        return double(host.getOption(OPT_HOST_REFRESH_RATE));

    } else {

        auto boost = config.speedBoost ? config.speedBoost : 100;
        return nativeRefreshRate() * boost / 100.0;
    }
}

i64
Atari::clockFrequency() const
{
    auto boost = config.speedBoost ? config.speedBoost : 100;
    return nativeClockFrequency() * boost / 100;
}

void
Atari::updateClockFrequency()
{
    auto frequency = clockFrequency();
    durationOfOneCycle = 10000000000 / frequency;
}

bool
Atari::getSlider(Slider s) const
{
    assert_enum(Slider, s);
    return slider[s];
}

void
Atari::setSlider(Slider s, bool val)
{
    setSlider(s, val, 0.0);
}

void
Atari::setSlider(Slider s, bool val, double delay)
{
    assert_enum(Slider, s);

    slider[s] = val;
    pia.updatePB();

    if (delay != 0.0) {
        scheduleRel<SLOT_SWI>(sec(delay), val ? SWI_OFF : SWI_ON, s);
    }
}

void
Atari::exportConfig(const fs::path &path) const
{
    auto fs = std::ofstream(path, std::ofstream::binary);

    if (!fs.is_open()) {
        throw Error(TIARA_ERROR_FILE_CANT_WRITE);
    }

    exportConfig(fs);
}

void
Atari::exportConfig(std::ostream &stream) const
{
    stream << "# Tiara " << Atari::build() << "\n";
    stream << "\n";
    stream << "c64 power off\n";
    stream << "\n";
    CoreComponent::exportConfig(stream);
    stream << "c64 power on\n";
}

i64
Atari::get(Option opt, isize objid) const
{
    debug(CNF_DEBUG, "get(%s, %ld)\n", OptionEnum::key(opt), objid);

    auto target = routeOption(opt, objid);
    if (target == nullptr) throw Error(TIARA_ERROR_OPT_INV_ID);
    return target->getOption(opt);
}

void
Atari::check(Option opt, i64 value, const std::vector<isize> objids)
{
    value = overrideOption(opt, value);

    if (objids.empty()) {

        for (isize objid = 0;; objid++) {

            auto target = routeOption(opt, objid);
            if (target == nullptr) break;

            debug(CNF_DEBUG, "check(%s, %lld, %ld)\n", OptionEnum::key(opt), value, objid);
            target->checkOption(opt, value);
        }
    }
    for (auto &objid : objids) {

        debug(CNF_DEBUG, "check(%s, %lld, %ld)\n", OptionEnum::key(opt), value, objid);

        auto target = routeOption(opt, objid);
        if (target == nullptr) throw Error(TIARA_ERROR_OPT_INV_ID);

        target->checkOption(opt, value);
    }
}

void
Atari::set(Option opt, i64 value, const std::vector<isize> objids)
{
    if (!isInitialized()) initialize();

    value = overrideOption(opt, value);

    if (objids.empty()) {

        for (isize objid = 0;; objid++) {

            auto target = routeOption(opt, objid);
            if (target == nullptr) break;

            debug(CNF_DEBUG, "set(%s, %lld, %ld)\n", OptionEnum::key(opt), value, objid);
            target->setOption(opt, value);
        }
    }
    for (auto &objid : objids) {

        debug(CNF_DEBUG, "set(%s, %lld, %ld)\n", OptionEnum::key(opt), value, objid);

        auto target = routeOption(opt, objid);
        if (target == nullptr) throw Error(TIARA_ERROR_OPT_INV_ID);

        target->setOption(opt, value);
    }
}

void
Atari::set(Option opt, const string &value, const std::vector<isize> objids)
{
    set(opt, OptionParser::parse(opt, value), objids);
}

void
Atari::set(const string &opt, const string &value, const std::vector<isize> objids)
{
    set(Option(util::parseEnum<OptionEnum>(opt)), value, objids);
}

Configurable *
Atari::routeOption(Option opt, isize objid)
{
    return CoreComponent::routeOption(opt, objid);
}

const Configurable *
Atari::routeOption(Option opt, isize objid) const
{
    auto result = const_cast<Atari *>(this)->routeOption(opt, objid);
    return const_cast<const Configurable *>(result);
}

i64
Atari::overrideOption(Option opt, i64 value) const
{
    static std::map<Option,i64> overrides = OVERRIDES;

    if (overrides.find(opt) != overrides.end()) {

        msg("Overriding option: %s = %lld\n", OptionEnum::key(opt), value);
        return overrides[opt];
    }

    return value;
}

void
Atari::update(CmdQueue &queue)
{
    Cmd cmd;
    bool cmdConfig = false;

    while (queue.poll(cmd)) {

        debug(CMD_DEBUG, "Command: %s\n", CmdTypeEnum::key(cmd.type));

        switch (cmd.type) {

            case CMD_CONFIG:

                cmdConfig = true;
                emulator.set(cmd.config.option, cmd.config.value, { cmd.config.id });
                break;

            case CMD_CONFIG_ALL:

                cmdConfig = true;
                emulator.set(cmd.config.option, cmd.config.value, { });
                break;

            case CMD_SET_SLIDER:
            case CMD_ALARM_ABS:
            case CMD_ALARM_REL:
            case CMD_INSPECTION_TARGET:

                processCommand(cmd);
                break;

            case CMD_CPU_BRK:
            case CMD_CPU_NMI:
             
                cpu.processCommand(cmd);
                break;

            case CMD_MOUSE_MOVE_ABS:
            case CMD_MOUSE_MOVE_REL:

                switch (cmd.coord.port) {

                    case PORT_1: port1.processCommand(cmd); break;
                    case PORT_2: port2.processCommand(cmd); break;
                    default: fatalError;
                }
                break;

            case CMD_MOUSE_EVENT:
            case CMD_JOY_EVENT:

                switch (cmd.action.port) {

                    case PORT_1: port1.processCommand(cmd); break;
                    case PORT_2: port2.processCommand(cmd); break;
                    default: fatalError;
                }
                break;

            case CMD_RSH_EXECUTE:

                retroShell.exec();
                break;

            case CMD_FOCUS:

                cmd.value ? focus() : unfocus();
                break;

            default:
                fatal("Unhandled command: %s\n", CmdTypeEnum::key(cmd.type));
        }
    }

    // Inform the GUI about a changed machine configuration
    if (cmdConfig) { msgQueue.put(MSG_CONFIG); }

    // Inform the GUI about new RetroShell content
    if (retroShell.isDirty) { retroShell.isDirty = false; msgQueue.put(MSG_RSH_UPDATE); }
}

void
Atari::computeFrame()
{
    config.fastPaths ? computeFrame<true>() : computeFrame<false>();
}

template <bool fastPaths> void
Atari::computeFrame()
{
    Cycle cycle = cpu.clock;

    if (flags & RL::SYNC_THREAD) { sofHandler(); }

    while (1) {

        // Process all pending events
        if (nextTrigger <= cycle) processEvents(cycle);

        // Execute the CPU
        cycle = ++cpu.clock;
        cpu.execute<MOS_6507>();

        // Execute other components
        pia.execute<fastPaths>();
        tia.execute<fastPaths>();
        cartPort.cart->execute();

        // Process pending actions
        if (flags) {

            bool pause = false;

            if (flags & RL::BREAKPOINT) {

                msgQueue.put(MSG_BREAKPOINT_REACHED, CpuMsg {u16(cpu.debugger.breakpointPC)});
                pause = true;
            }

            if (flags & RL::WATCHPOINT) {

                msgQueue.put(MSG_WATCHPOINT_REACHED, CpuMsg {u16(cpu.debugger.watchpointPC)});
                pause = true;
            }

            if (flags & RL::BEAMTRAP) {

                msgQueue.put(MSG_BEAMTRAP_REACHED, 0);
                pause = true;
            }

            if (flags & RL::STOP) {

                pause = true;
            }

            if (flags & RL::CPU_JAM) {

                msgQueue.put(MSG_CPU_JAMMED);
                pause = true;
            }

            if (flags & RL::STEP_CYCLE) {

                msgQueue.put(MSG_STEP);
                pause = true;
            }

            if (flags & RL::STEP_INSTRUCTION) {

                if (cpu.inFetchPhase()) {

                    if (!stepTo.has_value() || stepTo == cpu.getPC0()) {

                        clearFlag(RL::STEP_INSTRUCTION);
                        msgQueue.put(MSG_STEP);
                        pause = true;
                    }
                }
            }

            if (flags & RL::STEP_LINE) {

                if (tia.getX() >= 226) {

                    clearFlag(RL::STEP_LINE);
                    msgQueue.put(MSG_STEP);
                    pause = true;
                }
            }

            if (flags & RL::SYNC_THREAD) {

                if (flags & RL::STEP_FRAME) {

                    clearFlag(RL::STEP_FRAME);
                    msgQueue.put(MSG_STEP);
                    pause = true;
                }
            }

            flags &= RL::STEP_INSTRUCTION | RL::STEP_LINE | RL::STEP_FRAME | RL::SYNC_THREAD;

            if (pause) {
                throw StateChangeException(STATE_PAUSED);
            }
            if (flags & RL::SYNC_THREAD) break;
        }
    }
}

void 
Atari::fastForward(isize frames)
{
    auto target = frame + frames;

    // Execute until the target frame has been reached
    while (frame < target) computeFrame();
}

u64
Atari::getAutoInspectionMask() const
{
    return data[SLOT_INS];
}

void
Atari::setAutoInspectionMask(u64 mask)
{
    if (mask) {

        data[SLOT_INS] = mask;
        processINSEvent();

    } else {

        data[SLOT_INS] = 0;
        cancel<SLOT_INS>();
    }
}

void Atari::sofHandler()
{
    flags &= ~RL::SYNC_THREAD;

    auto oldy = tia.getY();

    tia.sofHandler();
    pia.sofHandler();
    logicAnalyzer.sofHandler(oldy);
}

void
Atari::eofHandler()
{
    flags |= RL::SYNC_THREAD;

    frame++;

    tia.eofHandler();
    pia.eofHandler();
    audioPort.eofHandler();
    videoPort.eofHandler();
    logicAnalyzer.eofHandler();
}

void
Atari::processCommand(const Cmd &cmd)
{
    switch (cmd.type) {

        case CMD_SET_SLIDER:

            setSlider(cmd.slider.slider, cmd.slider.value, cmd.slider.delay);
            break;

        case CMD_ALARM_ABS:

            setAlarmAbs(cmd.alarm.cycle, cmd.alarm.value);
            break;

        case CMD_ALARM_REL:

            setAlarmRel(cmd.alarm.cycle, cmd.alarm.value);
            break;
            
        case CMD_INSPECTION_TARGET:

            setAutoInspectionMask(cmd.value);
            break;

        default:
            fatalError;
    }
}

void
Atari::processEvents(Cycle cycle)
{
    //
    // Check primary slots
    //

    if (isDue<SLOT_REG>(cycle)) {
        processREGEvent();
    }
    if (isDue<SLOT_PIA>(cycle)) {

    }

    if (isDue<SLOT_SEC>(cycle)) {

        //
        // Check secondary slots
        //

        if (isDue<SLOT_TER>(cycle)) {

            //
            // Check tertiary slots
            //
            if (isDue<SLOT_EXP>(cycle)) {
                // expansionport.processEvent(eventid[SLOT_EXP]);
            }
            if (isDue<SLOT_SNP>(cycle)) {
                processSNPEvent(eventid[SLOT_SNP]);
            }
            if (isDue<SLOT_RSH>(cycle)) {
                retroShell.serviceEvent();
            }
            if (isDue<SLOT_SWI>(cycle)) {
                processSWIEvent(eventid[SLOT_SWI]);
            }
            if (isDue<SLOT_SRV>(cycle)) {
                remoteManager.serviceServerEvent();
            }
            if (isDue<SLOT_DBG>(cycle)) {
                regressionTester.processEvent(eventid[SLOT_DBG]);
            }
            if (isDue<SLOT_BTR>(cycle)) {
                logicAnalyzer.beamtraps.processEvent();
            }
            if (isDue<SLOT_ALA>(cycle)) {
                processAlarmEvent();
            }
            if (isDue<SLOT_INS>(cycle)) {
                processINSEvent();
            }

            // Determine the next trigger cycle for all tertiary slots
            Cycle next = trigger[SLOT_TER + 1];
            for (isize i = SLOT_TER + 2; i < SLOT_COUNT; i++) {
                if (trigger[i] < next) next = trigger[i];
            }
            rescheduleAbs<SLOT_TER>(next);
        }

        // Determine the next trigger cycle for all secondary slots
        Cycle next = trigger[SLOT_SEC + 1];
        for (isize i = SLOT_SEC + 2; i <= SLOT_TER; i++) {
            if (trigger[i] < next) next = trigger[i];
        }
        rescheduleAbs<SLOT_SEC>(next);
    }

    // Determine the next trigger cycle for all primary slots
    Cycle next = trigger[0];
    for (isize i = 1; i <= SLOT_SEC; i++) {
        if (trigger[i] < next) next = trigger[i];
    }
    nextTrigger = next;
}

void
Atari::processREGEvent()
{
    auto hi = HI_BYTE(data[SLOT_REG]);
    auto lo = LO_BYTE(data[SLOT_REG]);
    
    switch (eventid[SLOT_REG]) {

        case REG_WRITE_TIA: tia.poke(TIARegister(hi), lo); break;
        case REG_WRITE_PIA: pia.pokeReg(u16(hi), lo); break;

        default:
            fatalError;
    }
    
    cancel<SLOT_REG>();
}

void
Atari::processINSEvent()
{
    u64 mask = data[SLOT_INS];

    // Analyze bit mask
    if (mask & 1LL << AtariClass)           { record(); }
    if (mask & 1LL << CPUClass)             { cpu.record(); }
    if (mask & 1LL << MemoryClass)          { mem.record(); }
    if (mask & 1LL << PIAClass)             { pia.record(); }
    if (mask & 1LL << TIAClass)             { tia.record(); }

    // Reschedule the event
    rescheduleRel<SLOT_INS>(Cycle(inspectionInterval * PAL::CPU_CYCLES_PER_SEC));
}

void
Atari::setFlag(u32 flag)
{
    SYNCHRONIZED

    flags |= flag;
}

void
Atari::clearFlag(u32 flag)
{
    SYNCHRONIZED

    flags &= ~flag;
}

MediaFile *
Atari::takeSnapshot()
{
    Snapshot *result;

    // Take the snapshot
    { SUSPENDED result = new Snapshot(*this); }

    // Compress the snapshot if requested
    if (config.compressSnapshots) result->compress();

    return result;
}

void
Atari::loadSnapshot(const MediaFile &file)
{
    try {

        const Snapshot &snap = dynamic_cast<const Snapshot &>(file);

        // Make a copy so we can modify the snapshot
        Snapshot snapshot(snap);

        // Uncompress the snapshot
        snapshot.uncompress();

        {   SUSPENDED

            try {

                // Restore the saved state
                load(snapshot.getSnapshotData());

                // Print some debug info if requested
                if (SNP_DEBUG) dump(Category::State);

            } catch (Error &error) {

                /* If we reach this point, the emulator has been put into an
                 * inconsistent state due to corrupted snapshot data. We cannot
                 * continue emulation, because it would likely crash the
                 * application. Because we cannot revert to the old state either,
                 * we perform a hard reset to eliminate the inconsistency.
                 */
                hardReset();
                throw error;
            }
        }

        // Inform the GUI
        // msgQueue.put(vic.pal() ? MSG_PAL : MSG_NTSC);
        msgQueue.put(MSG_SNAPSHOT_RESTORED);

    } catch (...) {

        throw Error(TIARA_ERROR_FILE_TYPE_MISMATCH);
    }
}

void
Atari::processSNPEvent(EventID eventId)
{
    // Check for the main instance (ignore the run-ahead instance)
    if (objid == 0) {

        // Take snapshot and hand it over to GUI
        msgQueue.put( Message { .type = MSG_SNAPSHOT_TAKEN, .snapshot = { new Snapshot(*this) } } );
    }

    // Schedule the next event
    scheduleNextSNPEvent();
}

void
Atari::processSWIEvent(EventID id)
{
    switch (id) {

        case SWI_ON:    setSlider(Slider(data[SLOT_SWI]), true); break;
        case SWI_OFF:   setSlider(Slider(data[SLOT_SWI]), false); break;

        default:
            fatalError;
    }
    
    cancel<SLOT_SWI>();
}

void
Atari::scheduleNextSNPEvent()
{
    auto snapshots = emulator.get(OPT_ATARI_SNAP_AUTO);
    auto delay = emulator.get(OPT_ATARI_SNAP_DELAY);

    if (snapshots) {
        scheduleRel<SLOT_SNP>(Atari::sec(double(delay)), SNP_TAKE);
    } else {
        cancel<SLOT_SNP>();
    }
}

/*
void
Atari::attachCartridge(const fs::path &path, bool reset) throws
{
    CartFile file(path);
    attachCartridge(file, reset);
}

void
Atari::attachCartridge(const MediaFile &file, bool reset)
{
    SUSPENDED

    try {

        const auto &romFile = dynamic_cast<const CartFile &>(file);
        auto newCartridge = Cartridge::makeWithFile(*this, romFile);
        cart = std::move(newCartridge);

        if (reset) hardReset();

    } catch (...) {

        throw Error(TIARA_ERROR_FILE_TYPE_MISMATCH);
    }
}

void
Atari::detachCartridge()
{
    SUSPENDED

    cart = std::make_unique<Cartridge>(*this);
}

void
Atari::setCartType(CartType newType)
{
    debug(CRT_DEBUG, "Setting cartridge type to %s\n", CartTypeEnum::key(newType));

    if (cart->traits.cartType != newType) {

        SUSPENDED

        // Create a new cartridge of the proper subclass
        auto newCart = Cartridge::makeWithType(*this, newType);

        // Preserve information from the existing cartridge
        newCart->traits = cart->traits;
        newCart->predictedCartType = cart->predictedCartType;

        // Set the new type
        newCart->traits.cartType = newType;

        // Replace the existing cartridge
        cart = std::move(newCart);

        printf("New cart type assigned\n");
    }
}

void
Atari::revertCartType()
{
    setCartType(cart->predictedCartType);
}
*/

void
Atari::loadRom(const fs::path &path)
{
    CartFile file(path);
    loadRom(file);
}

void
Atari::loadRom(const MediaFile &file)
{

}

void
Atari::flash(const MediaFile &file)
{
    {   SUSPENDED
        
        switch (file.type()) {
                
            case FILETYPE_CART:
                break;
                
            case FILETYPE_SNAPSHOT:
                loadSnapshot(dynamic_cast<const Snapshot &>(file));
                break;
                

            default:
                fatalError;
        }
    }
}

void
Atari::setAlarmAbs(Cycle trigger, i64 payload)
{
    {   SUSPENDED

        alarms.push_back(Alarm { trigger, payload });
        scheduleNextAlarm();
    }
}

void
Atari::setAlarmRel(Cycle trigger, i64 payload)
{
    {   SUSPENDED

        alarms.push_back(Alarm { cpu.clock + trigger, payload });
        scheduleNextAlarm();
    }
}

void
Atari::processAlarmEvent()
{
    for (auto it = alarms.begin(); it != alarms.end(); ) {

        if (it->trigger <= cpu.clock) {
            msgQueue.put(MSG_ALARM, it->payload);
            it = alarms.erase(it);
        } else {
            it++;
        }
    }
    scheduleNextAlarm();
}

void
Atari::scheduleNextAlarm()
{
    Cycle trigger = INT64_MAX;

    cancel<SLOT_ALA>();

    for(Alarm alarm : alarms) {

        if (alarm.trigger < trigger) {
            scheduleAbs<SLOT_ALA>(alarm.trigger, ALA_TRIGGER);
            trigger = alarm.trigger;
        }
    }
}

u32
Atari::random()
{
    return random(u32(cpu.clock));
}

u32
Atari::random(u32 seed)
{
    // Parameters for the Linear Congruential Generator (LCG)
    u64 a = 1664525;
    u64 c = 1013904223;
    u64 m = 1LL << 32;

    // Apply the LCG formula
    return u32((a * seed + c) % m);
}

}

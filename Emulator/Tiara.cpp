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
#include "Tiara.h"
#include "Emulator.h"

namespace tiara {

DefaultsAPI Tiara::defaults(&Emulator::defaults);

void 
API::suspend()
{
    emu->suspend();
}

void 
API::resume()
{
    emu->resume();
}

bool 
API::isUserThread() const
{
    return !emu->isEmulatorThread();
}

string
Tiara::version()
{
    return Atari::version();
}

string
Tiara::build()
{
    return Atari::build();
}

Tiara::Tiara() {

    emu = new Emulator();

    atari.emu = emu;
    atari.atari = &emu->main;

    mem.emu = emu;
    mem.mem = &emu->main.mem;

    cpu.emu = emu;
    cpu.cpu = &emu->main.cpu;
    cpu.breakpoints.emu = emu;
    cpu.breakpoints.guards = &emu->main.cpu.breakpoints;
    cpu.watchpoints.emu = emu;
    cpu.watchpoints.guards = &emu->main.cpu.watchpoints;

    pia.emu = emu;
    pia.pia = &emu->main.pia;

    tia.emu = emu;
    tia.tia = &emu->main.tia;

    audioPort.emu = emu;
    audioPort.audioPort = &emu->main.audioPort;

    videoPort.emu = emu;
    videoPort.videoPort = &emu->main.videoPort;

    logicAnalyzer.emu = emu;
    logicAnalyzer.logicAnalyzer = &emu->main.logicAnalyzer;
    logicAnalyzer.beamtraps.emu = emu;
    logicAnalyzer.beamtraps.guards = &emu->main.logicAnalyzer.beamtraps;

    controlPort1.emu = emu;
    controlPort1.controlPort = &emu->main.port1;
    controlPort1.joystick.emu = emu;
    controlPort1.joystick.joystick = &emu->main.port1.joystick;
    controlPort1.paddle.emu = emu;
    controlPort1.paddle.paddle = &emu->main.port1.paddle;

    controlPort2.emu = emu;
    controlPort2.controlPort = &emu->main.port2;
    controlPort2.joystick.emu = emu;
    controlPort2.joystick.joystick = &emu->main.port2.joystick;
    controlPort2.paddle.emu = emu;
    controlPort2.paddle.paddle = &emu->main.port2.paddle;

    cartridge.emu = emu;
    // cartridge.cartridge = &emu->main.expansionport;

    remoteManager.emu = emu;
    remoteManager.remoteManager = &emu->main.remoteManager;

    retroShell.emu = emu;
    retroShell.retroShell = &emu->main.retroShell;

    defaults.emu = emu;
    defaults.defaults = &emu->defaults;
}

Tiara::~Tiara()
{
    delete emu;
    emu = nullptr;
}

const EmulatorInfo &
Tiara::getInfo() const 
{
    return emu->getInfo();
}

const EmulatorInfo &
Tiara::getCachedInfo() const
{
    return emu->getCachedInfo();
}

const EmulatorStats &
Tiara::getStats() const 
{
    return emu->getStats();
}

bool
Tiara::isPoweredOn() const
{
    return emu->isPoweredOn();
}

bool
Tiara::isPoweredOff() const
{
    return emu->isPoweredOff();
}

bool
Tiara::isPaused() const
{
    return emu->isPaused();
}

bool
Tiara::isRunning() const
{
    return emu->isRunning();
}

bool
Tiara::isSuspended() const
{
    return emu->isSuspended();
}

bool
Tiara::isHalted() const
{
    return emu->isHalted();
}

bool
Tiara::isWarping() const
{
    return emu->isWarping();
}

bool
Tiara::isTracking() const
{
    return emu->isTracking();
}

void 
Tiara::isReady() const
{
    return emu->isReady();
}

void 
Tiara::powerOn() 
{
    emu->Thread::powerOn();
}

void 
Tiara::powerOff() 
{
    emu->Thread::powerOff();
}

void 
Tiara::run() 
{
    emu->run();
}

void 
Tiara::pause() 
{
    emu->pause();
}

void 
Tiara::halt() 
{
    emu->halt();
}

void 
Tiara::suspend() 
{
    emu->suspend();
}

void 
Tiara::resume() 
{
    emu->resume();
}

void 
Tiara::warpOn(isize source)
{
    emu->warpOn(source);
}

void 
Tiara::warpOff(isize source)
{
    emu->warpOff(source);
}

void 
Tiara::trackOn(isize source)
{
    emu->trackOn(source);
}

void 
Tiara::trackOff(isize source)
{
    emu->trackOff(source);
}

void
Tiara::stepCycle()
{
    emu->stepCycle();
}

void
Tiara::stepInto()
{
    emu->stepInto();
}

void
Tiara::stepOver()
{
    emu->stepOver();
}

void
Tiara::finishLine()
{
    emu->finishLine();
}

void
Tiara::finishFrame()
{
    emu->finishFrame();
}

void
Tiara::wakeUp()
{
    emu->wakeUp();
}

void
Tiara::launch(const void *listener, Callback *func)
{
    emu->launch(listener, func);
}

bool
Tiara::isLaunched() const
{
    return emu->isLaunched();
}

i64
Tiara::get(Option option) const
{
    return emu->get(option);
}

i64
Tiara::get(Option option, long id) const
{
    return emu->get(option, id);
}

void
Tiara::set(Option opt, i64 value) throws
{
    emu->check(opt, value);
    put(CMD_CONFIG_ALL, ConfigCmd { .option = opt, .value = value });
    emu->markAsDirty();
}

void
Tiara::set(Option opt, i64 value, long id)
{
    emu->check(opt, value, { id });
    put(CMD_CONFIG, ConfigCmd { .option = opt, .value = value, .id = id });
    emu->markAsDirty();
}

void
Tiara::exportConfig(const fs::path &path) const
{
    emu->main.exportConfig(path);
}

void
Tiara::exportConfig(std::ostream& stream) const
{
    emu->main.exportConfig(stream);
}

void
Tiara::put(const Cmd &cmd)
{
    emu->put(cmd);
}


//
// C64
//

void
AtariAPI::hardReset()
{
    emu->hardReset();
    emu->markAsDirty();
}

void
AtariAPI::softReset()
{
    emu->softReset();
    emu->markAsDirty();
}

u64
AtariAPI::getAutoInspectionMask() const
{
    return atari->getAutoInspectionMask();
}

void
AtariAPI::setAutoInspectionMask(u64 mask)
{
    atari->setAutoInspectionMask(mask);
}

const AtariInfo &
AtariAPI::getInfo() const
{
    return atari->getInfo();
}

const AtariInfo &
AtariAPI::getCachedInfo() const
{
    return atari->getCachedInfo();
}

CartTraits
AtariAPI::getCartTraits() const
{
    return atari->cartPort.cart->traits;
}

MediaFile *
AtariAPI::takeSnapshot()
{
    return atari->takeSnapshot();
}

void
AtariAPI::loadSnapshot(const MediaFile &snapshot)
{
    atari->loadSnapshot(snapshot);
    emu->markAsDirty();
}

void
AtariAPI::attachCart(const std::filesystem::path &path, bool reset)
{
    atari->cartPort.attachCartridge(path, reset);
    emu->markAsDirty();
}

void
AtariAPI::attachCart(const MediaFile &c, bool reset)
{
    atari->cartPort.attachCartridge(c, reset);
    emu->markAsDirty();
}

void
AtariAPI::detachCart()
{
    atari->cartPort.detachCartridge();
    emu->markAsDirty();
}

void
AtariAPI::revertCartType()
{
    atari->cartPort.revertCartType();
    emu->markAsDirty();
}

void
AtariAPI::flash(const MediaFile &file)
{
    atari->flash(file);
    emu->markAsDirty();
}


//
// Components (Guards)
//

isize
GuardsAPI::elements() const
{
    return guards->elements();
}

std::optional<GuardInfo>
GuardsAPI::guardNr(long nr) const
{
    return guards->guardNr(nr);
}

std::optional<GuardInfo>
GuardsAPI::guardAt(u32 target) const
{
    return guards->guardAt(target);
}

void
GuardsAPI::setAt(u32 target, isize ignores)
{
    guards->setAt(target, ignores);
}

void
GuardsAPI::moveTo(isize nr, u32 newTarget)
{
    guards->moveTo(nr, newTarget);
}

void
GuardsAPI::remove(isize nr)
{
    guards->remove(nr);
}

void
GuardsAPI::removeAt(u32 target)
{
    guards->removeAt(target);
}

void
GuardsAPI::removeAll()
{
    guards->removeAll();
}

void
GuardsAPI::enable(isize nr)
{
    guards->enable(nr);
}

void
GuardsAPI::enableAt(u32 target)
{
    guards->enableAt(target);
}

void
GuardsAPI::enableAll()
{
    guards->enableAll();
}

void
GuardsAPI::disable(isize nr)
{
    guards->disable(nr);
}

void
GuardsAPI::disableAt(u32 target)
{
    guards->disableAt(target);
}

void
GuardsAPI::disableAll()
{
    guards->disableAll();
}

void
GuardsAPI::toggle(isize nr)
{
    guards->toggle(nr);
}


//
// CPU
//

const CPUInfo &
CPUAPI::getInfo() const
{
    return cpu->getInfo();
}

const CPUInfo &
CPUAPI::getCachedInfo() const
{
    return cpu->getCachedInfo();
}

isize
CPUAPI::loggedInstructions() const
{
    return cpu->debugger.loggedInstructions();
}

void
CPUAPI::clearLog()
{
    return cpu->debugger.clearLog();
}

void
CPUAPI::setNumberFormat(DasmNumberFormat instrFormat, DasmNumberFormat dataFormat)
{
    return cpu->disassembler.setNumberFormat(instrFormat, dataFormat);
}

isize
CPUAPI::disassemble(char *dst, const char *fmt, u16 addr) const
{
    return cpu->disassembler.disass(dst, fmt, addr);
}

isize
CPUAPI::disassembleRecorded(char *dst, const char *fmt, isize nr) const
{
    return cpu->debugger.disassRecorded(dst, fmt, nr);
}

Guard *
CPUAPI::breakpointNr(long nr) const
{
    return cpu->debugger.breakpoints.guardNr(nr);
}

Guard *
CPUAPI::breakpointAt(u32 addr) const
{
    return cpu->debugger.breakpoints.guardAt(addr);
}

Guard *
CPUAPI::watchpointNr(long nr) const
{
    return cpu->debugger.watchpoints.guardNr(nr);
}

Guard *
CPUAPI::watchpointAt(u32 addr) const
{
    return cpu->debugger.watchpoints.guardAt(addr);
}


//
// Memory
//

const MemConfig &
MemoryAPI::getConfig() const
{
    return mem->getConfig();
}

const MemInfo &
MemoryAPI::getInfo() const
{
    return mem->getInfo();
}

const MemInfo &
MemoryAPI::getCachedInfo() const
{
    return mem->getCachedInfo();
}

u8
MemoryAPI::peek(u16 addr) const
{
    return mem->spy(addr);
}

void
MemoryAPI::poke(u16 addr, u8 val)
{
    mem->poke(addr, val);
}

string
MemoryAPI::memdump(u16 addr, isize num, bool hex, isize pads, MemoryType src) const
{
    return mem->memdump(addr, num, hex, pads, src);
}

string
MemoryAPI::txtdump(u16 addr, isize num, MemoryType src) const
{
    return mem->txtdump(addr, num, src);
}

void
MemoryAPI::drawHeatmap(u32 *buffer, isize width, isize height) const
{
    return mem->heatmap.draw(buffer, width, height);
}


//
// PIA
//

const PIAConfig &
PIAAPI::getConfig() const
{
    return pia->getConfig();
}

const PIAInfo &
PIAAPI::getInfo() const
{
    return pia->getInfo();
}

const PIAInfo &
PIAAPI::getCachedInfo() const
{
    return pia->getCachedInfo();
}

PIAStats
PIAAPI::getStats() const
{
    return pia->getStats();
}


//
// TIA
//

const TIATraits &
TIAAPI::getTraits() const
{
    return tia->getTraits();
}

const TIAConfig &
TIAAPI::getConfig() const
{
    return tia->getConfig();
}

const TIAInfo &
TIAAPI::getInfo() const
{
    return tia->getInfo();
}

const TIAInfo &
TIAAPI::getCachedInfo() const
{
    return tia->getCachedInfo();
}

u32
TIAAPI::getColor(isize nr) const
{
    return tia->monitor.getColor(nr);
}

u32
TIAAPI::getColor(isize nr, Palette palette) const
{
    return 0; // tia->getColor(nr, palette);
}

/*
void
TIAAPI::setColor(TIARegister reg, u8 r, u8 g, u8 b)
{
    tia->setColor(reg, r, g, b);
}
*/

void
TIAAPI::lockReg(TIARegister reg)
{
    emu->set(OPT_TIA_REG_LOCK, emu->get(OPT_TIA_REG_LOCK) | (1LL << reg));
}

void
TIAAPI::unlockReg(TIARegister reg)
{
    emu->set(OPT_TIA_REG_LOCK, emu->get(OPT_TIA_REG_LOCK) & ~(1LL << reg));
}

void
TIAAPI::toggleRegLock(TIARegister reg)
{
    emu->set(OPT_TIA_REG_LOCK, emu->get(OPT_TIA_REG_LOCK) ^ (1LL << reg));
}

void
TIAAPI::watchReg(TIARegister reg)
{
    emu->set(OPT_TIA_REG_WATCH, emu->get(OPT_TIA_REG_WATCH) | (1LL << reg));
}

void
TIAAPI::unwatchReg(TIARegister reg)
{
    emu->set(OPT_TIA_REG_WATCH, emu->get(OPT_TIA_REG_WATCH) & ~(1LL << reg));
}

void
TIAAPI::toggleRegWatch(TIARegister reg)
{
    emu->set(OPT_TIA_REG_WATCH, emu->get(OPT_TIA_REG_WATCH) ^ (1LL << reg));
}

//
// Audio port
//

AudioPortStats
AudioPortAPI::getStats() const
{
    return audioPort->getStats();
}

isize
AudioPortAPI::copyMono(float *buffer, isize n)
{
    return audioPort->copyMono(buffer, n);
}

isize
AudioPortAPI::copyStereo(float *left, float *right, isize n)
{
    return audioPort->copyStereo(left, right, n);
}

isize
AudioPortAPI::copyInterleaved(float *buffer, isize n)
{
    return audioPort->copyInterleaved(buffer, n);
}


//
// Video port
//

u32 *
VideoPortAPI::getTexture() const
{
    return emu->getTexture();
}

u32 *
VideoPortAPI::getDmaTexture() const
{
    return emu->getDmaTexture();
}


//
// Logic Analyzer
//

const LogicAnalyzerConfig &
LogicAnalyzerAPI::getConfig() const
{
    return logicAnalyzer->getConfig();
}

void
LogicAnalyzerAPI::setColor(isize channel, u32 abgr)
{
    logicAnalyzer->setColor(channel, abgr);
}

const RecordedSignals *
LogicAnalyzerAPI::getData(isize line) const
{
    return logicAnalyzer->getData(line);
}


//
// Joystick
//

const JoystickInfo &
JoystickAPI::getInfo() const
{
    return joystick->getInfo();
}

const JoystickInfo &
JoystickAPI::getCachedInfo() const
{
    return joystick->getCachedInfo();
}


//
// Paddle
//

const PaddleInfo &
PaddleAPI::getInfo() const
{
    return paddle->getInfo();
}

const PaddleInfo &
PaddleAPI::getCachedInfo() const
{
    return paddle->getCachedInfo();
}

bool
PaddleAPI::detectShakeXY(double x, double y)
{
    return paddle->detectShakeXY(x, y);
}

bool
PaddleAPI::detectShakeDxDy(double dx, double dy)
{
    return paddle->detectShakeDxDy(dx, dy);
}


//
// RemoteManager
//

const RemoteManagerInfo &
RemoteManagerAPI::getInfo() const
{
    return remoteManager->getInfo();
}

const RemoteManagerInfo &
RemoteManagerAPI::getCachedInfo() const
{
    return remoteManager->getCachedInfo();
}


//
// RetroShell
//

const char *
RetroShellAPI::text()
{
    return retroShell->text();
}

isize
RetroShellAPI::cursorRel()
{
    return retroShell->cursorRel();
}

void
RetroShellAPI::press(RetroShellKey key, bool shift)
{
    retroShell->press(key, shift);
}

void
RetroShellAPI::press(char c)
{
    retroShell->press(c);
}

void
RetroShellAPI::press(const string &s)
{
    retroShell->press(s);
}

void
RetroShellAPI::execScript(std::stringstream &ss)
{
    retroShell->asyncExecScript(ss);
}

void
RetroShellAPI::execScript(const std::ifstream &fs)
{
    retroShell->asyncExecScript(fs);
}

void
RetroShellAPI::execScript(const string &contents)
{
    retroShell->asyncExecScript(contents);
}

void 
RetroShellAPI::execScript(const MediaFile &file)
{
    retroShell->asyncExecScript(file);
}

void
RetroShellAPI::setStream(std::ostream &os)
{
    retroShell->setStream(os);
}


//
// Expansion port
//

/*
CartridgeTraits
ExpansionPortAPI::getCartridgeTraits() const
{
    return expansionPort->getCartridgeTraits();
}

const CartridgeInfo &
ExpansionPortAPI::getInfo() const
{
    return expansionPort->getInfo();
}

const CartridgeInfo &
ExpansionPortAPI::getCachedInfo() const
{
    return expansionPort->getCachedInfo();
}
*/


//
// Defaults
//

void
DefaultsAPI::load(const fs::path &path)
{
    defaults->load(path);
}

void
DefaultsAPI::load(std::ifstream &stream)
{
    defaults->load(stream);
}

void
DefaultsAPI::load(std::stringstream &stream)
{
    defaults->load(stream);
}

void
DefaultsAPI::save(const fs::path &path)
{
    defaults->save(path);
}

void
DefaultsAPI::save(std::ofstream &stream)
{
    defaults->save(stream);
}

void
DefaultsAPI::save(std::stringstream &stream)
{
    defaults->save(stream);
}

string
DefaultsAPI::getRaw(const string &key) const
{
    return defaults->getRaw(key);
}

i64
DefaultsAPI::get(const string &key) const
{
    return defaults->get(key);
}

i64
DefaultsAPI::get(Option option, isize nr) const
{
    return defaults->get(option, nr);
}

string
DefaultsAPI::getFallbackRaw(const string &key) const
{
    return defaults->getFallbackRaw(key);
}

i64
DefaultsAPI::getFallback(const string &key) const
{
    return defaults->getFallback(key);
}

i64
DefaultsAPI::getFallback(Option option, isize nr) const
{
    return defaults->getFallback(option, nr);
}

void
DefaultsAPI::set(const string &key, const string &value)
{
    defaults->set(key, value);
}

void
DefaultsAPI::set(Option opt, const string &value)
{
    defaults->set(opt, value);
}

void
DefaultsAPI::set(Option opt, const string &value, std::vector<isize> objids)
{
    defaults->set(opt, value, objids);
}

void
DefaultsAPI::set(Option opt, i64 value)
{
    defaults->set(opt, value);
}

void
DefaultsAPI::set(Option opt, i64 value, std::vector<isize> objids)
{
    defaults->set(opt, value, objids);
}

void
DefaultsAPI::setFallback(const string &key, const string &value)
{
    defaults->setFallback(key, value);
}

void
DefaultsAPI::setFallback(Option opt, const string &value)
{
    defaults->setFallback(opt, value);
}

void
DefaultsAPI::setFallback(Option opt, const string &value, std::vector<isize> objids)
{
    defaults->setFallback(opt, value, objids);
}

void
DefaultsAPI::setFallback(Option opt, i64 value)
{
    defaults->setFallback(opt, value);
}

void
DefaultsAPI::setFallback(Option opt, i64 value, std::vector<isize> objids)
{
    defaults->setFallback(opt, value, objids);
}

void
DefaultsAPI::remove()
{
    defaults->remove();
}

void
DefaultsAPI::remove(const string &key)
{
    defaults->remove(key);
}

void
DefaultsAPI::remove(Option option)
{
    defaults->remove(option);
}

void
DefaultsAPI::remove(Option option, std::vector <isize> objids)
{
    defaults->remove(option, objids);
}

}

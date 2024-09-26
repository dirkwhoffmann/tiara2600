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
    return C64::version();
}

string
Tiara::build()
{
    return C64::build();
}

Tiara::Tiara() {

    emu = new Emulator();

    c64.emu = emu;
    c64.c64 = &emu->main;

    mem.emu = emu;
    mem.mem = &emu->main.mem;

    cpu.emu = emu;
    cpu.cpu = &emu->main.cpu;

    cia1.emu = emu;
    cia1.cia = &emu->main.cia1;

    cia2.emu = emu;
    cia2.cia = &emu->main.cia2;

    vicii.emu = emu;
    vicii.vicii = &emu->main.vic;

    sid.emu = emu;
    sid.sidBridge = &emu->main.sidBridge;

    audioPort.emu = emu;
    audioPort.audioPort = &emu->main.audioPort;

    videoPort.emu = emu;
    videoPort.videoPort = &emu->main.videoPort;

    dmaDebugger.emu = emu;
    dmaDebugger.dmaDebugger = &emu->main.vic.dmaDebugger;

    controlPort1.emu = emu;
    controlPort1.controlPort = &emu->main.port1;
    controlPort1.mouse.emu = emu;
    controlPort1.mouse.mouse = &emu->main.port1.mouse;
    controlPort1.joystick.emu = emu;
    controlPort1.joystick.joystick = &emu->main.port1.joystick;
    controlPort1.paddle.emu = emu;
    controlPort1.paddle.paddle = &emu->main.port1.paddle;

    controlPort2.emu = emu;
    controlPort2.controlPort = &emu->main.port2;
    controlPort2.mouse.emu = emu;
    controlPort2.mouse.mouse = &emu->main.port2.mouse;
    controlPort2.joystick.emu = emu;
    controlPort2.joystick.joystick = &emu->main.port2.joystick;
    controlPort2.paddle.emu = emu;
    controlPort2.paddle.paddle = &emu->main.port2.paddle;

    userPort.emu = emu;
    userPort.userPort = &emu->main.userPort;
    userPort.rs232.emu = emu;
    userPort.rs232.rs232 = &emu->main.userPort.rs232;

    expansionPort.emu = emu;
    expansionPort.expansionPort = &emu->main.expansionport;

    serialPort.emu = emu;
    serialPort.serialPort = &emu->main.iec;

    drive8.emu = emu;
    drive8.drive = &emu->main.drive8;
    drive8.disk.drive = &emu->main.drive8;

    drive9.emu = emu;
    drive9.drive = &emu->main.drive9;
    drive9.disk.drive = &emu->main.drive9;

    recorder.emu = emu;
    recorder.recorder = &emu->main.recorder;

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
Tiara::set(C64Model model)
{
    emu->set(model);
    emu->markAsDirty();
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
C64API::hardReset()
{
    emu->hardReset();
    emu->markAsDirty();
}

void
C64API::softReset()
{
    emu->softReset();
    emu->markAsDirty();
}

u64
C64API::getAutoInspectionMask() const
{
    return c64->getAutoInspectionMask();
}

void
C64API::setAutoInspectionMask(u64 mask)
{
    c64->setAutoInspectionMask(mask);
}

const C64Info &
C64API::getInfo() const
{
    return c64->getInfo();
}

const C64Info &
C64API::getCachedInfo() const
{
    return c64->getCachedInfo();
}

RomTraits
C64API::getRomTraits(RomType type) const
{
    return c64->getRomTraits(type);
}

MediaFile *
C64API::takeSnapshot()
{
    return c64->takeSnapshot();
}

void
C64API::loadSnapshot(const MediaFile &snapshot)
{
    c64->loadSnapshot(snapshot);
    emu->markAsDirty();
}

void
C64API::loadRom(const fs::path &path)
{
    c64->loadRom(path);
    emu->markAsDirty();
}

void 
C64API::loadRom(const MediaFile &file)
{
    c64->loadRom(file);
    emu->markAsDirty();
}

void 
C64API::deleteRom(RomType type)
{
    c64->deleteRom(type);
    emu->markAsDirty();
}

void 
C64API::deleteRoms()
{
    c64->deleteRoms();
    emu->markAsDirty();
}

void
C64API::saveRom(RomType rom, const std::filesystem::path &path)
{
    c64->saveRom(rom, path);
    emu->markAsDirty();
}

void
C64API::installOpenRom(RomType type)
{
    c64->installOpenRom(type);
    emu->markAsDirty();
}

void
C64API::installOpenRoms()
{
    c64->installOpenRoms();
    emu->markAsDirty();
}

void
C64API::flash(const MediaFile &file)
{
    c64->flash(file);
    emu->markAsDirty();
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
// CIAs
//

const CIAConfig &
CIAAPI::getConfig() const
{
    return cia->getConfig();
}

const CIAInfo &
CIAAPI::getInfo() const
{
    return cia->getInfo();
}

const CIAInfo &
CIAAPI::getCachedInfo() const
{
    return cia->getCachedInfo();
}

CIAStats
CIAAPI::getStats() const
{
    return cia->getStats();
}


//
// VICII
//

const VICIITraits &
VICIIAPI::getTraits() const
{
    return vicii->getTraits();
}

const VICIIConfig &
VICIIAPI::getConfig() const
{
    return vicii->getConfig();
}

const VICIIInfo &
VICIIAPI::getInfo() const
{
    return vicii->getInfo();
}

const VICIIInfo &
VICIIAPI::getCachedInfo() const
{
    return vicii->getCachedInfo();
}

SpriteInfo
VICIIAPI::getSpriteInfo(isize nr) const
{
    return vicii->getSpriteInfo(nr);
}

u32
VICIIAPI::getColor(isize nr) const
{
    return vicii->getColor(nr);
}

u32
VICIIAPI::getColor(isize nr, Palette palette) const
{
    return vicii->getColor(nr, palette);
}


//
// SID
//

SIDInfo
SIDAPI::getInfo(isize nr) const
{
    assert(nr < 3);

    return sidBridge->sid[nr].getInfo();
}

SIDInfo
SIDAPI::getCachedInfo(isize nr) const
{
    assert(nr < 3);

    return sidBridge->sid[nr].getCachedInfo();
}

float
SIDAPI::draw(u32 *buffer, isize width, isize height,
                         float maxAmp, u32 color, isize sid) const
{
    return sidBridge->draw(buffer, width, height, maxAmp, color, sid);
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
// DMA Debugger
//

const DmaDebuggerConfig &
DmaDebuggerAPI::getConfig() const
{
    return dmaDebugger->getConfig();
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

//
// RS232
//

void
RS232API::operator<<(char c)
{
    *rs232 << c;
}

void 
RS232API::operator<<(const string &s)
{
    *rs232 << s;
}

std::u16string
RS232API::readIncoming()
{
    return rs232->readIncoming();
}

std::u16string 
RS232API::readOutgoing()
{
    return rs232->readOutgoing();
}

int
RS232API::readIncomingPrintableByte()
{
    return rs232->readIncomingPrintableByte();
}

int
RS232API::readOutgoingPrintableByte()
{
    return rs232->readOutgoingPrintableByte();
}


//
// Mouse
//

bool MouseAPI::detectShakeXY(double x, double y)
{
    return mouse->detectShakeXY(x, y);
}

bool MouseAPI::detectShakeDxDy(double dx, double dy)
{
    return mouse->detectShakeDxDy(dx, dy);
}


//
// Recorder
//

const RecorderConfig &
RecorderAPI::getConfig() const
{
    return recorder->getConfig();
}

const RecorderInfo &
RecorderAPI::getInfo() const
{
    return recorder->getInfo();
}

const RecorderInfo &
RecorderAPI::getCachedInfo() const
{
    return recorder->getCachedInfo();
}

const fs::path
RecorderAPI::getExecPath() const
{
    return FFmpeg::getExecPath();
}

void RecorderAPI::setExecPath(const std::filesystem::path &path)
{
    FFmpeg::setExecPath(path);
}

void
RecorderAPI::startRecording(isize x1, isize y1, isize x2, isize y2)
{
    recorder->startRecording(x1, y1, x2, y2);
}

void
RecorderAPI::stopRecording()
{
    recorder->stopRecording();
}

bool
RecorderAPI::exportAs(const std::filesystem::path &path)
{
    return recorder->exportAs(path);
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

CartridgeRomInfo
ExpansionPortAPI::getRomInfo(isize nr) const
{
    return expansionPort->getRomInfo(nr);
}

void
ExpansionPortAPI::attachCartridge(const std::filesystem::path &path, bool reset)
{
    expansionPort->attachCartridge(path, reset);
    emu->markAsDirty();
}

void
ExpansionPortAPI::attachCartridge(const MediaFile &c, bool reset)
{
    expansionPort->attachCartridge(c, reset);
    emu->markAsDirty();
}

void
ExpansionPortAPI::attachReu(isize capacity)
{
    expansionPort->attachReu(capacity);
    emu->markAsDirty();
}

void
ExpansionPortAPI::attachGeoRam(isize capacity)
{
    expansionPort->attachGeoRam(capacity);
    emu->markAsDirty();
}

void
ExpansionPortAPI::attachIsepicCartridge()
{
    expansionPort->attachIsepicCartridge();
    emu->markAsDirty();
}

void
ExpansionPortAPI::detachCartridge()
{
    expansionPort->detachCartridge();
    emu->markAsDirty();
}


//
// Disk
//

Disk *
DiskAPI::get()
{
    return drive->disk.get();
}


//
// Drive
//

const DriveConfig &
DriveAPI::getConfig() const
{
    return drive->getConfig();
}

const DriveInfo &
DriveAPI::getInfo() const
{
    return drive->getInfo();
}

const DriveInfo &
DriveAPI::getCachedInfo() const
{
    return drive->getCachedInfo();
}

void
DriveAPI::insertMedia(MediaFile &file, bool wp)
{
    drive->insertMediaFile(file, wp);
    emu->markAsDirty();
}


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

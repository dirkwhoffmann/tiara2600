// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

#import "config.h"
#import "EmulatorProxy.h"
#import "Tiara.h"

using namespace tiara;

//
// Exception wrapper
//

@implementation ExceptionWrapper

@synthesize errorCode;
@synthesize what;

- (instancetype)init {

    if (self = [super init]) {
        
        errorCode = VC64ERROR_OK;
        what = @"";
    }
    return self;
}

- (void)save:(const Error &)exception
{
    errorCode = ErrorCode(exception.data);
    what = @(exception.what());
}

@end


//
// Base Proxy
//

@implementation Proxy

- (instancetype) initWith:(void *)ref
{
    if (ref == nil) {
        return nil;
    }
    if (self = [super init]) {
        obj = ref;
    }
    return self;
}

@end


//
// Defaults
//

@implementation DefaultsProxy

- (DefaultsAPI *)props
{
    return (DefaultsAPI *)obj;
}

- (void)load:(NSURL *)url exception:(ExceptionWrapper *)ex
{
    try { return [self props]->load([url fileSystemRepresentation]); }
    catch (Error &error) { [ex save:error]; }
}

- (void)save:(NSURL *)url exception:(ExceptionWrapper *)ex
{
    try { return [self props]->save([url fileSystemRepresentation]); }
    catch (Error &error) { [ex save:error]; }
}

- (void)register:(NSString *)key value:(NSString *)value
{
    [self props]->setFallback(string([key UTF8String]), string([value UTF8String]));
}

- (NSString *)getString:(NSString *)key
{
    auto result = [self props]->getRaw([key UTF8String]);
    return @(result.c_str());
}

- (NSInteger)getInt:(NSString *)key
{
    return [self props]->get([key UTF8String]);
}

- (NSInteger)getOpt:(Option)option
{
    return [self props]->get(option);
}

- (NSInteger)getOpt:(Option)option nr:(NSInteger)nr
{
    return [self props]->get(option, nr);
}

- (void)setKey:(NSString *)key value:(NSString *)value
{
    [self props]->set(string([key UTF8String]), string([value UTF8String]));
}

- (void)setOpt:(Option)option value:(NSInteger)value
{
    [self props]->set(option, value);
}

- (void)setOpt:(Option)option nr:(NSInteger)nr value:(NSInteger)value
{
    [self props]->set(option, value, {nr});
}

- (void)removeAll
{
    [self props]->remove();
}

- (void)removeKey:(NSString *)key
{
    [self props]->remove(string([key UTF8String]));
}

- (void)remove:(Option)option
{
    [self props]->remove(option);
}

- (void)remove:(Option) option nr:(NSInteger)nr
{
    [self props]->remove(option, {nr});
}

@end


//
// Guards (Breakpoints, Watchpoints)
//

@implementation GuardsProxy

- (GuardsAPI *)guards
{
    return (GuardsAPI *)obj;
}

- (NSInteger)count
{
    return [self guards]->elements();
}

- (NSInteger)addr:(NSInteger)nr
{
    auto guard = [self guards]->guardNr(nr);
    return guard ? (*guard).addr : 0;
}

- (BOOL)isSet:(NSInteger)nr
{
    auto guard = [self guards]->guardNr(nr);
    return guard.has_value();
}

- (BOOL)isSetAt:(NSInteger)addr
{
    auto guard = [self guards]->guardAt(u32(addr));
    return guard.has_value();
}

- (void)setAt:(NSInteger)addr exception:(ExceptionWrapper *)ex
{
    try { [self guards]->setAt((u32)addr); }
    catch (Error &error) { [ex save:error]; }
}

- (void)remove:(NSInteger)nr exception:(ExceptionWrapper *)ex
{
    try { [self guards]->remove(nr); }
    catch (Error &error) { [ex save:error]; }
}

- (void)removeAt:(NSInteger)addr exception:(ExceptionWrapper *)ex
{
    try { [self guards]->removeAt((u32)addr); }
    catch (Error &error) { [ex save:error]; }
}

- (void)removeAll
{
    return [self guards]->removeAll();
}

- (void)replace:(NSInteger)nr addr:(NSInteger)addr exception:(ExceptionWrapper *)ex
{
    try { [self guards]->moveTo(nr, (u32)addr); }
    catch (Error &error) { [ex save:error]; }
}

- (BOOL)isEnabled:(NSInteger)nr
{
    auto guard = [self guards]->guardNr(nr);
    return guard ? (*guard).enabled : false;
}

- (BOOL)isEnabledAt:(NSInteger)addr
{
    auto guard = [self guards]->guardAt(u32(addr));
    return guard ? (*guard).enabled : false;
}

- (BOOL)isDisabled:(NSInteger)nr
{
    auto guard = [self guards]->guardNr(nr);
    return guard ? (*guard).enabled == false : false;
}

- (BOOL)isDisabledAt:(NSInteger)addr
{
    auto guard = [self guards]->guardAt(u32(addr));
    return guard ? (*guard).enabled == false : false;
}

- (void)enable:(NSInteger)nr exception:(ExceptionWrapper *)ex
{
    try { [self guards]->enable(nr); }
    catch (Error &error) { [ex save:error]; }
}

- (void)enableAt:(NSInteger)addr exception:(ExceptionWrapper *)ex
{
    try { [self guards]->enableAt((u32)addr); }
    catch (Error &error) { [ex save:error]; }
}

- (void)disable:(NSInteger)nr exception:(ExceptionWrapper *)ex
{
    try { [self guards]->disable(nr); }
    catch (Error &error) { [ex save:error]; }
}

- (void)disableAt:(NSInteger)addr exception:(ExceptionWrapper *)ex
{
    try { [self guards]->disableAt((u32)addr); }
    catch (Error &error) { [ex save:error]; }
}

@end


//
// CPU proxy
//

@implementation CPUProxy

@synthesize breakpoints;
@synthesize watchpoints;

- (instancetype)initWith:(void *)ref
{
    if (self = [super init]) {

        obj = ref;
        CPUAPI *cpu = (CPUAPI *)ref;
        breakpoints = [[GuardsProxy alloc] initWith:&cpu->breakpoints];
        watchpoints = [[GuardsProxy alloc] initWith:&cpu->watchpoints];
    }
    return self;
}

- (CPUAPI *)cpu
{
    return (CPUAPI *)obj;
}

- (CPUInfo)info
{
    return [self cpu]->getInfo();
}

- (CPUInfo)cachedInfo
{
    return [self cpu]->getCachedInfo();
}

- (NSInteger)loggedInstructions
{
    return [self cpu]->loggedInstructions();
}

- (void)clearLog
{
    [self cpu]->clearLog();
}

- (void)setHex
{
    DasmNumberFormat instrFormat = {

        .prefix = "",
        .radix = 16,
        .upperCase = true,
        .fill = '0',
        .plainZero = false
    };

    DasmNumberFormat dataFormat = {

        .prefix = "",
        .radix = 16,
        .upperCase = true,
        .fill = '0',
        .plainZero = false
    };

    [self cpu]->setNumberFormat(instrFormat, dataFormat);
}

- (void)setDec
{
    DasmNumberFormat instrFormat = {

        .prefix = "",
        .radix = 10,
        .upperCase = true,
        .fill = '\0',
        .plainZero = false
    };

    DasmNumberFormat dataFormat = {

        .prefix = "",
        .radix = 10,
        .upperCase = true,
        .fill = '0',
        .plainZero = false
    };

    [self cpu]->setNumberFormat(instrFormat, dataFormat);
}

- (NSString *)disassemble:(NSInteger)addr format:(NSString *)fmt length:(NSInteger *)len
{
    char result[128];

    auto length = [self cpu]->disassemble(result, [fmt UTF8String], u16(addr));
    *len = (NSInteger)length;
    return @(result);
}

- (NSString *)disassembleRecorded:(NSInteger)addr format:(NSString *)fmt length:(NSInteger *)len
{
    char result[128];

    auto length = [self cpu]->disassembleRecorded(result, [fmt UTF8String], u16(addr));
    *len = (NSInteger)length;
    return @(result);
}

- (GuardInfo) guardInfo:(Guard *)guard
{
    GuardInfo result;

    result.addr = guard ? guard->addr : 0;
    result.enabled = guard ? guard->enabled : 0;
    // result.hits = guard ? guard->hits : 0;
    result.ignore = guard ? guard->ignore : 0;

    return result;
}

@end


//
// Memory proxy
//

@implementation MemoryProxy

- (MemoryAPI *)mem
{
    return (MemoryAPI *)obj;
}

- (MemConfig)config
{
    return [self mem]->getConfig();
}

- (MemInfo)info
{
    return [self mem]->getInfo();
}

- (MemInfo)cachedInfo
{
    return [self mem]->getCachedInfo();
}

- (NSInteger)peek:(NSInteger)addr
{
    return [self mem]->peek(u16(addr));
}

- (void)poke:(NSInteger)addr value:(NSInteger)value
{
    [self mem]->poke(u16(addr), u8(value));
}

- (NSString *)memdump:(NSInteger)addr num:(NSInteger)num hex:(BOOL)hex src:(MemoryType)src
{
    return @([self mem]->memdump((u16)addr, num, hex, hex ? 2 : 1, src).c_str());
}

- (NSString *)txtdump:(NSInteger)addr num:(NSInteger)num src:(MemoryType)src
{
    return @([self mem]->txtdump((u16)addr, num, src).c_str());
}

- (void)drawHeatmap:(u32 *)buffer w:(NSInteger)w h:(NSInteger)h
{
    [self mem]->drawHeatmap(buffer, w, h);
}

@end


//
// PIA
//

@implementation PIAProxy

- (PIAAPI *)pia
{
    return (PIAAPI *)obj;
}

- (PIAConfig)config
{
    return [self pia]->getConfig();
}

- (PIAInfo)info
{
    return [self pia]->getInfo();
}

- (PIAInfo)cachedInfo
{
    return [self pia]->getCachedInfo();
}

- (PIAStats)stats
{
    return [self pia]->getStats();
}

@end


//
// TIA
//

@implementation TIAProxy

- (TIAAPI *)tia
{
    return (TIAAPI *)obj;
}

- (TIATraits)traits
{
    return [self tia]->getTraits();
}

- (TIAConfig)config
{
    return [self tia]->getConfig();
}

- (TIAInfo)info
{
    return [self tia]->getInfo();
}

- (TIAInfo)cachedInfo
{
    return [self tia]->getCachedInfo();
}

- (NSColor *)color:(NSInteger)nr
{
    assert (0 <= nr && nr < 128);

    u32 color = [self tia]->getColor(nr);
    u8 r = color & 0xFF;
    u8 g = (color >> 8) & 0xFF;
    u8 b = (color >> 16) & 0xFF;

    return [NSColor colorWithCalibratedRed:(float)r/255.0
                                     green:(float)g/255.0
                                      blue:(float)b/255.0
                                     alpha:1.0];
}

- (UInt32)rgbaColor:(NSInteger)nr palette:(Palette)palette
{
    assert (0 <= nr && nr < 16);
    return [self tia]->getColor((unsigned)nr, palette);
}

- (void)setColor:(TIARegister)reg color:(NSColor *)color
{
    auto r = u8(color.redComponent * 255.0);
    auto g = u8(color.greenComponent * 255.0);
    auto b = u8(color.blueComponent * 255.0);
    [self tia]->setColor(reg, r, g, b);
}

- (void)lockReg:(TIARegister)reg
{
    assert (0 <= reg && reg < 64);
    [self tia]->lockReg(reg);
}

- (void)unlockReg:(TIARegister)reg
{
    assert (0 <= reg && reg < 64);
    [self tia]->unlockReg(reg);
}

@end


//
// Logic Analyzer
//

@implementation LogicAnalyzerProxy

- (LogicAnalyzerAPI *)la
{
    return (LogicAnalyzerAPI *)obj;
}

- (LogicAnalyzerConfig)getConfig
{
    return [self la]->getConfig();
}

- (void)setColor:(NSInteger)channel color:(NSColor *)color
{
    auto r = NSInteger(color.redComponent * 255.0);
    auto g = NSInteger(color.greenComponent * 255.0);
    auto b = NSInteger(color.blueComponent * 255.0);
    auto abgr = (0xFF << 24) | (b << 16) | (g << 8) | (r << 0);

    [self la]->setColor(channel, u32(abgr));
}

- (const RecordedSignals *)getData:(NSInteger)line
{
    return [self la]->getData(line);
}

@end


//
// Audio port
//

@implementation AudioPortProxy

- (AudioPortAPI *)port
{
    return (AudioPortAPI *)obj;
}

- (AudioPortStats)stats
{
    return [self port]->getStats();
}

- (NSInteger)copyMono:(float *)target size:(NSInteger)n
{
    return [self port]->copyMono(target, n);
}

- (NSInteger)copyStereo:(float *)target1 buffer2:(float *)target2 size:(NSInteger)n
{
    return [self port]->copyStereo(target1, target2, n);
}

- (NSInteger)copyInterleaved:(float *)target size:(NSInteger)n
{
    return [self port]->copyInterleaved(target, n);
}

@end


//
// Video port
//

@implementation VideoPortProxy

- (VideoPortAPI *)port
{
    return (VideoPortAPI *)obj;
}

- (u32 *)texture
{
    return [self port]->getTexture();
}

@end


//
// Control port
//

@implementation ControlPortProxy

@synthesize paddle;
@synthesize joystick;

- (instancetype) initWith:(void *)ref
{
    if (self = [super initWith:ref]) {

        ControlPortAPI *port = (ControlPortAPI *)obj;
        joystick = [[JoystickProxy alloc] initWith:&port->joystick];
        paddle = [[PaddleProxy alloc] initWith:&port->paddle];
    }
    return self;
}

- (ControlPortAPI *)port
{
    return (ControlPortAPI *)obj;
}

@end


//
// Paddle proxy
//

@implementation PaddleProxy

- (PaddleAPI *)paddle
{
    return (PaddleAPI *)obj;
}

- (BOOL)detectShakeAbs:(NSPoint)pos
{
    return [self paddle]->detectShakeXY(pos.x, pos.y);
}

- (BOOL)detectShakeRel:(NSPoint)pos
{
    return [self paddle]->detectShakeDxDy(pos.x, pos.y);
}

@end

//
// Joystick proxy
//

@implementation JoystickProxy

- (JoystickAPI *)joystick
{
    return (JoystickAPI *)obj;
}

@end


//
// RemoteManager proxy
//

@implementation RemoteManagerProxy

- (RemoteManagerAPI *)manager
{
    return (RemoteManagerAPI *)obj;
}

+ (instancetype)make:(RemoteManagerAPI *)manager
{
    if (manager == nullptr) { return nil; }

    RemoteManagerProxy *proxy = [[self alloc] initWith: manager];
    return proxy;
}

- (RemoteManagerInfo)info
{
    return [self manager]->getInfo();
}

@end


//
// RetroShell proxy
//

@implementation RetroShellProxy

- (RetroShellAPI *)shell
{
    return (RetroShellAPI *)obj;
}

+ (instancetype)make:(RetroShellAPI *)shell
{
    if (shell == nullptr) { return nil; }
    
    RetroShellProxy *proxy = [[self alloc] initWith: shell];
    return proxy;
}

-(NSInteger)cursorRel
{
	return [self shell]->cursorRel();
}

-(NSString *)getText
{
	const char *str = [self shell]->text();
	return str ? @(str) : nullptr;
}

- (void)pressKey:(char)c
{
	[self shell]->press(c);
}

- (void)pressSpecialKey:(RetroShellKey)key
{
    [self shell]->press(key);
}

- (void)pressSpecialKey:(RetroShellKey)key shift:(BOOL)shift
{
    [self shell]->press(key, shift);
}

- (void)executeScript:(MediaFileProxy *)file
{
    [self shell]->execScript(*(MediaFile *)file->obj);
}

- (void)executeString:(NSString *)str
{
    [self shell]->execScript(std::string([str UTF8String]));
}

@end


//
// MediaFile
//

@implementation MediaFileProxy

- (MediaFile *)file
{
    return (MediaFile *)obj;
}

+ (FileType)typeOfUrl:(NSURL *)url
{
    return MediaFile::type([url fileSystemRepresentation]);
}

+ (instancetype)make:(void *)file
{
    return file ? [[self alloc] initWith:file] : nil;
}

+ (instancetype)makeWithFile:(NSString *)path
                   exception:(ExceptionWrapper *)ex
{
    try { return [self make: MediaFile::make([path fileSystemRepresentation])]; }
    catch (Error &error) { [ex save:error]; return nil; }
}

+ (instancetype)makeWithFile:(NSString *)path
                        type:(FileType)type
                   exception:(ExceptionWrapper *)ex
{
    try { return [self make: MediaFile::make([path fileSystemRepresentation], type)]; }
    catch (Error &error) { [ex save:error]; return nil; }
}

+ (instancetype)makeWithBuffer:(const void *)buf length:(NSInteger)len
                          type:(FileType)type
                     exception:(ExceptionWrapper *)ex
{
    try { return [self make: MediaFile::make((u8 *)buf, len, type)]; }
    catch (Error &error) { [ex save:error]; return nil; }
}

+ (instancetype)makeWithTiara:(EmulatorProxy *)proxy
{
    auto tiara = (Tiara *)proxy->obj;
    return [self make:tiara->atari.takeSnapshot()];
}

- (FileType)type
{
    return [self file]->type();
}

- (u64)fnv
{
    return [self file]->fnv64();
}

- (NSInteger)size
{
    return [self file]->getSize();
}

- (BOOL)compressed
{
    return [self file]->isCompressed();
}

- (void)writeToFile:(NSString *)path exception:(ExceptionWrapper *)ex
{
    try { [self file]->writeToFile(string([path fileSystemRepresentation])); }
    catch (Error &err) { [ex save:err]; }
}

- (NSImage *)previewImage
{
    // Return cached image (if any)
    if (preview) { return preview; }

    // Get dimensions and data
    auto size = [self file]->previewImageSize();
    auto data = (unsigned char *)[self file]->previewImageData();

    // Create preview image
    if (data) {

        NSBitmapImageRep *rep = [[NSBitmapImageRep alloc]
                                 initWithBitmapDataPlanes: &data
                                 pixelsWide:size.first
                                 pixelsHigh:size.second
                                 bitsPerSample:8
                                 samplesPerPixel:4
                                 hasAlpha:true
                                 isPlanar:false
                                 colorSpaceName:NSCalibratedRGBColorSpace
                                 bytesPerRow:4*size.first
                                 bitsPerPixel:32];

        preview = [[NSImage alloc] initWithSize:[rep size]];
        [preview addRepresentation:rep];

        // image.makeGlossy()
    }
    return preview;
}

- (time_t)timeStamp
{
    return [self file]->timestamp();
}

@end

//
// Constants
//

@implementation Constants

+ (NSInteger)texWidth { return Texture::width; }
+ (NSInteger)texHeight { return Texture::height; }

@end


//
// Atari proxy
//

@implementation AtariProxy

- (AtariAPI *)c64
{
    return (AtariAPI *)obj;
}

- (AtariInfo)info
{
    return [self c64]->getInfo();
}

- (AtariInfo)cachedInfo
{
    return [self c64]->getCachedInfo();
}

- (NSInteger)autoInspectionMask
{
    return (NSInteger)[self c64]->getAutoInspectionMask();
}

- (void)setAutoInspectionMask:(NSInteger)mask
{
    return [self c64]->setAutoInspectionMask(u64(mask));
}

- (EventSlotInfo)cachedSlotInfo:(NSInteger)slot
{
    // return [self c64]->getSlotInfo(slot);
    return [self c64]->getCachedInfo().slotInfo[slot];
}

- (CartTraits)romTraits
{
    return [self c64]->getCartTraits();
}

- (void)hardReset
{
    [self c64]->hardReset();
}

- (void)softReset
{
    [self c64]->softReset();
}

- (MediaFileProxy *)takeSnapshot
{
    MediaFile *snapshot = [self c64]->takeSnapshot();
    return [MediaFileProxy make:snapshot];
}

@end

//
// Emulator
//

@implementation EmulatorProxy

@synthesize audioPort;
@synthesize atari;
@synthesize beamtraps;
@synthesize pia;
@synthesize cpu;
@synthesize logicAnalyzer;
@synthesize mem;
@synthesize port1;
@synthesize port2;
@synthesize remoteManager;
@synthesize retroShell;
@synthesize sid;
@synthesize tia;
@synthesize videoPort;

- (instancetype) init
{
    if (!(self = [super init])) return self;
    
    // Create the emulator instance
    Tiara *emu = new Tiara();
    obj = emu;

    // Create sub proxys
    audioPort = [[AudioPortProxy alloc] initWith:&emu->audioPort];
    atari = [[AtariProxy alloc] initWith:&emu->atari];
    pia = [[PIAProxy alloc] initWith:&emu->pia];
    cpu = [[CPUProxy alloc] initWith:&emu->cpu];
    logicAnalyzer = [[LogicAnalyzerProxy alloc] initWith:&emu->logicAnalyzer];
    beamtraps = [[GuardsProxy alloc] initWith:&emu->logicAnalyzer.beamtraps];
    mem = [[MemoryProxy alloc] initWith:&emu->mem];
    port1 = [[ControlPortProxy alloc] initWith:&emu->controlPort1];
    port2 = [[ControlPortProxy alloc] initWith:&emu->controlPort2];
    remoteManager = [[RemoteManagerProxy alloc] initWith:&emu->remoteManager];
    retroShell = [[RetroShellProxy alloc] initWith:&emu->retroShell];
    tia = [[TIAProxy alloc] initWith:&emu->tia];
    videoPort = [[VideoPortProxy alloc] initWith:&emu->videoPort];

    return self;
}

- (Tiara *)emu
{
    return (Tiara *)obj;
}

+ (DefaultsProxy *) defaults
{
    return [[DefaultsProxy alloc] initWith:(void *)&Tiara::defaults];
}

- (void)dealloc
{

}

- (void)kill
{
    assert([self emu] != NULL);
    delete [self emu];
    obj = NULL;
}

+ (NSString *)build
{
    return @(Tiara::build().c_str());
}

+ (NSString *)version
{
    return @(Tiara::version().c_str());
}

- (BOOL)releaseBuild
{
    return releaseBuild;
}

- (BOOL)trackMode
{
    return [self emu]->isTracking();
}

- (void)launch:(const void *)listener function:(Callback *)func
{
    [self emu]->launch(listener, func);
}

- (void)isReady:(ExceptionWrapper *)ex
{
    try { [self emu]->isReady(); }
    catch (Error &error) { [ex save:error]; }
}

- (void)powerOn:(ExceptionWrapper *)ex
{
    try { [self emu]->powerOn(); }
    catch (Error &error) { [ex save:error]; }
}

- (void)powerOff
{
    [self emu]->powerOff();
}

- (EmulatorInfo)info
{
    return [self emu]->getInfo();
}

- (EmulatorInfo)cachedInfo
{
    return [self emu]->getCachedInfo();
}

- (EmulatorStats)stats
{
    return [self emu]->getStats();
}

- (BOOL)poweredOn
{
    return [self emu]->isPoweredOn();
}

- (BOOL)poweredOff
{
    return [self emu]->isPoweredOff();
}

- (BOOL)paused
{
    return [self emu]->isPaused();
}

- (BOOL)running
{
    return [self emu]->isRunning();
}

- (BOOL)suspended
{
    return [self emu]->isSuspended();
}

- (BOOL)halted
{
    return [self emu]->isHalted();
}

- (BOOL)warping
{
    return [self emu]->isWarping();
}

- (BOOL)tracking
{
    return [self emu]->isTracking();
}

- (void)run:(ExceptionWrapper *)e
{
    [self emu]->run();
}

- (void)pause
{
    [self emu]->pause();
}

- (void)halt
{
    [self emu]->halt();
}

- (void)suspend
{
    [self emu]->suspend();
}

- (void)resume
{
    [self emu]->resume();
}

- (void)warpOn
{
    [self emu]->warpOn();
}

- (void)warpOn:(NSInteger)source
{
    [self emu]->warpOn(source);
}

- (void)warpOff
{
    [self emu]->warpOff();
}

- (void)warpOff:(NSInteger)source
{
    [self emu]->warpOff(source);
}

- (void)trackOn
{
    [self emu]->trackOn();
}

- (void)trackOn:(NSInteger)source
{
    [self emu]->trackOn(source);
}

- (void)trackOff
{
    [self emu]->trackOff();
}

- (void)trackOff:(NSInteger)source
{
    [self emu]->trackOff(source);
}

- (NSInteger)get:(Option)opt
{
    return [self emu]->get(opt);
}

- (NSInteger)get:(Option)opt id:(NSInteger)id
{
    return [self emu]->get(opt, id);
}

- (NSInteger)get:(Option)opt drive:(NSInteger)id
{
    return [self emu]->get(opt, (long)id);
}

- (BOOL)set:(Option)opt value:(NSInteger)val
{
    try {
        [self emu]->set(opt, val);
        return true;
    } catch (Error &exception) {
        return false;
    }
}

- (BOOL)set:(Option)opt enable:(BOOL)val
{
    try {
        [self emu]->set(opt, val ? 1 : 0);
        return true;
    } catch (Error &exception) {
        return false;
    }
}

- (BOOL)set:(Option)opt id:(NSInteger)id value:(NSInteger)val
{
    try {
        [self emu]->set(opt, val, id);
        return true;
    } catch (Error &exception) {
        return false;
    }
}

- (BOOL)set:(Option)opt id:(NSInteger)id enable:(BOOL)val
{
    try {
        [self emu]->set(opt, val ? 1 : 0, id);
        return true;
    } catch (Error &exception) {
        return false;
    }
}

- (BOOL)set:(Option)opt drive:(NSInteger)id value:(NSInteger)val
{
    try {
        [self emu]->set(opt, val, (long)id);
        return true;
    } catch (Error &exception) {
        return false;
    }
}

- (BOOL)set:(Option)opt drive:(NSInteger)id enable:(BOOL)val
{
    try {
        [self emu]->set(opt, val ? 1 : 0, (long)id);
        return true;
    } catch (Error &exception) {
        return false;
    }
}

- (void)exportConfig:(NSURL *)url exception:(ExceptionWrapper *)ex
{
    try { [self emu]->exportConfig([url fileSystemRepresentation]); }
    catch (Error &error) { [ex save:error]; }
}

- (void)wakeUp
{
    [self emu]->wakeUp();
}

- (void)stepCycle
{
    [self emu]->stepCycle();
}

- (void)stepInto
{
    [self emu]->stepInto();
}

- (void)stepOver
{
    [self emu]->stepOver();
}

- (void)finishLine
{
    [self emu]->finishLine();
}

- (void)finishFrame
{
    [self emu]->finishFrame();
}

- (BOOL) isRom:(NSURL *)url
{
    auto fileType = MediaFile::type([url fileSystemRepresentation]);
    return fileType == FILETYPE_CART;
}

- (void) attachCart:(NSURL *)url reset:(BOOL)reset exception:(ExceptionWrapper *)e
{
    try { [self emu]->atari.attachCart(string([url fileSystemRepresentation]), reset); }
    catch (Error &error) { [e save:error]; }
}

- (void) attachCart:(MediaFileProxy *)proxy reset:(BOOL)reset
{
    [self emu]->atari.attachCart(*(MediaFile *)proxy->obj, reset);
}

- (void)detachCart
{
    [self emu]->atari.detachCart();
}

- (void)revertCartType
{
    [self emu]->atari.revertCartType();
}

- (void)flash:(MediaFileProxy *)proxy exception:(ExceptionWrapper *)ex
{
    try { [self emu]->atari.flash(*(MediaFile *)proxy->obj); }
    catch (Error &error) { [ex save:error]; }
}

- (void)put:(CmdType)type
{
    [self emu]->put(type, 0);
}

- (void)put:(CmdType)type value:(NSInteger)value
{
    [self emu]->put(type, value);
}

- (void)put:(CmdType)type value:(NSInteger)value value2:(NSInteger)value2
{
    [self emu]->put(type, value, value2);
}

- (void)put:(CmdType)type slider:(SliderCmd)cmd
{
    [self emu]->put(type, cmd);
}

- (void)put:(CmdType)type key:(KeyCmd)cmd
{
    [self emu]->put(type, cmd);
}

- (void)put:(CmdType)type coord:(CoordCmd)cmd
{
    [self emu]->put(type, cmd);
}

- (void)put:(CmdType)type action:(GamePadCmd)cmd
{
    [self emu]->put(type, cmd);
}

@end

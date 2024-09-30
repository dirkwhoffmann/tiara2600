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
// SubComponentProxy proxy
//

@implementation SubComponentProxy

- (instancetype) initWith:(void *)ref emu:(Tiara *)emuref
{
    if (ref == nil || emuref == nil) {
        return nil;
    }
    if (self = [super init]) {
        obj = ref;
        emu = emuref;
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
// CPU proxy
//

@implementation CPUProxy

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
    result.hits = guard ? guard->hits : 0;
    result.ignore = guard ? guard->ignore : 0;

    return result;
}

- (BOOL) hasBreakpointWithNr:(NSInteger)nr
{
    return [self cpu]->breakpointNr(nr) != nullptr;
}

- (GuardInfo) breakpointWithNr:(NSInteger)nr
{
    return [self guardInfo:[self cpu]->breakpointNr(nr)];
}

- (BOOL) hasBreakpointAtAddr:(NSInteger)addr
{
    return [self cpu]->breakpointAt(u32(addr)) != nullptr;
}

- (GuardInfo) breakpointAtAddr:(NSInteger)addr
{
    return [self guardInfo:[self cpu]->breakpointAt(u32(addr))];
}

- (BOOL) hasWatchpointWithNr:(NSInteger)nr
{
    return [self cpu]->watchpointNr(nr) != nullptr;
}

- (GuardInfo) watchpointWithNr:(NSInteger)nr
{
    return [self guardInfo:[self cpu]->watchpointNr(nr)];
}

- (BOOL) hasWatchpointAtAddr:(NSInteger)addr
{
    return [self cpu]->watchpointAt(u32(addr)) != nullptr;
}
- (GuardInfo) watchpointAtAddr:(NSInteger)addr
{
    return [self guardInfo:[self cpu]->watchpointAt(u32(addr))];
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
// RIOT
//

@implementation RIOTProxy

- (RIOTAPI *)riot
{
    return (RIOTAPI *)obj;
}

- (RIOTConfig)config
{
    return [self riot]->getConfig();
}

- (RIOTInfo)info
{
    return [self riot]->getInfo();
}

- (RIOTInfo)cachedInfo
{
    return [self riot]->getCachedInfo();
}

- (RIOTStats)stats
{
    return [self riot]->getStats();
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
    assert (0 <= nr && nr < 16);

    u32 color = [self tia]->getColor((unsigned)nr);
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

@end


//
// Logic Analyzer
//

@implementation LogicAnalyzerProxy

- (LogicAnalyzerAPI *)debugger
{
    return (LogicAnalyzerAPI *)obj;
}

- (LogicAnalyzerConfig)getConfig
{
    return [self debugger]->getConfig();
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

- (instancetype) initWith:(void *)ref emu:(Tiara *)emuref
{
    if (self = [super initWith:ref emu:emuref]) {

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
// C64 proxy
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

- (RomTraits)romTraits
{
    return [self c64]->getRomTraits();
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
@synthesize riot;
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
    audioPort = [[AudioPortProxy alloc] initWith:&emu->audioPort emu:emu];
    atari = [[AtariProxy alloc] initWith:&emu->atari emu:emu];
    riot = [[RIOTProxy alloc] initWith:&emu->riot emu:emu];
    cpu = [[CPUProxy alloc] initWith:&emu->cpu emu:emu];
    logicAnalyzer = [[LogicAnalyzerProxy alloc] initWith:&emu->logicAnalyzer];
    mem = [[MemoryProxy alloc] initWith:&emu->mem emu:emu];
    port1 = [[ControlPortProxy alloc] initWith:&emu->controlPort1 emu:emu];
    port2 = [[ControlPortProxy alloc] initWith:&emu->controlPort2 emu:emu];
    remoteManager = [[RemoteManagerProxy alloc] initWith:&emu->remoteManager emu:emu];
    retroShell = [[RetroShellProxy alloc] initWith:&emu->retroShell emu:emu];
    tia = [[TIAProxy alloc] initWith:&emu->tia emu:emu];
    videoPort = [[VideoPortProxy alloc] initWith:&emu->videoPort emu:emu];

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

- (void)stepInto
{
    [self emu]->stepInto();
}

- (void)stepOver
{
    [self emu]->stepOver();
}

- (BOOL) isRom:(NSURL *)url
{
    auto fileType = MediaFile::type([url fileSystemRepresentation]);
    return fileType == FILETYPE_CART;
}

- (void) loadRom:(NSURL *)url exception:(ExceptionWrapper *)e
{
    try { [self emu]->atari.attachCartridge(string([url fileSystemRepresentation])); }
    catch (Error &error) { [e save:error]; }
}

- (void) loadRom:(MediaFileProxy *)proxy
{
    [self emu]->atari.attachCartridge(*(MediaFile *)proxy->obj);
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

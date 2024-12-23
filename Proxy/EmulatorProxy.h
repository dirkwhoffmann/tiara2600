// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

#import "config.h"
#import "TiaraTypes.h"
#import <Cocoa/Cocoa.h>
#import <MetalKit/MetalKit.h>

using namespace tiara;

@class AudioPortProxy;
@class EmulatorProxy;
@class AtariProxy;
@class PIAProxy;
@class Constants;
@class ControlPortProxy;
@class CPUProxy;
@class DefaultsProxy;
@class FileSystemProxy;
@class GuardsProxy;
@class JoystickProxy;
@class LogicAnalyzerProxy;
@class MediaFileProxy;
@class MemoryProxy;
@class PaddleProxy;
@class MyController;
@class RemoteManagerProxy;
@class RetroShellProxy;
@class TIAProxy;
@class VideoPortProxy;

//
// Exception wrapper
//

@interface ExceptionWrapper : NSObject {
    
    ErrorCode errorCode;
    NSString *what;
}

@property ErrorCode errorCode;
@property NSString *what;

@end

//
// Base proxies
//

@interface Proxy : NSObject {
    
    // Reference to the wrapped C++ instance
    @public void *obj;
}

- (instancetype) initWith:(void *)ref;

@end

//
// Constants
//

@interface Constants : NSObject {

}

@property (class, readonly) NSInteger texWidth;
@property (class, readonly) NSInteger texHeight;

@end

//
// Emulator
//

@interface EmulatorProxy : Proxy {
        
    AudioPortProxy *audioPort;
    GuardsProxy *beamtraps;
    PIAProxy *pia;
    ControlPortProxy *port1;
    ControlPortProxy *port2;
    CPUProxy *cpu;
    LogicAnalyzerProxy *logicAnalyzer;
    MemoryProxy *mem;
    PaddleProxy *paddle;
    RetroShellProxy *retroShell;
    TIAProxy *tia;
    VideoPortProxy *videoPort;
}

@property (class, readonly, strong) DefaultsProxy *defaults;

@property (readonly, strong) AudioPortProxy *audioPort;
@property (readonly, strong) AtariProxy *atari;
@property (readonly, strong) GuardsProxy *beamtraps;
@property (readonly, strong) PIAProxy *pia;
@property (readonly, strong) ControlPortProxy *port1;
@property (readonly, strong) ControlPortProxy *port2;
@property (readonly, strong) CPUProxy *cpu;
@property (readonly, strong) LogicAnalyzerProxy *logicAnalyzer;
@property (readonly, strong) MemoryProxy *mem;
@property (readonly, strong) RemoteManagerProxy *remoteManager;
@property (readonly, strong) RetroShellProxy *retroShell;
@property (readonly, strong) TIAProxy *tia;
@property (readonly, strong) VideoPortProxy *videoPort;

- (void)dealloc;
- (void)kill;

@property (class, readonly) NSString *build;
@property (class, readonly) NSString *version;

@property (readonly) EmulatorInfo info;
@property (readonly) EmulatorInfo cachedInfo;
@property (readonly) EmulatorStats stats;

@property (readonly) BOOL poweredOn;
@property (readonly) BOOL poweredOff;
@property (readonly) BOOL paused;
@property (readonly) BOOL running;
@property (readonly) BOOL suspended;
@property (readonly) BOOL halted;
@property (readonly) BOOL warping;
@property (readonly) BOOL tracking;

- (void)isReady:(ExceptionWrapper *)ex;
- (void)powerOn:(ExceptionWrapper *)ex;
- (void)powerOff;
- (void)run:(ExceptionWrapper *)ex;
- (void)pause;
- (void)halt;
- (void)suspend;
- (void)resume;
- (void)warpOn;
- (void)warpOn:(NSInteger)source;
- (void)warpOff;
- (void)warpOff:(NSInteger)source;
- (void)trackOn;
- (void)trackOn:(NSInteger)source;
- (void)trackOff;
- (void)trackOff:(NSInteger)source;

- (void)stepCycle;
- (void)stepInto;
- (void)stepOver;
- (void)finishLine;
- (void)finishFrame;

- (void)launch:(const void *)listener function:(Callback *)func;
- (void)wakeUp;

- (NSInteger)get:(Option)opt;
- (NSInteger)get:(Option)opt id:(NSInteger)id;
- (NSInteger)get:(Option)opt drive:(NSInteger)id;
- (BOOL)set:(Option)opt value:(NSInteger)val;
- (BOOL)set:(Option)opt enable:(BOOL)val;
- (BOOL)set:(Option)opt id:(NSInteger)id value:(NSInteger)val;
- (BOOL)set:(Option)opt id:(NSInteger)id enable:(BOOL)val;
- (BOOL)set:(Option)opt drive:(NSInteger)id value:(NSInteger)val;
- (BOOL)set:(Option)opt drive:(NSInteger)id enable:(BOOL)val;
- (void)exportConfig:(NSURL *)url exception:(ExceptionWrapper *)ex;

- (void)put:(CmdType)cmd;
- (void)put:(CmdType)type value:(NSInteger)value;
- (void)put:(CmdType)type value:(NSInteger)value value2:(NSInteger)value2;
- (void)put:(CmdType)type slider:(SliderCmd)cmd;
- (void)put:(CmdType)type key:(KeyCmd)cmd;
- (void)put:(CmdType)type coord:(CoordCmd)cmd;
- (void)put:(CmdType)type action:(GamePadCmd)cmd;

- (BOOL)isRom:(NSURL *)url;

- (void)attachCart:(NSURL *)url reset:(BOOL)reset exception:(ExceptionWrapper *)ex;
- (void)attachCart:(MediaFileProxy *)proxy reset:(BOOL)reset;
- (void)detachCart;
- (void)revertCartType;

- (void)flash:(MediaFileProxy *)container exception:(ExceptionWrapper *)ex;

@end


//
// Defaults
//

@interface DefaultsProxy : Proxy { }

- (void)load:(NSURL *)url exception:(ExceptionWrapper *)ex;
- (void)save:(NSURL *)url exception:(ExceptionWrapper *)ex;

- (void)register:(NSString *)key value:(NSString *)value;

- (NSString *)getString:(NSString *)key;
- (NSInteger)getInt:(NSString *)key;
- (NSInteger)getOpt:(Option)option;
- (NSInteger)getOpt:(Option)option nr:(NSInteger)nr;

- (void)setKey:(NSString *)key value:(NSString *)value;
- (void)setOpt:(Option)option value:(NSInteger)value;
- (void)setOpt:(Option)option nr:(NSInteger)nr value:(NSInteger)value;

- (void)removeAll;
- (void)removeKey:(NSString *)key;
- (void)remove:(Option)option;
- (void)remove:(Option) option nr:(NSInteger)nr;

@end


//
// Atari
//

@interface AtariProxy : Proxy { }

@property (readonly) AtariInfo info;
@property (readonly) AtariInfo cachedInfo;
- (EventSlotInfo)cachedSlotInfo:(NSInteger)slot;
@property NSInteger autoInspectionMask;
@property (readonly) CartTraits romTraits;

- (void)hardReset;
- (void)softReset;

- (MediaFileProxy *) takeSnapshot;

@end


//
// Guards (Breakpoints, Watchpoints, Beamtraps)
//

@interface GuardsProxy : Proxy { }

@property (readonly) NSInteger count;

- (NSInteger)addr:(NSInteger)nr;

- (BOOL)isSet:(NSInteger)nr;
- (BOOL)isSetAt:(NSInteger)addr;
- (void)setAt:(NSInteger)addr exception:(ExceptionWrapper *)ex;
- (void)remove:(NSInteger)nr exception:(ExceptionWrapper *)ex;
- (void)removeAt:(NSInteger)addr exception:(ExceptionWrapper *)ex;
- (void)removeAll;

- (void)replace:(NSInteger)nr addr:(NSInteger)addr exception:(ExceptionWrapper *)ex;

- (BOOL)isEnabled:(NSInteger)nr;
- (BOOL)isEnabledAt:(NSInteger)addr;
- (BOOL)isDisabled:(NSInteger)nr;
- (BOOL)isDisabledAt:(NSInteger)addr;

- (void)enable:(NSInteger)nr exception:(ExceptionWrapper *)ex;
- (void)enableAt:(NSInteger)addr exception:(ExceptionWrapper *)ex;
- (void)disable:(NSInteger)nr exception:(ExceptionWrapper *)ex;
- (void)disableAt:(NSInteger)addr exception:(ExceptionWrapper *)ex;

@end


//
// CPU
//

@interface CPUProxy : Proxy {

    GuardsProxy *breakpoints;
    GuardsProxy *watchpoints;
}

@property (readonly, strong) GuardsProxy *breakpoints;
@property (readonly, strong) GuardsProxy *watchpoints;

@property (readonly) CPUInfo info;
@property (readonly) CPUInfo cachedInfo;

- (NSInteger)loggedInstructions;
- (void)clearLog;

- (void)setHex;
- (void)setDec;

- (NSString *)disassemble:(NSInteger)addr format:(NSString *)fmt length:(NSInteger *)len;
- (NSString *)disassembleRecorded:(NSInteger)i format:(NSString *)fmt length:(NSInteger *)len;

@end


//
// PIA
//

@interface PIAProxy : Proxy { }

@property (readonly) PIAConfig config;
@property (readonly) PIAInfo info;
@property (readonly) PIAInfo cachedInfo;
@property (readonly) PIAStats stats;

@end


//
// Memory
//

@interface MemoryProxy : Proxy { }

@property (readonly) MemConfig config;
@property (readonly) MemInfo info;
@property (readonly) MemInfo cachedInfo;

- (NSString *)memdump:(NSInteger)addr num:(NSInteger)num hex:(BOOL)hex src:(MemoryType)src;
- (NSString *)txtdump:(NSInteger)addr num:(NSInteger)num src:(MemoryType)src;

- (void)drawHeatmap:(u32 *)buffer w:(NSInteger)w h:(NSInteger)h;

- (NSInteger)peek:(NSInteger)addr;
- (void)poke:(NSInteger)addr value:(NSInteger)value;

@end


//
// TIA
//

@interface TIAProxy : Proxy { }

@property (readonly) TIATraits traits;
@property (readonly) TIAConfig config;
@property (readonly) TIAInfo info;
@property (readonly) TIAInfo cachedInfo;

- (NSColor *)color:(NSInteger)nr;
- (UInt32)rgbaColor:(NSInteger)nr palette:(Palette)palette;

- (void)lockReg:(TIARegister)reg;
- (void)unlockReg:(TIARegister)reg;
- (void)toggleRegLock:(TIARegister)reg;

@end


//
// LogicAnalyzer
//

@interface LogicAnalyzerProxy : Proxy { }

- (LogicAnalyzerConfig)getConfig;

- (void)setColor:(NSInteger)channel color:(NSColor *)color;
- (const RecordedSignals *)getData:(NSInteger)line;


@end


//
// Audio port
//

@interface AudioPortProxy : Proxy { }

@property (readonly) AudioPortStats stats;

- (NSInteger)copyMono:(float *)target size:(NSInteger)n;
- (NSInteger)copyStereo:(float *)target1 buffer2:(float *)target2 size:(NSInteger)n;
- (NSInteger)copyInterleaved:(float *)target size:(NSInteger)n;

- (float)drawWaveform:(u32 *)buffer w:(NSInteger)w h:(NSInteger)h scale:(float)s color:(u32)c source:(NSInteger)source;
- (float)drawWaveform:(u32 *)buffer size:(NSSize)size scale:(float)s color:(u32)c source:(NSInteger)source;

@end


//
// Video port
//

@interface VideoPortProxy : Proxy { }

@property (readonly) u32 *texture;

@end


//
// ControlPort
//

@interface ControlPortProxy : Proxy {

    JoystickProxy *joystick;
    PaddleProxy *paddle;
}

@property (readonly) JoystickProxy *joystick;
@property (readonly) PaddleProxy *paddle;

@end


//
// Paddle
//

@interface PaddleProxy : Proxy { }

- (BOOL)detectShakeAbs:(NSPoint)pos;
- (BOOL)detectShakeRel:(NSPoint)pos;

@end


//
// Joystick
//

@interface JoystickProxy : Proxy { }

@end


//
// RemoteManager
//

@interface RemoteManagerProxy : Proxy { }

@property (readonly) RemoteManagerInfo info;

@end


//
// RetroShell
//

@interface RetroShellProxy : Proxy { }

@property (readonly) NSInteger cursorRel;

- (NSString *)getText;
- (void)pressKey:(char)c;
- (void)pressSpecialKey:(RetroShellKey)key;
- (void)pressSpecialKey:(RetroShellKey)key shift:(BOOL)shift;
- (void)executeScript:(MediaFileProxy *)file;
- (void)executeString:(NSString *)string;

@end


//
// MediaFile
//

@interface MediaFileProxy : Proxy
{
    NSImage *preview;
}

+ (FileType) typeOfUrl:(NSURL *)url;

+ (instancetype)make:(void *)file;
+ (instancetype)makeWithFile:(NSString *)path exception:(ExceptionWrapper *)ex;
+ (instancetype)makeWithFile:(NSString *)path type:(FileType)t exception:(ExceptionWrapper *)ex;
+ (instancetype)makeWithBuffer:(const void *)buf length:(NSInteger)len type:(FileType)t exception:(ExceptionWrapper *)ex;
+ (instancetype)makeWithTiara:(EmulatorProxy *)proxy;

@property (readonly) FileType type;
@property (readonly) u64 fnv;
@property (readonly) NSInteger size;
@property (readonly) BOOL compressed;

- (void)writeToFile:(NSString *)path exception:(ExceptionWrapper *)ex;

@property (readonly, strong) NSImage *previewImage;
@property (readonly) time_t timeStamp;

@end

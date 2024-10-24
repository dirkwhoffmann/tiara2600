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

#include "JoystickTypes.h"
#include "AtariTypes.h"
#include "Reflection.h"
#include "Option.h"

namespace tiara {

//
// Enumerations
//

/// Emulator command
enum_long(CMD_TYPE)
{
    CMD_NONE,                   ///< None

    // Emulator
    CMD_CONFIG,                 ///< Configure the emulator
    CMD_CONFIG_ALL,             ///< Configure the emulator

    // Atari
    CMD_SET_SLIDER,             ///< Operates a slider (console switch)
    CMD_ALARM_ABS,              ///< Schedule an alarm (absolute cycle)
    CMD_ALARM_REL,              ///< Schedule an alarm (relative cycle)
    CMD_INSPECTION_TARGET,      ///< Sets the auto-inspection component
    
    // CPU
    CMD_CPU_BRK,                ///< Let the CPU execute a BRK instruction
    CMD_CPU_NMI,                ///< Emulate an external expansion port NMI

    // Mouse
    CMD_MOUSE_MOVE_ABS,         ///< Signal a mouse movement (absolute)
    CMD_MOUSE_MOVE_REL,         ///< Signal a mouse movement (relative)
    CMD_MOUSE_EVENT,            ///< Signal a mouse button event

    // Joystick
    CMD_JOY_EVENT,              ///< Signal a joystick button event

    // RetroShell
    CMD_RSH_EXECUTE,            ///< Execute a script command

    // Host machine
    CMD_FOCUS                   ///< The emulator windows got or lost focus
};
typedef CMD_TYPE CmdType;

struct CmdTypeEnum : util::Reflection<CmdTypeEnum, CmdType> {

    static constexpr long minVal = 0;
    static constexpr long maxVal = CMD_FOCUS;

    static const char *prefix() { return "CMD"; }
    static const char *_key(long value)
    {
        switch (value) {

            case CMD_NONE:                  return "NONE";

            case CMD_CONFIG:                return "CONFIG";
            case CMD_CONFIG_ALL:            return "CONFIG_ALL";

            case CMD_SET_SLIDER:            return "SET_SLIDER";
            case CMD_ALARM_ABS:             return "ALARM_ABS";
            case CMD_ALARM_REL:             return "ALARM_REL";
            case CMD_INSPECTION_TARGET:     return "INSPECTION_TARGET";

            case CMD_CPU_BRK:               return "CPU_BRK";
            case CMD_CPU_NMI:               return "CPU_NMI";

            case CMD_MOUSE_MOVE_ABS:        return "MOUSE_MOVE_ABS";
            case CMD_MOUSE_MOVE_REL:        return "MOUSE_MOVE_REL";
            case CMD_MOUSE_EVENT:           return "MOUSE_EVENT";

            case CMD_JOY_EVENT:             return "JOY_EVENT";

            case CMD_RSH_EXECUTE:           return "RSH_EXECUTE";

            case CMD_FOCUS:                 return "FOCUS";

        }
        return "???";
    }
};

//
// Structures
//

typedef struct
{
    Option option;
    i64 value;
    isize id;
}
ConfigCmd;

typedef struct
{
    u8 keycode;
    double delay;
}
KeyCmd;

typedef struct
{
    isize port;
    double x;
    double y;
}
CoordCmd;

typedef struct
{
    isize port;
    GamePadAction action;
}
GamePadCmd;

typedef struct
{
    void *tape;
}
TapeCmd;

typedef struct
{
    i64 cycle;
    i64 value;
}
AlarmCmd;

typedef struct
{
    Slider slider;
    bool value;
    double delay;
}
SliderCmd;

typedef struct
{
    const char *command;
}
ShellCmd;

struct Cmd
{
    // Header
    CmdType type;

    // Payload
    union {

        struct { i64 value; i64 value2; };
        AlarmCmd alarm;
        SliderCmd slider;
        ConfigCmd config;
        CoordCmd coord;
        GamePadCmd action;
        KeyCmd key;
        ShellCmd shell;
        TapeCmd tape;
    };

    Cmd() { }
    Cmd(CmdType type, i64 v1 = 0, i64 v2 = 0) : type(type), value(v1), value2(v2) { }
    Cmd(CmdType type, const AlarmCmd &cmd) : type(type), alarm(cmd) { }
    Cmd(CmdType type, const SliderCmd &cmd) : type(type), slider(cmd) { }
    Cmd(CmdType type, const ConfigCmd &cmd) : type(type), config(cmd) { }
    Cmd(CmdType type, const CoordCmd &cmd) : type(type), coord(cmd) { }
    Cmd(CmdType type, const GamePadCmd &cmd) : type(type), action(cmd) { }
    Cmd(CmdType type, const KeyCmd &cmd) : type(type), key(cmd) { }
    Cmd(CmdType type, const ShellCmd &cmd) : type(type), shell(cmd) { }
    Cmd(CmdType type, const TapeCmd &cmd) : type(type), tape(cmd) { }
};

}

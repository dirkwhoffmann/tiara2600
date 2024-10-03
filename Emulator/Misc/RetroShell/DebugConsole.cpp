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
#include "Console.h"
#include "Emulator.h"

namespace tiara {

void
DebugConsole::_enter()
{
    msgQueue.put(MSG_RSH_DEBUGGER, true);

    // If the console is entered the first time...
    if (isEmpty()) {

        // Print the welcome message
        exec("welcome");
        *this << getPrompt();
    }
}

void
DebugConsole::_pause()
{
    *this << '\n' << '\n';
    exec("state");
    *this << getPrompt();
}

string
DebugConsole::getPrompt()
{
    std::stringstream ss;

    ss << "(";
    ss << std::right << std::setw(0) << std::dec << isize(atari.tia.getY());
    ss << ",";
    ss << std::right << std::setw(0) << std::dec << isize(atari.tia.getX());
    ss << ") $";
    ss << std::right << std::setw(4) << std::hex << isize(cpu.getPC0());
    ss << ": ";

    return ss.str();
}

void
DebugConsole::welcome()
{
    printHelp();
    *this << '\n';
}

void
DebugConsole::printHelp()
{
    storage << "Type 'help' or press 'TAB' twice for help.\n";
    storage << "Type '.' or press 'SHIFT+RETURN' to exit debug mode.";

    remoteManager.rshServer << "Type 'help' for help.\n";
    remoteManager.rshServer << "Type '.' to exit debug mode.";

    *this << '\n';
}

void
DebugConsole::pressReturn(bool shift)
{
    if (!shift && input.empty()) {

        emulator.isRunning() ? emulator.pause() : emulator.stepInto();

    } else {

        Console::pressReturn(shift);
    }
}

void
DebugConsole::initCommands(Command &root)
{
    Console::initCommands(root);

    //
    // Debug variables
    //

    root.add({"debug"}, "Debug variables");

    root.add({"debug", ""}, {},
             "Display all debug variables",
             [this](Arguments& argv, long value) {

        dump(emulator, Category::Debug);
    });

    if (debugBuild) {

        for (isize i = DebugFlagEnum::minVal; i < DebugFlagEnum::maxVal; i++) {

            root.add({"debug", DebugFlagEnum::key(i)}, { Arg::boolean },
                     DebugFlagEnum::help(i),
                     [](Arguments& argv, long value) {

                Emulator::setDebugVariable(DebugFlag(value), util::parseBool(argv[0]));

            }, i);
        }
    }


    //
    // Program execution
    //

    Command::currentGroup = "Program execution";

    root.add({"goto"}, { }, { Arg::value },
             std::pair <string, string>("g[oto]", "Goto address"),
             [this](Arguments& argv, long value) {

        argv.empty() ? emulator.run() : cpu.jump(parseAddr(argv[0]));
    });
    root.clone("g", {"goto"});

    root.add({"step"}, { }, { },
             std::pair <string, string>("s[tep]", "Step into the next instruction"),
             [this](Arguments& argv, long value) {

        emulator.stepInto();
    });
    root.clone("s", {"step"});

    root.add({"next"}, { }, { },
             std::pair <string, string>("n[next]", "Step over the next instruction"),
             [this](Arguments& argv, long value) {

        emulator.stepOver();
    });
    root.clone("n", {"next"});

    root.add({"break"},     "Manage CPU breakpoints");

    root.add({"break", ""},
             "List all breakpoints",
             [this](Arguments& argv, long value) {

        dump(cpu, Category::Breakpoints);
    });

    root.add({"break", "at"}, { Arg::address }, { Arg::ignores },
             "Set a breakpoint",
             [this](Arguments& argv, long value) {

        cpu.setBreakpoint(parseAddr(argv[0]), parseNum(argv, 1, 0));
    });

    root.add({"break", "delete"}, { Arg::nr },
             "Delete breakpoints",
             [this](Arguments& argv, long value) {

        cpu.deleteBreakpoint(parseNum(argv[0]));
    });

    root.add({"break", "toggle"}, { Arg::nr },
             "Enable or disable breakpoints",
             [this](Arguments& argv, long value) {

        cpu.toggleBreakpoint(parseNum(argv[0]));
    });

    root.add({"watch"},     "Manage CPU watchpoints");

    root.add({"watch", ""},
             "List all watchpoints",
             [this](Arguments& argv, long value) {

        dump(cpu, Category::Watchpoints);
    });

    root.add({"watch", "at"}, { Arg::address }, { Arg::ignores },
             "Set a watchpoint",
             [this](Arguments& argv, long value) {

        cpu.setWatchpoint(parseAddr(argv[0]), parseNum(argv, 1, 0));
    });

    root.add({"watch", "delete"}, { Arg::nr },
             "Delete watchpoints",
             [this](Arguments& argv, long value) {

        cpu.deleteWatchpoint(parseNum(argv[0]));
    });

    root.add({"watch", "toggle"}, { Arg::nr },
             "Enable or disable watchpoints",
             [this](Arguments& argv, long value) {

        cpu.toggleWatchpoint(parseNum(argv[0]));
    });


    //
    // Monitoring
    //

    Command::currentGroup = "Monitoring";

    root.add({"d"}, { }, { Arg::address },
             "Disassemble instructions",
             [this](Arguments& argv, long value) {

        std::stringstream ss;
        cpu.disassembler.disassembleRange(ss, parseAddr(argv, 0, cpu.getPC0()), 16);
        retroShell << '\n' << ss << '\n';
    });

    root.add({"a"}, { }, { Arg::address },
             "Dump memory in ASCII",
             [this](Arguments& argv, long value) {

        std::stringstream ss;
        mem.debugger.ascDump(ss, parseAddr(argv, 0, mem.debugger.current), 16);
        retroShell << '\n' << ss << '\n';
    });

    root.add({"m"}, { }, { Arg::address },
             std::pair<string, string>("m", "Dump memory"),
             [this](Arguments& argv, long value) {

        std::stringstream ss;
        mem.debugger.memDump(ss, parseAddr(argv, 0, mem.debugger.current), 16);
        retroShell << '\n' << ss << '\n';
    });

    root.add({"w"}, { Arg::value }, { Arg::address },
             std::pair<string, string>("w", "Write into memory"),
             [this](Arguments& argv, long value) {

        u16 addr = mem.debugger.current;
        if (argv.size() > 1) { addr = parseAddr(argv[1]); }
        mem.debugger.write(addr, u8(parseNum(argv[0])));
    });

    root.add({"c"}, { Arg::src, Arg::dst, Arg::count },
             std::pair<string, string>("c", "Copy a chunk of memory"),
             [this](Arguments& argv, long value) {

        mem.debugger.copy(u16(parseNum(argv[0])), u16(parseNum(argv[1])), parseNum(argv[2]));
    });

    root.add({"f"}, { Arg::sequence }, { Arg::address },
             std::pair<string, string>("f", "Find a sequence in memory"),
             [this](Arguments& argv, long value) {

        auto pattern = parseSeq(argv[0]);
        auto addr = parseAddr(argv, 1, mem.debugger.current);
        auto found = mem.debugger.memSearch(pattern, addr);

        if (found >= 0) {

            std::stringstream ss;
            mem.debugger.memDump(ss, u16(found), 16);
            retroShell << ss;

        } else {

            std::stringstream ss;
            ss << "Not found";
            retroShell << ss;
        }
    });

    root.add({"e"}, { Arg::address, Arg::count }, { Arg::value },
             std::pair<string, string>("e", "Erase memory"),
             [this](Arguments& argv, long value) {

        auto addr = parseAddr(argv[0]);
        auto cnt = parseNum(argv[1]);
        auto val = u8(parseNum(argv, 2, 0));
        
        mem.debugger.write(addr, val, cnt);
    });

    root.add({"r"},
             "Show registers");

    root.add({"r", "pia"}, "PIA",
             [this](Arguments& argv, long value) {

        dump(pia, Category::Registers);
    });

    root.add({"r", "tia"}, "TIA",
             [this](Arguments& argv, long value) {

        dump(tia, Category::Registers);
    });

    root.add({"?"},
             "Inspect a component");

    Command::currentGroup = "Components";

    root.add({"?", "thread"},       "Emulator thread");

    root.add({"?", "thread", ""},        "Displays the thread state",
             [this](Arguments& argv, long value) {

        dump(emulator, Category::State);
    });

    root.add({"?", "thread", "runahead"},    "Inspects the run-ahead instance",
             [this](Arguments& argv, long value) {

        dump(emulator, Category::RunAhead);
    });

    auto cmd = atari.shellName();
    auto description = atari.description();
    root.add({"?", cmd}, description, [this](Arguments& argv, long value) {

        dump(atari, { Category::Config, Category::State });
    });

    cmd = cpu.shellName();
    description = cpu.description();
    root.add({"?", cmd}, description, [this](Arguments& argv, long value) {

        dump(cpu, { Category::Config, Category::State });
    });

    cmd = mem.shellName();
    description = mem.description();
    root.add({"?", cmd}, description, [this](Arguments& argv, long value) {

        dump(mem, { Category::Config, Category::State });
    });

    cmd = pia.shellName();
    description = pia.description();
    root.add({"?", cmd}, description, [this](Arguments& argv, long value) {

        dump(pia, { Category::Config, Category::State });
    });

    cmd = tia.shellName();
    description = tia.description();
    root.add({"?", cmd}, description, [this](Arguments& argv, long value) {

        dump(tia, { Category::Config, Category::State });
    });

    cmd = cartPort.shellName();
    description = cartPort.description();
    root.add({"?", cmd}, description, [this](Arguments& argv, long value) {

        dump(cartPort, { Category::Config, Category::State });
    });

    Command::currentGroup = "Peripherals";

    cmd = port1.shellName();
    description = port1.description();
    root.add({"?", cmd}, description, [this](Arguments& argv, long value) {

        dump(port1, { Category::Config, Category::State });
    });

    cmd = port2.shellName();
    description = port2.description();
    root.add({"?", cmd}, description, [this](Arguments& argv, long value) {

        dump(port2, { Category::Config, Category::State });
    });

    cmd = port1.joystick.shellName();
    description = port1.joystick.description();
    root.add({"?", cmd}, description, [this](Arguments& argv, long value) {

        dump(port1.joystick, { Category::Config, Category::State });
    });

    cmd = port2.joystick.shellName();
    description = port2.joystick.description();
    root.add({"?", cmd}, description, [this](Arguments& argv, long value) {

        dump(port2.joystick, { Category::Config, Category::State });
    });

    cmd = audioPort.shellName();
    description = audioPort.description();
    root.add({"?", cmd}, description, [this](Arguments& argv, long value) {

        dump(audioPort, { Category::Config, Category::State });
    });

    Command::currentGroup = "Miscellaneous";

    cmd = host.shellName();
    description = host.description();
    root.add({"?", cmd}, description, [this](Arguments& argv, long value) {

        dump(host, { Category::Config, Category::State });
    });


    //
    // Miscellaneous
    //

    Command::currentGroup = "Miscellaneous";

    root.add({"checksums"},
             "Displays checksum of various components",
             [this](Arguments& argv, long value) {

        dump(atari, Category::Checksums);
    });

    root.add({"debug"}, "Debug variables");

    root.add({"debug", ""}, {},
             "Display all debug variables",
             [this](Arguments& argv, long value) {

        dump(emulator, Category::Debug);
    });

    if (debugBuild) {

        for (isize i = DebugFlagEnum::minVal; i < DebugFlagEnum::maxVal; i++) {

            root.add({"debug", DebugFlagEnum::key(i)}, { Arg::boolean },
                     DebugFlagEnum::help(i),
                     [](Arguments& argv, long value) {

                Emulator::setDebugVariable(DebugFlag(value), int(util::parseNum(argv[0])));

            }, i);
        }

        root.add({"debug", "verbosity"}, { Arg::value },
                 "Set the verbosity level for generated debug output",
                 [](Arguments& argv, long value) {

            CoreObject::verbosity = isize(util::parseNum(argv[0]));
        });
    }

    root.add({"%"}, { Arg::value },
             "Convert a value into different formats",
             [this](Arguments& argv, long value) {

        std::stringstream ss;

        if (isNum(argv[0])) {
            mem.debugger.convertNumeric(ss, u32(parseNum(argv[0])));
        } else {
            mem.debugger.convertNumeric(ss, argv.front());
        }

        retroShell << '\n' << ss << '\n';
    });
}



}

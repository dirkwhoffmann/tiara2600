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
#include "Option.h"
#include "IOUtils.h"

namespace tiara {

void
CommandConsole::_enter()
{
    msgQueue.put(MSG_RSH_DEBUGGER, false);

    // If the console is entered the first time...
    if (isEmpty()) {

        // Print the welcome message
        exec("welcome");
        *this << getPrompt();
    }
}

void
CommandConsole::_pause()
{

}

string
CommandConsole::getPrompt()
{
    return "tiara% ";
}

void
CommandConsole::welcome()
{
    storage << "Tiara RetroShell ";
    remoteManager.rshServer << "Tiara RetroShell Remote Server ";
    *this << Atari::build() << '\n';
    *this << '\n';
    *this << "Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de" << '\n';
    *this << "https://github.com/dirkwhoffmann/tiara2600" << '\n';
    *this << '\n';

    printHelp();
    *this << '\n';
}

void
CommandConsole::printHelp()
{
    storage << "Type 'help' or press 'TAB' twice for help.\n";
    storage << "Type '.' or press 'SHIFT+RETURN' to enter debug mode.";

    remoteManager.rshServer << "Type 'help' for help.\n";
    remoteManager.rshServer << "Type '.' to enter debug mode.";

    *this << '\n';
}

void
CommandConsole::pressReturn(bool shift)
{
    if (!shift && input.empty()) {

        retroShell.asyncExec("printhelp");

    } else {

        Console::pressReturn(shift);
    }
}

void
CommandConsole::initCommands(Command &root)
{
    Console::initCommands(root);

    //
    // Regression tester
    //

    Command::currentGroup = "Regression testing";

    auto cmd = registerComponent(regressionTester);
    root.seek("regression")->hidden = releaseBuild;

    // root.add({"regression"}, debugBuild ? "Runs the regression tester" : "");

    root.add({"regression", "setup"}, { C64ModelEnum::argList() },
             "Initialize the test environment",
             [this](Arguments& argv, long value) {

        auto model = parseEnum <C64Model, C64ModelEnum> (argv[0]);
        regressionTester.prepare(c64, model);
    });

    root.add({"regression", "run"}, { Arg::path },
             "Launch a regression test",
             [this](Arguments& argv, long value) {

        regressionTester.run(argv.front());
    });

    root.add({"screenshot"}, debugBuild ? "Manages screenshots" : "");

    root.add({"screenshot", "set"},
             "Configure the screenshot");

    root.add({"screenshot", "set", "path"}, { Arg::path },
             "Assign the save directory",
             [this](Arguments& argv, long value) {

        regressionTester.screenshotPath = argv.front();
    });

    root.add({"screenshot", "set", "cutout"}, { Arg::value, Arg::value, Arg::value, Arg::value },
             "Adjust the texture cutout",
             [this](Arguments& argv, long value) {

        isize x1 = parseNum(argv[0]);
        isize y1 = parseNum(argv[1]);
        isize x2 = parseNum(argv[2]);
        isize y2 = parseNum(argv[3]);

        regressionTester.x1 = x1;
        regressionTester.y1 = y1;
        regressionTester.x2 = x2;
        regressionTester.y2 = y2;
    });

    root.add({"screenshot", "save"}, { Arg::path },
             "Save a screenshot and exits the emulator",
             [this](Arguments& argv, long value) {

        regressionTester.dumpTexture(c64, argv.front());
    });


    //
    // Components
    //

    Command::currentGroup = "Components";

    //
    // Components (C64)
    //

    cmd = registerComponent(c64);

    root.add({cmd, "defaults"},
             "Display the user defaults storage",
             [this](Arguments& argv, long value) {

        dump(emulator, Category::Defaults);
    });

    root.add({cmd, "power"}, { Arg::onoff },
             "Switch the C64 on or off",
             [this](Arguments& argv, long value) {

        parseOnOff(argv[0]) ? c64.emulator.run() : c64.emulator.powerOff();
    });

    root.add({cmd, "reset"},
             "Perform a hard reset",
             [this](Arguments& argv, long value) {

        c64.hardReset();
    });

    root.add({cmd, "init"}, { C64ModelEnum::argList() },
             "Initialize the emulator with factory defaults",
             [](Arguments& argv, long value) {

        // emulator.set(parseEnum<C64Model, C64ModelEnum>(argv[0]));
    });

    root.add({cmd, "diff"},
             "Reports all differences to the default configuration",
             [this](Arguments& argv, long value) {

        std::stringstream ss;
        c64.exportDiff(ss);
        printf("ss = %s\n", ss.str().c_str());
        retroShell << ss << '\n';
    });


    //
    // Components (Memory)
    //

    cmd = registerComponent(mem);




    //
    // Components (RIOT)
    //

    cmd = registerComponent(riot);


    //
    // Components (TIA)
    //

    cmd = registerComponent(tia);


    //
    // Components (Logic Analyzer)
    //

    cmd = registerComponent(logicAnalyzer);

    root.add({cmd, "open"},
             "Opens the logic analyzer",
             [this](Arguments& argv, long value) {

        emulator.set(OPT_DMA_DEBUG_ENABLE, true);
    });

    root.add({cmd, "close"},
             "Closes the logic analyzer",
             [this](Arguments& argv, long value) {

        emulator.set(OPT_DMA_DEBUG_ENABLE, false);
    });


    //
    // Ports
    //

    Command::currentGroup = "Ports";


    //
    // Ports (Audio port)
    //

    cmd = registerComponent(audioPort);


    //
    // Ports (Video port)
    //

    cmd = registerComponent(videoPort);


    //
    // Peripherals
    //

    Command::currentGroup = "Peripherals";


    //
    // Peripherals (Monitor)
    //

    registerComponent(monitor);


    //
    // Peripherals (Joystick)
    //

    for (isize i = 0; i <= 1; i++) {

        if (i == 0) cmd = registerComponent(port1.joystick);
        if (i == 1) cmd = registerComponent(port2.joystick);

        root.add({cmd, "press"},
                 "Presses the joystick button",
                 [this](Arguments& argv, long value) {

            auto &port = (value == PORT_1) ? c64.port1 : c64.port2;
            port.joystick.trigger(PRESS_FIRE);

        }, i);

        root.add({cmd, "unpress"},
                 "Releases a joystick button",
                 [this](Arguments& argv, long value) {

            auto &port = (value == PORT_1) ? c64.port1 : c64.port2;
            port.joystick.trigger(RELEASE_FIRE);

        }, i);

        root.add({cmd, "pull"},
                 "Pulls the joystick");

        root.add({cmd, "pull", "left"},
                 "Pulls the joystick left",
                 [this](Arguments& argv, long value) {

            auto &port = (value == PORT_1) ? c64.port1 : c64.port2;
            port.joystick.trigger(PULL_LEFT);

        }, i);

        root.add({cmd, "pull", "right"},
                 "Pulls the joystick right",
                 [this](Arguments& argv, long value) {

            auto &port = (value == PORT_1) ? c64.port1 : c64.port2;
            port.joystick.trigger(PULL_RIGHT);

        }, i);

        root.add({cmd, "pull", "up"},
                 "Pulls the joystick up",
                 [this](Arguments& argv, long value) {

            auto &port = (value == PORT_1) ? c64.port1 : c64.port2;
            port.joystick.trigger(PULL_UP);

        }, i);

        root.add({cmd, "pull", "down"},
                 "Pulls the joystick down",
                 [this](Arguments& argv, long value) {

            auto &port = (value == PORT_1) ? c64.port1 : c64.port2;
            port.joystick.trigger(PULL_DOWN);

        }, i);

        root.add({cmd, "release"},
                 "Release a joystick axis");

        root.add({cmd, "release", "x"},
                 "Releases the x-axis",
                 [this](Arguments& argv, long value) {

            auto &port = (value == PORT_1) ? c64.port1 : c64.port2;
            port.joystick.trigger(RELEASE_X);

        }, i);

        root.add({cmd, "release", "y"},
                 "Releases the y-axis",
                 [this](Arguments& argv, long value) {

            auto &port = (value == PORT_1) ? c64.port1 : c64.port2;
            port.joystick.trigger(RELEASE_Y);

        }, i);
    }


    //
    // Peripherals (Paddles)
    //

    cmd = registerComponent(port1.paddle);
    cmd = registerComponent(port2.paddle);


    //
    // Miscellaneous
    //

    Command::currentGroup = "Miscellaneous";

    //
    // Miscellaneous (Host)
    //

    cmd = registerComponent(host);


    //
    // Miscellaneous (Remote server)
    //

    root.add({"server"}, "Remote connections");

    root.add({"server", ""},
             "Displays a server status summary",
             [this](Arguments& argv, long value) {

        dump(remoteManager, Category::State);
    });

    cmd = registerComponent(remoteManager.rshServer, root / "server");

    root.add({"server", cmd, "start"},
             "Starts the retro shell server",
             [this](Arguments& argv, long value) {

        remoteManager.rshServer.start();
    });

    root.add({"server", cmd, "stop"},
             "Stops the retro shell server",
             [this](Arguments& argv, long value) {

        remoteManager.rshServer.stop();
    });

    root.add({"server", cmd, "disconnect"},
             "Disconnects a client",
             [this](Arguments& argv, long value) {

        remoteManager.rshServer.disconnect();
    });
}

}

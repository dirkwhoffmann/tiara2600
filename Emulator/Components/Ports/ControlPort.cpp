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
#include "ControlPort.h"
#include "Atari.h"
#include "IOUtils.h"

namespace tiara {

void
ControlPort::execute()
{
    switch (device) {
            
        case CPDEVICE_MOUSE:    break;
        case CPDEVICE_JOYSTICK: joystick.eofHandler(); break;

        default:
            break;
    }
}

void
ControlPort::updateControlPort()
{
    // if (device == CPDEVICE_MOUSE) mouse.updateControlPort();
}

u8
ControlPort::getPiaBits() const
{
    switch (device) {
            
        case CPDEVICE_JOYSTICK: return joystick.getPiaBits();

        default:
            return 0xFF;
    }
}

u8
ControlPort::getTiaBits() const
{
    switch (device) {

        case CPDEVICE_JOYSTICK: return joystick.getTiaBits();

        default:
            return 0xFF;
    }
}

void
ControlPort::updatePotX()
{
    switch (device) {

        // case CPDEVICE_MOUSE: mouse.updatePotX(); break;

        default:
            break;
    }
}

void
ControlPort::updatePotY()
{
    switch (device) {

        // case CPDEVICE_MOUSE: mouse.updatePotY(); break;

        default:
            break;
    }
}

u8
ControlPort::readPotX() const
{
    switch (device) {

        // case CPDEVICE_MOUSE: return mouse.readPotX();

        default:
            return 0xFF;
    }
}

u8
ControlPort::readPotY() const
{
    switch (device) {

        // case CPDEVICE_MOUSE: return mouse.readPotY();

        default:
            return 0xFF;
    }
}

void
ControlPort::processCommand(const Cmd &cmd)
{
    switch (cmd.type) {

        case CMD_JOY_EVENT:         joystick.trigger(cmd.action.action); break;

        default:
            fatalError;
    }
}

}

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

#pragma once

#include "ControlPortTypes.h"
#include "CmdQueueTypes.h"
#include "SubComponent.h"
#include "Joystick.h"
#include "Paddle.h"

namespace tiara {

class ControlPort final : public SubComponent {

    friend class Joystick;
    friend class Paddle;

    Descriptions descriptions = {
        {
            .type           = ControlPortClass,
            .name           = "Port1",
            .description    = "Control Port 1",
            .shell          = "port1"
        },
        {
            .type           = ControlPortClass,
            .name           = "Port2",
            .description    = "Control Port 2",
            .shell          = "port2"
        }
    };

    Options options = {

    };
    
    // The connected device
    ControlPortDevice device = CPDEVICE_NONE;


    //
    // Subcomponents
    //

public:

    Joystick joystick = Joystick(atari, *this);
    Paddle paddle = Paddle(atari, *this);


    //
    // Methods
    //
    
public:

    ControlPort(Atari &ref, isize id);

    ControlPort& operator= (const ControlPort& other) {

        CLONE(joystick)
        CLONE(paddle)
        CLONE(device)
        
        return *this;
    }


    //
    // Methods from Serializable
    //

public:

    template <class T> void serialize(T& worker) { } SERIALIZERS(serialize);


    //
    // Methods from CoreComponent
    //

public:

    const Descriptions &getDescriptions() const override { return descriptions; }

private:

    void _dump(Category category, std::ostream& os) const override;


    //
    // Methods from Configurable
    //

public:

    const Options &getOptions() const override { return options; }
    

    //
    // Emulating
    //
    
public:
    
    // Invoked at the end of each frame
    void execute();

    // Updates the control port bits (must be called before reading)
    void updateControlPort();

    // Reads the port bits that show up in the PIA's data port registers
    u8 getPiaBits() const;

    // Reads the port bits that show up in the TIA's input registers
    u8 getTiaBits() const;

    // Updates the pot bits (must be called before reading)
    void updatePotX();
    void updatePotY();
    
    // Reads the pot bits that show up in the SID registers
    u8 readPotX() const;
    u8 readPotY() const;


    //
    // Processing commands and events
    //

public:

    // Processes a control port command
    void processCommand(const Cmd &cmd);
};

}

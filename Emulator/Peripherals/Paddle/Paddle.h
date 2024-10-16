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

#include "PaddleTypes.h"
#include "JoystickTypes.h"
#include "AtariTypes.h"
#include "SubComponent.h"

namespace tiara {

class ShakeDetector {

    // Horizontal position
    double x = 0.0;

    // Moved distance
    double dxsum = 0.0;

    // Direction (1 or -1)
    double dxsign = 1.0;

    // Number of turns
    isize dxturns = 0;

    // Time stamps
    u64 lastTurn = 0;
    util::Time lastShake;

public:

    // Feed in new coordinates and checks for a shake
    bool isShakingAbs(double x);
    bool isShakingRel(double dx);
};

class Paddle final : public SubComponent, public Inspectable<PaddleInfo> {

    Descriptions descriptions = {
        {
            .type           = PaddleClass,
            .name           = "Paddle1",
            .description    = "Paddle in Port 1",
            .shell          = "paddle1"
        },
        {
            .type           = PaddleClass,
            .name           = "Paddle2",
            .description    = "Paddle in Port 2",
            .shell          = "paddle2"
        }
    };

    Options options = {

        OPT_PADDLE_ORIENTATION,
        OPT_MOUSE_SHAKE_DETECT
    };

    // Reference to the control port this device belongs to
    ControlPort &port;

    // Current configuration
    PaddleConfig config = { };

    // Shake detector
    ShakeDetector shakeDetector;

    // Paddle positions in the range [-1...1]
    double pos[2] = { };

    // Button states
    bool button[2] = { };


    //
    // Methods
    //

public:

    Paddle(Atari &ref, ControlPort& pref);

    Paddle& operator= (const Paddle& other) {

        CLONE(config)

        return *this;
    }


    //
    // Methods from Serializable
    //

public:

    template <class T> void serialize(T& worker) {

        if (isResetter(worker)) return;

        worker

        << config.orientation;
    }
    
    void operator << (SerChecker &worker) override { serialize(worker); }
    void operator << (SerCounter &worker) override { serialize(worker); }
    void operator << (SerResetter &worker) override;
    void operator << (SerReader &worker) override;
    void operator << (SerWriter &worker) override { serialize(worker); }


    //
    // Methods from CoreComponent
    //

public:

    const Descriptions &getDescriptions() const override { return descriptions; }

private:

    void _dump(Category category, std::ostream& os) const override;
    void _didReset(bool hard) override;


    //
    // Methods from Inspectable
    //

private:

    void cacheInfo(PaddleInfo &result) const override;


    //
    // Methods from Configurable
    //

public:

    const PaddleConfig &getConfig() const { return config; }
    const Options &getOptions() const override { return options; }
    i64 getOption(Option opt) const override;
    void checkOption(Option opt, i64 value) override;
    void setOption(Option opt, i64 value) override;


    //
    // Using the device
    //

public:

    // Sets the button state
    void setButton(isize nr, bool value);

    // Sets the paddle position
    void setPosXY(isize nr, double x, double y);
    void setPosDxDy(isize nr, double x, double y);

    // Reads the port bits that show up in the CIA's data port registers
    u8 readControlPort() const;

    // Reads the pot bits that show up in the SID registers
    u8 readPotX() const;
    u8 readPotY() const;

    // Runs the shake detector
    bool detectShakeXY(double x, double y);
    bool detectShakeDxDy(double dx, double dy);
};

}

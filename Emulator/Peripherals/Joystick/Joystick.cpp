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
#include "Joystick.h"
#include "Emulator.h"
#include "IOUtils.h"

namespace tiara {

Joystick::Joystick(Atari& ref, ControlPort& pref) : SubComponent(ref, pref.objid), port(pref)
{
};

u8
Joystick::getPiaBits() const
{
    u8 result = 0xFF;

    if (axisY == -1) CLR_BIT(result, objid == 0 ? 0 : 4);
    if (axisY ==  1) CLR_BIT(result, objid == 0 ? 1 : 5);
    if (axisX == -1) CLR_BIT(result, objid == 0 ? 2 : 6);
    if (axisX ==  1) CLR_BIT(result, objid == 0 ? 3 : 7);

    return result;
}

u8
Joystick::getTiaBits() const
{
    u8 result = 0xFF;

    if (button) CLR_BIT(result, objid == 0 ? 4 : 5);

    return result;
}

void
Joystick::trigger(GamePadAction event)
{
    debug(JOY_DEBUG, "Port %ld: %s\n", objid, GamePadActionEnum::key(event));

    switch (event) {

        case PULL_UP:    axisY = -1; break;
        case PULL_DOWN:  axisY =  1; break;
        case PULL_LEFT:  axisX = -1; break;
        case PULL_RIGHT: axisX =  1; break;
        case RELEASE_X:  axisX =  0; break;
        case RELEASE_Y:  axisY =  0; break;
        case RELEASE_XY: axisX = axisY = 0; break;
            
        case PRESS_FIRE:
            
            // If autofire is enabled...
            if (config.autofire) {

                // ...check if we are currently firing.
                if (isAutofiring()) {

                    // If yes, the required action depends on the autofire mode.
                    if (config.autofireBursts) {

                        // In burst mode, reload the magazine.
                        reload();

                    } else {

                        // Otherwise, stop firing.
                        stopAutofire();
                    }

                } else {

                    // We are currently not firing. Initiate the first shot.
                    startAutofire();
                }

            } else {

                button = true;
            }
            break;

        case RELEASE_FIRE:
            
            if (!config.autofire) button = false;
            break;

        default:
            fatalError;
    }
    
    port.device = CPDEVICE_JOYSTICK;
    pia.updatePA();
}

void
Joystick::eofHandler()
{
    if (isAutofiring()) {

        if (i64(atari.frame) == nextAutofireFrame) {

            debug(JOY_DEBUG, "Autofire press\n");
            button = true;
            nextAutofireReleaseFrame = nextAutofireFrame + config.autofireDelay;
        }

        if (i64(atari.frame) == nextAutofireReleaseFrame) {

            debug(JOY_DEBUG, "Autofire release\n");
            button = false;
            if (--bulletCounter > 0) {
                nextAutofireFrame = nextAutofireReleaseFrame + config.autofireDelay;
            } else {
                stopAutofire();
            }
        }
    }
}

bool
Joystick::isAutofiring()
{
    return bulletCounter > 0;
}

isize 
Joystick::magazineSize()
{
    return config.autofireBursts ? config.autofireBullets : INT_MAX;
}

void
Joystick::startAutofire()
{
    debug(JOY_DEBUG, "startAutofire()\n");

    // Load magazine
    reload();

    // Fire the first shot
    button = true;

    // Schedule the release event
    nextAutofireReleaseFrame = atari.frame + config.autofireDelay;
}

void
Joystick::stopAutofire()
{
    trace(JOY_DEBUG, "stopAutofire()\n");

    // Release button and empty the bullet counter
    button = false;
    bulletCounter = 0;

    // Clear all events
    nextAutofireFrame = nextAutofireReleaseFrame = 0;
}

void
Joystick::reload()
{
    bulletCounter = magazineSize();
}

}

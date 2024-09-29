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
#include "Paddle.h"
#include "Emulator.h"
// #include "IOUtils.h"

namespace tiara {

Paddle::Paddle(Atari& ref, ControlPort& pref) : SubComponent(ref, pref.objid), port(pref)
{
};

void 
Paddle::setButton(isize nr, bool value)
{
    assert(nr == 0 || nr == 1);

    button[nr] = value;
}

void 
Paddle::setPosXY(isize nr, double x, double y)
{
    assert(nr == 0 || nr == 1);
    assert(x >= -1.0 && x <= 1.0);
    assert(y >= -1.0 && y <= 1.0);

    switch (config.orientation) {

        case PADDLE_HORIZONTAL:         pos[nr] = x; break;
        case PADDLE_HORIZONTAL_FLIPPED: pos[nr] = x; break;
        case PADDLE_VERTICAL:           pos[nr] = y; break;
        case PADDLE_VERTICAL_FLIPPED:   pos[nr] = y; break;

        default:
            fatalError;
    }
}

void 
Paddle::setPosDxDy(isize nr, double x, double y)
{
    assert(nr == 0 || nr == 1);

    switch (config.orientation) {

        case PADDLE_HORIZONTAL:         pos[nr] -= x; break;
        case PADDLE_HORIZONTAL_FLIPPED: pos[nr] += x; break;
        case PADDLE_VERTICAL:           pos[nr] += y; break;
        case PADDLE_VERTICAL_FLIPPED:   pos[nr] -= y; break;

        default:
            fatalError;
    }

    if (pos[nr] < -1.0) pos[nr] = -1.0;
    if (pos[nr] > 1.0) pos[nr] = 1.0;
}

u8
Paddle::readControlPort() const
{
    u8 result = 0xFF;

    if (button[0]) CLR_BIT(result, 2);
    if (button[1]) CLR_BIT(result, 3);

    return result;
}

u8
Paddle::readPotX() const
{
    return u8((pos[0] + 1.0) * 127.5);
}

u8
Paddle::readPotY() const
{
    return u8((pos[1] + 1.0) * 127.5);
}

bool
Paddle::detectShakeXY(double x, double y)
{
    if (config.shakeDetection && shakeDetector.isShakingAbs(x)) {
        msgQueue.put(MSG_SHAKING);
        return true;
    }
    return false;
}

bool
Paddle::detectShakeDxDy(double dx, double dy)
{
    if (config.shakeDetection && shakeDetector.isShakingRel(dx)) {
        msgQueue.put(MSG_SHAKING);
        return true;
    }
    return false;
}

bool
ShakeDetector::isShakingAbs(double newx)
{
    return isShakingRel(newx - x);
}

bool
ShakeDetector::isShakingRel(double dx) {

    // Accumulate the travelled distance
    x += dx;
    dxsum += abs(dx);

    // Check for a direction reversal
    if (dx * dxsign < 0) {

        u64 dt = util::Time::now().asNanoseconds() - lastTurn;
        dxsign = -dxsign;

        // A direction reversal is considered part of a shake, if the
        // previous reversal happened a short while ago.
        if (dt < 400 * 1000 * 1000) {

            // Eliminate jitter by demanding that the mouse has travelled
            // a long enough distance.
            if (dxsum > 400) {

                dxturns += 1;
                dxsum = 0;

                // Report a shake if the threshold has been reached.
                if (dxturns > 3) {

                    // printf("Mouse shake detected\n");
                    lastShake = util::Time::now().asNanoseconds();
                    dxturns = 0;
                    return true;
                }
            }

        } else {

            // Time out. The user is definitely not shaking the mouse.
            // Let's reset the recorded movement histoy.
            dxturns = 0;
            dxsum = 0;
        }

        lastTurn = util::Time::now().asNanoseconds();
    }

    return false;
}

}

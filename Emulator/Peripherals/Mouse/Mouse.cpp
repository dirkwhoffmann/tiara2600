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
#include "Mouse.h"
#include "Emulator.h"
#include "IOUtils.h"
#include <cmath>

namespace tiara {

Mouse::Mouse(C64 &ref, ControlPort& pref) : SubComponent(ref, pref.objid), port(pref)
{
    subComponents = std::vector<CoreComponent *> {
        
        &mouse1350,
        &mouse1351,
        &mouseNeos
    };
}

void Mouse::_didReset(bool hard)
{
    targetX = 0;
    targetY = 0;
}

i64
Mouse::getOption(Option option) const
{
    switch (option) {

        case OPT_MOUSE_MODEL:           return config.model;
        case OPT_MOUSE_VELOCITY:        return config.velocity;

        default:
            fatalError;
    }
}

void
Mouse::checkOption(Option opt, i64 value)
{
    switch (opt) {

        case OPT_MOUSE_MODEL:

            if (!MouseModelEnum::isValid(value)) {
                throw Error(VC64ERROR_OPT_INV_ARG, MouseModelEnum::keyList());
            }
            return;

        case OPT_MOUSE_VELOCITY:

            if (value < 0 || value > 255) {
                throw Error(VC64ERROR_OPT_INV_ARG, "0 ... 255");
            }
            return;

        default:
            throw Error(VC64ERROR_OPT_UNSUPPORTED);
    }
}

void
Mouse::setOption(Option opt, i64 value)
{    
    checkOption(opt, value);

    switch (opt) {
            
        case OPT_MOUSE_MODEL:
            
            config.model = MouseModel(value);
            targetX = 0;
            targetY = 0;
            return;

        case OPT_MOUSE_VELOCITY:

            if (value < 0 || value > 255) {
                throw Error(VC64ERROR_OPT_INV_ARG, "0 ... 255");
            }
            config.velocity = isize(value);
            updateScalingFactors();
            return;

        default:
            return;
    }
}

void
Mouse::updateScalingFactors()
{
    assert((unsigned long)config.velocity < 256);
    scaleX = scaleY = (double)config.velocity / 100.0;
}

void
Mouse::_dump(Category category, std::ostream& os) const
{
    using namespace util;

    if (category == Category::Config) {
        
        dumpConfig(os);
    }

    if (category == Category::State) {
        
        os << tab("Mouse nr") << dec(objid) << std::endl;
        os << tab("targetX") << targetX << std::endl;
        os << tab("targetY") << targetY << std::endl;
    }
}

void
Mouse::setXY(double x, double y)
{
    debug(PRT_DEBUG, "setXY(%f,%f)\n", x, y);

    switch(config.model) {

        case MOUSE_PADDLE_X:

            port.paddle.setPosXY(0, x * scaleX, y * scaleY);
            break;

        case MOUSE_PADDLE_Y:

            port.paddle.setPosXY(1, x * scaleX, y * scaleY);
            break;

        case MOUSE_PADDLE_XY:

            port.paddle.setPosXY(0, x * scaleX, y * scaleY);
            port.paddle.setPosXY(1, x * scaleX, y * scaleY);
            break;

        default:

            targetX = x * scaleX;
            targetY = y * scaleX;
            break;
    }

    port.device = CPDEVICE_MOUSE;
}

void
Mouse::setDxDy(double dx, double dy)
{
    debug(PRT_DEBUG, "setDxDy(%f,%f)\n", dx, dy);

    switch(config.model) {

        case MOUSE_PADDLE_X:    

            port.paddle.setPosDxDy(0, dx * scaleX / 10000, dy * scaleY / 10000);
            break;

        case MOUSE_PADDLE_Y:    

            port.paddle.setPosDxDy(1, dx * scaleX / 10000, dy * scaleY / 10000);
            break;

        case MOUSE_PADDLE_XY:

            port.paddle.setPosDxDy(0, dx * scaleX / 10000, dy * scaleY / 10000);
            port.paddle.setPosDxDy(1, dx * scaleX / 10000, dy * scaleY / 10000);
            break;

        default:

            targetX += dx * scaleX;
            targetY -= dy * scaleY;
            break;
    }

    port.device = CPDEVICE_MOUSE;
}

void
Mouse::setLeftButton(bool value)
{
    debug(PRT_DEBUG, "setLeftButton(%d)\n", value);
    
    switch(config.model) {
            
        case MOUSE_C1350:       mouse1350.setLeftMouseButton(value); break;
        case MOUSE_C1351:       mouse1351.setLeftMouseButton(value); break;
        case MOUSE_NEOS:        mouseNeos.setLeftMouseButton(value); break;
        case MOUSE_PADDLE_X:    port.paddle.setButton(0, value); break;
        case MOUSE_PADDLE_Y:    port.paddle.setButton(1, value); break;
        case MOUSE_PADDLE_XY:   port.paddle.setButton(0, value); port.paddle.setButton(1, value); break;

        default:
            fatalError;
    }
    port.device = CPDEVICE_MOUSE;
}

void
Mouse::setRightButton(bool value)
{
    debug(PRT_DEBUG, "setRightButton(%d)\n", value);

    switch(config.model) {
            
        case MOUSE_C1350:       mouse1350.setRightMouseButton(value); break;
        case MOUSE_C1351:       mouse1351.setRightMouseButton(value); break;
        case MOUSE_NEOS:        mouseNeos.setRightMouseButton(value); break;

        default:
            break;
    }
    port.device = CPDEVICE_MOUSE;
}

void
Mouse::trigger(GamePadAction event)
{
    assert_enum(GamePadAction, event);

    debug(PRT_DEBUG, "trigger(%ld)\n", event);
    
    switch (event) {

        case PRESS_LEFT: setLeftButton(true); break;
        case RELEASE_LEFT: setLeftButton(false); break;
        case PRESS_RIGHT: setRightButton(true); break;
        case RELEASE_RIGHT: setRightButton(false); break;
            
        default:
            break;
    }
}

void
Mouse::risingStrobe()
{
    mouseNeos.risingStrobe((i64)targetX, (i64)targetY);
}

void
Mouse::fallingStrobe()
{
    mouseNeos.fallingStrobe((i64)targetX, (i64)targetY);
}

void
Mouse::updatePotX()
{
    if (config.model == MOUSE_C1351) {
        mouse1351.executeX((i64)targetX);
    }
}

void
Mouse::updatePotY()
{
    if (config.model == MOUSE_C1351) {
        mouse1351.executeY((i64)targetY);
    }
}

void updatePotY();

u8
Mouse::readPotX() const
{
    switch(config.model) {
            
        case MOUSE_C1350:       return mouse1350.readPotX();
        case MOUSE_C1351:       return mouse1351.readPotX();
        case MOUSE_NEOS:        return mouseNeos.readPotX();
        case MOUSE_PADDLE_X:
        case MOUSE_PADDLE_Y:
        case MOUSE_PADDLE_XY:   return port.paddle.readPotX();

        default:
            fatalError;
    }
}

u8
Mouse::readPotY() const
{
    switch(config.model) {
            
        case MOUSE_C1350:       return mouse1350.readPotY();
        case MOUSE_C1351:       return mouse1351.readPotY();
        case MOUSE_NEOS:        return mouseNeos.readPotY();
        case MOUSE_PADDLE_X:
        case MOUSE_PADDLE_Y:
        case MOUSE_PADDLE_XY:   return port.paddle.readPotY();

        default:
            fatalError;
    }
}

void
Mouse::updateControlPort()
{
    if (config.model == MOUSE_NEOS) {
        mouseNeos.updateControlPort((i64)targetX, (i64)targetY);
    }
}

u8
Mouse::getControlPort() const
{
    switch(config.model) {
            
        case MOUSE_C1350:       return mouse1350.readControlPort();
        case MOUSE_C1351:       return mouse1351.readControlPort();
        case MOUSE_NEOS:        return mouseNeos.readControlPort();
        case MOUSE_PADDLE_X:
        case MOUSE_PADDLE_Y:
        case MOUSE_PADDLE_XY:   return port.paddle.readControlPort();

        default:
            fatalError;
    }
}

void
Mouse::execute()
{
    switch(config.model) {
            
        case MOUSE_C1350:
            
            mouse1350.execute((i64)targetX, (i64)targetY);
            break;
            
        case MOUSE_C1351:
            
            // Coordinates are updated in readPotX() and readPotY()
            break;
            
        case MOUSE_NEOS:
            
            // Coordinates are updated in latchPosition()
            break;

        case MOUSE_PADDLE_X:
        case MOUSE_PADDLE_Y:
        case MOUSE_PADDLE_XY:

            // Nothing to do
            break;

        default:
            fatalError;
    }
}

}

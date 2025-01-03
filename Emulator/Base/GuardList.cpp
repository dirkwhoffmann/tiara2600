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
#include "GuardList.h"
#include "Emulator.h"

namespace tiara {

void
GuardList::suspend()
{
    atari.suspend();
}

void
GuardList::resume()
{
    atari.resume();
}

std::optional<GuardInfo>
GuardList::guardNr(long nr) const
{
    if (auto *g = guards.guardNr(nr); g) {
        return GuardInfo {.addr = g->addr, .enabled = g->enabled, .ignore = g->ignore };
    }

    return { };
}

std::optional<GuardInfo>
GuardList::guardAt(u32 addr) const
{
    if (auto *g = guards.guardAt(addr); g) {
        return GuardInfo {.addr = g->addr, .enabled = g->enabled, .ignore = g->ignore };
    }

    return { };
}

std::optional<GuardInfo>
GuardList::hit() const
{
    if (auto g = guards.hit; g) {
        return GuardInfo {.addr = g->addr, .enabled = g->enabled, .ignore = g->ignore };
    }

    return { };
}

void
GuardList::setAt(u32 target, isize ignores)
{
    {   SUSPENDED

        if (guards.isSetAt(target)) throw Error(TIARA_ERROR_GUARD_ALREADY_SET, target);
        guards.setAt(target, ignores);
        update();
    }
    atari.msgQueue.put(MSG_GUARD_UPDATED);
}

void
GuardList::moveTo(isize nr, u32 newTarget)
{
    {   SUSPENDED

        if (!guards.guardNr(nr)) throw Error(TIARA_ERROR_GUARD_NOT_FOUND, nr);
        guards.moveTo(nr, newTarget);
        update();
    }
    atari.msgQueue.put(MSG_GUARD_UPDATED);
}

void
GuardList::ignore(long nr, long count)
{
    {   SUSPENDED

        if (!guards.guardNr(nr)) throw Error(TIARA_ERROR_GUARD_NOT_FOUND, nr);
        guards.ignore(nr, count);
        update();
    }
    atari.msgQueue.put(MSG_GUARD_UPDATED);
}

void
GuardList::remove(isize nr)
{
    {   SUSPENDED

        if (!guards.isSet(nr)) throw Error(TIARA_ERROR_GUARD_NOT_FOUND, nr);
        guards.remove(nr);
        update();
    }
    atari.msgQueue.put(MSG_GUARD_UPDATED);
}

void
GuardList::removeAt(u32 target)
{
    {   SUSPENDED

        if (!guards.isSetAt(target)) throw Error(TIARA_ERROR_GUARD_NOT_FOUND, target);
        guards.removeAt(target);
        update();
    }
    atari.msgQueue.put(MSG_GUARD_UPDATED);
}

void
GuardList::removeAll()
{
    {   SUSPENDED

        guards.removeAll();
        update();
    }
    atari.msgQueue.put(MSG_GUARD_UPDATED);
}

void
GuardList::enable(isize nr)
{
    {   SUSPENDED

        if (!guards.isSet(nr)) throw Error(TIARA_ERROR_GUARD_NOT_FOUND, nr);
        guards.enable(nr);
        update();
    }
    atari.msgQueue.put(MSG_GUARD_UPDATED);
}

void
GuardList::enableAt(u32 target)
{
    {   SUSPENDED

        if (!guards.isSetAt(target)) throw Error(TIARA_ERROR_GUARD_NOT_FOUND, target);
        guards.enableAt(target);
        update();
    }
    atari.msgQueue.put(MSG_GUARD_UPDATED);
}

void
GuardList::enableAll()
{
    {   SUSPENDED

        guards.enableAll();
        update();
    }
    atari.msgQueue.put(MSG_GUARD_UPDATED);
}

void
GuardList::disable(isize nr)
{
    {   SUSPENDED

        if (!guards.isSet(nr)) throw Error(TIARA_ERROR_GUARD_NOT_FOUND, nr);
        guards.disable(nr);
        update();
    }
    atari.msgQueue.put(MSG_GUARD_UPDATED);
}

void
GuardList::disableAt(u32 target)
{
    {   SUSPENDED

        if (!guards.isSetAt(target)) throw Error(TIARA_ERROR_GUARD_NOT_FOUND, target);
        guards.disableAt(target);
        update();
    }
    atari.msgQueue.put(MSG_GUARD_UPDATED);
}

void
GuardList::disableAll()
{
    {   SUSPENDED

        guards.disableAll();
        update();
    }
    atari.msgQueue.put(MSG_GUARD_UPDATED);
}

void
GuardList::toggle(isize nr)
{
    {   SUSPENDED

        guards.isEnabled(nr) ? disable(nr) : enable(nr);
    }
}

void
GuardList::update() {

    needsCheck = false;
    for (isize i = 0; i < guards.elements(); i++) {

        if (guards.isEnabled(i)) {

            needsCheck = true;
            break;
        }
    }

    setNeedsCheck(needsCheck);
}

}

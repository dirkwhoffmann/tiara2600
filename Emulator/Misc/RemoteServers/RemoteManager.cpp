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
#include "RemoteManager.h"
#include "IOUtils.h"
#include "Atari.h"

namespace tiara {

RemoteManager::RemoteManager(Atari& ref) : SubComponent(ref)
{
    subComponents = std::vector<CoreComponent *> {
        
        &rshServer
    };
}

void
RemoteManager::_dump(Category category, std::ostream& os) const
{
    using namespace util;
    
    if (category == Category::State) {

        os << "Remote server status: " << std::endl << std::endl;

        for (auto server : servers) {
            
            auto name = server->objectName();
            auto port = server->config.port;
            
            os << tab(string(name));
            
            if (server->isOff()) {
                os << "Off" << std::endl;
            } else {
                os << "Port " << dec(port);
                os << " (" << SrvStateEnum::key(server->state) << ")" << std::endl;
            }
        }
    }
}

void
RemoteManager::cacheInfo(RemoteManagerInfo &result) const
{
    info.numLaunching = numLaunching();
    info.numListening = numListening();
    info.numConnected = numConnected();
    info.numErroneous = numErroneous();
}

isize
RemoteManager::numLaunching() const
{
    isize result = 0;
    for (auto &s : servers) if (s->isStarting()) result++;
    return result;
}

isize
RemoteManager::numListening() const
{
    isize result = 0;
    for (auto &s : servers) if (s->isListening()) result++;
    return result;
}

isize
RemoteManager::numConnected() const
{
    isize result = 0;
    for (auto &s : servers) if (s->isConnected()) result++;
    return result;
}

isize
RemoteManager::numErroneous() const
{
    isize result = 0;
    for (auto &s : servers) if (s->isErroneous()) result++;
    return result;
}

void
RemoteManager::serviceServerEvent()
{
    assert(atari.eventid[SLOT_SRV] == SRV_LAUNCH_DAEMON);

    // Run the launch daemon
    if (rshServer.config.autoRun) {
        rshServer.shouldRun() ? rshServer._start() : rshServer._stop();
    }

    // Schedule next event
    atari.scheduleInc <SLOT_SRV> (Atari::sec(0.5), SRV_LAUNCH_DAEMON);
}

}

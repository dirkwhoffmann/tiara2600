// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension Inspector {

    private func cacheEvents() {

        if let emu = emu {
            eventInfo = emu.paused ? emu.atari.info : emu.atari.cachedInfo
        }
    }

    func refreshEvents(count: Int = 0, full: Bool = false) {

        cacheEvents()

        evCpuProgress.stringValue = "\(eventInfo.cpuProgress) Cycles"
        evVicProgress.stringValue = "\(eventInfo.frame) Frames"

        evTableView.refresh(count: count, full: full)
    }
}

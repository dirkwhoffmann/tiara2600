// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension Inspector {
    
    var selectedSID: Int { return sidSelector.indexOfSelectedItem }

    func refreshSID(count: Int = 0, full: Bool = false) {
        
        if let emu = emu {
            
            // Audio buffer
            let stats = emu.audioPort.stats
            let fillLevel = Int32(stats.fillLevel * 100)
            sidAudioBufferLevel.intValue = fillLevel
            sidAudioBufferLevelText.stringValue = "\(fillLevel) %"
            sidBufferUnderflows.intValue = Int32(stats.bufferUnderflows)
            sidBufferOverflows.intValue = Int32(stats.bufferOverflows)

            sidWaveformView.update()
        }
    }
    
    func refresh(waveform: UInt8, waveformPopup popup: NSPopUpButton) {

        popup.item(at: 0)?.state = (waveform == 0) ? .on : .off
        popup.item(at: 1)?.state = (waveform & 0x10 != 0) ? .on : .off
        popup.item(at: 2)?.state = (waveform & 0x20 != 0) ? .on : .off
        popup.item(at: 3)?.state = (waveform & 0x40 != 0) ? .on : .off
        popup.item(at: 4)?.state = (waveform & 0x80 != 0) ? .on : .off
    }

    @IBAction func selectSIDAction(_ sender: Any!) {

        fullRefresh()
    }
}

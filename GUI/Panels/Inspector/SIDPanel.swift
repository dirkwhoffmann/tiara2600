// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension Inspector {

    func refreshSID(count: Int = 0, full: Bool = false) {

        if let emu = emu {

            cacheTIA()

            aud0AUDV.integerValue = Int(tiaInfo.audio0.audv)
            aud0AUDF.integerValue = Int(tiaInfo.audio0.audf)
            aud0AUDC.integerValue = Int(tiaInfo.audio0.audc)
            aud0Poly40.integerValue = (Int(tiaInfo.audio0.poly4) & 0x01) != 0 ? 1 : 0
            aud0Poly41.integerValue = (Int(tiaInfo.audio0.poly4) & 0x02) != 0 ? 1 : 0
            aud0Poly42.integerValue = (Int(tiaInfo.audio0.poly4) & 0x04) != 0 ? 1 : 0
            aud0Poly43.integerValue = (Int(tiaInfo.audio0.poly4) & 0x08) != 0 ? 1 : 0
            aud0Poly50.integerValue = (Int(tiaInfo.audio0.poly5) & 0x01) != 0 ? 1 : 0
            aud0Poly51.integerValue = (Int(tiaInfo.audio0.poly5) & 0x02) != 0 ? 1 : 0
            aud0Poly52.integerValue = (Int(tiaInfo.audio0.poly5) & 0x04) != 0 ? 1 : 0
            aud0Poly53.integerValue = (Int(tiaInfo.audio0.poly5) & 0x08) != 0 ? 1 : 0
            aud0Poly54.integerValue = (Int(tiaInfo.audio0.poly5) & 0x10) != 0 ? 1 : 0

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

    /*
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
    */
}

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

            // Audio unit 0
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

            // Audio unit 1
            aud1AUDV.integerValue = Int(tiaInfo.audio1.audv)
            aud1AUDF.integerValue = Int(tiaInfo.audio1.audf)
            aud1AUDC.integerValue = Int(tiaInfo.audio1.audc)
            aud1Poly40.integerValue = (Int(tiaInfo.audio1.poly4) & 0x01) != 0 ? 1 : 0
            aud1Poly41.integerValue = (Int(tiaInfo.audio1.poly4) & 0x02) != 0 ? 1 : 0
            aud1Poly42.integerValue = (Int(tiaInfo.audio1.poly4) & 0x04) != 0 ? 1 : 0
            aud1Poly43.integerValue = (Int(tiaInfo.audio1.poly4) & 0x08) != 0 ? 1 : 0
            aud1Poly50.integerValue = (Int(tiaInfo.audio1.poly5) & 0x01) != 0 ? 1 : 0
            aud1Poly51.integerValue = (Int(tiaInfo.audio1.poly5) & 0x02) != 0 ? 1 : 0
            aud1Poly52.integerValue = (Int(tiaInfo.audio1.poly5) & 0x04) != 0 ? 1 : 0
            aud1Poly53.integerValue = (Int(tiaInfo.audio1.poly5) & 0x08) != 0 ? 1 : 0
            aud1Poly54.integerValue = (Int(tiaInfo.audio1.poly5) & 0x10) != 0 ? 1 : 0

            // Waveforms
            aud0WaveformView.update()
            aud1WaveformView.update()

            // Audio buffer
            let stats = emu.audioPort.stats
            let fillLevel = Int32(stats.fillLevel * 100)
            sidAudioBufferLevel.intValue = fillLevel
            sidAudioBufferLevelText.stringValue = "\(fillLevel) %"
            sidBufferUnderflows.intValue = Int32(stats.bufferUnderflows)
            sidBufferOverflows.intValue = Int32(stats.bufferOverflows)

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

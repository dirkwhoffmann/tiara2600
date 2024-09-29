// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension ConfigurationController {

    func refreshRomTab() {

        // if let emu = emu {
        if emu != nil {

            /*
            let basicRom = emu.c64.basicRom
            let charRom = emu.c64.charRom
            let kernalRom = emu.c64.kernalRom
            let vc1541Rom = emu.c64.vc1541Rom

            let poweredOff         = emu.poweredOff

            let hasChar            = charRom.crc != 0
            let hasCommodoreChar   = charRom.vendor == .COMMODORE
            let hasMega65Char      = charRom.vendor == .MEGA65
            let hasPatchedChar     = charRom.patched
            */

            let romMissing = NSImage(named: "rom_missing")
            /*
            let romOrig    = NSImage(named: "rom_original")
            let romMega    = NSImage(named: "rom_mega65")
            let romPatched = NSImage(named: "rom_patched")
            let romUnknown = NSImage(named: "rom_unknown")
            */

            // Icons
            cartDropView.image = romMissing

            /*
            kernalDropView.image =
            hasMega65Kernal    ? romMega :
            hasCommodoreKernal ? romOrig :
            hasPatchedKernal   ? romPatched :
            hasKernal          ? romUnknown : romMissing

            // Titles and subtitles
            basicTitle.stringValue = hasBasic ? String(cString: basicRom.title) : "Basic Rom"
            basicSubtitle.stringValue = hasBasic ? String(cString: basicRom.subtitle) : "Required"
            basicSubsubtitle.stringValue = String(cString: basicRom.revision)

            cartTitle.stringValue = hasChar ? String(cString: charRom.title) : "Character Rom"
            cartSubtitle.stringValue = hasChar ? String(cString: charRom.subtitle) : "Required"
            cartSubsubtitle.stringValue = String(cString: charRom.revision)

            kernalTitle.stringValue = hasKernal ? String(cString: kernalRom.title) : "Kernal Rom"
            kernalSubtitle.stringValue = hasKernal ? String(cString: kernalRom.subtitle) : "Required"
            kernalSubsubtitle.stringValue = String(cString: kernalRom.revision)

            vc1541Title.stringValue = hasVC1541 ? String(cString: vc1541Rom.title) : "VC1541 Rom"
            vc1541Subtitle.stringValue = hasVC1541 ? String(cString: vc1541Rom.subtitle) : "Optional"
            vc1541Subsubtitle.stringValue = String(cString: vc1541Rom.revision)
            */

            // Hide some controls
            /*
            basicDeleteButton.isHidden = !hasBasic
            cartDeleteButton.isHidden = !hasChar
            kernalDeleteButton.isHidden = !hasKernal
            vc1541DeleteButton.isHidden = !hasVC1541
            */

            // Boot button
            // romPowerButton.isHidden = !bootable
        }
    }

    //
    // Action methods
    //

    @IBAction func cartDeleteAction(_ sender: Any!) {

    }

    @IBAction func romDefaultsAction(_ sender: NSButton!) {
        
        do {

            try config.saveRomUserDefaults()

        } catch {

            parent.showAlert(.cantSaveRoms, error: error, window: window)
        }
    }
}

// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension ConfigurationController {

    func awakeCartPanelFromNib() {

        let first = tiara.CartridgeType._0840.rawValue
        let last = tiara.CartridgeType._X07.rawValue

        for i in first ... last {

            let item = tiara.CartridgeType(rawValue: i)
            cartCartType.addItem(withTitle: item!.description)
            cartCartType.lastItem!.tag = i
        }
    }

    func refreshRomTab() {

        if let emu = emu {

            let traits = emu.atari.romTraits

            let cartType = traits.cartType
            let hasCart = cartType != ._NONE
            let hasKnownCart = hasCart && cartType != ._UNKNOWN
            let name = traits.name != nil ? String(cString: traits.name) : ""
            let manufacturer = traits.manufacturer != nil ? String(cString: traits.manufacturer) : ""
            let model = traits.model != nil ? String(cString: traits.model) : ""
            let hash = traits.md5 != nil ? String(cString: traits.md5) : ""
            let supported = cartType == ._4K

            let romMissing = NSImage(named: "rom_missing")
            let romDefault = NSImage(named: "rom_original")

            // Icons
            cartDropView.image = hasCart ? romDefault : romMissing

            // Labels
            if hasCart {

                cartName.stringValue = name
                cartManufacturer.stringValue = manufacturer
                cartModel.stringValue = model
                cartCartType.stringValue = cartType.description

            } else {

                cartName.stringValue = "No cartridge"
                cartManufacturer.stringValue = "Use drag and drop to attach a cartridge"
                cartModel.stringValue = ""
                cartCartType.stringValue = ""
            }
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

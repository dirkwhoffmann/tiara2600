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

        let first = tiara.CartType._0840.rawValue
        let last = tiara.CartType._X07.rawValue

        for i in first ... last {

            let item = tiara.CartType(rawValue: i)
            cartCartType.addItem(withTitle: item!.description)
            cartCartType.lastItem!.tag = i
        }
    }

    func refreshRomTab() {

        func validCartType(type: tiara.CartType) -> Bool {

            return type.rawValue >= tiara.CartType._0840.rawValue &&
            type.rawValue <= tiara.CartType._X07.rawValue
        }

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
            cartDeleteButton.isHidden = !hasCart

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

            // PopUps
            cartCartType.isHidden = !hasCart
            if validCartType(type: traits.cartType) {
                cartCartType.selectItem(withTag: traits.cartType.rawValue)
                cartCartType.isEnabled = true
            } else {
                cartCartType.isEnabled = false
            }
        }
    }

    //
    // Action methods
    //

    @IBAction func cartDeleteAction(_ sender: Any!) {

        emu?.detachCart()
        refresh()
    }

    @IBAction func cartSetTypeAction(_ sender: NSPopUpButton!) {

        emu?.set(.CART_TYPE, value: sender.selectedTag())
        refresh()
    }

    @IBAction func cartRevertTypeAction(_ sender: NSPopUpButton!) {

        emu?.revertCartType()
        refresh()
    }

    @IBAction func cartDefaultsAction(_ sender: NSButton!) {
        
        do {

            try config.saveRomUserDefaults()

        } catch {

            parent.showAlert(.cantSaveRoms, error: error, window: window)
        }
    }
}

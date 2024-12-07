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

        let first = CartType._0840.rawValue
        let last = CartType._X07.rawValue

        for i in first ... last {

            let item = CartType(rawValue: i)
            cartType.addItem(withTitle: item!.description)
            cartType.lastItem!.tag = i
        }
    }

    func refreshRomTab() {

        func validCartType(type: CartType) -> Bool {

            return type.rawValue >= CartType._0840.rawValue &&
            type.rawValue <= CartType._X07.rawValue
        }

        if let emu = emu {

            let traits = emu.atari.romTraits

            let type = traits.cartType
            let hasCart = type != ._NONE
            let hasKnownCart = hasCart && type != ._UNKNOWN
            let name = traits.name != nil ? String(cString: traits.name) : ""
            let manufacturer = traits.manufacturer != nil ? String(cString: traits.manufacturer) : ""
            let model = traits.model != nil ? String(cString: traits.model) : ""
            let hash = traits.md5 != nil ? String(cString: traits.md5) : ""
            let supported = type == ._4K

            let romMissing = NSImage(named: "cart_missing")
            let romDefault = NSImage(named: "cart_original")

            // Icons
            cartDropView.image = hasCart ? romDefault : romMissing
            cartDeleteButton.isHidden = !hasCart

            // Labels
            if hasCart {

                cartName.stringValue = name
                cartManufacturer.stringValue = manufacturer
                cartModel.stringValue = model
                cartType.stringValue = type.description

            } else {

                cartName.stringValue = "No cartridge"
                cartManufacturer.stringValue = "Use drag and drop to attach a cartridge"
                cartModel.stringValue = ""
                cartType.stringValue = ""
            }

            // PopUps
            cartType.isHidden = !hasCart
            if validCartType(type: traits.cartType) {
                cartType.selectItem(withTag: traits.cartType.rawValue)
                cartType.isEnabled = true
            } else {
                cartType.isEnabled = false
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

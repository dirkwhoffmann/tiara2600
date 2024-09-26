// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension ConfigurationController {
   
    func refreshPeripheralsTab() {

        func update(_ component: NSTextField, enable: Bool) {
            component.textColor = enable ? .controlTextColor : .disabledControlTextColor
            component.isEnabled = enable
        }
        func update(_ component: NSControl, enable: Bool) {
            component.isEnabled = enable
        }
            
        // Ports
        parent.gamePadManager.refresh(popup: perControlPort1, hide: true)
        parent.gamePadManager.refresh(popup: perControlPort2, hide: true)
        perControlPort1.selectItem(withTag: config.gameDevice1)
        perControlPort2.selectItem(withTag: config.gameDevice2)

        // Joysticks
        let enable = config.autofire
        perAutofire.state = enable ? .on : .off
        perAutofireCease.state = config.autofireBursts ? .on : .off
        perAutofireBullets.integerValue = config.autofireBullets
        perAutofireFrequency.integerValue = config.autofireFrequency
        update(perAutofireFrequency, enable: enable)
        update(perAutofireFrequencyText1, enable: enable)
        update(perAutofireFrequencyText2, enable: enable)
        update(perAutofireCease, enable: enable)
        update(perAutofireCeaseText, enable: enable)
        update(perAutofireBullets, enable: enable && perAutofireCease.state == .on)
        update(perAutofireBulletsText, enable: enable && perAutofireCease.state == .on)

        // Power button
        perPowerButton.isHidden = !bootable
    }
    
    @IBAction func perControlPortAction(_ sender: NSPopUpButton!) {
                
        switch sender.tag {
        case 1: config.gameDevice1 = sender.selectedTag()
        case 2: config.gameDevice2 = sender.selectedTag()
        default: fatalError()
        }
    }
    
    @IBAction func perPaddleOrientationAction(_ sender: NSPopUpButton!) {

        config.paddleOrientation = sender.selectedTag()
    }

    @IBAction func perAutofireAction(_ sender: NSButton!) {

        config.autofire = (sender.state == .on)
    }

    @IBAction func perAutofireCeaseAction(_ sender: NSButton!) {

        config.autofireBursts = (sender.state == .on)
    }

    @IBAction func perAutofireBulletsAction(_ sender: NSTextField!) {

        config.autofireBullets = sender.integerValue
    }

    @IBAction func perAutofireFrequencyAction(_ sender: NSSlider!) {

        config.autofireFrequency = sender.integerValue
    }

    @IBAction func perPresetAction(_ sender: NSPopUpButton!) {

        if let emu = emu {
            
            emu.suspend()

            // Revert to standard settings
            EmulatorProxy.defaults.removePeripheralsUserDefaults()

            // Update the configuration
            config.applyPeripheralsUserDefaults()

            emu.resume()
        }
    }

    @IBAction func perDefaultsAction(_ sender: NSButton!) {
        
        config.savePeripheralsUserDefaults()
    }
    
}

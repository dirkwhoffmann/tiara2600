// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension ConfigurationController {

    func refreshPerformanceTab() {
                                
        // Power saving
        comViciiPowerSave.state = config.tiaPowerSave ? .on : .off

        // Warp
        comWarpMode.selectItem(withTag: config.warpMode)
        comWarpBoot.integerValue = config.warpBoot

        // Threading
        let speedBoost = config.speedBoost
        let runAhead = config.runAhead
        prfVSync.state = config.vsync ? .on : .off
        prfSpeedBoost.integerValue = speedBoost
        prfSpeedBoostInfo.stringValue = "\(speedBoost) %"
        prfRunAhead.integerValue = runAhead
        prfRunAheadInfo.stringValue = "\(runAhead) frame" + (runAhead == 1 ? "" : "s")
        prfSpeedBoost.isEnabled = !config.vsync
        prfSpeedBoostInfo.textColor = config.vsync ? .tertiaryLabelColor : .labelColor

        // Power button
        comPowerButton.isHidden = !bootable
    }

    //
    // Action methods (power saving)
    //

    @IBAction func comViciiPowerSaveAction(_ sender: NSButton!) {
        
        config.tiaPowerSave = sender.state == .on
    }

    //
    // Action methods (warp)
    //

    @IBAction func comWarpModeAction(_ sender: NSPopUpButton!) {

        config.warpMode = sender.selectedTag()
    }

    @IBAction func comWarpBootAction(_ sender: NSTextField!) {

        config.warpBoot = sender.integerValue
    }

    //
    // Action methods (threading)
    //

    @IBAction func prfVSyncAction(_ sender: NSButton!) {

        config.vsync = sender.state == .on
    }

    @IBAction func prfSpeedBoostAction(_ sender: NSSlider!) {

        config.speedBoost = sender.integerValue
    }

    @IBAction func prfRunAheadAction(_ sender: NSSlider!) {

        config.runAhead = sender.integerValue
    }

    @IBAction func comPresetAction(_ sender: NSPopUpButton!) {
        
        if let emu = emu {
            
            emu.suspend()

            // Revert to standard settings
            EmulatorProxy.defaults.removePerformanceUserDefaults()

            // Update the configuration
            config.applyPerformanceUserDefaults()

            // Override some options
            /*
            switch sender.selectedTag() {

            case 1: // Accurate

                config.viciiPowerSave = false
                config.ssCollisions = true
                config.sbCollisions = true

            case 2: // Accelerated

                config.viciiPowerSave = true
                config.ssCollisions = false
                config.sbCollisions = false

            default:
                break
            }
            */

            emu.resume()
        }
    }
    
    @IBAction func comDefaultsAction(_ sender: NSButton!) {
        
        config.savePerformanceUserDefaults()
    }
}

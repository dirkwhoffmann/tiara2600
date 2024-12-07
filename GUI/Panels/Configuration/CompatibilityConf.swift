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

        // Warp
        prfWarpMode.selectItem(withTag: config.warpMode)

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

        // Collisions
        let coll = config.tiaCollisions
        prfP0P1.state = coll & (1 << prfP0P1.tag) != 0 ? .on : .off
        prfP0M0.state = coll & (1 << prfP0M0.tag) != 0 ? .on : .off
        prfP0M1.state = coll & (1 << prfP0M1.tag) != 0 ? .on : .off
        prfP0BL.state = coll & (1 << prfP0BL.tag) != 0 ? .on : .off
        prfP0PF.state = coll & (1 << prfP0PF.tag) != 0 ? .on : .off
        prfP1M0.state = coll & (1 << prfP1M0.tag) != 0 ? .on : .off
        prfP1M1.state = coll & (1 << prfP1M1.tag) != 0 ? .on : .off
        prfP1BL.state = coll & (1 << prfP1BL.tag) != 0 ? .on : .off
        prfP1PF.state = coll & (1 << prfP1PF.tag) != 0 ? .on : .off
        prfM0M1.state = coll & (1 << prfM0M1.tag) != 0 ? .on : .off
        prfM0BL.state = coll & (1 << prfM0BL.tag) != 0 ? .on : .off
        prfM0PF.state = coll & (1 << prfM0PF.tag) != 0 ? .on : .off
        prfM1BL.state = coll & (1 << prfM1BL.tag) != 0 ? .on : .off
        prfM1PF.state = coll & (1 << prfM1PF.tag) != 0 ? .on : .off
        prfBLPF.state = coll & (1 << prfBLPF.tag) != 0 ? .on : .off

        // Power button
        prfPowerButton.isHidden = !bootable
    }

    //
    // Action methods (warp)
    //

    @IBAction func prfWarpModeAction(_ sender: NSPopUpButton!) {

        config.warpMode = sender.selectedTag()
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

    //
    // Action methods (Collisions)
    //

     @IBAction func prfCollisionAction(_ sender: NSButton!) {

         var coll = config.tiaCollisions

         if sender.state == .on {
             coll = coll | (1 << sender.tag)
         } else {
             coll = coll & ~(1 << sender.tag)
         }

         config.tiaCollisions = coll
     }

    @IBAction func prfPresetAction(_ sender: NSPopUpButton!) {
        
        if let emu = emu {
            
            emu.suspend()

            // Revert to standard settings
            EmulatorProxy.defaults.removePerformanceUserDefaults()

            // Update the configuration
            config.applyPerformanceUserDefaults()

            emu.resume()
        }
    }
    
    @IBAction func prfDefaultsAction(_ sender: NSButton!) {
        
        config.savePerformanceUserDefaults()
    }
}

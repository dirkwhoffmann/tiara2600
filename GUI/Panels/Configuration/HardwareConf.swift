// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension ConfigurationController {
    
    func awakeHardwarePrefsFromNib() {
        
    }
    
    func refreshHardwareTab() {
                                
        // VIC
        hwVicModelPopup.selectItem(withTag: config.vicRevision)
        
        switch tiara.VICIIRevision(rawValue: config.vicRevision) {

        case .PAL_6569_R1, .PAL_6569_R3:

            hwVicIcon.image = NSImage(named: "pref_vicii_pal")
            hwVicGrayDotBug.isEnabled = false

        case .PAL_8565:

            hwVicIcon.image = NSImage(named: "pref_vicii_pal")
            hwVicGrayDotBug.isEnabled = true

        case .NTSC_6567_R56A, .NTSC_6567:

            hwVicIcon.image = NSImage(named: "pref_vicii_ntsc")
            hwVicGrayDotBug.isEnabled = false

        case .NTSC_8562:
            
            hwVicIcon.image = NSImage(named: "pref_vicii_ntsc")
            hwVicGrayDotBug.isEnabled = true

        default:
            assert(false)
        }
        hwVicGrayDotBug.state = config.vicGrayDotBug ? .on : .off
        
        // CIA
        hwCiaModelPopup.selectItem(withTag: config.ciaRevision)
        hwCiaTimerBBug.state = config.ciaTimerBBug ? .on : .off

        // Logic board and power supply
        hwGlueLogicPopup.selectItem(withTag: config.glueLogic)
        hwPowerGridPopup.selectItem(withTag: config.powerGrid)

        // Startup
        hwRamPatternPopup.selectItem(withTag: config.ramPattern)

        // Power button
        hwPowerButton.isHidden = !bootable
    }
    
    @IBAction func hwVicRevAction(_ sender: NSPopUpButton!) {
        
        config.vicRevision = sender.selectedTag()
    }

    @IBAction func hwVicGrayDotBugAction(_ sender: NSButton!) {
        
        config.vicGrayDotBug = sender.state == .on
    }
    
    @IBAction func hwCiaRevAction(_ sender: NSPopUpButton!) {
        
        config.ciaRevision = sender.selectedTag()
    }
    
    @IBAction func hwCiaTimerBBugAction(_ sender: NSButton!) {

        config.ciaTimerBBug = sender.state == .on
    }
                
    @IBAction func hwGlueLogicAction(_ sender: NSPopUpButton!) {
        
        config.glueLogic = sender.selectedTag()
    }

    @IBAction func hwPowerGridAction(_ sender: NSPopUpButton!) {
        
        config.powerGrid = sender.selectedTag()
    }

    @IBAction func hwRamPatternAction(_ sender: NSPopUpButton!) {
        
        config.ramPattern = sender.selectedTag()
    }

    @IBAction func hwPresetAction(_ sender: NSPopUpButton!) {

        if let emu = emu {

            emu.suspend()

            // Revert to standard settings
            EmulatorProxy.defaults.removePeripheralsUserDefaults()

            // Update the configuration
            config.applyPeripheralsUserDefaults()

            // Override some options
            switch sender.selectedTag() {

            case 0: // C64_PAL
                config.vicRevision = tiara.VICIIRevision.PAL_6569_R3.rawValue
                config.vicGrayDotBug = false
                config.ciaRevision = tiara.CIARevision.MOS_6526.rawValue
                config.ciaTimerBBug = true
                config.glueLogic = tiara.GlueLogic.DISCRETE.rawValue
                config.powerGrid = tiara.PowerGrid.STABLE_50HZ.rawValue

            case 1: // C64_II_PAL
                config.vicRevision = tiara.VICIIRevision.PAL_8565.rawValue
                config.vicGrayDotBug = true
                config.ciaRevision = tiara.CIARevision.MOS_8521.rawValue
                config.ciaTimerBBug = false
                config.glueLogic = tiara.GlueLogic.IC.rawValue
                config.powerGrid = tiara.PowerGrid.STABLE_50HZ.rawValue

            case 2: // C64_OLD_PAL
                config.vicRevision = tiara.VICIIRevision.PAL_6569_R1.rawValue
                config.vicGrayDotBug = false
                config.ciaRevision = tiara.CIARevision.MOS_6526.rawValue
                config.ciaTimerBBug = true
                config.glueLogic = tiara.GlueLogic.DISCRETE.rawValue
                config.powerGrid = tiara.PowerGrid.STABLE_50HZ.rawValue

            case 3: // C64_NTSC
                config.vicRevision = tiara.VICIIRevision.NTSC_6567.rawValue
                config.vicGrayDotBug = false
                config.ciaRevision = tiara.CIARevision.MOS_6526.rawValue
                config.ciaTimerBBug = false
                config.glueLogic = tiara.GlueLogic.DISCRETE.rawValue
                config.powerGrid = tiara.PowerGrid.STABLE_60HZ.rawValue

            case 4: // C64_II_NTSC
                config.vicRevision = tiara.VICIIRevision.NTSC_8562.rawValue
                config.vicGrayDotBug = true
                config.ciaRevision = tiara.CIARevision.MOS_8521.rawValue
                config.ciaTimerBBug = true
                config.glueLogic = tiara.GlueLogic.IC.rawValue
                config.powerGrid = tiara.PowerGrid.STABLE_60HZ.rawValue

            case 5: // C64_OLD_NTSC
                config.vicRevision = tiara.VICIIRevision.NTSC_6567_R56A.rawValue
                config.vicGrayDotBug = false
                config.ciaRevision = tiara.CIARevision.MOS_6526.rawValue
                config.ciaTimerBBug = false
                config.glueLogic = tiara.GlueLogic.DISCRETE.rawValue
                config.powerGrid = tiara.PowerGrid.STABLE_60HZ.rawValue

            default:
                fatalError()
            }

            emu.resume()
        }
    }

    @IBAction func hwDefaultsAction(_ sender: NSButton!) {
        
        config.saveHardwareUserDefaults()
    }
}

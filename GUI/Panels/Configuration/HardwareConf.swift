// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension ConfigurationController {

    var paletteImage: NSImage? {

        // Compute layout
        let width = 256
        let height = 512
        let cols = 8
        let rows = 128 / cols
        let dx = width / cols
        let dy = height / rows

        // Create image representation
        let size = CGSize(width: width, height: height)
        let cap = width * height
        let mask = calloc(cap, MemoryLayout<UInt32>.size)!
        let ptr = mask.bindMemory(to: UInt32.self, capacity: cap)

        func drawBlock(y: Int, x: Int, abgr: UInt32) {

            for i in 0...dy {
                for j in 0...dx {

                    let index = (y * dy + i) * width + x * dx + j

                    if index < width * height {
                        ptr[index] = abgr
                    } else {
                        break
                    }
                }
            }
        }

        for i in 0..<rows {
            for j in 0..<cols {

                let color = emu?.tia.color(i*cols+j) ?? NSColor.white

                let r = Int(color.redComponent * CGFloat(255))
                let g = Int(color.greenComponent * CGFloat(255))
                let b = Int(color.blueComponent * CGFloat(255))
                let a = Int(color.alphaComponent * CGFloat(255))
                let abgr = UInt32(r | g << 8 | b << 16 | a << 24)

                drawBlock(y: i, x: j, abgr: abgr)
            }
        }

        // Create image
        let image = NSImage.make(data: mask, rect: size)
        let resizedImage = image?.resizeSharp(width: 512, height: 256)
        return resizedImage
    }
    
    func awakeHardwarePrefsFromNib() {
        
    }
    
    func refreshHardwareTab() {
                                
        // TIA
        hwVicModelPopup.selectItem(withTag: config.tiaRevision)
        tiaPalette.image = paletteImage
        
        /*
        switch tiara.TIARevision(rawValue: config.tiaRevision) {

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
        */

        // Startup
        hwRamPatternPopup.selectItem(withTag: config.ramPattern)

        // Power button
        hwPowerButton.isHidden = !bootable
    }
    
    @IBAction func hwVicRevAction(_ sender: NSPopUpButton!) {
        
        config.tiaRevision = sender.selectedTag()
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
            /*
            switch sender.selectedTag() {

            case 0: // C64_PAL
                config.vicRevision = tiara.VICIIRevision.PAL_6569_R3.rawValue
                config.vicGrayDotBug = false
                config.ciaRevision = tiara.CIARevision.MOS_6526.rawValue
                config.ciaTimerBBug = true

            case 1: // C64_II_PAL
                config.vicRevision = tiara.VICIIRevision.PAL_8565.rawValue
                config.vicGrayDotBug = true
                config.ciaRevision = tiara.CIARevision.MOS_8521.rawValue
                config.ciaTimerBBug = false

            case 2: // C64_OLD_PAL
                config.vicRevision = tiara.VICIIRevision.PAL_6569_R1.rawValue
                config.vicGrayDotBug = false
                config.ciaRevision = tiara.CIARevision.MOS_6526.rawValue
                config.ciaTimerBBug = true

            case 3: // C64_NTSC
                config.vicRevision = tiara.VICIIRevision.NTSC_6567.rawValue
                config.vicGrayDotBug = false
                config.ciaRevision = tiara.CIARevision.MOS_6526.rawValue
                config.ciaTimerBBug = false

            case 4: // C64_II_NTSC
                config.vicRevision = tiara.VICIIRevision.NTSC_8562.rawValue
                config.vicGrayDotBug = true
                config.ciaRevision = tiara.CIARevision.MOS_8521.rawValue
                config.ciaTimerBBug = true

            case 5: // C64_OLD_NTSC
                config.vicRevision = tiara.VICIIRevision.NTSC_6567_R56A.rawValue
                config.vicGrayDotBug = false
                config.ciaRevision = tiara.CIARevision.MOS_6526.rawValue
                config.ciaTimerBBug = false

            default:
                fatalError()
            }
            */

            emu.resume()
        }
    }

    @IBAction func hwDefaultsAction(_ sender: NSButton!) {
        
        config.saveHardwareUserDefaults()
    }
}

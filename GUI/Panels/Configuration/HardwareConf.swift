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

        let traits = emu!.tia.traits

        let fps = traits.fps
        let cpu = traits.cpuFrequency
        let height = traits.height
        let palette = traits.palette
        let colors = palette == .NTSC ? 128 : palette == .PAL ? 104 : 8

        // TIA
        hwTiaModelPopup.selectItem(withTag: config.tiaRevision)
        hwTiaModelPopup.isEnabled = !config.tiaAutoDetect
        hwTiaAutoDetect.state = config.tiaAutoDetect ? .on : .off

        // Config summary
        hwSummary.stringValue = "- \(fps) frames per second"
        hwSummary2.stringValue = String(format: "- %.2f MHz CPU clock", Float(cpu) / 1000000.0)
        hwSummary3.stringValue = "- \(height) scanlines per frame"
        hwSummary4.stringValue = "- \(colors) unique colors"

        // Images
        hwTiaPalette.image = paletteImage

        switch TIARevision(rawValue: config.tiaRevision) {

        case .NTSC, .NTSC50:    hwTiaIcon.image = NSImage(named: "pref_ntsc")
        case .PAL, .PAL60:      hwTiaIcon.image = NSImage(named: "pref_pal")
        case .SECAM, .SECAM60:  hwTiaIcon.image = NSImage(named: "pref_secam")

        default:
            assert(false)
        }

        // Startup
        hwRamPatternPopup.selectItem(withTag: config.ramPattern)

        // Power button
        hwPowerButton.isHidden = !bootable
    }
    
    @IBAction func hwTiaRevAction(_ sender: NSPopUpButton!) {
        
        config.tiaRevision = sender.selectedTag()
    }

    @IBAction func hwTiaAutoDetectAction(_ sender: NSButton!) {

        config.tiaAutoDetect = sender.state == .on
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

            emu.resume()
        }
    }

    @IBAction func hwDefaultsAction(_ sender: NSButton!) {
        
        config.saveHardwareUserDefaults()
    }
}

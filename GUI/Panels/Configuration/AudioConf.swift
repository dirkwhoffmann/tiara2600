// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension ConfigurationController {
    
    func refreshAudioTab() {
                                
        // Sampling
        audSampling.selectItem(withTag: config.sidSampling)

        // In
        audVol0.integerValue = config.vol0
        audVol1.integerValue = config.vol1
        audPan0.integerValue = config.pan0
        audPan1.integerValue = config.pan1

        // Out
        audVolL.integerValue = config.volL
        audVolR.integerValue = config.volR

        // Buttons
        audPowerButton.isHidden = !bootable
    }

    @IBAction func audVol0Action(_ sender: NSSlider!) {

        config.vol0 = sender.integerValue
    }
    
    @IBAction func audVol1Action(_ sender: NSSlider!) {

        config.vol1 = sender.integerValue
    }

    @IBAction func audPan0Action(_ sender: NSSlider!) {
        
        config.pan0 = sender.integerValue
    }
    
    @IBAction func audPan1Action(_ sender: NSSlider!) {
        
        config.pan1 = sender.integerValue
    }

    @IBAction func audVolLAction(_ sender: NSSlider!) {
        
        config.volL = sender.integerValue
    }

    @IBAction func audVolRAction(_ sender: NSSlider!) {
        
        config.volR = sender.integerValue
    }

    @IBAction func audSamplingAction(_ sender: NSPopUpButton!) {
        
        config.sidSampling = sender.selectedTag()
    }

    @IBAction func audPresetAction(_ sender: NSPopUpButton!) {
              
        if let emu = emu {
            
            emu.suspend()

            // Revert to standard settings
            EmulatorProxy.defaults.removeAudioUserDefaults()

            // Update the configuration
            config.applyAudioUserDefaults()

            // Override some options
            switch sender.selectedTag() {

            case 0: // Mono
                config.pan0 = 0
                config.pan1 = 0

            case 1: // Stereo
                config.pan0 = 100
                config.pan1 = 300

            default:
                fatalError()
            }

            emu.resume()
        }
    }
    
    @IBAction func audDefaultsAction(_ sender: NSButton!) {
        
        config.saveAudioUserDefaults()
    }
}

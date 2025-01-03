// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

class ConfigurationController: DialogController {

    var config: Configuration { return parent.config }
    
    @IBOutlet weak var prefTabView: NSTabView!
    
    //
    // Cartridge
    //

    @IBOutlet weak var cartDropView: RomDropView!
    @IBOutlet weak var cartName: NSTextField!
    @IBOutlet weak var cartManufacturer: NSTextField!
    @IBOutlet weak var cartModel: NSTextField!
    @IBOutlet weak var cartType: NSPopUpButton!
    @IBOutlet weak var cartWarning: NSTextField!
    @IBOutlet weak var cartDeleteButton: NSButton!

    @IBOutlet weak var cartOkButton: NSButton!
    @IBOutlet weak var cartPowerButton: NSButton!

    //
    // Hardware
    //
    
    // Custom chips
    @IBOutlet weak var hwTiaModelPopup: NSPopUpButton!
    @IBOutlet weak var hwTiaIcon: NSImageView!
    @IBOutlet weak var hwTiaAutoDetect: NSButton!
    @IBOutlet weak var hwTiaPalette: NSButton!
    @IBOutlet weak var hwPiaModelPopup: NSPopUpButton!

    // Startup
    @IBOutlet weak var hwRamPatternPopup: NSPopUpButton!

    // Summary
    @IBOutlet weak var hwSummary: NSTextField!
    @IBOutlet weak var hwSummary2: NSTextField!
    @IBOutlet weak var hwSummary3: NSTextField!
    @IBOutlet weak var hwSummary4: NSTextField!

    // Buttons
    @IBOutlet weak var hwOkButton: NSButton!
    @IBOutlet weak var hwPowerButton: NSButton!

    //
    // Peripherals
    //

    // Ports
    @IBOutlet weak var perControlPort1: NSPopUpButton!
    @IBOutlet weak var perControlPort2: NSPopUpButton!
        
    // Joystick
    @IBOutlet weak var perAutofire: NSButton!
    @IBOutlet weak var perAutofireText: NSTextField!
    @IBOutlet weak var perAutofireFrequency: NSSlider!
    @IBOutlet weak var perAutofireFrequencyText1: NSTextField!
    @IBOutlet weak var perAutofireFrequencyText2: NSTextField!
    @IBOutlet weak var perAutofireCease: NSButton!
    @IBOutlet weak var perAutofireCeaseText: NSTextField!
    @IBOutlet weak var perAutofireBullets: NSTextField!
    @IBOutlet weak var perAutofireBulletsText: NSTextField!

    // Buttons
    @IBOutlet weak var perPowerButton: NSButton!

    //
    // Performance
    //

    // Warp mode
    @IBOutlet weak var prfWarpMode: NSPopUpButton!

    // Threading
    @IBOutlet weak var prfSyncMode: NSPopUpButton!
    @IBOutlet weak var prfVSync: NSButton!
    @IBOutlet weak var prfSpeedBoost: NSSlider!
    @IBOutlet weak var prfSpeedBoostInfo: NSTextField!
    @IBOutlet weak var prfRunAhead: NSSlider!
    @IBOutlet weak var prfRunAheadInfo: NSTextField!

    // Emulation core
    @IBOutlet weak var prfFastPaths: NSButton!

    // Collisions
    @IBOutlet weak var prfP0P1: NSButton!
    @IBOutlet weak var prfP0M0: NSButton!
    @IBOutlet weak var prfP0M1: NSButton!
    @IBOutlet weak var prfP0BL: NSButton!
    @IBOutlet weak var prfP0PF: NSButton!
    @IBOutlet weak var prfP1M0: NSButton!
    @IBOutlet weak var prfP1M1: NSButton!
    @IBOutlet weak var prfP1BL: NSButton!
    @IBOutlet weak var prfP1PF: NSButton!
    @IBOutlet weak var prfM0M1: NSButton!
    @IBOutlet weak var prfM0BL: NSButton!
    @IBOutlet weak var prfM0PF: NSButton!
    @IBOutlet weak var prfM1BL: NSButton!
    @IBOutlet weak var prfM1PF: NSButton!
    @IBOutlet weak var prfBLPF: NSButton!

    // Buttons
    @IBOutlet weak var prfPowerButton: NSButton!

    //
    // Audio preferences
    //
    
    // Engine
    @IBOutlet weak var audSampling: NSPopUpButton!
    
    // In
    @IBOutlet weak var audVol0: NSSlider!
    @IBOutlet weak var audVol1: NSSlider!
    @IBOutlet weak var audVol2: NSSlider!
    @IBOutlet weak var audVol3: NSSlider!
    @IBOutlet weak var audPan0: NSSlider!
    @IBOutlet weak var audPan1: NSSlider!
    @IBOutlet weak var audPan2: NSSlider!
    @IBOutlet weak var audPan3: NSSlider!
    
    // Out
    @IBOutlet weak var audVolL: NSSlider!
    @IBOutlet weak var audVolR: NSSlider!

    // Buttons
    @IBOutlet weak var audOKButton: NSButton!
    @IBOutlet weak var audPowerButton: NSButton!
    
    //
    // Video preferences
    //
    
    // Palette
    @IBOutlet weak var vidPalettePopUp: NSPopUpButton!
    @IBOutlet weak var vidBrightnessSlider: NSSlider!
    @IBOutlet weak var vidContrastSlider: NSSlider!
    @IBOutlet weak var vidSaturationSlider: NSSlider!

    // Geometry
    @IBOutlet weak var vidZoom: NSPopUpButton!
    @IBOutlet weak var vidHZoom: NSSlider!
    @IBOutlet weak var vidVZoom: NSSlider!
    @IBOutlet weak var vidHZoomLabel: NSTextField!
    @IBOutlet weak var vidVZoomLabel: NSTextField!
    @IBOutlet weak var vidCenter: NSPopUpButton!
    @IBOutlet weak var vidHCenter: NSSlider!
    @IBOutlet weak var vidVCenter: NSSlider!
    @IBOutlet weak var vidHCenterLabel: NSTextField!
    @IBOutlet weak var vidVCenterLabel: NSTextField!

    // Effects
    @IBOutlet weak var vidUpscalerPopUp: NSPopUpButton!
    @IBOutlet weak var vidBlurPopUp: NSPopUpButton!
    @IBOutlet weak var vidBlurRadiusSlider: NSSlider!
    
    @IBOutlet weak var vidBloomPopUp: NSPopUpButton!
    @IBOutlet weak var vidBloomRadiusSlider: NSSlider!
    @IBOutlet weak var vidBloomBrightnessSlider: NSSlider!
    @IBOutlet weak var vidBloomWeightSlider: NSSlider!
    
    @IBOutlet weak var vidDotMaskPopUp: NSPopUpButton!
    @IBOutlet weak var vidDotMaskBrightnessSlider: NSSlider!
    
    @IBOutlet weak var vidScanlinesPopUp: NSPopUpButton!
    @IBOutlet weak var vidScanlineBrightnessSlider: NSSlider!
    @IBOutlet weak var vidScanlineWeightSlider: NSSlider!
    
    @IBOutlet weak var vidMisalignmentPopUp: NSPopUpButton!
    @IBOutlet weak var vidMisalignmentXSlider: NSSlider!
    @IBOutlet weak var vidMisalignmentYSlider: NSSlider!

    // Buttons
    @IBOutlet weak var vidOkButton: NSButton!
    @IBOutlet weak var vidPowerButton: NSButton!
    
    var bootable: Bool {
        
        do { try emu?.isReady() } catch { return false }
        return emu?.poweredOff ?? false
    }

    // The tab to open first
    var firstTab = ""
    
    func showSheet(tab: String) {
        
        firstTab = tab
        showSheet()
        refresh()
    }
    
    override func awakeFromNib() {

        awakeCartPanelFromNib()
        awakeVideoPanelFromNib()
        refresh()
    }
    
    override func sheetWillShow() {
        
        if firstTab != "" { prefTabView?.selectTabViewItem(withIdentifier: firstTab) }
        refresh()
    }
    
    func refresh() {
                
        if let id = prefTabView.selectedTabViewItem?.identifier as? String {
            
            switch id {
            case "Roms": refreshRomTab()
            case "Hardware": refreshHardwareTab()
            case "Peripherals": refreshPeripheralsTab()
            case "Performance": refreshPerformanceTab()
            case "Audio": refreshAudioTab()
            case "Video": refreshVideoTab()
            default: break
            }
        }
    }
    
    @IBAction func unlockAction(_ sender: Any!) {
                
        emu?.powerOff()
        refresh()
    }
    
    @IBAction override func okAction(_ sender: Any!) {
        
        hideSheet()
    }
    
    @IBAction func powerAction(_ sender: Any!) {
        
        hideSheet()
        try? emu?.run()
    }
}

extension ConfigurationController: NSTabViewDelegate {

    func tabView(_ tabView: NSTabView, didSelect tabViewItem: NSTabViewItem?) {

        refresh()
    }
}

extension ConfigurationController: NSTextFieldDelegate {

    func controlTextDidChange(_ obj: Notification) {

        if let view = obj.object as? NSTextField {

            let formatter = view.formatter as? NumberFormatter

            switch view {

            case perAutofireBullets:

                if formatter?.number(from: view.stringValue) != nil {
                    perAutofireBulletsAction(view)
                }

            default:
                break
            }
        }
    }
}

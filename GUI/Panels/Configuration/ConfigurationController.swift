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
    // Roms
    //
        
    @IBOutlet weak var basicDropView: RomDropView!
    @IBOutlet weak var basicTitle: NSTextField!
    @IBOutlet weak var basicSubtitle: NSTextField!
    @IBOutlet weak var basicSubsubtitle: NSTextField!
    @IBOutlet weak var basicDeleteButton: NSButton!
    
    @IBOutlet weak var kernalDropView: RomDropView!
    @IBOutlet weak var kernalTitle: NSTextField!
    @IBOutlet weak var kernalSubtitle: NSTextField!
    @IBOutlet weak var kernalSubsubtitle: NSTextField!
    @IBOutlet weak var kernalDeleteButton: NSButton!
    
    @IBOutlet weak var charDropView: RomDropView!
    @IBOutlet weak var charTitle: NSTextField!
    @IBOutlet weak var charSubtitle: NSTextField!
    @IBOutlet weak var charSubsubtitle: NSTextField!
    @IBOutlet weak var charDeleteButton: NSButton!
    
    @IBOutlet weak var vc1541DropView: RomDropView!
    @IBOutlet weak var vc1541Title: NSTextField!
    @IBOutlet weak var vc1541Subtitle: NSTextField!
    @IBOutlet weak var vc1541Subsubtitle: NSTextField!
    @IBOutlet weak var vc1541DeleteButton: NSButton!
    
    @IBOutlet weak var romInstallButton: NSButton!

    @IBOutlet weak var romLockImage: NSButton!
    @IBOutlet weak var romLockText: NSTextField!
    @IBOutlet weak var romLockSubText: NSTextField!

    @IBOutlet weak var romOkButton: NSButton!
    @IBOutlet weak var romPowerButton: NSButton!

    //
    // Hardware
    //
    
    // VIC
    @IBOutlet weak var hwVicModelPopup: NSPopUpButton!
    @IBOutlet weak var hwVicIcon: NSImageView!
    @IBOutlet weak var hwVicGrayDotBug: NSButton!
    
    // CIA
    @IBOutlet weak var hwCiaModelPopup: NSPopUpButton!
    @IBOutlet weak var hwCiaTimerBBug: NSButton!

    // Board logic and power supply
    @IBOutlet weak var hwGlueLogicPopup: NSPopUpButton!
    @IBOutlet weak var hwPowerGridPopup: NSPopUpButton!

    // Startup
    @IBOutlet weak var hwRamPatternPopup: NSPopUpButton!

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
    
    // Power saving
    @IBOutlet weak var comViciiPowerSave: NSButton!
    @IBOutlet weak var comSidPowerSave: NSButton!

    // Collision detection
    @IBOutlet weak var comSsCollisions: NSButton!
    @IBOutlet weak var comSbCollisions: NSButton!

    // Warp mode
    @IBOutlet weak var comWarpMode: NSPopUpButton!
    @IBOutlet weak var comWarpBoot: NSTextField!

    // Threading
    @IBOutlet weak var prfSyncMode: NSPopUpButton!
    @IBOutlet weak var prfVSync: NSButton!
    @IBOutlet weak var prfSpeedBoost: NSSlider!
    @IBOutlet weak var prfSpeedBoostInfo: NSTextField!
    @IBOutlet weak var prfRunAhead: NSSlider!
    @IBOutlet weak var prfRunAheadInfo: NSTextField!

    // Buttons
    @IBOutlet weak var comPowerButton: NSButton!

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
    
        awakeVideoPrefsFromNib()
        awakeHardwarePrefsFromNib()
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

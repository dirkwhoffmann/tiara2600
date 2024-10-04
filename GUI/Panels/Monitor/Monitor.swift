// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

class Monitor: DialogController {
    
    var config: Configuration { return parent.config }
    
    // Logic Analyzer
    @IBOutlet weak var laEnable: NSButton!
    @IBOutlet weak var laEnable0: NSButton!
    @IBOutlet weak var laEnable1: NSButton!
    @IBOutlet weak var laEnable2: NSButton!
    @IBOutlet weak var laEnable3: NSButton!

    @IBOutlet weak var laProbe0: NSPopUpButton!
    @IBOutlet weak var laProbe1: NSPopUpButton!
    @IBOutlet weak var laProbe2: NSPopUpButton!
    @IBOutlet weak var laProbe3: NSPopUpButton!

    @IBOutlet weak var laColor0: NSColorWell!
    @IBOutlet weak var laColor1: NSColorWell!
    @IBOutlet weak var laColor2: NSColorWell!
    @IBOutlet weak var laColor3: NSColorWell!

    @IBOutlet weak var laOpacity: NSSlider!
    @IBOutlet weak var laDisplayMode: NSPopUpButton!

    // Stencils
    @IBOutlet weak var cutEnable: NSButton!
    @IBOutlet weak var cutBorder: NSButton!
    @IBOutlet weak var cutForeground: NSButton!
    @IBOutlet weak var cutBackground: NSButton!
    @IBOutlet weak var cutSprites: NSButton!
    @IBOutlet weak var cutSprite0: NSButton!
    @IBOutlet weak var cutSprite1: NSButton!
    @IBOutlet weak var cutSprite2: NSButton!
    @IBOutlet weak var cutSprite3: NSButton!
    @IBOutlet weak var cutSprite4: NSButton!
    @IBOutlet weak var cutSprite5: NSButton!
    @IBOutlet weak var cutSprite6: NSButton!
    @IBOutlet weak var cutSprite7: NSButton!
    @IBOutlet weak var cutOpacity: NSSlider!
    
    // Sprites
    @IBOutlet weak var hideSprites: NSButton!

    override func awakeFromNib() {

        func initPopup(button: NSPopUpButton) {

            func add(_ title: String) {

                button.addItem(withTitle: title)
                button.lastItem!.tag = button.numberOfItems - 1
            }

            add("Unconnected")
            add("PHI1")
            add("PHI2")
            add("RDY")
            add("VSYNC")
            add("VBLANK")
        }

        super.awakeFromNib()

        // Initialize colors
        let palette: [NSColor] = [

            NSColor.blue,
            NSColor.red,
            NSColor.green,
            NSColor.yellow
        ]
        laColor0.color = palette[0]
        laColor1.color = palette[1]
        laColor2.color = palette[2]
        laColor3.color = palette[3]

        // Initialize PopUpButtons
        initPopup(button: laProbe0)
        initPopup(button: laProbe1)
        initPopup(button: laProbe2)
        initPopup(button: laProbe3)

        for i in 0..<4 { emu?.logicAnalyzer.setColor(i, color: palette[i]) }

        refresh()
    }
    
    override func showWindow(_ sender: Any?) {

        super.showWindow(self)

        print("Monitor: showWindow")
    }

    func refresh() {

        print("Refresh")

        if let la = emu?.logicAnalyzer.getConfig() {

            // Logic analyzer
            laEnable.state = la.enable ? .on : .off
            laEnable0.state = emu!.get(.LA_ENABLE0) != 0 ? .on : .off
            laEnable1.state = emu!.get(.LA_ENABLE1) != 0 ? .on : .off
            laEnable2.state = emu!.get(.LA_ENABLE2) != 0 ? .on : .off
            laEnable3.state = emu!.get(.LA_ENABLE3) != 0 ? .on : .off
            laProbe0.selectItem(withTag: emu!.get(.LA_PROBE0))
            laProbe1.selectItem(withTag: emu!.get(.LA_PROBE1))
            laProbe2.selectItem(withTag: emu!.get(.LA_PROBE2))
            laProbe3.selectItem(withTag: emu!.get(.LA_PROBE3))
            laOpacity.integerValue = Int(la.opacity)
            laDisplayMode.selectItem(withTag: la.displayMode.rawValue)
        }
    }
        
    //
    // Action methods
    //
    
    @IBAction func laEnableAction(_ sender: NSButton!) {

        emu?.set(.LA_ENABLE, enable: sender.state == .on)
    }

    @IBAction func laColorAction(_ sender: NSColorWell!) {

        emu?.logicAnalyzer.setColor(sender.tag, color: sender.color)
    }

    @IBAction func laChannelAction(_ sender: NSButton!) {

        switch sender.tag {
        case 0:  emu?.set(.LA_ENABLE0, enable: sender.state == .on)
        case 1:  emu?.set(.LA_ENABLE1, enable: sender.state == .on)
        case 2:  emu?.set(.LA_ENABLE2, enable: sender.state == .on)
        case 3:  emu?.set(.LA_ENABLE3, enable: sender.state == .on)
        default: break
        }
    }

    @IBAction func laProbeAction(_ sender: NSPopUpButton!) {

        switch sender.tag {
        case 0:  emu?.set(.LA_PROBE0, value: sender.selectedTag())
        case 1:  emu?.set(.LA_PROBE1, value: sender.selectedTag())
        case 2:  emu?.set(.LA_PROBE2, value: sender.selectedTag())
        case 3:  emu?.set(.LA_PROBE3, value: sender.selectedTag())
        default: break
        }
    }

    @IBAction func laDisplayModeAction(_ sender: NSPopUpButton!) {

        emu?.set(.LA_MODE, value: sender.selectedTag())
    }
    
    @IBAction func laOpacityAction(_ sender: NSSlider!) {

        emu?.set(.LA_OPACITY, value: sender.integerValue)
    }
}

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
    @IBOutlet weak var laChannel0: NSPopUpButton!
    @IBOutlet weak var laChannel1: NSPopUpButton!
    @IBOutlet weak var laChannel2: NSPopUpButton!
    @IBOutlet weak var laChannel3: NSPopUpButton!

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
        
        super.awakeFromNib()
        refresh()
    }
    
    override func showWindow(_ sender: Any?) {

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

        super.showWindow(self)

        print("Monitor: showWindow")

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
        initPopup(button: laChannel0)
        initPopup(button: laChannel1)
        initPopup(button: laChannel2)
        initPopup(button: laChannel3)

        for i in 0..<4 { emu?.logicAnalyzer.setColor(i, color: palette[i]) }

        refresh()
    }

    func refresh() {
                
        if let la = emu?.logicAnalyzer.getConfig() {

            // Logic analyzer
            laEnable.state = la.enable ? .on : .off
            laChannel0.selectItem(withTag: emu!.get(.LA_CHANNEL0))
            laChannel1.selectItem(withTag: emu!.get(.LA_CHANNEL1))
            laChannel2.selectItem(withTag: emu!.get(.LA_CHANNEL2))
            laChannel3.selectItem(withTag: emu!.get(.LA_CHANNEL3))
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

    @IBAction func laChannelAction(_ sender: NSPopUpButton!) {

        print("tag = \(sender.tag) selectedTag = \(sender.selectedTag())")
        switch sender.tag {
        case 0:  emu?.set(.LA_CHANNEL0, value: sender.selectedTag())
        case 1:  emu?.set(.LA_CHANNEL1, value: sender.selectedTag())
        case 2:  emu?.set(.LA_CHANNEL2, value: sender.selectedTag())
        case 3:  emu?.set(.LA_CHANNEL3, value: sender.selectedTag())
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

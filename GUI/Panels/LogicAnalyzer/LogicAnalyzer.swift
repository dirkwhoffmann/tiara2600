// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

class LogicAnalyzer: DialogController {
    
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

    @IBOutlet weak var trace0: LogicView!

    @IBOutlet weak var laOpacity: NSSlider!
    @IBOutlet weak var laDisplayMode: NSPopUpButton!

    // Indicates if the panel needs to be updated
    var isDirty = false

    var line = 4

    override func awakeFromNib() {

        func initPopup(button: NSPopUpButton) {

            func add(_ title: String) {

                button.addItem(withTitle: title)
                button.lastItem!.tag = button.numberOfItems - 1
            }

            button.removeAllItems()
            add("Address Bus")
            add("Data Bus")
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
        laColor0.color = palette[0]; trace0.signalColor[0] = palette[0]
        laColor1.color = palette[1]; trace0.signalColor[1] = palette[1]
        laColor2.color = palette[2]; trace0.signalColor[2] = palette[2]
        laColor3.color = palette[3]; trace0.signalColor[3] = palette[3]

        // Initialize PopUpButtons
        initPopup(button: laProbe0)
        initPopup(button: laProbe1)
        initPopup(button: laProbe2)
        initPopup(button: laProbe3)

        for i in 0..<4 { emu?.logicAnalyzer.setColor(i, color: palette[i]) }

        // trace0.needsDisplay = true

        refresh()
    }
    
    override func showWindow(_ sender: Any?) {

        super.showWindow(self)
    }

    func fullRefresh() {

        refresh(full: true)
    }

    func continuousRefresh() {

        if isDirty { refresh() }
        if emu?.running == true { isDirty = true }
    }

    func refresh(full: Bool = false) {

        if window?.isVisible == false { return }

        if let la = emu?.logicAnalyzer.getConfig() {

            let probe0 = emu!.get(.LA_PROBE0)
            let probe1 = emu!.get(.LA_PROBE1)
            let probe2 = emu!.get(.LA_PROBE2)
            let probe3 = emu!.get(.LA_PROBE3)

            laProbe0.selectItem(withTag: probe0)
            laProbe1.selectItem(withTag: probe1)
            laProbe2.selectItem(withTag: probe2)
            laProbe3.selectItem(withTag: probe3)
            laOpacity.integerValue = Int(la.opacity)
            laDisplayMode.selectItem(withTag: la.displayMode.rawValue)

            trace0.probe[0] = tiara.Probe(rawValue: probe0)!
            trace0.probe[1] = tiara.Probe(rawValue: probe1)!
            trace0.probe[2] = tiara.Probe(rawValue: probe2)!
            trace0.probe[3] = tiara.Probe(rawValue: probe3)!
        }

        trace0.update()

        isDirty = false
    }
        
    //
    // Action methods
    //

    @IBAction func updateLineAction(_ sender: NSButton!) {

        line = Int(emu?.tia.info.posy ?? 0)
        refresh()
    }

    @IBAction func laColorAction(_ sender: NSColorWell!) {

        emu?.logicAnalyzer.setColor(sender.tag, color: sender.color)
        trace0.signalColor[sender.tag] = sender.color
    }

    @IBAction func laChannelAction(_ sender: NSButton!) {

        switch sender.tag {
        case 0:  emu?.set(.LA_CHANNEL0, enable: sender.state == .on)
        case 1:  emu?.set(.LA_CHANNEL1, enable: sender.state == .on)
        case 2:  emu?.set(.LA_CHANNEL2, enable: sender.state == .on)
        case 3:  emu?.set(.LA_CHANNEL3, enable: sender.state == .on)
        default: break
        }
    }

    @IBAction func laProbeAction(_ sender: NSPopUpButton!) {

        let tag = sender.selectedTag()

        switch sender.tag {
        case 0:  emu?.set(.LA_PROBE0, value: tag)
        case 1:  emu?.set(.LA_PROBE1, value: tag)
        case 2:  emu?.set(.LA_PROBE2, value: tag)
        case 3:  emu?.set(.LA_PROBE3, value: tag)
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

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
    @IBOutlet weak var laLineField: NSTextField!
    @IBOutlet weak var laAutoLineButton: NSButton!
    @IBOutlet weak var laLineStepper: NSStepper!

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

    @IBOutlet weak var scrollView: NSScrollView!
    @IBOutlet weak var trace0: LogicView!

    @IBOutlet weak var laOpacity: NSSlider!
    @IBOutlet weak var laDisplayMode: NSPopUpButton!

    @IBOutlet weak var symButtom: NSButton!
    @IBOutlet weak var hexButtom: NSButton!

    @IBOutlet weak var runButton: NSButton!
    @IBOutlet weak var finishCycleButton: NSButton!
    @IBOutlet weak var finishLineButton: NSButton!
    @IBOutlet weak var finishFrameButton: NSButton!

    @IBOutlet weak var timeStamp: NSTextField!
    @IBOutlet weak var laX: NSTextField!
    @IBOutlet weak var laY: NSTextField!

    // Indicates if the panel needs to be updated
    var isDirty = false

    // The displayed scanline
    var line = 0 {
        didSet {
            laLineField.integerValue = line
            laLineStepper.integerValue = line
        }
    }

    // Indicates if the displayed scanline is always the current line
    var linked: Bool { return laAutoLineButton.state == .on }

    // Zoom level
    var zoom = 1.0 {
        didSet {
            let w = scrollView.frame.size.width * CGFloat(zoom)
            let h = scrollView.frame.size.height
            trace0.setFrameSize(NSSize(width: w, height: h))
        }
    }

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

            zoom = 15
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
        for i in 0..<4 { emu?.logicAnalyzer.setColor(i, color: palette[i]) }

        // Initialize PopUpButtons
        initPopup(button: laProbe0)
        initPopup(button: laProbe1)
        initPopup(button: laProbe2)
        initPopup(button: laProbe3)

        // Assign styles
        timeStamp.font = NSFont.monospacedSystemFont(ofSize: 12, weight: .regular)
        // laF.textColor = .secondaryLabelColor

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
        guard let emu = emu else { return }

        let tiaInfo = emu.tia.info
        let config = emu.logicAnalyzer.getConfig()

        if full {

            if emu.running {

                runButton.image = NSImage(named: "pauseTemplate")
                runButton.toolTip = "Pause"
                finishFrameButton.isEnabled = false
                finishCycleButton.isEnabled = false

            } else {

                runButton.image = NSImage(named: "runTemplate")
                runButton.toolTip = "Run"
                finishFrameButton.isEnabled = true
                finishCycleButton.isEnabled = true
            }
        }

        // Switch to the current line if applicable
        if linked { line = tiaInfo.posy }
        laLineField.isEditable = !linked

        let probe0 = emu.get(.LA_PROBE0)
        let probe1 = emu.get(.LA_PROBE1)
        let probe2 = emu.get(.LA_PROBE2)
        let probe3 = emu.get(.LA_PROBE3)

        laProbe0.selectItem(withTag: probe0)
        laProbe1.selectItem(withTag: probe1)
        laProbe2.selectItem(withTag: probe2)
        laProbe3.selectItem(withTag: probe3)
        laOpacity.integerValue = Int(config.opacity)
        laDisplayMode.selectItem(withTag: config.displayMode.rawValue)

        trace0.probe[0] = tiara.Probe(rawValue: probe0)!
        trace0.probe[1] = tiara.Probe(rawValue: probe1)!
        trace0.probe[2] = tiara.Probe(rawValue: probe2)!
        trace0.probe[3] = tiara.Probe(rawValue: probe3)!

        symButtom.state = trace0.formatter.symbolic ? .on : .off
        hexButtom.state = trace0.formatter.hex ? .on : .off

        timeStamp.stringValue = String(format: "%d:%03d:%03d",
                                       tiaInfo.frame, tiaInfo.posy, tiaInfo.posx)

        trace0.update()

        isDirty = false
    }

    //
    // Delegation calls
    //

    func powerOn() {

        fullRefresh()
    }

    func powerOff() {

        fullRefresh()
    }

    func run() {

        fullRefresh()
    }

    func pause() {

        fullRefresh()
    }

    func step() {

        fullRefresh()
    }

    func reset() {

        fullRefresh()
    }

    //
    // Action methods
    //

    @IBAction func lineAction(_ sender: NSTextField!) {

        line = sender.integerValue
        refresh()
    }

    @IBAction func lineStepperAction(_ sender: NSStepper!) {

        line = sender.integerValue
        refresh()
    }

    @IBAction func autoLineAction(_ sender: NSButton!) {

        line = Int(emu?.tia.info.posy ?? 0)
        refresh()
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

    @IBAction func laColorAction(_ sender: NSColorWell!) {

        emu?.logicAnalyzer.setColor(sender.tag, color: sender.color)
        trace0.signalColor[sender.tag] = sender.color
    }

    @IBAction func zoomInAction(_ sender: NSButton!) {

        if zoom < 21 { zoom += 1 }
    }

    @IBAction func zoomOutAction(_ sender: NSButton!) {

        if zoom > 1 { zoom -= 1 }
    }

    @IBAction func zoomSliderAction(_ sender: NSSlider!) {

        zoom = sender.doubleValue
    }

    @IBAction func laDisplayModeAction(_ sender: NSPopUpButton!) {

        emu?.set(.LA_MODE, value: sender.selectedTag())
    }
    
    @IBAction func laOpacityAction(_ sender: NSSlider!) {

        emu?.set(.LA_OPACITY, value: sender.integerValue)
    }

    @IBAction func runAction(_ sender: NSButton!) {

        if let emu = emu {
            if emu.running { emu.pause() } else { try? emu.run() }
        }
    }

    @IBAction func finishCycleAction(_ sender: NSButton!) {

        emu?.stepCycle()
    }

    @IBAction func finishLineAction(_ sender: NSButton!) {

        emu?.finishLine()
    }

    @IBAction func finishFrameAction(_ sender: NSButton!) {

        emu?.finishFrame()
    }

    @IBAction func symAction(_ sender: NSButton!) {

        trace0.formatter.symbolic = sender.state == .on
        refresh()
    }

    @IBAction func hexAction(_ sender: NSButton!) {

        trace0.formatter.hex = sender.state == .on
        refresh()
    }
}

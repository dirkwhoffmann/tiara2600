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
    @IBOutlet weak var laLinkButton: NSButton!
    @IBOutlet weak var laLineStepper: NSStepper!

    @IBOutlet weak var laProbe0: NSPopUpButton!
    @IBOutlet weak var laProbe1: NSPopUpButton!
    @IBOutlet weak var laProbe2: NSPopUpButton!
    @IBOutlet weak var laProbe3: NSPopUpButton!

    @IBOutlet weak var laColor0: NSColorWell!
    @IBOutlet weak var laColor1: NSColorWell!
    @IBOutlet weak var laColor2: NSColorWell!
    @IBOutlet weak var laColor3: NSColorWell!

    @IBOutlet weak var laScrollView: NSScrollView!
    @IBOutlet weak var laLogicView: LogicView!
    @IBOutlet weak var laRecordBox: NSBox!
    @IBOutlet weak var laSpinIcon: NSProgressIndicator!

    @IBOutlet weak var laOverlayButtom: NSButton!
    @IBOutlet weak var laOpacity: NSSlider!
    @IBOutlet weak var laDisplayMode: NSPopUpButton!

    @IBOutlet weak var laSymButtom: NSButton!
    @IBOutlet weak var laHexButtom: NSButton!

    @IBOutlet weak var laRunButton: NSButton!
    @IBOutlet weak var laFinishCycleButton: NSButton!
    @IBOutlet weak var laFinishLineButton: NSButton!
    @IBOutlet weak var laFinishFrameButton: NSButton!

    @IBOutlet weak var laTimeStamp: NSTextField!
    @IBOutlet weak var laBeamTrap: NSButton!
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

    // Indicates if the emulator is currently running or paused
    var running = 0

    // Indicates if the displayed scanline is always the current line
    var linked: Bool { return laLinkButton.state == .on }

    // Zoom level
    var zoom = 1.0 {
        didSet {
            let w = laScrollView.frame.size.width * CGFloat(zoom)
            let h = laScrollView.frame.size.height
            laLogicView.setFrameSize(NSSize(width: w, height: h))
        }
    }

    override func awakeFromNib() {

        func initPopup(button: NSPopUpButton) {

            func add(_ title: String, _ probe: Probe) {

                button.addItem(withTitle: title)
                button.lastItem!.tag = probe.rawValue
            }

            button.removeAllItems()
            add("None", .NONE)
            add("Address Bus", .ADDR_BUS)
            add("Data Bus", .DATA_BUS)
            add("Strobe", .STROBE)
            add("PHI1", .PHI1)
            add("PHI2", .PHI2)
            add("RDY", .RDY)
            add("SEC", .SEC)
            add("SECL", .SECL)
            add("HMC", .HMC)
            add("VSYNC", .VSYNC)
            add("VBLANK", .VBLANK)
            add("HBLANK", .HBLANK)
            add("INTIM", .INTIM)
        }

        super.awakeFromNib()

        zoom = 15

        // Initialize colors
        let palette: [NSColor] = [

            NSColor.blue,
            NSColor.red,
            NSColor.green,
            NSColor.yellow
        ]
        laColor0.color = palette[0]; laLogicView.signalColor[0] = palette[0]
        laColor1.color = palette[1]; laLogicView.signalColor[1] = palette[1]
        laColor2.color = palette[2]; laLogicView.signalColor[2] = palette[2]
        laColor3.color = palette[3]; laLogicView.signalColor[3] = palette[3]
        for i in 0..<4 { emu?.logicAnalyzer.setColor(i, color: palette[i]) }

        // Initialize PopUpButtons
        initPopup(button: laProbe0)
        initPopup(button: laProbe1)
        initPopup(button: laProbe2)
        initPopup(button: laProbe3)

        // Assign styles
        laTimeStamp.font = NSFont.monospacedSystemFont(ofSize: 12, weight: .regular)

        // Enable all channels
        emu?.set(.LA_CHANNEL0, enable: true)
        emu?.set(.LA_CHANNEL1, enable: true)
        emu?.set(.LA_CHANNEL2, enable: true)
        emu?.set(.LA_CHANNEL3, enable: true)
    }

    override func showWindow(_ sender: Any?) {

        super.showWindow(self)
        fullRefresh()
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

        let info = emu.tia.info
        let atariInfo = emu.atari.info
        let config = emu.logicAnalyzer.getConfig()
        if emu.running { running += 1 } else { running = 0 }

        if full {

            if running > 0 {

                laRunButton.image = NSImage(named: "pauseTemplate")
                laRunButton.toolTip = "Pause"
                laFinishCycleButton.isEnabled = false
                laFinishLineButton.isEnabled = false
                laFinishFrameButton.isEnabled = false

            } else {

                laRunButton.image = NSImage(named: "runTemplate")
                laRunButton.toolTip = "Run"
                laFinishCycleButton.isEnabled = true
                laFinishLineButton.isEnabled = true
                laFinishFrameButton.isEnabled = true
            }

            // 2D overlay
            laOpacity.integerValue = Int(config.opacity)
        }

        // Probes
        if linked { line = info.posy }
        laLineField.integerValue = line
        laLineField.isEnabled = !linked
        laLineStepper.isEnabled = !linked

        let probe0 = emu.get(.LA_PROBE0)
        let probe1 = emu.get(.LA_PROBE1)
        let probe2 = emu.get(.LA_PROBE2)
        let probe3 = emu.get(.LA_PROBE3)

        laProbe0.selectItem(withTag: probe0)
        laProbe1.selectItem(withTag: probe1)
        laProbe2.selectItem(withTag: probe2)
        laProbe3.selectItem(withTag: probe3)

        // 2D overlay
        laOverlayButtom.state = config.enable ? .on : .off
        laDisplayMode.selectItem(withTag: config.displayMode.rawValue)

        // Bottom bar
        laTimeStamp.stringValue = String(format: "%d:%03d:%03d",
                                         atariInfo.frame, info.posy, info.posx)
        laX.isEnabled = laBeamTrap.state == .on
        laY.isEnabled = laBeamTrap.state == .on
        laSymButtom.state = laLogicView.formatter.symbolic ? .on : .off
        laHexButtom.state = laLogicView.formatter.hex ? .on : .off

        // Trace view
        if running > 1 {

            laLogicView.visible = false
            laRecordBox.isHidden = false
            laSpinIcon.startAnimation(self)
        }

        if running == 0 {

            laLogicView.visible = true
            laRecordBox.isHidden = true
            laSpinIcon.stopAnimation(self)
        }

        laLogicView.probe[0] = Probe(rawValue: probe0)!
        laLogicView.probe[1] = Probe(rawValue: probe1)!
        laLogicView.probe[2] = Probe(rawValue: probe2)!
        laLogicView.probe[3] = Probe(rawValue: probe3)!

        laLogicView.x = info.posx
        laLogicView.y = info.posy
        laLogicView.sof = atariInfo.flags & tiara.RL.SYNC_THREAD != 0

        if linked && running == 0 {

            let pos = (laLogicView.bounds.width / CGFloat(228)) * CGFloat(info.posx + 1)
            let newx = pos - (laScrollView.bounds.width / 2)
            NSAnimationContext.runAnimationGroup({ context in
                context.duration = 0.5
                laScrollView.contentView.animator().setBoundsOrigin(NSPoint(x: newx, y: 0))
            }, completionHandler: nil)
        }

        laLogicView.update()

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

        laTimeStamp.textColor = .labelColor
        fullRefresh()
    }

    func pause() {

        fullRefresh()
    }

    func step() {

        laTimeStamp.textColor = .labelColor
        fullRefresh()
    }

    func reset() {

        fullRefresh()
    }

    func signalBeamtrap() {

        laTimeStamp.textColor = .warning
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

    @IBAction func probeAction(_ sender: NSPopUpButton!) {

        let tag = sender.selectedTag()

        switch sender.tag {
        case 0:  emu?.set(.LA_PROBE0, value: tag)
        case 1:  emu?.set(.LA_PROBE1, value: tag)
        case 2:  emu?.set(.LA_PROBE2, value: tag)
        case 3:  emu?.set(.LA_PROBE3, value: tag)
        default: break
        }
    }

    @IBAction func colorAction(_ sender: NSColorWell!) {

        emu?.logicAnalyzer.setColor(sender.tag, color: sender.color)
        laLogicView.signalColor[sender.tag] = sender.color
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

    @IBAction func overlayAction(_ sender: NSButton!) {

        emu?.set(.LA_ENABLE, enable: sender.state == .on)

        if sender.state == .on {
            parent.renderer.zoomTextureOut()
        } else {
            parent.renderer.zoomTextureIn()
        }
    }

    @IBAction func displayModeAction(_ sender: NSPopUpButton!) {

        emu?.set(.LA_MODE, value: sender.selectedTag())
    }
    
    @IBAction func opacityAction(_ sender: NSSlider!) {

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

    @IBAction func beamtrapAction(_ sender: NSButton!) {

        if sender.state == .on {

            if emu?.beamtraps.count == 0 {

                let pos = laY.integerValue << 16 | laX.integerValue
                try? emu?.beamtraps.set(at: pos)
            }
            try? emu?.beamtraps.enable(nr: 0)

        } else {

            try? emu?.beamtraps.disable(nr: 0)
        }
    }

    @IBAction func beamtrapYAction(_ sender: NSTextField!) {

        let pos = emu?.beamtraps.addr(0) ?? 0
        let x = pos & 0xFFFF
        let y = sender.integerValue

        try? emu?.beamtraps.replace(nr: 0, addr: y << 16 | x)
    }

    @IBAction func beamtrapXAction(_ sender: NSTextField!) {

        let pos = emu?.beamtraps.addr(0) ?? 0
        let x = sender.integerValue
        let y = (pos >> 16) & 0xFFFF

        try? emu?.beamtraps.replace(nr: 0, addr: y << 16 | x)
    }

    @IBAction func symAction(_ sender: NSButton!) {

        laLogicView.formatter.symbolic = sender.state == .on
        refresh()
    }

    @IBAction func hexAction(_ sender: NSButton!) {

        laLogicView.formatter.hex = sender.state == .on
        refresh()
    }
}

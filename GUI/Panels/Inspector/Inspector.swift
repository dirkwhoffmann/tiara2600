// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

// Number formatters
let fmt8b  = MyFormatter(radix: 2, min: 0, max: 0xFF)

let fmt3d  = MyFormatter(radix: 10, min: 0, max: 0x7)
let fmt4d  = MyFormatter(radix: 10, min: 0, max: 0xF)
let fmt6d  = MyFormatter(radix: 10, min: 0, max: 0x3F)
let fmt8d  = MyFormatter(radix: 10, min: 0, max: 0xFF)
let fmt9d  = MyFormatter(radix: 10, min: 0, max: 0x1FF)
let fmt10d = MyFormatter(radix: 10, min: 0, max: 0x3FF)
let fmt12d = MyFormatter(radix: 10, min: 0, max: 0xFFF)
let fmt16d = MyFormatter(radix: 10, min: 0, max: 0xFFFF)

let fmt3x  = MyFormatter(radix: 16, min: 0, max: 0x7)
let fmt4x  = MyFormatter(radix: 16, min: 0, max: 0xF)
let fmt6x  = MyFormatter(radix: 16, min: 0, max: 0x3F)
let fmt8x  = MyFormatter(radix: 16, min: 0, max: 0xFF)
let fmt9x  = MyFormatter(radix: 16, min: 0, max: 0x1FF)
let fmt10x = MyFormatter(radix: 16, min: 0, max: 0x3FF)
let fmt12x = MyFormatter(radix: 16, min: 0, max: 0xFFF)
let fmt16x = MyFormatter(radix: 16, min: 0, max: 0xFFFF)

class Inspector: DialogController {
    
    // Commons
    @IBOutlet weak var panel: NSTabView!
    @IBOutlet weak var stopAndGoButton: NSButton!
    @IBOutlet weak var stepCycleButton: NSButton!
    @IBOutlet weak var stepIntoButton: NSButton!
    @IBOutlet weak var stepOverButton: NSButton!
    @IBOutlet weak var message: NSTextField!
    @IBOutlet weak var hexDecSelector: NSMatrix!
    @IBOutlet weak var timeStamp: NSTextField!

    // CPU panel
    @IBOutlet weak var cpuTab: NSTabView!
    @IBOutlet weak var cpuInstrView: InstrTableView!
    @IBOutlet weak var cpuTraceView: TraceTableView!
    @IBOutlet weak var cpuBreakView: BreakTableView!
    @IBOutlet weak var cpuWatchView: WatchTableView!
    @IBOutlet weak var cpuPc: NSTextField!
    @IBOutlet weak var cpuPcWarning: NSTextField!
    @IBOutlet weak var cpuSp: NSTextField!
    @IBOutlet weak var cpuA: NSTextField!
    @IBOutlet weak var cpuX: NSTextField!
    @IBOutlet weak var cpuY: NSTextField!
    @IBOutlet weak var cpuN: NSButton!
    @IBOutlet weak var cpuZ: NSButton!
    @IBOutlet weak var cpuC: NSButton!
    @IBOutlet weak var cpuI: NSButton!
    @IBOutlet weak var cpuB: NSButton!
    @IBOutlet weak var cpuD: NSButton!
    @IBOutlet weak var cpuV: NSButton!
    @IBOutlet weak var cpuPortReg: NSTextField!
    @IBOutlet weak var cpuPortDir: NSTextField!
    @IBOutlet weak var cpuRdy: NSButton!
    @IBOutlet weak var cpuJam: NSButton!

    // Memory panel
    @IBOutlet weak var memTab: NSTabView!
    @IBOutlet weak var memLayoutButton: NSButton!
    @IBOutlet weak var memLayoutSlider: NSSlider!
    @IBOutlet weak var memRamButton: NSButton!
    @IBOutlet weak var memPIAButton: NSButton!
    @IBOutlet weak var memCartButton: NSButton!
    @IBOutlet weak var memTIAButton: NSButton!
    @IBOutlet weak var memSearchField: NSSearchField!
    @IBOutlet weak var memBankTableView: BankTableView!
    @IBOutlet weak var memTableView: MemTableView!
    @IBOutlet weak var memHeatmapView: HeatmapView!

    var bankType: [Int: tiara.MemoryType] = [:]
    var displayedBank = 0
    var layoutIsDirty = true
    var nextLayoutRefresh = 0

    // PIA panel
    @IBOutlet weak var ciaPRA: NSTextField!
    @IBOutlet weak var ciaPRAbinary: NSTextField!
    @IBOutlet weak var ciaDDRA: NSTextField!
    @IBOutlet weak var ciaDDRAbinary: NSTextField!
    @IBOutlet weak var ciaPA7: NSButton!
    @IBOutlet weak var ciaPA6: NSButton!
    @IBOutlet weak var ciaPA5: NSButton!
    @IBOutlet weak var ciaPA4: NSButton!
    @IBOutlet weak var ciaPA3: NSButton!
    @IBOutlet weak var ciaPA2: NSButton!
    @IBOutlet weak var ciaPA1: NSButton!
    @IBOutlet weak var ciaPA0: NSButton!
    @IBOutlet weak var ciaPRB: NSTextField!
    @IBOutlet weak var ciaPRBbinary: NSTextField!
    @IBOutlet weak var ciaDDRB: NSTextField!
    @IBOutlet weak var ciaDDRBbinary: NSTextField!
    @IBOutlet weak var ciaPB7: NSButton!
    @IBOutlet weak var ciaPB6: NSButton!
    @IBOutlet weak var ciaPB5: NSButton!
    @IBOutlet weak var ciaPB4: NSButton!
    @IBOutlet weak var ciaPB3: NSButton!
    @IBOutlet weak var ciaPB2: NSButton!
    @IBOutlet weak var ciaPB1: NSButton!
    @IBOutlet weak var ciaPB0: NSButton!
    @IBOutlet weak var ciaTA: NSTextField!
    @IBOutlet weak var ciaTAlatch: NSTextField!
    @IBOutlet weak var ciaTArunning: NSButton!
    @IBOutlet weak var ciaTAtoggle: NSButton!
    @IBOutlet weak var ciaTApbout: NSButton!
    @IBOutlet weak var ciaTAoneShot: NSButton!
    @IBOutlet weak var ciaTB: NSTextField!
    @IBOutlet weak var ciaTBlatch: NSTextField!
    @IBOutlet weak var ciaTBrunning: NSButton!
    @IBOutlet weak var ciaTBtoggle: NSButton!
    @IBOutlet weak var ciaTBpbout: NSButton!
    @IBOutlet weak var ciaTBoneShot: NSButton!
    @IBOutlet weak var ciaICR: NSTextField!
    @IBOutlet weak var ciaICRbinary: NSTextField!
    @IBOutlet weak var ciaIMR: NSTextField!
    @IBOutlet weak var ciaIMRbinary: NSTextField!
    @IBOutlet weak var ciaIntLineLow: NSButton!
    @IBOutlet weak var ciaTodHours: NSTextField!
    @IBOutlet weak var ciaTodMinutes: NSTextField!
    @IBOutlet weak var ciaTodSeconds: NSTextField!
    @IBOutlet weak var ciaTodTenth: NSTextField!
    @IBOutlet weak var ciaAlarmHours: NSTextField!
    @IBOutlet weak var ciaAlarmMinutes: NSTextField!
    @IBOutlet weak var ciaAlarmSeconds: NSTextField!
    @IBOutlet weak var ciaTodIntEnable: NSButton!
    @IBOutlet weak var ciaAlarmTenth: NSTextField!
    @IBOutlet weak var ciaSDR: NSTextField!
    @IBOutlet weak var ciaSSR: NSTextField!
    @IBOutlet weak var ciaSSRbinary: NSTextField!
    @IBOutlet weak var ciaIdleCycles: NSTextField!
    @IBOutlet weak var ciaIdleLevelText: NSTextField!
    @IBOutlet weak var ciaIdleLevel: NSLevelIndicator!
    
    // TIA panel
    @IBOutlet weak var tiaPalette: NSButton!
    @IBOutlet weak var tiaCOLUP0: NSTextField!
    @IBOutlet weak var tiaCOLUP1: NSTextField!
    @IBOutlet weak var tiaCOLUPF: NSTextField!
    @IBOutlet weak var tiaCOLUBK: NSTextField!
    @IBOutlet weak var tiaColorWell0: NSColorWell!
    @IBOutlet weak var tiaColorWell1: NSColorWell!
    @IBOutlet weak var tiaColorWell2: NSColorWell!
    @IBOutlet weak var tiaColorWell3: NSColorWell!

    @IBOutlet weak var vicScanline: NSTextField!
    @IBOutlet weak var vicRasterCycle: NSTextField!
    @IBOutlet weak var vicYCounter: NSTextField!
    @IBOutlet weak var vicXCounter: NSTextField!
    @IBOutlet weak var vicVC: NSTextField!
    @IBOutlet weak var vicVCBase: NSTextField!
    @IBOutlet weak var vicRC: NSTextField!
    @IBOutlet weak var vicVMLI: NSTextField!
    @IBOutlet weak var vicCtrl1: NSTextField!
    @IBOutlet weak var vicCtrl2: NSTextField!
    @IBOutlet weak var vicDy: NSTextField!
    @IBOutlet weak var vicDx: NSTextField!
    @IBOutlet weak var vicBadLine: NSButton!
    @IBOutlet weak var vicDisplayState: NSButton!
    @IBOutlet weak var vicVBlank: NSButton!
    @IBOutlet weak var vicScreenGeometry: NSPopUpButton!
    @IBOutlet weak var vicDisplayMode: NSPopUpButton!
    @IBOutlet weak var vicBorderColor: NSColorWell!
    @IBOutlet weak var vicBgColor0: NSColorWell!
    @IBOutlet weak var vicBgColor1: NSColorWell!
    @IBOutlet weak var vicBgColor2: NSColorWell!
    @IBOutlet weak var vicBgColor3: NSColorWell!
    @IBOutlet weak var vicMemSelect: NSTextField!
    @IBOutlet weak var vicUltimax: NSButton!
    @IBOutlet weak var vicMemoryBankAddr: NSPopUpButton!
    @IBOutlet weak var vicScreenMemoryAddr: NSPopUpButton!
    @IBOutlet weak var vicCharMemoryAddr: NSPopUpButton!
    @IBOutlet weak var vicIrqRasterline: NSTextField!
    @IBOutlet weak var vicImr: NSTextField!
    @IBOutlet weak var vicImrLP: NSButton!
    @IBOutlet weak var vicImrSS: NSButton!
    @IBOutlet weak var vicImrSB: NSButton!
    @IBOutlet weak var vicImrRaster: NSButton!
    @IBOutlet weak var vicIrr: NSTextField!
    @IBOutlet weak var vicIrrIrq: NSButton!
    @IBOutlet weak var vicIrrLP: NSButton!
    @IBOutlet weak var vicIrrSS: NSButton!
    @IBOutlet weak var vicIrrSB: NSButton!
    @IBOutlet weak var vicIrrRaster: NSButton!
    @IBOutlet weak var latchedLPX: NSTextField!
    @IBOutlet weak var latchedLPY: NSTextField!
    @IBOutlet weak var vicLpLine: NSButton!
    @IBOutlet weak var vicLpIrqHasOccurred: NSButton!
    
    @IBOutlet weak var sprSelector: NSSegmentedControl!
    @IBOutlet weak var sprX: NSTextField!
    @IBOutlet weak var sprY: NSTextField!
    @IBOutlet weak var sprEnabled: NSButton!
    @IBOutlet weak var sprExpandX: NSButton!
    @IBOutlet weak var sprExpandY: NSButton!
    @IBOutlet weak var sprPriority: NSButton!
    @IBOutlet weak var sprMulticolor: NSButton!
    @IBOutlet weak var sprSSCollision: NSButton!
    @IBOutlet weak var sprSBCollision: NSButton!
    @IBOutlet weak var sprColor: NSColorWell!
    @IBOutlet weak var sprExtra1: NSColorWell!
    @IBOutlet weak var sprExtra2: NSColorWell!

    // SID panel
    @IBOutlet weak var sidSelector: NSSegmentedControl!
    @IBOutlet weak var sidWaveform1: NSPopUpButton!
    @IBOutlet weak var sidFrequency1: NSTextField!
    @IBOutlet weak var sidPulseWidth1: NSTextField!
    @IBOutlet weak var sidPulseWidthText1: NSTextField!
    @IBOutlet weak var sidAttackRate1: NSTextField!
    @IBOutlet weak var sidDecayRate1: NSTextField!
    @IBOutlet weak var sidSustainRate1: NSTextField!
    @IBOutlet weak var sidReleaseRate1: NSTextField!
    @IBOutlet weak var sidGateBit1: NSButton!
    @IBOutlet weak var sidTestBit1: NSButton!
    @IBOutlet weak var sidSyncBit1: NSButton!
    @IBOutlet weak var sidRingBit1: NSButton!
    
    @IBOutlet weak var sidWaveform2: NSPopUpButton!
    @IBOutlet weak var sidFrequency2: NSTextField!
    @IBOutlet weak var sidPulseWidth2: NSTextField!
    @IBOutlet weak var sidPulseWidthText2: NSTextField!
    @IBOutlet weak var sidAttackRate2: NSTextField!
    @IBOutlet weak var sidDecayRate2: NSTextField!
    @IBOutlet weak var sidSustainRate2: NSTextField!
    @IBOutlet weak var sidReleaseRate2: NSTextField!
    @IBOutlet weak var sidGateBit2: NSButton!
    @IBOutlet weak var sidTestBit2: NSButton!
    @IBOutlet weak var sidSyncBit2: NSButton!
    @IBOutlet weak var sidRingBit2: NSButton!
    
    @IBOutlet weak var sidWaveform3: NSPopUpButton!
    @IBOutlet weak var sidFrequency3: NSTextField!
    @IBOutlet weak var sidPulseWidth3: NSTextField!
    @IBOutlet weak var sidPulseWidthText3: NSTextField!
    @IBOutlet weak var sidAttackRate3: NSTextField!
    @IBOutlet weak var sidDecayRate3: NSTextField!
    @IBOutlet weak var sidSustainRate3: NSTextField!
    @IBOutlet weak var sidReleaseRate3: NSTextField!
    @IBOutlet weak var sidGateBit3: NSButton!
    @IBOutlet weak var sidTestBit3: NSButton!
    @IBOutlet weak var sidSyncBit3: NSButton!
    @IBOutlet weak var sidRingBit3: NSButton!
    
    @IBOutlet weak var sidVolume: NSTextField!
    @IBOutlet weak var sidPotX: NSTextField!
    @IBOutlet weak var sidPotY: NSTextField!

    @IBOutlet weak var sidFilterType: NSPopUpButton!
    @IBOutlet weak var sidFilterCutoff: NSTextField!
    @IBOutlet weak var sidFilterResonance: NSTextField!
    @IBOutlet weak var sidFilter1: NSButton!
    @IBOutlet weak var sidFilter2: NSButton!
    @IBOutlet weak var sidFilter3: NSButton!
    
    @IBOutlet weak var sidWaveformView: WaveformView!
    @IBOutlet weak var sidWaveformSource: NSPopUpButton!
    @IBOutlet weak var sidAudioBufferLevel: NSLevelIndicator!
    @IBOutlet weak var sidAudioBufferLevelText: NSTextField!
    @IBOutlet weak var sidBufferUnderflows: NSTextField!
    @IBOutlet weak var sidBufferOverflows: NSTextField!

    // Events panel
    @IBOutlet weak var evCpuProgress: NSTextField!
    @IBOutlet weak var evVicProgress: NSTextField!
    @IBOutlet weak var evTableView: EventTableView!

    // Cached state of all C64 components
    var cpuInfo: tiara.CPUInfo!
    var piaInfo: tiara.PIAInfo!
    var piaStats: tiara.PIAStats!
    var memInfo: tiara.MemInfo!
    var tiaInfo: tiara.TIAInfo!
    var eventInfo: tiara.AtariInfo!
    var isRunning = true
    
    // Number format selection (hexadecimal or decimal)
    var hex = true
    var fmt3: MyFormatter { return hex ? fmt3x : fmt3d }
    var fmt4: MyFormatter { return hex ? fmt4x : fmt4d }
    var fmt6: MyFormatter { return hex ? fmt6x : fmt6d }
    var fmt8: MyFormatter { return hex ? fmt8x : fmt8d }
    var fmt9: MyFormatter { return hex ? fmt9x : fmt9d }
    var fmt10: MyFormatter { return hex ? fmt10x : fmt10d }
    var fmt12: MyFormatter { return hex ? fmt12x : fmt12d }
    var fmt16: MyFormatter { return hex ? fmt16x : fmt16d }

    // Refresh counter
    var refreshCnt = 0
        
    override func showWindow(_ sender: Any?) {

        super.showWindow(self)

        // Enter debug mode
        emu?.trackOn()
        emu?.set(.MEM_HEATMAP, enable: true)
        updateInspectionTarget()
    }
        
    func fullRefresh() {
        
        refresh(full: true)
    }
    
    func continuousRefresh() {
        
        if isRunning { refresh(count: refreshCnt) }
        isRunning = emu?.running ?? false
        refreshCnt += 1
    }
    
    func refresh(count: Int = 0, full: Bool = false) {
        
        if window?.isVisible == false { return }
        
        if full {

            if emu?.running ?? false {

                stopAndGoButton.image = NSImage(named: "pauseTemplate")
                stopAndGoButton.toolTip = "Pause"
                stepCycleButton.isEnabled = false
                stepIntoButton.isEnabled = false
                stepOverButton.isEnabled = false

            } else {

                stopAndGoButton.image = NSImage(named: "runTemplate")
                stopAndGoButton.toolTip = "Run"
                stepCycleButton.isEnabled = true
                stepIntoButton.isEnabled = true
                stepOverButton.isEnabled = true
            }

            timeStamp.font = NSFont.monospacedSystemFont(ofSize: 12, weight: .regular)
        }

        if let info = emu?.tia.info {
            timeStamp.stringValue = String(format: "%d:%03d:%03d",
                                           info.frame, info.posy, info.posx)
        }

        if let id = panel.selectedTabViewItem?.label {

            switch id {
                
            case "CPU": refreshCPU(count: count, full: full)
            case "PIA": refreshPIA(count: count, full: full)
            case "Memory": refreshMemory(count: count, full: full)
            case "TIA": refreshTIA(count: count, full: full)
            case "SID": refreshSID(count: count, full: full)
            case "Events": refreshEvents(count: count, full: full)

            default:
                break
            }
        }
    }
    
    func scrollToPC() {

        if cpuInfo != nil {
            scrollToPC(pc: Int(cpuInfo.pc0))
        }
    }

    func scrollToPC(pc: Int) {

        cpuInstrView.jumpTo(addr: pc)
    }

    func powerOn() {
    
        message.stringValue = ""
        fullRefresh()
    }

    func powerOff() {
    
        message.stringValue = ""
        fullRefresh()
    }

    func run() {
        
        message.stringValue = ""
        cpuInstrView.alertAddr = nil
        fullRefresh()
    }
    
    func pause() {
        
        fullRefresh()
    }

    func step() {

        message.stringValue = ""
        cpuInstrView.alertAddr = nil
        fullRefresh()
        scrollToPC()
    }
    
    func reset() {
        
        message.stringValue = ""
        cpuInstrView.alertAddr = nil
        fullRefresh()
    }

    func signalBreakPoint(pc: Int) {

        message.stringValue = String(format: "Breakpoint reached")
        cpuInstrView.alertAddr = nil
        scrollToPC(pc: pc)
    }

    func signalWatchPoint(pc: Int) {
    
        message.stringValue = String(format: "Watchpoint reached")
        cpuInstrView.alertAddr = pc
        scrollToPC(pc: pc)
    }

    func signalGoto(pc: Int) {

        if isRunning { return }

        let addr = String(format: (hex ? "$%04X" : "%d"), pc)
        message.stringValue = String(format: "Program counter redirected to " + addr)
        fullRefresh()
        scrollToPC()
    }

    @IBAction func refreshAction(_ sender: NSButton!) {

        refresh()
    }

    @IBAction func stopAndGoAction(_ sender: NSButton!) {

        if let emu = emu {
            if emu.running { emu.pause() } else { try? emu.run() }
        }
    }

    @IBAction func stepCycleAction(_ sender: NSButton!) {

        emu?.stepCycle()
    }

    @IBAction func stepIntoAction(_ sender: NSButton!) {

        emu?.stepInto()
    }
    
    @IBAction func stepOverAction(_ sender: NSButton!) {

        emu?.stepOver()
    }
    
    @IBAction func hexAction(_ sender: NSButtonCell!) {
        
        hex = true
        refresh(full: true)
    }

    @IBAction func decAction(_ sender: NSButtonCell!) {
        
        hex = false
        refresh(full: true)
    }
}

extension Inspector {
    
    override func windowWillClose(_ notification: Notification) {
                
        super.windowWillClose(notification)

        if let emu = emu {

            // Leave debug mode
            emu.trackOff()
            emu.set(.MEM_HEATMAP, enable: false)
            emu.atari.autoInspectionMask = 0
        }
    }
}

extension Inspector: NSTabViewDelegate {
    
    func updateInspectionTarget() {

        func mask(_ types: [CType]) -> Int {

            var result = 0
            for type in types { result = result | 1 << type.rawValue }
            return result
        }
        func mask(_ type: CType) -> Int { return mask([type]) }

        if let id = panel.selectedTabViewItem?.label {
                    
            switch id {
                
            case "CPU":     c64?.autoInspectionMask = mask([.CPUClass])
            case "Memory":  c64?.autoInspectionMask = mask([.MemoryClass])
            case "PIA":     c64?.autoInspectionMask = mask([.PIAClass])
            case "TIA":     c64?.autoInspectionMask = mask([.TIAClass])
            // case "SID":     c64?.autoInspectionMask = mask([.SIDClass])
            case "Events":  c64?.autoInspectionMask = mask([.AtariClass])

            default:
                break
            }
            
            fullRefresh()
        }
    }
    
    func tabView(_ tabView: NSTabView, didSelect tabViewItem: NSTabViewItem?) {

        if tabView === panel {
            updateInspectionTarget()
        }
        
        if tabView === cpuTab {
            cpuInstrView.refresh(full: true)
            cpuTraceView.refresh(full: true)
        }
    }
}

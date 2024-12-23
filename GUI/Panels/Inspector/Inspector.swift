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

    var bankType: [Int: MemoryType] = [:]
    var displayedBank = 0
    var layoutIsDirty = true
    var nextLayoutRefresh = 0

    // PIA panel (Port A)
    @IBOutlet weak var piaPRA: NSTextField!
    @IBOutlet weak var piaPRAbinary: NSTextField!
    @IBOutlet weak var piaPRA7: NSButton!
    @IBOutlet weak var piaPRA6: NSButton!
    @IBOutlet weak var piaPRA5: NSButton!
    @IBOutlet weak var piaPRA4: NSButton!
    @IBOutlet weak var piaPRA3: NSButton!
    @IBOutlet weak var piaPRA2: NSButton!
    @IBOutlet weak var piaPRA1: NSButton!
    @IBOutlet weak var piaPRA0: NSButton!

    @IBOutlet weak var piaDDRA: NSTextField!
    @IBOutlet weak var piaDDRAbinary: NSTextField!
    @IBOutlet weak var piaDDRA7I: NSTextField!
    @IBOutlet weak var piaDDRA6I: NSTextField!
    @IBOutlet weak var piaDDRA5I: NSTextField!
    @IBOutlet weak var piaDDRA4I: NSTextField!
    @IBOutlet weak var piaDDRA3I: NSTextField!
    @IBOutlet weak var piaDDRA2I: NSTextField!
    @IBOutlet weak var piaDDRA1I: NSTextField!
    @IBOutlet weak var piaDDRA0I: NSTextField!
    @IBOutlet weak var piaDDRA7O: NSTextField!
    @IBOutlet weak var piaDDRA6O: NSTextField!
    @IBOutlet weak var piaDDRA5O: NSTextField!
    @IBOutlet weak var piaDDRA4O: NSTextField!
    @IBOutlet weak var piaDDRA3O: NSTextField!
    @IBOutlet weak var piaDDRA2O: NSTextField!
    @IBOutlet weak var piaDDRA1O: NSTextField!
    @IBOutlet weak var piaDDRA0O: NSTextField!

    @IBOutlet weak var piaEXTA: NSTextField!
    @IBOutlet weak var piaEXTAbinary: NSTextField!
    @IBOutlet weak var piaEXTA7: NSButton!
    @IBOutlet weak var piaEXTA6: NSButton!
    @IBOutlet weak var piaEXTA5: NSButton!
    @IBOutlet weak var piaEXTA4: NSButton!
    @IBOutlet weak var piaEXTA3: NSButton!
    @IBOutlet weak var piaEXTA2: NSButton!
    @IBOutlet weak var piaEXTA1: NSButton!
    @IBOutlet weak var piaEXTA0: NSButton!

    @IBOutlet weak var piaPA7: NSButton!
    @IBOutlet weak var piaPA6: NSButton!
    @IBOutlet weak var piaPA5: NSButton!
    @IBOutlet weak var piaPA4: NSButton!
    @IBOutlet weak var piaPA3: NSButton!
    @IBOutlet weak var piaPA2: NSButton!
    @IBOutlet weak var piaPA1: NSButton!
    @IBOutlet weak var piaPA0: NSButton!

    // PIA (Port B)
    @IBOutlet weak var piaPRB: NSTextField!
    @IBOutlet weak var piaPRBbinary: NSTextField!
    @IBOutlet weak var piaPRB7: NSButton!
    @IBOutlet weak var piaPRB6: NSButton!
    @IBOutlet weak var piaPRB5: NSButton!
    @IBOutlet weak var piaPRB4: NSButton!
    @IBOutlet weak var piaPRB3: NSButton!
    @IBOutlet weak var piaPRB2: NSButton!
    @IBOutlet weak var piaPRB1: NSButton!
    @IBOutlet weak var piaPRB0: NSButton!

    @IBOutlet weak var piaDDRB: NSTextField!
    @IBOutlet weak var piaDDRBbinary: NSTextField!
    @IBOutlet weak var piaDDRB7I: NSTextField!
    @IBOutlet weak var piaDDRB6I: NSTextField!
    @IBOutlet weak var piaDDRB5I: NSTextField!
    @IBOutlet weak var piaDDRB4I: NSTextField!
    @IBOutlet weak var piaDDRB3I: NSTextField!
    @IBOutlet weak var piaDDRB2I: NSTextField!
    @IBOutlet weak var piaDDRB1I: NSTextField!
    @IBOutlet weak var piaDDRB0I: NSTextField!
    @IBOutlet weak var piaDDRB7O: NSTextField!
    @IBOutlet weak var piaDDRB6O: NSTextField!
    @IBOutlet weak var piaDDRB5O: NSTextField!
    @IBOutlet weak var piaDDRB4O: NSTextField!
    @IBOutlet weak var piaDDRB3O: NSTextField!
    @IBOutlet weak var piaDDRB2O: NSTextField!
    @IBOutlet weak var piaDDRB1O: NSTextField!
    @IBOutlet weak var piaDDRB0O: NSTextField!

    @IBOutlet weak var piaEXTB: NSTextField!
    @IBOutlet weak var piaEXTBbinary: NSTextField!
    @IBOutlet weak var piaEXTB7: NSButton!
    @IBOutlet weak var piaEXTB6: NSButton!
    @IBOutlet weak var piaEXTB5: NSButton!
    @IBOutlet weak var piaEXTB4: NSButton!
    @IBOutlet weak var piaEXTB3: NSButton!
    @IBOutlet weak var piaEXTB2: NSButton!
    @IBOutlet weak var piaEXTB1: NSButton!
    @IBOutlet weak var piaEXTB0: NSButton!

    @IBOutlet weak var piaPB7: NSButton!
    @IBOutlet weak var piaPB6: NSButton!
    @IBOutlet weak var piaPB5: NSButton!
    @IBOutlet weak var piaPB4: NSButton!
    @IBOutlet weak var piaPB3: NSButton!
    @IBOutlet weak var piaPB2: NSButton!
    @IBOutlet weak var piaPB1: NSButton!
    @IBOutlet weak var piaPB0: NSButton!

    // PIA (Counters)
    @IBOutlet weak var piaCounter: NSTextField!
    @IBOutlet weak var piaINTIM: NSTextField!
    @IBOutlet weak var piaTIM1T: NSButton!
    @IBOutlet weak var piaTIM8T: NSButton!
    @IBOutlet weak var piaTIM64T: NSButton!
    @IBOutlet weak var piaT1024T: NSButton!

    // PIA (Interrupts)
    @IBOutlet weak var piaINTENA: NSTextField!
    @IBOutlet weak var piaINSTAT: NSTextField!
    @IBOutlet weak var piaTimerEna: NSButton!
    @IBOutlet weak var piaPA7Ena: NSButton!
    @IBOutlet weak var piaTimerStat: NSButton!
    @IBOutlet weak var piaPA7Stat: NSButton!

    // TIA panel (Registers)
    @IBOutlet weak var tiaCOLUP0: NSTextField!
    @IBOutlet weak var tiaCOLUP0lock: NSButton!
    @IBOutlet weak var tiaCOLUP0Popup: NSPopUpButton!
    @IBOutlet weak var tiaCOLUP1: NSTextField!
    @IBOutlet weak var tiaCOLUP1lock: NSButton!
    @IBOutlet weak var tiaCOLUP1Popup: NSPopUpButton!
    @IBOutlet weak var tiaCOLUPF: NSTextField!
    @IBOutlet weak var tiaCOLUPFlock: NSButton!
    @IBOutlet weak var tiaCOLUPFPopup: NSPopUpButton!
    @IBOutlet weak var tiaCOLUBK: NSTextField!
    @IBOutlet weak var tiaCOLUBKlock: NSButton!
    @IBOutlet weak var tiaCOLUBKPopup: NSPopUpButton!
    @IBOutlet weak var tiaCX: NSTextField!
    @IBOutlet weak var tiaCXlock: NSButton!
    @IBOutlet weak var tiaINP: NSTextField!
    @IBOutlet weak var tiaINPlock: NSButton!

    @IBOutlet weak var tiaVSYNC: NSTextField!
    @IBOutlet weak var tiaVSYNClock: NSButton!
    @IBOutlet weak var tiaVBLANK: NSTextField!
    @IBOutlet weak var tiaVBLANKlock: NSButton!
    @IBOutlet weak var tiaPF0: NSTextField!
    @IBOutlet weak var tiaPF0lock: NSButton!
    @IBOutlet weak var tiaPF1: NSTextField!
    @IBOutlet weak var tiaPF1lock: NSButton!
    @IBOutlet weak var tiaPF2: NSTextField!
    @IBOutlet weak var tiaPF2lock: NSButton!
    @IBOutlet weak var tiaCTRLPF: NSTextField!
    @IBOutlet weak var tiaCTRLPFlock: NSButton!

    @IBOutlet weak var tiaENABL: NSTextField!
    @IBOutlet weak var tiaENABLlock: NSButton!
    @IBOutlet weak var tiaHMBL: NSTextField!
    @IBOutlet weak var tiaHMBLlock: NSButton!
    @IBOutlet weak var tiaVDELBL: NSTextField!
    @IBOutlet weak var tiaVDELBLlock: NSButton!

    @IBOutlet weak var tiaGRP0: NSTextField!
    @IBOutlet weak var tiaGRP0lock: NSButton!
    @IBOutlet weak var tiaREFP0: NSTextField!
    @IBOutlet weak var tiaREFP0lock: NSButton!
    @IBOutlet weak var tiaNUSIZ0: NSTextField!
    @IBOutlet weak var tiaNUSIZ0lock: NSButton!
    @IBOutlet weak var tiaVDELP0: NSTextField!
    @IBOutlet weak var tiaVDELP0lock: NSButton!
    @IBOutlet weak var tiaHMP0: NSTextField!
    @IBOutlet weak var tiaHMP0lock: NSButton!

    @IBOutlet weak var tiaENAM0: NSTextField!
    @IBOutlet weak var tiaENAM0lock: NSButton!
    @IBOutlet weak var tiaHMM0: NSTextField!
    @IBOutlet weak var tiaHMM0lock: NSButton!
    @IBOutlet weak var tiaRESMP0: NSTextField!
    @IBOutlet weak var tiaRESMP0lock: NSButton!

    @IBOutlet weak var tiaGRP1: NSTextField!
    @IBOutlet weak var tiaGRP1lock: NSButton!
    @IBOutlet weak var tiaREFP1: NSTextField!
    @IBOutlet weak var tiaREFP1lock: NSButton!
    @IBOutlet weak var tiaNUSIZ1: NSTextField!
    @IBOutlet weak var tiaNUSIZ1lock: NSButton!
    @IBOutlet weak var tiaVDELP1: NSTextField!
    @IBOutlet weak var tiaVDELP1lock: NSButton!
    @IBOutlet weak var tiaHMP1: NSTextField!
    @IBOutlet weak var tiaHMP1lock: NSButton!

    @IBOutlet weak var tiaENAM1: NSTextField!
    @IBOutlet weak var tiaENAM1lock: NSButton!
    @IBOutlet weak var tiaHMM1: NSTextField!
    @IBOutlet weak var tiaHMM1lock: NSButton!
    @IBOutlet weak var tiaRESMP1: NSTextField!
    @IBOutlet weak var tiaRESMP1lock: NSButton!

    @IBOutlet weak var tiaCXCLR: NSButton!
    @IBOutlet weak var tiaWSYNC: NSButton!
    @IBOutlet weak var tiaRSYNC: NSButton!
    @IBOutlet weak var tiaHMOVE: NSButton!
    @IBOutlet weak var tiaHMCLR: NSButton!
    @IBOutlet weak var tiaRESBL: NSButton!
    @IBOutlet weak var tiaRESP0: NSButton!
    @IBOutlet weak var tiaRESM0: NSButton!
    @IBOutlet weak var tiaRESP1: NSButton!
    @IBOutlet weak var tiaRESM1: NSButton!

    // Audio panel
    @IBOutlet weak var aud0AUDV: NSTextField!
    @IBOutlet weak var aud0AUDF: NSTextField!
    @IBOutlet weak var aud0AUDC: NSTextField!
    @IBOutlet weak var aud0Poly40: NSTextField!
    @IBOutlet weak var aud0Poly41: NSTextField!
    @IBOutlet weak var aud0Poly42: NSTextField!
    @IBOutlet weak var aud0Poly43: NSTextField!
    @IBOutlet weak var aud0Poly50: NSTextField!
    @IBOutlet weak var aud0Poly51: NSTextField!
    @IBOutlet weak var aud0Poly52: NSTextField!
    @IBOutlet weak var aud0Poly53: NSTextField!
    @IBOutlet weak var aud0Poly54: NSTextField!

    @IBOutlet weak var aud1AUDV: NSTextField!
    @IBOutlet weak var aud1AUDF: NSTextField!
    @IBOutlet weak var aud1AUDC: NSTextField!
    @IBOutlet weak var aud1Poly40: NSTextField!
    @IBOutlet weak var aud1Poly41: NSTextField!
    @IBOutlet weak var aud1Poly42: NSTextField!
    @IBOutlet weak var aud1Poly43: NSTextField!
    @IBOutlet weak var aud1Poly50: NSTextField!
    @IBOutlet weak var aud1Poly51: NSTextField!
    @IBOutlet weak var aud1Poly52: NSTextField!
    @IBOutlet weak var aud1Poly53: NSTextField!
    @IBOutlet weak var aud1Poly54: NSTextField!

    @IBOutlet weak var aud0WaveformView: WaveformView!
    @IBOutlet weak var aud1WaveformView: WaveformView!

    @IBOutlet weak var sidWaveformSource: NSPopUpButton!
    @IBOutlet weak var sidAudioBufferLevel: NSLevelIndicator!
    @IBOutlet weak var sidAudioBufferLevelText: NSTextField!
    @IBOutlet weak var sidBufferUnderflows: NSTextField!
    @IBOutlet weak var sidBufferOverflows: NSTextField!

    // Events panel
    @IBOutlet weak var evCpuProgress: NSTextField!
    @IBOutlet weak var evVicProgress: NSTextField!
    @IBOutlet weak var evTableView: EventTableView!

    // Cached state of all Atari components
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

        let tiaInfo = emu!.tia.info
        let atariInfo = emu!.atari.info

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

        timeStamp.stringValue = String(format: "%d:%03d:%03d",
                                       atariInfo.frame, tiaInfo.posy, tiaInfo.posx)

        if let id = panel.selectedTabViewItem?.label {

            switch id {
                
            case "CPU": refreshCPU(count: count, full: full)
            case "Memory": refreshMemory(count: count, full: full)
            case "TIA": refreshTIA(count: count, full: full)
            case "PIA": refreshPIA(count: count, full: full)
            case "Audio": refreshSID(count: count, full: full)
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
                
            case "CPU":     atari?.autoInspectionMask = mask([.CPUClass])
            case "Memory":  atari?.autoInspectionMask = mask([.MemoryClass])
            case "PIA":     atari?.autoInspectionMask = mask([.PIAClass])
            case "TIA":     atari?.autoInspectionMask = mask([.TIAClass])
            case "Audio":   atari?.autoInspectionMask = mask([.AudioClass])
            case "Events":  atari?.autoInspectionMask = mask([.AtariClass])

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

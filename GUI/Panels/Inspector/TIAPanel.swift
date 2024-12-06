// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension Inspector {

    private func cacheTIA() {

        if let emu = emu {

            tiaInfo = emu.paused ? emu.tia.info : emu.tia.cachedInfo
        }
    }
    
    func refreshTIA(count: Int = 0, full: Bool = false) {

        cacheTIA()

        let mask = emu!.get(.TIA_REG_LOCK)

        func lock(_ obj: NSButton, reg: TIARegister) {

            let locked = mask & (1 << reg.rawValue) != 0

            obj.image = locked ?
            NSImage(named: NSImage.lockLockedTemplateName) :
            NSImage(named: NSImage.lockUnlockedTemplateName)
        }

        func solidImage(size: NSSize, color: NSColor) -> NSImage {

            let image = NSImage(size: size)

            image.lockFocus()
            color.setFill()
            // let rect = NSRect(origin: .zero, size: size)
            NSRect(origin: .zero, size: size).fill()
            image.unlockFocus()

            return image
        }

        if full {

            func add(_ tag: Int, color: NSColor) {

                let img = solidImage(size: NSSize(width: 32, height: 16), color: color)

                tiaCOLUBKPopup.addItem(withTitle: "")
                tiaCOLUBKPopup.lastItem!.tag = tag
                tiaCOLUBKPopup.lastItem!.image = img
                tiaCOLUPFPopup.addItem(withTitle: "")
                tiaCOLUPFPopup.lastItem!.tag = tag
                tiaCOLUPFPopup.lastItem!.image = img
                tiaCOLUP0Popup.addItem(withTitle: "")
                tiaCOLUP0Popup.lastItem!.tag = tag
                tiaCOLUP0Popup.lastItem!.image = img
                tiaCOLUP1Popup.addItem(withTitle: "")
                tiaCOLUP1Popup.lastItem!.tag = tag
                tiaCOLUP1Popup.lastItem!.image = img
            }

            tiaCOLUBKPopup.removeAllItems()
            tiaCOLUPFPopup.removeAllItems()
            tiaCOLUP0Popup.removeAllItems()
            tiaCOLUP1Popup.removeAllItems()

            for i in 0...127 {
                add(i, color: emu!.tia.color(i)!)
            }

            tiaVSYNC.assignFormatter(fmt8)
            tiaVBLANK.assignFormatter(fmt8)
            tiaWSYNC.assignFormatter(fmt8)
            tiaRSYNC.assignFormatter(fmt8)
            tiaNUSIZ0.assignFormatter(fmt8)
            tiaNUSIZ1.assignFormatter(fmt8)
            tiaCOLUP0.assignFormatter(fmt8)
            tiaCOLUP1.assignFormatter(fmt8)
            tiaCOLUPF.assignFormatter(fmt8)
            tiaCOLUBK.assignFormatter(fmt8)
            tiaCTRLPF.assignFormatter(fmt8)
            tiaREFP0.assignFormatter(fmt8)
            tiaREFP1.assignFormatter(fmt8)
            tiaPF0.assignFormatter(fmt8)
            tiaPF1.assignFormatter(fmt8)
            tiaPF2.assignFormatter(fmt8)
            tiaRESP0.assignFormatter(fmt8)
            tiaRESP1.assignFormatter(fmt8)
            tiaRESM0.assignFormatter(fmt8)
            tiaRESM1.assignFormatter(fmt8)
            tiaRESBL.assignFormatter(fmt8)
            tiaGRP0.assignFormatter(fmt8)
            tiaGRP1.assignFormatter(fmt8)
            tiaENAM0.assignFormatter(fmt8)
            tiaENAM1.assignFormatter(fmt8)
            tiaENABL.assignFormatter(fmt8)
            tiaHMP0.assignFormatter(fmt8)
            tiaHMP1.assignFormatter(fmt8)
            tiaHMM0.assignFormatter(fmt8)
            tiaHMM1.assignFormatter(fmt8)
            tiaHMBL.assignFormatter(fmt8)
            tiaVDELP0.assignFormatter(fmt8)
            tiaVDELP1.assignFormatter(fmt8)
            tiaVDELBL.assignFormatter(fmt8)
            tiaRESMP0.assignFormatter(fmt8)
            tiaRESMP1.assignFormatter(fmt8)
            tiaHMOVE.assignFormatter(fmt8)
            tiaHMCLR.assignFormatter(fmt8)
            tiaCXCLR.assignFormatter(fmt8)
        }

        tiaVSYNC.integerValue = Int(tiaInfo.regs.0)
        tiaVBLANK.integerValue = Int(tiaInfo.regs.1)
        tiaWSYNC.integerValue = Int(tiaInfo.regs.2)
        tiaRSYNC.integerValue = Int(tiaInfo.regs.3)
        tiaNUSIZ0.integerValue = Int(tiaInfo.regs.4)
        tiaNUSIZ1.integerValue = Int(tiaInfo.regs.5)
        tiaCOLUP0.integerValue = Int(tiaInfo.regs.6)
        tiaCOLUP1.integerValue = Int(tiaInfo.regs.7)
        tiaCOLUPF.integerValue = Int(tiaInfo.regs.8)
        tiaCOLUBK.integerValue = Int(tiaInfo.regs.9)
        tiaCTRLPF.integerValue = Int(tiaInfo.regs.10)
        tiaREFP0.integerValue = Int(tiaInfo.regs.11)
        tiaREFP1.integerValue = Int(tiaInfo.regs.12)
        tiaPF0.integerValue = Int(tiaInfo.regs.13)
        tiaPF1.integerValue = Int(tiaInfo.regs.14)
        tiaPF2.integerValue = Int(tiaInfo.regs.15)
        tiaRESP0.integerValue = Int(tiaInfo.regs.16)
        tiaRESP1.integerValue = Int(tiaInfo.regs.17)
        tiaRESM0.integerValue = Int(tiaInfo.regs.18)
        tiaRESM1.integerValue = Int(tiaInfo.regs.19)
        tiaRESBL.integerValue = Int(tiaInfo.regs.20)
        tiaGRP0.integerValue = Int(tiaInfo.regs.27)
        tiaGRP1.integerValue = Int(tiaInfo.regs.28)
        tiaENAM0.integerValue = Int(tiaInfo.regs.29)
        tiaENAM1.integerValue = Int(tiaInfo.regs.30)
        tiaENABL.integerValue = Int(tiaInfo.regs.31)
        tiaHMP0.integerValue = Int(tiaInfo.regs.32)
        tiaHMP1.integerValue = Int(tiaInfo.regs.33)
        tiaHMM0.integerValue = Int(tiaInfo.regs.34)
        tiaHMM1.integerValue = Int(tiaInfo.regs.35)
        tiaHMBL.integerValue = Int(tiaInfo.regs.36)
        tiaVDELP0.integerValue = Int(tiaInfo.regs.37)
        tiaVDELP1.integerValue = Int(tiaInfo.regs.38)
        tiaVDELBL.integerValue = Int(tiaInfo.regs.39)
        tiaRESMP0.integerValue = Int(tiaInfo.regs.40)
        tiaRESMP1.integerValue = Int(tiaInfo.regs.41)
        tiaHMOVE.integerValue = Int(tiaInfo.regs.42)
        tiaHMCLR.integerValue = Int(tiaInfo.regs.43)
        tiaCXCLR.integerValue = Int(tiaInfo.regs.44)

        lock(tiaVSYNClock, reg: TIARegister._VSYNC)
        lock(tiaVBLANKlock, reg: TIARegister._VBLANK)
        lock(tiaNUSIZ0lock, reg: TIARegister._NUSIZ0)
        lock(tiaNUSIZ1lock, reg: TIARegister._NUSIZ1)
        lock(tiaCOLUP0lock, reg: TIARegister._COLUP0)
        lock(tiaCOLUP1lock, reg: TIARegister._COLUP1)
        lock(tiaCOLUPFlock, reg: TIARegister._COLUPF)
        lock(tiaCOLUBKlock, reg: TIARegister._COLUBK)
        lock(tiaCTRLPFlock, reg: TIARegister._CTRLPF)
        lock(tiaREFP0lock, reg: TIARegister._REFP0)
        lock(tiaREFP1lock, reg: TIARegister._REFP1)
        lock(tiaPF0lock, reg: TIARegister._PF0)
        lock(tiaPF1lock, reg: TIARegister._PF1)
        lock(tiaPF2lock, reg: TIARegister._PF2)
        lock(tiaGRP0lock, reg: TIARegister._GRP0)
        lock(tiaGRP1lock, reg: TIARegister._GRP1)
        lock(tiaENAM0lock, reg: TIARegister._ENAM0)
        lock(tiaENAM1lock, reg: TIARegister._ENAM1)
        lock(tiaENABLlock, reg: TIARegister._ENABL)
        lock(tiaHMP0lock, reg: TIARegister._HMP0)
        lock(tiaHMP1lock, reg: TIARegister._HMP1)
        lock(tiaHMM0lock, reg: TIARegister._HMM0)
        lock(tiaHMM1lock, reg: TIARegister._HMM1)
        lock(tiaHMBLlock, reg: TIARegister._HMBL)
        lock(tiaVDELP0lock, reg: TIARegister._VDELP0)
        lock(tiaVDELP1lock, reg: TIARegister._VDELP1)
        lock(tiaVDELBLlock, reg: TIARegister._VDELBL)
        lock(tiaRESMP0lock, reg: TIARegister._RESMP0)
        lock(tiaRESMP1lock, reg: TIARegister._RESMP1)

        tiaCOLUP0Popup.selectItem(withTag: Int(tiaInfo.regs.6 >> 1))
        tiaCOLUP1Popup.selectItem(withTag: Int(tiaInfo.regs.7 >> 1))
        tiaCOLUPFPopup.selectItem(withTag: Int(tiaInfo.regs.8 >> 1))
        tiaCOLUBKPopup.selectItem(withTag: Int(tiaInfo.regs.9 >> 1))
     }

    /*
    func tag2colreg(_ tag: Int) -> TIARegister {

        switch tag {
        case 0: return ._COLUBK
        case 1: return ._COLUPF
        case 2: return ._COLUP0
        case 3: return ._COLUP1
        default: fatalError()
        }
    }
    */

    @IBAction func tiaColorAction(_ sender: NSPopUpButton!) {

        print("colorAction \(sender.tag) \(sender.selectedTag())")

        let reg = TIARegister(rawValue: sender.tag)!
        let val = sender.selectedTag()

        emu!.suspend()
        emu!.tia.unlockReg(reg)
        emu!.mem.poke(reg.rawValue, value: (val << 1))
        emu!.tia.lockReg(reg)
        emu!.resume()

        refreshTIA()
    }

    @IBAction func tiaLockAction(_ sender: NSButton!) {

        print("tiaLockAction \(sender.tag)")

        let reg = TIARegister(rawValue: sender.tag)!
        emu?.tia.toggleRegLock(reg)
        refreshTIA()
    }
}

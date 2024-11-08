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

            tiaPalette.image = paletteImage

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

            /*
             vicScanline.assignFormatter(fmt9)
             vicRasterCycle.assignFormatter(fmt9)
             vicYCounter.assignFormatter(fmt9)
             vicXCounter.assignFormatter(fmt9)
             vicVC.assignFormatter(fmt10)
             vicVCBase.assignFormatter(fmt10)
             vicRC.assignFormatter(fmt3)
             vicVMLI.assignFormatter(fmt6)
             vicCtrl1.assignFormatter(fmt8)
             vicCtrl2.assignFormatter(fmt8)
             vicDy.assignFormatter(fmt3)
             vicDx.assignFormatter(fmt3)
             vicMemSelect.assignFormatter(fmt8)
             vicIrqRasterline.assignFormatter(fmt8)
             vicImr.assignFormatter(fmt8)
             vicIrr.assignFormatter(fmt8)
             latchedLPX.assignFormatter(fmt8)
             latchedLPY.assignFormatter(fmt8)
             sprX.assignFormatter(fmt9)
             sprY.assignFormatter(fmt8)
             */
        }

        let mask = emu!.get(.TIA_REGLOCK)
        let lockCOLUP0 = mask & (1 << tiara.TIARegister._COLUP0.rawValue) != 0
        let lockCOLUP1 = mask & (1 << tiara.TIARegister._COLUP1.rawValue) != 0
        let lockCOLUBK = mask & (1 << tiara.TIARegister._COLUBK.rawValue) != 0
        let lockCOLUPF = mask & (1 << tiara.TIARegister._COLUPF.rawValue) != 0

        tiaCOLUBK.integerValue = Int(tiaInfo.colubk)
        tiaCOLUPF.integerValue = Int(tiaInfo.colupf)
        tiaCOLUP0.integerValue = Int(tiaInfo.colup0)
        tiaCOLUP1.integerValue = Int(tiaInfo.colup1)

        tiaCOLUBKPopup.selectItem(withTag: Int(tiaInfo.colubk >> 1))
        tiaCOLUPFPopup.selectItem(withTag: Int(tiaInfo.colupf >> 1))
        tiaCOLUP0Popup.selectItem(withTag: Int(tiaInfo.colup0 >> 1))
        tiaCOLUP1Popup.selectItem(withTag: Int(tiaInfo.colup1 >> 1))

        tiaCOLUBKlock.isHidden = !lockCOLUBK
        tiaCOLUPFlock.isHidden = !lockCOLUPF
        tiaCOLUP0lock.isHidden = !lockCOLUP0
        tiaCOLUP1lock.isHidden = !lockCOLUP1
     }

    var paletteImage: NSImage? {

        // Compute layout
        let width = 256
        let height = 512
        let cols = 8
        let rows = 128 / cols
        let dx = width / cols
        let dy = height / rows

        // Create image representation
        let size = CGSize(width: width, height: height)
        let cap = width * height
        let mask = calloc(cap, MemoryLayout<UInt32>.size)!
        let ptr = mask.bindMemory(to: UInt32.self, capacity: cap)

        func drawBlock(y: Int, x: Int, abgr: UInt32) {

            for i in 0...dy {
                for j in 0...dx {

                    let index = (y * dy + i) * width + x * dx + j

                    if index < width * height {
                        ptr[index] = abgr
                    } else {
                        break
                    }
                }
            }
        }

        for i in 0..<rows {
            for j in 0..<cols {

                let color = emu?.tia.color(i*cols+j) ?? NSColor.white

                let r = Int(color.redComponent * CGFloat(255))
                let g = Int(color.greenComponent * CGFloat(255))
                let b = Int(color.blueComponent * CGFloat(255))
                let a = Int(color.alphaComponent * CGFloat(255))
                let abgr = UInt32(r | g << 8 | b << 16 | a << 24)

                drawBlock(y: i, x: j, abgr: abgr)
            }
        }

        // Create image
        let image = NSImage.make(data: mask, rect: size)
        let resizedImage = image?.resizeSharp(width: 512, height: 256)
        return resizedImage
    }

    /*
    @IBAction func tiaColorAction(_ sender: NSColorWell!) {

        print("colorAction \(sender.tag)")

        guard let emu = emu else { return }

        let reg: tiara.TIARegister =
        sender.tag == 0 ? ._COLUBK :
        sender.tag == 1 ? ._COLUPF :
        sender.tag == 2 ? ._COLUP0 : ._COLUP1

        emu.suspend()
        emu.tia.unlockReg(reg)
        emu.tia.setColor(reg, color: sender.color)
        emu.tia.lockReg(reg)
        emu.resume()

        refreshTIA()
    }
    */

    func tag2colreg(_ tag: Int) -> tiara.TIARegister {

        switch tag {
        case 0: return ._COLUBK
        case 1: return ._COLUPF
        case 2: return ._COLUP0
        case 3: return ._COLUP1
        default: fatalError()
        }
    }

    @IBAction func tiaColorAction(_ sender: NSPopUpButton!) {

        print("colorAction \(sender.tag) \(sender.selectedTag())")

        let reg = tag2colreg(sender.tag)
        let val = sender.selectedTag()

        emu!.suspend()
        emu!.tia.unlockReg(reg)
        emu!.mem.poke(reg.rawValue, value: (val << 1))
        emu!.tia.lockReg(reg)
        emu!.resume()

        refreshTIA()
    }

    @IBAction func tiaColorLockAction(_ sender: NSButton!) {

        print("colorLockAction \(sender.tag)")
        emu?.tia.unlockReg(tag2colreg(sender.tag))
        refreshTIA()
    }
}

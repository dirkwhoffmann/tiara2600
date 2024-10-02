// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

struct MemColors {

    static let unmapped = NSColor.gray
    static let tia      = NSColor(r: 0xFF, g: 0xFF, b: 0x99, a: 0xFF)
    static let pia     = NSColor(r: 0xCC, g: 0x99, b: 0xFF, a: 0xFF)
    static let ram      = NSColor(r: 0x99, g: 0xFF, b: 0x99, a: 0xFF)
    static let cart     = NSColor(r: 0x99, g: 0xCC, b: 0xFF, a: 0xFF)
}

extension Inspector {
    
    var mem: MemoryProxy? { return emu?.mem }

    private func updateBankMap() {

        bankType[0x00] = memInfo.peekSrc.0
        bankType[0x01] = memInfo.peekSrc.1
        bankType[0x02] = memInfo.peekSrc.2
        bankType[0x03] = memInfo.peekSrc.3
        bankType[0x04] = memInfo.peekSrc.4
        bankType[0x05] = memInfo.peekSrc.5
        bankType[0x06] = memInfo.peekSrc.6
        bankType[0x07] = memInfo.peekSrc.7
        bankType[0x08] = memInfo.peekSrc.8
        bankType[0x09] = memInfo.peekSrc.9
        bankType[0x0A] = memInfo.peekSrc.10
        bankType[0x0B] = memInfo.peekSrc.11
        bankType[0x0C] = memInfo.peekSrc.12
        bankType[0x0D] = memInfo.peekSrc.13
        bankType[0x0E] = memInfo.peekSrc.14
        bankType[0x0F] = memInfo.peekSrc.15
        bankType[0x10] = memInfo.peekSrc.16
        bankType[0x11] = memInfo.peekSrc.17
        bankType[0x12] = memInfo.peekSrc.18
        bankType[0x13] = memInfo.peekSrc.19
        bankType[0x14] = memInfo.peekSrc.20
        bankType[0x15] = memInfo.peekSrc.21
        bankType[0x16] = memInfo.peekSrc.22
        bankType[0x17] = memInfo.peekSrc.23
        bankType[0x18] = memInfo.peekSrc.24
        bankType[0x19] = memInfo.peekSrc.25
        bankType[0x1A] = memInfo.peekSrc.26
        bankType[0x1B] = memInfo.peekSrc.27
        bankType[0x1C] = memInfo.peekSrc.28
        bankType[0x1D] = memInfo.peekSrc.29
        bankType[0x1E] = memInfo.peekSrc.30
        bankType[0x1F] = memInfo.peekSrc.31

        for i in 0x20 ... 0x3F {
            bankType[i] = .CRT
        }
    }
    
    private func cacheMemory() {
        
        if let emu = emu {
            
            let oldBankMap = memInfo?.bankMap
            memInfo = emu.paused ? emu.mem.info : emu.mem.cachedInfo
            if oldBankMap != memInfo.bankMap { layoutIsDirty = true }
        }
    }
    
    func refreshMemory(count: Int = 0, full: Bool = false) {
        
        cacheMemory()
        
        // Recompute the bank map image if necessary
        if full || (layoutIsDirty && count >= nextLayoutRefresh) {
            
            updateBankMap()
            refreshMemoryLayout()
            memBankTableView.reloadData()
            memTableView.reloadData()
            layoutIsDirty = false
            nextLayoutRefresh = count + 10
        }

        memBankTableView.refresh(count: count, full: full)
        memTableView.refresh(count: count, full: full)
        
        if memTab.selectedTabViewItem?.label == "Heatmap" {
            memHeatmapView.update()
        }
    }
    
    private func refreshMemoryLayout() {
        
        let size = NSSize(width: 16, height: 16)
        
        memLayoutButton.image   = memLayoutImage
        memTIAButton.image     = NSImage(color: MemColors.tia, size: size)
        memRamButton.image    = NSImage(color: MemColors.ram, size: size)
        memPIAButton.image  = NSImage(color: MemColors.pia, size: size)
        memCartButton.image   = NSImage(color: MemColors.cart, size: size)
    }
    
    @IBAction func memSourceAction(_ sender: NSPopUpButton!) {
        
        layoutIsDirty = true
        refreshMemory(full: true)
    }
    
    func jumpTo(addr: Int) {
                
        if addr >= 0 && addr <= 0xFFFF {

            let bank = (addr & 0x3FFF) >> 7
            let row  = (addr & 0x7F) >> 4
            
            jumpTo(bank: bank)
            memTableView.scrollRowToVisible(row)
            memTableView.selectRowIndexes([row], byExtendingSelection: false)
        }
    }

    func jumpTo(type: [tiara.MemoryType]) {

        for i in 0...63 where type.contains(bankType[i]!) {
            jumpTo(bank: i)
            return
        }
    }

    func jumpTo(bank nr: Int) {
                
        if nr >= 0 && nr <= 63 {

            displayedBank = nr
            memLayoutSlider.integerValue = nr
            memTableView.scrollRowToVisible(0)
            memBankTableView.scrollRowToVisible(nr)
            memBankTableView.selectRowIndexes([nr], byExtendingSelection: false)
            fullRefresh()
        }
    }
        
    @IBAction func memTIAAction(_ sender: NSButton!) {

        jumpTo(type: [.TIA])
    }

    @IBAction func memRamAction(_ sender: NSButton!) {

        jumpTo(type: [.RAM])
    }

    @IBAction func memPIAAction(_ sender: NSButton!) {

        jumpTo(type: [.PIA])
    }

    @IBAction func memCartAction(_ sender: NSButton!) {

        jumpTo(type: [.CRT])
    }

    @IBAction func memSliderAction(_ sender: NSSlider!) {

        jumpTo(bank: min(sender.integerValue, 63))
    }

    @IBAction func memSearchAction(_ sender: NSTextField!) {
                
        let input = sender.stringValue
        let radix = hex ? 16 : 10
        let format = hex ? "%04X" : "%05d"
        
         if let addr = Int(input, radix: radix), input != "" {
             sender.stringValue = String(format: format, addr)
             jumpTo(addr: addr)
         } else {
             sender.stringValue = ""
         }
         fullRefresh()
    }
}

extension Inspector {
    
    var memLayoutImage: NSImage? {
                
        // Create image representation in memory
        let width = 256
        let height = 16
        let size = CGSize(width: width, height: height)
        let cap = width * height
        let mask = calloc(cap, MemoryLayout<UInt32>.size)!
        let ptr = mask.bindMemory(to: UInt32.self, capacity: cap)
        let c = 3
        let banks = 64
        let dx = width / banks

        // Create image data
        for bank in 0..<banks {
            
            var color: NSColor

            switch bankType[bank] {
            case .NONE: color = MemColors.unmapped
            case .TIA:  color = MemColors.tia
            case .RAM:  color = MemColors.ram
            case .PIA:  color = MemColors.pia
            case .CRT: color = MemColors.cart
            default: color = MemColors.unmapped
            }

            let ciColor = CIColor(color: color)!
            for y in 0..<height {
                for i in 0..<dx {
                    let r = Int(ciColor.red * CGFloat(255 - y*c))
                    let g = Int(ciColor.green * CGFloat(255 - y*c))
                    let b = Int(ciColor.blue * CGFloat(255 - y*c))
                    let a = Int(ciColor.alpha * CGFloat(255))
                    let abgr = UInt32(r | g << 8 | b << 16 | a << 24)
                    ptr[width*y+dx*bank+i] = abgr
                }
            }
        }

        // Create image
        let image = NSImage.make(data: mask, rect: size)
        let resizedImage = image?.resizeSharp(width: 512, height: 16)
        return resizedImage
    }
}

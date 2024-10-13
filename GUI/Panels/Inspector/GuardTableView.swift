// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

class GuardTableView: NSTableView {

    @IBOutlet weak var inspector: Inspector!
    var emu: EmulatorProxy? { return inspector.parent.emu }
    var cpu: CPUProxy? { return emu?.cpu }

    // Symbols
    var symEnabled = "⛔"  // "\u{26D4}"
    var symDisabled = "⚪" // "\u{26AA}"
    var symTrash = "🗑" // "\u{1F5D1}"

    // Data caches
    var disabledCache: [Int: Bool] = [:]
    var addrCache: [Int: Int] = [:]
    var numRows = 0

    override func awakeFromNib() {

        delegate = self
        dataSource = self
        target = self

        action = #selector(clickAction(_:))
    }

    func cache() { }
    func click(row: Int, col: Int) { }
    func edit(row: Int, addr: Int) { }

    func refresh(count: Int = 0, full: Bool = false) {
        
        if full {
            assignFormatter(inspector.fmt16, column: "addr")
            cache()
            reloadData()
        }
    }

    @IBAction func clickAction(_ sender: NSTableView!) {

        click(row: sender.clickedRow, col: sender.clickedColumn)
    }
}

extension GuardTableView: NSTableViewDataSource {

    func numberOfRows(in tableView: NSTableView) -> Int {

        return numRows + 1
    }

    func tableView(_ tableView: NSTableView, objectValueFor tableColumn: NSTableColumn?, row: Int) -> Any? {

        let last = row == numRows

        switch tableColumn?.identifier.rawValue {

        case "break" where disabledCache[row] == true:
            return last ? "" : symDisabled
        case "break":
            return last ? "" : symEnabled
        case "addr":
            return last ? "Add..." : addrCache[row]!
        case "delete":
            return last ? "" : symTrash

        default: return ""
        }
    }
}

extension GuardTableView: NSTableViewDelegate {

    func tableView(_ tableView: NSTableView, willDisplayCell cell: Any, for tableColumn: NSTableColumn?, row: Int) {

        if tableColumn?.identifier.rawValue == "addr" {
            if let cell = cell as? NSTextFieldCell {

                let last = row == numRows
                let disabled = !last && disabledCache[row] == true
                let selected = tableView.selectedRow == row
                let edited = tableView.editedRow == row

                cell.textColor =
                    disabled ? NSColor.disabledControlTextColor :
                    edited ? NSColor.textColor :
                    selected ? NSColor.white :
                    last ? NSColor.disabledControlTextColor :
                    NSColor.textColor
            }
        }
    }

    func tableView(_ tableView: NSTableView, shouldEdit tableColumn: NSTableColumn?, row: Int) -> Bool {

        if tableColumn?.identifier.rawValue == "addr" {
            return true
        }

        return false
    }

    func tableView(_ tableView: NSTableView, setObjectValue object: Any?, for tableColumn: NSTableColumn?, row: Int) {

        if tableColumn?.identifier.rawValue != "addr" { NSSound.beep(); return }
        guard let addr = object as? Int else { NSSound.beep(); return }

        edit(row: row, addr: addr)
        inspector.fullRefresh()
     }
}

class BreakTableView: GuardTableView {
    
    override func cache() {

        if let breakpoints = cpu?.breakpoints {

            numRows = breakpoints.count

            for i in 0 ..< numRows {
                disabledCache[i] = breakpoints.isDisabled(i)
                addrCache[i] = breakpoints.addr(i)
            }
        }
    }

    override func click(row: Int, col: Int) {

        if let breakpoints = cpu?.breakpoints {

            if col == 0 {

                // Toggle enable status
                if breakpoints.isDisabled(row) {
                    try? breakpoints.enable(nr: row)
                } else {
                    try? breakpoints.disable(nr: row)
                }
                inspector.fullRefresh()
            }

            if col == 0 || col == 1 {

                // Jump to breakpoint address
                let addr = breakpoints.addr(row)
                if addr <= 0xFFFF {
                    inspector.fullRefresh()
                    inspector.cpuInstrView.jumpTo(addr: addr)
                }

                if col == 2 {

                    // Delete
                    try? breakpoints.remove(nr: row)
                    inspector.fullRefresh()
                }
            }
        }
    }

    override func edit(row: Int, addr: Int) {

        if let breakpoints = cpu?.breakpoints {

            // Abort if a breakpoint is already set
            if breakpoints.isSet(at: addr) { NSSound.beep(); return }

            // emu?.suspend()

            if row < numRows {
                try? breakpoints.set(at: addr)
            } else {
                assert(row < numRows)
                try? breakpoints.replace(nr: row, addr: addr)
            }

            inspector.cpuInstrView.jumpTo(addr: addr)

            // emu?.resume()
        }
    }
}

class WatchTableView: GuardTableView {

    override func cache() {

        if let watchpoints = cpu?.watchpoints {

            numRows = watchpoints.count

            for i in 0 ..< numRows {
                disabledCache[i] = watchpoints.isDisabled(i)
                addrCache[i] = watchpoints.addr(i)
            }

            symEnabled = "⚠️"
        }
    }

    override func click(row: Int, col: Int) {
        
        if let watchpoints = cpu?.watchpoints {

            if col == 0 {

                // Toggle enable status
                if watchpoints.isDisabled(row) {
                    try? watchpoints.enable(nr: row)
                } else {
                    try? watchpoints.disable(nr: row)
                }
                inspector.fullRefresh()
            }

            if col == 2 {

                // Delete
                try? watchpoints.remove(nr: row)
                inspector.fullRefresh()
            }
        }
    }
    
    override func edit(row: Int, addr: Int) {
        
        if let watchpoints = cpu?.watchpoints {

            // Abort if a watchpoint is already set
            if watchpoints.isSet(at: addr) { NSSound.beep(); return }

            if row == numRows {
                try? watchpoints.set(at: addr)
            } else {
                assert(row < numRows)
                try? watchpoints.replace(nr: row, addr: addr)
            }
        }
    }
}

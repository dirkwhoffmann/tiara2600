// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

class BankTableView: NSTableView, NSTableViewDelegate {
    
    @IBOutlet weak var inspector: Inspector!
   
    var emu: EmulatorProxy? { return inspector.parent.emu }

    // Displayed memory bank
    var bank = 0

    // Data caches
    var bankCache: [Int: MemoryType] = [:]

    override func awakeFromNib() {

        delegate = self
        dataSource = self
        target = self
    }
    
    func cache() {

    }
    
    func refresh(count: Int = 0, full: Bool = false) {

        if full {
             
             assignFormatter(inspector.fmt4, column: "bank")
         }
        
        cache()
        reloadData()
    }
    
    @IBAction func tableViewSelectionDidChange(_ notification: Notification) {

        inspector.jumpTo(bank: selectedRow)
    }
}

extension BankTableView: NSTableViewDataSource {
    
    func numberOfRows(in tableView: NSTableView) -> Int { return 64; }
    
    func tableView(_ tableView: NSTableView, objectValueFor tableColumn: NSTableColumn?, row: Int) -> Any? {
        
        switch tableColumn?.identifier.rawValue {

        case "source":

            switch inspector.bankType[row] {
                
            case .NONE:   return "Unmapped"
            case .TIA:    return "TIA"
            case .PIA:    return "PIA"
            case .RAM:    return "RAM"
            case .CRT:   return "Cart"
            default:      return "???"
            }

        default:
            return row
        }
    }
}

/*
 extension BankTableView: NSTableViewDelegate {
    
    func tableView(_ tableView: NSTableView, willDisplayCell cell: Any, for tableColumn: NSTableColumn?, row: Int) {
        
        if let cell = cell as? NSTextFieldCell {

            if inspector.memBank[row] == M_NONE {
                cell.textColor = .gray
            } else {
                cell.textColor = nil
            }
        }
    }
}
*/

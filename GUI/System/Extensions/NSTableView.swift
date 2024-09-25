// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension NSTableView {
    
    func assignFormatter(_ formatter: Formatter, column: String) {
        
        let columnId = NSUserInterfaceItemIdentifier(rawValue: column)
        if let column = tableColumn(withIdentifier: columnId) {
            if let cell = column.dataCell as? NSCell {
                cell.formatter = formatter
            }
        }
    }
}

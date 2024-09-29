// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension tiara.EventSlot: CustomStringConvertible {

    public var description: String {

        switch self {

        case .RIOT:    return "CIA 1"
        case .SEC:     return "Next Secondary Event"

        case .TER:     return "Next Tertiary Event"

        case .EXP:     return "Expansion Port"
        case .SNP:     return "Snapshots"
        case .RSH:     return "Retro Shell"
        case .KEY:     return "Auto Typing"
        case .SRV:     return "Server Daemon"
        case .DBG:     return "Debugger"
        case .ALA:     return "Alarms"
        case .INS:     return "Inspector"

        case .COUNT:   return "???"

        default:        fatalError()
        }
    }
}

extension tiara.FileType {

    init?(url: URL?) {
        self = url == nil ? .UNKNOWN : MediaFileProxy.type(of: url)
    }

    static var all: [tiara.FileType] {
        return [
            .SNAPSHOT, .SCRIPT,
            .CRT,
            .BASIC_ROM, .CHAR_ROM, .KERNAL_ROM, .VC1541_ROM
        ]
    }

    static var draggable: [tiara.FileType] {

        return [ .SNAPSHOT, .SCRIPT, .CRT ]
    }
}

extension tiara.ErrorCode {

    func description(expected exp: Int = 0) -> String {
        
        switch self {
        
        case .OK:
            return ""
        case .FS_EXPECTED_VAL:
            return String(format: "Expected $%02X", exp)
        case .FS_EXPECTED_MIN:
            return String(format: "Expected a value greater or equal %d", exp)
        case .FS_EXPECTED_MAX:
            return String(format: "Expected a value less or equal %d", exp)

        default:
            fatalError("\(self)")
        }
    }
}

extension tiara.CartridgeType {
    
    var description: String {
        
        switch self {

        case .NONE:     return "None"
        case .NORMAL:   return "Standard"

        default: return "CRT type \(self.rawValue) (Unknown)"
        }
    }
}
            
extension tiara.TAPVersion {
    
    var description: String {
        
        switch self {
        
        case .ORIGINAL: return "TAP type 0 (Original pulse layout)"
        case .ADVANCED: return "TAP type 1 (Advanced pulse layout)"
            
        default: return "TAP type \(self.rawValue) (Unknown)"
        }
    }
}

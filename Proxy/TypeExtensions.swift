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

        case ._CIA1:    return "CIA 1"
        case ._CIA2:    return "CIA 2"
        case ._SEC:     return "Next Secondary Event"

        case ._TER:     return "Next Tertiary Event"

        case ._EXP:     return "Expansion Port"
        case ._TXD:     return "RS232 Out"
        case ._RXD:     return "RS232 In"
        case ._SNP:     return "Snapshots"
        case ._RSH:     return "Retro Shell"
        case ._KEY:     return "Auto Typing"
        case ._SRV:     return "Server Daemon"
        case ._DBG:     return "Debugger"
        case ._ALA:     return "Alarms"
        case ._INS:     return "Inspector"

        case ._COUNT:   return "???"

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
        case .NORMAL: return "Standard"
        case .SIMONS_BASIC: return "Simons Basic"
            
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

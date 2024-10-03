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

        case .PIA:    return "CIA 1"
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

extension tiara.CartType {

    var description: String {

        switch self {

        case ._NONE:        return "No Cartridge"
        case ._UNKNOWN:     return "Unknown Cartride Type"

        case ._0840:        return "0840 (8K EconoBanking)"
        case ._0FA0:        return "0FA0 (8K Fotomania)"
        case ._2IN1:        return "2IN1 Multicart (4-64K)"
        case ._4IN1:        return "4IN1 Multicart (8-64K)"
        case ._8IN1:        return "8IN1 Multicart (16-64K)"
        case ._16IN1:       return "16IN1 Multicart (32-128K)"
        case ._32IN1:       return "32IN1 Multicart (64/128K)"
        case ._64IN1:       return "64IN1 Multicart (128/256K)"
        case ._128IN1:      return "128IN1 Multicart (256/512K)"
        case ._2K:          return "2K (32-2048 bytes Atari)"
        case ._3E:          return "3E (Tigervision, 32K RAM)"
        case ._3EX:         return "3EX (Tigervision, 256K RAM)"
        case ._3EP:         return "3E+ (TJ modified 3E)"
        case ._3F:          return "3F (512K Tigervision)"
        case ._4A50:        return "4A50 (64K 4A50 + RAM)"
        case ._4K:          return "4K (4K Atari)"
        case ._4KSC:        return "4KSC (CPUWIZ 4K + RAM)"
        case ._AR:          return "AR (Supercharger)"
        case ._BF:          return "BF (CPUWIZ 256K)"
        case ._BFSC:        return "BFSC (CPUWIZ 256K + RAM)"
        case ._BUS:         return "BUS (Experimental)"
        case ._CDF:         return "CDF (Chris, Darrell, Fred)"
        case ._CM:          return "CM (SpectraVideo CompuMate)"
        case ._CTY:         return "CTY (CDW - Chetiry)"
        case ._CV:          return "CV (Commavid extra RAM)"
        case ._DF:          return "DF (CPUWIZ 128K)"
        case ._DFSC:        return "DFSC (CPUWIZ 128K + RAM)"
        case ._DPC:         return "DPC (Pitfall II)"
        case ._DPCP:        return "DPC+ (Enhanced DPC)"
        case ._E0:          return "E0 (8K Parker Bros)"
        case ._E7:          return "E7 (8-16K M Network)"
        case ._EF:          return "EF (64K H. Runner)"
        case ._EFSC:        return "EFSC (64K H. Runner + RAM)"
        case ._F0:          return "F0 (Dynacom Megaboy)"
        case ._F4:          return "F4 (32K Atari)"
        case ._F4SC:        return "F4SC (32K Atari + RAM)"
        case ._F6:          return "F6 (16K Atari)"
        case ._F6SC:        return "F6SC (16K Atari + RAM)"
        case ._F8:          return "F8 (8K Atari)"
        case ._F8SC:        return "F8SC (8K Atari + RAM)"
        case ._FA:          return "FA (CBS RAM Plus)"
        case ._FA2:         return "FA2 (CBS RAM Plus 24/28K)"
        case ._FC:          return "FC (32K Amiga)"
        case ._FE:          return "FE (8K Activision)"
        case ._MDM:         return "MDM (Menu Driven Megacart)"
        case ._MVC:         return "MVC (Movie Cart)"
        case ._SB:          return "SB (128-256K SUPERbank)"
        case ._TVBOY:       return "TV Boy (512K)"
        case ._UA:          return "UA (8K UA Ltd.)"
        case ._UASW:        return "UASW (8K UA swapped banks)"
        case ._WD:          return "WD (Pink Panther)"
        case ._WDSW:        return "WDSW (Pink Panther, bad)"
        case ._X07:         return "X07 (64K AtariAge)"

        default:            return "Unknown (\(self.rawValue))"
        }
    }
}

extension tiara.FileType {

    init?(url: URL?) {
        self = url == nil ? .UNKNOWN : MediaFileProxy.type(of: url)
    }

    static var all: [tiara.FileType] {
        return [ .SNAPSHOT, .SCRIPT, .CART ]
    }

    static var draggable: [tiara.FileType] {
        return [ .SNAPSHOT, .SCRIPT, .CART ]
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

extension tiara.TAPVersion {
    
    var description: String {
        
        switch self {
        
        case .ORIGINAL: return "TAP type 0 (Original pulse layout)"
        case .ADVANCED: return "TAP type 1 (Advanced pulse layout)"
            
        default: return "TAP type \(self.rawValue) (Unknown)"
        }
    }
}

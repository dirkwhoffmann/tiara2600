// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

typealias CartType = tiara.CartType
typealias CmdType = tiara.CmdType
typealias ControlPortDevice = tiara.ControlPortDevice
typealias CoordCmd = tiara.CoordCmd
typealias ErrorCode = tiara.ErrorCode
typealias EventSlot = tiara.EventSlot
typealias EventSlotInfo = tiara.EventSlotInfo
typealias FileType = tiara.FileType
typealias GamePadAction = tiara.GamePadAction
typealias GamePadCmd = tiara.GamePadCmd
typealias MemoryType = tiara.MemoryType
typealias Message = tiara.Message
typealias Option = tiara.Option
typealias Palette = tiara.Palette
typealias Probe = tiara.Probe
typealias PIARegister = tiara.PIARegister
typealias TIARegister = tiara.TIARegister
typealias Slider = tiara.Slider
typealias SliderCmd = tiara.SliderCmd
typealias WarpMode = tiara.WarpMode

extension TIARegister: CustomStringConvertible {

    public var description: String {

        switch self {

        case ._VSYNC:   return "VSYNC"
        case ._VBLANK:  return "VBLANK"
        case ._WSYNC:   return "WSYNC"
        case ._RSYNC:   return "RSYNC"
        case ._NUSIZ0:  return "NUSIZ0"
        case ._NUSIZ1:  return "NUSIZ1"
        case ._COLUP0:  return "COLUP0"
        case ._COLUP1:  return "COLUP1"
        case ._COLUPF:  return "COLUPF"
        case ._COLUBK:  return "COLUBK"
        case ._CTRLPF:  return "CTRLPF"
        case ._REFP0:   return "REFP0"
        case ._REFP1:   return "REFP1"
        case ._PF0:     return "PF0"
        case ._PF1:     return "PF1"
        case ._PF2:     return "PF2"
        case ._RESP0:   return "RESP0"
        case ._RESP1:   return "RESP1"
        case ._RESM0:   return "RESM0"
        case ._RESM1:   return "RESM1"
        case ._RESBL:   return "RESBL"
        case ._AUDC0:   return "AUDC0"
        case ._AUDC1:   return "AUDC1"
        case ._AUDF0:   return "AUDF0"
        case ._AUDF1:   return "AUDF1"
        case ._AUDV0:   return "AUDV0"
        case ._AUDV1:   return "AUDV1"
        case ._GRP0:    return "GRP0"
        case ._GRP1:    return "GRP1"
        case ._ENAM0:   return "ENAM0"
        case ._ENAM1:   return "ENAM1"
        case ._ENABL:   return "ENABL"
        case ._HMP0:    return "HMP0"
        case ._HMP1:    return "HMP1"
        case ._HMM0:    return "HMM0"
        case ._HMM1:    return "HMM1"
        case ._HMBL:    return "HMBL"
        case ._VDELP0:  return "VDELP0"
        case ._VDELP1:  return "VDELP1"
        case ._VDELBL:  return "VDELBL"
        case ._RESMP0:  return "RESMP0"
        case ._RESMP1:  return "RESMP1"
        case ._HMOVE:   return "HMOVE"
        case ._HMCLR:   return "HMCLR"
        case ._CXCLR:   return "CXCLR"

        case ._2D:      return "TIA(2D)"
        case ._2E:      return "TIA(2E)"
        case ._2F:      return "TIA(2F)"

        case ._CXM0P:   return "CXM0P"
        case ._CXM1P:   return "CXM1P"
        case ._CXP0FB:  return "CXP0FB"
        case ._CXP1FB:  return "CXP1FB"
        case ._CXM0FB:  return "CXM0FB"
        case ._CXM1FB:  return "CXM1FB"
        case ._CXBLPF:  return "CXBLPF"
        case ._CXPPMM:  return "CXPPMM"
        case ._INPT0:   return "INPT0"
        case ._INPT1:   return "INPT1"
        case ._INPT2:   return "INPT2"
        case ._INPT3:   return "INPT3"
        case ._INPT4:   return "INPT4"
        case ._INPT5:   return "INPT5"

        case ._3E:      return "TIA(3E)"
        case ._3F:      return "TIA(3F)"

        default:
            return "???"
        }
    }

    static func isTIAAddr(addr: Int) -> Bool {

        return addr & 0b0001_0000_1000_0000 == 0b0000_0000_0000_0000
    }
}

extension PIARegister: CustomStringConvertible {

    public var description: String {

        switch self {

        case ._SWCHA:     return "SWCHA"
        case ._SWACNT:    return "SWACNT"
        case ._SWCHB:     return "SWCHB"
        case ._SWBCNT:    return "SWBCNT"
        case ._INTIM:     return "INTIM"
        case ._INSTAT:    return "INSTAT"

        case ._06:        return "PIA(06)"
        case ._07:        return "PIA(07)"
        case ._08:        return "PIA(08)"
        case ._09:        return "PIA(09)"
        case ._0A:        return "PIA(0A)"
        case ._0B:        return "PIA(0B)"
        case ._0C:        return "PIA(0C)"
        case ._0D:        return "PIA(0D)"
        case ._0E:        return "PIA(0E)"
        case ._0F:        return "PIA(0F)"
        case ._10:        return "PIA(10)"
        case ._11:        return "PIA(11)"
        case ._12:        return "PIA(12)"
        case ._13:        return "PIA(13)"

        case ._TIM1T:     return "TIM1T"
        case ._TIM8T:     return "TIM8T"
        case ._TIM64T:    return "TIM64T"
        case ._T1024T:    return "T1024T"

        case ._18:        return "PIA(18)"
        case ._19:        return "PIA(19)"
        case ._1A:        return "PIA(1A)"
        case ._1B:        return "PIA(1B)"
        case ._1C:        return "PIA(1C)"
        case ._1D:        return "PIA(1D)"
        case ._1E:        return "PIA(1E)"
        case ._1F:        return "PIA(1F)"

        default:
            return "???"
        }
    }

    static func isPIAAddr(addr: Int) -> Bool {

        return addr & 0b0001_0010_1000_0000 == 0b0000_0010_1000_0000
    }
}

extension EventSlot: CustomStringConvertible {

    public var description: String {

        switch self {

        case .REG:     return "Registers"
        case .PIA:     return "PIA"
        case .SEC:     return "Next Secondary Event"

        case .TER:     return "Next Tertiary Event"

        case .EXP:     return "Expansion Port"
        case .SNP:     return "Snapshots"
        case .RSH:     return "Retro Shell"
        case .SWI:     return "Console Switches"
        case .SRV:     return "Server Daemon"
        case .DBG:     return "Debugger"
        case .BTR:      return "Beam Traps"
        case .ALA:     return "Alarms"
        case .INS:     return "Inspector"

        case .COUNT:   return "???"

        default:        fatalError()
        }
    }
}

extension CartType {

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

extension FileType {

    init?(url: URL?) {
        self = url == nil ? .UNKNOWN : MediaFileProxy.type(of: url)
    }

    static var all: [FileType] {
        return [ .SNAPSHOT, .SCRIPT, .CART ]
    }

    static var draggable: [FileType] {
        return [ .SNAPSHOT, .SCRIPT, .CART ]
    }
}

extension ErrorCode {

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

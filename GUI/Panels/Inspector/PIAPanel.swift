// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension Inspector {
        
    private func cachePIA() {

        if let emu = emu {

            piaInfo = emu.paused ? emu.pia.info : emu.pia.cachedInfo
        }
    }

    func refreshPIA(count: Int = 0, full: Bool = false) {

        cachePIA()

        if full {

            /*
            piaPRA0.title = (cia1 ? "C0,JB0"    : "VA14")
            piaPRA1.title = (cia1 ? "C1,JB1"    : "VA15")
            piaPRA2.title = (cia1 ? "C2,JB2"    : "User M")
            piaPRA3.title = (cia1 ? "C3,JB4"    : "ATN")
            piaPRA4.title = (cia1 ? "C4,BTNB"   : "CLK")
            piaPRA5.title = (cia1 ? "C5"        : "DATA")
            piaPRA6.title = (cia1 ? "C6"        : "CLK")
            piaPRA7.title = (cia1 ? "C7"        : "DATA")
            */

            piaPRA.assignFormatter(fmt8)
            piaDDRA.assignFormatter(fmt8)
            piaEXTA.assignFormatter(fmt8)
            piaPRAbinary.assignFormatter(fmt8b)
            piaDDRAbinary.assignFormatter(fmt8b)
            piaEXTAbinary.assignFormatter(fmt8b)

            piaPRB.assignFormatter(fmt8)
            piaDDRB.assignFormatter(fmt8)
            piaEXTB.assignFormatter(fmt8)
            piaPRBbinary.assignFormatter(fmt8b)
            piaDDRBbinary.assignFormatter(fmt8b)
            piaEXTBbinary.assignFormatter(fmt8b)
        }

        //
        // Port A
        //

        piaPRA.intValue = Int32(piaInfo.portA.reg)
        piaPRAbinary.intValue = Int32(piaInfo.portA.reg)
        piaDDRA.intValue = Int32(piaInfo.portA.dir)
        piaDDRAbinary.intValue = Int32(piaInfo.portA.dir)
        piaEXTA.intValue = Int32(piaInfo.portA.ext)
        piaEXTAbinary.intValue = Int32(piaInfo.portA.ext)

        var bits = piaInfo.portA.reg
        piaPRA7.state = (bits & 0b10000000) != 0 ? .on : .off
        piaPRA6.state = (bits & 0b01000000) != 0 ? .on : .off
        piaPRA5.state = (bits & 0b00100000) != 0 ? .on : .off
        piaPRA4.state = (bits & 0b00010000) != 0 ? .on : .off
        piaPRA3.state = (bits & 0b00001000) != 0 ? .on : .off
        piaPRA2.state = (bits & 0b00000100) != 0 ? .on : .off
        piaPRA1.state = (bits & 0b00000010) != 0 ? .on : .off
        piaPRA0.state = (bits & 0b00000001) != 0 ? .on : .off

        bits = piaInfo.portA.port
        piaPA7.state = (bits & 0b10000000) != 0 ? .on : .off
        piaPA6.state = (bits & 0b01000000) != 0 ? .on : .off
        piaPA5.state = (bits & 0b00100000) != 0 ? .on : .off
        piaPA4.state = (bits & 0b00010000) != 0 ? .on : .off
        piaPA3.state = (bits & 0b00001000) != 0 ? .on : .off
        piaPA2.state = (bits & 0b00000100) != 0 ? .on : .off
        piaPA1.state = (bits & 0b00000010) != 0 ? .on : .off
        piaPA0.state = (bits & 0b00000001) != 0 ? .on : .off

        bits = piaInfo.portA.ext
        piaEXTA7.state = (bits & 0b10000000) != 0 ? .on : .off
        piaEXTA6.state = (bits & 0b01000000) != 0 ? .on : .off
        piaEXTA5.state = (bits & 0b00100000) != 0 ? .on : .off
        piaEXTA4.state = (bits & 0b00010000) != 0 ? .on : .off
        piaEXTA3.state = (bits & 0b00001000) != 0 ? .on : .off
        piaEXTA2.state = (bits & 0b00000100) != 0 ? .on : .off
        piaEXTA1.state = (bits & 0b00000010) != 0 ? .on : .off
        piaEXTA0.state = (bits & 0b00000001) != 0 ? .on : .off

        bits = piaInfo.portA.dir
        /*
         piaDDRA7I.isHidden = (bits & 0b10000000) != 0
         piaDDRA6I.isHidden = (bits & 0b01000000) != 0
         piaDDRA5I.isHidden = (bits & 0b00100000) != 0
         piaDDRA4I.isHidden = (bits & 0b00010000) != 0
         piaDDRA3I.isHidden = (bits & 0b00001000) != 0
         piaDDRA2I.isHidden = (bits & 0b00000100) != 0
         piaDDRA1I.isHidden = (bits & 0b00000010) != 0
         piaDDRA0I.isHidden = (bits & 0b00000001) != 0
         piaDDRA7O.isHidden = (bits & 0b10000000) == 0
         piaDDRA6O.isHidden = (bits & 0b01000000) == 0
         piaDDRA5O.isHidden = (bits & 0b00100000) == 0
         piaDDRA4O.isHidden = (bits & 0b00010000) == 0
         piaDDRA3O.isHidden = (bits & 0b00001000) == 0
         piaDDRA2O.isHidden = (bits & 0b00000100) == 0
         piaDDRA1O.isHidden = (bits & 0b00000010) == 0
         piaDDRA0O.isHidden = (bits & 0b00000001) == 0
         */
        piaDDRA7I.textColor = (bits & 0b10000000) == 0 ? .textColor : .secondaryLabelColor
        piaDDRA6I.textColor = (bits & 0b01000000) == 0 ? .textColor : .secondaryLabelColor
        piaDDRA5I.textColor = (bits & 0b00100000) == 0 ? .textColor : .secondaryLabelColor
        piaDDRA4I.textColor = (bits & 0b00010000) == 0 ? .textColor : .secondaryLabelColor
        piaDDRA3I.textColor = (bits & 0b00001000) == 0 ? .textColor : .secondaryLabelColor
        piaDDRA2I.textColor = (bits & 0b00000100) == 0 ? .textColor : .secondaryLabelColor
        piaDDRA1I.textColor = (bits & 0b00000010) == 0 ? .textColor : .secondaryLabelColor
        piaDDRA0I.textColor = (bits & 0b00000001) == 0 ? .textColor : .secondaryLabelColor
        piaDDRA7O.textColor = (bits & 0b10000000) != 0 ? .textColor : .secondaryLabelColor
        piaDDRA6O.textColor = (bits & 0b01000000) != 0 ? .textColor : .secondaryLabelColor
        piaDDRA5O.textColor = (bits & 0b00100000) != 0 ? .textColor : .secondaryLabelColor
        piaDDRA4O.textColor = (bits & 0b00010000) != 0 ? .textColor : .secondaryLabelColor
        piaDDRA3O.textColor = (bits & 0b00001000) != 0 ? .textColor : .secondaryLabelColor
        piaDDRA2O.textColor = (bits & 0b00000100) != 0 ? .textColor : .secondaryLabelColor
        piaDDRA1O.textColor = (bits & 0b00000010) != 0 ? .textColor : .secondaryLabelColor
        piaDDRA0O.textColor = (bits & 0b00000001) != 0 ? .textColor : .secondaryLabelColor

        let pass = "↔", block = "|"
        piaDDRA7I.stringValue = (bits & 0b10000000) == 0 ? pass : block
        piaDDRA6I.stringValue = (bits & 0b01000000) == 0 ? pass : block
        piaDDRA5I.stringValue = (bits & 0b00100000) == 0 ? pass : block
        piaDDRA4I.stringValue = (bits & 0b00010000) == 0 ? pass : block
        piaDDRA3I.stringValue = (bits & 0b00001000) == 0 ? pass : block
        piaDDRA2I.stringValue = (bits & 0b00000100) == 0 ? pass : block
        piaDDRA1I.stringValue = (bits & 0b00000010) == 0 ? pass : block
        piaDDRA0I.stringValue = (bits & 0b00000001) == 0 ? pass : block
        piaDDRA7O.stringValue = (bits & 0b10000000) != 0 ? pass : block
        piaDDRA6O.stringValue = (bits & 0b01000000) != 0 ? pass : block
        piaDDRA5O.stringValue = (bits & 0b00100000) != 0 ? pass : block
        piaDDRA4O.stringValue = (bits & 0b00010000) != 0 ? pass : block
        piaDDRA3O.stringValue = (bits & 0b00001000) != 0 ? pass : block
        piaDDRA2O.stringValue = (bits & 0b00000100) != 0 ? pass : block
        piaDDRA1O.stringValue = (bits & 0b00000010) != 0 ? pass : block
        piaDDRA0O.stringValue = (bits & 0b00000001) != 0 ? pass : block

        //
        // Port B
        //

        piaPRB.intValue = Int32(piaInfo.portB.reg)
        piaPRBbinary.intValue = Int32(piaInfo.portB.reg)
        piaDDRB.intValue = Int32(piaInfo.portB.dir)
        piaDDRBbinary.intValue = Int32(piaInfo.portB.dir)
        piaEXTB.intValue = Int32(piaInfo.portB.ext)
        piaEXTBbinary.intValue = Int32(piaInfo.portB.ext)

        bits = piaInfo.portB.reg
        piaPRB7.state = (bits & 0b10000000) != 0 ? .on : .off
        piaPRB6.state = (bits & 0b01000000) != 0 ? .on : .off
        piaPRB5.state = (bits & 0b00100000) != 0 ? .on : .off
        piaPRB4.state = (bits & 0b00010000) != 0 ? .on : .off
        piaPRB3.state = (bits & 0b00001000) != 0 ? .on : .off
        piaPRB2.state = (bits & 0b00000100) != 0 ? .on : .off
        piaPRB1.state = (bits & 0b00000010) != 0 ? .on : .off
        piaPRB0.state = (bits & 0b00000001) != 0 ? .on : .off

        bits = piaInfo.portB.port
        piaPB7.state = (bits & 0b10000000) != 0 ? .on : .off
        piaPB6.state = (bits & 0b01000000) != 0 ? .on : .off
        piaPB5.state = (bits & 0b00100000) != 0 ? .on : .off
        piaPB4.state = (bits & 0b00010000) != 0 ? .on : .off
        piaPB3.state = (bits & 0b00001000) != 0 ? .on : .off
        piaPB2.state = (bits & 0b00000100) != 0 ? .on : .off
        piaPB1.state = (bits & 0b00000010) != 0 ? .on : .off
        piaPB0.state = (bits & 0b00000001) != 0 ? .on : .off

        bits = piaInfo.portB.ext
        piaEXTB7.state = (bits & 0b10000000) != 0 ? .on : .off
        piaEXTB6.state = (bits & 0b01000000) != 0 ? .on : .off
        piaEXTB5.state = (bits & 0b00100000) != 0 ? .on : .off
        piaEXTB4.state = (bits & 0b00010000) != 0 ? .on : .off
        piaEXTB3.state = (bits & 0b00001000) != 0 ? .on : .off
        piaEXTB2.state = (bits & 0b00000100) != 0 ? .on : .off
        piaEXTB1.state = (bits & 0b00000010) != 0 ? .on : .off
        piaEXTB0.state = (bits & 0b00000001) != 0 ? .on : .off

        bits = piaInfo.portB.dir
        /*
        piaDDRB7I.isHidden = (bits & 0b10000000) != 0
        piaDDRB6I.isHidden = (bits & 0b01000000) != 0
        piaDDRB5I.isHidden = (bits & 0b00100000) != 0
        piaDDRB4I.isHidden = (bits & 0b00010000) != 0
        piaDDRB3I.isHidden = (bits & 0b00001000) != 0
        piaDDRB2I.isHidden = (bits & 0b00000100) != 0
        piaDDRB1I.isHidden = (bits & 0b00000010) != 0
        piaDDRB0I.isHidden = (bits & 0b00000001) != 0
        piaDDRB7O.isHidden = (bits & 0b10000000) == 0
        piaDDRB6O.isHidden = (bits & 0b01000000) == 0
        piaDDRB5O.isHidden = (bits & 0b00100000) == 0
        piaDDRB4O.isHidden = (bits & 0b00010000) == 0
        piaDDRB3O.isHidden = (bits & 0b00001000) == 0
        piaDDRB2O.isHidden = (bits & 0b00000100) == 0
        piaDDRB1O.isHidden = (bits & 0b00000010) == 0
        piaDDRB0O.isHidden = (bits & 0b00000001) == 0
        */
        piaDDRB7I.textColor = (bits & 0b10000000) == 0 ? .textColor : .secondaryLabelColor
        piaDDRB6I.textColor = (bits & 0b01000000) == 0 ? .textColor : .secondaryLabelColor
        piaDDRB5I.textColor = (bits & 0b00100000) == 0 ? .textColor : .secondaryLabelColor
        piaDDRB4I.textColor = (bits & 0b00010000) == 0 ? .textColor : .secondaryLabelColor
        piaDDRB3I.textColor = (bits & 0b00001000) == 0 ? .textColor : .secondaryLabelColor
        piaDDRB2I.textColor = (bits & 0b00000100) == 0 ? .textColor : .secondaryLabelColor
        piaDDRB1I.textColor = (bits & 0b00000010) == 0 ? .textColor : .secondaryLabelColor
        piaDDRB0I.textColor = (bits & 0b00000001) == 0 ? .textColor : .secondaryLabelColor
        piaDDRB7O.textColor = (bits & 0b10000000) != 0 ? .textColor : .secondaryLabelColor
        piaDDRB6O.textColor = (bits & 0b01000000) != 0 ? .textColor : .secondaryLabelColor
        piaDDRB5O.textColor = (bits & 0b00100000) != 0 ? .textColor : .secondaryLabelColor
        piaDDRB4O.textColor = (bits & 0b00010000) != 0 ? .textColor : .secondaryLabelColor
        piaDDRB3O.textColor = (bits & 0b00001000) != 0 ? .textColor : .secondaryLabelColor
        piaDDRB2O.textColor = (bits & 0b00000100) != 0 ? .textColor : .secondaryLabelColor
        piaDDRB1O.textColor = (bits & 0b00000010) != 0 ? .textColor : .secondaryLabelColor
        piaDDRB0O.textColor = (bits & 0b00000001) != 0 ? .textColor : .secondaryLabelColor

        piaDDRB7I.stringValue = (bits & 0b10000000) == 0 ? pass : block
        piaDDRB6I.stringValue = (bits & 0b01000000) == 0 ? pass : block
        piaDDRB5I.stringValue = (bits & 0b00100000) == 0 ? pass : block
        piaDDRB4I.stringValue = (bits & 0b00010000) == 0 ? pass : block
        piaDDRB3I.stringValue = (bits & 0b00001000) == 0 ? pass : block
        piaDDRB2I.stringValue = (bits & 0b00000100) == 0 ? pass : block
        piaDDRB1I.stringValue = (bits & 0b00000010) == 0 ? pass : block
        piaDDRB0I.stringValue = (bits & 0b00000001) == 0 ? pass : block
        piaDDRB7O.stringValue = (bits & 0b10000000) != 0 ? pass : block
        piaDDRB6O.stringValue = (bits & 0b01000000) != 0 ? pass : block
        piaDDRB5O.stringValue = (bits & 0b00100000) != 0 ? pass : block
        piaDDRB4O.stringValue = (bits & 0b00010000) != 0 ? pass : block
        piaDDRB3O.stringValue = (bits & 0b00001000) != 0 ? pass : block
        piaDDRB2O.stringValue = (bits & 0b00000100) != 0 ? pass : block
        piaDDRB1O.stringValue = (bits & 0b00000010) != 0 ? pass : block
        piaDDRB0O.stringValue = (bits & 0b00000001) != 0 ? pass : block
    }
}

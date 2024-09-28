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

        if full {

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

        /*
         vicScanline.integerValue = Int(vicInfo.scanline)
         vicRasterCycle.integerValue = Int(vicInfo.rasterCycle)
         vicYCounter.integerValue = Int(vicInfo.yCounter)
         vicXCounter.integerValue = Int(vicInfo.xCounter)
         */
    }
}

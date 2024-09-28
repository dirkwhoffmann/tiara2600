// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension Canvas {
 
    var texW: CGFloat { return CGFloat(TextureSize.original.width) }
    var texH: CGFloat { return CGFloat(TextureSize.original.height) }

    fileprivate func normalize(_ rect: CGRect) -> CGRect {
        
        return CGRect(x: rect.origin.x / texW,
                      y: rect.origin.y / texH,
                      width: rect.width / texW,
                      height: rect.height / texH)
    }
    
    // Returns the used texture area (including HBLANK and VBLANK)
    var entire: CGRect {
        
        // let w = (emu?.vic.traits.cyclesPerLine ?? 0) * 8
        // let h = emu?.vic.traits.linesPerFrame ?? 0
        let w = Constants.texWidth //  emu?.tia.traits.width ?? 0
        let h = Constants.texHeight // emu?.tia.traits.height ?? 0

        return CGRect(x: 0, y: 0, width: w, height: h)
    }
    
    var entireNormalized: CGRect {
        
        return normalize(entire)
    }
    
    // Returns the largest visibile texture area (excluding HBLANK and VBLANK)
    var largestVisible: CGRect {

        /*
        if emu?.vic.traits.pal == true {
            return CGRect(x: 104, y: 16, width: 487 - 104, height: 299 - 16)
        } else {
            return CGRect(x: 104, y: 16, width: 487 - 104, height: 249 - 16)
        }
        */

        let x = emu?.tia.traits.hblankWidth ?? 0
        let y = emu?.tia.traits.vblankHeight ?? 0
        let w = emu?.tia.traits.visibleWidth ?? 0
        let h = emu?.tia.traits.visibleHeight ?? 0

        return CGRect(x: x, y: y, width: w, height: h)
    }

    var largestVisibleNormalized: CGRect {
        
        return normalize(largestVisible)
    }

    // Returns the visible texture area based on the zoom and center parameters
    var visible: CGRect {
        
        /*
         *       aw <--------- maxWidth --------> dw
         *    ah |-----|---------------------|-----|
         *     ^ |     bw                   cw     |
         *     | -  bh *<----- width  ------>*     -
         *     | |     ^                     ^     |
         *     | |     |                     |     |
         *     | |   height                height  |
         *     | |     |                     |     |
         *     | |     v                     v     |
         *     | -  ch *<----- width  ------>*     -
         *     v |                                 |
         *    dh |-----|---------------------|-----|
         *
         *      aw/ah - dw/dh = largest posible texture cutout
         *      bw/bh - cw/ch = currently used texture cutout
         */
        
        let max = largestVisible
        
        let hCenter = CGFloat(renderer.config.hCenter) / 1000.0
        let vCenter = CGFloat(renderer.config.vCenter) / 1000.0
        let hZoom = CGFloat(renderer.config.hZoom) / 1000.0
        let vZoom = CGFloat(renderer.config.vZoom) / 1000.0
        let width = (1 - hZoom) * max.width
        let bw = max.minX + hCenter * (max.width - width)
        let height = (1 - vZoom) * max.height
        let bh = max.minY + vCenter * (max.height - height)
        
        return CGRect(x: bw, y: bh, width: width, height: height)
    }
    
    var visibleNormalized: CGRect {
        
        return normalize(visible)
    }

    func updateTextureRect() {
        
        textureRect = visibleNormalized
    }
}

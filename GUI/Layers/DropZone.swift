// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

import Foundation

class DropZone: Layer {

    static let unconnected = 0.92
    static let unselected = 0.92
    static let selected = 0.92

    var window: NSWindow { return controller.window! }
    var contentView: NSView { return window.contentView! }
    var metal: MetalView { return controller.metal! }
    var mydocument: MyDocument { return controller.mydocument! }
    var mm: MediaManager { return controller.mm }

    let numZones = 1

    var zones: [NSImageView]
    var ul: [NSPoint]
    var lr: [NSPoint]
    var enabled: [Bool]
    var inUse: [Bool]
    var inside: [Bool]
    var currentAlpha: [Double]
    var targetAlpha: [Double]
    var maxAlpha: [Double]
    var hideAll = false

    //
    // Initializing
    //
    
    override init(renderer: Renderer) {

        ul = [NSPoint](repeating: NSPoint(x: 0, y: 0), count: numZones)
        lr = [NSPoint](repeating: NSPoint(x: 0, y: 0), count: numZones)
        enabled = [Bool](repeating: false, count: numZones)
        inUse = [Bool](repeating: false, count: numZones)
        inside = [Bool](repeating: false, count: numZones)
        currentAlpha = [Double](repeating: 0.0, count: numZones)
        targetAlpha = [Double](repeating: DropZone.unselected, count: numZones)
        maxAlpha = [Double](repeating: 0.0, count: numZones)

        zones = [NSImageView]()
        zones.reserveCapacity(numZones)
        for _ in 0..<numZones { zones.append(NSImageView()) }
        for i in 0..<numZones { zones[i].unregisterDraggedTypes() }
        super.init(renderer: renderer)
        resize()
    }

    private func image(zone: Int) -> NSImage {

        let suffix = enabled[zone] ? (inUse[zone] ? "InUse" : "Empty") : "Disabled"
        return NSImage(named: "dropZone\(zone)\(suffix)")!
    }
    
    private func setType(_ type: tiara.FileType) {

        inUse[0] = true

        switch type {

        case .CART:
            enabled[0] = true

        default:
            enabled[0] = false
        }

        for i in 0..<numZones { zones[i].image = image(zone: i) }

        // Hide all drop zones if none is enabled
        hideAll = true
        for i in 0..<numZones where enabled[i] { hideAll = false }
    }

    func open(type: tiara.FileType, delay: Double) {

        setType(type)
        open(delay: delay)
        resize()
    }

    override func update(frames: Int64) {
        
        super.update(frames: frames)
        if alpha.current > 0 { updateAlpha() }
    }
    
    func isInside(_ sender: NSDraggingInfo, zone i: Int) -> Bool {

        assert(i >= 0 && i < numZones)

        let x = sender.draggingLocation.x
        let y = sender.draggingLocation.y

        return x > ul[i].x && x < lr[i].x && y > ul[i].y && y < lr[i].y
    }

    func draggingUpdated(_ sender: NSDraggingInfo) {
                   
        if hideAll { return }
        
        for i in 0..<numZones {

            if !enabled[i] {
                targetAlpha[i] = DropZone.unconnected
                continue
            }
            
            let isIn = isInside(sender, zone: i)

            if isIn && !inside[i] {
                
                inside[i] = true
                zones[i].image = NSImage(named: "dropZone\(i)Selected")
                targetAlpha[i] = DropZone.selected
            }

            if !isIn && inside[i] {

                inside[i] = false
                zones[i].image = image(zone: i)
                targetAlpha[i] = DropZone.unselected
            }
        }
    }
    
    override func alphaDidChange() {
                
        if hideAll { return }
        
        for i in 0..<numZones {

            maxAlpha[i] = Double(alpha.current)
        
            if alpha.current > 0 && zones[i].superview == nil {
                contentView.addSubview(zones[i])
            }
            if alpha.current == 0 && zones[i].superview != nil {
                zones[i].removeFromSuperview()
            }
        }
        
        resize()
    }

    override func layerDidClose() {

        guard let url = metal.dropUrl else { return }
        guard let type = metal.dropType else { return }

        do {

            if let n = metal.dropZone {

                switch n {

                case 0: try mm.addMedia(url: url, allowedTypes: [type])

                default:
                    fatalError()
                }

            } else {

                switch type {

                case .SNAPSHOT:

                    try mm.addMedia(url: url, allowedTypes: [type])

                case .SCRIPT:

                    try mm.addMedia(url: url, allowedTypes: [type])
                    mm.console.open()

                default:
                    
                    NSSound.beep()
                }
            }

        } catch {

            controller.showAlert(.cantOpen(url: url), error: error, async: true)
        }
    }

    func updateAlpha() {
            
        for i in 0..<numZones {

            let current = currentAlpha[i]
            var delta = 0.0

            if current < targetAlpha[i] && current < maxAlpha[i] { delta = 0.05 }
            if current > targetAlpha[i] || current > maxAlpha[i] { delta = -0.05 }

            if delta != 0.0 {
                
                currentAlpha[i] += delta
                zones[i].alphaValue = CGFloat(currentAlpha[i])
            }
        }
    }
    
    func resize() {
                         
        let size = controller.metal.frame.size
        let origin = controller.metal.frame.origin
        let midx = origin.x + (size.width / 2)

        let w = size.width / 6
        let h = w * 1.2
        let y = size.height + origin.y - 24 - h * CGFloat(alpha.current)
        let margin = w / 8
        let totalw = Double(numZones) * w + (Double(numZones) - 1) * margin

        var x = midx - (totalw / 2)

        for i in 0..<numZones {

            ul[i] = CGPoint(x: x, y: y)
            lr[i] = CGPoint(x: ul[i].x + w, y: ul[i].y + h)

            zones[i].setFrameSize(NSSize(width: w, height: h))
            zones[i].frame.origin = ul[i]

            x += w + margin
        }
    }
}

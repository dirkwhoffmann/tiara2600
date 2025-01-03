// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

import Foundation

class HoverImageView: NSImageView {

    private var trackingArea: NSTrackingArea?
    private var dropZone: DropZone?
    var nr = 0
    var state = false

    convenience init(nr: Int, dropZone: DropZone) {

        self.init()
        self.nr = nr
        self.dropZone = dropZone

        updateImage(hover: false)
    }

    override func updateTrackingAreas() {

        super.updateTrackingAreas()

        if let trackingArea = trackingArea {
            removeTrackingArea(trackingArea)
        }

        let options: NSTrackingArea.Options = [.mouseEnteredAndExited, .activeInKeyWindow]
        trackingArea = NSTrackingArea(rect: bounds, options: options, owner: self, userInfo: nil)

        if let trackingArea = trackingArea {
            addTrackingArea(trackingArea)
        }
    }

    override func mouseEntered(with event: NSEvent) {

        super.mouseEntered(with: event)
        updateImage(hover: true)
    }

    override func mouseExited(with event: NSEvent) {

        super.mouseExited(with: event)
        updateImage(hover: false)
    }

    override func mouseDown(with event: NSEvent) {

        super.mouseDown(with: event)
        state = !state
        updateImage(hover: false)
        dropZone?.click(zone: nr)
    }

    func updateImage(hover: Bool) {

        image = NSImage(named: "switch\(nr)\(state ? "1" : "0")\(hover ? "b" : "a")")!
    }
}

class DropZone: Layer {

    static let unconnected = 0.92
    static let unselected = 0.92
    static let selected = 0.92

    var window: NSWindow { return controller.window! }
    var contentView: NSView { return window.contentView! }
    var metal: MetalView { return controller.metal! }
    var mydocument: MyDocument { return controller.mydocument! }
    var mm: MediaManager { return controller.mm }

    let numZones = 5

    var zones: [HoverImageView]
    var ul: [NSPoint]
    var lr: [NSPoint]
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
        currentAlpha = [Double](repeating: 0.0, count: numZones)
        targetAlpha = [Double](repeating: DropZone.unselected, count: numZones)
        maxAlpha = [Double](repeating: 0.0, count: numZones)
        zones = [HoverImageView]()
        zones.reserveCapacity(numZones)

        super.init(renderer: renderer)

        for i in 0..<numZones { zones.append(HoverImageView(nr: i, dropZone: self)) }
        for i in 0..<numZones { zones[i].unregisterDraggedTypes() }

        resize()
    }

    func open(type: FileType, delay: Double) {

        open(delay: delay)

        if let info = emu?.atari?.info {

            func update(zone nr: Int, slider: Slider) {

                switch slider.rawValue {
                case 0: zones[nr].state = info.slider.0
                case 1: zones[nr].state = info.slider.1
                case 2: zones[nr].state = info.slider.2
                case 3: zones[nr].state = info.slider.3
                case 4: zones[nr].state = info.slider.4
                default: fatalError()
                }
            }

            update(zone: 0, slider: Slider.COLOR)
            update(zone: 1, slider: Slider.DIFFA)
            update(zone: 2, slider: Slider.DIFFB)
            update(zone: 3, slider: Slider.SELECT)
            update(zone: 4, slider: Slider.RESET)
        }
        for i in 0..<numZones { zones[i].updateImage(hover: false) }
        resize()
    }

    override func update(frames: Int64) {
        
        super.update(frames: frames)
        if alpha.current > 0 { updateAlpha() }
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

    /*
    override func layerDidClose() {

    }
    */
    
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

    func click(zone: Int) {

        let val = zones[zone].state
        let cmd: tiara.SliderCmd

        switch zone {

        case 0:  cmd = SliderCmd(slider: .COLOR, value: val, delay: 0.0)
        case 1:  cmd = SliderCmd(slider: .DIFFA, value: val, delay: 0.0)
        case 2:  cmd = SliderCmd(slider: .DIFFB, value: val, delay: 0.0)
        case 3:  cmd = SliderCmd(slider: .SELECT, value: val, delay: 0.2)
        case 4:  cmd = SliderCmd(slider: .RESET, value: val, delay: 0.2)

        default:
            fatalError()
        }

        emu?.put(.SET_SLIDER, slider: cmd)

        print("Zone \(zone) clicked")
        close()
    }
}

// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

// import Cocoa

class LogicView: NSView {

    // Reference to the logic analyzer this view is embedded in
    @IBOutlet weak var analyzer: LogicAnalyzer!

    // Reference to the emulator
    var emu: EmulatorProxy? { return analyzer.emu }

    // The visualized rasterline
    var line: Int { return analyzer.line }

    // The probed signal
    var probe: tiara.Probe = .PHI1

    // Bit-width of the probed signal (e.g., 8 for data bus, 1 for RDY)
    var bitWidth = 1

    // The recorded data
    var data = (0...230).map( {_ in Int.random(in: 0...1) })

    // The graphics context used for drawing
    var context: CGContext!

    // Fonts and colors
    let box = NSBox()
    var signalColor = NSColor(r: 0x55, g: 0x83, b: 0xAC)
    let mono = NSFont.monospacedSystemFont(ofSize: 10, weight: .bold)
    let system = NSFont.systemFont(ofSize: 8)

    override func awakeFromNib() {

    }

    func update() {

        updateData()
        needsDisplay = true
    }

    func updateData() {

        if var values = emu?.logicAnalyzer.getData(line) {

            switch probe {

            case .ADDR_BUS: for i in 0..<228 { data[i] = Int((values + i).pointee.addrBus) }
            case .DATA_BUS: for i in 0..<228 { data[i] = Int(values.pointee.dataBus); values += 1 }
            case .PHI1:     for i in 0..<228 { data[i] = (values + i).pointee.phi1 ? 1 : 0 }
            case .PHI2:     for i in 0..<228 { data[i] = values.pointee.phi2 ? 1 : 0; values += 1 }
            case .RDY:      for i in 0..<228 { data[i] = values.pointee.rdy ? 1 : 0; values += 1 }
            case .VSYNC:    for i in 0..<228 { data[i] = values.pointee.vsync ? 1 : 0; values += 1 }
            case .VBLANK:   for i in 0..<228 { data[i] = values.pointee.vblank ? 1 : 0; values += 1 }

            default:
                break
            }
        }

        switch probe {

        case .ADDR_BUS: bitWidth = 16
        case .DATA_BUS: bitWidth = 8
        default: bitWidth = 1
        }
    }

    func clear(context: CGContext?) {

        box.fillColor.setFill()
        // NSColor.windowBackgroundColor.setFill()
        bounds.fill()

        let dx = bounds.width / 228
        for i in 0..<228 {

            drawText(text: "\(i)",
                     at: CGPoint(x: CGFloat(i) * dx + (dx / 2), y: bounds.height - 15),
                     font: system,
                     color: NSColor.secondaryLabelColor)
        }
    }

    override func draw(_ dirtyRect: NSRect) {

        // print("draw")
        super.draw(dirtyRect)

        context = NSGraphicsContext.current?.cgContext

        clear(context: context)
        drawSignal(color: signalColor)
    }

    func drawText(text: String, at point: CGPoint, font: NSFont, color: NSColor) {

        // Save the current graphics state
        context?.saveGState()

        // Set up the attributes
        let attributes: [NSAttributedString.Key: Any] = [ .font: font, .foregroundColor: color ]

        // Create the attributed string
        let attributedString = NSAttributedString(string: text, attributes: attributes)
        let size = attributedString.size()

        // Draw the string
        let p = CGPoint(x: point.x - size.width / 2, y: point.y - size.height / 2)
        attributedString.draw(at: p)

        // Restore the graphics state
        context?.restoreGState()
    }

    func drawSignal(color: NSColor) {

        let w = bounds.size.width / 228
        let bottomMargin = CGFloat(10)
        let h = CGFloat(24)

        var prev = -1
        var curr = data[0]
        var next = data[1]

        for i in 0..<228 {

            drawSegment(rect: CGRect(x: CGFloat(i) * w, y: bottomMargin, width: w, height: h),
                        v: [prev, curr, next],
                        color: color)

            let txt = "\(curr)"
            drawText(text: txt,
                     at: CGPoint(x: CGFloat(i) * w + (w / 2), y: bottomMargin + (h / 2)),
                     font: mono,
                     color: NSColor.labelColor)

            prev = curr
            curr = next
            next = data[i+2]
        }
    }

    var rectangle: CGRect {

        let margin = CGFloat(10)
        let width = bounds.size.width - 2 * margin
        let height = bounds.size.height - 2 * margin
        let rect = CGRect(x: margin, y: margin, width: width, height: height)
        return rect
    }

    func drawSegment(rect: CGRect, v: [Int], color: NSColor) {

        let path = CGMutablePath()

        let x1 = rect.minX
        let y1 = rect.minY
        let x2 = rect.maxX
        let y2 = rect.maxY

        if bitWidth == 1 {

            /*          p2                  p3
             *          .-------------------.
             *          |                   |
             *          |                   |
             *          p1                  p4
             */

            let p1 = CGPoint(x: x1, y: v[0] == 0 ? y1 : y2)
            let p2 = CGPoint(x: x1, y: v[1] == 0 ? y1 : y2)
            let p3 = CGPoint(x: x2, y: v[1] == 0 ? y1 : y2)
            let p4 = CGPoint(x: x2, y: v[2] == 0 ? y1 : y2)

            path.move(to: p1)
            path.addLine(to: p2)
            path.addLine(to: p3)
            path.addLine(to: p4)

        } else {

            /*           p2               p3
             *           /-----------------\
             *          /                   \
             *   p1/p8 .                     . p4/p5
             *          \                   /
             *           \-----------------/
             *           p7               p6
             */

            let m = 0.1 * rect.width
            let p1 = CGPoint(x: x1, y: v[0] == v[1] ? y1 : rect.midY)
            let p2 = CGPoint(x: x1 + m, y: y1)
            let p3 = CGPoint(x: x2 - m, y: y1)
            let p4 = CGPoint(x: x2, y: v[1] == v[2] ? y1 : rect.midY)
            let p5 = CGPoint(x: x2, y: v[1] == v[2] ? y2 : rect.midY)
            let p6 = CGPoint(x: x2 - m, y: y2)
            let p7 = CGPoint(x: x1 + m, y: y2)
            let p8 = CGPoint(x: x1, y: v[0] == v[1] ? y2 : rect.midY)

            path.move(to: p1)
            // path.addLine(to: p1)
            path.addLine(to: p2)
            path.addLine(to: p3)
            path.addLine(to: p4)
            // path.addLine(to: p5)
            path.move(to: p5)
            path.addLine(to: p6)
            path.addLine(to: p7)
            path.addLine(to: p8)
        }

        context.setLineWidth(2.0)
        context.setStrokeColor(color.cgColor)

        context.addPath(path)
        context.drawPath(using: .stroke)
    }

}

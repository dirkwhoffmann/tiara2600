// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

class LogicView: NSView {

    // Reference to the logic analyzer this view is embedded in
    @IBOutlet weak var analyzer: LogicAnalyzer!

    // Reference to the emulator
    var emu: EmulatorProxy? { return analyzer.emu }

    // The visualized rasterline
    var line: Int { return analyzer.line }

    // Beam position
    var x: Int?
    var y: Int?

    // The probed signal
    var probe: [tiara.Probe] = [ .ADDR_BUS, .DATA_BUS, .PHI1, .PHI2 ]

    // Bit-width of the probed signals (e.g., 8 for data bus, 1 for RDY)
    var bitWidth: [Int] = [ 16, 8, 1, 1 ]

    // The recorded data
    var data = Array(repeating: Array(repeating: 0, count: 230), count: 4)

    // Number formatter
    let formatter = LogicViewFormatter()

    // The graphics context used for drawing
    var context: CGContext!
    var gradient: CGGradient?

    // Fonts and colors
    let box = NSBox()
    var signalColor = [ NSColor.white, NSColor.white, NSColor.white, NSColor.white ]
    let mono = NSFont.monospacedSystemFont(ofSize: 10, weight: .regular)
    let system = NSFont.systemFont(ofSize: 8)

    override func awakeFromNib() {

        super.awakeFromNib()

        // Setup gradient
        let colorSpace = CGColorSpaceCreateDeviceRGB()
        let colors: [CGColor] = [
            NSColor(r: 0xFE, g: 0xFF, b: 0xEA).cgColor,
            NSColor(r: 0xD0, g: 0xD3, b: 0xC1).cgColor
        ]
        gradient = CGGradient(colorsSpace: colorSpace, colors: colors as CFArray, locations: [0.0, 1.0])
    }

    func update() {

        updateData()
        needsDisplay = true
    }

    //
    // Managing the data source
    //

    func updateData() {

        guard let emu = emu else { return }

        if let values = emu.logicAnalyzer.getData(line) {

            for c in 0...3 {

                switch probe[c] {

                case .ADDR_BUS: for i in 0..<228 { data[c][i] = Int((values + i).pointee.addrBus) }
                case .DATA_BUS: for i in 0..<228 { data[c][i] = Int((values + i).pointee.dataBus) }
                case .PHI1:     for i in 0..<228 { data[c][i] = (values + i).pointee.phi1 ? 1 : 0 }
                case .PHI2:     for i in 0..<228 { data[c][i] = (values + i).pointee.phi2 ? 1 : 0 }
                case .RDY:      for i in 0..<228 { data[c][i] = (values + i).pointee.rdy ? 1 : 0 }
                case .VSYNC:    for i in 0..<228 { data[c][i] = (values + i).pointee.vsync ? 1 : 0 }
                case .VBLANK:   for i in 0..<228 { data[c][i] = (values + i).pointee.vblank ? 1 : 0 }
                default: break
                }

                switch probe[c] {

                case .ADDR_BUS: bitWidth[c] = 16
                case .DATA_BUS: bitWidth[c] = 8
                default: bitWidth[c] = 1
                }
            }
        }
    }

    func getData(x pos: Int, channel: Int) -> Int? {

        if let x = x, let y = y {
            return line < y || (line == y && pos < x) ? data[channel][pos] : nil
        } else {
            return data[channel][pos]
        }
    }

    //
    // Drawing
    //

    func clear() {

        box.fillColor.setFill()
        // NSColor.controlBackgroundColor.setFill()
        bounds.fill()

        /*
        let startPoint = CGPoint(x: 0.0, y: bounds.minY)
        let endPoint = CGPoint(x: 0, y: bounds.maxY)
        context.drawLinearGradient(gradient!, start: startPoint, end: endPoint, options: [])
        */

        let path = CGMutablePath()
        let dx = bounds.width / 228

        for i in 1...227 {

            path.move(to: CGPoint(x: CGFloat(i) * dx, y: bounds.minY))
            path.addLine(to: CGPoint(x: CGFloat(i) * dx, y: bounds.maxY))
        }
        context.setLineWidth(0.5)
        context.setStrokeColor(NSColor.secondaryLabelColor.cgColor)

        context.addPath(path)
        context.drawPath(using: .stroke)

    }

    func drawMarkers(in rect: NSRect) {

        let dx = rect.width / 228
        for i in 0..<228 {

            drawText(text: "\(i)",
                     at: CGPoint(x: CGFloat(i) * dx + (dx / 2), y: rect.midY),
                     font: system,
                     color: NSColor.secondaryLabelColor)
        }
    }

    func drawMarkers() {

        drawMarkers(in: bounds)
    }

    override func draw(_ dirtyRect: NSRect) {

        let dy = CGFloat(36)

        super.draw(dirtyRect)
        context = NSGraphicsContext.current?.cgContext

        clear()
        drawMarkers(in: NSRect(x: bounds.minX,
                               y: bounds.maxY - dy,
                               width: bounds.width,
                               height: 24))
        for i in 0...3 {

            let rect = NSRect(x: bounds.minX,
                              y: bounds.maxY - CGFloat(i + 2) * dy,
                              width: bounds.width,
                              height: 24)
            drawSignalTrace(in: rect, channel: i)
        }
    }

    func drawSignalTrace(in rect: NSRect, channel: Int) {

        let info = analyzer.emu!.tia.info
        /*
        let x = info.posx
        let y = info.posy
        if y < analyzer.line { return }
        */
        let w = rect.size.width / 228

        var prev: Int?
        var curr: Int? = getData(x: 0, channel: channel)
        var next: Int? = getData(x: 1, channel: channel)

        for i in 0..<228 {

            if curr == nil { break }

            let r = CGRect(x: CGFloat(i) * w,
                           y: rect.minY,
                           width: w,
                           height: rect.height)

            if bitWidth[channel] == 1 {
                drawLineSegment(in: r, v: [prev, curr, next], color: signalColor[channel])
            } else {
                drawDataSegment(in: r, v: [prev, curr, next], color: signalColor[channel])
            }
            drawText(text: formatter.string(from: curr!, bitWidth: bitWidth[channel]),
                     at: CGPoint(x: CGFloat(i) * w + (w / 2), y: rect.midY),
                     font: mono,
                     color: NSColor.labelColor)

            prev = curr
            curr = next
            next = getData(x: i+2, channel: channel)
        }
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

    var rectangle: CGRect {

        let margin = CGFloat(10)
        let width = bounds.size.width - 2 * margin
        let height = bounds.size.height - 2 * margin
        let rect = CGRect(x: margin, y: margin, width: width, height: height)
        return rect
    }

    func drawLineSegment(in rect: CGRect, v: [Int?], color: NSColor) {

        if v[1] == nil { return }

        let path = CGMutablePath()

        let x1 = rect.minX
        let y1 = rect.minY
        let x2 = rect.maxX
        let y2 = rect.maxY

        /*          p2                  p3
         *          .-------------------.
         *          |                   |
         *          |                   |
         *          p1                  p4
         */

        let p2 = CGPoint(x: x1, y: v[1] == 1 ? y2 : y1)
        let p1 = v[0] != nil ? CGPoint(x: x1, y: v[0] == 1 ? y2 : y1) : p2
        let p3 = CGPoint(x: x2, y: v[1] == 1 ? y2 : y1)
        let p4 = v[2] != nil ? CGPoint(x: x2, y: v[2] == 1 ? y2 : y1) : p3

        path.move(to: p1)
        path.addLine(to: p2)
        path.addLine(to: p3)
        path.addLine(to: p4)

        context.setLineWidth(2.0)
        context.setStrokeColor(color.cgColor)

        context.addPath(path)
        context.drawPath(using: .stroke)
    }

    func drawDataSegment(in rect: CGRect, v: [Int?], color: NSColor) {

        if v[1] == nil { return }

        let path = CGMutablePath()

        let x1 = rect.minX
        let y1 = rect.minY
        let x2 = rect.maxX
        let y2 = rect.maxY

        /*           p2               p3
         *           /-----------------\
         *          /                   \
         *   p1/p8 .                     . p4/p5
         *          \                   /
         *           \-----------------/
         *           p7               p6
         */

        let m = 0.1 * rect.width
        let p1 = CGPoint(x: x1, y: (v[0] == nil || v[0] == v[1]) ? y1 : rect.midY)
        let p2 = CGPoint(x: x1 + m, y: y1)
        let p3 = CGPoint(x: x2 - m, y: y1)
        let p4 = CGPoint(x: x2, y: (v[2] == nil || v[1] == v[2]) ? y1 : rect.midY)
        let p5 = CGPoint(x: x2, y: (v[2] == nil || v[1] == v[2]) ? y2 : rect.midY)
        let p6 = CGPoint(x: x2 - m, y: y2)
        let p7 = CGPoint(x: x1 + m, y: y2)
        let p8 = CGPoint(x: x1, y: (v[0] == nil || v[0] == v[1]) ? y2 : rect.midY)

        path.move(to: p1)
        path.addLine(to: p2)
        path.addLine(to: p3)
        path.addLine(to: p4)
        path.move(to: p5)
        path.addLine(to: p6)
        path.addLine(to: p7)
        path.addLine(to: p8)

        context.setLineWidth(2.0)
        context.setStrokeColor(color.cgColor)

        context.addPath(path)
        context.drawPath(using: .stroke)
    }

}

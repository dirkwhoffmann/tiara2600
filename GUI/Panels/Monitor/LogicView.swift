//
//  LogicView.swift
//  Tiara
//
//  Created by Dirk Hoffmann on 04.10.24.
//

import Cocoa

class LogicView: NSView {

    var initialized = false

    let arr = (0...230).map( {_ in Int.random(in: 0...1) })

    override func awakeFromNib() {

    }

    func clear(context: CGContext?) {

        // NSColor.darkGray.setFill()
        NSColor.windowBackgroundColor.setFill()
        bounds.fill()

        let dx = bounds.width / 228
        for i in 0..<228 {

            drawText(in: context,
                     text: "\(i)",
                     at: CGPoint(x: CGFloat(i) * dx + (dx / 2), y: bounds.height - 15),
                     color: NSColor.secondaryLabelColor)
        }

        // initialized = true

        // rect.origin.y = rect.midY
        // rect.size.height = rect.height - 15
        // NSColor.yellow.setFill()
        // rect.fill()
    }

    override func draw(_ dirtyRect: NSRect) {

        // print("draw")
        super.draw(dirtyRect)

        let context = NSGraphicsContext.current?.cgContext

        clear(context: context)
        drawSignal(context: context, color: NSColor.cyan)
    }

    func drawText(in context: CGContext?, text: String, at point: CGPoint, color: NSColor) {

        // Save the current graphics state
        context?.saveGState()

        // Set up the attributes
        let attributes: [NSAttributedString.Key: Any] = [
            .font: NSFont.systemFont(ofSize: 10),
            .foregroundColor: color
        ]

        // Create the attributed string
        let attributedString = NSAttributedString(string: text, attributes: attributes)
        let size = attributedString.size()

        // Draw the string
        let p = CGPoint(x: point.x - size.width / 2, y: point.y - size.height / 2)
        attributedString.draw(at: p)

        // Restore the graphics state
        context?.restoreGState()
    }

    func drawSignal(context: CGContext?, color: NSColor) {

        let w = bounds.size.width / 228
        let margin = bounds.size.height / 4

        for i in 0..<228 {

            let r = CGRect(x: CGFloat(i) * w, y: margin, width: w, height: bounds.size.height - 2 * margin)
            drawSegment(rect: r,
                        context: context,
                        v: [arr[i], arr[i+1], arr[i+2]],
                        color: color)

            // let txt = arr[i+1] == 0 ? "VDELP0" : "WSYNC"
            let txt = "\(arr[i+1])"
            drawText(in: context,
                     text: txt,
                     at: CGPoint(x: CGFloat(i) * w + (w / 2), y: bounds.size.height / 2.0),
                     color: NSColor.labelColor)
        }
    }

    var rectangle: CGRect {

        let margin = CGFloat(10)
        let width = bounds.size.width - 2 * margin
        let height = bounds.size.height - 2 * margin
        let rect = CGRect(x: margin, y: margin, width: width, height: height)
        return rect
    }

    func drawSegment(rect: CGRect, context: CGContext?, v: [Int], color: NSColor) {

        let path = CGMutablePath()

        /*           p2               p3
         *           /-----------------\
         *          /                   \
         *   p1/p8 .                     . p4/p5
         *          \                   /
         *           \-----------------/
         *           p7               p6
         */

        let x1 = rect.minX
        let y1 = rect.minY
        let x2 = rect.maxX
        let y2 = rect.maxY
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

        context?.setLineWidth(2.0)
        context?.setStrokeColor(color.cgColor)

        context?.addPath(path)
        context?.drawPath(using: .stroke)
    }

}

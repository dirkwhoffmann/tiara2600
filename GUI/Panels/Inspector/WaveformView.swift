// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

import Foundation

class WaveformView: NSImageView {

    @IBOutlet weak var inspector: Inspector!

    var audioPort: AudioPortProxy? { return inspector.emu?.audioPort }

    // Waveform size
    var size: NSSize!
    var wordCount: Int { return Int(size.width) * Int(size.height) }

    // Waveform buffer
    var buffer: UnsafeMutablePointer<UInt32>!

    // Remembers the highest amplitude (used for auto scaling)
    var maxAmp: Float = 0.001

    // Foreground color
    let color = UInt32(NSColor.gray.usingColorSpace(.sRGB)!.gpuColor)

    required init?(coder decoder: NSCoder) {

        super.init(coder: decoder)
    }

    required override init(frame frameRect: NSRect) {
        
        super.init(frame: frameRect)
    }

    override func awakeFromNib() {

        let w = inspector.aud0WaveformView.visibleRect.width
        let h = inspector.aud0WaveformView.visibleRect.height

        size = NSSize(width: w, height: h)
        buffer = UnsafeMutablePointer<UInt32>.allocate(capacity: wordCount)
    }

    func update() {

        needsDisplay = true
    }

    override func draw(_ dirtyRect: NSRect) {

        maxAmp = audioPort?.drawWaveform(buffer, size: size, scale: maxAmp, color: color, source: tag) ?? 0
        image = NSImage.make(data: buffer, rect: CGSize(width: size.width, height: size.height))
        super.draw(dirtyRect)
    }
}

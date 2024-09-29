// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension NSDraggingInfo {

    var url: URL? {
        let pasteBoard = draggingPasteboard
        let types = [NSPasteboard.PasteboardType.fileURL]
        if pasteBoard.availableType(from: types) != nil {
            return NSURL(from: pasteBoard) as URL?
        }
        return nil
    }
}

class DropView: NSImageView {

    @IBOutlet var parent: ConfigurationController!
    var emu: EmulatorProxy? { return parent.emu }

    override func awakeFromNib() {

        registerForDraggedTypes([NSPasteboard.PasteboardType.fileURL])
    }
    
    func acceptDragSource(url: URL) -> Bool { return false }

    override func draggingEntered(_ sender: NSDraggingInfo) -> NSDragOperation {

        if let url = sender.url {
            if acceptDragSource(url: url) {
                image = NSImage(named: "rom_medium")
                return .copy
            }
        }
        return NSDragOperation()
    }

    override func performDragOperation(_ sender: NSDraggingInfo) -> Bool {

        return false
    }

    override func draggingExited(_ sender: NSDraggingInfo?) {

        parent.refresh()
    }
    
    override func prepareForDragOperation(_ sender: NSDraggingInfo) -> Bool {

        return true
    }
    
    override func concludeDragOperation(_ sender: NSDraggingInfo?) {

        parent.refresh()
    }
}

class RomDropView: DropView {

    func performDrag(url: URL?) -> Bool {

        guard let url = url?.unpacked else { return false }

        do {

            let rom = try MediaFileProxy.make(with: url)
            emu?.loadRom(rom)

            return true

        } catch {

            parent.parent.showAlert(.cantOpen(url: url),
                                    error: error,
                                    async: true,
                                    window: parent.window)
            return false
        }
    }

    override func acceptDragSource(url: URL) -> Bool {

        return emu?.isRom(url) ?? false
    }

    override func performDragOperation(_ sender: NSDraggingInfo) -> Bool {

        return performDrag(url: sender.url)
    }
}

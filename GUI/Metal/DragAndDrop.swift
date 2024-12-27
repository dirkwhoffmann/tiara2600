// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

import UniformTypeIdentifiers

public extension MetalView {

    func setupDragAndDrop() {

        registerForDraggedTypes(acceptedTypes())
    }

    func acceptedTypes() -> [NSPasteboard.PasteboardType] {
        
        return [.fileURL, .string, .fileContents]
    }

    override func draggingEntered(_ sender: NSDraggingInfo) -> NSDragOperation {
        
        let pasteBoard = sender.draggingPasteboard
        guard let type = pasteBoard.availableType(from: acceptedTypes()) else {
            return NSDragOperation()
        }

        dropUrl = nil
        dropType = nil
        
        switch type {
            
        case .string:
            return NSDragOperation.copy
        
        case .fileContents:
            return NSDragOperation.copy
            
        case .fileURL:

            if let url = NSURL(from: pasteBoard) as URL? {
            
                // Unpack the file if it is compressed
                dropUrl = url.unpacked(maxSize: 2048 * 1024)
                
                // Analyze the file type
                let type = MediaFileProxy.type(of: dropUrl)
            }
                
            return NSDragOperation.copy
            
        default:
            return NSDragOperation()
        }
    }

    override func draggingUpdated(_ sender: NSDraggingInfo) -> NSDragOperation {
        
        return NSDragOperation.copy
    }
    
    override func draggingExited(_ sender: NSDraggingInfo?) {
    
        parent.renderer.dropZone.close(delay: 0.25)
    }
    
    override func prepareForDragOperation(_ sender: NSDraggingInfo) -> Bool {
        
        parent.renderer.dropZone.close(delay: 0.25)
        return true
    }
    
    override func performDragOperation(_ sender: NSDraggingInfo) -> Bool {

        let pasteBoard = sender.draggingPasteboard

        if let type = pasteBoard.availableType(from: acceptedTypes()) {

            switch type {

            case .fileURL:
                return performUrlDrag(sender)

            default:
                break
            }
        }

        return false
    }

    func performUrlDrag(_ sender: NSDraggingInfo) -> Bool {

        // Only proceed if an URL is given
        guard let url = dropUrl else { return false }

        // Only proceed if a file type can be derived
        guard let type = FileType(url: dropUrl) else { return false }

        // Only proceed if a draggable type is given
        if !FileType.draggable.contains(type) { return false }

        do {

            switch type {
                
            case .CART:
                
                try parent.mm.addMedia(url: url, allowedTypes: [type])
                parent.emu?.pause()
                parent.emu?.atari.hardReset()
                try? parent.emu?.run()
                
            case .SNAPSHOT:
                
                try parent.mm.addMedia(url: url, allowedTypes: [type])
                try parent.emu?.run()
                
            case .SCRIPT:
                
                try parent.mm.addMedia(url: url, allowedTypes: [type])
                parent.mm.console.open()
                
            default:
                
                NSSound.beep()
            }

        } catch {

            parent.showAlert(.cantOpen(url: url), error: error, async: true)
        }
        
        
        return true
    }

    override func concludeDragOperation(_ sender: NSDraggingInfo?) {
    }
}

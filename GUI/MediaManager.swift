// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

class MediaManager {

    struct Option: OptionSet {

        let rawValue: Int

        static let force       = Option(rawValue: 1 << 0)
        static let remember    = Option(rawValue: 1 << 1)
        static let protect     = Option(rawValue: 1 << 2)
        static let reset       = Option(rawValue: 1 << 3)
        static let autostart   = Option(rawValue: 1 << 4)
    }

    // References to other objects
    var document: MyDocument!
    var emu: EmulatorProxy? { return document.emu }
    var controller: MyController { return document.parent }
    var console: Console { return controller.renderer.console }

    // Shared list of recently inserted tapes
    static var insertedTapes: [URL] = []

    // Shared list of recently attached cartridges
    static var attachedCartridges: [URL] = []

    // Shared list of recently inserted floppy disks
    static var insertedFloppyDisks: [URL] = []

    // Unshared list of recently exported floppy disks
    var exportedFloppyDisks: [[URL]] = [[URL]](repeating: [URL](), count: 2)

    //
    // Initializing
    //

    init(with document: MyDocument) {

        debug(.lifetime, "Creating media manager")
        self.document = document
    }

    //
    // Handling lists of recently used URLs
    //

    static func noteRecentlyUsedURL(_ url: URL, to list: inout [URL], size: Int) {

        if !list.contains(url) {

            // Shorten the list if it is too large
            if list.count == size { list.remove(at: size - 1) }

            // Add new item at the beginning
            list.insert(url, at: 0)
        }
    }

    static func getRecentlyUsedURL(_ pos: Int, from list: [URL]) -> URL? {
        return (pos < list.count) ? list[pos] : nil
    }

    // Import URLs (shared among all emulator instances and drives)

    static func noteNewRecentlyInsertedTapeURL(_ url: URL) {
        noteRecentlyUsedURL(url, to: &insertedTapes, size: 10)
    }

    static func getRecentlyInsertedTapeURL(_ pos: Int) -> URL? {
        return getRecentlyUsedURL(pos, from: insertedTapes)
    }

    static func noteNewRecentlyAtachedCartridgeURL(_ url: URL) {
        noteRecentlyUsedURL(url, to: &attachedCartridges, size: 10)
    }

    static func getRecentlyAtachedCartridgeURL(_ pos: Int) -> URL? {
        return getRecentlyUsedURL(pos, from: attachedCartridges)
    }

    static func noteNewRecentlyInsertedDiskURL(_ url: URL) {
        noteRecentlyUsedURL(url, to: &insertedFloppyDisks, size: 10)
    }

    static func getRecentlyInsertedDiskURL(_ pos: Int) -> URL? {
        return getRecentlyUsedURL(pos, from: insertedFloppyDisks)
    }

    static func noteNewRecentlyUsedURL(_ url: URL) {

        switch url.pathExtension.uppercased() {

        case "D64", "T64", "G64", "PRG", "P00":
            noteNewRecentlyInsertedDiskURL(url)

        case "TAP":
            noteNewRecentlyInsertedTapeURL(url)

        case "CRT":
            noteNewRecentlyAtachedCartridgeURL(url)

        default:
            break
        }
    }

    //
    // Loading media files
    //

    func createFileProxy(from url: URL, allowedTypes: [FileType]) throws -> MediaFileProxy {

        debug(.media, "Reading file \(url.lastPathComponent)")

        // If the provided URL points to compressed file, decompress it first
        let newUrl = url.unpacked(maxSize: 2048 * 1024)

        // Iterate through all allowed file types
        for type in allowedTypes {

            do {
                switch type {

                case .SNAPSHOT:
                    return try MediaFileProxy.make(with: newUrl, type: .SNAPSHOT)

                case .SCRIPT:
                    return try MediaFileProxy.make(with: newUrl, type: .SCRIPT)

                case .CART:
                    return try MediaFileProxy.make(with: newUrl, type: .CART)

                default:
                    fatalError()
                }

            } catch let error as VC64Error {
                if error.errorCode != .FILE_TYPE_MISMATCH {
                    throw error
                }
            }
        }

        // None of the allowed types matched the file
        throw VC64Error(.FILE_TYPE_MISMATCH,
                        "The type of this file is not known to the emulator.")
    }

    //
    // Importing media files
    //

    func addMedia(url: URL,
                  allowedTypes types: [FileType] = FileType.all,
                  options: [Option] = [.remember]) throws {

        debug(.media, "url = \(url) types = \(types)")

        // Read file
        let file = try createFileProxy(from: url, allowedTypes: types)

        // Remember the URL if requested
        if options.contains(.remember) {

            switch file.type {

            case .SNAPSHOT:
                document.snapshots.append(file, size: file.size)

            case .CART:
                MediaManager.noteNewRecentlyAtachedCartridgeURL(url)

            default:
                break
            }
        }

        // Process file
        try addMedia(proxy: file, options: options)
    }

    func addMedia(proxy: MediaFileProxy,
                  options: [Option] = []) throws {

        if let emu = emu {

            switch proxy.type {

            case .SNAPSHOT:

                debug(.media, "Snapshot")
                try emu.flash(proxy)
                debug(.media, "Snapshot flashed")

            case .CART:

                debug(.media, "CART")
                emu.attachCart(proxy, reset: true)

            case .SCRIPT:

                debug(.media, "Script")
                console.runScript(script: proxy)

            default:
                break
            }
        }
    }

    /*
    func flashMedia(proxy: MediaFileProxy, options: [Option] = []) throws {

        if let emu = emu {

            switch proxy.type {

            case .SNAPSHOT:

                debug(.media, "Snapshot")
                try emu.flash(proxy)

            case .CART:

                debug(.media, "CART")
                // try emu.expansionport.attachCartridge(proxy, reset: true)

            case .SCRIPT:

                debug(.media, "Script")
                console.runScript(script: proxy)

            default:
                break
            }
        }
    }
    */

    //
    // Exporting
    //

    func export(file: MediaFileProxy, to url: URL) throws {

        try file.writeToFile(url: url)
    }
}

// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

//
// Factory extensions
//

extension MediaFileProxy {

    static func makeWith(buffer: UnsafeRawPointer, length: Int, type: tiara.FileType) throws -> Self {

        let exc = ExceptionWrapper()
        let obj = make(withBuffer: buffer, length: length, type: type, exception: exc)
        if exc.errorCode != .OK { throw VC64Error(exc) }
        return obj!
    }

    static func make(with data: Data, type: tiara.FileType) throws -> Self {

        let exc = ExceptionWrapper()
        let obj = make(with: data, type: type, exception: exc)
        if exc.errorCode != .OK { throw VC64Error(exc) }
        return obj!
    }

    private static func make(with data: Data, type: tiara.FileType, exception: ExceptionWrapper) -> Self? {

        return data.withUnsafeBytes { uwbp -> Self? in

            return make(withBuffer: uwbp.baseAddress!, length: uwbp.count, type: type, exception: exception)
        }
    }

    static func make(with url: URL) throws -> Self {

        let exc = ExceptionWrapper()
        let obj = make(withFile: url.path, exception: exc)
        if exc.errorCode != .OK { throw VC64Error(exc) }
        return obj!
    }

    static func make(with url: URL, type: tiara.FileType) throws -> Self {

        let exc = ExceptionWrapper()
        let obj = make(withFile: url.path, type: type, exception: exc)
        if exc.errorCode != .OK { throw VC64Error(exc) }
        return obj!
    }
}

//
// Exception passing
//

extension EmulatorProxy {

    func isReady() throws {
        
        let exception = ExceptionWrapper()
        isReady(exception)
        if exception.errorCode != .OK { throw VC64Error(exception) }
    }

    func powerOn() throws {
        
        let exception = ExceptionWrapper()
        power(on: exception)
        if exception.errorCode != .OK { throw VC64Error(exception) }
    }

    func run() throws {
        
        let exception = ExceptionWrapper()
        run(exception)
        if exception.errorCode != .OK { throw VC64Error(exception) }
    }

    func exportConfig(url: URL) throws {

        let exception = ExceptionWrapper()
        exportConfig(url, exception: exception)
        if exception.errorCode != .OK { throw VC64Error(exception) }
    }

    func saveRom(_ type: tiara.RomType, url: URL) throws {

        let exception = ExceptionWrapper()
        saveRom(type, url: url, exception: exception)
        if exception.errorCode != .OK { throw VC64Error(exception) }
    }
     
    func flash(_ proxy: MediaFileProxy) throws {

        let exception = ExceptionWrapper()
        flash(proxy, exception: exception)
        if exception.errorCode != .OK { throw VC64Error(exception) }
    }
}

extension MediaFileProxy {
    
    func writeToFile(url: URL) throws {
        
        let exception = ExceptionWrapper()
        write(toFile: url.path, exception: exception)
        if exception.errorCode != .OK { throw VC64Error(exception) }
    }
}

extension RemoteManagerProxy {

    var icon: NSImage? {

        let info = info

        if info.numConnected > 0 {
            return NSImage(named: "srvConnectTemplate")!
        }
        if info.numListening > 0 {
            return NSImage(named: "srvListenTemplate")!
        }
        if info.numLaunching > 0 {
            return NSImage(named: "srvLaunchTemplate")!
        }
        if info.numErroneous > 0 {
            return NSImage(named: "srvErrorTemplate")!
        }

        return nil
    }
}

//
// Other extensions
//

public extension EmulatorProxy {

    func image(data: UnsafeMutablePointer<UInt8>?, size: NSSize) -> NSImage {
        
        var bitmap = data
        let width = Int(size.width)
        let height = Int(size.height)
        
        let imageRep = NSBitmapImageRep(bitmapDataPlanes: &bitmap,
                                        pixelsWide: width,
                                        pixelsHigh: height,
                                        bitsPerSample: 8,
                                        samplesPerPixel: 4,
                                        hasAlpha: true,
                                        isPlanar: false,
                                        colorSpaceName: NSColorSpaceName.calibratedRGB,
                                        bytesPerRow: 4 * width,
                                        bitsPerPixel: 32)
        
        let image = NSImage(size: (imageRep?.size)!)
        image.addRepresentation(imageRep!)
        image.makeGlossy()
        
        return image
    }
}

extension MediaFileProxy {

    func icon(protected: Bool = false) -> NSImage {
     
        switch type {
     
        case .BIN:
            return NSImage(named: "cartridge")!
        
        default:
            fatalError()
        }
    }
    
    static func diskIcon(protected: Bool = false) -> NSImage {

        let name = "disk2" + (protected ? "_protected" : "")
        return NSImage(named: name)!
    }
}

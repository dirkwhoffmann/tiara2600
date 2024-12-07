// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

/* This class stores all items that are specific to an individual emulator
 * instance. Each instance keeps its own object of this class inside the
 * document controller.
 *
 * See class "Preferences" for shared settings.
 */

class Configuration {
    
    var parent: MyController!
    var emu: EmulatorProxy? { return parent.emu }
    var renderer: Renderer { return parent.renderer }
    var gamePadManager: GamePadManager { return parent.gamePadManager }
    var ressourceManager: RessourceManager { return renderer.ressourceManager }
    
    //
    // Hardware
    //
    
    var tiaRevision: Int {
        get { return emu?.get(.TIA_REVISION) ?? 0 }
        set { emu?.set(.TIA_REVISION, value: newValue) }
    }

    var tiaAutoDetect: Bool {
        get { return emu?.get(.TIA_AUTO_DETECT) != 0 }
        set { emu?.set(.TIA_AUTO_DETECT, enable: newValue) }
    }

    var tiaCollisions: Int {
        get { return emu?.get(.TIA_COLLISIONS) ?? 0 }
        set { emu?.set(.TIA_COLLISIONS, value: newValue) }
    }

    var tiaRegLock: Int {
        get { return emu?.get(.TIA_REG_LOCK) ?? 0 }
        set { emu?.set(.TIA_REG_LOCK, value: newValue) }
    }

    var tiaRegWatch: Int {
        get { return emu?.get(.TIA_REG_WATCH) ?? 0 }
        set { emu?.set(.TIA_REG_WATCH, value: newValue) }
    }

    var ramPattern: Int {
        get { return emu?.get(.RAM_INIT_PATTERN) ?? 0 }
        set { emu?.set(.RAM_INIT_PATTERN, value: newValue) }
    }
    
    //
    // Peripherals
    //

    var gameDevice1 = -1 {
        didSet {
            
            // Try to connect the device (may disconnect the other device)
            gamePadManager.connect(slot: gameDevice1, port: 0)
            gamePadManager.listDevices()
            
            // Avoid double mappings
            if gameDevice1 != -1 && gameDevice1 == gameDevice2 {
                gameDevice2 = -1
            }
            
            parent.toolbar.validateVisibleItems()
        }
    }
    
    var gameDevice2 = -2 {
        didSet {
            
            // Try to connect the device (may disconnect the other device)
            gamePadManager.connect(slot: gameDevice2, port: 1)
            gamePadManager.listDevices()
            
            // Avoid double mappings
            if gameDevice2 != -1 && gameDevice2 == gameDevice1 {
                gameDevice1 = -1
            }
            
            parent.toolbar.validateVisibleItems()
        }
    }
    
    var paddleOrientation: Int {
        get { return emu?.get(.PADDLE_ORIENTATION, id: 1) ?? 0 }
        set { emu?.set(.PADDLE_ORIENTATION, value: newValue) }
    }

    var autofire: Bool {
        get { return emu?.get(.AUTOFIRE, id: 1) != 0 }
        set { emu?.set(.AUTOFIRE, enable: newValue) }
    }

    var autofireBursts: Bool {
        get { return emu?.get(.AUTOFIRE_BURSTS, id: 1) != 0 }
        set { emu?.set(.AUTOFIRE_BURSTS, enable: newValue) }
    }

    var autofireBullets: Int {
        get { return emu?.get(.AUTOFIRE_BULLETS, id: 1) ?? 0 }
        set { emu?.set(.AUTOFIRE_BULLETS, value: newValue) }
    }

    var autofireFrequency: Int {
        get { return emu?.get(.AUTOFIRE_DELAY, id: 1) ?? 0 }
        set { emu?.set(.AUTOFIRE_DELAY, value: newValue) }
    }

    //
    // Performance
    //

    var warpMode: Int {
        get { return emu?.get(.ATARI_WARP_MODE) ?? 0 }
        set { emu?.set(.ATARI_WARP_MODE, value: newValue) }
    }

    var vsync: Bool {
        get { return emu?.get(.ATARI_VSYNC) != 0 }
        set { emu?.set(.ATARI_VSYNC, enable: newValue) }
    }
    var speedBoost: Int {
        get { return emu?.get(.ATARI_SPEED_BOOST) ?? 0 }
        set { emu?.set(.ATARI_SPEED_BOOST, value: newValue) }
    }

    var runAhead: Int {
        get { return emu?.get(.ATARI_RUN_AHEAD) ?? 0 }
        set { emu?.set(.ATARI_RUN_AHEAD, value: newValue) }
    }

    var fastPaths: Bool {
        get { return emu?.get(.ATARI_FAST_PATHS) != 0 }
        set { emu?.set(.ATARI_FAST_PATHS, enable: newValue) }
    }

    //
    // Audio
    //

    var audSampling: Int {
        get { emu?.get(.AUD_SAMPLING, id: 0) ?? 0 }
        set { emu?.set(.AUD_SAMPLING, value: newValue) }
    }
    var vol0: Int {
        get { return emu?.get(.AUD_VOL0) ?? 0 }
        set { emu?.set(.AUD_VOL0, value: newValue) }
    }
    var vol1: Int {
        get { return emu?.get(.AUD_VOL1) ?? 0 }
        set { emu?.set(.AUD_VOL1, value: newValue) }
    }
    var pan0: Int {
        get { return emu?.get(.AUD_PAN0) ?? 0 }
        set { emu?.set(.AUD_PAN0, value: newValue) }
    }
    var pan1: Int {
        get { return emu?.get(.AUD_PAN1) ?? 0 }
        set { emu?.set(.AUD_PAN1, value: newValue) }
    }
    var volL: Int {
        get { return emu?.get(.AUD_VOL_L) ?? 0 }
        set { emu?.set(.AUD_VOL_L, value: newValue) }
    }
    var volR: Int {
        get { return emu?.get(.AUD_VOL_R) ?? 0 }
        set { emu?.set(.AUD_VOL_R, value: newValue) }
    }

    //
    // Video
    //

    var palette: Int {
        get { return emu?.get(.MON_PALETTE) ?? 0 }
        set { emu?.set(.MON_PALETTE, value: newValue) }
    }

    var brightness: Int {
        get { return emu?.get(.MON_BRIGHTNESS) ?? 0 }
        set { emu?.set(.MON_BRIGHTNESS, value: newValue) }
    }

    var contrast: Int {
        get { return emu?.get(.MON_CONTRAST) ?? 0 }
        set { emu?.set(.MON_CONTRAST, value: newValue) }
    }

    var saturation: Int {
        get { return emu?.get(.MON_SATURATION) ?? 0 }
        set { emu?.set(.MON_SATURATION, value: newValue) }
    }

    var hCenter: Int {
        get { return emu?.get(.MON_HCENTER) ?? 0 }
        set {
            emu?.set(.MON_HCENTER, value: newValue)
            renderer.canvas.updateTextureRect()
        }
    }
    var vCenter: Int {
        get { return emu?.get(.MON_VCENTER) ?? 0 }
        set {
            emu?.set(.MON_VCENTER, value: newValue)
            renderer.canvas.updateTextureRect()
        }
    }

    var hZoom: Int {
        get { return emu?.get(.MON_HZOOM) ?? 0 }
        set {
            emu?.set(.MON_HZOOM, value: newValue)
            renderer.canvas.updateTextureRect()
        }
    }

    var vZoom: Int {
        get { return emu?.get(.MON_VZOOM) ?? 0 }
        set {
            emu?.set(.MON_VZOOM, value: newValue)
            renderer.canvas.updateTextureRect()
        }
    }

    var upscaler: Int {
        get { return emu?.get(.MON_UPSCALER) ?? 0 }
        set {
            if ressourceManager.selectUpscaler(newValue) {
                emu?.set(.MON_UPSCALER, value: newValue)
            }
        }
    }

    var blur: Int {
        get { return emu?.get(.MON_BLUR) ?? 0 }
        set {
            emu?.set(.MON_BLUR, value: newValue)
            renderer.shaderOptions.blur = Int32(newValue)
        }
    }

    var blurRadius: Int {
        get { return emu?.get(.MON_BLUR_RADIUS) ?? 0 }
        set {
            emu?.set(.MON_BLUR_RADIUS, value: newValue)
            renderer.shaderOptions.blurRadius = Float(newValue) / 1000.0
        }
    }

    var bloom: Int {
        get { return emu?.get(.MON_BLOOM) ?? 0 }
        set {
            if ressourceManager.selectBloomFilter(newValue) {
                emu?.set(.MON_BLOOM, value: newValue)
                renderer.shaderOptions.bloom = Int32(bloom)
            }
        }
    }

    var bloomRadius: Int {
        get { return emu?.get(.MON_BLOOM_RADIUS) ?? 0 }
        set {
            emu?.set(.MON_BLOOM_RADIUS, value: newValue)
            renderer.shaderOptions.bloomRadius = Float(newValue) / 1000.0
        }
    }

    var bloomBrightness: Int {
        get { return emu?.get(.MON_BLOOM_BRIGHTNESS) ?? 0 }
        set {
            emu?.set(.MON_BLOOM_BRIGHTNESS, value: newValue)
            renderer.shaderOptions.bloomBrightness = Float(newValue) / 1000.0
        }
    }

    var bloomWeight: Int {
        get { return emu?.get(.MON_BLOOM_WEIGHT) ?? 0 }
        set {
            emu?.set(.MON_BLOOM_WEIGHT, value: newValue)
            renderer.shaderOptions.bloomWeight = Float(newValue) / 1000.0
        }
    }

    var dotMask: Int {
        get { return emu?.get(.MON_DOTMASK) ?? 0 }
        set {
            renderer.shaderOptions.dotMask = Int32(newValue)
            ressourceManager.buildDotMasks()
            if ressourceManager.selectDotMask(newValue) {
                emu?.set(.MON_DOTMASK, value: newValue)
            }
        }
    }

    var dotMaskBrightness: Int {
        get { return emu?.get(.MON_DOTMASK_BRIGHTNESS) ?? 0 }
        set {
            emu?.set(.MON_DOTMASK_BRIGHTNESS, value: newValue)
            renderer.shaderOptions.dotMaskBrightness = Float(newValue) / 1000.0
            ressourceManager.buildDotMasks()
            ressourceManager.selectDotMask(dotMask)
        }
    }

    var scanlines: Int {
        get { return emu?.get(.MON_SCANLINES) ?? 0 }
        set {
            renderer.shaderOptions.scanlines = Int32(newValue)
            if ressourceManager.selectScanlineFilter(newValue) {
                emu?.set(.MON_SCANLINES, value: newValue)
            }
        }
    }

    var scanlineBrightness: Int {
        get { return emu?.get(.MON_SCANLINE_BRIGHTNESS) ?? 0 }
        set {
            emu?.set(.MON_SCANLINE_BRIGHTNESS, value: newValue)
            renderer.shaderOptions.scanlineBrightness = Float(newValue) / 1000.0
        }
    }

    var scanlineWeight: Int {
        get { return emu?.get(.MON_SCANLINE_WEIGHT) ?? 0 }
        set {
            emu?.set(.MON_SCANLINE_WEIGHT, value: newValue)
            renderer.shaderOptions.scanlineWeight = Float(newValue) / 1000.0
        }
    }

    var disalignment: Int {
        get { return emu?.get(.MON_DISALIGNMENT) ?? 0 }
        set {
            emu?.set(.MON_DISALIGNMENT, value: newValue)
            renderer.shaderOptions.disalignment = Int32(newValue)
        }
    }

    var disalignmentH: Int {
        get { return emu?.get(.MON_DISALIGNMENT_H) ?? 0 }
        set {
            emu?.set(.MON_DISALIGNMENT_H, value: newValue)
            renderer.shaderOptions.disalignmentH = Float(newValue) / 1000000.0
        }
    }
    
    var disalignmentV: Int {
        get { return emu?.get(.MON_DISALIGNMENT_V) ?? 0 }
        set {
            emu?.set(.MON_DISALIGNMENT_V, value: newValue)
            renderer.shaderOptions.disalignmentV = Float(newValue) / 1000000.0
        }
    }
    init(with controller: MyController) { parent = controller }

    //
    // Roms
    //

    func loadRomUserDefaults() {

        func load(_ url: URL?, type: FileType) {

            if url != nil {
                if let file = try? MediaFileProxy.make(with: url!) {
                    if file.type == type { emu?.attachCart(file, reset: false) }
                }
            }
        }

        debug(.defaults)

        /*
        if let emu = emu {

            emu.suspend()
            load(UserDefaults.basicRomUrl, type: .BASIC_ROM)
            load(UserDefaults.charRomUrl, type: .CHAR_ROM)
            load(UserDefaults.kernalRomUrl, type: .KERNAL_ROM)
            load(UserDefaults.vc1541RomUrl, type: .VC1541_ROM)
            emu.resume()
        }
        */
    }

    func saveRomUserDefaults() throws {

        debug(.defaults)

        // var url: URL?

        /*
        if let emu = emu {

            emu.suspend()

            do {
                url = UserDefaults.basicRomUrl;  try save(.BASIC)
                url = UserDefaults.charRomUrl;   try save(.CHAR)
                url = UserDefaults.kernalRomUrl; try save(.KERNAL)
                url = UserDefaults.vc1541RomUrl; try save(.VC1541)

            } catch {

                emu.resume()
                throw error
            }

            emu.resume()
        }
        */
    }
}

// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

protocol MessageReceiver {
    func processMessage(_ msg: tiara.Message)
}

class MyController: NSWindowController, MessageReceiver {

    var pref: Preferences { return myAppDelegate.pref }

    // Reference to the connected document
    var mydocument: MyDocument!
    
    // Emulator proxy (bridge between the Swift frontend and the C++ backend)
    var emu: EmulatorProxy? { return mydocument.emu }

    // Media manager (handles the import and export of media files)
    var mm: MediaManager { return mydocument.mm }

    // Inspector panel of this emulator instance
    var inspector: Inspector?
    
    // Logic analyzer panel of this emulator instance
    var analyzer: LogicAnalyzer?
    
    // Configuration panel of this emulator instance
    var configurator: ConfigurationController?

    // Snapshot and screenshot browsers
    var snapshotBrowser: SnapshotViewer?
    var screenshotBrowser: ScreenshotViewer?

    // The current emulator configuration
    var config: Configuration!
    
    // Audio Engine
    var macAudio: MacAudio!

    // Game pad manager
    var gamePadManager: GamePadManager!
    var gamePad1: GamePad? { return gamePadManager.gamePads[config.gameDevice1] }
    var gamePad2: GamePad? { return gamePadManager.gamePads[config.gameDevice2] }
    
    // Keyboard controller
    var keyboard: KeyboardController!

    // Speedometer to measure clock frequence and frames per second
    var speedometer: Speedometer!

    // Remembers if an illegal instruction has jammed the CPU
    var jammed = false

    // Remembers if audio is muted (master volume of both channels is 0)
    var muted = false

    // Current keyboard modifier flags
    // These flags tell us if one of the special keysare currently pressed.
    // The flags are utilized, e.g., to alter behaviour when a key on the
    // TouchBar is pressed.
    var modifierFlags: NSEvent.ModifierFlags = .init(rawValue: 0)

    // Indicates if a status bar is shown
    var statusBar = true
    
    // Small disk icon to be shown in NSMenuItems
    static let iconSize = CGSize(width: 16, height: 16)
    var smallCart = NSImage(named: "cartTemplate")!.resize(size: iconSize)

    // Indicates if the window is in background
    var inBackground = false
    
    // Remembers the running state for the pauseInBackground feature
    var pauseInBackgroundSavedState = false

    //
    // Outlets
    //
    
    // Main screen
    @IBOutlet weak var metal: MetalView!
    
    var renderer: Renderer!

    // Status bar    
    @IBOutlet weak var haltIcon: NSButton!
    @IBOutlet weak var serverIcon: NSButton!
    @IBOutlet weak var trackIcon: NSButton!
    @IBOutlet weak var muteIcon: NSButton!
    
    @IBOutlet weak var warpIcon: NSButton!
    @IBOutlet weak var activityType: NSPopUpButton!
    @IBOutlet weak var activityInfo: NSTextField!
    @IBOutlet weak var activityBar: NSLevelIndicator!
    @IBOutlet weak var speedStepper: NSStepper!

    // Toolbar
    @IBOutlet weak var toolbar: MyToolbar!
}

extension MyController {

    // Provides the undo manager
    override open var undoManager: UndoManager? { return metal.undoManager }

    // Indicates if the emulator needs saving
    var needsSaving: Bool {
        get {
            return document?.changeCount != 0
        }
        set {
            if newValue && !pref.closeWithoutAsking {
                document?.updateChangeCount(.changeDone)
            } else {
                document?.updateChangeCount(.changeCleared)
            }
        }
    }
    
    //
    // Initializing
    //

    override open func awakeFromNib() {

        mydocument = document as? MyDocument
        config = Configuration(with: self)
        macAudio = MacAudio(with: self)
    }

    override open func windowDidLoad() {

        debug(.lifetime)
        
        // Create keyboard controller
        keyboard = KeyboardController(parent: self)
        assert(keyboard != nil, "Failed to create keyboard controller")

        // Create game pad manager
        gamePadManager = GamePadManager(parent: self)
        assert(gamePadManager != nil, "Failed to create game pad manager")

        // Setup renderer
        renderer = Renderer(view: metal,
                            device: MTLCreateSystemDefaultDevice()!,
                            controller: self)

        // Setup window
        configureWindow()

        // Launch the emulator
        launch()

        // Apply all GUI related user defaults
        pref.applyUserDefaults()
        config.applyUserDefaults()

        do {
            // Let the C64 throw an exception if it is not ready to power on
            try emu?.isReady()

            // Start emulation
            try emu?.run()

        } catch {
            
            // Open the Rom dialog
            openConfigurator(tab: "Roms")
        }

        // Add media file (if provided on startup)
        if let url = mydocument.launchUrl { try? mm.addMedia(url: url) }

        // Create speed monitor
        speedometer = Speedometer()
        
        // Update toolbar
        toolbar.validateVisibleItems()
        
        // Update status bar
        refreshStatusBar()
    }
    
    func configureWindow() {

        // Add status bar
        window?.autorecalculatesContentBorderThickness(for: .minY)
        window?.setContentBorderThickness(32.0, for: .minY)
        statusBar = true
        
        // Adjust size and enable auto-save for window coordinates
        adjustWindowSize()
        window?.windowController?.shouldCascadeWindows = false // true ?!
        let name = NSWindow.FrameAutosaveName("dirkwhoffmann.de.tiara.window")
        window?.setFrameAutosaveName(name)
        
        // Enable fullscreen mode
        window?.collectionBehavior = .fullScreenPrimary
    }
    
    func launch() {

        // Pass in command line arguments as a RetroShell script
        var script = ""
        for arg in myAppDelegate.argv where arg.hasPrefix("-") {
            script = script + arg.dropFirst() + "\n"
        }
        emu?.retroShell.execute(script)

        // Convert 'self' to a void pointer
        let myself = UnsafeRawPointer(Unmanaged.passUnretained(self).toOpaque())
        
        emu!.launch(myself) { (ptr, msg: tiara.Message) in

            // Convert void pointer back to 'self'
            let myself = Unmanaged<MyController>.fromOpaque(ptr!).takeUnretainedValue()

            // Process message in the main thread
            DispatchQueue.main.async { myself.processMessage(msg) }
        }
    }
    
    //
    // Timer and message processing
    //
    
    func update(frames: Int64) {

        if frames % 5 == 0 {

            // Animate the inspector
            if inspector?.window?.isVisible == true { inspector!.continuousRefresh() }
        }

        if frames % 8 == 0 {

            // Animate the logic analyzer
            if analyzer?.window?.isVisible == true { analyzer!.continuousRefresh() }
        }

        // Do less times...
        if (frames % 16) == 0 {
            
            updateSpeedometer()
        }
        
        // Do lesser times...
        if (frames % 256) == 0 {
            
            // Let the cursor disappear in fullscreen mode
            if renderer.fullscreen &&
                CGEventSource.secondsSinceLastEventType(.combinedSessionState,
                                                        eventType: .mouseMoved) > 1.0 {
                NSCursor.setHiddenUntilMouseMoves(true)
            }
        }
    }

    func processMessage(_ msg: tiara.Message) {

        var value: Int { return Int(msg.value) }
        var nr: Int { return Int(msg.drive.nr) }
        var halftrack: Int { return Int(msg.drive.value) }
        var drive: tiara.DriveMsg { return msg.drive }
        var pc: Int { return Int(msg.cpu.pc) }
        var vol: Int { return Int(msg.drive.volume) }
        var pan: Int { return Int(msg.drive.pan) }

        // Only proceed if the proxy object is still alive
        if emu == nil { return }

        switch msg.type {

        case .CONFIG:
            inspector?.fullRefresh()
            analyzer?.refresh()
            configurator?.refresh()
            refreshStatusBar()

        case .POWER:

            if value != 0 {

                renderer.canvas.open(delay: 2)
                inspector?.powerOn()

            } else {

                inspector?.powerOff()
            }

            toolbar.updateToolbar()
            configurator?.refresh()

        case .RUN:
            needsSaving = true
            jammed = false
            toolbar.updateToolbar()
            inspector?.run()
            analyzer?.run()
            refreshStatusBar()

        case .PAUSE:
            toolbar.updateToolbar()
            inspector?.pause()
            analyzer?.pause()
            refreshStatusBar()

        case .STEP:
            needsSaving = true
            inspector?.step()
            analyzer?.step()

        case .RESET:
            inspector?.reset()
            analyzer?.reset()

        case .SHUTDOWN:
            shutDown()

        case .ABORT:
            debug(.shutdown, "Aborting with exit code \(value)")
            exit(Int32(value))

        case .WARP, .TRACK:
            refreshStatusBar()

        case .MUTE:
            muted = value != 0
            refreshStatusBar()

        case .RSH_CLOSE:
            renderer.console.close(delay: 0.25)

        case .RSH_UPDATE:
            renderer.console.isDirty = true

        case .RSH_DEBUGGER:
            break

        case .RSH_WAIT:
            renderer.console.isDirty = true

        case .RSH_ERROR:
            NSSound.beep()
            renderer.console.isDirty = true

        case .GUARD_UPDATED:
            inspector?.fullRefresh()

        case .BREAKPOINT_REACHED:
            inspector?.signalBreakPoint(pc: pc)

        case .WATCHPOINT_REACHED:
            inspector?.signalWatchPoint(pc: pc)

        case .BEAMTRAP_REACHED:
            // inspector?.signalBeamtrap()
            analyzer?.signalBeamtrap()

        case .CPU_JAMMED:
            jammed = true
            refreshStatusBar()

        case .CPU_JUMPED:
            inspector?.signalGoto(pc: pc)

        case .PAL, .NTSC:
            renderer.canvas.updateTextureRect()

        case .DRIVE_STEP, .DISK_INSERT, .DISK_EJECT:
            break

        case .FILE_FLASHED:
            break

        case .DISK_PROTECTED,
                .DISK_MODIFIED,
                .DRIVE_LED,
                .SER_BUSY,
                .SER_IDLE,
                .DRIVE_MOTOR:
            refreshStatusBar()

        case .DRIVE_CONNECT, .DRIVE_POWER, .DRIVE_POWER_SAVE:
            break

        case .CRT_ATTACHED:
            refreshStatusBar()
            
        case .SHAKING:
            metal.lastShake = DispatchTime(uptimeNanoseconds: 0)
            if pref.releaseMouseByShaking {
                metal.releaseMouse()
            }

        case .SNAPSHOT_TAKEN:
            let ptr = msg.snapshot.snapshot
            let proxy = MediaFileProxy.init(ptr)!
            mydocument.snapshots.append(proxy, size: proxy.size)

        case .SNAPSHOT_RESTORED:
            renderer.rotateRight()
            // renderer.canvas.updateTextureRect()
            refreshStatusBar()
            hideOrShowDriveMenus()

        case .DMA_DEBUG:
            if value != 0 { renderer.zoomTextureOut() } else { renderer.zoomTextureIn() }

        case .ALARM:
            debug(.events, "Received Alarm \(msg.value)")

        case .SRV_STATE:
            refreshStatusBar()

        case .SRV_RECEIVE, .SRV_SEND:
            break
            
        default:
            warn("Unknown message: \(msg)")
            fatalError()
        }
    }

    //
    // Keyboard events
    //

    // Keyboard events are handled by the emulator window.
    // If they are handled here, some keys such as 'TAB' don't trigger an event.
}

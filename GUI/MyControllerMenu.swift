// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

import UniformTypeIdentifiers

extension MyController: NSMenuItemValidation {
    
    open func validateMenuItem(_ item: NSMenuItem) -> Bool {

        if let emu = emu {

            let info = emu.info
            let powered = info.powered
            let running = info.running
            var recording: Bool { return emu.recorder.recording }

            func validateURLlist(_ list: [URL], image: NSImage) -> Bool {

                let slot = item.tag % 10

                if let url = MediaManager.getRecentlyUsedURL(slot, from: list) {
                    item.title = url.lastPathComponent
                    item.isHidden = false
                    item.image = image
                } else {
                    item.title = ""
                    item.isHidden = true
                    item.image = nil
                }

                return true
            }

            switch item.action {

                // Machine menu
            case #selector(MyController.captureScreenAction(_:)):
                item.title = recording ? "Stop Recording" : "Record Screen"
                return true

                // Edit menu
            case #selector(MyController.stopAndGoAction(_:)):
                item.title = running ? "Pause" : "Continue"
                return true

            case #selector(MyController.powerAction(_:)):
                item.title = powered ? "Power Off" : "Power On"
                return true

                // View menu
            case #selector(MyController.toggleStatusBarAction(_:)):
                item.title = statusBar ? "Hide Status Bar" : "Show Status Bar"
                return true

                // Cartridge menu
            case #selector(MyController.attachRecentCartridgeAction(_:)):
                return validateURLlist(MediaManager.attachedCartridges, image: smallCart)

            case #selector(MyController.attachReuDummyAction(_:)):
                item.state = (emu.expansionport.traits.type == .REU) ? .on : .off

            case #selector(MyController.attachReuAction(_:)):
                item.state = (emu.expansionport.traits.type == .REU &&
                              emu.expansionport.traits.memory == item.tag * 1024) ? .on : .off

            case #selector(MyController.attachGeoRamDummyAction(_:)):
                item.state = (emu.expansionport.traits.type == .GEO_RAM) ? .on : .off

            case #selector(MyController.attachGeoRamAction(_:)):
                item.state = (emu.expansionport.traits.type == .GEO_RAM &&
                              emu.expansionport.traits.memory == item.tag * 1024) ? .on : .off

            case #selector(MyController.attachIsepicAction(_:)):
                item.state = (emu.expansionport.traits.type == .ISEPIC) ? .on : .off

            case #selector(MyController.detachCartridgeAction(_:)):
                return emu.expansionport.cartridgeAttached()

            case #selector(MyController.inspectCartridgeAction(_:)):
                return emu.expansionport.cartridgeAttached()

            case #selector(MyController.pressButtonDummyAction(_:)):
                return emu.expansionport.traits.buttons > 0

            case #selector(MyController.pressCartridgeButton1Action(_:)):
                let title = String(charptr: emu.expansionport.traits.button1)
                item.title = title ?? ""
                item.isHidden = title == nil
                return title != nil

            case #selector(MyController.pressCartridgeButton2Action(_:)):
                let title = String(charptr: emu.expansionport.traits.button2)
                item.title = title ?? ""
                item.isHidden = title == nil
                return title != nil

            case #selector(MyController.setSwitchDummyAction(_:)):
                return emu.expansionport.traits.switches > 0

            case #selector(MyController.setSwitchNeutralAction(_:)):
                let title = String(charptr: emu.expansionport.traits.switchNeutral)
                item.title = title ?? ""
                item.isHidden = title == nil
                item.state = emu.expansionport.info.switchPos == 0 ? .on : .off
                return title != nil

            case #selector(MyController.setSwitchLeftAction(_:)):
                let title = String(charptr: emu.expansionport.traits.switchLeft)
                item.title = title ?? ""
                item.isHidden = title == nil
                item.state = emu.expansionport.info.switchPos < 0 ? .on : .off
                return title != nil

            case #selector(MyController.setSwitchRightAction(_:)):
                let title = String(charptr: emu.expansionport.traits.switchRight)
                item.title = title ?? ""
                item.isHidden = title == nil
                item.state = emu.expansionport.info.switchPos > 0 ? .on : .off
                return title != nil

            default:
                return true
            }
        }

        return true
    }

    func hideOrShowDriveMenus() {
        
    }
    
    //
    // Action methods (App menu)
    //
    
    @IBAction func preferencesAction(_ sender: Any!) {
        
        if myAppDelegate.prefController == nil {

            myAppDelegate.prefController =
            PreferencesController(with: self, nibName: "Preferences")
        }
        myAppDelegate.prefController?.showWindow(self)
    }
    
    @IBAction func factorySettingsAction(_ sender: Any!) {

        let defaults = EmulatorProxy.defaults!

        // Power off the emulator if the user doesn't object
        if !askToPowerOff() { return }

        // Reset settings
        defaults.removeAll()
        defaults.resetSearchPaths()
        defaults.save()

        // Apply new settings
        config.applyUserDefaults()
        pref.applyUserDefaults()

        // Relaunch the emulator
        try? emu?.run()
    }

    @IBAction func importConfigAction(_ sender: Any!) {

        let openPanel = NSOpenPanel()

        // Power off the emulator if the user doesn't object
        if !askToPowerOff() { return }

        // Show file panel
        openPanel.allowsMultipleSelection = false
        openPanel.canChooseDirectories = true
        openPanel.canCreateDirectories = false
        openPanel.canChooseFiles = true
        openPanel.prompt = "Import"
        openPanel.allowedContentTypes = [.ini]
        openPanel.beginSheetModal(for: window!, completionHandler: { result in

            if result == .OK, let url = openPanel.url {

                do {
                    try self.mm.addMedia(url: url, allowedTypes: [.SCRIPT])
                } catch {
                    self.showAlert(.cantOpen(url: url), error: error, async: true)
                }
            }
        })
    }

    @IBAction func exportConfigAction(_ sender: Any!) {

        let savePanel = NSSavePanel()

        // Show file panel
        savePanel.prompt = "Export"
        savePanel.title = "Export"
        savePanel.nameFieldLabel = "Export As:"
        savePanel.nameFieldStringValue = "tiara.ini"
        savePanel.canCreateDirectories = true
        savePanel.beginSheetModal(for: window!, completionHandler: { result in

            if result == .OK, let url = savePanel.url {

                do {
                    try self.emu?.exportConfig(url: url)
                } catch {
                    self.showAlert(.cantExport(url: url), error: error, async: true)
                }
            }
        })
    }

    //
    // Action methods (Machine menu)
    //
    
    func openConfigurator(tab: String = "") {
        
        if configurator == nil {
            configurator = ConfigurationController(with: self, nibName: "Configuration")
        }
        configurator?.showSheet(tab: tab)
    }
    
    @IBAction func configureAction(_ sender: Any!) {
        
        openConfigurator()
    }

    @IBAction func inspectorAction(_ sender: Any!) {
        
        if inspector == nil {
            inspector = Inspector(with: self, nibName: "Inspector")
        }
        inspector?.showWindow(self)
    }
    
    @IBAction func monitorAction(_ sender: Any!) {
        
        if monitor == nil {
            monitor = Monitor(with: self, nibName: "Monitor")
        }
        monitor?.showWindow(self)
    }
    
    @IBAction func consoleAction(_ sender: Any!) {
        
        if renderer.console.isVisible {
            renderer.console.close(delay: 0.25)
        } else {
            renderer.console.open(delay: 0.25)
        }
    }
    
    @IBAction func takeSnapshotAction(_ sender: Any!) {

        if let snapshot = emu?.c64.takeSnapshot() {

            mydocument.snapshots.append(snapshot, size: snapshot.size)
            renderer.flash()
        }
    }
    
    @IBAction func restoreSnapshotAction(_ sender: Any!) {
        
        do {
            try restoreLatestSnapshot()
        } catch {
            showAlert(.cantRestore, error: error)
        }
    }
    
    @IBAction func browseSnapshotsAction(_ sender: Any!) {
        
        if snapshotBrowser == nil {
            snapshotBrowser = SnapshotViewer(with: self, nibName: "SnapshotViewer")
        }
        snapshotBrowser?.showSheet()
    }
    
    @IBAction func takeScreenshotAction(_ sender: Any!) {

        // Determine screenshot format
        let format = ScreenshotSource(rawValue: pref.screenshotSource)!
        
        // Take screenshot
        guard let screen = renderer.canvas.screenshot(source: format) else {

            warn("Failed to create screenshot")
            return
        }

        // Convert to Screenshot object
        let screenshot = Screenshot(screen: screen, format: pref.screenshotTarget)

        // Save to disk
        try? screenshot.save()
        
        // Create a visual effect
        renderer.flash()
    }
    
    @IBAction func browseScreenshotsAction(_ sender: Any!) {

        if screenshotBrowser == nil {
            screenshotBrowser = ScreenshotViewer(with: self, nibName: "ScreenshotViewer")
        }
        screenshotBrowser?.showSheet()
    }

    @IBAction func captureScreenAction(_ sender: Any!) {

        if let emu = emu {

            if emu.recorder.recording {

                emu.recorder.stopRecording()
                exportVideoAction(self)
                return
            }

            if !emu.recorder.hasFFmpeg {

                if pref.ffmpegPath != "" {
                    showAlert(.noFFmpegFound(exec: pref.ffmpegPath))
                } else {
                    showAlert(.noFFmpegInstalled)
                }
                return
            }

            var rect: CGRect
            if pref.captureSource == 0 {
                rect = renderer.canvas.visible
            } else {
                rect = renderer.canvas.entire
            }

            do {
                try emu.recorder.startRecording(rect: rect)
            } catch {

                showAlert(.cantRecord, error: error)
            }
        }
    }
    
    @IBAction func exportVideoAction(_ sender: Any!) {

        let exporter = VideoExporter(with: self, nibName: "VideoExporter")
        exporter?.showSheet()
    }
    
    //
    // Action methods (Edit menu)
    //

    @IBAction func pauseAction(_ sender: Any!) {
        
        if let emu = emu {
            if emu.running { emu.pause() }
        }
    }

    @IBAction func continueAction(_ sender: Any!) {
        
        if let emu = emu {
            if emu.paused { try? emu.run() }
        }
    }

    @IBAction func stopAndGoAction(_ sender: Any!) {
        
        if let emu = emu {
            if emu.running { emu.pause() } else { try? emu.run() }
        }
    }
    
    @IBAction func stepIntoAction(_ sender: Any!) {

        if let emu = emu {
            emu.stepInto()
        }
    }
    
    @IBAction func stepOverAction(_ sender: Any!) {
        
        if let emu = emu {
            emu.stepOver()
        }
    }
    
    @IBAction func resetAction(_ sender: Any!) {

        if let emu = emu {

            renderer.rotateLeft()
            emu.c64.hardReset()
            try? emu.run()
        }
    }

    @IBAction func softResetAction(_ sender: Any!) {

        if let emu = emu {
            emu.c64.softReset()
        }
    }

    @IBAction func powerAction(_ sender: Any!) {

        if let emu = emu {

            if emu.poweredOn {

                emu.powerOff()

            } else {

                do {
                    try emu.run()
                } catch {
                    showAlert(.cantRun, error: error)
                }
            }
        }
    }
     
    @IBAction func brkAction(_ sender: Any!) {

        if let emu = emu {
            emu.put(.CPU_BRK)
        }
    }

    //
    // Action methods (View menu)
    //

    @IBAction func toggleStatusBarAction(_ sender: Any!) {
        
        undoManager?.registerUndo(withTarget: self) { targetSelf in
            targetSelf.toggleStatusBarAction(sender)
        }
        
        showStatusBar(!statusBar)
    }

    //
    // Action methods (Keyboard menu)
    //
    
    //
    // Action methods (Cartridge menu)
    //

    @IBAction func attachCartridgeAction(_ sender: Any!) {
        
        let openPanel = NSOpenPanel()
        openPanel.allowsMultipleSelection = false
        openPanel.canChooseDirectories = false
        openPanel.canCreateDirectories = false
        openPanel.canChooseFiles = true
        openPanel.prompt = "Attach"
        // Note: macOS classifies CRT files as a .x509Certificate
        openPanel.allowedContentTypes = [.crt, .zip, .gzip, .x509Certificate]
        openPanel.beginSheetModal(for: window!, completionHandler: { result in
            if result == .OK, let url = openPanel.url {

                do {
                    try self.mm.addMedia(url: url, allowedTypes: [ .CRT ])
                } catch {
                    self.showAlert(.cantAttach, error: error, async: true)
                }
            }
        })
    }
    
    @IBAction func attachRecentCartridgeAction(_ sender: NSMenuItem!) {
        
        let slot  = sender.tag
        
        if let url = MediaManager.getRecentlyAtachedCartridgeURL(slot) {

            do {
                try self.mm.addMedia(url: url, allowedTypes: [ .CRT ])
            } catch {
                self.showAlert(.cantAttach, error: error, async: true)
            }
        }
    }

    @IBAction func detachCartridgeAction(_ sender: Any!) {

        if let emu = emu {

            emu.expansionport.detachCartridge()
            emu.c64.hardReset()
        }
    }

    @IBAction func attachReuDummyAction(_ sender: Any!) {
        // Dummy action method to enable menu item validation
    }

    @IBAction func attachReuAction(_ sender: NSMenuItem!) {

        if let emu = emu {

            let capacity = sender.tag
            emu.expansionport.attachReuCartridge(capacity)
        }
    }

    @IBAction func attachGeoRamDummyAction(_ sender: Any!) {
        // Dummy action method to enable menu item validation
    }

    @IBAction func attachGeoRamAction(_ sender: NSMenuItem!) {

        if let emu = emu {

            let capacity = sender.tag
            emu.expansionport.attachGeoRamCartridge(capacity)
        }
    }

    @IBAction func attachIsepicAction(_ sender: Any!) {

        if let emu = emu {
            emu.expansionport.attachIsepicCartridge()
        }
    }

    @IBAction func pressCartridgeButton1Action(_ sender: NSButton!) {
        
        if let emu = emu {

            emu.put(.CRT_BUTTON_PRESS, value: 1)

            DispatchQueue.main.asyncAfter(deadline: .now() + 0.5) {
                self.emu!.put(.CRT_BUTTON_RELEASE, value: 1)
            }
        }
    }

    @IBAction func pressCartridgeButton2Action(_ sender: NSButton!) {
        
        if let emu = emu {

            emu.put(.CRT_BUTTON_PRESS, value: 2)

            DispatchQueue.main.asyncAfter(deadline: .now() + 0.5) {
                self.emu!.put(.CRT_BUTTON_RELEASE, value: 2)
            }
        }
    }
    
    @IBAction func pressButtonDummyAction(_ sender: Any!) {
        // Dummy action method to enable menu item validation
    }

    @IBAction func setSwitchNeutralAction(_ sender: Any!) {
        
        if let emu = emu {
            emu.put(.CRT_SWITCH_NEUTRAL)
        }
    }

    @IBAction func setSwitchLeftAction(_ sender: Any!) {
        
        if let emu = emu {
            emu.put(.CRT_SWITCH_LEFT)
        }
    }

    @IBAction func setSwitchRightAction(_ sender: Any!) {
        
        if let emu = emu {
            emu.put(.CRT_SWITCH_RIGHT)
        }
    }

    @IBAction func setSwitchDummyAction(_ sender: Any!) {
        // Dummy action method to enable menu item validation
    }

    @IBAction  func inspectCartridgeAction(_ sender: Any!) {

        if let emu = emu {

            let panel = CartridgeInspector(with: self, nibName: "CartridgeInspector")
            panel?.show(expansionPort: emu.expansionport)
        }
    }

    //
    // Action methods (Window menu)
    //

    // Resizes the window such that every texture line hits a display line
    @IBAction func autoResizeWindow(_ sender: NSMenuItem!) {

        let height = renderer.canvas.visible.height * 2

        debug(.metal, "Old metal view: \(metal.frame)")
        debug(.metal, "Visible texture lines: \(height)")

        adjustWindowSize(height: height)

        debug(.metal, "New metal view: \(metal.frame)")
    }
}

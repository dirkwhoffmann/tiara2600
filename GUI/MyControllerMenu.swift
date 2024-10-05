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
            monitor = LogicAnalyzer(with: self, nibName: "LogicAnalyzer")
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

        if let snapshot = emu?.atari.takeSnapshot() {

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
            emu.atari.hardReset()
            try? emu.run()
        }
    }

    @IBAction func softResetAction(_ sender: Any!) {

        if let emu = emu {
            emu.atari.softReset()
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
                    try self.mm.addMedia(url: url, allowedTypes: [ .CART ])
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
                try self.mm.addMedia(url: url, allowedTypes: [ .CART ])
            } catch {
                self.showAlert(.cantAttach, error: error, async: true)
            }
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

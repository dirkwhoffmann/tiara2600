// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension PreferencesController {
    
    func refreshGeneralTab() {

        // Snapshots
        genAutoSnapshots.state = pref.autoSnapshots ? .on : .off
        genSnapshotInterval.integerValue = pref.snapshotInterval
        genSnapshotInterval.isEnabled = pref.autoSnapshots

        // Screenshots
        genScreenshotSourcePopup.selectItem(withTag: pref.screenshotSource)
        genScreenshotTargetPopup.selectItem(withTag: pref.screenshotTargetIntValue)

        // Fullscreen
        genAspectRatioButton.state = pref.keepAspectRatio ? .on : .off
        genExitOnEscButton.state = pref.exitOnEsc ? .on : .off

        // Miscellaneous
        genEjectUnasked.state = pref.ejectWithoutAsking ? .on : .off
        genCloseWithoutAskingButton.state = pref.closeWithoutAsking ? .on : .off
        genPauseInBackground.state = pref.pauseInBackground ? .on : .off
    }
    
    func selectGeneralTab() {

        refreshGeneralTab()
    }
        
    //
    // Action methods (Snapshots)
    //
    
    @IBAction func genAutoSnapshotAction(_ sender: NSButton!) {
        
        pref.autoSnapshots = sender.state == .on
        refresh()
    }
    
    @IBAction func genSnapshotIntervalAction(_ sender: NSTextField!) {
        
        if sender.integerValue > 0 {
            pref.snapshotInterval = sender.integerValue
        }
        refresh()
    }
    
    //
    // Action methods (Screenshots)
    //

    @IBAction func genScreenshotSourceAction(_ sender: NSPopUpButton!) {
        
        pref.screenshotSource = sender.selectedTag()
        refresh()
    }
    
    @IBAction func genScreenshotTargetAction(_ sender: NSPopUpButton!) {
        
        pref.screenshotTargetIntValue = sender.selectedTag()
        refresh()
    }
        
    //
    // Action methods (Fullscreen)
    //
    
    @IBAction func genAspectRatioAction(_ sender: NSButton!) {
        
        pref.keepAspectRatio = (sender.state == .on)
        refresh()
    }
    
    @IBAction func genExitOnEscAction(_ sender: NSButton!) {
        
        pref.exitOnEsc = (sender.state == .on)
        refresh()
    }
    
    //
    // Action methods (Miscellaneous)
    //
    
    @IBAction func genEjectWithoutAskingAction(_ sender: NSButton!) {
        
        pref.ejectWithoutAsking = (sender.state == .on)
        refresh()
    }

    @IBAction func genPauseInBackgroundAction(_ sender: NSButton!) {
        
        pref.pauseInBackground = (sender.state == .on)
        refresh()
    }
    
    @IBAction func genCloseWithoutAskingAction(_ sender: NSButton!) {
        
        pref.closeWithoutAsking = (sender.state == .on)
        for c in myAppDelegate.controllers {
            c.needsSaving = c.emu?.running ?? false
        }
        refresh()
    }
        
    //
    // Action methods (Misc)
    //
    
    @IBAction func genPresetAction(_ sender: NSPopUpButton!) {
        
        assert(sender.selectedTag() == 0)

        // Revert to standard settings
        EmulatorProxy.defaults.removeGeneralUserDefaults()

        // Apply the new settings
        pref.applyGeneralUserDefaults()

        refresh()
    }
}

// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

/* This class stores all emulator settings that belong to the application level.
 * There is a single object of this class stored in the application delegate.
 * The object is shared among all emulator instances.
 *
 * See class "Configuration" for instance specific settings.
 */

class Preferences {
        
    //
    // General
    //

    // Snapshots
    var autoSnapshots = false {
        didSet {
            for emu in myAppDelegate.proxies {
                emu?.set(.ATARI_SNAP_AUTO, enable: autoSnapshots)
            }
        }
    }
    var snapshotInterval = 0 {
        didSet {
            for emu in myAppDelegate.proxies {
                emu?.set(.ATARI_SNAP_DELAY, value: snapshotInterval)
            }
        }
    }

    // Screenshots
    var screenshotSource = 0
    var screenshotTarget = NSBitmapImageRep.FileType.png
    var screenshotTargetIntValue: Int {
        get { return Int(screenshotTarget.rawValue) }
        set { screenshotTarget = NSBitmapImageRep.FileType(rawValue: UInt(newValue))! }
    }

    // Fullscreen
    var keepAspectRatio = false
    var exitOnEsc = false
    
    // Misc
    var ejectWithoutAsking = false
    var closeWithoutAsking = false
    var pauseInBackground = false

    //
    // Controls
    //
    
    // Emulation keys
    var keyMaps: [[MacKey: Int]] = [ [:], [:], [:] ]

    // Joystick
    var disconnectJoyKeys = false

    // Mouse
    var retainMouseKeyComb = 0
    var retainMouseWithKeys = false
    var retainMouseByClick = false
    var retainMouseByEntering = false
    var releaseMouseKeyComb = 0
    var releaseMouseWithKeys = false
    var releaseMouseByShaking = false
}

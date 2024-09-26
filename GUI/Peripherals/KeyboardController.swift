// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

import Carbon.HIToolbox

class KeyboardController: NSObject {
    
    var myAppDelegate: MyAppDelegate { return NSApp.delegate as! MyAppDelegate }
    var parent: MyController!
        
    var emu: EmulatorProxy? { return parent.emu }
    var renderer: Renderer { return parent.renderer }
    var pref: Preferences { return parent.pref }
    
    // Remembers the state of some keys (true = currently pressed)
    var leftShift   = false, rightShift   = false
    var leftControl = false, rightControl = false
    var leftOption  = false, rightOption  = false
    var leftCommand = false, rightCommand = false
    var capsLock    = false

    // Remembers the currently pressed keys and their assigned C64 key list.
    // This variable is only used when keys are mapped symbolically. It it
    // written in keyDown and picked up in keyUp.
    var pressedKeys: [Int: [C64Key]] = [:]
        
    init(parent: MyController) {
        
        super.init()
        self.parent = parent
    }
    
    func keyDown(with event: NSEvent) {
                
        // Intercept if the console is open
        if renderer.console.isVisible { renderer.console.keyDown(with: event); return }

        // Ignore repeating keys
        if event.isARepeat { return }
        
        // Exit fullscreen mode if escape key is pressed
        if event.keyCode == kVK_Escape && renderer.fullscreen && pref.exitOnEsc {
            parent.window!.toggleFullScreen(nil)
            return
        }
        
        // Ignore keys that are pressed in combination with the Command key
        if event.modifierFlags.contains(NSEvent.ModifierFlags.command) { return }
        
        keyDown(with: MacKey(event: event))
    }
    
    func keyUp(with event: NSEvent) {
                
        // Intercept if the console is open
        if renderer.console.isVisible { renderer.console.keyUp(with: event); return }
        
        keyUp(with: MacKey(event: event))
    }
    
    func flagsChanged(with event: NSEvent) {
                
        debug(.events,
              "ls: \(leftShift) rs: \(rightShift) lc: \(leftControl) " +
              "rc: \(rightControl) lo: \(leftOption) ro: \(rightOption)")
        
        // Determine the pressed or released key
        switch Int(event.keyCode) {
            
        case kVK_Shift:
            leftShift = event.modifierFlags.contains(.shift) ? !leftShift : false
            if leftShift { keyDown(with: MacKey.shift) } else { keyUp(with: MacKey.shift) }

        case kVK_RightShift:
            rightShift = event.modifierFlags.contains(.shift) ? !rightShift : false
            if rightShift { keyDown(with: MacKey.rightShift) } else { keyUp(with: MacKey.rightShift) }

        case kVK_Control:
            leftControl = event.modifierFlags.contains(.control) ? !leftControl : false
            if leftControl { keyDown(with: MacKey.control) } else { keyUp(with: MacKey.control) }

        case kVK_RightControl:
            rightControl = event.modifierFlags.contains(.control) ? !rightControl : false
            if rightControl { keyDown(with: MacKey.rightControl) } else { keyUp(with: MacKey.rightControl) }

        case kVK_Option:
            leftOption = event.modifierFlags.contains(.option) ? !leftOption : false
            if leftOption { keyDown(with: MacKey.option) } else { keyUp(with: MacKey.option) }

        case kVK_RightOption:
            rightOption = event.modifierFlags.contains(.option) ? !rightOption : false
            if rightOption { keyDown(with: MacKey.rightOption) } else { keyUp(with: MacKey.rightOption) }

        case kVK_CapsLock where myAppDelegate.mapCapsLockWarp:
            capsLock = event.modifierFlags.contains(.capsLock)
            if capsLock { capsLockDown() } else { capsLockUp() }

        default:
            break
        }
    }
    
    func keyDown(with macKey: MacKey) {

        // Check if this key is used to emulate a game device
        if parent.gamePad1?.processKeyDownEvent(macKey: macKey) == true {
            if pref.disconnectJoyKeys { return }
        }
        if parent.gamePad2?.processKeyDownEvent(macKey: macKey) == true {
            if pref.disconnectJoyKeys { return }
        }
    }

    func keyUp(with macKey: MacKey) {
        
        // Check if this key is used to emulate a game device
        if parent.gamePad1?.processKeyUpEvent(macKey: macKey) == true {
            if pref.disconnectJoyKeys { return }
        }
        if parent.gamePad2?.processKeyUpEvent(macKey: macKey) == true {
            if pref.disconnectJoyKeys { return }
        }
    }

    func capsLockDown() {

        parent.config.warpMode = tiara.WarpMode.ALWAYS.rawValue
    }

    func capsLockUp() {

        parent.config.warpMode = tiara.WarpMode.NEVER.rawValue
    }
}

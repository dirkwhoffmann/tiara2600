// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

class DialogWindow: NSWindow {

    // Delegation method for ESC and Cmd+
    override func cancelOperation(_ sender: Any?) {

        if let controller = delegate as? DialogController {
            controller.cancelAction(sender)
        }
    }
}

protocol DialogControllerDelegate: AnyObject {

    // Called before beginSheet() is called
    func sheetWillShow()

    // Called after beginSheet() has beed called
    func sheetDidShow()

    // Called after the completion handler has been executed
    func cleanup()
}

/* Base class for all auxiliary windows. The class extends NSWindowController
 * by a reference to the controller of the connected emulator window (parent)
 * and a reference to the parents proxy object. It also provides some wrappers
 * around showing and hiding the window.
 */
class DialogController: NSWindowController, DialogControllerDelegate {
    
    var parent: MyController!
    var emu: EmulatorProxy? { return parent.emu }
    var c64: AtariProxy? { return emu?.atari }
    var mm: MediaManager { return parent.mydocument.mm }

    // List of open windows or sheets (to make ARC happy)
    static var active: [DialogController] = []

    // Remembers whether awakeFromNib has been called
    var awake = false

    // Lock that is kept during the lifetime of the dialog
    var lock = NSLock()

    convenience init?(with controller: MyController, nibName: NSNib.Name) {

        self.init(windowNibName: nibName)
        
        lock.lock()
        parent = controller
    }

    func register() {

        DialogController.active.append(self)
        debug(.lifetime, "Register: \(DialogController.active)")
    }

    func unregister() {

        DialogController.active = DialogController.active.filter {$0 != self}
        debug(.lifetime, "Unregister: \(DialogController.active)")
    }

    override func windowWillLoad() {
    }
    
    override func windowDidLoad() {
    }

    override func awakeFromNib() {

        awake = true
        window?.delegate = self
        sheetWillShow()
    }

    func sheetWillShow() {
        
    }
    
    func sheetDidShow() {
        
    }
    
    func cleanup() {
        
    }

    func showWindow(completionHandler handler: (() -> Void)? = nil) {

        register()
        if awake { sheetWillShow() }

        showWindow(self)
        sheetDidShow()
    }

    func showSheet(completionHandler handler: (() -> Void)? = nil) {
        
        register()
        if awake { sheetWillShow() }

        parent.window?.beginSheet(window!, completionHandler: { result in

            handler?()
            self.cleanup()
        })

        sheetDidShow()
    }
    
    func hideSheet() {

        if let win = window {
            parent.window?.endSheet(win, returnCode: .cancel)
        }
        unregister()
    }

    @IBAction func okAction(_ sender: Any!) {

        hideSheet()
    }

    @IBAction func cancelAction(_ sender: Any!) {

        hideSheet()
    }

    func join() {

        debug(.shutdown, "Wait until window is closed...")

        lock.lock()
        lock.unlock()
    }
}

extension DialogController: NSWindowDelegate {

    func windowWillClose(_ notification: Notification) {

        unregister()
        lock.unlock()
    }
}

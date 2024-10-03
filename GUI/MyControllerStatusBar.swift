// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
// -----------------------------------------------------------------------------

extension MyController {

    var hourglassIcon: NSImage? {

        if tiara.WarpMode(rawValue: config.warpMode) == .AUTO {

            return NSImage(named: emu?.info.warping == true ? "hourglass3Template" : "hourglass1Template")

        } else {

            return NSImage(named: emu?.info.warping == true ? "warpOnTemplate" : "warpOffTemplate")
        }
    }

    public func refreshStatusBar() {

        if let emu = emu {

            let c64state = emu.info
            let running = c64state.running
            let tracking = c64state.tracking
            let warping = c64state.warping
            let boost = emu.get(.ATARI_SPEED_BOOST)

            // Remote server icon
            refreshStatusBarServerIcon()

            // Warp mode
            refreshStatusBarWarpIcon()

            // Speed adjust
            speedStepper.integerValue = boost
            speedStepper.toolTip = "\(boost) %"

            // Visibility
            let items: [NSView: Bool] = [

                haltIcon: jammed,
                serverIcon: true,
                trackIcon: tracking,
                muteIcon: warping || muted,
                warpIcon: running,
                activityType: running,
                activityInfo: running,
                activityBar: running,
                speedStepper: running
            ]

            for (item, visible) in items {
                item.isHidden = !visible || !statusBar
            }
        }
    }

    func refreshStatusBarServerIcon() {

        if let emu = emu {

            serverIcon.image = emu.remoteManager.icon
        }
    }

    func refreshStatusBarWarpIcon() {

        warpIcon.image = hourglassIcon
    }

    func showStatusBar(_ value: Bool) {

        if statusBar != value {

            if value {

                metal.adjustHeight(-26.0)
                window?.setContentBorderThickness(26, for: .minY)
                adjustWindowSize(dy: 26.0)

            } else {

                metal.adjustHeight(26.0)
                window?.setContentBorderThickness(0.0, for: .minY)
                adjustWindowSize(dy: -26.0)
            }

            statusBar = value
            refreshStatusBar()
        }
    }

    func updateSpeedometer() {

        func setColor(color: [NSColor]) {

            let min = activityBar.minValue
            let max = activityBar.maxValue
            let cur = (activityBar.doubleValue - min) / (max - min)

            let index =
            cur < 0.15 ? 0 :
            cur < 0.40 ? 1 :
            cur < 0.60 ? 2 :
            cur < 0.85 ? 3 : 4

            activityBar.fillColor = color[index]
        }

        if let emu = emu {

            let state = emu.cpu.info
            // print("cycle = \(state.cycle)")
            speedometer.updateWith(cycle: state.cycle, gpuFrame: renderer.frames)

            switch activityType.selectedTag() {

            case 0:
                let mhz = speedometer.mhz
                activityBar.maxValue = 24
                activityBar.doubleValue = 10 * mhz
                activityInfo.stringValue = String(format: "%.2f MHz", mhz)
                setColor(color: [.systemRed, .systemYellow, .systemGreen, .systemYellow, .systemRed])

            case 1:
                let fps = emu.stats.fps
                activityBar.maxValue = 120
                activityBar.doubleValue = fps
                activityInfo.stringValue = String(format: "%d Hz", Int(fps))
                setColor(color: [.systemRed, .systemYellow, .systemGreen, .systemYellow, .systemRed])

            case 2:
                let cpu = Int(emu.stats.cpuLoad * 100)
                activityBar.maxValue = 100
                activityBar.integerValue = cpu
                activityInfo.stringValue = String(format: "%d%% CPU", cpu)
                setColor(color: [.systemGreen, .systemGreen, .systemGreen, .systemYellow, .systemRed])

            case 3:
                let fps = speedometer.gpsFps
                activityBar.maxValue = 120
                activityBar.doubleValue = fps
                activityInfo.stringValue = String(format: "%d FPS", Int(fps))
                setColor(color: [.systemRed, .systemYellow, .systemGreen, .systemYellow, .systemRed])

            case 4:
                let fill = emu.audioPort.stats.fillLevel * 100.0
                activityBar.maxValue = 100
                activityBar.doubleValue = fill
                activityInfo.stringValue = String(format: "Fill level %d%%", Int(fill))
                setColor(color: [.systemRed, .systemYellow, .systemGreen, .systemYellow, .systemRed])

            default:
                activityBar.integerValue = 0
                activityInfo.stringValue = "???"
            }
        }
    }

    //
    // Action methods
    //

    @IBAction func warpAction(_ sender: Any!) {

        switch tiara.WarpMode(rawValue: config.warpMode) {

        case .AUTO: config.warpMode = tiara.WarpMode.NEVER.rawValue
        case .NEVER: config.warpMode = tiara.WarpMode.ALWAYS.rawValue
        case .ALWAYS: config.warpMode = tiara.WarpMode.AUTO.rawValue

        default:
            fatalError()
        }

        refreshStatusBar()
        myAppDelegate.prefController?.refresh()
    }

    @IBAction func activityTypeAction(_ sender: NSPopUpButton!) {

        refreshStatusBar()
    }

    @IBAction func speedAction(_ sender: NSStepper!) {

        // Round the value to the next number dividable by 5
        var value = Int(round(sender.doubleValue / 5.0)) * 5

        // Make sure the value is in the valid range
        if value < 50 { value = 50 }
        if value > 200 { value = 200 }

        emu?.set(.ATARI_SPEED_BOOST, value: value)
    }

    @IBAction func speedResetAction(_ sender: Any!) {

        emu?.set(.ATARI_SPEED_BOOST, value: 100)
    }
}

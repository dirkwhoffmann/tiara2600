// -----------------------------------------------------------------------------
// This file is part of Tiara2600
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// This FILE is dual-licensed. You are free to choose between:
//
//     - The GNU General Public License v3 (or any later version)
//     - The Mozilla Public License v2
//
// SPDX-License-Identifier: GPL-3.0-or-later OR MPL-2.0
// -----------------------------------------------------------------------------
/// @file

#pragma once

#include "Reflection.h"

namespace tiara {

//
// Enumerations
//

/// Configuration option
enum_long(OPT)
{
    // Host
    OPT_HOST_REFRESH_RATE,      ///< Video refresh rate of the host display
    OPT_HOST_SAMPLE_RATE,       ///< Audio sample rate of the host display
    OPT_HOST_FRAMEBUF_WIDTH,    ///< Current width of the emulator window
    OPT_HOST_FRAMEBUF_HEIGHT,   ///< Current height of the emulator window

    // C64
    OPT_ATARI_WARP_BOOT,        ///< Warp-boot time in seconds
    OPT_ATARI_WARP_MODE,        ///< Warp activation mode
    OPT_ATARI_VSYNC,            ///< Derive the frame rate to the VSYNC signal
    OPT_ATARI_SPEED_BOOST,      ///< Speed adjustment in percent
    OPT_ATARI_RUN_AHEAD,        ///< Number of run-ahead frames

    // Snapshots
    OPT_ATARI_SNAP_AUTO,        ///< Automatically take a snapshots
    OPT_ATARI_SNAP_DELAY,       ///< Delay between two snapshots in seconds
    OPT_ATARI_SNAP_COMPRESS,    ///< Compress snapshot data

    // TIA
    OPT_TIA_REVISION,           ///< Chip revision
    OPT_TIA_POWER_SAVE,         ///< Enable fast-paths

    // PIA
    OPT_RAM_INIT_PATTERN,       ///< Initial RAM values

    // Logic Analyzer
    OPT_LA_ENABLE,              ///< Global on/off switch of the logic analyzer
    OPT_LA_CHANNEL0,            ///< Enable channel 0
    OPT_LA_CHANNEL1,            ///< Enable channel 1
    OPT_LA_CHANNEL2,            ///< Enable channel 2
    OPT_LA_CHANNEL3,            ///< Enable channel 3
    OPT_LA_PROBE0,              ///< Probe on channel 0
    OPT_LA_PROBE1,              ///< Probe on channel 1
    OPT_LA_PROBE2,              ///< Probe on channel 2
    OPT_LA_PROBE3,              ///< Probe on channel 3
    OPT_LA_MODE,                ///< Visual style (overlay mode)
    OPT_LA_OPACITY,             ///< Texture opacity

    // Cartridge port
    OPT_CART_TYPE,              ///< Type of the plugged-in cartridge

    // Video port
    OPT_VID_WHITE_NOISE,        ///< Generate white-noise when switched off

    // Monitor
    OPT_MON_PALETTE,            ///< Color palette
    OPT_MON_BRIGHTNESS,         ///< Brightness
    OPT_MON_CONTRAST,           ///< Contrast
    OPT_MON_SATURATION,         ///< Color saturation
    OPT_MON_HCENTER,            ///< Horizontal centering
    OPT_MON_VCENTER,            ///< Vertical centering
    OPT_MON_HZOOM,              ///< Horizontal zoom
    OPT_MON_VZOOM,              ///< Vertical centering
    OPT_MON_UPSCALER,           ///< Pixel upscaler
    OPT_MON_BLUR,               ///< Blur enable
    OPT_MON_BLUR_RADIUS,        ///< Blur radius
    OPT_MON_BLOOM,              ///< Bloom enable
    OPT_MON_BLOOM_RADIUS,       ///< Bloom radius
    OPT_MON_BLOOM_BRIGHTNESS,   ///< Bloom brightness
    OPT_MON_BLOOM_WEIGHT,       ///< Bloom weight
    OPT_MON_DOTMASK,            ///< Dotmask pattern
    OPT_MON_DOTMASK_BRIGHTNESS, ///< Dotmask brightness
    OPT_MON_SCANLINES,          ///< Scanline mode
    OPT_MON_SCANLINE_BRIGHTNESS,///< Scanline brightness
    OPT_MON_SCANLINE_WEIGHT,    ///< Scanline weight
    OPT_MON_DISALIGNMENT,       ///< Cathode ray disalignment enable
    OPT_MON_DISALIGNMENT_H,     ///< Horizontal cathode ray disalignment
    OPT_MON_DISALIGNMENT_V,     ///< Vertical cathode ray disalignment

    // SID
    OPT_SID_SAMPLING,           ///< Audio sampling mode

    // Audio port
    OPT_AUD_VOL0,               ///< Channel 0 volume
    OPT_AUD_VOL1,               ///< Channel 1 volume
    OPT_AUD_VOL2,               ///< Channel 2 volume
    OPT_AUD_VOL3,               ///< Channel 3 volume
    OPT_AUD_PAN0,               ///< Channel 0 panning
    OPT_AUD_PAN1,               ///< Channel 1 panning
    OPT_AUD_PAN2,               ///< Channel 2 panning
    OPT_AUD_PAN3,               ///< Channel 3 panning
    OPT_AUD_VOL_L,              ///< Master volume (left channel)
    OPT_AUD_VOL_R,              ///< Master volume (right channel)

    // Memory
    OPT_MEM_HEATMAP,            ///< Memory heatmap

    // Mouse
    OPT_MOUSE_SHAKE_DETECT,     ///< Detect a shaking mouse

    // Joystick
    OPT_AUTOFIRE,               ///< Autofire status [on/off]
    OPT_AUTOFIRE_BURSTS,        ///< Burst mode (on/off)
    OPT_AUTOFIRE_BULLETS,       ///< Number of bullets per burst
    OPT_AUTOFIRE_DELAY,         ///< Delay between two shots [frames]

    // Paddles
    OPT_PADDLE_ORIENTATION,     ///< Paddle value mapping scheme

    // Remote servers
    OPT_SRV_PORT,
    OPT_SRV_PROTOCOL,
    OPT_SRV_AUTORUN,
    OPT_SRV_VERBOSE,

    // Regression tester
    OPT_DBG_DEBUGCART,          ///< Emulate the VICE debug cartridge
    OPT_DBG_WATCHDOG,           ///< Watchdog delay in frames

    OPT_COUNT
};
typedef OPT Option;

struct OptionEnum : util::Reflection<OptionEnum, Option> {

    static constexpr long minVal = 0;
    static constexpr long maxVal = OPT_DBG_WATCHDOG;

    static const char *prefix() { return "OPT"; }
    static const char *_key(long value)
    {
        switch (value) {

            case OPT_HOST_REFRESH_RATE:     return "HOST.REFRESH_RATE";
            case OPT_HOST_SAMPLE_RATE:      return "HOST.SAMPLE_RATE";
            case OPT_HOST_FRAMEBUF_WIDTH:   return "HOST.FRAMEBUF_WIDTH";
            case OPT_HOST_FRAMEBUF_HEIGHT:  return "HOST.FRAMEBUF_HEIGHT";

            case OPT_ATARI_WARP_BOOT:       return "C64.WARP_BOOT";
            case OPT_ATARI_WARP_MODE:       return "C64.WARP_MODE";
            case OPT_ATARI_VSYNC:           return "C64.VSYNC";
            case OPT_ATARI_SPEED_BOOST:     return "C64.SPEED_BOOST";
            case OPT_ATARI_RUN_AHEAD:       return "C64.RUN_AHEAD";
            
            case OPT_ATARI_SNAP_AUTO:       return "C64.SNAP_AUTO";
            case OPT_ATARI_SNAP_DELAY:      return "C64.SNAP_DELAY";
            case OPT_ATARI_SNAP_COMPRESS:   return "C64.SNAP_COMPRESS";

            case OPT_TIA_REVISION:          return "TIA.REVISION";
            case OPT_TIA_POWER_SAVE:        return "TIA.POWER_SAVE";

            case OPT_RAM_INIT_PATTERN:      return "PIA.RAM_INIT_PATTERN";

            case OPT_LA_ENABLE:             return "LA.ENABLE";
            case OPT_LA_CHANNEL0:           return "LA.CHANNEL0";
            case OPT_LA_CHANNEL1:           return "LA.CHANNEL1";
            case OPT_LA_CHANNEL2:           return "LA.CHANNEL2";
            case OPT_LA_CHANNEL3:           return "LA.CHANNEL3";
            case OPT_LA_PROBE0:             return "LA.PROBE0";
            case OPT_LA_PROBE1:             return "LA.PROBE1";
            case OPT_LA_PROBE2:             return "LA.PROBE2";
            case OPT_LA_PROBE3:             return "LA.PROBE3";
            case OPT_LA_MODE:               return "LA.MODE";
            case OPT_LA_OPACITY:            return "LA.OPACITY";

            case OPT_CART_TYPE:             return "CART.TYPE";

            case OPT_VID_WHITE_NOISE:       return "VID.WHITE_NOISE";

            case OPT_MON_PALETTE:           return "MON.PALETTE";
            case OPT_MON_BRIGHTNESS:        return "MON.BRIGHTNESS";
            case OPT_MON_CONTRAST:          return "MON.CONTRAST";
            case OPT_MON_SATURATION:        return "MON.SATURATION";
            case OPT_MON_HCENTER:           return "MON.HCENTER";
            case OPT_MON_VCENTER:           return "MON.VCENTER";
            case OPT_MON_HZOOM:             return "MON.HZOOM";
            case OPT_MON_VZOOM:             return "MON.VZOOM";
            case OPT_MON_UPSCALER:          return "MON.UPSCALER";
            case OPT_MON_BLUR:              return "MON.BLUR";
            case OPT_MON_BLUR_RADIUS:       return "MON.BLUR_RADIUS";
            case OPT_MON_BLOOM:             return "MON.BLOOM";
            case OPT_MON_BLOOM_RADIUS:      return "MON.BLOOM_RADIUS";
            case OPT_MON_BLOOM_BRIGHTNESS:  return "MON.BLOOM_BRIGHTNESS";
            case OPT_MON_BLOOM_WEIGHT:      return "MON.BLOOM_WEIGHT";
            case OPT_MON_DOTMASK:           return "MON.DOTMASK";
            case OPT_MON_DOTMASK_BRIGHTNESS:    return "MON.DOTMASK_BRIGHTNESS";
            case OPT_MON_SCANLINES:             return "MON.SCANLINES";
            case OPT_MON_SCANLINE_BRIGHTNESS:   return "MON.SCANLINE_BRIGHTNESS";
            case OPT_MON_SCANLINE_WEIGHT:       return "MON.SCANLINE_WEIGHT";
            case OPT_MON_DISALIGNMENT:      return "MON.DISALIGNMENT";
            case OPT_MON_DISALIGNMENT_H:    return "MON.DISALIGNMENT_H";
            case OPT_MON_DISALIGNMENT_V:    return "MON.DISALIGNMENT_V";

            case OPT_SID_SAMPLING:          return "SID.SAMPLING";

            case OPT_AUD_VOL0:              return "AUD.VOL0";
            case OPT_AUD_VOL1:              return "AUD.VOL1";
            case OPT_AUD_VOL2:              return "AUD.VOL2";
            case OPT_AUD_VOL3:              return "AUD.VOL3";
            case OPT_AUD_PAN0:              return "AUD.PAN0";
            case OPT_AUD_PAN1:              return "AUD.PAN1";
            case OPT_AUD_PAN2:              return "AUD.PAN2";
            case OPT_AUD_PAN3:              return "AUD.PAN3";
            case OPT_AUD_VOL_L:             return "AUD.VOLL";
            case OPT_AUD_VOL_R:             return "AUD.VOLR";

            case OPT_MEM_HEATMAP:           return "MEM.HEATMAP";

            case OPT_MOUSE_SHAKE_DETECT:    return "MOUSE.SHAKE_DETECTION";

            case OPT_AUTOFIRE:              return "AUTOFIRE.ENABLE";
            case OPT_AUTOFIRE_BURSTS:       return "AUTOFIRE.BURSTS";
            case OPT_AUTOFIRE_BULLETS:      return "AUTOFIRE.BULLETS";
            case OPT_AUTOFIRE_DELAY:        return "AUTOFIRE.DELAY";

            case OPT_PADDLE_ORIENTATION:    return "PADDLE.ORIENTATION";

            case OPT_SRV_PORT:              return "SRV.PORT";
            case OPT_SRV_PROTOCOL:          return "SRV.PROTOCOL";
            case OPT_SRV_AUTORUN:           return "SRV.AUTORUN";
            case OPT_SRV_VERBOSE:           return "SRV.VERBOSE";

            case OPT_DBG_DEBUGCART:         return "DBG.DEBUGCART";
            case OPT_DBG_WATCHDOG:          return "DBG.WATCHDOG";

            case OPT_COUNT:                 return "???";
        }
        return "???";
    }

    static const char *help(Option value)
    {
        switch (value) {

            case OPT_HOST_REFRESH_RATE:     return "Host video refresh rate";
            case OPT_HOST_SAMPLE_RATE:      return "Host audio sample rate";
            case OPT_HOST_FRAMEBUF_WIDTH:   return "Window width";
            case OPT_HOST_FRAMEBUF_HEIGHT:  return "Window height";

            case OPT_ATARI_WARP_BOOT:       return "Warp-boot duration";
            case OPT_ATARI_WARP_MODE:       return "Warp activation";
            case OPT_ATARI_VSYNC:           return "VSYNC mode";
            case OPT_ATARI_SPEED_BOOST:      return "Speed adjustment";
            case OPT_ATARI_RUN_AHEAD:       return "Run-ahead frames";

            case OPT_ATARI_SNAP_AUTO:       return "Automatically take snapshots";
            case OPT_ATARI_SNAP_DELAY:      return "Time span between two snapshots";
            case OPT_ATARI_SNAP_COMPRESS:   return "Compress snapshot data";

            case OPT_TIA_REVISION:          return "Video standard";
            case OPT_TIA_POWER_SAVE:        return "Take fast paths";

            case OPT_RAM_INIT_PATTERN:      return "Memory start-up pattern";

            case OPT_LA_ENABLE:             return "Logic analyzer";
            case OPT_LA_CHANNEL0:           return "Channel 0 enable";
            case OPT_LA_CHANNEL1:           return "Channel 1 enable";
            case OPT_LA_CHANNEL2:           return "Channel 2 enable";
            case OPT_LA_CHANNEL3:           return "Channel 3 enable";
            case OPT_LA_PROBE0:             return "Channel 0 probe";
            case OPT_LA_PROBE1:             return "Channel 1 probe";
            case OPT_LA_PROBE2:             return "Channel 2 probe";
            case OPT_LA_PROBE3:             return "Channel 3 probe";
            case OPT_LA_MODE:               return "Logic analyzer visual style";
            case OPT_LA_OPACITY:            return "Overlay opacity";

            case OPT_CART_TYPE:             return "Cartridge type";

            case OPT_VID_WHITE_NOISE:       return "White noise";

            case OPT_MON_PALETTE:           return "Color palette";
            case OPT_MON_BRIGHTNESS:        return "Monitor brightness";
            case OPT_MON_CONTRAST:          return "Monitor contrast";
            case OPT_MON_SATURATION:        return "Monitor saturation";
            case OPT_MON_HCENTER:           return "Horizontal center";
            case OPT_MON_VCENTER:           return "Vertical center";
            case OPT_MON_HZOOM:             return "Horizontal zoom";
            case OPT_MON_VZOOM:             return "Vertical zoom";
            case OPT_MON_UPSCALER:          return "Upscaler";
            case OPT_MON_BLUR:              return "Blur";
            case OPT_MON_BLUR_RADIUS:       return "Blur radius";
            case OPT_MON_BLOOM:             return "Bloom";
            case OPT_MON_BLOOM_RADIUS:      return "Bloom radius";
            case OPT_MON_BLOOM_BRIGHTNESS:  return "Bloom brightness";
            case OPT_MON_BLOOM_WEIGHT:      return "Bloom weight";
            case OPT_MON_DOTMASK:           return "Dotmask";
            case OPT_MON_DOTMASK_BRIGHTNESS:    return "Dotmask brightness";
            case OPT_MON_SCANLINES:             return "Scanlines";
            case OPT_MON_SCANLINE_BRIGHTNESS:   return "Scanline brightness";
            case OPT_MON_SCANLINE_WEIGHT:       return "Scanline weight";
            case OPT_MON_DISALIGNMENT:      return "Cathode rays disalignment";
            case OPT_MON_DISALIGNMENT_H:    return "Horizontal cathode ray shift";
            case OPT_MON_DISALIGNMENT_V:    return "Vertical cathode ray shift";

            case OPT_SID_SAMPLING:          return "Audio sampling rate";
            case OPT_AUD_VOL0:              return "Channel 0 volume";
            case OPT_AUD_VOL1:              return "Channel 1 volume";
            case OPT_AUD_VOL2:              return "Channel 2 volume";
            case OPT_AUD_VOL3:              return "Channel 3 volume";
            case OPT_AUD_PAN0:              return "Channel 0 pan";
            case OPT_AUD_PAN1:              return "Channel 1 pan";
            case OPT_AUD_PAN2:              return "Channel 2 pan";
            case OPT_AUD_PAN3:              return "Channel 3 pan";
            case OPT_AUD_VOL_L:             return "Master volume (left)";
            case OPT_AUD_VOL_R:             return "Master volume (right)";

            case OPT_MEM_HEATMAP:           return "Heatmap";

            case OPT_MOUSE_SHAKE_DETECT:    return "Detect a shaked mouse";

            case OPT_AUTOFIRE:              return "Autofire";
            case OPT_AUTOFIRE_BURSTS:       return "Burst mode";
            case OPT_AUTOFIRE_BULLETS:      return "Number of bullets per burst";
            case OPT_AUTOFIRE_DELAY:        return "Autofire delay in frames";

            case OPT_PADDLE_ORIENTATION:    return "Paddle value mapping scheme";

            case OPT_SRV_PORT:              return "Server port";
            case OPT_SRV_PROTOCOL:          return "Server protocol";
            case OPT_SRV_AUTORUN:           return "Auto run";
            case OPT_SRV_VERBOSE:           return "Verbose mode";

            case OPT_DBG_DEBUGCART:         return "VICE debug cartridge";
            case OPT_DBG_WATCHDOG:          return "Watchdog delay in cycles";

            case OPT_COUNT:                 return "???";
        }
        return "???";
    }
};

}

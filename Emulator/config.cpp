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

#include "config.h"

// General
debugflag XFILES          = 0;
debugflag CNF_DEBUG       = 0;
debugflag DEF_DEBUG       = 0;

// Runloop
debugflag RUN_DEBUG       = 0;
debugflag TIM_DEBUG       = 0;
debugflag WARP_DEBUG      = 0;
debugflag CMD_DEBUG       = 0;
debugflag MSG_DEBUG       = 0;
debugflag SNP_DEBUG       = 0;

// Run ahead
debugflag RUA_DEBUG       = 0;
debugflag RUA_CHECKSUM    = 0;
debugflag RUA_ON_STEROIDS = 0;

// CPU
debugflag CPU_DEBUG       = 0;
debugflag IRQ_DEBUG       = 0;

// Memory
debugflag MEM_DEBUG       = 0;

// TIA
debugflag TIA_DEBUG       = 0;
debugflag TIA_REG_DEBUG   = 0;
debugflag AUD_DEBUG       = 1;
debugflag AUDREG_DEBUG    = 0;
debugflag AUDBUF_DEBUG    = 0;
debugflag AUDVOL_DEBUG    = 0;

// PIA
debugflag PIA_DEBUG       = 0;
debugflag PIA_REG_DEBUG   = 0;

// Media
debugflag CART_DEBUG      = 0;
debugflag FILE_DEBUG      = 0;

// Peripherals
debugflag JOY_DEBUG       = 0;
debugflag DRV_DEBUG       = 0;
debugflag TAP_DEBUG       = 0;
debugflag KBD_DEBUG       = 0;
debugflag PRT_DEBUG       = 0;
debugflag EXP_DEBUG       = 0;
debugflag USR_DEBUG       = 0;

// Other components
debugflag REC_DEBUG       = 0;
debugflag REU_DEBUG       = 0;
debugflag SCK_DEBUG       = 0;
debugflag SRV_DEBUG       = 0;


//
// Forced error conditions
//

debugflag FORCE_ROM_MISSING              = 0;
debugflag FORCE_MEGA64_MISMATCH          = 0;
debugflag FORCE_SNAP_TOO_OLD             = 0;
debugflag FORCE_SNAP_TOO_NEW             = 0;
debugflag FORCE_SNAP_IS_BETA             = 0;
debugflag FORCE_SNAP_CORRUPTED           = 0;
debugflag FORCE_CRT_UNKNOWN              = 0;
debugflag FORCE_CRT_UNSUPPORTED          = 0;
debugflag FORCE_RECORDING_ERROR          = 0;
debugflag FORCE_NO_FFMPEG                = 0;

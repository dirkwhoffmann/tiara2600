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

#pragma once

//
// Release settings
//

// Version number
#define VER_MAJOR 0
#define VER_MINOR 0
#define VER_SUBMINOR 1
#define VER_BETA 1

// Snapshot version number
#define SNP_MAJOR 0
#define SNP_MINOR 0
#define SNP_SUBMINOR 1
#define SNP_BETA 2

// Uncomment these settings in a release build
// #define RELEASEBUILD


//
// Build settings
//

#if defined(__clang__)

#define alwaysinline __attribute__((always_inline))
#pragma GCC diagnostic ignored "-Wgnu-anonymous-struct"
#pragma GCC diagnostic ignored "-Wnested-anon-types"

#elif defined(__GNUC__) || defined(__GNUG__)

#define alwaysinline __attribute__((always_inline))

#elif defined(_MSC_VER)

#define alwaysinline __forceinline

#endif


//
// Configuration overrides
//

#define OVERRIDES { }


//
// Debug settings
//

#ifdef RELEASEBUILD
#ifndef NDEBUG
#define NDEBUG
#endif
static const bool releaseBuild = 1;
static const bool debugBuild = 0;
typedef const int debugflag;
#else
static const bool releaseBuild = 0;
static const bool debugBuild = 1;
typedef int debugflag;
#endif

#if VER_BETA == 0
static const bool betaRelease = 0;
#else
static const bool betaRelease = 1;
#endif

#ifdef __EMSCRIPTEN__
static const bool emscript = 1;
#else
static const bool emscript = 0;
#endif


// General
extern debugflag XFILES;
extern debugflag CNF_DEBUG;
extern debugflag DEF_DEBUG;

// Emulator
extern debugflag RUN_DEBUG;
extern debugflag TIM_DEBUG;
extern debugflag WARP_DEBUG;
extern debugflag CMD_DEBUG;
extern debugflag MSG_DEBUG;
extern debugflag SNP_DEBUG;

// Run ahead
extern debugflag RUA_DEBUG;
extern debugflag RUA_CHECKSUM;
extern debugflag RUA_ON_STEROIDS;

// CPU
extern debugflag CPU_DEBUG;
extern debugflag IRQ_DEBUG;

// Memory
extern debugflag MEM_DEBUG;

// TIA
extern debugflag TIA_DEBUG;
extern debugflag TIA_REG_DEBUG;

// PIA
extern debugflag PIA_DEBUG;
extern debugflag PIA_REG_DEBUG;

// SID
extern debugflag SID_DEBUG;
extern debugflag SID_EXEC;
extern debugflag SIDREG_DEBUG;
extern debugflag AUDBUF_DEBUG;
extern debugflag AUDVOL_DEBUG;

// Media
extern debugflag CART_DEBUG;
extern debugflag FILE_DEBUG;

// Peripherals
extern debugflag JOY_DEBUG;
extern debugflag DRV_DEBUG;
extern debugflag TAP_DEBUG;
extern debugflag KBD_DEBUG;
extern debugflag PRT_DEBUG;
extern debugflag EXP_DEBUG;
extern debugflag USR_DEBUG;

// Other components
extern debugflag REC_DEBUG;
extern debugflag REU_DEBUG;
extern debugflag SCK_DEBUG;
extern debugflag SRV_DEBUG;


//
// Forced error conditions
//

extern debugflag FORCE_ROM_MISSING;
extern debugflag FORCE_MEGA64_MISMATCH;
extern debugflag FORCE_SNAP_TOO_OLD;
extern debugflag FORCE_SNAP_TOO_NEW;
extern debugflag FORCE_SNAP_IS_BETA;
extern debugflag FORCE_SNAP_CORRUPTED;
extern debugflag FORCE_CRT_UNKNOWN;
extern debugflag FORCE_CRT_UNSUPPORTED;
extern debugflag FORCE_RECORDING_ERROR;
extern debugflag FORCE_NO_FFMPEG;

#include <assert.h>

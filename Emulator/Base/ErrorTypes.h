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

/// Error condition
enum_long(TIARA_ERROR_CODE)
{
    TIARA_ERROR_OK,                   ///< No error
    TIARA_ERROR_UNKNOWN,              ///< Unclassified error condition

    // Execution state
    TIARA_ERROR_LAUNCH,               ///< Launch error
    TIARA_ERROR_POWERED_OFF,          ///< The emulator is powered off
    TIARA_ERROR_POWERED_ON,           ///< The emulator is powered on
    TIARA_ERROR_RUNNING,              ///< The emulator is running

    // Configuration
    TIARA_ERROR_OPT_UNSUPPORTED,      ///< Unsupported configuration option
    TIARA_ERROR_OPT_INV_ARG,          ///< Invalid argument
    TIARA_ERROR_OPT_INV_ID,           ///< Invalid component id
    TIARA_ERROR_OPT_LOCKED,           ///< The option is temporarily locked

    // Property storage
    TIARA_ERROR_INVALID_KEY,          ///< Invalid property key
    TIARA_ERROR_SYNTAX,               ///< Syntax error

    // CPU
    TIARA_ERROR_GUARD_NOT_FOUND,      ///< Guard is not set
    TIARA_ERROR_GUARD_ALREADY_SET,    ///< Guard is already set
    /*
    TIARA_ERROR_BP_NOT_FOUND,         ///< Breakpoint is not set (DEPRECATED)
    TIARA_ERROR_BP_ALREADY_SET,       ///< Breakpoint is already set (DEPRECATED)
    TIARA_ERROR_WP_NOT_FOUND,         ///< Watchpoint is not set (DEPRECATED)
    TIARA_ERROR_WP_ALREADY_SET,       ///< Watchpoint is already set (DEPRECATED)
     */
    
    // Memory
    TIARA_ERROR_OUT_OF_MEMORY,        ///< Out of memory

    // File IO
    TIARA_ERROR_DIR_NOT_FOUND,        ///< Directory does not exist
    TIARA_ERROR_DIR_ACCESS_DENIED,    ///< File access denied
    TIARA_ERROR_DIR_CANT_CREATE,      ///< Unable to create a directory
    TIARA_ERROR_DIR_NOT_EMPTY,        ///< Directory is not empty
    TIARA_ERROR_FILE_NOT_FOUND,       ///< File not found error
    TIARA_ERROR_FILE_EXISTS,          ///< File already exists
    TIARA_ERROR_FILE_IS_DIRECTORY,    ///< The file is a directory
    TIARA_ERROR_FILE_ACCESS_DENIED,   ///< File access denied
    TIARA_ERROR_FILE_TYPE_MISMATCH,   ///< File type mismatch
    TIARA_ERROR_FILE_TYPE_UNSUPPORTED,///< Unsupported file type
    TIARA_ERROR_FILE_CANT_READ,       ///< Can't read from file
    TIARA_ERROR_FILE_CANT_WRITE,      ///< Can't write to file
    TIARA_ERROR_FILE_CANT_CREATE,     ///< Can't create file

    // Roms
    TIARA_ERROR_CART_MISSING,         ///< No cartridge attached

    // Snapshots
    TIARA_ERROR_SNAP_TOO_OLD,         ///< Snapshot was created with an older version
    TIARA_ERROR_SNAP_TOO_NEW,         ///< Snapshot was created with a later version
    TIARA_ERROR_SNAP_IS_BETA,         ///< Snapshot was created with a beta release
    TIARA_ERROR_SNAP_CORRUPTED,       ///< Snapshot data is corrupted

    // Drives
    TIARA_ERROR_DRV_UNCONNECTED,      ///< Floppy drive is not connected
    TIARA_ERROR_DRV_NO_DISK,          ///< Floppy drive contains no disk

    // Cartridges
    TIARA_ERROR_CRT_UNKNOWN,          ///< Unknown cartridge type
    TIARA_ERROR_CRT_UNSUPPORTED,      ///< Unsupported cartridge type
    TIARA_ERROR_CRT_TOO_MANY_PACKETS, ///< CRT file contains too many Rom packets
    TIARA_ERROR_CRT_CORRUPTED_PACKET, ///< CRT file contains a corrupted Rom package

    // Remote servers
    TIARA_ERROR_SOCK_CANT_CREATE,
    TIARA_ERROR_SOCK_CANT_CONNECT,
    TIARA_ERROR_SOCK_CANT_BIND,
    TIARA_ERROR_SOCK_CANT_LISTEN,
    TIARA_ERROR_SOCK_CANT_ACCEPT,
    TIARA_ERROR_SOCK_CANT_RECEIVE,
    TIARA_ERROR_SOCK_CANT_SEND,
    TIARA_ERROR_SOCK_DISCONNECTED,
    TIARA_ERROR_SERVER_PORT_IN_USE,
    TIARA_ERROR_SERVER_ON,
    TIARA_ERROR_SERVER_OFF,
    TIARA_ERROR_SERVER_RUNNING,
    TIARA_ERROR_SERVER_NOT_RUNNING,
    TIARA_ERROR_SERVER_NO_CLIENT,

    // File systems
    TIARA_ERROR_FS_UNSUPPORTED,       ///< Unsupported file system
    TIARA_ERROR_FS_WRONG_CAPACITY,    ///< Wrong file system capacity
    TIARA_ERROR_FS_CORRUPTED,         ///< File system is corrupted
    TIARA_ERROR_FS_HAS_NO_FILES,      ///< File system is empty
    TIARA_ERROR_FS_HAS_CYCLES,        ///< File system has cyclic links
    TIARA_ERROR_FS_CANT_IMPORT,       ///< Failed to import a file system
    TIARA_ERROR_FS_EXPECTED_VAL,      ///< Unexpected value found
    TIARA_ERROR_FS_EXPECTED_MIN,      ///< Value is too small
    TIARA_ERROR_FS_EXPECTED_MAX,      ///< Value is too big

    TIARA_ERROR_COUNT
};
typedef TIARA_ERROR_CODE ErrorCode;

struct ErrorCodeEnum : util::Reflection<ErrorCodeEnum, ErrorCode> {

    static constexpr long minVal = 0;
    static constexpr long maxVal = TIARA_ERROR_FS_EXPECTED_MAX;

    static const char *prefix() { return "ERROR"; }
    static const char *_key(long value)
    {
        switch (value) {

            case TIARA_ERROR_OK:                      return "OK";
            case TIARA_ERROR_UNKNOWN:                 return "UNKNOWN";

            case TIARA_ERROR_LAUNCH:                  return "LAUNCH";
            case TIARA_ERROR_POWERED_OFF:             return "POWERED_OFF";
            case TIARA_ERROR_POWERED_ON:              return "POWERED_ON";
            case TIARA_ERROR_RUNNING:                 return "RUNNING";

            case TIARA_ERROR_OPT_UNSUPPORTED:         return "OPT_UNSUPPORTED";
            case TIARA_ERROR_OPT_INV_ARG:             return "OPT_INV_ARG";
            case TIARA_ERROR_OPT_INV_ID:              return "OPT_INV_ID";
            case TIARA_ERROR_OPT_LOCKED:              return "OPT_LOCKED";

            case TIARA_ERROR_INVALID_KEY:             return "INVALID_KEY";
            case TIARA_ERROR_SYNTAX:                  return "SYNTAX";

            case TIARA_ERROR_GUARD_NOT_FOUND:         return "GUARD_NOT_FOUND";
            case TIARA_ERROR_GUARD_ALREADY_SET:       return "GUARD_ALREADY_SET";
                /*
            case TIARA_ERROR_BP_NOT_FOUND:            return "BP_NOT_FOUND";
            case TIARA_ERROR_BP_ALREADY_SET:          return "BP_ALREADY_SET";
            case TIARA_ERROR_WP_NOT_FOUND:            return "WP_NOT_FOUND";
            case TIARA_ERROR_WP_ALREADY_SET:          return "WP_ALREADY_SET";
                 */
            case TIARA_ERROR_OUT_OF_MEMORY:           return "OUT_OF_MEMORY";

            case TIARA_ERROR_DIR_NOT_FOUND:           return "DIR_NOT_FOUND";
            case TIARA_ERROR_DIR_ACCESS_DENIED:       return "DIR_ACCESS_DENIED";
            case TIARA_ERROR_DIR_CANT_CREATE:         return "DIR_CANT_CREATE";
            case TIARA_ERROR_DIR_NOT_EMPTY:           return "DIR_NOT_EMPTY";
            case TIARA_ERROR_FILE_NOT_FOUND:          return "FILE_NOT_FOUND";
            case TIARA_ERROR_FILE_EXISTS:             return "FILE_EXISTS";
            case TIARA_ERROR_FILE_IS_DIRECTORY:       return "FILE_IS_DIRECtORY";
            case TIARA_ERROR_FILE_ACCESS_DENIED:      return "FILE_ACCESS_DENIED";
            case TIARA_ERROR_FILE_TYPE_MISMATCH:      return "FILE_TYPE_MISMATCH";
            case TIARA_ERROR_FILE_TYPE_UNSUPPORTED:   return "FILE_TYPE_UNSUPPORTED";
            case TIARA_ERROR_FILE_CANT_READ:          return "FILE_CANT_READ";
            case TIARA_ERROR_FILE_CANT_WRITE:         return "FILE_CANT_WRITE";
            case TIARA_ERROR_FILE_CANT_CREATE:        return "FILE_CANT_CREATE";

            case TIARA_ERROR_CART_MISSING:            return "CART_MISSING";

            case TIARA_ERROR_SNAP_TOO_OLD:            return "SNAP_TOO_OLD";
            case TIARA_ERROR_SNAP_TOO_NEW:            return "SNAP_TOO_NEW";
            case TIARA_ERROR_SNAP_IS_BETA:		    return "SNAP_IS_BETA";
            case TIARA_ERROR_SNAP_CORRUPTED:		    return "SNAP_CORRUPTED";

            case TIARA_ERROR_DRV_UNCONNECTED:         return "DRV_UNCONNECTED";
            case TIARA_ERROR_DRV_NO_DISK:             return "DRV_NO_DISK";

            case TIARA_ERROR_CRT_UNKNOWN:             return "TIARA_ERROR_CRT_UNKNOWN";
            case TIARA_ERROR_CRT_UNSUPPORTED:         return "CRT_UNSUPPORTED";
            case TIARA_ERROR_CRT_TOO_MANY_PACKETS:    return "CRT_TOO_MANY_PACKETS";
            case TIARA_ERROR_CRT_CORRUPTED_PACKET:    return "CRT_CORRUPTED_PACKET";

            case TIARA_ERROR_SOCK_CANT_CREATE:        return "SOCK_CANT_CREATE";
            case TIARA_ERROR_SOCK_CANT_CONNECT:       return "SOCK_CANT_CONNECT";
            case TIARA_ERROR_SOCK_CANT_BIND:          return "SOCK_CANT_BIND";
            case TIARA_ERROR_SOCK_CANT_LISTEN:        return "SOCK_CANT_LISTEN";
            case TIARA_ERROR_SOCK_CANT_ACCEPT:        return "SOCK_CANT_ACCEPT";
            case TIARA_ERROR_SOCK_CANT_RECEIVE:       return "SOCK_CANT_RECEIVE";
            case TIARA_ERROR_SOCK_CANT_SEND:          return "SOCK_CANT_SEND";
            case TIARA_ERROR_SOCK_DISCONNECTED:       return "SOCK_DISCONNECTED";
            case TIARA_ERROR_SERVER_PORT_IN_USE:      return "SERVER_PORT_IN_USE";
            case TIARA_ERROR_SERVER_ON:               return "SERVER_ON";
            case TIARA_ERROR_SERVER_OFF:              return "SERVER_OFF";
            case TIARA_ERROR_SERVER_RUNNING:          return "SERVER_RUNNING";
            case TIARA_ERROR_SERVER_NOT_RUNNING:      return "SERVER_NOT_RUNNING";
            case TIARA_ERROR_SERVER_NO_CLIENT:        return "SERVER_NO_CLIENT";

            case TIARA_ERROR_FS_UNSUPPORTED:          return "FS_UNSUPPORTED";
            case TIARA_ERROR_FS_WRONG_CAPACITY:       return "FS_WRONG_CAPACITY";
            case TIARA_ERROR_FS_CORRUPTED:            return "FS_CORRUPTED";
            case TIARA_ERROR_FS_HAS_NO_FILES:         return "TIARA_ERROR_FS_HAS_NO_FILES";
            case TIARA_ERROR_FS_HAS_CYCLES:           return "FS_HAS_CYCLES";
            case TIARA_ERROR_FS_CANT_IMPORT:          return "FS_CANT_IMPORT";
            case TIARA_ERROR_FS_EXPECTED_VAL:         return "FS_EXPECTED_VAL";
            case TIARA_ERROR_FS_EXPECTED_MIN:         return "FS_EXPECTED_MIN";
            case TIARA_ERROR_FS_EXPECTED_MAX:         return "FS_EXPECTED_MAX";

            case TIARA_ERROR_COUNT:                   return "???";
        }
        return "???";
    }
};

}

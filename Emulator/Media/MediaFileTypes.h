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

enum_long(FILETYPE)
{
    FILETYPE_UNKNOWN,
    FILETYPE_CART,
    FILETYPE_SNAPSHOT,
    FILETYPE_SCRIPT
};
typedef FILETYPE FileType;

struct FileTypeEnum : util::Reflection<FileTypeEnum, FileType> {

    static constexpr long minVal = 0;
    static constexpr long maxVal = FILETYPE_SCRIPT;

    static const char *prefix() { return "FILETYPE"; }
    static const char *_key(long value)
    {
        switch (value) {

            case FILETYPE_UNKNOWN:    return "UNKNOWN";
            case FILETYPE_CART:       return "CART";
            case FILETYPE_SNAPSHOT:   return "SNAPSHOT";
            case FILETYPE_SCRIPT:     return "SCRIPT";
        }
        return "???";
    }
};

enum_long(FILE_ERROR)
{
    ERR_FILE_OK,

    // General
    ERR_FILE_NOT_FOUND,
    ERR_INVALID_TYPE,
    ERR_CANT_READ,
    ERR_CANT_WRITE,
    ERR_OUT_OF_MEMORY,
    ERR_UNKNOWN,

    // Snapshots
    ERR_UNSUPPORTED_SNAPSHOT
};
typedef FILE_ERROR FileError;

}

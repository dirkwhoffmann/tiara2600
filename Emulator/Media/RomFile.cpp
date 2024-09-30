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
#include "RomFile.h"
#include "Atari.h"
#include "IOUtils.h"
#include "RomDatabase.h"

namespace tiara {


bool
RomFile::isCompatible(const fs::path &path)
{
    auto s = util::uppercased(path.extension().string());
    return s == ".BIN" || s == ".A26";
}

bool
RomFile::isCompatible(const u8 *buf, isize len)
{
    return true;
}

bool
RomFile::isCompatible(const Buffer<u8> &buf)
{
    return isCompatible(buf.ptr, buf.size);
}

void
RomFile::finalizeRead()
{

}

RomTraits
RomFile::traits() const
{
    auto md5 = data.md5();

    RomTraits result {

        .md5            = md5,
        .name           = "Unknown Cartridge",
        /*
        .manufacturer   = "",
        .type           = "",
        .model          = "",
        .format         = "",
        .note           = "",
        .left           = "",
        .right          = ""
        */
    };

    // Crawl through the database
    for (auto &traits : roms) if (traits.md5 == md5) { result = traits; break; }

    // Replace null pointers by empty strings
    /*
    if (!result.name) result.name = "";
    if (!result.manufacturer) result.manufacturer = "";
    if (!result.type) result.type = "";
    if (!result.model) result.model = "";
    if (!result.format) result.format = "";
    if (!result.note) result.note = "";
    if (!result.left) result.left = "";
    if (!result.right) result.right = "";
    */

    return result;
}

CartridgeType
RomFile::cartridgeType() const
{
    auto type = traits().type;

    if (!type) return CRT_NORMAL;

    return CRT_NONE;
}

}

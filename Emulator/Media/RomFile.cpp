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
#include "C64.h"
#include "IOUtils.h"

namespace tiara {


bool
RomFile::isCompatible(const fs::path &path)
{
    auto s = util::uppercased(path.extension().string());
    return s == ".BIN";
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

bool
RomFile::isRomBuffer(RomType type, const u8 *buf, isize len)
{
    return true;
}

void
RomFile::finalizeRead()
{

}

}

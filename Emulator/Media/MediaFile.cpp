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
#include "MediaFile.h"
#include "Tiara.h"
#include "StringUtils.h"
#include "Checksum.h"
#include "RomFile.h"
#include "Script.h"
#include "Snapshot.h"

namespace tiara {

FileType
MediaFile::type(const fs::path &path)
{
    Buffer<u8> buffer(path);
    if (buffer.empty()) return FILETYPE_UNKNOWN;

    if (Snapshot::isCompatible(path) &&
        Snapshot::isCompatible(buffer)) return FILETYPE_SNAPSHOT;

    if (Script::isCompatible(path) &&
        Script::isCompatible(buffer)) return FILETYPE_SCRIPT;

    if (RomFile::isCompatible(path)) {
        if (RomFile::isRomBuffer(ROM_TYPE_BASIC, buffer)) return FILETYPE_BASIC_ROM;
        if (RomFile::isRomBuffer(ROM_TYPE_CHAR, buffer)) return FILETYPE_CHAR_ROM;
        if (RomFile::isRomBuffer(ROM_TYPE_KERNAL, buffer)) return FILETYPE_KERNAL_ROM;
        if (RomFile::isRomBuffer(ROM_TYPE_VC1541, buffer)) return FILETYPE_VC1541_ROM;
    }

    return FILETYPE_UNKNOWN;
}

MediaFile *
MediaFile::make(const fs::path &path)
{
    return make(path, type(path));
}

MediaFile *
MediaFile::make(const fs::path &path, FileType type)
{
    switch (type) {

        case FILETYPE_SNAPSHOT:   return new Snapshot(path);
        case FILETYPE_SCRIPT:     return new Script(path);
        case FILETYPE_BASIC_ROM:  return new RomFile(path);
        case FILETYPE_CHAR_ROM:   return new RomFile(path);
        case FILETYPE_KERNAL_ROM: return new RomFile(path);
        case FILETYPE_VC1541_ROM: return new RomFile(path);

        default:
            return nullptr;
    }
}

MediaFile *
MediaFile::make(const u8 *buf, isize len, FileType type)
{
    switch (type) {
            
        case FILETYPE_SNAPSHOT:   return new Snapshot(buf, len);
        case FILETYPE_SCRIPT:     return new Script(buf, len);
        case FILETYPE_BASIC_ROM:  return new RomFile(buf, len);
        case FILETYPE_CHAR_ROM:   return new RomFile(buf, len);
        case FILETYPE_KERNAL_ROM: return new RomFile(buf, len);
        case FILETYPE_VC1541_ROM: return new RomFile(buf, len);
            
        default:
            return nullptr;
    }
}

string
MediaFile::getSizeAsString() const
{
    return util::byteCountAsString(getSize());
}

}

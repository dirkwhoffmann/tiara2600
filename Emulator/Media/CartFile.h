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

#include "AnyFile.h"
#include "AtariTypes.h"
#include "MemoryTypes.h"
#include "CartridgeTypes.h"
#include <map>

namespace tiara {

class CartFile : public AnyFile {

    static std::map<string, CartridgeType> ext2type;

public:

    char md5[129];

    RomTraits traits = {

        .md5            = md5,
        .name           = "",
        .manufacturer   = "",
        .type           = "",
        .model          = "",
        .format         = "",
        .note           = "",
        .left           = "",
        .right          = ""
    };


    //
    // Class methods
    //

    static bool isCompatible(const fs::path &name);
    static bool isCompatible(const u8 *buf, isize len);
    static bool isCompatible(const Buffer<u8> &buffer);


    //
    // Initializing
    //
    
    CartFile(const fs::path &path) throws { init(path); predictTraits(); }
    // CartFile(const u8 *buf, isize len) throws { init(buf, len); predictTraits(); }
    // CartFile(const Buffer<u8> &buf) throws { init(buf.ptr, buf.size); }

    
    //
    // Methods from CoreObject
    //
    
    const char *objectName() const override { return "BinFile"; }

    
    //
    // Methods from AnyFile
    //
    
    bool isCompatiblePath(const fs::path &path) override { return isCompatible(path); }
    bool isCompatibleBuffer(const u8 *buf, isize len) override { return isCompatible(buf, len); }
    FileType type() const override { return FILETYPE_CART; }
    void finalizeRead() override;


    //
    // Analyzing
    //

    void predictTraits();
    CartridgeType predictType() const;

};

}

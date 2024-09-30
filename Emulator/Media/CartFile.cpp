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
#include "CartFile.h"
#include "Atari.h"
#include "IOUtils.h"
#include "RomDatabase.h"

namespace tiara {

std::map<string, CartridgeType>
CartFile::ext2type = {

    { ".BIN"   , CART_UNKNOWN },
    { ".A26"   , CART_UNKNOWN },

    { ".084"   , CART_0840   },
    { ".0840"  , CART_0840   },
    { ".0FA"   , CART_0FA0   },
    { ".0FA0"  , CART_0FA0   },
    { ".2N1"   , CART_2IN1   },
    { ".4N1"   , CART_4IN1   },
    { ".8N1"   , CART_8IN1   },
    { ".16N"   , CART_16IN1  },
    { ".16N1"  , CART_16IN1  },
    { ".32N"   , CART_32IN1  },
    { ".32N1"  , CART_32IN1  },
    { ".64N"   , CART_64IN1  },
    { ".64N1"  , CART_64IN1  },
    { ".128"   , CART_128IN1 },
    { ".128N1" , CART_128IN1 },
    { ".2K"    , CART_2K     },
    { ".3E"    , CART_3E     },
    { ".3EX"   , CART_3EX    },
    { ".3EP"   , CART_3EP    },
    { ".3E+"   , CART_3EP    },
    { ".3F"    , CART_3F     },
    { ".4A5"   , CART_4A50   },
    { ".4A50"  , CART_4A50   },
    { ".4K"    , CART_4K     },
    { ".4KS"   , CART_4KSC   },
    { ".4KSC"  , CART_4KSC   },
    { ".AR"    , CART_AR     },
    { ".BF"    , CART_BF     },
    { ".BFS"   , CART_BFSC   },
    { ".BFSC"  , CART_BFSC   },
    { ".BUS"   , CART_BUS    },
    { ".CDF"   , CART_CDF    },
    { ".CM"    , CART_CM     },
    { ".CTY"   , CART_CTY    },
    { ".CV"    , CART_CV     },
    { ".DF"    , CART_DF     },
    { ".DFS"   , CART_DFSC   },
    { ".DFSC"  , CART_DFSC   },
    { ".DPC"   , CART_DPC    },
    { ".DPP"   , CART_DPCP   },
    { ".DPCP"  , CART_DPCP   },
    { ".E0"    , CART_E0     },
    { ".E7"    , CART_E7     },
    { ".E78"   , CART_E7     },
    { ".E78K"  , CART_E7     },
    { ".EF"    , CART_EF     },
    { ".EFS"   , CART_EFSC   },
    { ".EFSC"  , CART_EFSC   },
    { ".F0"    , CART_F0     },
    { ".F4"    , CART_F4     },
    { ".F4S"   , CART_F4SC   },
    { ".F4SC"  , CART_F4SC   },
    { ".F6"    , CART_F6     },
    { ".F6S"   , CART_F6SC   },
    { ".F6SC"  , CART_F6SC   },
    { ".F8"    , CART_F8     },
    { ".F8S"   , CART_F8SC   },
    { ".F8SC"  , CART_F8SC   },
    { ".FA"    , CART_FA     },
    { ".FA2"   , CART_FA2    },
    { ".FC"    , CART_FC     },
    { ".FE"    , CART_FE     },
    { ".MDM"   , CART_MDM    },
    { ".MVC"   , CART_MVC    },
    { ".SB"    , CART_SB     },
    { ".TVB"   , CART_TVBOY  },
    { ".TVBOY" , CART_TVBOY  },
    { ".UA"    , CART_UA     },
    { ".UASW"  , CART_UASW   },
    { ".WD"    , CART_WD     },
    { ".WDSW"  , CART_WDSW   },
    { ".X07"   , CART_X07    }
};

bool
CartFile::isCompatible(const fs::path &path)
{
    return ext2type.contains(util::uppercased(path.extension().string()));
}

bool
CartFile::isCompatible(const u8 *buf, isize len)
{
    return true;
}

bool
CartFile::isCompatible(const Buffer<u8> &buf)
{
    return isCompatible(buf.ptr, buf.size);
}

void
CartFile::finalizeRead()
{

}

void
CartFile::predictTraits()
{
    auto hash = data.md5();

    // Start from scratch
    traits = { };

    // Crawl through the database
    for (auto &item : roms) if (item.md5 == hash) { traits = item; break; }

    // Copy the hash
    hash.copy(md5, 128); md5[128] = 0;

    // Replace null pointers by empty strings
    if (!traits.name) traits.name = "";
    if (!traits.manufacturer) traits.manufacturer = "";
    if (!traits.type) traits.type = "";
    if (!traits.model) traits.model = "";
    if (!traits.format) traits.format = "";
    if (!traits.note) traits.note = "";
    if (!traits.left) traits.left = "";
    if (!traits.right) traits.right = "";

    // Predict the cartridge type if not known yet
    if (!traits.cartType) traits.cartType = predictType();
}

CartridgeType
CartFile::predictType() const
{
    CartridgeType result = CART_UNKNOWN;

    // Get the type from the file extension if possible
    auto extension = util::uppercased(path.extension().string());
    if (ext2type.contains(extension)) result = ext2type[extension];

    if (result == CART_UNKNOWN) {

        // Predict the type based on the cartridge size
        if (data.size == KB(4)) result = CART_4K;
    }

    return result;
}

}

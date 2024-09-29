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

#include "CartridgeTypes.h"
#include "SubComponent.h"
#include "RomFile.h"

namespace tiara {

class Cartridge : public SubComponent, public Inspectable<CartridgeInfo> {

    Descriptions descriptions = {{

        .type           = CartridgeClass,
        .name           = "Cartridge",
        .description    = "Cartridge",
        .shell          = "cartridge"
    }};

    Options options = {

    };

public:

    virtual const CartridgeTraits &getCartridgeTraits() const {

        static CartridgeTraits traits = {

            .type       = CRT_NORMAL,
        };

        return traits;
    }


    //
    // ROM
    //

public:

    Buffer<u8> rom;


    //
    // Class methods
    //

public:

    // Checks whether this cartridge is a supported by the emulator
    static bool isSupportedType(CartridgeType type);

    // Factory methods
    static Cartridge *makeWithType(C64 &c64, CartridgeType type) throws;
    static Cartridge *makeWithFile(C64 &c64, const RomFile &file) throws;


    //
    // Methods
    //

public:

    Cartridge(C64 &ref);
    ~Cartridge();

    virtual void init();
    void dealloc();

public:

    Cartridge& operator= (const Cartridge& other) {

        return *this;
    }


    //
    // Methods from Serializable
    //

public:

    template <class T>
    void serialize(T& worker)
    {
        /*
        worker

        << chipL
        << chipH
        << mappedBytesL
        << mappedBytesH
        << offsetL
        << offsetH
        << led;
        */

        if (isResetter(worker)) return;

        /*
        worker

        << gameLineInCrtFile
        << exromLineInCrtFile
        << numPackets
        << ramCapacity
        << writes
        << control
        << switchPos;
        */
    } SERIALIZERS(serialize);


    //
    // Methods from CoreComponent
    //

public:

    const Descriptions &getDescriptions() const override { return descriptions; }

protected:

    // const char *objectName() const override { return getCartridgeTraits().title; }
    void _dump(Category category, std::ostream& os) const override;


    //
    // Methods from Inspectable
    //

public:

    void cacheInfo(CartridgeInfo &result) const override;


    //
    // Methods from Configurable
    //

public:

    const Options &getOptions() const override { return options; }


    //
    // Analyzing
    //

public:

    // Returns the cartridge type
    virtual CartridgeType getCartridgeType() const { return getCartridgeTraits().type; }

    // Checks whether this cartridge is supported by the emulator yet
    bool isSupported() const { return isSupportedType(getCartridgeType()); }


    //
    // Execution
    //

    //
    virtual void execute() { };

    //
    virtual void endOfFrame() { };
};

}

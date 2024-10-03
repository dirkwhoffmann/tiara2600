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
#include "CartFile.h"

namespace tiara {

class Cartridge : public SubComponent, public Inspectable<CartridgeInfo> {

    friend class CartPort;

    Descriptions descriptions = {{

        .type           = CartridgeClass,
        .name           = "Cartridge",
        .description    = "Cartridge",
        .shell          = "cartridge"
    }};

    Options options{};

public:

    CartTraits traits {

        .cartType       = CART_NONE,
        .md5            = "",
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
    // ROM
    //

public:

    Buffer<u8> rom;

    // The predicted type (as provided by the CartFile)
    CartType predictedCartType{};


    //
    // Class methods
    //

public:

    // Checks whether this cartridge is a supported by the emulator
    static bool isSupportedType(CartType type);

    // Factory methods
    static std::unique_ptr<Cartridge> makeWithType(Atari &c64, CartType type) throws;
    static std::unique_ptr<Cartridge> makeWithFile(Atari &c64, const CartFile &file) throws;


    //
    // Methods
    //

public:

    Cartridge(Atari &ref);
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

    // Checks whether this cartridge is supported by the emulator yet
    virtual bool isSupported() const { return traits.cartType == CART_NONE; }

    //
    // Accessing memory
    //

public:

    virtual u8 spypeek(u16 addr) { return 0; }


    //
    // Execution
    //

    //
    virtual void execute() { };

    //
    virtual void endOfFrame() { };
};

}

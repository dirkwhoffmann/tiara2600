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

#include "CartPortTypes.h"
#include "SubComponent.h"
#include "Cartridge.h"

namespace tiara {

class CartPort final : public SubComponent {

    Descriptions descriptions = {{

        .type           = CartPortClass,
        .name           = "CartPort",
        .description    = "Cartridge Port",
        .shell          = "cart"
    }};

    Options options = {

        OPT_CART_TYPE
    };

    // Current configuration
    CartPortConfig config = { };

public:

    // The plugged-in cartridge
    std::unique_ptr<Cartridge> cart = std::make_unique<Cartridge>(atari);


    //
    // Methods
    //

public:

    CartPort(Atari &ref);
    const Descriptions &getDescriptions() const override { return descriptions; }

    CartPort& operator= (const CartPort& other) {

        CLONE(config)

        return *this;
    }


    //
    // Methods from Serializable
    //

public:

    template <class T>
    void serialize(T& worker)
    {
        if (isResetter(worker)) return;

        // worker

        // << config.type;

    } SERIALIZERS(serialize);


    //
    // Methods from CoreComponent
    //

private:

    void _dump(Category category, std::ostream& os) const override;
    void _isReady() const override;
    

    //
    // Methods from Configurable
    //

public:

    const CartPortConfig &getConfig() const { return config; }
    const Options &getOptions() const override { return options; }
    i64 getOption(Option opt) const override;
    void checkOption(Option opt, i64 value) override;
    void setOption(Option opt, i64 value) override;


    //
    // Attaching and detaching cartridges
    //

public:

    // Attaches a cartrige
    void attachCartridge(const fs::path &path, bool reset = true) throws;
    void attachCartridge(const MediaFile &file, bool reset = true);

    // Detaches the current cartridge
    void detachCartridge();

    // Reverts to the predicted cartridge type
    void revertCartType();

private:

    // Changed the current cartridge type
    void setCartType(CartType newType);


    //
    // Querying cartridge information
    //

public:
    
    // Reads the reset vector from the plugged-in cartridge
    u16 resetVector() const;

};

}

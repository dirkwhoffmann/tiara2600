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

#include "TIATypes.h"
#include "AtariTypes.h"
#include "SubComponent.h"

namespace tiara {

class Detector final : public SubComponent {

    Descriptions descriptions = {
        {
            .type           = DetectorClass,
            .name           = "Detector",
            .description    = "Video standard detector",
            .shell          = ""
        }
    };

    Options options = {

    };

    // Frame type counters
    isize pal;
    isize ntsc;


    //
    // Methods
    //

public:

    using SubComponent::SubComponent;

    Detector& operator= (const Detector& other) {

        return *this;
    }


    //
    // Methods from Serializable
    //

public:

    template <class T> void serialize(T& worker) {

    } SERIALIZERS(serialize);


    //
    // Methods from CoreComponent
    //

public:

    const Descriptions &getDescriptions() const override { return descriptions; }

private:

    void _dump(Category category, std::ostream& os) const override;


    //
    // Methods from Inspectable
    //

private:

    // void cacheInfo(DetectorInfo &result) const override;


    //
    // Methods from Configurable
    //

public:

    const Options &getOptions() const override { return options; }


    //
    // Using the device
    //

public:

    // End-of-frame handler
    void eofHandler();

    // Predicts the video standard
    TIARevision predict() const;
};

}

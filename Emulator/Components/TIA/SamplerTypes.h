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

#include "BasicTypes.h"
#include "Reflection.h"

namespace tiara {

//
// Enumerations
//

enum_long(SMP_METHOD)
{
    SMP_NONE,
    SMP_NEAREST,
    SMP_LINEAR
};
typedef SMP_METHOD SamplingMethod;

#ifdef __cplusplus
struct SamplingMethodEnum : util::Reflection<SamplingMethodEnum, SamplingMethod>
{
    static constexpr long minVal = 0;
    static constexpr long maxVal = SMP_LINEAR;

    static const char *prefix() { return "SMP"; }
    static const char *_key(long value)
    {
        switch (value) {

            case SMP_NONE:     return "NONE";
            case SMP_NEAREST:  return "NEAREST";
            case SMP_LINEAR:   return "LINEAR";
        }
        return "???";
    }
};
#endif

}

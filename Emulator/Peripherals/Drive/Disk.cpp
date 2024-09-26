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
#include "C64.h"
#include "IOUtils.h"
#include "Checksum.h"

#include <stdarg.h>

namespace tiara {

const TrackDefaults Disk::trackDefaults[43] = {
    
    { 0, 0, 0, 0, 0, 0 }, // Padding
    
    // Speedzone 3 (outer tracks)
    { 21, 3, 7693, 7693 * 8,   0, 0.268956 }, // Track 1
    { 21, 3, 7693, 7693 * 8,  21, 0.724382 }, // Track 2
    { 21, 3, 7693, 7693 * 8,  42, 0.177191 }, // Track 3
    { 21, 3, 7693, 7693 * 8,  63, 0.632698 }, // Track 4
    { 21, 3, 7693, 7693 * 8,  84, 0.088173 }, // Track 5
    { 21, 3, 7693, 7693 * 8, 105, 0.543583 }, // Track 6
    { 21, 3, 7693, 7693 * 8, 126, 0.996409 }, // Track 7
    { 21, 3, 7693, 7693 * 8, 147, 0.451883 }, // Track 8
    { 21, 3, 7693, 7693 * 8, 168, 0.907342 }, // Track 9
    { 21, 3, 7693, 7693 * 8, 289, 0.362768 }, // Track 10
    { 21, 3, 7693, 7693 * 8, 210, 0.815512 }, // Track 11
    { 21, 3, 7693, 7693 * 8, 231, 0.268338 }, // Track 12
    { 21, 3, 7693, 7693 * 8, 252, 0.723813 }, // Track 13
    { 21, 3, 7693, 7693 * 8, 273, 0.179288 }, // Track 14
    { 21, 3, 7693, 7693 * 8, 294, 0.634779 }, // Track 15
    { 21, 3, 7693, 7693 * 8, 315, 0.090253 }, // Track 16
    { 21, 3, 7693, 7693 * 8, 336, 0.545712 }, // Track 17
    
    // Speedzone 2
    { 19, 2, 7143, 7143 * 8, 357, 0.945418 }, // Track 18
    { 19, 2, 7143, 7143 * 8, 376, 0.506081 }, // Track 19
    { 19, 2, 7143, 7143 * 8, 395, 0.066622 }, // Track 20
    { 19, 2, 7143, 7143 * 8, 414, 0.627303 }, // Track 21
    { 19, 2, 7143, 7143 * 8, 433, 0.187862 }, // Track 22
    { 19, 2, 7143, 7143 * 8, 452, 0.748403 }, // Track 23
    { 19, 2, 7143, 7143 * 8, 471, 0.308962 }, // Track 24
    
    // Speedzone 1
    { 18, 1, 6667, 6667 * 8, 490, 0.116926 }, // Track 25
    { 18, 1, 6667, 6667 * 8, 508, 0.788086 }, // Track 26
    { 18, 1, 6667, 6667 * 8, 526, 0.459190 }, // Track 27
    { 18, 1, 6667, 6667 * 8, 544, 0.130238 }, // Track 28
    { 18, 1, 6667, 6667 * 8, 562, 0.801286 }, // Track 29
    { 18, 1, 6667, 6667 * 8, 580, 0.472353 }, // Track 30
    
    // Speedzone 0 (inner tracks)
    { 17, 0, 6250, 6250 * 8, 598, 0.834120 }, // Track 31
    { 17, 0, 6250, 6250 * 8, 615, 0.614880 }, // Track 32
    { 17, 0, 6250, 6250 * 8, 632, 0.395480 }, // Track 33
    { 17, 0, 6250, 6250 * 8, 649, 0.176140 }, // Track 34
    { 17, 0, 6250, 6250 * 8, 666, 0.956800 }, // Track 35
    
    // Speedzone 0 (usually unused tracks)
    { 17, 0, 6250, 6250 * 8, 683, 0.300 }, // Track 36
    { 17, 0, 6250, 6250 * 8, 700, 0.820 }, // Track 37
    { 17, 0, 6250, 6250 * 8, 717, 0.420 }, // Track 38
    { 17, 0, 6250, 6250 * 8, 734, 0.940 }, // Track 39
    { 17, 0, 6250, 6250 * 8, 751, 0.540 }, // Track 40
    { 17, 0, 6250, 6250 * 8, 768, 0.130 }, // Track 41
    { 17, 0, 6250, 6250 * 8, 785, 0.830 }  // Track 42
};

isize
Disk::numberOfSectorsInTrack(Track t)
{
    return (t < 1) ? 0 : (t < 18) ? 21 : (t < 25) ? 19 : (t < 31) ? 18 : (t < 43) ? 17 : 0;
}
isize
Disk::numberOfSectorsInHalftrack(Halftrack ht)
{
    return numberOfSectorsInTrack((ht + 1) / 2);
}

isize
Disk::speedZoneOfTrack(Track t)
{
    return (t < 18) ? 3 : (t < 25) ? 2 : (t < 31) ? 1 : 0;
}

isize
Disk::speedZoneOfHalftrack(Halftrack ht)
{
    return (ht < 35) ? 3 : (ht < 49) ? 2 : (ht < 61) ? 1 : 0;
}

bool
Disk::isValidTrackSectorPair(Track t, Sector s)
{
    return s < numberOfSectorsInTrack(t);
}

bool
Disk::isValidHalftrackSectorPair(Halftrack ht, Sector s)
{
    return s < numberOfSectorsInHalftrack(ht);
}

Disk::Disk()
{    
    clearDisk();
}

void
Disk::init(const fs::path &path, bool wp)
{

}

void
Disk::init(SerReader &reader)
{
    serialize(reader);
}

void
Disk::_dump(Category category, std::ostream& os) const
{
    using namespace util;
    
    if (category == Category::Disk) {

        auto checksum = util::fnv32((const u8 *)data.track, sizeof(data.track));

        os << tab("Write protected") << bol(writeProtected) << std::endl;
        os << tab("Modified") << bol(modified) << std::endl;
        os << tab("Checksum") << hex(checksum) << std::endl;
    }

    if (category == Category::Layout) {

        for (Halftrack ht = 1; ht <= highestHalftrack; ht++) {
            
            auto length = lengthOfHalftrack(ht);
            
            os << tab("Halftrack " + std::to_string(ht));
            os << dec(length) << " Bits (" << dec(length / 8) << " Bytes)";
            os << std::endl;
        }
    }
}

void
Disk::setModified(bool b)
{
    if (b != modified) {
        modified = b;
    }
}

void
Disk::encodeGcr(u8 value, Track t, HeadPos offset)
{
    assert(isTrackNumber(t));
    
    u8 nibble1 = bin2gcr(value >> 4);
    u8 nibble2 = bin2gcr(value & 0xF);
    
    writeBitToTrack(t, offset++, nibble1 & 0x10);
    writeBitToTrack(t, offset++, nibble1 & 0x08);
    writeBitToTrack(t, offset++, nibble1 & 0x04);
    writeBitToTrack(t, offset++, nibble1 & 0x02);
    writeBitToTrack(t, offset++, nibble1 & 0x01);

    writeBitToTrack(t, offset++, nibble2 & 0x10);
    writeBitToTrack(t, offset++, nibble2 & 0x08);
    writeBitToTrack(t, offset++, nibble2 & 0x04);
    writeBitToTrack(t, offset++, nibble2 & 0x02);
    writeBitToTrack(t, offset++, nibble2 & 0x01);
}

void
Disk::encodeGcr(u8 *values, isize length, Track t, HeadPos offset)
{
    for (isize i = 0; i < length; i++, values++, offset += 10) {
        encodeGcr(*values, t, offset);
    }
}

bool
Disk::isValidHeadPos(Halftrack ht, HeadPos pos) const
{
    return isHalftrackNumber(ht) && pos >= 0 && pos < length.halftrack[ht];
}

HeadPos
Disk::wrap(Halftrack ht, HeadPos pos) const
{
    auto len = length.halftrack[ht];
    return pos < 0 ? pos + len : pos >= len ? pos - len : pos;
}

u64
Disk::_bitDelay(Halftrack ht, HeadPos pos) const {
    
    assert(isValidHeadPos(ht, pos));

    // In the current implementation, we assume that the density bits were
    // set to their correct values when a bit was written to disk. According
    // to this assumption, the returned value is determined solely by the
    // track position of the drive head.
    
    if (ht <= 33)
        return 4 * 10000; // Density bits = 00: 4 * 16/16 * 10^4 1/10 nsec
    if (ht <= 47)
        return 4 * 9375;  // Density bits = 01: 4 * 15/16 * 10^4 1/10 nsec
    if (ht <= 59)
        return 4 * 8750;  // Density bits = 10: 4 * 14/16 * 10^4 1/10 nsec
    
    return 4 * 8125;     // Density bits = 11: 4 * 13/16 * 10^4 1/10 nsec
}

void
Disk::clearHalftrack(Halftrack ht)
{
    memset(&data.halftrack[ht], 0x55, sizeof(data.halftrack[ht]));
    length.halftrack[ht] = sizeof(data.halftrack[ht]) * 8;
}

void
Disk::clearDisk()
{
    // memset(&data, 0x55, sizeof(data));
    for (Halftrack ht = 1; ht <= highestHalftrack; ht++) {
        clearHalftrack(ht);
    }
    writeProtected = false;
    modified = false;
}

bool
Disk::halftrackIsEmpty(Halftrack ht) const
{
    assert(isHalftrackNumber(ht));
    for (isize i = 0; i < isizeof(data.halftrack[ht]); i++)
        if (data.halftrack[ht][i] != 0x55) return false;
    return true;
}

bool
Disk::trackIsEmpty(Track t) const
{
    assert(isTrackNumber(t));
    return halftrackIsEmpty(2 * t - 1);
}

isize
Disk::nonemptyHalftracks() const
{
    isize result = 0;
    
    for (Halftrack ht = 1; ht < 85; ht++) {
        if (!halftrackIsEmpty(ht))
            result++;
    }
    
    return result;
}

isize
Disk::lengthOfTrack(Track t) const
{
    assert(isTrackNumber(t));
    return length.track[t][0];
}

isize
Disk::lengthOfHalftrack(Halftrack ht) const
{
    assert(isHalftrackNumber(ht));
    return length.halftrack[ht];
}

}

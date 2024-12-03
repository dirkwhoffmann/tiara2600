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
#include "Defaults.h"
#include "Atari.h"
#include "StringUtils.h"
#include "IOUtils.h"

namespace tiara {

Defaults::Defaults()
{
    setFallback(OPT_HOST_REFRESH_RATE,          60);
    setFallback(OPT_HOST_SAMPLE_RATE,           44100);
    setFallback(OPT_HOST_FRAMEBUF_WIDTH,        0);
    setFallback(OPT_HOST_FRAMEBUF_HEIGHT,       0);

    setFallback(OPT_ATARI_WARP_BOOT,            0);
    setFallback(OPT_ATARI_WARP_MODE,            WARP_NEVER);
    setFallback(OPT_ATARI_VSYNC,                false);
    setFallback(OPT_ATARI_SPEED_BOOST,          100);
    setFallback(OPT_ATARI_RUN_AHEAD,            0);
    setFallback(OPT_ATARI_FAST_PATHS,           1);

    setFallback(OPT_ATARI_SNAP_AUTO,            false);
    setFallback(OPT_ATARI_SNAP_DELAY,           10);
    setFallback(OPT_ATARI_SNAP_COMPRESS,        true);

    setFallback(OPT_TIA_REVISION,               TIA_NTSC);
    setFallback(OPT_TIA_COLLISIONS,             0xFFFF);
    setFallback(OPT_TIA_REGLOCK,                0);
    setFallback(OPT_TIA_POWER_SAVE,             true);

    setFallback(OPT_RAM_INIT_PATTERN,           RAM_PATTERN_ZEROES);

    setFallback(OPT_LA_ENABLE,                  false);
    setFallback(OPT_LA_CHANNEL0,                false);
    setFallback(OPT_LA_CHANNEL1,                false);
    setFallback(OPT_LA_CHANNEL2,                false);
    setFallback(OPT_LA_CHANNEL3,                false);
    setFallback(OPT_LA_PROBE0,                  PROBE_ADDR_BUS);
    setFallback(OPT_LA_PROBE1,                  PROBE_DATA_BUS);
    setFallback(OPT_LA_PROBE2,                  PROBE_NONE);
    setFallback(OPT_LA_PROBE3,                  PROBE_NONE);
    setFallback(OPT_LA_MODE,                    LA_DISPLAY_MODE_FG_LAYER);
    setFallback(OPT_LA_OPACITY,                 0x80);

    setFallback(OPT_CART_TYPE,                  CART_NONE);

    setFallback(OPT_VID_WHITE_NOISE,            true);

    setFallback(OPT_MON_PALETTE,                PALETTE_COLOR);
    setFallback(OPT_MON_BRIGHTNESS,             50);
    setFallback(OPT_MON_CONTRAST,               100);
    setFallback(OPT_MON_SATURATION,             50);
    setFallback(OPT_MON_HCENTER,                0);
    setFallback(OPT_MON_VCENTER,                0);
    setFallback(OPT_MON_HZOOM,                  0);
    setFallback(OPT_MON_VZOOM,                  46);
    setFallback(OPT_MON_UPSCALER,               UPSCALER_NONE);
    setFallback(OPT_MON_BLUR,                   true);
    setFallback(OPT_MON_BLUR_RADIUS,            0);
    setFallback(OPT_MON_BLOOM,                  false);
    setFallback(OPT_MON_BLOOM_RADIUS,           1000);
    setFallback(OPT_MON_BLOOM_BRIGHTNESS,       400);
    setFallback(OPT_MON_BLOOM_WEIGHT,           1210);
    setFallback(OPT_MON_DOTMASK,                DOTMASK_NONE);
    setFallback(OPT_MON_DOTMASK_BRIGHTNESS,     700);
    setFallback(OPT_MON_SCANLINES,              SCANLINES_NONE);
    setFallback(OPT_MON_SCANLINE_BRIGHTNESS,    550);
    setFallback(OPT_MON_SCANLINE_WEIGHT,        110);
    setFallback(OPT_MON_DISALIGNMENT,           0);
    setFallback(OPT_MON_DISALIGNMENT_H,         1000);
    setFallback(OPT_MON_DISALIGNMENT_V,         1000);

    setFallback(OPT_AUD_SAMPLING,               SMP_NONE);
    setFallback(OPT_AUD_VOL0,                   100);
    setFallback(OPT_AUD_VOL1,                   100);
    setFallback(OPT_AUD_PAN0,                   0);
    setFallback(OPT_AUD_PAN1,                   0);
    setFallback(OPT_AUD_VOL_L,                  50);
    setFallback(OPT_AUD_VOL_R,                  50);

    setFallback(OPT_MEM_HEATMAP,                false);
    
    setFallback(OPT_MOUSE_SHAKE_DETECT,         true);

    setFallback(OPT_AUTOFIRE,                   false);
    setFallback(OPT_AUTOFIRE_BURSTS,            false);
    setFallback(OPT_AUTOFIRE_BULLETS,           3);
    setFallback(OPT_AUTOFIRE_DELAY,             5);

    setFallback(OPT_PADDLE_ORIENTATION,         PADDLE_HORIZONTAL);

    setFallback(OPT_SRV_PORT,                   8081,                   { SERVER_RSH });
    setFallback(OPT_SRV_PROTOCOL,               SRVPROT_DEFAULT,        { SERVER_RSH });
    setFallback(OPT_SRV_AUTORUN,                false,                  { SERVER_RSH });
    setFallback(OPT_SRV_VERBOSE,                true,                   { SERVER_RSH });

    setFallback(OPT_DBG_DEBUGCART,              0);
    setFallback(OPT_DBG_WATCHDOG,               0);
}

void
Defaults::_dump(Category category, std::ostream& os) const
{
    for (const auto &it: fallbacks) {

        const string key = it.first;

        if (values.contains(key)) {

            os << util::tab(key);
            os << values.at(key) << std::endl;

        } else {

            os << util::tab(key);
            os << fallbacks.at(key) << " (Default)" << std::endl;
        }
    }
}

void
Defaults::load(const fs::path &path)
{
    auto fs = std::ifstream(path, std::ifstream::binary);

    if (!fs.is_open()) {
        throw Error(VC64ERROR_FILE_NOT_FOUND);
    }

    debug(DEF_DEBUG, "Loading user defaults from %s...\n", path.string().c_str());
    load(fs);
}

void
Defaults::load(std::ifstream &stream)
{
    std::stringstream ss;
    ss << stream.rdbuf();

    load(ss);
}

void
Defaults::load(std::stringstream &stream)
{
    isize line = 0;
    isize accepted = 0;
    isize skipped = 0;
    string input;
    string section;

    {   SYNCHRONIZED

        debug(DEF_DEBUG, "Loading user defaults from string stream...\n");

        while(std::getline(stream, input)) {

            line++;

            // Remove white spaces
            util::trim(input);

            // Ignore empty lines
            if (input == "") continue;

            // Ignore comments
            if (input.substr(0,1) == "#") continue;

            // Check if this line contains a section marker
            if (input.front() == '[' && input.back() == ']') {

                // Extract the section name
                section = input.substr(1, input.size() - 2);
                continue;
            }

            // Check if this line is a key-value pair
            if (auto pos = input.find("="); pos != std::string::npos) {

                auto key = input.substr(0, pos);
                auto value = input.substr(pos + 1, std::string::npos);

                // Remove white spaces
                util::trim(key);
                util::trim(value);

                // Assemble the key
                auto delimiter = section.empty() ? "" : ".";
                key = section + delimiter + key;

                // Check if the key is a known key
                if (!fallbacks.contains(key)) {

                    warn("Ignoring invalid key %s\n", key.c_str());
                    skipped++;
                    continue;
                }

                // Add the key-value pair
                values[key] = value;
                accepted++;
                continue;
            }

            throw Error(VC64ERROR_SYNTAX, line);
        }

        if (accepted || skipped) {
            debug(DEF_DEBUG, "%ld keys accepted, %ld ignored\n", accepted, skipped);
        }
    }
}

void
Defaults::save(const fs::path &path)
{
    auto fs = std::ofstream(path, std::ofstream::binary);

    if (!fs.is_open()) {
        throw Error(VC64ERROR_FILE_CANT_WRITE);
    }

    save(fs);
}

void
Defaults::save(std::ofstream &stream)
{
    std::stringstream ss;
    save(ss);

    stream << ss.rdbuf();
}

void
Defaults::save(std::stringstream &stream)
{
    {   SYNCHRONIZED

        debug(DEF_DEBUG, "Saving user defaults...\n");

        std::map <string, std::map <string, string>> groups;

        // Write header
        stream << "# Tiara " << Atari::build() << std::endl;
        stream << "# dirkwhoffmann.github.io/tiara2600" << std::endl;
        stream << std::endl;

        // Iterate through all known keys
        for (const auto &it: fallbacks) {

            auto key = it.first;
            auto value = getRaw(key);

            // Check if the key belongs to a group
            if (auto pos = key.find('.'); pos == std::string::npos) {

                // Write ungrouped keys immediately
                stream << key << "=" << value << std::endl;

            } else {

                // Save the key temporarily
                auto prefix = key.substr(0, pos);
                auto suffix = key.substr(pos + 1, string::npos);
                groups[prefix][suffix] = value;
            }
        }

        // Write all groups
        for (const auto &[group, values]: groups) {

            stream << std::endl << "[" << group << "]" << std::endl;

            for (const auto &[key, value]: values) {

                stream << key << "=" << value << std::endl;
            }
        }
    }
}

string
Defaults::getRaw(const string &key) const
{
    if (values.contains(key)) return values.at(key);
    if (fallbacks.contains(key)) return fallbacks.at(key);

    throw Error(VC64ERROR_INVALID_KEY, key);
}

i64
Defaults::get(const string &key) const
{
    auto value = getRaw(key);

    try {

        return i64(std::stoll(value));

    } catch (...) {

        warn("Can't parse value %s\n", key.c_str());
        return 0;
    }
}

i64
Defaults::get(Option option, isize nr) const
{
    try {

        return get(string(OptionEnum::rawkey(option)) + std::to_string(nr));

    } catch (...) {

        return get(string(OptionEnum::rawkey(option)));
    }
}

string
Defaults::getFallbackRaw(const string &key) const
{
    if (fallbacks.contains(key)) return fallbacks.at(key);

    throw Error(VC64ERROR_INVALID_KEY, key);
}

i64
Defaults::getFallback(const string &key) const
{
    auto value = getFallbackRaw(key);

    try {

        return i64(std::stoll(value));

    } catch (...) {

        warn("Can't parse value %s\n", key.c_str());
        return 0;
    }
}

i64
Defaults::getFallback(Option option, isize nr) const
{
    try {

        return getFallback(string(OptionEnum::rawkey(option)) + std::to_string(nr));

    } catch (...) {

        return getFallback(string(OptionEnum::rawkey(option)));
    }
}

void
Defaults::set(const string &key, const string &value)
{
    {   SYNCHRONIZED

        debug(DEF_DEBUG, "%s = %s\n", key.c_str(), value.c_str());

        if (!fallbacks.contains(key)) {

            warn("Invalid key: %s\n", key.c_str());
            assert(false);
            throw Error(VC64ERROR_INVALID_KEY, key);
        }

        values[key] = value;
    }
}

void
Defaults::set(Option option, const string &value)
{
    set(OptionEnum::rawkey(option), value);
}

void
Defaults::set(Option option, const string &value, std::vector <isize> objids)
{
    auto key = string(OptionEnum::rawkey(option));

    for (auto &nr : objids) {
        set(key + std::to_string(nr), value);
    }
}

void 
Defaults::set(Option option, i64 value)
{
    set(option, std::to_string(value));
}

void
Defaults::set(Option option, i64 value, std::vector <isize> objids)
{
    set(option, std::to_string(value), objids);
}

void
Defaults::setFallback(const string &key, const string &value)
{
    {   SYNCHRONIZED

        debug(DEF_DEBUG, "Fallback: %s = %s\n", key.c_str(), value.c_str());
        fallbacks[key] = value;
    }
}

void
Defaults::setFallback(Option option, const string &value)
{
    setFallback(OptionEnum::rawkey(option), value);
}

void
Defaults::setFallback(Option option, const string &value, std::vector <isize> objids)
{
    auto key = string(OptionEnum::rawkey(option));

    for (auto &nr : objids) {
        setFallback(key + std::to_string(nr), value);
    }
}

void
Defaults::setFallback(Option option, i64 value)
{
    setFallback(option, std::to_string(value));
}

void
Defaults::setFallback(Option option, i64 value, std::vector <isize> objids)
{
    setFallback(option, std::to_string(value), objids);
}

void
Defaults::remove()
{
    SYNCHRONIZED values.clear();
}

void
Defaults::remove(const string &key)
{
    {   SYNCHRONIZED

        if (!fallbacks.contains(key)) {

            warn("Invalid key: %s\n", key.c_str());
            assert(false);
            throw Error(VC64ERROR_INVALID_KEY, key);
        }
        if (values.contains(key)) {
            values.erase(key);
        }
    }
}

void
Defaults::remove(Option option)
{
    remove(string(OptionEnum::rawkey(option)));
}

void
Defaults::remove(Option option, std::vector <isize> nrs)
{
    for (auto &nr : nrs) {
        remove(string(OptionEnum::rawkey(option)) + std::to_string(nr));
    }
}

}

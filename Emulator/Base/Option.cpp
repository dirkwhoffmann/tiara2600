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
#include "Option.h"
#include "TiaraTypes.h"
#include "Error.h"
#include "IOUtils.h"
#include "Macros.h"

namespace tiara {

std::unique_ptr<OptionParser>
OptionParser::create(Option opt, i64 arg)
{
    auto enumParser = [&]<typename T>() { return std::unique_ptr<EnumParser<T>>(new EnumParser<T>(opt, arg)); };
    auto boolParser = [&]() { return std::unique_ptr<BoolParser>(new BoolParser(opt, arg)); };
    auto numParser  = [&](string unit = "") { return std::unique_ptr<NumParser>(new NumParser(opt, arg, unit)); };
    // auto hexParser  = [&](string unit = "") { return std::unique_ptr<HexParser>(new HexParser(opt, arg, unit)); };

    switch (opt) {

        case OPT_HOST_SAMPLE_RATE:          return numParser(" Hz");
        case OPT_HOST_REFRESH_RATE:         return numParser(" fps");
        case OPT_HOST_FRAMEBUF_WIDTH:       return numParser(" pixels");
        case OPT_HOST_FRAMEBUF_HEIGHT:      return numParser(" pixels");

        case OPT_ATARI_WARP_MODE:           return enumParser.template operator()<WarpModeEnum>();
        case OPT_ATARI_WARP_BOOT:           return numParser(" sec");
        case OPT_ATARI_VSYNC:               return boolParser();
        case OPT_ATARI_SPEED_BOOST:         return numParser("%");
        case OPT_ATARI_RUN_AHEAD:           return numParser(" frames");

        case OPT_ATARI_SNAP_AUTO:           return boolParser();
        case OPT_ATARI_SNAP_DELAY:          return numParser(" sec");
        case OPT_ATARI_SNAP_COMPRESS:       return boolParser();

        case OPT_TIA_REVISION:              return enumParser.template operator()<TIARevisionEnum>();
        case OPT_TIA_COLLISIONS:            return numParser();
        case OPT_TIA_REGLOCK:               return numParser();
        case OPT_TIA_POWER_SAVE:            return boolParser();

        case OPT_RAM_INIT_PATTERN:          return enumParser.template operator()<RamPatternEnum>();

        case OPT_LA_ENABLE:                 return boolParser();
        case OPT_LA_CHANNEL0:               return boolParser();
        case OPT_LA_CHANNEL1:               return boolParser();
        case OPT_LA_CHANNEL2:               return boolParser();
        case OPT_LA_CHANNEL3:               return boolParser();
        case OPT_LA_PROBE0:                 return enumParser.template operator()<ProbeEnum>();
        case OPT_LA_PROBE1:                 return enumParser.template operator()<ProbeEnum>();
        case OPT_LA_PROBE2:                 return enumParser.template operator()<ProbeEnum>();
        case OPT_LA_PROBE3:                 return enumParser.template operator()<ProbeEnum>();
        case OPT_LA_MODE:                   return enumParser.template operator()<LaDisplayModeEnum>();
        case OPT_LA_OPACITY:                return numParser("%");

        case OPT_CART_TYPE:                 return enumParser.template operator()<CartTypeEnum>();

        case OPT_VID_WHITE_NOISE:           return boolParser();
            
        case OPT_MON_PALETTE:               return enumParser.template operator()<PaletteEnum>();
        case OPT_MON_BRIGHTNESS:            return numParser("%");
        case OPT_MON_CONTRAST:              return numParser("%");
        case OPT_MON_SATURATION:            return numParser("%");
        case OPT_MON_HCENTER:               return numParser();
        case OPT_MON_VCENTER:               return numParser();
        case OPT_MON_HZOOM:                 return numParser();
        case OPT_MON_VZOOM:                 return numParser();
        case OPT_MON_UPSCALER:              return enumParser.template operator()<UpscalerEnum>();
        case OPT_MON_BLUR:                  return boolParser();
        case OPT_MON_BLUR_RADIUS:           return numParser();
        case OPT_MON_BLOOM:                 return boolParser();
        case OPT_MON_BLOOM_RADIUS:          return numParser();
        case OPT_MON_BLOOM_BRIGHTNESS:      return numParser();
        case OPT_MON_BLOOM_WEIGHT:          return numParser();
        case OPT_MON_DOTMASK:               return enumParser.template operator()<DotmaskEnum>();
        case OPT_MON_DOTMASK_BRIGHTNESS:    return numParser();
        case OPT_MON_SCANLINES:             return enumParser.template operator()<ScanlinesEnum>();
        case OPT_MON_SCANLINE_BRIGHTNESS:   return numParser();
        case OPT_MON_SCANLINE_WEIGHT:       return numParser();
        case OPT_MON_DISALIGNMENT:          return boolParser();
        case OPT_MON_DISALIGNMENT_H:        return numParser();
        case OPT_MON_DISALIGNMENT_V:        return numParser();

        case OPT_AUD_SAMPLING:              return enumParser.template operator()<SamplingMethodEnum>();
        case OPT_AUD_VOL0:                  return numParser("%");
        case OPT_AUD_VOL1:                  return numParser("%");
        case OPT_AUD_VOL2:                  return numParser("%");
        case OPT_AUD_VOL3:                  return numParser("%");
        case OPT_AUD_PAN0:                  return numParser();
        case OPT_AUD_PAN1:                  return numParser();
        case OPT_AUD_PAN2:                  return numParser();
        case OPT_AUD_PAN3:                  return numParser();
        case OPT_AUD_VOL_L:                 return numParser("%");
        case OPT_AUD_VOL_R:                 return numParser("%");

        case OPT_MEM_HEATMAP:               return boolParser();

        case OPT_MOUSE_SHAKE_DETECT:        return boolParser();

        case OPT_AUTOFIRE:                  return boolParser();
        case OPT_AUTOFIRE_BURSTS:           return boolParser();
        case OPT_AUTOFIRE_BULLETS:          return numParser(" bullets");
        case OPT_AUTOFIRE_DELAY:            return numParser(" frames");

        case OPT_PADDLE_ORIENTATION:        return enumParser.template operator()<PaddleOrientationEnum>();

        case OPT_SRV_PORT:                  return numParser();
        case OPT_SRV_PROTOCOL:              return enumParser.template operator()<ServerProtocolEnum>();
        case OPT_SRV_AUTORUN:               return boolParser();
        case OPT_SRV_VERBOSE:               return boolParser();

        case OPT_DBG_DEBUGCART:             return boolParser();
        case OPT_DBG_WATCHDOG:              return numParser();

        default:
            fatalError;
    }
}

i64 
OptionParser::parse(Option opt, const string &arg)
{
    return create(opt)->parse(arg);
}

string
OptionParser::asPlainString(Option opt, i64 arg)
{
    return create(opt, arg)->asPlainString();
}

string
OptionParser::asString(Option opt, i64 arg)
{
    return create(opt, arg)->asString();
}

string
OptionParser::keyList(Option opt)
{
    return create(opt)->keyList();
}

string
OptionParser::argList(Option opt)
{
    return create(opt)->argList();
}

string
HexParser::asPlainString()
{
    std::stringstream ss;
    ss << std::hex << "0x" << std::setw(4) << std::setfill('0') << arg;

    return ss.str();
}

}

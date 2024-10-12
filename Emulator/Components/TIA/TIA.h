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

#include "TIAComponents.h"
#include "SubComponent.h"
#include "AtariTypes.h"
#include "Constants.h"

namespace tiara {

class TIA final : public SubComponent, public Inspectable<TIAInfo, TIAStats> {

    friend class LogicAnalyzer;
    
    Descriptions descriptions = {
        {
            .type           = TIAClass,
            .name           = "TIA",
            .description    = "Television Interface Adaptor",
            .shell          = "tia"
        }
    };

    static constexpr TIATraits traits[3] = {
        {
            .revision       = TIA_NTSC,

            .cpuFrequency   = NTSC::CPU_CLOCK_FREQUENCY,
            .fps            = NTSC::FPS,

            .width          = NTSC::WIDTH,
            .height         = NTSC::HEIGHT,
            .hblankWidth    = NTSC::FIRST_VISIBLE_PIXEL,
            .vblankHeight   = NTSC::FIRST_VISIBLE_LINE,
            .visibleWidth   = NTSC::VISIBLE_WIDTH,
            .visibleHeight  = NTSC::VISIBLE_HEIGHT
        },
        {
            .revision       = TIA_PAL,

            .cpuFrequency   = PAL::CPU_CLOCK_FREQUENCY,
            .fps            = PAL::FPS,

            .width          = PAL::WIDTH,
            .height         = PAL::HEIGHT,
            .hblankWidth    = PAL::FIRST_VISIBLE_PIXEL,
            .vblankHeight   = PAL::FIRST_VISIBLE_LINE,
            .visibleWidth   = PAL::VISIBLE_WIDTH,
            .visibleHeight  = PAL::VISIBLE_HEIGHT
        },
        {
            .revision       = TIA_SECAM,

            .cpuFrequency   = PAL::CPU_CLOCK_FREQUENCY,
            .fps            = PAL::FPS,

            .width          = PAL::WIDTH,
            .height         = PAL::HEIGHT,
            .hblankWidth    = PAL::FIRST_VISIBLE_PIXEL,
            .vblankHeight   = PAL::FIRST_VISIBLE_LINE,
            .visibleWidth   = PAL::VISIBLE_WIDTH,
            .visibleHeight  = PAL::VISIBLE_HEIGHT
        }
    };

    Options options = {

        OPT_TIA_REVISION,
        OPT_TIA_POWER_SAVE
    };

    // Current configuration
    TIAConfig config{};

    // Frame counter
    isize frame{};

    // Beam position
    isize x{}, y{};


    //
    // Chip interface
    //

public:

    // Chip Select (1 = selected)
    bool cs{};

    // Read-write (1 = read)
    bool rw{};


    //
    // Internal components
    //

private:

    // VSYNC and VBLANK latches
    bool vs{};
    bool vb{};

    // RDY latch (controls the CPU's RDY input)
    bool rdy{};

    // The horizontal counter
    DualPhaseCounter<56> hc { .phase = 1, .current = 56, .resl = false, .res = true };


    //
    // Signals
    //

    TIARegister strobe = TIA_VOID;


    //
    // Screen buffers and colors
    //

private:

    // C64 colors in RGBA format (updated in updatePalette())
    u32 rgbaTable[16]{};

    /* Texture buffers. TIA outputs the generated texture into these buffers.
     * At any time, one buffer is the working buffer and the other one is the
     * stable buffer. While TIA always writes into the working buffer, the
     * GUI accesses the stable buffer at a constant frame rate and copies it
     * into the GPU's texture RAM.
     *
     * The emuTexture buffers contain the emulator texture. It is the texture
     * that is usually drawn by the GUI. The dmaTexture buffers contain the
     * texture generated by the logic analyzer. If the logic analyzer is
     * enabled, this texture is superimposed on the emulator texture.
     */
    u32 *emuTexture1 = new u32[Texture::height * Texture::width];
    u32 *emuTexture2 = new u32[Texture::height * Texture::width];
    u32 *dmaTexture1 = new u32[Texture::height * Texture::width];
    u32 *dmaTexture2 = new u32[Texture::height * Texture::width];

    /* Pointer to the current working texture. This variable points either to
     * the first or the second texture buffer. After a frame has been finished,
     * the pointer is redirected to the other buffer.
     */
    u32 *emuTexture{};
    u32 *dmaTexture{};

    /* Pointer to the beginning of the current scanline inside the current
     * working textures. These pointers are used by all rendering methods to
     * write pixels. It always points to the beginning of a scanline, either
     * the first or the second texture buffer. They are reset at the beginning
     * of each frame and incremented at the beginning of each scanline.
     */
    // u32 *emuTexturePtr;
    // u32 *dmaTexturePtr;


    //
    // Methods
    //

public:

    TIA(Atari &ref);

    TIA& operator= (const TIA& other) {

        CLONE(config)

        CLONE(x)
        CLONE(y)

        return *this;
    }

    //
    // Methods from Serializable
    //

public:

    template <class T> void serialize(T& worker) {

        worker

        << x
        << y;

        if (isResetter(worker)) return;

        // worker
        //
        // << config.xxx;

    } SERIALIZERS(serialize);


    //
    // Methods from CoreComponent
    //

public:

    const Descriptions &getDescriptions() const override { return descriptions; }

private:

    void _dump(Category category, std::ostream& os) const override;
    void _initialize() override;
    void _didReset(bool hard) override;
    void _trackOn() override;
    void _trackOff() override;
    

    //
    // Methods from Inspectable
    //

private:

    void cacheInfo(TIAInfo &result) const override;
    void cacheStats(TIAStats &result) const override;


    //
    // Methods from Configurable
    //

public:

    const TIAConfig &getConfig() const { return config; }
    const Options &getOptions() const override { return options; }
    i64 getOption(Option opt) const override;
    void checkOption(Option opt, i64 value) override;
    void setOption(Option opt, i64 value) override;


    //
    // Deriving chip properties
    //

public:

    // Returns properties about the currently selected TIA chip
    const TIATraits &getTraits() const { return traits[config.revision]; }

    // Returns the number of cycles per frame
    isize tiaCyclesPerFrame() const { return traits[config.revision].height * TIA_CYCLES_PER_LINE; }
    isize cpuCyclesPerFrame() const { return traits[config.revision].height * CPU_CYCLES_PER_LINE; }


    //
    // Managing the beam
    //

public:

    isize getX() const { return x; }
    isize getY() const { return y; }

    // Computes the distance of the beam to the provided position
    isize diff(isize y, isize x);


    //
    // Managing colors
    //

public:

    void updatePalette();


    //
    // Working with textures
    //

public:
    
    // Returns pointers to the stable textures
    u32 *getTexture() const;
    u32 *getDmaTexture() const;

    void resetEmuTexture(isize nr);
    void resetEmuTextures() { resetEmuTexture(1); resetEmuTexture(2); }
    void resetDmaTexture(isize nr);
    void resetDmaTextures() { resetDmaTexture(1); resetDmaTexture(2); }
    void resetTexture(u32 *p);

    void drawPixel(isize x, isize y, u32 color);
    void drawDebugPixel(isize x, isize y, u32 color);


    //
    // Accessing registers and memory
    //

public:

    u8 peek(u16 addr);
    u8 spy(u16 addr) const;

    void poke(TIARegister reg, u8 val, Cycle delay = 0);

    
    //
    // Executing
    //

public:

    // Executes three color clock cycles
    template <bool> void execute();
    template <bool, isize> void execute();

    // Frame handlers (start of frame, end of frame)
    void sofHandler();
    void eofHandler();


    //
    // Processing events and commands
    //

public:

    // Processes a command from the command queue
    // void processCommand(const Cmd &cmd) { };

};

}

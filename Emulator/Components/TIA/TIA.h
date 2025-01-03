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
#include "Audio.h"
#include "Playfield.h"
#include "Player.h"
#include "Missile.h"
#include "Ball.h"
#include "Constants.h"

namespace tiara {

class TIA final : public SubComponent, public Inspectable<TIAInfo, TIAStats> {

    friend class Playfield;
    friend class Player;
    friend class Missile;
    friend class LogicAnalyzer;

    Descriptions descriptions = {
        {
            .type           = TIAClass,
            .name           = "TIA",
            .description    = "Television Interface Adaptor",
            .shell          = "tia"
        }
    };

    static constexpr TIATraits traits[6] = {
        {
            .revision           = TIA_NTSC,
            .palette            = TIA_PALETTE_NTSC,

            .cpuFrequency       = NTSC::CPU_CLOCK_FREQUENCY,
            .cpuCyclesPerFrame  = NTSC::CPU_CYCLES_PER_FRAME,
            .fps                = NTSC::FPS,

            .width              = NTSC::WIDTH,
            .height             = NTSC::HEIGHT,
            .hblankWidth        = NTSC::FIRST_VISIBLE_PIXEL,
            .vblankHeight       = NTSC::FIRST_VISIBLE_LINE,
            .visibleWidth       = NTSC::VISIBLE_WIDTH,
            .visibleHeight      = NTSC::VISIBLE_HEIGHT
        },
        {
            .revision           = TIA_PAL,
            .palette            = TIA_PALETTE_PAL,

            .cpuFrequency       = PAL::CPU_CLOCK_FREQUENCY,
            .cpuCyclesPerFrame  = PAL::CPU_CYCLES_PER_FRAME,
            .fps                = PAL::FPS,

            .width              = PAL::WIDTH,
            .height             = PAL::HEIGHT,
            .hblankWidth        = PAL::FIRST_VISIBLE_PIXEL,
            .vblankHeight       = PAL::FIRST_VISIBLE_LINE,
            .visibleWidth       = PAL::VISIBLE_WIDTH,
            .visibleHeight      = PAL::VISIBLE_HEIGHT
        },
        {
            .revision           = TIA_SECAM,
            .palette            = TIA_PALETTE_SECAM,

            .cpuFrequency       = PAL::CPU_CLOCK_FREQUENCY,
            .cpuCyclesPerFrame  = PAL::CPU_CYCLES_PER_FRAME,
            .fps                = PAL::FPS,

            .width              = PAL::WIDTH,
            .height             = PAL::HEIGHT,
            .hblankWidth        = PAL::FIRST_VISIBLE_PIXEL,
            .vblankHeight       = PAL::FIRST_VISIBLE_LINE,
            .visibleWidth       = PAL::VISIBLE_WIDTH,
            .visibleHeight      = PAL::VISIBLE_HEIGHT
        },
        {
            .revision           = TIA_NTSC50,
            .palette            = TIA_PALETTE_NTSC,

            .cpuFrequency       = PAL::CPU_CLOCK_FREQUENCY,
            .cpuCyclesPerFrame  = PAL::CPU_CYCLES_PER_FRAME,
            .fps                = PAL::FPS,

            .width              = PAL::WIDTH,
            .height             = PAL::HEIGHT,
            .hblankWidth        = PAL::FIRST_VISIBLE_PIXEL,
            .vblankHeight       = PAL::FIRST_VISIBLE_LINE,
            .visibleWidth       = PAL::VISIBLE_WIDTH,
            .visibleHeight      = PAL::VISIBLE_HEIGHT
        },
        {
            .revision           = TIA_PAL60,
            .palette            = TIA_PALETTE_PAL,

            .cpuFrequency       = NTSC::CPU_CLOCK_FREQUENCY,
            .cpuCyclesPerFrame  = NTSC::CPU_CYCLES_PER_FRAME,
            .fps                = NTSC::FPS,

            .width              = NTSC::WIDTH,
            .height             = NTSC::HEIGHT,
            .hblankWidth        = NTSC::FIRST_VISIBLE_PIXEL,
            .vblankHeight       = NTSC::FIRST_VISIBLE_LINE,
            .visibleWidth       = NTSC::VISIBLE_WIDTH,
            .visibleHeight      = NTSC::VISIBLE_HEIGHT
        },
        {
            .revision           = TIA_SECAM60,
            .palette            = TIA_PALETTE_SECAM,

            .cpuFrequency       = NTSC::CPU_CLOCK_FREQUENCY,
            .cpuCyclesPerFrame  = NTSC::CPU_CYCLES_PER_FRAME,
            .fps                = NTSC::FPS,

            .width              = NTSC::WIDTH,
            .height             = NTSC::HEIGHT,
            .hblankWidth        = NTSC::FIRST_VISIBLE_PIXEL,
            .vblankHeight       = NTSC::FIRST_VISIBLE_LINE,
            .visibleWidth       = NTSC::VISIBLE_WIDTH,
            .visibleHeight      = NTSC::VISIBLE_HEIGHT
        }
    };

    Options options = {

        OPT_TIA_REVISION,
        OPT_TIA_AUTO_DETECT,
        OPT_TIA_COLLISIONS,
        OPT_TIA_REG_LOCK,
        OPT_TIA_REG_WATCH,
    };

    // Current configuration
    TIAConfig config{};


    //
    // Lookup tables
    //

    // Color lookup table ( [PFP][SCORE][RIGHT][<TIA objects>] )
    TIAColor colorTable[2][2][2][64];

    // Collision lookup table ( [<TIA objects>] )
    u32 collisonTable[64];


    //
    // Subcomponents
    //

public:

    // Audio units
    Audio audio[2] = { Audio(atari, 0), Audio(atari, 1) };


    //
    // Objects
    //

    Playfield pf;
    Player p0;
    Player p1;
    Missile m0;
    Missile m1;
    Ball bl;


    //
    // Extra motion clocks
    //

    isize hmc;
    ExtraClock blec;
    ExtraClock m0ec;
    ExtraClock m1ec;
    ExtraClock p0ec;
    ExtraClock p1ec;


    //
    // Counters
    //

    // Beam position
    isize x{}, y{};




    //
    // Registers
    //

    // Color registers
    u8 colup0 = 0;
    u8 colup1 = 0;
    u8 colupf = 0;
    u8 colubk = 0;

    // RGBA values of the four selected colors
    u32 rgba[4]{};

    // Control playfield, ball size, collisions
    u8 ctrlpf = 0;
    bool score = false;
    bool pfp = false;

    // Collision bits
    u32 cx = 0;

    // Port bits
    u8 inpt[6]{};

    // Latch mode for INPT.4 and INPT.5
    bool inptLatched = false;


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
    bool vs = false; // TODO: RENAME TO VSYNC
    bool vb = false; // DEPRECATED
    u8 vblank = 0;

    // Controls the vertical beam reset
    bool vsedge = false;

    // RDY latch (controls the CPU's RDY input)
    bool rdy = false;

    // Dual-phase horizontal counter
    DualPhaseCounter<56> hc;

    // SEC logic
    SEC sec;

    // Latched SEC signal
    bool secl = false;

    // HB latch (Horizontal Blank)
    DualPhaseDelayLatch<bool> hb;


    //
    // Signals
    //

    TIARegister strobe = TIA_VOID;

    u8 dataBus = 0;


    //
    // Screen buffers and colors
    //

private:

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


    //
    // Methods
    //

public:

    TIA(Atari &ref);

    TIA& operator= (const TIA& other) {

        CLONE(config)

        CLONE_ARRAY(audio)
        CLONE(pf)
        CLONE(p0)
        CLONE(p1)
        CLONE(m0)
        CLONE(m1)
        CLONE(bl)

        CLONE(hmc)
        CLONE(blec)
        CLONE(m0ec)
        CLONE(m1ec)
        CLONE(p0ec)
        CLONE(p1ec)
        
        CLONE(x)
        CLONE(y)
        
        CLONE(colup0)
        CLONE(colup1)
        CLONE(colupf)
        CLONE(colubk)
        CLONE_ARRAY(rgba)
        
        CLONE(ctrlpf)
        CLONE(score)
        CLONE(pfp)
        CLONE(cx)

        CLONE_ARRAY(inpt)
        CLONE(inptLatched)
              
        CLONE(cs)
        CLONE(rw)

        CLONE(vs)
        CLONE(vb)
        CLONE(vblank)
        CLONE(vsedge)
        CLONE(rdy)
        CLONE(hc)
        CLONE(sec)
        CLONE(secl)
        CLONE(hb)

        CLONE(strobe)
        CLONE(dataBus)

        return *this;
    }

    //
    // Methods from Serializable
    //

public:

    template <class T> void serialize(T& worker) {

        worker

        << audio
        << pf
        << p0
        << p1
        << m0
        << m1
        << bl

        << hmc
        << blec
        << m0ec
        << m1ec
        << p0ec
        << p1ec

        << x
        << y

        << colup0
        << colup1
        << colupf
        << colubk
        << rgba

        << ctrlpf
        << score
        << pfp
        << cx

        << inpt
        << inptLatched
        
        << cs
        << rw

        << vs
        << vb
        << vblank
        << vsedge
        << rdy
        << hc
        << sec
        << secl
        << hb

        << strobe
        << dataBus;

        if (isResetter(worker)) return;

        worker
        
        << config.revision
        << config.autoDetect
        << config.collMask
        << config.lockMask
        << config.watchMask;

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
    u8 spy(TIARegister addr) const;

    void poke(TIARegister reg, u8 val);
    void poke(TIARegister reg, u8 val, Cycle delay);

    void latchInpt45(bool value);
    void updateInpt();


    //
    // Executing
    //

public:

    // Executes three color-clock cycles
    template <bool fastPaths> void execute();

    // Executes a specific color-clock cycle
    template <bool fastPaths, bool phi1, bool phi2> void execute(isize cycle);

    // Start-of-frame handler
    void sofHandler();

    // End-of-frame handler
    void eofHandler();


    //
    // Processing events and commands
    //

public:

    // Processes a command from the command queue
    // void processCommand(const Cmd &cmd) { };

};

}

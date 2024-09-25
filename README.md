Tiara2600 will be an Atari 2600 emulator for macOS written in C++. 

<p align="center">
  <a href = "https://dirkwhoffmann.github.io/virtualc64"><img src="https://dirkwhoffmann.github.io/virtualc64/images/tiara-banner.png" width="60%"></a>
</p>

Tiara will be my third retro emulator after VirtualC64 and vAmiga. The project has just started, so don't expect anything to work. As I strongly favor the philosophy of keeping a system runnable at all time, I will not develop the emulator from the ground up. Instead, I will start with one of my existing Commodore emulators and gradually turn it into an Atari. Thus, don't be surprised to find a complete copy of the current VirtualC64 repo as the first commit.

Although emulator development is a challenging task in general, writing an Atari 2600 emulator is comparably easy these days. First, when compared to an advanced machine such as the Commodore Amiga, the Atari 2600 has almost trivial hardware, and most components are well documented. For example, complete schematics are available for the TIA chip, which is the most challenging part of the 2600. Second, a couple of accurate emulators already exist, which I can use later to run my work against. All and foremost, there is [Stella](https://github.com/stella-emu/stella), the by far the most prominent Atari 2600 emulator. It emulates the machine accurately and supports many cartridges and additional hardware. Then, there is [jigo2600](https://github.com/jigo2600), which I like for two reasons: First, it has a clean and concise code base that is well-documented and easy to read. Second, it emulates the Atari 2600 with high precision by sticking close to the hardware level. At the same time, it is abstract enough to gain high emulation speed. If I ever finish Tiara, I can already tell that its design will closely resemble what jigo2600 already presents. I fell in love with the Jigo design the minute I encountered the project.

Let the fun begin. Let us turn this...

<p align="center">
  <a href = "https://dirkwhoffmann.github.io/virtualc64"><img src="https://dirkwhoffmann.github.io/virtualc64/images/tiara1.png"  width="50%"></a>
</p>

into this...

<p align="center">
  <a href = "https://dirkwhoffmann.github.io/virtualc64"><img src="https://dirkwhoffmann.github.io/virtualc64/images/tiara3.png"  width="50%"></a>
</p>


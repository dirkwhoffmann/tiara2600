Welcome to the official Tiara documentation. Here you will find a detailed view of Tiara's public API. It summarizes the necesarry information for developers to incoorporate the emulation core in own projects. For more information about Tiara plase visit the [official website](https://dirkwhoffmann.github.io/tiara2600/).

\image html ad-vc.png width=400px

![Watchers](https://img.shields.io/github/watchers/dirkwhoffmann/tiara?style=social)
![Stars](https://img.shields.io/github/stars/dirkwhoffmann/tiara?style=social)
![Forks](https://img.shields.io/github/forks/dirkwhoffmann/tiara?style=social)

![Build](https://github.com/dirkwhoffmann/tiara/workflows/CMake/badge.svg)
![Build](https://github.com/dirkwhoffmann/tiara/workflows/CMake-MinGW/badge.svg)
![MSVC](https://github.com/dirkwhoffmann/tiara/workflows/CMake-MSVC/badge.svg)

## Example

Tiara is implemented in C++20 with high portability in mind. The following code snippet demonstrates the general usage model of the emulator core.

```cpp
#include "Tiara.h"

int main(int argc, char *argv[]) 
{

	// Create an emulator instance
	Tiara tiara;

	// Launch the emulator thread (with messageReceiver defined elsewhere)
	tiara.launch(this, messageReceiver);

	// Configure the emulator
	tiara.set(OPT_xxx, yyy);

	// Start the emulator
	tiara.run() 

	//
	// Interact with the emulator
	// 
}
```

## See also

- Class [Tiara](#tiara::Tiara) which provides the public API.

<div class="section_buttons">

|                        Next |
|----------------------------:|
| [Headless App](headless.md) |
 
</div>

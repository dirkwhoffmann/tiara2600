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

namespace tiara {

#define BASIC       ROM_TYPE_BASIC
#define KERNAL      ROM_TYPE_KERNAL
#define CHAR        ROM_TYPE_CHAR
#define VC1541      ROM_TYPE_VC1541

#define COMMODORE   ROM_VENDOR_COMMODORE
#define MEGA65      ROM_VENDOR_MEGA65
#define OTHER       ROM_VENDOR_OTHER

static std::vector<RomTraits> roms = {
    {
        .md5          = "000509d1ed2b8d30a9d94be1b3b5febb",
        .manufacturer = "Greg Zumwalt",
        .name         = "Jungle Jane (2003) (Greg Zumwalt) (Hack)",
        .note         = "Hack of Pitfall!",
    },{
        .md5          = "0060a89b4c956b9c703a59b181cb3018",
        .manufacturer = "CommaVid, Irwin Gaines - Ariola",
        .model        = "CM-008 - 712 008-720",
        .name         = "Cakewalk (1983) (CommaVid) (PAL)",
        .note         = "AKA Alarm in der Backstube",
    },{
        .md5          = "007d18dedc1f0565f09c42aa61a6f585",
        .manufacturer = "CCE",
        .model        = "C-843",
        .name         = "Worm War I (1983) (CCE)",
    },{
        .md5          = "008543ae43497af015e9428a5e3e874e",
        .manufacturer = "Retroactive",
        .name         = "Qb (V2.09) (PAL) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "00b7b4cbec81570642283e7fc1ef17af",
        .manufacturer = "SEGA - Beck-Tech, Steve Beck, Phat Ho",
        .model        = "006-01",
        .name         = "Congo Bongo (1983) (SEGA)",
    },{
        .md5          = "00ce0bdd43aed84a983bef38fe7f5ee3",
        .manufacturer = "20th Century Fox, Bill Aspromonte",
        .model        = "11012",
        .name         = "Bank Heist (1983) (20th Century Fox)",
        .note         = "AKA Bonnie and Clyde, Cops 'n' Robbers, Holdup, Rooring 20's",
    },{
        .md5          = "00ce76ad69cdc2fa36ada01ae092d5a6",
        .manufacturer = "Bit Corporation",
        .model        = "PGP214",
        .name         = "Cosmic Avenger (4 Game in One) (1983) (BitCorp) (PAL)",
        .note         = "AKA StarMaster",
    },{
        .md5          = "00dc28b881989c39a6cf87a892bd3c6b",
        .manufacturer = "CCE",
        .name         = "Krull (CCE)",
    },{
        .md5          = "00e19ebf9d0817ccfb057e262be1e5af",
        .manufacturer = "Atari, Ed Logg, Carol Shaw",
        .model        = "CX2639, CX2639P",
        .name         = "Othello (1981) (Atari) (PAL) [no grid markers]",
    },{
        .md5          = "00e55b27fe2e96354cd21b8b698d1e31",
        .name         = "Phoenix (Unknown)",
    },{
        .md5          = "00eaee22034aff602f899b684c107d77",
        .manufacturer = "Rainbow Vision - Suntek - Sunteck Corp",
        .model        = "SS-001",
        .name         = "Time Race (1983) (Rainbow Vision) (PAL)",
        .note         = "AKA Space Jockey",
    },{
        .md5          = "00f7985c20b8bdf3c557fac4d3f26775",
        .manufacturer = "Aaron Curtis",
        .name         = "AStar (NTSC)",
    },{
        .md5          = "012020625a3227815e47b37fd025e480",
        .manufacturer = "Rob Kudla",
        .name         = "Better Space Invaders (1999) (Rob Kudla) (Hack) [a]",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "01293bd90a4579abb7aed2f7d440681f",
        .manufacturer = "Century",
        .name         = "Snoopy (1983) (Century) (PAL)",
        .note         = "AKA Snoopy and the Red Baron",
    },{
        .md5          = "01297d9b450455dd716db9658efb2fae",
        .manufacturer = "TechnoVision - Video Technology",
        .model        = "TVS1002",
        .name         = "Save Our Ship (1983) (TechnoVision) (PAL)",
    },{
        .md5          = "012b8e6ef3b5fd5aabc94075c527709d",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4302",
        .name         = "Party Mix (1983) (Arcadia)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "0164f26f6b38a34208cd4a2d0212afc3",
        .manufacturer = "Coleco - Individeo, Ed English",
        .model        = "2656",
        .name         = "Mr. Do! (1983) (Coleco)",
        .phosphor     = 1,
    },{
        .md5          = "0173675d40a8d975763ee493377ca87d",
        .manufacturer = "CBS Electronics - Individeo, Ed English",
        .model        = "4L1751",
        .name         = "Roc 'n Rope (1984) (CBS Electronics) (PAL)",
    },{
        .md5          = "01abcc1d2d3cba87a3aa0eb97a9d7b9c",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Topy (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "01b09872dcd9556427761f0ed64aa42a",
        .manufacturer = "Galaga Games",
        .name         = "River Raid (1984) (Galaga Games)",
    },{
        .md5          = "01cb3e8dfab7203a9c62ba3b94b4e59f",
        .manufacturer = "Atari, Mimi Nyden, Scott Smith, Robert Vieira",
        .model        = "CX26127",
        .name         = "Gremlins (1984) (Atari)",
    },{
        .md5          = "01e5c81258860dd82f77339d58bc5f5c",
        .manufacturer = "CCE",
        .name         = "Corrida da Matematica (CCE)",
        .note         = "AKA Math Gran Prix",
    },{
        .md5          = "01e60a109a6a67c70d3c0528381d0187",
        .manufacturer = "ITT Family Games, Perry Rhodan-Serie",
        .model        = "554-33 383",
        .name         = "Fire Birds (1983) (ITT Family Games) (PAL)",
        .note         = "AKA Sky Alien",
    },{
        .md5          = "01f584bf67b0e464014a8c8b5ea470e3",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "5 AR-4200",
        .name         = "Labyrinth (Escape from the Mindmaster Beta) (1982) (Arcadia)",
    },{
        .md5          = "02066b17f29082412c6754c1a2d6302e",
        .name         = "Demo Image Series #3 - Baboon (19-02-2003) (Andrew Davie)",
    },{
        .md5          = "021dbeb7417cac4e5f8e867393e742d6",
        .manufacturer = "Simone Serra - AtariAge",
        .model        = "RC 09.09.2008",
        .name         = "Lead ",
    },{
        .md5          = "024365007a87f213cbe8ef5f2e8e1333",
        .manufacturer = "Atari, Frank Hausman, Mimi Nyden, Steve Woita",
        .model        = "CX2686",
        .name         = "Quadrun (1983) (Atari)",
    },{
        .md5          = "025668e36a788e8af8ac4f1be7e72043",
        .manufacturer = "Atari, Jerome Domurat, Howard Scott Warshaw",
        .model        = "CX2659",
        .name         = "Raiders of the Lost Ark (06-14-82) (Atari) (Prototype)",
        .note         = "Console ports are swapped",
        .swapPorts    = 1,
    },{
        .md5          = "026180bf641ff17d8577c33facf0edea",
        .manufacturer = "Activision, Steve Cartwright",
        .model        = "AX-022",
        .name         = "Seaquest (1983) (Activision) (8K)",
    },{
        .md5          = "0277c449fae63f6f1c8f94dedfcf0058",
        .name         = "Laser Demo (B. Watson)",
    },{
        .md5          = "027a59a575b78860aed780b2ae7d001d",
        .manufacturer = "CCE",
        .name         = "Pressure Cooker (CCE)",
    },{
        .md5          = "028024fb8e5e5f18ea586652f9799c96",
        .manufacturer = "Coleco - Woodside Design Associates, Steve 'Jessica Stevens' Kitchen",
        .model        = "2468",
        .name         = "Carnival (1982) (Coleco)",
    },{
        .md5          = "02811151906e477d47c135db5b1699c6",
        .name         = "FlickerSort Demo (Updated) (20-04-2002) (Manuel Rotschkar)",
    },{
        .md5          = "02a5fc90a0d183f870e8eebac1f16591",
        .manufacturer = "HES",
        .model        = "771-422",
        .name         = "2 Pak Special - Star Warrior, Frogger (1990) (HES) (PAL)",
    },{
        .md5          = "02ab2c47bc21e7feafa015f90d7df776",
        .manufacturer = "Atari",
        .model        = "MA017600",
        .name         = "Diagnostic Test Cartridge 2.6 (1982) (Atari) (Prototype)",
    },{
        .md5          = "02b71d3860126d9de21073d237e502db",
        .manufacturer = "Fotomania",
        .name         = "Cosmic Ark (Fotomania)",
    },{
        .md5          = "02ced7ea2b7cb509748db6bfa227ebec",
        .manufacturer = "Parker Brothers, Ed English, David Lamkins",
        .model        = "931502",
        .name         = "Frogger (1982) (Parker Bros) (PAL)",
    },{
        .md5          = "02cee0b140d2f1a1efcfb1d482a5c392",
        .manufacturer = "Atari, Ed Logg, Carol Shaw - Sears",
        .model        = "CX2639 - 49-75162",
        .name         = "Othello (1981) (Atari) (4K)",
    },{
        .md5          = "02dcba28c614fec7ca25955327128abb",
        .manufacturer = "Andrew Wallace",
        .name         = "Laseresal 2002 (PAL) (PD) [a]",
    },{
        .md5          = "02e3f4ba156fb578bef7d7a0bf3400c1",
        .name         = "Booster (Junkosoft) (PD)",
    },{
        .md5          = "033e21521e0bf4e54e8816873943406d",
        .manufacturer = "20th Century Fox Video Games - Sirius Software, Dan Thompson",
        .model        = "11020",
        .name         = "Earth Dies Screaming, The (1983) (20th Century Fox)",
        .note         = "The Day the Earth Stood Still",
    },{
        .md5          = "034c1434280b0f2c9f229777d790d1e1",
        .manufacturer = "Telegames",
        .model        = "5665 A016",
        .name         = "Baseball (1988) (Telegames) (PAL)",
        .note         = "AKA Super Challenge Baseball",
    },{
        .md5          = "0375f589f7da06d2d2be532e0d4d4b94",
        .name         = "Push (V0.04) (2001) (Andrew Davie)",
    },{
        .md5          = "0383dc02cb82302da3d155fd108bfe3a",
        .manufacturer = "AtariAge, Chris Spry",
        .model        = "CX26200",
        .name         = "Princess Rescue (2013) (Sprybug) (PAL60)",
        .note         = "Compatible with Genesis controller",
        .left         = "JOYSTICK",
        .phosphor     = 1,
    },{
        .md5          = "038e1e79c3d4410defde4bfe0b99cc32",
        .manufacturer = "Atari, Tod Frye, Gary Shannon",
        .name         = "Aquaventure (08-12-1983) (Atari) (Prototype)",
        .note         = "AKA Sea Sentinel",
    },{
        .md5          = "039cf18b459d33b8a8fca31d06c4c244",
        .name         = "Demo Image Series #0 (12-02-2003) (Andrew Davie)",
    },{
        .md5          = "03b1051c9374678363c899914412cfc5",
        .name         = "Incoming (30-10-2002) (Ben Larson) (PD)",
    },{
        .md5          = "03c3f7ba4585e349dd12bfa7b34b7729",
        .manufacturer = "SEGA, Jeff Lorenz",
        .model        = "004-01",
        .name         = "Star Trek - Strategic Operations Simulator (1983) (SEGA)",
        .phosphor     = 1,
    },{
        .md5          = "03fbcee0bc80e31f27254aea3d920510",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Trick Shot (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "03ff9e8a7af437f16447fe88cea3226c",
        .manufacturer = "Bomb - Onbase",
        .model        = "CA285",
        .name         = "Wall-Defender (1983) (Bomb)",
        .note         = "AKA Wall Break",
    },{
        .md5          = "04014d563b094e79ac8974366f616308",
        .manufacturer = "Atari, Andrew Fuchs, Courtney Granner, Jeffrey Gusman, Mark R. Hahn",
        .model        = "CX2690",
        .name         = "Pengo (1984) (Atari)",
    },{
        .md5          = "041b5e56bbc650db574bd8db3fae2696",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Thrust (V1.0) (2000) (Thomas Jentzsch)",
    },{
        .md5          = "043f165f384fbea3ea89393597951512",
        .manufacturer = "Spectravision - Spectravideo",
        .model        = "SA-202",
        .name         = "Planet Patrol (1982) (Spectravision)",
    },{
        .md5          = "0443cfa9872cdb49069186413275fa21",
        .manufacturer = "M Network - INTV, Patricia Lewis Du Long, Ron Surratt",
        .model        = "MT4518",
        .name         = "BurgerTime (1983) (M Network)",
    },{
        .md5          = "045035f995272eb2deb8820111745a07",
        .manufacturer = "Arcadia Corporation, Steve Mundry, Scott Nelson",
        .model        = "AR-4401",
        .name         = "Survival Island (1983) (Arcadia)",
        .note         = "AKA Jungle Raid",
    },{
        .md5          = "047ac3b9faea64522b7a23c4465a7aa8",
        .name         = "Defender (Unknown) (PAL)",
    },{
        .md5          = "04856e3006a4f5f7b4638da71dad3d88",
        .manufacturer = "Atari, Douglas Neubauer",
        .model        = "CX26176",
        .name         = "Radar Lock (1989) (Atari) (PAL)",
        .note         = "AKA Dog Fight",
    },{
        .md5          = "049626cbfb1a5f7a5dc885a0c4bb758e",
        .name         = "MegaMania (Unknown) (PAL) [a]",
    },{
        .md5          = "04b488d4eef622d022a0021375e7e339",
        .manufacturer = "Home Vision - Gem International Corp. - VDI",
        .model        = "VCS83107",
        .name         = "Tennis (1983) (Home Vision) (PAL) (4K)",
    },{
        .md5          = "04cf9e6898007024622ed6a0b295961f",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Tennis (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "04dfb4acac1d0909e4c360fd2ac04480",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Jammed (2001) (XYPE)",
    },{
        .md5          = "04e737c9d53cd84bfd5ee679954e4706",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Checkers (Jone Yuan) (4K)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "04fccc7735155a6c1373d453b110c640",
        .manufacturer = "HES - Imagineering, David Lubar",
        .model        = "535",
        .name         = "My Golf (1990) (HES) (PAL)",
    },{
        .md5          = "0519f395d5f7d76be813b834aa51c0be",
        .manufacturer = "Atari, Ian Shepard",
        .model        = "CX2604",
        .name         = "Space War (1978) (Atari) (PAL) (4K)",
    },{
        .md5          = "0546f4e6b946f38956799dd00caab3b1",
        .manufacturer = "Thomas Jentzsch",
        .name         = "My Golf (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "056f5d886a4e7e6fdd83650554997d0d",
        .manufacturer = "Parker Brothers, Ed Temple",
        .model        = "931504",
        .name         = "Amidar (1982) (Parker Bros) (PAL)",
    },{
        .md5          = "056ff67dd9715fafa91fb8b0ddcc4a46",
        .name         = "Frisco (Unknown) (PAL) (Hack)",
    },{
        .md5          = "05824fcbe615dbca836d061a140a50e0",
        .manufacturer = "Jeffry Johnston",
        .name         = "Radial Pong - Version 9 (Jeffry Johnston) (PD)",
    },{
        .md5          = "05aedf04803c43eb5e09dfd098d3fd01",
        .name         = "Keystone Kapers (Unknown) (PAL)",
    },{
        .md5          = "05aff8f626ef870432ae3b3d9d5aa301",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AG-019",
        .name         = "Sky Jinks (1982) (Activision) (16K)",
    },{
        .md5          = "05b45ba09c05befa75ac70476829eda0",
        .manufacturer = "Parker Brothers, Rex Bradford",
        .model        = "931507",
        .name         = "Star Wars - Jedi Arena (1983) (Parker Bros) (PAL)",
        .note         = "Uses the Paddle Controllers (swapped)",
        .swapPaddles  = 1,
    },{
        .md5          = "05c60458ec69e7fe8b1be973852d84f1",
        .name         = "Test (1996) (J.V. Matthews) (PD)",
    },{
        .md5          = "05c765a63e61882abd1c2d627b652225",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Challenge of... Nexar, The - Amiga Mouse Hack v1.1 (NTSC) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "05ccf96247af12eef59698f1a060a54f",
        .manufacturer = "Otto Versand",
        .model        = "600273",
        .name         = "King Arthur (1983) (Otto Versand) (PAL)",
        .note         = "AKA Dragonfire (Double-Game Package)",
        .phosphor     = 1,
    },{
        .md5          = "05d61b925d3d2474bab83f0a79bb5df1",
        .manufacturer = "Eckhard Stolberg",
        .name         = "Cosmic Ark Stars (1997) (Eckhard Stolberg)",
    },{
        .md5          = "05eb4347f0ec8f4783983ca35ffd8d1b",
        .name         = "Qb (2.06) (Retroactive) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "05ebd183ea854c0a1b56c218246fbbae",
        .manufacturer = "Atari, Dan Hitchens",
        .model        = "CX2656",
        .name         = "SwordQuest - EarthWorld (1982) (Atari) [a]",
    },{
        .md5          = "05f11fb2e45c4e47424d3cb25414d278",
        .name         = "Boring (NTSC) (Andrew Davie)",
    },{
        .md5          = "060c865c782debb047e6fd101c8923fc",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Freeway Rabbit (32 in 1) (1988) (Atari) (PAL) (4K)",
        .note         = "AKA Freeway",
    },{
        .md5          = "0614ed51acd027d531e7c85c4f435292",
        .name         = "Narnia (Glenn Saunders) (PD)",
    },{
        .md5          = "0619e1c3286bbfbace040b8c3ec5add2",
        .manufacturer = "Omegamatrix",
        .name         = "Millipede (Atari Trak-Ball) v6.5 (Omegamatrix)",
        .note         = "Uses Atari Trak-Ball Controller",
        .format       = "PAL60",
    },{
        .md5          = "0651216c4a4a9c9ac5ada3013a317c72",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Fishing Derby (Jone Yuan) (4K) (Hack)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "0653285db216755085bd025b93ea6a25",
        .manufacturer = "AtariAge, Chris Walton & Thomas Jentzsch",
        .name         = "Star Castle Arcade (2014) (Chris Walton, Thomas Jentzsch) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "06742cf522f23797157f215a1dc8a1a9",
        .name         = "Healthbars (PD)",
    },{
        .md5          = "0685bd0bcb975ceef7041749a5454a48",
        .manufacturer = "Piero Cavina",
        .name         = "11 Sprite Demo (Piero Cavina) (PD)",
    },{
        .md5          = "069c17beb1e8e0557adb8539fdcf6cba",
        .name         = "Phantom II & Pirate (PAL60)",
    },{
        .md5          = "06b0194ce992584c365278e0d7323279",
        .manufacturer = "Activision",
        .name         = "Unknown Activision Game #2 (Prototype) (PAL)",
    },{
        .md5          = "06b6c5031b8353f3a424a5b86b8fe409",
        .manufacturer = "Activision, Mike Lorenzen - Ariola",
        .model        = "EAX-023 - 711 023-720",
        .name         = "Oink! (1983) (Activision) (PAL)",
        .note         = "AKA Das Schweinchen und der Wolf",
    },{
        .md5          = "06cfd57f0559f38b9293adae9128ff88",
        .manufacturer = "Telegames",
        .model        = "4317 A009",
        .name         = "Adventures on GX-12 (1988) (Telegames) (PAL)",
        .note         = "AKA Adventures of Tron",
    },{
        .md5          = "06d2f7674cea977607f74c464ce600a2",
        .manufacturer = "CBS Electronics, Alex Nevelson",
        .model        = "4L 2737 0000",
        .name         = "Omega Race (1983) (CBS Electronics) (Prototype)",
        .left         = "BOOSTERGRIP",
    },{
        .md5          = "06db908011065e5ebb37f4e253c2a0b0",
        .name         = "Gopher (Unknown) (PAL)",
    },{
        .md5          = "06e5dc181a8eda1c31cc7c581c68b6ef",
        .name         = "Tac-Scan (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "071f84d10b343c7c05ce3e32af631687",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-019",
        .name         = "Curtiss (1983) (Rainbow Vision) (PAL)",
        .note         = "AKA Atlantis",
    },{
        .md5          = "072a6ea2181ca0df88ac0dedc67b239d",
        .name         = "Multiple Missiles Demo (19-12-2002) (Christopher Tumber)",
    },{
        .md5          = "073cb76b006af034fd150be3f5e0e7e6",
        .name         = "Mobile 48 Sprite Kernel (Bug Fixed) (10-01-2003) (Eric Ball)",
    },{
        .md5          = "073d7aff37b7601431e4f742c36c0dc1",
        .name         = "Bermuda (Unknown) (PAL)",
        .note         = "AKA River Raid",
    },{
        .md5          = "074ec425ec20579e64a7ded592155d48",
        .manufacturer = "Atari - Sculptured Software, Steve Aguirre",
        .model        = "CX26162",
        .name         = "Fatal Run (Ultimate Driving) (1991) (Atari) (PAL)",
    },{
        .md5          = "075069ad80cde15eca69e3c98bd66714",
        .manufacturer = "CCE",
        .model        = "C-803",
        .name         = "Bobby Is Going Home (1983) (CCE)",
        .note         = "AKA Bobby Vai Para Casa",
    },{
        .md5          = "0751f342ee4cf28f2c9a6e8467c901be",
        .manufacturer = "Atari, Mimi Nyden, Joseph Tung",
        .model        = "CX26152",
        .name         = "Super Baseball (1988) (Atari) (PAL)",
    },{
        .md5          = "07973be3ecfd55235bf59aa56bdef28c",
        .manufacturer = "Suntek",
        .model        = "SS-036",
        .name         = "Criminal Pursuit (1983) (Suntek) (PAL)",
        .note         = "AKA A Mysterious Thief",
        .phosphor     = 1,
    },{
        .md5          = "079fe9103515d15bc108577e234a484d",
        .name         = "Multi Demo 5.5 (Bob Colbert) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "07a3af1e18b63765b6807876366f5e8a",
        .manufacturer = "Joe Grand",
        .name         = "SCSIcide Pre-release 2 (Joe Grand)",
    },{
        .md5          = "07c76f2d88552d20ad2c0ed7aef406c6",
        .manufacturer = "Cody Pittman",
        .name         = "Blob (Cody Pittman) (Hack)",
        .note         = "Hack of Halloween",
    },{
        .md5          = "07f42847a79e4f5ae55cc03304b18c25",
        .manufacturer = "Zellers",
        .name         = "Sea Hawk (Zellers)",
        .note         = "AKA Seahawk",
    },{
        .md5          = "07f5004d26ea2b776169bbfc41cc05a8",
        .name         = "Football (Unknown) (PAL) (4K)",
    },{
        .md5          = "07f84db31e97ef8d08dc9fa8a5250755",
        .manufacturer = "Supergame",
        .name         = "Enduro (1984) (Supergame)",
    },{
        .md5          = "07f91e33e76f53bb9d2731fd5d8a35a5",
        .manufacturer = "Atari",
        .model        = "CX2632",
        .name         = "Space Invaders (1978) (Atari) [t1]",
    },{
        .md5          = "0805366f1b165a64b6d4df20d2c39d25",
        .manufacturer = "Atari, Dan Hitchens",
        .model        = "CX2650",
        .name         = "Berzerk (1982) (Atari) (PAL)",
    },{
        .md5          = "08188785e2b8300983529946dbeff4d2",
        .manufacturer = "Atari, Carla Meninsky, Ed Riddle - Sears",
        .model        = "CX2611 - 99821, 49-75149",
        .name         = "Indy 500 (1977) (Atari) (4K)",
        .note         = "Uses the Driving Controllers",
        .left         = "DRIVING",
        .right        = "DRIVING",
    },{
        .md5          = "081e2c114c9c20b61acf25fc95c71bf4",
        .manufacturer = "Parker Brothers, Ed English, David Lamkins",
        .model        = "PB5300",
        .name         = "Frogger (1982) (Parker Bros)",
    },{
        .md5          = "082fdc8bd47fef01482ce5883c4ffdb8",
        .manufacturer = "Charles Morgan",
        .name         = "Tanks DX (Charles Morgan) (Hack)",
        .note         = "Hack of Tanks But No Tanks",
    },{
        .md5          = "0832fb2ee654bf9382bc57d2b16d2ffc",
        .manufacturer = "Apollo - Games by Apollo, Ed Salvo",
        .model        = "AP-1001",
        .name         = "Skeet Shoot (1981) (Apollo) (PAL)",
    },{
        .md5          = "083e7cae41a874b2f9b61736c37d2ffe",
        .manufacturer = "Imagic, Rob Fulop, Bob Smith",
        .model        = "720106-2A, IA3600P, EIX-009-04I",
        .name         = "Riddle of the Sphinx (1982) (Imagic) (PAL)",
    },{
        .md5          = "085322bae40d904f53bdcc56df0593fc",
        .manufacturer = "Parker Brothers, Dave Engman, Dawn Stockbridge",
        .model        = "PB5340",
        .name         = "Tutankham (1983) (Parker Bros)",
    },{
        .md5          = "0856f202b18cd46e44fd1dc3b42e9bfb",
        .name         = "Frame Counter 1 (2001) (Jake Patterson) (PD)",
    },{
        .md5          = "0866e22f6f56f92ea1a14c8d8d01d29c",
        .manufacturer = "Androbot - Western Technologies, Michael Case, Lenny Carlson",
        .name         = "AndroMan on the Moon (1984) (Western Tech) (Prototype)",
    },{
        .md5          = "0891252ee4e307689febccf3cfd8a8ab",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Atari Trak-Ball Hack v1.4 (PAL60) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "0894aa7be77521f9df562be8d9555fe6",
        .manufacturer = "CBS Electronics, Dan Kitchen, Garry Kitchen",
        .model        = "4L1700, 4L1701, 4L1702, 4L1802, 4L2274",
        .name         = "Donkey Kong (1982) (CBS Electronics) (PAL) [a2]",
    },{
        .md5          = "08989fa4ff537f5dbd611aff4019521a",
        .manufacturer = "Atari, Gary Palmer",
        .model        = "CX26163P",
        .name         = "Fun with Numbers (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "08bd4c1dcc843f6a0b563d9fd80b3b11",
        .manufacturer = "Quelle",
        .model        = "343.273 9",
        .name         = "Phantompanzer II (1983) (Quelle) (PAL)",
        .note         = "AKA Thunderground",
    },{
        .md5          = "08bf437d012db07b05ff57a0c745c49e",
        .manufacturer = "Arcadia Corporation, Steve Hales, Stephen H. Landrum",
        .model        = "4 AR-4102",
        .name         = "Meteoroids (1982) (Arcadia) (Prototype)",
        .note         = "Suicide Mission Beta",
        .phosphor     = 1,
    },{
        .md5          = "08d1b6d75206edb999252caf542a2c7f",
        .manufacturer = "Larry Petit",
        .name         = "Super Home Run (2003) (Larry Petit) (Hack)",
        .note         = "Hack of Home Run",
    },{
        .md5          = "08d60a58a691c7f690162850302dc0e1",
        .name         = "Poker Squares (V0.27) (PAL) (2001) (B. Watson)",
    },{
        .md5          = "08e5960bb52d9a3e2c9954677b5e4472",
        .manufacturer = "Atari - CCW, Christopher H. Omarzu, Preston Stuart, Bruce Williams",
        .model        = "CX26101",
        .name         = "Oscar's Trash Race (10-20-1982) (Atari) (Prototype)",
        .note         = "Uses the Keyboard Controllers",
    },{
        .md5          = "08ea2fdaa22e5802c839ee7dfb0483dc",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Challenge of... Nexar, The - Atari Trak-Ball Hack v1.2 (PAL60) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "08f4dc6f118f7c98e2406c180c08e78e",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4302",
        .name         = "Party Mix - Tug of War (2 of 3) (1983) (Arcadia) (PAL)",
        .note         = "Uses Paddle Controllers",
    },{
        .md5          = "08f853e8e01e711919e734d85349220d",
        .manufacturer = "Atari, Jerome Domurat, Michael Sierchio",
        .model        = "CX2667",
        .name         = "RealSports Soccer (1983) (Atari)",
    },{
        .md5          = "0906c6e0e4bda9c10cfa4c5fc64d2f4b",
        .manufacturer = "Retroactive",
        .name         = "Qb (V0.12) (NTSC) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "090f0a7ef8a3f885048d213faa59b2f8",
        .manufacturer = "Carrere Video - Western Technologies, John Hall - Teldec - Prism",
        .model        = "USC1012",
        .name         = "M.A.D. (1983) (Carrere Video) (PAL)",
    },{
        .md5          = "09274c3fc1c43bf1e362fda436651fd8",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Acid Drop (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "09388bf390cd9a86dc0849697b96c7dc",
        .manufacturer = "Absolute Entertainment, Alex DeMeo",
        .model        = "AG-045-04, AK-045-04",
        .name         = "Pete Rose Baseball (1988) (Absolute)",
    },{
        .md5          = "0945081a6bd00345ff3d58eb7a07330a",
        .name         = "Stampede (Unknown) (PAL) (4K)",
    },{
        .md5          = "0956285e24a18efa10c68a33846ca84d",
        .manufacturer = "Dismac",
        .name         = "Viagem Espacial (Dismac)",
        .note         = "AKA Star Voyager",
    },{
        .md5          = "0963aa9f7f6cf5a36ff700001583624e",
        .manufacturer = "Franklin Cruz",
        .name         = "Space Invaders 2 (Hack) [o1]",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "096649575e451508006b17e0353259a5",
        .manufacturer = "Justin J. Scott",
        .name         = "Yar Vs. Yar (2002) (Justin J. Scott) (Hack)",
        .note         = "Hack of Yars' Revenge",
        .phosphor     = 1,
    },{
        .md5          = "097074f24cde141fe6a0f26a10333265",
        .name         = "Marble Craze (V0.90) (Paul Slocum)",
    },{
        .md5          = "097936b07e0e0117b9026ae6835eb168",
        .manufacturer = "Imagic, Dennis Koble",
        .model        = "720100-2B, IA3000P",
        .name         = "Trick Shot (1982) (Imagic) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "09abfe9a312ce7c9f661582fdf12eab6",
        .manufacturer = "Atari, Douglas Neubauer",
        .model        = "CX26154",
        .name         = "Super Football (1988) (Atari)",
    },{
        .md5          = "09e1ecf9bd2a3030d5670dba7a65e78d",
        .manufacturer = "Atari, James Andreasen",
        .model        = "CX2654",
        .name         = "Haunted House (1982) (Atari) (PAL)",
    },{
        .md5          = "09e9ba0762fd0c3cf3c2e072cff79cac",
        .manufacturer = "Parker Brothers, Wilfredo Aguilar, Michael Becker, Neil McKenzie, Bob Smith, Brad Stewart",
        .model        = "PB5540",
        .name         = "Star Wars - The Arcade Game (1984) (Parker Bros) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "09f89bbfa2ab00f1964d200e12d7ced0",
        .manufacturer = "Atari",
        .model        = "MA017600",
        .name         = "Diagnostic Test Cartridge 2.6 (1982) (Atari) (Prototype) (4K)",
    },{
        .md5          = "0a1b98937911d621b004b1617446d124",
        .name         = "Hangman Pac-Man Biglist1 (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "0a981c03204ac2b278ba392674682560",
        .manufacturer = "Atari, Bob Whitehead - Sears",
        .model        = "CX2651 - 99805, 49-75602",
        .name         = "Blackjack (1977) (Atari)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXIS",
    },{
        .md5          = "0aa208060d7c140f20571e3341f5a3f8",
        .manufacturer = "U.S. Games Corporation - Western Technologies,  Jeff Corsiglia, Paul Allen Newell, Tom Sloper",
        .model        = "VC1009",
        .name         = "Towering Inferno (1982) (U.S. Games)",
        .note         = "Uses the Joystick Controllers (swapped)",
        .swapPorts    = 1,
        .phosphor     = 1,
    },{
        .md5          = "0abf64ca504a116adca80f77f85e00fb",
        .name         = "Cube Conquest (Billy Eno) (PD)",
    },{
        .md5          = "0ac0d491763153fac75f5337ce32a9d6",
        .name         = "SPAM Image Demo (PD)",
    },{
        .md5          = "0acaf71e60b89f6b6eab63db6ab84510",
        .name         = "This Planet Sucks (Greg Troutman) [a2]",
    },{
        .md5          = "0aceb7c3bd13fe048b77a1928ed4267d",
        .manufacturer = "Imagic, Bob Smith",
        .model        = "720102-2B, IA3201P, EIX-011-04I",
        .name         = "Star Voyager (1982) (Imagic) (PAL)",
    },{
        .md5          = "0ad9a358e361256b94f3fb4f2fa5a3b1",
        .manufacturer = "Atari, Carol Shaw, Nick 'Sandy Maiwald' Turner - Sears",
        .model        = "CX2608 - 49-75165",
        .name         = "Super Breakout (1982 - 1981) (Atari) [a]",
        .note         = "Uses the Paddle Controllers (left only)",
    },{
        .md5          = "0adb21206de92e8aec5ef295805ebb90",
        .name         = "Solaris (Genesis)",
        .note         = "Genesis controller (C switches to map mode)",
    },{
        .md5          = "0ae3497e731ca0bf6a77b23441d9d9f9",
        .name         = "Analog Clock (V0.0) (20-01-2003) (Andrew Davie)",
    },{
        .md5          = "0af51ceb4aecc7a8fc89781ac44a1973",
        .manufacturer = "Barry Laws Jr.",
        .name         = "Face Invaders Deluxe (Barry Laws Jr.) (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "0afe6ae18966795b89314c3797dd2b1e",
        .manufacturer = "Atari - GCC, Mark Ackerman, Noellie Alito",
        .model        = "CX2692, CX2692P",
        .name         = "Moon Patrol (1983) (Atari) (PAL) [a]",
    },{
        .md5          = "0b01909ba84512fdaf224d3c3fd0cf8d",
        .name         = "Revenge of the Apes (Hack)",
        .note         = "Hack of Planet of the Apes",
    },{
        .md5          = "0b1056f1091cfdc5eb0e2301f47ac6c3",
        .manufacturer = "Tigervision - Software Electronics Corp., Karl T. Olinger - Teldec",
        .model        = "7-001 - 3.60001 VE",
        .name         = "King Kong (1982) (Tigervision) (PAL) [a]",
    },{
        .md5          = "0b170a67e97f0c3fd908e7529a218ae9",
        .name         = "Cosmic Swarm (Unknown)",
    },{
        .md5          = "0b17ed42984000da8b727ca46143f87a",
        .manufacturer = "Atari - CCW, Christopher H. Omarzu",
        .model        = "CX26104",
        .name         = "Big Bird's Egg Catch (05-17-1983) (Atari) (Prototype)",
        .note         = "Uses the Keyboard Controller",
        .left         = "KEYBOARD",
    },{
        .md5          = "0b24658714f8dff110a693a2052cc207",
        .manufacturer = "CCE",
        .model        = "C-815",
        .name         = "Seaquest (1983) (CCE)",
    },{
        .md5          = "0b33252b680b65001e91a411e56e72e9",
        .manufacturer = "CCE",
        .model        = "C-832",
        .name         = "Atlantis (1983) (CCE) [a]",
    },{
        .md5          = "0b4e793c9425175498f5a65a3e960086",
        .manufacturer = "CCE",
        .name         = "Kung Fu Master (CCE)",
    },{
        .md5          = "0b55399cf640a2a00ba72dd155a0c140",
        .manufacturer = "Imagic, Wilfredo Aguilar, Michael Becker, Rob Fulop",
        .model        = "720111-1A, 03205",
        .name         = "Fathom (1983) (Imagic)",
        .note         = "AKA Scuba",
        .phosphor     = 1,
    },{
        .md5          = "0b577e63b0c64f9779f315dca8967587",
        .manufacturer = "Videospielkassette - Ariola",
        .model        = "PGP236",
        .name         = "Raketen-Angriff (Ariola) (PAL)",
        .note         = "AKA Missile Control",
    },{
        .md5          = "0b8d3002d8f744a753ba434a4d39249a",
        .manufacturer = "Sears Tele-Games, Robert Zdybel",
        .model        = "CX2619 - 49-75159",
        .name         = "Stellar Track (1981) (Sears)",
        .note         = "AKA Stella Trak",
        .phosphor     = 1,
    },{
        .md5          = "0bf19e40d5cd8aa5afb33b16569313e6",
        .manufacturer = "Atari, Jerome Domurat, Andrew Fuchs, Dave Staugas, Robert Vieira",
        .model        = "CX26118",
        .name         = "Millipede (01-04-1984) (Atari) (Prototype)",
    },{
        .md5          = "0bf1e354304f46c0caf8fc0f6f5e9525",
        .manufacturer = "Arcadia Corporation, Stephen Harland Landrum",
        .model        = "AR-4105",
        .name         = "Official Frogger (1983) (Arcadia) [a]",
    },{
        .md5          = "0bfabf1e98bdb180643f35f2165995d0",
        .manufacturer = "Atari, Bob Whitehead - Sears",
        .model        = "CX2623 - 6-99819, 49-75108, 49-75125",
        .name         = "Home Run (1978) (Atari)",
        .swapPorts    = 1,
    },{
        .md5          = "0c0392db94a20e4d006d885abbe60d8e",
        .name         = "Dodge Demo 3 (PD)",
    },{
        .md5          = "0c336f83b0e6e3bc86c77f368448e77b",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Circus Atari (32 in 1) (BitCorp) (Hack)",
        .left         = "JOYSTICK",
        .right        = "JOYSTICK",
    },{
        .md5          = "0c35806ff0019a270a7acae68de89d28",
        .manufacturer = "Froggo",
        .model        = "FG1003",
        .name         = "Task Force (1987) (Froggo)",
        .note         = "AKA Gangster Alley",
    },{
        .md5          = "0c48e820301251fbb6bcdc89bd3555d9",
        .manufacturer = "Atari, Bill Aspromonte, Andrew Fuchs",
        .model        = "CX26120",
        .name         = "Stargate (1984) (Atari)",
    },{
        .md5          = "0c54811cf3b1f1573c9164d5f19eca65",
        .manufacturer = "Activision, David Crane - Ariola",
        .model        = "EAG-001, PAG-001, EAG-001-04B, EAG-001-04I - 711 001-715",
        .name         = "Dragster (1980) (Activision) (PAL)",
        .note         = "AKA Dragster Rennen, Drag Strip",
    },{
        .md5          = "0c72cc3a6658c1abd4b735ef55fa72e4",
        .manufacturer = "Dion Olsthoorn",
        .model        = "v1.3",
        .name         = "Amoeba Jump (2018) (Dionoid) (PAL60)",
    },{
        .md5          = "0c7926d660f903a2d6910c254660c32c",
        .manufacturer = "Atari, Larry Kaplan",
        .model        = "CX2602, CX2602P",
        .name         = "Air-Sea Battle (1977) (Atari) (PAL)",
        .note         = "AKA Anti-Aircraft",
    },{
        .md5          = "0c7bd935d9a7f2522155e48315f44fa0",
        .manufacturer = "Carrere Video - Western Technologies, Jeff Corsiglia, Paul Allen Newell, Tom Sloper - Teldec - Prism",
        .model        = "USC1009",
        .name         = "Infernal Tower (1983) (Carrere Video) (PAL)",
        .note         = "AKA Towering Inferno",
        .swapPorts    = 1,
        .phosphor     = 1,
    },{
        .md5          = "0c80751f6f7a3b370cc9e9f39ad533a7",
        .manufacturer = "Atari, Carla Meninsky",
        .model        = "CX2610",
        .name         = "Warlords (1981) (Atari) (PAL)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "0cb7af80fd0ddef84844481d85e5d29b",
        .name         = "Mr. Pac-Man (El Destructo)",
    },{
        .md5          = "0cc8224ff1edfe458e8629e9e5fe3f5b",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Trick 12 (2001) (Thomas Jentzsch)",
    },{
        .md5          = "0cdd9cc692e8b04ba8eb31fc31d72e5e",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Wing War (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "0cebb0bb45a856b23f56d21ce7d1bc34",
        .manufacturer = "20th Century Fox Video Games, Bill Aspromonte",
        .model        = "11131",
        .name         = "Crash Dive (1983) (20th Century Fox) (PAL)",
    },{
        .md5          = "0cec9e46a25d338bf595a29aa2606516",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Challenge of... Nexar, The - Atari Mouse Hack v1.1 (PAL60) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "0cfdd2f3b243cac21f38a0f09f54bead",
        .name         = "Overhead Adventure Demo 4 (PD)",
    },{
        .md5          = "0d07d2c1be1a5eaaea235a533bcda781",
        .name         = "Scrolling Playfield 1 (Junkosoft) (PD)",
    },{
        .md5          = "0d08558f34a47e4eaa39d01c8efb81f0",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Control - Atari Mouse Hack v1.15 (NTSC) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "0d09cff0d28033c02c3290edfc3a5cea",
        .manufacturer = "Atari, Jerome Domurat, Steve Woita",
        .model        = "CX2699",
        .name         = "Taz (1983) (Atari) (Prototype)",
    },{
        .md5          = "0d1b3abf681a2fc9a6aa31a9b0e8b445",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Laser Blast (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "0d27c7f5db349b592f70f68daf5e8f3b",
        .name         = "Space Instigators (21-10-2002) (Christopher Tumber)",
    },{
        .md5          = "0d35618b6d76ddd46d2626e9e3e40db5",
        .name         = "X-Doom V.26 (PD)",
    },{
        .md5          = "0d5af65ad3f19558e6f8e29bf2a9d0f8",
        .manufacturer = "Atari - Sculptured Software, Adam Clayton",
        .model        = "CX26151, CX26151P",
        .name         = "Dark Chambers (1989) (Atari) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "0d6b974fe58a1bdd453600401c407856",
        .manufacturer = "Atari",
        .name         = "128 in 1 Junior Console (Chip 3 or 4) (1991) (Atari) (PAL)",
        .note         = "Actually contains only 16 games, not 32",
        .type         = "16IN1",
    },{
        .md5          = "0d786a41695e5fc8cffd05a6dbb3f659",
        .name         = "Scrolling Playfield With Score (10-02-2003) (Aaron Bergstrom)",
    },{
        .md5          = "0d7e630a14856f4d52c9666040961d4d",
        .name         = "Wavy Line Test (PD)",
    },{
        .md5          = "0d90a0ee73d55539b7def24c88caa651",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AG-005, CAG-005, AG-005-04",
        .name         = "Skiing (1980) (Activision) (16K)",
    },{
        .md5          = "0db4f4150fecf77e4ce72ca4d04c052f",
        .manufacturer = "Atari, Carol Shaw - Sears",
        .model        = "CX2618 - 49-75123",
        .name         = "3-D Tic-Tac-Toe (1980) (Atari)",
    },{
        .md5          = "0dd0658ace9a31a571a9de966985a068",
        .manufacturer = "Fotomania",
        .name         = "Laser Gates (Fotomania)",
        .note         = "AKA Innerspace",
    },{
        .md5          = "0dd4c69b5f9a7ae96a7a08329496779a",
        .manufacturer = "Tigervision - Software Electronics Corp., Karl T. Olinger - Teldec",
        .model        = "7-001 - 3.60001 VE",
        .name         = "King Kong (1982) (Tigervision) (PAL)",
    },{
        .md5          = "0de53160a8b54c3aa5aed8d68c970b62",
        .manufacturer = "Quelle",
        .model        = "806.174 9",
        .name         = "Fuchs & Schweinchen Schlau (1983) (Quelle) (PAL)",
        .note         = "AKA Oink!",
    },{
        .md5          = "0dfbdadf8f1bc718e7e1bb3ccd5fef3d",
        .name         = "Mr. Pac-Man (New start tune) (El Destructo)",
    },{
        .md5          = "0e0808227ef41f6825c06f25082c2e56",
        .name         = "Candi (Hack) [a]",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "0e08cd2c5bcf11c6a7e5a009a7715b6a",
        .name         = "Boing! (PD) [a1]",
    },{
        .md5          = "0e224ea74310da4e7e2103400eb1b4bf",
        .manufacturer = "Atari, Peter C. Niday, Gary Shannon, Howard Scott Warshaw",
        .name         = "Mind Maze (10-10-1984) (Atari) (Prototype)",
    },{
        .md5          = "0e23d0ed4c33b2011ab4cc93a7619683",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Amiga Mouse Hack v1.4 (PAL60) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "0e4b2b6e014a93ef8be896823da0d4ec",
        .name         = "Skiing (Unknown) (PAL)",
    },{
        .md5          = "0e713d4e272ea7322c5b27d645f56dd0",
        .manufacturer = "Home Vision - Gem International Corp. - VDI",
        .model        = "VCS83105",
        .name         = "Panda Chase (1983) (Home Vision) (PAL)",
    },{
        .md5          = "0e7e73421606873b544e858c59dc283e",
        .manufacturer = "Digivision",
        .name         = "Super Soccer (Digivision)",
        .note         = "AKA RealSports Soccer",
        .type         = "F8",
        .phosphor     = 1,
    },{
        .md5          = "0e86470791b26292abe1c64545c47985",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4302",
        .name         = "Party Mix - Down on the Line (3 of 3) (1983) (Arcadia) (PAL)",
        .note         = "Uses Paddle Controllers",
        .left         = "PADDLES_IAXIS",
    },{
        .md5          = "0ec93f519bb769e0d9f80e61f6cc8023",
        .manufacturer = "Atari - GCC, John Allred, Mike Feinstein",
        .model        = "CX2688",
        .name         = "Jungle Hunt (02-25-1983) (Atari) (Prototype)",
    },{
        .md5          = "0ecdb07bf9b36ef18f3780ef48e6c709",
        .manufacturer = "Bit Corporation",
        .model        = "PG209",
        .name         = "Mr. Postman (1983) (BitCorp)",
    },{
        .md5          = "0eebfb60d437796d536039701ec43845",
        .manufacturer = "Fabrizio Zavagli",
        .name         = "Cakewalk (Fabrizio Zavagli)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "0eecb5f58f55de9db4eedb3a0f6b74a8",
        .manufacturer = "Xonox - Beck-Tech",
        .model        = "6210, 06002, 06004, 99002",
        .name         = "Ghost Manor (1983) (Xonox) (4K)",
    },{
        .md5          = "0ef64cdbecccb7049752a3de0b7ade14",
        .manufacturer = "Atari, Joe Decuir, Larry Caplan, Steve Mayer, Larry Wagner",
        .model        = "CX26163P",
        .name         = "Combat (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "0efc91e45f61023cda9d086a7d3c402f",
        .manufacturer = "B.J. Best (aka bjbest60)",
        .name         = "Space Cactus Canyon (2017)",
        .phosphor     = 1,
    },{
        .md5          = "0effef4a341f8eebab65621c60c48787",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Atari Trak-Ball Hack v1.3 (PAL) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "0f14c03050b35d6b1d8850b07578722d",
        .manufacturer = "Jeffry Johnston",
        .name         = "Radial Pong - Version 10 (Jeffry Johnston) (PD)",
    },{
        .md5          = "0f24ca5668b4ab5dfaf217933c505926",
        .name         = "Fantastic Voyage (Unknown) (PAL)",
    },{
        .md5          = "0f2e09c71cc216f79d22a804152ba24b",
        .manufacturer = "Bob Colbert",
        .name         = "Scroller Demo (Bob Colbert) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "0f341d1f4e144e3163d9a5fc5a662b79",
        .name         = "RUN Platform Demo (PD)",
        .phosphor     = 1,
    },{
        .md5          = "0f39fc03d579d0d93a6b729a3746843e",
        .manufacturer = "Atari, Ed Bogas, Sam Comstock, Richard Dobbis, Nick 'Sandy Maiwald' Turner",
        .model        = "CX26111",
        .name         = "Snoopy and the Red Baron (05-27-1983) (Atari) (Prototype)",
    },{
        .md5          = "0f604cd4c9d2795cf5746e8af7948064",
        .manufacturer = "Champ Games",
        .model        = "CG-02-N",
        .name         = "Conquest Of Mars (2010) (NTSC)",
        .note         = "Rev 2 release",
    },{
        .md5          = "0f643c34e40e3f1daafd9c524d3ffe64",
        .manufacturer = "Atari, Robert C. Polaro, Alan J. Murphy - Sears",
        .model        = "CX2609 - 49-75186",
        .name         = "Defender (1982) (Atari)",
    },{
        .md5          = "0f6676b05621f80c670966e2995b227a",
        .name         = "Globe Trotter Demo 1 (24-03-2003) (Weston)",
    },{
        .md5          = "0f738dc44437557624eb277ed7ad91c9",
        .name         = "Grand Prix (Unknown) (PAL)",
        .note         = "AKA Grand Prix",
    },{
        .md5          = "0f8043715d66a4bbed394ef801d99862",
        .manufacturer = "Quelle",
        .model        = "684.733 9",
        .name         = "Robin Hood (1983) (Quelle) (PAL)",
        .note         = "AKA Save Our Ship",
    },{
        .md5          = "0f95264089c99fc2a839a19872552004",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-009, AG-009-04",
        .name         = "Freeway (1981) (Activision) (8K)",
    },{
        .md5          = "0fba7d8c3520bdb681f75494e498ec36",
        .name         = "Gunfight 2600 - Final Run (Manuel Rotschkar)",
    },{
        .md5          = "0fbf618be43d4396856d4244126fe7dc",
        .manufacturer = "Quelle",
        .model        = "805.784 6",
        .name         = "Labyrinth (1983) (Quelle) (PAL)",
        .note         = "AKA Maze Craze",
    },{
        .md5          = "0fc161704c46e16f7483f92b06c1558d",
        .name         = "Spider Fighter (Unknown)",
    },{
        .md5          = "0fcff6fe3b0769ad5d0cf82814d2a6d9",
        .manufacturer = "Suntek",
        .model        = "SS-027",
        .name         = "Zoo Fun (1983) (Suntek) (PAL)",
        .note         = "AKA Pumuckl at the Zoo",
    },{
        .md5          = "0fd72a13b3b6103fc825a692c71963b4",
        .manufacturer = "Imagic, Rob Fulop",
        .model        = "720104-2A, IA3204P, EIX-008-04I",
        .name         = "Cosmic Ark (1982) (Imagic) (PAL) [selectable starfield]",
    },{
        .md5          = "0fee596b974c9d3e70b367a3671599b6",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Name This Game (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "101ab60f4000a5d13792ef0abad5f74b",
        .manufacturer = "Atari, Dave Joly, Peter C. Niday, Robert Vieira",
        .model        = "CX26109",
        .name         = "Sorcerer's Apprentice (1983) (Atari) [a]",
    },{
        .md5          = "102672bbd7e25cd79f4384dd7214c32b",
        .manufacturer = "Atari, Alan Miller - Sears",
        .model        = "CX2642 - 6-99814",
        .name         = "Hunt & Score - Memory Match (1978) (Atari)",
        .note         = "Uses Keyboard Controllers",
    },{
        .md5          = "103e9d616328969f5d7b4e0a381b25d5",
        .name         = "Playfield Illustration and Logo Demo (2001) (Jake Patterson) (PD)",
    },{
        .md5          = "103f1756d9dc0dd2b16b53ad0f0f1859",
        .manufacturer = "Home Vision, Gem International Corp.",
        .name         = "Go Go Home Monster (1983) (Home Vision) (PAL)",
        .note         = "AKA Go Go Home",
    },{
        .md5          = "104468e44898b8e9fa4a1500fde8d4cb",
        .manufacturer = "AtariAge, Chris Spry",
        .model        = "CX26200",
        .name         = "Princess Rescue (2013) (Sprybug)",
        .note         = "Compatible with Genesis controller",
        .left         = "JOYSTICK",
        .phosphor     = 1,
    },{
        .md5          = "106326c262dfd3e8eaeabd961d2a0519",
        .name         = "PAL-NTSC Detector (15-11-2002) (Christopher Tumber)[a1]",
    },{
        .md5          = "106855474c69d08c8ffa308d47337269",
        .manufacturer = "Atari - Sculptured Software, Adam Clayton",
        .model        = "CX26151",
        .name         = "Dark Chambers (1989) (Atari)",
        .phosphor     = 1,
    },{
        .md5          = "107cc025334211e6d29da0b6be46aec7",
        .manufacturer = "Atari, Bob Smith - Sears",
        .model        = "CX2648 - 49-75161",
        .name         = "Video Pinball (1981) (Atari)",
    },{
        .md5          = "1086ff69f82b68d6776634f336fb4857",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-009",
        .name         = "Bloody Human Freeway (1981) (Activision) (Prototype)",
    },{
        .md5          = "10958cd0a1a81d599005f1797ab0e51d",
        .name         = "Centipede 2k (2000) (PD) (Hack)",
        .note         = "Hack of Centipede",
    },{
        .md5          = "10a3cd14e5dcfdde6ff216a14ce7b7dd",
        .manufacturer = "Atari",
        .model        = "CX262, CX2627P",
        .name         = "Human Cannonball (1979) (Atari) (PAL)",
    },{
        .md5          = "10af8728f975aa35a99d0965de8f714c",
        .manufacturer = "Dinatronic",
        .name         = "Seaquest (Dinatronic)",
    },{
        .md5          = "10c47acca2ecd212b900ad3cf6942dbb",
        .manufacturer = "Atari - Axlon, Tod Frye - Heuristica, Agustin Ortiz Valdiviezo",
        .model        = "CX26169",
        .name         = "Shooting Arcade (03-07-1989) (Atari) (Prototype) [screen 5]",
        .note         = "Uses the Light Gun Controller (left only)",
    },{
        .md5          = "10c8cfd8c37522f11d47540ff024e5f9",
        .manufacturer = "Canal 3 - Intellivision",
        .model        = "C 3016",
        .name         = "Demon Attack (Canal 3)",
    },{
        .md5          = "10eae73a07b3da044b72473d8d366267",
        .manufacturer = "Funvision - Fund. Int'l Co.",
        .name         = "Karate (1982) (Funvision) (PAL)",
    },{
        .md5          = "10f0ecaf962aef1fc28abed870b01b65",
        .manufacturer = "Atari, Paul Donaldson",
        .name         = "Bionic Breakthrough (06-22-1984) (Atari) (Prototype)",
        .note         = "Uses MindLink Controller",
        .left         = "MINDLINK",
        .right        = "MINDLINK",
    },{
        .md5          = "10f62443f1ae087dc588a77f9e8f43e9",
        .manufacturer = "Atari, Carla Meninsky",
        .model        = "CX2637, CX2637P",
        .name         = "Dodge 'Em (1980) (Atari) (PAL) [fixed]",
    },{
        .md5          = "110ac8ecaf1b69f41bc94c59dfcb8b2d",
        .name         = "Demon Attack (Unknown)",
    },{
        .md5          = "111029770226b319524134193886a10e",
        .manufacturer = "Hozer Video Games",
        .name         = "Gunfight 2600 - One Limit Reached! (2001) (Manuel Rotschkar)",
    },{
        .md5          = "11330eaa5dd2629052fac37cfe1a0b7d",
        .manufacturer = "128 in 1 Junior Console",
        .name         = "Human Cannonball (128 in 1 Junior Console) (PAL)",
    },{
        .md5          = "113cd09c9771ac278544b7e90efe7df2",
        .manufacturer = "Atari, Ed Logg, Carol Shaw - Sears",
        .model        = "CX2639 - 49-75162",
        .name         = "Othello (1981) (Atari) [no grid markers]",
    },{
        .md5          = "114c599454d32f74c728a6e1f71012ba",
        .manufacturer = "Activision, Bob Whitehead - Ariola",
        .model        = "EAX-015, EAX-015-04I - 711 015-725",
        .name         = "Chopper Command (1982) (Activision) (PAL)",
    },{
        .md5          = "11ad7b3e15c8cb3223d5349795bef4ad",
        .manufacturer = "Omegamatrix",
        .name         = "Indy 500 Menu (Omegamatrix)",
        .note         = "Uses the Driving Controllers",
        .left         = "DRIVING",
        .right        = "DRIVING",
    },{
        .md5          = "11bcf5c752088b5aaf86d6c7a6a11e8d",
        .manufacturer = "Atari, Jerome Domurat, Andrew Fuchs, Dave Staugas, Robert Vieira",
        .model        = "CX26118",
        .name         = "Millipede (1984) (Atari) (Prototype)",
    },{
        .md5          = "11e7e0d9437ec98fa085284cf16d0eb4",
        .name         = "Bowling (Unknown) (PAL)",
    },{
        .md5          = "11f55cdbb4e059f5ca56c509c57cb510",
        .manufacturer = "Fotomania",
        .name         = "Keystone Kapers (Fotomania)",
    },{
        .md5          = "11f9532557e4c9569f4b242164006161",
        .manufacturer = "Chris Walton, Justin Hairgrove, Tony Morse",
        .name         = "Hunchy II (2005) (PAL)",
        .note         = "Homebrew",
    },{
        .md5          = "1201c18cf00d2c236f42e4d7d8c86aa1",
        .name         = "Nick Bensema Demo (Nick Bensema)",
    },{
        .md5          = "12080205f669b8e7783b976f8cf3d8bb",
        .manufacturer = "Omegamatrix",
        .name         = "Star Wars Arcade (Amiga Mouse) v4 (Omegamatrix)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "12123b534bdee79ed7563b9ad74f1cbd",
        .manufacturer = "Absolute Entertainment, Alex DeMeo",
        .model        = "AG-041-04",
        .name         = "Title Match Pro Wrestling (1987) (Absolute)",
    },{
        .md5          = "1228c01cd3c4b9c477540c5adb306d2a",
        .manufacturer = "Atari, Alan Miller",
        .model        = "CX26163P",
        .name         = "Basketball (32 in 1) (1988) (Atari) (PAL)",
        .note         = "Console ports are swapped",
        .swapPorts    = 1,
    },{
        .md5          = "1266b3fd632c981f3ef9bdbf9f86ce9a",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "EAZ-034-04, EAZ-034-04I",
        .name         = "Private Eye (1984) (Activision) (PAL)",
    },{
        .md5          = "1267e3c6ca951ff1df6f222c8f813d97",
        .name         = "Dragonfire (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "126f7f64b7b00e25dcf5e3710b4cf8b8",
        .manufacturer = "Atari - GCC",
        .model        = "CX2676",
        .name         = "Centipede (1983) (Atari) (Prototype)",
    },{
        .md5          = "1278f74ca1dfaa9122df3eca3c5bcaad",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-013",
        .name         = "Bi! Bi! (Rainbow Vision) (PAL)",
        .note         = "AKA Skindiver",
    },{
        .md5          = "1287535256bf5dff404839ac9e25c3e7",
        .manufacturer = "PacManPlus",
        .model        = "Rev 2",
        .name         = "Alien Pac-Man (PacManPlus) (Hack)",
        .note         = "Hack of Alien",
        .phosphor     = 1,
    },{
        .md5          = "12937db3d4a80da5c4452b752891252d",
        .manufacturer = "Digitel",
        .name         = "Megamania (1983) (Digitel)",
    },{
        .md5          = "12bca8305d5ab8ea51fe1cfd95d7ab0e",
        .manufacturer = "Epyx, Steven A. Baker, Tod Frye, Peter Engelbrite",
        .model        = "80561-00250",
        .name         = "Summer Games (1987) (Epyx) (PAL)",
    },{
        .md5          = "12d7e0d6b187889f8d150bf7034d1db2",
        .name         = "Poker Squares (V0.0e) (2001) (B. Watson)",
    },{
        .md5          = "130c5742cd6cbe4877704d733d5b08ca",
        .manufacturer = "Home Vision - Gem International Corp. - VDI",
        .model        = "VCS83109",
        .name         = "World End (1983) (Home Vision) (PAL)",
        .note         = "AKA The End of the World",
    },{
        .md5          = "1323c45d660f5a5b6d5ea45c6c4cbe4a",
        .manufacturer = "Canal 3 - Intellivision",
        .name         = "Enduro (Canal 3)",
    },{
        .md5          = "133456269a03e3fdae6cddd65754c50d",
        .manufacturer = "Tigervision - Software Electronics Corporation - Teldec - Prism",
        .model        = "7-006 - 3.60008 VG",
        .name         = "Springer (1983) (Tigervision) (PAL)",
    },{
        .md5          = "133a4234512e8c4e9e8c5651469d4a09",
        .manufacturer = "Atari, Andrew Fuchs, Jeffrey Gusman, Dave Jolly, Suki Lee",
        .model        = "CX26117",
        .name         = "Obelix (1984) (Atari)",
    },{
        .md5          = "133b56de011d562cbab665968bde352b",
        .manufacturer = "Activision, John Van Ryzin",
        .model        = "AG-038-04",
        .name         = "Cosmic Commuter (1984) (Activision)",
    },{
        .md5          = "1343de49c2a50d99176255f99f0d0234",
        .manufacturer = "Gray Games & AtariAge",
        .name         = "E.T. Book Cart (PAL)",
        .note         = "Charles F. Gray & Michael Rideout",
        .phosphor     = 1,
    },{
        .md5          = "13448eb5ba575e8d7b8d5b280ea6788f",
        .manufacturer = "Digivision",
        .name         = "Crackpots (Digivision)",
    },{
        .md5          = "1345e972dbe08ea3e70850902e20e1a5",
        .manufacturer = "Greg Troutman",
        .name         = "Dark Mage (rough beta) (Greg Troutman) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "1351c67b42770c1bd758c3e42f553fea",
        .manufacturer = "Digivision",
        .name         = "Keystone Kapers (Digivision)",
    },{
        .md5          = "135708b9a7dd20576c1b66ab2a41860d",
        .name         = "Hangman Man Biglist1 (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "13584411da0a8d431991035423fdc0dc",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Skiing (Jone Yuan) (4K)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "1367e41858be525710eb04d0dab53505",
        .manufacturer = "Kyle Pittman",
        .name         = "Zelda (2003) (Kyle Pittman) (Hack)",
        .note         = "Hack of Adventure",
    },{
        .md5          = "136f75c4dd02c29283752b7e5799f978",
        .manufacturer = "Atari, Dan Hitchens - Sears",
        .model        = "CX2650 - 49-75168",
        .name         = "Berzerk (1982) (Atari)",
    },{
        .md5          = "137373599e9b7bf2cf162a102eb5927f",
        .manufacturer = "AtariAge, Joe Grand",
        .name         = "Ultra SCSIcide (SCSIcide 2.0)",
        .left         = "PADDLES",
    },{
        .md5          = "13895ef15610af0d0f89d588f376b3fe",
        .manufacturer = "Tigervision, Rorke Weigandt",
        .model        = "7-005",
        .name         = "Marauder (1982) (Tigervision)",
    },{
        .md5          = "13a37cf8170a3a34ce311b89bde82032",
        .manufacturer = "Atari - GCC, Mark Ackerman, Tom Calderwood, Glenn Parker",
        .model        = "CX2684, CX2684P",
        .name         = "Galaxian (1983) (Atari) (PAL)",
    },{
        .md5          = "13a991bc9c2ff03753aeb322d3e3e2e5",
        .manufacturer = "Funvision - Fund. International Co.",
        .name         = "Galactic (Funvision) (PAL)",
        .note         = "AKA Condor Attack",
    },{
        .md5          = "13aa1f9ac4249947e4af61319d9a08f2",
        .manufacturer = "Atari - GCC",
        .model        = "CX2680, CX2680P",
        .name         = "RealSports Tennis (1983) (Atari) (PAL) [a1]",
    },{
        .md5          = "13abc32f803165c458bb086fa57195fb",
        .manufacturer = "Christian Samuel",
        .name         = "E.T. The Extra-Testical (Christian Samuel) (Hack)",
        .note         = "Hack of E.T. The Extra-Terrestrial",
    },{
        .md5          = "13ccc692f111d52fec75d83df16192e2",
        .manufacturer = "Canal 3 - Intellivision",
        .name         = "Fishing Derby (Canal 3) (4K)",
    },{
        .md5          = "13d8326bf5648db4dafce45d25e62ddd",
        .name         = "Atari Logo Demo 2 (PD)",
    },{
        .md5          = "13dfb095e519a555a5b60b7d9d7169f9",
        .name         = "Red Line Demo (PD)",
    },{
        .md5          = "140909d204abd6841c64cdad4d7765b4",
        .name         = "Moving Blue Ladder Demo (PD)",
    },{
        .md5          = "14163eb2a3ddd35576bd8527eae3b45e",
        .name         = "Multi Demo 6 (Bob Colbert) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "1423f560062c4f3c669d55891a2bcbe7",
        .name         = "M.A.S.H. (Unknown)",
    },{
        .md5          = "1428029e762797069ad795ce7c6a1a93",
        .name         = "Thunderground (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "143918368f4f4dfff90999188c0197c9",
        .name         = "Unknown Title (bin00016 (200110)) (PD)",
    },{
        .md5          = "1442d1b35a6478fba22ae7dd1fcb5634",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Thrust (V0.2) (2000) (Thomas Jentzsch)",
    },{
        .md5          = "148471144ccebd7f6aa9aa9215896533",
        .manufacturer = "Parker Brothers - JWDA, Todd Marshall",
        .model        = "PB5550",
        .name         = "Q-bert's Qubes (1984) (Parker Bros) (Prototype)",
    },{
        .md5          = "149b543c917c180a1b02d33c12415206",
        .manufacturer = "CCE",
        .model        = "C-857",
        .name         = "Superman (1983) (CCE)",
    },{
        .md5          = "14a56b493a8d9d10e94a3e100362e3a2",
        .manufacturer = "Hozer Video Games",
        .name         = "Gunfight 2600 - Early Play-kernel (2001) (Manuel Rotschkar)",
    },{
        .md5          = "14b1e30982962c72f426e2e763eb4274",
        .manufacturer = "Atari, Carol Shaw - Ralph Lauren",
        .name         = "Polo (1978) (Atari) (Prototype) (4K)",
    },{
        .md5          = "14c2548712099c220964d7f044c59fd9",
        .manufacturer = "First Star Software, Alex Leavens, Shirley Ann Russell",
        .name         = "Boing! (1983) (First Star Software)",
        .note         = "AKA Bubbles, Soap Suds, The Emphysema Game",
        .phosphor     = 1,
    },{
        .md5          = "14d365bbfaac3d20c6119591f57acca4",
        .name         = "Video Life (Unknown) (4K) (Hack)",
        .phosphor     = 1,
    },{
        .md5          = "14dbb3686dd31964332dc2ef0c55cad0",
        .name         = "Demo Image Series #15 - Three Marios (PAL) (Non-Interleave) (06-03-2003) (Andrew Davie)",
    },{
        .md5          = "151c33a71b99e6bcffb34b43c6f0ec23",
        .manufacturer = "Parker Brothers, Laura Nikolich",
        .name         = "Care Bears (1983) (Parker Bros) (Prototype)",
    },{
        .md5          = "151fa3218d8d7600114eb5bcd79c85cb",
        .manufacturer = "Atari - CCW, Christopher H. Omarzu",
        .model        = "CX26104",
        .name         = "Big Bird's Egg Catch (05-02-1983) (Atari) (Prototype)",
        .note         = "Uses the Keyboard Controller",
        .left         = "KEYBOARD",
    },{
        .md5          = "152c253478b009c275e18cd731b48561",
        .name         = "Quest (11-10-2002) (Chris Larkin)",
    },{
        .md5          = "153f40e335e5cb90f5ce02e54934ab62",
        .manufacturer = "Absolute Entertainment, Alex DeMeo",
        .model        = "EAZ-041-04I",
        .name         = "Title Match Pro Wrestling (1987) (Absolute) (PAL)",
    },{
        .md5          = "1542662f665d2ffaa77b4b897dd2e2af",
        .name         = "Starfield (V1.0) (2002) (Manuel Rotschkar)",
    },{
        .md5          = "155fa7f479dcba3b10b1494e236d6010",
        .manufacturer = "Skyworks",
        .name         = "Tomcat (2002) (Skyworks) (PAL)",
        .note         = "AKA The F-14 Flight Simulator",
    },{
        .md5          = "157356f80c709ab675961d8b8b207e20",
        .name         = "Multi-Sprite Game V2.5 (Piero Cavina) (PD)",
    },{
        .md5          = "157bddb7192754a45372be196797f284",
        .manufacturer = "Atari, Warren Robinett - Sears",
        .model        = "CX2613, 49-75154",
        .name         = "Adventure (1980) (Atari)",
    },{
        .md5          = "159e5cd6ccb968015f49aed5adbc91eb",
        .manufacturer = "Justin J. Scott",
        .name         = "Yar's Defeat (2002) (Justin J. Scott) (Hack)",
        .note         = "Hack of Yars' Revenge",
        .phosphor     = 1,
    },{
        .md5          = "15a0d59304dece2c7d0580f3ea3527f0",
        .manufacturer = "Atari, Jerome Domurat, Peter C. Niday",
        .model        = "CX26115",
        .name         = "Dumbo's Flying Circus (04-04-1983) (Atari) (Prototype)",
    },{
        .md5          = "15b498199ed0ed28057bf0dbdce9b8d8",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Jammed (V0.2) (Demo) (2001) (Thomas Jentzsch)",
    },{
        .md5          = "15b9f5e2439bfaa08874b5184261c777",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Space Invaders (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "15bcd74f2f1f2a63e1aa93e90d2c0555",
        .name         = "Incoming (22-08-2002) (Ben Larson) (PD)",
    },{
        .md5          = "15bf2ef7583bfcbbba630847a1dc5539",
        .manufacturer = "Erik Eid",
        .name         = "Euchre (Jul 15) (2002) (Eric Eid) (PD)",
    },{
        .md5          = "15c11ab6e4502b2010b18366133fc322",
        .manufacturer = "Atari - Axlon, Tod Frye - Heuristica, Agustin Ortiz Valdiviezo",
        .model        = "CX26169",
        .name         = "Shooting Arcade (09-19-1989) (Atari) (Prototype)",
        .note         = "Uses the Light Gun Controller (left only)",
    },{
        .md5          = "15dd21c2608e0d7d9f54c0d3f08cca1f",
        .manufacturer = "Data Age, J. Ray Dettling",
        .model        = "112-008",
        .name         = "Frankenstein's Monster (1983) (Data Age)",
    },{
        .md5          = "15fe28d0c8893be9223e8cb2d032e557",
        .name         = "Towering Inferno (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "1619bc27632f9148d8480cd813aa74c3",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Steeple Chase (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
        .phosphor     = 1,
    },{
        .md5          = "161ded4a85d3c78e44fffd40426f537f",
        .manufacturer = "Thomas Jentzsch",
        .name         = "JtzBall (Alpha) (Thomas Jentzsch)",
    },{
        .md5          = "16229d61d7b0c89b01853660a8da22bb",
        .name         = "spin4a50",
        .type         = "4A50",
    },{
        .md5          = "163e7e757e2dc44469123ff0e5daec5e",
        .name         = "Many Blue Bars and Text Demo 2 (PD)",
    },{
        .md5          = "169d4c7bd3a4d09e184a3b993823d048",
        .name         = "Superman (Unknown) (PAL) [a]",
    },{
        .md5          = "16baafb06c06aa475aa671f234399e05",
        .manufacturer = "Parker Brothers - Roklan, Joe Gaucher",
        .model        = "PB5080",
        .name         = "Gyruss (1983) (Parker Bros) (Prototype) [a1]",
        .phosphor     = 1,
    },{
        .md5          = "16cb43492987d2f32b423817cdaaf7c4",
        .manufacturer = "Atari, Larry Kaplan - Sears",
        .model        = "CX2602 - 99802, 6-99802, 49-75102",
        .name         = "Air-Sea Battle (1977) (Atari)",
        .note         = "AKA Target Fun (Anti-Aircraft)",
    },{
        .md5          = "16cc6d1b4ddce51c767a1ba8e5ff196c",
        .name         = "Big - Move This Demo 2 (PD)",
        .phosphor     = 1,
    },{
        .md5          = "16d69f71bf5846639be5ff16483f0498",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Golf (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "16e04823887c547dc24bc70dff693df4",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Tennis (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "16ee443c990215f61f7dd1e55a0d2256",
        .manufacturer = "Spectravideo, David Lubar",
        .model        = "SA-218, SA-218C",
        .name         = "Bumper Bash (1983) (Spectravideo) (PAL)",
        .note         = "Uses the Paddle Controllers (left only)",
        .left         = "PADDLES",
    },{
        .md5          = "16f494f20af5dc803bc35939ef924020",
        .manufacturer = "Mark De Smet",
        .name         = "Video Simon (Mark De Smet)",
    },{
        .md5          = "170e7589a48739cfb9cc782cbb0fe25a",
        .manufacturer = "M Network - INTV - APh Technological Consulting, Hal Finney",
        .model        = "MT5666",
        .name         = "Astroblast (1982) (M Network) [fixed]",
        .note         = "Can also use left joystick",
        .left         = "PADDLES",
        .swapPaddles  = 1,
    },{
        .md5          = "171cd6b55267573e6a9c2921fb720794",
        .manufacturer = "Kurt Howe",
        .name         = "Adventure 34 (Kurt Howe) (Hack)",
        .note         = "Hack of Adventure",
    },{
        .md5          = "171ebf135b13ba907f462c10d88a2c25",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Challenge of... Nexar, The - Amiga Mouse Hack v1.1 (PAL60) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "1733772165d7b886a94e2b4ed0f74ccd",
        .name         = "Boring Journey Escape (Hack)",
        .note         = "Hack of Journey - Escape",
    },{
        .md5          = "1738b2e3f25ab3eef3cecb95e1d0d957",
        .name         = "Hangman Monkey Biglist1 (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "17512d0c38f448712f49f36f9d185c4e",
        .manufacturer = "Retroactive",
        .name         = "Qb (Release Candidate #1) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "17515a4d0b7ea5029ffff7dfa8456671",
        .manufacturer = "Piero Cavina",
        .name         = "Multi-Sprite Demo V1.1 (Piero Cavina) (PD)",
    },{
        .md5          = "176d3fba7d687f2b23158098e103c34a",
        .manufacturer = "Zach Matley",
        .name         = "Combat AI (16-02-2003) (Zach Matley)",
    },{
        .md5          = "177504abd4260c4265e1338955e9fa47",
        .manufacturer = "HCC Software",
        .name         = "Pitfall! (Steroids Hack)",
        .note         = "Hack of Pitfall! (Activision)",
    },{
        .md5          = "1782929e1c214b70fb6884f77c207a55",
        .manufacturer = "Activision, David Crane",
        .model        = "AX-018, AX-018-04",
        .name         = "Pitfall! (1982) (Activision) (Prototype)",
        .note         = "Pitfall Harry's Jungle Adventure (Jungle Runner)",
    },{
        .md5          = "17ba72433dd41383065d4aa6dedb3d91",
        .name         = "SCSIcide (09-06-2001) (Joe Grand)",
    },{
        .md5          = "17badbb3f54d1fc01ee68726882f26a6",
        .manufacturer = "M Network - INTV - APh Technological Consulting, Hal Finney, Bruce Pedersen",
        .model        = "MT5659",
        .name         = "Space Attack (1982) (M Network)",
    },{
        .md5          = "17bbe288c3855c235950fea91c9504e9",
        .manufacturer = "Dismac",
        .name         = "Pega Ladrao (Dismac)",
        .note         = "AKA Keystone Kapers",
    },{
        .md5          = "17c0a63f9a680e7a61beba81692d9297",
        .manufacturer = "U.S. Games Corporation - Western Technologies, Jeff Corsiglia, David Johnson, Tom Sloper",
        .model        = "VC2004",
        .name         = "Picnic (1983) (U.S. Games)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "17d000a2882f9fdaa8b4a391ad367f00",
        .manufacturer = "Atari - GCC",
        .model        = "CX2676",
        .name         = "Centipede (1983) (Atari) (PAL)",
    },{
        .md5          = "17ee158d15e4a34f57a837bc1ce2b0ce",
        .manufacturer = "Atari - GCC, Mike Feinstein, Kevin Osborn",
        .model        = "CX2691, CX2691P",
        .name         = "Joust (1983) (Atari) (PAL) [a]",
        .phosphor     = 1,
    },{
        .md5          = "17ee23e5da931be82f733917adcb6386",
        .manufacturer = "Salu, Dennis M. Kiss",
        .model        = "460758",
        .name         = "Acid Drop (1992) (Salu) (PAL)",
    },{
        .md5          = "1802cc46b879b229272501998c5de04f",
        .manufacturer = "Atari - CCW, Christopher H. Omarzu",
        .model        = "CX26104",
        .name         = "Big Bird's Egg Catch (1983) (Atari)",
        .note         = "Uses Kids/Keyboard Controllers",
        .left         = "KEYBOARD",
        .right        = "KEYBOARD",
    },{
        .md5          = "183020a80848e06a1238a1ab74079d52",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Command (Amiga Mouse) (2002) (Thomas Jentzsch) (PAL)",
        .note         = "Uses Amiga Mouse Controller",
        .phosphor     = 1,
    },{
        .md5          = "1862fca4f98e66f363308b859b5863af",
        .manufacturer = "Atari",
        .name         = "128 in 1 Junior Console (Chip 1 of 4) (1991) (Atari) (PAL)",
        .note         = "Actually contains only 16 games, not 32",
        .type         = "16IN1",
    },{
        .md5          = "18a970bea7ac4d29707c8d5cd559d03a",
        .name         = "Bridge (Unknown) (PAL)",
    },{
        .md5          = "18b28b386abdadb3a700ac8fb68e639a",
        .manufacturer = "Manuel Polik",
        .name         = "Gunfight 2600 (Manuel Rotschkar) (PAL)",
    },{
        .md5          = "18b476a34ce5e6db2c032029873ac39b",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Atlantis (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "18b6a3e2b53596c15f64d1834ba1ed34",
        .name         = "Championship Soccer (Unknown) (PAL)",
    },{
        .md5          = "18be8981b8201638f3ed8ae92bb4c215",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Control - Amiga Mouse Hack v1.15 (PAL60) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "18bebbbd41c234f82b1717b1905e6027",
        .name         = "Space Instigators (Public Release) (02-01-2003) (Christopher Tumber)",
    },{
        .md5          = "18d26111cef66dff0c8af8cf0e117843",
        .name         = "Tunnel Demo (Cycling Colours 2) (29-03-2003) (Andrew Davie)",
    },{
        .md5          = "18dc28bc22402f21e1c9b81344b3b8c5",
        .manufacturer = "Atari - GCC, Mark Ackerman, Glenn Parker",
        .model        = "CX2684, CX2684P",
        .name         = "Galaxian (1983) (Atari) (PAL) [a1]",
    },{
        .md5          = "18ed63e3ce5bc3dd2d8bd188b807f1a2",
        .name         = "Stell-A-Sketch (Bob Colbert) (PD) [a1]",
        .phosphor     = 1,
    },{
        .md5          = "18f299edb5ba709a64c80c8c9cec24f2",
        .manufacturer = "Home Vision - Gem International Corp. - VDI",
        .model        = "VCS83111",
        .name         = "Asteroid Fire (1983) (Home Vision) (PAL)",
    },{
        .md5          = "19098c46da0640f2b5763167dea6c716",
        .manufacturer = "Andrew Wallace",
        .name         = "Laseresal 2002 (NTSC) (PD)",
    },{
        .md5          = "191449e40b0c56411c70772706f79224",
        .name         = "Multi Demo 2 (Bob Colbert) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "19162393786098d50587827588198a86",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Flag Capture (Jone Yuan) (4K)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "191ac4eec767358ee3ec3756c120423a",
        .name         = "Checkers (Unknown) (PAL)",
    },{
        .md5          = "192aa2e8c795c9e10a7913e5d41feb81",
        .manufacturer = "Atari - GCC, Jaques Hugon, Seth Lipkin",
        .model        = "CX26125",
        .name         = "Los Angeles 1984 Games (1984) (Atari) (Prototype) (PAL)",
        .note         = "AKA Track and Field (Uses Track & Field Controller)",
    },{
        .md5          = "193f060553ba0a2a2676f91d9ec0c555",
        .manufacturer = "Atari, Carol Shaw",
        .model        = "CX2636, CX2636P",
        .name         = "Video Checkers (1980) (Atari) (PAL)",
    },{
        .md5          = "1942bdb7abc75e412068330a9082b0ff",
        .manufacturer = "Atari, Omegamatrix",
        .name         = "Super Breakout Menu (2020) (PAL) (Hack)",
        .note         = "Hack of Super Breakout",
    },{
        .md5          = "1986f864e32e3e8d198b5becf3022257",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Atari Trak-Ball Hack v1.3 (PAL) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "199985cae1c0123ab1aef921daace8be",
        .name         = "Euchre (Release Candidate 2) (PAL) (01-10-2002) (Erik Eid)",
    },{
        .md5          = "199eb0b8dce1408f3f7d46411b715ca9",
        .manufacturer = "Parker Brothers, David Lamkins, Laura Nikolich",
        .model        = "PB5900",
        .name         = "Spider-Man (1982) (Parker Bros)",
    },{
        .md5          = "19a9d3f9fa1b1358fb53009444247aaf",
        .name         = "Blackjack (Unknown) (PAL) (4K)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXIS",
    },{
        .md5          = "19abaf2144b6a7b281c4112cff154904",
        .manufacturer = "Atari, Brad Stewart",
        .model        = "CX2649, CX2649P",
        .name         = "Asteroids (1981) (Atari) (PAL) [a2]",
        .phosphor     = 1,
    },{
        .md5          = "19b3b807507653516985ba95da92499d",
        .manufacturer = "Joe Gaucher",
        .name         = "VCS Draw Demo (Joe Gaucher)",
    },{
        .md5          = "19d6956ff17a959c48fcd8f4706a848d",
        .manufacturer = "PlayAround - JHM",
        .model        = "202",
        .name         = "Burning Desire (1982) (PlayAround)",
        .phosphor     = 1,
    },{
        .md5          = "19d9b5f8428947eae6f8e97c7f33bf44",
        .name         = "Fortress (Dual Version) (20-04-2003) (Christopher Tumber)",
    },{
        .md5          = "19e739c2764a5ab9ed08f9095aa2af0b",
        .manufacturer = "Atari, Andrew Fuchs, Jeffrey Gusman, Dave Jolly, Suki Lee",
        .model        = "CX26117",
        .name         = "Obelix (1984) (Atari) (PAL)",
    },{
        .md5          = "19e761e53e5ec8e9f2fceea62715ca06",
        .manufacturer = "Panda",
        .model        = "104",
        .name         = "Scuba Diver (1983) (Panda)",
        .note         = "AKA Skindiver",
    },{
        .md5          = "1a23540d91f87584a04f184304a00648",
        .name         = "Race Demo (PD)",
    },{
        .md5          = "1a613ce60fc834d4970e1e674b9196b3",
        .manufacturer = "Home Vision - Gem International Corp. - VDI",
        .model        = "VCS83135",
        .name         = "Tanks War (1983) (Home Vision) (PAL)",
        .note         = "AKA Phantom Tank",
    },{
        .md5          = "1a624e236526c4c8f31175e9c89b2a22",
        .name         = "Space Raid (Unknown) (PAL)",
        .note         = "AKA MegaMania",
    },{
        .md5          = "1a8204a2bcd793f539168773d9ad6230",
        .manufacturer = "Atari, Rob Fulop - Sears",
        .model        = "CX2638 - 49-75166",
        .name         = "Missile Command (1981) (Atari) [no initials]",
        .phosphor     = 1,
    },{
        .md5          = "1aa7344b563c597eecfbfcf8e7093c27",
        .manufacturer = "David Marli",
        .name         = "Slot Invaders (David Marli) (Hack)",
        .note         = "Hack of Slot Machine",
    },{
        .md5          = "1b0f3d7af668eeea38ddd6182d8f48fb",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Cosmic Swarm (Jone Yuan) (4K)",
        .note         = "2600 Screen Search Console",
        .phosphor     = 1,
    },{
        .md5          = "1b1daaa9aa5cded3d633bfcbeb06479c",
        .name         = "Ship Demo (V 1502) (PD)",
    },{
        .md5          = "1b22a3d79ddd79335b69c94dd9b3e44e",
        .manufacturer = "Tron",
        .name         = "Moon Patrol (Tron)",
    },{
        .md5          = "1b4b06c2a14ed3ee73b7d0fd61b6aaf5",
        .manufacturer = "Arcadia Corporation, Stephen H. Landrum",
        .model        = "AR-4400",
        .name         = "Excalibur (Dragonstomper Beta) (1982) (Arcadia) (Prototype) [a]",
    },{
        .md5          = "1b5a8da0622bffcee4c5b42aed4e0ef0",
        .manufacturer = "Akor",
        .name         = "TV Boy II (1992) (Akor)",
        .note         = "Includes 127 games",
        .left         = "JOYSTICK",
        .right        = "JOYSTICK",
    },{
        .md5          = "1b8c3c0bfb815b2a1010bba95998b66e",
        .manufacturer = "Telegames",
        .name         = "Frogs and Flies (1988) (Telegames) (PAL)",
    },{
        .md5          = "1b8d35d93697450ea26ebf7ff17bd4d1",
        .manufacturer = "Quelle - Otto Versand",
        .model        = "176.764 9 - 781644",
        .name         = "Marineflieger (1983) (Quelle) (PAL)",
        .note         = "AKA Seahawk",
    },{
        .md5          = "1bb91bae919ddbd655fa25c54ea6f532",
        .manufacturer = "Suntek",
        .model        = "SS-026",
        .name         = "Treasure Island (1983) (Suntek) (PAL)",
        .note         = "AKA Treasure Discovery",
    },{
        .md5          = "1bc2427ac9b032a52fe527c7b26ce22c",
        .manufacturer = "Intellivision Productions - M Network - APh Technological Consulting, Bruce Pedersen, Larry Zwick",
        .model        = "MT5860",
        .name         = "Sea Battle (1983) (M Network)",
        .note         = "High Seas",
    },{
        .md5          = "1bef389e3dd2d4ca4f2f60d42c932509",
        .manufacturer = "Dimax - Sinmax",
        .model        = "SM8001",
        .name         = "Space Robot (1983) (Dimax - Sinmax) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "1bf503c724001b09be79c515ecfcbd03",
        .name         = "Bumper Bash (Unknown) (PAL)",
    },{
        .md5          = "1bfae770e089fa81412d04eb299f4c3f",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Marble Craze - Atari Mouse Hack v1.0 (NTSC) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controllers",
    },{
        .md5          = "1c3f3133a3e5b023c77ecba94fd65995",
        .manufacturer = "CCE",
        .model        = "C-830",
        .name         = "Planet Patrol (1983) (CCE) [a]",
    },{
        .md5          = "1c5796d277d9e4df3f6648f7012884c4",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-012",
        .name         = "Hey! Stop! (1983) (Rainbow Vision) (PAL)",
        .note         = "AKA Keystone Kapers",
    },{
        .md5          = "1c666ba5aac19b81671357e76062989b",
        .manufacturer = "Nukey Shay, Omegamatrix",
        .name         = "Double Dragon (Genesis) (PAL60) V2",
        .note         = "Genesis controller",
    },{
        .md5          = "1c6eb740d3c485766cade566abab8208",
        .manufacturer = "Atari, Michael Kosaka, Peter C. Niday, Robert Vieira",
        .model        = "CX26110",
        .name         = "Crystal Castles (1984) (Atari)",
    },{
        .md5          = "1c85c0fc480bbd69dc301591b6ecb422",
        .manufacturer = "CCE",
        .name         = "Super Box (CCE)",
        .note         = "AKA RealSports Boxing",
    },{
        .md5          = "1c8c42d1aee5010b30e7f1992d69216e",
        .manufacturer = "PlayAround - JHM",
        .model        = "205",
        .name         = "Gigolo (1982) (PlayAround)",
        .phosphor     = 1,
    },{
        .md5          = "1cad3b56cc0e6e858554e46d08952861",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Chopper Command (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "1cafa9f3f9a2fce4af6e4b85a2bbd254",
        .manufacturer = "Atari, Jerome Domurat, Howard Scott Warshaw",
        .model        = "CX2659",
        .name         = "Raiders of the Lost Ark (1982) (Atari) (PAL)",
        .note         = "Console ports are swapped",
        .swapPorts    = 1,
    },{
        .md5          = "1cca2197d95c5a41f2add49a13738055",
        .manufacturer = "Atari, Larry Kaplan - Sears",
        .model        = "CX2664 - 6-99818",
        .name         = "Brain Games (1978) (Atari)",
        .note         = "Uses Keyboard Controllers",
        .left         = "KEYBOARD",
        .right        = "KEYBOARD",
    },{
        .md5          = "1cf59fc7b11cdbcefe931e41641772f6",
        .manufacturer = "SEGA",
        .model        = "005-01",
        .name         = "Buck Rogers - Planet of Zoom (1983) (SEGA)",
        .phosphor     = 1,
    },{
        .md5          = "1d1d2603ec139867c1d1f5ddf83093f1",
        .manufacturer = "Atari, Larry Kaplan - Sears",
        .model        = "CX2602 - 99802, 6-99802, 49-75102",
        .name         = "Air-Sea Battle (1977) (Atari) (4K)",
        .note         = "AKA Target Fun (Anti-Aircraft)",
    },{
        .md5          = "1d284d6a3f850bafb25635a12b316f3d",
        .manufacturer = "CCE",
        .name         = "H.E.R.O. (CCE)",
    },{
        .md5          = "1d2a28eb8c95da0d6d6b18294211839f",
        .name         = "Fishing Derby (Unknown) (PAL) (4K)",
    },{
        .md5          = "1d4e0a034ad1275bc4d75165ae236105",
        .manufacturer = "20th Century Fox Video Games, Mark Klein",
        .model        = "11034",
        .name         = "Pick Up (1983) (20th Century Fox) (Prototype)",
    },{
        .md5          = "1d5eac85e67b8cff1377c8dba1136929",
        .name         = "Chronocolor Donkey Kong Sideways (PD)",
    },{
        .md5          = "1d6ed6fe9dfbde32708e8353548cbb80",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Super Challenge Baseball (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "1d72cc6ee466a4af1b27587b900ed430",
        .manufacturer = "Atari, Omegamatrix",
        .name         = "Space Invaders Menu (2020) (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "1da2da7974d2ca73a823523f82f517b3",
        .manufacturer = "Spectravision - Spectravideo - Sirius Software, David Lubar",
        .model        = "SA-206",
        .name         = "Challenge of.... Nexar, The (1982) (Spectravision) (PAL)",
    },{
        .md5          = "1db3bc4601f22cf43be7ce015d74f59a",
        .name         = "Ship Demo (V 10) (PD)",
    },{
        .md5          = "1e060a8025512ad2127e3da11e212ccc",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum, Scott Nelson",
        .model        = "13",
        .name         = "Sweat! - The Decathlon Game (3 of 3) (1983) (Arcadia) (Prototype)",
        .note         = "Uses the Paddle Controllers (left only)",
    },{
        .md5          = "1e0ef01e330e5b91387f75f700ccaf8f",
        .manufacturer = "Quelle - Otto Versand",
        .model        = "686.561 2 - 781627",
        .name         = "Mein Weg (1983) (Quelle) (PAL)",
        .note         = "AKA Challenge",
        .phosphor     = 1,
    },{
        .md5          = "1e1290ea102e12d7ac52820961457e2b",
        .manufacturer = "Parker Brothers, Wilfredo Aguilar, Michael Becker, Neil McKenzie, Bob Smith, Brad Stewart",
        .model        = "PB5540",
        .name         = "Star Wars - The Arcade Game (12-15-1983) (Parker Bros) (Prototype) (4K)",
        .phosphor     = 1,
    },{
        .md5          = "1e272d09c0e55f5ef14fcb76a735f6d7",
        .manufacturer = "Atari, David Crane",
        .model        = "CX26163P",
        .name         = "Slot Machine (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "1e31b3a48865ba98d4d1aa5205115983",
        .manufacturer = "Atari - Roklan, Bob Curtiss",
        .name         = "Firefox (1983) (Atari) (Prototype)",
        .note         = "AKA Combat II, Fighter Command",
    },{
        .md5          = "1e587ca91518a47753a28217cd4fd586",
        .manufacturer = "Telesys, Jim Rupp, Jack Woodman",
        .model        = "1001",
        .name         = "Coco Nuts (1982) (Telesys)",
    },{
        .md5          = "1e750000af77cc76232f4d040f4ab060",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Raft Rider (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "1e85f8bccb4b866d4daa9fcf89306474",
        .manufacturer = "Atari, Lou Harp",
        .model        = "CX26122",
        .name         = "Sinistar (02-13-1984) (Atari) (Prototype)",
    },{
        .md5          = "1e89f722494608d6ea15a00d99f81337",
        .name         = "River Raid (Unknown) (PAL)",
        .format       = "NTSC50",
    },{
        .md5          = "1ea1abcd2d3d3d628f59a99a9d41b13b",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Stampede (Jone Yuan) (Hack)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "1ea980574416bfd504f62575ba524005",
        .manufacturer = "Atari - GCC, Mark Ackerman, Glenn Parker",
        .model        = "CX2675",
        .name         = "Ms. Pac-Man (1982) (Atari) (Prototype)",
    },{
        .md5          = "1ec57bbd27bdbd08b60c391c4895c1cf",
        .manufacturer = "Atari, Jerome Domurat, Howard Scott Warshaw",
        .model        = "CX26119",
        .name         = "Saboteur (09-02-1983) (Atari) (Prototype)",
    },{
        .md5          = "1ec5bef77b91e59313cba205f15b06d7",
        .name         = "Overhead Adventure Demo 1 (PD)",
    },{
        .md5          = "1ede4f365ce1386d58f121b15a775e24",
        .manufacturer = "Parker Brothers, Dave Hampton, Tom Sloper",
        .model        = "931517",
        .name         = "Q-bert (1983) (Parker Bros) (PAL) [a]",
    },{
        .md5          = "1ee2cfc7d0333b96bd11f7f3ec8ce8bc",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4200",
        .name         = "Escape from the Mindmaster (4 of 4) (1982) (Arcadia) (PAL)",
    },{
        .md5          = "1ee9c1ba95cef2cf987d63f176c54ac3",
        .manufacturer = "Atari - GCC, Mark Ackerman, Glenn Parker",
        .model        = "CX2675, CX2675P",
        .name         = "Ms. Pac-Man (1983) (Atari) (PAL)",
    },{
        .md5          = "1ef04e7e508296a8d9eb61cc7dae2e5d",
        .manufacturer = "SOLID Corp. (D. Scott Williamson)",
        .model        = "CX2655-069",
        .name         = "Star Castle 2600 (SolidCorp) [069]",
        .phosphor     = 1,
    },{
        .md5          = "1f21666b8f78b65051b7a609f1d48608",
        .manufacturer = "K-Tel Vision",
        .name         = "Vulture Attack (1982) (K-Tel Vision)",
        .note         = "AKA Condor Attack",
    },{
        .md5          = "1f2ae0c70a04c980c838c2cdc412cf45",
        .manufacturer = "Atari - GCC",
        .model        = "CX2698",
        .name         = "Rubik's Cube (1984) (Atari)",
        .note         = "AKA Atari Video Cube",
    },{
        .md5          = "1f349dd41c3f93c4214e5e308dccb056",
        .name         = "Virtual Pet Demo 2 (CRACKERS) (PD)",
    },{
        .md5          = "1f40eefc7447336ae6cd8ffa5eb325be",
        .manufacturer = "Atari, Chris Crawford",
        .name         = "Wizard (1980) (Atari) (Prototype) (4K) [a]",
    },{
        .md5          = "1f562b89d081e36d58e6fc943512ec05",
        .name         = "Hangman Man Biglist2 (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "1f5a2927a0b2faf87540b01d9d7d7fd1",
        .name         = "Tennis (Unknown) (PAL)",
    },{
        .md5          = "1f60e48ad98b659a05ce0c1a8e999ad9",
        .name         = "Mondo Pong V2 (Piero Cavina) (PD)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXDR",
    },{
        .md5          = "1f773a94d919b2a3c647172bbb97f6b4",
        .manufacturer = "Atari, Jerome Domurat, Peter C. Niday",
        .model        = "CX26115",
        .name         = "Dumbo's Flying Circus (07-11-1983) (Atari) (Prototype) (PAL)",
        .note         = "AKA Dumbo Flies Home",
    },{
        .md5          = "1fa58679d4a39052bd9db059e8cda4ad",
        .manufacturer = "Imagic, Dan Oliver",
        .model        = "720118-1A, 03208",
        .name         = "Laser Gates (1983) (Imagic)",
        .note         = "AKA Innerspace",
    },{
        .md5          = "1fa7a42c2c7d6b7a0c6a05d38c7508f4",
        .manufacturer = "Coleco - Individeo, Ed Temple",
        .name         = "Cabbage Patch Kids (09-04-1984) (Coleco) (Prototype)",
        .note         = "Adventures in the Park",
    },{
        .md5          = "1fa86282403fa35d103ab88a9d603c31",
        .manufacturer = "SpiceWare - Darrell Spice Jr.",
        .name         = "Stay Frosty (SpiceWare) (PAL60)",
        .note         = "Part of Stella's Stocking 2007 Xmas compilation",
        .phosphor     = 1,
    },{
        .md5          = "1fab68fd67fe5a86b2c0a9227a59bb95",
        .manufacturer = "20th Century Fox Video Games - Videa, Lee Actor",
        .name         = "Lasercade (1983) (20th Century Fox) (Prototype)",
    },{
        .md5          = "200309c8fba0f248c13751ed4fc69bab",
        .manufacturer = "Jeffry Johnston",
        .name         = "Radial Pong - Version 1 (Jeffry Johnston) (PD)",
    },{
        .md5          = "2008c76deba5953201ef75a09b2ff7dc",
        .name         = "Fortress (21-04-2003) (Christopher Tumber)",
    },{
        .md5          = "200a9d2a7cb4441ce4f002df6aa47e38",
        .name         = "Doomzerk (PD) (Hack)",
        .note         = "Hack of Berzerk",
    },{
        .md5          = "2016726db38ad6a68b4c48ba6fe51557",
        .manufacturer = "Piero Cavina, Erik Mooney",
        .name         = "INV 2 (Piero Cavina, Erik Mooney)",
    },{
        .md5          = "203049f4d8290bb4521cc4402415e737",
        .manufacturer = "Tigervision, Robert H. O'Neil - Teldec",
        .model        = "7-007 - 3.60005 VG",
        .name         = "Polaris (1983) (Tigervision) (PAL)",
    },{
        .md5          = "203abb713c00b0884206dcc656caa48f",
        .manufacturer = "Imagic, Bob Smith",
        .model        = "720114-1A, 03207, IZ-001-04",
        .name         = "Moonsweeper (1983) (Imagic)",
        .phosphor     = 1,
    },{
        .md5          = "203b1efc6101d4b9d83bb6cc1c71f67f",
        .manufacturer = "Quelle",
        .model        = "685.996 1",
        .name         = "Teller-Jonglieren! (1983) (Quelle) (PAL)",
        .note         = "AKA Dancing Plate",
        .phosphor     = 1,
    },{
        .md5          = "205070b6a0d454961dd9196a8e81d877",
        .name         = "Hangman Monkey Biglist2 (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "2058cf3fefad4d2bc03ed817cedddcd4",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Amiga Mouse Hack v1.3 (PAL60) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "2091af29b4e7b86914d79d9aaa4cbd20",
        .manufacturer = "CBS Electronics - Woodside Design Associates, Harley H. Puthuff Jr.",
        .model        = "4L1802",
        .name         = "Donkey Kong Junior (1983) (CBS Electronics) (PAL)",
    },{
        .md5          = "20ae62fb69c6cc6e8098cca8cd080487",
        .manufacturer = "Zirok",
        .name         = "Tennis (Zirok)",
    },{
        .md5          = "20d4457ba22517253fcb62967af11b37",
        .manufacturer = "Atari, Eric Manghise, Mimi Nyden, Joseph Tung",
        .model        = "CX2640",
        .name         = "RealSports Baseball (1982) (Atari) (Prototype)",
    },{
        .md5          = "20dca534b997bf607d658e77fbb3c0ee",
        .manufacturer = "Mythicon, Bill Bryner, Bruce de Graaf",
        .model        = "MA1002",
        .name         = "Fire Fly (1983) (Mythicon)",
    },{
        .md5          = "20edcc3aa6c189259fa7e2f044a99c49",
        .manufacturer = "Spectravision - Spectravideo",
        .model        = "SA-201",
        .name         = "Gangster Alley (1982) (Spectravision) [fixed]",
    },{
        .md5          = "211774f4c5739042618be8ff67351177",
        .manufacturer = "Atari - GCC, Mark Ackerman, Tom Calderwood, Glenn Parker",
        .model        = "CX2684",
        .name         = "Galaxian (1983) (Atari)",
    },{
        .md5          = "211f76dff0b7dad3f6fcac9d938ee61a",
        .manufacturer = "JSK",
        .name         = "Custer's Viagra (JSK) (Hack) [a]",
        .note         = "Hack of Custer's Revenge",
    },{
        .md5          = "211fbbdbbca1102dc5b43dc8157c09b3",
        .manufacturer = "Apollo",
        .model        = "AP-2009",
        .name         = "Final Approach (1982) (Apollo)",
    },{
        .md5          = "2124cf92978c46684b6c39ccc2e33713",
        .name         = "Sea Monster (Unknown) (PAL)",
    },{
        .md5          = "21299c8c3ac1d54f8289d88702a738fd",
        .manufacturer = "K-Tel Vision",
        .name         = "Spider Maze (1982) (K-Tel Vision)",
        .note         = "AKA Spider Kong",
    },{
        .md5          = "212d0b200ed8b45d8795ad899734d7d7",
        .manufacturer = "Atari, Richard Maurer, Christopher H. Omarzu - Coca Cola",
        .name         = "Pepsi Invaders (1983) (Atari)",
    },{
        .md5          = "213e5e82ecb42af237cfed8612c128ac",
        .manufacturer = "Sancho - Tang's Electronic Co.",
        .model        = "TEC006",
        .name         = "Forest (1983) (Sancho) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "2162266b906c939b35c84ff9a0f50ad1",
        .manufacturer = "Atari, Larry Kaplan",
        .model        = "CX2664, CX2664P",
        .name         = "Brain Games (1978) (Atari) (PAL) (4K)",
        .note         = "Uses Keyboard Controllers",
        .left         = "KEYBOARD",
        .right        = "KEYBOARD",
    },{
        .md5          = "2179dfd7edee76efafe698c1bc763735",
        .name         = "Yellow Submarine (Cody Pittman) (PD)",
    },{
        .md5          = "217b1452881264ac75126bf77b8d0db8",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Atari Trak-Ball Hack v1.4 (NTSC) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "218b76f5a4142dc2ea9051a768583d70",
        .manufacturer = "Atari - GCC, Mark Ackerman, Glenn Parker",
        .model        = "CX2684, CX2684P",
        .name         = "Galaxian (1983) (Atari) (PAL) [a2]",
    },{
        .md5          = "218c0fe53dfaaa37f3c823f66eafd3fc",
        .manufacturer = "Atari, Alan Miller",
        .model        = "CX2624, CX2624P",
        .name         = "Basketball (1978) (Atari) (PAL)",
        .note         = "Console ports are swapped",
        .swapPorts    = 1,
    },{
        .md5          = "21a96301bb0df27fde2e7eefa49e0397",
        .manufacturer = "Data Age",
        .model        = "DA1003",
        .name         = "Sssnake (1982) (Data Age)",
    },{
        .md5          = "21b09c40295c2d7074a83ae040f22edf",
        .name         = "Marble Craze (V0.90) (Easy Version) (Paul Slocum)",
    },{
        .md5          = "21d2c435bcccde7792d82844b3cf60f4",
        .manufacturer = "Atari - GCC, Doug Macrae",
        .model        = "CX2677, CX2677P",
        .name         = "Dig Dug (1983) (Atari) (PAL) [a]",
    },{
        .md5          = "21d7334e406c2407e69dbddd7cec3583",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AG-011",
        .name         = "Stampede (1981) (Activision)",
    },{
        .md5          = "2228c67d25e507603d4873d3934f0757",
        .name         = "Fu Kung! (V0.10) (28-01-2003) (Andrew Davie)",
    },{
        .md5          = "22319be7a640af5314ec3c482cceb676",
        .name         = "Joustpong (05-07-2002) (Kirk Israel) (PD)",
    },{
        .md5          = "2240655247d6de1c585564004a853ab7",
        .name         = "Fu Kung! (V0.17) (07-02-2003) (Andrew Davie)",
    },{
        .md5          = "225522777dc7155627808bde0c1d0ef0",
        .name         = "This Planet Sucks Demo 1 (Greg Troutman) (PD)",
    },{
        .md5          = "22675cacd9b71dea21800cbf8597f000",
        .manufacturer = "Atari, David Crane",
        .model        = "CX2605, CX2605P",
        .name         = "Outlaw (1978) (Atari) (PAL)",
    },{
        .md5          = "227532d82505c3c185a878273c285d5f",
        .name         = "Hangman Man Original Words (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "22abbdcb094d014388d529352abe9b4b",
        .manufacturer = "Apollo",
        .model        = "AP-2012",
        .name         = "Squoosh (1983) (Apollo) (Prototype) [a]",
        .note         = "AKA Vat's Incredible!, The Grape Escape",
    },{
        .md5          = "22b22c4ce240303012e8a9596ae8d189",
        .name         = "Skeleton+ (03-05-2003) (Eric Ball) (PAL)",
    },{
        .md5          = "22f6b40fc82110d68e50a1208ae0bb97",
        .name         = "Purple Bar Demo (PD)",
    },{
        .md5          = "2319922df4d0c820b3e5f15faa870cc3",
        .manufacturer = "Atari - GCC, Mike Feinstein",
        .model        = "CX2681, CX2681P",
        .name         = "Battlezone (1983) (Atari) (PAL) [a]",
    },{
        .md5          = "2327456f86d7e0deda94758c518d05b3",
        .manufacturer = "Digitel",
        .name         = "Mr. Postman (Digitel)",
    },{
        .md5          = "2351d26d0bfdee3095bec9c05cbcf7b0",
        .name         = "Warring Worms (19-01-2002) (Billy Eno)",
    },{
        .md5          = "2353725ec98e0f0073462109e886efd7",
        .manufacturer = "Champ Games",
        .model        = "CG-03-P",
        .name         = "Scramble (PAL60)",
        .note         = "Compatible with Genesis controller",
        .left         = "JOYSTICK",
        .phosphor     = 1,
    },{
        .md5          = "235436ab0832370e73677c9c6f0c8b06",
        .name         = "Beast Invaders (Double Shot) (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "2365e1534d67f94d8670394ab99150ce",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Command (Atari Mouse) (2002) (Thomas Jentzsch)",
        .note         = "Uses Atari ST Mouse Controller",
        .left         = "ATARIMOUSE",
        .right        = "ATARIMOUSE",
        .phosphor     = 1,
    },{
        .md5          = "23d445ea19a18fb78d5035878d9fb649",
        .manufacturer = "CBS Electronics - JWDA, Sylvia Day, Todd Marshall, Henry Will IV",
        .model        = "4L1818, 4L1819, 4L1820, 4L1821",
        .name         = "Mouse Trap (1983) (CBS Electronics) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "23e4ca038aba11982e1694559f3be10f",
        .name         = "Big Dig (V3) (20-10-2002) (Christopher Tumber)",
    },{
        .md5          = "23fad5a125bcd4463701c8ad8a0043a9",
        .manufacturer = "CCE",
        .model        = "C-840",
        .name         = "Stone Age (1983) (CCE)",
        .note         = "Uses the Joystick Controllers (swapped)",
        .swapPorts    = 1,
        .phosphor     = 1,
    },{
        .md5          = "240bfbac5163af4df5ae713985386f92",
        .manufacturer = "Activision, Steve Cartwright",
        .model        = "AX-022",
        .name         = "Seaquest (1983) (Activision)",
    },{
        .md5          = "2418fa5ecfb685f7bb70bc4527e9d966",
        .manufacturer = "AtariAge, Chris Walton & Thomas Jentzsch",
        .name         = "Star Castle Arcade (2014) (Chris Walton, Thomas Jentzsch)",
        .phosphor     = 1,
    },{
        .md5          = "2432f33fd278dea5fe6ae94073627fcc",
        .manufacturer = "CBS Electronics, Tom DiDomenico",
        .model        = "4L2477, 4L2482, 4L2485, 4L4171",
        .name         = "Blueprint (1983) (CBS Electronics) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "2434102f30eeb47792cf0825e368229b",
        .manufacturer = "Sparrow - Enter-Tech, Paul Walters, Rick Harris, George Hefner, Barbara Ultis",
        .name         = "Arkyology (1983) (Sparrow) (Prototype)",
        .note         = "ROM must be started in bank 0",
    },{
        .md5          = "24385ba7f5109fbe76aadc0a375de573",
        .manufacturer = "CCE",
        .name         = "Xevious (CCE)",
        .phosphor     = 1,
    },{
        .md5          = "2447e17a4e18e6b609de498fe4ab52ba",
        .manufacturer = "CCE",
        .name         = "Super Futebol (CCE)",
        .note         = "AKA RealSports Soccer",
        .phosphor     = 1,
    },{
        .md5          = "244c6de27faff527886fc7699a41c3be",
        .name         = "Matt Demo (PD)",
    },{
        .md5          = "2450dfa1df70d12b60683185775efed8",
        .manufacturer = "Jeffry Johnston",
        .name         = "Radial Pong - Version 7 (Jeffry Johnston) (PD)",
    },{
        .md5          = "24544ee5d76f579992d9522e9b238955",
        .manufacturer = "Carrere Video - Western Technologies, Jeff Corsiglia, David Johnson, Tom Sloper - Teldec - Prism",
        .model        = "USC2004",
        .name         = "Picnic (1983) (Carrere Video) (PAL)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "245f07c8603077a0caf5f83ee6cf8b43",
        .manufacturer = "Home Vision - Thomas Jentzsch",
        .name         = "Parachute (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "24759be31e8fe55d2829fd86bdf3181f",
        .manufacturer = "Hozer Video Games",
        .name         = "Gunfight 2600 - Worst Nightmare... (2001) (Manuel Rotschkar)",
    },{
        .md5          = "247fa1a29ad90e64069ee13d96fea6d6",
        .manufacturer = "CCE",
        .model        = "C-867",
        .name         = "Radar (1983) (CCE)",
        .note         = "AKA Exocet",
    },{
        .md5          = "248668b364514de590382a7eda2c9834",
        .manufacturer = "CBS Electronics, Richard K. Balaska Jr., Bob Curtiss, Alex Leavens, Alex Nevelson",
        .name         = "Kick-Man (01-08-82) (CBS Electronics) (Prototype)",
    },{
        .md5          = "2496d404bfc561a40a80bea6a69695c3",
        .name         = "Jungle Hunt (Unknown)",
    },{
        .md5          = "24ad538291eb5f5cac4b9998f3b851c3",
        .name         = "Gunfight 2600 - This time it's your decission! (2001) (Manuel Rotschkar)",
    },{
        .md5          = "24aff972d58990f9b88a6d787c796f1e",
        .manufacturer = "CBS Electronics",
        .model        = "4L1767, 4L1768, 4L1769, 4L1770",
        .name         = "Smurf (1982) (CBS Electronics) (PAL) [a]",
    },{
        .md5          = "24b5f4bbdb853eca38ea0cae2dfe73a1",
        .name         = "Home Run (Unknown) (PAL) (4K)",
        .swapPorts    = 1,
    },{
        .md5          = "24b9adac1b4f85b0bac9bf9b9e180906",
        .manufacturer = "Angelino",
        .name         = "Space 2002 (Angelino) (Hack)",
        .note         = "Hack of Space Jockey",
    },{
        .md5          = "24d018c4a6de7e5bd19a36f2b879b335",
        .manufacturer = "Activision, Larry Miller",
        .model        = "AX-021",
        .name         = "Spider Fighter (1983) (Activision)",
    },{
        .md5          = "24d9a55d8f0633e886a1b33ee1e0e797",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Dragon Defender (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
        .phosphor     = 1,
    },{
        .md5          = "24df052902aa9de21c2b2525eb84a255",
        .manufacturer = "Imagic, Dennis Koble",
        .model        = "720000-100, 720100-1B, IA3000, IA3000C",
        .name         = "Trick Shot (1982) (Imagic)",
        .phosphor     = 1,
    },{
        .md5          = "24fbf8250a71611e40ef18552e61b009",
        .name         = "Movable Grid Demo (PD)",
    },{
        .md5          = "2516f4f4b811ede4ecf6fbeb5d54a299",
        .manufacturer = "Quelle",
        .model        = "701.134 9",
        .name         = "Schiessbude (1983) (Quelle) (PAL)",
        .note         = "AKA Carnival",
    },{
        .md5          = "2517827950fee41a3b9de60275c8aa6a",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Fishing (32 in 1) (1988) (Atari) (PAL)",
        .note         = "AKA Fishing Derby",
    },{
        .md5          = "25265d0e7f88b3026003809f25ee025e",
        .manufacturer = "Atari - GCC, Ava-Robin Cohen",
        .model        = "CX26123",
        .name         = "Jr. Pac-Man (1984) (Atari) [a]",
    },{
        .md5          = "25472dfdeef6a42581a231d631d6b04d",
        .name         = "Gunfight 2600 - Design thoughts (Manuel Rotschkar)",
    },{
        .md5          = "25710bde8fa181b0c5cf0846b983bec1",
        .name         = "Demo Image Series #15 - Three Marios (NTSC) (06-03-2003) (Andrew Davie)",
    },{
        .md5          = "257bc3b72a6b5db3fd0d47619125b387",
        .manufacturer = "CBS Electronics",
        .model        = "4L 2737 0000",
        .name         = "Omega Race (1983) (CBS Electronics) [a]",
        .note         = "Set right difficulty to 'A' for BoosterGrip in both ports",
        .left         = "BOOSTERGRIP",
        .right        = "BOOSTERGRIP",
    },{
        .md5          = "25a21c47afe925a3ca0806876a2b4f3f",
        .manufacturer = "Quelle",
        .model        = "685.640 5",
        .name         = "Der kleine Baer (1983) (Quelle) (PAL)",
        .note         = "AKA Frostbite",
    },{
        .md5          = "25b52bf8dd215bcbd59c9abdb55c44f8",
        .manufacturer = "Atari - GCC, Betty Ryan Tylko, Doug Macrae",
        .model        = "CX2694, CX2694P",
        .name         = "Pole Position (1983) (Atari) (PAL) [a]",
    },{
        .md5          = "25b6dc012cdba63704ea9535c6987beb",
        .manufacturer = "Avalon Hill, Jean Baer, Bill Hood",
        .model        = "5004002",
        .name         = "Shuttle Orbiter (1983) (Avalon Hill)",
    },{
        .md5          = "25bb080457351be724aac8a02021aa92",
        .manufacturer = "CBS Electronics",
        .model        = "4L1784, 4L1786, 4L1787, 4L2277",
        .name         = "Zaxxon (1983) (CBS Electronics) (PAL)",
    },{
        .md5          = "25d4be3309b89583c6b39d9f93bf654f",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AX-015, AX-015-04",
        .name         = "Chopper Command (1982) (Activision) (16K)",
    },{
        .md5          = "25e73efb9a6edf119114718bd2f646ba",
        .manufacturer = "Atari, Dave Joly, Gary Shannon",
        .model        = "CX26113",
        .name         = "Miss Piggy's Wedding (1983) (Atari) (Prototype) (4K) [a]",
    },{
        .md5          = "25f2e760cd7f56b88aac88d63757d41b",
        .manufacturer = "Activision, Bob Whitehead - Ariola",
        .model        = "EAG-002, EAG-002-04I, PAG-002 - 711 002-715",
        .name         = "Boxing (1980) (Activision) (PAL)",
    },{
        .md5          = "25f879ff678130fea615ac418e7943f1",
        .manufacturer = "Activision, Garry Kitchen",
        .model        = "EAX-025",
        .name         = "Keystone Kapers (1983) (Activision) (SECAM)",
    },{
        .md5          = "25f9cf703575c5d63048c222f5463758",
        .name         = "Multi-Sprite Demo 1 (PD)",
    },{
        .md5          = "260c787e8925bf3649c8aeae5b97dcc0",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Hell Driver (Thomas Jentzsch)",
        .note         = "NTSC Conversion, joystick ports swapped",
        .swapPorts    = 1,
    },{
        .md5          = "262ccb882ff617d9b4b51f24aee02cbe",
        .manufacturer = "Atari, Douglas Neubauer",
        .model        = "CX26154, CX26154P",
        .name         = "Super Football (1988) (Atari) (PAL)",
    },{
        .md5          = "265a85f66544eaf95fda06c3d9e48abf",
        .name         = "Tunnel Demo (Cycling Colours) (29-03-2003) (Andrew Davie)",
    },{
        .md5          = "265c74a956500bd31efd24adc6d5ccf6",
        .manufacturer = "Activision, Larry Miller",
        .model        = "AX-026, AX-026-04",
        .name         = "Enduro (1983) (Activision) (8K)",
    },{
        .md5          = "2683d29a282dd059535ac3bb250f540d",
        .name         = "Space Treat (12-01-2003) (Fabrizio Zavagli)",
    },{
        .md5          = "268f46038e29301568fa9e443e16e960",
        .manufacturer = "Atarius Maximum",
        .name         = "Pitfall Unlimited (Atarius Maximus) (Hack)",
        .note         = "Hack of Pitfall",
    },{
        .md5          = "26bc2bdf447a17376aea7ef187ff6e44",
        .name         = "Amanda Invaders (PD)",
    },{
        .md5          = "26f4f8b098609164effef7809e0121e1",
        .name         = "Oystron (V2.7) (Piero Cavina) (PD)",
    },{
        .md5          = "270229c6d5578446e6a588492e4e5910",
        .name         = "Space Invaders 2 (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "2712e91f6f1dc55e90e2b14b27c042ac",
        .manufacturer = "Omegamatrix",
        .name         = "SpaceMaster X-7 (Amiga Mouse) (PAL60) (Omegamatrix)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "271bfd5dc2673d382019f1fb6cab9332",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4200",
        .name         = "Escape from the Mindmaster (Preview) (1982) (Arcadia) (PAL)",
    },{
        .md5          = "273ce50db5a0d6da7ea827a54f44dee9",
        .name         = "Island Flyer Demo (PD)",
    },{
        .md5          = "274d17ccd825ef9c728d68394b4569d2",
        .manufacturer = "Playaround - J.H.M.",
        .model        = "202",
        .name         = "Bachelorette Party (1982) (Playaround)",
        .note         = "AKA Bachelor Party, Uses the paddle controllers",
        .left         = "PADDLES_IAXIS",
        .phosphor     = 1,
    },{
        .md5          = "277c7281ac945b8331e2e6fcad560c11",
        .manufacturer = "Arcadia Corporation, Steve Mundry, Scott Nelson",
        .model        = "AR-4401",
        .name         = "Survival Island (2 of 3) (1983) (Arcadia) (PAL)",
    },{
        .md5          = "277cca62014fceebb46c549bac25a2e3",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AG-002, CAG-002, AG-002-04",
        .name         = "Boxing (1980) (Activision) (4K)",
    },{
        .md5          = "277fa4b9a6bb7a8dcea2c5f38a4c25f0",
        .manufacturer = "Atari, Alan J. Murphy, Robert Zdybel",
        .model        = "CX2668",
        .name         = "RealSports Football (1982) (Atari) (Prototype)",
        .note         = "AKA Football II",
        .phosphor     = 1,
    },{
        .md5          = "278155fc9956e9b6ef2359eb238f7c7f",
        .name         = "Donkey Kong Junior (Unknown) (Hack)",
        .note         = "Hack of Donkey Kong Junior",
    },{
        .md5          = "2783006ee6519f15cbc96adae031c9a9",
        .manufacturer = "Telegames",
        .name         = "Night Stalker (1989) (Telegames) (PAL) [a]",
        .note         = "AKA Dark Cavern",
    },{
        .md5          = "278531cc31915747018d22145823d2c9",
        .name         = "Defender MegaDrive (PAL) (Genesis)",
        .note         = "Genesis controller (C is smartbomb)",
    },{
        .md5          = "278f14887d601b5e5b620f1870bc09f6",
        .manufacturer = "Thomas Jentzsch",
        .name         = "SWOOPS! (v0.96) (Thomas Jentzsch)",
        .note         = "Uses the Joystick (L) and Paddle (R) Controllers",
    },{
        .md5          = "27a5d2d0c74c8e4b2c05b94c9f098eea",
        .manufacturer = "Atari, Omegamatrix",
        .name         = "Video Olympics Menu (2020) (PAL60) (Hack)",
        .note         = "Hack of Video Olympics",
        .swapPaddles  = 1,
    },{
        .md5          = "27baecd618e7e53dc11f2a9c559f529d",
        .manufacturer = "Omegamatrix",
        .name         = "Star Wars Arcade (Atari Trak-Ball) v4 (Omegamatrix)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "27c4c2af4b46394bb98638af8e0f6e9d",
        .manufacturer = "Atari, Dave Joly, Peter C. Niday, Robert Vieira",
        .model        = "CX26109",
        .name         = "Sorcerer's Apprentice (1983) (Atari) (Prototype)",
    },{
        .md5          = "27c6a2ca16ad7d814626ceea62fa8fb4",
        .manufacturer = "Parker Brothers, Mark Lesser",
        .model        = "PB5590",
        .name         = "Frogger II (1984) (Parker Bros)",
        .phosphor     = 1,
    },{
        .md5          = "27f9e2e1b92af9dc17c6155605c38e49",
        .manufacturer = "CCE",
        .name         = "Nightmare (CCE)",
    },{
        .md5          = "2808dc745ff4321dc5c8122abef6711f",
        .manufacturer = "Retroactive",
        .name         = "Qb (2.11) (Retroactive) (Stella)",
        .phosphor     = 1,
    },{
        .md5          = "28148a52b1955ce12c7a74d3a3e620a4",
        .manufacturer = "CCE",
        .name         = "Freeway (CCE) (4K)",
    },{
        .md5          = "281ff9bd0470643853de5cbd6d9e17f5",
        .manufacturer = "Eckhard Stolberg",
        .name         = "Cubis (EM) (1997) (Eckhard Stolberg)",
    },{
        .md5          = "2823364702595feea24a3fbee138a243",
        .manufacturer = "Bit Corporation",
        .model        = "PG206",
        .name         = "Bobby Is Going Home (1983) (BitCorp) (PAL)",
        .note         = "AKA Bobby geht Heim",
    },{
        .md5          = "2825f4d068feba6973e61c84649489fe",
        .name         = "Boom Bang (Unknown) (PAL)",
        .note         = "AKA Crackpots",
    },{
        .md5          = "282a77841cb3d33af5b56151acba770e",
        .manufacturer = "Otto Versand",
        .model        = "311388",
        .name         = "Black Hole (1983) (Otto Versand) (PAL)",
        .note         = "AKA Cosmic Ark (Double-Game Package)",
    },{
        .md5          = "283cb03ee031c842beabdad1aa4e7dbc",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Demon Attack (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "283dee88f295834c4c077d788f151125",
        .manufacturer = "Retroactive",
        .name         = "Qb (2.11) (Retroactive) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "284ca61b2407bdba3938048b0a559015",
        .manufacturer = "Atari, Tod Frye",
        .model        = "CX2695",
        .name         = "Xevious (05-25-1983) (Atari) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "2854e5dfb84173fafc5bf485c3e69d5a",
        .manufacturer = "Canal 3 - Intellivision",
        .model        = "C 3004",
        .name         = "Moon Patrol (Canal 3)",
    },{
        .md5          = "2880c6b59bd54b153174676e465167c7",
        .manufacturer = "Tron",
        .name         = "Donkey Kong Jr. (Tron)",
        .note         = "AKA Donkey Kong Junior",
    },{
        .md5          = "28a2bea8f84936cb2e063f857414cda0",
        .manufacturer = "Thiago Paiva",
        .name         = "Mega Mania Raid (1999) (Thiago Paiva) (Hack)",
        .note         = "Hack of Megamania",
    },{
        .md5          = "28a4cd87fb9de4ee91693a38611cb53c",
        .name         = "Skeleton (V1.1) (NTSC) (24-10-2002) (Eric Ball)",
    },{
        .md5          = "28d5df3ed036ed63d33a31d0d8b85c47",
        .manufacturer = "Bit Corporation",
        .model        = "PG204",
        .name         = "Open, Sesame! (1983) (BitCorp) (PAL)",
        .note         = "AKA Sesam, Offne Dich",
        .phosphor     = 1,
    },{
        .md5          = "2903896d88a341511586d69fcfc20f7d",
        .manufacturer = "Activision, David Crane",
        .model        = "AX-014, AX-014-04",
        .name         = "Grand Prix (1982) (Activision)",
    },{
        .md5          = "291bcdb05f2b37cdf9452d2bf08e0321",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "32 in 1 Game Cartridge (1988) (Atari) (Prototype) (PAL)",
        .type         = "32IN1",
    },{
        .md5          = "291cc37604bc899e8e065c30153fc4b9",
        .manufacturer = "Activision, Carol Shaw",
        .model        = "AX-020, AX-020-04",
        .name         = "River Raid (1982) (Activision) (16K)",
    },{
        .md5          = "291dd47588b9158beebe4accc3a093a6",
        .manufacturer = "Atari",
        .name         = "32 in 1 Console ROM (02-10-1989) (Atari) (Prototype) (PAL)",
        .type         = "32IN1",
    },{
        .md5          = "292a0bb975b2587f9ac784c960e1b453",
        .name         = "Qb (05-02-2001) (Andrew Davie)",
        .phosphor     = 1,
    },{
        .md5          = "292f2446a0325b7b423e88a2ebfeb5a0",
        .name         = "Cube Conquest (Non Interlaced) (Billy Eno) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "29396db58406084e416032c372734a3e",
        .name         = "Gunfight 2600 - Fixed Beta Release! (2001) (Manuel Rotschkar)",
    },{
        .md5          = "2942680c47beb9bf713a910706ffabfe",
        .name         = "Blue Line Demo (PD)",
    },{
        .md5          = "294762000e853b4319f9991c1ced5dfc",
        .name         = "T.F. Space Invaders (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "295f3679bdf91ca5e37da3f787b29997",
        .name         = "Exorcise (Hack)",
        .note         = "Hack of Adventure",
    },{
        .md5          = "29630a20d356fb58685b150bfa8f00c3",
        .manufacturer = "M Network, Kevin Miller",
        .model        = "MT5687",
        .name         = "International Soccer (1982) (Mattel) [a]",
    },{
        .md5          = "297236cb9156be35679f83c4e38ee169",
        .manufacturer = "Exus Corporation",
        .name         = "Video Reflex (1983) (Exus) [no roman numbers]",
        .note         = "AKA Foot Craz (no roman numbers)",
    },{
        .md5          = "297c405afd01f3ac48cdb67b00d273fe",
        .manufacturer = "Atari - GCC, Ava-Robin Cohen",
        .model        = "CX26123, CX26123P",
        .name         = "Jr. Pac-Man (1986) (Atari) (PAL)",
    },{
        .md5          = "2982e655dffc89d218a0a3072cfc6811",
        .name         = "Mini Golf 812631 (Hack)",
        .note         = "Hack of Miniature Golf",
    },{
        .md5          = "298387b0637173d2002770a649b4fbca",
        .name         = "S.I.PLIX 2 (Hack) [a]",
        .note         = "Hack of Kaboom!",
    },{
        .md5          = "29843f43b81f3736bf35c00b1bb88fb2",
        .manufacturer = "Gray Games & AtariAge",
        .name         = "E.T. Book Cart (NTSC)",
        .note         = "Charles F. Gray & Michael Rideout",
        .phosphor     = 1,
    },{
        .md5          = "29949f893ef6cb9e8ecb368b9e99eee4",
        .manufacturer = "Erik Eid",
        .name         = "Euchre (Alpha) (NTSC) (31-08-2002) (Erik Eid)",
    },{
        .md5          = "29dfa26b7988af9984d617708e4fc6e2",
        .name         = "Boulderdash Demo (05-04-2003) (Andrew Davie)",
    },{
        .md5          = "2a0ba55e56e7a596146fa729acf0e109",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AG-019",
        .name         = "Sky Jinks (1982) (Activision)",
    },{
        .md5          = "2a10053fd08664c7cfbbb104386ed77f",
        .name         = "Alpha Demo - The Beta Demo (2000) (Manuel Rotschkar)",
    },{
        .md5          = "2a1b454a5c3832b0240111e7fd73de8a",
        .manufacturer = "Tigervision, Bill Hogue",
        .model        = "7-011",
        .name         = "Miner 2049er Volume II (1983) (Tigervision)",
        .phosphor     = 1,
    },{
        .md5          = "2a2f46b3f4000495239cbdad70f17c59",
        .manufacturer = "CommaVid, John Bronstein - Ariola",
        .model        = "CM-003 - 712 003-720",
        .name         = "Cosmic Swarm (1982) (CommaVid) (PAL)",
        .note         = "AKA Angriff der Termiten",
        .phosphor     = 1,
    },{
        .md5          = "2a33e21447bf9e13dcfed85077ff6b40",
        .name         = "Backwards Cannonball v2 (Hack)",
        .note         = "Hack of Human Cannonball",
    },{
        .md5          = "2a360bc85bf22de438651cf92ffda1de",
        .manufacturer = "Bit Corporation",
        .model        = "PGP213",
        .name         = "Spy Vs. Spy (4 Game in One) (1983) (BitCorp) (PAL)",
        .note         = "AKA Chopper Command",
    },{
        .md5          = "2a9f9001540c55a302befd8e9d54b47b",
        .manufacturer = "Atari, Dan Hitchens",
        .model        = "CX2697, CX2697P",
        .name         = "Mario Bros. (1983) (Atari) (PAL) [a]",
    },{
        .md5          = "2aa5e56d36c2e58b6f2856109f2099a9",
        .manufacturer = "Atari, Larry Kaplan - Sears",
        .model        = "CX2628 - 6-99842, 49-75117",
        .name         = "Bowling (1979) (Atari) (4K) [a]",
    },{
        .md5          = "2aba6a1b01a5859e96d6a66d2286772f",
        .manufacturer = "Activision, Steve Cartwright",
        .model        = "AX-027",
        .name         = "Plaque Attack (1983) (Activision) (8K)",
    },{
        .md5          = "2abc3d46b3f2140160759e2e10bc86d9",
        .name         = "Gunfight 2600 - Beta Release! (2001) (Manuel Rotschkar)",
    },{
        .md5          = "2ac3a08cfbf1942ba169c3e9e6c47e09",
        .manufacturer = "Activision, Dan Kitchen",
        .model        = "EAK-046-04B",
        .name         = "Fighter Pilot (1988) (Activision) (PAL)",
        .note         = "AKA Tomcat - The F-14 Fighter Simulator",
    },{
        .md5          = "2ae700c9dba843a68dfdca40d7d86bd6",
        .manufacturer = "TechnoVision - Thomas Jentzsch",
        .name         = "Pharaoh's Curse (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
        .phosphor     = 1,
    },{
        .md5          = "2aeedcc6eb1602efb77161b0cef832ab",
        .manufacturer = "SOLID Corp. (D. Scott Williamson)",
        .model        = "CX2655-025",
        .name         = "Star Castle 2600 (SolidCorp) [025]",
        .phosphor     = 1,
    },{
        .md5          = "2b1589c7e1f394ae6a1c046944f06688",
        .manufacturer = "Carrere Video - JWDA, Todd Marshall, Robin McDaniel, Wes Trager, Henry Will IV - Teldec - Prism",
        .model        = "USC2003",
        .name         = "Eggomania (1983) (Carrere Video) (PAL)",
        .note         = "Uses the Paddle Controllers (left only)",
    },{
        .md5          = "2b27eb194e13f3b38d23c879cc1e3abf",
        .manufacturer = "Quelle",
        .model        = "402.272 9",
        .name         = "Super-Ferrari (1983) (Quelle) (PAL)",
        .note         = "AKA Enduro",
    },{
        .md5          = "2b42da79a682ed6e2d735facbf70107e",
        .name         = "DKjr Improved (Hack)",
        .note         = "Hack of Donkey Kong Jr.",
    },{
        .md5          = "2b430c00dc79e495762ac59b2f9b4fcd",
        .manufacturer = "Activision, David Crane",
        .model        = "AX-018, AX-018-04",
        .name         = "Pitfall! (1982) (Activision) (Prototype)",
    },{
        .md5          = "2b71a59a53be5883399917bf582b7772",
        .manufacturer = "Greg Troutman",
        .name         = "Dark Mage (final beta) (Greg Troutman) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "2ba02f509a4991aa176ba8d9e540df3d",
        .manufacturer = "Atari, Mark R. Hahn",
        .model        = "CX2678",
        .name         = "Dukes of Hazzard (1983) (Atari) [a]",
    },{
        .md5          = "2bb0a1f1dee5226de648eb5f1c97f067",
        .manufacturer = "Robby",
        .name         = "Enduro (Robby)",
    },{
        .md5          = "2bb9f4686f7e08c5fcc69ec1a1c66fe7",
        .manufacturer = "Atari - GCC, John Allred, Mike Feinstein",
        .model        = "CX2688",
        .name         = "Jungle Hunt (1983) (Atari)",
    },{
        .md5          = "2bc26619e31710a9884c110d8430c1da",
        .manufacturer = "Atari, Bob Whitehead",
        .model        = "CX2652, CX2652P",
        .name         = "Casino (1979) (Atari) (PAL)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXIS",
    },{
        .md5          = "2bc6c53b19e0097a242f22375a6a60ff",
        .name         = "Droid Demo 2 (David Conrad Schweinsberg) (PD)",
    },{
        .md5          = "2bee7f226d506c217163bad4ab1768c0",
        .manufacturer = "Xonox - K-Tel Software - Beck-Tech, Steve Beck",
        .model        = "6210, 06002, 06004, 99002",
        .name         = "Ghost Manor (1983) (Xonox)",
    },{
        .md5          = "2bf34b6ad7d2317a2d0808b3fb93571b",
        .name         = "Easy Playfield Graphics (1997) (Chris Cracknell)",
    },{
        .md5          = "2c0dc885d5ede94aa664bf3081add34e",
        .name         = "Earth Dies Screaming, The (Unknown) (PAL)",
    },{
        .md5          = "2c29182edf0965a7f56fe0897d2f84ba",
        .manufacturer = "Atari - Axlon, Steve DeFrisco",
        .model        = "CX26192",
        .name         = "Klax (08-18-1990) (Atari) (Prototype)",
    },{
        .md5          = "2c2aea31b01c6126c1a43e10cacbfd58",
        .manufacturer = "Paul Slocum",
        .name         = "Synthcart (2002) (Paul Slocum)",
        .note         = "Uses Keyboard Controllers",
        .phosphor     = 1,
    },{
        .md5          = "2c3b2843295c9d6b16996971180a3fe9",
        .manufacturer = "HES - Activision",
        .name         = "Sports Action Pak - Enduro, Ice Hockey, Fishing Derby, Dragster (1988) (HES) (PAL)",
    },{
        .md5          = "2c3b9c171e214e9e46bbaa12bdf8977e",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Othello (32 in 1) (BitCorp)",
    },{
        .md5          = "2c45c3eb819a797237820a1816c532eb",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Boxing (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "2c8835aed7f52a0da9ade5226ee5aa75",
        .manufacturer = "Arcadia Corporation, Stephen H. Landrum",
        .model        = "AR-4101",
        .name         = "Communist Mutants from Space (1982) (Arcadia)",
    },{
        .md5          = "2c8c11295d8613f875b7bcf5253ab9bb",
        .manufacturer = "Fabrizio Zavagli",
        .name         = "Kool Aid Man (PAL Conversion) (16-11-2002) (Fabrizio Zavagli) (PAL60)",
        .note         = "PAL60 Conversion",
    },{
        .md5          = "2c9fadd510509cc7f28f1ccba931855f",
        .name         = "Hangman Invader Biglist1 (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "2ca6445204ffb7686ddee3e33ba64d5b",
        .manufacturer = "Alex Herbert",
        .name         = "AtariVox Test ROM",
        .note         = "Uses the AtariVox controller",
        .right        = "ATARIVOX",
    },{
        .md5          = "2cb42cf62b2f25f59f909b5447821b14",
        .manufacturer = "Atari, Christopher H. Omarzu - Children's Computer Workshop",
        .model        = "CX26104",
        .name         = "Big Bird's Egg Catch (1983) (Atari) (PAL) [a]",
        .note         = "Uses Kids/Keyboard Controllers",
        .left         = "KEYBOARD",
        .right        = "KEYBOARD",
    },{
        .md5          = "2cc3049b7feb8e92f1870f1972629757",
        .manufacturer = "Video Soft",
        .name         = "Atom Smasher (1984) (Video Soft) (Prototype) [stack pointer fix]",
    },{
        .md5          = "2cccc079c15e9af94246f867ffc7e9bf",
        .manufacturer = "PlayAround - JHM",
        .model        = "203",
        .name         = "Jungle Fever (1982) (PlayAround)",
        .phosphor     = 1,
    },{
        .md5          = "2cefa695df2ed020899a7df7bb1e3a95",
        .manufacturer = "Manuel Polik, Fabrizio Zavagli",
        .name         = "A-Team (2002) (Manuel Polik) (Hack)",
        .note         = "Hack of A-Team",
    },{
        .md5          = "2cf20f82abcae2decff88db99331e071",
        .manufacturer = "Activision, Mike Lorenzen",
        .model        = "AX-023",
        .name         = "Oink! (1983) (Activision) (8K)",
    },{
        .md5          = "2cfb188c1091cc7ec2a7e60064d2a758",
        .name         = "Space Invaders Hack Demo (2003) (SnailSoft)",
    },{
        .md5          = "2d15b092e8350912ec4b2e5e750fa1c6",
        .manufacturer = "Wizard Video Games, Bob Davis, Robert H. O'Neil",
        .name         = "Texas Chainsaw Massacre, The (1982) (Wizard Video Games) (Prototype)",
    },{
        .md5          = "2d16a8b59a225ea551667be45f554652",
        .manufacturer = "Quelle",
        .model        = "802.744 3",
        .name         = "Der Geheimkurier (1983) (Quelle) (PAL)",
        .note         = "AKA Mr. Postman",
    },{
        .md5          = "2d1af6442d6d5f15de37e47dd5a78411",
        .manufacturer = "Parker Brothers - Roklan, Joe Gaucher",
        .model        = "PB5080",
        .name         = "Gyruss (1983) (Parker Bros) (Prototype) (PAL) [a]",
    },{
        .md5          = "2d1cf85fbc732856bf76470cd4060f4a",
        .name         = "Daredevil (V1) (Stunt_Cycle_Rules!) (PD)",
    },{
        .md5          = "2d2c5f0761e609e3c5228766f446f7f8",
        .manufacturer = "Atari - Axlon, Steve DeFrisco",
        .model        = "CX26170, CX26170P",
        .name         = "Secret Quest (1989) (Atari) (PAL)",
    },{
        .md5          = "2d33a44e82f88d05f6c50577218c0cae",
        .manufacturer = "AtariAge - Michael Haas",
        .model        = "RC2",
        .name         = "Flappy (2014) (AtariAge)",
    },{
        .md5          = "2d38a96f92952b301eefdf25a5e6976b",
        .manufacturer = "Omegamatrix",
        .name         = "Star Wars Arcade (Atari Mouse) (Y_Inverted) v4 (Omegamatrix)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "2d405da70af82b20a6b3ecc3d1d2c4ec",
        .manufacturer = "Genus",
        .name         = "Pitfall (Genus)",
        .note         = "AKA Pitfall!",
    },{
        .md5          = "2d6388a8389f1d59108fd169c3356d79",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Atari Mouse Hack v1.3 (NTSC) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "2d63b452f897818c52b3fceeb080a4d0",
        .manufacturer = "HES - Absolute Entertainment",
        .name         = "Pete Rose Baseball (HES) (PAL)",
    },{
        .md5          = "2d6741cda3000230f6bbdd5e31941c01",
        .manufacturer = "CBS Electronics - VSS",
        .model        = "80110",
        .name         = "Targ (1983) (CBS Electronics) (Prototype)",
    },{
        .md5          = "2d69a5f23784f1c2230143292a073b53",
        .name         = "Qb (Fixed background animation) (2001) (Andrew Davie)",
        .phosphor     = 1,
    },{
        .md5          = "2d6da0eb85eabc93270e5bb8a466ca51",
        .name         = "Sprite Demo 7 (PD)",
    },{
        .md5          = "2d76c5d1aad506442b9e9fb67765e051",
        .manufacturer = "Apollo - Games by Apollo, Larry Minor, Ernie Runyon, Ed Salvo",
        .model        = "AP-2004",
        .name         = "Lost Luggage (1982) (Apollo) [no opening scene]",
        .note         = "AKA Airport Mayhem",
    },{
        .md5          = "2d9e5d8d083b6367eda880e80dfdfaeb",
        .manufacturer = "QDI, Mike Montana, Rich Montana - Selchow & Righter",
        .model        = "87",
        .name         = "Glib (1983) (QDI)",
        .note         = "AKA Video Word Game",
    },{
        .md5          = "2d9e65959808a6098c16c82a59c9d9dc",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum",
        .model        = "AR-4400",
        .name         = "Dragonstomper (1 of 3) (1982) (Starpath) (PAL)",
    },{
        .md5          = "2dbc92688f9ba92a7e086d62be9df79d",
        .name         = "How to Draw a Playfield (1997) (Jim Crawford) (PD)",
    },{
        .md5          = "2dbdca3058035d2b40c734dcf06a86d9",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Asteroids DC+ (Thomas Jentzsch) (Hack)",
        .note         = "Uses the Joystick (left) or Driving (right) Controller",
        .right        = "DRIVING",
        .phosphor     = 1,
    },{
        .md5          = "2dcf9ce486393cd36ca0928cd53b96cb",
        .manufacturer = "Atari - GCC, Mike Feinstein, John Allred",
        .model        = "CX2688, CX2688P",
        .name         = "Jungle Hunt (1983) (Atari) (PAL) [a2]",
    },{
        .md5          = "2de41a11c6767e54a5ee9ebaffec72af",
        .manufacturer = "Gray Games & AtariAge",
        .name         = "E.T. Book Cart (PAL60)",
        .note         = "Charles F. Gray & Michael Rideout",
        .phosphor     = 1,
    },{
        .md5          = "2dfec1615c49501fefc02165c81955e6",
        .name         = "Song (05-11-2002) (Paul Slocum)",
        .phosphor     = 1,
    },{
        .md5          = "2e0aed5bb619edcefa3fafb4fbe7c551",
        .name         = "Qb (2.06) (Retroactive) (NTSC)",
        .phosphor     = 1,
    },{
        .md5          = "2e2acef8513edcca991e7e5149412e11",
        .manufacturer = "Parker Brothers, Larry Gelberg, Gary Goltz",
        .model        = "PB5065",
        .name         = "Star Wars - Ewok Adventure (1983) (Parker Bros) (Prototype) (16K)",
    },{
        .md5          = "2e3728f3086dc3e71047ffd6b2d9f015",
        .manufacturer = "Atari, David Crane",
        .model        = "CX26163P",
        .name         = "Outlaw (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "2e5b184da8a27c4d362b5a81f0b4a68f",
        .manufacturer = "Atari",
        .name         = "Rabbit Transit (08-29-1983) (Atari) (Prototype)",
    },{
        .md5          = "2e663eaa0d6b723b645e643750b942fd",
        .manufacturer = "Atari, Tom Reuterdahl - Sears",
        .model        = "CX2634 - 49-75121",
        .name         = "Golf (1980) (Atari)",
    },{
        .md5          = "2e7e9c6dcfcceaffc6fa73f0d08a402a",
        .manufacturer = "CCE",
        .model        = "C-818",
        .name         = "Star Voyager (1983) (CCE) [a]",
    },{
        .md5          = "2e82a1628ef6c735c0ab8fa92927e9b0",
        .manufacturer = "Atari, Dave Joly, Peter C. Niday, Robert Vieira",
        .model        = "CX26109",
        .name         = "Sorcerer's Apprentice (1983) (Atari) (PAL)",
    },{
        .md5          = "2e842c2ee22e9dad9df16eed091315c4",
        .manufacturer = "HES",
        .model        = "701-157",
        .name         = "2 Pak Special - Moto-cross, Boom Bang (1990) (HES) (PAL)",
    },{
        .md5          = "2eaf8fa9e9fdf1fcfc896926a4bdbf85",
        .manufacturer = "Arcadia Corporation, Stephen H. Landrum",
        .model        = "AR-4400",
        .name         = "Excalibur Version 39 (Dragonstomper Beta) (1982) (Arcadia) (Prototype)",
    },{
        .md5          = "2ec6b045cfd7bc52d9cdfd1b1447d1e5",
        .manufacturer = "Activision, David Crane - Ariola",
        .model        = "EAG-009, PAG-009 - 711 009-720",
        .name         = "Freeway (1981) (Activision) (PAL)",
    },{
        .md5          = "2eda6a49a49fcb2b674ea9e160b6a617",
        .manufacturer = "Kyle Pittman",
        .name         = "Rambo in Afghanistan (Kyle Pittman) (Hack)",
        .note         = "Hack of Riddle of the Sphinx",
    },{
        .md5          = "2ef36341d1bf42e02c7ea2f71e024982",
        .name         = "Space Invaders (Explosion Hack)",
        .note         = "Hack of Space Invaders (Atari)",
    },{
        .md5          = "2f0546c4d238551c7d64d884b618100c",
        .manufacturer = "SEGA, Jeff Lorenz",
        .name         = "Ixion (1984) (SEGA) (Prototype)",
    },{
        .md5          = "2f0a8bb4e18839f9b1dcaa2f5d02fd1d",
        .manufacturer = "CCE",
        .name         = "Super Futebol (CCE) [a]",
        .note         = "AKA RealSports Football",
        .phosphor     = 1,
    },{
        .md5          = "2f11ba54609777e2c6a5da9b302c98e8",
        .manufacturer = "Atari - GCC",
        .model        = "CX2676",
        .name         = "Centipede (1982) (Atari) (Prototype) (PAL)",
    },{
        .md5          = "2f16663b01591539624d0ef52934a17d",
        .manufacturer = "M Network",
        .name         = "Rocky and Bullwinkle",
    },{
        .md5          = "2f2f9061398a74c80420b99ddecf6448",
        .manufacturer = "Rentacom",
        .name         = "Bobby Is Going Home (Rentacom)",
    },{
        .md5          = "2f66ebf037321ed0442ac4b89ce22633",
        .manufacturer = "Baroque Gaming (Billy Eno)",
        .name         = "Warring Worms (Beta 2) (2002) (Baroque Gaming)",
    },{
        .md5          = "2f7772879a1ed04f660aa9d77a86a4bd",
        .name         = "Yars' Revenge (Genesis)",
        .note         = "Genesis controller (C is zorlon cannon)",
        .phosphor     = 1,
    },{
        .md5          = "2f77f015fc880b05f28e84156f989a0c",
        .name         = "Plane Demo (Gonzalo) (PD)",
    },{
        .md5          = "2f7949f71076db42480d3f5036b4a332",
        .name         = "Name This Game (Unknown) (PAL) (Hack)",
    },{
        .md5          = "2facd460a6828e0e476d3ac4b8c5f4f7",
        .manufacturer = "Sancho - Tang's Electronic Co.",
        .name         = "Words-Attack (1983) (Sancho) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "3025bdc30b5aec9fb40668787f67d24c",
        .name         = "Demo Image Series #14 - Two Marios (4K Interleaved Chronocolour Vertical Movement) (05-03-2003) (Andrew Davie)",
    },{
        .md5          = "303242c239474f2d7763b843de58c1c3",
        .manufacturer = "CCE",
        .name         = "Laser Blast (CCE)",
    },{
        .md5          = "304512528a5530a9361e8a231ed9a6de",
        .manufacturer = "Thomas Jentzsch",
        .name         = "River Raid Plus (Thomas Jentzsch) (Hack)",
        .note         = "Hack of River Raid",
    },{
        .md5          = "30512e0e83903fc05541d2f6a6a62654",
        .manufacturer = "Atari, Jim Huether - Sears",
        .model        = "CX2644 - 6-99824",
        .name         = "Flag Capture (1978) (Atari)",
        .note         = "AKA Capture the Flag",
    },{
        .md5          = "30516cfbaa1bc3b5335ee53ad811f17a",
        .manufacturer = "Wizard Video Games - VSS - MicroGraphic Image, Robert Barber, Tim Martin",
        .model        = "007",
        .name         = "Halloween (1983) (Wizard Video Games)",
    },{
        .md5          = "3051b6071cb26377cd428af155e1bfc4",
        .manufacturer = "Atari, David Crane - Sears",
        .model        = "CX2607 - 6-99828, 49-75115",
        .name         = "Canyon Bomber (1979) (Atari) (4K)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXDR",
        .swapPaddles  = 1,
    },{
        .md5          = "30685b9b6ebd9ba71536dd7632a1e3b6",
        .manufacturer = "Dactari - Milmar",
        .name         = "Tennis (Dactari)",
    },{
        .md5          = "3091af0ef1a61e801f4867783c21d45c",
        .manufacturer = "CCE",
        .model        = "C-862",
        .name         = "Crackpots (1983) (CCE) [a]",
    },{
        .md5          = "30997031b668e37168d4d0e299ccc46f",
        .name         = "John K Harvey's Equalizer (PAL) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "30c92c685224dc7a72b9bbe5eb62d004",
        .name         = "Hangman Monkey Original Words (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "30e012e8d50330c8972f126b8e913bc4",
        .name         = "Indy 500 (Hack) [a2]",
        .note         = "Hack of Indy 500",
        .left         = "DRIVING",
        .right        = "DRIVING",
    },{
        .md5          = "30e0ab8be713208ae9a978b34e9e8e8c",
        .manufacturer = "Atari, Mike Lorenzen",
        .model        = "CX2630, CX2630P",
        .name         = "Circus Atari (1980) (Atari) (PAL)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "30f0b49661cfcfd4ec63395fab837dc3",
        .manufacturer = "SEGA, Jeff Lorenz - Teldec",
        .model        = "004-01 - 3.60103 VG",
        .name         = "Star Trek - Strategic Operations Simulator (1983) (SEGA) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "3105967f7222cc36a5ac6e5f6e89a0b4",
        .manufacturer = "SEGA, Jeff Lorenz",
        .model        = "011-01, 011-02",
        .name         = "Spy Hunter (1984) (SEGA)",
        .note         = "Uses Joystick Coupler (Dual Control Module)",
    },{
        .md5          = "310ba30e25ea8957e58180b663503c0c",
        .manufacturer = "Ed Federmeyer",
        .name         = "Sound X6 (1994) (Ed Federmeyer)",
    },{
        .md5          = "31235a27b065c2863048fa84db330dc6",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Control - Amiga Mouse Hack v1.15 (PAL) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "313243fc41e49ef6bd3aa9ebc0d372dd",
        .name         = "Fast Food (Unknown) (PAL)",
    },{
        .md5          = "31512cdfadfd82bfb6f196e3b0fd83cd",
        .manufacturer = "Tigervision",
        .model        = "7-004",
        .name         = "River Patrol (1984) (Tigervision)",
    },{
        .md5          = "3177cc5c04c1a4080a927dfa4099482b",
        .manufacturer = "Atari - Imagineering, Alex DeMeo",
        .model        = "CX26135",
        .name         = "RealSports Boxing (1987) (Atari)",
    },{
        .md5          = "317a4cdbab090dcc996833d07cb40165",
        .manufacturer = "Video Game - Ariola",
        .model        = "SP-204",
        .name         = "Sternkrieg (1983) (Ariola) (PAL)",
        .note         = "AKA Astrowar",
    },{
        .md5          = "318046ae3711c05fd16e479b298e5fcc",
        .manufacturer = "Retroactive",
        .name         = "Qb (V2.08) (Stella) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "318a9d6dda791268df92d72679914ac3",
        .manufacturer = "Activision, Steve Cartwright",
        .model        = "AX-017, AX-017-04",
        .name         = "MegaMania (1982) (Activision)",
    },{
        .md5          = "319a142aab6260842ab616382848c204",
        .name         = "Marble Craze (05-02-2002) (Paul Slocum)",
    },{
        .md5          = "31bb9b8ceed46cb3e506777a9e65f3ce",
        .manufacturer = "Bit Corporation",
        .name         = "4 Game in One Light Green (1983) (BitCorp) (PAL)",
        .note         = "Phantom UFO, Ice Hockey, Cosmic Avenger, Spy Vs. Spy",
        .type         = "4IN1",
    },{
        .md5          = "31c5fd55a39db5ff30a0da065f86c140",
        .manufacturer = "Dactari - Milmar",
        .name         = "Enduro (1983) (Dactari)",
    },{
        .md5          = "31d08cb465965f80d3541a57ec82c625",
        .manufacturer = "Atari, Alan Miller - Sears",
        .model        = "CX2641 - 99807, 49-75105",
        .name         = "Surround (1977) (Atari) (4K)",
    },{
        .md5          = "31df1c50c4351e144c9a378adb8c10ba",
        .manufacturer = "Quelle",
        .model        = "687.463 0",
        .name         = "Die Ratte und die Karotten (1983) (Quelle) (PAL)",
        .note         = "AKA Gopher",
    },{
        .md5          = "31e518debba46df6226b535fa8bd2543",
        .manufacturer = "Atari, Douglas 'Solaris' Neubauer, Mimi Nyden",
        .model        = "CX26134",
        .name         = "Last Starfighter (1984) (Atari) (Prototype)",
        .note         = "Solaris Beta",
    },{
        .md5          = "31f4692ee2ca07a7ce1f7a6a1dab4ac9",
        .manufacturer = "Atari, Alan Miller",
        .model        = "CX2642",
        .name         = "Game of Concentration (1980) (Atari) (4K)",
        .note         = "Uses Keyboard Controllers",
    },{
        .md5          = "31fcbce1cfa6ec9f5b6de318e1f57647",
        .manufacturer = "Atari, Jerome Domurat, Peter C. Niday",
        .model        = "CX26115",
        .name         = "Dumbo's Flying Circus (1983) (Atari) (Prototype) (PAL)",
        .note         = "AKA Dumbo Flies Home",
    },{
        .md5          = "32199271dc980eb31a2cc96e10a9e244",
        .name         = "Radial Pong - Version 12 (Jeffry Johnston) (PD)",
    },{
        .md5          = "321c3451129357af42a375d12afd4450",
        .manufacturer = "Atari - Imagineering, Dan Kitchen",
        .model        = "CX26177",
        .name         = "Ikari Warriors (1991) (Atari) (PAL)",
    },{
        .md5          = "32244e55ce6ec6bfbd763f33384bdc2e",
        .manufacturer = "Activision, Steve Cartwright",
        .model        = "AX-027",
        .name         = "Plaque Attack (1983) (Activision) (16K)",
    },{
        .md5          = "3225676f5c0c577aeccfaa7e6bedd765",
        .manufacturer = "CCE",
        .model        = "C-1002",
        .name         = "Pole Position (1983) (CCE)",
    },{
        .md5          = "322b29e84455aa41e7cc9af463bffa89",
        .manufacturer = "Atari - Bobco, Robert C. Polaro",
        .model        = "CX2663",
        .name         = "Road Runner (06-25-1984) (Atari) (Prototype)",
    },{
        .md5          = "324cb4a749bcac4f3db9da842b85d2f7",
        .manufacturer = "Dennis Debro",
        .name         = "Climber 5 (01-05-2003) (Dennis Debro)",
    },{
        .md5          = "327468d6c19697e65ab702f06502c7ed",
        .manufacturer = "Charles Morgan",
        .name         = "Aster-Hawk (2002) (Charles Morgan) (Hack)",
        .note         = "Hack of Asteroids",
        .phosphor     = 1,
    },{
        .md5          = "3276c777cbe97cdd2b4a63ffc16b7151",
        .manufacturer = "Atari - GCC, Mike Feinstein, Kevin Osborn",
        .model        = "CX2691",
        .name         = "Joust (1983) (Atari)",
        .phosphor     = 1,
    },{
        .md5          = "3278158e5c1f7eb5c5d28ccfd7285250",
        .manufacturer = "Dactari - Milmar",
        .name         = "Megamania (Dactari)",
    },{
        .md5          = "327fe8cf94f3a45c35a840a453df1235",
        .name         = "Spice Girls Rule Demo (PD)",
    },{
        .md5          = "328949872e454181223a80389d03c122",
        .name         = "Home Run (Unknown) (PAL)",
        .swapPorts    = 1,
    },{
        .md5          = "32ae78abbb5e677e2aabae5cc86cec29",
        .manufacturer = "Atari, Christopher H. Omarzu, Courtney Granner",
        .model        = "CX26112",
        .name         = "Good Luck, Charlie Brown (04-18-1984) (Atari) (Prototype)",
        .note         = "Prototype",
    },{
        .md5          = "32d1260ea682e1bb10850fa94c04ec5f",
        .manufacturer = "Atari, Alan Miller",
        .model        = "CX26163P",
        .name         = "Basketball (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "32dcd1b535f564ee38143a70a8146efe",
        .manufacturer = "Xonox - K-Tel Software - Product Guild, Anthony R. Henderson",
        .model        = "99007, 6240",
        .name         = "Tomarc the Barbarian (1983) (Xonox)",
        .note         = "AKA Thundarr the Barbarian",
    },{
        .md5          = "32e65d1e4dfcbcd9b57fee72cafe074c",
        .name         = "Eckhard Stolberg's Scrolling Text Demo 3 (PD)",
    },{
        .md5          = "32ecb5a652eb73d287e883eea751d99c",
        .manufacturer = "Dactar - Milmar",
        .name         = "Bowling (Dactar - Milmar)",
    },{
        .md5          = "32f4e47a71601ab06cfb59e1c6a0b846",
        .manufacturer = "Ed Federmeyer",
        .name         = "Sound X (1994) (Ed Federmeyer)",
    },{
        .md5          = "3316ee2f887e9cb9b54dd23c5b98c3e2",
        .name         = "Texas Golf (miniature Gold Hack)",
    },{
        .md5          = "331938989f0f33ca39c10af4c09ff640",
        .manufacturer = "Zach Matley",
        .name         = "Combat - Tank AI (19-04-2003) (Zach Matley)",
    },{
        .md5          = "332f01fd18e99c6584f61aa45ee7791e",
        .name         = "X'Mission (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "3347a6dd59049b15a38394aa2dafa585",
        .manufacturer = "Parker Brothers - JWDA, Henry Will IV",
        .model        = "PB5760",
        .name         = "Montezuma's Revenge (1984) (Parker Bros)",
        .note         = "Featuring Panama Joe",
    },{
        .md5          = "335793736cbf6fc99c9359ed2a32a49d",
        .name         = "Analog Clock (V0.0) (20-01-2003) (Andrew Davie) [a]",
    },{
        .md5          = "335a7c5cfa6fee0f35f5824d1fa09aed",
        .manufacturer = "SEGA - Beck-Tech, Steve Beck, Phat Ho - Teldec",
        .model        = "006-01 - 3.60105 VG",
        .name         = "Congo Bongo (1983) (SEGA) (PAL)",
    },{
        .md5          = "3367eeba3269aa04720abe6169767502",
        .name         = "Space Treat (30-12-2002) (Fabrizio Zavagli)",
    },{
        .md5          = "336ea20d38f98926919d4b4651d1a03f",
        .manufacturer = "Omegamatrix",
        .name         = "Omega Race (Genesis) V2",
        .note         = "Genesis controller",
    },{
        .md5          = "3391f7c4c656793f92299f4187e139f7",
        .manufacturer = "Commavid, Ben Burch",
        .model        = "CM-010",
        .name         = "Rush Hour (1983) (Commavid) (Prototype) [a4]",
    },{
        .md5          = "33cac5e767a534c95d292b04f439dc37",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Tapeworm (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "33d68c3cd74e5bc4cf0df3716c5848bc",
        .manufacturer = "CBS Electronics, Tom DiDomenico",
        .model        = "4L 2486 5000",
        .name         = "Blueprint (1983) (CBS Electronics)",
        .phosphor     = 1,
    },{
        .md5          = "33ed6dfac4b9ea2f81f778ceddbb4a75",
        .manufacturer = "Activision",
        .name         = "River Raid (1982) (SpkSoft) [t1]",
    },{
        .md5          = "340f546d59e72fb358c49ac2ca8482bb",
        .manufacturer = "Sancho - Tang's Electronic Co.",
        .model        = "TEC003",
        .name         = "Skindiver (1983) (Sancho) (PAL)",
    },{
        .md5          = "34340c8eecd1e557314789cc6477e650",
        .manufacturer = "Joe Grand",
        .name         = "SCSIcide Pre-release 4 (Joe Grand)",
    },{
        .md5          = "345488d3b014b684a181108f0ef823cb",
        .manufacturer = "CBS Electronics, Tom DiDomenico",
        .model        = "4L 2486 5000",
        .name         = "Blueprint (1983) (CBS Electronics) (Prototype)",
    },{
        .md5          = "345758747b893e4c9bdde8877de47788",
        .manufacturer = "CBS Electronics, Joseph Biel",
        .model        = "4L1802, 4L1803, 4L1804, 4L2278",
        .name         = "Venture (1983) (CBS Electronics) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "345769d085113d57937198262af52298",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-007",
        .name         = "Space Raid (1983) (Rainbow Vision) (PAL)",
        .note         = "AKA MegaMania",
    },{
        .md5          = "346555779a2d51b48833463b5433472f",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Thrust (V0.1) (2000) (Thomas Jentzsch)",
    },{
        .md5          = "348615ffa30fab3cec1441b5a76e9460",
        .manufacturer = "Activision, Alan Miller - Ariola",
        .model        = "EAX-016, PAX-016 - 711 016-725",
        .name         = "StarMaster (1982) (Activision) (PAL) [fixed]",
        .note         = "Use Color/BW switch to change between galactic chart and front views",
    },{
        .md5          = "34b269387fa1aa5a396636f5ecdd63dd",
        .name         = "Marble Craze (mc7_23) (Paul Slocum)",
    },{
        .md5          = "34c808ad6577dbfa46169b73171585a3",
        .manufacturer = "Apollo",
        .model        = "AP-2012",
        .name         = "Squoosh (1983) (Apollo) (Prototype)",
        .note         = "AKA Vat's Incredible!, The Grape Escape",
    },{
        .md5          = "34ca2fcbc8ba4a0b544acd94991cfb50",
        .manufacturer = "Atari, Robert C. Polaro",
        .name         = "Dukes of Hazzard (1980) (Atari) (Prototype) (4K)",
        .note         = "AKA Stunt Cycle",
    },{
        .md5          = "34e37eaffc0d34e05e40ed883f848b40",
        .manufacturer = "Retroactive",
        .name         = "Qb (2.15) (Retroactive) (Stella)",
        .phosphor     = 1,
    },{
        .md5          = "34f4b1d809aa705ace6e46b13253fd3b",
        .manufacturer = "Aaron Bergstrom",
        .name         = "Nothern Alliance (Aaron Bergstrom) (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "34fd4fcb40ff5babce67f8b806d5969c",
        .name         = "Boxing (Dactari) (4K)",
    },{
        .md5          = "350e0f7b562ec5e457b3f5af013648db",
        .manufacturer = "Atari, Jerome Domurat, Howard Scott Warshaw",
        .model        = "CX26119",
        .name         = "Saboteur (06-09-1983) (Atari) (Prototype)",
    },{
        .md5          = "35156407e54f67eb1f625450d5c093e1",
        .name         = "Mouse Trap (Genesis)",
        .note         = "Genesis controller (C changes to dog)",
    },{
        .md5          = "35163b56f4a692a232ae96ad3e23310f",
        .manufacturer = "Retroactive",
        .name         = "Qb (2.12) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "3545eb3b8b1e7dc19f87d231ab0b1d4c",
        .manufacturer = "CBS Electronics - Roklan, Joe Hellesen, Joe Wagner",
        .model        = "M8774, M8794",
        .name         = "Wizard of Wor (1982) (CBS Electronics) (Prototype)",
    },{
        .md5          = "3556e125681aea864e17b09f3f3b2a75",
        .name         = "Incoming (2 Player Demo) (PD)",
    },{
        .md5          = "3576037c9281656655fa114a835be553",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4200",
        .name         = "Escape from the Mindmaster (1 of 4) (1982) (Arcadia) (PAL)",
    },{
        .md5          = "3577e19714921912685bb0e32ddf943c",
        .manufacturer = "TechnoVision - Video Technology",
        .model        = "TVS1003",
        .name         = "Pharaoh's Curse (1983) (TechnoVision) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "35ae903dff7389755ad4a07f2fb7400c",
        .name         = "Colored Wall Demo (PD)",
    },{
        .md5          = "35b10a248a7e67493ec43aeb9743538c",
        .manufacturer = "Dor-x",
        .name         = "Defender (Dor-x) (Hack)",
        .note         = "Hack of Defender",
    },{
        .md5          = "35b43b54e83403bb3d71f519739a9549",
        .manufacturer = "Parker Brothers, Dave Engman, Isabel Garret",
        .name         = "McDonald's (06-06-1983) (Parker Bros) (Prototype)",
    },{
        .md5          = "35be55426c1fec32dfb503b4f0651572",
        .manufacturer = "Men-A-Vision",
        .name         = "Air Raid (Men-A-Vision) (NTSC)",
        .format       = "NTSC50",
        .phosphor     = 1,
    },{
        .md5          = "35fa32256982774a4f134c3347882dff",
        .manufacturer = "Retroactive",
        .name         = "Qb (V0.05) (Macintosh) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "360ba640f6810ec902b01a09cc8ab556",
        .manufacturer = "Atari, Jerome Domurat, Steve Woita",
        .model        = "CX2699",
        .name         = "Taz (06-15-1983) (Atari) (Prototype) (PAL)",
    },{
        .md5          = "360c0dcb11506e73bd0b77207c81bc62",
        .manufacturer = "Digitel",
        .name         = "Enduro (1983) (Digitel)",
    },{
        .md5          = "3619786f6a32efc1e4a262d5aca8a070",
        .manufacturer = "Atari, John Dunn - Sears",
        .model        = "CX2631 - 49-75152",
        .name         = "Superman (1979) (Atari) (8K)",
    },{
        .md5          = "3624e5568368929fabb55d7f9df1022e",
        .manufacturer = "Activision - Imagineering, Donald Hahn, Dan Kitchen",
        .model        = "EAK-050-04",
        .name         = "Double Dragon (1989) (Activision) (PAL)",
    },{
        .md5          = "36306070f0c90a72461551a7a4f3a209",
        .manufacturer = "U.S. Games Corporation - JWDA, Roger Booth, Sylvia Day, Ron Dubren, Todd Marshall, Robin McDaniel, Wes Trager, Henry Will IV",
        .model        = "VC1007",
        .name         = "Name This Game (1983) (U.S. Games)",
        .note         = "AKA Guardians of Treasure, Octopussy",
    },{
        .md5          = "36547bc6faa5132b87504e18d088e1d7",
        .name         = "Cosmic Swarm (Unknown) (PAL) (4K)",
        .phosphor     = 1,
    },{
        .md5          = "367411b78119299234772c08df10e134",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Skiing (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "3685060707df27d4091ba0ea2dc4b059",
        .name         = "PezZerk - PezMan in Ghost Manor (Hack)",
        .note         = "Hack of Berzerk",
    },{
        .md5          = "368d88a6c071caba60b4f778615aae94",
        .manufacturer = "Atari, Matthew L. Hubbard",
        .model        = "CX26159",
        .name         = "Double Dunk (1989) (Atari)",
        .note         = "AKA Super Basketball",
    },{
        .md5          = "36a701c60a9f9768d057bc2a83526a80",
        .name         = "Cube Conquest (Interlaced) (Billy Eno) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "36b20c427975760cb9cf4a47e41369e4",
        .manufacturer = "Coleco - Woodside Design Associates - Imaginative Systems Software, Garry Kitchen",
        .model        = "2451",
        .name         = "Donkey Kong (1982) (Coleco)",
    },{
        .md5          = "36c29ceee2c151b23a1ad7aa04bd529d",
        .manufacturer = "Atari - GCC, Ava-Robin Cohen",
        .model        = "CX26123",
        .name         = "Jr. Pac-Man (1986) (Atari)",
    },{
        .md5          = "36c31bb5daeb103f488c66de67ac5075",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4302",
        .name         = "Party Mix - Bop a Buggy (1 of 3) (1983) (Arcadia)",
        .note         = "Uses Paddle Controllers",
    },{
        .md5          = "36c993dc328933e4dd6374a8ffe224f4",
        .manufacturer = "Gameworld, J. Ray Dettling",
        .model        = "133-007",
        .name         = "Bermuda Triangle (1983) (Gameworld) (PAL)",
    },{
        .md5          = "36e47ed74968c365121eab60f48c6517",
        .manufacturer = "Quelle",
        .model        = "343.373 7",
        .name         = "Master Builder (1983) (Quelle) (PAL)",
    },{
        .md5          = "36edef446ab4c2395666efc672b92ed0",
        .manufacturer = "Atari - Axlon, John Vifian",
        .model        = "CX26168",
        .name         = "Off the Wall (1989) (Atari) (PAL)",
    },{
        .md5          = "36f9a953ebdd9a8be97ccf27a2041903",
        .name         = "Chinese Character Demo (PD)",
    },{
        .md5          = "37252757a79dc5b174e3c03d6ea0bdcb",
        .name         = "Sky Diver (Unknown) (PAL) (4K) (Hack)",
    },{
        .md5          = "372bddf113d088bc572f94e98d8249f5",
        .manufacturer = "Bomb - Onbase",
        .model        = "CA285",
        .name         = "Wall-Defender (1983) (Bomb) (PAL)",
        .note         = "AKA Wall Break",
    },{
        .md5          = "373b8a081acd98a895db0cb02df35673",
        .name         = "Demo Image Series #5 - Boofly (19-02-2003) (Andrew Davie)",
    },{
        .md5          = "3750f2375252b6a20e4628692e94e8b1",
        .manufacturer = "Dismac",
        .name         = "Ases do Ar (Dismac)",
        .note         = "AKA Sky Jinks",
    },{
        .md5          = "37527966823ee9243d34c7da8302774f",
        .name         = "Word Zapper (Unknown) (PAL)",
    },{
        .md5          = "376944889dcfa96c73d3079f308e3d32",
        .manufacturer = "Retroactive",
        .name         = "Qb (0.11) (Retroactive) (Stella)",
        .phosphor     = 1,
    },{
        .md5          = "3783f12821b88b08814da8adb1a9f220",
        .name         = "Mission Survive (PAL) (Genesis)",
        .note         = "Genesis controller (C is vertical fire)",
        .phosphor     = 1,
    },{
        .md5          = "378a62af6e9c12a760795ff4fc939656",
        .manufacturer = "Atari - Axlon, Steve DeFrisco",
        .model        = "CX26171",
        .name         = "MotoRodeo (1991) (Atari)",
        .phosphor     = 1,
    },{
        .md5          = "378c118b3bda502c73e76190ca089eef",
        .manufacturer = "Atari, Alan Miller",
        .model        = "CX2662P",
        .name         = "Hangman (1978) (Atari) (PAL)",
    },{
        .md5          = "37ab3affc7987995784b59fcd3fcbd31",
        .name         = "Sprite Test (29-11-2002) (Eric Ball)",
    },{
        .md5          = "37b98344c8e0746c486caf5aaeec892a",
        .manufacturer = "K-Tel Vision",
        .model        = "6",
        .name         = "Spider Maze (1982) (K-Tel Vision) (PAL)",
        .note         = "AKA Spider Kong",
    },{
        .md5          = "37e828675d556775ae8285c0caf7d11c",
        .manufacturer = "AtariAge - Fred Quimby",
        .name         = "Gingerbread Man (Fred Quimby) (Genesis)",
        .note         = "Genesis controller (C throws cookie)",
        .left         = "GENESIS",
    },{
        .md5          = "37f42ab50018497114f6b0f4f01aa9a1",
        .name         = "Droid Demo 2-M (David Conrad Schweinsberg) (PD)",
    },{
        .md5          = "37fd7fa52d358f66984948999f1213c5",
        .name         = "Pyramid War (Unknown) (PAL) [a]",
        .note         = "AKA Chopper Command",
    },{
        .md5          = "384db97670817103dd8c0bbdef132445",
        .manufacturer = "Atari - Sears",
        .model        = "CX2626 - 6-99829, 49-75116",
        .name         = "Miniature Golf (1979) (Atari) (4K)",
    },{
        .md5          = "384f5fbf57b5e92ed708935ebf8a8610",
        .manufacturer = "20th Century Fox Video Games, John W.S. Marvin",
        .model        = "11009",
        .name         = "Crypts of Chaos (1983) (20th Century Fox)",
    },{
        .md5          = "3856b9425cc0185ed770376a62af0282",
        .manufacturer = "Kyle Pittman",
        .name         = "Yellow Submarine (Kyle Pittman) (Hack)",
        .note         = "Hack of Bermuda Triangle",
    },{
        .md5          = "386ff28ac5e254ba1b1bac6916bcc93a",
        .manufacturer = "Arcadia Corporation, Scott Nelson",
        .model        = "AR-4300",
        .name         = "Fireball (1982) (Arcadia)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "3882224adbd0ca7c748b2a1c9b87263e",
        .manufacturer = "Atari, Tod Frye",
        .model        = "CX2657",
        .name         = "SwordQuest - FireWorld (1982) (Atari) (PAL) [a]",
    },{
        .md5          = "3889351c6c2100b9f3aef817a7e17a7a",
        .manufacturer = "CCE",
        .name         = "Dolphin (CCE)",
    },{
        .md5          = "3897744dd3c756ea4b1542e5e181e02a",
        .manufacturer = "Atari, Jerome Domurat, Peter C. Niday",
        .model        = "CX26115",
        .name         = "Dumbo's Flying Circus (05-05-1983) (Atari) (Prototype)",
        .note         = "AKA Dumbo Flies Home",
    },{
        .md5          = "38bd172da8b2a3a176e517c213fcd5a6",
        .manufacturer = "Atari",
        .model        = "MA017600",
        .name         = "Diagnostic Test Cartridge 2.6 (1982) (Atari)",
    },{
        .md5          = "38c362dcd5cad5a62e73ae52631bd9d8",
        .manufacturer = "Jake Patterson",
        .name         = "Baubles (14-11-2001) (Jake Patterson) (PD)",
    },{
        .md5          = "38cf93eacfb2fa9a2c5e39059ff35a74",
        .manufacturer = "Greg Zumwalt",
        .name         = "WacMan (2003) (Greg Zumwalt) (Hack)",
        .note         = "Hack of Ms. Pac-Man",
    },{
        .md5          = "38de7b68379770b9bd3f7bf000136eb0",
        .manufacturer = "Imagic, Mark Klein",
        .model        = "EIZ-003-04I",
        .name         = "Subterranea (1983) (Imagic) (PAL)",
    },{
        .md5          = "391764720140c432aec454a468f77a40",
        .manufacturer = "Video Game Program",
        .name         = "Miss Pack Man (Video Game Program) (PAL)",
        .note         = "AKA Ms. Pac-Man",
    },{
        .md5          = "392d34c0498075dd58df0ce7cd491ea2",
        .manufacturer = "Atari, Frank Hausman, Mimi Nyden, Steve Woita",
        .model        = "CX2686",
        .name         = "Quadrun (1983) (Atari) (Prototype)",
    },{
        .md5          = "392f00fd1a074a3c15bc96b0a57d52a1",
        .manufacturer = "Atari, Rob Fulop - Sears",
        .model        = "CX2633 - 49-75119",
        .name         = "Night Driver (1980) (Atari)",
        .note         = "Uses the Paddle Controllers (left only)",
        .phosphor     = 1,
    },{
        .md5          = "393948436d1f4cc3192410bb918f9724",
        .manufacturer = "Activision, Carol Shaw",
        .model        = "AX-020, AX-020-04",
        .name         = "River Raid (1982) (Activision)",
    },{
        .md5          = "393e41ca8bdd35b52bf6256a968a9b89",
        .manufacturer = "U.S. Games Corporation - Western Technologies, John Hall",
        .model        = "VC1012",
        .name         = "M.A.D. (1983) (U.S. Games)",
        .note         = "AKA Missile Intercept, Mutually Assured Destruction",
    },{
        .md5          = "3947eb7305b0c904256cdbc5c5956c0f",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Lilly Adventure (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "396f7bc90ab4fa4975f8c74abe4e81f0",
        .manufacturer = "Atari, Larry Kaplan - Sears",
        .model        = "CX2612 - 99804, 49-75103",
        .name         = "Street Racer (1977) (Atari)",
        .note         = "Uses the Paddle Controllers (swapped)",
        .swapPaddles  = 1,
    },{
        .md5          = "3974e2d1f614fbd3a092533ecae2e84d",
        .manufacturer = "Alessandro Ciceri",
        .name         = "MagiCard+ (alex_79) WIP_20150118",
        .note         = "MagiCard hack",
    },{
        .md5          = "39790a2e9030751d7db414e13f1b6960",
        .name         = "Robotfindskitten2600 (26-04-2003) (Jeremy Penner) [a1]",
    },{
        .md5          = "39a6a5a2e1f6297cceaa48bb03af02e9",
        .name         = "Pitfall 2 Plus (Hack)",
        .note         = "Hack of Pitfall 2",
    },{
        .md5          = "39b94d41bd3b01c12b4054c1a8733783",
        .manufacturer = "SOLID Corp. (D. Scott Williamson)",
        .model        = "CX2655-016",
        .name         = "Star Castle 2600 (SolidCorp) [016]",
        .phosphor     = 1,
    },{
        .md5          = "39c78d682516d79130b379fa9deb8d1c",
        .manufacturer = "Apollo - Games by Apollo, Ed Salvo",
        .model        = "AP-1001",
        .name         = "Skeet Shoot (1981) (Apollo)",
    },{
        .md5          = "39d36366ae7e6dfd53393fb9ebab02a0",
        .manufacturer = "CCE",
        .model        = "C-811",
        .name         = "River Raid (1983) (CCE) [a]",
    },{
        .md5          = "39da69ff9833f8c143f03b6e0e7a996b",
        .manufacturer = "Charles Morgan",
        .name         = "Ventrra Invaders 2002 (Charles Morgan) (Hack)",
        .note         = "Hack of Megamania",
    },{
        .md5          = "39fe316952134b1277b6a81af8e05776",
        .manufacturer = "Robby",
        .model        = "18",
        .name         = "River Raid (Robby)",
    },{
        .md5          = "3a10562937a766cbbb77203d029b00e1",
        .manufacturer = "Carrere Video - JWDA, Garry Kitchen, Paul Willson - Teldec - Prism",
        .model        = "USC1002",
        .name         = "Sneak 'n Peek (1983) (Carrere Video) (PAL)",
        .note         = "AKA Der Unsichtbare",
    },{
        .md5          = "3a2e2d0c6892aa14544083dfb7762782",
        .manufacturer = "Atari, Rob Fulop - Sears",
        .model        = "CX2638 - 49-75166",
        .name         = "Missile Command (1981) (Atari)",
        .phosphor     = 1,
    },{
        .md5          = "3a35d7f1dc2a33565c8dca52baa86bc4",
        .name         = "Rubik's Cube Demo 2 (23-12-2002) (Christopher Tumber)",
    },{
        .md5          = "3a51a6860848e36e6d06ffe01b71fb13",
        .manufacturer = "Retroactive",
        .name         = "Qb (2.07) (Retroactive) (NTSC)",
        .phosphor     = 1,
    },{
        .md5          = "3a521b7e29123b2d38e34e3ff8dc255c",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Atari Mouse Hack v1.4 (NTSC) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "3a526e6a1f9fe918af0f2ce997dfea73",
        .manufacturer = "CBS Electronics, Dan Kitchen, Garry Kitchen",
        .model        = "4L1700, 4L1701, 4L1702, 4L1802, 4L2274",
        .name         = "Donkey Kong (1982) (CBS Electronics) (PAL) [a1]",
    },{
        .md5          = "3a53963f053b22599db6ac9686f7722f",
        .name         = "Word Zapper (Unknown) (PAL) [a]",
    },{
        .md5          = "3a771876e4b61d42e3a3892ad885d889",
        .manufacturer = "Atari, Bill Aspromonte, Andrew Fuchs",
        .model        = "CX26120",
        .name         = "Defender II (1987) (Atari)",
        .note         = "AKA Stargate",
    },{
        .md5          = "3a98b97b3df21715816b6ad62e843dad",
        .manufacturer = "Digivision",
        .name         = "Planet Patrol (Digivision) (PAL)",
    },{
        .md5          = "3aad0ef62885736a5b8c6ccac0dbe00c",
        .manufacturer = "Dynacom",
        .name         = "Atlantis (1983) (Dynacom)",
    },{
        .md5          = "3ab5d138e26d88c8190e7cc629a89493",
        .name         = "Phased Color Demo (PD)",
        .phosphor     = 1,
    },{
        .md5          = "3ac6c50a8e62d4ce71595134cbd8035e",
        .manufacturer = "Absolute Entertainment, Dan Kitchen",
        .model        = "AK-046-04",
        .name         = "Tomcat (1988) (Absolute)",
    },{
        .md5          = "3ad3dc799211ccd424d7c6d454401436",
        .manufacturer = "Probe 2000 - NAP",
        .name         = "Power Lords (1983) (Probe) (Prototype)",
    },{
        .md5          = "3ad58b53a1e972396890bd86c735e78d",
        .manufacturer = "Arcadia Corporation, Stephen H. Landrum",
        .model        = "AR-4400",
        .name         = "Excalibur Version 36 (Dragonstomper Beta) (1982) (Arcadia) (Prototype)",
    },{
        .md5          = "3b040ed7d1ef8acb4efdeebebdaa2052",
        .manufacturer = "Tigervision",
        .model        = "7-008",
        .name         = "Miner 2049er (1983) (Tigervision) [fixed]",
    },{
        .md5          = "3b097a7ed5bd2a84dc3d3ed361e9c31c",
        .name         = "Interleaved ChronoColour Demo (PAL) (05-03-2003) (Andrew Davie)",
    },{
        .md5          = "3b10106836565e5db28c7823c0898fbb",
        .manufacturer = "Xonox - Beck-Tech",
        .model        = "6210, 06002, 06004, 99002",
        .name         = "Ghost Manor (1983) (Xonox) (PAL) [a]",
    },{
        .md5          = "3b2c32fcd331664d037952bcaa62df94",
        .manufacturer = "Xonox",
        .model        = "6230, 6250",
        .name         = "Super Kung-Fu (1983) (Xonox) (PAL) [a]",
    },{
        .md5          = "3b5751a8d20f7de41eb069f76fecd5d7",
        .name         = "Eckhard Stolberg's Scrolling Text Demo 4 (PD)",
    },{
        .md5          = "3b64a00ce147c3c29f7f8f8e531d08d8",
        .name         = "This Planet Sucks (16K) (Greg Troutman)",
    },{
        .md5          = "3b69f8929373598e1752f43f8da61aa4",
        .manufacturer = "Apollo - Games by Apollo - RCA Video Jeux",
        .model        = "AP-2006",
        .name         = "Infiltrate (1921) (Apollo) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "3b6dba1a24bb2893bd3bd0593f92016b",
        .manufacturer = "CBS Electronics / Thomas Jentzsch",
        .name         = "Omega Race JS (Thomas Jentzsch)",
        .note         = "Hack of Omega Race (CBS Electronics)",
    },{
        .md5          = "3b76242691730b2dd22ec0ceab351bc6",
        .manufacturer = "M Network - INTV, Connie Goldman, Joe King, Patricia Lewis Du Long, Gerald Moore, Mike Sanders, Jossef Wagner",
        .model        = "MT4319",
        .name         = "Masters of the Universe (1983) (M Network)",
        .phosphor     = 1,
    },{
        .md5          = "3b80b8f52a0939e16b5059f93a3fc19a",
        .manufacturer = "V007",
        .name         = "Virtual Pet (V007) (after Demo 2) (CRACKERS) (PD)",
    },{
        .md5          = "3b86a27132fb74d9b35d4783605a1bcb",
        .manufacturer = "Atari, Chris Crawford",
        .name         = "Wizard (1980) (Atari) (Prototype) (4K)",
    },{
        .md5          = "3b8aacf5f5638492b926b5124de19f18",
        .manufacturer = "Atari, Tod Frye - Sears",
        .model        = "CX2646 - 49-75185",
        .name         = "Pac-Man (1981) (Atari) (8K)",
    },{
        .md5          = "3b91c347d8e6427edbe942a7a405290d",
        .manufacturer = "Parker Brothers",
        .model        = "PB5350",
        .name         = "Sky Skipper (1983) (Parker Bros)",
    },{
        .md5          = "3b9480bb6fb1e358c9c0a64e86945aee",
        .name         = "Title Match Pro Wrestling (2002) (Skyworks)",
    },{
        .md5          = "3b966bf3c2ca34ac6ca1de4cf6383582",
        .name         = "Double-Height 6-Digit Score Display (2001) (Andrew Davie)",
    },{
        .md5          = "3bb9793c60c92911895cf44530846136",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Dragster (Jone Yuan) (4K)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "3c21a89bc38d8cd0b010a2916bcff5c2",
        .name         = "Colony 7 - CX-22 Hack v0.4 (NTSC)",
        .phosphor     = 1,
    },{
        .md5          = "3c3a2bb776dec245c7d6678b5a56ac10",
        .name         = "Push (V0.xx) (2001) (Andrew Davie)",
    },{
        .md5          = "3c4223316c835ceaad619651e25df0f9",
        .name         = "Defender (Genesis)",
        .note         = "Genesis controller (C is smartbomb)",
    },{
        .md5          = "3c4a6f613ca8ba27ce9e43c6c92a3128",
        .name         = "Qb (V0.04) (Non-Lax Version) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "3c57748c8286cf9e821ecd064f21aaa9",
        .manufacturer = "Atari, Jerome Domurat, Andrew Fuchs, Dave Staugas, Robert Vieira",
        .model        = "CX26118",
        .name         = "Millipede (1984) (Atari)",
    },{
        .md5          = "3c72ddaf41158fdd66e4f1cb90d4fd29",
        .manufacturer = "Dismac",
        .name         = "Comando Suicida (Dismac)",
        .note         = "AKA Chopper Command",
    },{
        .md5          = "3c7a7b3a0a7e6319b2fa0f923ef6c9af",
        .manufacturer = "Atari - Roklan, Joe Gaucher",
        .name         = "Racer (1982) (Atari) (Prototype)",
        .note         = "ROM must be started in bank 0",
    },{
        .md5          = "3c7a96978f52b2b15426cdd50f2c4048",
        .name         = "Overhead Adventure Demo 3 (PD)",
    },{
        .md5          = "3c82e808fe0e6a006dc0c4e714d36209",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-004",
        .name         = "Fishing Derby (1980) (Activision) (16K)",
    },{
        .md5          = "3c853d864a1d5534ed0d4b325347f131",
        .manufacturer = "Telesys, Don 'Donyo' Ruffcorn",
        .model        = "1002",
        .name         = "Cosmic Creeps (1982) (Telesys)",
        .note         = "AKA Space Maze, Spaze Maze",
        .phosphor     = 1,
    },{
        .md5          = "3c8e57a246742fa5d59e517134c0b4e6",
        .manufacturer = "Parker Brothers, Rex Bradford, Sam Kjellman",
        .model        = "PB5050",
        .name         = "Star Wars - The Empire Strikes Back (1982) (Parker Bros)",
    },{
        .md5          = "3ca51b5c08f5a0ecfb17d0c1ec6d0942",
        .manufacturer = "Atari, James Andreasen - Sears",
        .model        = "CX2654 - 49-75141",
        .name         = "Haunted House (09-28-81) (Atari) (Prototype)",
        .note         = "AKA Mystery Mansion, Graves' Manor, Nightmare Manor",
    },{
        .md5          = "3caa902ac0ce4509308990645876426a",
        .manufacturer = "Atari - GCC, Dave Payne",
        .model        = "CX2669, CX2669P",
        .name         = "Vanguard (1983) (Atari) (PAL)",
    },{
        .md5          = "3cbdf71bb9fd261fbc433717f547d738",
        .manufacturer = "CCE",
        .model        = "C-803",
        .name         = "Bobby Is Going Home (1983) (CCE) (PAL)",
        .note         = "AKA Bobby Vai Para Casa",
    },{
        .md5          = "3cdd91e1c28d28e856c0063d602da166",
        .name         = "Stell-A-Sketch (03-11-1997) (Bob Colbert) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "3d1e83afdb4265fa2fb84819c9cfd39c",
        .manufacturer = "Coleco - JWDA, Todd Marshall, Robin McDaniel, Henry Will IV",
        .model        = "2465",
        .name         = "Smurf - Rescue in Gargamel's Castle (1983) (Coleco)",
        .note         = "AKA Smurf, Smurf Action",
    },{
        .md5          = "3d2367b2b09c28f1659c082bb46a7334",
        .manufacturer = "Imagic, Dennis Koble",
        .model        = "720103-2A, IA3203P, EIX-010-04I",
        .name         = "Atlantis (1982) (Imagic) (PAL)",
        .note         = "AKA Lost City of Atlantis",
    },{
        .md5          = "3d2652cbea462a886a41791dd7c8d073",
        .name         = "Ritorno dei frattelli di Mario (Mario Bros Hack)",
    },{
        .md5          = "3d48b8b586a09bdbf49f1a016bf4d29a",
        .manufacturer = "Video Game Cartridge - Ariola",
        .model        = "TP-606",
        .name         = "Hole Hunter (Video Game Cartridge)",
        .note         = "AKA Topy",
    },{
        .md5          = "3d6fc7a19be76d808aa233415cb583fc",
        .manufacturer = "CCE",
        .model        = "C-833",
        .name         = "Target Practice (1983) (CCE)",
        .note         = "AKA Carnival",
    },{
        .md5          = "3d7749fb9c2f91a276dfe494495234c5",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Checkers (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "3d7aad37c55692814211c8b590a0334c",
        .manufacturer = "Atari, Dan Oliver",
        .name         = "Telepathy (1983) (Atari) (Prototype)",
        .note         = "Uses both left joystick and right MindLink controllers (press Fire on respective controller to begin)",
        .right        = "MINDLINK",
    },{
        .md5          = "3d8a2d6493123a53ade45e3e2c5cafa0",
        .manufacturer = "Atari, Jim Huether - Sears",
        .model        = "CX2629 - 6-99843, 49-75118",
        .name         = "Sky Diver (1979) (Atari) (4K)",
    },{
        .md5          = "3d934bb980e2e63e1ead3e7756928ccd",
        .manufacturer = "Activision, Steve Cartwright - Ariola",
        .model        = "EAX-017, EAX-017-04I - 711 017-720",
        .name         = "MegaMania (1982) (Activision) (PAL)",
    },{
        .md5          = "3d9c2fccf8b11630762ff00811c19277",
        .name         = "Challenge of.... Nexar, The (Unknown) (PAL)",
    },{
        .md5          = "3da7cc7049d73d34920bb73817bd05a9",
        .manufacturer = "Activision, Mike Lorenzen",
        .model        = "AX-023",
        .name         = "Oink! (1983) (Activision) (16K)",
    },{
        .md5          = "3dfb7c1803f937fadc652a3e95ff7dc6",
        .manufacturer = "Dimax - Sinmax",
        .model        = "SM8001",
        .name         = "Space Robot (Dimax - Sinmax)",
        .phosphor     = 1,
    },{
        .md5          = "3e03086da53ecc29d855d8edf10962cb",
        .manufacturer = "CBS Electronics - Roklan, Joe Gaucher, Dan Kurczewski, Alex Leavens, Kathy Von",
        .model        = "4L1751, 4L1752, 4L1753, 4L2275",
        .name         = "Gorf (1982) (CBS Electronics) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "3e1682ddaec486d8b6b90b527aaa0fc4",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Robot City (V0.12) (Thomas Jentzsch)",
    },{
        .md5          = "3e22c7eaf6459b67388602e4bebbb3a8",
        .manufacturer = "CommaVid, John Bronstein - Ariola",
        .model        = "CM-003 - 712 003-720",
        .name         = "Cosmic Swarm (1982) (CommaVid) (PAL) (4K)",
        .note         = "AKA Angriff der Termiten",
    },{
        .md5          = "3e33ac10dcf2dff014bc1decf8a9aea4",
        .manufacturer = "Spectravideo - Video Games Industries Corporation, Michael Schwartz - Ralston Purina",
        .name         = "Chase the Chuckwagon (1983) (Spectravideo)",
        .phosphor     = 1,
    },{
        .md5          = "3e49da621193d2611a4ea152d5d5ca3a",
        .name         = "Atari Logo Demo 3 (PD)",
    },{
        .md5          = "3e4b1137433cc1e617b5508619e13063",
        .name         = "Asteroids (Genesis)",
        .note         = "Genesis controller (C is hyperspace)",
        .phosphor     = 1,
    },{
        .md5          = "3e5ca1afaa27c5da3c54c9942fec528b",
        .name         = "2600 Digital Clock (Demo 2) (PD)",
    },{
        .md5          = "3e6dab92009d6034618cb6b7844c5216",
        .name         = "Ed Invaders (Hack)",
        .note         = "Hack of Pepsi Invaders",
    },{
        .md5          = "3e7d10d0a911afc4b492d06c99863e65",
        .manufacturer = "VGS",
        .name         = "Super Tenis (VGS)",
        .note         = "AKA RealSports Tennis",
    },{
        .md5          = "3e88cca5b860d0bd8947479e74c44284",
        .manufacturer = "Atari, Lou Harp",
        .model        = "CX26122",
        .name         = "Sinistar (01-23-1984) (Atari) (Prototype)",
    },{
        .md5          = "3e899eba0ca8cd2972da1ae5479b4f0d",
        .manufacturer = "Coleco, Joseph Biel",
        .model        = "2457",
        .name         = "Venture (1982) (Coleco)",
        .phosphor     = 1,
    },{
        .md5          = "3e90cf23106f2e08b2781e41299de556",
        .manufacturer = "Activision, David Crane",
        .model        = "AX-018, AX-018-04",
        .name         = "Pitfall! (1982) (Activision)",
        .note         = "Pitfall Harry's Jungle Adventure (Jungle Runner)",
    },{
        .md5          = "3eae062a9b722bda1255d474a87eca5c",
        .manufacturer = "Atari, David Crane",
        .model        = "CX2605, CX2605P",
        .name         = "Outlaw (1978) (Atari) (PAL) (4K)",
    },{
        .md5          = "3eb1e34a4f0eec36f12e7336badcecf2",
        .manufacturer = "Jake Patterson",
        .name         = "Baubles (V0.001) (2001) (Jake Patterson) (PD)",
    },{
        .md5          = "3eb21313ea5d5764c5ed9160a5a55a83",
        .manufacturer = "Activision, Alan Miller",
        .model        = "AX-012, CAX-012, AX-012-04",
        .name         = "Ice Hockey (1981) (Activision) (8K)",
    },{
        .md5          = "3ec12372ca3e870b11ca70edc7ec26a4",
        .manufacturer = "CommaVid, John Bronstein",
        .model        = "CM-002",
        .name         = "Video Life (1981) (CommaVid) (4K)",
        .phosphor     = 1,
    },{
        .md5          = "3eccf9f363f5c5de0c8b174a535dc83b",
        .name         = "Plaque Attack (Unknown) (PAL)",
    },{
        .md5          = "3ef9573536730dcd6d9c20b6822dbdc4",
        .manufacturer = "Atari, Larry Wagner, Bob Whitehead",
        .model        = "CX2645, CX2645P",
        .name         = "Video Chess (1979) (Atari) (PAL)",
        .note         = "AKA Computer Chess",
    },{
        .md5          = "3f01bd6d059396f495a4cde7de0ab180",
        .name         = "Qb (Special Edition) (NTSC) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "3f039981255691d3859d04ef813a1264",
        .manufacturer = "Xonox, John Perkins",
        .model        = "6230, 7210, 06004, 99004",
        .name         = "Artillery Duel (1983) (Xonox) [a]",
    },{
        .md5          = "3f251c50aa7237e61a38ab42315ebed4",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Ikari Warriors (1990) (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "3f3ad2765c874ca13c015ca6a44a40a1",
        .manufacturer = "CCE",
        .model        = "C-862",
        .name         = "Crackpots (1983) (CCE)",
    },{
        .md5          = "3f540a30fdee0b20aed7288e4a5ea528",
        .manufacturer = "Atari - GCC",
        .model        = "CX2670",
        .name         = "Atari Video Cube (1983) (Atari)",
        .note         = "AKA Atari Cube, Video Cube",
    },{
        .md5          = "3f58f972276d1e4e0e09582521ed7a5b",
        .manufacturer = "Telegames",
        .model        = "6082 A145",
        .name         = "Kung Fu Superkicks (1988) (Telegames)",
        .note         = "AKA Chuck Norris Superkicks",
    },{
        .md5          = "3f5a43602f960ede330cd2f43a25139e",
        .manufacturer = "Activision, Alan Miller",
        .model        = "AG-003",
        .name         = "Checkers (1980) (Activision)",
    },{
        .md5          = "3f6938aa6ce66e6f42e582c1eb19b18c",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Laser Blast (Jone Yuan) (4K) (Hack)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "3f6dbf448f25e2bd06dea44248eb122d",
        .model        = "5687 A279",
        .name         = "Soccer (1988) (Telegames)",
        .note         = "AKA International Soccer",
    },{
        .md5          = "3f75a5da3e40d486b21dfc1c8517adc0",
        .manufacturer = "Atari, Jim Huether",
        .model        = "CX26163P",
        .name         = "Sky Diver (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "3f9431cc8c5e2f220b2ac14bbc8231f4",
        .name         = "Colors Demo (PD)",
    },{
        .md5          = "3f96eb711928a6fac667c04ecd41f59f",
        .manufacturer = "Bit Corporation",
        .model        = "PGP218",
        .name         = "Rodeo Champ (4 Game in One Dark Green) (1983) (BitCorp) (PAL)",
        .note         = "AKA Stampede",
    },{
        .md5          = "3f9cb1aba8ec20e2c243ae642f9942bf",
        .name         = "New Questions (1998) (John K. Harvey) (PD)",
    },{
        .md5          = "3fd1f9d66a418c9f787fc5799174ddb7",
        .manufacturer = "Aaron Curtis",
        .name         = "AStar (PAL)",
    },{
        .md5          = "3fd53bfeee39064c945a769f17815a7f",
        .manufacturer = "CCE",
        .name         = "Sea Hawk (CCE)",
        .note         = "AKA Seahawk",
    },{
        .md5          = "3fe43915e5655cf69485364e9f464097",
        .manufacturer = "CCE",
        .model        = "C-863",
        .name         = "Fisher Price (1983) (CCE)",
        .note         = "AKA Skindiver",
    },{
        .md5          = "3ff5165378213dab531ffa4f1a41ae45",
        .manufacturer = "Otto Versand",
        .model        = "311377",
        .name         = "Pygmy (1983) (Otto Versand) (PAL)",
        .note         = "AKA Lock 'n' Chase (Double-Game Package)",
    },{
        .md5          = "4026ad38ba5ce486e88383dc27d7a46f",
        .manufacturer = "Nukey Shay, Omegamatrix",
        .name         = "Double Dragon (Genesis) V2",
        .note         = "Genesis controller",
    },{
        .md5          = "402b1ca3c230a60fb279d4a2a10fa677",
        .name         = "3-D Tic-Tac-Toe (Unknown) (PAL) (4K)",
    },{
        .md5          = "402d876ec4a73f9e3133f8f7f7992a1e",
        .manufacturer = "Alex Herbert",
        .name         = "Man Goes Down (2006) (A. Herbert) (Prototype)",
        .note         = "Uses AtariVox controller",
        .right        = "ATARIVOX",
    },{
        .md5          = "405f8591b6941cff56c9b392c2d5e4e5",
        .manufacturer = "Telegames",
        .name         = "Star Strike (1988) (Telegames) (PAL)",
    },{
        .md5          = "4066309eb3fa3e7a725585b9814bc375",
        .name         = "Multi Ball Demo (PD)",
    },{
        .md5          = "4066d7d88ec4a2c656127a67fa52dcf1",
        .name         = "Overhead Adventure Demo 2 (PD)",
    },{
        .md5          = "407a0c6cc0ff777f67b669440d68a242",
        .manufacturer = "Erik Eid",
        .name         = "Euchre (Alpha) (PAL) (31-08-2002) (Erik Eid)",
    },{
        .md5          = "4093382187f8387e6d011883e8ea519b",
        .name         = "Go Go Home (Unknown)",
    },{
        .md5          = "40aa851e8d0f1c555176a5e209a5fabb",
        .name         = "Euchre (More for less) (NTSC) (22-08-2002) (Erik Eid)",
    },{
        .md5          = "40b1832177c63ebf81e6c5b61aaffd3a",
        .manufacturer = "Atari, Peter C. Niday",
        .name         = "Rubik's Cube 3-D (1982) (Atari) (Prototype)",
    },{
        .md5          = "40b59249e05135bca33861e383735e9e",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Skiing (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "40d8ed6a5106245aa79f05642a961485",
        .manufacturer = "Xonox - K-Tel Software - Beck-Tech, Steve Beck",
        .model        = "6210, 06002, 06004, 99002",
        .name         = "Ghost Manor (1983) (Xonox) (PAL)",
    },{
        .md5          = "40d9f5709877ecf3dd1184f9791dd35e",
        .manufacturer = "Dactari - Milmar",
        .name         = "Skiing (Dactari)",
    },{
        .md5          = "40e12c008037a323a1290c8fa4d2fe7f",
        .name         = "Skeleton (NTSC) (06-09-2002) (Eric Ball)",
    },{
        .md5          = "40eb4e263581b3dfec6dd8920b68e00f",
        .manufacturer = "Sears Tele-Games, Marilyn Churchill, Matthew L. Hubbard",
        .model        = "CX2647 - 49-75142",
        .name         = "Seawolf 3 (03-23-1981) (Sears) (Prototype) (PAL)",
        .note         = "Submarine Commander Beta",
    },{
        .md5          = "413c925c5fdcea62842a63a4c671a5f2",
        .manufacturer = "Activision, Larry Kaplan",
        .model        = "AX-006",
        .name         = "Bridge (1980) (Activision) [fixed]",
    },{
        .md5          = "4153dd2beed648e9dc082140ebe8e836",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Coke Zero (v1.0) (NTSC)",
    },{
        .md5          = "415c11fcac66bbd2ace2096687774b5a",
        .name         = "Fu Kung! (V0.00) (07-01-2003) (Andrew Davie)",
    },{
        .md5          = "4181087389a79c7f59611fb51c263137",
        .manufacturer = "Atari, Dave Joly, Gary Shannon",
        .model        = "CX26113",
        .name         = "Miss Piggy's Wedding (06-24-1983) (Atari) (Prototype)",
    },{
        .md5          = "41810dd94bd0de1110bedc5092bef5b0",
        .manufacturer = "Funvision - Fund. International Co.",
        .name         = "Dragon Treasure (Funvision)",
        .note         = "AKA Dragonfire",
        .phosphor     = 1,
    },{
        .md5          = "41818738ab1745e879024a17784d71f5",
        .manufacturer = "CCE",
        .model        = "C-832",
        .name         = "Atlantis (1983) (CCE)",
    },{
        .md5          = "4189adfc1b30c121248876e3a1a3ac7e",
        .manufacturer = "Eric Ball",
        .name         = "Skeleton (Complete) (06-09-2002) (Eric Ball)",
    },{
        .md5          = "418a849f977db94062c459b7f636c8d1",
        .manufacturer = "Activision, Steve Cartwright",
        .model        = "AX-031",
        .name         = "Iceman (07-27-1983) (Activision) (Prototype)",
        .note         = "Frostbite Beta",
    },{
        .md5          = "4191b671bcd8237fc8e297b4947f2990",
        .manufacturer = "Exus Corporation",
        .name         = "Video Jogger (1983) (Exus)",
        .note         = "AKA Foot Craz",
    },{
        .md5          = "41b554c6970b18670acc7b6baef8ed2e",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Amiga Mouse Hack v1.3 (PAL) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "41c4e3d45a06df9d21b7aae6ae7e9912",
        .manufacturer = "CCE",
        .model        = "C-826",
        .name         = "Grand Prix (1983) (CCE)",
    },{
        .md5          = "41f252a66c6301f1e8ab3612c19bc5d4",
        .manufacturer = "Atari - GCC, Mike Feinstein, Brad Rice",
        .model        = "CX2681",
        .name         = "Battlezone (1983) (Atari)",
    },{
        .md5          = "4209e9dcdf05614e290167a1c033cfd2",
        .manufacturer = "CommaVid, John Bronstein",
        .model        = "CM-002",
        .name         = "Video Life (1984) (CommaVid) [higher sounds]",
        .phosphor     = 1,
    },{
        .md5          = "42249ec8043a9a0203dde0b5bb46d8c4",
        .manufacturer = "CCE",
        .name         = "Resgate Espacial (CCE)",
        .note         = "AKA Moonsweeper",
        .phosphor     = 1,
    },{
        .md5          = "4233eb824c2b4811abef9b6d00355ae9",
        .manufacturer = "Retroactive",
        .name         = "Qb (V0.10) (PAL) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "4251b4557ea6953e88afb22a3a868724",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Robot City (V1.1) (Thomas Jentzsch)",
    },{
        .md5          = "425ee444a41d218598893d6b6e03431a",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Invaders Demo (2001) (Thomas Jentzsch)",
    },{
        .md5          = "4279485e922b34f127a88904b31ce9fa",
        .name         = "Enduro (Unknown) [a]",
    },{
        .md5          = "428b2d36f5d716765460701f7016ac91",
        .manufacturer = "Andrew Wallace",
        .name         = "Brooni (2001) (Andrew Wallace) (PD)",
    },{
        .md5          = "42ae81ae8ac51e5c238639f9f77d91ae",
        .name         = "Multi Demo 8 (Bob Colbert) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "42b2c3b4545f1499a083cfbc4a3b7640",
        .manufacturer = "U.S. Games Corporation - JWDA, Todd Marshall, Robin McDaniel, Wes Trager, Henry Will IV",
        .model        = "VC2003",
        .name         = "Eggomania (1982) (U.S. Games)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "42b3ab3cf661929bdc77b621a8c37574",
        .manufacturer = "Robby",
        .name         = "Volleyball (Robby)",
        .note         = "AKA RealSports Volleyball",
    },{
        .md5          = "42b5e3a35b032f033809afb0ea28802d",
        .manufacturer = "Atari, Mimi Nyden, Scott Smith, Robert Vieira",
        .model        = "CX26127",
        .name         = "Gremlins (03-12-1984) (Atari) (Prototype)",
    },{
        .md5          = "42cdd6a9e42a3639e190722b8ea3fc51",
        .manufacturer = "Activision, Alan Miller",
        .model        = "AG-007, CAG-007",
        .name         = "Tennis (1981) (Activision)",
    },{
        .md5          = "42dcc02777b0bcfacd85aeb61d33558a",
        .name         = "Human Cannonball (Unknown) (PAL) (4K)",
    },{
        .md5          = "42e0ec5ab8f5deba53e4169ff2a5efbe",
        .name         = "Atari Logo Demo 5 (PD)",
    },{
        .md5          = "4311a4115fb7bc68477c96cf44cebacf",
        .name         = "Challenge (Unknown)",
    },{
        .md5          = "4326edb70ff20d0ee5ba58fa5cb09d60",
        .manufacturer = "Atari - GCC, Kevin Osborn",
        .model        = "CX2689",
        .name         = "Kangaroo (1983) (Atari)",
    },{
        .md5          = "435fd469f088468c4d66be6b5204d887",
        .manufacturer = "Atari - GCC",
        .model        = "CX2680, CX2680P",
        .name         = "RealSports Tennis (1983) (Atari) (PAL) [a]",
    },{
        .md5          = "438968a26b7cfe14a499f5bbbbf844db",
        .name         = "Raft Rider (Unknown) (PAL)",
    },{
        .md5          = "43adf60ebdd6b5a0fae21594ecf17154",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Stampede (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "43c6cfffeddab6b3787357fed9d44529",
        .manufacturer = "20th Century Fox Video Games, Frank Cohen, Douglas 'Dallas North' Neubauer",
        .model        = "11111",
        .name         = "M.A.S.H (1983) (20th Century Fox) (PAL)",
    },{
        .md5          = "43f33c6dfdeaf5138ce6e6968ad7c5ce",
        .manufacturer = "Jeffry Johnston",
        .name         = "Radial Pong - Version 11 (Jeffry Johnston) (PD)",
    },{
        .md5          = "43f8459d39fb4eddf9186d62722ff795",
        .name         = "Skeleton+ (17-04-2003) (Eric Ball) (PAL)",
    },{
        .md5          = "442602713cb45b9321ee93c6ea28a5d0",
        .name         = "Demon Attack (Unknown) (PAL)",
    },{
        .md5          = "4427f06085bb4c22ff047027f7acecc2",
        .manufacturer = "Parker Brothers, Rex Bradford",
        .model        = "PB5000",
        .name         = "Star Wars - Jedi Arena (1983) (Parker Bros) (Prototype)",
        .note         = "Uses the Paddle Controllers (swapped)",
        .swapPaddles  = 1,
    },{
        .md5          = "442b7863683e5f084716fda050474feb",
        .manufacturer = "Eckhard Stolberg",
        .name         = "Frame Timed Sound Effects-EM (Eckhard Stolberg)",
    },{
        .md5          = "4431428a7500c96fc0e2798a5dbd36d6",
        .name         = "Kangaroo (Genesis)",
        .note         = "Genesis controller (B is punch, C is jump)",
    },{
        .md5          = "4474b3ad3bf6aabe719a2d7f1d1fb4cc",
        .manufacturer = "Activision - Imagineering, Dan Kitchen, Garry Kitchen",
        .model        = "EAX-039-04B, EAX-039-04I",
        .name         = "Kung-Fu Master (1987) (Activision) (PAL)",
    },{
        .md5          = "4476c39736090dabac09f6caf835fc49",
        .name         = "Text Screen (25-01-2003) (Andrew Davie)",
    },{
        .md5          = "448c2a175afc8df174d6ff4cce12c794",
        .manufacturer = "Activision, David Crane",
        .model        = "AB-035-04",
        .name         = "Pitfall II (1983) (Activision) [a2]",
    },{
        .md5          = "44e9c4a047c348dbeb7ace60f45484b4",
        .name         = "Moon Patrol Arcade (Genesis)",
        .note         = "Genesis controller (C is jump)",
    },{
        .md5          = "44f71e70b89dcc7cf39dfd622cfb9a27",
        .manufacturer = "Tigervision, Robert H. O'Neil",
        .model        = "7-007",
        .name         = "Polaris (1983) (Tigervision)",
    },{
        .md5          = "45027dde2be5bdd0cab522b80632717d",
        .manufacturer = "Epyx, Steven A. Baker, Tod Frye, Peter Engelbrite",
        .model        = "80561-00250",
        .name         = "Summer Games (1987) (Epyx)",
    },{
        .md5          = "45040679d72b101189c298a864a5b5ba",
        .manufacturer = "20th Century Fox Video Games - Sirius Software, David Lubar",
        .model        = "11022",
        .name         = "SpaceMaster X-7 (1983) (20th Century Fox)",
    },{
        .md5          = "4543b7691914dfd69c3755a5287a95e1",
        .manufacturer = "CommaVid, Irwin Gaines",
        .model        = "CM-005",
        .name         = "Mines of Minos (1982) (CommaVid)",
        .phosphor     = 1,
    },{
        .md5          = "456453a54ca65191781aef316343ae00",
        .name         = "Full Screen Bitmap (3-D Green) (PD)",
    },{
        .md5          = "4565c1a7abce773e53c75b35414adefd",
        .manufacturer = "Arcadia Corporation",
        .name         = "Supercharger BIOS (1982) (Arcadia)",
    },{
        .md5          = "457b03cd48ff6d895795ef043c6b0f1e",
        .manufacturer = "AtariAge, Chris Spry",
        .model        = "CX26201",
        .name         = "Zippy the Porcupine (2014) (Sprybug)",
    },{
        .md5          = "457e7d4fcd56ebc47f5925dbea3ee427",
        .manufacturer = "Carrere Video - JWDA, Garry Kitchen - Teldec - Prism",
        .model        = "USC1001",
        .name         = "Space Jockey (1983) (Carrere Video) (PAL)",
    },{
        .md5          = "457f4ad2cda5f4803f122508bfbde3f5",
        .name         = "Canyon Bomber (Unknown) (PAL)",
    },{
        .md5          = "458883f1d952cd772cf0057abca57497",
        .name         = "Fishing Derby (Unknown) (PAL) (Hack)",
    },{
        .md5          = "45a095645696a217e416e4bd2baea723",
        .manufacturer = "Digivision",
        .name         = "Snoopy (Digivision)",
        .note         = "AKA Snoopy and the Red Baron",
    },{
        .md5          = "45a4f55bb9a5083d470ad479afd8bca2",
        .manufacturer = "CommaVid, Joseph Biel",
        .name         = "Frog Demo (1983) (CommaVid)",
    },{
        .md5          = "45beef9da1a7e45f37f3f445f769a0b3",
        .manufacturer = "Atari, Suki Lee",
        .model        = "CX2658",
        .name         = "Math Gran Prix (1982) (Atari) (PAL)",
    },{
        .md5          = "45c4413dd703b9cfea49a13709d560eb",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Challenge of.... Nexar, The (Jone Yuan) (Hack)",
        .note         = "Hack",
    },{
        .md5          = "45cb0f41774b78def53331e4c3bf3362",
        .manufacturer = "Carrere Video - JWDA, Roger Booth, Sylvia Day, Todd Marshall, Robin McDaniel, Wes Trager, Henry Will IV - Teldec - Prism",
        .model        = "USC1007",
        .name         = "Octopus (1983) (Carrere Video) (PAL)",
        .note         = "AKA Name This Game",
    },{
        .md5          = "4605a00f5b44a9cbd5803a7a55de150e",
        .manufacturer = "Coleco - Individeo, Ed Temple",
        .name         = "Cabbage Patch Kids (07-03-1984) (Coleco) (Prototype)",
        .note         = "Adventures in the Park",
    },{
        .md5          = "461029ab23800833e9645be3e472d470",
        .name         = "Combat TC (v0.1)",
    },{
        .md5          = "46258bd92b1f66f4cb47864d7654f542",
        .manufacturer = "Zellers",
        .name         = "Turmoil (Zellers)",
    },{
        .md5          = "463dd4770506e6c0ef993a40c52c47be",
        .manufacturer = "Arcadia Corporation, Steve Hales, Stephen H. Landrum",
        .model        = "4 AR-4102",
        .name         = "Suicide Mission (Preview) (1982) (Arcadia)",
        .note         = "AKA Meteoroids",
        .phosphor     = 1,
    },{
        .md5          = "463e66ad98806a49106cffa49c08e2ed",
        .name         = "Interlace Game Demo (01-09-2002) (Billy Eno)",
    },{
        .md5          = "467340a18158649aa5e02a4372dcfccd",
        .manufacturer = "Activision, John Van Ryzin - Ariola",
        .model        = "EAZ-036-04, EAZ-036-04B, EAZ-036-04I - 711 036-720",
        .name         = "H.E.R.O. (1984) (Activision) (PAL) [a1]",
    },{
        .md5          = "4689081b7363721858756fe781cc7713",
        .name         = "Oystron (V2.6) (Piero Cavina) (PD)",
    },{
        .md5          = "468f2dec984f3d4114ea84f05edf82b6",
        .manufacturer = "Tigervision - Teldec",
        .model        = "7-011 - 3.60015 VG",
        .name         = "Miner 2049er Volume II (1983) (Tigervision) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "4690fdb70c86604bb35da26696818667",
        .name         = "Euchre (Release Candidate) (NTSC) (28-09-2002) (Erik Eid)",
    },{
        .md5          = "469473ff6fed8cc8d65f3c334f963aab",
        .manufacturer = "Atari, Bruce Poehlman, Gary Stark",
        .name         = "Dune (07-10-1984) (Atari) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "46c021a3e9e2fd00919ca3dd1a6b76d8",
        .manufacturer = "Atari, Jim Huether - Sears",
        .model        = "CX2629 - 6-99843, 49-75118",
        .name         = "Sky Diver (1979) (Atari)",
    },{
        .md5          = "46c43fdcbce8fde3a91ebeafc05b7cbd",
        .name         = "Invaders Demo (PAL) (2001) (Eckhard Stolberg)",
    },{
        .md5          = "46dc526773808c8b9bb2111f24e5704c",
        .manufacturer = "Omegamatrix",
        .name         = "SpaceMaster X-7 (Atari Mouse) (Omegamatrix)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "46e9428848c9ea71a4d8f91ff81ac9cc",
        .manufacturer = "Telegames",
        .name         = "Astroblast (1988) (Telegames) (PAL)",
        .note         = "Can also use left joystick",
        .left         = "PADDLES",
        .swapPaddles  = 1,
    },{
        .md5          = "4702d8d9b48a332724af198aeac9e469",
        .manufacturer = "Atari, Jerome Domurat, Steve Woita",
        .model        = "CX2699",
        .name         = "Taz (1983) (Atari) [a]",
    },{
        .md5          = "470878b9917ea0348d64b5750af149aa",
        .manufacturer = "Atari, Suki Lee - Sears",
        .model        = "CX2658 - 49-75128",
        .name         = "Math Gran Prix (1982) (Atari)",
    },{
        .md5          = "471f7bdc933e8db0e44aa3dde2dd92af",
        .manufacturer = "Omegamatrix",
        .name         = "Millipede (Atari Mouse) v6.5 (Omegamatrix)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "47464694e9cce07fdbfd096605bf39d4",
        .manufacturer = "Activision, Dan Kitchen",
        .model        = "EAK-050-04",
        .name         = "Double Dragon (1989) (Activision) (PAL) [a]",
    },{
        .md5          = "47585c047802dd9af888b998fb921f32",
        .manufacturer = "Omegamatrix",
        .name         = "Star Wars Arcade (Atari Trak-Ball) v4 (PAL60) (Omegamatrix)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "4767356fa0ed3ebe21437b4473d4ee28",
        .manufacturer = "Atari, Dan Hitchens, Mimi Nyden",
        .model        = "CX2685",
        .name         = "Gravitar (04-12-1983) (Atari) (Prototype)",
    },{
        .md5          = "47711c44723da5d67047990157dcb5dd",
        .manufacturer = "CCE",
        .name         = "Ice Hockey (CCE)",
    },{
        .md5          = "47911752bf113a2496dbb66c70c9e70c",
        .manufacturer = "Atari - CCW, Christopher H. Omarzu, Preston Stuart, Bruce Williams",
        .model        = "CX26101",
        .name         = "Oscar's Trash Race (1984) (Atari) (PAL)",
        .note         = "Uses the Keyboard Controllers",
        .left         = "KEYBOARD",
        .right        = "KEYBOARD",
    },{
        .md5          = "4799a40b6e889370b7ee55c17ba65141",
        .manufacturer = "Konami",
        .model        = "RC 100-X 02",
        .name         = "Pooyan (1983) (Konami)",
    },{
        .md5          = "47aad247cce2534fd70c412cb483c7e0",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-010",
        .name         = "Mafia (1983) (Rainbow Vision) (PAL)",
        .note         = "AKA Gangster Alley",
    },{
        .md5          = "47abfb993ff14f502f88cf988092e055",
        .manufacturer = "Zellers",
        .name         = "Inca Gold (Zellers)",
    },{
        .md5          = "47aef18509051bab493589cb2619170b",
        .name         = "Stell-A-Sketch (Bob Colbert) (PD)",
        .note         = "Uses Driving, Joystick, or Amiga/Atari ST Mouse Controllers",
        .phosphor     = 1,
    },{
        .md5          = "47b82d47e491ac7fdb5053a88fccc832",
        .manufacturer = "Atari Freak 1, Franklin Cruz",
        .name         = "Asteroid 2 (Atari Freak 1) (Hack)",
        .note         = "Hack of Asteroids",
        .phosphor     = 1,
    },{
        .md5          = "47cd61f83457a0890de381e478f5cf5f",
        .manufacturer = "Imagic, Wilfredo Aguilar, Michael Becker, Rob Fulop",
        .model        = "720111-2A, 13205",
        .name         = "Fathom (1983) (Imagic) (PAL)",
        .note         = "AKA Scuba",
        .phosphor     = 1,
    },{
        .md5          = "481d20ec22e7a63e818d5ef9679d548b",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Freeway Rabbit (32 in 1) (1988) (Atari) (PAL)",
        .note         = "AKA Freeway",
    },{
        .md5          = "481f9a742052801cc5f3defb41cb638e",
        .manufacturer = "Jeffry Johnston",
        .name         = "Radial Pong - Version 4 (Jeffry Johnston) (PD)",
    },{
        .md5          = "48287a9323a0ae6ab15e671ac2a87598",
        .manufacturer = "Zellers",
        .name         = "Laser Volley (Zellers)",
        .note         = "AKA Innerspace",
    },{
        .md5          = "4834b7b28ea862227ac7e40053fb52a5",
        .manufacturer = "Nukey Shay",
        .name         = "Montezuma's Revenge (Genesis) (F6_Conversion)",
        .note         = "Genesis controller",
    },{
        .md5          = "48411c9ef7e2cef1d6b2bee0e6055c27",
        .manufacturer = "Telesys, Don Ruffcorn, Jack Woodman",
        .model        = "1003",
        .name         = "Fast Food (1982) (Telesys) (PAL)",
    },{
        .md5          = "484b0076816a104875e00467d431c2d2",
        .manufacturer = "Atari",
        .model        = "CX26150",
        .name         = "Q-bert (1987) (Atari)",
    },{
        .md5          = "4857f8bb88bb63c640d3ea5aac7f5d6d",
        .manufacturer = "Atari, James Andreasen - Sears",
        .model        = "CX2654 - 49-75141",
        .name         = "Haunted House (08-12-81) (Atari) (Prototype)",
        .note         = "AKA Mystery Mansion, Graves' Manor, Nightmare Manor",
    },{
        .md5          = "4868a81e1b6031ed66ecd60547e6ec85",
        .manufacturer = "Eric Mooney",
        .name         = "Invaders by Erik Mooney (V2.1) (1-3-98) (PD)",
    },{
        .md5          = "487193a7b7fe57a1bbc2f431f628bd5f",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Challenge of... Nexar, The - Atari Trak-Ball Hack v1.1 (NTSC) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "4884b1297500bd1243659e43c7e7579e",
        .manufacturer = "Atari - Axlon, Tod Frye - Heuristica, Agustin Ortiz Valdiviezo",
        .model        = "CX26178",
        .name         = "Save Mary! (10-24-1991) (Atari) (Prototype) (PAL)",
    },{
        .md5          = "4892b85c248131d6a42c66a4163a40d0",
        .manufacturer = "Canal 3 - Intellivision",
        .name         = "Tac-Scan (Canal 3)",
        .note         = "Uses the Paddle Controllers",
        .swapPorts    = 1,
        .swapPaddles  = 1,
        .phosphor     = 1,
    },{
        .md5          = "48bcf2c5a8c80f18b24c55db96845472",
        .manufacturer = "Activision, John Van Ryzin - Ariola",
        .model        = "EAZ-036-04, EAZ-036-04B, EAZ-036-04I - 711 036-720",
        .name         = "H.E.R.O. (1984) (Activision) (PAL) (16K)",
    },{
        .md5          = "48e5c4ae4f2d3b62b35a87bca18dc9f5",
        .manufacturer = "Quelle",
        .model        = "476.774 5",
        .name         = "Bobby geht nach Hause (1983) (Quelle) (PAL)",
        .note         = "AKA Bobby Is Going Home",
    },{
        .md5          = "48f18d69799a5f5451a5f0d17876acef",
        .name         = "Mysterious Thief, A (Unknown)",
        .phosphor     = 1,
    },{
        .md5          = "4901c05068512828367fde3fb22199fe",
        .manufacturer = "Imagic, Rob Fulop",
        .model        = "720101-2B, IA3200P, EIX-006-04I",
        .name         = "Demon Attack (1982) (Imagic) (PAL)",
        .note         = "AKA Death from Above",
    },{
        .md5          = "4904a2550759b9b4570e886374f9d092",
        .manufacturer = "Parker Brothers, Charlie Heath",
        .model        = "931506",
        .name         = "Reactor (1983) (Parker Bros) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "490e3cc59d82f85fae817cdf767ea7a0",
        .name         = "Berzerk (Unknown) (PAL) [a]",
    },{
        .md5          = "490eed07d4691b27f473953fbea6541a",
        .manufacturer = "Activision, Steve Cartwright, David Crane",
        .model        = "AB-035-04",
        .name         = "Pitfall II (1983) (Activision) [a]",
    },{
        .md5          = "49366f41aa7a54baf263426e99ce4312",
        .name         = "POP-MDM-Test (PAL) (63 games)",
        .type         = "MDM",
        .left         = "JOYSTICK",
        .right        = "JOYSTICK",
    },{
        .md5          = "493daaf9fb1ba450eba6b8ed53ffb37d",
        .name         = "3-D Corridor Demo (27-03-2003) (Manuel Rotschkar)",
    },{
        .md5          = "493de059b32f84ab29cde6213964aeee",
        .manufacturer = "Atari, Bill Aspromonte, Andrew Fuchs",
        .model        = "CX26120",
        .name         = "Stargate (1984) (Atari) (PAL)",
    },{
        .md5          = "493e90602a4434b117c91c95e73828d1",
        .manufacturer = "Telegames",
        .name         = "Lock 'n' Chase (1988) (Telegames) (PAL)",
    },{
        .md5          = "4947c9de2e28b2f5f3b0c40ce7e56d93",
        .name         = "3-D Corridor Demo 2 (29-03-2003) (Manuel Rotschkar)",
    },{
        .md5          = "494cda91cc640551b4898c82be058dd9",
        .manufacturer = "Andreas Dietrich",
        .name         = "Donkey Kong VCS (2017) (1.0) (PAL60)",
        .phosphor     = 1,
    },{
        .md5          = "49571b26f46620a85f93448359324c28",
        .name         = "Save Our Ship (Unknown)",
    },{
        .md5          = "497c811026367c08fd838c9c59e5041d",
        .manufacturer = "Omegamatrix",
        .name         = "SpaceMaster X-7 (Atari Trak-Ball) (Omegamatrix)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "497f3d2970c43e5224be99f75e97cbbb",
        .manufacturer = "CommaVid, John Bronstein",
        .model        = "CM-002",
        .name         = "Video Life (1984) (CommaVid)",
        .phosphor     = 1,
    },{
        .md5          = "4981cefe5493ea512284e7f9f27d1e54",
        .manufacturer = "Home Vision - Gem International Corp. - VDI",
        .model        = "VCS83136",
        .name         = "Cosmic War (1983) (Home Vision) (PAL)",
        .note         = "AKA Space Tunnel",
    },{
        .md5          = "4999b45be0ab5a85bac1b7c0e551542b",
        .manufacturer = "CCE",
        .name         = "Double Dragon (CCE) (PAL)",
    },{
        .md5          = "499b612f6544ae71d4915aa63e403e10",
        .manufacturer = "Atari, Carol Shaw",
        .model        = "CX26163P",
        .name         = "Checkers (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "49f2cef5269fd06218be9f9474c74f8d",
        .manufacturer = "Rentacom",
        .name         = "Time Pilot (1983) (Rentacom)",
    },{
        .md5          = "4a196713a21ef07a3f74cf51784c6b12",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Frogs and Flies (Jone Yuan) (Hack)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "4a2fe6f0f6317f006fd6d4b34515448b",
        .name         = "Warring Worms (Midwest Classic Edition) (08-06-2002) (Billy Eno)",
    },{
        .md5          = "4a45c6d75b1ba131f94a9c13194d8e46",
        .name         = "How to Draw a Playfield II (Joystick Hack) (1997) (Eric Bacher) (PD)",
    },{
        .md5          = "4a5fddf89801336637ac8e57a7c9a881",
        .manufacturer = "Amiga",
        .model        = "1125",
        .name         = "Power Play Arcade Video Game Album IV (1984) (Amiga) (Prototype)",
        .note         = "Atlantis, Cosmic Ark, Dragonfire",
    },{
        .md5          = "4a6be79310f86f0bebc7dfcba4d74161",
        .name         = "Demolition Herby (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "4a7eee19c2dfb6aeb4d9d0a01d37e127",
        .manufacturer = "Hozer Video Games",
        .name         = "Crazy Valet (Hozer Video Games)",
    },{
        .md5          = "4a8c743396b8ad69d97e6fd3dd3e3132",
        .manufacturer = "Arcadia Corporation",
        .name         = "Supercharger BIOS (1982) (Arcadia) (PAL)",
    },{
        .md5          = "4a9009620038f7f30aaeb2a00ae58fde",
        .manufacturer = "Arcadia Corporation, Steve Mundry, Scott Nelson",
        .model        = "AR-4401",
        .name         = "Survival Island (3 of 3) (1983) (Arcadia)",
    },{
        .md5          = "4ab2ebd95a8f861ea451abebdad914a5",
        .manufacturer = "Nukey Shay, Thomas Jentzsch",
        .model        = "PAL conversion (F6)",
        .name         = "Montezuma's Revenge (PAL) (Genesis)",
        .note         = "Genesis controller (B jumps left, C jumps right)",
    },{
        .md5          = "4ab4af3adcdae8cdacc3d06084fc8d6a",
        .manufacturer = "Nick Bensema",
        .name         = "Sucky Zepplin (Nick Bensema) (PD)",
    },{
        .md5          = "4abb4c87a4c5f5d0c14ead2bb36251be",
        .manufacturer = "Atari - Imagineering, Alex DeMeo",
        .model        = "CX26135, CX26135P",
        .name         = "RealSports Boxing (1987) (Atari) (PAL)",
    },{
        .md5          = "4ac9f40ddfcf194bd8732a75b3f2f214",
        .manufacturer = "Atari - CCW, Stephan R. Keith, Laura Scholl, Preston Stuart",
        .model        = "CX26106",
        .name         = "Grover's Music Maker (12-29-1982) (Atari) (Prototype)",
        .note         = "Uses Keyboard Controller",
    },{
        .md5          = "4ae8c76cd6f24a2e181ae874d4d2aa3d",
        .name         = "Flash Gordon (Unknown) (PAL)",
    },{
        .md5          = "4af4103759d603c82b1c9c5acd2d8faf",
        .manufacturer = "Imagic, Bob Smith",
        .model        = "720114-2A, 13207, EIZ-001-04I",
        .name         = "Moonsweeper (1983) (Imagic) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "4afa7f377eae1cafb4265c68f73f2718",
        .manufacturer = "Ed Fries",
        .name         = "Halo 2600 (2010) (Ed Fries)",
    },{
        .md5          = "4afe528a082f0d008e7319ebd481248d",
        .name         = "Multi Demo 1 (Bob Colbert) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "4b09877f0700425ee964a166d5c192cb",
        .manufacturer = "Parker Brothers - On-Time Software, Joe Gaucher, Dan Kurczewski, Louis Marbel, Kathy Von",
        .model        = "PB5110",
        .name         = "James Bond 007 (1983) (Parker Bros) (Prototype)",
        .note         = "James Bond Agent 007",
    },{
        .md5          = "4b143d7dcf6c96796c37090cba045f4f",
        .manufacturer = "Atari, Jim Huether - Sears",
        .model        = "CX2644 - 6-99824",
        .name         = "Flag Capture (1978) (Atari) (4K)",
    },{
        .md5          = "4b205ef73a5779acc5759bde3f6d33ed",
        .name         = "Berzerk (Unknown) (PAL)",
    },{
        .md5          = "4b27f5397c442d25f0c418ccdacf1926",
        .manufacturer = "Atari, Warren Robinett",
        .model        = "CX2613, 49-75154",
        .name         = "Adventure (1980) (Atari) (PAL)",
    },{
        .md5          = "4b379b885e2694f992c6cc932f18327f",
        .manufacturer = "Omegamatrix",
        .name         = "SpaceMaster X-7 (Atari Mouse) (PAL60) (Omegamatrix)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "4b71197153d651480830638cb6a03249",
        .manufacturer = "Atari, Larry Kaplan",
        .model        = "CX26163P",
        .name         = "Bowling (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "4b753a97aee91e4b3e4e02f5e9758c72",
        .manufacturer = "Glenn Saunders, Roger Williams",
        .name         = "Asymmetric Reflected Playfield (Glenn Saunders)",
    },{
        .md5          = "4b854623357e511c2fac852529f0ae2c",
        .manufacturer = "Edu Games - Edu Juegos",
        .name         = "Commando (1984) (Edu Games) (PAL)",
        .note         = "AKA Front Line",
    },{
        .md5          = "4b94fd272785d7ec6c95fb7279d0f522",
        .manufacturer = "Atari - CCW, Christopher H. Omarzu, Preston Stuart, Bruce Williams",
        .model        = "CX26101",
        .name         = "Oscar's Trash Race (12-03-1982) (Atari) (Prototype)",
        .note         = "Uses the Keyboard Controllers",
        .left         = "KEYBOARD",
        .right        = "KEYBOARD",
    },{
        .md5          = "4b9581c3100a1ef05eac1535d25385aa",
        .name         = "IQ 180 (Unknown)",
    },{
        .md5          = "4baada22435320d185c95b7dd2bcdb24",
        .manufacturer = "Atari, Jerome Domurat, Dave Staugas",
        .model        = "CX2682",
        .name         = "Krull (1983) (Atari)",
    },{
        .md5          = "4bcc7f6ba501a26ee785b7efbfb0fdc8",
        .manufacturer = "Atari, Andrew Fuchs, Courtney Granner, Jeffrey Gusman, Mark R. Hahn",
        .model        = "CX2690",
        .name         = "Pengo (1983) (Atari) (Prototype)",
    },{
        .md5          = "4bdae9246d6ee258c26665512c1c8de3",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Human Cannonball (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "4bdf54a454470ba015a217a8f5e61320",
        .manufacturer = "Omegamatrix",
        .name         = "Millipede (Amiga Mouse) v6.5 (Omegamatrix)",
        .note         = "Uses Amiga Mouse Controller",
        .format       = "PAL60",
    },{
        .md5          = "4c030667d07d1438f0e5c458a90978d8",
        .manufacturer = "Retroactive",
        .name         = "Qb (V2.03) (PAL) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "4c0fb2544ae0f8b5f7ae8bce7bd7f134",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4302",
        .name         = "Party Mix (Preview) (1983) (Arcadia)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "4c205f166157154df2f1ef60d87e552f",
        .name         = "Single-Scanline Positioning Demo 2 (2001) (Roger Williams)",
    },{
        .md5          = "4c39a2c97917d3d71739b3e21f60bba5",
        .name         = "Whale (Sub Scan Hack)",
    },{
        .md5          = "4c462b2b6fb0a19a1437eb2c3dc20783",
        .manufacturer = "Arcadia Corporation, Steve Mundry, Scott Nelson",
        .model        = "AR-4401",
        .name         = "Survival Island (1 of 3) (1983) (Arcadia)",
    },{
        .md5          = "4c4ba1549830e9fca5e2c110f4ebe47f",
        .name         = "Planet Patrol (Unknown) (PAL) [a]",
    },{
        .md5          = "4c4ce802cbfd160f7b3ec0f13f2a29df",
        .name         = "Beta Demo (V1.1) (26-09-2002) (Manuel Rotschkar)",
    },{
        .md5          = "4c606235f4ec5d2a4b89139093a69437",
        .manufacturer = "Andrew Davies",
        .name         = "Andrew Davies early notBoulderDash demo (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "4c6afb8a44adf8e28f49164c84144bfe",
        .manufacturer = "CCE",
        .model        = "C-806",
        .name         = "Mission 3,000 A.D. (1983) (CCE)",
    },{
        .md5          = "4c8832ed387bbafc055320c05205bc08",
        .manufacturer = "Atari, Joe Decuir, Steve Mayer, Larry Wagner - Sears",
        .model        = "CX2601 - 99801, 6-99801, 49-75124",
        .name         = "Combat (1977) (Atari)",
    },{
        .md5          = "4c8970f6c294a0a54c9c45e5e8445f93",
        .manufacturer = "Xonox - K-Tel Software - Product Guild, Anthony R. Henderson",
        .model        = "99006, 6220",
        .name         = "Sir Lancelot (1983) (Xonox)",
    },{
        .md5          = "4c9307de724c36fd487af6c99ca078f2",
        .manufacturer = "Imagic, Brad Stewart",
        .model        = "720106-1A, IA3409",
        .name         = "Sky Patrol (1982) (Imagic) (Prototype)",
    },{
        .md5          = "4ca0959f846d2beada18ecf29efe137e",
        .manufacturer = "Atari, Jim Huether, Alan J. Murphy, Robert C. Polaro",
        .model        = "CX2666, CX2666P",
        .name         = "RealSports Volleyball (1982) (Atari) (PAL)",
    },{
        .md5          = "4ca73eb959299471788f0b685c3ba0b5",
        .manufacturer = "Activision, Steve Cartwright",
        .model        = "AX-031",
        .name         = "Frostbite (1983) (Activision)",
        .note         = "Iceman",
    },{
        .md5          = "4ca90ba45eced6f5ad560ea8938641b2",
        .name         = "Hangman Man Wordlist (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "4cabc895ea546022c2ecaa5129036634",
        .manufacturer = "Funvision - Fund. International Co.",
        .name         = "Ocean City (Funvision)",
        .note         = "AKA Atlantis",
    },{
        .md5          = "4cd796b5911ed3f1062e805a3df33d98",
        .manufacturer = "Tigervision - Software Electronics Corporation - Teldec",
        .model        = "7-006",
        .name         = "Springer (1983) (Tigervision)",
    },{
        .md5          = "4d06f72cc3d8934579c11ff8f375c260",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Bowling (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "4d0a28443f7df5f883cf669894164cfa",
        .name         = "Beast Invaders (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "4d2cef8f19cafeec72d142e34a1bbc03",
        .manufacturer = "HES",
        .model        = "771-422",
        .name         = "2 Pak Special - Star Warrior, Frogger (1990) (HES) (PAL) [a]",
    },{
        .md5          = "4d38e1105c3a5f0b3119a805f261fcb5",
        .manufacturer = "Bit Corporation",
        .model        = "PGP212",
        .name         = "Phantom UFO (4 Game in One Light Green) (1983) (BitCorp) (PAL)",
        .note         = "AKA Spider Fighter",
    },{
        .md5          = "4d502d6fb5b992ee0591569144128f99",
        .manufacturer = "Atari - Axlon, Tod Frye - Heuristica, Agustin Ortiz Valdiviezo",
        .model        = "CX26178",
        .name         = "Save Mary! (11-21-1989) (Atari) (Prototype)",
    },{
        .md5          = "4d5f6db55f7f44fd0253258e810bde21",
        .manufacturer = "Fabrizio Zavagli",
        .name         = "Betterblast (Fabrizio Zavagli) (Hack)",
        .note         = "Hack of Astroblast",
        .left         = "PADDLES",
        .swapPaddles  = 1,
    },{
        .md5          = "4d7517ae69f95cfbc053be01312b7dba",
        .manufacturer = "Atari, Alan Miller - Sears",
        .model        = "CX2641 - 99807, 49-75105",
        .name         = "Surround (1977) (Atari)",
    },{
        .md5          = "4d77f291dca1518d7d8e47838695f54b",
        .manufacturer = "Data Age",
        .model        = "DA1004",
        .name         = "Airlock (1982) (Data Age)",
    },{
        .md5          = "4d8396deeabb40b5e8578276eb5a8b6d",
        .manufacturer = "Otto Versand",
        .model        = "781698",
        .name         = "Volleyball (1983) (Otto Versand) (PAL)",
        .note         = "AKA RealSports Volleyball (Double-Game Package)",
    },{
        .md5          = "4dbd7e8b30e715efc8d71d215aec7fe7",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Air Raiders (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "4dbf47c7f5ac767a3b07843a530d29a5",
        .manufacturer = "Ric Pryor",
        .name         = "Breaking News (2002) (Ric Pryor) (Hack)",
        .note         = "Hack of Bump 'n' Jump",
    },{
        .md5          = "4dcc7e7c2ec0738e26c817b9383091af",
        .name         = "Unknown Title (bin00026 (200110)) (PD)",
    },{
        .md5          = "4dd6c7ab9ef77f2b4950d8fc7cd42ee1",
        .manufacturer = "Retroactive",
        .name         = "Qb (V2.04) (Stella) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "4df6124093ccb4f0b6c26a719f4b7706",
        .manufacturer = "Atari, Brad Stewart - Sears",
        .model        = "CX2622 - 6-99813, 49-75107",
        .name         = "Breakout (1978) (Atari) [a]",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "4df9d7352a56a458abb7961bf10aba4e",
        .name         = "Racing Car (Unknown)",
        .swapPorts    = 1,
    },{
        .md5          = "4e01d9072c500331e65bb87c24020d3f",
        .manufacturer = "Atari, Jerome Domurat, Howard Scott Warshaw",
        .model        = "CX26119",
        .name         = "Saboteur (06-15-1983) (Atari) (Prototype)",
    },{
        .md5          = "4e02880beeb8dbd4da724a3f33f0971f",
        .manufacturer = "Imagic, Michael Greene",
        .model        = "EIZ-002-04I",
        .name         = "Wing War (1983) (Imagic) (PAL)",
        .note         = "AKA Flap!",
    },{
        .md5          = "4e15ddfd48bca4f0bf999240c47b49f5",
        .manufacturer = "Avalon Hill, Jean Baer, Jim Jacob",
        .model        = "5001002",
        .name         = "Death Trap (1983) (Avalon Hill)",
        .phosphor     = 1,
    },{
        .md5          = "4e2c884d04b57b43f23a5a2f4e9d9750",
        .name         = "Baby Center Animation (PD)",
        .phosphor     = 1,
    },{
        .md5          = "4e37992a37ea36489283f7eb90913bbc",
        .manufacturer = "Kris",
        .name         = "Hangman Ghost Halloween (Kris) (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "4e4895c3381aa4220f8c2795d6338237",
        .name         = "Backwards Cannonball v1 (Hack)",
        .note         = "Hack of Human Cannonball",
    },{
        .md5          = "4e66c8e7c670532569c70d205f615dad",
        .manufacturer = "Atari - GCC",
        .model        = "CX2680, CX2680P",
        .name         = "RealSports Tennis (1983) (Atari) (PAL)",
    },{
        .md5          = "4e86866d9cde738d1630e2e35d7288ce",
        .name         = "Bermuda (Unknown)",
        .note         = "AKA River Raid",
    },{
        .md5          = "4e99ebd65a967cabf350db54405d577c",
        .manufacturer = "Coleco",
        .model        = "2663",
        .name         = "Time Pilot (1983) (Coleco) [b1]",
    },{
        .md5          = "4eb4fd544805babafc375dcdb8c2a597",
        .manufacturer = "Inspirational Video Concepts, Steve Shustack",
        .model        = "321430",
        .name         = "Red Sea Crossing (1983) (Inspirational Video Concepts)",
    },{
        .md5          = "4edb251f5f287c22efc64b3a2d095504",
        .manufacturer = "Atari",
        .name         = "Atari VCS Point-of-Purchase ROM (1982) (Atari)",
    },{
        .md5          = "4f0071946e80ca68edfdccbac86dcce0",
        .name         = "Virtual Pet Demo 1 (CRACKERS) (PD)",
    },{
        .md5          = "4f2d47792a06da224ba996c489a87939",
        .manufacturer = "HES - Activision",
        .model        = "223",
        .name         = "Super Action Pak - Pitfall, Barnstorming, Grand Prix, Laser Blast (1988) (HES) (PAL)",
    },{
        .md5          = "4f32b24869d8c1310fecf039c6424db6",
        .manufacturer = "U.S. Games Corporation - JWDA, Todd Marshall",
        .name         = "3-D Zapper (12-15-82) (U.S. Games) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "4f618c2429138e0280969193ed6c107e",
        .manufacturer = "Activision, Alan Miller",
        .model        = "AZ-028, AG-028-04",
        .name         = "Robot Tank (1983) (Activision)",
    },{
        .md5          = "4f634893d54e9cabe106e0ec0b7bdcdf",
        .manufacturer = "Retroactive",
        .name         = "Qb (2.14) (Retroactive) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "4f64d6d0694d9b7a1ed7b0cb0b83e759",
        .manufacturer = "20th Century Fox Video Games, John Russell",
        .model        = "11016",
        .name         = "Revenge of the Beefsteak Tomatoes (1983) (20th Century Fox)",
        .note         = "AKA Revenge of the Cherry Tomatoes",
    },{
        .md5          = "4f6702c3ba6e0ee2e2868d054b00c064",
        .manufacturer = "Activision - Woodside Design Associates, Steve 'Jessica Stevens' Kitchen - Ariola",
        .model        = "EAZ-033 - 711 033-725",
        .name         = "Space Shuttle (1983) (Activision) (PAL)",
        .note         = "A Journey Into Space, Eine Reise ins All",
    },{
        .md5          = "4f781f0476493c50dc578336f1132a67",
        .name         = "Indy 500 (Unknown) (PAL) (4K)",
        .note         = "Uses Driving Controllers",
        .left         = "DRIVING",
        .right        = "DRIVING",
    },{
        .md5          = "4f7b07ec2bef5ccffe06403a142f80db",
        .manufacturer = "Apollo - Games by Apollo, Ed Salvo, Byron Parks",
        .model        = "AP-2003",
        .name         = "Racquetball (1982) (Apollo) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "4f82d8d78099dd71e8e169646e799d05",
        .name         = "Miniature Golf (Unknown) (PAL) (4K)",
    },{
        .md5          = "4f89b897444e7c3b36aed469b8836839",
        .manufacturer = "Atari",
        .model        = "CX26190",
        .name         = "BMX Air Master (1989) (Atari) (PAL)",
    },{
        .md5          = "4fae08027365d31c558e400b687adf21",
        .name         = "Qb (V2.17) (NTSC) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "4faeb04b1b7fb0fa25db05753182a898",
        .name         = "2600 Digital Clock (V x.xx) (PD) [a1]",
    },{
        .md5          = "4fbe0f10a6327a76f83f83958c3cbeff",
        .manufacturer = "CCE",
        .model        = "C-816",
        .name         = "Keystone Kappers (1983) (CCE)",
        .note         = "AKA Keystone Kapers",
    },{
        .md5          = "4fc1b85b8074b4b9436d097900e34f29",
        .manufacturer = "John K. Harvey",
        .name         = "John K. Harvey's Equalizer (John K. Harvey)",
        .phosphor     = 1,
    },{
        .md5          = "50200f697aeef38a3ce31c4f49739551",
        .manufacturer = "Mystique - American Multiple Industries, Joel H. Martin",
        .name         = "Custer's Revenge (1982) (Mystique) (PAL60)",
    },{
        .md5          = "502044b1ac111b394e6fbb0d821fca41",
        .name         = "Hangman Invader 4letter (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "502168660bfd9c1d2649d415dc89c69d",
        .manufacturer = "Activision, Bob Whitehead - Ariola",
        .model        = "EAG-019, EAG-019-04I - 711 019-715",
        .name         = "Sky Jinks (1982) (Activision) (PAL) (4K)",
    },{
        .md5          = "504688d49a41bf03d8a955512609f3f2",
        .manufacturer = "Thomas Jentzsch",
        .name         = "SWOOPS! (v0.94) (Thomas Jentzsch)",
        .note         = "Uses the Joystick (L) and Paddle (R) Controllers",
    },{
        .md5          = "50568c80ac61cab789d9923c9b05b68e",
        .manufacturer = "Ebivision",
        .name         = "Merlin's Walls - Standard Edition (1999) (Ebivision)",
        .note         = "Image rotated 90 degrees CW",
    },{
        .md5          = "5069fecbe4706371f17737b0357cfa68",
        .manufacturer = "Apollo - Games by Apollo, Steve Stringfellow",
        .model        = "AP-2005",
        .name         = "Shark Attack (1982) (Apollo) (PAL)",
        .note         = "AKA Lochjaw",
    },{
        .md5          = "5079bfbc7b8f5770f84215ed2e3bdd1b",
        .manufacturer = "Omegamatrix (2012)",
        .name         = "Genesis Button Tester",
        .left         = "GENESIS",
        .right        = "GENESIS",
    },{
        .md5          = "50a410a5ded0fc9aa6576be45a04f215",
        .manufacturer = "Activision, Bob Whitehead - Ariola",
        .model        = "EAG-019, EAG-019-04I - 711 019-715",
        .name         = "Sky Jinks (1982) (Activision) (PAL)",
    },{
        .md5          = "50c7edc9f9dc0369abcdab3b4efeb5e9",
        .manufacturer = "U.S. Games Corporation - JWDA, Todd Marshall",
        .name         = "3-D Zapper (U.S. Games) (Prototype)",
    },{
        .md5          = "50ef88f9a5e0e1e6b86e175362a27fdb",
        .name         = "Multi-Sprite Game V2.4 (Piero Cavina) (PD)",
    },{
        .md5          = "512e874a240731d7378586a05f28aec6",
        .manufacturer = "Tigervision, Rorke Weigandt - Teldec",
        .model        = "7-005 - 3.60004 VE",
        .name         = "Marauder (1982) (Tigervision) (PAL)",
    },{
        .md5          = "5131ab3797fe8c127e3e135b18b4d2c8",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-004",
        .name         = "Fishing Derby (1980) (Activision) (8K)",
    },{
        .md5          = "514f911ecff2be5eeff2f39c49a9725c",
        .manufacturer = "Parker Brothers",
        .model        = "931510",
        .name         = "Sky Skipper (1983) (Parker Bros) (PAL)",
    },{
        .md5          = "515046e3061b7b18aa3a551c3ae12673",
        .manufacturer = "Atari - GCC, Mark Ackerman, Noelie Alito",
        .model        = "CX2692",
        .name         = "Moon Patrol (1983) (Atari)",
    },{
        .md5          = "516ffd008057a1d78d007c851e6eff37",
        .manufacturer = "Parker Brothers, Dawn Stockbridge",
        .model        = "PB5910",
        .name         = "Strawberry Shortcake - Musical Match-Ups (1983) (Parker Bros) (PAL)",
    },{
        .md5          = "517592e6e0c71731019c0cebc2ce044f",
        .manufacturer = "Parker Brothers - JWDA, Todd Marshall",
        .model        = "PB5550",
        .name         = "Q-bert's Qubes (1984) (Parker Bros)",
    },{
        .md5          = "517923e655755086a3b72c0b17b430e6",
        .manufacturer = "Tron",
        .name         = "Super Tennis (1983) (Tron)",
        .note         = "AKA RealSports Tennis",
    },{
        .md5          = "5188fee071d3c5ef0d66fb45c123e4a5",
        .manufacturer = "Gameworld",
        .model        = "133-001",
        .name         = "Encounter at L-5 (1983) (Gameworld) (PAL)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "519f007c0e14fb90208dbb5199dfb604",
        .manufacturer = "Amiga - Video Soft",
        .name         = "Depth Charge (1983) (Amiga) (Prototype)",
    },{
        .md5          = "51c1ddc9d6d597f71fb7efb56012abec",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Lock 'n' Chase (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "51de328e79d919d7234cf19c1cd77fbc",
        .manufacturer = "Atari, Mark R. Hahn",
        .model        = "CX2678",
        .name         = "Dukes of Hazzard (1983) (Atari)",
    },{
        .md5          = "51e390424f20e468d2b480030ce95d7b",
        .manufacturer = "Video Game Program",
        .name         = "Fire Bird (Video Game Program) (PAL)",
        .note         = "AKA Phoenix",
    },{
        .md5          = "51f15b39d9f502c2361b6ba6a73464d4",
        .name         = "Amanda Invaders (PD) [a]",
    },{
        .md5          = "51f211c8fc879391fee26edfa7d3f11c",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AX-015, AX-015-04",
        .name         = "Chopper Command (1982) (Activision) (8K)",
    },{
        .md5          = "521f4dd1eb84a09b2b19959a41839aad",
        .manufacturer = "Bit Corporation",
        .model        = "PG206",
        .name         = "Bobby Is Going Home (1983) (BitCorp)",
    },{
        .md5          = "522b27a8afeb951b5a5a667f8d1a46a1",
        .manufacturer = "Omegamatrix",
        .name         = "Millipede (Amiga Mouse) v6.5 (Omegamatrix)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "522c9cf684ecd72db2f85053e6f6f720",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-008",
        .name         = "Year 1999, The (1983) (Rainbow Vision) (PAL)",
        .note         = "AKA Condor Attack",
    },{
        .md5          = "52385334ac9e9b713e13ffa4cc5cb940",
        .manufacturer = "CCE",
        .model        = "C-804",
        .name         = "Open, Sesame! (1983) (CCE)",
        .note         = "AKA Abre-te, Sesamo!",
        .phosphor     = 1,
    },{
        .md5          = "523f5cbb992f121e2d100f0f9965e33f",
        .manufacturer = "Joe Grand",
        .name         = "SCSIcide (1.30) (CGE 2001 Release) (Joe Grand)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXDR",
    },{
        .md5          = "524693b337f7ecc9e8b9126e04a232af",
        .name         = "Euchre (19-08-2001) (Eric Eid) (PD)",
    },{
        .md5          = "5256f68d1491986aae5cfdff539bfeb5",
        .manufacturer = "Atari - GCC, Mark Ackerman, Noelie Alito",
        .model        = "CX2692",
        .name         = "Moon Patrol (07-26-1983) (Atari) (Prototype)",
    },{
        .md5          = "525ea747d746f3e80e3027720e1fa7ac",
        .manufacturer = "Activision, Garry Kitchen - Ariola",
        .model        = "EAZ-032 - 771 032-712",
        .name         = "Pressure Cooker (1983) (Activision) (PAL)",
    },{
        .md5          = "525f2dfc8b21b0186cff2568e0509bfc",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-930-04, AZ-030",
        .name         = "Decathlon (1983) (Activision) [fixed]",
        .right        = "PADDLES",
    },{
        .md5          = "52615ae358a68de6e76467e95eb404c7",
        .name         = "DJdsl-wopd (PD)",
        .phosphor     = 1,
    },{
        .md5          = "528400fad9a77fd5ad7fc5fdc2b7d69d",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum, Jon Leupp",
        .model        = "11 AR-4201",
        .name         = "Sword of Saros (1983) (Starpath)",
    },{
        .md5          = "52a0003efb3b1c49fcde4dbc2c685d8f",
        .manufacturer = "Atari, Alan Miller - Sears",
        .model        = "CX2641 - 99807, 49-75105",
        .name         = "Surround (1977) (Atari) (4K) [a]",
        .type         = "2K",
    },{
        .md5          = "52a207c2ac6b4dc87d5650f1d7bf5dfa",
        .name         = "Donkey Kong (Unknown) (Hack)",
    },{
        .md5          = "52b448757081fd9fabf859f4e2f91f6b",
        .name         = "Worm War I (Unknown) (PAL)",
    },{
        .md5          = "52bae1726d2d7a531c9ca81e25377fc3",
        .name         = "Space Instigators (V1.8 Fixed) (20-10-2002) (Christopher Tumber)",
    },{
        .md5          = "52e1954dc01454c03a336b30c390fb8d",
        .manufacturer = "Retroactive",
        .name         = "Qb (2.14) (Retroactive) (Stella)",
        .phosphor     = 1,
    },{
        .md5          = "52e9db3fe8b5d336843acac234aaea79",
        .name         = "Fu Kung! (V0.11) (28-01-2003) (Andrew Davie)",
    },{
        .md5          = "5305f69fbf772fac4760cdcf87f1ab1f",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Ski Run (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "5324cf5b6dc17af4c64bf8696c39c2c1",
        .manufacturer = "Imagic, Dennis Koble",
        .model        = "IA3203, IX-010-04",
        .name         = "Atlantis (1982) (Imagic) (8K)",
        .note         = "AKA Lost City of Atlantis",
    },{
        .md5          = "533661e9bccd8a9f80ce3765f282c92f",
        .manufacturer = "Omegamatrix",
        .name         = "Star Wars Arcade (Atari Trak-Ball) (Y Inverted) v4 (Omegamatrix)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "5336f86f6b982cc925532f2e80aa1e17",
        .manufacturer = "Parker Brothers - JWDA, Todd Marshall, Robin McDaniel, Ray Miller",
        .model        = "PB5060",
        .name         = "Star Wars - Death Star Battle (1983) (Parker Bros)",
        .phosphor     = 1,
    },{
        .md5          = "534e23210dd1993c828d944c6ac4d9fb",
        .manufacturer = "M Network, Stephen Tatsumi, Jane Terjung - Kool Aid",
        .model        = "MT4648",
        .name         = "Kool-Aid Man (1983) (M Network)",
        .note         = "AKA Kool Aid Pitcher Man",
    },{
        .md5          = "5355f80cacf0e63a49cbf4ade4e27034",
        .manufacturer = "Christian Samuel",
        .name         = "Cute Dead Things House (Christian Samuel) (Hack)",
        .note         = "Hack of Haunted House",
    },{
        .md5          = "5360693f1eb90856176bd1c0a7b17432",
        .name         = "Oystron (V2.85) (Piero Cavina) (PD)",
    },{
        .md5          = "536bf56baa70acb17113884ac41f2820",
        .manufacturer = "Atari, Omegamatrix",
        .name         = "Video Olympics Menu (2020) (PAL) (Hack)",
        .note         = "Hack of Video Olympics",
        .swapPaddles  = 1,
    },{
        .md5          = "537ed1e0d80e6c9f752b33ea7acbe079",
        .name         = "A-VCS-tec Challenge (beta 5) (PD)",
    },{
        .md5          = "5385cf2a04de1d36ab55c73174b84db0",
        .manufacturer = "Paul Slocum",
        .name         = "Combat Rock (PD) (Hack)",
        .note         = "Hack of Combat",
    },{
        .md5          = "539d26b6e9df0da8e7465f0f5ad863b7",
        .manufacturer = "Atari, Carol Shaw - Sears",
        .model        = "CX2636 - 49-75156",
        .name         = "Video Checkers (1980) (Atari)",
    },{
        .md5          = "539f3c42c4e15f450ed93cb96ce93af5",
        .manufacturer = "Dion Olsthoorn",
        .model        = "v1.3",
        .name         = "Amoeba Jump (2018) (Dionoid)",
    },{
        .md5          = "53b66f11f67c3b53b2995e0e02017bd7",
        .manufacturer = "CCE",
        .model        = "C-1005",
        .name         = "Super Tennis (1983) (CCE)",
        .note         = "AKA RealSports Tennis",
    },{
        .md5          = "53bd1c7c972ae634c912331a9276c6e3",
        .manufacturer = "Atari, Nick 'Sandy Maiwald' Turner",
        .model        = "CX2665",
        .name         = "Frog Pond (1982) (Atari) (Prototype) (4K)",
    },{
        .md5          = "53d181cde2e0219b5754caad246fcb66",
        .name         = "Missile Demo (1998) (Ruffin Bailey) (PD)",
    },{
        .md5          = "53e03df47e76329b701641f8bdc206f5",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Atari Trak-Ball Hack v1.4 (PAL) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "53f147b9746fdc997c62f3dd67888ee5",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AG-011",
        .name         = "Stampede (1981) (Activision) (8K)",
    },{
        .md5          = "540075f657d4b244a1f74da1b9e4bf92",
        .manufacturer = "Bit Corporation",
        .model        = "PGP230",
        .name         = "Festival (4 Game in One Dark Green) (1983) (BitCorp) (PAL)",
        .note         = "AKA Carnival",
    },{
        .md5          = "5409d20c1aea0b89c56993aec5dc5740",
        .name         = "Carnival Shooter (PD)",
    },{
        .md5          = "541cac55ebcf7891d9d51c415922303f",
        .manufacturer = "SpiceWare - Darrell Spice Jr.",
        .model        = "SW-05",
        .name         = "Stay Frosty 2",
        .note         = "AtariAge Holiday Greetings 2014",
        .left         = "JOYSTICK",
        .phosphor     = 1,
    },{
        .md5          = "5428cdfada281c569c74c7308c7f2c26",
        .manufacturer = "Activision, Larry Kaplan, David Crane",
        .model        = "AG-010, CAG-010, AG-010-04",
        .name         = "Kaboom! (1981) (Activision)",
        .note         = "Uses the Paddle Controllers (left only)",
    },{
        .md5          = "542c6dd5f7280179b51917a4cba4faff",
        .manufacturer = "ZiMAG - Emag - Vidco",
        .model        = "GN-080",
        .name         = "Spinning Fireball (1983) (ZiMAG) (Prototype)",
    },{
        .md5          = "5438e84b90e50a5362f01cc843b358d4",
        .manufacturer = "Arcadia Corporation, Scott Nelson",
        .model        = "3 AR-4300",
        .name         = "Fireball (1982) (Arcadia) (Prototype)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "543b4b8ff1d616fa250c648be428a75c",
        .manufacturer = "Warren Robinett",
        .name         = "Adventure (1978) (Warren Robinett) (Hack)",
        .note         = "Hack of Adventure",
    },{
        .md5          = "545048ccb045f9efc6cf2b125cd0dfa8",
        .manufacturer = "Arcadia Corporation, Stephen Harland Landrum, Jon Leupp",
        .model        = "AR-4201",
        .name         = "Sword of Saros (1983) (Arcadia) [a]",
    },{
        .md5          = "54785fa29e28aae6038929ba29d33d38",
        .name         = "Poker Squares (V0.19) (2001) (B. Watson)",
    },{
        .md5          = "54836a8f23913e9a77c7f2665baf36ac",
        .manufacturer = "Bit Corporation",
        .model        = "PG204",
        .name         = "Open, Sesame! (1982) (BitCorp)",
    },{
        .md5          = "5494b9ee403d9757f0fd1f749e80214a",
        .manufacturer = "Larry Petit",
        .name         = "Xenophobe Arcade (2003) (Larry Petit) (Hack)",
        .note         = "Hack of Xenophobe",
    },{
        .md5          = "54a1c1255ed45eb8f71414dadb1cf669",
        .manufacturer = "Spectravideo",
        .model        = "SA-212",
        .name         = "Mangia' (1983) (Spectravideo)",
    },{
        .md5          = "54bafc299423f5a50b8bc3a797914706",
        .manufacturer = "SOLID Corp. (D. Scott Williamson)",
        .model        = "CX2655*",
        .name         = "Star Castle 2600 (SolidCorp) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "54da3b0b3f43f5b37911c135b9432b49",
        .name         = "Halloween III Revision (Hack)",
        .note         = "Hack of Kaboom!",
    },{
        .md5          = "54f7efa6428f14b9f610ad0ca757e26c",
        .manufacturer = "Apollo - Games by Apollo, Steve Stringfellow",
        .model        = "AP-2005",
        .name         = "Shark Attack (1982) (Apollo)",
        .note         = "AKA Lochjaw",
    },{
        .md5          = "551a64a945d7d6ece81e9c1047acedbc",
        .manufacturer = "Matthias Jaap",
        .name         = "Coffee Cup Soccer (Matthias Jaap) (Hack)",
        .note         = "Hack of Pele's Soccer",
    },{
        .md5          = "5524718a19107a04ec3265c93136a7b5",
        .manufacturer = "Thomas Jentzsch",
        .name         = "RealSports Basketball (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "553dbf9358cfd2195e2fa0e08b01fb6a",
        .manufacturer = "Atari - GCC, Mike Feinstein, Kevin Osborn",
        .model        = "CX2691",
        .name         = "Joust (07-05-1983) (Atari) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "554fd5775ca6d544818c96825032cf0d",
        .manufacturer = "Atari - Roklan, Bob Curtiss",
        .name         = "Firefox (06-01-83) (Atari) (Prototype)",
        .note         = "AKA Combat II, Fighter Command",
    },{
        .md5          = "557e893616648c37a27aab5a47acbf10",
        .manufacturer = "Atari - Axlon, Tod Frye - Heuristica, Agustin Ortiz Valdiviezo",
        .model        = "CX26169",
        .name         = "Shooting Arcade (01-16-1990) (Atari) (Prototype) (PAL)",
        .note         = "Uses the Light Gun Controller (left only)",
    },{
        .md5          = "559317712f989f097ea464517f1a8318",
        .manufacturer = "Panda",
        .model        = "100",
        .name         = "Space Canyon (1983) (Panda)",
        .note         = "AKA Space Cavern",
    },{
        .md5          = "55949cb7884f9db0f8dfcf8707c7e5cb",
        .manufacturer = "Atari, Ed Logg, Carol Shaw - Sears",
        .model        = "CX2639 - 49-75162",
        .name         = "Othello (1981) (Atari)",
    },{
        .md5          = "55ace3c775f42eb46f08bb1dca9114e7",
        .name         = "Shadow Keep (04-03-2003) (Andrew Towers)",
    },{
        .md5          = "55ef6ab2321ca0c3d369e63d59c059c8",
        .name         = "Pitfall! (Unknown) (PAL)",
        .note         = "Pitfall Harry's Jungle Adventure",
    },{
        .md5          = "55ef7b65066428367844342ed59f956c",
        .manufacturer = "Atari - Roklan, Joe Gaucher, Alex Leavens",
        .model        = "CX2683",
        .name         = "Crazy Climber (1983) (Atari)",
    },{
        .md5          = "56210a3b9ea6d5dd8f417a357ed8ca92",
        .manufacturer = "Probe 2000 - NAP, Roger Booth, Todd Marshall, Robin McDaniel, Jim Wickstead",
        .model        = "3152VC",
        .name         = "Pursuit of the Pink Panther (Probe) (Prototype) [bad dump]",
        .note         = "AKA Adventures of the Pink Panther",
    },{
        .md5          = "56300ed31fef018bd96768ccc982f7b4",
        .manufacturer = "HES - Activision",
        .model        = "559",
        .name         = "Rad Action Pak - Kung-Fu Master, Freeway, Frostbite (1990) (HES) (PAL)",
    },{
        .md5          = "5641c0ff707630d2dd829b26a9f2e98f",
        .manufacturer = "Joystik",
        .name         = "Motocross (Joystik)",
        .note         = "AKA Motocross Racer",
    },{
        .md5          = "5643ee916f7dc760148fca4db3aa7d10",
        .name         = "Moon Patrol (Genesis)",
        .note         = "Genesis controller (C is jump)",
    },{
        .md5          = "5678ebaa09ca3b699516dba4671643ed",
        .manufacturer = "Coleco, Sylvia Day, Henry Will IV",
        .model        = "2459",
        .name         = "Mouse Trap (1982) (Coleco)",
        .phosphor     = 1,
    },{
        .md5          = "568371fbae6f5e5b936af80031cd8888",
        .name         = "Robotfindskitten2600 (26-04-2003) (Jeremy Penner)",
    },{
        .md5          = "56f72247eb9ebfd33bfd0cca23ab7ef4",
        .manufacturer = "Omegamatrix",
        .name         = "Star Wars Arcade (Amiga Mouse) v4 (PAL60) (Omegamatrix)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "571c6d9bc71cb97617422851f787f8fe",
        .manufacturer = "Activision, David Crane - Ariola",
        .model        = "EAG-004, PAG-004 - 711 004-715",
        .name         = "Fishing Derby (1980) (Activision) (PAL)",
        .note         = "AKA Schneller als der Hai",
    },{
        .md5          = "572d0a4633d6a9407d3ba83083536e0f",
        .manufacturer = "Funvision - Fund. International Co.",
        .name         = "Busy Police (Funvision)",
        .note         = "AKA Keystone Kapers",
    },{
        .md5          = "575c0fb61e66a31d982c95c9dea6865c",
        .name         = "Blackjack (Unknown) (PAL)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXIS",
    },{
        .md5          = "57939b326df86b74ca6404f64f89fce9",
        .manufacturer = "Atari, Ed Bogas, Sam Comstock, Richard Dobbis, Nick 'Sandy Maiwald' Turner",
        .model        = "CX26111",
        .name         = "Snoopy and the Red Baron (1983) (Atari)",
    },{
        .md5          = "579baa6a4aa44f035d245908ea7a044d",
        .manufacturer = "Jess Ragan",
        .name         = "Galaxian Enhanced Graphics (Jess Ragan) (Hack)",
        .note         = "Hack of Galaxian",
    },{
        .md5          = "57a66b6db7efc5df17b0b0f2f2c2f078",
        .manufacturer = "Retroactive",
        .name         = "Qb (V2.08) (NTSC) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "57c5b351d4de021785cf8ed8191a195c",
        .manufacturer = "Atari - CCW, Gary Stark",
        .model        = "CX26102",
        .name         = "Cookie Monster Munch (1983) (Atari)",
        .note         = "Uses Kids/Keyboard Controllers",
        .right        = "KEYBOARD",
    },{
        .md5          = "5835a78a88f97acea38c964980b7dbc6",
        .name         = "Cosmic Creeps (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "5846b1d34c296bf7afc2fa05bbc16e98",
        .manufacturer = "Atari - Sears",
        .model        = "CX2643 - 6-99815",
        .name         = "Codebreaker (1978) (Atari)",
        .note         = "Uses Keyboard Controllers",
    },{
        .md5          = "58513bae774360b96866a07ca0e8fd8e",
        .manufacturer = "Mystique - American Multiple Industries, Joel H. Martin",
        .model        = "1001",
        .name         = "Custer's Revenge (1982) (Mystique)",
    },{
        .md5          = "585600522b1f22f617652c962e358a5d",
        .name         = "Multi-Sprite Game V2.2 (Piero Cavina) (PD)",
    },{
        .md5          = "585f73010e205ae5b04ee5c1a67e632d",
        .name         = "Daredevil (V3) (Stunt_Cycle_Rules!) (PD)",
    },{
        .md5          = "5864cab0bc21a60be3853b6bcd50c59f",
        .name         = "Commando Raid (Unknown) (PAL)",
    },{
        .md5          = "58746219d8094edff869f0f5c2aeaad5",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Bowling (Jone Yuan) (4K)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "5894c9c0c1e7e29f3ab86c6d3f673361",
        .manufacturer = "Activision - Woodside Design Associates, Steve 'Jessica Stevens' Kitchen",
        .model        = "AZ-033, AZ-033-04",
        .name         = "Space Shuttle (1983) (Activision)",
        .note         = "A Journey Into Space",
    },{
        .md5          = "589c73bbcd77db798cb92a992b4c06c3",
        .manufacturer = "Xonox - K-Tel Software - Action Graphics, Michael Schwartz, David Thiel",
        .model        = "6230, 7210, 06004, 99004",
        .name         = "Artillery Duel (1983) (Xonox) (PAL60)",
    },{
        .md5          = "58a82e1da64a692fd727c25faef2ecc9",
        .manufacturer = "CCE",
        .model        = "C-824",
        .name         = "Jaw Breaker (1983) (CCE)",
    },{
        .md5          = "58af1e991b55710486a9868f75b15cf0",
        .name         = "M.A.S.H (Unknown) (PAL)",
    },{
        .md5          = "58c396323ea3e85671e34c98eb54e2a4",
        .manufacturer = "Brian Watson",
        .name         = "Color Tweaker (B. Watson)",
    },{
        .md5          = "58d331c23297ed98663d11b869636f16",
        .name         = "Fu Kung! (V0.09) (26-01-2003) (Andrew Davie)",
    },{
        .md5          = "58e313e2b5613b2439b5f12bb41e3eef",
        .name         = "Cube Conquest (Demo Interlace) (Billy Eno) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "590ac71fa5f71d3eb29c41023b09ade9",
        .manufacturer = "Atari - GCC, Mark Ackerman, Tom Calderwood, Glenn Parker",
        .model        = "CX2684",
        .name         = "Galaxian (01-05-1983) (Atari) (Prototype)",
    },{
        .md5          = "59135f13985b84c4f13cc9e55eec869a",
        .name         = "Multi-Sprite Game V2.0 (Piero Cavina) (PD)",
    },{
        .md5          = "594437a35603c3e857b5af75b9718b61",
        .manufacturer = "HES - Activision",
        .name         = "Robot Tank (HES) (PAL)",
    },{
        .md5          = "594dbc80b93fa5804e0f1368c037331d",
        .manufacturer = "Telesys, Alex Leavens",
        .name         = "Bouncin' Baby Bunnies (1983) (Telesys) (Prototype)",
        .note         = "AKA Baby Boom Boom, Bouncing Baby Monkeys",
    },{
        .md5          = "5961d259115e99c30b64fe7058256bcf",
        .manufacturer = "Universal Gamex Corporation, Miguel Castillo, H.K. Poon",
        .model        = "GX-001",
        .name         = "X-Man (1983) (Universal)",
    },{
        .md5          = "59734e1cc41822373845a09c51e6ba21",
        .manufacturer = "Activision, John Van Ryzin",
        .model        = "AG-038-04",
        .name         = "Cosmic Commuter (1984) (Activision) (8K)",
    },{
        .md5          = "598a4e6e12f8238b7e7555f5a7777b46",
        .manufacturer = "Tigervision",
        .model        = "7-008",
        .name         = "Miner 2049er (1983) (Tigervision) (Prototype)",
    },{
        .md5          = "599cbf919d47a05af975ad447df29497",
        .manufacturer = "Jake Patterson",
        .name         = "Baubles (V0.002) (2001) (Jake Patterson) (PD)",
    },{
        .md5          = "59b70658f9dd0e2075770b07be1a35cf",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Surfer's Paradise (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "59d33e00c07665395209c1e55da0b139",
        .name         = "Imagic Selector ROM (1982) (Imagic)",
    },{
        .md5          = "59e53894b3899ee164c91cfa7842da66",
        .manufacturer = "Data Age",
        .name         = "Survival Run (1983) (Data Age) (Prototype)",
    },{
        .md5          = "59e96de9628e8373d1c685f5e57dcf10",
        .manufacturer = "PlayAround - J.H.M.",
        .model        = "204",
        .name         = "Beat 'Em & Eat 'Em (1982) (PlayAround)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "59f596285d174233c84597dee6f34f1f",
        .manufacturer = "CCE",
        .model        = "C-811",
        .name         = "River Raid (1983) (CCE)",
    },{
        .md5          = "5a0ff99ba10bd26d542e1d6f59f56850",
        .manufacturer = "Champ Games",
        .model        = "CG-04-P",
        .name         = "Super Cobra Arcade (PAL60)",
        .note         = "Compatible with Genesis controller",
        .left         = "JOYSTICK",
        .phosphor     = 1,
    },{
        .md5          = "5a17e30e6e911e74ccd7b716d02b16c6",
        .manufacturer = "Activision, Dan Kitchen",
        .model        = "AX-029",
        .name         = "Crackpots (1983) (Activision) (8K)",
    },{
        .md5          = "5a272012a62becabcd52920348c7c60b",
        .name         = "Tom Boy (Unknown)",
        .note         = "AKA Pitfall!",
    },{
        .md5          = "5a2f2dcd775207536d9299e768bcd2df",
        .manufacturer = "Otto Versand",
        .model        = "781698",
        .name         = "Flippern (Double-Game Package) (1983) (Otto Versand) (PAL)",
        .note         = "AKA Video Pinball",
    },{
        .md5          = "5a4205aeedd3b0588f973f38bbd9dfd4",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Amiga Mouse Hack v1.4 (PAL) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "5a5390f91437af9951a5f8455b61cd43",
        .manufacturer = "Retroactive",
        .name         = "Qb (0.11) (Retroactive) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "5a6febb9554483d8c71c86a84a0aa74e",
        .manufacturer = "CCE",
        .model        = "C-1003",
        .name         = "Donkey Kong Jr (1983) (CCE)",
        .note         = "AKA Donkey Kong Junior",
    },{
        .md5          = "5a734779d797ccef25dc8acfa47244c7",
        .name         = "Oh No! (Version 2) (18-01-2003) (Andrew Davie)",
    },{
        .md5          = "5a80b857eb8b908ab477ec4ef902edc8",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AG-002, CAG-002, AG-002-04",
        .name         = "Boxing (1980) (Activision) (8K)",
    },{
        .md5          = "5a81ad4e184050851e63c8e16e3dac77",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .model        = "Hack",
        .name         = "Sky Diver (Jone Yuan) (Hack)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "5a8afe5422abbfb0a342fb15afd7415f",
        .manufacturer = "Atari - Bobco, Robert C. Polaro",
        .model        = "CX26155",
        .name         = "Sprint Master (1988) (Atari)",
        .note         = "AKA Sprint 88, Sprint 2000",
    },{
        .md5          = "5a93265095146458df2baf2162014889",
        .manufacturer = "Activision, Steve Cartwright - Ariola",
        .model        = "EAX-031, EAX-031-04B - 711 031-717",
        .name         = "Frostbite (1983) (Activision) (PAL)",
        .note         = "Expedition ins Eis (Iceman)",
    },{
        .md5          = "5a9685c4d51a6c1d6a9544946d9e8dc3",
        .manufacturer = "AtariAge",
        .name         = "Grandma's Revenge (AtariAge)",
        .note         = "Can use Driving Controller in right port",
        .right        = "DRIVING",
    },{
        .md5          = "5a9d188245aff829efde816fcade0b16",
        .manufacturer = "CCE",
        .model        = "C-808",
        .name         = "Phantom Tank (1983) (CCE) (PAL)",
    },{
        .md5          = "5acf9865a72c0ce944979f76ff9610f0",
        .name         = "Dodge Demo 2 (PD)",
    },{
        .md5          = "5ae73916fa1da8d38ceff674fa25a78a",
        .manufacturer = "CCE",
        .name         = "Barnstorming (CCE)",
    },{
        .md5          = "5aea9974b975a6a844e6df10d2b861c4",
        .manufacturer = "Atari, Dan Hitchens. Mimi Nyden",
        .model        = "CX2656",
        .name         = "SwordQuest - EarthWorld (1982) (Atari)",
        .note         = "AKA Adventure I, SwordQuest I - EarthWorld",
    },{
        .md5          = "5af9cd346266a1f2515e1fbc86f5186a",
        .manufacturer = "SEGA",
        .model        = "002-01",
        .name         = "Sub-Scan (1983) (SEGA)",
        .note         = "AKA Subterfuge",
    },{
        .md5          = "5b124850de9eea66781a50b2e9837000",
        .manufacturer = "PlayAround - J.H.M.",
        .model        = "205",
        .name         = "Bachelor Party (1982) (PlayAround)",
        .note         = "Uses the paddle controllers",
        .left         = "PADDLES_IAXIS",
        .phosphor     = 1,
    },{
        .md5          = "5b574faa56836da0866ba32ae32547f2",
        .name         = "Tomb Raider 2600 [REV 03] (Montezuma's Revenge Hack)",
    },{
        .md5          = "5b5d04887922b430de0b7b2a21f9cd25",
        .name         = "Omega Race (Genesis)",
        .note         = "Genesis controller (B is thrust, C is fire)",
    },{
        .md5          = "5b6f5bcbbde42fc77d0bdb3146693565",
        .name         = "Seaquest (Unknown) (PAL)",
    },{
        .md5          = "5b7ea6aa6b35dc947c65ce665fde624b",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum",
        .model        = "AR-4400",
        .name         = "Dragonstomper (2 of 3) (1982) (Starpath)",
    },{
        .md5          = "5b85e987e2b1618769d97ba9182333d0",
        .manufacturer = "Atari - GCC, Mike Feinstein, Brad Rice",
        .model        = "CX2681",
        .name         = "Battlezone (05-12-1983) (Atari) (Prototype)",
    },{
        .md5          = "5b92a93b23523ff16e2789b820e2a4c5",
        .manufacturer = "Activision - Imagineering, Dan Kitchen, Garry Kitchen",
        .model        = "AG-039-04",
        .name         = "Kung-Fu Master (1987) (Activision)",
    },{
        .md5          = "5b98e0536c3f60547dd708ae22adb04b",
        .manufacturer = "Ben Hudman",
        .name         = "Donkey Kong Gingerbread Man (Ben Hudman) (Prototype)",
    },{
        .md5          = "5b9c2e0012fbfd29efd3306359bbfc4a",
        .manufacturer = "HES",
        .name         = "2 Pak Special - Hoppy, Alien Force (1992) (HES) (PAL) [a]",
    },{
        .md5          = "5babe0cad3ec99d76b0aa1d36a695d2f",
        .manufacturer = "Coleco - Individeo, Ed Temple",
        .model        = "2654",
        .name         = "Looping (1983) (Coleco) (Prototype)",
    },{
        .md5          = "5bba254e18257e578c245ed96f6b003b",
        .name         = "Music Effects Demo (21-01-2003) (Paul Slocum)",
        .phosphor     = 1,
    },{
        .md5          = "5bbab3f3e4b47e3e23f9820765dbb45c",
        .name         = "Pitfall! (says 1985) [h1]",
    },{
        .md5          = "5bbb75b49b2bccef9c91ff84bb249c80",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Control - Atari Trak-Ball Hack v1.15 (NTSC) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "5bc9998b7e9a970e31d2cb60e8696cc4",
        .manufacturer = "Jack Kortkamp",
        .name         = "Borgwars Asteroids (2003) (Jack Kortkamp) (Hack)",
        .note         = "Hack of Asteroids",
        .phosphor     = 1,
    },{
        .md5          = "5bcc83677d68f7ef74c1b4a0697ba2a8",
        .manufacturer = "Activision, Alan Miller",
        .model        = "AX-012, CAX-012, AX-012-04",
        .name         = "Ice Hockey (1981) (Activision) (16K)",
        .type         = "4K",
    },{
        .md5          = "5bd79139a0c03b63f6f2cf00a7d385d2",
        .manufacturer = "Marc de Smet",
        .name         = "An Exercise In Minimalism (V1) (1999) (Marc de Smet) (PD)",
    },{
        .md5          = "5be03a1fe7b2c114725150be04b38704",
        .manufacturer = "Atari, Alan Miller",
        .model        = "CX2642",
        .name         = "Hunt & Score (1978) (Atari) (PAL)",
        .note         = "Uses Keyboard Controllers",
    },{
        .md5          = "5c0227ad63300670a647fcebf595ea37",
        .manufacturer = "Josh",
        .name         = "Battle for Naboo (Josh) (Hack)",
        .note         = "Hack of Atlantis",
    },{
        .md5          = "5c0520c00163915a4336e481ca4e7ef4",
        .name         = "Pyramid War (Unknown) (PAL)",
        .note         = "AKA Chopper Command",
    },{
        .md5          = "5c19f6da638c4c7c1f98d09e63df43e4",
        .manufacturer = "Canal 3 - Intellivision",
        .name         = "Cosmic Ark (Canal 3)",
    },{
        .md5          = "5c1b1aa78b7609d43c5144c3b3b60adf",
        .name         = "Demo Image Series #8 - Two Marios (Different Interlacing) (27-02-2003) (Andrew Davie)",
    },{
        .md5          = "5c3a6d27c026f59a96b7af91e8b1bf26",
        .manufacturer = "PlayAround - JHM",
        .name         = "PlayAround Demo (PlayAround) (1982)",
    },{
        .md5          = "5c618a50dfa23daac97ba459b9ff5206",
        .manufacturer = "Steve Engelhardt",
        .name         = "Berzerk Renegade (2002) (Steve Engelhardt) (Hack)",
        .note         = "Hack of Room of Doom",
        .phosphor     = 1,
    },{
        .md5          = "5c73693a89b06e5a09f1721a13176f95",
        .name         = "Wavy Line Test 2 (PD)",
    },{
        .md5          = "5c86e938e0845b9d61f458539e9a552b",
        .manufacturer = "Atari, Alan Miller",
        .model        = "CX26163P",
        .name         = "Surround (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "5cbd7c31443fb9c308e9f0b54d94a395",
        .manufacturer = "Spectravideo, Mark Turmell",
        .model        = "SA-217",
        .name         = "Gas Hog (1983) (Spectravideo) [fixed]",
    },{
        .md5          = "5ce98f22ade915108860424d8dde0d35",
        .name         = "Hangman Man Biglist3 (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "5ced13931c21ef4fc77d3fe801a1cbfa",
        .manufacturer = "CCE",
        .model        = "C-828",
        .name         = "Missile Command (1983) (CCE)",
        .phosphor     = 1,
    },{
        .md5          = "5d0e8a25cbd23e76f843c75a86b7e15b",
        .manufacturer = "Coleco - Individeo, Ed Temple",
        .name         = "Cabbage Patch Kids (09-07-1984) (Coleco) (Prototype)",
        .note         = "Adventures in the Park",
    },{
        .md5          = "5d132d121aabc5235dd039dfc46aa024",
        .name         = "Basketball (Unknown) (PAL) (Hack)",
        .note         = "Console ports are swapped",
        .swapPorts    = 1,
    },{
        .md5          = "5d25df9dc2cde746ceac48e834cf84a7",
        .manufacturer = "Activision - Woodside Design Associates, Steve 'Jessica Stevens' Kitchen",
        .model        = "EAZ-033",
        .name         = "Space Shuttle (1983) (Activision) (SECAM)",
        .note         = "A Journey Into Space",
        .type         = "FE",
    },{
        .md5          = "5d2cc33ca798783dee435eb29debf6d6",
        .manufacturer = "Activision - Imagineering, Mike Reidel",
        .model        = "AK-043-04",
        .name         = "Commando (1988) (Activision)",
    },{
        .md5          = "5d7293f1892b66c014e8d222e06f6165",
        .manufacturer = "Atari - Axlon, Tod Frye - Heuristica, Agustin Ortiz Valdiviezo",
        .model        = "CX26169",
        .name         = "Shooting Arcade (03-07-1989) (Atari) (Prototype) [screen 2]",
        .note         = "Uses the Light Gun Controller (left only)",
    },{
        .md5          = "5d799bfa9e1e7b6224877162accada0d",
        .manufacturer = "Spectravision - Spectravideo - Sirius Software, David Lubar",
        .model        = "SA-206",
        .name         = "Challenge of.... Nexar, The (1982) (Spectravision)",
    },{
        .md5          = "5d8f1ab95362acdf3426d572a6301bf2",
        .manufacturer = "Thomas Jentzsch",
        .name         = "SWOOPS! (v0.96) (Thomas Jentzsch) (PAL)",
        .note         = "Uses the Joystick (L) and Paddle (R) Controllers",
    },{
        .md5          = "5d8fb14860c2f198472b233874f6b0c9",
        .name         = "Boing! (PD) [a2]",
    },{
        .md5          = "5d9592756425192ec621d2613d0e683d",
        .manufacturer = "CCE",
        .model        = "C-839",
        .name         = "Misterious Thief, A (1983) (CCE) [a]",
        .note         = "AKA A Mysterious Thief",
    },{
        .md5          = "5da8fd0b5ed33a360bff37f8b5d0cd58",
        .manufacturer = "Tron",
        .name         = "Pole Position (Tron)",
    },{
        .md5          = "5dae540347cf0a559962d62604ecf750",
        .manufacturer = "Canal 3 - Intellivision",
        .name         = "Freeway (Canal 3) (4K)",
    },{
        .md5          = "5db9e5bf663cad6bf159bc395f6ead53",
        .manufacturer = "Goliath - Hot Shot",
        .model        = "83-212",
        .name         = "Time Race (1983) (Goliath) (PAL)",
        .note         = "AKA Space Jockey",
    },{
        .md5          = "5dccf215fdb9bbf5d4a6d0139e5e8bcb",
        .manufacturer = "Froggo",
        .model        = "FG1009",
        .name         = "Sea Hunt (1987) (Froggo)",
        .note         = "AKA Skindiver",
    },{
        .md5          = "5dd08e85fd7b928df16f59df92a9d983",
        .name         = "Boom Bang (Unknown) [a2]",
        .note         = "AKA Crackpots",
    },{
        .md5          = "5de8803a59c36725888346fdc6e7429d",
        .manufacturer = "Atari, John Dunn - Sears",
        .model        = "CX2631 - 49-75152",
        .name         = "Superman (1979) (Atari) [fixed]",
    },{
        .md5          = "5df32450b9fbcaf43f9d83bd66bd5a81",
        .manufacturer = "Eric Ball",
        .name         = "Atari Logo Playfield Demo (2001) (Eric Ball) (PD)",
    },{
        .md5          = "5df559a36347d8572f9a6e8075a31322",
        .manufacturer = "Digivision",
        .name         = "Enduro (Digivision)",
    },{
        .md5          = "5e0c37f534ab5ccc4661768e2ddf0162",
        .manufacturer = "Telegames - VSS, Ed Salvo",
        .model        = "5667 A106",
        .name         = "Glacier Patrol (1988) (Telegames)",
    },{
        .md5          = "5e1b4629426f4992cf3b2905a696e1a7",
        .manufacturer = "Activision - Bobco, Robert C. Polaro",
        .model        = "AK-049-04",
        .name         = "Rampage! (1989) (Activision)",
    },{
        .md5          = "5e1b7a6078af428ef056fe85a37a95ca",
        .manufacturer = "Activision, David Crane",
        .model        = "AX-014, AX-014-04",
        .name         = "Grand Prix (1982) (Activision) (8K)",
    },{
        .md5          = "5e1cd11a6d41fc15cf4792257400a31e",
        .manufacturer = "Philip R. Frey",
        .name         = "Return of Mario Bros (Philip R. Frey) (Hack)",
        .note         = "Hack of Mario Bros.",
    },{
        .md5          = "5e201d6bfc520424a28f129ee5e56835",
        .manufacturer = "Universal Gamex Corporation, Miguel Castillo, H.K. Poon",
        .model        = "GX-001",
        .name         = "X-Man (1983) (Universal) (PAL)",
    },{
        .md5          = "5e2495d43b981010304af55efed1e798",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Math Gran Prix (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "5e43c0391f7412ae64fae6f3742d6ee9",
        .manufacturer = "Thomas Jentzsch, Paul Slocum",
        .name         = "Thrust+ Platinum (v1.27)",
        .left         = "BOOSTERGRIP",
        .right        = "DRIVING",
    },{
        .md5          = "5e99aa93d0acc741dcda8752c4e813ce",
        .name         = "2600 Digital Clock (V b2) (PD)",
    },{
        .md5          = "5ec73ac7d2ac95ac9530c6d33e713d14",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum, Scott Nelson",
        .model        = "13",
        .name         = "Sweat! - The Decathlon Game (2 of 3) (1983) (Arcadia) (Prototype)",
        .note         = "Uses the Paddle Controllers (left only)",
    },{
        .md5          = "5eeb81292992e057b290a5cd196f155d",
        .manufacturer = "Wizard Video Games - VSS, Ed Salvo",
        .model        = "008",
        .name         = "Texas Chainsaw Massacre, The (1983) (Wizard Video)",
    },{
        .md5          = "5ef303b9f0aa8cf20720c560e5f9baa1",
        .manufacturer = "Atari, Jim Huether",
        .model        = "CX2629, CX2629P",
        .name         = "Sky Diver (1979) (Atari) (PAL) (4K)",
    },{
        .md5          = "5f1b7d5fa73aa071ba0a3c2819511505",
        .manufacturer = "CCE",
        .name         = "Cosmic Commuter (CCE)",
    },{
        .md5          = "5f2b4c155949f01c06507fb32369d42a",
        .manufacturer = "Apollo, Ed Salvo",
        .model        = "AP-1001",
        .name         = "Skeet Shoot (1981) (Apollo) (4K)",
    },{
        .md5          = "5f316973ffd107f7ab9117e93f50e4bd",
        .name         = "Commando Raid (Unknown) (PAL) [a]",
    },{
        .md5          = "5f39353f7c6925779b0169a87ff86f1e",
        .manufacturer = "Atari - GCC, John Allred, Douglas B. Macrae, Betty Ryan Tylko",
        .model        = "CX2694",
        .name         = "Pole Position (1983) (Atari) [a]",
        .note         = "AKA RealSports Driving",
    },{
        .md5          = "5f46d1ff6d7cdeb4b09c39d04dfd50a1",
        .manufacturer = "Atari, Gary Palmer",
        .model        = "CX2661P",
        .name         = "Fun with Numbers (1980) (Atari) (PAL)",
        .note         = "AKA Basic Math",
    },{
        .md5          = "5f4ebf8a1e5f5f7b9ff3e3c6affff3e6",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Donkey Kong (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "5f560837396387455c9dcb05cdd4b053",
        .manufacturer = "Canal 3 - Intellivision",
        .name         = "Eggomania (Canal 3)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "5f681403b1051a0822344f467b05a94d",
        .manufacturer = "Atari, Howard Scott Warshaw - Sears",
        .model        = "CX2655 - 49-75167",
        .name         = "Yars' Revenge (1982) (Atari) [a]",
        .phosphor     = 1,
    },{
        .md5          = "5f708ca39627697e859d1c53f8d8d7d2",
        .manufacturer = "Atari, Warren Robinett - Sears",
        .model        = "CX2606 - 6-99825, 49-75112",
        .name         = "Slot Racers (1978) (Atari) (4K)",
    },{
        .md5          = "5f73e7175474c1c22fb8030c3158e9b3",
        .manufacturer = "Atari, Nick 'Sandy Maiwald' Turner",
        .model        = "CX2665",
        .name         = "Frog Pond (1982) (Atari) (Prototype)",
    },{
        .md5          = "5f786b67e05fb9985b77d4beb35e06ee",
        .manufacturer = "Atari, Bill Aspromonte, Andrew Fuchs",
        .model        = "CX26120",
        .name         = "Defender II (1987) (Atari) (PAL)",
        .note         = "AKA Stargate",
    },{
        .md5          = "5f7ae9a7f8d79a3b37e8fc841f65643a",
        .manufacturer = "Atari, Dave Joly, Peter C. Niday, Robert Vieira",
        .model        = "CX26109",
        .name         = "Sorcerer's Apprentice (1983) (Atari)",
    },{
        .md5          = "5f7de62a408b9de3a1168898298fd31d",
        .name         = "Super Cobra (Genesis)",
        .note         = "Genesis controller (B is bomb, C is laser)",
    },{
        .md5          = "5f950a2d1eb331a1276819520705df94",
        .manufacturer = "20th Century Fox Video Games - Microcomputer Technologies, Jim Collas",
        .name         = "Heart Like a Wheel (1983) (20th Century Fox) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "5f9b62350b31be8bd270d9a241cbd50e",
        .manufacturer = "Telegames",
        .model        = "5658 A088",
        .name         = "Football (1988) (Telegames) (PAL)",
        .note         = "AKA Super Challenge Football",
    },{
        .md5          = "5faffe1c4c57430978dec5ced32b9f4a",
        .manufacturer = "Dactari - Milmar",
        .name         = "Volleyball (Dactari)",
        .note         = "AKA RealSports Volleyball",
    },{
        .md5          = "5fb71cc60e293fe10a5023f11c734e55",
        .name         = "This Planet Sucks (Fix) (27-12-2002) (Greg Troutman)",
    },{
        .md5          = "5fd4239051c76563eed086f512b4cd48",
        .name         = "Lilly Adventure (Unknown)",
    },{
        .md5          = "600d48eef5c0ec27db554b7328b3251c",
        .name         = "Bars and Text Demo 3 (PD)",
    },{
        .md5          = "6015a9cef783e97e98a2aa2cf070ae06",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Battlezone TC (Thomas Jentzsch) (Hack)",
        .note         = "Uses two simultaneous Joystick Controllers, Hack of Battlezone",
    },{
        .md5          = "60358edf0c2cc76b1e549e031e50e130",
        .manufacturer = "Manuel Polik",
        .name         = "Cyber Goth Galaxian (Manuel Polik) (Hack)",
        .note         = "Hack of Galaxian",
    },{
        .md5          = "603c7a0d12c935df5810f400f3971b67",
        .manufacturer = "Bit Corporation",
        .model        = "PG209",
        .name         = "Mr. Postman (1983) (BitCorp) (PAL)",
    },{
        .md5          = "6041f400b45511aa3a69fab4b8fc8f41",
        .manufacturer = "Apollo, Ban Tran",
        .model        = "AP-2010",
        .name         = "Wabbit (1982) (Apollo)",
    },{
        .md5          = "604e09724555807c28108049efe34a13",
        .name         = "Sokoban (01-01-2003) (Adam Wozniak)",
    },{
        .md5          = "6058e40ce79d7434c7f7477b29abd4a5",
        .name         = "Rubik's Cube Demo (23-12-2002) (Christopher Tumber)",
    },{
        .md5          = "605dcb73d22f4efdb90ef9da2f290f7c",
        .manufacturer = "Atari, Larry Kaplan",
        .model        = "CX26163P",
        .name         = "Air-Sea Battle (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "605fd59bfef88901c8c4794193a4cbad",
        .manufacturer = "Data Age",
        .name         = "Secret Agent (1983) (Data Age) (Prototype)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "606c2c1753051e03c1f1ac096c9d2832",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Crackpots (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "6076b187a5d8ea7a2a05111c19b5d5cd",
        .name         = "Fu Kung! (V0.14) (01-02-2003) (Andrew Davie)",
    },{
        .md5          = "60a61da9b2f43dd7e13a5093ec41a53d",
        .manufacturer = "VentureVision, Dan Oliver",
        .model        = "VV2001",
        .name         = "Rescue Terra I (1982) (VentureVision)",
    },{
        .md5          = "60bbd425cb7214ddb9f9a31948e91ecb",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AG-005, CAG-005, AG-005-04",
        .name         = "Skiing (1980) (Activision) (4K)",
    },{
        .md5          = "60cd61a2dfccb0e2736434f9792c1672",
        .manufacturer = "Amiga - Video Soft, Frank Ellis, Jerry Lawson",
        .model        = "2110",
        .name         = "3-D Havoc (1983) (Amiga) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "60d304582d33e2957b73eb300a7495bb",
        .name         = "Jam Demo 2 (PD)",
    },{
        .md5          = "60e0ea3cbe0913d39803477945e9e5ec",
        .manufacturer = "Atari, Joe Decuir - Sears",
        .model        = "CX2621 - 99806, 6-99806, 49-75104",
        .name         = "Video Olympics (1977) (Atari)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXDR",
        .right        = "PADDLES_IAXDR",
        .swapPaddles  = 1,
    },{
        .md5          = "613abf596c304ef6dbd8f3351920c37a",
        .name         = "Boring Pac-Man (Hack)",
        .note         = "Hack of Pac-Man",
    },{
        .md5          = "6141c095d0aee4e734bebfaac939030a",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-017",
        .name         = "Mariana (1983) (Rainbow Vision) (PAL)",
        .note         = "AKA Seaquest",
    },{
        .md5          = "61426cee013306e7f7367534ab124747",
        .name         = "One Blue Bar Demo (PD)",
    },{
        .md5          = "615a3bf251a38eb6638cdc7ffbde5480",
        .manufacturer = "Atari, Jerome Domurat, Howard Scott Warshaw",
        .model        = "CX2674",
        .name         = "E.T. - The Extra-Terrestrial (1982) (Atari)",
    },{
        .md5          = "61621a556ad3228f0234f5feb3ab135c",
        .name         = "Fu Kung! (V0.05 Cuttle Card Compattle Revision) (14-01-2003) (Andrew Davie)",
    },{
        .md5          = "61631c2f96221527e7da9802b4704f93",
        .manufacturer = "Activision - Imagineering, Mike Reidel",
        .model        = "AK-043-04",
        .name         = "Commando (1988) (Activision) [different logo]",
    },{
        .md5          = "61719a8bdafbd8dab3ca9ce7b171b9e2",
        .name         = "Enduro (Unknown) (PAL)",
    },{
        .md5          = "61728c6cfb052e62a9ed088c5bf407ba",
        .name         = "Sprite Demo 4 (PD)",
    },{
        .md5          = "619de46281eb2e0adbb98255732483b4",
        .name         = "Time Warp (Unknown)",
    },{
        .md5          = "61baadddc2c8f6e5faa57d4d0f285462",
        .name         = "208 in 1 MDM-Test (PAL) (127 games)",
        .type         = "MDM",
        .left         = "JOYSTICK",
        .right        = "JOYSTICK",
    },{
        .md5          = "61dbe94f110f30ca4ec524ae5ce2d026",
        .manufacturer = "CCE",
        .model        = "C-820",
        .name         = "Space Invaders (1983) (CCE)",
    },{
        .md5          = "61e0f5e1cc207e98704d0758c68df317",
        .manufacturer = "Star Game",
        .model        = "007",
        .name         = "Tennis (Star Game)",
    },{
        .md5          = "61ef8c2fc43be9a04fe13fdb79ff2bd9",
        .name         = "Gas Gauge Demo - Revisited (2001) (Joe Grand) (PD)",
    },{
        .md5          = "6205855cc848d1f6c4551391b9bfa279",
        .name         = "Euchre (Release Candidate 2) (NTSC) (01-10-2002) (Erik Eid)",
    },{
        .md5          = "6238ac888871fec301d1b9fc4fc613c9",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Marble Craze - Atari Mouse Hack v1.0 (PAL) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controllers",
    },{
        .md5          = "623c0a85245738af3954ff14591a8773",
        .name         = "Barnstorming (Unknown) (PAL) [a]",
    },{
        .md5          = "624e0a77f9ec67d628211aaf24d8aea6",
        .manufacturer = "Panda",
        .model        = "108",
        .name         = "Sea Hawk (1983) (Panda)",
        .note         = "AKA Seahawk",
    },{
        .md5          = "626d67918f4b5e3f961e4b2af2f41f1d",
        .manufacturer = "Atari",
        .model        = "50008",
        .name         = "Diagnostic Test Cartridge 2.0 (1980) (Atari) (Prototype)",
    },{
        .md5          = "6272f348a9a7f2d500a4006aa93e0d08",
        .manufacturer = "Atari, Jerome Domurat, Michael Sierchio",
        .model        = "CX2667, CX2667P",
        .name         = "RealSports Soccer (1983) (Atari) (PAL) [a]",
        .phosphor     = 1,
    },{
        .md5          = "62899430338e0538ee93397867d85957",
        .manufacturer = "Gameworld",
        .model        = "133-004",
        .name         = "Airlock (1983) (Gameworld) (PAL)",
    },{
        .md5          = "62921652f6634eb1a0940ed5489c7e18",
        .name         = "SCSIcide (V1.09) (2001) (Joe Grand)",
        .left         = "PADDLES_IAXDR",
    },{
        .md5          = "62992392ea651a16aa724a92e4596ed6",
        .manufacturer = "Eric Mooney",
        .name         = "Invaders by Erik Mooney (Beta) (PD)",
    },{
        .md5          = "62d1f50219edf9a429a9f004c19f31b3",
        .manufacturer = "JWDA, Todd Marshall",
        .name         = "Euro Gen (02-01-83) (JWDA) (PAL)",
    },{
        .md5          = "62ee2b8f59e9cd6285bbdb674a952e8b",
        .manufacturer = "Probe 2000 - NAP, Roger Booth, Todd Marshall, Robin McDaniel, Jim Wickstead",
        .model        = "3152VC",
        .name         = "Pursuit of the Pink Panther (Probe) (Prototype)",
        .note         = "AKA Adventures of the Pink Panther",
    },{
        .md5          = "62f74a2736841191135514422b20382d",
        .name         = "Pharaoh's Curse (Unknown)",
        .format       = "PAL60",
        .phosphor     = 1,
    },{
        .md5          = "62ffd175cac3f781ef6e4870136a2520",
        .name         = "2600 Digital Clock (V x.xx) (PD)",
    },{
        .md5          = "63166867f75869a3592b7a94ea62d147",
        .name         = "Indy 500 (Hack) [a1]",
        .note         = "Hack of Indy 500",
        .left         = "DRIVING",
        .right        = "DRIVING",
    },{
        .md5          = "6333ef5b5cbb77acd47f558c8b7a95d3",
        .manufacturer = "Greg Troutman",
        .name         = "Dark Mage (Greg Troutman) (PD) (8K)",
        .phosphor     = 1,
    },{
        .md5          = "6337927ad909aa739d6d0044699a916d",
        .manufacturer = "Jeffry Johnston",
        .name         = "Radial Pong - Version 2 (Jeffry Johnston) (PD)",
    },{
        .md5          = "6339d28c9a7f92054e70029eb0375837",
        .manufacturer = "Parker Brothers, Wilfredo Aguilar, Michael Becker, Neil McKenzie, Bob Smith, Brad Stewart",
        .model        = "PB5540",
        .name         = "Star Wars - The Arcade Game (1984) (Parker Bros)",
        .phosphor     = 1,
    },{
        .md5          = "6342afe9c9ad1b6120b8f6fb040d0926",
        .name         = "Move a Blue Blob Demo (PD)",
    },{
        .md5          = "6354f9c7588a27109c66905b0405825b",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Amidar DS (2003) (Thomas Jentzsch) (Hack)",
        .note         = "Hack of Amidar",
    },{
        .md5          = "6358f7f8bf0483402a080efccf250d61",
        .manufacturer = "CommaVid, John Bronstein",
        .model        = "CM-003",
        .name         = "Cosmic Swarm (1982) (CommaVid) (Prototype)",
        .note         = "AKA Termite",
        .phosphor     = 1,
    },{
        .md5          = "635cc7a0db33773959d739d04eff96c2",
        .name         = "Minesweeper (V.90) (Soren Gust) (PD)",
    },{
        .md5          = "6362396c8344eec3e86731a700b13abf",
        .manufacturer = "Panda",
        .model        = "109",
        .name         = "Exocet (1983) (Panda)",
    },{
        .md5          = "637efac676ff063f2fbb0abff77c4fa5",
        .name         = "Noize Maker Demo (PD)",
    },{
        .md5          = "63811ed69bdbc35c69d8aa7806c3d6e9",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Homerun (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "638cc82ea96f67674595ba9ae05da6c6",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-011",
        .name         = "Super Ferrari (1983) (Rainbow Vision) (PAL)",
        .note         = "AKA Enduro",
    },{
        .md5          = "63a6eda1da30446569ac76211d0f861c",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-001",
        .name         = "Dragster (1980) (Activision) (4K)",
    },{
        .md5          = "63a7445b1d3046d3cdcdbd488dca38d9",
        .manufacturer = "Rob Kudla",
        .name         = "Better Space Invaders (1999) (Rob Kudla) (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "63c5fef3208bb1424d26cf1ab984b40c",
        .name         = "Analog Clock (V0.1) (20-01-2003) (Andrew Davie)",
    },{
        .md5          = "63c7395d412a3cd095ccdd9b5711f387",
        .manufacturer = "Eric Ball",
        .model        = "ELB005",
        .name         = "Skeleton+ (PAL)",
        .note         = "Stereo sound",
    },{
        .md5          = "63d6247f35902ba32aa49e7660b0ecaa",
        .name         = "Space War (Unknown) (PAL)",
    },{
        .md5          = "63e42d576800086488679490a833e097",
        .manufacturer = "Telesys, Jim Rupp",
        .model        = "1004",
        .name         = "Ram It (1983) (Telesys) (PAL)",
    },{
        .md5          = "63e783994df824caf289b69a084cbf3e",
        .manufacturer = "David Marli",
        .name         = "Fat Albert (David Marli) (Hack)",
        .note         = "Hack of Fast Food",
    },{
        .md5          = "63e9e612bbee31045f8d184a4e53f8ec",
        .manufacturer = "ATARITALIA",
        .name         = "Moby Blues (2002) (ATARITALIA) (Hack)",
        .note         = "Hack of Mario Bros",
    },{
        .md5          = "640a08e9ca019172d612df22a9190afb",
        .manufacturer = "Atari - GCC, Mike Feinstein, Kevin Osborn",
        .model        = "CX2691, CX2691P",
        .name         = "Joust (1983) (Atari) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "64198bb6470c78ac24fcf13fe76ab28c",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4200",
        .name         = "Escape from the Mindmaster (1982) (Arcadia) [a]",
    },{
        .md5          = "643e6451eb6b8ab793eb60ba9c02e000",
        .manufacturer = "Salu - Avantgarde Software, Michael Buetepage",
        .model        = "460741",
        .name         = "Ghostbusters II (1992) (Salu) (PAL) [different tune]",
        .phosphor     = 1,
    },{
        .md5          = "645bf7f9146f0e4811ff9c7898f5cd93",
        .manufacturer = "Xonox - K-Tel Software - VSS, Robert Weatherby",
        .model        = "6230, 6250",
        .name         = "Super Kung-Fu (1983) (Xonox) (PAL)",
    },{
        .md5          = "6468d744be9984f2a39ca9285443a2b2",
        .manufacturer = "Atari, Ed Logg, Carol Shaw",
        .model        = "CX26163P",
        .name         = "Reversi (32 in 1) (1988) (Atari) (PAL)",
        .note         = "AKA Othello",
    },{
        .md5          = "647162cceb550fd49820e2206d9ee7e8",
        .name         = "Skeleton (NTSC) (2002) (Eric Ball)",
    },{
        .md5          = "64b8e19c767191ccdc97acc6904c397b",
        .manufacturer = "Jeffry Johnston",
        .name         = "Radial Pong - Version 6 (Jeffry Johnston) (PD)",
    },{
        .md5          = "64ca518905311d2d9aeb56273f6caa04",
        .manufacturer = "CCE",
        .name         = "Cubo Magico (CCE)",
        .note         = "AKA Cubicolor",
    },{
        .md5          = "64d43859258dc8ca54949e9ff4174202",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Lilly Adventure (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "64fab9d15df937915b1c392fc119b83b",
        .manufacturer = "Atari, Jerome Domurat, Howard Scott Warshaw",
        .model        = "CX26119",
        .name         = "Saboteur (05-20-1983) (Atari) (Prototype)",
    },{
        .md5          = "650df778c6ce22d3fd1a7c33c565bcc3",
        .manufacturer = "Atari - GCC, Betty Ryan Tylko, Douglas B. Macrae",
        .model        = "CX2694",
        .name         = "Pole Position (1983) (Atari)",
        .note         = "Genesis controller (B is high gear, C is low gear, left difficulty switch swaps gear buttons)",
        .left         = "GENESIS",
    },{
        .md5          = "651d2b6743a3a18b426bce2c881af212",
        .manufacturer = "CCE",
        .model        = "C-812",
        .name         = "Pac Man (1983) (CCE) [a]",
        .note         = "AKA Pac-Man",
    },{
        .md5          = "6522717cfd75d1dba252cbde76992090",
        .manufacturer = "Home Vision - Gem International Corp. - VDI",
        .model        = "VCS83102",
        .name         = "War 2000 (1983) (Home Vision) (PAL)",
        .note         = "AKA Astrowar",
    },{
        .md5          = "6538e454b0498ad2befe1ef0f87815c0",
        .manufacturer = "Joe Grand",
        .name         = "SCSIcide (v1.2) (2001) (Joe Grand)",
        .left         = "PADDLES_IAXDR",
    },{
        .md5          = "65490d61922f3e3883ee1d583ce10855",
        .manufacturer = "Atari - GCC, Mark Ackerman, Noelie Alito",
        .model        = "CX2692, CX2692P",
        .name         = "Moon Patrol (1983) (Atari) (PAL)",
    },{
        .md5          = "65562f686b267b21b81c4dddc129d724",
        .name         = "Euchre (28-07-2001) (Eric Eid) (PD)",
    },{
        .md5          = "655c84e5b951258c9d20f0bf2b9d496d",
        .name         = "2600_2003 Demo (PD)",
    },{
        .md5          = "656dc247db2871766dffd978c71da80c",
        .manufacturer = "Sears Tele-Games, Jim Huether",
        .model        = "CX2614 - 49-75126",
        .name         = "Steeplechase (1981) (Sears)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXIS",
    },{
        .md5          = "6588d192d9a8afce27b44271a2072325",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Basketball (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "65917ae29a8c9785bb1f2acb0d6aafd0",
        .name         = "Junkosoft One Year Demo (1999) (PD)",
    },{
        .md5          = "65949de96b741046269379289189b3de",
        .manufacturer = "Parker Brothers - Roklan, Joe Gaucher",
        .model        = "PB5080",
        .name         = "Gyruss (1983) (Parker Bros) (Prototype) [a2]",
        .phosphor     = 1,
    },{
        .md5          = "6596b3737ae4b976e4aadb68d836c5c7",
        .manufacturer = "Digivision",
        .name         = "Defender (Digivision)",
    },{
        .md5          = "659a20019de4a23c748ec2292ea5f221",
        .manufacturer = "Retroactive",
        .name         = "Qb (V2.05) (NTSC) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "65a6f1255fe22468a8bf84ff28a4d289",
        .manufacturer = "Akor",
        .name         = "Super TV Boy (1995) (Akor)",
        .note         = "Includes 127 games",
        .left         = "JOYSTICK",
        .right        = "JOYSTICK",
    },{
        .md5          = "65b106eba3e45f3dab72ea907f39f8b4",
        .manufacturer = "Christian Software Development - HomeComputer Software, Dan Schafer, Glenn Stohel, Jon Tedesco - Sparrow",
        .model        = "GCG 1001T",
        .name         = "Music Machine, The (1983) (Sparrow)",
        .note         = "Uses the Paddle Controllers (left only)",
    },{
        .md5          = "65ba1a4c643d1ab44481bdddeb403827",
        .manufacturer = "Quelle",
        .model        = "876.013 4",
        .name         = "Katastrophen-Einsatz (1983) (Quelle) (PAL)",
        .note         = "AKA M.A.S.H.",
    },{
        .md5          = "65bd29e8ab1b847309775b0de6b2e4fe",
        .manufacturer = "Coleco - Individeo, Ed English",
        .model        = "2667",
        .name         = "Roc 'n Rope (1984) (Coleco)",
    },{
        .md5          = "65c6406f5af934590097c8c032ebb482",
        .name         = "Three Hugger (Pave Demo) (20-12-2002) (Billy Eno)",
    },{
        .md5          = "6604f72a966ca6b2df6a94ee4a68eb82",
        .name         = "MegaMania (Unknown) (PAL)",
    },{
        .md5          = "662eca7e3d89175ba0802e8e3425dedb",
        .name         = "Hangman Pac-Man Biglist3 (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "66362890eb78d6ea65301592cce65f5b",
        .name         = "Euchre (13-07-2001) (Eric Eid) (PD)",
    },{
        .md5          = "663ef22eb399504d5204c543b8a86bcd",
        .manufacturer = "CBS Electronics - Roklan, Joe Hellesen, Joe Wagner",
        .model        = "4L1720, 4L1721, 4L1722, 4L2276",
        .name         = "Wizard of Wor (1982) (CBS Electronics) (PAL)",
        .note         = "Uses the Joystick Controllers (swapped)",
        .swapPorts    = 1,
        .phosphor     = 1,
    },{
        .md5          = "664d9bfda6f32511f6b4aa0159fd87f5",
        .manufacturer = "Atari - Roklan, Joe Gaucher",
        .name         = "Racer (1982) (Atari) (Prototype) [a]",
    },{
        .md5          = "6651e2791d38edc02c5a5fd7b47a1627",
        .manufacturer = "Parker Brothers, Wilfredo Aguilar, Michael Becker, Neil McKenzie, Bob Smith, Brad Stewart",
        .model        = "PB5540",
        .name         = "Star Wars - The Arcade Game (04-05-1984) (Parker Bros) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "665b8f8ead0eef220ed53886fbd61ec9",
        .manufacturer = "Telesys, Don Ruffcorn, Jack Woodman",
        .model        = "1003",
        .name         = "Fast Food (1982) (Telesys)",
    },{
        .md5          = "66706459e62514d0c39c3797cbf73ff1",
        .manufacturer = "Video Gems",
        .model        = "VG-05",
        .name         = "Treasure Below (1983) (Video Gems) (PAL)",
    },{
        .md5          = "6672de8f82c4f7b8f7f1ef8b6b4f614d",
        .manufacturer = "Videospielkassette - Ariola",
        .model        = "PGP237",
        .name         = "Angeln I (Ariola) (PAL)",
        .note         = "AKA Fishing Derby",
    },{
        .md5          = "667a70b028f581d87648693b873bc962",
        .manufacturer = "Parker Brothers - Roklan, Joe Gaucher",
        .model        = "PB5370",
        .name         = "Popeye (1983) (Parker Bros) (Prototype) (4K)",
    },{
        .md5          = "668dc528b7ea9345140f4fcfbecf7066",
        .manufacturer = "Gakken",
        .model        = "001",
        .name         = "Pooyan (1983) (Gakken) (PAL)",
    },{
        .md5          = "6697f177847c70505824422e76aad586",
        .name         = "Tennis (Unknown) (PAL) (4K)",
    },{
        .md5          = "669840b0411bfbab5c05b786947d55d4",
        .manufacturer = "Atari, Andrew Fuchs, Jeffrey Gusman, Dave Jolly, Suki Lee",
        .model        = "CX26117",
        .name         = "Obelix (1983) (Atari) (PAL) [a]",
    },{
        .md5          = "66b89ba44e7ae0b51f9ef000ebba1eb7",
        .manufacturer = "Atari - CCW, Stephan R. Keith, Laura Scholl, Preston Stuart",
        .model        = "CX26106",
        .name         = "Grover's Music Maker (01-18-1983) (Atari) (Prototype)",
        .note         = "Uses Keyboard Controller",
    },{
        .md5          = "66b92ede655b73b402ecd1f4d8cd9c50",
        .manufacturer = "Activision, John Van Ryzin - Ariola",
        .model        = "EAZ-036-04, EAZ-036-04B, EAZ-036-04I - 711 036-720",
        .name         = "H.E.R.O. (1984) (Activision) (PAL) [a2]",
    },{
        .md5          = "66bc1bef269ea59033928bac2d1d81e6",
        .manufacturer = "Arcadia Corporation, Scott Nelson",
        .model        = "AR-4300",
        .name         = "Fireball (Preview) (1982) (Arcadia)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "66c2380c71709efa7b166621e5bb4558",
        .manufacturer = "Parker Brothers, Dave Engman, Dawn Stockbridge",
        .model        = "931509",
        .name         = "Tutankham (1983) (Parker Bros) (PAL)",
    },{
        .md5          = "66c4e0298d4120df333bc2f3e163657e",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum",
        .model        = "AR-4400",
        .name         = "Dragonstomper (2 of 3) (1982) (Starpath) (PAL)",
    },{
        .md5          = "66f49b3248791b9803fa3e2f4165d072",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Football (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "66fcf7643d554f5e15d4d06bab59fe70",
        .manufacturer = "Coleco - Individeo, Ed Temple",
        .name         = "Cabbage Patch Kids (09-13-1984) (Coleco) (Prototype)",
        .note         = "Adventures in the Park",
    },{
        .md5          = "6706a00f9635508cfeda20639156e66e",
        .manufacturer = "Atari, Jerome Domurat, Michael Sierchio",
        .model        = "CX2667",
        .name         = "RealSports Soccer (1983) (Atari) (Prototype)",
    },{
        .md5          = "672012d40336b403edea4a98ce70c76d",
        .name         = "Inca Gold (Unknown) (PAL) [a]",
    },{
        .md5          = "673268cfaa8ff3f655b9e34d75e6a90c",
        .manufacturer = "Fotomania",
        .name         = "River Raid (Fotomania)",
    },{
        .md5          = "675ae9c23fa1aae376cea86cad96f9a5",
        .name         = "Poker Squares (V0.25) (2001) (B. Watson)",
    },{
        .md5          = "67631ea5cfe44066a1e76ddcb6bcb512",
        .name         = "Turmoil (Unknown) (PAL)",
    },{
        .md5          = "67684a1d18c85ffa5d82dab48fd1cb51",
        .manufacturer = "Tigervision, Warren Schwader - Teldec - Prism",
        .model        = "7-003",
        .name         = "Threshold (1982) (Tigervision) (PAL)",
    },{
        .md5          = "678c1d71a1616d9d022f03d8545b64bb",
        .name         = "Demo Image Series #11 - Donald And Mario (28-02-2003) (Andrew Davie)",
    },{
        .md5          = "67931b0d37dc99af250dd06f1c095e8d",
        .manufacturer = "CommaVid, Irwin Gaines",
        .model        = "CM-004",
        .name         = "Room of Doom (1982) (CommaVid)",
        .phosphor     = 1,
    },{
        .md5          = "679d30c7886b283cbe1db4e7dbe5f2a6",
        .manufacturer = "Colin Hughes",
        .name         = "Puzzle (Colin Hughes) (PD)",
    },{
        .md5          = "679e910b27406c6a2072f9569ae35fc8",
        .manufacturer = "Data Age",
        .model        = "DA1002",
        .name         = "Warplock (1982) (Data Age)",
        .note         = "Uses the Paddle Controllers",
        .phosphor     = 1,
    },{
        .md5          = "67bd3d4dc5ac6a42a99950b4245bdc81",
        .manufacturer = "Retroactive",
        .name         = "Qb (2.11) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "67c05ae94bf8b83a666c3ae2c4bc14de",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "NFL Football (32 in 1) (1988) (Atari) (PAL) (4K)",
        .note         = "AKA Football",
    },{
        .md5          = "67cdde4176e0447fc45a71e0a1cdd288",
        .manufacturer = "Telegames - VSS, Ed Salvo",
        .model        = "5665 A016",
        .name         = "Glacier Patrol (1988) (Telegames) (PAL)",
    },{
        .md5          = "67ce6cdf788d324935fd317d064ed842",
        .manufacturer = "Retroactive",
        .name         = "Qb (V2.09) (Stella) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "67cf913d1df0bf2d7ae668060d0b6694",
        .name         = "Hangman Monkey 4letter (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "67f90d74fd0b72fdc6d9b92436780ea9",
        .manufacturer = "Omegamatrix",
        .name         = "SpaceMaster X-7 (Atari Trak-Ball) (PAL60) (Omegamatrix)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "6803fa7c2c094b428b859a58dc1dd06a",
        .manufacturer = "Retroactive",
        .name         = "Qb (0.11) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "6805734a0b7bcc8925d9305b071bf147",
        .manufacturer = "Bit Corporation",
        .model        = "PGP229",
        .name         = "Kung Fu (4 Game in One Dark Green) (1983) (BitCorp) (PAL)",
        .note         = "AKA Karate",
    },{
        .md5          = "681206a6bde73e71c19743607e96c4bb",
        .name         = "Casino (Unknown) (PAL)",
    },{
        .md5          = "6833c26f385e866f3a0fa0dff311216e",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Atari Mouse Hack v1.4 (PAL60) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "683bb0d0f0c5df58557fba9dffc32c40",
        .manufacturer = "Arcadia Corporation, Scott Nelson",
        .model        = "AR-4300",
        .name         = "Fireball (1982) (Arcadia) [a]",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "683dc64ef7316c13ba04ee4398e2b93a",
        .manufacturer = "Ed Federmeyer",
        .name         = "Edtris (1995) (Ed Federmeyer)",
    },{
        .md5          = "68449e4aaba677abcd7cde4264e02168",
        .name         = "Horizonal Color Bars Demo 2 (PD)",
    },{
        .md5          = "6847ce70819b74febcfd03e99610243b",
        .name         = "Ruby Runner 4A50",
        .phosphor     = 1,
    },{
        .md5          = "68489e60268a5e6e052bad9c62681635",
        .manufacturer = "Bit Corporation",
        .model        = "PG201",
        .name         = "Sea Monster (1982) (BitCorp) (PAL)",
    },{
        .md5          = "68597264c8e57ada93be3a5be4565096",
        .manufacturer = "Data Age",
        .model        = "DA1005",
        .name         = "Bugs (1982) (Data Age)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "685e9668dc270b6deeb9cfbfd4d633c3",
        .manufacturer = "CommaVid, Irwin Gaines - Ariola",
        .model        = "CM-004 - 712 004-720",
        .name         = "Room of Doom (1982) (CommaVid) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "68760b82fc5dcf3fedf84376a4944bf9",
        .manufacturer = "CCE",
        .model        = "C-860",
        .name         = "Laser Gate (1983) (CCE)",
        .note         = "AKA Innerspace",
    },{
        .md5          = "687c23224e26f81c56e431c24faea36d",
        .name         = "Qb (Simple Background Animation) (2001) (Andrew Davie)",
        .phosphor     = 1,
    },{
        .md5          = "68878250e106eb6c7754bc2519d780a0",
        .manufacturer = "CCE",
        .model        = "C-809",
        .name         = "Squirrel (1983) (CCE)",
        .note         = "AKA Snail Against Squirrel",
    },{
        .md5          = "689f49e31cac68db8a2cf8f44fa7a01a",
        .manufacturer = "Oscar Toledo G., Thomas Jentzsch, Nathan Strum",
        .name         = "Aardvark (2019) (PAL60)",
        .phosphor     = 1,
    },{
        .md5          = "68ac69b8e1ba83af8792f693f5ae7783",
        .manufacturer = "Digivision",
        .name         = "Fathon (Digivision)",
        .note         = "AKA Fathom",
    },{
        .md5          = "68c80e7e1d30df98a0cf67ecbf39cc67",
        .manufacturer = "Hozer Video Games",
        .name         = "Gunfight 2600 - One Step Forward & Two Steps Back (2001) (Manuel Rotschkar)",
    },{
        .md5          = "68c938a2a2b45c37db50509f1037fe6e",
        .manufacturer = "Omegamatrix",
        .name         = "Star Wars Arcade (Atari Mouse) v4 (Omegamatrix)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "68cd2adc6b1fc9a1f263ab4561112f30",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Boulderdash Demo (09-12-2002) (Thomas Jentzsch)",
        .phosphor     = 1,
    },{
        .md5          = "68feb6d6ff63e80df1302d8547979aec",
        .name         = "Starfield Demo 2 (20-12-2002) (Christopher Tumber)",
    },{
        .md5          = "690a6049db78b9400c13521646708e9c",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-002",
        .name         = "Galactic (1983) (Rainbow Vision) (PAL) [a]",
        .note         = "AKA The Challenge of.... Nexar",
    },{
        .md5          = "6913c90002636c1487538d4004f7cac2",
        .manufacturer = "Atari - CCW",
        .model        = "CX26131",
        .name         = "Monster Cise (1984) (Atari) (Prototype)",
        .note         = "Uses the Keyboard Controllers (left only)",
    },{
        .md5          = "691d67910b08b63de8631901d1887c1f",
        .manufacturer = "Arcadia Corporation, Steve Mundry, Scott Nelson",
        .model        = "AR-4401",
        .name         = "Survival Island (1983) (Arcadia) [a]",
    },{
        .md5          = "692202772d8b38ccf85a90c8003a1324",
        .name         = "Zi - The Flie Buster (2002) (Fernando Mora) (PD)",
    },{
        .md5          = "693137592a7f5ccc9baae2d1041b7a85",
        .name         = "Qb (V2.02) (Stella) (2001) (Retroactive) [a1]",
        .phosphor     = 1,
    },{
        .md5          = "6936aa6763835f62ac13d1aaa79b9f91",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Atari Trak-Ball Hack v1.4 (NTSC) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "6979f30204149be3e227558cffe21c1d",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Miniaturer Golf (32 in 1) (1988) (Atari) (PAL) (4K)",
        .note         = "AKA Miniature Golf",
    },{
        .md5          = "6982854657a2cc87d712f718e402bf85",
        .manufacturer = "Zellers",
        .name         = "Earth Attack (Zellers)",
        .note         = "AKA Defender",
    },{
        .md5          = "69877da5caded48315e3e45882a303d5",
        .manufacturer = "Atari - Roklan, Joe Gaucher, Alex Leavens",
        .model        = "CX2683",
        .name         = "Crazy Climber (1983) (Atari) (Prototype)",
    },{
        .md5          = "698f569eab5a9906eec3bc7c6b3e0980",
        .manufacturer = "SpkLeader",
        .name         = "Demons! (2003) (SpkLeader) (Hack)",
        .note         = "Hack of Phoenix",
    },{
        .md5          = "69974dd5d6420b90898cde50aec5ef39",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-009, AG-009-04",
        .name         = "Freeway (1981) (Activision) (16K)",
    },{
        .md5          = "69df0411d4d176e558017f961f5c5849",
        .manufacturer = "CCE",
        .model        = "C-831",
        .name         = "Cosmic Ark (1983) (CCE) [a]",
    },{
        .md5          = "69e79b1352b9ee1754bbe63b4a7062c3",
        .manufacturer = "Barry Laws Jr.",
        .name         = "Pink Floyd - The Wall (2003) (Barry Laws Jr.) (Hack)",
        .note         = "Hack of Berzerk",
    },{
        .md5          = "69ebf910ab9b63e5b8345f016095003b",
        .name         = "Maze Demo 1 (PD)",
    },{
        .md5          = "69edfb4e1810a523311b3e250fc1e275",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Command Atari Trak-Ball Hack v1.3 (PAL) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
        .phosphor     = 1,
    },{
        .md5          = "69fac82cd2312dd9ce5d90e22e2f070a",
        .manufacturer = "Spectravision - Spectravideo - Quelle",
        .model        = "SA-202 - 412.851 8",
        .name         = "Planet Patrol (1982) (Spectravision) (PAL)",
    },{
        .md5          = "6a03c28d505bab710bf20b954e14d521",
        .name         = "Pressure Gauge 2 Beta (Hozer Video Games)",
    },{
        .md5          = "6a07836c382195dd5305ce61d992aaa6",
        .manufacturer = "Apollo, Larry Martin",
        .model        = "AP-2008",
        .name         = "Guardian (1982) (Apollo) (Prototype)",
        .note         = "Uses the Paddle Controller (left only)",
    },{
        .md5          = "6a091b8ffeacd0939850da2094b51564",
        .name         = "Vertically Scrolling Playfield (02-02-2003) (Aaron Bergstrom)",
    },{
        .md5          = "6a222c26bcece3a510ddda21398f72c6",
        .manufacturer = "Bit Corporation",
        .model        = "PG203",
        .name         = "Phantom Tank (1982) (BitCorp)",
    },{
        .md5          = "6a2c68f7a77736ba02c0f21a6ba0985b",
        .manufacturer = "Atari, Larry Wagner, Bob Whitehead",
        .name         = "Computer Chess (07-07-1978) (Atari) (Prototype)",
    },{
        .md5          = "6a3b0c33cf74b1e213a629e3c142b73c",
        .manufacturer = "Cody Pittman",
        .name         = "Cory The Interviewer (Cody Pittman) (Hack)",
        .note         = "Hack of Ghostbusters",
    },{
        .md5          = "6a76d5f0ed721639474aa9bbde69ebf0",
        .name         = "Play Demo (PD)",
        .phosphor     = 1,
    },{
        .md5          = "6a82b8ecc663f371b19076d99f46c598",
        .manufacturer = "Activision, Larry Miller - Ariola",
        .model        = "EAX-026, EAX-026-04B, EAX-026-04I - 711 026-725",
        .name         = "Enduro (1983) (Activision) (PAL)",
    },{
        .md5          = "6a882fb1413912d2ce5cf5fa62cf3875",
        .manufacturer = "Video Game Cartridge - Ariola",
        .model        = "TP-605",
        .name         = "Dragon Defender (Ariola) (PAL)",
        .note         = "AKA Dragon Power",
        .phosphor     = 1,
    },{
        .md5          = "6a8c6940d3be6fd01274363c4d4b298e",
        .name         = "Spy Hunter (Genesis)",
        .note         = "Genesis controller (C is oil/smoke)",
    },{
        .md5          = "6a9b30ca46b0dba9e719f4cbd340e01c",
        .manufacturer = "Bit Corporation",
        .model        = "CP405",
        .name         = "Eskimo Jump (4 Game in One) (1983) (BitCorp) (PAL)",
        .note         = "AKA Frostbite",
    },{
        .md5          = "6a9e0c72fab92df70084eccd9061fdbd",
        .manufacturer = "CCE",
        .model        = "C-835",
        .name         = "Beany Bopper (1983) (CCE)",
    },{
        .md5          = "6aa66e9c3eea76a0c40ef05513497c40",
        .name         = "Hangman Ghost Biglist2 (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "6ac3fd31a51730358708c7fdc62487f8",
        .manufacturer = "Matthias Jaap",
        .name         = "PC Invaders (Matthias Jaap) (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "6aca52e11b597ab84b33d5252e1cd9d1",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Tac-Scan (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "6ae4dc6d7351dacd1012749ca82f9a56",
        .manufacturer = "Atari - GCC, Jaques Hugon, Seth Lipkin",
        .model        = "CX26125, CX26127",
        .name         = "Track and Field (1984) (Atari)",
        .note         = "Uses the Track & Field Controller",
    },{
        .md5          = "6b01a519b413f8cfa2f399f4d2841b42",
        .name         = "Aphex Invaders (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "6b1fc959e28bd71aed7b89014574bdc2",
        .manufacturer = "Bit Corporation",
        .model        = "PG203",
        .name         = "Phantom Tank (1982) (BitCorp) (PAL)",
    },{
        .md5          = "6b4eb5b3df80995b8d9117cb7e9aeb3c",
        .manufacturer = "Gameworld, J. Ray Dettling",
        .model        = "133-006",
        .name         = "Journey Escape (1983) (Gameworld) (PAL)",
        .note         = "AKA Rock 'n' Roll Escape",
        .phosphor     = 1,
    },{
        .md5          = "6b683be69f92958abe0e2a9945157ad5",
        .manufacturer = "U.S. Games Corporation - Western Technologies, Jeff Corsiglia, Paul Allen Newell, Steven B. Sidley, Tom Sloper",
        .model        = "VC2007",
        .name         = "Entombed (1983) (U.S. Games)",
        .note         = "Released as Name That Game for a contest (winning name was Entombed)",
        .phosphor     = 1,
    },{
        .md5          = "6b6ca32228ae352b4267e4bd2cddf10c",
        .name         = "Pac-Man 4 (Pac-Man Hack)",
    },{
        .md5          = "6b71f20c857574b732e7a8e840bd3cb2",
        .name         = "Frostbite (Unknown) (PAL)",
    },{
        .md5          = "6b72b691ea86f61438ed0d84c4d711de",
        .name         = "Fishing Derby (Unknown) (PAL) (4K) (Hack)",
    },{
        .md5          = "6b75f8fa4fd011a6698c58315f83d2ac",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Sprintmaster DC (Thomas Jentzsch)",
        .note         = "Uses the Driving Controllers, Hack of Sprintmaster (Atari)",
        .left         = "DRIVING",
        .right        = "DRIVING",
    },{
        .md5          = "6b7a56b6ac2ca4bf9254474bf6ed7d80",
        .name         = "Horizonal Color Bars Demo (PD)",
    },{
        .md5          = "6b7e1c11448c4d3f28160d2de884ebc8",
        .manufacturer = "Zirok",
        .name         = "Fast Food (Zirok)",
    },{
        .md5          = "6b8fb021bb2e1f1e9bd7ee57f2a8e709",
        .manufacturer = "Paul Slocum",
        .name         = "3-D Corridor (29-03-2003) (Paul Slocum) (PD) [a]",
    },{
        .md5          = "6bb09bc915a7411fe160d0b2e4d66047",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "UFO (32 in 1) (1988) (Atari) (PAL)",
        .note         = "AKA Space Jockey",
    },{
        .md5          = "6bb22efa892b89b69b9bf5ea547e62b8",
        .manufacturer = "Dynacom",
        .name         = "Megamania (1982) (Dynacom)",
    },{
        .md5          = "6bde3f6ac31aceef447ce57d4d2c2ec0",
        .manufacturer = "Piero Cavina",
        .name         = "Mondo Pong V1 (Piero Cavina) (PD)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXDR",
    },{
        .md5          = "6c128bc950fcbdbcaf0d99935da70156",
        .manufacturer = "Digitel",
        .name         = "Volleyball (1983) (Digitel)",
        .note         = "AKA RealSports Volleyball",
    },{
        .md5          = "6c1553ca90b413bf762dfc65f2b881c7",
        .manufacturer = "Quelle",
        .model        = "343.073 3",
        .name         = "Winterjagd (1983) (Quelle) (PAL)",
        .note         = "AKA Ski Hunt",
    },{
        .md5          = "6c1f3f2e359dbf55df462ccbcdd2f6bf",
        .manufacturer = "Activision, Garry Kitchen - Ariola",
        .model        = "EAX-025, EAX-025-04I - 711 025-725",
        .name         = "Keystone Kapers (1983) (Activision) (PAL)",
    },{
        .md5          = "6c25f58fd184632ca76020f589bb3767",
        .manufacturer = "Dynacom",
        .name         = "Beat 'Em & Eat 'Em (1983) (Dynacom)",
        .note         = "Uses the Paddle Controller (left only)",
    },{
        .md5          = "6c449db9bbbd90972ad1932d6af87330",
        .name         = "20 Sprites at Once Demo 3 (PD)",
    },{
        .md5          = "6c658b52d03e01828b9d2d4718a998ac",
        .name         = "Hangman Invader Biglist2 (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "6c76fe09aa8b39ee52035e0da6d0808b",
        .manufacturer = "Atari, Brad Stewart",
        .model        = "CX2622, CX2622P",
        .name         = "Breakout (1978) (Atari) (PAL)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "6c85098518d3f94f7622c42fd1d819ac",
        .manufacturer = "Suntek",
        .model        = "SS-028",
        .name         = "Firebug (1983) (Suntek) (PAL)",
        .note         = "AKA Spinning Fireball",
    },{
        .md5          = "6c91ac51421cb9fc72c9833c4f440d65",
        .manufacturer = "ITT Family Games",
        .model        = "554-33 375",
        .name         = "Cosmic Town (1983) (ITT Family Games) (PAL)",
        .note         = "AKA Base Attack (Perry Rhodan-Serie)",
    },{
        .md5          = "6c9a32ad83bcfde3774536e52be1cce7",
        .name         = "Space Treat (NTSC) (13-08-2002) (Fabrizio Zavagli)",
    },{
        .md5          = "6cab04277e7cd552a3e40b3c0e6e1e3d",
        .manufacturer = "Telegames - VSS",
        .model        = "7062 A305",
        .name         = "Universal Chaos (1988) (Telegames) (Prototype)",
        .note         = "AKA Targ",
    },{
        .md5          = "6cbe945e16d9f827d0d295546ac11b22",
        .name         = "Gunfight 2600 - AI (Manuel Rotschkar)",
    },{
        .md5          = "6ccd8ca17a0e4429b446cdcb66327bf1",
        .name         = "RPG Engine (12-05-2003) (Paul Slocum) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "6cd1dc960e3e8d5c5e0fbe67ab49087a",
        .name         = "Vertical Playfield Demo 1 (PD)",
    },{
        .md5          = "6cd506509e8fd5627f55603780e862a8",
        .manufacturer = "Greg Troutman",
        .name         = "Dark Mage (SuperCharger) (Greg Troutman) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "6ce2110ac5dd89ab398d9452891752ab",
        .name         = "River Raid (Unknown) [a]",
    },{
        .md5          = "6cea35ded079863a846159c3a1101cc7",
        .name         = "Atlantis (208 in 1) (Unknown) (PAL) (Hack)",
    },{
        .md5          = "6ceb7d6a54e9a5e62d26874d1cc88dbc",
        .manufacturer = "Video Soft",
        .name         = "Atom Smasher (1984) (Video Soft) (Prototype)",
    },{
        .md5          = "6cf054cd23a02e09298d2c6f787eb21d",
        .manufacturer = "Parker Brothers, Wilfredo Aguilar, Michael Becker, Neil McKenzie, Bob Smith, Brad Stewart",
        .model        = "PB5540",
        .name         = "Star Wars - The Arcade Game (1984) (Parker Bros) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "6d218dafbf5a691045cdc1f67ceb6a8f",
        .manufacturer = "Robin Harbron",
        .name         = "6 Digit Score Display (1998) (Robin Harbron) (PD)",
    },{
        .md5          = "6d475019ea30d0b29f695e9dcfd8f730",
        .manufacturer = "Eric Mooney",
        .name         = "Invaders by Erik Mooney (Alpha 2) (PD)",
    },{
        .md5          = "6d74ebaba914a5cfc868de9dd1a5c434",
        .name         = "Fortress (Smooth Version) (20-04-2003) (Christopher Tumber)",
    },{
        .md5          = "6d842c96d5a01967be9680080dd5be54",
        .manufacturer = "Activision, Steve Cartwright, David Crane",
        .model        = "AB-035-04",
        .name         = "Pitfall II (1984) (Activision)",
    },{
        .md5          = "6d8a04ee15951480cb7c466e5951eee0",
        .manufacturer = "Zirok",
        .name         = "Kanguru (1983) (Zirok)",
        .note         = "AKA Kangaroo",
    },{
        .md5          = "6d9afd70e9369c2a6bff96c4964413b7",
        .name         = "Time Warp (Unknown) (PAL)",
    },{
        .md5          = "6dda84fb8e442ecf34241ac0d1d91d69",
        .manufacturer = "Atari - GCC, Ava-Robin Cohen, Douglas B. Macrae",
        .model        = "CX2677",
        .name         = "Dig Dug (1983) (Atari)",
    },{
        .md5          = "6de924c2297c8733524952448d54a33c",
        .manufacturer = "CCE",
        .model        = "C-1006",
        .name         = "Moon Patrol (1983) (CCE)",
    },{
        .md5          = "6dfad2dd2c7c16ac0fa257b6ce0be2f0",
        .manufacturer = "Parker Brothers, Larry Gelberg",
        .model        = "PB5065",
        .name         = "Star Wars - Ewok Adventure (1983) (Parker Bros) (Prototype) (PAL)",
    },{
        .md5          = "6e179eee3d4631a7434d40cf7aeea6e8",
        .manufacturer = "Wizard Video Games - VSS - MicroGraphic Image, Robert Barber, Tim Martin",
        .model        = "007",
        .name         = "Halloween (1983) (Wizard Video Games) (Prototype)",
    },{
        .md5          = "6e19428387686a77d8c8d2f731cb09e0",
        .name         = "Purple Cross Demo (PD)",
    },{
        .md5          = "6e372f076fb9586aff416144f5cfe1cb",
        .manufacturer = "Atari, Tod Frye - Sears",
        .model        = "CX2646 - 49-75185",
        .name         = "Pac-Man (1982) (Atari)",
    },{
        .md5          = "6e59dd52f88c00d5060eac56c1a0b0d3",
        .manufacturer = "Atari, Bob Smith",
        .model        = "CX2648",
        .name         = "Video Pinball (1981) (Atari) (PAL)",
    },{
        .md5          = "6e5d5ba193d2540aec2e847aafb2a5fb",
        .manufacturer = "Retroactive",
        .name         = "Qb (2.14) (Retroactive) (NTSC)",
        .phosphor     = 1,
    },{
        .md5          = "6e7ed74082f39ad4166c823765a59909",
        .name         = "Poker Squares (V0.14) (2001) (B. Watson)",
    },{
        .md5          = "6e7efb0ed13ec28a00d19572de9c9f03",
        .manufacturer = "Apollo - Games by Apollo",
        .model        = "AP-2006",
        .name         = "Infiltrate (1982) (Apollo) (Prototype)",
    },{
        .md5          = "6eb10fd23c7161751d18b9e8484c0004",
        .manufacturer = "Coleco - JWDA, Todd Marshall, Robin McDaniel, Henry Will IV",
        .model        = "2465",
        .name         = "Smurf - Rescue in Gargamel's Castle (1983) (Coleco) (Prototype)",
        .note         = "AKA Smurf, Smurf Action",
    },{
        .md5          = "6ed5012793f5ddf4353a48c11ea9b8d3",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4302",
        .name         = "Party Mix - Down on the Line (3 of 3) (1983) (Arcadia)",
        .note         = "Uses Paddle Controllers",
        .left         = "PADDLES_IAXIS",
    },{
        .md5          = "6ed6bda5c42b2eb7a21c54e5b3ace3e3",
        .manufacturer = "Canal 3 - Intellivision",
        .name         = "Ice Hockey (Canal 3)",
    },{
        .md5          = "6efe876168e2d45d4719b6a61355e5fe",
        .manufacturer = "Bit Corporation",
        .model        = "PG207",
        .name         = "Mission 3,000 A.D. (1983) (BitCorp) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "6f05cbc85eb3d439036f8155090accc0",
        .name         = "Mission 3,000 A.D. (Unknown) (PAL) [a]",
    },{
        .md5          = "6f084daf265599f65422ef4173b69bc7",
        .name         = "Music Kit (V2.0) - Song Player (Paul Slocum)",
        .phosphor     = 1,
    },{
        .md5          = "6f2aaffaaf53d23a28bf6677b86ac0e3",
        .manufacturer = "U.S. Games Corporation - Vidtec - JWDA, Garry Kitchen",
        .model        = "VC1001",
        .name         = "Space Jockey (1982) (U.S. Games)",
    },{
        .md5          = "6f3e3306da2aa6e74a5e046ff43bf028",
        .name         = "Defender Arcade (Genesis)",
        .note         = "Genesis controller (C is smartbomb)",
    },{
        .md5          = "6f744f14aac04f7e1ea0d3f4bafcb3e4",
        .manufacturer = "Atari - Roklan, Joe Gaucher, Alex Leavens",
        .model        = "CX2683",
        .name         = "Crazy Climber (1983) (Atari) (Prototype) [a3]",
    },{
        .md5          = "6f74ed915ffe73b524ef0f63819e2a1d",
        .manufacturer = "Eckhard Stolberg",
        .name         = "An Exercise In Minimalism (V2) (1999) (Eckhard Stolberg)",
    },{
        .md5          = "6fa0ac6943e33637d8e77df14962fbfc",
        .manufacturer = "Imagic, Rob Fulop",
        .name         = "Cubicolor (1982) (Imagic) (Prototype)",
    },{
        .md5          = "6fac680fc9a72e0e54255567c72afe34",
        .name         = "Superman (Unknown) (PAL)",
    },{
        .md5          = "6fbd05b0ad65b2a261fa154b34328a7f",
        .name         = "Boardgame Demo (20-12-2002) (Christopher Tumber)",
    },{
        .md5          = "6fc0176ccf53d7bce249aeb56d59d414",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-004",
        .name         = "Pyramid War (1983) (Rainbow Vision) (PAL)",
        .note         = "AKA Chopper Command",
    },{
        .md5          = "6fc27a9233fc69d28d3f190b4ff80f03",
        .name         = "UFO #6 (Charles Morgan) (Hack)",
        .note         = "Hack of Pepsi Invaders",
    },{
        .md5          = "6fc394dbf21cf541a60e3b3631b817f1",
        .manufacturer = "Imagic, Bob Smith",
        .model        = "720020-2A, IA3611P",
        .name         = "Dragonfire (1982) (Imagic) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "6fd7c7057eeab273b29c7aafc7429a96",
        .manufacturer = "Activision, David Crane",
        .model        = "AX-018, AX-018-04",
        .name         = "Pitfall! (1982) (Activision) (16K)",
    },{
        .md5          = "6fe67f525c39200a798985e419431805",
        .manufacturer = "Atari - GCC, Kevin Osborn",
        .model        = "CX2689, CX2689P",
        .name         = "Kangaroo (1983) (Atari) (PAL)",
    },{
        .md5          = "6ff4156d10b357f61f09820d03c0f852",
        .manufacturer = "Atari, Larry Kaplan - Sears",
        .model        = "CX2612 - 99804, 49-75103",
        .name         = "Street Racer (1977) (Atari) (4K)",
        .note         = "Uses the Paddle Controllers (swapped)",
        .swapPaddles  = 1,
    },{
        .md5          = "6ffc95108e5add6f9b8abcaf330be835",
        .manufacturer = "Charles Morgan",
        .name         = "TP Bug (Charles Morgan) (Hack)",
        .note         = "Hack of Pac-Man",
    },{
        .md5          = "700a786471c8a91ec09e2f8e47f14a04",
        .manufacturer = "Activision",
        .name         = "Hard-Head (1983) (Activision) (Prototype)",
    },{
        .md5          = "703d32062436e4c20c48313dff30e257",
        .name         = "Moving Maze Demo (PD)",
        .phosphor     = 1,
    },{
        .md5          = "703f0f7af350b0fa29dfe5fbf45d0d75",
        .manufacturer = "Bit Corporation",
        .model        = "P460",
        .name         = "4 Game in One Dark Green (1983) (BitCorp) (PAL)",
        .note         = "Rodeo Champ, Bobby is Going Home, Open Sesame, Festival",
        .type         = "4IN1",
    },{
        .md5          = "705fe719179e65b0af328644f3a04900",
        .manufacturer = "Atari, David Crane - Sears",
        .model        = "CX2653 - 6-99823, 49-75111",
        .name         = "Slot Machine (1979) (Atari) (4K) [a]",
    },{
        .md5          = "706e3cc4931f984447213b92d1417aff",
        .name         = "Joustpong (06-07-2002) (Kirk Israel) (PD)",
    },{
        .md5          = "707ecd80030e85751ef311ced66220bc",
        .name         = "Double-Height 6-Digit Score Display (Background Color Change) (2001) (Andrew Davie)",
    },{
        .md5          = "7096a198531d3f16a99d518ac0d7519a",
        .manufacturer = "Telesys, Jim Rupp",
        .model        = "1004",
        .name         = "Ram It (1983) (Telesys)",
    },{
        .md5          = "709910c2e83361bc4bf8cd0c20c34fbf",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-006",
        .name         = "Netmaker (1983) (Rainbow Vision) (PAL)",
        .note         = "AKA Amidar",
    },{
        .md5          = "70a43fbdb1c039283ee5048d99842469",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Atari Mouse Hack v1.3 (PAL) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "70a8480cfaf08776e5420365732159d2",
        .manufacturer = "Rob Kudla",
        .name         = "Horizontally Scrolling Playfield Thing (Rob Kudla) (PD)",
    },{
        .md5          = "70ce036e59be92821c4c7fd735ec6f68",
        .manufacturer = "Activision, Steve Cartwright - Ariola",
        .model        = "EAX-031, EAX-031-04B - 711 031-717",
        .name         = "Frostbite (1983) (Activision) (PAL) (16K)",
    },{
        .md5          = "70d14c66c319683b4c19abbe0e3db57c",
        .name         = "Oystron (V2.82) (Piero Cavina) (PD)",
    },{
        .md5          = "710497df2caab69cdcc45e919c69e13f",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "5 AR-4200",
        .name         = "Labyrinth (Escape from the Mindmaster Beta) (1982) (Arcadia) [a]",
    },{
        .md5          = "713fde2af865b6ec464dfd72e2ebb83e",
        .name         = "Challenge (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "71464c54da46adae9447926fdbfc1abe",
        .manufacturer = "M Network - INTV - APh Technological Consulting, Bruce Pedersen",
        .model        = "MT5663",
        .name         = "Lock 'n' Chase (1982) (M Network)",
    },{
        .md5          = "714e13c08508ee9a7785ceac908ae831",
        .manufacturer = "Home Vision - Gem International Corp. - VDI",
        .model        = "VCS83123",
        .name         = "Parachute (1983) (Home Vision) (PAL)",
    },{
        .md5          = "715dbf2e39ba8a52c5fe5cdd927b37e0",
        .manufacturer = "Amiga - Video Soft",
        .model        = "3135",
        .name         = "S.A.C. Alert (1983) (Amiga) (Prototype)",
        .note         = "Uses Joyboard",
    },{
        .md5          = "715dd9e0240638d441a3add49316c018",
        .manufacturer = "Atari",
        .name         = "128 in 1 Junior Console (Chip 2 of 4) (1991) (Atari) (PAL)",
        .note         = "Actually contains only 16 games, not 32",
        .type         = "16IN1",
    },{
        .md5          = "7187118674ff3c0bb932e049d9dbb379",
        .manufacturer = "Zirok",
        .name         = "Keystone Keypers (1983) (Zirok)",
        .note         = "AKA Keystone Kapers",
    },{
        .md5          = "718ae62c70af4e5fd8e932fee216948a",
        .manufacturer = "Data Age, J. Ray Dettling",
        .model        = "112-006",
        .name         = "Journey Escape (1983) (Data Age)",
        .phosphor     = 1,
    },{
        .md5          = "718ee85ea7ec27d5bea60d11f6d40030",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Ghostbusters II (1992) (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
        .phosphor     = 1,
    },{
        .md5          = "7197b6cbde6ecd10376155e6b848e80d",
        .manufacturer = "Piero Cavina",
        .name         = "Multi-Sprite Game V2.1 (Piero Cavina) (PD)",
    },{
        .md5          = "71b193f46c88fb234329855452dfac5b",
        .manufacturer = "Digitel",
        .name         = "Atlantis (1983) (Digitel)",
    },{
        .md5          = "71ba6aefca09424899441db9ae14ee04",
        .name         = "Oink! (Unknown)",
    },{
        .md5          = "71d005b60cf6e608d04efb99a37362c3",
        .manufacturer = "Atari, Larry Kaplan",
        .model        = "CX2643",
        .name         = "Codebreaker (1978) (Atari) (PAL) (4K) [a]",
        .note         = "Uses Keyboard Controllers",
    },{
        .md5          = "71f09f128e76eb14e244be8f44848759",
        .manufacturer = "Funvision - Fund. International Co.",
        .name         = "Time Race (Funvision) (PAL)",
        .note         = "AKA Time Warp",
    },{
        .md5          = "71f8bacfbdca019113f3f0801849057e",
        .manufacturer = "Atari, Dan Hitchens",
        .model        = "CX26126",
        .name         = "Elevator Action (1983) (Atari) (Prototype)",
    },{
        .md5          = "72097e9dc366900ba2da73a47e3e80f5",
        .name         = "Euchre (15-06-2001) (Eric Eid) (PD)",
    },{
        .md5          = "721a5567f76856f6b50a6707aa8f8316",
        .manufacturer = "Activision, David Crane, Dan Kitchen",
        .model        = "EAG-108-04, EAZ-108-04B",
        .name         = "Ghostbusters (1985) (Activision) (PAL) [a]",
    },{
        .md5          = "7224947dce1130f70de83f25b446e4e4",
        .manufacturer = "Fotomania",
        .name         = "Mr. Postman (Fotomania)",
    },{
        .md5          = "72305c997f2cec414fe6f8c946172f83",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4000, AR-4100",
        .name         = "Phaser Patrol (1982) (Arcadia) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "724613effaf7743cbcd695fab469c2a8",
        .name         = "Super-Ferrari (Unknown)",
        .note         = "AKA Enduro",
    },{
        .md5          = "726af33d9acfc8616a8df05de4f560af",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Robot City RC8 (PAL-60)",
        .phosphor     = 1,
    },{
        .md5          = "728152f5ae6fdd0d3a9b88709bee6c7a",
        .manufacturer = "Spectravideo, Mark Turmell",
        .model        = "SA-217",
        .name         = "Gas Hog (1983) (Spectravideo)",
    },{
        .md5          = "72876fd7c7435f41d571f1101fc456ea",
        .manufacturer = "Quelle",
        .model        = "688.383 9",
        .name         = "Die Ente und der Wolf (1983) (Quelle) (PAL)",
        .note         = "AKA Pooyan",
    },{
        .md5          = "72a46e0c21f825518b7261c267ab886e",
        .manufacturer = "Xonox - K-Tel Software - Computer Magic",
        .model        = "99005, 6220, 6250",
        .name         = "Robin Hood (1983) (Xonox)",
    },{
        .md5          = "72a5b5052272ac785fa076709d16cef4",
        .name         = "KC Munckin (29-01-2003) (J. Parlee)",
    },{
        .md5          = "72a63bcb5eb31bd0fd5e98ed05125ec1",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Control - Atari Trak-Ball Hack v1.15 (PAL60) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "72bda70c75dfa2365b3f8894bace9e6a",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Atlantis (Thomas Jentzsch) (Hack)",
        .note         = "Hack of Atlantis",
    },{
        .md5          = "72d0acb5de0db662de0360a6fc59334d",
        .name         = "Cosmic Ark (Unknown) (PAL)",
    },{
        .md5          = "72db1194b1cc7d45b242f25eb1c148d3",
        .name         = "Pac-Man (1981) (Atari) (Hack)",
        .note         = "Hack of Pac-Man",
    },{
        .md5          = "72fd08deed1d6195942e0c6f392e9848",
        .manufacturer = "HES",
        .model        = "0701-406",
        .name         = "2 Pak Special - Wall Defender, Planet Patrol (1990) (HES) (PAL)",
    },{
        .md5          = "72ffbef6504b75e69ee1045af9075f66",
        .manufacturer = "Atari, Richard Maurer - Sears",
        .model        = "CX2632 - 49-75153",
        .name         = "Space Invaders (1980) (Atari)",
    },{
        .md5          = "73158ea51d77bf521e1369311d26c27b",
        .manufacturer = "Zellers",
        .name         = "Challenge (Zellers)",
    },{
        .md5          = "73521c6b9fed6a243d9b7b161a0fb793",
        .manufacturer = "Atari, Tom Reuterdahl",
        .model        = "CX26163P",
        .name         = "Miniaturer Golf (32 in 1) (1988) (Atari) (PAL)",
        .note         = "AKA Miniature Golf",
    },{
        .md5          = "736388d73198552d77d423962000006f",
        .manufacturer = "Dactari",
        .name         = "Tennis (Dactari) (4K)",
    },{
        .md5          = "73a710e621d44e97039d640071908aef",
        .name         = "Barber Pole Demo (PD)",
    },{
        .md5          = "73aa02458b413091ac940c0489301710",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-016",
        .name         = "Boom Bang (1983) (Rainbow Vision) (PAL)",
        .note         = "AKA Crackpots",
    },{
        .md5          = "73b4e8f8b04515d91937510e680214bc",
        .name         = "Rubik's Cube Demo 3 (24-12-2002) (Christopher Tumber)",
    },{
        .md5          = "73c545db2afd5783d37c46004e4024c2",
        .manufacturer = "CBS Electronics - JWDA, Todd Marshall, Robin McDaniel, Henry Will IV",
        .model        = "4L1767, 4L1768, 4L1769, 4L1770",
        .name         = "Smurf - Schtroumpfs (1983) (CBS Electronics) (PAL)",
        .note         = "Pitufo",
    },{
        .md5          = "73c839aff6a055643044d2ce16b3aaf7",
        .manufacturer = "Activision, Alan Miller - Ariola",
        .model        = "EAX-016, PAX-016 - 711 016-725",
        .name         = "StarMaster (1982) (Activision) (PAL)",
        .note         = "Use Color/BW switch to change between galactic chart and front views",
    },{
        .md5          = "73cb1f1666f3fd30b52b4f3d760c928f",
        .name         = "Mines of Minos (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "73e66e82ac22b305eb4d9578e866236e",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Unknown Datatech Game (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "73efa9f3cbe197f26e0fb87132829232",
        .manufacturer = "CCE",
        .model        = "C-858",
        .name         = "Tennis (1983) (CCE) (4K)",
    },{
        .md5          = "74023e0f2e739fc5a9ba7caaeeee8b6b",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Fishing Derby (Jone Yuan) (Hack)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "740a7fa80f52cc7287ba37677afb6b21",
        .name         = "Double Dragon (PAL) (Genesis)",
        .note         = "Genesis controller (C is jumpkick)",
    },{
        .md5          = "740b47df422372fbef700b42cea4e0bf",
        .name         = "Dizzy Wiz (2001) (B. Watson)",
    },{
        .md5          = "740f39e71104e90416c29a73560b9c6b",
        .manufacturer = "Atari",
        .model        = "TE016643",
        .name         = "Diagnostic Test Cartridge 2.6P (1982) (Atari) (PAL) (4K)",
    },{
        .md5          = "7412f6788087d7e912c33ba03b36dd1b",
        .manufacturer = "AtariAge, Omegamatrix",
        .name         = "Venture Reloaded (2019) (AtariAge) (Hack)",
        .note         = "Transformative hack of Venture",
        .phosphor     = 1,
    },{
        .md5          = "742de93b8d849220f266b627fbabba82",
        .name         = "SCSIcide (25-02-2001) (Chris Wilkson) (PD)",
    },{
        .md5          = "7450ae4e10ba8380c55b259d7c2b13e8",
        .name         = "Register Twiddler Demo 2 (PD)",
    },{
        .md5          = "7454786af7126ccc7a0c31fcf5af40f1",
        .name         = "Phantom Tank (Unknown) (PAL)",
    },{
        .md5          = "745820765bd159c5bf5222fb859769d8",
        .manufacturer = "Bit Corporation",
        .model        = "CP405",
        .name         = "Laser Blaser (4 Game in One) (1983) (BitCorp) (PAL)",
        .note         = "AKA The End of the World",
    },{
        .md5          = "7465b06b6e25a4a6c6d77d02242af6d6",
        .manufacturer = "Atari",
        .model        = "CX26193",
        .name         = "8 in 1 (01-16-92) (Atari) (Prototype)",
        .note         = "Game 2 is Centipede, but doesn't work",
        .type         = "8IN1",
    },{
        .md5          = "7481f0771bff13885b2ff2570cf90d7b",
        .manufacturer = "Arcadia Corporation, Brian McGhie",
        .model        = "AR-4104",
        .name         = "Rabbit Transit (1983) (Arcadia) (PAL)",
    },{
        .md5          = "749fec9918160921576f850b2375b516",
        .manufacturer = "Spectravision - Spectravideo",
        .model        = "SA-205",
        .name         = "China Syndrome (1982) (Spectravision)",
        .phosphor     = 1,
    },{
        .md5          = "74d072e8a34560c36cacbc57b2462360",
        .manufacturer = "Sancho - Tang's Electronic Co.",
        .model        = "TEC002",
        .name         = "Seahawk (1982) (Sancho) (PAL)",
    },{
        .md5          = "74ebaca101cc428cf219f15dda84b6f8",
        .manufacturer = "Activision, Alan Miller",
        .model        = "AG-007, CAG-007",
        .name         = "Tennis (1981) (Activision) (8K)",
    },{
        .md5          = "74f623833429d35341b7a84bc09793c0",
        .manufacturer = "Zellers",
        .name         = "Radar (Zellers)",
        .note         = "AKA Exocet",
    },{
        .md5          = "75028162bfc4cc8e74b04e320f9e6a3f",
        .manufacturer = "Atari, Greg Easter, Mimi Nyden",
        .model        = "CX26107",
        .name         = "Snow White (02-09-1983) (Atari) (Prototype)",
    },{
        .md5          = "7511c34518a9a124ea773f5b0b5c9a48",
        .name         = "Donkey Kong (Unknown) (PAL)",
    },{
        .md5          = "75169c08b56e4e6c36681e599c4d8cc5",
        .manufacturer = "M Network - INTV - APh Technological Consulting, Hal Finney",
        .model        = "MT5666",
        .name         = "Astroblast (1982) (M Network)",
        .note         = "Can also use left joystick",
        .left         = "PADDLES",
        .swapPaddles  = 1,
    },{
        .md5          = "752da1c0acd7d132ccfb0b1067f53cf6",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Atari Mouse Hack v1.3 (PAL) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "753375d183c713cfa0aa7298d1f3067b",
        .manufacturer = "Arcadia Corporation, Steve Hales, Stephen Harland Landrum",
        .model        = "AR-4102",
        .name         = "Suicide Mission (1982) (Arcadia) [a]",
        .phosphor     = 1,
    },{
        .md5          = "7550b821ee56fb5833dca2be88622d5a",
        .name         = "Multiple Moving Objects Demo (B. Watson)",
    },{
        .md5          = "75511bb694662301c9e71df645f4b5a7",
        .manufacturer = "Activision, Bob Whitehead - Ariola",
        .model        = "EAG-011, PAG-011 - 711 011-715",
        .name         = "Stampede (1981) (Activision) (PAL)",
    },{
        .md5          = "755fed16b48e81de05130708a905d00d",
        .manufacturer = "SnailSoft",
        .name         = "Comitoid beta 3 (SnailSoft)",
    },{
        .md5          = "756ca07a65a4fbbedeb5f0ddfc04d0be",
        .manufacturer = "Atari, Jim Huether",
        .model        = "CX2629, CX2629P",
        .name         = "Sky Diver (1979) (Atari) (PAL)",
    },{
        .md5          = "7574480ae2ab0d282c887e9015fdb54c",
        .manufacturer = "Atari, Jerome Domurat, Steve Woita",
        .model        = "CX2699",
        .name         = "Taz (1984) (Atari)",
    },{
        .md5          = "7576dd46c2f8d8ab159d97e3a3f2052f",
        .manufacturer = "Goliath - Hot Shot",
        .model        = "83-112",
        .name         = "Time Machine (1983) (Goliath) (PAL)",
        .note         = "AKA Asteroid Fire",
    },{
        .md5          = "757f529026696e13838364dea382a4ed",
        .manufacturer = "Activision, David Crane - Ariola",
        .model        = "EAX-014, PAX-014, EAX-014-04B, EAX-014-04I - 711 014-720",
        .name         = "Grand Prix (1982) (Activision) (PAL)",
    },{
        .md5          = "75893a9dc5de4b91cc426959b82a1da0",
        .manufacturer = "Champ Games",
        .model        = "CG-02-P",
        .name         = "Conquest Of Mars (2010) (PAL60)",
        .note         = "Rev 2 release",
    },{
        .md5          = "75a303fd46ad12457ed8e853016815a0",
        .manufacturer = "ZiMAG - Emag - Vidco",
        .model        = "715-111 - GN-060",
        .name         = "Immies & Aggies (1983) (ZiMAG) (Prototype)",
    },{
        .md5          = "75b22fdf632d76e246433db1ebccd3c4",
        .name         = "Skeleton+ (05-05-2003) (Eric Ball) (PAL)",
    },{
        .md5          = "75b557be7f08db84ec5b242207b9f241",
        .name         = "Space Treat (30-12-2002) (Fabrizio Zavagli) [a1]",
    },{
        .md5          = "75e276ba12dc4504659481c31345703a",
        .manufacturer = "Arcadia Corporation, Kevin Norman",
        .model        = "AR-4103",
        .name         = "Killer Satellites (1983) (Arcadia) (PAL)",
    },{
        .md5          = "75e8d8b9e9c5c67c2226dbfd77dcfa7d",
        .name         = "2600 Digital Clock (V b1) (PD)",
    },{
        .md5          = "75ea128ba96ac6db8edf54b071027c4e",
        .manufacturer = "Atari, David Crane",
        .model        = "CX26163P",
        .name         = "Slot Machine (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "75ea60884c05ba496473c23a58edf12f",
        .manufacturer = "Atari, Howard Scott Warshaw - Sears",
        .model        = "CX2655 - 49-75167",
        .name         = "Yars' Revenge (1982) (Atari) (PAL) [a]",
        .note         = "ROM must be started in bank 0",
        .phosphor     = 1,
    },{
        .md5          = "75ee371ccfc4f43e7d9b8f24e1266b55",
        .manufacturer = "Atari, Greg Easter, Mimi Nyden",
        .model        = "CX26107",
        .name         = "Snow White (11-09-1982) (Atari) (Prototype)",
        .note         = "ROM must be started in bank 0",
    },{
        .md5          = "7608abdfd9b26f4a0ecec18b232bea54",
        .manufacturer = "Atari, Bob Whitehead",
        .model        = "CX26163P",
        .name         = "NFL Football (32 in 1) (1988) (Atari) (PAL)",
        .note         = "AKA Football",
    },{
        .md5          = "7623a639a6fffdb246775fe2eabc8d01",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AG-005, CAG-005, AG-005-04",
        .name         = "Skiing (1980) (Activision) (8K)",
    },{
        .md5          = "7628d3cadeee0fd2e41e68b3b8fbe229",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Fishing Derby (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "7648e72a5b5899076688df18a1ddcf72",
        .manufacturer = "CBS Electronics, Richard K. Balaska Jr., Andy Frank, Stuart Ross",
        .model        = "4L 2520 5000",
        .name         = "Tunnel Runner (1983) (CBS Electronics) (Prototype)",
        .note         = "Black Box",
    },{
        .md5          = "764ce6801f28a9ad36f11de3e57c053b",
        .manufacturer = "Atari, Jim Huether, Alan J. Murphy, Robert C. Polaro",
        .model        = "CX2666",
        .name         = "RealSports Volleyball (1982) (Atari) (Prototype)",
    },{
        .md5          = "76809eb1ee0db8a318308a5cdda0f4e2",
        .manufacturer = "Atari, Jerome Domurat, Steve Woita",
        .model        = "CX2699",
        .name         = "Taz (1983) (Atari) (Prototype) [a]",
    },{
        .md5          = "769ddc995dbb9edb8167efcea9f34a7c",
        .name         = "H.E.R.O. (Genesis)",
        .note         = "Genesis controller (B is laser, C is dynamite)",
    },{
        .md5          = "76a9bf05a6de8418a3ebc7fc254b71b4",
        .manufacturer = "VideoSoft, Jerry Lawson, Dan McElroy",
        .model        = "VS1008",
        .name         = "Color Bar Generator (1984) (VideoSoft)",
    },{
        .md5          = "76c685d1a60c0107aa54a772113a2972",
        .manufacturer = "Arcadia Corporation, Steve Mundry, Scott Nelson",
        .model        = "AR-4401",
        .name         = "Survival Island (3 of 3) (1983) (Arcadia) (PAL)",
    },{
        .md5          = "76c88341017eae660efc6e49c4b6ab40",
        .name         = "Indiana Pitfall (Hack)",
        .note         = "Hack of Pitfall!",
    },{
        .md5          = "76ee917d817ef9a654bc4783e0273ac4",
        .manufacturer = "Otto Versand",
        .model        = "311377",
        .name         = "Fox & Goat (Double-Game Package) (1983) (Otto Versand) (PAL)",
        .note         = "AKA Nuts",
    },{
        .md5          = "76f53abbbf39a0063f24036d6ee0968a",
        .manufacturer = "M Network, David Akers, Joe 'Ferreira' King, Patricia Lewis Du Long, Jeff Ratcliff - INTV",
        .model        = "MT7045",
        .name         = "Bump 'n' Jump (1983) (M Network)",
    },{
        .md5          = "76f66ce3b83d7a104a899b4b3354a2f2",
        .manufacturer = "UA Limited",
        .name         = "Cat Trax (1983) (UA Limited) (1)",
        .phosphor     = 1,
    },{
        .md5          = "77057d9d14b99e465ea9e29783af0ae3",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-001",
        .name         = "Dragster (1980) (Activision)",
        .note         = "AKA Drag Strip",
    },{
        .md5          = "7732e4e4cc2644f163d6650ddcc9d9df",
        .manufacturer = "HES",
        .model        = "771-333",
        .name         = "2 Pak Special - Challenge, Surfing (1990) (HES) (PAL)",
    },{
        .md5          = "7761418d46af069b8cd80c29fe6cd814",
        .manufacturer = "Dion Olsthoorn",
        .model        = "RetroN 77 edition",
        .name         = "Amoeba Jump (R77) (DionoiD)",
    },{
        .md5          = "7778ac65d775a079f537e97cbdad541c",
        .name         = "Spider Fighter (Unknown) (PAL)",
    },{
        .md5          = "777aece98d7373998ffb8bc0b5eff1a2",
        .name         = "2600 Collison Demo 2 (Piero Cavina) (PD)",
    },{
        .md5          = "77887e4192a6b0a781530e6cf9be7199",
        .manufacturer = "Atari",
        .model        = "CX2604",
        .name         = "Space War (1978) (Atari) [b1]",
    },{
        .md5          = "77be57d872e3f5b7ecf8d19d97f73281",
        .name         = "Basketball (Unknown) (PAL)",
        .note         = "Console ports are swapped",
        .swapPorts    = 1,
    },{
        .md5          = "77cd9a9dd810ce8042bdb9d40e256dfe",
        .manufacturer = "Kyle Pittman",
        .name         = "Evil Dead (2003) (Kyle Pittman) (Hack)",
        .note         = "Hack of Haunted House",
    },{
        .md5          = "77d0a577636e1c9212aeccde9d0baa4b",
        .manufacturer = "Atari, Joe Decuir",
        .model        = "CX2621, CX2621P",
        .name         = "Video Olympics (1977) (Atari) (PAL)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXDR",
        .right        = "PADDLES_IAXDR",
        .swapPaddles  = 1,
    },{
        .md5          = "78297db7f416af3052dd793b53ff014e",
        .name         = "Poker Squares (V0.17) (2001) (B. Watson)",
    },{
        .md5          = "7836794b79e8060c2b8326a2db74eef0",
        .name         = "RIOT RAM Test (26-11-2002) (Dennis Debro)",
    },{
        .md5          = "784176346e9422733d55c427230e5bad",
        .manufacturer = "Activision, Alex DeMeo",
        .name         = "Title Match Pro Wrestling (1989) (Activision)",
    },{
        .md5          = "784abfdb31d5341e5bd404d8d2a71c3b",
        .manufacturer = "Alessandro Ciceri",
        .name         = "MagiCard (TV format conversion) (alex_79) (PAL)",
        .note         = "MagiCard PAL conversion hack",
    },{
        .md5          = "7860716fa5dbc0fffab93fb9a4cb4132",
        .name         = "Hangman Monkey Wordlist (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "7867ee819b53d69cfcfe740f7ddca574",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "1 AR-4000, AR-4100",
        .name         = "Phaser Patrol (1982) (Arcadia) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "787ebc2609a31eb5c57c4a18837d1aee",
        .manufacturer = "Brian Prescott",
        .name         = "Vault Assault (19xx) (Brian Prescott)",
    },{
        .md5          = "78821ef76ebc3934850d1bc1b9e4f4b0",
        .manufacturer = "HES - Activision",
        .model        = "542",
        .name         = "Hot Action Pak - Ghostbusters, Tennis, Plaque Attack (1990) (HES) (PAL)",
    },{
        .md5          = "78963290052fd17c6c7998305ab3a6a0",
        .name         = "Push (V0.08) (2001) (Andrew Davie)",
    },{
        .md5          = "78b84cfb1c57b0488d674d2374e656e6",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum",
        .model        = "AR-4400",
        .name         = "Dragonstomper (1 of 3) (1982) (Starpath)",
    },{
        .md5          = "78c2de58e42cd1faac2ea7df783eaeb3",
        .name         = "Fu Kung! (V0.07) (25-01-2003) (Andrew Davie)",
    },{
        .md5          = "79004f84bdeee78d142e445057883169",
        .manufacturer = "CCE",
        .model        = "C-830",
        .name         = "Planet Patrol (1983) (CCE)",
    },{
        .md5          = "791bc8aceb6b0f4d9990d6062b30adfa",
        .manufacturer = "Activision, David Crane - Ariola",
        .model        = "EAX-018, EAX-018-04B, EAX-018-04I - 711 018-725",
        .name         = "Pitfall! (1982) (Activision) (PAL)",
        .note         = "Abenteuer im Urwald (Jungle Runner)",
    },{
        .md5          = "791c88eca9836af8c34bf32b07cb58a7",
        .manufacturer = "SpiceWare - Darrell Spice Jr.",
        .model        = "SW-05",
        .name         = "Stay Frosty 2 (PAL60)",
        .note         = "AtariAge Holiday Greetings 2014",
        .left         = "JOYSTICK",
        .phosphor     = 1,
    },{
        .md5          = "7926083ad423ed685de3b3a04a914315",
        .manufacturer = "Barry Laws Jr.",
        .name         = "Face Invaders 2 (Barry Laws Jr.) (Hack)",
        .note         = "Hack of Astroblast",
        .left         = "PADDLES",
        .swapPaddles  = 1,
    },{
        .md5          = "792b1d93eb1d8045260c840b0688ec8f",
        .manufacturer = "Kroko",
        .name         = "3E Bankswitch Test (TIA @ $00)",
    },{
        .md5          = "7972e5101fa548b952d852db24ad6060",
        .manufacturer = "Atari - Sears",
        .model        = "CX2627 - 6-99841",
        .name         = "Human Cannonball (1979) (Atari)",
        .note         = "AKA Cannon Man",
    },{
        .md5          = "798b8921276eec9e332dfcb47a2dbb17",
        .manufacturer = "Atari - CCW, Gary Stark",
        .model        = "CX26102",
        .name         = "Cookie Monster Munch (1983) (Atari) (PAL) [a]",
        .note         = "Uses Kids/Keyboard Controllers",
        .right        = "KEYBOARD",
    },{
        .md5          = "798cc114f1623c14085868cd3494fe8e",
        .name         = "Pins Revenge (Atari Freak 1)",
    },{
        .md5          = "7991e1797e5e9f311fd957e62d889dff",
        .manufacturer = "Joe Grand",
        .name         = "SCSIcide (v1.1) (2001) (Joe Grand)",
        .left         = "PADDLES_IAXDR",
    },{
        .md5          = "7996b8d07462a19259baa4c811c2b4b4",
        .name         = "Math Gran Prix (Unknown) (PAL)",
    },{
        .md5          = "79ab4123a83dc11d468fb2108ea09e2e",
        .manufacturer = "Activision - Cheshire Engineering, David Rolfe, Larry Zwick",
        .model        = "AZ-037-04",
        .name         = "Beamrider (1984) (Activision)",
    },{
        .md5          = "79b649fb812c50b4347d12e7ddbb8400",
        .name         = "Red Pong Number 2 Demo 2 (PD)",
        .phosphor     = 1,
    },{
        .md5          = "79c27f90591e3fdc7d2ed020ecbedeb3",
        .manufacturer = "CCE",
        .model        = "C-815",
        .name         = "Seaquest (1983) (CCE) [a]",
    },{
        .md5          = "79d4af56036ec28f298cad964a2e2494",
        .name         = "Hangman Pac-Man Wordlist (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "79d6f61da3c64688ac8e075667f8a39f",
        .name         = "Tie-Fighters (Manuel Rotschkar)",
    },{
        .md5          = "79e5338dbfa6b64008bb0d72a3179d3c",
        .manufacturer = "M Network - INTV, David Akers, Patricia Lewis Du Long",
        .model        = "MT4313",
        .name         = "Star Strike (1983) (M Network)",
    },{
        .md5          = "79fcdee6d71f23f6cf3d01258236c3b9",
        .manufacturer = "Atari - GCC, Mike Feinstein, John Mracek",
        .model        = "CX2673, CX2673P",
        .name         = "Phoenix (1983) (Atari) (PAL)",
    },{
        .md5          = "7a09299f473105ae1ef3ad6f9f2cd807",
        .manufacturer = "Atari, Steve Wright",
        .model        = "CX2616P",
        .name         = "Pele's Soccer (1981) (Atari) (PAL)",
        .note         = "AKA Pele's Championship Soccer",
    },{
        .md5          = "7a2af383014f5d810ad26d322823549d",
        .name         = "FlickerSort Demo (20-04-2002) (Manuel Rotschkar)",
    },{
        .md5          = "7a48dd03d839da082dc2287ede070383",
        .name         = "Atari 2600 Multicart (16x8K, F8/E0)",
        .type         = "16IN1",
    },{
        .md5          = "7a5463545dfb2dcfdafa6074b2f2c15e",
        .manufacturer = "20th Century Fox Video Games - Sirius Software, Mark Turmell",
        .model        = "11007",
        .name         = "Turmoil (1982) (20th Century Fox)",
    },{
        .md5          = "7a63d7ea3f2851bcf04f0bb4ba1a3929",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4200",
        .name         = "Escape from the Mindmaster (3 of 4) (1982) (Arcadia)",
    },{
        .md5          = "7a64a8b727c8215d945e37d565ca95a5",
        .manufacturer = "Atari, Warren Robinett",
        .model        = "CX2606",
        .name         = "Slot Racers (1978) (Atari) (PAL) (4K)",
    },{
        .md5          = "7a64b5a6e90619c6aacf244cdd7502f8",
        .manufacturer = "Baroque Gaming (Billy Eno)",
        .name         = "Warring Worms (Beta 1) (2002) (Baroque Gaming)",
    },{
        .md5          = "7a7f6ab9215a3a6b5940b8737f116359",
        .manufacturer = "Arcadia Corporation, Kevin Norman",
        .model        = "AR-4103",
        .name         = "Killer Satellites (1983) (Arcadia)",
    },{
        .md5          = "7a93d0c029eaa72236523eedc3f19645",
        .name         = "20 Sprites at Once Demo 2 (PD)",
    },{
        .md5          = "7ab0917107b6ec768a5ebaadf28c497a",
        .name         = "Santa's Helper (Hack)",
        .note         = "Hack of Kaboom!",
    },{
        .md5          = "7ab210f448de518fa61a5924120ba872",
        .name         = "Fortress (20-04-2003) (Christopher Tumber)",
    },{
        .md5          = "7ab2f190d4e59e8742e76a6e870b567e",
        .manufacturer = "Apollo, Larry Martin",
        .model        = "AP-2008",
        .name         = "Guardian (1982) (Apollo)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "7ac4f4fb425db38288fa07fb8ff4b21d",
        .manufacturer = "Goliath",
        .model        = "83-213",
        .name         = "Space Eagle (1983) (Goliath) (PAL)",
        .note         = "AKA Exocet",
    },{
        .md5          = "7ad257833190bc60277c1ca475057051",
        .manufacturer = "Atari, Alan J. Murphy, Robert Zdybel",
        .model        = "CX2668",
        .name         = "RealSports Football (1982) (Atari)",
        .phosphor     = 1,
    },{
        .md5          = "7ad782952e5147b88b65a25cadcdf9e0",
        .manufacturer = "Imagic, Dave Johnson",
        .model        = "720119-1A, 03211",
        .name         = "Kwibble (1983) (Imagic) (Prototype)",
        .note         = "AKA Quick Step! Beta",
    },{
        .md5          = "7adbcf78399b19596671edbffc3d34aa",
        .manufacturer = "Atari, Mimi Nyden, Joseph Tung",
        .model        = "CX26152",
        .name         = "Super Baseball (1988) (Atari)",
    },{
        .md5          = "7af40c1485ce9f29b1a7b069a2eb04a7",
        .manufacturer = "Amiga - Video Soft",
        .model        = "3120",
        .name         = "Mogul Maniac (1983) (Amiga)",
        .note         = "Uses the Amiga Joyboard",
    },{
        .md5          = "7b24bfe1b61864e758ada1fe9adaa098",
        .manufacturer = "Atari, Chris Crawford",
        .name         = "Wizard (1980) (Atari) (Prototype)",
    },{
        .md5          = "7b33407b2b198af74906b936ce1eecbb",
        .manufacturer = "King Atari",
        .name         = "Ghostbuster 2 (King Atari)",
        .phosphor     = 1,
    },{
        .md5          = "7b3cf0256e1fa0fdc538caf3d5d86337",
        .manufacturer = "CommaVid, Joseph Biel",
        .model        = "CM-009",
        .name         = "Stronghold (1983) (CommaVid)",
    },{
        .md5          = "7b43c32e3d4ff5932f39afcb4c551627",
        .manufacturer = "Syncro, Daniel Wolf",
        .name         = "Kamikaze Saucers (1983) (Syncro) (Prototype)",
    },{
        .md5          = "7b4be337ac4d73eda75c848355f6f480",
        .manufacturer = "Omegamatrix",
        .name         = "Star Wars Arcade (Atari Trak-Ball) (Y Inverted) (PAL60) v4 (Omegamatrix)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "7b5207e68ee85b16998bea861987c690",
        .manufacturer = "Atari, Carol Shaw",
        .model        = "CX26163P",
        .name         = "3-D Tic-Tac-Toe (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "7b57318c489ff178f7ff500da1ec9e8c",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Amiga Mouse Hack v1.3 (PAL) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "7b6f3348dbf71ada88db0fdaf7feefe0",
        .name         = "3-D Corridor (Pink Spiral) (31-03-2003) (Andrew Davie)",
    },{
        .md5          = "7b79beb378d1b4471def90ceccf413de",
        .name         = "Pitfall Cupcake (Hack)",
        .note         = "Hack of Pitfall",
    },{
        .md5          = "7b7b4ac05232490c28f9b680c72998f9",
        .manufacturer = "Zellers",
        .name         = "Freeway (Zellers)",
    },{
        .md5          = "7b8a481e0c5aa78150b5555dff01f64e",
        .manufacturer = "Atari - GCC, Mark Ackerman, Noelie Alito",
        .model        = "CX2692",
        .name         = "Moon Patrol (05-12-1983) (Atari) (Prototype)",
    },{
        .md5          = "7b938c7ddf18e8362949b62c7eaa660a",
        .manufacturer = "Atari, Bob Whitehead - Sears",
        .model        = "CX2603 - 99803, 49-75601",
        .name         = "Star Ship (1977) (Atari) (4K)",
    },{
        .md5          = "7ba07d4ea18bf3b3245c374d8720ad30",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum",
        .model        = "AR-4101",
        .name         = "Communist Mutants from Space (Preview) (1982) (Arcadia) (PAL)",
    },{
        .md5          = "7bb286cb659d146af3966d699b51f509",
        .manufacturer = "Atari - Axlon, Tod Frye - Heuristica, Agustin Ortiz Valdiviezo",
        .model        = "CX26178",
        .name         = "Save Mary! (04-03-1989) (Atari) (Prototype)",
        .note         = "AKA Saving Mary",
    },{
        .md5          = "7bc4fd254ec8c0a25a13f02fd3f762ff",
        .manufacturer = "Retroactive",
        .name         = "Qb (V1.00) (Stella) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "7c00e7a205d3fda98eb20da7c9c50a55",
        .manufacturer = "Apollo - Games by Apollo, Larry Minor, Ernie Runyon, Ed Salvo",
        .model        = "AP-2004",
        .name         = "Lost Luggage (1982) (Apollo)",
        .note         = "AKA Airport Mayhem",
    },{
        .md5          = "7c4a499d343fca0cef2d59dd16af621a",
        .name         = "Poker Card Demo (PD)",
    },{
        .md5          = "7c757bb151269b2a626c907a22f5dae7",
        .manufacturer = "TNT Games - Sculptured Software, Adam Clayton",
        .model        = "26192",
        .name         = "BMX Air Master (1989) (TNT Games) (PAL)",
    },{
        .md5          = "7c7a4a2d505c2d0c75337c44711d8d54",
        .manufacturer = "Atari, Warren Robinett",
        .name         = "Elf Adventure (04-22-83) (Atari) (Prototype)",
    },{
        .md5          = "7c9b3b8b25acf2fe3b8da834f69629c6",
        .name         = "I Robot (1984) (Atari) (Prototype) [!]",
    },{
        .md5          = "7ca7a471d70305c673fedd08174a81e8",
        .manufacturer = "Tim Snider",
        .name         = "Venture II (2001) (Tim Snider)",
        .phosphor     = 1,
    },{
        .md5          = "7cc77f6745e1f2b20df4a4327d350545",
        .manufacturer = "Atari, Richard Maurer",
        .model        = "CX2632, CX2632P",
        .name         = "Space Invaders (1980) (Atari) (PAL) [fixed]",
    },{
        .md5          = "7ccf350354ee15cd9b85564a2014b08c",
        .name         = "Big Dig (13-04-2003) (Christopher Tumber)",
    },{
        .md5          = "7cd379da92c93679f3b6d2548617746a",
        .name         = "Demo Image Series #5 - Clown (19-02-2003) (Andrew Davie)",
    },{
        .md5          = "7cd900e9eccbb240fe9c37fa28f917b5",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Bi! Bi! (Jone Yuan) (PAL)",
        .note         = "AKA Skindiver",
    },{
        .md5          = "7ced6709f091e79a2ab9575d3516a4ac",
        .manufacturer = "Activision, Steve Cartwright - Ariola",
        .model        = "EAX-027 - 711 027-722",
        .name         = "Plaque Attack (1983) (Activision) (PAL)",
    },{
        .md5          = "7cedffa0db65d610568b90aeca705ac6",
        .manufacturer = "Atari, Rob Fulop - Sears",
        .model        = "CX2638 - 49-75166",
        .name         = "Missile Command (1981) (Atari) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "7cf3a9267cdb95aba91abc5838d61cc5",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Atari Mouse Hack v1.4 (PAL60) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "7d0b49ea4fe3a5f1e119a6d14843db17",
        .manufacturer = "Gameworld, J. Ray Dettling",
        .model        = "133-008",
        .name         = "Frankenstein's Monster (1983) (Gameworld) (PAL)",
    },{
        .md5          = "7d1034bcb38c9b746ea2c0ae37d9dff2",
        .manufacturer = "Atari, Brad Stewart",
        .name         = "Morse Code Tutor (1979) (Atari)",
    },{
        .md5          = "7d24f3054be9950aa263e005581c4786",
        .manufacturer = "Parker Brothers - First Star Software, Alex Leavens",
        .name         = "Astro Chase (10-25-1983) (Parker Bros) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "7d3cdde63b16fa637c4484e716839c94",
        .manufacturer = "CCE",
        .name         = "Road Runner (CCE)",
    },{
        .md5          = "7d483b702c44ee65cd2df22cbcc8b7ed",
        .manufacturer = "Atari, Warren Robinett",
        .name         = "Elf Adventure (05-25-83) (Atari) (Prototype)",
    },{
        .md5          = "7d5c3b7b908752b98e30690e2a3322c2",
        .manufacturer = "Dactari - Milmar",
        .name         = "Freeway (Dactari - Milmar)",
    },{
        .md5          = "7d726fa494f706784bafeb1b50d87f23",
        .manufacturer = "Coleco - Individeo, Ed Temple",
        .name         = "Cabbage Patch Kids (07-27-1984) (Coleco) (Prototype)",
        .note         = "Adventures in the Park",
    },{
        .md5          = "7d8287e8423a56d4f8cef10435d97179",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Challenge of... Nexar, The - Atari Trak-Ball Hack v1.2 (NTSC) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "7d903411807704e725cf3fafbeb97255",
        .manufacturer = "Imagic, Rob Fulop",
        .model        = "720104-1A, 720104-1B, IA3204",
        .name         = "Cosmic Ark (Reaction) (1982) (Imagic) [selectable starfield]",
    },{
        .md5          = "7d93071b3e3616093a6b5a98b0315751",
        .name         = "Gunfight 2600 - Music & Bugfixes 2 (2001) (Manuel Rotschkar)",
    },{
        .md5          = "7d940d749e55b96b7b746519fa06f2de",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4302",
        .name         = "Party Mix (Preview) (1983) (Arcadia) (PAL)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "7d9c96b215d1941e87b6fb412eb9204f",
        .name         = "Othello (Unknown) (PAL) (4K)",
    },{
        .md5          = "7da9de8d62fcdd3a2c545b2e720c2a61",
        .manufacturer = "CommaVid, John Bronstein",
        .model        = "CM-001",
        .name         = "MagiCard (1981) (CommaVid) (4K)",
        .note         = "Uses the Keyboard Controllers",
    },{
        .md5          = "7dbc8fa2e488e3f6b87fbe0f76c5b89f",
        .manufacturer = "Ed Federmeyer",
        .name         = "Sound X (1996) (Ed Federmeyer)",
    },{
        .md5          = "7dc03a1f56d0e6a8aae3e3e50d654a08",
        .name         = "Hozer Video Demo (PD)",
    },{
        .md5          = "7dcbfd2acc013e817f011309c7504daa",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4000, AR-4100",
        .name         = "Phaser Patrol (1982) (Arcadia)",
        .phosphor     = 1,
    },{
        .md5          = "7dd9c5284422f729066ab22a284c8283",
        .manufacturer = "CCE",
        .model        = "C-833",
        .name         = "Target Practice (1983) (CCE) [a]",
        .note         = "AKA Carnival",
    },{
        .md5          = "7ded20e88b17c8149b4de0d55c795d37",
        .manufacturer = "Thomas Jentzsch, Paul Slocum",
        .name         = "Thrust+ Platinum (v1.26)",
        .left         = "BOOSTERGRIP",
        .right        = "DRIVING",
    },{
        .md5          = "7dfd100bda9abb0f3744361bc7112681",
        .manufacturer = "Telesys, Don Ruffcorn",
        .model        = "1006",
        .name         = "Demolition Herby (1983) (Telesys) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "7e2fe40a788e56765fe56a3576019968",
        .manufacturer = "Activision - Imagineering, Donald Hahn, Dan Kitchen",
        .model        = "AK-050-04",
        .name         = "Double Dragon (1989) (Activision)",
    },{
        .md5          = "7e464186ba384069582d9f0c141f7491",
        .manufacturer = "PlayAround - JHM",
        .model        = "206",
        .name         = "General Re-Treat (1982) (PlayAround) (PAL)",
        .note         = "AKA Custer's Revenge",
    },{
        .md5          = "7e4783a59972ae2cd8384f231757ea0b",
        .manufacturer = "Atari - Imagineering, Dan Kichen",
        .model        = "CX26139P",
        .name         = "Crossbow (1988) (Atari) (PAL)",
    },{
        .md5          = "7e51a58de2c0db7d33715f518893b0db",
        .manufacturer = "CBS Electronics, E.F. Dreyer, Ed Salvo",
        .model        = "4L 2738 0000",
        .name         = "Mountain King (1983) (CBS Electronics) [a]",
        .phosphor     = 1,
    },{
        .md5          = "7e52a95074a66640fcfde124fffd491a",
        .manufacturer = "Atari - GCC, Mike Feinstein, John Mracek",
        .model        = "CX2673",
        .name         = "Phoenix (1983) (Atari)",
    },{
        .md5          = "7e7c4c59d55494e66eef5e04ec1c6157",
        .manufacturer = "Baroque Gaming (Billy Eno)",
        .name         = "Warring Worms (2002) (Baroque Gaming)",
    },{
        .md5          = "7e8aa18bc9502eb57daaf5e7c1e94da7",
        .manufacturer = "CBS Electronics - Roklan, Joe Hellesen, Joe Wagner",
        .model        = "M8774, M8794",
        .name         = "Wizard of Wor (1982) (CBS Electronics)",
        .note         = "Uses the Joystick Controllers (swapped)",
        .swapPorts    = 1,
        .phosphor     = 1,
    },{
        .md5          = "7e9da5cb84d5bc869854938fe3e85ffa",
        .manufacturer = "Atari, Ian Shepard - Sears",
        .model        = "CX2604 - 6-99812, 49-75106",
        .name         = "Space War (1978) (Atari) (4K)",
    },{
        .md5          = "7e9f088e15b2af9ff3411991393e6b1f",
        .manufacturer = "Atari - Roklan, Joe Gaucher",
        .model        = "CX2679",
        .name         = "RealSports Basketball (12-28-1982) (Atari) (Prototype) (PAL)",
    },{
        .md5          = "7eab0284a0cd1043461d446a08d08cec",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Basic Math (Jone Yuan) (4K)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "7ead257e8b5a44cac538f5f54c7a0023",
        .manufacturer = "Xonox, Anthony R. Henderson",
        .model        = "99006, 6220",
        .name         = "Sir Lancelot (1983) (Xonox) [a1]",
    },{
        .md5          = "7eaf009a892f03d90682dc1e67e85f07",
        .manufacturer = "Fabrizio Zavagli",
        .name         = "Bounce! (18-03-2003) (Fabrizio Zavagli)",
        .phosphor     = 1,
    },{
        .md5          = "7eafc9827e8d5b1336905939e097aae7",
        .manufacturer = "Atari, Mark R. Hahn",
        .name         = "Elk Attack (1987) (Atari) (Prototype)",
    },{
        .md5          = "7eba20c2291a982214cc7cbe8d0b47cd",
        .manufacturer = "Imagic, Dave Johnson",
        .model        = "720119-1A, 03211",
        .name         = "Quick Step! (1983) (Imagic)",
    },{
        .md5          = "7ed61a18cebdeca0a93be1f5461731e5",
        .manufacturer = "Dactari",
        .name         = "Skiing (Dactari) (4K)",
    },{
        .md5          = "7ed7130a6e4020161836414332b11983",
        .name         = "Fu Kung! (V0.05 Cuttle Card Compatible) (13-01-2003) (Andrew Davie)",
    },{
        .md5          = "7edc8fcb319b3fb61cac87614afd4ffa",
        .manufacturer = "Activision, Alan Miller",
        .model        = "AG-003",
        .name         = "Checkers (1980) (Activision) (4K)",
    },{
        .md5          = "7ef3ca08abde439c6ccca84693839c57",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4302",
        .name         = "Party Mix (1983) (Arcadia) (PAL)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "7ef74879d7cb9fa0ef161b91ad55b3bb",
        .manufacturer = "CCE",
        .name         = "Vanguard (CCE)",
    },{
        .md5          = "7f0209cfcc3d181715463f4d6451cecf",
        .manufacturer = "Atari - GCC, John Allred, Douglas B. Macrae, Betty Ryan Tylko",
        .model        = "CX2694",
        .name         = "Pole Position (05-15-1983) (Atari) (Prototype)",
        .note         = "AKA RealSports Driving",
    },{
        .md5          = "7f07cd2e89dda5a3a90d3ab064bfd1f6",
        .manufacturer = "Videospielkassette - Ariola",
        .model        = "PGP234",
        .name         = "Boxen (Ariola) (PAL)",
        .note         = "AKA Boxing",
    },{
        .md5          = "7f430c33044e0354815392b53a9a772d",
        .manufacturer = "HES",
        .model        = "773-891",
        .name         = "2 Pak Special - Cavern Blaster, City War (1992) (HES) (PAL)",
    },{
        .md5          = "7f525b07bc98080cc8950f7284e52ede",
        .manufacturer = "Atari",
        .name         = "128 in 1 Junior Console (Chip 4 of 4) (1991) (Atari) (PAL)",
        .note         = "Actually contains only 16 games, not 32",
        .type         = "16IN1",
    },{
        .md5          = "7f54fa6aa824001af415503c313262f2",
        .manufacturer = "HES",
        .name         = "Boom Bang (HES) (PAL)",
        .note         = "AKA Crackpots",
    },{
        .md5          = "7f5da5dc44bb5e0b959507bb0ea31cd6",
        .manufacturer = "Parker Brothers - Roklan, Joe Gaucher",
        .model        = "PB5080",
        .name         = "Gyruss (1983) (Parker Bros) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "7f6533386644c7d6358f871666c86e79",
        .manufacturer = "CommaVid, Irwin Gaines",
        .model        = "CM-008",
        .name         = "Cakewalk (1983) (CommaVid)",
    },{
        .md5          = "7f790939f7eaa8c47a246c4283981f84",
        .name         = "This Planet Sucks Demo 3 (Greg Troutman) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "7f819454734ddf93f83fefcffcd3e212",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Outlaw (Jone Yuan) (4K)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "7f9fbe3e00a21ea06e6ae5e0e5db2143",
        .name         = "Skate Boardin' (2002) (Skyworks)",
    },{
        .md5          = "7fcd1766de75c614a3ccc31b25dd5b7a",
        .manufacturer = "PlayAround - J.H.M.",
        .model        = "203",
        .name         = "Knight on the Town (1982) (PlayAround)",
        .phosphor     = 1,
    },{
        .md5          = "7fcd5fb59e88fc7b8473c641f44226c3",
        .manufacturer = "CCE",
        .model        = "C-807",
        .name         = "Space Tunnel (1983) (CCE)",
        .note         = "AKA O Tunel Espacial",
    },{
        .md5          = "7ff53f6922708119e7bf478d7d618c86",
        .manufacturer = "Suntek",
        .model        = "SS-032",
        .name         = "Walker (1983) (Suntek) (PAL)",
        .note         = "AKA Guignol",
    },{
        .md5          = "7ffc2d80fd49a124808315306d19868e",
        .manufacturer = "Ishido",
        .name         = "Domino (Ishido) (PD)",
    },{
        .md5          = "801ba40f3290fc413e8c816c467c765c",
        .manufacturer = "Hozer Video Games",
        .name         = "Gunfight 2600 - Westward Ho! (2001) (Manuel Rotschkar)",
    },{
        .md5          = "803393ed29a9e9346569dd1bf209907b",
        .manufacturer = "Atari - GCC, Mark Ackerman, Tom Calderwood, Glenn Parker",
        .model        = "CX2684",
        .name         = "Galaxian (02-04-1983) (Atari) (Prototype)",
    },{
        .md5          = "804ed85eadf1ce3e93721547cbea7592",
        .manufacturer = "CCE",
        .name         = "Fishing Derby (CCE) (4K)",
    },{
        .md5          = "8055b9c2622136fd91edfea6df642daf",
        .manufacturer = "Activision",
        .name         = "Unknown Activision Game #1 (1983) (Activision) (Prototype) (PAL)",
    },{
        .md5          = "805f9a32ef97ac25f999a25014dc5c23",
        .manufacturer = "SnailSoft",
        .name         = "Balthazar (SnailSoft)",
        .note         = "AKA Babylon 5",
        .phosphor     = 1,
    },{
        .md5          = "8068e07b484dfd661158b3771d6621ca",
        .manufacturer = "Epyx, Steven A. Baker, Peter Engelbrite",
        .model        = "80561-00286",
        .name         = "California Games (1987) (Epyx) (PAL)",
    },{
        .md5          = "807841df228ee8aab0a06ee639ce5a8a",
        .manufacturer = "Coleco - Project Guild - GMA, Michael Green, Anthony R. Henderson, Gary Littleton",
        .model        = "2455",
        .name         = "Turbo (1982) (Coleco) (Prototype)",
        .note         = "Prototype",
    },{
        .md5          = "807a8ff6216b00d52aba2dfea5d8d860",
        .manufacturer = "John Payson",
        .name         = "Strat-O-Gems Deluxe (2005) (J. Payson)",
        .note         = "Uses the AtariVox controller",
        .right        = "ATARIVOX",
    },{
        .md5          = "808c3b1e60ee0e7c65205fa4bd772221",
        .manufacturer = "CCE",
        .name         = "Defender (CCE)",
    },{
        .md5          = "80cd42881e670e4b74a9ccd10d0d7b2e",
        .manufacturer = "20th Century Fox Video Games - Sirius, Ed Hodapp",
        .model        = "11004",
        .name         = "Deadly Duck (1982) (20th Century Fox) [a]",
    },{
        .md5          = "80cec82239913cb8c4016eb13749de44",
        .manufacturer = "David Marli",
        .name         = "Invaders from Space by David Marli (Space Invaders Hack)",
        .note         = "Hack of Space Invaders (Atari)",
    },{
        .md5          = "80dcbe1b55f12be731a224a53ee4ad5f",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Amidar (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "80e1410ec98089e0733cc09e584dba4b",
        .manufacturer = "Dynamics",
        .model        = "DY-293005",
        .name         = "Jumping Jack (1983) (Dynamics) (PAL)",
        .note         = "AKA Bobby Is Going Home",
    },{
        .md5          = "80e52315919bd8a8b82a407ccd9bb13f",
        .name         = "Euchre (Jul 28) (2002) (Eric Eid) (PD)",
    },{
        .md5          = "80e5400470ac788143e6db9bc8dd88cf",
        .manufacturer = "Coleco - Individeo, Ed Temple",
        .name         = "Cabbage Patch Kids (06-XX-1984) (Coleco) (Prototype)",
        .note         = "Adventures in the Park",
    },{
        .md5          = "80f7bf7418a462e8687ecefeaf6eb9c2",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Atari Trak-Ball Hack v1.3 (NTSC) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "8101efafcf0af32fedda4579c941e6f4",
        .name         = "Okie Dokie (4K) (PD)",
    },{
        .md5          = "81073d0377a2badef8d5e74fc44fc323",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Sadoom (Thomas Jentzsch) (PAL60) (Hack)",
        .note         = "Hack of Kaboom!",
    },{
        .md5          = "8108162bc88b5a14adc3e031cf4175ad",
        .manufacturer = "Suntek",
        .model        = "SS-030",
        .name         = "Skydiver (1983) (Suntek) (PAL)",
        .note         = "AKA Parachute",
    },{
        .md5          = "8108ad2679bd055afec0a35a1dca46a4",
        .name         = "Maze Craze (Unknown)",
        .format       = "NTSC",
    },{
        .md5          = "810d8952af5a6036fca8d0c4e1b23db6",
        .manufacturer = "Tiger Vision - Eram",
        .name         = "Keystone (Tiger Vision)",
        .note         = "AKA Keystone Kapers",
    },{
        .md5          = "81254ebce88fa46c4ff5a2f4d2bad538",
        .manufacturer = "Atari, David Crane - Sears",
        .model        = "CX2653 - 6-99823, 49-75111",
        .name         = "Slot Machine (1979) (Atari) (4K)",
    },{
        .md5          = "81341f00b61ab37d19d1529f483d496d",
        .name         = "Fu Kung! (V0.04) (10-01-2003) (Andrew Davie)",
    },{
        .md5          = "813985a940aa739cc28df19e0edd4722",
        .manufacturer = "Imagic, Bob Smith",
        .model        = "720000-201, 720102-1B, IA3201",
        .name         = "Star Voyager (1982) (Imagic)",
    },{
        .md5          = "81414174f1816d5c1e583af427ac89fc",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Treasure Below (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "814210c0e121f7dbc25661b93c06311c",
        .name         = "Joustpong (16-09-2002) (Kirk Israel) (PD)",
    },{
        .md5          = "81591a221419024060b890665beb0fb8",
        .manufacturer = "Atari, Carla Meninsky, Ed Riddle",
        .model        = "CX2611, CX2611P",
        .name         = "Indy 500 (1977) (Atari) (PAL)",
        .note         = "Uses the Driving Controllers",
        .left         = "DRIVING",
        .right        = "DRIVING",
    },{
        .md5          = "8190b403d67bf9792fe22fa5d22f3556",
        .name         = "Sky Diver (Unknown) (PAL) (Hack)",
    },{
        .md5          = "819aeeb9a2e11deb54e6de334f843894",
        .manufacturer = "Atari, Gary Palmer",
        .model        = "CX2661",
        .name         = "Fun with Numbers (1980) (Atari)",
        .note         = "AKA Basic Math",
    },{
        .md5          = "81a010abdba1a640f7adf7f84e13d307",
        .manufacturer = "Telegames - VSS",
        .model        = "7062 A305",
        .name         = "Universal Chaos (1988) (Telegames)",
        .note         = "AKA Targ",
    },{
        .md5          = "81b3bf17cf01039d311b4cd738ae608e",
        .manufacturer = "CBS Electronics - Roklan, Joe Gaucher, Dan Kurczewski, Alex Leavens, Kathy Von",
        .model        = "M8776, M8793",
        .name         = "Gorf (1982) (CBS Electronics)",
        .phosphor     = 1,
    },{
        .md5          = "81f4f0285f651399a12ff2e2f35bab77",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4200",
        .name         = "Escape from the Mindmaster (1982) (Arcadia)",
    },{
        .md5          = "822a950f27ff0122870558a89a49cad3",
        .name         = "Space Jockey (Unknown) (PAL) [a]",
    },{
        .md5          = "82337e5fe0f418ca9484ca851dfc226a",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Robot City (V1.0) (Alpha) (Thomas Jentzsch)",
    },{
        .md5          = "826481f6fc53ea47c9f272f7050eedf7",
        .manufacturer = "Imagic, Dennis Koble",
        .model        = "720103-1A, IA3203",
        .name         = "Atlantis II (1982) (Imagic)",
    },{
        .md5          = "827a22b9dffee24e93ed0df09ff8414a",
        .manufacturer = "CBS Electronics, Stuart Ross",
        .name         = "Wings (10-10-1983) (CBS Electronics) (Prototype) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "8290daea8391f96d7c8e1482e184d19c",
        .manufacturer = "Eckhard Stolberg",
        .name         = "Frame Timed Sound Effects (Eckhard Stolberg)",
    },{
        .md5          = "82bf0dff20cee6a1ed4bb834b00074e6",
        .manufacturer = "Suntek",
        .model        = "SS-035",
        .name         = "Panda (1983) (Quest) (Suntek) (PAL)",
        .note         = "AKA Panda Chase",
    },{
        .md5          = "82c25d1c35e6ac6f893d1d7c2fc2f9c8",
        .manufacturer = "Atari, Larry Kaplan",
        .model        = "CX2628, CX2628P",
        .name         = "Bowling (1979) (Atari) (PAL) (4K)",
    },{
        .md5          = "82c9b068826f7f57c6dc710606b3e8b5",
        .manufacturer = "Atari",
        .name         = "2 in 1 - Chess, Othello (Atari) (Prototype)",
    },{
        .md5          = "82d5ada7c61833d17ca0604eb1e3709f",
        .name         = "Q-bert (Unknown)",
    },{
        .md5          = "82de957d155fc041fc6afb8315a28550",
        .manufacturer = "Coleco, Joseph Biel",
        .model        = "2457",
        .name         = "Venture (1982) (Coleco) (Prototype)",
        .note         = "2K",
    },{
        .md5          = "82e7aab602c378cffdd8186a099e807e",
        .name         = "Space Robot (Unknown)",
    },{
        .md5          = "82ee056af81203af58092ff2e6cf079d",
        .manufacturer = "Oscar Toledo G., Thomas Jentzsch, Nathan Strum",
        .name         = "Aardvark (2019) (NTSC)",
        .phosphor     = 1,
    },{
        .md5          = "82efe7984783e23a7c55266a5125c68e",
        .manufacturer = "CCE",
        .model        = "C-837",
        .name         = "Pizza Chef (1983) (CCE)",
    },{
        .md5          = "834a2273e97aec3181ee127917b4b269",
        .manufacturer = "Quelle",
        .model        = "043.151 0, 874.382 5",
        .name         = "Die hungrigen Froesche (1983) (Quelle) (PAL)",
        .note         = "AKA Frogs and Flies",
    },{
        .md5          = "835759ff95c2cdc2324d7c1e7c5fa237",
        .manufacturer = "20th Century Fox Video Games, Frank Cohen, Douglas 'Dallas North' Neubauer",
        .model        = "11011",
        .name         = "M.A.S.H (1983) (20th Century Fox)",
    },{
        .md5          = "8372eec01a08c60dbed063c5524cdfb1",
        .name         = "Cross Force (Unknown) (PAL)",
    },{
        .md5          = "8388d6fe59c38c0b3a6ab2c58420036a",
        .manufacturer = "Atari, Frank Hausman, Mimi Nyden, Steve Woita",
        .model        = "CX2686",
        .name         = "Quadrun (12-06-1982) (Atari) (Prototype) (4K)",
    },{
        .md5          = "838e691e97d753d28320a932cf3fd6b3",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Three.s (2014) (Thomas Jentzsch)",
    },{
        .md5          = "83b8c01c72306d60dd9b753332ebd276",
        .name         = "Bank Heist (Unknown) (PAL) [a]",
    },{
        .md5          = "83bdc819980db99bf89a7f2ed6a2de59",
        .manufacturer = "Atari, Carla Meninsky - Sears",
        .model        = "CX2637 - 49-75158",
        .name         = "Dodge 'Em (1980) (Atari) [fixed]",
    },{
        .md5          = "83d15fb9843d9f84aa3710538403f434",
        .name         = "Gunfight 2600 - Release Candidate (2001) (Manuel Rotschkar) (PAL)",
    },{
        .md5          = "83e1b9f22f29259679e1018bc04cc018",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Fast Eddie (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "83f05ececae8be59ba1e51135f4bdcbf",
        .name         = "Demo Image Series #13 - Mario (4K Interleaved Chronocolour) (05-03-2003) (Andrew Davie)",
    },{
        .md5          = "83f50fa0fbae545e4b88bb53b788c341",
        .manufacturer = "Atari, Larry Kaplan - Sears",
        .model        = "CX2643 - 6-99815",
        .name         = "Codebreaker (1978) (Atari) (4K)",
        .note         = "Uses Keyboard Controllers",
    },{
        .md5          = "83fafd7bd12e3335166c6314b3bde528",
        .manufacturer = "Epyx, Steven A. Baker, Tod Frye, Peter Engelbrite",
        .model        = "80561-00251",
        .name         = "Winter Games (1987) (Epyx)",
    },{
        .md5          = "840a5a2eaea24d95d289f514fd12f9bb",
        .name         = "GBImprov (Hack)",
        .note         = "Hack of Ghostbusters",
    },{
        .md5          = "841057f83ce3731e6bbfda1707cbca58",
        .manufacturer = "Champ Games",
        .model        = "CG-04-N",
        .name         = "Super Cobra Arcade (NTSC)",
        .note         = "Compatible with Genesis controller",
        .left         = "JOYSTICK",
        .phosphor     = 1,
    },{
        .md5          = "841b7bc1cad05f5408302308777d49dc",
        .manufacturer = "Activision",
        .name         = "Unknown Activision Game (10-22-1982) (Activision) (Prototype)",
    },{
        .md5          = "84290e333ff7567c2380f179430083b8",
        .manufacturer = "Imagic, Dave Johnson",
        .model        = "13211, EIX-004-04I",
        .name         = "Quick Step! (1983) (Imagic) (PAL) [a]",
    },{
        .md5          = "843435eb360ed72085f7ab9374f9749a",
        .manufacturer = "Joe Grand",
        .name         = "SCSIcide (1.31) (Joe Grand)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXDR",
    },{
        .md5          = "84535afb9a69712ec0af4947329e08b8",
        .manufacturer = "CCE",
        .model        = "C-868",
        .name         = "Bingo (1983) (CCE) (PAL)",
        .note         = "AKA Dice Puzzle",
        .phosphor     = 1,
    },{
        .md5          = "8454ed9787c9d8211748ccddb673e920",
        .manufacturer = "Froggo",
        .model        = "FG1002",
        .name         = "Spiderdroid (1987) (Froggo)",
        .note         = "AKA Amidar",
    },{
        .md5          = "8490e1014c2baa0d3a3a08854e5d68b3",
        .manufacturer = "Xonox, Anthony R. Henderson",
        .model        = "99006, 6220",
        .name         = "Sir Lancelot (1983) (Xonox) [a2]",
    },{
        .md5          = "84db818cd4111542a15c2a795369a256",
        .manufacturer = "Arcadia Corporation, Steve Mundry, Scott Nelson",
        .model        = "AR-4401",
        .name         = "Survival Island (1983) (Arcadia) (PAL)",
    },{
        .md5          = "850ffd5849c911946b24544ea1e60496",
        .name         = "Invasion (07-10-2002) (Christopher Tumber)",
    },{
        .md5          = "851cc1f3c64eaedd10361ea26345acea",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-009, AG-009-04",
        .name         = "Freeway (1981) (Activision) (4K)",
    },{
        .md5          = "85227160f37aaa29f5e3a6c7a3219f54",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-004",
        .name         = "Fishing Derby (1980) (Activision) (4K)",
    },{
        .md5          = "8530caaaf40acbdcd118c282b5f8a37a",
        .name         = "This Planet Sucks Demo 2 (Greg Troutman) (PD)",
    },{
        .md5          = "8538c5e3ee83267774480649f83fa8d6",
        .name         = "Escape Demo (PD)",
    },{
        .md5          = "853c11c4d07050c22ef3e0721533e0c5",
        .name         = "Oink! (Unknown) (PAL)",
    },{
        .md5          = "85470dcb7989e5e856f36b962d815537",
        .manufacturer = "Atari - Sculptured Software, Inc., Steve Aguirre",
        .model        = "CX26162",
        .name         = "Fatal Run (1989) (Atari) (Prototype)",
    },{
        .md5          = "85478bb289dfa5c63726b9153992a920",
        .name         = "Candi (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "854b68b93e7123a3be42b5a2a41f75d7",
        .manufacturer = "Atari, Carol Shaw",
        .model        = "CX2618, CX2618P",
        .name         = "3-D Tic-Tac-Toe (1980) (Atari) (PAL) (4K)",
    },{
        .md5          = "85502d69fe46b7f54ef2598225678b47",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Super-Ferrari (Jone Yuan)",
        .note         = "AKA Enduro",
    },{
        .md5          = "85564dd0665aa0a1359037aef1a48d58",
        .manufacturer = "ITT Family Games",
        .model        = "554-33 367",
        .name         = "Laser Base (1983) (ITT Family Games) (PAL) [a]",
        .note         = "AKA The End of the World (Perry Rhodan-Serie)",
        .phosphor     = 1,
    },{
        .md5          = "8556b42aa05f94bc29ff39c39b11bff4",
        .manufacturer = "Atari, Craig Nelson - Sears",
        .model        = "CX2617 - 49-75183",
        .name         = "Backgammon (1979) (Atari)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXDR",
    },{
        .md5          = "855a42078b14714bcfd490d2cf57e68d",
        .manufacturer = "Atari, Dave Joly, Gary Shannon",
        .model        = "CX26113",
        .name         = "Miss Piggy's Wedding (1983) (Atari) (Prototype) (4K)",
    },{
        .md5          = "8597f66dd37d9c855663804669d69d7a",
        .manufacturer = "Tigervision, Warren Schwader",
        .model        = "7-003",
        .name         = "Threshold (1982) (Tigervision) (Prototype)",
    },{
        .md5          = "85a4133f6dcf4180e36e70ad0fca0921",
        .manufacturer = "CCE",
        .model        = "C-827",
        .name         = "Chopper Command (1983) (CCE)",
    },{
        .md5          = "85b1bca93e69f13905107cc802a02470",
        .manufacturer = "Atari, Craig Nelson",
        .model        = "CX2617, CX2617P",
        .name         = "Backgammon (1979) (Atari) (PAL)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXDR",
    },{
        .md5          = "85bbefb90e16bf386b304c1e9a1f6084",
        .manufacturer = "Champ Games",
        .model        = "CG-02-P",
        .name         = "Conquest Of Mars (PAL60)",
    },{
        .md5          = "85e48d68c8d802e3ba9d494a47d6e016",
        .name         = "Ship Demo (V 15) (PD)",
    },{
        .md5          = "85e564dae5687e431955056fbda10978",
        .manufacturer = "Milton Bradley Company - Renaissance Technology, Ty Roberts",
        .model        = "4362",
        .name         = "Survival Run (1983) (Milton Bradley)",
        .note         = "AKA Cosmic Commander",
        .phosphor     = 1,
    },{
        .md5          = "86128001e69ab049937f265911ce7e8a",
        .manufacturer = "Apollo - Games by Apollo, Steve Stringfellow",
        .model        = "AP-2005",
        .name         = "Lochjaw (1982) (Apollo)",
    },{
        .md5          = "8619da7f6796cedff59e5aa20712fb4e",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Sadistroids (v1.2) (2003) (Thomas Jentzsch)",
        .note         = "Supports Driving Controller in right port",
        .right        = "DRIVING",
        .phosphor     = 1,
    },{
        .md5          = "862cf669cbced78f9ed31a5d375b2ebe",
        .name         = "Gunfight 2600 - Flicker acceptance (2001) (Manuel Rotschkar)",
    },{
        .md5          = "8644352b806985efde499ae6fc7b0fec",
        .manufacturer = "CCE",
        .model        = "C-801",
        .name         = "Mr. Postman (1983) (CCE)",
    },{
        .md5          = "8654d7f0fb351960016e06646f639b02",
        .manufacturer = "Home Vision, R.J.P.G. - Gem International Corp. - VDI",
        .model        = "VCS83106",
        .name         = "Ski Hunt (1983) (Home Vision) (PAL)",
        .note         = "AKA Skiiing Hunt",
    },{
        .md5          = "866e5150c995c4ae5172e5207ba948c7",
        .manufacturer = "Canal 3 - Intellivision",
        .name         = "Stampede (Canal 3) (16K)",
    },{
        .md5          = "869abe0426e6e9fcb6d75a3c2d6e05d1",
        .name         = "Stampede (Unknown) (PAL)",
    },{
        .md5          = "86b4aa76bbeb70e1a4f9211a9880ba8e",
        .name         = "Incoming (1 Player Version) (05-11-2002) (Ben Larson)",
    },{
        .md5          = "8712cceec5644aacc2c21203d9ebe2ec",
        .manufacturer = "Retroactive",
        .name         = "Qb (V0.10) (NTSC) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "8726c17ee7b559cb7bf2330d20972ad0",
        .name         = "Cave Demo (21-04-2003) (Christopher Tumber)",
    },{
        .md5          = "873fb75a7788ba0f4ae715229a05545e",
        .name         = "Euchre (Improved Colors) (PAL) (26-09-2002) (Erik Eid)",
    },{
        .md5          = "8747ba79cd39fa83a529bb26010db21b",
        .manufacturer = "Atari, Richard Maurer",
        .model        = "CX2632, CX2632P",
        .name         = "Space Invaders (1980) (Atari) (PAL) [different speed and colors]",
    },{
        .md5          = "8749a0d088df25218c149dc325abc7ca",
        .manufacturer = "Commavid, Ben Burch",
        .model        = "CM-010",
        .name         = "Rush Hour (1983) (Commavid) (Prototype) [a5]",
    },{
        .md5          = "874c76726f68c166fcfac48ce78eef95",
        .name         = "Red Pong Number 2 Demo (PD)",
        .phosphor     = 1,
    },{
        .md5          = "8764462d7d19a33b0717af22b99fc88f",
        .manufacturer = "CCE",
        .name         = "Sky Jinks (CCE) (4K)",
    },{
        .md5          = "87662815bc4f3c3c86071dc994e3f30e",
        .manufacturer = "Intellivision Productions - M Network, Patricia Lewis Du Long, Stephen Tatsumi",
        .name         = "Swordfight (1983) (Intellivision)",
    },{
        .md5          = "876a953daae0e946620cf05ed41989f4",
        .manufacturer = "Retroactive",
        .name         = "Qb (V2.08) (PAL) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "877a5397f3f205bf6750398c98f33de1",
        .manufacturer = "Erik Eid",
        .name         = "Euchre (Beta) (PAL) (12-09-2002) (Erik Eid)",
    },{
        .md5          = "8786c1e56ef221d946c64f6b65b697e9",
        .manufacturer = "20th Century Fox Video Games, David Lubar",
        .model        = "11015",
        .name         = "AKA Space Adventure",
    },{
        .md5          = "8786f229b974c393222874f73a9f3206",
        .manufacturer = "Activision, Larry Miller - Ariola",
        .model        = "EAX-021, EAX-021-04I - 711 021-720",
        .name         = "Spider Fighter (1983) (Activision) (PAL)",
    },{
        .md5          = "8786f4609a66fbea2cd9aa48ca7aa11c",
        .manufacturer = "Goliath",
        .model        = "5",
        .name         = "Open Sesame (1983) (Goliath) (PAL)",
        .note         = "AKA Open, Sesame!",
        .phosphor     = 1,
    },{
        .md5          = "87b460df21b7bbcfc57b1c082c6794b0",
        .manufacturer = "Dennis Debro",
        .name         = "Climber 5 (20-03-2003) (Dennis Debro)",
    },{
        .md5          = "87b6a17132fc32f576bc49ea18729506",
        .manufacturer = "Atari, Andrew Fuchs, Courtney Granner, Jeffrey Gusman, Mark R. Hahn",
        .model        = "CX2690",
        .name         = "Pengo (1984) (Atari) (PAL)",
    },{
        .md5          = "87bea777a34278d29b3b6029833c5422",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Polaris (1983) (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "87e79cd41ce136fd4f72cc6e2c161bee",
        .manufacturer = "Atari - GCC, Mark Ackerman, Glenn Parker",
        .model        = "CX2675",
        .name         = "Ms. Pac-Man (1983) (Atari)",
    },{
        .md5          = "87f020daa98d0132e98e43db7d8fea7e",
        .manufacturer = "20th Century Fox Video Games - Sirius, David Lubar",
        .model        = "11001",
        .name         = "Worm War I (1982) (20th Century Fox)",
    },{
        .md5          = "883258dcd68cefc6cd4d40b1185116dc",
        .manufacturer = "Activision, David Crane - Ariola",
        .model        = "EAZ-030, EAZ-030-04B, EAZ-030-04I - 711 030-725",
        .name         = "Decathlon (1983) (Activision) (PAL)",
    },{
        .md5          = "8874b68751fd2ba6d3306a263ae57a7d",
        .manufacturer = "Eric Mooney",
        .name         = "Invaders by Erik Mooney (Alpha 1) (PD)",
    },{
        .md5          = "8885d0ce11c5b40c3a8a8d9ed28cefef",
        .manufacturer = "Atari, Carol Shaw, Nick 'Sandy Maiwald' Turner - Sears",
        .model        = "CX2608 - 49-75165",
        .name         = "Super Breakout (1982 - 1981) (Atari)",
        .note         = "Uses the Paddle Controllers (left only)",
    },{
        .md5          = "888debb162d7d1ae71025b4ab794257f",
        .name         = "Interleaved ChronoColour - Nude Art (17-04-2003) (Andrew Davie)",
    },{
        .md5          = "88a6c9c88cb329ee5fa7d168bd6c7c63",
        .manufacturer = "CCE",
        .model        = "C-1007",
        .name         = "Jungle Hunt (1983) (CCE)",
    },{
        .md5          = "88d300a38bdd7cab9edad271c18cd02b",
        .manufacturer = "Funvision - Fund. Int'l Co.",
        .name         = "Pac Kong (Funvision) (PAL)",
        .note         = "AKA Inca Gold",
    },{
        .md5          = "88d7b6b3967de0db24cdae1c7f7181bd",
        .manufacturer = "Atari - GCC, Dave Payne",
        .model        = "CX2669",
        .name         = "Vanguard (1982) (Atari) (Prototype)",
    },{
        .md5          = "88d8a1accab58cf1abb043613cf185e9",
        .manufacturer = "Bob Colbert",
        .name         = "Sabotage (Multi Demo) (Bob Colbert)",
    },{
        .md5          = "88dce4037471424bb38ab6841aaa8cab",
        .name         = "Double-Height 6-Digit Score Display (Two Background Color Change) (2001) (Andrew Davie)",
    },{
        .md5          = "88ed87c011f699dd27321dbe404db6c8",
        .manufacturer = "Activision, Dan Kitchen",
        .model        = "AX-029",
        .name         = "Crackpots (1983) (Activision) (16K)",
    },{
        .md5          = "88f74ec75ef696e7294b7b6ac5ca465f",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AG-002, CAG-002, AG-002-04",
        .name         = "Boxing (1980) (Activision) (16K)",
    },{
        .md5          = "8905d54f48b8024fc718ed643e9033f7",
        .manufacturer = "Coleco - Individeo, Ed Temple",
        .name         = "Cabbage Patch Kids (05-24-1984) (Coleco) (Prototype)",
        .note         = "Adventures in the Park",
    },{
        .md5          = "890c13590e0d8d5d6149737d930e4d95",
        .manufacturer = "Atari, David Crane - Sears",
        .model        = "CX2605 - 6-99822, 49-75109",
        .name         = "Outlaw (1978) (Atari)",
    },{
        .md5          = "8917f7c1ac5eb05b82331cf01c495af2",
        .manufacturer = "Bit Corporation",
        .model        = "PG202",
        .name         = "Space Tunnel (1982) (BitCorp) (PAL) [a]",
    },{
        .md5          = "8933976f2029c0d8492ebd8f4eb21492",
        .name         = "Synthcart Plus (09-02-2003) (Paul Slocum)",
        .note         = "Uses Keyboard Controllers",
    },{
        .md5          = "8953bc11352d794431d3303e31d3b892",
        .manufacturer = "Tigervision, Robert H. O'Neil",
        .model        = "7-007",
        .name         = "Polaris (02-17-1983) (Tigervision) (Prototype) (4K)",
    },{
        .md5          = "896ec58f26e930e02f5e4f046602c3a1",
        .name         = "Synthcart (Beta) (2002) (Paul Slocum)",
        .note         = "Uses Keyboard Controllers",
        .phosphor     = 1,
    },{
        .md5          = "898143773824663efe88d0a3a0bb1ba4",
        .manufacturer = "Activision - Woodside Design Associates, Steve 'Jessica Stevens' Kitchen",
        .model        = "AZ-033, AZ-033-04",
        .name         = "Space Shuttle (1983) (Activision) [FE]",
        .note         = "A Journey Into Space",
    },{
        .md5          = "898748d5eaac3164b0391a64ae1e0e32",
        .name         = "Hangman Man 4letter (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "898b5467551d32af48a604802407b6e8",
        .manufacturer = "Bit Corporation",
        .model        = "PG208",
        .name         = "Snail Against Squirrel (1983) (BitCorp) (PAL)",
    },{
        .md5          = "89a65b83203980d5d4d60f52a584a5b8",
        .name         = "Marble Craze (PAL) (02-02-2003) (Paul Slocum)",
    },{
        .md5          = "89a68746eff7f266bbf08de2483abe55",
        .manufacturer = "Atari, Jerome Domurat, Steve Woita",
        .model        = "CX2696",
        .name         = "Asterix (1984) (Atari)",
        .note         = "AKA Taz",
    },{
        .md5          = "89afff4a10807093c105740c73e9b544",
        .name         = "Pooyan (Unknown) (PAL)",
    },{
        .md5          = "89eaba47a59cbfd26e74aad32f553cd7",
        .manufacturer = "Apollo - Games by Apollo, Ed Salvo, Byron Parks",
        .model        = "AP-2001",
        .name         = "Spacechase (1982) (Apollo) (PAL)",
        .note         = "AKA Space Attack",
    },{
        .md5          = "8a159ee58b2f0a54805162984b0f07e5",
        .manufacturer = "Atari - Sculptured Software, Inc., Steve Aguirre",
        .model        = "CX26162",
        .name         = "Fatal Run (1989) (Atari) (PAL) [a]",
    },{
        .md5          = "8a183b6357987db5170c5cf9f4a113e5",
        .manufacturer = "Atari - Roklan, Joe Gaucher",
        .model        = "CX2679",
        .name         = "RealSports Basketball (01-11-1983) (Atari) (Prototype) (PAL)",
    },{
        .md5          = "8a42e2c7266439d8997a55d0124c912c",
        .name         = "Hangman Invader Wordlist (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "8a49cf1785e3dea2012d331a3ad476e1",
        .name         = "Boulderdash (10 Blocks Wide) (02-04-2003) (Andrew Davie)",
    },{
        .md5          = "8a6c84f481acf42abcb78ba5064ad755",
        .manufacturer = "128 in 1 Junior Console",
        .name         = "Street Racer (128 in 1 Junior Console) (PAL) (4K)",
        .note         = "Uses the Paddle Controllers (swapped)",
        .swapPaddles  = 1,
    },{
        .md5          = "8a8e401369e2b63a13e18a4d685387c6",
        .manufacturer = "Activision, David Crane - Ariola",
        .model        = "EAG-008, PAG-008, EAG-008-04I - 711 008-720",
        .name         = "Laser Blast (1981) (Activision) (PAL)",
    },{
        .md5          = "8a9d874a38608964f33ec0c35cab618d",
        .manufacturer = "Chris Cracknell",
        .name         = "Rescue Bira Bira (Chris Cracknell)",
        .note         = "Hack of Jungle Fever",
        .phosphor     = 1,
    },{
        .md5          = "8a9d953ac3db52a313a90d6a9b139c76",
        .name         = "Hangman Invader Biglist3 (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "8aad33da907bed78b76b87fceaa838c1",
        .manufacturer = "Atari, Larry Kaplan",
        .model        = "CX26163P",
        .name         = "Air-Sea Battle (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "8ac18076d01a6b63acf6e2cab4968940",
        .manufacturer = "Atari, Dan Hitchens, Mimi Nyden",
        .model        = "CX2685",
        .name         = "Gravitar (1983) (Atari)",
    },{
        .md5          = "8ad3b8e7436816db03e7824406bdc670",
        .manufacturer = "Edu Games - Edu Juegos",
        .name         = "Galaxian (Edu Games) (PAL)",
    },{
        .md5          = "8af58a9b90b25907da0251ec0facf3b8",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Cosmic Swarm (Jone Yuan)",
        .note         = "2600 Screen Search Console",
        .phosphor     = 1,
    },{
        .md5          = "8b04e9d132b8e30d447acaa6bd049c32",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum",
        .model        = "AR-4400",
        .name         = "Dragonstomper (1982) (Starpath) (PAL)",
    },{
        .md5          = "8b40a9ca1cfcd14822e2547eaa9df5c1",
        .manufacturer = "Parker Brothers - Western Technologies, Dave Hampton, Tom Sloper",
        .model        = "931517",
        .name         = "Q-bert (1983) (Parker Bros) (PAL)",
    },{
        .md5          = "8b504b417c8626167a7e02f44229f0e7",
        .manufacturer = "Retroactive",
        .name         = "Qb (V1.00) (NTSC) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "8b556c3d9ca8e5e6e665bd759b93ffae",
        .name         = "Synthcart (2002) (Paul Slocum) (PAL) [!]",
        .note         = "Uses Keyboard Controllers",
        .phosphor     = 1,
    },{
        .md5          = "8b5b1e3a434ebbdc2c2a49dc68f46360",
        .manufacturer = "CBS Electronics - Woodside Design Associates - Imaginative Systems Software, Garry Kitchen",
        .model        = "4L1700, 4L1701, 4L1702, 4L1802, 4L2274",
        .name         = "Donkey Kong (1983) (CBS Electronics) (PAL)",
    },{
        .md5          = "8b7ca29a55432f886cee3d452fb00481",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum, Jon Leupp",
        .model        = "11 AR-4201",
        .name         = "Sword of Saros (1983) (Starpath) (PAL)",
    },{
        .md5          = "8b8152d6081f31365406cb716bd95567",
        .manufacturer = "Atari",
        .model        = "CX2626, CX2626P",
        .name         = "Miniature Golf (1979) (Atari) (PAL) (4K)",
    },{
        .md5          = "8b8789c6669a4cee86c579a65332f852",
        .manufacturer = "Digivision",
        .name         = "Plaque Attack (Digivision)",
    },{
        .md5          = "8bb5030d015194435c3f01f220f23977",
        .manufacturer = "Apollo - Games by Apollo",
        .model        = "AP-2006",
        .name         = "Infiltrate (1982) (Apollo) (Prototype) [a]",
    },{
        .md5          = "8bbfd951c89cc09c148bfabdefa08bec",
        .manufacturer = "UA Limited",
        .name         = "Pleiades (1983) (UA Limited) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "8bc0d2052b4f259e7a50a7c771b45241",
        .manufacturer = "Xonox - K-Tel Software, Anthony R. Henderson",
        .model        = "99007, 6240",
        .name         = "Tomarc the Barbarian (1983) (Xonox) [a]",
        .note         = "AKA Thundarr the Barbarian",
    },{
        .md5          = "8bd8f65377023bdb7c5fcf46ddda5d31",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AG-019",
        .name         = "Sky Jinks (1982) (Activision) (4K)",
    },{
        .md5          = "8bebac614571135933116045204f0f00",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Command (Trakball) (2002) (Thomas Jentzsch) (PAL)",
        .note         = "Uses the Trakball Controller",
        .left         = "TRAKBALL",
        .right        = "TRAKBALL",
        .phosphor     = 1,
    },{
        .md5          = "8c103a79b007a2fd5af602334937b4e1",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Laser Base (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "8c136e97c0a4af66da4a249561ed17db",
        .name         = "Poker Squares (V0.27) (2001) (B. Watson)",
    },{
        .md5          = "8c146c61817edd376bc1354c7f1ddc63",
        .manufacturer = "Omegamatrix",
        .name         = "Star Wars Arcade (Amiga Mouse) (Y Inverted) (PAL60) v4 (Omegamatrix)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "8c1cc284edba691139d6626d062c606f",
        .manufacturer = "Atari, Omegamatrix",
        .name         = "Super Breakout Menu (2020) (PAL60) (Hack)",
        .note         = "Hack of Super Breakout",
    },{
        .md5          = "8c2fa33048f055f38358d51eefe417db",
        .manufacturer = "Home Vision - Gem International Corp. - VDI",
        .model        = "VCS83137",
        .name         = "Teddy Apple (1983) (Home Vision) (PAL)",
        .note         = "AKA Open, Sesame!",
        .phosphor     = 1,
    },{
        .md5          = "8c36ed2352801031516695d1eeefe617",
        .manufacturer = "Epyx, Steven A. Baker, Tod Frye, Peter Engelbrite",
        .model        = "80561-00251",
        .name         = "Winter Games (1987) (Epyx) (PAL)",
    },{
        .md5          = "8c7e5e2329f4f4e06cbcc994a30fd352",
        .manufacturer = "Data Age",
        .model        = "DA1004",
        .name         = "Airlock (1982) (Data Age) (Prototype)",
    },{
        .md5          = "8c8a26ed57870daba8e13162d497bad1",
        .manufacturer = "HES",
        .name         = "2 Pak Special - Dolphin, Oink (1990) (HES) (PAL)",
    },{
        .md5          = "8c8b15b3259e60757987ed13cdd74d41",
        .manufacturer = "Supergame",
        .model        = "71",
        .name         = "River Raid (1984) (Supergame)",
    },{
        .md5          = "8c941fa32c7718a10061d8c328909577",
        .manufacturer = "Digivision",
        .name         = "River Raid (Digivision)",
    },{
        .md5          = "8ccaa442d26b09139685f5b22bf189c4",
        .manufacturer = "Retroactive",
        .name         = "Qb (V1.01) (NTSC) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "8ccf63141a029603572d1056e772990e",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Amiga Mouse Hack v1.4 (NTSC) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "8cd26dcf249456fe4aeb8db42d49df74",
        .manufacturer = "Atari - Imagineering, Dan Kichen",
        .model        = "CX26139",
        .name         = "Crossbow (1988) (Atari)",
    },{
        .md5          = "8ce9126066f2ddd5173e9f1f9ce1494e",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Command (Trakball) (2002) (Thomas Jentzsch)",
        .note         = "Uses the Trakball Controller",
        .left         = "TRAKBALL",
        .right        = "TRAKBALL",
        .phosphor     = 1,
    },{
        .md5          = "8cf0d333bbe85b9549b1e6b1e2390b8d",
        .manufacturer = "Atari, Brad Stewart",
        .model        = "CX2649, CX2649P",
        .name         = "Asteroids (1981) (Atari) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "8d00a38f4c8f8800f1c237215ac243fc",
        .name         = "3-D Corridor (Green) (30-03-2003) (Andrew Davie)",
    },{
        .md5          = "8d1e2a6d2885966e6d86717180938f87",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Command (Amiga Mouse) (2002) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
        .phosphor     = 1,
    },{
        .md5          = "8d2a818e0255c66040802defe32c341a",
        .manufacturer = "Fotomania",
        .name         = "Fast Food (Fotomania)",
    },{
        .md5          = "8d8b7d7b983f75debbdaac651e814768",
        .name         = "Demo Image Series #15 - Three Marios (PAL) (06-03-2003) (Andrew Davie)",
    },{
        .md5          = "8d9a06101ebb0f147936356e645309b8",
        .name         = "Grid Pattern Demo 2 (20-12-2002) (Christopher Tumber)",
    },{
        .md5          = "8da51e0c4b6b46f7619425119c7d018e",
        .manufacturer = "Atari - Imagineering, David Lubar",
        .model        = "CX26183",
        .name         = "Sentinel (1991) (Atari)",
        .note         = "Uses the Light Gun Controller (left only)",
    },{
        .md5          = "8db152458abaef3cfa7a4e420ddbda59",
        .name         = "Keystone Kapers (Unknown)",
    },{
        .md5          = "8dda212b5d92a3b21812890b472f0e7a",
        .manufacturer = "Artkaris Software",
        .name         = "Ms Pac-Man (1986) (Artkaris) (PAL)",
        .note         = "AKA Ms. Pac-Man",
    },{
        .md5          = "8df4be9ddc54ac363b13dc57ceaf161a",
        .manufacturer = "Scott Stilphen",
        .name         = "Asteroids SS (Scott Stilphen) (Hack)",
        .note         = "Hack of Asteroids",
        .phosphor     = 1,
    },{
        .md5          = "8e0ab801b1705a740b476b7f588c6d16",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-009, AG-009-04",
        .name         = "Freeway (1981) (Activision)",
    },{
        .md5          = "8e42674972d6805068fc653e014370fd",
        .name         = "Skeleton (PAL) (15-10-2002) (Eric Ball)",
    },{
        .md5          = "8e48ea6ea53709b98e6f4bd8aa018908",
        .manufacturer = "CBS Electronics, Stuart Ross",
        .name         = "Wings (06-03-1983) (CBS Electronics) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "8e4cd60d93fcde8065c1a2b972a26377",
        .manufacturer = "Imagic, Dan Oliver",
        .model        = "720118-2A, 13208, EIX-007-04I",
        .name         = "Laser Gates (1983) (Imagic) (PAL)",
        .note         = "AKA Innerspace",
    },{
        .md5          = "8e4fa8c6ad8d8dce0db8c991c166cdaa",
        .manufacturer = "Atari, Bill Aspromonte, Dave Joly, John Russell, Michael Sierchio, Robert Zdybel",
        .model        = "CX26114",
        .name         = "Pigs in Space (1983) (Atari)",
        .note         = "Starring Miss Piggy",
    },{
        .md5          = "8e512ad4506800458f99dec084fc2c64",
        .manufacturer = "Bob Montgomery, Nathan Strum",
        .name         = "Reindeer Rescue (2005)",
        .note         = "2005 AtariAge Holiday Cart",
    },{
        .md5          = "8e7241bfc8380aac3c0ef1b6881cdded",
        .manufacturer = "Atari, Howard Scott Warshaw - Sears",
        .model        = "CX2655 - 49-75167",
        .name         = "Yars' Revenge (09-01-81) (Atari) (Prototype)",
        .note         = "Time Freeze",
        .phosphor     = 1,
    },{
        .md5          = "8e737a88a566cc94bd50174c2d019593",
        .manufacturer = "Quelle",
        .model        = "343.173 1",
        .name         = "Feuerwehr im Einsatz (1983) (Quelle) (PAL)",
        .note         = "AKA Fire Fighter",
    },{
        .md5          = "8e822b39a71c84ac875f0107fb61d6f0",
        .name         = "Hangman Ghost Original Words (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "8e879aa58db41edb67cbf318b77766c4",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Cosmic Commuter (Thomas Jentzsch) (PAL60)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "8e887d1ba5f3a71ae8a0ea16a4af9fc9",
        .name         = "Skeleton (V1.1) (PAL) (24-10-2002) (Eric Ball)",
    },{
        .md5          = "8ed5a746c59571feb255eaa7d6d0cf98",
        .name         = "Carnival (Unknown) (PAL) (Hack)",
    },{
        .md5          = "8ed73106e2f42f91447fb90b6f0ea4a4",
        .manufacturer = "Spectravision - Spectravideo",
        .model        = "SA-204",
        .name         = "Tapeworm (1982) (Spectravision) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "8ee3f64dc0f349adc893fe93df5245d8",
        .name         = "Euchre (20-07-2001) (Eric Eid) (PD)",
    },{
        .md5          = "8ef96ace4a1d6dfb65926c1e868b0188",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Amiga Mouse Hack v1.3 (PAL60) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "8f08c777b424c3085eece73774335962",
        .manufacturer = "Dactari - Milmar",
        .name         = "Cosmic Ark (Dactari)",
    },{
        .md5          = "8f33bce5ba1053dcf4cea9c1c69981e4",
        .name         = "Jawbreaker (Unknown) (PAL) [a]",
    },{
        .md5          = "8f53a3b925f0fd961d9b8c4d46ee6755",
        .name         = "Astrowar (Unknown)",
    },{
        .md5          = "8f5ac5139419c5d49bacc296e342a247",
        .manufacturer = "Atari - CCW, Michael Callahan, Preston Stuart",
        .model        = "CX26103",
        .name         = "Alpha Beam with Ernie (12-22-1982) (Atari) (Prototype)",
        .note         = "Uses Keyboard Controllers",
    },{
        .md5          = "8f60551db6d1535ef0030f155018c738",
        .name         = "Space War (Unknown) (PAL) (4K)",
    },{
        .md5          = "8f613ea7c32a587d6741790e32872ddd",
        .name         = "Troll Demo (PD)",
    },{
        .md5          = "8f88309afad108936ca70f8b2b084718",
        .manufacturer = "Spectravision - Spectravideo - Quelle",
        .model        = "SA-203 - 413.223 9",
        .name         = "Cross Force (1982) (Spectravision) (PAL)",
        .note         = "AKA Kreuzfeuer (Cross Fire)",
    },{
        .md5          = "8f90590dba143d783df5a6cff2000e4d",
        .name         = "Gopher (Unknown) (PAL)",
    },{
        .md5          = "8f98519a91dbbf4864f135a10050d9ed",
        .manufacturer = "Silvio Mogno",
        .name         = "Rainbow Invaders (non-playable demo) (PD)",
    },{
        .md5          = "8fa47e5242776e841df7e708b12eb998",
        .name         = "Sea Hawk (Genesis)",
        .note         = "Genesis controller (C drops bomb)",
    },{
        .md5          = "8fbabaa87941cdf3a377c15e95bdb0f3",
        .name         = "Meteor Smasher (SnailSoft)",
    },{
        .md5          = "8fe00172e7fff4c1878dabcf11bb8dce",
        .manufacturer = "Quelle",
        .model        = "689.302 8",
        .name         = "Hili Ball (1983) (Quelle) (PAL)",
        .note         = "AKA Racquetball",
        .phosphor     = 1,
    },{
        .md5          = "8febdd9142960d084ab6eeb1d3e88969",
        .manufacturer = "Atari, Jerome Domurat, Howard Scott Warshaw",
        .model        = "CX2674",
        .name         = "E.T. - The Extra-Terrestrial (1982) (Atari) (PAL)",
    },{
        .md5          = "8fffc8f15bb2e6d24e211884a5479aa5",
        .manufacturer = "Retroactive",
        .name         = "Qb (V1.00) (PAL) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "9007c3cbb55ce05ad7d1c34d4906750a",
        .manufacturer = "Activision, David Crane",
        .model        = "AX-018, AX-018-04",
        .name         = "Pitfall! (03-18-1983) (Activision) (Prototype)",
        .note         = "Pitfall Harry's Jungle Adventure (Jungle Runner)",
    },{
        .md5          = "9048ccb7e0802cd8fa5bfc2609f292d8",
        .manufacturer = "Tigervision, Robert H. O'Neil",
        .model        = "7-007",
        .name         = "Polaris (1983) (Tigervision) (Prototype)",
    },{
        .md5          = "9057694dce8449521e6164d263702185",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AG-011",
        .name         = "Stampede (1981) (Activision) (16K)",
    },{
        .md5          = "90578a63441de4520be5324e8f015352",
        .manufacturer = "Bit Corporation",
        .model        = "PGP204",
        .name         = "Open Sesame (4 Game in One) (1983) (BitCorp) (PAL)",
        .note         = "AKA Open, Sesame!",
        .phosphor     = 1,
    },{
        .md5          = "9072c142728a3a3d994956d03bfacba2",
        .manufacturer = "Fabrizio Zavagli",
        .name         = "Crash Dive (Fabrizio Zavagli) (PAL60)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "90a3c3255f2a54225cdcb50831f8793a",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Challenge of... Nexar, The - Atari Trak-Ball Hack v1.1 (PAL) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "90b1799dddb8bf748ee286d22e609480",
        .name         = "Ship Demo (PD)",
    },{
        .md5          = "90b647bfb6b18af35fcf613573ad2eec",
        .manufacturer = "AtariAge (Chris Walton)",
        .name         = "Juno First (2009)",
        .note         = "AtariVox supported",
        .right        = "ATARIVOX",
        .phosphor     = 1,
    },{
        .md5          = "90ccf4f30a5ad8c801090b388ddd5613",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum",
        .model        = "AR-4400",
        .name         = "Dragonstomper (1982) (Starpath)",
    },{
        .md5          = "90d77e966793754ab4312c47b42900b1",
        .manufacturer = "Imagic, Brad Stewart",
        .model        = "720105-2A, IA3400P, EIX-005-04I",
        .name         = "Fire Fighter (1982) (Imagic) (PAL)",
    },{
        .md5          = "90f502cbf4438a95f69f848cef36eb64",
        .manufacturer = "Digitel",
        .name         = "River Raid II (1985) (Digitel)",
        .note         = "AKA River Raid",
    },{
        .md5          = "910dd9bf98cc5bc080943e5128b15bf5",
        .name         = "Gunfight 2600 - Improved AI (Manuel Rotschkar)",
    },{
        .md5          = "911d385ee0805ff5b8f96c5a63da7de5",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Jammed (V0.1) (Demo) (2001) (Thomas Jentzsch)",
    },{
        .md5          = "913d5d959b5021f879033c89797bab5e",
        .name         = "Robot Player Graphic (1996) (J.V. Matthews) (PD)",
    },{
        .md5          = "914a8feaf6d0a1bbed9eb61d33817679",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Freeway Chicken (32 in 1) (1988) (Atari) (PAL)",
        .note         = "AKA Freeway",
    },{
        .md5          = "91925abce3a29e33b6a8b81482f4f5af",
        .manufacturer = "Activision, Garry Kitchen - Ariola",
        .model        = "EAX-025, EAX-025-04I - 711 025-725",
        .name         = "Keystone Kapers (1983) (Activision) (PAL) (8K)",
    },{
        .md5          = "9193b6fff6897d43274741d4f9855b6d",
        .name         = "M.A.S.H (Unknown) (PAL) (Hack)",
    },{
        .md5          = "91a3749ff7b7e72b7fa09e05396a0e7b",
        .name         = "Gunfight 2600 - Final Run Part 2 (2002) (Manuel Rotschkar)",
    },{
        .md5          = "91b007f33f9b790be64f57220ec52e80",
        .manufacturer = "Jone Yuan Telephonic Enterprise",
        .name         = "Laser Blast (Jone Yuan) (Hack)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "91c2098e88a6b13f977af8c003e0bca5",
        .manufacturer = "Atari - GCC",
        .model        = "CX2676",
        .name         = "Centipede (1983) (Atari)",
    },{
        .md5          = "91d1c82ceaf8af2add3973a3c34bc0cb",
        .name         = "Starfield Demo 1 (20-12-2002) (Christopher Tumber)",
    },{
        .md5          = "91f0a708eeb93c133e9672ad2c8e0429",
        .name         = "Oystron (V2.9) (Piero Cavina) (PD)",
    },{
        .md5          = "91fdb6541f70c40b16aabf8308123be8",
        .name         = "Interlacing Game (19-08-2002) (Billy Eno)",
    },{
        .md5          = "9222b25a0875022b412e8da37e7f6887",
        .manufacturer = "Panda",
        .model        = "106",
        .name         = "Dice Puzzle (1983) (Panda)",
        .phosphor     = 1,
    },{
        .md5          = "9245a84e9851565d565cb6c9fac5802b",
        .manufacturer = "Bomb - Onbase",
        .model        = "CA282",
        .name         = "Great Escape (1983) (Bomb)",
        .note         = "AKA Asteroid Fire",
    },{
        .md5          = "927d422d6335018da469a9a07cd80390",
        .manufacturer = "Activision, Carol Shaw - Ariola",
        .model        = "EAX-020, EAX-020-04B, EAX-020-04I - 711 020-720",
        .name         = "River Raid (1982) (Activision) (PAL)",
    },{
        .md5          = "9281eccd7f6ef4b3ebdcfd2204c9763a",
        .manufacturer = "Retroactive",
        .name         = "Qb (2.15) (Retroactive) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "9295570a141cdec18074c55dc7229d08",
        .manufacturer = "Telegames",
        .model        = "7045 A015",
        .name         = "Bump 'n' Jump (1988) (Telegames) (PAL)",
    },{
        .md5          = "929e8a84ed50601d9af8c49b0425c7ea",
        .manufacturer = "Bit Corporation",
        .model        = "PG205",
        .name         = "Dancing Plate (1982) (BitCorp) (PAL)",
        .note         = "AKA Dishaster, Dancing Plates, Tanzende Teller",
        .phosphor     = 1,
    },{
        .md5          = "92a1a605b7ad56d863a56373a866761b",
        .manufacturer = "U.S. Games Corporation - Western Technologies, Dave Hampton",
        .model        = "VC2006",
        .name         = "Raft Rider (1983) (U.S. Games)",
    },{
        .md5          = "92d1b6cb8a1b615266c4088a58464779",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Fishing Derby (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "92d1f6ac179ebe5963868d6bc1bdda8d",
        .manufacturer = "HES",
        .model        = "498",
        .name         = "Smash Hit Pak - Frogger, Boxing, Seaquest, Skiing, Stampede (HES) (PAL)",
    },{
        .md5          = "92e72f7cc569584c44c9530d645ae04e",
        .manufacturer = "Canal 3 - Intellivision",
        .name         = "Spider Fighter (Canal 3)",
    },{
        .md5          = "93096a1038cd558ed0b48741bbf17c64",
        .manufacturer = "Fotomania",
        .name         = "Pac-Man (Fotomania)",
    },{
        .md5          = "931b91a8ea2d39fe4dca1a23832b591a",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-008",
        .name         = "Laser Blast (1981) (Activision)",
    },{
        .md5          = "9333172e3c4992ecf548d3ac1f2553eb",
        .manufacturer = "Konami",
        .model        = "RC 101-X 02",
        .name         = "Strategy X (1983) (Konami)",
    },{
        .md5          = "93420cc4cb1af1f2175c63e52ec18332",
        .manufacturer = "Tim Snider",
        .name         = "Blair Witch Project (Tim Snider) (Hack)",
        .note         = "Hack of Haunted House",
    },{
        .md5          = "9364ad51c321e0f15c96a8c0aff47ceb",
        .manufacturer = "Atari, Rob Fulop",
        .model        = "CX2638",
        .name         = "Missile Command (1981) (Atari) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "936ef1d6f8a57b9ff575dc195ee36b80",
        .name         = "Pac Kong (Unknown) [a]",
        .note         = "AKA Inca Gold",
    },{
        .md5          = "936f555b4b1a2cd061b659ff63f4f5f2",
        .manufacturer = "HES, David Lubar",
        .model        = "535",
        .name         = "My Golf (1990) (HES) (PAL) [a1]",
    },{
        .md5          = "937736d899337036de818391a87271e0",
        .manufacturer = "Atari, Dave Joly, Suki Lee",
        .model        = "CX26108",
        .name         = "Donald Duck's Speedboat (04-12-1983) (Atari) (Prototype)",
        .note         = "AKA Donald Duck's Sailboat Regatta",
    },{
        .md5          = "939ce554f5c0e74cc6e4e62810ec2111",
        .manufacturer = "ZiMAG - Emag - Vidco",
        .model        = "711-111 - GN-020",
        .name         = "Dishaster (1983) (ZiMAG)",
        .note         = "AKA Dancing Plate",
        .phosphor     = 1,
    },{
        .md5          = "93acd5020ae8eb5673601e2edecbc158",
        .manufacturer = "Chris Cracknell",
        .name         = "Video Time Machine (Chris Cracknell)",
    },{
        .md5          = "93b9229fc0ea4fb959d604f83f8f603c",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Amidar DS (Fast Enemies) (2003) (Thomas Jentzsch) (Hack)",
        .note         = "Hack of Amidar",
    },{
        .md5          = "93c4b910f7649b3e998bb6d8527c6f4a",
        .manufacturer = "Sparrow - Enter-Tech, Paul Walters, Rick Harris, George Hefner, Barbara Ultis",
        .name         = "Arkyology (1983) (Sparrow) (Prototype) [fixed]",
        .note         = "Fix for un-initialized 'X' register",
    },{
        .md5          = "93c52141d3c4e1b5574d072f1afde6cd",
        .manufacturer = "Imagic, Mark Klein",
        .model        = "720112-1A, 03213",
        .name         = "Subterranea (1983) (Imagic)",
    },{
        .md5          = "93c8d9d24f9c5f1f570694848d087df7",
        .manufacturer = "Digivision",
        .name         = "Galaxian (Digivision)",
    },{
        .md5          = "93c9f9239a4e5c956663dd7affa70da2",
        .manufacturer = "Quelle",
        .model        = "626.610 0",
        .name         = "Billard (1983) (Quelle) (PAL)",
        .note         = "AKA Trick Shot",
        .phosphor     = 1,
    },{
        .md5          = "93db185c3b3dc382f3aecd6a2fea7fd9",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Challenge of... Nexar, The - Atari Trak-Ball Hack v1.1 (PAL60) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "93dc15d15e77a7b23162467f95a5f22d",
        .manufacturer = "CCE",
        .name         = "Sky Jinks (CCE)",
    },{
        .md5          = "93e276172b521c4491097f8b1393eea7",
        .manufacturer = "Atari",
        .name         = "Diagnostic Test Cartridge 4.2 (06-01-1982) (Atari)",
    },{
        .md5          = "93eb1795c8b1065b1b3d62bb9ec0ccdc",
        .manufacturer = "JSK",
        .name         = "Custer's Viagra (JSK) (Hack)",
        .note         = "Hack of Custer's Revenge",
    },{
        .md5          = "94102febc53b4a78342d11b645342ed4",
        .name         = "Joustpong (14-07-2002) (Kirk Israel) (PD)",
    },{
        .md5          = "9433770890f087bfcf3e50122694d8c0",
        .manufacturer = "Omegamatrix",
        .name         = "Star Wars Arcade (Amiga Mouse) (Y Inverted) v4 (Omegamatrix)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "9436b7ad131b5a1f7753ce4309ba3dee",
        .manufacturer = "Kyle Pittman",
        .name         = "War of The Worlds (Kyle Pittman) (Hack)",
        .note         = "Hack of Defender",
    },{
        .md5          = "943798452ceba9357e2c56303cadb4f7",
        .manufacturer = "Thomas Jentzsch, Paul Slocum",
        .name         = "Thrust+ Platinum (v1.28)",
        .note         = "Also supports BoosterGrip/Genesis (switched by Color/B+W)",
        .left         = "JOYSTICK",
        .right        = "DRIVING",
    },{
        .md5          = "9446940866c9417f210f8552cf6c3078",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Marble Craze - Amiga Mouse Hack v1.0 (PAL60) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controllers",
    },{
        .md5          = "94507dee401b0a072a481c00d7699ffe",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Control - Atari Trak-Ball Hack v1.15 (PAL) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "9469d18238345d87768e8965f9f4a6b2",
        .manufacturer = "CCE",
        .name         = "Ms. Pac-Man (CCE)",
    },{
        .md5          = "947317a89af38a49c4864d6bdd6a91fb",
        .manufacturer = "CBS Electronics, Bob Curtiss",
        .model        = "4L 2487 5000",
        .name         = "Solar Fox (1983) (CBS Electronics)",
    },{
        .md5          = "94b92a882f6dbaa6993a46e2dcc58402",
        .manufacturer = "Activision, Larry Miller",
        .model        = "AX-026, AX-026-04",
        .name         = "Enduro (1983) (Activision)",
    },{
        .md5          = "94d90f63678e086f6b6d5e1bc6c4c8c2",
        .manufacturer = "Digivision",
        .name         = "Seaquest (Digivision)",
    },{
        .md5          = "94e3fbc19107a169909e274187247a9d",
        .model        = "2402-044-01",
        .name         = "2 in 1 Freeway and Tennis (Unknown)",
        .type         = "2IN1",
    },{
        .md5          = "94e4c9b924286038527f49cdc20fda69",
        .manufacturer = "Retroactive",
        .name         = "Qb (V2.12) (Stella) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "94e7cc6342d11e508e7e8b2ddf53c255",
        .name         = "Missile Command (Unknown) (PAL) (Hack)",
        .phosphor     = 1,
    },{
        .md5          = "94ff6b7489ed401dcaaf952fece10f67",
        .manufacturer = "Atari - GCC, Mark Ackerman, Noelie Alito",
        .model        = "CX2692",
        .name         = "Moon Patrol (07-31-1983) (Atari) (Prototype)",
    },{
        .md5          = "951e8cec7a1a1d6c01fd649e7ff7743a",
        .manufacturer = "Atari - Sculptured Software, Adam Clayton",
        .model        = "CX26151, CX26151P",
        .name         = "Dark Chambers (1988) (Atari) (Prototype) (PAL)",
    },{
        .md5          = "9526e3db3bdfbc27989a9cbfd0ee34bf",
        .name         = "Atari Logo Demo 6 (PD)",
    },{
        .md5          = "952a63b8305154a7969743c7b8671243",
        .name         = "Krull (Unknown) (PAL)",
    },{
        .md5          = "95351b46fa9c45471d852d28b9b4e00b",
        .manufacturer = "Atari, Tom Reuterdahl",
        .model        = "CX26163P",
        .name         = "Golf (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "955c408265ad6994f61f9b66657bbae9",
        .name         = "Quadrun (Video Conversion) (Fabrizio Zavagli)",
    },{
        .md5          = "956496f81775de0b69a116a0d1ad41cc",
        .manufacturer = "CCE",
        .name         = "Alien (CCE)",
        .phosphor     = 1,
    },{
        .md5          = "956b99511c0f47b3a11d18e8b7ac8d47",
        .name         = "Bones (Arcade Golf Hack)",
    },{
        .md5          = "95956108289a917f80667eccd3ce98a9",
        .manufacturer = "Atari, Ed Logg, Carol Shaw",
        .model        = "CX2639, CX2639P",
        .name         = "Othello (1981) (Atari) (PAL) (4K)",
    },{
        .md5          = "95a69cf8c08ef1522b050529464f0bca",
        .name         = "Grid Pattern Demo 1 (20-12-2002) (Christopher Tumber)",
    },{
        .md5          = "95a89d1bf767d7cc9d0d5093d579ba61",
        .manufacturer = "PlayAround - JHM",
        .model        = "204",
        .name         = "Lady in Wading (1982) (PlayAround)",
        .phosphor     = 1,
    },{
        .md5          = "95e1d834c57cdd525dd0bd6048a57f7b",
        .manufacturer = "Atari, Bill Aspromonte, Dave Joly, John Russell, Michael Sierchio, Robert Zdybel",
        .model        = "CX26114",
        .name         = "Pigs in Space (1983) (Atari) (PAL)",
        .note         = "Starring Miss Piggy",
    },{
        .md5          = "95e542a7467c94b1e4ab24a3ebe907f1",
        .manufacturer = "Suntek",
        .model        = "SS-021",
        .name         = "Dragon Defender (1983) (Suntek) (PAL)",
        .note         = "AKA Dragon Power",
        .phosphor     = 1,
    },{
        .md5          = "95fd6097dc27c20666f039cfe34f7c69",
        .name         = "Oh No! (Version 1) (17-01-2003) (Andrew Davie)",
    },{
        .md5          = "961112b74a920a5242e233480326c356",
        .manufacturer = "Activision, Alan Miller",
        .model        = "AG-007, CAG-007",
        .name         = "Tennis (1981) (Activision) (16K)",
    },{
        .md5          = "962ffd3eaf865230a7a312b80e6c5cfd",
        .manufacturer = "Imagic, Wilfredo 'Willy' Aguilar, Michael Becker, Rob Fulop",
        .model        = "13205",
        .name         = "Fathom (1983) (Imagic) (PAL) [a]",
        .phosphor     = 1,
    },{
        .md5          = "96662271ae50b6859017bffbdda75525",
        .manufacturer = "Andrew Davie & Thomas Jentzsch",
        .name         = "Boulder Dash - Demo (2011)",
    },{
        .md5          = "96670d0bf3610da2afcabd8e21d8eabf",
        .name         = "Boring Pitfall (Hack)",
        .note         = "Hack of Pitfall!",
    },{
        .md5          = "966b11d3c147d894dd9e4ebb971ea309",
        .name         = "Marble Craze Song (Paul Slocum) (PD)",
    },{
        .md5          = "966c955e4aaca7082d9ffb9a68e3f3ed",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Atari Mouse Hack v1.4 (PAL) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "9671b658286e276cc4a3d02aa25931d2",
        .name         = "Hangman Ghost Wordlist (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "968efc79d500dce52a906870a97358ab",
        .manufacturer = "TNT Games - Sculptured Software, Adam Clayton",
        .model        = "26192",
        .name         = "BMX Air Master (1989) (TNT Games)",
    },{
        .md5          = "969b968383d9f0e9d8ffd1056bcaef49",
        .manufacturer = "Atari, Larry Kaplan",
        .model        = "CX2628, CX2628P",
        .name         = "Bowling (1979) (Atari) (PAL)",
    },{
        .md5          = "96bcb3d97ce4ff7586326d183ac338a2",
        .name         = "Revenge of the Apes (Hack) [h2]",
        .note         = "Hack of Planet of the Apes",
    },{
        .md5          = "96e798995af6ed9d8601166d4350f276",
        .manufacturer = "20th Century Fox Video Games - Videa, David Ross",
        .model        = "11029",
        .name         = "Meltdown (1983) (20th Century Fox) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "96eccc2277043508a6c481ea432d7dd9",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Command (Atari Mouse) (2002) (Thomas Jentzsch) (PAL)",
        .note         = "Uses Atari ST Mouse Controller",
        .left         = "ATARIMOUSE",
        .right        = "ATARIMOUSE",
        .phosphor     = 1,
    },{
        .md5          = "96f806fc62005205d851e758d050dfca",
        .name         = "Push (V0.05) (2001) (Andrew Davie)",
    },{
        .md5          = "97184b263722748757cfdc41107ca5c0",
        .manufacturer = "Parker Brothers",
        .model        = "PB5820",
        .name         = "Mr. Do!'s Castle (1984) (Parker Bros)",
        .phosphor     = 1,
    },{
        .md5          = "9718b85ac5a55cbc7348963c63ffa35a",
        .manufacturer = "Robby",
        .name         = "Demon Attack (Robby)",
    },{
        .md5          = "972486110933623039a3581db308fda6",
        .name         = "Xeno Plus (Hack)",
        .note         = "Hack of Xenophobe",
    },{
        .md5          = "97327d6962f8c64e6f926f79cd01c6b9",
        .name         = "Jawbreaker (Unknown) (PAL)",
    },{
        .md5          = "977294ae6526c31c7f9a166ee00964ad",
        .manufacturer = "Atari - GCC, Ava-Robin Cohen, Douglas B. Macrae",
        .model        = "CX2677, CX2677P",
        .name         = "Dig Dug (1983) (Atari) (PAL)",
    },{
        .md5          = "9784290f422e7aeeab4d542318bd9a1f",
        .manufacturer = "AtariAge, Chris Walton",
        .model        = "1.0 (Release)",
        .name         = "Chetiry (2011) (AtariAge) (60k)",
        .phosphor     = 1,
    },{
        .md5          = "97842fe847e8eb71263d6f92f7e122bd",
        .manufacturer = "Imagic, Wilfredo Aguilar, Michael Becker, Dennis Koble",
        .model        = "720113-1A, 03206",
        .name         = "Solar Storm (1983) (Imagic)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "97933c9f20873446e4c1f8a4da21575f",
        .name         = "Racquetball (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "97a9bb5c3679d67f5c2cd17f30b85d95",
        .manufacturer = "Atari",
        .name         = "Colors (1980) (Atari) (Prototype) (PAL)",
    },{
        .md5          = "97cd63c483fe3c68b7ce939ab8f7a318",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Robot City (V0.21) (15-09-2002) (Thomas Jentzsch)",
    },{
        .md5          = "97d0151beb84acbe82aa6db18cd91b98",
        .manufacturer = "Steve Engelhardt",
        .name         = "Lunar Attack (2002) (Steve Engelhardt) (Hack)",
        .note         = "Hack of Z-Tack",
    },{
        .md5          = "97d079315c09796ff6d95a06e4b70171",
        .manufacturer = "Activision, Garry Kitchen",
        .model        = "AZ-032",
        .name         = "Pressure Cooker (1983) (Activision)",
    },{
        .md5          = "97e47512f89e79818d988d078dc90410",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Control - Amiga Mouse Hack v1.15 (NTSC) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "97f4da9f1031486f4e588f1e53572e53",
        .manufacturer = "SpiceWare - Darrell Spice Jr.",
        .name         = "Draconian",
        .phosphor     = 1,
    },{
        .md5          = "9813b9e4b8a6fd919c86a40c6bda8c93",
        .manufacturer = "Atari",
        .model        = "CX26177",
        .name         = "Ikari Warriors (1989) (Atari) (PAL) [a]",
    },{
        .md5          = "9831efc7f4cb8ffb4df0082bab2f07a3",
        .manufacturer = "Activision, Steve Cartwright - Ariola",
        .model        = "EAX-031, EAX-031-04B - 711 031-717",
        .name         = "Frostbite (1983) (Activision) (PAL) (8K)",
    },{
        .md5          = "9848b5ef7a0c02fe808b920a2ac566d2",
        .manufacturer = "Skyworks Technology Inc.",
        .name         = "Baseball (2002) (Skyworks)",
    },{
        .md5          = "9853089672116117258097dbbdb939b7",
        .manufacturer = "Hozer Video Games",
        .name         = "Gunfight 2600 - Cowboy Hair (2001) (Manuel Rotschkar)",
    },{
        .md5          = "98555b95cb38e0e0b22b482b2b60a5b6",
        .name         = "Spinning Fireball (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "989a48c6ed5893c366c9592f7568c1e8",
        .name         = "Freeway (Unknown) (PAL) (Hack)",
    },{
        .md5          = "98ba601a60172cb46c5bf9a962fd5b1f",
        .name         = "Gorilla Kong (Hack)",
        .note         = "Hack of Donkey Kong",
    },{
        .md5          = "98ccd15345b1aee6caf51e05955f0261",
        .manufacturer = "Retroactive",
        .name         = "Qb (V2.03) (NTSC) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "98e5e4d5c4dd9a986d30fd62bd2f75ae",
        .name         = "Air-Sea Battle (Unknown) (Hack) (4K)",
    },{
        .md5          = "98e6e34af45a0664597972c3bb31180f",
        .name         = "Space Instigators (V1.7) (17-10-2002) (Christopher Tumber)",
    },{
        .md5          = "98e7caaab8ec237558378d2776c66616",
        .manufacturer = "Bradford W. Mott",
        .name         = "HMOVE Test (Bradford W. Mott) (1998) (PD)",
    },{
        .md5          = "98ea10c47c13f1b3306c7b13db304865",
        .name         = "Jam Demo 1 (PD)",
    },{
        .md5          = "98ec0fa4199b9c01f7b8fa3732e43372",
        .manufacturer = "Activision, David Crane",
        .model        = "AX-018, AX-018-04",
        .name         = "Pitfall! (1982) (Activision) (8K)",
    },{
        .md5          = "98ef1593624b409b9fb83a1c272a0aa7",
        .manufacturer = "CCE",
        .model        = "C-831",
        .name         = "Cosmic Ark (1983) (CCE)",
    },{
        .md5          = "98f63949e656ff309cefa672146dc1b8",
        .manufacturer = "Atari - Axlon, John Vifian",
        .model        = "CX26168",
        .name         = "Off the Wall (1989) (Atari)",
    },{
        .md5          = "98fa3ad778a668a79449350de4b3b95b",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Thrust (V1.1) (2000) (Thomas Jentzsch)",
    },{
        .md5          = "9905f9f4706223dadee84f6867ede8e3",
        .manufacturer = "HES",
        .name         = "Challenge (HES) (PAL)",
        .note         = "Surfer's Paradise if right difficulty = 'A'",
    },{
        .md5          = "9912d06eea42200a198dd3e2be18c601",
        .manufacturer = "Imagic, Michael Greene",
        .model        = "IA3312",
        .name         = "No Escape! (1982) (Imagic) [a]",
    },{
        .md5          = "991d57bbcd529ad62925098e0aec1241",
        .name         = "Gunfight 2600 - The Final Kernel (Manuel Rotschkar) [a1]",
    },{
        .md5          = "9945a22f60bbaf6d04a8d73b3cf3db75",
        .manufacturer = "Activision, Dan Kitchen",
        .model        = "EAX-039-04B, EAX-039-04I",
        .name         = "Kung-Fu Master (1987) (Activision) (PAL) [a]",
    },{
        .md5          = "9947f1ebabb56fd075a96c6d37351efa",
        .manufacturer = "CBS Electronics",
        .model        = "4L 2737 0000",
        .name         = "Omega Race (1983) (CBS Electronics)",
        .note         = "Set right difficulty to 'A' for BoosterGrip in both ports",
        .left         = "BOOSTERGRIP",
        .right        = "BOOSTERGRIP",
    },{
        .md5          = "9962034ea7b3d4a905d0991804670087",
        .name         = "Grid Demo (PD)",
    },{
        .md5          = "9989f974c3cf9c641db6c8a70a2a2267",
        .manufacturer = "Eckhard Stolberg",
        .name         = "Colours Selector (Eckhard Stolberg)",
    },{
        .md5          = "99a24d7bb31d49b720b422550b32c35f",
        .name         = "Hangman Ghost Biglist1 (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "99ac89241365b692255ba95d745edd91",
        .manufacturer = "Atari, Frank Hausman, Mimi Nyden, Steve Woita",
        .model        = "CX2686",
        .name         = "Quadrun (18-03-1982) (Atari) (Prototype)",
    },{
        .md5          = "99f7c6c26046bbe95f1c604b25da8360",
        .manufacturer = "SnailSoft",
        .name         = "Comitoid beta 2 (SnailSoft)",
    },{
        .md5          = "9a01115206f32eb0b539c7e5a47ccafa",
        .manufacturer = "Atari, Jerome Domurat, Steve Woita",
        .model        = "CX2699",
        .name         = "Taz (07-15-1983) (Atari) (Prototype)",
    },{
        .md5          = "9a165c39af3f050fdee6583fdfcdc9be",
        .manufacturer = "Zirok",
        .name         = "Mario Bros. (Zirok)",
    },{
        .md5          = "9a21fba9ee9794e0fadd7c7eb6be4e12",
        .manufacturer = "Atari - Imagineering, Dan Kitchen",
        .model        = "CX26177",
        .name         = "Ikari Warriors (1991) (Atari)",
    },{
        .md5          = "9a25b3cfe2bbb847b66a97282200cca2",
        .manufacturer = "Atari, Brad Stewart - Sears",
        .model        = "CX2622 - 6-99813, 49-75107",
        .name         = "Breakout (1978) (Atari) (4K)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "9a4274409216ff09ecde799f2a56ac73",
        .manufacturer = "CCE",
        .model        = "C-801",
        .name         = "Mr. Postman (1983) (CCE) [a]",
    },{
        .md5          = "9ab72d3fd2cc1a0c9adb504502579037",
        .manufacturer = "Epyx, Steven A. Baker, Peter Engelbrite",
        .model        = "80561-00286",
        .name         = "California Games (1987) (Epyx)",
    },{
        .md5          = "9ad362179c2eea4ea115c7640b4b003e",
        .name         = "Barnstorming (Unknown) (PAL)",
        .format       = "NTSC50",
    },{
        .md5          = "9ad36e699ef6f45d9eb6c4cf90475c9f",
        .manufacturer = "Imagic, Dennis Koble",
        .model        = "720103-1A, 720103-1B, IA3203, IX-010-04",
        .name         = "Atlantis (1982) (Imagic)",
        .note         = "AKA Lost City of Atlantis",
    },{
        .md5          = "9aeb5206c5bf974892a9cc59f1478db3",
        .manufacturer = "Activision, Steve Cartwright",
        .model        = "AX-013",
        .name         = "Barnstorming (1982) (Activision) (8K)",
    },{
        .md5          = "9af615951e9719df2244bc77fc50cb95",
        .manufacturer = "Dactari - Milmar",
        .name         = "Defender (Dactari - Milmar)",
    },{
        .md5          = "9afdfe1cff7f37f1c971fe3f0c900606",
        .name         = "Plaque Attack (Unknown)",
    },{
        .md5          = "9b150a42fc788960fbb4cbe250259ee2",
        .manufacturer = "Kroko",
        .name         = "3E Bankswitch Test (TIA @ $40)",
    },{
        .md5          = "9b21d8fc78cc4308990d99a4d906ec52",
        .manufacturer = "CCE",
        .model        = "C-838",
        .name         = "Immies & Aggies (1983) (CCE)",
    },{
        .md5          = "9b246683f44c963a50e41d6b485bee77",
        .name         = "Boring (PAL) (Andrew Davie)",
    },{
        .md5          = "9bb136b62521c67ac893213e01dd338f",
        .manufacturer = "Xonox - Beck-Tech",
        .model        = "6210, 7210, 06003. 99001",
        .name         = "Spike's Peak (1983) (Xonox) (PAL) [a]",
    },{
        .md5          = "9bd4e0d5f28ba6da417c26649171f8e4",
        .name         = "Hangman Pac-Man Original Words (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "9be58a14e055b0e7581fc4d6c2f6b31d",
        .name         = "Adventure (Color Scrolling) (Hack)",
        .note         = "Hack of Adventure",
    },{
        .md5          = "9c27ef3bd01c611cdb80182a59463a82",
        .manufacturer = "Arcadia Corporation, Kevin Norman",
        .model        = "AR-4103",
        .name         = "Killer Satellites (1983) (Arcadia) [a]",
    },{
        .md5          = "9c40bf810f761ffc9c1b69c4647a8b84",
        .name         = "2 in 1 - Frostbite, River Raid (Unknown)",
        .type         = "2IN1",
    },{
        .md5          = "9c6d65bd3b477aace0376f705b354d68",
        .name         = "RPG Kernal (18-04-2003) (Paul Slocum) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "9c6faa4ff7f2ae549bbcb14f582b70e4",
        .manufacturer = "U.S. Games Corporation, Garry Kitchen, Paul Willson - Vidtec",
        .model        = "VC1002",
        .name         = "Sneak 'n Peek (1982) (U.S. Games)",
        .note         = "AKA Hide 'n Seek",
    },{
        .md5          = "9c6fd6ed3599978ab7b6f900484b9be6",
        .manufacturer = "Andrew Wallace",
        .name         = "Laseresal 2002 (PAL60) (PD)",
    },{
        .md5          = "9c729017dd2f9ccbadcb511187f80e6b",
        .name         = "J-Pac (Hack)",
        .note         = "Hack of Pac-Man",
    },{
        .md5          = "9c7fa3cfcaaafb4e6daf1e2517d43d88",
        .name         = "PIEROXM Demo (PD)",
    },{
        .md5          = "9ca2deb61318eba4fb784d4bf7441d8b",
        .name         = "Purple Bar Demo 2 (PD)",
    },{
        .md5          = "9cbb07f1993a027bc2f87d5205457ec9",
        .name         = "Eckhard Stolberg's Scrolling Text Demo 1 (PD)",
    },{
        .md5          = "9d0befa555f003069a21d2f6847ad962",
        .manufacturer = "Atari - GCC, Dave Payne",
        .model        = "CX2669",
        .name         = "Vanguard (1982) (Atari) (PAL) [a]",
    },{
        .md5          = "9d1556ae5890398be7e3d57449774b40",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-001",
        .name         = "Dragster (1980) (Activision) (8K)",
    },{
        .md5          = "9d2938eb2b17bb73e9a79bbc06053506",
        .manufacturer = "Imagic, Michael Greene",
        .model        = "EIZ-002-04I",
        .name         = "Wing War (1983) (Imagic) (PAL) [a]",
    },{
        .md5          = "9d2f05d0fe8b2dfcf770b02eda066fc1",
        .name         = "Push (V0.06) (2001) (Andrew Davie)",
    },{
        .md5          = "9d33d31fb1de58c5460d8a67b57b36da",
        .name         = "Star Voyager (Genesis)",
        .note         = "Genesis controller (C is secondary lasers)",
    },{
        .md5          = "9d37a1be4a6e898026414b8fee2fc826",
        .manufacturer = "M Network - INTV - APh Technological Consulting, David Rolfe",
        .model        = "MT5665",
        .name         = "Super Challenge Baseball (1982) (M Network)",
        .note         = "AKA Big League Baseball",
    },{
        .md5          = "9d4bc7c6fe9a7c8c4aa24a237c340adb",
        .manufacturer = "Dennis Debro",
        .name         = "Climber 5 (16-04-2003) (Dennis Debro)",
        .note         = "For Philly Classic 4",
    },{
        .md5          = "9d522a3759aa855668e75962c84546f7",
        .manufacturer = "Atari, Tom Reuterdahl",
        .model        = "CX2634, CX2634P",
        .name         = "Golf (1980) (Atari) (PAL)",
    },{
        .md5          = "9d7f04618bb4043f531d087e3aaa7ac8",
        .manufacturer = "Parker Brothers, Larry Gelberg, Gary Goltz",
        .model        = "PB5065",
        .name         = "Star Wars - Ewok Adventure (1983) (Parker Bros) (Prototype) (PAL) (16K)",
    },{
        .md5          = "9de0d45731f90a0a922ab09228510393",
        .manufacturer = "20th Century Fox Video Games - Sirius, Mark Turmell",
        .model        = "11003",
        .name         = "Fast Eddie (1982) (20th Century Fox)",
    },{
        .md5          = "9dec0be14d899e1aac4337acef5ab94a",
        .manufacturer = "CommaVid, John Bronstein",
        .model        = "CM-003",
        .name         = "Cosmic Swarm (1982) (CommaVid) (4K)",
        .phosphor     = 1,
    },{
        .md5          = "9e01f7f95cb8596765e03b9a36e8e33c",
        .manufacturer = "Atari - CCW, Michael Callahan, Preston Stuart",
        .model        = "CX26103",
        .name         = "Alpha Beam with Ernie (1983) (Atari)",
        .note         = "Uses Keyboard Controllers",
    },{
        .md5          = "9e135f5dce61e3435314f5cddb33752f",
        .manufacturer = "Fabrizio Zavagli",
        .name         = "Space Treat Deluxe (2003)",
    },{
        .md5          = "9e192601829f5f5c2d3b51f8ae25dbe5",
        .manufacturer = "PlayAround - JHM",
        .model        = "201",
        .name         = "Cathouse Blues (1982) (PlayAround)",
        .phosphor     = 1,
    },{
        .md5          = "9e2c7299c69b602443d327c7dad51cbf",
        .manufacturer = "Charles Morgan",
        .name         = "Xaxyrax Road (Charles Morgan) (Hack)",
        .note         = "Hack of Freeway",
    },{
        .md5          = "9e437229136f1c5e6ef4c5f36178ed18",
        .manufacturer = "Funvision - Fund. International Co.",
        .name         = "Grand Prize (Funvision)",
        .note         = "AKA Enduro",
    },{
        .md5          = "9e5007131695621d06902ab3c960622a",
        .manufacturer = "Sega",
        .name         = "Tac Scan (1983) (Sega) [h1]",
        .phosphor     = 1,
    },{
        .md5          = "9e6fde3b65726c116c3e5110c3d1dedf",
        .manufacturer = "Fotomania",
        .name         = "Megamania (Fotomania)",
    },{
        .md5          = "9e792a59f8795664cbaaff1ba152d731",
        .name         = "Bullet Demo (20-12-2002) (Christopher Tumber)",
    },{
        .md5          = "9e904e2eaa471c050c491289b8b80f60",
        .name         = "How to Draw a Playfield II (1997) (Erik Mooney) (PD)",
    },{
        .md5          = "9ea8ed9dec03082973244a080941e58a",
        .manufacturer = "Eric Mooney, Piero Cavina",
        .name         = "INV+",
    },{
        .md5          = "9ec1b259a1bcffa63042a3c2b3b90f0a",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-008",
        .name         = "Laser Blast (1981) (Activision) (16K)",
    },{
        .md5          = "9eca521db1959156a115dee85a405194",
        .name         = "Fu Kung! (V0.08) (2003) (Andrew Davie)",
    },{
        .md5          = "9ed0f2aa226c34d4f55f661442e8f22a",
        .name         = "Nuts (Unknown) (PAL)",
    },{
        .md5          = "9eeb40f04a27efb1c68ba1d25e606607",
        .manufacturer = "Kyle Pittman",
        .name         = "Rambo II (2003) (Kyle Pittman) (Hack)",
        .note         = "Hack of Double Dragon",
    },{
        .md5          = "9efa877a98dd5a075e058214da428abb",
        .manufacturer = "Hozer Video Games",
        .name         = "SCSIcide (1.32) (Hozer Video Games)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXDR",
    },{
        .md5          = "9efb4e1a15a6cdd286e4bcd7cd94b7b8",
        .manufacturer = "20th Century Fox Video Games, John W.S. Marvin",
        .name         = "Planet of the Apes (1983) (20th Century Fox) (Prototype)",
    },{
        .md5          = "9f2d58dce1b81c6ba201ed103507c025",
        .name         = "Fu Kung! (V0.02) (2003) (Andrew Davie)",
    },{
        .md5          = "9f48eeb47836cf145a15771775f0767a",
        .manufacturer = "Atari, Warren Robinett",
        .model        = "CX2620",
        .name         = "Basic Programming (1979) (Atari)",
        .note         = "Uses Keyboard Controllers",
        .phosphor     = 1,
    },{
        .md5          = "9f5096a6f1a5049df87798eb59707583",
        .manufacturer = "20th Century Fox Video Games, Mark Klein",
        .model        = "11036",
        .name         = "Entity, The (1983) (20th Century Fox) (Prototype)",
    },{
        .md5          = "9f52271759f8a2004d207b2247ae0bb3",
        .manufacturer = "Parker Brothers",
        .model        = "PB5820",
        .name         = "Mr. Do!'s Castle (03-12-84) (Parker Bros) (Prototype) (4K)",
        .phosphor     = 1,
    },{
        .md5          = "9f59eddf9ba91a7d93bce7ee4b7693bc",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Montezuma's Revenge (Thomas Jentzsch) (PAL60)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "9f8fad4badcd7be61bbd2bcaeef3c58f",
        .manufacturer = "Parker Brothers, Charlie Heath",
        .model        = "PB5330",
        .name         = "Reactor (1983) (Parker Bros)",
        .phosphor     = 1,
    },{
        .md5          = "9f901509f0474bf9760e6ebd80e629cd",
        .manufacturer = "Atari, Bob Whitehead - Sears",
        .model        = "CX2623 - 6-99819, 49-75108, 49-75125",
        .name         = "Home Run (1978) (Atari) (4K)",
        .swapPorts    = 1,
    },{
        .md5          = "9f93734c68f6479eb022cab40814142e",
        .name         = "Push (V0.07) (2001) (Andrew Davie)",
    },{
        .md5          = "9f982421b9b4320ede00fe4aa2e812f4",
        .manufacturer = "Atari, Omegamatrix",
        .name         = "Super Breakout Menu (2020) (Hack)",
        .note         = "Hack of Super Breakout",
    },{
        .md5          = "9f9ee0f60c119c831e80694b6678ca1a",
        .manufacturer = "Jeffry Johnston",
        .name         = "Radial Pong - Version 8 (Jeffry Johnston) (PD)",
    },{
        .md5          = "9fa0c664b157a0c27d10319dbbca812c",
        .manufacturer = "Chris Walton, Justin Hairgrove, Tony Morse",
        .name         = "Hunchy II (2005)",
        .note         = "Homebrew",
    },{
        .md5          = "9fa61e79ac8ccf05103fc95bf415a7de",
        .manufacturer = "Tron",
        .name         = "River Raid (Tron)",
    },{
        .md5          = "9fc2d1627dcdd8925f4c042e38eb0bc9",
        .manufacturer = "Atari - GCC, John Allred, Mike Feinstein",
        .model        = "CX2688, CX2688P",
        .name         = "Jungle Hunt (1983) (Atari) (PAL)",
    },{
        .md5          = "E68E28752D3C54EDD3CCDA42C27E320C",
        .manufacturer = "Xonox - K-Tel Software, Anthony R. Henderson",
        .model        = "99007, 6240",
        .name         = "Tomarc the Barbarian (1983) (Xonox)",
        .note         = "Genesis controller (B is jump and throw, C switches between players)",
    },{
        .md5          = "a0028f057d496f22b549fd8deecc6f78",
        .manufacturer = "Joe Grand",
        .name         = "SCSIcide Pre-release 6 (Joe Grand)",
    },{
        .md5          = "a00ec89d22fcc0c1a85bb542ddcb1178",
        .manufacturer = "CCE",
        .model        = "C-1012",
        .name         = "Phoenix (1983) (CCE)",
    },{
        .md5          = "a00ee0aed5c8979add4c170f5322c706",
        .manufacturer = "Barry Laws Jr.",
        .name         = "Egghead (Barry Laws Jr.) (Hack)",
        .note         = "Hack of Pac-Man",
    },{
        .md5          = "a0185c06297b2818f786d11a3f9e42c3",
        .name         = "International Soccer (Unknown) (PAL)",
    },{
        .md5          = "a025a8f83a42a4d6d46c4887e799bfac",
        .manufacturer = "Hozer Video Games",
        .name         = "Gunfight 2600 - Descissions had to be made (2001) (Manuel Rotschkar)",
    },{
        .md5          = "a0297c4788f9e91d43e522f4c561b4ad",
        .manufacturer = "Atari - CCW, Gary Stark",
        .model        = "CX26102",
        .name         = "Cookie Monster Munch (1983) (Atari) (PAL)",
        .note         = "Uses Kids/Keyboard Controllers",
        .right        = "KEYBOARD",
    },{
        .md5          = "a0563dd6d8215c38c488fbbd61435626",
        .name         = "Ship Demo (V 1501) (PD)",
    },{
        .md5          = "a0675883f9b09a3595ddd66a6f5d3498",
        .manufacturer = "Telegames - VSS",
        .model        = "6057 A227",
        .name         = "Quest for Quintana Roo (1988) (Telegames)",
    },{
        .md5          = "a075ad332942740c386f4c3814925ece",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4200",
        .name         = "Escape from the Mindmaster (2 of 4) (1982) (Arcadia) (PAL)",
    },{
        .md5          = "a0d502dc8b90b1d7daa5f6effb10d349",
        .name         = "Demo Image Series #5 - Sam (19-02-2003) (Andrew Davie)",
    },{
        .md5          = "a0e2d310e3e98646268200c8f0f08f46",
        .manufacturer = "Atari, Ed Logg, Carol Shaw",
        .model        = "CX2639, CX2639P",
        .name         = "Othello (1981) (Atari) (PAL)",
    },{
        .md5          = "a100eff2d7ae61ca2b8e65baf7e2aae8",
        .manufacturer = "David Marli",
        .name         = "Muncher (David Marli) (Hack)",
        .note         = "Hack of Pac-Man",
    },{
        .md5          = "a11099b6ec24e4b00b8795744fb12005",
        .manufacturer = "Activision - Bobco, Robert C. Polaro",
        .model        = "EAK-049-04B",
        .name         = "Rampage! (1989) (Activision) (PAL)",
    },{
        .md5          = "a1403fef01641dcd3980cac9f24d63f9",
        .manufacturer = "Dactari - Milmar",
        .name         = "Atlantis (Dactari - Milmar)",
    },{
        .md5          = "a14d8a388083c60283e00592b18d4c6c",
        .name         = "Tunnel Demo (28-03-2003) (Andrew Davie)",
    },{
        .md5          = "a15b5831a1fab52e4c416068c85ec011",
        .manufacturer = "Hozer Video Games",
        .name         = "Gunfight 2600 - The Good, The Bad, The Ugly (2001) (Manuel Rotschkar)",
    },{
        .md5          = "a174cece06b3abc0aec3516913cdf9cc",
        .manufacturer = "Sears Tele-Games, Jim Huether",
        .model        = "CX2614 - 49-75126",
        .name         = "Steeplechase (1980) (Sears) (4K)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXIS",
    },{
        .md5          = "a1770ef47146ab7b12e2c4beccd68806",
        .manufacturer = "Digitel",
        .name         = "Kaystone Kapers (1983) (Digitel)",
        .note         = "AKA Keystone Kapers",
    },{
        .md5          = "a184846d8904396830951217b47d13d9",
        .manufacturer = "Activision, Dan Kitchen",
        .model        = "AX-029",
        .name         = "Crackpots (1983) (Activision)",
        .note         = "Flower Power",
    },{
        .md5          = "a189f280521f4e5224d345efb4e75506",
        .manufacturer = "Atari - Thomas Jentzsch",
        .name         = "Obelix (1983) (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "a1bcbe0bfe6570da2661fc4de2f74e8a",
        .manufacturer = "Imagic - Advanced Program Technology, Rob Fulop",
        .name         = "Actionauts (Microbots) (1984-2008) (Imagic)",
    },{
        .md5          = "a1ca372388b6465a693e4626cc98b865",
        .manufacturer = "Quelle",
        .model        = "176.543 7",
        .name         = "Der Vielfrass (1983) (Quelle) (PAL)",
        .note         = "AKA Fast Food",
    },{
        .md5          = "a1ead9c181d67859aa93c44e40f1709c",
        .manufacturer = "American Videogame - Dunhill Electronics, Darrell Wagner, Todd Clark Holm, John Simonds",
        .name         = "Tax Avoiders (1986) (American Videogame)",
    },{
        .md5          = "a1f9159121142d42e63e6fb807d337aa",
        .manufacturer = "Quelle - Otto Versand",
        .model        = "700.223 1 - 781627",
        .name         = "Der moderne Ritter (1983) (Quelle) (PAL)",
        .note         = "AKA Fast Eddie",
    },{
        .md5          = "a204cd4fb1944c86e800120706512a64",
        .manufacturer = "Coleco, Rob Harris",
        .model        = "2511",
        .name         = "Smurfs Save the Day (1983) (Coleco)",
        .note         = "Uses the Kid Vid Voice Module",
    },{
        .md5          = "a20b7abbcdf90fbc29ac0fafa195bd12",
        .manufacturer = "Quelle - Otto Versand",
        .model        = "719.383 2 - 649635, 781393, 781784, 986404",
        .name         = "Motocross (1983) (Quelle) (PAL)",
        .note         = "AKA Motorcross",
    },{
        .md5          = "a20d931a8fddcd6f6116ed21ff5c4832",
        .manufacturer = "Apollo - Games by Apollo, Ed Salvo, Byron Parks",
        .model        = "AP-2003",
        .name         = "Racquetball (1982) (Apollo)",
        .phosphor     = 1,
    },{
        .md5          = "a2170318a8ef4b50a1b1d38567c220d6",
        .manufacturer = "Amiga - Video Soft, Chip Curry",
        .model        = "3125",
        .name         = "Surf's Up (1983) (Amiga) (Prototype) [a1]",
        .note         = "Uses the Joyboard controller",
    },{
        .md5          = "a2276822c772f72073a8a40a72a1ca52",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Challenge of... Nexar, The - Atari Mouse Hack v1.1 (NTSC) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "a2424c1a0c783d7585d701b1c71b5fdc",
        .name         = "Video Pinball (Unknown) (PAL)",
    },{
        .md5          = "a25bb76e9e773117e567fd4300b1bb23",
        .name         = "Interleaved ChronoColour Demo (NTSC) (05-03-2003) (Andrew Davie)",
    },{
        .md5          = "a28d872fc50fa6b64eb35981d0f4bb8d",
        .manufacturer = "Atari, Larry Kaplan - Sears",
        .model        = "CX2628 - 6-99842, 49-75117",
        .name         = "Bowling (1979) (Atari) (4K)",
    },{
        .md5          = "a29df35557f31dfea2e2ae4609c6ebb7",
        .manufacturer = "Atari",
        .name         = "Circus Atari (1980) (Atari) (Joystick)",
        .left         = "JOYSTICK",
        .right        = "JOYSTICK",
    },{
        .md5          = "a29fc854838e08c247553a7d883dd65b",
        .manufacturer = "Activision, Steve Cartwright",
        .model        = "AX-013",
        .name         = "Barnstorming (1982) (Activision) (16K)",
    },{
        .md5          = "a2a384d3a16d5be50afd12906f146827",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Flash Gordon (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "a2aae759e4e76f85c8afec3b86529317",
        .name         = "Boom Bang (Unknown)",
        .note         = "AKA Crackpots",
    },{
        .md5          = "a2d7cc2e5419a9e4ab91fdb26339b726",
        .manufacturer = "Omegamatrix",
        .name         = "Star Wars Arcade (Atari Mouse) (Y Inverted) (PAL60) v4 (Omegamatrix)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "a2de0fc85548871279ed2a3c1325c13e",
        .manufacturer = "George Veeder",
        .name         = "Cat and Mouse (George Veeder) (Hack)",
        .note         = "Hack of Pac-Man",
    },{
        .md5          = "a2eb84cfeed55acd7fece7fefdc83fbb",
        .name         = "Kool Aid Man (Fixed) (15-11-2002) (Christopher Tumber)",
        .note         = "HMOVE handling fixed in this version",
    },{
        .md5          = "a2f296ea2d6d4b59979bac5dfbf4edf0",
        .name         = "Warring Worms (28-01-2002) (Billy Eno)",
    },{
        .md5          = "a2f9e3b6aaa23b6dc06099cdd5b51b31",
        .manufacturer = "Nukey Shay",
        .name         = "Montezuma's Revenge (Genesis) (PAL60) (F6_Conversion)",
        .note         = "Genesis controller",
    },{
        .md5          = "a302b922a8dbec47743f28b7f91d4cd8",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum",
        .model        = "AR-4400",
        .name         = "Dragonstomper (Preview) (1982) (Starpath)",
    },{
        .md5          = "a30ece6dc4787e474fbc4090512838dc",
        .manufacturer = "Zellers",
        .name         = "Circus (Zellers)",
        .note         = "AKA Circus Atari",
        .left         = "JOYSTICK",
        .right        = "JOYSTICK",
    },{
        .md5          = "a310494ad5ba2b5b221a30d7180a0336",
        .name         = "Demo Image Series #6 - Mario (19-02-2003) (Andrew Davie)",
    },{
        .md5          = "a336beac1f0a835614200ecd9c41fd70",
        .manufacturer = "Atari, Christopher H. Omarzu, Robert Vieira",
        .model        = "CX26121",
        .name         = "Zoo Keeper Sounds (1984) (Atari) (Prototype)",
    },{
        .md5          = "a34560841e0878c7b14cc65f79f6967d",
        .manufacturer = "Multivision, Michael Case",
        .name         = "Harem (1982) (Multivision)",
    },{
        .md5          = "a3486c0b8110d9d4b1db5d8a280723c6",
        .manufacturer = "Atari, Alan J. Murphy, Robert C. Polaro",
        .model        = "CX26100",
        .name         = "Bugs Bunny (08-04-1983) (Atari) (Prototype)",
    },{
        .md5          = "a35d47898b2b16ec641d1dfa8a45c2b7",
        .manufacturer = "Activision, Steve Cartwright",
        .model        = "AX-017, AX-017-04",
        .name         = "MegaMania (1982) (Activision) (16K)",
    },{
        .md5          = "a3873d7c544af459f40d58dfcfb78887",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Tennis (Jone Yuan)",
    },{
        .md5          = "a3b9d2be822eab07e7f4b10593fb5eaa",
        .name         = "GREGXM Demo (PD)",
    },{
        .md5          = "a3c1c70024d7aabb41381adbfb6d3b25",
        .manufacturer = "Telesys, Alex Leavens",
        .model        = "1005",
        .name         = "Stargunner (1983) (Telesys)",
    },{
        .md5          = "a3d7c299fbcd7b637898ee0fdcfc47fc",
        .manufacturer = "Arcadia Corporation, Scott Nelson",
        .model        = "AR-4300",
        .name         = "Fireball (Preview) (1982) (Arcadia) (PAL)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "a3f2a0fcf74bbc5fa763b0ee979b05b1",
        .manufacturer = "Quelle",
        .model        = "873.790 0",
        .name         = "Eishockey-Fieber (1983) (Quelle) (PAL)",
        .note         = "AKA Ice Hockey",
    },{
        .md5          = "a3f8aebb38182749cb8da85cfbc63d7c",
        .name         = "Tennis (Unknown) (PAL) (Hack)",
    },{
        .md5          = "a3fee8ce15525ea00d45a06f04c215d1",
        .manufacturer = "Aaron Curtis",
        .name         = "AStar (PAL60)",
    },{
        .md5          = "a406d2f6d84e61d842f4cb13b2b1cfa7",
        .manufacturer = "Tigervision, John Harris - Teldec",
        .model        = "7-002 - 3.60002 VE",
        .name         = "Jawbreaker (1982) (Tigervision) (PAL)",
    },{
        .md5          = "a412c8577b2d57b09185ae51739ac54f",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4000",
        .name         = "Phaser Patrol (1982) (Arcadia) [a]",
        .phosphor     = 1,
    },{
        .md5          = "a41450333f8dd0e96e5e9f0af3770ae9",
        .name         = "Basic Math (Unknown) (PAL)",
    },{
        .md5          = "a422194290c64ef9d444da9d6a207807",
        .manufacturer = "M Network - APh Technological Consulting, Hal Finney",
        .model        = "MT5667",
        .name         = "Dark Cavern (1982) (M Network)",
    },{
        .md5          = "a428068d3e51498907d97cec40000515",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Sky Alien (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "a47878a760f5fa3aa99f95c3fdc70a0b",
        .name         = "Demo Image Series #5 - Baboon (19-02-2003) (Andrew Davie)",
    },{
        .md5          = "a4790224bd5afabd53cbe93e46a7f241",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AG-019",
        .name         = "Sky Jinks (1982) (Activision) (8K)",
    },{
        .md5          = "a47e26096de6f6487bf5dd2d1cced294",
        .manufacturer = "Atari",
        .model        = "CX2643",
        .name         = "Codebreaker (1978) (Atari) (PAL)",
        .note         = "Uses Keyboard Controllers",
    },{
        .md5          = "a484638990de7b12c62947c79dafa4c6",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Marble Craze - Atari Mouse Hack v1.0 (PAL60) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controllers",
    },{
        .md5          = "a499d720e7ee35c62424de882a3351b6",
        .manufacturer = "SEGA - Beck-Tech, Steve Beck, Phat Ho",
        .model        = "009-01",
        .name         = "Up 'n Down (1984) (SEGA)",
    },{
        .md5          = "a4aa7630e4c0ad7ebb9837d2d81de801",
        .name         = "Atari 2600 Invaders (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "a4ab331e8768eafdc20ce8b0411ff77a",
        .name         = "Demo Image Series #1 - Sam (19-02-2003) (Andrew Davie)",
    },{
        .md5          = "a4b9423877a0b86ca35b52ca3c994ac5",
        .manufacturer = "CCE",
        .model        = "C-805",
        .name         = "Sea Monster (1983) (CCE)",
        .note         = "O Monstro Marinho",
    },{
        .md5          = "a4b99aa5ed85cfdb7d101923147de035",
        .manufacturer = "Jim Goebel",
        .name         = "Pac-Law (Jim Goebel) (Hack)",
        .note         = "Hack of Outlaw",
    },{
        .md5          = "a4c08c4994eb9d24fb78be1793e82e26",
        .manufacturer = "Activision, Alan Miller",
        .model        = "AX-012, CAX-012, AX-012-04",
        .name         = "Ice Hockey (1981) (Activision)",
    },{
        .md5          = "a4d026a5c200ef98518ebb77719fe8dc",
        .manufacturer = "Kyle Pittman",
        .name         = "SpongeBob SquarePants (2003) (Kyle Pittman) (Hack)",
        .note         = "Hack of Revenge of the Beefsteak Tomatoes",
    },{
        .md5          = "a4e885726af9d97b12bb5a36792eab63",
        .manufacturer = "Xonox - K-Tel Software - Beck-Tech, Steve Beck",
        .model        = "6210, 7210, 06003. 99001",
        .name         = "Spike's Peak (1983) (Xonox)",
    },{
        .md5          = "a4ecb54f877cd94515527b11e698608c",
        .manufacturer = "Atari, Jerome Domurat, Howard Scott Warshaw",
        .model        = "CX26119",
        .name         = "Saboteur (12-20-1983) (Atari) (Prototype)",
    },{
        .md5          = "a4f1cea2c8479284e2a2292f8d51b5fa",
        .name         = "Gunfight 2600 - The Final Kernel Part 2 (Manuel Rotschkar)",
    },{
        .md5          = "a4ff39d513b993159911efe01ac12eba",
        .manufacturer = "Atari - GCC, John Allred, Douglas B. Macrae, Betty Ryan Tylko",
        .model        = "CX2694",
        .name         = "Pole Position (1983) (Atari)",
        .note         = "AKA RealSports Driving",
    },{
        .md5          = "a511f7ee13e4b35512f9217a677b4028",
        .manufacturer = "Atari, Jerome Domurat, Howard Scott Warshaw",
        .model        = "CX2674",
        .name         = "E.T. - The Extra-Terrestrial (1982) (Atari) (PAL) [a]",
    },{
        .md5          = "a5262fe6d01d6a1253692682a47f79dd",
        .name         = "JKH Text Scrolling Demo (PD)",
    },{
        .md5          = "a537879d8e82e1061d3ad800479d3b84",
        .manufacturer = "Andrew Wallace",
        .name         = "Brooni (2001) (Andrew Wallace) (PD) (PAL)",
    },{
        .md5          = "a539b9fd1ba57e46442b3e9351e6383b",
        .name         = "River Raid (Unknown) (PAL) (Hack) [a]",
    },{
        .md5          = "a56b642a3d3ab9bbeee63cd44eb73216",
        .manufacturer = "Carrere Video - JWDA, Sylvia Day, Todd Marshall, Robin McDaniel, Henry Will IV - Teldec - Prism",
        .model        = "USC2001",
        .name         = "Gopher (1983) (Carrere Video) (PAL)",
        .note         = "AKA Vorsicht Wuhlmaus!",
    },{
        .md5          = "a5855d73d304d83ef07dde03e379619f",
        .manufacturer = "Atari, David Crane",
        .name         = "Boggle (08-07-1978) (Atari) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "a58b11148c18d85e4c2aef4ff46ade67",
        .name         = "Video Chess (Unknown) (PAL)",
    },{
        .md5          = "a591b5e8587aae0d984a0f6fe2cc7d1c",
        .name         = "Globe Trotter Demo (24-03-2003) (Weston)",
    },{
        .md5          = "a5b7f420ca6cc1384da0fed523920d8e",
        .name         = "Adventure (New Graphics) (Hack)",
        .note         = "Hack of Adventure",
    },{
        .md5          = "a5c96b046d5f8b7c96daaa12f925bef8",
        .manufacturer = "Activision, Alan Miller - Ariola",
        .model        = "EAG-007, EAG-007-04I, PAG-007 - 711 007-720",
        .name         = "Tennis (1981) (Activision) (PAL)",
    },{
        .md5          = "a5e9ed3033fb2836e80aa7a420376788",
        .manufacturer = "Atari, Carla Meninsky",
        .model        = "CX2637, CX2637P",
        .name         = "Dodge 'Em (1980) (Atari) (PAL)",
    },{
        .md5          = "a60598ad7ee9c5ccad42d5b0df1570a1",
        .manufacturer = "Atari, Alan Miller",
        .model        = "CX26163P",
        .name         = "Surround (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "a6127f470306eed359d85eb4a9cf3c96",
        .manufacturer = "Atari, Michael Kosaka, Peter C. Niday, Robert Vieira",
        .model        = "CX26110",
        .name         = "Crystal Castles (1984) (Atari) [a]",
    },{
        .md5          = "a6239810564638de7e4c54e66b3014e4",
        .manufacturer = "Personal Games Company, Robert Anthony Tokar",
        .name         = "Birthday Mania (1984) (Personal Games)",
    },{
        .md5          = "a62e3e19280ff958407e05ca0a2d5ec7",
        .name         = "Hangman Ghost Biglist3 (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "a6737c81542a99ee71cb5f5ff14703d9",
        .name         = "Scrolling Playfield 3 (Junkosoft) (PD)",
    },{
        .md5          = "a69f5b1761a8a11c98e706ec7204937f",
        .name         = "Pharaoh's Curse (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "a6ed8d72ed691fd3aad5b6974fa17978",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Bank Heist (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "a74689a08746a667a299b0507e1e6dd9",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum",
        .model        = "9 AR-4105",
        .name         = "Official Frogger, The (1983) (Starpath) (PAL)",
    },{
        .md5          = "a7523db9a33e9417637be0e71fa4377c",
        .manufacturer = "Videospielkassette - Ariola",
        .model        = "PGP238",
        .name         = "Gangster (Ariola) (PAL)",
        .note         = "AKA Outlaw",
    },{
        .md5          = "a7673809068062106db8e9d10b56a5b3",
        .manufacturer = "Atari, Jerome Domurat, Andrew Fuchs, Dave Staugas, Robert Vieira",
        .model        = "CX26118, CX26118P",
        .name         = "Millipede (1984) (Atari) (PAL)",
    },{
        .md5          = "a779b9fa02c62d00d7c31ed51268f18a",
        .manufacturer = "Arcadia Corporation, Brian McGhie",
        .model        = "AR-4104",
        .name         = "Rabbit Transit (1983) (Arcadia) [a]",
    },{
        .md5          = "a7a58e9291aefa1064e933071f60d4ef",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "1 AR-4000, AR-4100",
        .name         = "Phaser Patrol (1982) (Arcadia) (Prototype) [a]",
        .phosphor     = 1,
    },{
        .md5          = "a7b584937911d60c120677fe0d47f36f",
        .manufacturer = "M Network - INTV - APh Technological Consulting, Hal Finney",
        .model        = "MT5661",
        .name         = "Armor Ambush (1982) (M Network)",
        .note         = "AKA Tank Battle",
    },{
        .md5          = "a7b96a8150600b3e800a4689c3ec60a2",
        .manufacturer = "Atari, Mike Lorenzen - Sears",
        .model        = "CX2630 - 49-75122",
        .name         = "Circus Atari (1980) (Atari)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "a7bf8353f77caca407ef85c2698fdff2",
        .manufacturer = "Atari, Suki Lee - Sears",
        .model        = "CX2658 - 49-75128",
        .name         = "Math Gran Prix (1982) (Atari) (Prototype)",
    },{
        .md5          = "a7cf2b9afdbb3a161bf418dbcf0321dc",
        .manufacturer = "Barry Laws Jr.",
        .name         = "Attack Of The Mutant Space Urchins (2002) (Barry Laws Jr.) (Hack)",
        .note         = "Hack of Alien",
        .phosphor     = 1,
    },{
        .md5          = "a7d2e9408bb7cd70139ecced407ff238",
        .manufacturer = "Atari - Roklan, Joe Gaucher, Alex Leavens",
        .model        = "CX2683",
        .name         = "Crazy Climber (1983) (Atari) (Prototype) [a1]",
    },{
        .md5          = "a7ed7dc5cbc901388afa59030fb11d26",
        .manufacturer = "Atari, Warren Robinett",
        .model        = "CX2606, CX2606P",
        .name         = "Slot Racers (1978) (Atari) (PAL)",
    },{
        .md5          = "a7ef44ccb5b9000caf02df3e6da71a92",
        .manufacturer = "Atari, Ian Shepard - Sears",
        .model        = "CX2604 - 6-99812, 49-75106",
        .name         = "Space War (1978) (Atari)",
    },{
        .md5          = "a8101cb667e50a46165c6fb48c608b6b",
        .name         = "Kung Fu Sprite Demo (PD)",
        .phosphor     = 1,
    },{
        .md5          = "a81697b0c8bbc338ae4d0046ede0646b",
        .manufacturer = "CCE",
        .name         = "Gravitar (CCE)",
    },{
        .md5          = "a81b29177f258494b499fbac69789cef",
        .manufacturer = "Greg Thompson",
        .name         = "Console Wars (Greg Thompson) (Hack)",
        .note         = "Hack of Space Jockey",
    },{
        .md5          = "a83b070b485cf1fb4d5a48da153fdf1a",
        .manufacturer = "Apollo",
        .model        = "AP-2011",
        .name         = "Pompeii (1983) (Apollo) (Prototype)",
    },{
        .md5          = "a8435ec570141de5d833c4abec499e55",
        .name         = "Happy Birthday Demo (2001) (Dennis Debro) (PD)",
    },{
        .md5          = "a8633050a686270fcf6c0cc4dcbad630",
        .manufacturer = "Zirok",
        .name         = "Phoenix (Zirok)",
    },{
        .md5          = "a867b76098786c4091dba2fcee5084c3",
        .name         = "Dragrace (Hack)",
        .note         = "Hack of Dragster",
    },{
        .md5          = "a875f0a919129b4f1b5103ddd200d2fe",
        .manufacturer = "Atari, Dan Hitchens. Mimi Nyden",
        .model        = "CX2656",
        .name         = "SwordQuest - EarthWorld (1982) (Atari) (PAL)",
        .note         = "AKA Adventure I, SwordQuest I - EarthWorld",
    },{
        .md5          = "a8916734ff8c64ec3342f4c73fd5b57d",
        .manufacturer = "Atari",
        .name         = "Stand Alone Test Cart (1982) (Atari) [a]",
    },{
        .md5          = "a89a3e0547d6887279c34aba4b17a560",
        .manufacturer = "M Network, Steve Crandall, Patricia Lewis Du Long",
        .model        = "MT4646",
        .name         = "Rocky & Bullwinkle (1983) (Mattel) (Prototype)",
        .type         = "4K",
    },{
        .md5          = "a8a703e073183a89c94d4d99b9661b7f",
        .manufacturer = "Franklin Cruz",
        .name         = "Spice Invaders (Franklin Cruz) (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "a8b3ea6836b99bea77c8f603cf1ea187",
        .name         = "Boxing (Unknown)",
    },{
        .md5          = "a8c447efbec3a2b5d08b05a09999bd92",
        .name         = "MegaCart Menu",
        .left         = "JOYSTICK",
        .right        = "JOYSTICK",
    },{
        .md5          = "a8c48b4e0bf35fe97cc84fdd2c507f78",
        .manufacturer = "Puzzy - Bit Corporation",
        .model        = "PG201",
        .name         = "Seamonster (1982) (Puzzy)",
    },{
        .md5          = "a8d0a4a77cd71ac601bd71df5a060e4c",
        .name         = "Space Shuttle (1983) (Activision) [t2] (Fuel)",
    },{
        .md5          = "a8d4a9500b18b0a067a1f272f869e094",
        .name         = "Red And White Checkerboard Demo (PD)",
    },{
        .md5          = "a8e49d7e24ce293629ca29614862821b",
        .name         = "Enduro (Genesis)",
        .note         = "Genesis controller (B is acceleration, C is brakes)",
    },{
        .md5          = "a91d0858a52de3a2e6468437212d93e8",
        .name         = "Q-bert (Unknown) (PAL)",
    },{
        .md5          = "a936d80083e99d48752ad15c2b5f7c96",
        .name         = "Room of Doom (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "a93e8ea1f565c3c1e86b708cf0dc2fa9",
        .manufacturer = "Jess Ragan",
        .name         = "Kabul! (Jess Ragan) (Hack)",
        .note         = "Hack of Kaboom!",
    },{
        .md5          = "a94528ae05dd051894e945d4d2349b3b",
        .manufacturer = "Genus",
        .name         = "River Raid (Genus)",
    },{
        .md5          = "a94b8ca630f467b574b614808d813919",
        .manufacturer = "HES",
        .model        = "773-883",
        .name         = "2 Pak Special - Space Voyage, Fire Alert (1992) (HES) (PAL)",
    },{
        .md5          = "a9531c763077464307086ec9a1fd057d",
        .manufacturer = "Atari, John Dunn - Sears",
        .model        = "CX2631 - 49-75152",
        .name         = "Superman (1979) (Atari)",
    },{
        .md5          = "a957dbe7d85ea89133346ad56fbda03f",
        .manufacturer = "Atari, Brad Stewart",
        .model        = "CX2649, CX2649P",
        .name         = "Asteroids (1981) (Atari) (PAL) [a1]",
        .phosphor     = 1,
    },{
        .md5          = "a97733b0852ee3096300102cb0689175",
        .manufacturer = "CCE",
        .model        = "C-834",
        .name         = "Fast Eddie (1983) (CCE)",
    },{
        .md5          = "a9784c24cddb33bd0d14442b97784f3d",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Omega Race DC (2003) (Thomas Jentzsch) (Omega Race Hack)",
    },{
        .md5          = "a98b649912b6ca19eaf5c2d2faf38562",
        .name         = "This Planet Sucks (Greg Troutman) (PAL) [!]",
    },{
        .md5          = "a995b6cbdb1f0433abc74050808590e6",
        .manufacturer = "Imagic, Rob Fulop, Bob Smith",
        .model        = "720106-1A, IA3600",
        .name         = "Riddle of the Sphinx (1982) (Imagic)",
    },{
        .md5          = "a9cb638cd2cb2e8e0643d7a67db4281c",
        .manufacturer = "M Network - INTV - APh Technological Consulting, Larry Zwick",
        .model        = "MT5861",
        .name         = "Air Raiders (1983) (M Network)",
        .note         = "AKA Air Battle",
    },{
        .md5          = "a9d9e19d0c89fb31780b5d63e1f8c6a4",
        .manufacturer = "AtariAge, Chris Spry",
        .model        = "CX26201",
        .name         = "Zippy the Porcupine (2014) (Sprybug) (PAL60)",
    },{
        .md5          = "a9e3c23599c0d77151602f8e31daf879",
        .name         = "Kung Fu Master (Genesis)",
        .note         = "Genesis controller (C is extra kick modes)",
        .left         = "GENESIS",
    },{
        .md5          = "aa1c41f86ec44c0a44eb64c332ce08af",
        .manufacturer = "Spectravideo, David Lubar",
        .model        = "SA-218",
        .name         = "Bumper Bash (1983) (Spectravideo)",
        .note         = "Uses the Paddle Controllers (left only)",
        .left         = "PADDLES",
    },{
        .md5          = "aa2c4b32656bde9a75042a4d158583e1",
        .name         = "Oystron X (Piero Cavina) (PD)",
    },{
        .md5          = "aa5cfe3b20395aba1d479135943ad85c",
        .name         = "Defender (Hack) (Unknown)",
    },{
        .md5          = "aa7bb54d2c189a31bb1fa20099e42859",
        .manufacturer = "CBS Electronics - Individeo, Ed English",
        .model        = "4L4478",
        .name         = "Mr. Do! (1983) (CBS Electronics) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "aa8c75d6f99548309949916ad6cf33bc",
        .manufacturer = "Bob Montgomery (aka vdub_bobby)",
        .name         = "Squish 'Em (2007)",
    },{
        .md5          = "aa8e4b2cb8a78ffe6b20580033f4dec9",
        .name         = "Bitmap Demo (13-01-2003) (Andrew Davie)",
    },{
        .md5          = "aaac0d277eda054861e613c59c2e4ff2",
        .manufacturer = "JWDA, Todd Marshall",
        .name         = "Music Demo (JWDA)",
    },{
        .md5          = "aab840db22075aa0f6a6b83a597f8890",
        .manufacturer = "Home Vision, R.J.P.G. - Gem International Corp. - VDI",
        .model        = "VCS83124",
        .name         = "Racing Car (1983) (Home Vision) (PAL)",
        .swapPorts    = 1,
    },{
        .md5          = "aad61898633f470ce528e3d7ef3d0adb",
        .manufacturer = "Commavid, Ben Burch",
        .model        = "CM-010",
        .name         = "Rush Hour (1983) (Commavid) (Prototype) [a1]",
    },{
        .md5          = "aad91be0bf78d33d29758876d999848a",
        .manufacturer = "Activision, David Crane",
        .model        = "AX-018, AX-018-04",
        .name         = "Pitfall! (1981) (Activision) (Prototype)",
        .note         = "Pitfall Harry's Jungle Adventure (Jungle Runner)",
    },{
        .md5          = "aaea37b65db9e492798f0105a6915e96",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4302",
        .name         = "Party Mix - Tug of War (2 of 3) (1983) (Arcadia)",
        .note         = "Uses Paddle Controllers",
    },{
        .md5          = "aafc79ffc32c4c9b2d73c8ada7602cfe",
        .name         = "Planet Patrol (Unknown) (PAL)",
    },{
        .md5          = "ab10f2974dee73dab4579f0cab35fca6",
        .manufacturer = "ITT Family Games",
        .name         = "Wilma Wanderer (1983) (ITT Family Games) (PAL)",
        .note         = "AKA Lilly Adventure",
    },{
        .md5          = "ab2cfcaad3daaf673b2b14fdbb8dac33",
        .manufacturer = "M Network - INTV, David Akers, Joe King, Patricia Lewis Du Long, Jeff Ratcliff",
        .model        = "MT7045",
        .name         = "Bump 'n' Jump (1983) (M Network)",
    },{
        .md5          = "ab2ea35dcc1098c87455bb8210b018cf",
        .name         = "Fu Kung! (V0.04 Single Line Resolution) (10-01-2003) (Andrew Davie)",
    },{
        .md5          = "ab301d3d7f2f4fe3fdd8a3540b7a74f5",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "IQ 180 (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "ab434f4c942d6472e75d5490cc4dd128",
        .manufacturer = "HES",
        .model        = "773-875",
        .name         = "2 Pak Special - Hoppy, Alien Force (1992) (HES) (PAL)",
    },{
        .md5          = "ab48c4af46c8b34c3613d210e1206132",
        .manufacturer = "Andrew Davie & Thomas Jentzsch",
        .name         = "Boulder Dash - Demo V2 (2014)",
    },{
        .md5          = "ab4ac994865fb16ebb85738316309457",
        .manufacturer = "Atari, Alan Miller - Sears",
        .model        = "CX2624 - 6-99826, 49-75113",
        .name         = "Basketball (1978) (Atari)",
        .note         = "Console ports are swapped",
        .swapPorts    = 1,
    },{
        .md5          = "ab56f1b2542a05bebc4fbccfc4803a38",
        .manufacturer = "Activision - Imagineering, Dan Kitchen, David Lubar",
        .model        = "AK-048-04",
        .name         = "River Raid II (1988) (Activision)",
    },{
        .md5          = "ab5bf1ef5e463ad1cbb11b6a33797228",
        .manufacturer = "Imagic, Rob Fulop",
        .model        = "720104-1A, 720104-1B, IA3204",
        .name         = "Cosmic Ark (1982) (Imagic)",
    },{
        .md5          = "ab60ea7b707c58d356cad858eb18db43",
        .name         = "Tazer (John K. Harvey)",
    },{
        .md5          = "ab8d318da4addd39c65b7f9c408df2a6",
        .name         = "Star Trek (Genesis)",
        .note         = "Genesis controller (B is phaser, C is warp)",
        .phosphor     = 1,
    },{
        .md5          = "abb740bea0a6842831b4f53112fb8145",
        .name         = "Qb (V1.01) (PAL) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "abb741c83f665d73c86d90a7d9292a9b",
        .manufacturer = "Telegames",
        .name         = "Space Attack (1988) (Telegames) (PAL)",
    },{
        .md5          = "abc64037ca5d5b04ae8a7eedbca3ed74",
        .name         = "Green and Yellow Number 1 Demo (PD)",
        .phosphor     = 1,
    },{
        .md5          = "abe40542e4ff2d1c51aa2bb033f09984",
        .manufacturer = "Absolute Entertainment, David Crane",
        .model        = "EAZ-042-04B, EAZ-042-04I",
        .name         = "Skate Boardin' (1987) (Absolute) (PAL)",
    },{
        .md5          = "ac05c0e53a5e7009ddd75ed4b99949fc",
        .manufacturer = "Atari, Joe Decuir, Steve Mayer, Larry Wagner - Sears",
        .model        = "CX2601 - 99801, 6-99801, 49-75124",
        .name         = "Combat (1977) (Atari) (4K)",
    },{
        .md5          = "ac0ddbcff34d064009591607746e33b8",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Atlantis FH (2003) (Thomas Jentzsch) (Hack)",
        .note         = "Hack of Atlantis",
    },{
        .md5          = "ac26d7d37248d1d8eac5eccacdbef8db",
        .name         = "Snail Against Squirrel (Unknown) (PAL)",
    },{
        .md5          = "ac3dd22dd945724be705ddd2785487c2",
        .manufacturer = "Atari - GCC, Mark Ackerman, Noelie Alito",
        .model        = "CX2692",
        .name         = "Moon Patrol (06-15-1983) (Atari) (Prototype)",
    },{
        .md5          = "ac53b83e1b57a601eeae9d3ce1b4a458",
        .manufacturer = "Retroactive",
        .name         = "Qb (2.15) (Retroactive) (NTSC)",
        .phosphor     = 1,
    },{
        .md5          = "ac5f78bae0638cf3f2a0c8d07eb4df69",
        .name         = "Minesweeper (V.99) (Soren Gust) (PD)",
    },{
        .md5          = "ac7c2260378975614192ca2bc3d20e0b",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-930-04, AZ-030",
        .name         = "Decathlon (1983) (Activision)",
        .right        = "PADDLES",
    },{
        .md5          = "ac9adbd6de786a242e19d4bec527982b",
        .manufacturer = "Activision, Alan Miller - Ariola",
        .model        = "EAG-012-04I, EAX-012, EAX-012-04B - 711 012-720",
        .name         = "Ice Hockey (1981) (Activision) (PAL)",
    },{
        .md5          = "aca09ffea77174b148b96b205109db4d",
        .manufacturer = "Activision, Alan Miller",
        .model        = "AG-007, CAG-007",
        .name         = "Tennis (1981) (Activision) (4K)",
    },{
        .md5          = "acaa27d214039d89d7031609aafa55c3",
        .name         = "Sprite Demo 6 (PD)",
    },{
        .md5          = "acb6787b938079f4e74313a905ec3ceb",
        .name         = "Chronocolor Donkey Kong (PD)",
    },{
        .md5          = "acb7750b4d0c4bd34969802a7deb2990",
        .manufacturer = "Parker Brothers, Ed Temple",
        .model        = "PB5310",
        .name         = "Amidar (1982) (Parker Bros)",
    },{
        .md5          = "acb962473185d7a652f90ed6591ae13b",
        .manufacturer = "Imagic, Dennis Koble",
        .model        = "IA3203, IX-010-04",
        .name         = "Atlantis (1982) (Imagic) (16K)",
        .note         = "AKA Lost City of Atlantis",
    },{
        .md5          = "ace319dc4f76548659876741a6690d57",
        .manufacturer = "Atari, Steve Wright",
        .model        = "CX2616",
        .name         = "Pele's Soccer (1981) (Atari)",
        .note         = "AKA Pele's Championship Soccer",
    },{
        .md5          = "ad2e6bfb3b9b9b36ba8bf493ce764c49",
        .name         = "2600 Collison Demo 1 (Piero Cavina) (PD)",
    },{
        .md5          = "ad42e3ca3144e2159e26be123471bffc",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Human Cannonball (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "ad72d616030a17634ff29ce8680d3c4c",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Atari Trak-Ball Hack v1.3 (PAL60) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "ad7e97c19bd25d5aa3999430845c755b",
        .name         = "Sprite Demo 5 (PD)",
    },{
        .md5          = "ad8072675109d13fdd31a2e0403d5cff",
        .name         = "Thunderground (Unknown) (Hack)",
    },{
        .md5          = "adb770ff70e9adf08bbb907a7eccd240",
        .name         = "Inv Demo 3 (2001) (Erik Mooney) (PD)",
    },{
        .md5          = "adb79f9ac1a633cdd44954e2eac14774",
        .manufacturer = "Digivision",
        .name         = "Frostbite (Digivision)",
    },{
        .md5          = "adf1afac3bdd7b36d2eda5949f1a0fa3",
        .manufacturer = "Quelle - Otto Versand",
        .model        = "495.463 2 - 746381",
        .name         = "Angriff der Luftflotten (1983) (Quelle) (PAL)",
        .note         = "AKA Paris Attack, M.A.D.",
    },{
        .md5          = "adfbd2e8a38f96e03751717f7422851d",
        .manufacturer = "Champ Games",
        .model        = "CG-01-N",
        .name         = "Lady Bug (NTSC)",
        .phosphor     = 1,
    },{
        .md5          = "ae047e9468bda961d8e9e9d8ff52980f",
        .name         = "Tunnel Demo (Red Spiral) (30-03-2003) (Andrew Davie)",
    },{
        .md5          = "ae0d4f3396cb49de0fabdff03cb2756f",
        .manufacturer = "Retroactive",
        .name         = "Qb (V2.02) (PAL) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "ae10527840a1ac24de43730645ed508d",
        .manufacturer = "Charles Morgan",
        .name         = "Planet Invaders (Charles Morgan) (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "ae18c11e4d7ed2437f0bf5d167c0e96c",
        .name         = "Multi Demo 3 (Bob Colbert) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "ae2f1f69bb38355395c1c75c81acc644",
        .manufacturer = "Parker Brothers, Wilfredo Aguilar, Michael Becker, Neil McKenzie, Bob Smith, Brad Stewart",
        .model        = "PB5540",
        .name         = "Star Wars - The Arcade Game (12-23-1983) (Parker Bros) (Prototype) (4K)",
        .phosphor     = 1,
    },{
        .md5          = "ae465044dfba287d344ba468820995d7",
        .name         = "Inca Gold (Unknown) (PAL)",
    },{
        .md5          = "ae4be3a36b285c1a1dff202157e2155d",
        .manufacturer = "Spectravideo",
        .model        = "SA-210",
        .name         = "Master Builder (1983) (Spectravideo)",
    },{
        .md5          = "ae682886058cd6981c4b8e93e7b019cf",
        .manufacturer = "Retroactive",
        .name         = "Qb (V0.12) (PAL) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "ae6cb335470788b94beb5787976e8818",
        .name         = "Mortal Kurling (02-01-2003) (Christopher Tumber)",
    },{
        .md5          = "ae83541cf4a4c0bce0adccd2c1bf6288",
        .name         = "Maze 003 Demo (PD)",
    },{
        .md5          = "ae97cf8ed21f4154b4360a3cf6c95c5e",
        .name         = "Teleterm 2600 (John K. Harvey) (PD)",
    },{
        .md5          = "aeb104f1e7b166bc0cbaca0a968fde51",
        .name         = "Ms. Pac-Man (1999) (Hack)",
        .note         = "Hack of Ms. Pac-Man",
    },{
        .md5          = "aec9b885d0e8b24e871925630884095c",
        .manufacturer = "Amiga - Video Soft, Chip Curry",
        .model        = "3125",
        .name         = "Surf's Up (1983) (Amiga) (Prototype)",
        .note         = "Uses the Joyboard controller",
    },{
        .md5          = "aed0b7bd64cc384f85fdea33e28daf3b",
        .manufacturer = "Atari, Jim Huether, Alan J. Murphy, Robert C. Polaro",
        .model        = "CX2666",
        .name         = "RealSports Volleyball (1982) (Atari)",
    },{
        .md5          = "aed82052f7589df05a3f417bb4e45f0c",
        .manufacturer = "Atari, Warren Robinett - Sears",
        .model        = "CX2606 - 6-99825, 49-75112",
        .name         = "Slot Racers (1978) (Atari)",
    },{
        .md5          = "af6ab88d3d7c7417db2b3b3c70b0da0a",
        .manufacturer = "Activision, Larry Kaplan, David Crane",
        .model        = "AG-010, AG-010-04",
        .name         = "Kaboom! (1981) (Activision) (4K)",
        .note         = "Uses the Paddle Controllers (left only)",
    },{
        .md5          = "af6f3e9718bccfcd8afb421f96561a34",
        .manufacturer = "Atari, Tod Frye",
        .model        = "CX2695",
        .name         = "Xevious (01-18-1984) (Atari) (Prototype)",
    },{
        .md5          = "afb3bc45c6a82739cc82582127cd96e6",
        .manufacturer = "Atari - Sculptured Software, Adam Clayton",
        .model        = "CX26151, CX26151P",
        .name         = "Dungeon (11-22-1985) (Atari) (Prototype)",
        .note         = "Dark Chambers Beta",
    },{
        .md5          = "afc194534c1b346609ef05eff6d3cef6",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Boxing (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "afd2cf258d51ae4965ee21abba3627ab",
        .manufacturer = "Atari - CCW, Christopher H. Omarzu",
        .model        = "CX26104",
        .name         = "Big Bird's Egg Catch (12-08-1982) (Atari) (Prototype)",
        .note         = "Uses the Keyboard Controller",
        .left         = "KEYBOARD",
    },{
        .md5          = "afe4eefc7d885c277fc0649507fbcd84",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Ant Party (32 in 1) (1988) (Atari) (PAL)",
        .note         = "AKA Cosmic Swarm",
        .phosphor     = 1,
    },{
        .md5          = "afe776db50e3378cd6f29c7cdd79104a",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Bobby is Going Home (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "afe88aae81d99e0947c0cfb687b16251",
        .manufacturer = "Apollo - Games by Apollo",
        .model        = "AP-2006",
        .name         = "Infiltrate (1982) (Apollo)",
        .phosphor     = 1,
    },{
        .md5          = "aff8cba0f2d2eb239953dd7116894a08",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum",
        .model        = "AR-4400",
        .name         = "Dragonstomper (3 of 3) (1982) (Starpath) (PAL)",
    },{
        .md5          = "b00088418fc891f3faa3d4ddde6ace94",
        .name         = "Unknown Title (bin00007 (200102)) (PD)",
    },{
        .md5          = "b00a8bc9d7fe7080980a514005cbad13",
        .manufacturer = "K-Tel Vision",
        .name         = "Vulture Attack (1982) (K-Tel Vision) (PAL)",
        .note         = "AKA Condor Attack",
    },{
        .md5          = "b00e8217633e870bf39d948662a52aac",
        .manufacturer = "Konami",
        .model        = "RC 102-X 02",
        .name         = "Marine Wars (1983) (Konami)",
    },{
        .md5          = "b011d8fdc450597c0762c2c0010a9b17",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Amiga Mouse Hack v1.3 (NTSC) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "b049fc8ac50be7c2f28418817979c637",
        .manufacturer = "Activision - Imagineering, Dan Kitchen, David Lubar",
        .model        = "EAK-048-04, EAK-048-04B",
        .name         = "River Raid II (1988) (Activision) (PAL)",
    },{
        .md5          = "b06050f686c6b857d0df1b79fea47bb4",
        .manufacturer = "Activision",
        .model        = "AIZ-001",
        .name         = "Moonsweeper (1988) (Activision)",
        .phosphor     = 1,
    },{
        .md5          = "b061e98a4c854a672aadefa233236e51",
        .manufacturer = "Atari, Warren Robinett",
        .model        = "CX2620, CX2620P",
        .name         = "Basic Programming (1979) (Atari) (PAL)",
        .note         = "Uses Keyboard Controllers",
        .phosphor     = 1,
    },{
        .md5          = "b095009004df341386d22b2a3fae3c81",
        .name         = "Sub-Scan (Unknown) (PAL)",
    },{
        .md5          = "b09b79c9628878be051e89f7f1e77378",
        .manufacturer = "Activision, Larry Kaplan, David Crane - Ariola",
        .model        = "EAG-010, PAG-010 - 711 010-720",
        .name         = "Kaboom! (1981) (Activision) (PAL) (4K)",
        .note         = "Uses the Paddle Controllers (left only)",
    },{
        .md5          = "b0a9c6f6c8014c4023e0341ba11ca35e",
        .manufacturer = "The Atari 2600 Connection - John K. Harvey, Tim Duarte",
        .model        = "v75",
        .name         = "Mean Santa (2009) (PAL)",
        .note         = "Released in 2019",
    },{
        .md5          = "b0ba51723b9330797985808db598fc31",
        .manufacturer = "Atari, Michael Callahan, Preston Stuart",
        .model        = "CX26103",
        .name         = "Alpha Beam with Ernie (1983) (Atari) (PAL) [a]",
    },{
        .md5          = "b0c47e426c7f799aee2c40422df8f56a",
        .name         = "Space Treat (PAL) (Fabrizio Zavagli)",
    },{
        .md5          = "b0c9cf89a6d4e612524f4fd48b5bb562",
        .manufacturer = "Atari - GCC",
        .model        = "CX2663",
        .name         = "Combat Two (1982) (Atari) (Prototype)",
        .note         = "AKA Super Combat",
    },{
        .md5          = "b0e1ee07fbc73493eac5651a52f90f00",
        .manufacturer = "Colin Hughes",
        .name         = "Tetris 2600 (Colin Hughes)",
        .phosphor     = 1,
    },{
        .md5          = "b1276417fb0f79bc52e741bb8f4d8360",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Marble Craze - Amiga Mouse Hack v1.0 (NTSC) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controllers",
    },{
        .md5          = "b129d7541cff79ebe33852a83057c524",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Marble Craze - Atari Trak-Ball Hack v1.0 (NTSC) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controllers",
    },{
        .md5          = "b12a7f63787a6bb08e683837a8ed3f18",
        .manufacturer = "Imagic, Rob Fulop",
        .model        = "720000-200, 720101-1B, 720101-1C, IA3200, IA3200C, IX-006-04",
        .name         = "Demon Attack (1982) (Imagic) [fixed]",
        .note         = "AKA Death from Above",
    },{
        .md5          = "b1339c56a9ea63122232fe4328373ac5",
        .manufacturer = "Goliath - Hot Shot",
        .model        = "83-215",
        .name         = "Dream Flight (1983) (Goliath) (PAL)",
        .note         = "AKA Nightmare",
    },{
        .md5          = "b1486e12de717013376447ac6f7f3a80",
        .manufacturer = "Spectravideo, Mark Turmell, Quelle",
        .model        = "SA-217, SA-217C - 413.723 8",
        .name         = "Gas Hog - Piraten Schiff (1983) (Spectravideo) (PAL)",
    },{
        .md5          = "b15026b43c6758609667468434766dd8",
        .manufacturer = "Retroactive",
        .name         = "Qb (0.06) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "b16cd9784589219391c839cb68c47b9c",
        .manufacturer = "Video Soft, Jerry Lawson, Dan McElroy",
        .name         = "Golf Diagnostic (1983) (Video Soft) (Prototype)",
    },{
        .md5          = "b17b9cc4103844dcda54f77f44acc93a",
        .manufacturer = "Quelle",
        .model        = "377.943 6",
        .name         = "Stopp die Gangster (1983) (Quelle) (PAL)",
        .note         = "AKA Gangster Alley",
    },{
        .md5          = "b182d9708e00709830caab9cf8205ca0",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Atari Mouse Hack v1.3 (PAL60) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "b1a6c96e9093352106bc335e96caa154",
        .manufacturer = "Joe Grand",
        .name         = "SCSIcide Pre-release 1 (Joe Grand)",
    },{
        .md5          = "b1b20536aef4eed9c79dc5804f077862",
        .name         = "Euchre (NTSC) (09-11-2001) (Erik Eid)",
    },{
        .md5          = "b1c14b5ac896400cc91c8e5dd67acb59",
        .name         = "River Raid (Unknown) (PAL) (Hack)",
    },{
        .md5          = "b1d1e083dc9e7d9a5dc1627869d2ade7",
        .manufacturer = "CCE",
        .model        = "C-1004",
        .name         = "Mario's Bros. (1983) (CCE)",
        .note         = "AKA Mario Bros.",
    },{
        .md5          = "b1e2d5dc1353af6d56cd2fe7cfe75254",
        .manufacturer = "Atari - Axlon, Steve DeFrisco",
        .model        = "CX26171",
        .name         = "MotoRodeo (1991) (Atari) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "b1fd0b71de9f6eeb5143a97963674cb6",
        .name         = "Multi Demo 7 (Bob Colbert) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "b227175699e372b8fe10ce243ad6dda5",
        .manufacturer = "Atari, Brad Stewart - Sears",
        .model        = "CX2649, 49-75163",
        .name         = "Asteroids (1981) (Atari) [a1]",
        .phosphor     = 1,
    },{
        .md5          = "b23ebf427713dd0198b7ef47dbd07ef4",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Sky Diver (Jone Yuan) (4K) (Hack)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "b24f6a5820a4b7763a3d547e3e07441d",
        .manufacturer = "CCE",
        .model        = "C-823",
        .name         = "Demon Attack (1983) (CCE)",
    },{
        .md5          = "b25841173f058380b1771aacd5e7cdf3",
        .manufacturer = "Bit Corporation",
        .model        = "PG205",
        .name         = "Dancing Plate (1982) (BitCorp)",
    },{
        .md5          = "b26506fbf411009e5e3f7365f442960e",
        .manufacturer = "Atari, Alan Miller",
        .model        = "CX2642",
        .name         = "Hunt & Score (1978) (Atari) (PAL) (4K)",
        .note         = "Uses the Keyboard Controllers",
    },{
        .md5          = "b2737034f974535f5c0c6431ab8caf73",
        .manufacturer = "CBS Electronics, Richard K. Balaska Jr., Andy Frank, Stuart Ross",
        .model        = "4L 2520 5000",
        .name         = "Tunnel Runner (1983) (CBS Electronics)",
    },{
        .md5          = "b2761efb8a11fc59b00a3b9d78022ad6",
        .manufacturer = "Atari, Bob Whitehead - Sears",
        .model        = "CX2651 - 99805, 49-75602",
        .name         = "Blackjack (1977) (Atari) (4K)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXIS",
    },{
        .md5          = "b290c2b139344fcff5b312c71b9ac3b2",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "UFO (32 in 1) (1988) (Atari) (PAL) (4K)",
        .note         = "AKA Space Jockey",
    },{
        .md5          = "b29359f7de62fed6e6ad4c948f699df8",
        .manufacturer = "Goliath",
        .model        = "3",
        .name         = "Phantom Tank (1983) (Goliath) (PAL)",
    },{
        .md5          = "b2a6f31636b699aeda900f07152bab6e",
        .name         = "Space Instigators (Public Release 2) (06-01-2003) (Christopher Tumber)",
    },{
        .md5          = "b2ab209976354ad4a0e1676fc1fe5a82",
        .manufacturer = "Atari - Axlon, Tod Frye - Heuristica, Agustin Ortiz Valdiviezo",
        .model        = "CX26169",
        .name         = "Shooting Arcade (03-07-1989) (Atari) (Prototype) [screen 4]",
        .note         = "Uses the Light Gun Controller (left only)",
    },{
        .md5          = "b2d1e63f7f22864096b7b6c154151d55",
        .manufacturer = "Fabrizio Zavagli",
        .name         = "Bounce! (17-03-2003) (Fabrizio Zavagli)",
        .phosphor     = 1,
    },{
        .md5          = "b2d3bcee001cff2bd2d8a21b2cb55109",
        .manufacturer = "Atari - GCC, Mike Feinstein, Kevin Osborn",
        .model        = "CX2691",
        .name         = "Joust (08-09-1983) (Atari) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "b2d5d200f0af8485413fad957828582a",
        .manufacturer = "Atari - Bobco, Robert C. Polaro",
        .model        = "CX26155P",
        .name         = "Sprint Master (1988) (Atari) (PAL)",
        .note         = "AKA Sprint 88, Sprint 2000",
    },{
        .md5          = "b2f0d7217147160b2f481954cedf814b",
        .name         = "Marquee Drawer (2001) (B. Watson)",
        .phosphor     = 1,
    },{
        .md5          = "b2ff4327d305fb473dfa474e0dc3701b",
        .manufacturer = "Fotomania",
        .name         = "Demon Attack (Fotomania)",
    },{
        .md5          = "b3017e397f74efd53caf8fae0a38e3fe",
        .manufacturer = "Retroactive",
        .name         = "Qb (2.12) (Retroactive) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "b311ab95e85bc0162308390728a7361d",
        .manufacturer = "Parker Brothers - Roklan, Joe Gaucher",
        .model        = "PB5080",
        .name         = "Gyruss (1984) (Parker Bros)",
        .phosphor     = 1,
    },{
        .md5          = "b31dc989f594764eacfa7931cead0050",
        .manufacturer = "Arcadia Corporation, Steve Mundry, Scott Nelson",
        .model        = "AR-4401",
        .name         = "Survival Island (2 of 3) (1983) (Arcadia)",
    },{
        .md5          = "b31e9487efc06f18dfc3d7ebadf54416",
        .manufacturer = "Omegamatrix",
        .name         = "Star Wars Arcade (Atari Mouse) v4 (PAL60) (Omegamatrix)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "b31f178aa0d569cccac7959f84e0a724",
        .manufacturer = "Atari, Jerome Domurat, Steve Woita",
        .model        = "CX2699",
        .name         = "Taz (07-13-1983) (Atari) (Prototype)",
    },{
        .md5          = "b3203e383b435f7e43f9492893c7469f",
        .manufacturer = "Gameworld",
        .model        = "133-003",
        .name         = "Sssnake (1983) (Gameworld) (PAL)",
    },{
        .md5          = "b36040a2f9ecafa73d835d804a572dbf",
        .manufacturer = "Digitel",
        .name         = "Pac Man (1983) (Digitel)",
        .note         = "AKA Pac-Man",
    },{
        .md5          = "b37f0fe822b92ca8f5e330bf62d56ea9",
        .manufacturer = "Xonox - K-Tel Software - Beck-Tech, Steve Beck",
        .model        = "6210, 7210, 06003. 99001",
        .name         = "Spike's Peak (1983) (Xonox) (PAL)",
    },{
        .md5          = "b392964e8b1c9c2bed12246f228011b2",
        .name         = "Name This Game (Unknown) (PAL)",
    },{
        .md5          = "b4030c38a720dd84b84178b6ce1fc749",
        .manufacturer = "M Network - APh Technological Consulting, Kevin Miller",
        .model        = "MT5687",
        .name         = "International Soccer (1982) (M Network)",
    },{
        .md5          = "b40dea357d41c5408546e4e4d5f27779",
        .manufacturer = "Digivision",
        .name         = "Spider Fighter (Digivision)",
    },{
        .md5          = "b41fdd4a522e1d5a2721840028684ac2",
        .name         = "Green and Yellow Number 1 Demo 2 (PD)",
        .phosphor     = 1,
    },{
        .md5          = "b42df8d92e3118dc594cecd575f515d7",
        .manufacturer = "Mystique - American Multiple Industries",
        .model        = "1003",
        .name         = "Burning Desire (1982) (Mystique) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "b4362c4eb535eda58079e2a1a6a45707",
        .name         = "Exocet (Unknown) (PAL)",
    },{
        .md5          = "b438a6aa9d4b9b8f0b2ddb51323b21e4",
        .manufacturer = "Telegames",
        .model        = "5861 A030",
        .name         = "Bogey Blaster (1988) (Telegames) (PAL)",
        .note         = "AKA Air Raiders",
    },{
        .md5          = "b451307b8b5e29f1c5f2cf064f6c7227",
        .name         = "Demo Image Series #6 - Mario (Fixed) (26-02-2003) (Andrew Davie)",
    },{
        .md5          = "b49331b237c8f11d5f36fe2054a7b92b",
        .name         = "Condor Attack (Unknown) (PAL)",
    },{
        .md5          = "b4a4c87840613f102acb5b3a647d0a67",
        .name         = "Mobile 48 Sprite Kernel (04-01-2003) (Eric Ball)",
    },{
        .md5          = "b4daedb43511521db9036d503b3c1b69",
        .name         = "Sokoban (01-01-2003) (Adam Wozniak) [a1]",
    },{
        .md5          = "b4e2fd27d3180f0f4eb1065afc0d7fc9",
        .manufacturer = "Avalon Hill, Jean Baer, Bill 'Rebecca Ann' Heineman, William O. Sheppard",
        .model        = "5002002",
        .name         = "London Blitz (1983) (Avalon Hill)",
    },{
        .md5          = "b4f05e544834d0238a0c263491775edf",
        .manufacturer = "Starpath Corporation, Steve Hales, Stephen H. Landrum",
        .model        = "4 AR-4102",
        .name         = "Suicide Mission (Preview) (1982) (Starpath) (PAL)",
        .note         = "AKA Meteoroids",
        .phosphor     = 1,
    },{
        .md5          = "b4f31ea8a6cc9f1fd4d5585a87c3b487",
        .manufacturer = "Mystique - American Multiple Industries, Joel H. Martin",
        .name         = "Beat 'Em & Eat 'Em (1982) (Mystique) (PAL)",
        .note         = "Uses the Paddle Controller (left only)",
    },{
        .md5          = "b4f87ce75f7329c18301a2505fe59cd3",
        .manufacturer = "Videospielkassett - Ariola",
        .model        = "PGP232",
        .name         = "Autorennen (Ariola) (PAL)",
        .note         = "AKA Grand Prix",
    },{
        .md5          = "b50ae55aac93fbed258bc5a873edd2cb",
        .manufacturer = "Recompile",
        .name         = "E.T. The Extra-Terrestrial (Recompile) (Hack)",
        .note         = "www.neocomputer.org/projects/et",
    },{
        .md5          = "b5110f55ed99d5279f18266d001a8cd5",
        .manufacturer = "Eckhard Stolberg",
        .name         = "Auto-mobile Demo (2001) (Eckhard Stolberg)",
    },{
        .md5          = "b56264f738b2eb2c8f7cf5a2a75e5fdc",
        .manufacturer = "Atari - GCC, John Allred, Douglas B. Macrae, Betty Ryan Tylko",
        .model        = "CX2694, CX2694P",
        .name         = "Pole Position (1983) (Atari) (PAL)",
        .note         = "AKA RealSports Driving",
    },{
        .md5          = "b5657d4c1c732fbb6af150668464247f",
        .manufacturer = "Arcadia Corporation, Stephen H. Landrum",
        .model        = "AR-4400",
        .name         = "Excalibur (Dragonstomper Beta) (1982) (Arcadia) (Prototype)",
    },{
        .md5          = "b59417d083b0be2d49a7d93769880a4b",
        .manufacturer = "Pet Boat",
        .name         = "Donkey Kong (1983) (Pet Boat) (PAL)",
    },{
        .md5          = "b59fd465abf76f64c85652ff29d5952d",
        .manufacturer = "VentureVision, Dan Oliver",
        .name         = "Innerspace (1983) (VentureVision) (Prototype)",
    },{
        .md5          = "b5a1a189601a785bdb2f02a424080412",
        .manufacturer = "Imagic, Dennis Koble",
        .model        = "720021-1A, IA3410",
        .name         = "Shootin' Gallery (1983) (Imagic)",
    },{
        .md5          = "b5cb9cf6e668ea3f4cc2be00ea70ec3c",
        .manufacturer = "CommaVid, Irwin Gaines - Ariola",
        .model        = "CM-005 - 712 005-720",
        .name         = "Mines of Minos (1982) (CommaVid) (PAL)",
        .note         = "AKA Im Labyrinth des Roboters",
        .phosphor     = 1,
    },{
        .md5          = "b5cdbab514ea726a14383cff6db40e26",
        .manufacturer = "Video Gems",
        .model        = "VG-04",
        .name         = "Mission Survive (1983) (Video Gems) (PAL) [louder sounds]",
        .phosphor     = 1,
    },{
        .md5          = "b5efe0271d2214e4d5dc798881486884",
        .manufacturer = "Atari - Axlon, Steve DeFrisco",
        .model        = "CX26192",
        .name         = "Klax (06-14-1990) (Atari) (Prototype)",
    },{
        .md5          = "b6166f15720fdf192932f1f76df5b65d",
        .manufacturer = "Amiga - Video Soft, Frank Ellis",
        .model        = "3130",
        .name         = "Off Your Rocker (1983) (Amiga) (Prototype)",
        .note         = "Uses the Amiga Joyboard",
    },{
        .md5          = "b64426e787f04ff23ee629182c168603",
        .manufacturer = "Dynacom",
        .name         = "Plaque Attack (1983) (Dynacom)",
    },{
        .md5          = "b65d4a38d6047735824ee99684f3515e",
        .manufacturer = "Dynacom",
        .name         = "MegaBoy (Dynacom)",
    },{
        .md5          = "b676a9b7094e0345a76ef027091d916b",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Mission Survive (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
        .phosphor     = 1,
    },{
        .md5          = "b6812eaf87127f043e78f91f2028f9f4",
        .manufacturer = "Simage",
        .name         = "Eli's Ladder (1984) (Simage)",
    },{
        .md5          = "b6821ac51c4c1dcb283f01be2f047dc1",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Rubik's Cube 3D Demo (25-11-2002) (Thomas Jentzsch)",
    },{
        .md5          = "b6960be26bee87d53ba4e2e71cfe772f",
        .name         = "3-D Corridor (Spiral Words) (31-03-2003) (Andrew Davie)",
    },{
        .md5          = "b6d52a0cf53ad4216feb04147301f87d",
        .manufacturer = "Imagic, Michael Greene",
        .model        = "720055-1A, IA3312",
        .name         = "No Escape! (1983) (Imagic)",
    },{
        .md5          = "b6e40bce550672e5495a8cdde7075b8b",
        .manufacturer = "Arcadia Corporation, Steve Mundry, Scott Nelson",
        .model        = "AR-4401",
        .name         = "Survival Island (1 of 3) (1983) (Arcadia) (PAL)",
    },{
        .md5          = "b702641d698c60bcdc922dbd8c9dd49c",
        .manufacturer = "Atari, Ian Shepard",
        .model        = "CX26163P",
        .name         = "Space War (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "b719ada17771a8d206c7976553825139",
        .manufacturer = "Ron Corcoran",
        .name         = "DUP Space Invaders (Ron Corcoran) (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "b731d35e4ac6b3b47eba5dd0991f452f",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Rubik's Cube 3D Demo (Final) (08-01-2003) (Thomas Jentzsch)",
    },{
        .md5          = "b7345220a0c587f3b0c47af33ebe533c",
        .manufacturer = "Quelle",
        .model        = "176.433 1",
        .name         = "Landungskommando (1983) (Quelle) (PAL)",
        .note         = "AKA Strategy X",
    },{
        .md5          = "b76fbadc8ffb1f83e2ca08b6fb4d6c9f",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AG-005, CAG-005, AG-005-04",
        .name         = "Skiing (1980) (Activision)",
    },{
        .md5          = "b77468d586957d1b7fb4cccda2684f47",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Boxing (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "b77dc19183a8fb857c601074f53f6d81",
        .manufacturer = "Fotomania",
        .name         = "Bobby Is Going Home (Fotomania)",
    },{
        .md5          = "b7903268e235310dc346a164af4c7022",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Cat Trax (Thomas Jentzsch) (PAL60)",
        .note         = "NTSC Conversion",
        .phosphor     = 1,
    },{
        .md5          = "b79fe32320388a197ac3a0b932cc2189",
        .manufacturer = "Imagic, Bob Smith",
        .model        = "13207, EIZ-001-04I",
        .name         = "Moonsweeper (1983) (Imagic) (PAL) [a]",
        .phosphor     = 1,
    },{
        .md5          = "b7a7e34e304e4b7bc565ec01ba33ea27",
        .manufacturer = "Parker Brothers",
        .model        = "PB5820",
        .name         = "Mr. Do!'s Castle (1984) (Parker Bros) [a]",
        .phosphor     = 1,
    },{
        .md5          = "b7b1d3ce07e75976c43a2dca3866237e",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Freeway Chicken (32 in 1) (1988) (Atari) (PAL) (4K)",
        .note         = "AKA Freeway",
    },{
        .md5          = "b7d0aae399781b3c18679debda6d32b1",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Three.s (v1.02)",
    },{
        .md5          = "b7d7c76e37f372f4e4979b380ed95a58",
        .manufacturer = "AtariAge - Michael Haas",
        .model        = "RC2",
        .name         = "Flappy (2014) (AtariAge) (PAL60)",
    },{
        .md5          = "b7e459d5416eeb196aaa8e092db14463",
        .name         = "Push (V0.02) (1998) (Andrew Davie)",
    },{
        .md5          = "b7f184013991823fc02a6557341d2a7a",
        .name         = "Blue Rod Demo (PD)",
    },{
        .md5          = "b80d50ecee73919a507498d0a4d922ae",
        .manufacturer = "20th Century Fox Video Games - Sirius Software, David Lubar",
        .model        = "11008",
        .name         = "Fantastic Voyage (1982) (20th Century Fox)",
    },{
        .md5          = "b816296311019ab69a21cb9e9e235d12",
        .manufacturer = "Atari, Bob Whitehead - Sears",
        .model        = "CX2652 - 6-99816, 49-75151",
        .name         = "Casino (1979) (Atari)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXIS",
    },{
        .md5          = "b822fba8b7c8a97ea4e92aeb2c455ef9",
        .manufacturer = "Dactari",
        .name         = "Freeway (Dactari) (4K)",
    },{
        .md5          = "b83579c4450fcbdf2b108903731fa734",
        .name         = "Mission 3,000 A.D. (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "b83df1f32b4539c324bdf94851b4db55",
        .manufacturer = "Angelino",
        .name         = "One On One by Angelino (Basketball Hack)",
        .note         = "Hack of Basketball (1978) (Atari)",
    },{
        .md5          = "b86552198f52cfce721bafb496363099",
        .manufacturer = "Apollo, Tim Martin",
        .model        = "AP-2007",
        .name         = "Kyphus (1982) (Apollo) (Prototype)",
    },{
        .md5          = "b86a12e53ab107b6caedd4e0272aa034",
        .name         = "Pitfall! (Unknown)",
        .note         = "Pitfall Harry's Jungle Adventure",
    },{
        .md5          = "b879e13fd99382e09bcaf1d87ad84add",
        .manufacturer = "Zellers",
        .name         = "Time Warp (Zellers)",
    },{
        .md5          = "b8865f05676e64f3bec72b9defdacfa7",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-004",
        .name         = "Fishing Derby (1980) (Activision)",
    },{
        .md5          = "b897f9e3f939b9f21566d56db812a84e",
        .manufacturer = "Atari, Jim Huether",
        .model        = "CX26163P",
        .name         = "Flag Capture (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "b8e715223ba65cf716b3620a90ca3ec1",
        .manufacturer = "Parker Brothers",
        .model        = "PB5820",
        .name         = "Mr. Do!'s Castle (1984) (Parker Bros) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "b8ed78afdb1e6cfe44ef6e3428789d5f",
        .manufacturer = "Data Age, J. Ray Dettling",
        .model        = "112-007",
        .name         = "Bermuda Triangle (1983) (Data Age)",
    },{
        .md5          = "b9232c1de494875efe1858fc8390616d",
        .manufacturer = "Panda",
        .model        = "110",
        .name         = "Harbor Escape (1983) (Panda)",
        .note         = "AKA River Raid",
    },{
        .md5          = "b9336ed6d94a5cc81a16483b0a946a73",
        .manufacturer = "Atari, Jerome Domurat, Michael Sierchio",
        .model        = "CX2667, CX2667P",
        .name         = "RealSports Soccer (1983) (Atari) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "b9429824ab7ce3c1a83438f32af3f4e1",
        .name         = "Blackjack (Unknown) (PAL) [a]",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXIS",
    },{
        .md5          = "b955eb0e2baf7a437c186bddd4c49958",
        .manufacturer = "Atari, Omegamatrix",
        .name         = "Space Invaders Menu (2020) (PAL60) (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "b958d5fd9574c5cf9ece4b9421c28ecd",
        .manufacturer = "Piero Cavina",
        .name         = "Multi-Sprite Game V1.0 (Piero Cavina) (PD)",
    },{
        .md5          = "b95a6274ca0e0c773bfdc06b4c3daa42",
        .manufacturer = "Paul Slocum",
        .name         = "3-D Corridor (29-03-2003) (Paul Slocum)",
    },{
        .md5          = "b98cc2c6f7a0f05176f74f0f62c45488",
        .manufacturer = "Spectravideo",
        .model        = "SV-010",
        .name         = "CompuMate (1983) (Spectravideo)",
        .type         = "CM",
        .left         = "COMPUMATE",
        .right        = "COMPUMATE",
        .phosphor     = 1,
    },{
        .md5          = "b98cea78c084434f226993d5f6c8059a",
        .manufacturer = "Parker Brothers - On-Time Software, Joe Gaucher, Dan Kurczewski, Louis Marbel, Kathy Von",
        .model        = "PB5110",
        .name         = "James Bond 007 (1983) (Parker Bros) (Prototype) [a2]",
        .note         = "James Bond Agent 007",
    },{
        .md5          = "b9b4612358a0b2c1b4d66bb146767306",
        .manufacturer = "Commavid, Ben Burch",
        .model        = "CM-010",
        .name         = "Rush Hour (1983) (Commavid) (Prototype)",
    },{
        .md5          = "b9d1e3be30b131324482345959aed5e5",
        .manufacturer = "Activision - Boston Design Center, Rex Bradford",
        .name         = "Kabobber (07-25-1983) (Activision) (Prototype)",
    },{
        .md5          = "b9f6fa399b8cd386c235983ec45e4355",
        .manufacturer = "Parker Brothers, John Emerson",
        .model        = "931511",
        .name         = "Action Force (1983) (Parker Bros) (PAL)",
        .note         = "AKA G.I. Joe - Cobra Strike",
        .right        = "JOYSTICK",
    },{
        .md5          = "b9f9c0fed0db08c34346317f3957a945",
        .name         = "Chopper Command (Unknown) (PAL)",
    },{
        .md5          = "ba0d6ac9158a5c6a59431658d0df9486",
        .manufacturer = "Atari, Jerome Domurat, Steve Woita",
        .model        = "CX2696",
        .name         = "Asterix (08-01-1983) (Atari) (Prototype) (PAL)",
        .note         = "AKA Taz",
    },{
        .md5          = "ba257438f8a78862a9e014d831143690",
        .manufacturer = "U.S. Games Corporation - JWDA, Todd Marshall, Robin McDaniel, Henry Will IV",
        .model        = "VC2002",
        .name         = "Squeeze Box (1983) (U.S. Games)",
    },{
        .md5          = "ba317f83cdfcd58cbc65aac1ccb87bc5",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Jammed (2001) (XYPE) [a1]",
    },{
        .md5          = "ba3a17efd26db8b4f09c0cf7afdf84d1",
        .manufacturer = "Activision, Larry Miller",
        .model        = "AX-021",
        .name         = "Spider Fighter (1983) (Activision) (16K)",
    },{
        .md5          = "ba3b0eebccc7b791107de5b4abb671b4",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Thrust (V0.9) (2000) (Thomas Jentzsch)",
    },{
        .md5          = "ba657d940a11e807ff314bba2c8b389b",
        .manufacturer = "Activision, John Van Ryzin",
        .model        = "AG-038-04",
        .name         = "Cosmic Commuter (1984) (Activision) (16K)",
    },{
        .md5          = "bac28d06dfc03d3d2f4a7c13383e84ee",
        .manufacturer = "Supergame",
        .name         = "Demon Attack (Supergame)",
    },{
        .md5          = "bae1a23f9b6acdadf465cfb330ba0acb",
        .manufacturer = "Atari - GCC, Doug Macrae",
        .model        = "CX2677",
        .name         = "Dig Dug (1983) (Atari) [a]",
    },{
        .md5          = "bae66907c3200bc63592efe5a9a69dbb",
        .manufacturer = "Spectravision - Spectravideo - Quelle",
        .model        = "SA-201 - 412.783 3",
        .name         = "Gangster Alley (1982) (Spectravision) (PAL)",
    },{
        .md5          = "baf4ce885aa281fd31711da9b9795485",
        .manufacturer = "Atari, Douglas Neubauer",
        .model        = "CX26176",
        .name         = "Radar Lock (1989) (Atari)",
    },{
        .md5          = "bb18189021d58362d9e4d317cd2e28b7",
        .manufacturer = "Activision, David Crane - Ariola",
        .model        = "EAG-001, PAG-001, EAG-001-04B, EAG-001-04I - 711 001-715",
        .name         = "Dragster (1980) (Activision) (PAL) (4K)",
        .note         = "AKA Dragster Rennen",
    },{
        .md5          = "bb268fde5a210622a09e52af539930ed",
        .name         = "Infiltrate (Unknown) (PAL)",
    },{
        .md5          = "bb2b83fff97604f74ada565e0b5bae94",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Control - Atari Mouse Hack v1.15 (PAL60) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "bb5049e4558daade0f87fed69a244c59",
        .manufacturer = "Atari, Brad Stewart",
        .model        = "CX2649, CX2649P",
        .name         = "Asteroids (1981) (Atari) (PAL) [no copyright]",
        .phosphor     = 1,
    },{
        .md5          = "bb579404924c40ca378b4aff6ccf302d",
        .name         = "Lightbulb Lightens, The (PD) (Non Functional)",
    },{
        .md5          = "bb6a5a2f7b67bee5d1f237f62f1e643f",
        .name         = "Demo Image Series #5 - Animegirl (19-02-2003) (Andrew Davie)",
    },{
        .md5          = "bb745c893999b0efc96ea9029e3c62ca",
        .manufacturer = "Play Video",
        .name         = "Planet Patrol (1982) (Play Video) (PAL)",
    },{
        .md5          = "bb756aa98b847dddc8fc170bc79f92b2",
        .name         = "Golf (Unknown) (PAL)",
    },{
        .md5          = "bb9112d478a1a922d2c289a752bba695",
        .manufacturer = "Omegamatrix",
        .name         = "SpaceMaster X-7 (Amiga Mouse) (Omegamatrix)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "bbe40e0a59628a35e9288fe8b3de7b9f",
        .name         = "Keystone Kapers (Unknown) (PAL) [a]",
    },{
        .md5          = "bbf8c7c9ed280151934aabe138e41ba7",
        .manufacturer = "Amiga",
        .model        = "1130",
        .name         = "Power Play Arcade Video Game Album V (1984) (Amiga) (Prototype)",
        .note         = "Mogul Maniac, Surf's Up, Off Your Rocker, S.A.C. Alert",
    },{
        .md5          = "bc24440b59092559a1ec26055fd1270e",
        .name         = "Private Eye (1984) (Activision) [a]",
    },{
        .md5          = "bc3057a35319aae3a5cd87a203736abe",
        .manufacturer = "CCE",
        .model        = "C-845",
        .name         = "Time Warp (1983) (CCE)",
    },{
        .md5          = "bc33c685e6ffced83abe7a43f30df7f9",
        .manufacturer = "Dynacom",
        .name         = "Seaquest (1983) (Dynacom)",
    },{
        .md5          = "bc4cf38a4bee45752dc466c98ed7ad09",
        .manufacturer = "Atari, Douglas Neubauer, Mimi Nyden",
        .model        = "CX26136",
        .name         = "Solaris (1986) (Atari) (PAL)",
        .note         = "AKA The Last Starfighter, Star Raiders II, Universe",
    },{
        .md5          = "bc526185ad324241782dc68ba5d0540b",
        .name         = "Dodge Demo 1 (PD)",
    },{
        .md5          = "bc5389839857612cfabeb810ba7effdc",
        .manufacturer = "Atari, Tod Frye",
        .model        = "CX2671",
        .name         = "SwordQuest - WaterWorld (1983) (Atari)",
    },{
        .md5          = "bc593f2284c67b7d8716d110f541953f",
        .manufacturer = "Simone Serra - AtariAge",
        .model        = "30.11.2011",
        .name         = "Omicron",
    },{
        .md5          = "bc703ea6afb20bc089f04d8c9d79a2bd",
        .name         = "Gunfight 2600 - Not mergeable with Colbert wizardry... (2001) (Manuel Rotschkar)",
    },{
        .md5          = "bc97d544f1d4834cc72bcc92a37b8c1b",
        .name         = "Sky Demo (PD)",
    },{
        .md5          = "bcb31f22856b0028c00d12f0e4c0a952",
        .manufacturer = "Canal 3 - Intellivision",
        .model        = "C 3051",
        .name         = "Thunderground (Canal 3)",
    },{
        .md5          = "bcb73b534ed7c613ac379ecd726effb5",
        .manufacturer = "Bob Montgomery (aka vdub_bobby)",
        .name         = "Squish 'Em (2007) (PAL60)",
    },{
        .md5          = "bccb4e2cfad5efc93f6d55dc992118ce",
        .manufacturer = "Activision, Carol Shaw",
        .model        = "AX-020, AX-020-04",
        .name         = "River Raid (1982) (Activision) (8K)",
    },{
        .md5          = "bce4c291d0007f16997faa5c4db0a6b8",
        .manufacturer = "Quelle",
        .model        = "292.651 7",
        .name         = "Weltraumtunnel (1983) (Quelle) (PAL)",
        .note         = "AKA Innerspace",
    },{
        .md5          = "bce93984b920e9b56cf24064f740fe78",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Checkers (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "bcef7880828a391cf6b50d5a6dcef719",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-009",
        .name         = "Bermuda, The (1983) (Rainbow Vision) (PAL)",
        .note         = "AKA River Raid",
    },{
        .md5          = "bd1bd6f6b928df17a702def0302f46f4",
        .name         = "Binary To Decimal Routine (2001) (Andrew Davie)",
    },{
        .md5          = "bd39598f067a1193ae81bd6182e756d1",
        .manufacturer = "Telegames",
        .name         = "Night Stalker (1988) (Telegames) (PAL)",
        .note         = "AKA Dark Cavern",
    },{
        .md5          = "bd430c2193045c68d1a20a018a976248",
        .name         = "Pac Ghost Sprite Demo 2 (PD)",
    },{
        .md5          = "bd551ff1264f5c367a3ad7cf0d2f266c",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "SpaceMaster X-7 (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "bda1463e02ae3a6e1107ffe1b572efd2",
        .manufacturer = "Atari, Nick 'Sandy Maiwald' Turner",
        .model        = "CX26111",
        .name         = "Snoopy and the Red Baron (1983) (Atari) (PAL) [a]",
    },{
        .md5          = "bdb4b584ddc90c9d2ec7e21632a236b6",
        .manufacturer = "Atari Freak 1",
        .name         = "Nitemare at Sunshine Bowl-a-Rama (Atari Freak 1) (Hack)",
        .note         = "Hack of Pac-Man Jr.",
    },{
        .md5          = "bdbaeff1f7132358ea64c7be9e46c1ac",
        .manufacturer = "20th Century Fox Video Games, Douglas 'Dallas North' Neubauer",
        .model        = "11105",
        .name         = "Mega Force (1982) (20th Century Fox) (PAL) [a]",
    },{
        .md5          = "bdbfd5f85421fd2a713258503123a4bc",
        .manufacturer = "Dactari - Milmar",
        .name         = "River Raid (1983) (Dactari)",
    },{
        .md5          = "bdc381baf7c252c63739c5e9ed087a5c",
        .name         = "Vertical Ship Demo 1 (PD)",
    },{
        .md5          = "bdc6ecf341705ab3ae4113a1a902fca3",
        .manufacturer = "Fotomania",
        .name         = "Atlantis (Fotomania)",
    },{
        .md5          = "bde78ccb6478664190921b6951ec7919",
        .manufacturer = "Parker Brothers - On-Time Software, Joe Gaucher, Dan Kurczewski, Louis Marbel, Kathy Von",
        .model        = "PB5110",
        .name         = "James Bond 007 (1983) (Parker Bros) (Prototype) [a5]",
        .note         = "James Bond Agent 007",
    },{
        .md5          = "bdecc81f740200780db04a107c3a1eba",
        .manufacturer = "Quelle",
        .model        = "874.254 6",
        .name         = "Super-Cowboy beim Rodeo (1983) (Quelle) (PAL)",
        .note         = "AKA Stampede",
    },{
        .md5          = "bdf1996e2dd64baf8eff5511811ca6ca",
        .manufacturer = "Tron",
        .name         = "H.E.R.O. (Tron)",
    },{
        .md5          = "be060a704803446c02e6f039ab12eb91",
        .manufacturer = "Parker Brothers, Rex Bradford, Sam Kjellman",
        .model        = "931501",
        .name         = "Star Wars - The Empire Strikes Back (1982) (Parker Bros) (PAL)",
    },{
        .md5          = "be1922bd8e09d74da471287e1e968653",
        .manufacturer = "Cropsy",
        .name         = "Hangman Pacman Demo (Cropsy) (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "be2870a0120fd28d25284e9ccdcbdc99",
        .name         = "Tomb Raider 2600 [REV 01] (Montezuma's Revenge Hack)",
    },{
        .md5          = "be35d8b37bbc03848a5f020662a99909",
        .manufacturer = "Atari, Joe Decuir, Steve Mayer, Larry Wagner - Sears",
        .model        = "CX2601 - 99801, 6-99801, 49-75124",
        .name         = "Combat (1977) (Atari) (4K) [a]",
    },{
        .md5          = "be3f0e827e2f748819dac2a22d6ac823",
        .manufacturer = "Puzzy - Bit Corporation",
        .model        = "PG202",
        .name         = "Space Tunnel (1982) (Puzzy)",
        .note         = "AKA Le Tunnel de L'Estace",
    },{
        .md5          = "be41463cd918daef107d249f8cde3409",
        .name         = "Berzerk (Voice Enhanced) (Hack)",
        .note         = "Hack of Berzerk",
    },{
        .md5          = "be561b286b6432cac71bccbae68002f7",
        .name         = "Counter Demo (PD)",
    },{
        .md5          = "be929419902e21bd7830a7a7d746195d",
        .manufacturer = "Activision, Garry Kitchen",
        .model        = "AX-025, AX-025-04",
        .name         = "Keystone Kapers (1983) (Activision)",
    },{
        .md5          = "becd908f9d7bb361982c3dc02d6475c6",
        .manufacturer = "Kyle Pittman",
        .name         = "THX-1138 (Kyle Pittman) (Hack)",
        .note         = "Hack of Berserk",
    },{
        .md5          = "bedfbde71fb606601f936b5b057f26f7",
        .manufacturer = "Activision, Garry Kitchen - Ariola",
        .model        = "EAX-025, EAX-025-04I - 711 025-725",
        .name         = "Keystone Kapers (1983) (Activision) (PAL) (16K)",
    },{
        .md5          = "befce0de2012b24fd6cb8b53c17c8271",
        .name         = "Push (V0.03) (No Illegal Opcodes) (1998) (Andrew Davie)",
    },{
        .md5          = "bf1970b692275b42c4ec0683588eb062",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Amiga Mouse Hack v1.3 (NTSC) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "bf52327c2197d9d2c4544be053caded1",
        .manufacturer = "HES - Activision",
        .model        = "AG-930-04, AZ-030",
        .name         = "Decathlon (HES) (PAL) (16K)",
        .note         = "AKA Activision Decathlon",
    },{
        .md5          = "bf84f528de44225dd733c0e6a8e400a0",
        .manufacturer = "CCE",
        .name         = "Demons to Diamonds (CCE)",
        .note         = "Uses the Paddle Controllers (left only)",
        .swapPaddles  = 1,
    },{
        .md5          = "bf976cf80bcf52c5f164c1d45f2b316b",
        .manufacturer = "Atari, Tod Frye, Mimi Nyden",
        .model        = "CX2657",
        .name         = "SwordQuest - FireWorld (1982) (Atari) (PAL)",
        .note         = "AKA Adventure II, SwordQuest II - FireWorld",
    },{
        .md5          = "bfa58198c6b9cd8062ee76a2b38e9b33",
        .name         = "20 Sprites at Once Demo 4 (PD)",
    },{
        .md5          = "bfb73aabb2489316cd5882c3cd11d9f9",
        .manufacturer = "AtariAge, Chris Walton & Thomas Jentzsch",
        .model        = "165",
        .name         = "Star Castle Arcade (2014) (AtariAge)",
        .phosphor     = 1,
    },{
        .md5          = "bfe14ea890d3a4e2293568c0fcce726f",
        .name         = "Challenge of.... Nexar, The (Unknown) (PAL) [a]",
    },{
        .md5          = "bff8f8f53a8aeb1ee804004ccbb08313",
        .name         = "Droid Demo 22 (David Conrad Schweinsberg) (PD)",
    },{
        .md5          = "bffe34516aaa3cbf5d307eab382a7e95",
        .name         = "Euchre (Release Candidate) (PAL) (28-09-2002) (Erik Eid)",
    },{
        .md5          = "c00734a2233ef683d9b6e622ac97a5c8",
        .manufacturer = "Atari, Jerome Domurat, Howard Scott Warshaw",
        .model        = "CX26133",
        .name         = "A-Team, The (03-30-1984) (Atari) (Prototype)",
        .note         = "AKA Saboteur",
    },{
        .md5          = "c00b65d1bae0aef6a1b5652c9c2156a1",
        .manufacturer = "Atari, Joe Decuir - Sears",
        .model        = "CX2621 - 99806, 6-99806, 49-75104",
        .name         = "Video Olympics (1977) (Atari) (4K)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXDR",
        .swapPaddles  = 1,
    },{
        .md5          = "c02e1afa0671e438fd526055c556d231",
        .manufacturer = "Atari",
        .name         = "A-Team (Atari) (Prototype) (PAL60)",
    },{
        .md5          = "c032c2bd7017fdfbba9a105ec50f800e",
        .manufacturer = "Activision, Charlie Heath",
        .name         = "Thwocker (04-09-1984) (Activision) (Prototype)",
    },{
        .md5          = "c033dc1d7b6fde41b9cadce9638909bb",
        .name         = "Skeleton (V1.1) (06-09-2002) (Eric Ball)",
    },{
        .md5          = "c0589bb73858924389077fa3c2e9441a",
        .manufacturer = "SOLID Corp. (D. Scott Williamson)",
        .model        = "CX2655-014",
        .name         = "Star Castle 2600 (SolidCorp) [014]",
        .phosphor     = 1,
    },{
        .md5          = "c05f367fa4767ceb27abadf0066df7f4",
        .manufacturer = "Thomas Jentzsch",
        .name         = "TomInv (31-07-2001) (Thomas Jentzsch)",
    },{
        .md5          = "c07e9a1af18261a80db55d0280a0fa95",
        .manufacturer = "Fotomania",
        .name         = "Frostbite (Fotomania)",
    },{
        .md5          = "c08d0cee43077d3055febb00e5745c1d",
        .manufacturer = "HES - Activision",
        .name         = "Super Hit Pak - River Raid, Sky Jinks, Grand Prix, Fishing Derby, Checkers (HES) (PAL)",
    },{
        .md5          = "c0a68837c60e15d1fc5a40c9a62894bc",
        .manufacturer = "Arcadia Corporation, Kevin Norman",
        .model        = "7 AR-4103",
        .name         = "Killer Satellites (1983) (Arcadia) (Prototype)",
    },{
        .md5          = "c0c7eddefce9015346db88ade3e1e096",
        .manufacturer = "CBS Electronics, Bob Curtiss",
        .model        = "4L 2487 5000",
        .name         = "Solar Fox (1983) (CBS Electronics) (Prototype) (4K)",
        .note         = "RAM must be zero'ed to start correctly",
        .phosphor     = 1,
    },{
        .md5          = "c0d2434348de72fa6edcc6d8e40f28d7",
        .manufacturer = "SEGA - Beck-Tech, Steve Beck",
        .model        = "010-01",
        .name         = "Tapper (1984) (SEGA)",
    },{
        .md5          = "c1034a5bfb0bb13cc5bdf86cc58989a7",
        .manufacturer = "Atari, Nick 'Sandy Maiwald' Turner",
        .model        = "CX2665",
        .name         = "Frog Pond (1982) (Atari) (Prototype) (4K) [a]",
    },{
        .md5          = "c118854d670289a8b5d5156aa74b0c49",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Skiing (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "c11e8473c652619ac6166900150ce215",
        .manufacturer = "AtariAge, Chris Walton",
        .model        = "1.0 (Release)",
        .name         = "Chetiry (2011) (AtariAge) (60k) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "c126656df6badfa519cc63e681fb3596",
        .manufacturer = "Ron Corcoran",
        .name         = "Space Invaders (2002) (Ron Corcoran) (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "c15042e54c7408498f051d782aaa8945",
        .manufacturer = "Omegamatrix",
        .name         = "Millipede (Atari Trak-Ball) v6.5 (Omegamatrix)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "c150c76cbde2c9b5a97eb5399d46c64f",
        .name         = "Unknown Title (xxx00000 (200203)) (PD)",
    },{
        .md5          = "c16c79aad6272baffb8aae9a7fff0864",
        .manufacturer = "U.S. Games Corporation - JWDA, Sylvia Day, Todd Marshall, Robin McDaniel, Henry Will IV",
        .model        = "VC2001",
        .name         = "Gopher (1982) (U.S. Games)",
        .note         = "AKA Gopher Attack",
    },{
        .md5          = "c16fbfdbfdf5590cc8179e4b0f5f5aeb",
        .name         = "Wall Break (Unknown)",
    },{
        .md5          = "c17bdc7d14a36e10837d039f43ee5fa3",
        .manufacturer = "Spectravision - Spectravideo",
        .model        = "SA-203",
        .name         = "Cross Force (1982) (Spectravision)",
    },{
        .md5          = "c1a83f44137ea914b495fc6ac036c493",
        .manufacturer = "Atari, Carla Meninsky",
        .model        = "CX2660",
        .name         = "Star Raiders (1982) (Atari) (PAL)",
        .note         = "Uses Joystick (left) and Keyboard (right) Controllers",
    },{
        .md5          = "c1b038ce5cb6d85e956c5509b0e0d0d8",
        .name         = "Rotating Colors Demo 2 (Junkosoft) (PD)",
    },{
        .md5          = "c1b1049b88bcd98437d8872d1d62ba31",
        .name         = "Demo Image Series #4 - Donald (19-02-2003) (Andrew Davie)",
    },{
        .md5          = "c1b7aeabc3ec41556d924c8372a9ba5b",
        .manufacturer = "Atari, Robert C. Polaro",
        .name         = "Dukes of Hazard (1980) (Atari) (Prototype)",
        .note         = "AKA Stunt Cycle",
    },{
        .md5          = "c1cb228470a87beb5f36e90ac745da26",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AX-015, AX-015-04",
        .name         = "Chopper Command (1982) (Activision)",
    },{
        .md5          = "c1e6e4e7ef5f146388a090f1c469a2fa",
        .manufacturer = "Bomb - Onbase",
        .model        = "CA283",
        .name         = "Z-Tack (1983) (Bomb)",
        .note         = "AKA Base Attack",
    },{
        .md5          = "c1f209d80f0624dada5866ce05dd3399",
        .manufacturer = "Telegames",
        .name         = "Deadly Discs (1988) (Telegames) (PAL)",
        .note         = "AKA TRON - Deadly Discs",
    },{
        .md5          = "c1f9f70ae527093b6af3b6531860e75d",
        .manufacturer = "CBS Electronics - Roklan, Joe Gaucher, Dan Kurczewski, Alex Leavens, Kathy Von",
        .model        = "M8776, M8793",
        .name         = "Gorf (1982) (CBS Electronics) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "c1fdd44efda916414be3527a47752c75",
        .manufacturer = "Parker Brothers, John Emerson",
        .model        = "PB5920",
        .name         = "G.I. Joe - Cobra Strike (1983) (Parker Bros)",
        .note         = "Uses the Paddle (left) and Joystick (right) Controllers",
        .right        = "JOYSTICK",
    },{
        .md5          = "c20f15282a1aa8724d70c117e5c9709e",
        .manufacturer = "Video Gems",
        .model        = "VG-02",
        .name         = "Surfer's Paradise (1983) (Video Gems) (PAL)",
    },{
        .md5          = "c21450c21efb7715746e9fa87ad6f145",
        .manufacturer = "Hozer Video Games",
        .name         = "Gunfight 2600 - It could've been soooo cool, but... (2001) (Manuel Rotschkar)",
    },{
        .md5          = "c216b91f5db21a093ded6a5aaec85709",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Dragster (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "c221607529cabc93450ef25dbac6e8d2",
        .manufacturer = "Eckhard Stolberg",
        .name         = "Color Test (26-09-2002) (Eckhard Stolberg)",
    },{
        .md5          = "c225379e7c4fb6f886ef9c8c522275b4",
        .manufacturer = "Video Mania",
        .name         = "Frostbite (1983) (Video Mania)",
    },{
        .md5          = "c225abfb584960efe1f359fc94b73379",
        .name         = "Joustpong (21-09-2002) (Kirk Israel) (PD)",
    },{
        .md5          = "c2410d03820e0ff0a449fa6170f51211",
        .name         = "Pac-Man (Unknown) (PAL) (Hack)",
    },{
        .md5          = "c246e05b52f68ab2e9aee40f278cd158",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Star Wars - Ewok Adventure (Thomas Jentzsch) (Prototype)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "c2778507b83d9540e9be5713758ff945",
        .name         = "Island Flyer Demo 2 (PD)",
    },{
        .md5          = "c28b29764c2338b0cf95537cc9aad8c9",
        .name         = "Multi Demo 4 (Bob Colbert) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "c29d17eef6b0784db4586c12cb5fd454",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "River Raid (Jone Yuan) (Hack)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "c29f8db680990cb45ef7fef6ab57a2c2",
        .manufacturer = "Parker Brothers - Roklan, Paul Crowley, Bob Curtiss",
        .model        = "PB5320",
        .name         = "Super Cobra (1983) (Parker Bros)",
    },{
        .md5          = "c2a37f1c7603c5fd97df47d6c562abfa",
        .manufacturer = "Roger Williams",
        .name         = "Bar-Score Demo (2001) (Roger Williams)",
    },{
        .md5          = "c2b5c50ccb59816867036d7cf730bf75",
        .manufacturer = "Salu - Avantgarde Software, Michael Buetepage",
        .model        = "460741",
        .name         = "Ghostbusters II (1992) (Salu) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "c2bcd8f2378c3779067f3a551f662bb7",
        .manufacturer = "Activision, Bob Whitehead - Ariola",
        .model        = "EAG-002, EAG-002-04I, PAG-002 - 711 002-715",
        .name         = "Boxing (1980) (Activision) (PAL) (4K)",
    },{
        .md5          = "c2c7a11717e255593e54d0acaf653ee5",
        .name         = "Chopper Command (Unknown) (PAL) (Hack)",
    },{
        .md5          = "c2c8eb642765137bb82b83a65232961f",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Challenge of... Nexar, The - Atari Mouse Hack v1.1 (PAL) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "c2dea467f4a02fa1f06d66f52bc12e6e",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Command Atari Trak-Ball Hack v1.3 (NTSC) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
        .phosphor     = 1,
    },{
        .md5          = "c2fbef02b6eea37d8df3e91107f89950",
        .manufacturer = "Champ Games",
        .model        = "CG-02-N",
        .name         = "Conquest Of Mars (NTSC)",
    },{
        .md5          = "c31a17942d162b80962cb1f7571cd1d5",
        .manufacturer = "Home Vision - Gem International Corp. - VDI",
        .model        = "VCS83112",
        .name         = "Sky Alien (1983) (Home Vision) (PAL)",
        .note         = "AKA Sky Aliem",
    },{
        .md5          = "c3205e3707f646e1a106e09c5c49c1bf",
        .name         = "Unknown Title (bin00003 (200206)) (PD)",
    },{
        .md5          = "c3472fa98c3b452fa2fd37d1c219fb6f",
        .manufacturer = "Atari, Carla Meninsky - Sears",
        .model        = "CX2637 - 49-75158",
        .name         = "Dodge 'Em (1980) (Atari) [a]",
    },{
        .md5          = "c370c3268ad95b3266d6e36ff23d1f0c",
        .manufacturer = "Atari, Alan Miller",
        .model        = "CX2641, CX2641P",
        .name         = "Surround (1977) (Atari) (PAL)",
    },{
        .md5          = "c3a9550f6345f4c25b372c42dc865703",
        .manufacturer = "Atari - Bobco, Robert C. Polaro",
        .model        = "CX2663",
        .name         = "Road Runner (1989) (Atari) (PAL)",
    },{
        .md5          = "c3aeb796fdaf9429e8cd6af6346f337e",
        .name         = "If It's Not One Thing It's Another (1997) (Chris Cracknell)",
    },{
        .md5          = "c3bbc673acf2701b5275e85d9372facf",
        .manufacturer = "Atari, Robert C. Polaro",
        .model        = "CX26157",
        .name         = "Stunt Cycle (07-21-1980) (Atari) (Prototype)",
    },{
        .md5          = "c3e4aa718f46291311f1cce53e6ccd79",
        .name         = "Hangman Ghost 4letter (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "c3ef5c4653212088eda54dc91d787870",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AG-002, CAG-002, AG-002-04",
        .name         = "Boxing (1980) (Activision)",
    },{
        .md5          = "c3f53993ade534b0982ca3a286c85bb5",
        .name         = "Full Screen Bitmap Drawing System (12-02-2003) (Andrew Davie)",
    },{
        .md5          = "c405655354a9b674203b97f22fc31d8f",
        .manufacturer = "Parker Brothers - On-Time Software, Joe Gaucher, Dan Kurczewski, Louis Marbel, Kathy Von",
        .model        = "PB5110",
        .name         = "James Bond 007 (1983) (Parker Bros) (Prototype) [a3]",
        .note         = "James Bond Agent 007",
    },{
        .md5          = "c4060a31d61ba857e756430a0a15ed2e",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Pick 'n Pile (2003) (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
        .phosphor     = 1,
    },{
        .md5          = "c41e7735f6701dd50e84ee71d3ed1d8f",
        .manufacturer = "Dynacom",
        .name         = "Spider Fighter (1983) (Dynacom)",
    },{
        .md5          = "c43bd363e1f128e73ba5f0380b6fd7e3",
        .manufacturer = "Atari, Chris Crawford",
        .name         = "Wizard (1980) (Atari) (Prototype) [a]",
    },{
        .md5          = "c446288fe62c0c2737639fd788ae4a21",
        .name         = "Mark's Sound Demo (PD)",
        .phosphor     = 1,
    },{
        .md5          = "c450a285daa7a3b65188c2c3cf04fb3e",
        .manufacturer = "Wizard Video Games",
        .model        = "007",
        .name         = "Halloween (1983) (Wizard Video Games) [a]",
    },{
        .md5          = "c469151655e333793472777052013f4f",
        .name         = "Base Attack (Unknown) (Hack)",
    },{
        .md5          = "c471b97446a85304bbac021c57c2cb49",
        .manufacturer = "First Star Software, Alex Leavens, Shirley Ann Russell",
        .name         = "Boing! (1983) (First Star Software) (PAL)",
        .note         = "AKA Bubbles, Soap Suds, The Emphysema Game",
        .phosphor     = 1,
    },{
        .md5          = "c47244f5557ae12c61e8e01c140e2173",
        .manufacturer = "Atari - GCC, Mike Feinstein, John Allred",
        .model        = "CX2688, CX2688P",
        .name         = "Jungle Hunt (1983) (Atari) (PAL) [a1]",
    },{
        .md5          = "c47b7389e76974fd0de3f088fea35576",
        .manufacturer = "Funvision - Fund. International Co.",
        .name         = "Mighty Mouse (Funvision)",
        .note         = "AKA Gopher",
    },{
        .md5          = "c482f8eebd45e0b8d479d9b71dd72bb8",
        .manufacturer = "Retroactive",
        .name         = "Push (V0.03) (1998) (Andrew Davie)",
        .phosphor     = 1,
    },{
        .md5          = "c49fe437800ad7fd9302f3a90a38fb7d",
        .manufacturer = "Atari, Dan Hitchens, Mimi Nyden",
        .model        = "CX2697, CX2697P",
        .name         = "Mario Bros. (1983) (Atari) (PAL)",
    },{
        .md5          = "c4b73c35bc2f54b66cd786f55b668a82",
        .manufacturer = "Arcadia Corporation, Stephen Harland Landrum",
        .model        = "AR-4101",
        .name         = "Communist Mutants from Space (1982) (Arcadia) [a]",
    },{
        .md5          = "c4bbbb0c8fe203cbd3be2e318e55bcc0",
        .name         = "Atlantis (Unknown) (PAL) (Hack)",
    },{
        .md5          = "c4bc8c2e130d76346ebf8eb544991b46",
        .manufacturer = "Imagic",
        .name         = "Imagic Selector ROM (1982) (Imagic) [a]",
    },{
        .md5          = "c4cdd90fab655d3e91933289dd1d8753",
        .manufacturer = "Data Age, J. Ray Dettling",
        .model        = "112-008",
        .name         = "Frankenstein's Monster (1982) (Data Age) (Prototype)",
    },{
        .md5          = "c4d888bcf532e7c9c5fdeafbb145266a",
        .name         = "Space Robot (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "c504a71c411a601d1fc3173369cfdca4",
        .manufacturer = "Retroactive",
        .name         = "Qb (V2.02) (Stella) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "c5124e7d7a8c768e5a18bde8b54aeb1d",
        .manufacturer = "Imagic, Rob Fulop",
        .model        = "720104-2A, IA3204P, EIX-008-04I",
        .name         = "Cosmic Ark (1982) (Imagic) (PAL)",
    },{
        .md5          = "c517144e3d3ac5c06f2f682ebf212dd7",
        .manufacturer = "Tigervision - Teldec",
        .model        = "7-008 - 3.60006 VG",
        .name         = "Miner 2049er (1983) (Tigervision) (PAL)",
    },{
        .md5          = "c529e63013698064149b9e0468afd941",
        .name         = "S.I.PLIX 2 (Hack)",
        .note         = "Hack of Kaboom!",
    },{
        .md5          = "c52d9bbdc5530e1ef8e8ba7be692b01e",
        .manufacturer = "Atari, Robert C. Polaro",
        .model        = "CX26130",
        .name         = "Holey Moley (02-29-1984) (Atari) (Prototype)",
        .note         = "Uses Keyboard Controllers",
    },{
        .md5          = "c5301f549d0722049bb0add6b10d1e09",
        .manufacturer = "Atari, Carla Meninsky, Ed Riddle - Sears",
        .model        = "CX2611 - 99821, 49-75149",
        .name         = "Indy 500 (1977) (Atari)",
        .note         = "Uses the Driving Controllers",
        .left         = "DRIVING",
        .right        = "DRIVING",
    },{
        .md5          = "c5387fc1aa71f11d2fa82459e189a5f0",
        .manufacturer = "Bit Corporation",
        .model        = "PG202",
        .name         = "Space Tunnel (1982) (BitCorp) (PAL)",
        .note         = "AKA Weltraum-Tunnel",
    },{
        .md5          = "c53c0d10c74325deae9ba84074281983",
        .manufacturer = "The Atari 2600 Connection - John K. Harvey, Tim Duarte",
        .model        = "v75",
        .name         = "Mean Santa (2009)",
        .note         = "Released in 2019",
    },{
        .md5          = "c541a5f6fc23b40a211196dd78233780",
        .manufacturer = "Atari, Carla Meninsky - Sears",
        .model        = "CX2660 - 49-75187",
        .name         = "Star Raiders (1981) (Atari) (Prototype) (4K)",
        .note         = "Uses Joystick (left) and Keyboard (right) Controllers",
        .right        = "KEYBOARD",
    },{
        .md5          = "c54b4207ce1d4bf72fadbb1a805d4a39",
        .manufacturer = "Billy Eno",
        .name         = "Sniper (Feb 30) (2001) (Prototype)",
    },{
        .md5          = "c560a3ecb7b751021953819efcfe5b41",
        .manufacturer = "Omegamatrix",
        .name         = "Ghostbusters (Genesis)",
        .note         = "Genesis controller",
        .left         = "GENESIS",
    },{
        .md5          = "c569e57dca93d3bee115a49923057fd7",
        .name         = "Pac-Space (Pac-Man Hack)",
    },{
        .md5          = "c58708c09ccb61625cda9d15ddcd8be6",
        .manufacturer = "SPIKE the Percussionist",
        .name         = "NOIZ Invaders (SPIKE) (2002) (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "c5930d0e8cdae3e037349bfa08e871be",
        .manufacturer = "Atari, Howard Scott Warshaw - Sears",
        .model        = "CX2655 - 49-75167",
        .name         = "Yars' Revenge (1982) (Atari)",
        .phosphor     = 1,
    },{
        .md5          = "c59633dbebd926c150fb6d30b0576405",
        .manufacturer = "Telegames",
        .model        = "5861 A030",
        .name         = "Bogey Blaster (1988) (Telegames)",
        .note         = "AKA Air Raiders",
    },{
        .md5          = "c5a76bafc4676edb76e0126fb9f0fb2d",
        .manufacturer = "Charles Morgan",
        .name         = "Zero Patrol (Charles Morgan) (Hack)",
        .note         = "Hack of Moon Patrol",
    },{
        .md5          = "c5bab953ac13dbb2cba03cd0684fb125",
        .manufacturer = "SpiceWare - Darrell Spice Jr.",
        .name         = "Stay Frosty (SpiceWare)",
        .note         = "Part of Stella's Stocking 2007 Xmas compilation",
        .phosphor     = 1,
    },{
        .md5          = "c5bf03028b2e8f4950ec8835c6811d47",
        .manufacturer = "Atari - Axlon, Tod Frye - Heuristica, Agustin Ortiz Valdiviezo",
        .model        = "CX26169",
        .name         = "Shooting Arcade (03-07-1989) (Atari) (Prototype) [screen 3]",
        .note         = "Uses the Light Gun Controller (left only)",
    },{
        .md5          = "c5c7cc66febf2d4e743b4459de7ed868",
        .manufacturer = "Atari, Jerome Domurat, Steve Woita",
        .model        = "CX2696",
        .name         = "Asterix (1983) (Atari) (PAL) [a]",
        .note         = "AKA Taz",
    },{
        .md5          = "c5d2834bf98e90245e545573eb7e6bbc",
        .manufacturer = "CCE",
        .name         = "Snoopy and the Red Baron (CCE)",
    },{
        .md5          = "c5dd8399257d8862f3952be75c23e0eb",
        .manufacturer = "Atari - GCC",
        .model        = "CX2680",
        .name         = "RealSports Tennis (1982) (Atari) (Prototype)",
    },{
        .md5          = "c5f71dfbdca9cc96b28643ff4d06aa6f",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Atari Trak-Ball Hack v1.4 (PAL) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "c5fe45f2734afd47e27ca3b04a90213c",
        .manufacturer = "Atari, Brad Stewart",
        .model        = "CX2622, CX2622P",
        .name         = "Breakout (1978) (Atari) (PAL) (4K)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "c63a98ca404aa5ee9fcff1de488c3f43",
        .manufacturer = "Atari",
        .model        = "CX26145",
        .name         = "Venture (1987) (Atari)",
        .phosphor     = 1,
    },{
        .md5          = "c6556e082aac04260596b4045bc122de",
        .manufacturer = "Atari - GCC, Dave Payne",
        .model        = "CX2669",
        .name         = "Vanguard (1983) (Atari)",
    },{
        .md5          = "c6688781f4ab844852f4e3352772289b",
        .manufacturer = "Atari, Tod Frye",
        .model        = "CX2695",
        .name         = "Xevious (08-02-1983) (Atari) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "c67ff409f28f44883bd5251cea79727d",
        .name         = "Gunfight 2600 - Music & Bugfixes 1 (2001) (Manuel Rotschkar)",
    },{
        .md5          = "c689148ad9275667924ab334107b517e",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Space Raid (Jone Yuan)",
        .note         = "AKA MegaMania",
    },{
        .md5          = "c68a6bafb667bad2f6d020f879be1d11",
        .manufacturer = "Atari, Michael Kosaka, Peter C. Niday, Robert Vieira",
        .model        = "CX26110",
        .name         = "Crystal Castles (1984) (Atari) (Prototype)",
    },{
        .md5          = "c6ae21caceaad734987cb24243793bd5",
        .manufacturer = "CCE",
        .name         = "Frostbite (CCE)",
    },{
        .md5          = "c6c63da3bc2e47291f63280e057061d0",
        .manufacturer = "128 in 1 Junior Console",
        .name         = "Human Cannonball (128 in 1 Junior Console) (PAL) (4K)",
    },{
        .md5          = "c6d48c6ae6461e0e82753540a985ac9e",
        .manufacturer = "Ed Federmeyer",
        .name         = "Edtris (1994) (Ed Federmeyer)",
    },{
        .md5          = "c6d7fe7a46dc46f962fe8413c6f53fc9",
        .manufacturer = "Parker Brothers, Mark Lesser",
        .model        = "PB5950",
        .name         = "Lord of the Rings (1983) (Parker Bros) (Prototype) [a]",
        .note         = "Journey to Rivendell (The Lord of the Rings I)",
    },{
        .md5          = "c6db733e0b108c2580a1d65211f06dbf",
        .manufacturer = "Atari, Eric Manghise, Mimi Nyden, Joseph Tung",
        .model        = "CX2640",
        .name         = "RealSports Baseball (07-09-1982) (Atari) (Prototype)",
    },{
        .md5          = "c738fc3f5aae1e8f86f7249f6c82ac81",
        .manufacturer = "Atari, Brad Stewart - Sears",
        .model        = "CX2622 - 6-99813, 49-75107",
        .name         = "Breakout (1978) (Atari) (16K)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "c73ae5ba5a0a3f3ac77f0a9e14770e73",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum",
        .model        = "9 AR-4105",
        .name         = "Official Frogger, The (1983) (Starpath)",
    },{
        .md5          = "c745487828a1a6a743488ecebc55ad44",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-002",
        .name         = "Galactic (1983) (Rainbow Vision) (PAL)",
        .note         = "AKA The Challenge of.... Nexar",
    },{
        .md5          = "c74bfd02c7f1877bbe712c1da5c4c194",
        .manufacturer = "Thomas Jentzsch",
        .name         = "River Raid Tanks (Thomas Jentzsch) (Hack)",
        .note         = "Hack of River Raid",
    },{
        .md5          = "c7600d72247c5dfa1ec1a88d23e6c85e",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum, Scott Nelson",
        .model        = "13",
        .name         = "Sweat! - The Decathlon Game (1 of 3) (1983) (Arcadia) (Prototype)",
        .note         = "Uses the Paddle Controllers (left only)",
    },{
        .md5          = "c77c35a6fc3c0f12bf9e8bae48cba54b",
        .manufacturer = "Xonox - K-Tel Software - Action Graphics, Michael Schwartz, David Thiel",
        .model        = "6230, 7210, 06004, 99004",
        .name         = "Artillery Duel (1983) (Xonox)",
    },{
        .md5          = "c77d3b47f2293e69419b92522c6f6647",
        .manufacturer = "Panda",
        .model        = "101",
        .name         = "Tank Brigade (1983) (Panda)",
        .note         = "AKA Phantom Tank",
    },{
        .md5          = "c7900a7fe95a47eef3b325072ad2c232",
        .manufacturer = "Larry Petit",
        .name         = "Super Congo Bongo (2003) (Larry Petit) (Hack)",
        .note         = "Hack of Bongo",
    },{
        .md5          = "c7d5819b26b480a49eb26aeb63cc831e",
        .manufacturer = "Bit Corporation",
        .model        = "PGP210",
        .name         = "Ice Hockey (4 Game in One Light Green) (1983) (BitCorp) (PAL)",
        .note         = "AKA Hockey, Hockey",
    },{
        .md5          = "c7e43ad79c5e5c029d9f5ffde23e32cf",
        .name         = "PAL-NTSC Detector (15-11-2002) (Christopher Tumber)",
    },{
        .md5          = "c7eab66576696e11e3c11ffff92e13cc",
        .manufacturer = "Atari - GCC",
        .model        = "CX2680, CX2680P",
        .name         = "RealSports Tennis (1983) (Atari) (PAL) [a2]",
    },{
        .md5          = "c7f13ef38f61ee2367ada94fdcc6d206",
        .manufacturer = "Parker Brothers - Roklan, Joe Gaucher",
        .model        = "PB5370",
        .name         = "Popeye (1983) (Parker Bros)",
        .phosphor     = 1,
    },{
        .md5          = "c82ec00335cbb4b74494aecf31608fa1",
        .manufacturer = "CCE",
        .name         = "E.T. - The Extra-Terrestrial (CCE)",
    },{
        .md5          = "c830f6ae7ee58bcc2a6712fb33e92d55",
        .manufacturer = "Atari, Michael Kosaka",
        .model        = "CX2687",
        .name         = "Tempest (01-05-1984) (Atari) (Prototype)",
    },{
        .md5          = "c866c995c0d2ca7d017fef0fc0c2e268",
        .manufacturer = "Retroactive",
        .name         = "Qb (2.00) (Retroactive) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "c880c659cdc0f84c4a66bc818f89618e",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Open Sesame (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
        .phosphor     = 1,
    },{
        .md5          = "c89c3138a99fd1fd54367d65f75b0244",
        .manufacturer = "Atari, Omegamatrix",
        .name         = "Space Invaders Menu (2020) (PAL) (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "c8c7da12f087e8d16d3e6a21b371a5d3",
        .name         = "Demo Image Series #9 - Genius (28-02-2003) (Andrew Davie)",
    },{
        .md5          = "c8e90fc944596718c84c82b55139b065",
        .manufacturer = "Atari - Roklan, Bob Curtiss",
        .name         = "Firefox (1983) (Atari) (Prototype) [a]",
        .note         = "AKA Combat II, Fighter Command",
    },{
        .md5          = "c8fa5d69d9e555eb16068ef87b1c9c45",
        .manufacturer = "Atari",
        .model        = "CX26144",
        .name         = "Donkey Kong Junior (1987) (Atari)",
    },{
        .md5          = "c90788d9aa71a78bcc78c015edb22c54",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Marble Craze - Atari Trak-Ball Hack v1.0 (PAL60) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controllers",
    },{
        .md5          = "c9196e28367e46f8a55e04c27743148f",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Stampede (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "c92cfa54b5d022637fdcbdc1ef640d82",
        .manufacturer = "Retroactive",
        .name         = "Qb (V2.05) (PAL) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "c98e8c918a40b4d3a243dd6c49196330",
        .manufacturer = "AtariAge, Omegamatrix",
        .name         = "Venture Reloaded (2019) (AtariAge) (PAL60) (Hack)",
        .note         = "Transformative hack of Venture",
        .phosphor     = 1,
    },{
        .md5          = "c9b7afad3bfd922e006a6bfc1d4f3fe7",
        .manufacturer = "Atari, Larry Kaplan - Sears",
        .model        = "CX2628 - 6-99842, 49-75117",
        .name         = "Bowling (1979) (Atari)",
    },{
        .md5          = "c9c25fc536de9a7cdc5b9a916c459110",
        .manufacturer = "Activision, Mike Lorenzen",
        .model        = "AX-023",
        .name         = "Oink! (1983) (Activision)",
    },{
        .md5          = "c9d02d3cfeef8b48fb71cb4520a4aa84",
        .name         = "Euchre (More for less) (PAL) (22-08-2002) (Erik Eid)",
    },{
        .md5          = "c9e721eb29c940c2e743485b044c0a3f",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4200",
        .name         = "Escape from the Mindmaster (1982) (Arcadia) (PAL)",
    },{
        .md5          = "c9f6e521a49a2d15dac56b6ddb3fb4c7",
        .manufacturer = "Parker Brothers, Rex Bradford",
        .model        = "PB5000",
        .name         = "Star Wars - Jedi Arena (1983) (Parker Bros)",
        .note         = "Uses the Paddle Controllers (swapped)",
        .swapPaddles  = 1,
    },{
        .md5          = "ca09fa7406b7d2aea10d969b6fc90195",
        .manufacturer = "Activision, Matthew L. Hubbard, Bob Whitehead",
        .model        = "AX-024",
        .name         = "Dolphin (1983) (Activision)",
    },{
        .md5          = "ca4f8c5b4d6fb9d608bb96bc7ebd26c7",
        .manufacturer = "M Network - INTV - APh Technological Consulting, Hal Finney, Glenn Hightower, Peter Kaminski",
        .model        = "MT4317",
        .name         = "Adventures of TRON (1983) (M Network)",
        .note         = "AKA Tron Joystick",
    },{
        .md5          = "ca50cc4b21b0155255e066fcd6396331",
        .manufacturer = "Suntek",
        .model        = "SS-031",
        .name         = "UFO Patrol (1983) (Suntek) (PAL)",
        .note         = "AKA X'Mission",
        .phosphor     = 1,
    },{
        .md5          = "ca53fc8fd8b3c4a7df89ac86b222eba0",
        .manufacturer = "CCE",
        .model        = "C-812",
        .name         = "Pac Man (1983) (CCE)",
        .note         = "AKA Pac-Man",
    },{
        .md5          = "ca54de69f7cdf4d7996e86f347129892",
        .manufacturer = "PlayAround - JHM",
        .model        = "201",
        .name         = "Philly Flasher (1982) (PlayAround)",
        .note         = "Uses the Paddle Controllers, AKA Beat 'Em & Eat 'Em",
    },{
        .md5          = "ca7aaebd861a9ef47967d31c5a6c4555",
        .manufacturer = "Atari, Bob Whitehead",
        .model        = "CX26163P",
        .name         = "Homerun (32 in 1) (1988) (Atari) (PAL)",
        .swapPorts    = 1,
    },{
        .md5          = "ca7abc774a2fa95014688bc0849eee47",
        .manufacturer = "Atari, Michael Kosaka, Peter C. Niday, Robert Vieira",
        .model        = "CX26110",
        .name         = "Crystal Castles (1984) (Atari) (PAL)",
    },{
        .md5          = "ca7f166a94eed1a349dec6d6a358bcad",
        .manufacturer = "Activision, Alan Miller - Ariola",
        .model        = "EAG-007, EAG-007-04I, PAG-007 - 711 007-720",
        .name         = "Tennis (1981) (Activision) (PAL) (4K)",
    },{
        .md5          = "cac9928a84e1001817b223f0cecaa3f2",
        .manufacturer = "Amiga - Video Soft, Jerry Lawson, Dan McElroy",
        .name         = "3-D Genesis (1983) (Amiga) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "cad982c9b45bc5eff34e4ea982d5f1ca",
        .name         = "Song (17-02-2003) (Paul Slocum)",
        .phosphor     = 1,
    },{
        .md5          = "cade123747426df69570a2bc871d3baf",
        .manufacturer = "Gakken",
        .model        = "011",
        .name         = "Marine Wars (1983) (Gakken) (PAL)",
    },{
        .md5          = "cae8f83c06831ec7bb6a3c07e98e9342",
        .manufacturer = "Colin Hughes",
        .name         = "Tetris 2600 (Colin Hughes) [o1]",
        .phosphor     = 1,
    },{
        .md5          = "cb18d8d5fbdcb1cd7bd36c5423348859",
        .name         = "RAM-Pong (NTSC) v1.0",
    },{
        .md5          = "cb24210dc86d92df97b38cf2a51782da",
        .manufacturer = "Video Gems",
        .model        = "VG-01",
        .name         = "Missile Control (1983) (Video Gems) (PAL)",
    },{
        .md5          = "cb4a7b507372c24f8b9390d22d54a918",
        .manufacturer = "ITT Family Games",
        .model        = "554-37 338",
        .name         = "Peter Penguin (1983) (ITT Family Games) (PAL)",
        .note         = "AKA Frisco (Pumuckl-Serie)",
    },{
        .md5          = "cb8399dc0d409ff1f531ef86b3b34953",
        .name         = "Demo Image Series #12 - Luigi And Mario (01-03-2003) (Andrew Davie)",
    },{
        .md5          = "cb9626517b440f099c0b6b27ca65142c",
        .manufacturer = "Atari, Larry Kaplan - Sears",
        .model        = "CX2664 - 6-99818",
        .name         = "Brain Games (1978) (Atari) (4K)",
        .note         = "Uses Keyboard Controllers",
        .left         = "KEYBOARD",
        .right        = "KEYBOARD",
    },{
        .md5          = "cb96b0cf90ab7777a2f6f05e8ad3f694",
        .manufacturer = "Silvio Mogno",
        .name         = "Rainbow Invaders",
    },{
        .md5          = "cb9b2e9806a7fbab3d819cfe15f0f05a",
        .manufacturer = "Parker Brothers - JWDA, Todd Marshall, Robin McDaniel, Ray Miller",
        .model        = "931513",
        .name         = "Star Wars - Death Star Battle (1983) (Parker Bros) (PAL)",
    },{
        .md5          = "cb9e924160a4df520456fbe745d61959",
        .manufacturer = "Parker Brothers - On-Time Software, Joe Gaucher, Dan Kurczewski, Louis Marbel, Kathy Von",
        .model        = "PB5110",
        .name         = "James Bond 007 (1983) (Parker Bros) (Prototype) [a1]",
        .note         = "James Bond Agent 007",
    },{
        .md5          = "cba56e939252b05df7b7de87307d12ca",
        .name         = "Playfield Text Demo (2001) (Roger Williams)",
    },{
        .md5          = "cbad928e10aeee848786cc55394fb692",
        .name         = "Fu Kung! (V0.06a Cuttle Cart Compatible) (15-01-2003) (Andrew Davie)",
    },{
        .md5          = "cbb0ee17c1308148823cc6da85bff25c",
        .name         = "Rotating Colors Demo 1 (Junkosoft) (PD)",
    },{
        .md5          = "cbc373fbcb1653b4c56bfabba33ea50d",
        .manufacturer = "CCE",
        .name         = "Super Voleyball (CCE)",
        .note         = "AKA RealSports Volleyball",
    },{
        .md5          = "cbced209dd0575a27212d3eee6aee3bc",
        .manufacturer = "Apollo - Games by Apollo, Ed Salvo, Byron Parks",
        .model        = "AP-2003",
        .name         = "Racquetball (1982) (Apollo) [a]",
        .phosphor     = 1,
    },{
        .md5          = "cbd981a23c592fb9ab979223bb368cd5",
        .manufacturer = "Atari, Carla Meninsky - Sears",
        .model        = "CX2660 - 49-75187",
        .name         = "Star Raiders (1982) (Atari)",
        .note         = "Uses Joystick (left) and Keyboard (right) Controllers",
    },{
        .md5          = "cbe5a166550a8129a5e6d374901dffad",
        .manufacturer = "Atari, Carla Meninsky - Sears",
        .model        = "CX2610 - 49-75127",
        .name         = "Warlords (1981) (Atari)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "cbeafd37f15e0dddb0540dbe15c545a4",
        .name         = "Black and White Fast Scolling Demo (PD)",
    },{
        .md5          = "cc03c68b8348b62331964d7a3dbec381",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Marauder (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "cc12581e079cd18330a89902625b8347",
        .manufacturer = "Dave Neuman",
        .name         = "Space Battle (PAL)",
    },{
        .md5          = "cc1939e4769d0c157ace326efcfdcf80",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4200",
        .name         = "Escape from the Mindmaster (3 of 4) (1982) (Arcadia) (PAL)",
    },{
        .md5          = "cc2973680c150886cce1ed8693c3aca2",
        .manufacturer = "Quelle",
        .model        = "874.254 6",
        .name         = "Super-Cowboy beim Rodeo (1983) (Quelle) (PAL) (4K)",
        .note         = "AKA Stampede",
    },{
        .md5          = "cc3d942c6958bd16b1c602623f59e6e1",
        .manufacturer = "Atari, Bill Aspromonte, John Russell, Michael Sierchio, Robert Zdybel",
        .model        = "CX26114",
        .name         = "Pigs in Space (1983) (Atari) (PAL) [a]",
    },{
        .md5          = "cc7138202cd8f6776212ebfc3a820ecc",
        .manufacturer = "Atari - CCW, Christopher H. Omarzu, Preston Stuart, Bruce Williams",
        .model        = "CX26101",
        .name         = "Oscar's Trash Race (03-30-1983) (Atari) (Prototype)",
        .note         = "Uses the Keyboard Controllers",
        .right        = "KEYBOARD",
    },{
        .md5          = "cc724ebe74a109e39c0b2784ddc980ca",
        .manufacturer = "Atari, Jerome Domurat, Dave Staugas",
        .model        = "CX2682",
        .name         = "Krull (05-27-1983) (Atari) (Prototype)",
    },{
        .md5          = "cc74ddb45d7bc4d04c2e6f1907416699",
        .name         = "Colour Display Programme (1997) (Chris Cracknell)",
    },{
        .md5          = "cc75d0c727e5e4af4fa366a78b0f60d2",
        .manufacturer = "Fotomania",
        .name         = "Planet Patrol (Fotomania)",
    },{
        .md5          = "cca33ae30a58f39e3fc5d80f94dc0362",
        .name         = "Okie Dokie (PD)",
    },{
        .md5          = "ccb56107ff0492232065b85493daa635",
        .manufacturer = "Bit Corporation",
        .model        = "PG206 [demonstration cartridge]",
        .name         = "Bobby Is Going Home (1983) (BitCorp) (PAL) [demo cart]",
        .note         = "AKA Bobby geht Heim",
    },{
        .md5          = "ccb5fa954fb76f09caae9a8c66462190",
        .manufacturer = "Answer Software Corporation - TY Associates, Mike Wentz",
        .model        = "ASC1001",
        .name         = "Malagai (1983) (Answer Software)",
        .phosphor     = 1,
    },{
        .md5          = "ccb807eb79b0ed0f5fdc460445ef703a",
        .name         = "Superman (Stunt_Cycle_Rules!) (Hack)",
        .note         = "Hack of Superman",
    },{
        .md5          = "ccbd36746ed4525821a8083b0d6d2c2c",
        .manufacturer = "Atari, Brad Stewart - Sears",
        .model        = "CX2649, 49-75163",
        .name         = "Asteroids (1981) (Atari) [no copyright]",
        .phosphor     = 1,
    },{
        .md5          = "cccfe9e9a11b1dad04beba46eefb7351",
        .name         = "Poker Squares (V0.25) (PAL) (2001) (B. Watson)",
    },{
        .md5          = "ccd6ce508eee4b3fca67212833edcd85",
        .manufacturer = "Otto Versand",
        .model        = "746422",
        .name         = "Hot Wave (Double-Game Package) (1983) (Otto Versand) (PAL)",
        .note         = "AKA Ram It",
    },{
        .md5          = "ccd92a269a4c2bd64d58cf2c0114423c",
        .manufacturer = "Atari - GCC, Mark Ackerman, Glenn Parker",
        .model        = "CX2675",
        .name         = "Ms. Pac-Man (09-20-1983) (Atari) (Prototype)",
    },{
        .md5          = "cd032ab6764b55438a7b0bfb5e78595a",
        .name         = "Hangman Pac-Man 4letter (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "cd139ae6d09f3665ad09eb79da3f9e49",
        .manufacturer = "Eric Mooney",
        .name         = "Invaders by Erik Mooney (4-24-97) (PD)",
    },{
        .md5          = "cd34b3b3ef9e485201e841ba71beb253",
        .manufacturer = "Bradford W. Mott",
        .name         = "Hit HMOVE At Various Cycles After WSYNC Test (Bradford W. Mott) (1998) (PD)",
    },{
        .md5          = "cd38ad19f51b1048d8e5e99c86a2a655",
        .name         = "Demo Image Series #5 - Flag (19-02-2003) (Andrew Davie)",
    },{
        .md5          = "cd399bc422992a361ba932cc50f48b65",
        .manufacturer = "Arcadia Corporation, Brian McGhie",
        .model        = "AR-4104",
        .name         = "Rabbit Transit (Preview) (1983) (Arcadia)",
    },{
        .md5          = "cd3e26786136a4692fd2cb2dfbc1927e",
        .name         = "Multiple Moving Objects Demo 2 (B. Watson)",
    },{
        .md5          = "cd4423bd9f0763409bae9111f888f7c2",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "River Raid (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "cd4ded1ede63c4dd09f3dd01bda7458c",
        .name         = "Laser Gates (Unknown) (PAL)",
        .note         = "AKA Innerspace",
    },{
        .md5          = "cd568d6acb2f14477ebf7e59fb382292",
        .manufacturer = "Videospielkassette - Ariola",
        .model        = "PGP235",
        .name         = "Fussball (Ariola) (PAL)",
        .note         = "AKA International Soccer",
    },{
        .md5          = "cd5af682685cfecbc25a983e16b9d833",
        .manufacturer = "Atari, Jerome Domurat, Howard Scott Warshaw",
        .model        = "CX26133",
        .name         = "A-Team, The (05-08-1984) (Atari) (Prototype)",
        .note         = "AKA Saboteur",
    },{
        .md5          = "cd88ef1736497288c4533bcca339f881",
        .manufacturer = "SEGA - Teldec",
        .model        = "005-10 - 3.60104 VG",
        .name         = "Buck Rogers - Planet of Zoom (1983) (SEGA) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "cd8fa2e9f6255ef3d3b9b5a4f24a54f7",
        .name         = "Daredevil (V2) (Stunt_Cycle_Rules!) (PD)",
    },{
        .md5          = "cd98be8a48ebf610c9609a688b9c57f2",
        .manufacturer = "Arcadia Corporation, Steve Hales, Stephen H. Landrum",
        .model        = "4 AR-4102",
        .name         = "Suicide Mission (1982) (Arcadia) (Prototype)",
        .note         = "AKA Meteoroids",
        .phosphor     = 1,
    },{
        .md5          = "cd9fea12051e414a6dfe17052067da8e",
        .manufacturer = "Paul Slocum",
        .name         = "Marble Craze Demo (PD)",
    },{
        .md5          = "cda38714267978b9a8b0b24bee3529ae",
        .name         = "Space Instigators (V1.6) (17-10-2002) (Christopher Tumber)",
    },{
        .md5          = "cdadb57b34438805ee322ff05bd3d43e",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Amiga Mouse Hack v1.4 (PAL60) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "cdb81bf33d830ee4ee0606ee99e84dba",
        .manufacturer = "Arcadia Corporation, Scott Nelson",
        .model        = "AR-4300",
        .name         = "Fireball (1982) (Arcadia) (PAL)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "cdc1a5c61d7488eadc9aba36166b253d",
        .manufacturer = "Retroactive",
        .name         = "Qb (V0.12) (Stella) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "cdd4a538c420358ab64767d326921bf6",
        .name         = "4 in 1 (Logitachi)",
        .type         = "4IN1",
    },{
        .md5          = "cddabfd68363a76cd30bee4e8094c646",
        .manufacturer = "Computer Magic - CommaVid, John Bronstein",
        .model        = "CM-001",
        .name         = "MagiCard (1981) (CommaVid)",
        .note         = "Uses the Keyboard Controllers",
    },{
        .md5          = "ce17325834bf8b0a0d0d8de08478d436",
        .name         = "Boring Freeway (Hack)",
        .note         = "Hack of Freeway",
    },{
        .md5          = "ce1cbe159b9ae5992dacf09371de5e13",
        .manufacturer = "Atari - GCC, Kevin Osborn",
        .model        = "CX2689",
        .name         = "Kangaroo (01-19-1983) (Atari) (Prototype)",
    },{
        .md5          = "ce243747bf34a2de366f846b3f4ca772",
        .manufacturer = "Home Vision - Gem International Corp. - VDI",
        .name         = "Jacky Jump (1983) (Home Vision) (PAL)",
        .note         = "AKA Bobby Is Going Home",
    },{
        .md5          = "ce4bbe11d682c15a490ae15a4a8716cf",
        .name         = "Okie Dokie (Older) (PD)",
    },{
        .md5          = "ce5524bb18e3bd8e092273ef22d36cb9",
        .manufacturer = "Carrere Video - JWDA, Todd Marshall, Wes Trager, Henry Will IV - Teldec - Prism",
        .model        = "USC1004",
        .name         = "Commando Raid (1983) (Carrere Video) (PAL)",
    },{
        .md5          = "ce5cc62608be2cd3ed8abd844efb8919",
        .manufacturer = "Atari - Bobco, Robert C. Polaro",
        .model        = "CX2663",
        .name         = "Road Runner (1989) (Atari)",
    },{
        .md5          = "ce64812eb83c95723b04fb56d816910b",
        .manufacturer = "Retroactive",
        .name         = "Qb (V2.04) (NTSC) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "ce6c4270f605ad3ce5e82678b0fc71f8",
        .name         = "Vertical Rainbow Demo (PD)",
    },{
        .md5          = "ce82a675c773ff21e0ffc0a4d1c90a71",
        .name         = "Defender 2 (Genesis)",
        .note         = "Genesis controller (C is smartbomb)",
    },{
        .md5          = "ce8467ae2a3a5bc88ca72a2ce44ce28c",
        .manufacturer = "SOLID Corp. (D. Scott Williamson)",
        .model        = "CX2655-015",
        .name         = "Star Castle 2600 (SolidCorp) (PAL) [015]",
        .phosphor     = 1,
    },{
        .md5          = "ce89529d6e98a13ddf3d84827bbdfe68",
        .name         = "Kung Fu Sprite Demo 2 (PD)",
        .phosphor     = 1,
    },{
        .md5          = "ce904c0ae58d36d085cd506989116b0b",
        .manufacturer = "Telegames",
        .model        = "5687 A279",
        .name         = "International Soccer (1988) (Telegames) (PAL)",
    },{
        .md5          = "cea9f72036dc6f7af5eff52459066290",
        .manufacturer = "Retroactive",
        .name         = "Qb (2.07) (Retroactive) (Stella)",
        .phosphor     = 1,
    },{
        .md5          = "ceba7965a93c689bdecdb46a5b2ac0c1",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Atari Trak-Ball Hack v1.3 (PAL60) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "cedbd67d1ff321c996051eec843f8716",
        .manufacturer = "Ultravision",
        .model        = "1044",
        .name         = "Karate (1982) (Ultravision)",
    },{
        .md5          = "cef01595000627ee50863d4290372c27",
        .name         = "Many Blue Bars and Text Demo (PD)",
    },{
        .md5          = "cef2287d5fd80216b2200fb2ef1adfa8",
        .manufacturer = "Milton Bradley Company",
        .model        = "4363",
        .name         = "Spitfire Attack (1983) (Milton Bradley)",
        .note         = "AKA Flight Commander)",
    },{
        .md5          = "cf0c593c563c84fdaf0f741adb367445",
        .manufacturer = "Retroactive",
        .name         = "Qb (V0.05) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "cf3a9ada2692bb42f81192897752b912",
        .name         = "Air Raiders (Unknown) (PAL)",
    },{
        .md5          = "cf3c2725f736d4bcb84ad6f42de62a41",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-009",
        .name         = "Bermuda, The (1983) (Rainbow Vision) (PAL) [a]",
        .note         = "AKA River Raid",
    },{
        .md5          = "cf507910d6e74568a68ac949537bccf9",
        .manufacturer = "SEGA, Jeff Lorenz",
        .model        = "003-01",
        .name         = "Thunderground (1983) (SEGA)",
        .note         = "AKA Underground",
        .phosphor     = 1,
    },{
        .md5          = "cf63ffac9da89ef09c6c973083061a47",
        .manufacturer = "CCE",
        .model        = "C-859",
        .name         = "MASH (1983) (CCE)",
        .note         = "AKA M.A.S.H",
    },{
        .md5          = "cf9069f92a43f719974ee712c50cd932",
        .manufacturer = "Video Gems",
        .model        = "VG-04",
        .name         = "Mission Survive (1983) (Video Gems) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "cfad2b9ca8b8fec7fb1611d656cc765b",
        .manufacturer = "Bit Corporation",
        .model        = "PG207",
        .name         = "Mission 3,000 A.D. (1983) (BitCorp) (PAL) [demo cart]",
        .note         = "demonstration cartridge",
        .phosphor     = 1,
    },{
        .md5          = "cfb3260c603b0341d49ddfc94051ec10",
        .manufacturer = "Dactari - Milmar",
        .name         = "Boxing (Dactari - Milmar)",
    },{
        .md5          = "cfb83a3b0513acaf8be4cae1512281dc",
        .manufacturer = "Starpath Corporation",
        .name         = "Going-Up (1983) (Starpath) (Prototype)",
    },{
        .md5          = "cfc226d04d7490b69e155abd7741e98c",
        .manufacturer = "Atari, Matthew L. Hubbard",
        .model        = "CX26159",
        .name         = "Double Dunk (1989) (Atari) (PAL)",
        .note         = "AKA Super Basketball",
    },{
        .md5          = "cfce5596a7e8ca13529e9804cad693ef",
        .manufacturer = "Canal 3 - Intellivision",
        .name         = "Tennis (Canal 3) (4K)",
    },{
        .md5          = "cfd5518c71552b8bb853b0e461e328d7",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Spider Fighter (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "cfd6a8b23d12b0462baf6a05ef347cd8",
        .manufacturer = "Activision, Larry Kaplan",
        .model        = "AX-006",
        .name         = "Bridge (1980) (Activision)",
    },{
        .md5          = "cfdb4d0427a1ea8085c6bc6eb90259d8",
        .name         = "Gunfight 2600 - Release Candidate (2001) (Manuel Rotschkar)",
    },{
        .md5          = "cfe2185f84ce8501933beb5c5e1fd053",
        .name         = "Football (Unknown) (PAL)",
    },{
        .md5          = "cfe62ed7125ff9fae99b4c8a367c0399",
        .manufacturer = "Activision, Larry Miller",
        .model        = "AX-026, AX-026-04",
        .name         = "Enduro (1983) (Activision) (16K)",
    },{
        .md5          = "cfee10bd7119f10b136921ced2ee8972",
        .name         = "Space Instigators (V1.8) (19-10-2002) (Christopher Tumber)",
    },{
        .md5          = "cfef1a2d1f6a5ee7a5e1f43f3056f112",
        .name         = "Skeleton+ (05-05-2003) (Eric Ball) (NTSC)",
    },{
        .md5          = "cff1e9170bdbc29859b815203edf18fa",
        .manufacturer = "Retroactive",
        .name         = "Push (V0.01) (1998) (Andrew Davie)",
        .phosphor     = 1,
    },{
        .md5          = "cff578e5c60de8caecbee7f2c9bbb57b",
        .manufacturer = "George Veeder",
        .name         = "Suicide Adventure (George Veeder) (Hack)",
        .note         = "Hack of Adventure",
    },{
        .md5          = "cff9950d4e650094f65f40d179a9882d",
        .manufacturer = "Paul Slocum",
        .name         = "Mr. Roboto (Paul Slocum) (Hack)",
        .note         = "Hack of Berzerk",
        .phosphor     = 1,
    },{
        .md5          = "cfffc4b97d01cc3e7b9f47575f7b11ec",
        .manufacturer = "Xonox - K-Tel Software, Anthony R. Henderson",
        .model        = "99007, 6240",
        .name         = "Tomarc the Barbarian (1983) (Xonox) (PAL60)",
        .note         = "Genesis controller (B is jump and throw, C switches between players)",
    },{
        .md5          = "d00f6f8ba89559e4b20972a478fc0370",
        .manufacturer = "Spiceware",
        .model        = "SW-01",
        .name         = "Medieval Mayhem (PAL)",
    },{
        .md5          = "d010e3dfe7366e47561c088079a59439",
        .manufacturer = "Retroactive",
        .name         = "Qb (V0.10) (Stella) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "d026716b3c5be2c951cc4c064317c524",
        .name         = "Fu Kung! (V0.06) (14-01-2003) (Andrew Davie)",
    },{
        .md5          = "d0498baca989e792db4b8270a02b9624",
        .name         = "Pac Ghost Sprite Demo (PD)",
    },{
        .md5          = "d071d2ec86b9d52b585cc0382480b351",
        .manufacturer = "UA Limited",
        .name         = "Cat Trax (1983) (UA Limited) (1) [a]",
        .phosphor     = 1,
    },{
        .md5          = "d078674afdf24a4547b4b32890fdc614",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Laser Blast (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "d078d25873c5b99f78fa267245a2af02",
        .manufacturer = "SEGA - Beck-Tech, Steve Beck, Phat Ho",
        .model        = "006-01",
        .name         = "Congo Bongo (1983) (SEGA) [a]",
    },{
        .md5          = "d0796a0317abf9018d6745086bef411f",
        .manufacturer = "Edward Smith",
        .name         = "Alien Attack (2018)",
    },{
        .md5          = "d08fccfbebaa531c4a4fa7359393a0a9",
        .manufacturer = "Activision, David Crane, Bob Whitehead",
        .name         = "Venetian Blinds Demo (1981) (Activision)",
    },{
        .md5          = "d090836f0a4ea8db9ac7abb7d6adf61e",
        .manufacturer = "Hozer Video Games",
        .name         = "Yahtzee (Hozer Video Games)",
        .phosphor     = 1,
    },{
        .md5          = "d09935802d6760ae58253685ff649268",
        .manufacturer = "Telesys, Don Ruffcorn",
        .model        = "1006",
        .name         = "Demolition Herby (1983) (Telesys)",
        .phosphor     = 1,
    },{
        .md5          = "d09a7504ee8c8717ac3e24d263e7814d",
        .manufacturer = "Activision, Matthew L. Hubbard, Bob Whitehead",
        .model        = "AX-024",
        .name         = "Dolphin (1983) (Activision) (16K)",
    },{
        .md5          = "d09f1830fb316515b90694c45728d702",
        .manufacturer = "Imagic, Brad Stewart",
        .model        = "720105-1A, IA3400",
        .name         = "Fire Fighter (1982) (Imagic)",
    },{
        .md5          = "d0a379946ed77b1b126230ca68461333",
        .manufacturer = "Ataripoll",
        .name         = "Atari Invaders (Ataripoll) (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "d0af33865512e9b6900714c26db5fa23",
        .manufacturer = "Telegames",
        .name         = "Armor Ambush (1988) (Telegames) (PAL)",
    },{
        .md5          = "d0b26e908370683ad99bc6b52137a784",
        .manufacturer = "Apollo - Games by Apollo, Larry Minor, Ernie Runyon, Ed Salvo - RCA Video Jeux",
        .model        = "AP-2004",
        .name         = "Lost Luggage (1982) (Apollo) (PAL)",
        .note         = "AKA La valise piegee, Airport Mayhem",
    },{
        .md5          = "d0b9df57bfea66378c0418ec68cfe37f",
        .manufacturer = "20th Century Fox Video Games - Sirius, Grady Ward",
        .model        = "11002",
        .name         = "Beany Bopper (1982) (20th Century Fox)",
    },{
        .md5          = "d0b9f705aa5f61f47a748a66009ae2d2",
        .name         = "Synthcart (14-01-2002) (Paul Slocum)",
        .note         = "Uses Keyboard Controllers",
        .phosphor     = 1,
    },{
        .md5          = "d0cb28e1b7bd6c7f683a0917b59f707e",
        .manufacturer = "Atari, Gary Palmer",
        .model        = "CX2661P",
        .name         = "Fun with Numbers (1980) (Atari) (PAL) (4K)",
        .note         = "AKA Basic Math",
    },{
        .md5          = "d0cdafcb000b9ae04ac465f17788ad11",
        .manufacturer = "Quelle - Otto Versand",
        .model        = "732.273 8 - 600273, 781644",
        .name         = "Lilly Adventure (1983) (Quelle) (PAL)",
    },{
        .md5          = "d0e05ba5f10e3df3023c5ee787f760ef",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Atari Mouse Hack v1.4 (PAL) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "d0e15a3ce322c5af60f07343594392af",
        .manufacturer = "Amiga - Video Soft",
        .model        = "3125",
        .name         = "Surf's Up (1983) (Amiga) (Prototype) (4K)",
        .note         = "Uses the Joyboard controller",
    },{
        .md5          = "d0e9beb2347595c6c7d158e9d83d2da8",
        .manufacturer = "Retroactive",
        .name         = "Qb (2.00) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "d100b11be34a1e5b7832b1b53f711497",
        .name         = "Robotfindskitten2600 (26-04-2003) (Jeremy Penner) [a2]",
    },{
        .md5          = "d15655fe355fa57dd541487dc5725145",
        .manufacturer = "Rentacom",
        .name         = "Vanguard (Rentacom)",
    },{
        .md5          = "d1680f0bb8e6a2773fe712bb3f480a18",
        .manufacturer = "Atari, Jim Huether, Alan J. Murphy, Robert C. Polaro",
        .model        = "CX2666",
        .name         = "RealSports Volleyball (05-11-1982) (Atari) (Prototype)",
    },{
        .md5          = "d170317ae4c7d997a989c7d6567c2840",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Stampede (Jone Yuan) (4K) (Hack)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "d175258b2973b917a05b46df4e1cf15d",
        .name         = "Guignol (Unknown) (PAL)",
    },{
        .md5          = "d17a671029b1532b197defca5f3649a7",
        .manufacturer = "Hozer Video Games",
        .name         = "Gunfight 2600 - Limit broken again! (2001) (Manuel Rotschkar)",
    },{
        .md5          = "d17a8c440d6be79fae393a4b46661164",
        .name         = "Warring Worms (Beta 3) (2002) (Billy Eno)",
    },{
        .md5          = "d1a1841b7f2007a24439ac248374630a",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4200",
        .name         = "Escape from the Mindmaster (1 of 4) (1982) (Arcadia)",
    },{
        .md5          = "d1a9478b99d6a55e13a9fd4262da7cd4",
        .manufacturer = "U.S. Games Corporation, Garry Kitchen - Vidtec",
        .model        = "VC1001",
        .name         = "Space Jockey (1982) (U.S. Games) (4K)",
    },{
        .md5          = "d1b4075925e8d3031a7616d2f02fdd1f",
        .name         = "Demo Image Series #7 - Two Marios (27-02-2003) (Andrew Davie)",
    },{
        .md5          = "d1c3520b57c348bc21d543699bc88e7e",
        .manufacturer = "Gameworld",
        .model        = "133-002",
        .name         = "Warplock (1983) (Gameworld) (PAL)",
        .note         = "Uses the Paddle Controllers",
        .phosphor     = 1,
    },{
        .md5          = "d1ca47b262f952413c1234117c4e4e21",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Missile Command (32 in 1) (BitCorp) (Hack)",
        .phosphor     = 1,
    },{
        .md5          = "d1d704a7146e95709b57b6d4cac3f788",
        .manufacturer = "Atari, Warren Robinett",
        .model        = "CX26163P",
        .name         = "Slot Racers (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "d20e61c86ed729780feca162166912ca",
        .manufacturer = "Supergame",
        .model        = "32",
        .name         = "Pitfall (1984) (Supergame)",
        .note         = "AKA Pitfall!",
    },{
        .md5          = "d214c7a734e133a5c18e93229435b57a",
        .manufacturer = "Digivision",
        .name         = "Mickey (1984) (Digivision)",
        .note         = "AKA Sorcerer's Apprentice",
        .type         = "UASW",
    },{
        .md5          = "d223bc6f13358642f02ddacfaf4a90c9",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-003",
        .name         = "Pac-Kong (1983) (Rainbow Vision) (PAL)",
        .note         = "AKA Inca Gold",
    },{
        .md5          = "d245e2f27c84016041e9496b66b722fe",
        .name         = "Gunfight 2600 - The Final Kernel (Manuel Rotschkar)",
    },{
        .md5          = "d25018349c544320bf3fd5092ee072bc",
        .manufacturer = "Activision, Larry Miller",
        .model        = "AX-021",
        .name         = "Spider Fighter (1983) (Activision) (8K)",
    },{
        .md5          = "d28afe0517a046265c418181fa9dd9a1",
        .name         = "Dodge 'Em (Unknown) (PAL)",
    },{
        .md5          = "d2901c34bb6496bb96c7bc78a9e6142a",
        .manufacturer = "Greg Zumwalt",
        .name         = "Fish Revenge (2003) (Greg Zumwalt) (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "d2c4f8a4a98a905a9deef3ba7380ed64",
        .manufacturer = "Mythicon, Bill Bryner, Bruce de Graaf",
        .model        = "MA1001",
        .name         = "Sorcerer (1983) (Mythicon)",
    },{
        .md5          = "d2c8e6aa8172b16c8aa9aae739ac9c5e",
        .manufacturer = "Activision, David Crane",
        .model        = "08-08-1980",
        .name         = "Laser Blast (08-08-1980) (Activision) (Prototype)",
    },{
        .md5          = "d2c957dd7746521b51bb09fde25c5774",
        .manufacturer = "Eckhard Stolberg",
        .name         = "Cubis (6K) (1997) (Eckhard Stolberg)",
    },{
        .md5          = "d2d8c4f1ea7f347c8bcc7d24f45aa338",
        .name         = "20 Sprites at Once Demo 5 (PD)",
    },{
        .md5          = "d2deddb77c8b823e4be9c57cb3c69adc",
        .manufacturer = "Canal 3 - Intellivision",
        .model        = "C 3007",
        .name         = "Snoopy and the Red Baron (Canal 3)",
    },{
        .md5          = "d2f713c78a9ebba9da6d10aeefc6f20f",
        .manufacturer = "Digivision",
        .name         = "Enduro (Digivision) [a]",
    },{
        .md5          = "d3171407c3a8bb401a3a62eb578f48fb",
        .name         = "Spinning Fireball (Unknown)",
        .phosphor     = 1,
    },{
        .md5          = "d326db524d93fa2897ab69c42d6fb698",
        .manufacturer = "Parker Brothers - Roklan, Paul Crowley, Bob Curtiss",
        .model        = "931505",
        .name         = "Super Cobra (1983) (Parker Bros) (PAL)",
    },{
        .md5          = "d339b95f273f8c3550dc4daa67a4aa94",
        .name         = "Laser Blast (Unknown) (PAL) (4K)",
    },{
        .md5          = "d341d39774277cee6a1d378a013f92ac",
        .manufacturer = "Xonox, John Perkins",
        .model        = "6230, 7210, 06004, 99004",
        .name         = "Artillery Duel (1983) (Xonox) (PAL) [a]",
    },{
        .md5          = "d3423d7600879174c038f53e5ebbf9d3",
        .manufacturer = "U.S. Games Corporation - Western Technologies",
        .model        = "VC2005",
        .name         = "Piece o' Cake (1983) (U.S. Games)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "d3456b4cf1bd1a7b8fb907af1a80ee15",
        .manufacturer = "Avalon Hill, Duncan Scott",
        .model        = "5003002",
        .name         = "Wall Ball (1983) (Avalon Hill)",
        .phosphor     = 1,
    },{
        .md5          = "d34b933660e29c0a0a04004f15d7e160",
        .name         = "Multi Demo 5 (Bob Colbert) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "d36308387241e98f813646f346e7f9f7",
        .manufacturer = "King Atari",
        .name         = "Ghostbuster 2 (King Atari) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "d39e29b03af3c28641084dd1528aae05",
        .manufacturer = "Funvision - Fund. Int'l Co.",
        .name         = "Spider Monster (1982) (Funvision) (PAL)",
        .note         = "AKA Spider Kong",
    },{
        .md5          = "d3bb42228a6cd452c111c1932503cc03",
        .manufacturer = "UA Limited",
        .name         = "Funky Fish (1983) (UA Limited) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "d44d90e7c389165f5034b5844077777f",
        .manufacturer = "Parker Brothers, Larry Gelberg",
        .model        = "PB5065",
        .name         = "Star Wars - Ewok Adventure (1983) (Parker Bros) (Prototype)",
    },{
        .md5          = "d45bf71871b196022829aa3b96bfcfd4",
        .manufacturer = "Activision, Steve Cartwright",
        .model        = "AX-017, AX-017-04",
        .name         = "MegaMania (1982) (Activision) (8K)",
    },{
        .md5          = "d45ebf130ed9070ea8ebd56176e48a38",
        .manufacturer = "SEGA, Jeff Lorenz",
        .model        = "001-01",
        .name         = "Tac-Scan (1983) (SEGA)",
        .note         = "Uses the Paddle Controllers (right only)",
        .swapPorts    = 1,
        .swapPaddles  = 1,
        .phosphor     = 1,
    },{
        .md5          = "d47387658ed450db77c3f189b969cc00",
        .manufacturer = "PlayAround - JHM",
        .model        = "206",
        .name         = "Westward Ho (1982) (PlayAround) (PAL)",
        .note         = "AKA Custer's Revenge",
    },{
        .md5          = "d4806775693fcaaa24cf00fc00edcdf3",
        .manufacturer = "Atari - Bobco, Robert C. Polaro",
        .model        = "CX26140, CX26140P",
        .name         = "Desert Falcon (1987) (Atari) (PAL)",
        .note         = "AKA Nile Flyer, Sphinx",
    },{
        .md5          = "d483f65468d9a265661917bae1a54f3e",
        .manufacturer = "Joe Grand",
        .name         = "SCSIcide Pre-release 3 (Joe Grand)",
    },{
        .md5          = "d4942f4b55313ff269488527d84ce35c",
        .manufacturer = "Atari - GCC, Mark Ackerman, Glenn Parker",
        .model        = "CX2675, CX2675P",
        .name         = "Ms. Pac-Man (1982) (Atari) (PAL) [a]",
    },{
        .md5          = "d49aff83f77a1b9041ad7185df3c2277",
        .name         = "Space Treat (60% complete) (PD)",
    },{
        .md5          = "d4aa89e96d2902692f5c45f36903d336",
        .name         = "Euchre (NTSC) (Erik Eid) (PD)",
    },{
        .md5          = "d4c590ccfb611a73b3331359700c01a3",
        .name         = "Sprite Movement Demo 2 (2001) (Roger Williams)",
    },{
        .md5          = "d541b20eae221a8ee321375e5971e766",
        .manufacturer = "Arcadia Corporation, Stephen H. Landrum",
        .model        = "AR-4101",
        .name         = "Communist Mutants from Space (Preview) (1982) (Arcadia)",
    },{
        .md5          = "d54cd41ecfd59e4b72d2c086152b9a75",
        .manufacturer = "Amiga - Video Soft - Michael K. Glass, Jerry Lawson",
        .model        = "1110",
        .name         = "Power Play Arcade Video Game Album (1983) (Amiga) (Prototype)",
        .note         = "3-D Ghost Attack only (3-D Genesis & 3-D Havoc missing in ROM)",
        .phosphor     = 1,
    },{
        .md5          = "d5618464dbdc2981f6aa8b955828eeb4",
        .manufacturer = "CCE",
        .model        = "C-829",
        .name         = "Megamania (1983) (CCE)",
    },{
        .md5          = "d563ba38151b8204c9f5c9f58e781455",
        .manufacturer = "Atari, Brad Stewart - Sears",
        .model        = "CX2649, 49-75163",
        .name         = "Asteroids (1981) (Atari) [a2]",
        .phosphor     = 1,
    },{
        .md5          = "d573089534ca596e64efef474be7b6bc",
        .manufacturer = "Parker Brothers, John Emerson",
        .model        = "931511",
        .name         = "Action Force (1983) (Parker Bros) (PAL) [a]",
        .note         = "AKA G.I. Joe - Cobra Strike",
        .right        = "JOYSTICK",
    },{
        .md5          = "d57913088e0c49ac3a716bf9837b284f",
        .manufacturer = "Activision, Garry Kitchen",
        .model        = "EAZ-032",
        .name         = "Pressure Cooker (1983) (Activision) (PAL) [a]",
    },{
        .md5          = "d57eb282d7540051bc9b5427cf966f03",
        .manufacturer = "Atari Troll",
        .name         = "Custer's Viagra (Atari Troll) (Hack)",
        .note         = "Hack of Custer's Revenge",
    },{
        .md5          = "d597d35c6022c590d6e75e865738558a",
        .name         = "Sprite Color Demo (PD)",
    },{
        .md5          = "d5aa7472e7f2cc17e893a1a36f8dadf0",
        .name         = "Overhead Adventure Demo 5 (PD)",
    },{
        .md5          = "d5c6b81212ad86fd9542a1fedaf57cae",
        .name         = "Sprite Demo 1 (PD)",
    },{
        .md5          = "d5d2d44fb73785996ccc24ae3a0f5cef",
        .manufacturer = "Robby",
        .name         = "Grand Prix (Robby)",
    },{
        .md5          = "d5e17022d1ecc20fd9b53dc464c302f1",
        .manufacturer = "Activision, Carol Shaw",
        .model        = "EAX-020",
        .name         = "River Raid (1982) (Activision) (SECAM)",
    },{
        .md5          = "d5e27051512c1e7445a9bf91501bda09",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-008",
        .name         = "Laser Blast (1981) (Activision) (4K)",
    },{
        .md5          = "d5e5b3ec074fff8976017ef121d26129",
        .name         = "River Raid (Unknown)",
    },{
        .md5          = "d5f965c159e26a1fb49a22a47fbd1dd0",
        .manufacturer = "Supergame",
        .name         = "River Raid II (Supergame)",
        .note         = "AKA River Raid",
    },{
        .md5          = "d605ed12f4eaaaec3dcd5aa909a4bad7",
        .name         = "Chronocolor Frame Demo (10-01-2003) (Andrew Davie)",
    },{
        .md5          = "d61629bbbe035f45552e31cef7d591b2",
        .name         = "Atari Logo Demo (PD) (PAL)",
    },{
        .md5          = "d62283aed0f4199adb2333de4c263e9c",
        .manufacturer = "Atari, Alan J. Murphy, Nick 'Sandy Maiwald' Turner",
        .model        = "CX2615",
        .name         = "Demons to Diamonds (1982) (Atari) (PAL)",
        .note         = "Uses the Paddle Controllers (left only)",
        .swapPaddles  = 1,
    },{
        .md5          = "d62d7d1a974c31c5803f96a8c1552510",
        .name         = "StarMaster (Unknown) (PAL)",
        .note         = "Use Color/BW switch to change between galactic chart and front views",
    },{
        .md5          = "d632b74fea533d593af82cf16e7c5e4a",
        .name         = "Fu Kung! (V0.13) (01-02-2003) (Andrew Davie)",
        .phosphor     = 1,
    },{
        .md5          = "d65028524761ef52fbbdebab46f79d0f",
        .manufacturer = "CCE",
        .name         = "Galaxian (CCE)",
    },{
        .md5          = "d65900fefa7dc18ac3ad99c213e2fa4e",
        .name         = "Guntest (2000) (Eckhard Stolberg)",
        .note         = "Light Gun Test (based on Sentinel code)",
    },{
        .md5          = "d69559f9c9dc6ef528d841bf9d91b275",
        .manufacturer = "Activision, Alan Miller",
        .model        = "AX-016",
        .name         = "StarMaster (1982) (Activision)",
        .note         = "Use Color/BW switch to change between galactic chart and front views",
    },{
        .md5          = "d6a44277c3eb4f9d039185e0ecf7bfa6",
        .name         = "Trick (1997) (Eckhard Stolberg)",
    },{
        .md5          = "d6acff6aed0f04690fe4024d58ff4ce3",
        .manufacturer = "Spectravision - Spectravideo - Quelle",
        .model        = "SA-202 - 412.851 8",
        .name         = "Planet Patrol (1982) (Spectravision) (PAL) [different spaceship]",
    },{
        .md5          = "d6b8beeb05e5b730084d4b8f381bbf8d",
        .name         = "208 in 1 Game Select ROM (Unknown) (PAL)",
    },{
        .md5          = "d6d1ddd21e9d17ea5f325fa09305069c",
        .manufacturer = "Funvision - Fund. International Co.",
        .name         = "Time Warp (1982) (Funvision) (PAL)",
    },{
        .md5          = "d6d5dd8fd322d3cf874e651e7b6c1657",
        .name         = "How to Draw a Playfield (1997) (Nick Bensema) (PD)",
    },{
        .md5          = "d6dc9b4508da407e2437bfa4de53d1b2",
        .manufacturer = "Bomb - Onbase",
        .model        = "CA283",
        .name         = "Z-Tack (1983) (Bomb) (PAL)",
        .note         = "AKA Base Attack",
    },{
        .md5          = "d726621c676552afa503b7942af5afa2",
        .manufacturer = "Atari, Bob Whitehead",
        .model        = "CX26163P",
        .name         = "Blackjack (32 in 1) (1988) (Atari) (PAL) (4K)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "d73ad614f1c2357997c88f37e75b18fe",
        .manufacturer = "Goliath",
        .model        = "7",
        .name         = "Space Tunnel (1983) (Goliath) (PAL)",
    },{
        .md5          = "d74a81fcd89c5cf0bd4c88eb207ebd62",
        .name         = "Poker Squares (V0.00a) (2001) (B. Watson)",
    },{
        .md5          = "d763e3a9cdcdd56c715ec826106fab6a",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-001",
        .name         = "Dragster (1980) (Activision) (16K)",
    },{
        .md5          = "d7759fa91902edd93f1568a37dc70cdb",
        .manufacturer = "Atari, Robert C. Polaro",
        .model        = "CX26157",
        .name         = "Stunt Cycle (1980) (Atari) (Prototype) (4K)",
    },{
        .md5          = "d782543818b6320e4f60d77da2b596de",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Fishing Derby (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "d787ec6785b0ccfbd844c7866db9667d",
        .manufacturer = "Retroactive",
        .name         = "Qb (V0.04) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "d7891b0faa4c7f764482762d0ed427a5",
        .name         = "Bars and Text Demo 2 (PD)",
    },{
        .md5          = "d7b2259f6bb57bf37eac82365c1f8ad6",
        .manufacturer = "Parker Brothers, Mike Brodie",
        .model        = "PB5320",
        .name         = "Super Cobra (1983) (Parker Bros) (Prototype)",
    },{
        .md5          = "d7b58303ec8d8c4dbcbf54d3b9734c7e",
        .name         = "Paddle Demo (Joe Grand) (PD)",
    },{
        .md5          = "d7dd56677e4ec1e6627419478a4a9668",
        .name         = "Shadow Keep (Fixed) (04-03-2003) (Andrew Towers)",
    },{
        .md5          = "d7f5bf138cfc7feab7b8ef1534c8b477",
        .name         = "Eric Bergstrom's KC-135 (Radar Map) (Aaron Bergstrom)",
    },{
        .md5          = "d816fea559b47f9a672604df06f9d2e3",
        .manufacturer = "Atari, Gary Palmer",
        .model        = "CX26163P",
        .name         = "Fun with Numbers (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "d81bb6965e6c99b3be99ffd8978740e4",
        .name         = "Gunfight 2600 - The Final Kernel Part 3 (Manuel Rotschkar)",
    },{
        .md5          = "d82675ce67caf16afe5ed6b6fac8aa37",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Robot City (V0.23) (13-11-2002) (Thomas Jentzsch)",
    },{
        .md5          = "d8295eff5dcc43360afa87221ea6021f",
        .manufacturer = "Spectravideo",
        .model        = "SA-212",
        .name         = "Mangia' (1983) (Spectravideo) (PAL)",
    },{
        .md5          = "d82c8a58098a6b46c5b81c16180354d1",
        .manufacturer = "Dennis Debro",
        .name         = "Climber 5 (30-10-2002) (Dennis Debro) (Prototype)",
    },{
        .md5          = "d85f1e35c5445ac898746719a3d93f09",
        .manufacturer = "Suntek",
        .model        = "SS-034",
        .name         = "Farmyard Fun (1983) (Suntek) (PAL)",
        .note         = "AKA Pumuckl at the Farm House",
    },{
        .md5          = "d86deb100c6abed1588aa84b2f7b3a98",
        .manufacturer = "Atari, Bob Whitehead - Sears",
        .model        = "CX2625 - 6-99827, 49-75114",
        .name         = "Football (1979) (Atari) (4K)",
    },{
        .md5          = "d88691c995008b9ab61a44bb686b32e4",
        .name         = "Warring Worms (07-02-2002) (Billy Eno)",
    },{
        .md5          = "d89262907e70c13dff23356c4a9055d0",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Video Pinball (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "d89fedded0436fdeda7c3c37e2fb7cf1",
        .name         = "Surround (Unknown) (PAL) (4K)",
    },{
        .md5          = "d8acaa980cda94b65066568dd04d9eb0",
        .manufacturer = "CCE",
        .name         = "Sea Hunt (CCE)",
        .note         = "AKA Skindiver",
    },{
        .md5          = "d8b2c81cea5af04f795eb3dc6573d72b",
        .name         = "Tunnel Demo 2 (27-03-2003) (Christopher Tumber)",
    },{
        .md5          = "d8df256c0d89e494a9fb3e9abb8e44ac",
        .manufacturer = "Imagic, Michael Greene",
        .model        = "IA3312P",
        .name         = "No Escape! (1982) (Imagic) (PAL) [a]",
    },{
        .md5          = "d8e4c8e2d210270cd1e0f6d1b4582b91",
        .manufacturer = "Imagic, Mark Klein",
        .model        = "EIZ-003-04I",
        .name         = "Subterranea (1983) (Imagic) (PAL) [a]",
    },{
        .md5          = "d90205e29bb73a4cdf28ea7662ba0c3c",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Boulderdash Demo (Brighter Version) (09-12-2002) (Thomas Jentzsch)",
        .phosphor     = 1,
    },{
        .md5          = "d912312349d90e9d41a9db0d5cd3db70",
        .manufacturer = "CCE",
        .model        = "C-818",
        .name         = "Star Voyager (1983) (CCE)",
    },{
        .md5          = "d9548ad44e67edec202d1b8b325e5adf",
        .manufacturer = "Apollo - Games by Apollo, Dan Oliver - RCA Video Jeux",
        .model        = "AP-2002",
        .name         = "Space Cavern (1982) (Apollo) (PAL)",
        .note         = "AKA Les guerriers de l'espace",
    },{
        .md5          = "d968de2b4ff18bfe4a95066cde310578",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Amiga Mouse Hack v1.4 (PAL) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "d97e3d0b4575ce0b9a6132e19cfeac6e",
        .manufacturer = "Fabrizio Zavagli",
        .name         = "Space Treat (061002) (PD)",
        .note         = "Won't work with Stella < V1.2",
    },{
        .md5          = "d97fd5e6e1daacd909559a71f189f14b",
        .manufacturer = "M Network, Steve Crandall, Patricia Lewis Du Long",
        .model        = "MT4646",
        .name         = "Rocky & Bullwinkle (04-20-1983) (M Network) (Prototype)",
    },{
        .md5          = "d9ab6b67a17da51e5ad13717e93fa2e2",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Turbo (Coleco) Prototype Fake v0.1 (Thomas Jentzsch)",
    },{
        .md5          = "d9b49f0678776e04916fa5478685a819",
        .manufacturer = "Activision, John Van Ryzin - Ariola",
        .model        = "EAZ-036-04, EAZ-036-04B, EAZ-036-04I - 711 036-720",
        .name         = "H.E.R.O. (1984) (Activision) (PAL)",
    },{
        .md5          = "d9bd343533b61389b270c0787210943b",
        .manufacturer = "Atari, Douglas 'Solaris' Neubauer",
        .model        = "CX26134",
        .name         = "Last Starfighter (1984) (Atari) (Prototype)",
        .note         = "Genesis controller (C switches to map mode)",
    },{
        .md5          = "d9c9cece2e769c7985494b1403a25721",
        .manufacturer = "SOLID Corp. (D. Scott Williamson)",
        .model        = "CX2655*",
        .name         = "Star Castle 2600 (SolidCorp)",
        .phosphor     = 1,
    },{
        .md5          = "d9da2ae7c7894a29b43b3c6b79f3b7a2",
        .manufacturer = "Atari, Rob Fulop",
        .model        = "CX2633, CX2633P",
        .name         = "Night Driver (1980) (Atari) (PAL) (4K)",
        .note         = "Uses the Paddle Controllers (left only)",
        .phosphor     = 1,
    },{
        .md5          = "d9fbf1113114fb3a3c97550a0689f10f",
        .manufacturer = "ZiMAG - Emag - Vidco",
        .model        = "713-111 - GN-050",
        .name         = "Pizza Chef (1983) (ZiMAG) (Prototype)",
        .note         = "AKA Pizza Time",
    },{
        .md5          = "da0fb2a484d0d2d8f79d6e063c94063d",
        .name         = "Air Raiders (1982) (Unknown) [a]",
    },{
        .md5          = "da4e3396aa2db3bd667f83a1cb9e4a36",
        .manufacturer = "Activision, Steve Cartwright",
        .model        = "AX-027",
        .name         = "Plaque Attack (1983) (Activision)",
    },{
        .md5          = "da5096000db5fdaa8d02db57d9367998",
        .manufacturer = "Digitel",
        .name         = "River Raid (1983) (Digitel)",
    },{
        .md5          = "da6465a34d2e44d26aa9a2a0cd1bce4d",
        .manufacturer = "Absolute Entertainment, Alex DeMeo",
        .model        = "AG-041-04",
        .name         = "Title Match Pro Wrestling (1987) (Absolute) [a]",
    },{
        .md5          = "da66d75e4b47fab99733529743f86f4f",
        .manufacturer = "Digitel",
        .name         = "Chopper Command (1983) (Digitel)",
    },{
        .md5          = "da732c57697ad7d7af414998fa527e75",
        .manufacturer = "Atari - Glenn Axworthy",
        .model        = "CX26129",
        .name         = "Midnight Magic (1986) (Atari) (PAL)",
        .note         = "AKA Pinball Wizard",
        .phosphor     = 1,
    },{
        .md5          = "da79aad11572c80a96e261e4ac6392d0",
        .manufacturer = "Salu - Ubi Soft, Dennis M. Kiss",
        .model        = "460673",
        .name         = "Pick 'n' Pile (1990) (Salu) (PAL)",
        .swapPorts    = 1,
        .phosphor     = 1,
    },{
        .md5          = "da7a17dcdaa62d6971393c0a6faf202a",
        .name         = "Flag Capture (Unknown) (PAL)",
    },{
        .md5          = "dab844deed4c752632b5e786b0f47999",
        .name         = "Super Challenge Baseball (Unknown) (PAL)",
    },{
        .md5          = "dac38b4dd3da73bb7b2e9d70c61d2b7c",
        .name         = "Hangman Monkey Biglist3 (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "dac5c0fe74531f077c105b396874a9f1",
        .manufacturer = "Atari - GCC",
        .model        = "CX2680",
        .name         = "RealSports Tennis (1983) (Atari)",
    },{
        .md5          = "dac762e4d01d445bdef20b7771f6570e",
        .manufacturer = "Atari, Carla Meninsky, Ed Riddle - Sears",
        .model        = "CX2611 - 99821, 49-75149",
        .name         = "Indy 500 (1977) (Atari) (4K) [a]",
        .note         = "Uses the Driving Controllers",
        .left         = "DRIVING",
        .right        = "DRIVING",
    },{
        .md5          = "dad2ab5f66f98674f12c92abcfbf3a20",
        .name         = "Blue and White Sprite Demo (PD)",
    },{
        .md5          = "daeb54957875c50198a7e616f9cc8144",
        .manufacturer = "20th Century Fox Video Games, Douglas 'Dallas North' Neubauer",
        .model        = "11005",
        .name         = "Mega Force (1982) (20th Century Fox)",
    },{
        .md5          = "daef7d8e5a09981c4aa81573d4dbb380",
        .manufacturer = "Adam Thornton",
        .name         = "Lord of the Rings (Adam Thornton) (Hack)",
        .note         = "Hack of Dark Mage",
        .phosphor     = 1,
    },{
        .md5          = "dafc3945677ccc322ce323d1e9930beb",
        .manufacturer = "Atari",
        .name         = "A-Team (Atari) (Prototype) (PAL)",
    },{
        .md5          = "db1753cc702c18d3917ec7f3b0e8659f",
        .name         = "Frame Counter 2 (2001) (Jake Patterson) (PD)",
    },{
        .md5          = "db339aea2b65b84c7cfe0eeab11e110a",
        .name         = "Chronocolor Frame Demo 2 (10-01-2003) (Andrew Davie)",
    },{
        .md5          = "db4eb44bc5d652d9192451383d3249fc",
        .manufacturer = "CBS Electronics - E.F. Dreyer - VSS, Ed Salvo",
        .model        = "4L 2738 0000",
        .name         = "Mountain King (1983) (CBS Electronics)",
        .phosphor     = 1,
    },{
        .md5          = "db5073bd75eb05f7d62a7268396d1e77",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Golf (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "db76f7a0819659d9e585f2cdde9175c7",
        .manufacturer = "Xonox",
        .model        = "99005, 6220, 6250",
        .name         = "Robin Hood (1983) (Xonox) (PAL) [a]",
    },{
        .md5          = "db80d8ef9087af4764236f7b5649fa12",
        .manufacturer = "M Network, Steve Crandall, Patricia Lewis Du Long",
        .model        = "MT4646",
        .name         = "Rocky & Bullwinkle (1983) (Mattel) (Prototype) (4K)",
    },{
        .md5          = "db971b6afc9d243f614ebf380af0ac60",
        .manufacturer = "Gammation, Robert L. Esken Jr.",
        .name         = "Gamma-Attack (1983) (Gammation)",
        .note         = "Uses right joystick controller",
        .swapPorts    = 1,
    },{
        .md5          = "dba270850ae997969a18ee0001675821",
        .manufacturer = "Greg Troutman",
        .name         = "Dark Mage (Greg Troutman) (PD) (4K)",
        .phosphor     = 1,
    },{
        .md5          = "dbabb80e92ff18d8eecf615c0539151e",
        .name         = "Sprite Demo 3 (PD)",
    },{
        .md5          = "dbb10b904242fcfb8428f372e00c01af",
        .manufacturer = "Atari, John Dunn",
        .model        = "CX2631, CX2631P",
        .name         = "Superman (1979) (Atari) (PAL)",
    },{
        .md5          = "dbba14a0f69f0e13fdccb3fde3baedca",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Atari Trak-Ball Hack v1.3 (NTSC) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "dbc7485ad5814d466de780a3e7ed3b46",
        .manufacturer = "Kyle Pittman",
        .name         = "Pink Floyd (Kyle Pittman) (PD)",
        .note         = "Hack of Adventures of Tron (Mattel)",
    },{
        .md5          = "dbc8829ef6f12db8f463e30f60af209f",
        .manufacturer = "Data Age",
        .model        = "DA1001",
        .name         = "Encounter at L-5 (1982) (Data Age)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "dbdaf82f4f0c415a94d1030271a9ef44",
        .manufacturer = "CCE",
        .name         = "Kaboom! (CCE)",
        .note         = "Uses the Paddle Controllers (left only)",
    },{
        .md5          = "dbdd21e1ee3d72119e8cd14d943c585b",
        .name         = "Slot Machine (Unknown) (PAL) (4K)",
    },{
        .md5          = "dc13df8420ec69841a7c51e41b9fbba5",
        .manufacturer = "Atari, Mimi Nyden, Steve Woita",
        .model        = "CX26132",
        .name         = "Garfield (06-21-1984) (Atari) (Prototype)",
        .note         = "AKA Garfield on the Run",
    },{
        .md5          = "dc33479d66615a3b09670775de4c2a38",
        .manufacturer = "Suntek",
        .model        = "SS-033",
        .name         = "I.Q. Memory Teaser (1983) (Suntek) (PAL)",
        .note         = "AKA IQ 180",
    },{
        .md5          = "dc81c4805bf23959fcf2c649700b82bf",
        .manufacturer = "Imagic, Michael Greene",
        .model        = "720055-2A, IA3312P",
        .name         = "No Escape! (1983) (Imagic) (PAL)",
    },{
        .md5          = "dc905b22de0f191a029df13eddfcabc4",
        .manufacturer = "Atari, Warren Robinett",
        .name         = "Elf Adventure (05-02-83) (Atari) (Prototype)",
    },{
        .md5          = "dc97cbcf091a5ef4ca7fe95dc0848036",
        .manufacturer = "Atari - Roklan, Joe Gaucher, Alex Leavens",
        .model        = "CX2683",
        .name         = "Crazy Climber (1983) (Atari) (Prototype) [a2]",
    },{
        .md5          = "dca90ea1084a2fdbe300d7178ca1a138",
        .manufacturer = "Imagic, Dennis Koble",
        .model        = "IA3000P",
        .name         = "Trick Shot (1982) (Imagic) (PAL) [a]",
        .phosphor     = 1,
    },{
        .md5          = "dca941dab5c6f859b71883b13ade9744",
        .name         = "Hangman Pac-Man Biglist2 (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "dcba0e33aa4aed67630a4b292386f405",
        .manufacturer = "Retroactive",
        .name         = "Qb (V2.08) (Half Speed Version) (NTSC) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "dcc2956c7a39fdbf1e861fc5c595da0d",
        .manufacturer = "M Network - INTV - APh Technological Consulting, David Rolfe",
        .model        = "MT5664",
        .name         = "Frogs and Flies (1982) (M Network)",
        .note         = "AKA Frogs 'n' Flies",
    },{
        .md5          = "dcec46a98f45b193f07239611eb878c2",
        .name         = "Bars and Text Demo (PD)",
    },{
        .md5          = "dd08e18cfee87a0e7fc19a684b36e124",
        .manufacturer = "Atari - GCC, Kevin Osborn",
        .model        = "CX2689, CX2689P",
        .name         = "Kangaroo (1983) (Atari) (PAL) [a]",
    },{
        .md5          = "dd0cbe5351551a538414fb9e37fc56e8",
        .manufacturer = "Xonox - K-Tel Software - Product Guild, Anthony R. Henderson",
        .model        = "99006, 6220",
        .name         = "Sir Lancelot (1983) (Xonox) (PAL)",
    },{
        .md5          = "dd0de0f61af2a2a4878e377b880a3933",
        .manufacturer = "SOLID Corp. (D. Scott Williamson)",
        .model        = "CX2655-013",
        .name         = "Star Castle 2600 (SolidCorp) [013]",
        .phosphor     = 1,
    },{
        .md5          = "dd10b5ee37fdbf909423f2998a1f3179",
        .name         = "Space Instigators (V1.9) (21-10-2002) (Christopher Tumber)",
    },{
        .md5          = "dd13a16d14100819f79b1ce3a5bf499c",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Control - Atari Mouse Hack v1.15 (PAL) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "dd1422ffd538e2e33b339ebeef4f259d",
        .manufacturer = "Atari, Robert Zdybel",
        .name         = "Football Demo (1982) (Atari)",
    },{
        .md5          = "dd17711a30ad60109c8beace0d4a76e8",
        .name         = "Karate (Unknown) (PAL)",
    },{
        .md5          = "dd1842ba0f3f9d94dccb21eaa0f069b7",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Defender (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "dd45e370aceff765f1e72c619efd4399",
        .manufacturer = "Bit Corporation",
        .model        = "PG201",
        .name         = "Sea Monster (1982) (BitCorp)",
    },{
        .md5          = "dd4f4e0fbd81762533e39e6f5b55bb3a",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Turbo WIP (Thomas Jentzsch)",
    },{
        .md5          = "dd7598b8bcb81590428900f71b720efb",
        .manufacturer = "Xonox - K-Tel Software - Computer Magic",
        .model        = "99005, 6220, 6250",
        .name         = "Robin Hood (1983) (Xonox) (PAL)",
    },{
        .md5          = "dd7884b4f93cab423ac471aa1935e3df",
        .manufacturer = "Atari, Brad Stewart - Sears",
        .model        = "CX2649, 49-75163",
        .name         = "Asteroids (1981) (Atari)",
        .phosphor     = 1,
    },{
        .md5          = "dd8a2124d4eda200df715c698a6ea887",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum",
        .model        = "AR-4400",
        .name         = "Dragonstomper (3 of 3) (1982) (Starpath)",
    },{
        .md5          = "dd92d6ad50976f881d86b52d38616118",
        .manufacturer = "SpkSoft",
        .name         = "River Raid (SpkSoft) [h1]",
    },{
        .md5          = "dda23757407c4e217f64962c87ad0c82",
        .manufacturer = "Atari Freak 1",
        .name         = "Nitemare at Sunshine Bowl-a-Rama (Atari Freak 1) (Hack) [a]",
        .note         = "Hack of Pac-Man Jr.",
    },{
        .md5          = "ddd1efc1862cd3eb3baf4cba81ff5050",
        .name         = "Max3 (2001) (Maxime Beauvais) (PD)",
    },{
        .md5          = "dde55d9868911407fe8b3fefef396f00",
        .manufacturer = "Manuel Rotschkar (Xype)",
        .name         = "Seawolf (2004)",
    },{
        .md5          = "de0173ed6be9de6fd049803811e5f1a8",
        .manufacturer = "Xonox - K-Tel Software - Product Guild, Anthony R. Henderson",
        .model        = "99008, 6240",
        .name         = "Motocross Racer (1983) (Xonox)",
    },{
        .md5          = "de07e9cb43ad8d06a35f6506e22c62e9",
        .name         = "Oh No! (Version 4) (22-01-2003) (Andrew Davie)",
    },{
        .md5          = "de1a636d098349be11bbc2d090f4e9cf",
        .name         = "Pressure Gauge (Hozer Video Games)",
    },{
        .md5          = "de1e9fb700baf8d2e5ae242bffe2dbda",
        .manufacturer = "Activision - Imagineering, Mike Reidel",
        .model        = "EAK-043-04I",
        .name         = "Commando (1988) (Activision) (PAL)",
    },{
        .md5          = "de24f700fd28d5b8381de13abd091db9",
        .manufacturer = "CCE",
        .name         = "Plaque Attack (CCE)",
    },{
        .md5          = "de29e46dbea003c3c09c892d668b9413",
        .manufacturer = "Coleco - Woodside Design Associates, Steve 'Jessica Stevens' Kitchen",
        .model        = "4L1717, 4L1718, 4L1719, 4L2277",
        .name         = "Carnival (1983) (CBS Electronics) (PAL)",
    },{
        .md5          = "de3d0e37729d85afcb25a8d052a6e236",
        .manufacturer = "Spectravision - Spectravideo",
        .model        = "SA-204",
        .name         = "Tapeworm (1982) (Spectravision)",
        .phosphor     = 1,
    },{
        .md5          = "de4436eaa41e5d7b7609512632b90078",
        .manufacturer = "Activision, David Crane",
        .model        = "AX-014, AX-014-04",
        .name         = "Grand Prix (1982) (Activision) (16K)",
    },{
        .md5          = "de5aab22e5aba5edcb29a3e7491ff319",
        .name         = "Pac Kong (Unknown)",
        .note         = "AKA Inca Gold",
    },{
        .md5          = "de61a0b171e909a5a4cfcf81d146dbcb",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-005",
        .name         = "Tom Boy (1983) (Rainbow Vision) (PAL)",
        .note         = "AKA Pitfall!",
    },{
        .md5          = "de62f8a30298e2325249fe112ecb5c10",
        .manufacturer = "CCE",
        .model        = "C-810",
        .name         = "Enduro (1983) (CCE)",
    },{
        .md5          = "de78b3a064d374390ac0710f95edde92",
        .manufacturer = "Bomb - Onbase",
        .model        = "CA281",
        .name         = "Assault (1983) (Bomb)",
        .note         = "AKA Sky Alien",
    },{
        .md5          = "de7a64108074098ba333cc0c70eef18a",
        .name         = "Nuts (Unknown)",
    },{
        .md5          = "de7bca4e569ad9d3fd08ff1395e53d2d",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Thrust (V1.22) (2000) (Thomas Jentzsch)",
        .note         = "Supports BoosterGrip",
        .left         = "BOOSTERGRIP",
    },{
        .md5          = "de8443ff47283e7b274a7838cb071fb6",
        .manufacturer = "Atari, Lou Harp",
        .model        = "CX26122",
        .name         = "Sinistar (01-04-1984) (Atari) (Prototype)",
    },{
        .md5          = "dea0ade296f7093e71185e802b500db8",
        .manufacturer = "CCE",
        .name         = "Fishing Derby (CCE)",
    },{
        .md5          = "deb39482e77f984d4ce73be9fd8adabd",
        .manufacturer = "Activision, David Lubar",
        .model        = "AK-048-04",
        .name         = "River Raid II (1988) (Activision) [a]",
    },{
        .md5          = "ded26e1cb17f875a9c17515c900f9933",
        .name         = "Space Treat (29-12-2002) (Fabrizio Zavagli)",
    },{
        .md5          = "df12953b919844dad2070ed2e70c9fa2",
        .manufacturer = "Amiga - Video Soft",
        .model        = "3135",
        .name         = "S.A.C. Alert (1983) (Amiga) (Prototype) (PAL)",
        .note         = "Uses Joyboard",
    },{
        .md5          = "df2745d585238780101df812d00b49f4",
        .manufacturer = "Bit Corporation",
        .model        = "PG202",
        .name         = "Space Tunnel (1982) (BitCorp)",
    },{
        .md5          = "df3e6a9b6927cf59b7afb626f6fd7eea",
        .name         = "Tuby Bird (Unknown) (PAL)",
        .note         = "AKA Dolphin",
    },{
        .md5          = "df40af244a8d68b492bfba9e97dea4d6",
        .manufacturer = "Franklin Cruz",
        .name         = "Asteroids 2 (Franlin Cruz) (Hack)",
        .note         = "Hack of Asteroids",
        .phosphor     = 1,
    },{
        .md5          = "df5cc5cccdc140eb7107f5b8adfacda1",
        .manufacturer = "Cracker Jack Productions",
        .name         = "Lumberman (Cracker Jack) (Hack)",
        .note         = "Hack of Pac-Man",
    },{
        .md5          = "df62a658496ac98a3aa4a6ee5719c251",
        .manufacturer = "Atari, Tom Reuterdahl - Sears",
        .model        = "CX2626 - 6-99829, 49-75116",
        .name         = "Miniature Golf (1979) (Atari)",
        .note         = "AKA Arcade Golf",
    },{
        .md5          = "df6a28a89600affe36d94394ef597214",
        .manufacturer = "Apollo - Games by Apollo, Dan Oliver",
        .model        = "AP-2002",
        .name         = "Space Cavern (1982) (Apollo)",
    },{
        .md5          = "df6a46714960a3e39b57b3c3983801b5",
        .manufacturer = "Puzzy - Bit Corporation",
        .model        = "PG201",
        .name         = "Sea Monster (1982) (Puzzy) (PAL)",
    },{
        .md5          = "df753cb87d3af4d03f694ab848638108",
        .manufacturer = "CBS Electronics, Bob Curtiss",
        .model        = "4L1845, 4L1852, 4L1853, 4L1854",
        .name         = "Solar Fox (1983) (CBS Electronics) (PAL) [a]",
    },{
        .md5          = "df91277a3569344b89e6e8bd5bebc8d1",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Marble Craze - Amiga Mouse Hack v1.0 (PAL) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controllers",
    },{
        .md5          = "df95e4af466c809619299f49ece92365",
        .manufacturer = "Atari - CCW, Michael Callahan, Preston Stuart",
        .model        = "CX26103",
        .name         = "Alpha Beam with Ernie (06-03-1983) (Atari) (Prototype) (PAL)",
        .note         = "Uses Keyboard Controllers",
    },{
        .md5          = "dfad86dd85a11c80259f3ddb6151f48f",
        .manufacturer = "HES - Imagineering, David Lubar",
        .model        = "535",
        .name         = "My Golf (1990) (HES) (PAL) [fixed]",
    },{
        .md5          = "dfafa3fa58f5cc3f0342cca475df6095",
        .name         = "Space Treat (V1.1 Beta) (24-12-2002) (Fabrizio Zavagli)",
    },{
        .md5          = "dfc03ef371cf5163f54c50d8ee73c8cf",
        .manufacturer = "Atari, Gary Palmer",
        .model        = "CX2661",
        .name         = "Fun with Numbers (1980) (Atari) (4K)",
        .note         = "AKA Basic Math",
    },{
        .md5          = "dfc3dbbb39f05d7dd8ee3ac987478970",
        .name         = "Imagic Selector ROM (1982) (Imagic) (PAL)",
    },{
        .md5          = "dfcdd6f593bb7b05dbc2e8e1fc6ee0de",
        .name         = "Gunfight 2600 - Scenarios complete (Manuel Rotschkar)",
    },{
        .md5          = "dfe034297200dff672df9533ed1449a9",
        .name         = "Sprite Movement Demo 1 (2001) (Roger Williams)",
    },{
        .md5          = "dfe6aa7443bb813cefa35a4cf4887422",
        .name         = "This Planet Sucks (Greg Troutman) [a1]",
    },{
        .md5          = "dfe885fb877a0f8fa604b7d99a6deaad",
        .manufacturer = "Atari, Robert C. Polaro, Alan J. Murphy - Sears",
        .model        = "CX2609 - 49-75186",
        .name         = "Defender (11-XX-1981) (Atari) (Prototype)",
    },{
        .md5          = "dff33523ccd2fdc8912e84cab8e0d982",
        .name         = "Fu Kung! (V0.03) (10-01-2003) (Andrew Davie)",
    },{
        .md5          = "e01e00504e6d4b88fa743c0bbe8a96e5",
        .name         = "Qb (Special Edition, some bugfixes) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "e020f612255e266a8a6a9795a4df0c0f",
        .manufacturer = "Telegames - VSS",
        .model        = "7062 A305",
        .name         = "Universal Chaos (1988) (Telegames) (PAL)",
        .note         = "AKA Targ",
    },{
        .md5          = "e02156294393818ff872d4314fc2f38e",
        .manufacturer = "Sancho - Tang's Electronic Co.",
        .model        = "TEC005",
        .name         = "Dice Puzzle (1983) (Sancho) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "e0221c95aa657f5764eeeb64c8429258",
        .name         = "Tomb Raider 2600 [REV 02] (Montezuma's Revenge Hack)",
    },{
        .md5          = "e03b0b091bea5bc9d3f14ee0221e714d",
        .manufacturer = "CBS Electronics, Bob Curtiss",
        .model        = "4L1852, 4L1853, 4L1854, 4L1855",
        .name         = "Solar Fox (1983) (CBS Electronics) (PAL)",
    },{
        .md5          = "e040df95a055b18ebdb094e904cb71b2",
        .name         = "Score Demo (B. Watson)",
    },{
        .md5          = "e04f1c1e4401d584d3f4343410a5bcc4",
        .manufacturer = "Wizard Video Games - VSS - MicroGraphic Image, Robert Barber, Tim Martin",
        .model        = "007",
        .name         = "Halloween (1983) (Wizard Video Games) (Prototype) [a]",
    },{
        .md5          = "e0b24c3f40a46cda52e29835ab7ad660",
        .manufacturer = "Quelle - Otto Versand",
        .model        = "626.502 9 - 746381",
        .name         = "Top Gun (1983) (Quelle) (PAL)",
        .note         = "AKA Air Raiders",
    },{
        .md5          = "e0cbfc33f4926022ccaf6d0d0e920a0e",
        .manufacturer = "Parker Brothers - Roklan, Joe Gaucher",
        .model        = "PB5080",
        .name         = "Gyruss (1983) (Parker Bros) (Prototype) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "e0cf2dcc4c1348c468f5bb1e421c9164",
        .name         = "Invader Sprites in a Line Demo (PD)",
    },{
        .md5          = "e0de3773f5b867795db557be7b8a703e",
        .name         = "Boulderdash (13 Blocks Wide) (02-04-2003) (Andrew Davie)",
    },{
        .md5          = "e0eff071f578ecf19edc2ab276644e46",
        .name         = "Gas Gauge Demo (2001) (Joe Grand) (PD)",
    },{
        .md5          = "e1029676edb3d35b76ca943da7434da8",
        .manufacturer = "Atari, Robert C. Polaro, Alan J. Murphy - Sears",
        .model        = "CX2609 - 49-75186",
        .name         = "Defender (10-30-1981) (Atari) (Prototype)",
    },{
        .md5          = "e10bf1af6bf3b4a253c5bef6577fe923",
        .manufacturer = "Rob Kudla",
        .name         = "Space Invaders (1978) (Atari) [h1]",
        .note         = "Hack of Space Invaders (Atari)",
    },{
        .md5          = "e10d2c785aadb42c06390fae0d92f282",
        .manufacturer = "Parker Brothers, Dawn Stockbridge",
        .model        = "PB5910",
        .name         = "Strawberry Shortcake - Musical Match-Ups (1983) (Parker Bros)",
    },{
        .md5          = "e1143b72a30d4d3fee385eec38b4aa4d",
        .name         = "Word Zapper (Unknown)",
    },{
        .md5          = "e12e32dee68201b6765fcd0ed54d6646",
        .manufacturer = "Atari, Larry Kaplan",
        .model        = "CX2612, CX2612P",
        .name         = "Street Racer (1977) (Atari) (PAL)",
        .note         = "Uses the Paddle Controllers (swapped)",
        .swapPaddles  = 1,
    },{
        .md5          = "e13818a5c0cb2f84dd84368070e9f099",
        .manufacturer = "CCE",
        .model        = "C-839",
        .name         = "Misterious Thief, A (1983) (CCE)",
        .note         = "AKA A Mysterious Thief",
        .phosphor     = 1,
    },{
        .md5          = "e13c7627b2e136b9c449d9e8925b4547",
        .manufacturer = "Atari, Alan Miller - Sears",
        .model        = "CX2624 - 6-99826, 49-75113",
        .name         = "Basketball (1978) (Atari) (4K)",
    },{
        .md5          = "e1486c7822c07117b4f94a32e5ed68c1",
        .manufacturer = "Coleco - Individeo, Ed Temple",
        .name         = "Cabbage Patch Kids (06-14-1984) (Coleco) (Prototype)",
        .note         = "Adventures in the Park",
    },{
        .md5          = "e14dc36b24fe22c04fa076e298f2e15f",
        .manufacturer = "Activision, Larry Kaplan, David Crane",
        .model        = "AG-010, AG-010-04",
        .name         = "Kaboom! (1981) (Activision) (16K)",
        .note         = "Uses the Paddle Controllers (left only)",
    },{
        .md5          = "e14feddeb82f5160ed5cf9ca4078e58d",
        .name         = "SpaceMaster X-7 (Unknown) (PAL)",
    },{
        .md5          = "e150f0d14f013a104b032305c0ce23ef",
        .manufacturer = "Spectravision - Spectravideo",
        .model        = "SA-205",
        .name         = "China Syndrome (1982) (Spectravision) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "e15b5525cf8f77297b322838df8d999c",
        .name         = "Sprite Demo 0 (PD)",
    },{
        .md5          = "e171558c51bb3bac97bfa79fa2c1a19c",
        .name         = "Warring Worms (Tim Strauss Edition) (20-12-2002) (Billy Eno)",
    },{
        .md5          = "e17699a54c90f3a56ae4820f779f72c4",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-020",
        .name         = "Tuby Bird (1983) (Rainbow Vision) (PAL)",
        .note         = "AKA Dolphin",
    },{
        .md5          = "e18abe87035379c56b435bfe8175077b",
        .manufacturer = "Grimlock",
        .name         = "Rumble 2600 (Grimlock) (Hack)",
        .note         = "Hack of Mario Bros.",
    },{
        .md5          = "e1a51690792838c5c687da80cd764d78",
        .manufacturer = "20th Century Fox, John Russell",
        .name         = "Alligator People (1983) (20th Century Fox) (Prototype)",
    },{
        .md5          = "e1b90f1e01b1a316d7bbf141525cc00e",
        .name         = "Sky Jinks (Unknown) (PAL) (4K) (Hack)",
    },{
        .md5          = "e1d5c8213e82820128fa9c4775f1e166",
        .manufacturer = "Jess Ragan",
        .name         = "Jungle King (2003) (Jess Ragan) (Hack)",
        .note         = "Hack of Jungle Hunt",
    },{
        .md5          = "e1d79e4e7c150f3861256c541ec715a1",
        .name         = "Space Jockey (Unknown) (PAL)",
    },{
        .md5          = "e1e09e2f280e8e142121a377d0dc1b46",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Thrust (V1.21) (2000) (Thomas Jentzsch)",
        .note         = "Bugfixed",
        .left         = "BOOSTERGRIP",
    },{
        .md5          = "e1efe2ef7664bb6758b1a22ff8ea16a1",
        .manufacturer = "Dynacom",
        .name         = "Enduro (1983) (Dynacom)",
    },{
        .md5          = "e1f88da6da8a7d521ca1dcbf2bc6978b",
        .manufacturer = "Activision, Bob Whitehead - Ariola",
        .model        = "EAG-005, PAG-005, EAG-005-04B - 711 005-715",
        .name         = "Skiing (1980) (Activision) (PAL) (4K)",
    },{
        .md5          = "e21ee3541ebd2c23e817ffb449939c37",
        .manufacturer = "Tigervision - Software Electronics Corp., Karl T. Olinger - Teldec",
        .model        = "7-001",
        .name         = "King Kong (1982) (Tigervision)",
    },{
        .md5          = "e227be19f572f6900e314213ae9a4deb",
        .manufacturer = "Atari, Dan Hitchens, Mimi Nyden",
        .model        = "CX2656",
        .name         = "SwordQuest - EarthWorld (1982) (Atari) (Prototype)",
        .note         = "AKA Adventure I, SwordQuest I - EarthWorld",
    },{
        .md5          = "e237ee91514d5ed535c95a14fc608c11",
        .manufacturer = "Activision, Matthew L. Hubbard, Bob Whitehead",
        .model        = "AX-024",
        .name         = "Dolphin (1983) (Activision) (8K)",
    },{
        .md5          = "e2389c0be5b5b84e0d3ca36ec7e67514",
        .manufacturer = "Retroactive",
        .name         = "Qb (V2.09) (NTSC) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "e24d7d879281ffec0641e9c3f52e505a",
        .manufacturer = "Parker Brothers, Mark Lesser",
        .model        = "PB5950",
        .name         = "Lord of the Rings (1983) (Parker Bros) (Prototype)",
        .note         = "Journey to Rivendell (The Lord of the Rings I)",
    },{
        .md5          = "e25e173740f7ecc0e23025445c4591f3",
        .manufacturer = "Greg Zumwalt",
        .name         = "Comitoid (Greg Zumwalt)",
    },{
        .md5          = "e275cbe7d4e11e62c3bfcfb38fca3d49",
        .manufacturer = "M Network - INTV - APh Technological Consulting, Ken Smith",
        .model        = "MT5658",
        .name         = "Super Challenge Football (1982) (M Network)",
        .note         = "AKA Pro Football",
    },{
        .md5          = "e27d518993b0a010f16e92b971ecdcdd",
        .manufacturer = "Manuel Polik",
        .name         = "Star Fire (2003) (XYPE) (PAL)",
    },{
        .md5          = "e28113d10c0c14cc3b5f430b0d142fcb",
        .manufacturer = "CCE",
        .model        = "C-816",
        .name         = "Keystone Kappers (1983) (CCE) [a]",
        .note         = "AKA Keystone Kapers",
    },{
        .md5          = "e2846af3e4d172b251ab77cbdd01761e",
        .manufacturer = "Steve Engelhardt",
        .name         = "Adventure Plus (2003) (Steve Engelhardt) (Hack)",
        .note         = "Hack of Adventure",
    },{
        .md5          = "e2904748da63dfefc8816652b924b642",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Catch Time (Jone Yuan)",
        .note         = "AKA Plaque Attack",
    },{
        .md5          = "e2b36d0781d5a5be64dad87fe20e0de3",
        .manufacturer = "Parker Brothers - On-Time Software, Joe Gaucher, Dan Kurczewski, Louis Marbel, Kathy Von",
        .model        = "PB5110",
        .name         = "James Bond 007 (1983) (Parker Bros) (Prototype) [a4]",
        .note         = "James Bond Agent 007",
    },{
        .md5          = "e2b682f6e6d76b35c180c7d847e93b4f",
        .name         = "Dodge Demo 4 (PD)",
    },{
        .md5          = "e2c1b60eaa8eda131632d73e4e0c146b",
        .manufacturer = "Atari - GCC, Mark Ackerman, Noelie Alito",
        .model        = "CX2692",
        .name         = "Moon Patrol (07-04-1983) (Atari) (Prototype)",
    },{
        .md5          = "e2c89f270f72cd256ed667507fa038a2",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum",
        .model        = "AR-4101",
        .name         = "Communist Mutants from Space (1982) (Arcadia) (PAL)",
    },{
        .md5          = "e2ca84a2bb63d1a210ebb659929747a9",
        .manufacturer = "Telesys, Don 'Donyo' Ruffcorn",
        .model        = "1002",
        .name         = "Cosmic Creeps (1982) (Telesys) (PAL)",
        .note         = "AKA Space Maze, Spaze Maze",
        .phosphor     = 1,
    },{
        .md5          = "e2eccbbe963f80f291cb1f18803bf557",
        .manufacturer = "Atari, Joe Decuir, Steve Mayer, Larry Wagner",
        .model        = "CX26163P",
        .name         = "Combat (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "e30f3a37032da52d7815b5a409f6d4b4",
        .manufacturer = "SEGA, Fred Mack",
        .name         = "Bear Game Demo (1983) (SEGA)",
    },{
        .md5          = "e314b42761cd13c03def744b4afc7b1b",
        .manufacturer = "Activision, David Crane, Dan Kitchen",
        .model        = "AZ-108-04",
        .name         = "Ghostbusters (1985) (Activision)",
    },{
        .md5          = "e34c236630c945089fcdef088c4b6e06",
        .manufacturer = "Activision, Steve Cartwright, David Crane - Ariola",
        .model        = "EAB-035-04 - 711 035-721",
        .name         = "Pitfall II (1984) (Activision) (PAL)",
        .note         = "Lost Caverns",
    },{
        .md5          = "e3533684a7ef930a7fbd0c4dd8ec4847",
        .name         = "Video Pinball (Unknown)",
    },{
        .md5          = "e3600be9eb98146adafdc12d91323d0f",
        .manufacturer = "Atari, Carol Shaw",
        .model        = "CX2618, CX2618P",
        .name         = "3-D Tic-Tac-Toe (1980) (Atari) (PAL)",
    },{
        .md5          = "e363e467f605537f3777ad33e74e113a",
        .manufacturer = "Atari, Bob Whitehead - Sears",
        .model        = "CX2603 - 99803, 49-75601",
        .name         = "Star Ship (1977) (Atari)",
    },{
        .md5          = "e377c3af4f54a51b85efe37d4b7029e6",
        .manufacturer = "20th Century Fox Video Games, Beck-Tech, Steve Beck",
        .model        = "11035",
        .name         = "Save the Whales (1983) (20th Century Fox) (Prototype)",
    },{
        .md5          = "e37c8055d70979af354251ebe9f1b7dd",
        .manufacturer = "HES",
        .name         = "Mega Funpak - Gorf, P. Patrol, Pacman, Skeet Shoot (HES) (PAL)",
    },{
        .md5          = "e38dc1f81a02e325562cd285123f579b",
        .manufacturer = "Atari - GCC, Mike Feinstein",
        .model        = "CX2681, CX2681P",
        .name         = "Battlezone (1983) (Atari) (PAL) [a1]",
    },{
        .md5          = "e39843c56b7a4a08b18fa7949ec3ee6b",
        .name         = "Joshua Invaders (Hack)",
        .note         = "Hack of Space Invaders",
    },{
        .md5          = "e39a13b13dc82c5fdbfbbfd55ba1230e",
        .name         = "Analog Clock (Additional Frame Info) (V0.0) (20-01-2003) (Andrew Davie)",
    },{
        .md5          = "e3c0451d29dad724231bc5818ec4bae0",
        .name         = "Single-Scanline Positioning Demo 1 (2001) (Roger Williams)",
    },{
        .md5          = "e3c35eac234537396a865d23bafb1c84",
        .manufacturer = "TechnoVision - Video Technology",
        .model        = "TVS1001",
        .name         = "Nuts (1983) (TechnoVision) (PAL)",
    },{
        .md5          = "e3ed4ba3361756970f076e46e9cad1d2",
        .name         = "Tennis (Unknown) (PAL) (4K) [a]",
    },{
        .md5          = "e40a818dac4dd851f3b4aafbe2f1e0c1",
        .manufacturer = "Atari, Bill Aspromonte, Dr. Lee Salk",
        .model        = "CX26135",
        .name         = "Peek-A-Boo (1984) (Atari) (Prototype)",
        .note         = "Uses the Keyboard Controllers",
    },{
        .md5          = "e42b937c30c617241ca9e01e4510c3f6",
        .name         = "Pitfall! (No Walls Hack)",
    },{
        .md5          = "e434c0e161dd3c3fb435eb6bad2e182c",
        .manufacturer = "Atari - GCC, Mike Feinstein, Brad Rice",
        .model        = "CX2681",
        .name         = "Battlezone (05-02-1983) (Atari) (Prototype)",
    },{
        .md5          = "e48d3a4056ede9393586421996db1ae8",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Atari Trak-Ball Hack v1.4 (PAL60) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "e49ac0ec879a0d7820bc2598fc2cfcd4",
        .manufacturer = "CCE",
        .name         = "Kaboom! (CCE) (4K)",
        .note         = "Uses the Paddle Controllers (left only)",
    },{
        .md5          = "e4a0b28befaaa2915df1fa01238b1e29",
        .name         = "Gunfight 2600 - Red River (Manuel Rotschkar)",
    },{
        .md5          = "e4afe157c09962cf39cdb25845d83d47",
        .manufacturer = "Activision, David Crane - Ariola",
        .model        = "EAG-009, PAG-009 - 711 009-720",
        .name         = "Freeway (1981) (Activision) (PAL) (4K)",
    },{
        .md5          = "e4b12deaafd1dbf5ac31afe4b8e9c233",
        .manufacturer = "Adam Thornton",
        .name         = "Lord of the Rings (Adam Thornton) (Hack) [a]",
        .note         = "Hack of Dark Mage",
        .phosphor     = 1,
    },{
        .md5          = "e4bff1d5df70163c0428a1ead309c22d",
        .manufacturer = "Atari, Robert C. Polaro, Alan J. Murphy",
        .model        = "CX2609, CX2609P",
        .name         = "Defender (1982) (Atari) (PAL)",
    },{
        .md5          = "e4c00beb17fdc5881757855f2838c816",
        .manufacturer = "20th Century Fox Video Games - Sirius, Ed Hodapp",
        .model        = "11004",
        .name         = "Deadly Duck (1982) (20th Century Fox)",
    },{
        .md5          = "e4c2077a18e3c27f4819aa7757903aa0",
        .name         = "Many Blue Bars Demo (PD)",
    },{
        .md5          = "e4c666ca0c36928b95b13d33474dbb44",
        .manufacturer = "Arcadia Corporation, Steve Hales, Stephen H. Landrum",
        .model        = "4 AR-4102",
        .name         = "Suicide Mission (1982) (Arcadia)",
        .note         = "AKA Meteoroids",
        .phosphor     = 1,
    },{
        .md5          = "e4d41f2d59a56a9d917038682b8e0b8c",
        .manufacturer = "Cody Pittman",
        .name         = "Kiss Meets Pacman (Cody Pittman) (Hack)",
        .note         = "Hack of Pac-Man",
    },{
        .md5          = "e4e9125a8741977583776729359614e1",
        .manufacturer = "SnailSoft",
        .name         = "Comitoid beta 4 (SnailSoft)",
    },{
        .md5          = "e4fa739c81b003c92bea7da5e84c7feb",
        .manufacturer = "Akor",
        .name         = "TV Boy (1992) (Akor) (NTSC) [bad dump]",
        .note         = "Includes 127 games",
        .left         = "JOYSTICK",
        .right        = "JOYSTICK",
    },{
        .md5          = "e505bd8e59e31aaed20718d47b15c61b",
        .manufacturer = "Funvision - Fund. Int'l Co.",
        .name         = "Space War (1982) (Funvision) (PAL)",
        .note         = "AKA Condor Attack",
    },{
        .md5          = "e51030251e440cffaab1ac63438b44ae",
        .manufacturer = "Parker Brothers - On-Time Software, Joe Gaucher, Dan Kurczewski, Louis Marbel, Kathy Von",
        .model        = "PB5110",
        .name         = "James Bond 007 (1984) (Parker Bros)",
        .note         = "James Bond Agent 007",
        .phosphor     = 1,
    },{
        .md5          = "e51c23389e43ab328ccfb05be7d451da",
        .manufacturer = "Arcadia Corporation, Scott Nelson",
        .model        = "13",
        .name         = "Sweat! - The Decathlon Game (1983) (Arcadia) (Prototype)",
        .note         = "Uses the Paddle Controllers (left only)",
    },{
        .md5          = "e5359cbbbff9c6d7fe8aeff5fb471b46",
        .name         = "Boom Bang (Unknown) [a1]",
        .note         = "AKA Crackpots",
    },{
        .md5          = "e549f1178e038fa88dc6d657dc441146",
        .manufacturer = "Atari, Bob Whitehead - Sears",
        .model        = "CX2625 - 6-99827, 49-75114",
        .name         = "Football (1979) (Atari)",
    },{
        .md5          = "e556e07cc06c803f2955986f53ef63ed",
        .manufacturer = "Coleco - Individeo, Ed Temple",
        .model        = "2665",
        .name         = "Front Line (1984) (Coleco)",
    },{
        .md5          = "e558be88eef569f33716e8e330d2f5bc",
        .manufacturer = "Shock Vision",
        .name         = "Keystone Kapers (Shock Vision)",
    },{
        .md5          = "e56da674188ba2f02c7a0a343a01236f",
        .name         = "This Planet Sucks Demo 4 (Greg Troutman) (PD)",
    },{
        .md5          = "e59d022d524d05acc19515598c831e4d",
        .manufacturer = "Alessandro Ciceri",
        .name         = "MagiCard+ (alex_79) WIP_20150118 (PAL)",
        .note         = "MagiCard hack",
    },{
        .md5          = "e5a6e0bb7d56e2f08b237e15076e5699",
        .name         = "Color Table Display Helper (PD)",
    },{
        .md5          = "e5bacf526036d3c8c99db5b030cf00e7",
        .name         = "Starmaster (Genesis)",
        .note         = "Genesis controller (C switches to map mode)",
    },{
        .md5          = "e5d5085123a98c1e61818caa2971e999",
        .name         = "Euchre (PAL) (Erik Eid) (PD)",
    },{
        .md5          = "e5d72ff8bab4450be57785cc9e83f3c0",
        .manufacturer = "Telegames",
        .model        = "6082 A145",
        .name         = "Kung Fu Superkicks (1988) (Telegames) (PAL)",
        .note         = "AKA Chuck Norris Superkicks",
    },{
        .md5          = "e5ecd78edd24326a968809decbc7b916",
        .manufacturer = "Imagic, Bob Smith",
        .model        = "720020-1A, IA3611",
        .name         = "Cheese (Dragonfire Beta) (05-21-1982) (Imagic) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "e5f17b3e62a21d0df1ca9aee1aa8c7c5",
        .manufacturer = "CommaVid, John Bronstein",
        .model        = "CM-003",
        .name         = "Cosmic Swarm (1982) (CommaVid)",
        .note         = "AKA Termite",
        .phosphor     = 1,
    },{
        .md5          = "e5f360226dc552aba3e7e9b202330f48",
        .manufacturer = "Supercat",
        .name         = "Mega Bitmap Demo (2007) (Supercat)",
        .phosphor     = 1,
    },{
        .md5          = "e5f84930aa468db33c0d0f7b26dd8293",
        .manufacturer = "CCE",
        .model        = "C-826",
        .name         = "Grand Prix (1983) (CCE) [a]",
    },{
        .md5          = "e5fcc62e1d73706be7b895e887e90f84",
        .name         = "Air-Sea Battle (Unknown) (PAL) (4K)",
    },{
        .md5          = "e600f5e98a20fafa47676198efe6834d",
        .manufacturer = "Parker Brothers - Roklan, Joe Gaucher",
        .model        = "PB5080",
        .name         = "Gyruss (1984) (Parker Bros) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "e609e8a007127b8fcff79ffc380da6b1",
        .name         = "Multi-Sprite Game V2.3 (Piero Cavina) (PD)",
    },{
        .md5          = "e61210293b14c9c4ecc91705072c6a7e",
        .manufacturer = "Gameworld",
        .model        = "133-005",
        .name         = "Bugs (1983) (Gameworld) (PAL)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "e62e60a3e6cb5563f72982fcd83de25a",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "End of the World (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "e63a87c231ee9a506f9599aa4ef7dfb9",
        .name         = "Threshold (Unknown)",
    },{
        .md5          = "e63efdfda9a4003dcd77a854a781a06a",
        .manufacturer = "Paul Slocum",
        .name         = "Combat Rock (PD) (Hack) [a]",
        .note         = "Hack of Combat",
    },{
        .md5          = "e643aaec9a9e1c8ab7fe1eae90bc77d7",
        .manufacturer = "Roger Williams",
        .name         = "Asymmetric Playfield (Roger Williams)",
    },{
        .md5          = "e64a8008812327853877a37befeb6465",
        .manufacturer = "Answer Software Corporation - TY Associates, Mike Wentz",
        .model        = "ASC1002",
        .name         = "Gauntlet (1983) (Answer Software)",
    },{
        .md5          = "e6508b878145187b87b9cded097293e7",
        .name         = "Oystron (V2.8) (Piero Cavina) (PD)",
    },{
        .md5          = "e66e5af5dea661d58420088368e4ef0d",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AG-011",
        .name         = "Stampede (1981) (Activision) (4K)",
    },{
        .md5          = "e67b0ed32fd9d28d12ab3775d52e8c3a",
        .manufacturer = "Atari, Omegamatrix",
        .name         = "Video Olympics Menu (2020) (Hack)",
        .note         = "Hack of Video Olympics",
        .swapPaddles  = 1,
    },{
        .md5          = "e6d5948f451a24994dfaaca51dfdb4e1",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Football (Jone Yuan) (4K)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "e6de4ef9ab62e2196962aa6b0dedac59",
        .manufacturer = "Imagic, Wilfredo Aguilar, Michael Becker, Dennis Koble",
        .model        = "720113-2A, 13206",
        .name         = "Solar Storm (1983) (Imagic) (PAL)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "e6e5bb0e4f4350da573023256268313d",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Missile Control (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "e6f49a1053c79211f82be4d90dc9fe3d",
        .name         = "Gunfight 2600 - Little progress... (2001) (Manuel Rotschkar)",
    },{
        .md5          = "e723ad8f406cb258b89681ef4cef0eff",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Sadoom (Thomas Jentzsch) (PAL) (Hack)",
        .note         = "Hack of Kaboom!",
    },{
        .md5          = "e72eb8d4410152bdcb69e7fba327b420",
        .manufacturer = "Atari, Douglas Neubauer, Mimi Nyden",
        .model        = "CX26136",
        .name         = "Solaris (1986) (Atari)",
        .note         = "AKA The Last Starfighter, Star Raiders II, Universe",
    },{
        .md5          = "e72ee2d6e501f07ec5e8a0efbe520bee",
        .manufacturer = "Imagic, Dave Johnson",
        .model        = "720119-2A, 13211, EIX-004-04I",
        .name         = "Quick Step! (1983) (Imagic) (PAL)",
    },{
        .md5          = "e73838c43040bcbc83e4204a3e72eef4",
        .manufacturer = "CCE",
        .name         = "Apples and Dolls (CCE)",
        .note         = "AKA Open, Sesame!",
        .phosphor     = 1,
    },{
        .md5          = "e74022cfe31ec8908844718dfbdedf7a",
        .name         = "Space Treat (30-12-2002) (Fabrizio Zavagli) [a2]",
    },{
        .md5          = "e77ec259e1387bc308b0534647a89198",
        .manufacturer = "Parker Brothers, David Lamkins, Laura Nikolich",
        .model        = "931503",
        .name         = "Spider-Man (1982) (Parker Bros) (PAL)",
    },{
        .md5          = "e77f332b71f13884c84771e7a121182d",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Hey! Stop! (Jone Yuan)",
        .note         = "AKA Keystone Kapers",
    },{
        .md5          = "e784a9d26707cfcd170a4c1c60422a72",
        .manufacturer = "Quelle",
        .model        = "147.443 6",
        .name         = "Gefecht im All (1983) (Quelle) (PAL)",
        .note         = "AKA Space Jockey",
    },{
        .md5          = "e7864caaf9ec49ed67b1904ce8602690",
        .name         = "Donkey Kong 2K3 Pic (PD)",
    },{
        .md5          = "e7a758bb0b43d0f7004e92b9abf4bc83",
        .name         = "Troll's Adventure (Hack)",
        .note         = "Hack of Adventure",
    },{
        .md5          = "e7dd8c2e6c100044002c1086d02b366e",
        .manufacturer = "Activision, Steve Cartwright - Ariola",
        .model        = "EAX-013, PAX-013, 711 013-720",
        .name         = "Barnstorming (1982) (Activision) (PAL)",
        .note         = "AKA Die tollkeuhnen Flieger",
    },{
        .md5          = "e7f005ddb6902c648de098511f6ae2e5",
        .manufacturer = "Spectravideo - Universum",
        .model        = "SV-010",
        .name         = "CompuMate (1983) (Spectravideo) (PAL)",
        .type         = "CM",
        .left         = "COMPUMATE",
        .right        = "COMPUMATE",
        .phosphor     = 1,
    },{
        .md5          = "e800e4aec7c6c54c9cf3db0d1d030058",
        .name         = "Qb (2.06) (Retroactive) (Stella)",
        .phosphor     = 1,
    },{
        .md5          = "e80a4026d29777c3c7993fbfaee8920f",
        .name         = "Frisco (Unknown)",
    },{
        .md5          = "e823b13751e4388f1f2a375d3560a8d7",
        .manufacturer = "Arcadia Corporation, Stephen Harland Landrum",
        .model        = "AR-4105",
        .name         = "Official Frogger (Preview) (1983) (Arcadia) [a]",
    },{
        .md5          = "e879b7093ac4cfad74c88d636ca97d00",
        .name         = "Poker Squares (V0.0f) (2001) (B. Watson)",
    },{
        .md5          = "e88340f5bd2f03e2e9ce5ecfa9c644f5",
        .name         = "Lock 'n' Chase (Unknown) (PAL)",
    },{
        .md5          = "e88b0962a1c951e02f3fa2b8038b9d02",
        .manufacturer = "Fotomania",
        .name         = "Chopper Command (1982) (Fotomania)",
    },{
        .md5          = "e8a3473bf786cf796d1336d2d03a0008",
        .manufacturer = "Parker Brothers, Wilfredo Aguilar, Michael Becker, Neil McKenzie, Bob Smith, Brad Stewart",
        .model        = "PB5540",
        .name         = "Star Wars - The Arcade Game (12-05-1983) (Parker Bros) (Prototype) (4K)",
        .phosphor     = 1,
    },{
        .md5          = "e8aa36e3d49e9bfa654c25dcc19c74e6",
        .manufacturer = "Atari, Joe Decuir, Larry Caplan, Steve Mayer, Larry Wagner",
        .model        = "CX2601, CX2601P",
        .name         = "Combat (1977) (Atari) (PAL)",
    },{
        .md5          = "e8e7b9bdf4bf04930c2bcaa0278ee637",
        .name         = "Boring Taz (Hack)",
        .note         = "Hack of Taz",
    },{
        .md5          = "e8f7679359c4f532f5d5e93af7d8a985",
        .name         = "Hangman Invader Original Words (Hack)",
        .note         = "Hack of Hangman",
    },{
        .md5          = "e9034b41741dcee64ab6605aba9de455",
        .manufacturer = "Digivision",
        .name         = "Phanton Tank (Digivision)",
        .note         = "AKA Phantom Tank",
    },{
        .md5          = "e908611d99890733be31733a979c62d8",
        .manufacturer = "Atari, Dan Hitchens, Mimi Nyden",
        .model        = "CX2697",
        .name         = "Mario Bros. (1983) (Atari)",
    },{
        .md5          = "e91d2ecf8803ae52b55bbf105af04d4b",
        .manufacturer = "Atari, Howard Scott Warshaw",
        .model        = "CX2655, CX2655P",
        .name         = "Yars' Revenge (1982) (Atari) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "e923001015bedd7901569f035d9c592c",
        .name         = "Adventure II (Hack)",
        .note         = "Hack of Adventure",
    },{
        .md5          = "e927ecf80f3784d745abd8368d78f2f3",
        .name         = "Space Instigators (V1.8) (19-10-2002) (Christopher Tumber) [a1]",
    },{
        .md5          = "e932f44fad2a66b6d5faec9addec208e",
        .name         = "Atari Logo Demo 1 (PD)",
    },{
        .md5          = "e94632b0d863dd76459d689a9865bb33",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Combat (Jone Yuan) (4K)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "e957eb4612d6bd5940d3492dfa749668",
        .name         = "Tunnel Demo (27-03-2003) (Christopher Tumber)",
    },{
        .md5          = "e959b5a2c882ccaacb43c32790957c2d",
        .name         = "Phantom II & Pirate (NTSC)",
    },{
        .md5          = "e97eafd0635651d3999cece953c06bd5",
        .name         = "M.A.S.H (Unknown) (PAL) [a]",
    },{
        .md5          = "e9be3e8e4a7e73dd63ed4235a3a1a25f",
        .name         = "MMetall (Hack)",
        .note         = "Hack of Miniature Golf",
    },{
        .md5          = "e9c5d04643855949a23ff29349af74ea",
        .name         = "SCSIcide (Score Hack 2) (24-02-2001) (Joe Grand) (PD)",
    },{
        .md5          = "e9c71f8cdba6037521c9a3c70819d171",
        .name         = "Bank Heist (Unknown) (PAL)",
    },{
        .md5          = "e9cb18770a41a16de63b124c1e8bd493",
        .manufacturer = "Parker Brothers - Roklan, Joe Gaucher",
        .model        = "931519",
        .name         = "Popeye (1983) (Parker Bros) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "e9db2f91efe6ff7ea3546e2c2578fb09",
        .manufacturer = "Omegamatrix",
        .name         = "Millipede (Atari Mouse) v6.5 (Omegamatrix)",
        .note         = "Uses Atari Mouse Controller",
        .format       = "PAL60",
    },{
        .md5          = "e9e646f730b8400cd5da08c849ef3e3b",
        .manufacturer = "Tron",
        .name         = "Enduro (Tron)",
    },{
        .md5          = "e9e6ad30549a6e2cd89fe93b7691d447",
        .manufacturer = "Atari - Bobco, Robert C. Polaro",
        .model        = "CX26140, CX26140P",
        .name         = "Desert Falcon (05-27-1987) (Atari) (Prototype) (PAL)",
        .note         = "AKA Nile Flyer, Sphinx",
    },{
        .md5          = "e9f25c7af4f27c9e1b5b8f6fe6141e8c",
        .manufacturer = "Champ Games",
        .model        = "CG-03-N",
        .name         = "Scramble (NTSC)",
        .note         = "Compatible with Genesis controller",
        .left         = "JOYSTICK",
        .phosphor     = 1,
    },{
        .md5          = "ea38fcfc06ad87a0aed1a3d1588744e4",
        .manufacturer = "Atari, Lou Harp",
        .model        = "CX26122",
        .name         = "Sinistar (01-XX-1984) (Atari) (Prototype)",
    },{
        .md5          = "ea6d40db5498d6386571a76df448aa4c",
        .name         = "Vertical Playfield Demo 2 (PD)",
    },{
        .md5          = "ea7e25ade3fe68f5b786ee0aa82b1fe5",
        .name         = "Galatic (Unknown) (PAL)",
        .note         = "AKA Challenge of.... Nexar, The",
    },{
        .md5          = "ea832e2cb6aae6f525f07452c381fa48",
        .name         = "Polar to Cartesian and VV (2001) (Roger Williams)",
    },{
        .md5          = "ea86176b27ab0da8cce8f0179884bfaa",
        .name         = "Demo Image Series #10 - It's Art (28-02-2003) (Andrew Davie)",
    },{
        .md5          = "eaacfcdc1d4ee1258429b7ae7f084125",
        .manufacturer = "Telegames",
        .model        = "6057 A227",
        .name         = "Quest for Quintana Roo (1989) (Telegames)",
        .note         = "Genesis controller (B is action button, C chooses tool or weapon)",
    },{
        .md5          = "ead60451c28635b55ca8fea198444e16",
        .manufacturer = "Sancho - Tang's Electronic Co.",
        .model        = "TEC004",
        .name         = "Nightmare (1983) (Sancho) (PAL)",
    },{
        .md5          = "eada0dd61ce13f8317de774dc1e68604",
        .name         = "2600 Digital Clock (Demo 1) (PD)",
    },{
        .md5          = "eae0c06ee61c63b81cd016096fc901b0",
        .manufacturer = "Joe Grand",
        .name         = "SCSIcide (v1.0) (2001) (Joe Grand)",
    },{
        .md5          = "eae6a5510055341d3abeb45667bb3e9b",
        .manufacturer = "HES",
        .name         = "Wall Defender (HES) (PAL)",
        .note         = "AKA Wall Break (Planet Patrol if right difficulty = 'A')",
    },{
        .md5          = "eaf744185d5e8def899950ba7c6e7bb5",
        .manufacturer = "Atari",
        .model        = "CX26172",
        .name         = "Xenophobe (1991) (Atari)",
    },{
        .md5          = "eafe8b40313a65792e88ff9f2fe2655c",
        .manufacturer = "Eric Ball",
        .model        = "ELB004",
        .name         = "Skeleton+ (NTSC)",
        .note         = "Stereo sound",
    },{
        .md5          = "eb3d680699f8762f71f38e28e321234d",
        .name         = "Fu Kung! (V0.01) (08-01-2003) (Andrew Davie)",
    },{
        .md5          = "eb4252faff7a4f2ba5284a98b8f78d1a",
        .name         = "John K Harvey's Equalizer (NTSC) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "eb46e99ec15858f8cd8c91cef384ce09",
        .manufacturer = "Goliath - Hot Shot",
        .model        = "83-113",
        .name         = "Ground Zero (1983) (Goliath) (PAL)",
        .note         = "AKA River Raid",
    },{
        .md5          = "eb503cc64c3560cd78b7051188b7ba56",
        .name         = "Mega Force (Unknown)",
    },{
        .md5          = "eb634650c3912132092b7aee540bbce3",
        .manufacturer = "Atari, Eric Manghise, Mimi Nyden, Joseph Tung",
        .model        = "CX2640",
        .name         = "RealSports Baseball (1982) (Atari)",
        .phosphor     = 1,
    },{
        .md5          = "eb6d6e22a16f30687ade526d7a6f05c5",
        .manufacturer = "Atari",
        .model        = "CX26150P",
        .name         = "Q-bert (1987) (Atari) (PAL)",
    },{
        .md5          = "eb71743c6c7ccce5b108fad70a326ad9",
        .name         = "Euchre (25-11-2001) (Erik Eid) (PD)",
    },{
        .md5          = "eb7934360658a29c50aeaff20bfda23b",
        .manufacturer = "Activision, John Van Ryzin",
        .model        = "EAZ-036-04",
        .name         = "H.E.R.O. (1984) (Activision) (SECAM)",
    },{
        .md5          = "eb92193f06b645df0b2a15d077ce435f",
        .manufacturer = "Starpath Corporation, Steve Hales, Stephen H. Landrum",
        .model        = "4 AR-4102",
        .name         = "Suicide Mission (1982) (Starpath) (PAL)",
        .note         = "AKA Meteoroids",
        .phosphor     = 1,
    },{
        .md5          = "eb9712e423b57f0b07ccd315bb9abf61",
        .manufacturer = "Retroactive",
        .name         = "Qb (V2.04) (PAL) (2001) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "eb9f8b84c193d9d93a58fca112aa39ed",
        .name         = "Register Twiddler Demo (PD)",
    },{
        .md5          = "ebcb084a91d41865b2c1915779001ca7",
        .manufacturer = "JVP",
        .name         = "Bob Is Going Home (JVP)",
        .note         = "AKA Bobby Is Going Home",
    },{
        .md5          = "ebcbc8a181a738e13df6216e5c329230",
        .manufacturer = "Activision, Steve Cartwright",
        .model        = "AX-022",
        .name         = "Seaquest (1983) (Activision) (16K)",
    },{
        .md5          = "ebd2488dcace40474c1a78fa53ebfadf",
        .manufacturer = "Skill Screen Games, Herman Quast",
        .model        = "SSG001",
        .name         = "Extra Terrestrials (1984) (SSG)",
        .note         = "The only Canadian-designed and manufactured Atari 2600 game from the 1980's",
    },{
        .md5          = "ebdc5716b85c4ff44fa357cb697d6cef",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Amiga Mouse Hack v1.4 (NTSC) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "ebf2dff78a08733251bf3838f02f7938",
        .manufacturer = "Commavid, Ben Burch",
        .model        = "CM-010",
        .name         = "Rush Hour (1983) (Commavid) (Prototype) [a2]",
    },{
        .md5          = "ebf9038e927e6a0db3e0d170c59911e6",
        .name         = "Pac-2600 (PD)",
    },{
        .md5          = "ec3beb6d8b5689e867bafb5d5f507491",
        .manufacturer = "U.S. Games Corporation - Vidtec - JWDA, Todd Marshall, Henry Will IV",
        .model        = "VC1003",
        .name         = "Word Zapper (1982) (U.S. Games)",
        .note         = "AKA Word Grabber",
    },{
        .md5          = "ec407a206b718a0a9f69b03e920a0185",
        .manufacturer = "Quelle",
        .model        = "876.482 1",
        .name         = "Landung in der Normandie (1983) (Quelle) (PAL)",
        .note         = "AKA Commando Raid",
    },{
        .md5          = "ec44dcf2ddb4319962fc43b725a902e8",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Robot City RC8 (NTSC)",
        .phosphor     = 1,
    },{
        .md5          = "ec5c861b487a5075876ab01155e74c6c",
        .manufacturer = "Apollo - Games by Apollo, Ed Salvo, Byron Parks",
        .model        = "AP-2001",
        .name         = "Spacechase (1982) (Apollo)",
        .note         = "AKA Space Attack",
    },{
        .md5          = "ecd78ba4a9441866e7be2abd6aaef662",
        .name         = "Gas Hog (Unknown)",
    },{
        .md5          = "ece463abde92e8b89bcd867ec71751b8",
        .manufacturer = "Puzzy - Bit Corporation",
        .model        = "PG205",
        .name         = "Dancing Plate (1982) (Puzzy) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "ece908d77ab944f7bac84322b9973549",
        .name         = "Tom Boy (Unknown) ",
        .note         = "AKA Pitfall!",
    },{
        .md5          = "ecf51385384b468834611d44a8429c03",
        .manufacturer = "20th Century Fox Video Games, Douglas 'Dallas North' Neubauer",
        .model        = "11105",
        .name         = "Mega Force (1982) (20th Century Fox) (PAL)",
    },{
        .md5          = "ecfa04523dde82fe42cdc7315a8f61b6",
        .manufacturer = "Activision, David Crane - Ariola",
        .model        = "EAG-004, PAG-004 - 711 004-715",
        .name         = "Fishing Derby (1980) (Activision) (PAL) (4K)",
        .note         = "AKA Schneller als der Hai",
    },{
        .md5          = "ed014beeeb77dbb2bbcf9b5f6850b2f4",
        .name         = "Green Bar Text Demo (PD)",
    },{
        .md5          = "ed0451010d022b96a464febcba70b9c4",
        .manufacturer = "PlayAround - J.H.M.",
        .model        = "203",
        .name         = "Knight on the Town (1982) (PlayAround) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "ed0ab909cf7b30aff6fc28c3a4660b8e",
        .manufacturer = "Panda",
        .model        = "105",
        .name         = "Stunt Man (1983) (Panda)",
        .note         = "AKA Nightmare",
    },{
        .md5          = "ed1306436ce237afc5a7ed3f77134202",
        .manufacturer = "HES",
        .model        = "771-341",
        .name         = "2 Pak Special - Dolphin, Pigs n' Wolf (1990) (HES) (PAL)",
    },{
        .md5          = "ed1492d4cafd7ebf064f0c933249f5b0",
        .manufacturer = "CCE",
        .name         = "Video Cube (CCE)",
        .note         = "AKA Atari Video Cube",
    },{
        .md5          = "ed1a784875538c7871d035b7a98c2433",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Save Our Ship (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "ed2218b3075d15eaa34e3356025ccca3",
        .manufacturer = "Atari, Richard Maurer",
        .model        = "CX2635, CX2635P",
        .name         = "Maze Craze (1980) (Atari) (PAL)",
        .note         = "AKA A Game of Cops 'n Robbers",
    },{
        .md5          = "ed5ccfc93ad4561075436ee42a15438a",
        .manufacturer = "Atari, Tom Reuterdahl",
        .model        = "CX2626, CX2626P",
        .name         = "Miniature Golf (1979) (Atari) (PAL)",
    },{
        .md5          = "ed637054c93e82e436618bcc687e8777",
        .name         = "2 in 1 (Motocross, Pole Position)",
        .type         = "2IN1",
    },{
        .md5          = "ed8f319e82d355832195eb7715644795",
        .manufacturer = "Activision, Larry Kaplan, David Crane",
        .model        = "AG-010, AG-010-04",
        .name         = "Kaboom! (1981) (Activision) (8K)",
        .note         = "Uses the Paddle Controllers (left only)",
    },{
        .md5          = "eddef10fdc0029301064115ae0cd41d4",
        .manufacturer = "CCE",
        .name         = "Freeway (CCE)",
    },{
        .md5          = "ede4ab11ca346bd023b2c21d941e0c50",
        .manufacturer = "Activision, David Crane",
        .model        = "EAZ-030",
        .name         = "Decathlon (1983) (Activision) (SECAM)",
    },{
        .md5          = "ede7e8bf865b0afb4744f86d13624f9a",
        .name         = "Demo Image Series #2 - Clown (19-02-2003) (Andrew Davie)",
    },{
        .md5          = "edf69b123e06eaf8663cc78d8aeba06e",
        .manufacturer = "SpkSoft 98",
        .name         = "River Raid (SpkSoft 98) [h1]",
    },{
        .md5          = "ee28424af389a7f3672182009472500c",
        .manufacturer = "Atari, Carol Shaw - Ralph Lauren",
        .name         = "Polo (1978) (Atari) (Prototype)",
    },{
        .md5          = "ee456542b93fa8d7e6a8c689b5a0413c",
        .name         = "Chronocolor Donkey Kong Clean (PD)",
    },{
        .md5          = "ee4c186123d31a279ed7a84d3578df23",
        .manufacturer = "Atari, Carol Shaw, Nick 'Sandy Maiwald' Turner",
        .model        = "CX2608",
        .name         = "Super Breakout (1982 - 1981) (Atari) (PAL)",
        .note         = "Uses the Paddle Controllers (left only)",
    },{
        .md5          = "ee659ae50e9df886ac4f8d7ad10d046a",
        .manufacturer = "Exus Corporation",
        .name         = "Video Reflex (1983) (Exus)",
        .note         = "AKA Foot Craz",
    },{
        .md5          = "ee6665683ebdb539e89ba620981cb0f6",
        .manufacturer = "Coleco",
        .model        = "2658",
        .name         = "Berenstain Bears (1983) (Coleco)",
        .note         = "Uses the Kid Vid Voice Module",
    },{
        .md5          = "ee67dc0b01746372d2b983d88f48e24f",
        .name         = "Scroller Demo (02-01-2003) (Christopher Tumber)",
    },{
        .md5          = "ee681f566aad6c07c61bbbfc66d74a27",
        .manufacturer = "Activision",
        .name         = "Unknown Activision Game (10-29-1982) (Activision) (Prototype)",
    },{
        .md5          = "ee6cbedf6c0aac90faa0a8dbc093ffbe",
        .manufacturer = "CCE",
        .name         = "My Golf (CCE) (PAL)",
    },{
        .md5          = "ee8027d554d14c8d0b86f94737d2fdcc",
        .manufacturer = "Canal 3 - Intellivision",
        .name         = "Yars' Revenge (Canal 3)",
        .phosphor     = 1,
    },{
        .md5          = "ee84bdc5dae268e227e407c7b5e6b6b7",
        .name         = "Marilyn Monroe Demo (PD)",
    },{
        .md5          = "ee9caee4eb958284fb10c277b14537f1",
        .manufacturer = "Carrere Video, Garry Kitchen - Teldec",
        .model        = "USC1001",
        .name         = "Space Jockey (1983) (Carrere Video) (PAL) (4K)",
    },{
        .md5          = "eea0da9b987d661264cce69a7c13c3bd",
        .manufacturer = "Coleco",
        .model        = "2454",
        .name         = "Zaxxon (1983) (Coleco)",
    },{
        .md5          = "eeb92f3f46df841487d1504f2896d61a",
        .manufacturer = "Cody Pittman",
        .name         = "Corys Adventure (Cody Pittman) (Hack)",
        .note         = "Hack of Pac-Man",
    },{
        .md5          = "eec61cc4250df70939d48fe02d7122ac",
        .manufacturer = "Activision, Bob Whitehead - Ariola",
        .model        = "EAG-005, PAG-005, EAG-005-04B - 711 005-715",
        .name         = "Skiing (1980) (Activision) (PAL)",
    },{
        .md5          = "eed9eaf1a0b6a2b9bc4c8032cb43e3fb",
        .manufacturer = "Atari - Axlon, Steve DeFrisco",
        .model        = "CX26192",
        .name         = "Klax (1991) (Atari) (PAL)",
    },{
        .md5          = "eee7695ae3eea7818321df0b790b31f3",
        .name         = "Sound Paddle V2 (Dennis Caswell & Jim Nitchals) (PD)",
        .note         = "Uses the Paddle Controllers",
        .swapPorts    = 1,
    },{
        .md5          = "ef263d40a23483ab339cac44d9515a56",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Fatal Run (Thomas Jentzsch)",
        .note         = "NTSC Conversion",
    },{
        .md5          = "ef3a4f64b6494ba770862768caf04b86",
        .manufacturer = "Activision, Bob Whitehead",
        .model        = "AG-034-04",
        .name         = "Private Eye (1984) (Activision)",
    },{
        .md5          = "ef60b06fddb675b0d783afbfa5fc5232",
        .name         = "Many Blue Bars and Text Demo 4 (PD)",
    },{
        .md5          = "ef66af190840871409fe1702d2483554",
        .manufacturer = "Andrew Davie, Paul Slocum, Christopher Tumber",
        .name         = "DiscoTech (12-02-2003) (Andrew Davie)",
    },{
        .md5          = "ef71e9fb0d8d477226d8d42261fbf0a7",
        .manufacturer = "Piero Cavina",
        .name         = "Multi-Sprite Demo V2.0 (Piero Cavina) (PD)",
    },{
        .md5          = "ef76ea05655a0b62cb1018c92b9b4b7d",
        .manufacturer = "Gakken",
        .model        = "010",
        .name         = "Strategy X (1983) (Gakken) (PAL)",
    },{
        .md5          = "efa1098c7d091b940c2543abe372f036",
        .manufacturer = "Scott Stilphen",
        .name         = "E.T. The Extra-Terrestrial (Scott Stilphen) (Hack)",
        .note         = "Hack of E.T. The Extra-Terrestrial",
    },{
        .md5          = "efb47d70b2965ce689e2c5757616b286",
        .name         = "Time Test Demo (Eckhard Stolberg) (PAL) (PD)",
    },{
        .md5          = "efd387430a35a659ff569a9a0ec22209",
        .manufacturer = "Atari - GCC",
        .model        = "CX26118",
        .name         = "Millipede (1984) (Atari) (Prototype) (PAL)",
    },{
        .md5          = "efefc02bbc5258815457f7a5b8d8750a",
        .manufacturer = "CBS Electronics, Richard K. Balaska Jr.",
        .model        = "4L 2520 5000",
        .name         = "Tunnel Runner (1983) (CBS Electronics) [a]",
    },{
        .md5          = "effa3a7ce078c6d83bf43174a7bfdb1f",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Centipede - Atari Mouse Hack v1.4 (NTSC) (Half-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "efffafc17b7cb01b9ca35324aa767364",
        .name         = "Circus Atari (Unknown)",
        .left         = "JOYSTICK",
        .right        = "JOYSTICK",
    },{
        .md5          = "f02ba8b5292bf3017d10553c9b7b2861",
        .manufacturer = "Atari",
        .model        = "CX26172",
        .name         = "Xenophobe (1991) (Atari) (PAL)",
    },{
        .md5          = "f032b2f2d8323404a6b4541f92dd1825",
        .name         = "Many Blue Bars and Text Demo 3 (PD)",
    },{
        .md5          = "f047df70d3d08e331122cd2de61d6af8",
        .manufacturer = "Dave Neuman",
        .name         = "Space Battle (NTSC)",
    },{
        .md5          = "f04ee80011d95798006378643650aaa7",
        .manufacturer = "Atari, Bill Aspromonte, Dave Joly, John Russell, Michael Sierchio, Robert Zdybel",
        .model        = "CX26114",
        .name         = "Pigs in Space (1983) (Atari) (Prototype)",
        .note         = "Starring Miss Piggy",
    },{
        .md5          = "f0510abbfbe24ead552e92e3841f63f3",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Atari Mouse Hack v1.3 (NTSC) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "f0536303f49006806bac3aec15738336",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4200",
        .name         = "Escape from the Mindmaster (4 of 4) (1982) (Arcadia)",
    },{
        .md5          = "f0541d2f7cda5ec7bab6d62b6128b823",
        .manufacturer = "Atari, Paul Donaldson",
        .name         = "Bionic Breakthrough (1984) (Atari) (Prototype)",
        .note         = "Uses MindLink Controller",
        .left         = "MINDLINK",
        .right        = "MINDLINK",
    },{
        .md5          = "f060826626aac9e0d8cda0282f4b7fc3",
        .manufacturer = "Atari, David Crane - Sears",
        .model        = "CX2605 - 6-99822, 49-75109",
        .name         = "Outlaw (1978) (Atari) (4K)",
    },{
        .md5          = "f0631c6675033428238408885d7e4fde",
        .manufacturer = "Paul Slocum",
        .name         = "Test Cart (2002) (Paul Slocum)",
        .phosphor     = 1,
    },{
        .md5          = "f066bea7ab0a37b83c83c924a87c5b67",
        .name         = "Air Raiders (2003) (Hack) (Thomas Jentzsch)",
        .note         = "Unlimited ammo hack",
    },{
        .md5          = "f0a6e99f5875891246c3dbecbf2d2cea",
        .manufacturer = "Atari, James Andreasen - Sears",
        .model        = "CX2654 - 49-75141",
        .name         = "Haunted House (1982) (Atari)",
    },{
        .md5          = "f0b7db930ca0e548c41a97160b9f6275",
        .manufacturer = "Atari, Larry Wagner, Bob Whitehead - Sears",
        .model        = "CX2645 - 49-75181",
        .name         = "Video Chess (1979) (Atari)",
        .note         = "AKA Computer Chess",
    },{
        .md5          = "f0cacae1d1b79ee92f0dc035f42e0560",
        .name         = "Boring Donkey Kong (Hack)",
        .note         = "Hack of Donkey Kong",
    },{
        .md5          = "f0d393dbf4164a688b2346770c9bbd12",
        .name         = "Racquetball (Unknown)",
        .phosphor     = 1,
    },{
        .md5          = "f0daaa966199ef2b49403e9a29d12c50",
        .name         = "Mr. Postman (Unknown)",
    },{
        .md5          = "f0de4f49e95d529569e8788d5a7b4d30",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Reactor - Atari Mouse Hack v1.3 (PAL60) (Full-Speed) (Thomas Jentzsch)",
        .note         = "Uses Atari Mouse Controller",
    },{
        .md5          = "f0e0addc07971561ab80d9abe1b8d333",
        .manufacturer = "Imagic, Rob Fulop",
        .model        = "720000-200, 720101-1B, 720101-1C, IA3200, IA3200C, IX-006-04",
        .name         = "Demon Attack (1982) (Imagic)",
        .note         = "AKA Death from Above",
    },{
        .md5          = "f0ef9a1e5d4027a157636d7f19952bb5",
        .manufacturer = "Atari - Axlon, Tod Frye - Heuristica, Agustin Ortiz Valdiviezo",
        .model        = "CX26169",
        .name         = "Shooting Arcade (03-07-1989) (Atari) (Prototype) [screen 6]",
        .note         = "Uses the Light Gun Controller (left only)",
    },{
        .md5          = "f10e3f45fb01416c87e5835ab270b53a",
        .manufacturer = "Suntek",
        .model        = "SS-024",
        .name         = "Ski Run (1983) (Suntek) (PAL)",
    },{
        .md5          = "f1127ade54037236e75a133b1dfc389d",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4200",
        .name         = "Escape from the Mindmaster (Preview) (1982) (Arcadia)",
    },{
        .md5          = "f11cfab087fcbd930ab8b0becc5b2e5a",
        .manufacturer = "Canal 3 - Intellivision",
        .name         = "River Raid (Canal 3)",
    },{
        .md5          = "f12afbffa080dd3b2801dd14d4837cf6",
        .manufacturer = "Atari, Michael Kosaka, Peter C. Niday, Robert Vieira",
        .model        = "CX26110",
        .name         = "Crystal Castles (01-04-1984) (Atari) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "f137211537438b1fce3d811baef25457",
        .name         = "Incoming (02-10-2002) (Ben Larson) (PD)",
    },{
        .md5          = "f1489e27a4539a0c6c8529262f9f7e18",
        .manufacturer = "Champ Games",
        .model        = "CG-01-P",
        .name         = "Lady Bug (PAL60)",
        .phosphor     = 1,
    },{
        .md5          = "f14d5e96ec3380aef57a4b70132c6677",
        .manufacturer = "Goliath - Hot Shot",
        .model        = "83-414",
        .name         = "Pac Kong (1983) (Goliath) (PAL)",
        .note         = "AKA Inca Gold",
    },{
        .md5          = "f1554569321dc933c87981cf5c239c43",
        .manufacturer = "Atari - Glenn Axworthy",
        .model        = "CX26129",
        .name         = "Midnight Magic (1986) (Atari)",
        .note         = "AKA Pinball Wizard",
        .phosphor     = 1,
    },{
        .md5          = "f16c709df0a6c52f47ff52b9d95b7d8d",
        .manufacturer = "Atari, Alan Miller - Sears",
        .model        = "CX2662 - 6-99811",
        .name         = "Hangman (1978) (Atari)",
    },{
        .md5          = "f16ef574d2042ed8fe877d6541f4dba4",
        .manufacturer = "Spectravision - Spectravideo",
        .model        = "SA-201",
        .name         = "Gangster Alley (1982) (Spectravision)",
    },{
        .md5          = "f1929bb9b5db22d98dd992aa3fe72920",
        .name         = "Cube Conquest (Improved Interlace) (Billy Eno) (PD)",
        .phosphor     = 1,
    },{
        .md5          = "f19aba18f86e415812480ad2be221425",
        .manufacturer = "Chris Larkin",
        .name         = "Solaris Trainer (2002) (Chris Larkin) (Hack)",
        .note         = "Hack of Solaris",
    },{
        .md5          = "f1a0a23e6464d954e3a9579c4ccd01c8",
        .manufacturer = "20th Century Fox, Douglas 'Dallas North' Neubauer",
        .model        = "11006",
        .name         = "Alien (1982) (20th Century Fox)",
        .phosphor     = 1,
    },{
        .md5          = "f1ae6305fa33a948e36deb0ef12af852",
        .manufacturer = "Andreas Dietrich",
        .name         = "Donkey Kong VCS (2017) (1.0)",
        .phosphor     = 1,
    },{
        .md5          = "f1b2ea568b3e156e3f2849dac83591f6",
        .name         = "Multi Demo 2 (Bob Colbert) (PD)",
    },{
        .md5          = "f1b7edff81ceef5af7ae1fa76c8590fc",
        .manufacturer = "Atari, Richard Maurer",
        .model        = "CX2632, CX2632P",
        .name         = "Space Invaders (1980) (Atari) (PAL)",
    },{
        .md5          = "f1beca5a198cf08190487e5c27b8e540",
        .name         = "Fu Kung! (V0.16) (2003) (Andrew Davie)",
    },{
        .md5          = "f1e375d921858467166e53bcec05803f",
        .manufacturer = "Jeffry Johnston",
        .name         = "Radial Pong - Version 3 (Jeffry Johnston) (PD)",
    },{
        .md5          = "f1eeeccc4bba6999345a2575ae96508e",
        .manufacturer = "Video Gems",
        .model        = "VG-03",
        .name         = "Steeplechase (1983) (Video Gems) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "f1fe06ebe2900eac4cdd17799389a102",
        .manufacturer = "Atari, Jim Huether",
        .model        = "CX26163P",
        .name         = "Sky Diver (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "f20675c8b98518367b9f5b8ee6f7c8ea",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Stampede (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "f20bd756f3990e06c492f53cd0168e68",
        .name         = "Skeleton+ (03-05-2003) (Eric Ball) (NTSC)",
    },{
        .md5          = "f21813aa050437f0dbc8479864acec6d",
        .name         = "Sneak 'n Peek (Unknown) (PAL)",
    },{
        .md5          = "f23d19b73dac50cc6149316912b8ee53",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Challenge of... Nexar, The - Amiga Mouse Hack v1.1 (PAL) (Thomas Jentzsch)",
        .note         = "Uses Amiga Mouse Controller",
    },{
        .md5          = "f240ba9f8092d2e8a4c7d82c554bf509",
        .manufacturer = "Quelle",
        .model        = "463.860 7",
        .name         = "Strahlen der Teufelsvoegel (1983) (Quelle) (PAL)",
        .note         = "AKA Atlantis",
    },{
        .md5          = "f280976d69d6e27a48506bd6bad11dcd",
        .manufacturer = "Atari, Larry Kaplan",
        .model        = "CX2664, CX2664P",
        .name         = "Brain Games (1978) (Atari) (PAL)",
        .note         = "Uses Keyboard Controllers",
        .left         = "KEYBOARD",
        .right        = "KEYBOARD",
    },{
        .md5          = "f283cc294ece520c2badf9da20cfc025",
        .manufacturer = "Atari - CCW, Christopher H. Omarzu",
        .model        = "CX26104",
        .name         = "Big Bird's Egg Catch (1983) (Atari) (PAL)",
        .note         = "Uses Kids/Keyboard Controllers",
        .left         = "KEYBOARD",
        .right        = "KEYBOARD",
    },{
        .md5          = "f28c07767b3e90a2689ade5b5e305874",
        .manufacturer = "Canal 3 - Intellivision",
        .model        = "C 3014",
        .name         = "Keystone Kapers (Canal 3)",
    },{
        .md5          = "f2d40c70cf3e1d03bc112796315888d9",
        .manufacturer = "Atari - CCW, Michael Callahan, Preston Stuart",
        .model        = "CX26103",
        .name         = "Alpha Beam with Ernie (1983) (Atari) (PAL)",
        .note         = "Uses Keyboard Controllers",
    },{
        .md5          = "f2d4d6187903cac2d5ea8ed90dad120d",
        .manufacturer = "Digimax",
        .name         = "River Raid II (Digimax)",
        .note         = "AKA River Raid",
    },{
        .md5          = "f2e4fb2d3600c0f76d05864e658cc57b",
        .name         = "Marble Craze (Kernel) (17-02-2002) (Paul Slocum)",
    },{
        .md5          = "f2f2cb35fdef063c966c1f5481050ea2",
        .name         = "Ram It (Unknown) (PAL)",
    },{
        .md5          = "f2f59629d7341c97644405daeac08845",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Bobby Is Going Home (Jone Yuan)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "f303630a2d7316787aecd67fff6b2e33",
        .manufacturer = "AtariAge - Fred Quimby",
        .name         = "Gingerbread Man (Fred Quimby)",
    },{
        .md5          = "f3213a8a702b0646d2eaf9ee0722b51c",
        .manufacturer = "Atari, Carol Shaw - Sears",
        .model        = "CX2618 - 49-75123",
        .name         = "3-D Tic-Tac-Toe (1980) (Atari) (4K)",
    },{
        .md5          = "f33f1d0f7819c74148dacb48cbf1c597",
        .manufacturer = "Retroactive",
        .name         = "Qb (2.00) (Retroactive) (Stella)",
        .phosphor     = 1,
    },{
        .md5          = "f344ac1279152157d63e64aa39479599",
        .manufacturer = "Tigervision",
        .model        = "7-012",
        .name         = "Espial (1984) (Tigervision)",
    },{
        .md5          = "f34dd3b8156aaf113cb621b2e51d90b8",
        .manufacturer = "Joe Grand",
        .name         = "SCSIcide Pre-release 5 (Joe Grand)",
    },{
        .md5          = "f34f08e5eb96e500e851a80be3277a56",
        .manufacturer = "Atari, Brad Stewart - Sears",
        .model        = "CX2622 - 6-99813, 49-75107",
        .name         = "Breakout (1978) (Atari)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "f367e58667a30e7482175809e3cec4d4",
        .manufacturer = "ZiMAG - Emag - Vidco",
        .model        = "708-111 - GN-040",
        .name         = "Cosmic Corridor (1983) (ZiMAG)",
        .note         = "AKA Space Tunnel",
    },{
        .md5          = "f38358cd8f5ecfedffd5aca1aa939f18",
        .manufacturer = "Universal Gamex Corporation, Alan Roberts",
        .model        = "1005",
        .name         = "X-Man (1983) (Universal) [a]",
    },{
        .md5          = "f39e4bc99845edd8621b0f3c7b8c4fd9",
        .manufacturer = "AtariAge",
        .name         = "Toyshop Trouble (AtariAge)",
        .note         = "F8 Emulator Release",
    },{
        .md5          = "f3c431930e035a457fe370ed4d230659",
        .name         = "Crackpots (Unknown) (PAL)",
    },{
        .md5          = "f3cd0f886201d1376f3abab2df53b1b9",
        .manufacturer = "Commavid, Ben Burch",
        .model        = "CM-010",
        .name         = "Rush Hour (1983) (Commavid) (Prototype)",
    },{
        .md5          = "f3dfae774f3bd005a026e29894db40d3",
        .manufacturer = "Otto Versand",
        .model        = "649635",
        .name         = "See Saw (Double-Game Package) (1983) (Otto Versand) (PAL)",
        .note         = "AKA Circus Atari",
        .left         = "JOYSTICK",
        .right        = "JOYSTICK",
    },{
        .md5          = "f3f5f72bfdd67f3d0e45d097e11b8091",
        .manufacturer = "Sears Tele-Games, Marilyn Churchill, Matthew L. Hubbard",
        .model        = "CX2647 - 49-75142",
        .name         = "Submarine Commander (1982) (Sears)",
        .note         = "AKA Seawolf 3",
    },{
        .md5          = "f3f92aad3a335f0a1ead24a0214ff446",
        .name         = "Spectrum Color Demo (PD)",
    },{
        .md5          = "f40e437a9ebf0bdfe26204152f74f868",
        .manufacturer = "Bit Corporation",
        .model        = "R320",
        .name         = "Jawbreaker (32 in 1) (BitCorp) (Hack)",
    },{
        .md5          = "f4204fc92d17ed4cb567c40361ad58f1",
        .manufacturer = "Inky",
        .name         = "Beanie Baby Bash (Inky) (Hack)",
        .note         = "Hack of Beany Bopper",
    },{
        .md5          = "f4469178cd8998cb437fa110a228eaca",
        .manufacturer = "Digitel",
        .name         = "Frostbite (1983) (Digitel)",
    },{
        .md5          = "f45644ff82b533a781a1ee50f2e95f3c",
        .name         = "Overhead Adventure Demo 6 (PD)",
    },{
        .md5          = "f457674cef449cfd85f21db2b4f631a7",
        .manufacturer = "U.S. Games Corporation - JWDA, Todd Marshall, Wes Trager, Henry Will IV",
        .model        = "VC1004",
        .name         = "Commando Raid (1982) (U.S. Games)",
    },{
        .md5          = "f473f99e47d4026a7a571184922ebf04",
        .manufacturer = "Philip R. Frey",
        .name         = "Donkey Claus (Philip R. Frey) (Hack)",
        .note         = "Hack of Donkey Kong",
    },{
        .md5          = "f48022230bb774a7f22184b48a3385af",
        .manufacturer = "Atari, Rob Fulop - Sears",
        .model        = "CX2633 - 49-75119",
        .name         = "Night Driver (1980) (Atari) (4K)",
        .note         = "Uses the Paddle Controllers (left only)",
        .phosphor     = 1,
    },{
        .md5          = "f48735115ec302ba8bb2d2f3a442e814",
        .name         = "Dancing Plate (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "f49a34f1fdd7dc147cbf96ce2ce71b76",
        .name         = "Qb (Special Edition) (PAL) (Retroactive)",
        .phosphor     = 1,
    },{
        .md5          = "f4a09f906cc37be31224433f576d77d3",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Challenge of... Nexar, The - Atari Trak-Ball Hack v1.2 (PAL) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controller",
    },{
        .md5          = "f4ab6bd5f80d8988141edde4c84b23b5",
        .manufacturer = "Atari, Alan Miller",
        .model        = "CX2624, CX2624P",
        .name         = "Basketball (1978) (Atari) (PAL) (4K)",
    },{
        .md5          = "f4b8a47a95b61895e671c3ec86ffd461",
        .manufacturer = "Parker Brothers, Wilfredo Aguilar, Michael Becker, Neil McKenzie, Bob Smith, Brad Stewart",
        .model        = "PB5540",
        .name         = "Star Wars - The Arcade Game (01-03-1984) (Parker Bros) (Prototype) (4K)",
        .phosphor     = 1,
    },{
        .md5          = "f4c2e50b01dff99bddbe037b3489511c",
        .name         = "Hypnotic (V0.04) (2001) (Inkling) (PD)",
    },{
        .md5          = "f4c6621f1a0b4d27081123c08d7d1497",
        .manufacturer = "CCE",
        .model        = "C-838",
        .name         = "Immies & Aggies (1983) (CCE)",
    },{
        .md5          = "f4cf6881b65c424095dc25dc987f151f",
        .name         = "128 in 1 Game Select ROM (Unknown)",
    },{
        .md5          = "f4dabd5bcc603e8464a478208037d423",
        .manufacturer = "Coleco - Individeo, Ed Temple",
        .name         = "Cabbage Patch Kids (08-21-1984) (Coleco) (Prototype)",
        .note         = "Adventures in the Park",
    },{
        .md5          = "f526d0c519f5001adb1fc7948bfbb3ce",
        .manufacturer = "Mythicon, Bill Bryner, Bruce de Graaf",
        .model        = "MA1003",
        .name         = "Star Fox (1983) (Mythicon)",
    },{
        .md5          = "f52f40299fd238c6ffd9e6107050dc76",
        .manufacturer = "Activision, Bob Whitehead - Ariola",
        .model        = "EAG-011, PAG-011 - 711 011-715",
        .name         = "Stampede (1981) (Activision) (PAL) (4K)",
    },{
        .md5          = "f539e32bf6ce39c8ca47cb0cdd2c5cb8",
        .manufacturer = "Control Video Corporation",
        .name         = "GameLine Master Module ROM (1983) (Control Video)",
    },{
        .md5          = "f542b5d0193a3959b54f3c4c803ba242",
        .manufacturer = "Atari, Tom Rudadahl - Sears",
        .model        = "CX2634 - 49-75121",
        .name         = "Golf (1980) (Atari) (4K)",
    },{
        .md5          = "f5445b52999e229e3789c39e7ee99947",
        .manufacturer = "Atari, Jim Huether",
        .model        = "CX26163P",
        .name         = "Flag Capture (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "f5a2f6efa33a3e5541bc680e9dc31d5b",
        .manufacturer = "Suntek",
        .model        = "SS-022",
        .name         = "Motocross (1983) (Suntek) (PAL)",
    },{
        .md5          = "f5a3e051730d45fea518f2e8b926565b",
        .manufacturer = "Robby",
        .name         = "Keystone Kapers (Robby)",
    },{
        .md5          = "f5aa6bd10f662199c42e43863a30106c",
        .name         = "Music Kit (V1.0) - Song Player (Paul Slocum)",
        .phosphor     = 1,
    },{
        .md5          = "f5d103a9ae36d1d4ee7eef657b75d2b3",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum",
        .model        = "9 AR-4105",
        .name         = "Official Frogger, The (Preview) (1983) (Starpath)",
    },{
        .md5          = "f610d2bc17283d8064f7389fdf2ce8d4",
        .manufacturer = "Megatronix",
        .name         = "Game Over 2600 (Megatronix)",
        .note         = "256 games",
        .type         = "128IN1",
        .left         = "JOYSTICK",
        .right        = "JOYSTICK",
    },{
        .md5          = "f613aad84d2163d6b197b220bfec1b7e",
        .name         = "X-Doom V.27 (PD)",
    },{
        .md5          = "f661f129644f338b13d9f4510d816c03",
        .manufacturer = "Atari, David Crane",
        .model        = "CX26163P",
        .name         = "Outlaw (32 in 1) (1988) (Atari) (PAL) (4K)",
    },{
        .md5          = "f6676e3fe901eb8515fc7ae310302c3c",
        .manufacturer = "Activision, David Crane",
        .model        = "AG-008",
        .name         = "Laser Blast (1981) (Activision) (8K)",
    },{
        .md5          = "f67181b3a01b9c9159840b15449b87b0",
        .manufacturer = "Atari, Nick 'Sandy Maiwald' Turner",
        .model        = "CX2665",
        .name         = "Frog Pond (08-27-1982) (Atari) (Prototype)",
    },{
        .md5          = "f687ec4b69611a7f78bd69b8a567937a",
        .manufacturer = "Activision, Alan Miller - Ariola",
        .model        = "EAZ-028 - 711 028-725",
        .name         = "Robot Tank (1983) (Activision) (PAL)",
    },{
        .md5          = "f69a39b215852a0c2764d2a923c1e463",
        .name         = "Move a Blue Blob Demo 2 (PD)",
    },{
        .md5          = "f69bb58b815a6bdca548fa4d5e0d5a75",
        .manufacturer = "Atari, Larry Kaplan",
        .model        = "CX26163P",
        .name         = "Bowling (32 in 1) (1988) (Atari) (PAL)",
    },{
        .md5          = "f69d4fcf76942fcd9bdf3fd8fde790fb",
        .manufacturer = "CCE",
        .name         = "Aquaventure (CCE)",
    },{
        .md5          = "f6a282374441012b01714e19699fc62a",
        .manufacturer = "ZiMAG - Emag - Vidco",
        .model        = "710-111 - GN-010",
        .name         = "I Want My Mommy (1983) (ZiMAG)",
        .note         = "AKA Open, Sesame!",
        .phosphor     = 1,
    },{
        .md5          = "f6a9ea814d15b85bffe980c927df606b",
        .name         = "Missile Command (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "f6b5ebb65cbb2981af4d546c470629d7",
        .manufacturer = "Coleco - Individeo, Ed Temple",
        .name         = "Cabbage Patch Kids (09-13-1984) (Coleco) (Prototype) [a]",
        .note         = "Adventures in the Park",
    },{
        .md5          = "f6c13e816e58c8c62f82b2c8b91a2d67",
        .name         = "Scrolling Playfield 2 (Junkosoft) (PD)",
    },{
        .md5          = "f6d512bef1bf253dc935d0e13c3d1462",
        .name         = "Slot Racers (Unknown) (PAL) (4K)",
    },{
        .md5          = "f6daebc0424fa0f8d9aaf26c86df50f4",
        .manufacturer = "Brian Watson",
        .name         = "Color Tweaker (V1.0) (2001) (B. Watson)",
    },{
        .md5          = "f6efa00ae99aaf33e427b674bcfd834d",
        .name         = "2600 Digital Clock (Demo 3) (PD)",
    },{
        .md5          = "f6f1b27efc247a0e8d473ddb4269ff9e",
        .manufacturer = "Rainbow Vision - Suntek",
        .model        = "SS-015",
        .name         = "Catch Time (1983) (Rainbow Vision) (PAL)",
        .note         = "AKA Plaque Attack",
    },{
        .md5          = "f7048fa1f96360123ddae93cb3600ea2",
        .manufacturer = "Fotomania",
        .name         = "Pitfall (Fotomania)",
        .note         = "AKA Pitfall!",
    },{
        .md5          = "f70e3f3bb2d19ec2aaec8f78dc43744f",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Pooyan (Jone Yuan) (Hack)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "f714a223954c28eccf459295517dcae6",
        .name         = "Big - Move This Demo (PD)",
    },{
        .md5          = "f7154add27b95cd90464dbed8cfd7557",
        .manufacturer = "Fabrizio Zavagli",
        .name         = "Space Treat Deluxe (2003) (PAL)",
    },{
        .md5          = "f724d3dd2471ed4cf5f191dbb724b69f",
        .manufacturer = "Atari, Jerome Domurat, Howard Scott Warshaw",
        .model        = "CX2659",
        .name         = "Raiders of the Lost Ark (1982) (Atari)",
        .note         = "Console ports are swapped",
        .swapPorts    = 1,
    },{
        .md5          = "f736864442164b29235e8872013180cd",
        .manufacturer = "Telegames - VSS",
        .model        = "6057 A227",
        .name         = "Quest for Quintana Roo (1988) (Telegames) (PAL)",
    },{
        .md5          = "f73d2d0eff548e8fc66996f27acf2b4b",
        .manufacturer = "CCE",
        .model        = "C-813",
        .name         = "Pitfall (1983) (CCE)",
        .note         = "AKA Pitfall!",
    },{
        .md5          = "f7424985bac41067502b4a05b64cb75a",
        .manufacturer = "Activision, Steve Cartwright",
        .model        = "AX-027",
        .name         = "Plaque Attack (1983) (Activision)",
        .note         = "Genesis controller (B is fire up, C is fire down)",
        .left         = "GENESIS",
    },{
        .md5          = "f74ad642552385c3daa203a2a6fc2291",
        .manufacturer = "Eckhard Stolberg",
        .name         = "Cubis (1997) (Eckhard Stolberg)",
    },{
        .md5          = "f750b5d613796963acecab1690f554ae",
        .manufacturer = "Manuel Polik",
        .name         = "Gunfight 2600 (Manuel Rotschkar)",
    },{
        .md5          = "f75872946e82ad74d48eae5bc28f5f0e",
        .manufacturer = "Sears Tele-Games, Jim Huether",
        .model        = "CX2614 - 49-75126",
        .name         = "Steeplechase (04-15-1980) (Sears) (Prototype)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "f777444fc21a5925e066b68b1d350575",
        .name         = "Marble Craze (Kernel Works) (Paul Slocum)",
    },{
        .md5          = "f77f5fc3893da5d00198e4cd96544aad",
        .manufacturer = "Canal 3 - Intellivision",
        .name         = "Stampede (Canal 3)",
    },{
        .md5          = "f7856e324bc56f45b9c8e6ff062ec033",
        .manufacturer = "Atari, Jerome Domurat, Michael Sierchio",
        .model        = "CX2667",
        .name         = "RealSports Soccer (1983) (Atari) [no opening tune]",
        .phosphor     = 1,
    },{
        .md5          = "f78c125b5da483c41e51522947d6c4ce",
        .name         = "Sound Paddle V1 (Dennis Caswell & Jim Nitchals) (PD)",
        .note         = "Uses the Paddle Controllers",
        .swapPorts    = 1,
    },{
        .md5          = "f7a138eed69665b5cd1bfa796a550b01",
        .manufacturer = "Tigervision - Teldec",
        .model        = "7-012 - 3.60016 VC",
        .name         = "Espial (1984) (Tigervision) (PAL)",
    },{
        .md5          = "f7a651972d78f9ba485b14690452d4be",
        .manufacturer = "Paul Slocum",
        .name         = "Homestar Runner Demo #2 (2004-03-29)",
        .phosphor     = 1,
    },{
        .md5          = "f7af41a87533524d9a478575b0d873d0",
        .manufacturer = "Quelle",
        .model        = "495.663 7",
        .name         = "Spiderman (1983) (Quelle) (PAL)",
        .note         = "AKA Spider-Man",
    },{
        .md5          = "f7d6592dcb773c81c278140ed4d01669",
        .manufacturer = "Activision, David Crane, Dan Kitchen",
        .model        = "EAG-108-04, EAZ-108-04B",
        .name         = "Ghostbusters (1985) (Activision) (PAL)",
    },{
        .md5          = "f7e07080ed8396b68f2e5788a5c245e2",
        .manufacturer = "Video Game Cartridge - Ariola",
        .model        = "TP-617",
        .name         = "Farmyard Fun (Ariola)",
        .note         = "AKA Pumuckl at the Farm House",
    },{
        .md5          = "f7e92eccb2bb0fc307f984b4f29ce6df",
        .manufacturer = "Fotomania",
        .name         = "Crackpots (Fotomania)",
    },{
        .md5          = "f7ec2f2bdbe8fbea048c0d5fa6503b0b",
        .manufacturer = "Akor",
        .name         = "TV Boy (1992) (Akor) (PAL)",
        .note         = "Includes 127 games",
        .left         = "JOYSTICK",
        .right        = "JOYSTICK",
    },{
        .md5          = "f7f50d9c9d28bcc9f7d3075668b7ac89",
        .manufacturer = "Activision, David Crane - Ariola",
        .model        = "EAG-008, PAG-008, EAG-008-04I - 711 008-720",
        .name         = "Laser Blast (1981) (Activision) (PAL) (4K)",
    },{
        .md5          = "f7fac15cf54b55c5597718b6742dbec2",
        .manufacturer = "Spiceware",
        .model        = "SW-01",
        .name         = "Medieval Mayhem (NTSC)",
    },{
        .md5          = "f802fa61011dd9eb6f80b271bac479d0",
        .manufacturer = "Suntek",
        .model        = "SS-023",
        .name         = "Mole Hunter (1983) (Suntek) (PAL)",
        .note         = "AKA Topy",
    },{
        .md5          = "f80cf77164079d774b9b0fae33dffca9",
        .name         = "Fu Kung! (V0.15) (Negative Version) (05-02-2003) (Andrew Davie)",
    },{
        .md5          = "f8240e62d8c0a64a61e19388414e3104",
        .manufacturer = "Activision, Steve Cartwright",
        .model        = "AX-013",
        .name         = "Barnstorming (1982) (Activision)",
    },{
        .md5          = "f825c538481f9a7a46d1e9bc06200aaf",
        .manufacturer = "Atari, Richard Maurer - Sears",
        .model        = "CX2635 - 49-75157",
        .name         = "Maze Craze (1980) (Atari)",
        .note         = "AKA A Game of Cops 'n Robbers",
        .format       = "NTSC",
    },{
        .md5          = "f844f4c6f3baaaf5322657442d6f29eb",
        .manufacturer = "Atari, Ed Bogas, Sam Comstock, Richard Dobbis, Nick 'Sandy Maiwald' Turner",
        .model        = "CX26111",
        .name         = "Snoopy and the Red Baron (1983) (Atari) (PAL)",
    },{
        .md5          = "f847fb8dba6c6d66d13724dbe5d95c4d",
        .manufacturer = "Absolute Entertainment, David Crane",
        .model        = "AG-042-02, AG-042-04",
        .name         = "Skate Boardin' (1987) (Absolute)",
    },{
        .md5          = "f8582bc6ca7046adb8e18164e8cecdbc",
        .name         = "Panda Chase (Unknown) (PAL)",
    },{
        .md5          = "f8648d0c6ad1266434f6c485ff69ec40",
        .manufacturer = "CCE",
        .name         = "Oink! (CCE)",
    },{
        .md5          = "f8811d45a9935cca90c62f924712f8e6",
        .manufacturer = "Jone Yuan Telephonic Enterprise Co",
        .name         = "Chopper Command (Jone Yuan) (Hack)",
        .note         = "2600 Screen Search Console",
    },{
        .md5          = "f8b2a6a4d73ebff10d805a9b59041986",
        .manufacturer = "Activision, Larry Kaplan - Ariola",
        .model        = "EAX-006, PAX-006 - 771 006-720",
        .name         = "Bridge (1980) (Activision) (PAL)",
    },{
        .md5          = "f8bfd99163d2c4ec688357786e6fba28",
        .name         = "Eckhard Stolberg's Scrolling Text Demo 2 (PD)",
    },{
        .md5          = "f8c1c4a41303bd40b0d6c81bfaf8573b",
        .manufacturer = "HES",
        .model        = "773-891",
        .name         = "2 Pak Special - Dungeon Master, Creature Strike (1992) (HES) (PAL)",
    },{
        .md5          = "f8fbe2b07345086fc867bceeaf38dc48",
        .manufacturer = "Atari, Eric Manghise, Mimi Nyden, Joseph Tung",
        .model        = "CX2640",
        .name         = "RealSports Baseball (1982) (Atari) (Prototype) (4K)",
    },{
        .md5          = "f8ff34b53d86f55bd52d7a520af6d1dc",
        .name         = "Big Dig (04-04-2003) (Christopher Tumber)",
    },{
        .md5          = "f90b5da189f24d7e1a2117d8c8abc952",
        .manufacturer = "Atari, David Crane - Sears",
        .model        = "CX2653 - 6-99823, 49-75111",
        .name         = "Slot Machine (1979) (Atari)",
    },{
        .md5          = "f91fb8da3223b79f1c9a07b77ebfa0b2",
        .manufacturer = "Atari, Alan J. Murphy, Nick 'Sandy Maiwald' Turner - Sears",
        .model        = "CX2615 - 49-75140",
        .name         = "Demons to Diamonds (1982) (Atari)",
        .note         = "Uses the Paddle Controllers (left only)",
        .swapPaddles  = 1,
    },{
        .md5          = "f93d7fee92717e161e6763a88a293ffa",
        .manufacturer = "20th Century Fox Video Games - Lazer Micro Systems - Dunhill Electronics, B. Winston Hendrickson, Randall Hyde, Mark V. Rhoads, John Simonds",
        .model        = "11013",
        .name         = "Porky's (1983) (20th Century Fox)",
    },{
        .md5          = "f9420173efcb4b9f2b01c2a7b595cca7",
        .manufacturer = "CCE",
        .name         = "Laser Blast (CCE) (4K)",
    },{
        .md5          = "f954381f9e0f2009d1ac40dedd777b1a",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Robot City (V0.18) (01-09-2002) (Thomas Jentzsch)",
    },{
        .md5          = "f9655ed51462ecfc690c7b97cec649f9",
        .manufacturer = "Andrew Wallace",
        .name         = "Laseresal 2002 (PAL) (PD)",
    },{
        .md5          = "f965cc981cbb0822f955641f8d84e774",
        .manufacturer = "Answer Software Corporation - TY Associates, Kim Ellis",
        .model        = "ASC2001",
        .name         = "Confrontation (1983) (Answer) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "f9660ebed66fee8bdfdf07b4faa22941",
        .manufacturer = "VGS",
        .name         = "Vanguard (VGS)",
    },{
        .md5          = "f9677b2ec8728a703eb710274474613d",
        .manufacturer = "Atari, Ian Shepard",
        .model        = "CX2604, CX2604P",
        .name         = "Space War (1978) (Atari) (PAL)",
    },{
        .md5          = "f979543df0113fb49571dfac8b78b694",
        .manufacturer = "Fotomania",
        .name         = "Enduro (Fotomania)",
    },{
        .md5          = "f97dee1aa2629911f30f225ca31789d4",
        .manufacturer = "Avalon Hill, Jean Baer, Bill 'Rebecca Ann' Heineman, Jim Jacob",
        .model        = "5005002",
        .name         = "Out of Control (1983) (Avalon Hill)",
    },{
        .md5          = "f98d2276d4a25b286135566255aea9d0",
        .manufacturer = "Digitel",
        .name         = "Name This Game (1983) (Digitel)",
    },{
        .md5          = "f98d869f287d2ce4f8fb36e0686929d9",
        .name         = "Skeleton+ (17-04-2003) (Eric Ball) (NTSC)",
    },{
        .md5          = "f991e0670b5f67faa6b6211e9bd81b91",
        .manufacturer = "Nukey Shay, Omegamatrix",
        .name         = "Double Dragon (Genesis) (PAL) V2",
        .note         = "Genesis controller",
    },{
        .md5          = "f992a39b46aa48188fab12ad3809ae4a",
        .name         = "Sky Jinks (Unknown) (PAL) (Hack)",
    },{
        .md5          = "f9967369943209b4788d4e92cefc0795",
        .manufacturer = "Atari",
        .model        = "CX26163P",
        .name         = "Fishing (32 in 1) (1988) (Atari) (PAL) (4K)",
        .note         = "AKA Fishing Derby",
    },{
        .md5          = "f9cef637ea8e905a10e324e582dd39c2",
        .manufacturer = "CCE",
        .name         = "Private Eye (CCE)",
    },{
        .md5          = "f9d51a4e5f8b48f68770c89ffd495ed1",
        .manufacturer = "Atari, Tod Frye, Mimi Nyden",
        .model        = "CX2657",
        .name         = "SwordQuest - FireWorld (1982) (Atari)",
        .note         = "AKA Adventure II, SwordQuest II - FireWorld",
    },{
        .md5          = "f9da42f91a1c5cfa344d2ff440c6f8d4",
        .manufacturer = "ZUT",
        .name         = "Pac Invaders (ZUT)",
    },{
        .md5          = "f9de91d868d6ebfb0076af9063d7195e",
        .name         = "Maze Demo 2 (PD)",
    },{
        .md5          = "f9e99596345a84358bc5d1fbe877134b",
        .manufacturer = "Activision, Larry Kaplan, David Crane - Ariola",
        .model        = "EAG-010, PAG-010 - 711 010-720",
        .name         = "Kaboom! (1981) (Activision) (PAL)",
        .note         = "Uses the Paddle Controllers (left only)",
    },{
        .md5          = "fa0570561aa80896f0ead05c46351389",
        .manufacturer = "Tigervision",
        .model        = "7-008",
        .name         = "Miner 2049er (1983) (Tigervision)",
    },{
        .md5          = "fa1b060fd8e0bca0c2a097dcffce93d3",
        .manufacturer = "Atari - CCW, Christopher H. Omarzu, Preston Stuart, Bruce Williams",
        .model        = "CX26101",
        .name         = "Oscar's Trash Race (1984) (Atari)",
        .note         = "Uses the Keyboard Controllers",
        .left         = "KEYBOARD",
        .right        = "KEYBOARD",
    },{
        .md5          = "fa2be8125c3c60ab83e1c0fe56922fcb",
        .manufacturer = "Camelot - DSD, Michael Doherty, Clyde Hager - Johnson & Johnson",
        .name         = "Tooth Protectors (1983) (Camelot)",
        .phosphor     = 1,
    },{
        .md5          = "fa3de71841c0841db6a741884a6b6b2f",
        .name         = "Warring Worms (17-02-2002) (Billy Eno)",
    },{
        .md5          = "fa4404fabc094e3a31fcd7b559cdd029",
        .manufacturer = "Atari, Alan J. Murphy, Robert C. Polaro",
        .model        = "CX26100",
        .name         = "Bugs Bunny (1983) (Atari) (Prototype)",
    },{
        .md5          = "fa529ec88eca679f6d5fd0ccb2120e46",
        .name         = "20 Sprites at Once Demo 1 (PD)",
    },{
        .md5          = "fa6fe97a10efb9e74c0b5a816e6e1958",
        .manufacturer = "ZiMAG - Emag - Vidco",
        .model        = "707-111 - GN-030",
        .name         = "Tanks But No Tanks (1983) (ZiMAG)",
        .note         = "AKA Phantom Tank",
    },{
        .md5          = "fa7ce62e7fd77e02b3e2198d70742f80",
        .manufacturer = "Atari, Dave Joly, Suki Lee",
        .model        = "CX26108",
        .name         = "Donald Duck's Speedboat (04-18-1983) (Atari) (Prototype) (PAL)",
        .note         = "AKA Donald Duck's Sailboat Regatta",
    },{
        .md5          = "fa7e11a3dbea4365975cd2f094e61d25",
        .manufacturer = "Tim Snider",
        .name         = "Mystery Science Theater 2600 (1999) (Tim Snider) (Hack)",
        .note         = "Hack of Megamania",
    },{
        .md5          = "fa98d48cd609c9babc819e0a1bd8d598",
        .manufacturer = "AtariAge (Chris Walton)",
        .name         = "Juno First (2009) (PAL60)",
        .note         = "AtariVox supported",
        .right        = "ATARIVOX",
        .phosphor     = 1,
    },{
        .md5          = "fab7b04b9f42df761eb6f2bc445eaa99",
        .manufacturer = "20th Century Fox Video Games - Sirius Software, David Lubar",
        .model        = "11008",
        .name         = "Fantastic Voyage (11-04-1982) (20th Century Fox) (Prototype)",
    },{
        .md5          = "fabca526d57de46768b392f758f1a008",
        .name         = "Laseresal 2600 (16-12-2001) (Andrew Wallace) (PD)",
    },{
        .md5          = "fac28963307b6e85082ccd77c88325e7",
        .manufacturer = "CCE",
        .name         = "Berzerk (CCE)",
    },{
        .md5          = "fadb89f9b23beb4d43a7895c532757e2",
        .manufacturer = "Galaga Games",
        .name         = "River Raid (1984) (Galaga Games) (PAL)",
    },{
        .md5          = "fae0b86934a7c5a362281dffebdb43a0",
        .manufacturer = "Retroactive",
        .name         = "Qb (2.07) (Retroactive) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "faebcb2ef1f3831b2fc1dbd39d36517c",
        .manufacturer = "Atari, Jerome Domurat, Steve Woita",
        .model        = "CX2696",
        .name         = "Asterix (1984) (Atari) (PAL)",
        .note         = "AKA Taz",
    },{
        .md5          = "faed2ef6b44894f8c83f2b50891c35c6",
        .manufacturer = "CCE",
        .name         = "Super Baseball (CCE)",
        .note         = "AKA RealSports Baseball",
    },{
        .md5          = "faffd84f3a8eceee2fa5ea5b0a3e6678",
        .manufacturer = "Suntek",
        .model        = "SS-025",
        .name         = "Spectracube Invasion (1983) (Suntek) (PAL)",
        .note         = "AKA Immies & Aggies",
    },{
        .md5          = "fb09ee4ccd47ae74a3c314f0d8a40344",
        .name         = "Titans (SnailSoft)",
    },{
        .md5          = "fb0c32ef7af5b45486db663510094be8",
        .name         = "Demo Image Series #15 - Three Marios (NTSC) (Non-Interleave) (06-03-2003) (Andrew Davie)",
    },{
        .md5          = "fb0e84cee4c108d24253bcb7e382cffd",
        .name         = "Interleaved ChronoColour Demo (SECAM) (05-03-2003) (Andrew Davie)",
    },{
        .md5          = "fb27afe896e7c928089307b32e5642ee",
        .manufacturer = "M Network - INTV - APh Technological Consulting, Jeff Ronne, Brett Stutz",
        .model        = "MT5662",
        .name         = "TRON - Deadly Discs (1983) (M Network)",
    },{
        .md5          = "fb4ca865abc02d66e39651bd9ade140a",
        .manufacturer = "Arcadia Corporation, Brian McGhie",
        .model        = "AR-4104",
        .name         = "Rabbit Transit (1983) (Arcadia)",
    },{
        .md5          = "fb531febf8e155328ec0cd39ef77a122",
        .name         = "Worm War I (Unknown) (PAL) [a]",
        .phosphor     = 1,
    },{
        .md5          = "fb5c8af97bd8ffe88323656f462645a7",
        .name         = "Interlace Demo (Glenn Saunders)",
        .phosphor     = 1,
    },{
        .md5          = "fb833ed50c865a9a505a125fc9d79a7e",
        .manufacturer = "ITT Family Games",
        .name         = "Pumuckl I (1983) (ITT Family Games) (PAL)",
        .note         = "AKA Pumuckl at the Zoo",
    },{
        .md5          = "fb884ffd89013331a6f01ae3f6abd214",
        .manufacturer = "Activision, David Crane",
        .name         = "Venetian Blinds Demo (1982) (Activision) (PAL)",
    },{
        .md5          = "fb88baa01afd34e0e4b601e1d29bc806",
        .manufacturer = "Manuel Polik",
        .name         = "Star Fire (2003) (XYPE)",
    },{
        .md5          = "fb88c400d602fe759ae74ef1716ee84e",
        .manufacturer = "20th Century Fox Video Games, Bill Aspromonte",
        .model        = "11031",
        .name         = "Crash Dive (1983) (20th Century Fox)",
        .note         = "AKA Voyage to the Bottom of the Sea",
    },{
        .md5          = "fb91da78455d9b1606913fbf8c859772",
        .name         = "Split Screen (Ballblazer) Demo (PD)",
    },{
        .md5          = "fb91dfc36cddaa54b09924ae8fd96199",
        .manufacturer = "Parker Brothers, Mark Lesser",
        .model        = "PB5590",
        .name         = "Frogger II (1984) (Parker Bros) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "fb978f1c053e8061cc37a726639f43f7",
        .manufacturer = "Atari - Axlon, Tod Frye - Heuristica, Agustin Ortiz Valdiviezo",
        .model        = "CX26169",
        .name         = "Shooting Arcade (03-07-1989) (Atari) (Prototype)",
        .note         = "Uses the Light Gun Controller (left only)",
    },{
        .md5          = "fbac6476e7b2b20d246202af81662c88",
        .manufacturer = "Starpath Corporation, Stephen H. Landrum",
        .model        = "AR-4400",
        .name         = "Dragonstomper (Preview) (1982) (Starpath) (PAL)",
    },{
        .md5          = "fbb0151ea2108e33b2dbaae14a1831dd",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Robot Tank TV (Thomas Jentzsch) (Hack)",
        .note         = "Uses two simultaneous Joystick Controllers, Hack of Robot Tank",
    },{
        .md5          = "fbb4f3debf48dc961b559384467f2057",
        .manufacturer = "Digitel",
        .name         = "River Raid III (1985) (Digitel)",
        .note         = "AKA River Raid",
    },{
        .md5          = "fbe554aa8f759226d251ba6b64a9cce4",
        .manufacturer = "Atari - GCC, Mike Feinstein, Brad Rice",
        .model        = "CX2681, CX2681P",
        .name         = "Battlezone (1983) (Atari) (PAL)",
    },{
        .md5          = "fbfebee9c14694719e3eda4854dc42ee",
        .manufacturer = "Jake Patterson",
        .name         = "Baubles 3 (Jake Patterson) (PD)",
    },{
        .md5          = "fc2104dd2dadf9a6176c1c1c8f87ced9",
        .manufacturer = "Coleco - Woodside Design Associates, Harley H. Puthuff Jr.",
        .model        = "2663",
        .name         = "Time Pilot (1983) (Coleco)",
    },{
        .md5          = "fc2233fc116faef0d3c31541717ca2db",
        .manufacturer = "Atari, Tod Frye",
        .model        = "CX2646",
        .name         = "Pac-Man (1982) (Atari) (PAL)",
    },{
        .md5          = "fc24a94d4371c69bc58f5245ada43c44",
        .manufacturer = "Atari - Axlon, Steve DeFrisco",
        .model        = "CX26170",
        .name         = "Secret Quest (1989) (Atari)",
    },{
        .md5          = "fc6052438f339aea373bbc999433388a",
        .manufacturer = "Atari, David Crane",
        .model        = "CX2653P",
        .name         = "Slot Machine (1979) (Atari) (PAL)",
    },{
        .md5          = "fc668a2251dd79cbd903d4fa0e558f96",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Thrust (V1.1) (2000) (Thomas Jentzsch) [a1]",
    },{
        .md5          = "fc92d74f073a44bc6e46a3b3fa8256a2",
        .name         = "Megademo (19xx) (PD)",
    },{
        .md5          = "fc9c1652fe3a2cade6188f4d3692481f",
        .manufacturer = "Andrew Davies",
        .name         = "Andrew Davies early notBoulderDash demo (NTSC)",
        .phosphor     = 1,
    },{
        .md5          = "fca4a5be1251927027f2c24774a02160",
        .manufacturer = "Activision, John Van Ryzin",
        .model        = "AZ-036-04",
        .name         = "H.E.R.O. (1984) (Activision)",
    },{
        .md5          = "fcbbd0a407d3ff7bf857b8a399280ea1",
        .manufacturer = "ZiMAG - Emag - Vidco",
        .model        = "GN-070",
        .name         = "Mysterious Thief, A (1983) (ZiMAG) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "fcbdf405f0fc2027b0ea45bb5af94c1a",
        .manufacturer = "Amiga - Video Soft, Michael K. Glass, Jerry Lawson",
        .name         = "3-D Ghost Attack (1983) (Amiga) (Prototype)",
        .phosphor     = 1,
    },{
        .md5          = "fcea12625c071ddc49f4e409f4038c60",
        .manufacturer = "Fabrizio Zavagli",
        .name         = "Balls! (16-09-2002) (Fabrizio Zavagli)",
        .phosphor     = 1,
    },{
        .md5          = "fcf8e306f6615f74feba5cb25550038c",
        .name         = "Blue Dot Demo (PD)",
    },{
        .md5          = "fd0e5148162e8ec6719445d559f018a9",
        .manufacturer = "Activision, Steve Cartwright - Ariola",
        .model        = "EAX-022, EAX-022-04I - 711 022-720",
        .name         = "Seaquest (1983) (Activision) (PAL)",
    },{
        .md5          = "fd10915633aea4f9cd8b518a25d62b55",
        .manufacturer = "Atari, John Dunn",
        .model        = "CX2631, CX2631P",
        .name         = "Superman (1979) (Atari) (PAL) [a]",
    },{
        .md5          = "fd16949913aaab5beaefed73bf2ca67c",
        .manufacturer = "Atari - GCC, John Allred, Mike Feinstein",
        .model        = "CX2688",
        .name         = "Jungle Hunt (02-03-1983) (Atari) (Prototype)",
    },{
        .md5          = "fd4f5536fd80f35c64d365df85873418",
        .manufacturer = "Atari - Bobco, Robert C. Polaro",
        .model        = "CX26140",
        .name         = "Desert Falcon (1987) (Atari)",
        .note         = "AKA Nile Flyer, Sphinx",
    },{
        .md5          = "fd6e507b5df68beeeddeaf696b6828fa",
        .name         = "Boxing (Unknown) (PAL)",
    },{
        .md5          = "fd7464edaa8cc264b97ba0d13e7f0678",
        .manufacturer = "HES",
        .model        = "771-333",
        .name         = "2 Pak Special - Challenge, Surfing (1990) (HES) (PAL) [a]",
    },{
        .md5          = "fd78f186bdff83fbad7f97cb583812fe",
        .manufacturer = "Amiga - Video Soft, Chip Curry",
        .model        = "3125",
        .name         = "Surf's Up (1983) (Amiga) (Prototype) [a2]",
        .note         = "Uses the Joyboard controller",
    },{
        .md5          = "fd8b4ee0d57605b35e236e814f706ff1",
        .manufacturer = "Atari - GCC, Mike Feinstein, John Mracek",
        .model        = "CX2673, CX2673P",
        .name         = "Phoenix (1982) (Atari) (PAL) [a]",
    },{
        .md5          = "fd9b321cee5fbb32c39ba3ca5d9ec7cf",
        .manufacturer = "Jeffry Johnston",
        .name         = "Radial Pong - Version 5 (Jeffry Johnston) (PD)",
    },{
        .md5          = "fdd4995a50395db14f518f63c2d63438",
        .name         = "Oh No! (Version 3) (18-01-2003) (Andrew Davie)",
    },{
        .md5          = "fde42e39710e75e9e4d4d75440f8e4e5",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Coke Zero (v1.0) (PAL)",
    },{
        .md5          = "fdf0de38517e0cf7f0885f98ccc95836",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4200",
        .name         = "Escape from the Mindmaster (2 of 4) (1982) (Arcadia)",
    },{
        .md5          = "fdf6680b2b1e8054293a39700a765692",
        .name         = "Alpha Demo - The Beta Demo 2 (2000) (Manuel Rotschkar)",
    },{
        .md5          = "fe0b7f27e3ad50bbf9ff468ee56d553d",
        .name         = "Lines Demo (Eckhard Stolberg) (PAL) (PD)",
    },{
        .md5          = "fe0bc4bb92c1c4de7d5706aaa8d8c10d",
        .name         = "Sprite Demo 2 (PD)",
    },{
        .md5          = "fe3b461d4c8b179fe68bc77760294c25",
        .manufacturer = "Atari, Joe Decuir",
        .model        = "CX2621, CX2621P",
        .name         = "Video Olympics (1977) (Atari) (PAL) (4K)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXDR",
        .swapPaddles  = 1,
    },{
        .md5          = "fe641247a4ab9bee970e19ab55f23b25",
        .manufacturer = "20th Century Fox Video Games, Beck-Tech, Steve Beck",
        .model        = "11035",
        .name         = "Save the Whales (02-07-1983) (20th Century Fox) (Prototype)",
    },{
        .md5          = "fe67087f9c22655ce519616fc6c6ef4d",
        .manufacturer = "Atari - Zip Technology, Randy Bowker, Bruce Williams",
        .model        = "CX26142",
        .name         = "Crack'ed (11-28-1988) (Atari) (Prototype)",
    },{
        .md5          = "fe6abc0f63e31e2646c9c600926b5b7f",
        .manufacturer = "Atari",
        .model        = "CX26137",
        .name         = "4 in 1 (02-19-1987) (Atari) (Prototype)",
        .note         = "Home Run, Canyon Bomber, Sky Diver, Night Driver",
        .type         = "4IN1",
    },{
        .md5          = "fe870018332a0221eb59fb18b0c6bccc",
        .name         = "Incoming (08-11-2002) (Ben Larson) (PD)",
    },{
        .md5          = "fe9ae625d924b54c9f8a14ac9a0f6c6d",
        .manufacturer = "BG Dodson",
        .name         = "High Bid! (BG Dodson) (Hack)",
        .note         = "Hack of Pepsi Invaders",
    },{
        .md5          = "feba8686fd0376015258d1152923958a",
        .name         = "Super Circus (Unknown) (PAL)",
        .note         = "AKA Circus Atari",
        .left         = "JOYSTICK",
        .right        = "JOYSTICK",
    },{
        .md5          = "fec0c2e2ab0588ed20c750b58cf3baa3",
        .manufacturer = "Activision - Cheshire Engineering, David Rolfe, Larry Zwick",
        .model        = "EAZ-037-04, EAZ-037-04I",
        .name         = "Beamrider (1984) (Activision) (PAL)",
    },{
        .md5          = "fece458a8023a809a5006867feca40e8",
        .name         = "SCSIcide (24-02-2001) (Joe Grand) (PD)",
    },{
        .md5          = "feec54aac911887940b47fe8c9f80b11",
        .manufacturer = "Atari, Rob Fulop",
        .model        = "CX2633, CX2633P",
        .name         = "Night Driver (1980) (Atari) (PAL)",
        .note         = "Uses the Paddle Controllers (left only)",
        .phosphor     = 1,
    },{
        .md5          = "feedcc20bc3ca34851cd5d9e38aa2ca6",
        .manufacturer = "Atari, David Crane - Sears",
        .model        = "CX2607 - 6-99828, 49-75115",
        .name         = "Canyon Bomber (1979) (Atari)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXDR",
        .swapPaddles  = 1,
    },{
        .md5          = "ff1523783e0e76a3b0d1f7f0d1cb3050",
        .manufacturer = "Thomas Jentzsch",
        .name         = "Marble Craze - Atari Trak-Ball Hack v1.0 (PAL) (Thomas Jentzsch)",
        .note         = "Uses Atari Trak-Ball Controllers",
    },{
        .md5          = "ff3bd0c684f7144aeaa18758d8281a78",
        .manufacturer = "Atari, Bob Whitehead",
        .model        = "CX2651",
        .name         = "Blackjack (1977) (Atari) (PAL)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXIS",
    },{
        .md5          = "ff5a9e340d96df6f5a5b6eb038e923bd",
        .name         = "Space Shuttle (1983) (Activision) [t1]",
    },{
        .md5          = "ff7627207e8aa03730c35c735a82c26c",
        .manufacturer = "Atari, Bob Whitehead",
        .model        = "CX26163P",
        .name         = "Blackjack (32 in 1) (1988) (Atari) (PAL)",
        .note         = "Uses the Paddle Controllers",
        .left         = "PADDLES_IAXIS",
    },{
        .md5          = "ff8343ce12fa222a23ab13d7d733e27b",
        .manufacturer = "Artkaris Software",
        .name         = "Phoenix (1986) (Artkaris) (PAL)",
    },{
        .md5          = "ff86fc8ffa717bb095e8471638c1c31c",
        .manufacturer = "Arcadia Corporation, Dennis Caswell",
        .model        = "AR-4302",
        .name         = "Party Mix - Bop a Buggy (1 of 3) (1983) (Arcadia) (PAL)",
        .note         = "Uses Paddle Controllers",
    },{
        .md5          = "ff87d58125ae517eb7b09a0475a1ccdc",
        .name         = "SCSIcide (Score Hack 1) (24-02-2001) (Joe Grand) (PD)",
    },{
        .md5          = "ffb1cd548563158ce33f9d10268187e7",
        .manufacturer = "Erik Eid",
        .name         = "Euchre (Beta) (NTSC) (12-09-2002) (Erik Eid)",
    },{
        .md5          = "ffc0ff4305dd46b4b459885bd1818e2e",
        .manufacturer = "Barry Laws Jr.",
        .name         = "Star Wars - The Battle of Alderaan (Star Strike Hack)",
        .note         = "Hack of Star Strike (Mattel)",
    },{
        .md5          = "ffdc0eb3543404eb4c353fbdddfa33b6",
        .manufacturer = "CCE",
        .model        = "C-827",
        .name         = "Chopper Command (1983) (CCE) [a]",
    },{
        .md5          = "ffe51989ba6da2c6ae5a12d277862e16",
        .manufacturer = "Atari - Sears",
        .model        = "CX2627 - 6-99841",
        .name         = "Human Cannonball (1979) (Atari) (4K)",
        .note         = "AKA Cannon Man",
    },{
        .md5          = "ffebb0070689b9d322687edd9c0a2bae",
        .name         = "Spitfire Attack (1983) (Milton Bradley) [h1]",
    },{
        .md5          = "0be9ad4729ecd50cadece9200f324a43",
        .manufacturer = "Bit Corporation",
        .model        = "PG208",
        .name         = "Snail Against Squirrel (1983) (BitCorp) ",
    },{
        .md5          = "112afb9c6777d652968f31328a327a01",
        .manufacturer = "Atari, Tod Frye, Mimi Nyden",
        .model        = "CX2657",
        .name         = "SwordQuest - FireWorld Contest Edition (1984) (Atari)",
    },{
        .md5          = "13e133a1efc1b55fcd76cbb3ae7cf333",
        .name         = "Yars' Revenge (Unknown) (PAL)",
        .phosphor     = 1,
    },{
        .md5          = "19f2680259c02945a221627e2ffec18a",
        .name         = "Super Challenge Baseball (Unknown) (PAL) [a]",
    },{
        .md5          = "1d67c50baff2df771c32e2f915879176",
        .manufacturer = "Atari - Axlon, Tod Frye - Heuristica, Agustin Ortiz Valdiviezo",
        .model        = "CX26169",
        .name         = "Shooting Arcade (09-19-1989) (Atari) (Prototype) [screen 5]",
        .note         = "Uses the Light Gun Controller (left only)",
    },{
        .md5          = "1eebb6c3ad8153b46bf45b17d879d2e5",
        .name         = "Save Our Ship (Unknown) (PAL)",
    },{
        .md5          = "238976ea238ba2f6d85ad30d5ac50280",
        .name         = "Slot Machine (Unknown) (PAL) (4K)",
    },{
        .md5          = "3095f60d0d9a054bdef5c43c4ad4ac1c",
        .name         = "Video Chess (Unknown)",
    },{
        .md5          = "3584222eec8152f2feae3902bab2595f",
        .manufacturer = "Atari, Douglas Neubauer, Mimi Nyden",
        .model        = "CX26136",
        .name         = "Solaris (1986) (Atari) (Prototype)",
        .note         = "AKA The Last Starfighter, Star Raiders II, Universe",
    },{
        .md5          = "4e4a263ca1f7fd37b04b9c4d7416f151",
        .name         = "Zaxxon (Unknown) (PAL)",
    },{
        .md5          = "4f7a6ba1baac8d25ce524eb660cca78d",
        .manufacturer = "Bit Corporation",
        .model        = "CP405",
        .name         = "Turtle Race (4 Game in One) (1983) (BitCorp) (PAL)",
        .note         = "AKA Freeway",
    },{
        .md5          = "5061a82ea69e329a46b120cfac328fef",
        .manufacturer = "Fotomania",
        .name         = "Seaquest (Fotomania)",
    },{
        .md5          = "52e6c8551e38b901472293339a360fa2",
        .name         = "Space Jockey (Unknown)",
    },{
        .md5          = "52ec33be79c05b9218c9b55f7ccc1bfa",
        .manufacturer = "Edu Games - Edu Juegos",
        .name         = "Time Pilot (1983) (Edu Games) (PAL)",
    },{
        .md5          = "5b1e05ba56ad9345d39f261d4dadb88c",
        .name         = "Solar Fox (Unknown) (PAL)",
    },{
        .md5          = "5f3e92916a3d1c0638e9665781119551",
        .name         = "Star Trek (Unknown) (PAL)",
    },{
        .md5          = "60246884418a559d6c23d3a6baee9e8f",
        .name         = "Space War (Unknown) (PAL) (4K)",
    },{
        .md5          = "660c378803503a443556525ddda08648",
        .manufacturer = "Atari - Axlon, Tod Frye - Heuristica, Agustin Ortiz Valdiviezo",
        .model        = "CX26169",
        .name         = "Shooting Arcade (09-19-1989) (Atari) (Prototype) [screen 6]",
        .note         = "Uses the Light Gun Controller (left only)",
    },{
        .md5          = "6bc89b25d541a6da465d2e2c0b527941",
        .name         = "Stampede (Unknown) (PAL) (4K)",
    },{
        .md5          = "7095858d35ca36e7a8f46bea46bb46da",
        .manufacturer = "Canal 3 - Intellivision",
        .name         = "Seaquest (Canal 3)",
    },{
        .md5          = "7128e72bc1b707ef63f7a95177e96c39",
        .name         = "Star Voyager (Unknown) (PAL)",
    },{
        .md5          = "75723c16a975afb9da92022583fa802d",
        .manufacturer = "Bit Corporation",
        .model        = "CP405",
        .name         = "Snow Hunter (4 Game in One) (1983) (BitCorp) (PAL)",
        .note         = "AKA Ski Hunt",
    },{
        .md5          = "76226fa2eb33e796d1e7c7bb8f22a91e",
        .name         = "Spider-Man (Unknown) (PAL)",
    },{
        .md5          = "81e44e968a4b3cd85b4a0f9a60d25dcd",
        .name         = "Stampede (Unknown)",
    },{
        .md5          = "83531415b25531b47d23cf205961e51f",
        .manufacturer = "Atari - Axlon, Tod Frye - Heuristica, Agustin Ortiz Valdiviezo",
        .model        = "CX26169",
        .name         = "Shooting Arcade (09-19-1989) (Atari) (Prototype) [screen 3]",
        .note         = "Uses the Light Gun Controller (left only)",
    },{
        .md5          = "85b6071974aca39e980d48064ae5e847",
        .manufacturer = "Tigervision, Warren Schwader",
        .model        = "7-003",
        .name         = "Threshold (1982) (Tigervision)",
    },{
        .md5          = "8ea7e1c23b7c0367d0d5de27dbb6da39",
        .manufacturer = "Telesys, Alex Leavens",
        .model        = "1005",
        .name         = "Stargunner (1983) (Telesys) (PAL)",
    },{
        .md5          = "927a409c01600c64c7fe3565b409dba6",
        .manufacturer = "Canal 3 - Intellivision",
        .name         = "Solar Storm (Canal 3)",
        .note         = "Uses the Paddle Controllers",
    },{
        .md5          = "9713537765b4c6532f6ee40025d8f182",
        .name         = "Thunderground (Unknown) (Hack) [a]",
    },{
        .md5          = "a256ebbfefdc7b5ff8cc6697a868ec3a",
        .name         = "Towering Inferno (Unknown) (PAL) [a]",
    },{
        .md5          = "b018c51949fcf78b76b3bac7d3bcb1ae",
        .manufacturer = "Atari - Axlon, Tod Frye - Heuristica, Agustin Ortiz Valdiviezo",
        .model        = "CX26169",
        .name         = "Shooting Arcade (09-19-1989) (Atari) (Prototype) [screen 4]",
        .note         = "Uses the Light Gun Controller (left only)",
    },{
        .md5          = "be7011581614ffb0c38f79f99ae67b4f",
        .manufacturer = "Atari - Axlon, Tod Frye - Heuristica, Agustin Ortiz Valdiviezo",
        .model        = "CX26169",
        .name         = "Shooting Arcade (09-19-1989) (Atari) (Prototype) [screen 2]",
        .note         = "Uses the Light Gun Controller (left only)",
    },{
        .md5          = "c16cc583860bee0b928ef7fbd0010b4e",
        .manufacturer = "Fotomania",
        .name         = "Volleyball (Fotomania)",
        .note         = "AKA RealSports Volleyball",
    },{
        .md5          = "cee0177142b348b323877983d4ea38dc",
        .name         = "Submarine Commander (Unknown) (PAL)",
    },{
        .md5          = "e313e8f1d19b433ec37e586b918f4df8",
        .manufacturer = "Fotomania",
        .name         = "Tennis (Fotomania)",
    },{
        .md5          = "f72d7b54973203cafabc619582147ed8",
        .name         = "Skiing (Unknown) (PAL) (4K)",
    },{
        .md5          = "fc6999c4897af166a2a8d109306650ee",
        .name         = "Vanguard (Unknown) (PAL)",
    }
};

}

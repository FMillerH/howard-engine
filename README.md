# Howard Engine

A C++20 UI and scene framework built on [raylib](https://www.raylib.com/), with a custom
plain-text format (`.hwd`) and a hand-written parser. Menus, scenes, and the navigation
links between them are declared in data files and loaded at runtime, so changing the UI
does not require editing C++ or recompiling.

No parsing or UI dependencies — raylib is the only external library, and CMake fetches it
automatically.

> **Status:** Active work in progress and a learning project.
> The parser, menu construction, scene graph, and input binding
> are 'working' in the sense that I will soon be able to add
> the ability to construct new menus within the program.
> As of now, many of the 'user interaction' components merely
> exist as ideas within the code, and so much of this is simply
> unfinished. I encourage exploration of the custom UI environment,
> as well as the HWD parser, which interacts with the .hwd files.
> See [Repository layout](#repository-layout)

---

## The `.hwd` format

UI and scene structure live in plain text instead of hardcoded C++. A file opens with a
parser key (`*MENU`, `*SCENE`) that tells the parser how to read the rest of it.

**`menu.hwd`** — each line declares a menu and its button labels:

```
*MENU
MENU::MAIN = NEW GAME, LOAD GAME, OPTIONS, QUIT;
MENU::OPT = TEST_A1, TEST_B1, BACK;
MENU::SELECT = BRAWL MATH TEST, PLATFORMER, BUSINESS MGMT, BACK;

REQUEST! MAIN.OPTIONS -> OPT.BACK;
REQUEST! OPT.TEST_A1 -> SELECT.BACK;
```

A `REQUEST!` line wires one menu to another: pressing `OPTIONS` in `MAIN` opens `OPT`, and
`BACK` in `OPT` returns. Links are declared separately from the menus themselves, which is
what makes the two-phase load necessary.

**`scene.hwd`** — the same idea applied to the scene graph:

```
*SCENE
SCENE::CENTER;
SCENE::LEFT;

REQUEST! CENTER -> LEFT;
```

---

## How loading works

**Two-phase construction.** A `REQUEST!` line can name a menu that appears later in the
file. Resolving links while parsing would force every menu to be declared before anything
referencing it, so the loader builds every menu first and then resolves the requests by name
in a second pass. Declaration order in the file stops mattering.

**Parser.** `LightTextParser/` holds the format reading. `HWD::parseFile` returns a `Block`
carrying the menu-to-labels map, generated identities, and the parsed request list.
Splitting is done by hand with `std::string_view` — `splitConditional` breaks a request line
into its four parts around the operator. No parsing library is used; writing this from
scratch was the point of the exercise.

**Navigation.** Menu history is kept on a stack, so back navigation falls out of the data
structure instead of needing reverse links declared in the file.

**Input.** `Controller` holds an `unordered_map<int, std::function<void()>>` from raylib key
codes to actions. `scanKeyBindings()` walks the map once per frame, which keeps per-frame
polling in one place rather than spread through the game loop. This will be more fleshed out
in a future build.

---

## Building

Requires CMake 3.16+, a C++20 compiler, and an internet connection on the first build
(raylib 5.5 is fetched automatically).

```bash
git clone https://github.com/FMillerH/howard-engine.git
cd howard-engine
cmake -B build
cmake --build build
./build/H03_01
```

AddressSanitizer and UBSan flags are present in `CMakeLists.txt`, commented out. Uncomment
the `target_compile_options` / `target_link_options` lines to build with them.

---

## Repository layout

Entry point is **`main.cpp`** at the repository root. It calls one of the window functions
in `Windows/`, each of which is a separate runnable demo.

```
howard-engine/
├── main.cpp                  # Entry point — selects which window to run
├── menu.hwd                  # Menu definitions and navigation links
├── scene.hwd                 # Scene graph definitions
│
├── LightTextParser/          # .hwd format parser
│   ├── hwd.*                 #   HWD class, Block struct — main parser
│   └── lightTextParser.*     #   Earlier line-based parsing helpers
│
├── ImportedUI/               # UI framework
│   ├── UIenv/                #   UIenv — owns menus, drives navigation
│   ├── ToolsUI00/            #   Container, Button, Menu, Placer, buttonMap
│   └── ButtonActions/        #   Action dispatch for buttons
│
├── Sandbox/                  # Scene system
│   ├── Scene/                #   Scene base + SceneList (mainMenu, center)
│   ├── SceneGraph/           #   Scene graph structure
│   ├── SCENEenv/             #   Scene environment
│   └── Primes/               #   Unrelated experiment
│
├── Controller/               # Key binding and per-frame input polling
├── Example/                  # ExampleGame2D, Player — demo game using the framework
└── Windows/                  # Runnable demos
    ├── Path01/               #   2D UI + ExampleGame2D
    ├── Path02/               #   3D camera demo and BouncingSquare experiment
    └── Exceptions/           #   Error handling helpers
```

---

## Design notes

**Why a custom format instead of JSON or YAML?**
When I started learning C++ and raylib, I noticed that I was not comfortable using libraries 
without understanding how they worked.This led to experiments regarding syntax in .txt files 
while enforcing those rules at startup. Since this project was meant to mirror an 'in-house'
development tool, I felt it necessary to develop my own tools with their own use-cases. That
way, whenever something broke, I either knew right away what the issue was, or I was forced 
to patch in more safeguards.

---

## Tools

C++20 · raylib 5.5 · CMake · AddressSanitizer · CLion

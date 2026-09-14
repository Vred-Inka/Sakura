# Project Setup

This section describes how to build and run the project on a clean machine.

---

# Requirements

Install:

- Visual Studio 2022
- MSVC C++ Toolset
- Windows SDK
- Git (optional)

---

# Repository Structure

```text
Solution
│
├── Engine
│
├── DrMario
│
└── ThirdParty
    └── SDL3
```

---

# SDL3 Installation

Download SDL3 development libraries.

Expected structure:

```text
ThirdParty
└── SDL3
    ├── include
    │   └── SDL3
    │       ├── SDL.h
    │       ├── SDL_render.h
    │       └── ...
    │
    ├── lib
    │   └── x64
    │
    └── bin
        └── SDL3.dll
```

---

# Engine Project Configuration

## Include Directories

Engine Project

```text
Properties
    -> C/C++
    -> General
    -> Additional Include Directories
```

Add:

```text
$(SolutionDir)ThirdParty\SDL3\include
$(ProjectDir)
```

---

## Library Directories

Engine Project

```text
Properties
    -> Linker
    -> General
    -> Additional Library Directories
```

Add:

```text
$(SolutionDir)ThirdParty\SDL3\lib\x64
```

---

## Link Dependencies

Engine Project

```text
Properties
    -> Linker
    -> Input
    -> Additional Dependencies
```

Add:

```text
SDL3.lib
```

---

# DrMario Project Configuration

## Include Directories

DrMario Project

```text
Properties
    -> C/C++
    -> General
    -> Additional Include Directories
```

Add:

```text
$(SolutionDir)Engine
```

This allows:

```cpp
#include "Core/Application.h"
#include "Framework/IGame.h"
```

---

## Link Engine Library

DrMario Project

```text
Properties
    -> Linker
    -> Input
    -> Additional Dependencies
```

Add:

```text
Engine.lib
```

---

## Library Directory

DrMario Project

```text
Properties
    -> Linker
    -> General
    -> Additional Library Directories
```

Point to:

```text
Engine build output directory
```

Example:

```text
$(SolutionDir)x64\Debug
```

or

```text
$(OutDir)
```

depending on your build layout.

---

# Startup Project

Set:

```text
DrMario
```

as Startup Project.

The Engine project is a static library and cannot be started directly.

---

# SDL3 Runtime DLL

Copy:

```text
SDL3.dll
```

into the executable directory.

Example:

```text
DrMario
└── x64
    └── Debug
        ├── DrMario.exe
        └── SDL3.dll
```

Without the DLL the executable will not start.

---

# Build Order

Visual Studio should build:

```text
Engine
    ↓
DrMario
```

Project Dependencies:

```text
DrMario
    depends on
Engine
```

---

# Running

Build:

```text
Build -> Build Solution
```

Run:

```text
Debug -> Start Debugging
```

or

```text
F5
```

Expected result:

```text
Application starts
    ↓
Window created
    ↓
Game initialized
    ↓
GameplayState loaded
    ↓
Board rendered
    ↓
Pill rendered
```

---

# Troubleshooting

## Cannot open include file

Example:

```text
Cannot open include file:
'Core/Application.h'
```

Verify:

```text
DrMario
    Additional Include Directories
```

contains:

```text
$(SolutionDir)Engine
```

---

## SDL.h Not Found

Example:

```text
Cannot open include file:
'SDL3/SDL.h'
```

Verify:

```text
$(SolutionDir)ThirdParty\SDL3\include
```

is configured in Engine include directories
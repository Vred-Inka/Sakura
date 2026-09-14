#### Add includes to project settings
Visual Studio → Project → Properties → C/C++ → Additional Include Directories

Add: external/SDL3/include

Apply to All Configurations and All Platforms

//c++ additional include directories
$(SolutionDir)external/include

//linker/ additional libraries
Visual Studio → Project → Properties → Linker → General → Additional Library Directories
$(SolutionDir)external/lib

//Additional dependencies
SDL3.lib


# Sakura Engine + Dr. Mario Clone

## Overview

The project consists of two parts:

- Engine (reusable framework)
- DrMario (game implementation)

The engine does not contain any game-specific logic.

The game contains all gameplay rules such as pills, board, matching, gravity, scoring, and state management.

---

# Project Structure

```text
Solution
│
├── Engine
│
└── DrMario
```

---

# Engine

## Responsibilities

The engine provides:

- Application lifecycle
- Window management
- Rendering
- Input handling
- Timing
- State framework

The engine does not know anything about:

- Pills
- Viruses
- Board
- Match detection
- Scoring

---

# Core

## Application

Root object responsible for:

- Engine initialization
- Main loop
- Shutdown

Flow:

```text
Initialize
    ↓
Run
    ↓
Shutdown
```

Main loop:

```text
Process Events
    ↓
Update Game
    ↓
Render Frame
```

---

## Time

Provides:

```cpp
Time::DeltaTime()
```

Used to make movement frame-rate independent.

Example:

```cpp
position += speed * dt;
```

---

# Platform

## Window

SDL wrapper around:

```cpp
SDL_Window
```

Responsibilities:

- Create window
- Destroy window

No gameplay code should interact with SDL_Window directly.

---

## Input

Responsible for keyboard state tracking.

Provides:

```cpp
Input::IsKeyDown()
Input::IsKeyPressed()
Input::IsKeyReleased()
```

SDL events are translated into engine keys.

Game code should never use SDL key codes.

---

# Rendering

## Renderer

Wrapper around SDL renderer.

Provides operations such as:

```cpp
DrawRect()
BeginFrame()
EndFrame()
```

Game systems communicate with Renderer instead of SDL.

---

# Framework

## IGame

Represents a game running on the engine.

Interface:

```cpp
Initialize()
Update()
Render()
Shutdown()
```

Application interacts only with IGame.

Current implementation:

```text
DrMarioGame
    ↓
IGame
```

---

## IState

Common interface for game states.

Examples:

```text
GameplayState
MainMenuState
PauseState
```

Methods:

```cpp
Enter()
Exit()
Update()
Render()
```

---

## StateMachine

Manages active state.

Responsibilities:

- Change state
- Update current state
- Render current state

Flow:

```text
StateMachine
        │
        ▼
   Current State
```

---

# DrMario

## Responsibilities

Contains all game-specific logic.

Examples:

- Pills
- Board
- Random color generation
- Falling mechanics
- Matching
- Gravity

---

# DrMarioGame

Main game implementation.

Implements:

```cpp
IGame
```

Owns:

```text
StateMachine
```

Flow:

```text
DrMarioGame
        │
        ▼
    StateMachine
        │
        ▼
   GameplayState
```

---

# GameplayState

Current active gameplay mode.

Owns:

```text
Board
Active Pill
FallingSystem
```

Responsible for:

- Input processing
- Updating gameplay systems
- Rendering gameplay

---

# Board

Represents the playfield.

Current size:

```text
8 x 16
```

Stores:

```cpp
Cell[16][8]
```

Board contains gameplay data only.

Board does not render itself.

---

# Cell

Represents one board slot.

Contains:

```cpp
Occupied
Color
```

---

# Pill

Represents active player-controlled capsule.

Contains:

- Grid position
- Orientation
- Left color
- Right color

Supports:

```cpp
MoveLeft()
MoveRight()
MoveDown()
Rotate()
```

Pill contains data and gameplay behaviour only.

Pill does not render itself.

---

# Colors

Available colors:

```cpp
Magenta
Blue
Yellow
```

Colors are randomly generated when new pills are spawned.

---

# BoardRenderer

Responsible for visualizing the board.

Responsibilities:

- Draw board grid
- Draw occupied cells

BoardRenderer reads Board data.

BoardRenderer does not modify gameplay data.

---

# PillRenderer

Responsible for visualizing pills.

Responsibilities:

- Draw horizontal pill
- Draw vertical pill

PillRenderer reads Pill data.

PillRenderer does not modify gameplay data.

---

# FallingSystem

Responsible for automatic downward movement.

Responsibilities:

```text
Timer
    ↓
Move Pill Down
```

Current functionality:

- Tracks fall timer
- Moves active pill down periodically

Future functionality:

- Lock pills
- Notify gameplay state when movement is blocked

---

# Gameplay Architecture

Current gameplay flow:

```text
Spawn Pill
    ↓
Player Control
    ↓
Automatic Falling
    ↓
Lock
    ↓
Spawn New Pill
```

Future gameplay flow:

```text
Spawn Pill
    ↓
Player Control
    ↓
Lock
    ↓
Match Detection
    ↓
Destroy Matches
    ↓
Gravity
    ↓
Spawn New Pill
```

---

# Design Principles

## Engine

Engine provides infrastructure.

Examples:

```text
Window
Renderer
Input
StateMachine
```

Engine never contains Dr. Mario gameplay.

---

## Game

Game provides rules.

Examples:

```text
Board
Pill
Virus
Matching
Gravity
```

Game never accesses SDL directly.

---

## Separation of Concerns

Gameplay classes:

```text
Board
Pill
Cell
```

contain rules and state.

Rendering classes:

```text
BoardRenderer
PillRenderer
```

contain visual representation.

Rendering never changes gameplay state.

Gameplay never performs rendering.

---

# Current Milestones

✅ Application

✅ Window

✅ Renderer

✅ Input

✅ IGame

✅ StateMachine

✅ GameplayState

✅ Pill Rendering

✅ Pill Movement

✅ Pill Rotation

✅ Board

✅ BoardRenderer

✅ Random Color Generation

✅ Falling System

---

# Next Milestones

- Bottom collision
- Lock pill into board
- Spawn new pill
- Board occupancy collision
- Match detection
- Gravity system
- Virus generation
- Score system
- Audio
- Visual effects
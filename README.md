# 2D Animated Village OpenGL

A 2D animated village scene developed using **OpenGL and GLUT** for a Computer Graphics Lab project. The project demonstrates 2D transformations, geometric primitives, animation, text rendering, and interactive keyboard controls through a simple village environment.

## Project Overview

This project presents a simple animated village scene containing a house, windmill, car, clouds, sun, grass, road, and an information panel.

The main purpose of the project is to demonstrate fundamental concepts of **2D Computer Graphics** using OpenGL.

## Features

* 2D village environment
* House with roof and door
* Moving car animation
* Moving cloud animation
* Rotating windmill
* Sun, sky, grass, and road
* 2D geometric primitives
* House translation and scaling
* Interactive keyboard controls
* Text rendering using GLUT
* Double buffering for smooth animation
* Orthographic 2D projection

## Technologies Used

* C++
* OpenGL
* GLUT
* FreeGLUT
* Code::Blocks / compatible C++ IDE

## Graphics Concepts Demonstrated

The project demonstrates several fundamental Computer Graphics concepts:

* Geometric primitives
* Polygon drawing
* Circle generation
* Translation
* Scaling
* Rotation
* Animation using timer functions
* Keyboard interaction
* Orthographic projection
* Double buffering
* Basic color handling
* Text rendering

## Project Structure

```text
2D-Animated-Village-OpenGL/
│
├── README.md
├── progress.md
├── .gitignore
│
├── src/
│   └── main.cpp
│
├── docs/
│   └── project-notes.md
│
└── assets/
    └── screenshots/
```

## Controls

| Key | Action               |
| --- | -------------------- |
| Q   | Move house right     |
| W   | Move house left      |
| R   | Move house up        |
| T   | Move house down      |
| S   | Increase house scale |
| A   | Decrease house scale |
| Y   | Rotate windmill      |

## Animation

Two objects are animated automatically:

### Car

The car continuously moves from left to right across the road. When it leaves the screen, it is repositioned to the left side.

### Cloud

The cloud continuously moves across the sky and returns to the left side after reaching the right side.

## Project Members

* 41230301349
* 41230301350

## How to Run

1. Install a C++ IDE with OpenGL/GLUT support.
2. Clone this repository.
3. Open the project in the IDE.
4. Build the source code.
5. Run the application.
6. Use the keyboard controls to interact with the scene.

## Project Status

The project is completed as a Computer Graphics Lab project. The repository is being organized with documentation and development history for learning and project reference.

## License

This project is created for academic and educational purposes.

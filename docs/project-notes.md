# 2D Animated Village — Project Notes

## 1. Introduction

The 2D Animated Village is a Computer Graphics project developed using C++ with OpenGL and GLUT. The project creates a simple village environment using basic geometric shapes and demonstrates several fundamental concepts of 2D computer graphics.

The scene contains a house, windmill, car, clouds, sun, road, grass, and an information panel.

## 2. Objectives

The main objectives of this project are:

* To understand basic OpenGL programming.
* To draw 2D objects using geometric primitives.
* To understand 2D transformations.
* To implement simple object animation.
* To handle keyboard-based interaction.
* To understand orthographic projection.
* To practice basic computer graphics concepts through a visual project.

## 3. Main Components

### 3.1 Background

The background is divided into two main areas:

* Sky
* Grass

A road is also drawn over the grass area.

### 3.2 Sun

A circular sun is drawn in the upper part of the scene using a custom circle drawing function.

### 3.3 House

The house consists of:

* Rectangular base
* Triangular roof
* Rectangular door

The house can be moved and scaled using keyboard controls.

### 3.4 Windmill

The windmill contains:

* Vertical stand
* Four rotating blades

The blades are rotated around the center point using the OpenGL rotation transformation.

### 3.5 Car

The car contains:

* Main body
* Upper section
* Two circular wheels

The car is automatically animated from left to right.

### 3.6 Clouds

The cloud is created using multiple circles. The cloud automatically moves across the sky.

### 3.7 Information Box

An information box is displayed in the upper-left corner of the scene.

It contains:

* Project title
* Keyboard controls
* Group member IDs

## 4. Graphics Techniques Used

### Geometric Primitives

The project uses OpenGL primitives such as:

* `GL_QUADS`
* `GL_TRIANGLES`
* `GL_POLYGON`
* `GL_LINE_LOOP`

These primitives are combined to create the objects in the scene.

### Circle Drawing

Circles are generated using multiple points calculated with sine and cosine functions.

The general coordinate formula is:

```text
x = cx + r × cos(angle)
y = cy + r × sin(angle)
```

Where:

* `cx` = center x-coordinate
* `cy` = center y-coordinate
* `r` = radius
* `angle` = angle in radians

### Translation

Translation is used to move objects from one position to another.

The project uses:

```cpp
glTranslatef(x, y, z);
```

Translation is used for:

* Moving the house
* Moving the car
* Moving the cloud
* Positioning the windmill blades

### Scaling

Scaling changes the size of the house.

The project uses:

```cpp
glScalef(x, y, z);
```

### Rotation

Rotation is used for the windmill blades.

The project uses:

```cpp
glRotatef(angle, 0, 0, 1);
```

## 5. Animation

Animation is implemented using the GLUT timer function.

The `update()` function changes the position of animated objects and requests the scene to be redrawn.

The main animated objects are:

* Car
* Cloud

The windmill rotation is controlled through keyboard input.

## 6. Keyboard Interaction

The project supports interactive controls through the keyboard.

```text
Q/W → Move house horizontally
R/T → Move house vertically
S/A → Scale house
Y   → Rotate windmill
```

## 7. Projection

The project uses an orthographic 2D projection:

```cpp
gluOrtho2D(0, 1000, 0, 1000);
```

This provides a simple 2D coordinate system where objects can be positioned directly using x and y coordinates.

## 8. Double Buffering

The project uses:

```cpp
GLUT_DOUBLE
```

and swaps the front and back buffers using:

```cpp
glutSwapBuffers();
```

Double buffering helps provide smoother animation and reduces visible flickering.

## 9. Transformation Matrix

The project uses:

```cpp
glPushMatrix();
```

and:

```cpp
glPopMatrix();
```

to isolate transformations.

This allows transformations applied to one object to avoid affecting other objects in the scene.

## 10. Conclusion

The 2D Animated Village project demonstrates how basic OpenGL functions and 2D graphics concepts can be combined to create an interactive animated environment.

Through this project, concepts such as geometric primitives, translation, scaling, rotation, animation, keyboard interaction, orthographic projection, and double buffering are applied in a practical way.

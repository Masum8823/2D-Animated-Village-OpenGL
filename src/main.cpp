#include <GL/glut.h>
#include <math.h>

// Draw a circle using polygon approximation
void drawCircle(float cx, float cy, float radius)
{
glBegin(GL_POLYGON);

```
for (int i = 0; i < 360; i++)
{
    float angle = i * 3.14159f / 180.0f;

    glVertex2f(
        cx + radius * cos(angle),
        cy + radius * sin(angle)
    );
}

glEnd();
```

}

// Draw the village house
void drawHouse()
{
// House Base
glColor3f(0.7f, 0.4f, 0.2f);

```
glBegin(GL_QUADS);
glVertex2f(600, 300);
glVertex2f(800, 300);
glVertex2f(800, 500);
glVertex2f(600, 500);
glEnd();

// Roof
glColor3f(0.9f, 0.1f, 0.1f);

glBegin(GL_TRIANGLES);
glVertex2f(580, 500);
glVertex2f(820, 500);
glVertex2f(700, 650);
glEnd();

// Door
glColor3f(0.2f, 0.1f, 0.0f);

glBegin(GL_QUADS);
glVertex2f(670, 300);
glVertex2f(730, 300);
glVertex2f(730, 420);
glVertex2f(670, 420);
glEnd();
```

}

// Draw the windmill
void drawWindmill()
{
// Stand
glColor3f(0.5f, 0.5f, 0.5f);

```
glBegin(GL_QUADS);
glVertex2f(200, 300);
glVertex2f(220, 300);
glVertex2f(220, 550);
glVertex2f(200, 550);
glEnd();

// Blades
glPushMatrix();

glTranslatef(210, 550, 0);

glColor3f(1.0f, 1.0f, 1.0f);

for (int i = 0; i < 4; i++)
{
    glRotatef(90, 0, 0, 1);

    glBegin(GL_TRIANGLES);
    glVertex2f(0, 0);
    glVertex2f(-20, 100);
    glVertex2f(20, 100);
    glEnd();
}

glPopMatrix();
```

}

// Draw the car
void drawCar()
{
// Car Body
glColor3f(1.0f, 0.0f, 0.0f);

```
glBegin(GL_QUADS);
glVertex2f(50, 150);
glVertex2f(250, 150);
glVertex2f(250, 220);
glVertex2f(50, 220);
glEnd();

// Car Top
glBegin(GL_QUADS);
glVertex2f(80, 220);
glVertex2f(220, 220);
glVertex2f(190, 270);
glVertex2f(110, 270);
glEnd();

// Wheels
glColor3f(0.0f, 0.0f, 1.0f);

drawCircle(90, 150, 30);
drawCircle(210, 150, 30);
```

}



// Initialize OpenGL settings
void init()
{
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

```
glMatrixMode(GL_PROJECTION);
glLoadIdentity();

gluOrtho2D(0, 1000, 0, 1000);
```

}

// Display function
void display()
{
glClear(GL_COLOR_BUFFER_BIT);

```
// Sky
glColor3f(0.5f, 0.8f, 1.0f);
glBegin(GL_QUADS);
glVertex2f(0, 500);
glVertex2f(1000, 500);
glVertex2f(1000, 1000);
glVertex2f(0, 1000);
glEnd();

// Grass
glColor3f(0.2f, 0.8f, 0.2f);
glBegin(GL_QUADS);
glVertex2f(0, 0);
glVertex2f(1000, 0);
glVertex2f(1000, 500);
glVertex2f(0, 500);
glEnd();

// Road
glColor3f(0.2f, 0.2f, 0.2f);
glBegin(GL_QUADS);
glVertex2f(0, 100);
glVertex2f(1000, 100);
glVertex2f(1000, 250);
glVertex2f(0, 250);
glEnd();

// Sun
glColor3f(1.0f, 1.0f, 0.0f);
drawCircle(900, 900, 50);

// House
drawHouse();

// Windmill
drawWindmill();

// Car
drawCar();

glutSwapBuffers();
```

}

// Main function
int main(int argc, char** argv)
{
glutInit(&argc, argv);

```
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

glutInitWindowSize(800, 600);
glutCreateWindow("2D Animated Village Scene");

init();

glutDisplayFunc(display);

glutMainLoop();

return 0;
```

}

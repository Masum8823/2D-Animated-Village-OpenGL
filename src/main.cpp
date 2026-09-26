#include <GL/glut.h>

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

#include <GL/glut.h>
#include <math.h>

float carPos = -200.0f;
float cloudPos = 0.0f;
float fanAngle = 0.0f;

float houseScale = 1.0f;

float houseX = 0.0f;
float houseY = 0.0f;


void drawCircle(float cx, float cy, float radius)
{
    glBegin(GL_POLYGON);

    for (int i = 0; i < 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(cx + radius * cos(angle),cy + radius * sin(angle));
    }

    glEnd();
}


// House
void drawHouse()
{
    // House Base
    glColor3f(0.7f, 0.4f, 0.2f);

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
}


// Windmill
void drawWindmill()
{
    // Stand
    glColor3f(0.5f, 0.5f, 0.5f);

    glBegin(GL_QUADS);
    glVertex2f(200, 300);
    glVertex2f(220, 300);
    glVertex2f(220, 550);
    glVertex2f(200, 550);
    glEnd();


    // Blades
    glPushMatrix();

    glTranslatef(210, 550, 0);
    glRotatef(fanAngle, 0, 0, 1);

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
}


// Car
void drawCar()
{
    // Car Body
    glColor3f(1.0f, 0.0f, 0.0f);

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
}


// Text
void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);

    for (int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
}


// Information Box
void drawInfoBox()
{
    // Box
    glColor3f(0.10f, 0.12f, 0.16f);

    glBegin(GL_QUADS);
    glVertex2f(20, 700);
    glVertex2f(330, 700);
    glVertex2f(330, 970);
    glVertex2f(20, 970);
    glEnd();


    // Border
    glColor3f(0.8f, 0.8f, 0.8f);

    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2f(20, 700);
    glVertex2f(330, 700);
    glVertex2f(330, 970);
    glVertex2f(20, 970);
    glEnd();


    glColor3f(1.0f, 0.85f, 0.2f);
    drawText(40, 940, "2D ANIMATED VILLAGE");


    glColor3f(0.3f, 0.8f, 1.0f);
    drawText(40, 910, "CONTROLS");

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(40, 885, "Q/W - House Left/Right");
    drawText(40, 862, "R/T - House Up/Down");
    drawText(40, 839, "S/A - House Scale");
    drawText(40, 816, "Y - Windmill Rotate");


    // Group Members
    glColor3f(0.3f, 0.8f, 1.0f);
    drawText(40, 780, "GROUP MEMBERS");

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(40, 755, "41230301349");
    drawText(40, 733, "41230301350");
}


// Display
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);


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


    // House Transformation
    glPushMatrix();

    glTranslatef(houseX, houseY, 0);


    glTranslatef(700, 300, 0);
    glScalef(houseScale, houseScale, 1.0f);
    glTranslatef(-700, -300, 0);

    drawHouse();

    glPopMatrix();


    drawWindmill();


    // Clouds
    glPushMatrix();

    glTranslatef(cloudPos, 0, 0);
    glColor3f(1.0f, 1.0f, 1.0f);

    drawCircle(150, 850, 40);
    drawCircle(200, 850, 50);
    drawCircle(250, 850, 40);

    glPopMatrix();


    // Car
    glPushMatrix();

    glTranslatef(carPos, 0, 0);
    drawCar();

    glPopMatrix();


    // Information Box
    drawInfoBox();

    glutSwapBuffers();
}


// Keyboard
void keyboard(unsigned char key, int x, int y)
{
    if (key == 'q' || key == 'Q')
        houseX += 10.0f;

    if (key == 'w' || key == 'W')
        houseX -= 10.0f;

    if (key == 'r' || key == 'R')
        houseY += 10.0f;

    if (key == 't' || key == 'T')
        houseY -= 10.0f;

    if (key == 's' || key == 'S')
        houseScale *= 2.0f;

    if (key == 'a' || key == 'A')
        houseScale /= 2.0f;

    if (key == 'y' || key == 'Y')
        fanAngle -= 10.0f;

    glutPostRedisplay();
}


// Animation
void update(int value)
{
    // Car Movement
    carPos += 5.0f;

    if (carPos > 1000)
        carPos = -300.0f;


    // Cloud Movement
    cloudPos += 1.0f;

    if (cloudPos > 800)
        cloudPos = -300.0f;


    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}


// Initialization
void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 1000, 0, 1000);
}


// Main
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);

    glutCreateWindow("2D Animated Village Scene");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}

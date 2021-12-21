/*
   Name:           Hieu Huynh
   Project:        S1
   Description:    This program produce a few basic objects,
                   and manipulate these objects, and the surroundings
                   to create the actual scene

   Requirement:
       -Use only 3D parallel projection (glOrtho)
       -Define a "viewing volume" with edge length x,y,z = 3,5,7
       -Define a window of 800x800
       -Generate a [P]oint, [L]ine, [T]riangle, [S]quare, [H]exagon, [C]ircle, and c[U]be
           in the center of the viewing volume
           -Normalized with length of edges/radious = 2
           -Hexagon with length of edge = 1.5
           -Circle should be drawn using 40-gon
           -No restriction on cube placement
*/
#include <gl/glut.h>
#include <stdlib.h>
#include <math.h>

//Setting up window
void myInit();
void myDisplay();

//Reseting screen after each keystrikes
void resetScreen();

//Manipulating objects
void objectPoint();
void objectLine();
void objectTriangle();
void objectSquare();
void objectHexagon();
void objectCircle();
void objectCube();

//Interpreting keyboard strikes of "P,L,T,S,H,C, and U"
void myKeyboard(unsigned char theKey, int mouseX, int mouseY);

//initialize code OpenGl
void myInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glClearDepth(1.0f);
    glPointSize(4.0);
    glLineWidth(4.0);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glOrtho(-1.5, 1.5, -2.5, 2.5, -3.5, 3.5);
}

void myDisplay(void) {
    glutKeyboardFunc(myKeyboard);
}

void resetScreen() {
    glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5, 1.5, -2.5, 2.5, -3.5, 3.5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void objectPoint() {
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0, 0.0);
    glEnd();
    glFlush();
}

void objectLine() {
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0, 1.0);       //line of length = 2
    glVertex2f(0.0, -1.0);
    glEnd();
    glFlush();
}

void objectTriangle() {
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(-1.0, -1.0); //bottom edge of length = 2
    glVertex2f(1.0, -1.0);  //right edge of length = 2
    glVertex2f(0.0, 1.0);   //left edge of length = 2
    glEnd();
    glFlush();
}

void objectSquare() {
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-1.0, 1.0);  // point on top left
    glVertex2f(1.0, 1.0);   // point on top right
    glVertex2f(1.0, -1.0);  // point on bottom right
    glVertex2f(-1.0, -1.0); // point on bottom left
    glEnd();
    glFlush();
}

void objectHexagon() {
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(-0.75, 1.3);    // point on top left
    glVertex2f(0.75, 1.3);     // point on top right
    glVertex2f(1.5, 0.0);      // point on far right
    glVertex2f(0.75, -1.3);    // point on bottom right
    glVertex2f(-0.75, -1.3);   // point on bottom left
    glVertex2f(-1.5, 0.0);     // point on far left
    glEnd();
    glFlush();
}

void objectCircle() {
    const float numEdges = 40;
    const float radius = 1.5f;
    const float angle = 3.14159265358 * 2.f / numEdges;
    float xCoordinate = 0;
    float yCoordinate = 0;

    //Assign old coordinates
    float oldX = xCoordinate;
    float oldY = yCoordinate - radius;

    for (int i = 0; i <= numEdges; i++) {
        float newX = radius * sin(angle * i);
        float newY = -radius * cos(angle * i);

        glBegin(GL_POLYGON);  //draw polygons for circle
        glColor3f(1.0f, 0.5f, 0.0f);
        glVertex2f(0.0, 0.0);
        glVertex2f(oldX, oldY);
        glVertex2f(newX, newY);

        oldX = newX;
        oldY = newY;
    }

    glEnd();
    glFlush();
}

void objectCube() {
    gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);

    glBegin(GL_QUADS); // Begin drawing the color cube with 6 quads

    // Bottom quads (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f); // Orange
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Back quads (z = -1.0f)
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Left quads (x = -1.0f)
    glColor3f(1.0f, 0.0f, 1.0f); // Magneta
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Top quads (y = 1.0f)
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

    // Front quads (z = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Right quads (x = 1.0f)
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd();
    glFlush();
}


void myKeyboard(unsigned char theKey, int mouseX, int mouseY) {
    //Key P - Point
    if (theKey == 'P' || theKey == 'p') {

        resetScreen();
        objectPoint();
    }

    //Key L - Line
    else if (theKey == 'L' || theKey == 'l') {

        resetScreen();
        objectLine();
    }

    //Key T - Triangle
    else if (theKey == 'T' || theKey == 't') {

        resetScreen();
        objectTriangle();
    }

    //Key S - Square
    else if (theKey == 'S' || theKey == 's') {

        resetScreen();
        objectSquare();
    }

    //Key H - Hexagon
    else if (theKey == 'H' || theKey == 'h') {

        resetScreen();
        objectHexagon();
    }

    //Key C - Circle
    else if (theKey == 'C' || theKey == 'c') {

        resetScreen();
        objectCircle();
    }

    //Key U - cUbe
    else if (theKey == 'U' || theKey == 'u') {

        resetScreen();
        objectCube();
    }

    //Key Q - Quit
    else if (theKey == 'Q' || theKey == 'q') {
        exit(-1);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);  // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);   //set display mode
    glutInitWindowSize(800, 800);   //set window size

    //start the screen window
    glutCreateWindow("Project_S1_HieuHuynh - Manipulate Basic Object - Type Q or q to quit");

    // Clear color and depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //register redraw function
    glutDisplayFunc(myDisplay);

    myInit();

    //go into a perpetual loop
    glutMainLoop();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

/*
   Name:           Hieu Huynh
   Project:        S2
   Description:    This program rotate and transform objects from Assignment S1, and
                    modify the viewport.

   Requirement:
    -Camera
        -Use gluLookAt()
        -Define a window of 1024x1024 that is not in the "origin" of the screen
        -Define a viewport of 512x512 that is not in the "origin" of the screen
    -Object
        -Replace Hexagon by Octagon
    -Render
        -Do not overlap the translated and scaled objects
        -Scaled point, line, triangle, and square
            -Scaling factor of your choice
            -Different scaling factor for each object
            -Same saling factor for each axis of the objects
        -Scale the circle and the Octagon
            -Scaling factor of your choice
            -Different scaling factor for each object
            -Choose own vector and rotate around this vector
    -Render Cube
        -Cube 1. Edge length of 0.25 anywhere, "far" from the center
        -Cube 2. Rotate by 45 degrees around the vector (1, 1, 1) translate and render again
    -Scene
        -Produce only one scene
        -May want to push and pop the Model View matrix between consecutive transformation
*/
#include <gl/glut.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>

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
void objectOctagon();
void objectCircle();
void objectCube();
void renderCube();

void renderObject();

//Interpreting keyboard strikes of "P,L,T,S,H,C, and U"
void myKeyboard(unsigned char theKey, int mouseX, int mouseY);

//initialize code OpenGl
void myInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(4.0);
    glLineWidth(4.0);

    glLoadIdentity();
    glViewport(16, 16, 512, 512);       //viewport glViewport(xvmin, yvmin, widgth, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //glOrtho(left, right, bottom, top, near, far) double value
    glOrtho(-1.5, 1.5, -2.5, 2.5, -3.5, 3.5);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //gluLookAt(eyex, eyey, eyez, atx, aty, atz, upx, upy, upz);
    gluLookAt(1, 1, 1,          //Point where camera is located
        0, 0, 0,          //Point toward which camera is aimed at
        0, 1, 0);         //Upright position of camera specified by the vector
                          //from (0, 0, 0) to (0, 1, 0)
}

void myDisplay(void) {
    renderObject();
    glutKeyboardFunc(myKeyboard);
}

void renderObject() {
    objectPoint();
    objectLine();
    objectTriangle();
    objectSquare();
    objectOctagon();
    objectCircle();

    renderCube();

}

void objectPoint() {
    glPushMatrix();
    glTranslatef(1.4f, 0.0f, 0.0f);
    glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
    glScalef(3.0, 3.0, 3.0);

    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0, 0.0);
    glEnd();
    glFlush();

    glPopMatrix();
}

void objectLine() {
    glPushMatrix();
    glTranslatef(0.0f, -1.3f, 0.0f);
    glRotatef(135.0f, 0.0f, 0.0f, 1.0f);
    glScalef(1.0, 1.0, 1.0);

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0, 1.0);       //line of length = 2
    glVertex2f(0.0, -1.0);
    glEnd();
    glFlush();

    glPopMatrix();
}

void objectTriangle() {
    glPushMatrix();
    glTranslatef(1.0f, 2.4f, 0.0f);
    glRotatef(75.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.60, 0.60, 0.60);

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(-1.0, -1.0); //bottom edge of length = 2
    glVertex2f(1.0, -1.0);  //right edge of length = 2
    glVertex2f(0.0, 1.0);   //left edge of length = 2
    glEnd();
    glFlush();

    glPopMatrix();

}

void objectSquare() {
    glPushMatrix();
    glTranslatef(-1.0f, 0.2f, 0.0f);
    glRotatef(100.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.45, 0.45, 0.45);

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-1.0, 1.0);  // point on top left
    glVertex2f(1.0, 1.0);   // point on top right
    glVertex2f(1.0, -1.0);  // point on bottom right
    glVertex2f(-1.0, -1.0); // point on bottom left
    glEnd();
    glFlush();

    glPopMatrix();
}

void objectOctagon() {
    glPushMatrix();
    glTranslatef(-1.2f, 1.6f, 0.0f);
    glRotatef(125.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.15, 0.15, 0.15);

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f);
    //keeping the edge length of 1.5 as Assignment S1
    glVertex2f(-0.75, 2.05);    //top left
    glVertex2f(0.75, 2.05);     //top right
    glVertex2f(1.5, 0.75);      //far right top
    glVertex2f(1.5, -0.75);     //far right bottom
    glVertex2f(0.75, -2.05);    //bottom right
    glVertex2f(-0.75, -2.05);   //bottom left
    glVertex2f(-1.5, -0.75);    //far left bottom
    glVertex2f(-1.5, 0.75);     //far left top
    glEnd();
    glFlush();

    glPopMatrix();
}

void objectCircle() {
    glPushMatrix();
    glTranslatef(0.5f, 0.4f, 0.0f);
    glScalef(0.3, 0.3, 0.3);
    glRotatef(155.0f, 0.0f, 0.0f, 1.0f);
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

    glPopMatrix();
}

void objectCube() {
    // Bottom quads (y = -1.0f)
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5f, 0.0f); // Orange
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();

    // Left quads (x = -1.0f)
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 1.0f); // Magneta
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();

    // Back quads (z = -1.0f)
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glEnd();

    // Front quads (z = 1.0f)
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glEnd();

    // Top quads (y = 1.0f)
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glEnd();

    // Right quads (x = 1.0f)
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();

    glFlush();
}

void renderCube() {
    glPushMatrix();
    //gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);
    glTranslatef(-1.2f, -1.4f, 0.0f);
    glScalef(0.125, 0.125, 0.125);
    objectCube();
    glPopMatrix();

    glPushMatrix();
    //gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);
    glTranslatef(1.0f, -1.4f, 0.0f);
    glScalef(0.125, 0.125, 0.125);
    glRotatef(45.0f, 1.0f, 1.0f, 1.0f);
    objectCube();
    glPopMatrix();
}

void myKeyboard(unsigned char theKey, int mouseX, int mouseY) {

    //Key Q - Quit
    if (theKey == 'Q' || theKey == 'q') {
        exit(-1);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);  // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);   //set display mode

    //task: window should not be in the "origin" of the screen
    glutInitWindowSize(1024, 1024);     //set window size
    glutInitWindowPosition(300, 300);

    //start the screen window
    glutCreateWindow("Project_S2_HieuHuynh - Manipulate Render Object - Type Q or q to quit");
    glutDisplayFunc(myDisplay);     //register redraw function
    myInit();
    glutMainLoop();                  //go into a perpetual loop

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

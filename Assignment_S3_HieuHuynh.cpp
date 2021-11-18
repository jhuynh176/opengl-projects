/*
   Name:           Hieu Huynh
   Assignment:     S3
   Description:    This program manipulate light sources, and light meshes.

   Requirement:
        -   Add at least 4 light sources
                1.  point at a finite location
                2.  point at infinite
                3.  spot with different cut-offs and attenuation parameters
                4.  ambient light source
            -   User different colors in the ambient, diffuse, and specular space for each light source
            -   At least one light should be visible

        -   Associate material properties with each object in the scene:
            a.  Use different reflection coefficients in the ambient, diffuse, and specular space for each object.
            b.  Define shininess
            c.  Define normals and use flat as well as smooth, shading.
            d.  Use the Gourad method to find the normals of common vertices on the cube.
            e.  Take at least 4 snapshots of the scene with the light sources moving from one location to another between snapshots.
            f.  Draw all the snapshots in one window using different view ports.

        -   A shadow is a polygon that is “attached” to a geometry object (e.g., a cube and reflects the effect of a shadow caused by the light emitted on geometry object.” Add shadowing (shadows
that are due to the lighting) effects to the following objects from your scene:
            a.  The cube,
            b.  The sphere

*/
#include <gl/glut.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include <vector>
#include <cmath>

#define WIDTH 640
#define HEIGHT 640
#define PI 3.14159265358979323846

//Setting up window
void myInit();
void myDisplay();

//Interpreting keyboard strikes of "P,L,T,S,H,C, and U"
void myKeyboard(unsigned char theKey, int mouseX, int mouseY);

//Creating objects
void objectPoint();
void objectLine();
void objectTriangle();
void objectSquare();
void objectOctagon();
void objectCircle();
void objectCube();
void objectSphere();
//Rendering objects
void renderPoint();
void renderLine();
void renderTriangle();
void renderSquare();
void renderOctagon();
void renderCircle();
void renderCube_right();
void renderCube_top();
void renderCube_shadow();
void renderSphere_right();
void renderSphere_center();
void renderSphere_left();
//Shadow
void renderCube_shadow();
void renderSphere_shadow();
//Show all render
void showAllRender();

//Show all light
void draw_light_point_line();
void draw_light_triangle();
void draw_light_square();
void draw_light_octagon();
void draw_light_circle();
void draw_light_cube_right();
void draw_light_cube_top();
void draw_light_sphere_right();
void draw_light_sphere_center();
void draw_light_sphere_left();
void draw_light_sphere_shadow();

void showLight_Global();
void showLight_Ambient();
void showLight_Fixed();
void showLight_Directed();
void showLight_Spot();
void showAllLight();

void showLight_Global() {
    //lighting set up
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    //set lighting intensity and color
    GLfloat qaAmbientLight[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat qaDiffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

    //set light position
    GLfloat qaLightPosition[] = { .5, 0.5, 0.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
}
void showLight_Ambient() {
    //ambient light
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
    GLfloat lightAmbient[4] = { 0.7f, 0.4f, 0.4f, 1.0f };
    GLfloat viewLocal[] = { 0.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightAmbient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, viewLocal);
}
void showLight_Fixed() {
    //positioned light
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHT0);
    GLfloat lightPosition_0[4] = { -50.0f, 100.0f, 0.0f, 1.0f };
    GLfloat lightDiffusion_0[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat lightAmbient_0[4] = { 0.025f, 0.025f, 0.025f, 1.0f };
    GLfloat lightSpecular_0[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient_0);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition_0);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffusion_0);
    glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpecular_0);
}
void showLight_Directed() {
    //directed light
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHT2);
    GLfloat lightPosition_1[4] = { 120.0f, -130.f, 130.0f, 0.0f };
    GLfloat lightDiffusion_1[4] = { 0.25f, 0.25f, 0.25f, 1.0f };
    GLfloat lightAmbient_1[4] = { 0.0125f, 0.0125f, 0.0125f, 1.0f };
    GLfloat lightSpecular_1[4] = { 0.95f, 0.95f, 0.95f, 1.0f };
    glLightfv(GL_LIGHT2, GL_AMBIENT, lightAmbient_1);
    glLightfv(GL_LIGHT2, GL_POSITION, lightPosition_1);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, lightDiffusion_1);
    glLightfv(GL_LIGHT2, GL_SPECULAR, lightSpecular_1);
}
void showLight_Spot() {
    //spotlight
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHT3);
    GLfloat lightSpot[4] = { -1.0f, 1.0f, -8.0f };
    GLfloat lightDiffusion_2[4] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat lightAmbient_2[4] = { 0.05f, 0.05f, 0.05f, 1.0f };
    GLfloat lightSpecular_2[4] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat lightPosition_2[4] = { -120.0f, 130.0f, -130.0f, 0.0f };
    glLightfv(GL_LIGHT3, GL_POSITION, lightPosition_2);
    glLightfv(GL_LIGHT3, GL_AMBIENT, lightAmbient_2);
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, lightSpot);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, lightDiffusion_2);
    glLightfv(GL_LIGHT3, GL_SPECULAR, lightSpecular_2);
    glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 180.0);
    glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 2.0);
    glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 2.5);
    glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.5);
    glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.2);

    //glEnable(GL_COLOR_MATERIAL);
    //glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    //glEnable(GL_NORMALIZE);
    //glEnable(GL_CULL_FACE);
}
void showAllLight() {
    showLight_Spot();
    showLight_Directed();
    showLight_Fixed();
    showLight_Ambient();
    showLight_Global();
}

void draw_light_point_line() {
    //glClear(GL_COLOR_BUFFER_BIT);

    //Set material properties
    GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat qaColor[] = { 0.0, 7.0, 3.0, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaColor);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 10);
}
void draw_light_triangle() {
    //glClear(GL_COLOR_BUFFER_BIT);

    //Set material properties
    GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat qaColor[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaColor);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 20);
}
void draw_light_square() {
    //glClear(GL_COLOR_BUFFER_BIT);

    //Set material properties
    GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat qaColor[] = { 2.0, 1.0, 7.0, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaColor);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaColor);
    glMaterialf(GL_FRONT, GL_SHININESS, 30);
}
void draw_light_octagon() {
    //glClear(GL_COLOR_BUFFER_BIT);

    //Set material properties
    GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat qaColor[] = { 0.0, 1.0, 3.0, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaColor);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 40);
}
void draw_light_circle() {
    //glClear(GL_COLOR_BUFFER_BIT);

    //Set material properties
    GLfloat qaBlack[] = { 0.5, 0.1, 0.7, 1.0 };
    GLfloat qaColor[] = { 3.0, 1.0, 0.0, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.5, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaWhite);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaBlack);
    glMaterialf(GL_FRONT, GL_SHININESS, 50);
}
void draw_light_cube_right() {
    //glClear(GL_COLOR_BUFFER_BIT);

    //Set material properties
    GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat qaColor[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat qaWhite[] = { 1.5, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 60);
}
void draw_light_cube_top() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat qaBlack[] = { 0.5, -0.1, 0.1, 1.0 };
    GLfloat qaColor[] = { 1.0, 1.0, 0.0, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 70);
}
void draw_light_sphere_right() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat qaBlack[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat qaColor[] = { 1.0, 0.0, 1.0, 1.0 };
    GLfloat qaWhite[] = { 1.0, -1.0, 1.0, 1.0 };
    glMaterialfv(GL_BACK, GL_AMBIENT, qaColor);
    glMaterialfv(GL_BACK, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_BACK, GL_SPECULAR, qaWhite);
    glMaterialf(GL_BACK, GL_SHININESS, 100);
}
void draw_light_sphere_center() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat qaBlack[] = { 0.2, -0.4, 0.9, 1.0 };
    GLfloat qaColor[] = { 1.0, 0.0, 1.0, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 90);
}
void draw_light_sphere_left() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    showLight_Ambient();
    GLfloat qaBlack[] = { -3.3, -0.5, -0.5, 1.0 };
    GLfloat qaColor[] = { 4.0, 1.6, 5.0, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 80);
    glEnable(GL_NORMALIZE);

}
void draw_light_sphere_shadow() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat qaBlack[] = { -0.15, -0.15, -0.15, 1.0 };
    GLfloat qaColor[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat qaWhite[] = { -3, -3, -3, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 90);
}
//---------------------------------------------------
//---------------------------------------------------
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
void objectOctagon() {
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
}
void objectCircle() {
    const float numEdges = 40;
    const float radius = 1.5f;
    const float angle = PI * 2.f / numEdges;
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
void objectSphere() {
    glColor3f(1.0f, 0.0f, 0.0f);
    int  color = 0;
    //float PI = atan(1.0) * 4.0;
    float a, b, x, y, z;
    float da = 6.0, db = 6.0;
    float radius = 1.0;

    for (a = -90.0; a + da <= 90.0; a += da) {
        glBegin(GL_QUAD_STRIP);

        for (b = 0.0; b <= 360.0; b += db) {
            //if (color) {
            //    //glIndexi(RED);
            //    glColor3f(1, 0, 0);
            //}
            //else {
            //    //glIndexi(WHITE);
            //    glColor3f(1, 1, 1);
                //{
            x = radius * cos(b * PI / 180) * cos(a * PI / 180);
            y = radius * sin(b * PI / 180) * cos(a * PI / 180);
            z = radius * sin(a * PI / 180);
            glVertex3f(x, y, z);
            x = radius * cos(b * PI / 180) * cos((a + da) * PI / 180);
            y = radius * sin(b * PI / 180) * cos((a + da) * PI / 180);
            z = radius * sin((a + da) * PI / 180);
            glVertex3f(x, y, z);
            color = 1 - color;
        }
        glEnd();
    }
    glFlush();
}
//---------------------------------------------------
//---------------------------------------------------
void renderPoint() {
    draw_light_point_line();

    glPushMatrix();
    glTranslatef(6, 0, 0);
    objectPoint();
    glPopMatrix();
}
void renderLine() {
    glPushMatrix();
    glTranslatef(2, -6, 0);
    glRotatef(90, 0, 0, 1);
    glScalef(3.0, 3.0, 3.0);
    objectLine();
    glPopMatrix();
}
void renderTriangle() {
    draw_light_triangle();

    glPushMatrix();
    glTranslatef(5, 5, 0);
    //glRotatef(75.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.60, 0.60, 0.60);
    objectTriangle();
    glPopMatrix();
}
void renderSquare() {
    draw_light_square();

    glPushMatrix();
    glTranslatef(-6, 0, 0);
    glRotatef(100.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.45, 0.45, 0.45);
    objectSquare();
    glPopMatrix();
}
void renderOctagon() {
    draw_light_octagon();

    glPushMatrix();
    glTranslatef(-5, 4, 0);
    glRotatef(125.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.15, 0.15, 0.15);
    objectOctagon();
    glPopMatrix();
}
void renderCircle() {
    draw_light_circle();

    glPushMatrix();
    glTranslatef(-5, -5, 0);
    glScalef(0.3, 0.3, 0.3);
    glRotatef(155.0f, 0.0f, 0.0f, 1.0f);
    objectCircle();
    glPopMatrix();
}
void renderCube_right() {
    draw_light_cube_right();

    glPushMatrix();
    glTranslatef(6, -2, 0);
    glScalef(0.6, 0.6, 0.6);
    objectCube();
    glPopMatrix();
}
void renderCube_top() {
    draw_light_cube_top();

    glPushMatrix();
    //gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);
    glTranslatef(0, 6, 0);
    glScalef(0.5, 0.5, 0.5);
    glRotatef(45.0f, 1.0f, 1.0f, 1.0f);
    objectCube();
    glPopMatrix();

}
void renderSphere_right() {
    draw_light_sphere_right();

    glPushMatrix();
    glTranslatef(3, 0, 0);
    objectSphere();
    glPopMatrix();
}
void renderSphere_center() {
    draw_light_sphere_center();

    glPushMatrix();
    glRotatef(60, 60, 40, 0);
    objectSphere();
    glPopMatrix();
}
void renderSphere_left() {
    draw_light_sphere_left();

    glPushMatrix();
    glTranslatef(-3, 0, 0);
    glRotatef(-60, 30, 20, 0);
    objectSphere();
    glPopMatrix();
}
void renderSphere_shadow() {
    draw_light_sphere_shadow();
    //center sphere
    glPushMatrix();
    glTranslatef(0, -1, 0);
    glColor3f(0, 0, 0);
    //glRotatef(180, 45, 90, 0);
    objectSphere();
    glPopMatrix();

    //left sphere
    glPushMatrix();
    glTranslatef(-4, 0, 0);
    glColor3f(0, 0, 0);
    //glRotatef(180, 45, 90, 0);
    objectSphere();
    glPopMatrix();

    //right sphere
    glPushMatrix();
    glTranslatef(2, -1, 0);
    glColor3f(0, 0, 0);
    //glRotatef(200, 60, 90, 0);
    objectSphere();
    glPopMatrix();
}

void showAllRender() {
    showAllLight();

    //
    //objectPoint();
    //objectLine();
    //objectTriangle();
    //objectSquare();
    //objectOctagon();
    //objectCube();
    //objectCircle();
    //objectSphere();
    // 
    renderSphere_shadow();
    renderPoint();
    renderLine();
    renderTriangle();
    renderSquare();
    renderOctagon();
    renderCircle();
    renderCube_right();
    renderCube_top();
    renderSphere_right();
    renderSphere_center();
    renderSphere_left();
}
//---------------------------------------------------
//---------------------------------------------------
void myKeyboard(unsigned char theKey, int mouseX, int mouseY) {

    //Key Q - Quit
    if (theKey == 'Q' || theKey == 'q') {
        exit(-1);
    }
}

//initialize code OpenGl
void myInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(4.0);
    glLineWidth(4.0);

    //glLoadIdentity();
    glViewport(16, 16, WIDTH, HEIGHT);       //viewport glViewport(xvmin, yvmin, widgth, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //glOrtho(left, right, bottom, top, near, far) double value
    glOrtho(-8, 8, -8, 8, -8, 8);
    gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);

}

void myDisplay(void) {
    showAllRender();
    glutKeyboardFunc(myKeyboard);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);  // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);   //set display mode

    //task: window should not be in the "origin" of the screen
    glutInitWindowSize(1024, 1024);     //set window size
    glutInitWindowPosition(300, 300);

    //start the screen window
    glutCreateWindow("Assignment_S3_HieuHuynh - Manipulate Light Meshes - Type Q or q to quit");
    glutDisplayFunc(myDisplay);     //register redraw function
    myInit();
    glutMainLoop();                  //go into a perpetual loop

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

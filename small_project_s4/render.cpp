#include "render.h"
#include "object.h"
#include "texture.h"
#include "ppmRead.h"

void renderPoint() {
    drawLight_point_line();

    glPushMatrix();
    glTranslated(-5, 1, -2);
    objectPoint();
    glPopMatrix();
}
void renderLine() {
    glPushMatrix();
    glTranslated(6, -4, 0);
    glRotatef(100, 0, 0, 1);
    glScaled(3.0, 3.0, 3.0);
    objectLine();
    glPopMatrix();
}
void renderTriangle() {
    //drawLight_triangle();

    glPushMatrix();
    glTranslated(3, 5, -2);
    //glRotatef(75.0f, 0.0f, 0.0f, 1.0f);
    glScaled(1.1, 1.1, 1.1);
    objectTriangle();
    glPopMatrix();
}
void renderSquare() {
    //drawLight_square();

    glPushMatrix();
    glTranslated(0, 5, 6);
    glRotatef(100.0f, 0.0f, 0.0f, 1.0f);
    glScaled(1, 1, 1);
    objectSquare();
    glPopMatrix();
}
void renderHexagon() {
    drawLight_octagon();

    glPushMatrix();
    glTranslated(-4, 4, 2);
    glRotatef(125.0f, 0.0f, 0.0f, 1.0f);
    glScaled(1.2, 1.2, 1.2);
    objectHexagon();
    glPopMatrix();
}
void renderCircle() {
    //drawLight_circle();

    glPushMatrix();
    glTranslated(3, 1, -5);
    glScaled(1.3f, 1.3f, 1.3f);
    glRotatef(155.0f, 0.0f, 0.0f, 1.0f);
    objectCircle();
    glPopMatrix();
}
void renderCube_right() {
    drawLight_cube_right();

    glPushMatrix();
    glTranslated(7, 2, 2);
    glScaled(0.7, 0.7, 0.7);
    objectCube();
    glPopMatrix();
}
void renderCube_top() {
    drawLight_cube_top();

    glPushMatrix();
    //gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);
    glTranslated(-3, 3, -3);
    glScaled(0.9, 0.9, 0.9);
    glRotatef(45.0f, 1.0f, 1.0f, 1.0f);
    objectCube();
    glPopMatrix();

}
void renderSphere_center() {
    drawLight_sphere_center();

    glPushMatrix();
    glScaled(1.6, 1.6, 1.6);
    glRotatef(60, 60, 40, 0);
    objectSphere();
    glPopMatrix();
}
void renderCylinder() {
    glPushMatrix();
    glTranslated(-2, -2, 4);
    glScaled(1.2, 1.2, 1.2);
    glRotatef(90, 1, 1, 1);
    objectCylinder();
    glPopMatrix();
}
void renderShadow_S4() {
    drawLight_shadow();
    //top cube 
    glPushMatrix();
    glTranslated(-5, 3, -2);
    glScaled(0.9, 0.9, 0.9);
    glRotatef(45.0f, 1.0f, 1.0f, 1.0f);
    glColor3f(0, 0, 0);
    //glRotatef(180, 45, 90, 0);
    objectSquare();
    glPopMatrix();

    //right cube
    glPushMatrix();
    glTranslated(2, -2, 0);
    glScaled(0.7, 0.7, 0.7);
    glColor3f(0, 0, 0);
    //glRotatef(180, 45, 90, 0);
    objectSquare();
    glPopMatrix();

    //center sphere
    glPushMatrix();
    glScaled(1.7, 1.7, 1.7);
    glRotatef(60, 60, 40, 0);
    glColor3f(0, 0, 0);
    //glRotatef(180, 45, 90, 0);
    objectCircle();
    glPopMatrix();

    //center sphere
    glPushMatrix();
    glTranslated(-4, 0, 0);
    glScaled(0.7, 0.7, 0.7);
    glRotatef(60, 0, 1, 0);
    glColor3f(0, 0, 0);
    //glRotatef(180, 45, 90, 0);
    objectCircle();
    glPopMatrix();
}
void renderWall() {
    //drawLight_wall();
    glShadeModel(GL_SMOOTH);
    glPushMatrix();
    glTranslated(1, 1, 1);
    glScaled(6, 6, 6);
    glRotated(50, 0, 1, 0);
    glRotated(-35, 1, 0, 0);

    objectWall();
    glPopMatrix();
}
void renderFloor() {
    //drawLight_wall();
    glShadeModel(GL_SMOOTH);
    glPushMatrix();
    glTranslated(1, 1, 1);
    glScaled(6, 6, 6);
    glRotated(50, 0, 1, 0);
    glRotated(-35, 1, 0, 0);

    objectFloor();
    glPopMatrix();
}
void renderCeiling() {
    //drawLight_wall();
    glShadeModel(GL_SMOOTH);
    glPushMatrix();
    glTranslated(1, 1, 1);
    glScaled(6, 6, 6);
    glRotated(50, 0, 1, 0);
    glRotated(-35, 1, 0, 0);

    objectCeiling();
    glPopMatrix();
}


void showAllRender() {
    //renderWall();
    //renderFloor();
    //renderCeiling();
    renderShadow_S4();

    renderPoint();
    renderLine();
    //renderTriangle();
    //renderSquare();
    //renderHexagon();
    //renderCircle();
    //renderCube_right();
    //renderCube_top();
    //renderSphere_center();
    //renderCylinder();

    displaySquare();
    displayTriangle();
    displayHexagon();
    displayCircle();
    displayCubeRight();
    displayCubeTop();
    displaySphere();
    displayCylinder();

    //displayRoom();

    displayWall_PPM();
    displayFloor_PPM();
    displayCeiling_PPM();
}
#include "drawLight.h"

void drawLight_point_line() {
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
void drawLight_triangle() {
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
void drawLight_square() {
    //glClear(GL_COLOR_BUFFER_BIT);

    //Set material properties
    GLfloat qaBlack[] = { 0.0, 0.0, 1.0, 1.0 };
    GLfloat qaColor[] = { 2.0, 0.0, 0.5, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaColor);
    glMaterialf(GL_FRONT, GL_SHININESS, 30);
}
void drawLight_octagon() {
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
void drawLight_circle() {
    //glClear(GL_COLOR_BUFFER_BIT);

    //Set material properties
    GLfloat qaBlack[] = { 0.5, 0.1, 0.7, 1.0 };
    GLfloat qaColor[] = { 3.0, 1.0, 0.0, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.5, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 50);
}
void drawLight_cube_right() {
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
void drawLight_cube_top() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat qaBlack[] = { 0.5, -0.1, 0.1, 1.0 };
    GLfloat qaColor[] = { 1.0, 1.0, 0.0, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 70);
}
void drawLight_sphere_center() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat qaBlack[] = { 0.2, -0.4, 0.9, 1.0 };
    GLfloat qaColor[] = { 1.0, 0.0, 1.0, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 90);
}
void drawLight_cylinder_body() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat qaBlack[] = { 0, 0.2, 0.6, 0 };
    GLfloat qaColor[] = { 0.0, 0.2, 1.0, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 10);
}
void drawLight_cylinder_top() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat qaBlack[] = { 0.5, -0.1, 0.1, 1.0 };
    GLfloat qaColor[] = { 1.0, 1.0, 0.0, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 70);
}
void drawLight_cylinder_bottom() {
    //glClear(GL_COLOR_BUFFER_BIT);

    //Set material properties
    GLfloat qaBlack[] = { 0.0, -0.1, 0.0, 1.0 };
    GLfloat qaColor[] = { 1.5, 0.0, 0.5, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 90);
}
void drawLight_wall_left() {
    //glClear(GL_COLOR_BUFFER_BIT);
    //Set material properties
    GLfloat qaBlack[] = { 0.0, 0.0, -0.2, 1.0 };
    GLfloat qaColor[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 100);
}
void drawLight_wall_floor() {
    //glClear(GL_COLOR_BUFFER_BIT);
    //Set material properties
    GLfloat qaBlack[] = { 0.1, -0.1, 0.1, 1.0 };
    GLfloat qaColor[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat qaWhite[] = { 1.5, 1.2, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 90);
}
void drawLight_wall_back() {
    //glClear(GL_COLOR_BUFFER_BIT);
    //Set material properties
    GLfloat qaBlack[] = { -0.1, -0.2, -0.0, 1.0 };
    GLfloat qaColor[] = { 0.0, 1.0, 0.0, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 10);
}
void drawLight_shadow() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat qaBlack[] = { -0.15, -0.15, -0.15, 1.0 };
    GLfloat qaColor[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat qaWhite[] = { -3, -3, -3, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 90);
}
void drawLight_wall() {
    //glClear(GL_COLOR_BUFFER_BIT);

    //Set material properties
    GLfloat qaBlack[] = { 0, 0, 0, 1 };
    GLfloat qaColor[] = { 1, 1, 1, 1 };
    GLfloat qaWhite[] = { 1, 1, 1, 1 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 30);
}

void drawLight_curve() {
    GLfloat qaBlack[] = { 0.0, 0.0, 1.0, 1.0 };
    GLfloat qaColor[] = { 10, 1.0, 1.0, 1.0 };
    GLfloat qaWhite[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, qaBlack);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, qaColor);
    glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 30);
}
#include "object.h"
#include "drawLight.h"
#include "texture.h"

int length = 2;
int size = 1.3;

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
    //glColor3f(0.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);
    glTexCoord2f(0.5, 0.5); glVertex3f(1.0, 1.0, 0.0);

    glEnd();
    glFlush();
}
void objectSquare() {

    glBegin(GL_QUADS);
    //glColor3f(0.0f, 1.0f, 0.0f);

    glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -1.0, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-2.0, 1.0, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(0.0, 1.0, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(0.0, -1.0, 0.0);

    glEnd();
    glFlush();
}

void objectHexagon() {
    //right triangle
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.5, 0.0, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-0.75, -1.3, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(-0.75, 1.3, 0.0);
    glEnd();

    //left triangle
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0); glVertex3f(0.75, -1.3, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(1.5, 0.0, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(0.75, 1.3, 0.0);
    glEnd();

    //middle square
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0); glVertex3f(-0.75, -1.3, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(0.75, -1.3, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(0.75, 1.3, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(-0.75, 1.3, 0.0);
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
        glTexCoord2f(0.5, 0.5);     glVertex2f(0.0, 0.0);
        glTexCoord2f(oldX, oldY);   glVertex2f(oldX, oldY);
        glTexCoord2f(newX, newY);   glVertex2f(newX, newY);

        oldX = newX;
        oldY = newY;
    }

    glEnd();
    glFlush();
}
void objectCube() {
   
    glBegin(GL_QUADS);
    // Front Face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    // Back Face
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
    // Top Face
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
    // Bottom Face
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    // Right face
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    // Left Face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();
    //glutSwapBuffers(); // Swap front and back buffers (double buffered mode)  
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
            glTexCoord3f(x, y, z);
            glVertex3f(x, y, z);
            x = radius * cos(b * PI / 180) * cos((a + da) * PI / 180);
            y = radius * sin(b * PI / 180) * cos((a + da) * PI / 180);
            z = radius * sin((a + da) * PI / 180);
            glTexCoord3f(x, y, z);
            glVertex3f(x, y, z);
            color = 1 - color;
        }
        glEnd();
    }
    glFlush();
}
void objectCylinder() {
    /*
    n - number of sides
    arg - starting angle
    mult - multiplying sides to incrase their length
    v - cylinder height
    */
    int n = 40;
    int arg = 0;
    float mult = 1;
    float v = 3.0;


    // DumbProof Double Check :)
    if (arg < 0)
        arg = 0;


    // Cylinder Top
    drawLight_cylinder_top();
    glBegin(GL_POLYGON);
    glColor4f(1.0, 0.0, 0.0, 1.0);
    for (int i = arg; i <= (360 + arg); i += (360 / n)) {
        float a = i * PI / 180; // degrees to radians
        glTexCoord2f(mult * cos(a), mult * sin(a));
        glVertex3f(mult * cos(a), mult * sin(a), 0.0);
    }
    glEnd();



    // Cylinder "Cover"
    drawLight_cylinder_body();
    glBegin(GL_QUAD_STRIP);
    glColor4f(1.0, 1.0, 0.0, 1.0);
    for (int i = arg; i < 480; i += (360 / n)) {
        float a = i * PI / 180; // degrees to radians
        glTexCoord2f(mult * cos(a), mult * sin(a));
        glVertex3f(mult * cos(a), mult * sin(a), 0.0);
        glTexCoord2f(mult * cos(a), mult * sin(a));
        glVertex3f(mult * cos(a), mult * sin(a), v);
    }
    glEnd();

    // Cylinder Bottom
    drawLight_cylinder_bottom();
    glBegin(GL_POLYGON);
    glColor4f(0.0, 0.0, 1.0, 1.0);
    for (int i = arg; i <= (360 + arg); i += (360 / n)) {
        float a = i * PI / 180; // degrees to radians
        glTexCoord2f(mult * cos(a), mult * sin(a));
        glVertex3f(mult * cos(a), mult * sin(a), v);
    }
    glEnd();


}
void objectWall() {

  
    glBegin(GL_QUADS);
    //Wall side = left
    drawLight_wall_left();
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-length, length, 1);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-length, -length, 1);
    //connect point bottom
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-size, -size, -1);
    //connect point top
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-size, size, -1);


    //Wall side = front
    //glVertex3f(-1, -1, 1);
    //glVertex3f(1, -1, 1);
    //glVertex3f(1, 1, 1);
    //glVertex3f(-1, 1, 1);

    drawLight_wall_back();
    //Wall side = back
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, -size, -1);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(size, -size, -1);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(size, size, -1);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, size, -1);

    //Wall side = right
    drawLight_wall_left();
    glTexCoord2f(0.0f, 1.0f); glVertex3f(length, length, 1);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(length, -length, 1);
    //connect left point
    glTexCoord2f(1.0f, 0.0f); glVertex3f(size, -size, -1);
    //connect right point
    glTexCoord2f(1.0f, 1.0f); glVertex3f(size, size, -1);


    glEnd();
}

void objectFloor() {
    glBegin(GL_QUADS);

    drawLight_wall_floor();
    /* Floor */
    //connect left point
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-size, -size, -1);
    //connect right point
    glTexCoord2f(0.0f, 1.0f); glVertex3f(size, -size, -1);
    //far right point
    glTexCoord2f(0.0f, 0.0f); glVertex3f(length, -length, 1);
    //far left point
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-length, -length, 1);

    glEnd();

}
void objectCeiling() {
    glBegin(GL_QUADS);

    drawLight_wall_floor();
    /* Ceiling */
    //connect left point 
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-size, size, -1);
    //connect right point
    glTexCoord2f(0.0f, 1.0f); glVertex3f(size, size, -1);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(length, length, 1);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-length, length, 1);

    glEnd();
}

void draw(GLfloat ctrlpoints[4][3])
{
    glShadeModel(GL_FLAT);
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4,
        &ctrlpoints[0][0]);

    glEnable(GL_MAP1_VERTEX_3);

    // Fill the color
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);

    int i = 0;

    // Find the coordinates
    for (i = 0; i <= 30; i++)
        glEvalCoord1f((GLfloat)i / 30.0);

    glEnd();
    glFlush();
}

//implement Bezier Curves
void objectCurve_1() {
    //std::cout << "Reading this curve 1... " << std::endl;
    GLfloat ctrlpoints[4][3]
        = { { 0, 3.6, 0.0 },
            { 0, 3.4, 0.0 },
            { 0, 3.2, 0.0 },
            { 0, 3.0, 0.0 }, };
    draw(ctrlpoints);

    GLfloat ctrlpoints1[4][3]
        = { { 0, 3.5, 0.0 },
            { 2, 4, 0.0 },
            { 3, 3, 0.0 },
            { 3, 2, 0.0 } };
    draw(ctrlpoints1);

    GLfloat ctrlpoints2[4][3]
        = { { 3, 2, 0.0 },
            { 3, 1, 0.0 },
            { 2, 0, 0.0 },
            { 0, 0, 0.0 } };
    draw(ctrlpoints2);

    GLfloat ctrlpoints3[4][3]
        = { { 0, 0, 0.0 },
            { 2, 0, 0.0 },
            { 3, -1, 0.0 },
            { 3, -2, 0.0 } };
    draw(ctrlpoints3);

    GLfloat ctrlpoints4[4][3]
        = { { 3, -2, 0.0 },
            { 3, -3, 0.0 },
            { 2, -4, 0.0 },
            { 0, -3.5, 0.0 } };
    draw(ctrlpoints4);

    GLfloat ctrlpoints5[4][3]
        = { { 0, -3.6, 0.0 },
            { 0, -3.4, 0.0 },
            { 0, -3.2, 0.0 }, 
            { 0, -3.0, 0.0 }, };
    draw(ctrlpoints5);
}
void objectCurve_2() {
    //std::cout << "Reading this curve 1... " << std::endl;
    GLfloat ctrlpoints[4][3]
        = { { 0, 0, 0.0 },
            { 2, 0, 0.0 },
            { 3, 1, 0.0 },
            { 4, 2, 0.0 } };
    draw(ctrlpoints);

    GLfloat ctrlpoints1[4][3]
        = { { 0, 0, 0.0 },
            { 2, 0, 0.0 },
            { 3, -1, 0.0 },
            { 4, -2, 0.0 } };
    draw(ctrlpoints1);
}

void objectCurve_2_2() {

}
void objectCurve_3() {
    GLfloat ctrlpoints[4][3]
        = { { 1.0, 0, 0.0 },
            { 1.5, 0.75, 0.0 },
            { 2, 1.55, 0.0 },
            { 1.00, 2.00, 0.0 } };
    draw(ctrlpoints);

    GLfloat ctrlpoints1[4][3]
        = { { 1.00, 2.00, 0.0 },
            { -2.00, 2.00, 0.0 },
            { -3.00, -2.00, 0.0 },
            { -1.50, -3.00, 0.0 } };
    draw(ctrlpoints1);

    GLfloat ctrlpoints3[4][3]
        = { { -1.50, -3.00, 0.0 },
            { 1, -5.00, 0.0 },
            { 4, 3, 0.0 },
            { 7, 5, 0.0 } };
    draw(ctrlpoints3);

    GLfloat ctrlpoints4[4][3]
        = { { 7, 5, 0.0 },
            { 9, 6, 0.0 },
            { 11, 4, 0.0 },
            { 8, 2, 0.0 } };
    draw(ctrlpoints4);
}

void objectCurve_3_2() {

}
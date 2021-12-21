/*
   Name:           Hieu Huynh
   Project:        S5
   Description:    This program manipulate texture

   Requirement:     
        - Add curves and surfaces
       

*/
#pragma comment (lib, "opengl32.lib")


#include "object.h"
#include "drawLight.h"
#include "render.h"
#include "showLight.h"
#include "texture.h"
#include "ppmRead.h"
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"


int viewportWitdh = 512;
int viewportHeight = 512;
int windowSize = 1024;
int windowPosition = 300;

//Setting up window
void myInit();
void myDisplay();
static void reshape(int w, int h);
void idle();

void makeCheckImage(void);
//void displaySquare();

//Interpreting keyboard strikes of "P,L,T,S,H,C, and U"
void myKeyboard(unsigned char theKey, int mouseX, int mouseY);

void myKeyboard(unsigned char theKey, int mouseX, int mouseY) {

    //Key Q - Quit
    if (theKey == 'Q' || theKey == 'q') {
        exit(-1);
    }
}

//initialize code OpenGl
void myInit() {


}
static void reshape(int w, int h) {

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(8.0);
    glLineWidth(8.0);
   
    //viewport glViewport(xvmin, yvmin, widgth, height);
    glViewport(viewportWitdh/2, viewportWitdh/2, viewportWitdh, viewportHeight);
    //glViewport(16, 16, viewportWitdh, viewportHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    int xleftRight = 8;
    int ybottomTop = 8;
    int znearFar = 12;
    ////glOrtho(xleft, xright, ybottom, ytop, znear, zfar);
    glOrtho(-xleftRight, xleftRight, -ybottomTop, ybottomTop, -znearFar, znearFar);

    //gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);
    //gluLookAt(0.6, 0.6, 0.5, 0, 0, 0, 0, 1, 0);
    gluLookAt(0.6, 0.6, 0.5, 0, 0, 0, 0, 1, 0);
}
void myDisplay(void) {
    std::cerr << "\ndisplay callback\n" << std::endl;

    //glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    showLight_Directed_S4();
    moveLight();


    glutSwapBuffers();
    glDisable(GL_TEXTURE_2D);
}

/* Gets called whenever computer doesn't have anything else to do */
void idle()
{
    std::cerr << "\nidle callback\n" << std::endl;
    myDisplay();     // call display callback, useful for animation
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);  // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);   //set display mode
    //task: window should not be in the "origin" of the screen
    glutInitWindowSize(windowSize, windowSize);     //set window size
    glutInitWindowPosition(windowPosition, windowPosition);
    //start the screen window
    glutCreateWindow("Project_S5_HieuHuynh - Add curves and surfaces - Type Q or q to quit");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    myInit();
    glutDisplayFunc(myDisplay);     //register redraw function
    glutReshapeFunc(reshape);
    //glutIdleFunc(idle);       // for animation
    glutKeyboardFunc(myKeyboard);
    glutMainLoop();                  //go into a perpetual loop
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

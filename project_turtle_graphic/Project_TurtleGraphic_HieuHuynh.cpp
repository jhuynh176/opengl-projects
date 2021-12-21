/*
   Name:           Hieu Huynh
   Project:        Turtle  Graphic
   Description:    Developing an app, Turtle Graphic.

   Requirement:
        - Move forward by a given distance from its current location
        - Turn by alpha degree
        - PenUp
        - PenDown

*/
#include <gl/glut.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//Setting up window
void myInit();
void myDisplay();

//Reseting screen after each keystrikes
void resetScreen();

//Manipulating objects
void objectTurtle();
void moveTurtle();
void penUp();
void penDown();
void getDirection();
void drawLine();
void debugInit();
void debugForward();
void debugTurn();

//Interpreting keyboard strikes of "P,L,T,S,H,C, and U"
void myKeyboard(unsigned char theKey, int mouseX, int mouseY);
void clear(void);

#define PI 3.1415926535

//Global variables
double radAngleToAngle = 0.0;
double angle = 90.0;         //turtle is facing north

float r = 1.0;
float g = 1.0;
float b = 1.0;

//Convert to radian = angle * pi/180
double radian = 0.0;
double cosine = cos(90 * PI / 180);
double sine = sin(90 * PI / 180);

typedef struct { float x, y; } graph2D;
graph2D nex = { 0.0, 0.0 };
graph2D old = { 0.0, 0.0 };
graph2D direction = { cosine, sine };

int windowXmin = -200;
int windowXmax = 200;
int windowYmin = -200;
int windowYmax = 200;

//User input value
double userValue;
//User input command
string userCommand;
//User quit flag
bool running = true;

//initialize code OpenGl
void myInit() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(windowXmin, windowXmax, windowYmin, windowYmax);
    glMatrixMode(GL_MODELVIEW);

    glPointSize(12.0);
    glLineWidth(4.0);

}

void myDisplay(void) {
    //Initial turtle location
    objectTurtle();     //calling time = 1
    glutKeyboardFunc(myKeyboard);

    debugInit();
   
    do {
        moveTurtle();
    } while (running == true);
}

void moveTurtle() {

    cout << "\nEnter your command: ";
    cin >> userCommand;

    //If enter q or Q, quit
    if (userCommand == "q" || userCommand == "Q") {
        running = false;
        exit(-1);
    }
    else {
        cin >> userValue;

        if (userCommand == "forward" || userCommand == "Forward") {
            debugForward();
            drawLine();
            objectTurtle(); //calling time = 2

            old.x = nex.x;
            old.y = nex.y;

            glFlush();
            glPopMatrix();
            penDown();
        }

        else if (userCommand == "turn" || userCommand == "Turn") {
            debugTurn();
            getDirection();
            penDown();
        }

        else {
            //Debug incorrect command
            cout << "\tInfo: Incorrect Input \t-->\t " << userCommand << endl;
        }
    }

}

void getDirection() {
    if (angle > 360) {
        angle -= 360;
    }
    radAngleToAngle = angle * PI / 180;

    cosine = cos(radAngleToAngle);
    sine = sin(radAngleToAngle);

    direction.x = cosine;
    direction.y = sine;
}
void drawLine() {
    glPushMatrix();
    glBegin(GL_LINE_LOOP);
    glColor3f(r, g, b);
    glVertex2f(old.x, old.y);
    glVertex2f(nex.x, nex.y);
    glEnd();
}

void debugInit() {
    cout << "Tutorial: " << endl;
    cout << "    To quit the program, please enter: q or Q" << endl;
    cout << "    To move turtle, please enter your command in format (user_command command_value). Example: forward 10" << endl;
    cout << "\n\tInfo: Default Coordinate \t-->\t(" << old.x << ", " << old.y << ")" << endl;
    cout << "\tInfo: Default Direction \t-->\tNorth" << endl;
    cout << "\tInfo: Default Angle \t\t-->\t" << angle << " Degree" << endl;
    cout << "\nProgram start..." << endl;
}

void debugForward() {
    nex.x = (userValue * direction.x) + old.x;
    nex.y = (userValue * direction.y) + old.y;

    //Debug correct command
    cout << "\tInfo: Correct Input.\n\t---------" << endl;

    //Debug for command forward
    cout << "\tInfo: User input \t\t-->\tMove Straight " << userValue << " Units" << endl;

    //Debug angle
    cout << "\tInfo: Angle \t\t\t-->\t" << angle << " Degree" << endl;
    cout << "\tInfo: Direction \t\t-->\tCos = " << cosine << " | Sin = " << sine << endl;
    //cout << "\tInfo: Trigonometry\t-->\tDi-x = " << direction.x << " | Di-y = " << direction.y << endl;
    cout << "\tInfo: Old Coordinate \t\t-->\t(" << old.x << ", " << old.y << ")" << endl;
    cout << "\tInfo: New Coordinate \t\t-->\t(" << nex.x << ", " << nex.y << ")" << endl;
}

void debugTurn() {
    //Debug correct command
    cout << "\tInfo: Correct Input.\n\t---------" << endl;

    //Debug for command turn
    cout << "\tInfo: User input \t\t-->\tTurn " << angle << " Degree." << endl;

    //positive angle = turn left
    if (userValue > 0) {
        cout << "\tInfo: Deg = Positive \t\t-->\tCommand: Turning left." << endl;
        r = r / 3.0;
        b = (1.5 + b) / 3.0;
        glColor3f(r, g, b);
    }
    //negatige angle = turn right
    else if (userValue < 0) {
        cout << "\tInfo: Deg = Negative  \t\t-->\tCommand: Turning right." << endl;
        r = (1.5 + r) / 3.0;
        b = 3.0 * b;
        glColor3f(r, g, b);
    }
    else {
        cout << "\tInfo: Deg = Zero \t\t-->\tCommand: Go Straight." << endl;
    }

    cout << "\tInfo: Change in Angle \t\t-->\t" << angle << " Degree -> ";
    angle += userValue;
    cout << angle << " Degree." << endl;
    cout << "\tInfo: Direction \t\t-->\tCos = " << cosine << " | Sin = " << sine << endl;
}
//Turtle 8x8 vertex
void objectTurtle() {
    //Turtle body
    glPointSize(20.0);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(nex.x, nex.y);
    glEnd();

    glFlush();
    glutIdleFunc(myDisplay);

}

void penDown() {
    glutIdleFunc(myDisplay);
}

void myKeyboard(unsigned char theKey, int mouseX, int mouseY) {

    //Key Q - Quit
    if (theKey == 'Q' || theKey == 'q') {
        exit(-1);
    }
}

void clear(void) {
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);  // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);   //set display mode
    glutInitWindowSize(1024, 1024);

    //task: window should not be in the "origin" of the screen
    glutInitWindowPosition(960, 0);

    //start the screen window
    glutCreateWindow("Project - Tutle Graphic - Hieu Huynh - Type Q or q to quit");
    glutIdleFunc(myDisplay);
    glutDisplayFunc(clear);     //register redraw function
    myInit();
    glutMainLoop();                  //go into a perpetual loop

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

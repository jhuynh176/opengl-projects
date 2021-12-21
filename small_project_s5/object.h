#pragma comment (lib, "opengl32.lib")
#pragma warning(disable:4996)

#ifndef OBJECT_H
#define _CRT_SECURE_NO_DEPRECATE

#define PI 3.14159265358979323846

#include <Windows.h>
#include <GL/GLU.h>
#include <GL/GL.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <cmath>
#include <cctype>
#include <string>

//the function of object is to create the items, shapes
void objectPoint();
void objectLine();
void objectTriangle();
void objectSquare();
void objectHexagon();
void objectCircle();
void objectCube();
void objectSphere();
void objectCylinder();

void objectWall();
void objectFloor();
void objectCeiling();

void draw(GLfloat ctrlpoints[4][3]);
void objectCurve_1();
void objectCurve_2();
void objectCurve_2_2();
void objectCurve_3();
void objectCurve_3_2();


#endif // !OBJECT_H
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


#endif // !OBJECT_H
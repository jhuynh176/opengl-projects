#pragma comment (lib, "opengl32.lib")

#ifndef RENDER_H


#include "object.h"
#include "drawLight.h"

//the function of render is to manipulate ojbect: translate, scale, and rotate
void renderPoint();
void renderLine();
void renderTriangle();
void renderSquare();
void renderHexagon();
void renderCircle();
void renderCube_right();
void renderCube_top();
void renderSphere_center();
void renderCylinder();
void renderShadow_S4();

void renderWall();
void renderFloor();
void renderCeiling();

void showAllRender();

#endif // !RENDER_H
#pragma once
#ifndef TEXTURE_H

#include "object.h"
#include "render.h"
#include "ppmRead.h"


//making computer generated image
void makeCheckImage(void);

//check texture option
void checkTextureName(std::string textureOptions);
//check color option for texture
void checkColorSet(std::string colorSet);

//the function of display is to create computer texture-mapped rendered-object and display it
void displayTriangle();
void displaySquare();
void displayHexagon();
void displayCircle();
void displayCubeRight();
void displayCubeTop();
void displaySphere();
void displayCylinder();
void displayRoom();

//the function of displayPPM is to create ppm texture-mapped rendered-object and display it
void displayWall_PPM();
void displayFloor_PPM();
void displayCeiling_PPM();

#endif // !TEXTURE_H

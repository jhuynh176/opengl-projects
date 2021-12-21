#pragma comment (lib, "opengl32.lib")

#ifndef SHOWLIGHT_H

#include "object.h"

/*
the function of showLight is to create :
	-	global light, 
	-	ambient light, 
	-	fixed light, 
	-	spot light, 
	-	directed light
*/
void showLight_Global();
void showLight_Ambient();
void showLight_Fixed();
void showLight_Spot();
void showLight_Directed();
void showLight_Directed_S4();
void showAllLight();

void moveLight();

#endif // !SHOWLIGHT_H



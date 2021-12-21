#pragma comment (lib, "opengl32.lib")

#ifndef DRAWLIGHT_H

#include "object.h"

//the function of drawLight is make light color on the rendered object
void drawLight_point_line();
void drawLight_triangle();
void drawLight_square();
void drawLight_octagon();
void drawLight_circle();
void drawLight_cube_right();
void drawLight_cube_top();
void drawLight_sphere_center();
void drawLight_cylinder_body();
void drawLight_cylinder_top();
void drawLight_cylinder_bottom();
void drawLight_shadow();
void drawLight_wall();
void drawLight_wall_left();
void drawLight_wall_floor();
void drawLight_wall_back();

void drawLight_curve();


#endif // !DRAWLIGHT_H
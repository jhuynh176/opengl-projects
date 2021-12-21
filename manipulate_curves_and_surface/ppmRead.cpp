#include "ppmRead.h"

using namespace std;

// just a hack. A better way is to
// define a dynamic array
unsigned char ID_wall[256][256][3];  
unsigned char ID_floor[256][256][3];
unsigned char ID_ceiling[256][256][3];

void readImage(const char* fname, std::string options) {
	FILE* file = fopen(fname, "r");

	int height, width, ccv;
	char header[100];

	// assuming the width and height are 256 and 256 here ...
	fscanf(file, "%s %d %d %d", header, &width, &height, &ccv);
	int r, g, b;
	cout << "\nReading " << options << "\tppm file --> " << fname << endl;
	
	if (options == "wall") {
		for (int i = height - 1; i >= 0; i--) {
			for (int j = 0; j < width; j++)
			{
				fscanf(file, "%d %d %d", &r, &g, &b);
				ID_wall[i][j][0] = (GLubyte)r;
				ID_wall[i][j][1] = (GLubyte)g;
				ID_wall[i][j][2] = (GLubyte)b;
			}
		}

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0,
			GL_RGB, GL_UNSIGNED_BYTE, ID_wall);
	}
	else if (options == "floor") {
		for (int i = height - 1; i >= 0; i--) {
			for (int j = 0; j < width; j++)
			{
				fscanf(file, "%d %d %d", &r, &g, &b);
				ID_floor[i][j][0] = (GLubyte)r;
				ID_floor[i][j][1] = (GLubyte)g;
				ID_floor[i][j][2] = (GLubyte)b;
			}
		}

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0,
			GL_RGB, GL_UNSIGNED_BYTE, ID_floor);
	}
	else if (options == "ceiling") {
		for (int i = height - 1; i >= 0; i--) {
			for (int j = 0; j < width; j++)
			{
				fscanf(file, "%d %d %d", &r, &g, &b);
				ID_ceiling[i][j][0] = (GLubyte)r;
				ID_ceiling[i][j][1] = (GLubyte)g;
				ID_ceiling[i][j][2] = (GLubyte)b;
			}
		}

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0,
			GL_RGB, GL_UNSIGNED_BYTE, ID_ceiling);
	}

}
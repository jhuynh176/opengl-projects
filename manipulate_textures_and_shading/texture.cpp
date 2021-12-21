#include "texture.h"


/*  Create checkerboard texture  */
#define checkImageWidth 64
#define checkImageHeight 64
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
static GLubyte checkImage_square[checkImageHeight][checkImageWidth][4];
static GLubyte checkImage_triangle[checkImageHeight][checkImageWidth][4];
static GLubyte checkImage_hexagon[checkImageHeight][checkImageWidth][4];
static GLubyte checkImage_circle[checkImageHeight][checkImageWidth][4];
static GLubyte checkImage_cube_right[checkImageHeight][checkImageWidth][4];
static GLubyte checkImage_cube_top[checkImageHeight][checkImageWidth][4];
static GLubyte checkImage_sphere[checkImageHeight][checkImageWidth][4];
static GLubyte checkImage_cylinder[checkImageHeight][checkImageWidth][4];
static GLubyte checkImage_room[checkImageHeight][checkImageWidth][4];

static GLuint texture_triangle;
static GLuint texture_square;
static GLuint texture_circle;
static GLuint texture_hexagon;
static GLuint texture_sphere;
static GLuint texture_cube_right;
static GLuint texture_cube_top;
static GLuint texture_sphere1;
static GLuint texture_cylinder;
static GLuint texture_room;

std::string textureName;
std::string colorSet;

int pattern_x = 0;
int pattern_y = 0;
int defaultColor_first = 0;
int defaultColor_second = 1;
int defaultColor_third = 2;
int defaultColor_fourth = 3;

void checkTextureName(std::string textureName) {
    std::cout << "Applying texture:\t" << textureName << std::endl;

    if (textureName == "triangle") {
        pattern_x = 64;
        pattern_y = 1;

        int i, j, c;

        for (i = 0; i < checkImageHeight; i++) {
            for (j = 0; j < checkImageWidth; j++) {
                c = ((((i & pattern_x) == 0) ^ ((j & pattern_y)) == 0)) * 255;
                checkImage_triangle[i][j][defaultColor_first] = (GLubyte)c;
                checkImage_triangle[i][j][defaultColor_second] = (GLubyte)c;
                checkImage_triangle[i][j][defaultColor_third] = (GLubyte)c;
                checkImage_triangle[i][j][defaultColor_fourth] = (GLubyte)255;
            }
        }

    }
    else if (textureName == "square") {
        pattern_x = 16;
        pattern_y = 16;

        int i, j, c;

        for (i = 0; i < checkImageHeight; i++) {
            for (j = 0; j < checkImageWidth; j++) {
                c = ((((i & pattern_x) == 0) ^ ((j & pattern_y)) == 0)) * 255;
                checkImage_square[i][j][defaultColor_first] = (GLubyte)c;
                checkImage_square[i][j][defaultColor_second] = (GLubyte)c;
                checkImage_square[i][j][defaultColor_third] = (GLubyte)c;
                checkImage_square[i][j][defaultColor_fourth] = (GLubyte)255;
            }
        }
    }
    else if (textureName == "hexagon") {
        pattern_x = 16;
        pattern_y = 64;

        int i, j, c;

        for (i = 0; i < checkImageHeight; i++) {
            for (j = 0; j < checkImageWidth; j++) {
                c = ((((i & pattern_x) == 0) ^ ((j & pattern_y)) == 0)) * 255;
                checkImage_hexagon[i][j][defaultColor_first] = (GLubyte)c;
                checkImage_hexagon[i][j][defaultColor_second] = (GLubyte)c;
                checkImage_hexagon[i][j][defaultColor_third] = (GLubyte)c;
                checkImage_hexagon[i][j][defaultColor_fourth] = (GLubyte)255;
            }
        }
    }
    else if (textureName == "circle") {
        pattern_x = 30;
        pattern_y = 30;

        int i, j, c;

        for (i = 0; i < checkImageHeight; i++) {
            for (j = 0; j < checkImageWidth; j++) {
                c = ((((i & pattern_x) == 0) ^ ((j & pattern_y)) == 0)) * 255;
                checkImage_circle[i][j][defaultColor_first] = (GLubyte)c;
                checkImage_circle[i][j][defaultColor_second] = (GLubyte)c;
                checkImage_circle[i][j][defaultColor_third] = (GLubyte)c;
                checkImage_circle[i][j][defaultColor_fourth] = (GLubyte)255;
            }
        }
    }
    else if (textureName == "cube_right") {
        pattern_x = 10;
        pattern_y = 10;

        int i, j, c;

        for (i = 0; i < checkImageHeight; i++) {
            for (j = 0; j < checkImageWidth; j++) {
                c = ((((i & pattern_x) == 0) ^ ((j & pattern_y)) == 0)) * 255;
                checkImage_cube_right[i][j][defaultColor_first] = (GLubyte)c;
                checkImage_cube_right[i][j][defaultColor_second] = (GLubyte)c;
                checkImage_cube_right[i][j][defaultColor_third] = (GLubyte)c;
                checkImage_cube_right[i][j][defaultColor_fourth] = (GLubyte)255;
            }
        }
    }
    else if (textureName == "cube_top") {
        int q = 16;
        pattern_x = 32;
        pattern_y = 12;

        int i, j, c;

        for (i = 0; i < checkImageHeight; i++) {
            for (j = 0; j < checkImageWidth; j++) {
                c = ((((i & pattern_x) == 0) ^ ((j & pattern_y)) == 0)) * 255;
                checkImage_cube_top[i][j][defaultColor_first] = (GLubyte)c;
                checkImage_cube_top[i][j][defaultColor_second] = (GLubyte)c;
                checkImage_cube_top[i][j][defaultColor_third] = (GLubyte)c;
                checkImage_cube_top[i][j][defaultColor_fourth] = (GLubyte)255;
            }
        }
    }
    else if (textureName == "sphere") {
        //int q = 1.5;
        int q = 6;
        pattern_x = 64;
        pattern_y = 4;

        int i, j, c;

        for (i = 0; i < checkImageHeight; i++) {
            for (j = 0; j < checkImageWidth; j++) {
                c = ((((i & pattern_x) == 0) ^ ((j & pattern_y)) == 0)) * 255;
                checkImage_sphere[i][j][defaultColor_first] = (GLubyte)c;
                checkImage_sphere[i][j][defaultColor_second] = (GLubyte)c;
                checkImage_sphere[i][j][defaultColor_third] = (GLubyte)c;
                checkImage_sphere[i][j][defaultColor_fourth] = (GLubyte)255;
            }
        }
    }
    else if (textureName == "cylinder") {
        int q = 31;
        pattern_x = q;
        pattern_y = q;

        int i, j, c;

        for (i = 0; i < checkImageHeight; i++) {
            for (j = 0; j < checkImageWidth; j++) {
                c = ((((i & pattern_x) == 0) ^ ((j & pattern_y)) == 0)) * 255;
                checkImage_cylinder[i][j][defaultColor_first] = (GLubyte)c;
                checkImage_cylinder[i][j][defaultColor_second] = (GLubyte)c;
                checkImage_cylinder[i][j][defaultColor_third] = (GLubyte)c;
                checkImage_cylinder[i][j][defaultColor_fourth] = (GLubyte)255;
            }
        }
    }
    else if (textureName == "room") {
        int q = 27;
        pattern_x = q;
        pattern_y = q;

        int i, j, c;

        for (i = 0; i < checkImageHeight; i++) {
            for (j = 0; j < checkImageWidth; j++) {
                c = ((((i & pattern_x) == 0) ^ ((j & pattern_y)) == 0)) * 255;
                checkImage_room[i][j][defaultColor_first] = (GLubyte)c;
                checkImage_room[i][j][defaultColor_second] = (GLubyte)c;
                checkImage_room[i][j][defaultColor_third] = (GLubyte)c;
                checkImage_room[i][j][defaultColor_fourth] = (GLubyte)255;
            }
        }
    }

}

void checkColorSet(std::string colorSet) {
    std::cout << "Applying color:\t" << colorSet << std::endl;

    if (colorSet == "white") {
        defaultColor_first = 0;
        defaultColor_second = 1;
        defaultColor_third = 2;
        defaultColor_fourth = 3;

    }
    else if (colorSet == "yellow") {
        defaultColor_first = 0;
        defaultColor_second = 1;
        defaultColor_third = 0;
        defaultColor_fourth = 3;

    }
    else if (colorSet == "red") {
        defaultColor_first = 0;
        defaultColor_second = 0;
        defaultColor_third = 0;
        defaultColor_fourth = 3;
    }
    else if (colorSet == "purple") {
        defaultColor_first = 0;
        defaultColor_second = 0;
        defaultColor_third = 2;
        defaultColor_fourth = 3;
    }
    else if (colorSet == "jade_blue") {
        defaultColor_first = 1;
        defaultColor_second = 1;
        defaultColor_third = 2;
        defaultColor_fourth = 3;
    }
    else if (colorSet == "dark_blue") {
        defaultColor_first = 1;
        //defaultColor_second = 1.5;
        defaultColor_second = 2;
        defaultColor_third = 1;
        defaultColor_fourth = 3;
    }
    else if (colorSet == "green") {
        defaultColor_first = 1;
        defaultColor_second = 1;
        defaultColor_third = 1;
        defaultColor_fourth = 3;
    }
}


void makeCheckImage(void)
{
    int i, j, c;

    for (i = 0; i < checkImageHeight; i++) {
        for (j = 0; j < checkImageWidth; j++) {
            c = ((((i & pattern_x) == 0) ^ ((j & pattern_y)) == 0)) * 255;
            checkImage[i][j][defaultColor_first] = (GLubyte)c;
            checkImage[i][j][defaultColor_second] = (GLubyte)c;
            checkImage[i][j][defaultColor_third] = (GLubyte)c;
            checkImage[i][j][defaultColor_fourth] = (GLubyte)255;
        }
    }
}

void displaySquare() {
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    textureName = "square";
    colorSet = "white";
    checkColorSet(colorSet);
    checkTextureName(textureName);
    //makeCheckImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &texture_square);
    glBindTexture(GL_TEXTURE_2D, texture_square);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
        checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
        checkImage_square);


    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texture_square);

    renderSquare();

    glDisable(GL_TEXTURE_2D);
}

void displayTriangle() {
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    textureName = "triangle";
    colorSet = "yellow";
    checkColorSet(colorSet);
    checkTextureName(textureName);
    //makeCheckImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &texture_triangle);
    glBindTexture(GL_TEXTURE_2D, texture_triangle);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
        checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
        checkImage_triangle);


    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texture_triangle);

    renderTriangle();

    glDisable(GL_TEXTURE_2D);
}

void displayHexagon() {
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    textureName = "hexagon";
    colorSet = "red";
    checkColorSet(colorSet);
    checkTextureName(textureName);
    //makeCheckImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &texture_hexagon);
    glBindTexture(GL_TEXTURE_2D, texture_hexagon);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
        checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
        checkImage_hexagon);


    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texture_hexagon);

    renderHexagon();

    glDisable(GL_TEXTURE_2D);
}

void displayCircle() {
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    textureName = "circle";
    colorSet = "purple";
    checkColorSet(colorSet);
    checkTextureName(textureName);
    //makeCheckImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &texture_circle);
    glBindTexture(GL_TEXTURE_2D, texture_circle);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
        checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
        checkImage_circle);


    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texture_circle);

    renderCircle();

    glDisable(GL_TEXTURE_2D);
}

void displayCubeRight() {
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    textureName = "cube_right";
    colorSet = "jade_blue";
    checkColorSet(colorSet);
    checkTextureName(textureName);
    //makeCheckImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &texture_cube_right);
    glBindTexture(GL_TEXTURE_2D, texture_cube_right);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
        checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
        checkImage_cube_right);


    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texture_cube_right);

    renderCube_right();

    glDisable(GL_TEXTURE_2D);
}

void displayCubeTop() {
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    textureName = "cube_top";
    colorSet = "dark_blue";
    checkColorSet(colorSet);
    checkTextureName(textureName);
    //makeCheckImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &texture_cube_top);
    glBindTexture(GL_TEXTURE_2D, texture_cube_top);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
        checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
        checkImage_cube_top);


    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texture_cube_top);

    renderCube_top();

    glDisable(GL_TEXTURE_2D);
}
void displaySphere() {
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    textureName = "sphere";
    colorSet = "purple";
    checkColorSet(colorSet);
    checkTextureName(textureName);
    //makeCheckImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &texture_sphere1);
    glBindTexture(GL_TEXTURE_2D, texture_sphere1);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
        checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
        checkImage_sphere);


    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texture_sphere1);

    renderSphere_center();

    glDisable(GL_TEXTURE_2D);
}
void displayCylinder() {
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    textureName = "cylinder";
    colorSet = "green";
    checkColorSet(colorSet);
    checkTextureName(textureName);
    //makeCheckImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &texture_cylinder);
    glBindTexture(GL_TEXTURE_2D, texture_cylinder);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
        checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
        checkImage_cylinder);


    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texture_cylinder);

    renderCylinder();

    glDisable(GL_TEXTURE_2D);
}
void displayRoom() {
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    textureName = "room";
    colorSet = "green";
    checkColorSet(colorSet);
    checkTextureName(textureName);
    //makeCheckImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &texture_room);
    glBindTexture(GL_TEXTURE_2D, texture_room);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
        checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
        checkImage_room);


    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texture_room);

    renderWall();

    glDisable(GL_TEXTURE_2D);
}


void displayWall_PPM() {
    readImage("bw.ppm", "wall");


    //readID_wall("building.ppm", "wall");

    glEnable(GL_TEXTURE_2D);

    renderWall();

    glDisable(GL_TEXTURE_2D);
}

void displayFloor_PPM() {

    readImage("bw.ppm", "floor");
    //readID_floor("bw.ppm", "floor");

    glEnable(GL_TEXTURE_2D);

    renderFloor();

    glDisable(GL_TEXTURE_2D);
}

void displayCeiling_PPM() {

    readImage("eyes.ppm", "ceiling");
    //readID_ceiling("tile.ppm", "ceiling");

    glEnable(GL_TEXTURE_2D);

    renderCeiling();

    glDisable(GL_TEXTURE_2D);
}
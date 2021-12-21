#include "showLight.h"

#include "render.h"

int n = 0;

void showLight_Global() {
    //lighting set up
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    //set lighting intensity and color
    GLfloat qaAmbientLight[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat qaDiffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

    //set light position
    GLfloat qaLightPosition[] = { .5, 0.5, 0.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
}
void showLight_Ambient() {
    //ambient light
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
    GLfloat lightAmbient[4] = { 0.7f, 0.4f, 0.4f, 1.0f };
    GLfloat viewLocal[] = { 0.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightAmbient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, viewLocal);
}
void showLight_Fixed() {
    //positioned light
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHT0);
    GLfloat lightPosition_0[4] = { -50.0f, 100.0f, 0.0f, 1.0f };
    GLfloat lightDiffusion_0[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat lightAmbient_0[4] = { 0.025f, 0.025f, 0.025f, 1.0f };
    GLfloat lightSpecular_0[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient_0);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition_0);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffusion_0);
    glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpecular_0);
}
void showLight_Spot() {
    //spotlight
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHT3);
    GLfloat lightSpot[4] = { -1.0f, 1.0f, -8.0f };
    GLfloat lightDiffusion_2[4] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat lightAmbient_2[4] = { 0.05f, 0.05f, 0.05f, 1.0f };
    GLfloat lightSpecular_2[4] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat lightPosition_2[4] = { -120.0f, 130.0f, -130.0f, 0.0f };
    glLightfv(GL_LIGHT3, GL_POSITION, lightPosition_2);
    glLightfv(GL_LIGHT3, GL_AMBIENT, lightAmbient_2);
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, lightSpot);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, lightDiffusion_2);
    glLightfv(GL_LIGHT3, GL_SPECULAR, lightSpecular_2);
    glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 180.0);
    glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 2.0);
    glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 2.5);
    glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.5);
    glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.2);

    //glEnable(GL_COLOR_MATERIAL);
    //glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    //glEnable(GL_NORMALIZE);
    //glEnable(GL_CULL_FACE);
}
void showLight_Directed() {
    //directed light
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHT2);
    GLfloat lightPosition_1[4] = { 120.0f, -130.f, 130.0f, 0.0f };
    GLfloat lightDiffusion_1[4] = { 0.25, 0.25, 0.25, 1.0f };
    GLfloat lightAmbient_1[4] = { 0.125, 0.125, 0.125, 1.0f };
    GLfloat lightSpecular_1[4] = { 0.95f, 0.95f, 0.95f, 1.0f };
    glLightfv(GL_LIGHT2, GL_AMBIENT, lightAmbient_1);
    glLightfv(GL_LIGHT2, GL_POSITION, lightPosition_1);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, lightDiffusion_1);
    glLightfv(GL_LIGHT2, GL_SPECULAR, lightSpecular_1);
}
void showLight_Directed_S4() {
    //directed light
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHT2);
    GLfloat lightPosition_1[4] = { 120.0f, -130.f, 100, 0.0f };
    GLfloat lightDiffusion_1[4] = { 0.2, 0.2, 0.2, 1.0f };
    GLfloat lightAmbient_1[4] = { 0.2, 0.2, 0.2, 1.0f };
    GLfloat lightSpecular_1[4] = { 0.95f, 0.95f, 0.95f, 1.0f };
    glLightfv(GL_LIGHT2, GL_AMBIENT, lightAmbient_1);
    glLightfv(GL_LIGHT2, GL_POSITION, lightPosition_1);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, lightDiffusion_1);
    glLightfv(GL_LIGHT2, GL_SPECULAR, lightSpecular_1);
}
void showAllLight() {
    showLight_Spot();
    showLight_Fixed();
    showLight_Ambient();
    showLight_Global();
    //showLight_Directed();

}

void moveLight() {
    showAllLight();
    glPushMatrix();
    glRotatef(40, 0, 0, 0);
    showAllRender();
    n++;
    glPopMatrix();
}
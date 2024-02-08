#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string.h>
#include "BmpLoader.h"



GLfloat mat_ambient[4];
GLfloat mat_diffuse[4];
GLfloat mat_specular[4];
GLfloat mat_shininess[] = {60};

float speed = 0.0;

static void getNormal3p(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3);

unsigned int ID;





void material_properties(GLfloat *p)
{
    mat_ambient[0] = p[0];
    mat_ambient[1] = p[1];
    mat_ambient[2] = p[2];
    mat_ambient[3] = p[3];

    mat_diffuse[0] = p[4];
    mat_diffuse[1] = p[5];
    mat_diffuse[2] = p[6];
    mat_diffuse[3] = p[7];

    mat_specular[0] = p[4];
    mat_specular[1] = p[5];
    mat_specular[2] = p[6];
    mat_specular[3] = p[7];

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}
void material_properties2(GLfloat *p)
{
    mat_ambient[0] = p[0];
    mat_ambient[1] = p[1];
    mat_ambient[2] = p[2];
    mat_ambient[3] = p[3];

    mat_diffuse[0] = p[4];
    mat_diffuse[1] = p[5];
    mat_diffuse[2] = p[6];
    mat_diffuse[3] = p[7];

    mat_specular[0] = p[4];
    mat_specular[1] = p[5];
    mat_specular[2] = p[6];
    mat_specular[3] = p[7];

    GLfloat mat_emission[] = {1, 1, 1, 1.0};
    glMaterialfv( GL_FRONT, GL_EMISSION, mat_emission);


    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

static GLfloat v_points[12][3] =
    {
        {0.0, 0.0, 0.0},
        {0.0, 0.0, 1.0},
        {0.0, 1.0, 1.0},
        {0.0, 1.0, 0.0},
        {1.0, 0.0, 1.0},
        {1.0, 1.0, 1.0},
        {1.0, 0.0, 0.0},
        {1.0, 1.0, 0.0}};
static GLubyte quadIndices[6][4] =
    {
        {0, 1, 2, 3},
        {1, 4, 5, 2},
        {5, 4, 6, 7},
        {3, 2, 5, 7},
        {3, 0, 6, 7},
        {0, 1, 4, 6}};

static GLfloat colors[5][3] =
    {
        {0.0, 0.0, 1.0},
        {0.5, 0.0, 1.0},
        {0.0, 1.0, 0.0},
        {0.0, 1.0, 1.0},
        {0.8, 0.0, 0.0}};

void drawCube(GLfloat col1, GLfloat col2, GLfloat col3)
{

    glBegin(GL_QUADS);
    for (GLint i = 0; i < 6; i++)
    {

       getNormal3p(v_points[quadIndices[i][0]][0], v_points[quadIndices[i][0]][1], v_points[quadIndices[i][0]][2],
                   v_points[quadIndices[i][1]][0], v_points[quadIndices[i][1]][1], v_points[quadIndices[i][1]][2],
                   v_points[quadIndices[i][2]][0], v_points[quadIndices[i][2]][1], v_points[quadIndices[i][2]][2]);


        glColor3f(col1, col2, col3);
        GLfloat p[] = {col1, col2, col3, 1.0, col1, col2, col3, 1.0, col1, col2, col3, 1.0};
        material_properties(p);
        glVertex3fv(&v_points[quadIndices[i][0]][0]);glTexCoord2f(1,1);
        glVertex3fv(&v_points[quadIndices[i][1]][0]);glTexCoord2f(1,0);
        glVertex3fv(&v_points[quadIndices[i][2]][0]);glTexCoord2f(0,0);
        glVertex3fv(&v_points[quadIndices[i][3]][0]);glTexCoord2f(0,1);
    }
    glEnd();
}
void drawCube2(GLfloat col1, GLfloat col2, GLfloat col3)
{

    glBegin(GL_QUADS);
    for (GLint i = 0; i < 6; i++)
    {

       getNormal3p(v_points[quadIndices[i][0]][0], v_points[quadIndices[i][0]][1], v_points[quadIndices[i][0]][2],
                   v_points[quadIndices[i][1]][0], v_points[quadIndices[i][1]][1], v_points[quadIndices[i][1]][2],
                   v_points[quadIndices[i][2]][0], v_points[quadIndices[i][2]][1], v_points[quadIndices[i][2]][2]);


        glColor3f(col1, col2, col3);
        GLfloat p[] = {col1, col2, col3, 1.0, col1, col2, col3, 1.0, col1, col2, col3, 1.0};
        material_properties(p);
        glVertex3fv(&v_points[quadIndices[i][0]][0]);glTexCoord2f(1,1);
        glVertex3fv(&v_points[quadIndices[i][1]][0]);glTexCoord2f(1,0);
        glVertex3fv(&v_points[quadIndices[i][2]][0]);glTexCoord2f(0,0);
        glVertex3fv(&v_points[quadIndices[i][3]][0]);glTexCoord2f(0,1);
    }
    glEnd();
}









// float spotx = 14,spoty = 5, spotz = 14;

float spotx = -18,spoty = 144, spotz = 97;
float spotxx = 0,spotyy = -3, spotzz = 0;
void spotlight1(float table_lamp)
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.3, 0.3, 0.3, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { -10,49,22, 1.0 };

    if(table_lamp == 1){
        glEnable( GL_LIGHT6);
        glLightfv(GL_LIGHT6, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT6, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT6, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT6, GL_POSITION, light_position);
    }else{
        glEnable( GL_LIGHT6);
        glLightfv(GL_LIGHT6, GL_AMBIENT, no_light);
        glLightfv(GL_LIGHT6, GL_DIFFUSE, no_light);
        glLightfv(GL_LIGHT6, GL_SPECULAR, no_light);
        glLightfv(GL_LIGHT6, GL_POSITION, light_position);
    }

    GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
    glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT6, GL_SPOT_CUTOFF, 10.0);
}



void spotlight2(float table_lamp)
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.3, 0.3, 0.3, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { -18,144,97, 1.0 };

    if(table_lamp){
        glEnable( GL_LIGHT7);
        glLightfv(GL_LIGHT7, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT7, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT7, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT7, GL_POSITION, light_position);
    }else{
        glEnable( GL_LIGHT7);
        glLightfv(GL_LIGHT7, GL_AMBIENT, no_light);
        glLightfv(GL_LIGHT7, GL_DIFFUSE, no_light);
        glLightfv(GL_LIGHT7, GL_SPECULAR, no_light);
        glLightfv(GL_LIGHT7, GL_POSITION, light_position);
    }

    GLfloat spot_direction[] = { 0.0, -3.0, 0.0 };
    glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT7, GL_SPOT_CUTOFF, 10.0);
}


void tableLamp(){
    glPushMatrix();
    glTranslatef(-15,5,13);
    glScalef(.4,.4,.4);
    drawCube2(1,1,1);
    glPopMatrix();

    //hanger
    GLUquadricObj *q;
    q = gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 9);
    gluQuadricTexture(q, GL_TRUE);
    glPushMatrix();
    glTranslatef(-15,13,13);
    glRotatef(90,1,0,0);
    gluCylinder(q, .1, .1, 8, 52, 52);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}


void streetlight(){

    GLUquadricObj *q;
    q = gluNewQuadric();

    //bulb box
    glPushMatrix();
    glScalef(.5,.5,2);
    glTranslatef(-60.5,19,42.8);
    drawCube2(1,1,1);
    glPopMatrix();

    //pillar
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 9);
    gluQuadricTexture(q, GL_TRUE);
    glPushMatrix();
    glTranslatef(-30,10,84);
    glRotatef(90,1,0,0);
    gluCylinder(q, .3, .3, 25, 52, 52);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-30,9.7,84);
    gluCylinder(q, .1, .1, 3, 52, 52);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}


void atm_machine();
void vault();



void Walls()
{

    float t_y = -9;
    float s_y = 22;

    //floor
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
    glPushMatrix();
    glTranslatef(-30, -10, -20);
    glScalef(61, 1, 60);
    drawCube(1.0, 1.0, 1.0);
    glPopMatrix();
    //extend floor
    glPushMatrix();
    glTranslatef(-5, -10, 40);
    glScalef(36, 1, 10);
    drawCube(1.0, 1.0, 1.0);
    glPopMatrix();
    //extend floor
    glDisable(GL_TEXTURE_2D);
    //floor end


    // //ceil
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
    glPushMatrix();
    glTranslatef(-30, 13, -20);
    glScalef(63, 1, 73);
    drawCube(1.0, 1.0, 1.0);
    glPopMatrix();

    // glPushMatrix();
    // glTranslatef(-5, 12, 40);
    // glScalef(38, 1, 12);
    // drawCube(1.0, 1.0, 1.0);
    // glPopMatrix();
    // glDisable(GL_TEXTURE_2D);
    // //ceil end



    //ground
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,2);
    glPushMatrix();
    glTranslatef(-40, -10.8, -39);
    glScalef(80, 1, 119.5);
    drawCube(1.0, 1.0, 1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    //ground end


    //earth
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,14);
    glPushMatrix();
    glTranslatef(-1000, -11, -2000);
    glScalef(1000000000, .5, 1000000000);
    // glScalef(10000, .5, 10000);
    drawCube(.6, 0.4, 0.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    //earth end




    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);

    //dining room and drawing room wall
    // glPushMatrix();
    // glTranslatef(11, t_y, 28);
    // glScalef(20, s_y, .5);
    // drawCube(1, 1, 1);
    // glPopMatrix();

    glPushMatrix();
    glTranslatef(0, t_y, 28);
    glScalef(6, s_y, .5);
    drawCube(1, 1, 1);
    glPopMatrix();

    //library gate wall
    glPushMatrix();
    glTranslatef(0, t_y, 25);
    glScalef(.5, s_y, 18);
    drawCube(1, 1, 1);
    glPopMatrix();

    //main gate small wall
    glPushMatrix();
    glTranslatef(0, t_y, 48.5);
    glScalef(.5, s_y, 2);
    drawCube(1, 1, 1);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(30.5, t_y, -4);
    glScalef(.5, s_y, 54);
    drawCube(1, 1, 1);
    glPopMatrix();
    //dining room and drawing room wall end

    //front door side walls
    // glPushMatrix();
    // glTranslatef(.5, t_y, 50);
    // glScalef(14, s_y, .5);
    // drawCube(1, 1, 1);
    // glPopMatrix();

    // glPushMatrix();
    // glTranslatef(21, t_y, 50);
    // glScalef(10, s_y, .5);
    // drawCube(1, 1, 1);
    // glPopMatrix();

    // glPushMatrix();
    // glTranslatef(13, t_y, 50);
    // glScalef(10, 8, .5);
    // drawCube(1, 1, 1);
    // glPopMatrix();

    // glPushMatrix();
    // glTranslatef(13, t_y+17, 50);
    // glScalef(10, 5, .5);
    // drawCube(1, 1, 1);
    // glPopMatrix();
    //end front door side walls



    //front wall
    glPushMatrix();
    glTranslatef(-29.5, t_y, 39.5);
    glScalef(30, s_y, .5);
    drawCube(1, 1, 1);
    glPopMatrix();


    //front wall end



    //left wall
    glPushMatrix();
    glTranslatef(-29.7, t_y, -19);
    glScalef(.5, s_y, 59);
    drawCube(1, 1, 1);
    glPopMatrix();
    //left wall end


    //window side wall
    glPushMatrix();
    glTranslatef(30.5, t_y, -18);
    glScalef(.5, 7, 16);
    drawCube(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30.5, -2, -8);
    glScalef(.5, 6, 4);
    drawCube(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30.5, -2, -19);
    glScalef(.5, 6, 6.7);
    drawCube(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30.5, 4.1, -19);
    glScalef(.5, 9, 20);
    drawCube(1, 1, 1);
    glPopMatrix();
    //window side wall end

    //exhaust fan wall
    //back wall
    glPushMatrix();
    glTranslatef(-29.5, -9, -19);
    glScalef(61, 13, .5);
    drawCube(1, 1, 1);
    glPopMatrix();
    //back wall end


    glPushMatrix();
    glTranslatef(-29.5, 3.5, -19);
    glScalef(46.5, 4, .5);
    drawCube(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20.5, 3.5, -19);
    glScalef(10.5, 4, .5);
    drawCube(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-29.5, 7.3, -18.5);
    glScalef(61, 5.8, .5);
    drawCube(1, 1, 1);
    glPopMatrix();
    //exhaust fan wall end

    // kitchen wall
    // glPushMatrix();
    // glTranslatef(8, t_y, -3);
    // glScalef(23, 22, .5);
    // drawCube(1, 1, 1);
    // glPopMatrix();
    // kitchen wall end


    //bedroom and drawing room wall
    glPushMatrix();
    glTranslatef(-29.5, t_y, 10);
    glScalef(30, s_y, .5);
    drawCube(1, 1, 1);
    glPopMatrix();
    //bedroom and drawing room wall end



    //bedroom wall
    glPushMatrix();
    glTranslatef(0, t_y, -10);
    glScalef(.5, s_y, 30);
    drawCube(1, 1, 1);
    glPopMatrix();

    // glPushMatrix();
    // glTranslatef(0, t_y, -18.5);
    // glScalef(.5, s_y, 3.5);
    // drawCube(1, 1, 1);
    // glPopMatrix();
    //bedroom wall end

    //door upper wall
    glPushMatrix();
    glTranslatef(0, 10, -15);
    glScalef(.5, 3, 7);
    drawCube(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 10, 19);
    glScalef(.5, 3, 7);
    drawCube(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 10, 43);
    glScalef(.5, 3, 7);
    drawCube(1, 1, 1);
    glPopMatrix();
    //door upper wall end
    glDisable(GL_TEXTURE_2D);






    // boundary walls
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,8);
    //front
    glPushMatrix();
    glTranslatef(-40, -10.5, 80.5);
    glScalef(18, 10, .5);
    drawCube(1,1,1); //0.9, 0.7, 0.5
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-12, -10.5, 80.5);
    glScalef(52, 10, .5);
    drawCube(1,1,1);
    glPopMatrix();

    //left
    glPushMatrix();
    glTranslatef(-40, -10.5, -39);
    glScalef(.5, 10, 120);
    drawCube(1,1, 1);
    glPopMatrix();

    //right
    glPushMatrix();
    glTranslatef(40, -10.5, -39);
    glScalef(.5, 10, 120);
    drawCube(1,1,1);
    glPopMatrix();

    // back
    glPushMatrix();
    glTranslatef(-40.3, -10.5, -40);
    glScalef(81, 10, .5);
    // drawCube(0.9, 0.7, 0.5);
    drawCube(1, 1, 1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    // boundary walls end





    //atm walls left
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 3);
    glTranslatef(-22.5, t_y, 39.5);
    glScalef(.5, s_y, 10);
    drawCube(1, 1, 1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();





    glPushMatrix();
    atm_machine();
    glPopMatrix();


    //atm left to door wall
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 3);
    glTranslatef(-22.5, t_y, 49.5);
    glScalef(9.5, s_y, .5);
    drawCube(1, 1, 1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    float atm_door=0;
    //atm door


    //atm logo
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 26);
    glTranslatef(-19.5, t_y+14.5, 49.9);
    glScalef(18, 8, .5);
    drawCube(1, 1, 1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();



    //bank logo
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 22);
    glTranslatef(-2.5, t_y+21.9, 52.8);
    glScalef(30, 15, .5);
    drawCube(1, 1, 1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    //atm wall back
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 3);
    glTranslatef(-7.5, t_y, 49.5);
    glScalef(15.2, s_y, .5);
    drawCube(1, 1, 1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //atm wall back
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 3);
    glTranslatef(18, t_y, 49.5);
    glScalef(15, s_y, .5);
    drawCube(1, 1, 1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    //bank door logo
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 27);
    glTranslatef(7.5, t_y+15.5, 49.5);
    glScalef(10.5, 7, .5);
    drawCube(1, 1, 1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //border left
    glPushMatrix();
    glTranslatef(7.5, t_y, 49.5);
    glScalef(.5, 15, .1);
    drawCube(0.8235, 0.7725, 0.7412);
    glPopMatrix();


    //border up
    glPushMatrix();
    glTranslatef(7.5, t_y+15, 49.5);
    glScalef(11, 0.5, .1);
    drawCube(0.8235, 0.7725, 0.7412);
    glPopMatrix();

    //border right
    glPushMatrix();
    glTranslatef(17.6, t_y, 49.5);
    glScalef(.5, 15, .1);
    drawCube(0.8235, 0.7725, 0.7412);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-26.55, -31, -57);
    glScalef(0.96, 1,1);
    vault();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-67.6, -31, 9);
    glRotatef(90, 0, 1, 0);
    glScalef(0.952, 1,1);
    vault();
    glPopMatrix();
}

void atm_machine(){
    float t_y = -9;
    float s_y = 22;


    for(float i=-20; i<0; i+=5){
        glPushMatrix();
        glTranslatef(i, t_y, 39.5);
        glScalef(3, 10, 3);
        drawCube(0.8196, 0.8314, 0.8509);
        glPopMatrix();




        glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 23);
        glTranslatef(i, t_y, 42.58);
        glScalef(3, 10, 0.02);
        drawCube(0.8196, 0.8314, 0.8509);
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();



        glPushMatrix();
        glTranslatef(i-1, t_y, 39.5);
        glScalef(0.2, 11, 4.5);
        drawCube(0.8196, 0.8314, 0.8509);
        glPopMatrix();
    }
    glPushMatrix();
    glTranslatef(-1.5, t_y, 39.5);
    glScalef(0.2, 11, 4.5);
    drawCube(0.8196, 0.8314, 0.8509);
    glPopMatrix();
}



void vault(){
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 24);
    glTranslatef(-1.5, 22, 39.5);
    glScalef(29.5, 22, 0.01);
    drawCube(0.8196, 0.8314, 0.8509);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

}



void atm_cash(){
    for(float i=5; i<7.5; i+=0.011){
        glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 28);
        glTranslatef(0, i, 90);
        glRotatef(90, 0, 1, 0);
        glScalef(5, 0.01, 15);
        drawCube(.40,.39,.39);
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
}

void atm_card(){
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 29);
    glTranslatef(0, 5, 90);
    glRotatef(90, 0, 1, 0);
    glScalef(5, 0.01, 15);
    drawCube(.40,.39,.39);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void cash_counter(){
    glPushMatrix();
    glTranslatef(0, -7.5, 90);
    glScalef(15, 5, 5);
    drawCube(.40,.39,.39);
    glPopMatrix();

    //horizontal top
    glPushMatrix();
    glTranslatef(-.25, -2.5, 90);
    glScalef(15.5, 1, 5.15);
    drawCube(.45,.43,.43);
    glPopMatrix();


    //background
    glPushMatrix();
    glTranslatef(-.25, -7.5, 85);
    glScalef(15.5, 20, 0.15);
    drawCube(1, 0.9725, 0.9686);
    glPopMatrix();


    //logo on background
    glPushMatrix();
    glTranslatef(4, -.5, 85.1);
    glScalef(7, 5, 0.25);
    drawCube(1, 0.98, 0.98);
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 22);
    glTranslatef(4, -.5, 85.42);
    glScalef(7, 5, 0.02);
    drawCube(1, 0.98, 0.98);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    for(float i=0.5; i<16; i+=3.7){
        if(i<13){
            glPushMatrix();
            glTranslatef(i, -2.5, 95.15);
            glScalef(3, 1, 0.05);
            drawCube(1,1,1);
            glPopMatrix();


            glPushMatrix();
            glTranslatef(i, -5.5, 95.01);
            glScalef(3, 4, 0.05);
            drawCube(1,1,1);
            glPopMatrix();
        }
        //vertical bars
        glPushMatrix();
        glTranslatef(i-.5, -5.5, 92.1);
        glScalef(0.25, 10, 3.15);
        drawCube(1,1,1);
        glPopMatrix();


    }






    /*
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 21);
    glPushMatrix();
    glTranslatef(0, -7.5, 95.025);
    glScalef(15, 5, 0);
    drawCube(1, 1, 1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);*/
}


/*
void leftCabinet()
{

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 4);
    glPushMatrix();
    glTranslatef(-4.9, -6, 4);
    glScalef(3, 5, 5);
    drawCube(0.8, 0.5, 0.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);





    // top white part
    glPushMatrix();
    glTranslatef(-4.9, -1, 4);
    glScalef(3.2, .6, 5);
    drawCube(.7, .8, .7);
    glPopMatrix();

    // glPushMatrix();
    // glTranslatef(-4.9, -6, -7);
    // glScalef(3, 5, 6.5);
    // drawCube(0.8, 0.5, 0.0);
    // glPopMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 4);
    glPushMatrix();
    glTranslatef(-4.9, -6, -7);
    glScalef(3, 5, 6.5);
    drawCube(0.8, 0.5, 0.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    // top white part
    glPushMatrix();
    glTranslatef(-4.9, -1, -7);
    glScalef(3.2, .6, 6.6);
    drawCube(.7, .8, .7);
    glPopMatrix();



    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 4);
    glPushMatrix();
    glTranslatef(-4.9, -6, -.5);
    glScalef(3, 2.3, 5);
    drawCube(0.8, 0.5, 0.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    // sink inside part
    glPushMatrix();
    glTranslatef(-4.9, -3.5, -.5);
    glScalef(.9, 2.5, 5);
    drawCube(.7, .6, .7);
    glPopMatrix();
    // white part
    glPushMatrix();
    glTranslatef(-4.9, -1, -.5);
    glScalef(.5, .6, 5);
    drawCube(.7, .8, .7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.9, -3.5, 3.9);
    glScalef(2.7, 2.5, .3);
    drawCube(.7, .7, .7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.9, -3.5, -.4);
    glScalef(2.7, 2.5, .3);
    drawCube(.7, .7, .7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.9, -3.8, -.5);
    glScalef(2.5, 0.3, 5);
    drawCube(0.7, 0.6, 0.6);
    glPopMatrix();

    // sink front
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 4);
    glPushMatrix();
    glTranslatef(-2.5, -3.6, -.5);
    glScalef(.6, 2.5, 5);
    drawCube(0.8, 0.5, 0.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);





    // cabinet side bar
    glPushMatrix();
    glTranslatef(-1.9, -5.7, 6);
    glScalef(.1, 4.5, .2);
    drawCube(0.9, 0.7, 0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.9, -5.7, 3);
    glScalef(.1, 4.5, .2);
    drawCube(0.9, 0.7, 0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.9, -5.7, 0);
    glScalef(.1, 4.5, .2);
    drawCube(0.9, 0.7, 0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.9, -5.7, -3);
    glScalef(.1, 4.5, .2);
    drawCube(0.9, 0.7, 0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.9, -5.7, -6);
    glScalef(.1, 4.5, .2);
    drawCube(0.9, 0.7, 0.5);
    glPopMatrix();

    // cabinet door handle
    glPushMatrix();
    glTranslatef(-1.9, -4.2, 6.5);
    glScalef(.01, 1, .3);
    drawCube(0.3, 0.3, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.9, -4.2, .4);
    glScalef(.01, 1, .3);
    drawCube(0.3, 0.3, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.9, -4.2, -.6);
    glScalef(.01, 1, .3);
    drawCube(0.3, 0.3, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.9, -4.2, -5.5);
    glScalef(.01, 1, .3);
    drawCube(0.3, 0.3, 0.2);
    glPopMatrix();
}





void topShelf()
{

    // full cabinet
    // glPushMatrix();
    // glTranslatef(-4.95, 2, 9);
    // glScalef(2, 4, -18.5);
    // drawCube(0.8, 0.5, 0.0);
    // glPopMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glPushMatrix();
    glTranslatef(-4.95, 2, 9);
    glScalef(2, 4, -18.5);
    drawCube(0.8, 0.5, 0.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    //shelf door
    glPushMatrix();
    glTranslatef(-2.9, 2.2, 6);
    glScalef(.01, 3.5, 2.5);
    drawCube(0.9, 0.7, 0.5);
    glPopMatrix();

    // glEnable(GL_TEXTURE_2D);
    // glPushMatrix();
    // glTranslatef(-2.9, 2.2, 6);
    // glScalef(.01, 3.5, 2.5);
    // LoadTexture("D:\\4-2\\Graphics Lab CSE 4208\\prac\\Final_Project_try1\\texture_images\\tt.bmp");
    // drawCube(0.9, 0.7, 0.5);
    // glPopMatrix();
    // glDisable(GL_TEXTURE_2D);




    glPushMatrix();
    glTranslatef(-2.9, 2.2, 3);
    glScalef(.01, 3.5, 2.5);
    drawCube(0.9, 0.7, 0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.9, 2.2, 0);
    glScalef(.01, 3.5, 2.5);
    drawCube(0.9, 0.7, 0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.9, 2.2, -3);
    glScalef(.01, 3.5, 2.5);
    drawCube(0.9, 0.7, 0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.9, 2.2, -6);
    glScalef(.01, 3.5, 2.5);
    drawCube(0.9, 0.7, 0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.9, 2.2, -9);
    glScalef(.01, 3.5, 2.5);
    drawCube(0.9, 0.7, 0.5);
    glPopMatrix();

    // door handle
    glPushMatrix();
    glTranslatef(-2.85, 2.5, 6.3);
    glScalef(.01, .4, .8);
    drawCube(0.3, 0.3, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.85, 2.5, 4.5);
    glScalef(.01, .4, .8);
    drawCube(0.3, 0.3, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.85, 2.5, 0.3);
    glScalef(.01, .4, .8);
    drawCube(0.3, 0.3, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.85, 2.5, -1.5);
    glScalef(.01, .4, .8);
    drawCube(0.3, 0.3, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.85, 2.5, -5.8);
    glScalef(.01, .4, .8);
    drawCube(0.3, 0.3, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.85, 2.5, -7.5);
    glScalef(.01, .4, .8);
    drawCube(0.3, 0.3, 0.2);
    glPopMatrix();
}

void windowShelf()
{

    // main cabinet
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glPushMatrix();
    glTranslatef(-4.9, -6, -9.9);
    glScalef(11.5, 5, 3);
    drawCube(0.8, 0.5, 0.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // top white part
    glPushMatrix();
    glTranslatef(-4.9, -1, -9.9);
    glScalef(11.5, .6, 3.2);
    drawCube(.7, .8, .7);
    glPopMatrix();

    // glass part
    glPushMatrix();
    glTranslatef(.6, -5.2, -6.9);
    glScalef(3, 3, .1);
    drawCube(.7, .8, .7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, -1.9, -6.9);
    glScalef(1.4, .5, .1);
    drawCube(.7, .8, .7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.2, -1.9, -6.9);
    glScalef(.3, .5, .3);
    drawCube(.7, .8, .7);
    glPopMatrix();

    // glPushMatrix();
    // glTranslatef(2.3,-1.9,-6.9);
    // glScalef(.3,.5,.3);
    // drawCube(.7, .8, .7);
    // glPopMatrix();

    glPushMatrix();
    glTranslatef(.8, -1.9, -6.9);
    glScalef(.3, .5, .3);
    drawCube(.7, .8, .7);
    glPopMatrix();

    // glPushMatrix();
    // glTranslatef(-0.8,-1.9,-6.9);
    // glScalef(.3,.5,.3);
    // drawCube(.7, .8, .7);
    // glPopMatrix();

    // side bar
    glPushMatrix();
    glTranslatef(4, -5.7, -6.9);
    glScalef(.3, 4.5, .2);
    drawCube(0.9, 0.7, 0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -5.7, -6.9);
    glScalef(.3, 4.5, .2);
    drawCube(0.9, 0.7, 0.5);
    glPopMatrix();

    // handle
    glPushMatrix();
    glTranslatef(4.5, -4, -6.9);
    glScalef(.3, 1.5, .2);
    drawCube(0.3, 0.3, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5, -4, -6.9);
    glScalef(.3, 1.5, .2);
    drawCube(0.3, 0.3, 0.2);
    glPopMatrix();
}
*/
void window()
{
    // window border
    glPushMatrix();
    glTranslatef(-1, 1, -10);
    glScalef(4.5, 6, .1);
    drawCube(0.1, 0.0, 0.0);
    glPopMatrix();

    // window glasses
    glPushMatrix();
    glTranslatef(-.5, 1.5, -9.9);
    glScalef(1.6, 2.3, .1);
    drawCube(0.5, 1.0, 1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6, 1.5, -9.9);
    glScalef(1.6, 2.3, .1);
    drawCube(0.5, 1.0, 1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-.5, 4.3, -9.9);
    glScalef(1.6, 2.3, .1);
    drawCube(0.5, 1.0, 1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6, 4.3, -9.9);
    glScalef(1.6, 2.3, .1);
    drawCube(0.5, 1.0, 1.0);
    glPopMatrix();
}


//all about trees,road,car
void root(){

    GLfloat m_amb[] = {1, 1, 1,1};
    GLfloat m_diff[] = {0.000, 0.392, 0.000,1};
    GLfloat m_spec[] = {0.000, 0.392, 0.000,1};
    GLfloat m_sh[] = {30};

    glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, m_spec);
    glMaterialfv(GL_FRONT, GL_SHININESS, m_sh);
    /// root
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,16);
    glPushMatrix();
        glTranslated(11, -3, -17);
        glRotated(90, -1, 0, 0);
        glBegin(GL_POLYGON);
            GLUquadricObj *roo_obj = gluNewQuadric();
            gluQuadricTexture(roo_obj, GL_TRUE);
            gluCylinder(roo_obj, 0.3, 0.3, 15.0, 300.0, 300.0);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void branch()
{
    GLfloat m_amb[] = {0.000, 0.392, 0.000,1};
    GLfloat m_diff[] = {0.000, 0.392, 0.000,1};
    GLfloat m_spec[] = {0.000, 0.392, 0.000,1};
    GLfloat m_sh[] = {30};

    // GLfloat m_amb[] = {1, 1, 1,1};
    // GLfloat m_diff[] = {0.000, 0.392, 0.000,1};
    // GLfloat m_spec[] = {0.000, 0.392, 0.000,1};
    // GLfloat m_sh[] = {30};

    glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, m_spec);
    glMaterialfv(GL_FRONT, GL_SHININESS, m_sh);


    /// branch
    glPushMatrix();
        glTranslated(11, 8.0, -17);
        glRotated(90, -1, 0, 0);
        glutSolidCone(2.5, 4.0, 300, 300);
    glPopMatrix();
    glPushMatrix();
        glTranslated(11, 10.5, -17);
        glRotated(90, -1, 0, 0);
        glutSolidCone(2.5, 4.0, 300, 300);
    glPopMatrix();
}

void tree(){
    glPushMatrix();
    root();
    glPopMatrix();

    glPushMatrix();
    branch();
    glPopMatrix();
}


void circle_3D(GLdouble radius,GLfloat mat_diffuse[])
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    GLUquadric *qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GL_TRUE);

    glRotatef(270, 1, 0, 0);
    gluSphere(qobj, radius, 20, 20);
    gluDeleteQuadric(qobj);
}

void cylinder_3D(GLdouble height,GLdouble rad,GLdouble rad_2,GLfloat mat_diffuse[])
{

    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    GLUquadric *qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GL_TRUE);
    glRotatef(90, 1, 0, 0);

    gluCylinder(qobj,  rad, rad_2, height, 20, 20);
    gluDeleteQuadric(qobj);

}
void tree2()
{
    GLfloat mat_diffuse[] = {.8,.6,0};
    GLfloat mat_diffuse2[] = {1,1,1};

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,16); ///tree2 base
    glPushMatrix();
    glTranslatef(5,2,2);
    cylinder_3D(3,.2,.45,mat_diffuse);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,18); ///Tree_leafs1
    glPushMatrix();
    glTranslatef(5,2.5,1.9);
    glScalef(1.5,0.8,0.7);
    circle_3D(1,mat_diffuse2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,18); ///Tree_leafs1_2
    glPushMatrix();
    glTranslatef(5,2.5,2.5);
    glScalef(1.5,0.8,0.7);
    circle_3D(1,mat_diffuse2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,18); ///Tree_leaf2
    glPushMatrix();
    glTranslatef(4.2,2.0,2.2);
    glScalef(1.5,0.8,0.7);
    circle_3D(0.8,mat_diffuse2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,18); ///Tree_leafs3
    glPushMatrix();
    glTranslatef(5.8,2.0,2.2);
    glScalef(1.5,0.8,0.7);
    circle_3D(0.8,mat_diffuse2);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


}


void drive_way(){

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,11);
    glPushMatrix();
    glTranslatef(-30, -11, 45);
    glScalef(72, 1.5, 17);
    drawCube(1.0, 1.0, 1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(23, -11, 62);
    glScalef(72, 1.5, 18);
    drawCube(1.0, 1.0, 1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


}

void road(){

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 6);
    glPushMatrix();
    glTranslatef(-200, -10, 85);
    glScalef(500, 1.5, 15);
    drawCube(1.0, 1.0, 1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

//all about trees,roads,car end

//all about sun
float sun_y = 600;
void sun()
{
    GLfloat m_amb[] = {1, 0.34, 0.15};
    GLfloat m_diff[] = {1, 0.34, 0.15};
    GLfloat m_spec[] = {1, 0.34, 0.15};
    GLfloat m_sh[] = {30};

    glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, m_spec);
    glMaterialfv(GL_FRONT, GL_SHININESS, m_sh);

    glPushMatrix();
    glTranslatef(0, sun_y, -800);
    glutSolidSphere(50, 50, 50);
    glPopMatrix();
}
//all about sun end



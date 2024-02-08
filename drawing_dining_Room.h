#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <windows.h>
#include "BmpLoader.h"



void drawCube(GLfloat col1, GLfloat col2, GLfloat col3);
void LoadTexture(const char *filename);
static void getNormal3p (GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3);
void tableg(float llen, float lthk);
void table(float tabwid, float tablen, float tabthk, float llen, float lthk);
void cleg(float cllen,float clwid);
void chair(float cblen,float cbwid,float cbthk,float cllen,float clwid);


GLUquadricObj *Cylinder;
GLUquadricObj *Disk;
int flag=-1;
double angle=0;
double maino=0,romo=0,tro=0,tro2=0,tro3=0,wtro = 0,mgo=0,sgo=0; //angle=0,speed=5,


void matprop(GLfloat amb[], GLfloat dif[], GLfloat spec[], GLfloat shi[])
{
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shi);
}

//colors
float red[] = {1.0 ,0.0 ,0.0};
float green[] = {0.0 ,1.0 ,0.0};
float blue[] = {0.0, 0.0 ,1.0};
float yellow[] = {1.0 ,1.0, 0.0};
float purple[] = {1.0 ,0.0,1.0};
float cyan[] = {0.0 ,1.0, 1.0};
float white[] = {1.0 ,1.0 ,1.0};
float acwhite[] = {1,1,1};
float orange[] = {1.0 ,0.5, 0.0};
float greenish_yellow[] = {0.5, 1.0 ,0.0};
float light_green[] = {0.5, 1.0 ,0.5};
float dark_green[] = {0.0, 0.5, 0.0};
float magenta[] = {1,0,1};
float violet[] = {0.5f, 0.5f, 0.5f};
float baby_blue[]= {0.0f, 0.5f, 1.0f};
float lilac[] ={2.0f, 0.5f, 1.0f};
float dark_grey[] = {0.1f, 0.1f, 0.1f};
float dark_purple[] = {0.1f, 0.0f, 0.1f};
float bronze[] ={0.1f, 0.1f, 0.0f};
float dark_blue[] = {0.0f, 0.1f, 0.1f};
float forest_green[] = {0.0f, 0.1f, 0.0f};
float brown[] = {0.1f, 0.0f, 0.0f};
float light_blue[] = {0.0f, 1.0f, 1.0f, 1.0f};
float chair_wood[] = {.20,.14,.14};
float table_wood[] = {.30,.14,.14};
float bed_wood[] = {.568,.318,.004};
float pillow_color[] = {0,1,.7};
float closet_wood[] = {.1,.1,.1};
float plastic_black[] = {.8,.8,.8};
float tiles_white[] = {.7,.7,.7};
float grey[] = {.4,.4,.4};






void dCube(float x, float y, float z, float xheight, float yheight, float zheight, float color[],float shine=60)
{

    GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat mat_ambient[] = {color[0] * .3, color[1] * .3, color[2] * .3, 1.0};
    GLfloat mat_diffuse[] = {color[0], color[1], color[2], 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {shine};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    static GLfloat v_cube[8][3] =
        {
            {0.0, 0.0, 0.0}, // 0
            {0.0, 0.0, 1.0}, // 1
            {1.0, 0.0, 1.0}, // 2
            {1.0, 0.0, 0.0}, // 3
            {0.0, 1.0, 0.0}, // 4
            {0.0, 1.0, 1.0}, // 5
            {1.0, 1.0, 1.0}, // 6
            {1.0, 1.0, 0.0}  // 7
        };

    static GLubyte quadIndices[6][4] =
        {
            {0, 1, 2, 3}, // bottom
            {4, 5, 6, 7}, // top
            {5, 1, 2, 6}, // front
            {0, 4, 7, 3}, // back is clockwise
            {2, 3, 7, 6}, // right
            {1, 5, 4, 0}  // left is clockwise
        };

    glBegin(GL_QUADS);
    for (GLint i = 0; i < 6; i++)
    {
        getNormal3p(v_cube[quadIndices[i][0]][0], v_cube[quadIndices[i][0]][1], v_cube[quadIndices[i][0]][2],
                    v_cube[quadIndices[i][1]][0], v_cube[quadIndices[i][1]][1], v_cube[quadIndices[i][1]][2],
                    v_cube[quadIndices[i][2]][0], v_cube[quadIndices[i][2]][1], v_cube[quadIndices[i][2]][2]);
        glVertex3fv(&v_cube[quadIndices[i][0]][0]);glTexCoord2f(1,1);
        glVertex3fv(&v_cube[quadIndices[i][1]][0]);glTexCoord2f(1,0);
        glVertex3fv(&v_cube[quadIndices[i][2]][0]);glTexCoord2f(0,0);
        glVertex3fv(&v_cube[quadIndices[i][3]][0]);glTexCoord2f(0,1);
    }
    glEnd();
}


// void drawSphere()
// {
//     GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
//     GLfloat mat_ambient[] = {0.5, 0.0, 0.0, 1.0};
//     GLfloat mat_diffuse[] = {1.0, 0.0, 0.0, 1.0};
//     GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
//     GLfloat mat_shininess[] = {60};

//     glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
//     glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
//     glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//     glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

//     glutSolidSphere(3.0, 20, 16);
// }

void double_sofa()
{
    // structure of left sofa
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,5);
    glPushMatrix();
    glTranslatef(-27, -7, 25);
    glScalef(4, 1, 10);
    drawCube(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-27, -7, 25);
    glScalef(1, 5, 10);
    drawCube(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-27, -10, 25);
    glScalef(4, 7, .5);
    drawCube(1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-27, -10, 34.5);
    glScalef(4, 7, .5);
    drawCube(1, 1, 1);
    glPopMatrix();
    //structure of left sofa end



    glDisable(GL_TEXTURE_2D);

    //seats of the sofa

    //middle sofa
    glPushMatrix();
    glScalef(2, .5, 9.5);
    glTranslatef(-12.7,-12,2.7);
    dCube(0,0,0,1,1,1,red);
    glPopMatrix();

    glPushMatrix();
    glScalef(.5, 3.5, 9);
    glTranslatef(-52,-1.6,2.84);
    dCube(0,0,0,1,1,1,red);
    glPopMatrix();
    //middle sofa end




}




void tableg(float llen, float lthk)
{
    glPushMatrix();
    glRotated(-90, 1, 0, 0);
    Cylinder = gluNewQuadric();
    gluCylinder(Cylinder, lthk, lthk, llen, 32, 32);
    glPopMatrix();
}
void table(float tabwid, float tablen, float tabthk, float llen, float lthk)
{
    glPushMatrix();
    glPushMatrix();
    glTranslated(0, llen, 0);
    glScaled(tabwid, tabthk, tablen);
    glutSolidCube(1);
    glPopMatrix();
    float dist1 = .95 * tablen / 2 - lthk / 2;
    float dist2 = .95 * tabwid / 2 - lthk / 2;
    // front right leg
    glPushMatrix();
    glTranslated(dist2, 0, dist1);
    tableg(llen, lthk);
    glPopMatrix();
    // back right leg
    glPushMatrix();
    glTranslated(dist2, 0, -dist1);
    tableg(llen, lthk);
    glPopMatrix();
    // back left leg
    glPushMatrix();
    glTranslated(-dist2, 0, -dist1);
    tableg(llen, lthk);
    glPopMatrix();
    // front left leg
    glPushMatrix();
    glTranslated(-dist2, 0, dist1);
    tableg(llen, lthk);
    glPopMatrix();
    glPopMatrix();
}

void cot(float cwid, float clen, float cthk, float llen, float lthk)
{

    GLfloat ambient_table[] = {0.8, 0.5, 0.0, 1};
    GLfloat specular_table[] = {0.8, 0.5, 0.0, 1};
    GLfloat diffuse_table[] = {0.8, 0.5, 0.0, 1};
    GLfloat mat_shininess_table[] = {50};
    matprop(ambient_table, specular_table, diffuse_table, mat_shininess_table);

    glPushMatrix();
    glTranslated(5.6, 0, .5);
    table(cwid, clen, cthk, llen, lthk);
    glPopMatrix();
    // glPushMatrix();
    // glTranslated(0, llen, clen / 2);
    // GLdouble eqn[3] = {0.0, 1.0, 0.0};
    // glPushMatrix();
    // glClipPlane(GL_CLIP_PLANE0, eqn); // void glClipPlane(GLenum plane, const GLdouble *equation);
    // glEnable(GL_CLIP_PLANE0);         // enable clip plane
    // gluDisk(Disk, 0, cwid / 2, 32, 32);
    // glPopMatrix();
    // glDisable(GL_CLIP_PLANE0);
    // glPopMatrix();
    // glPushMatrix();
    // glTranslated(0, llen, -clen / 2);
    // glPushMatrix();
    // glClipPlane(GL_CLIP_PLANE0, eqn);
    // glEnable(GL_CLIP_PLANE0);
    // glScaled(1, 1.5, 1);
    // gluDisk(Disk, 0, cwid / 2, 32, 32);
    // glPopMatrix();
    // glDisable(GL_CLIP_PLANE0);
    // glPopMatrix();
    // glPopMatrix();
}

void cleg(float cllen,float clwid)
{
glRotated(90,1,0,0);
gluCylinder(Cylinder,clwid,clwid,cllen,32,32);
}



void closet(int basex, int basey,float topsize, float px, float py, float pz)
{

    glPushMatrix();
    glTranslatef(px,py,pz);


    //basebottom
    glPushMatrix();
    glScalef(basex, 1, basey);
    glTranslatef(-0.5,-12,-0.5);
    dCube(0,0,0,1,1,1,closet_wood);
    glPopMatrix();

    //basetop
    glPushMatrix();
    glScalef(basex, 1, basey);
    glTranslatef(-0.5,8,-0.5);
    dCube(0,0,0,1,1,1,closet_wood);
    glPopMatrix();


    //legs
    glPushMatrix();
    glTranslatef(8.5,-2.5,3);
    glScalef(1,topsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,closet_wood);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-8.5,-2.5,3);
    glScalef(1,topsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,closet_wood);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8.5,-2.5,-3);
    glScalef(1,topsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,closet_wood);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-8.5,-2.5,-3);
    glScalef(1,topsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,closet_wood);
    glPopMatrix();

    //side connector

    glPushMatrix();
    glTranslatef(7,-2,0);
    glScalef(1,topsize-3,basey-2);
    glTranslatef(-0.1, -0.5, -0.5);
    dCube(0,0,0,1,1,1,closet_wood,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7.5,-2,.5);
    glScalef(1,topsize-3,basey-2);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,closet_wood,20);
    glPopMatrix();



    //top leg connector


    glPushMatrix();
    glTranslatef(0,-2,-3);
    glScalef(basex-2,23,2.5);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,closet_wood,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-2,2.5);
    glScalef(basex-2,23,2.5);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,closet_wood,20);
    glPopMatrix();

    //door


    glPushMatrix();
    glTranslatef(4.5,-2,3);
    glScalef(basex-12,20,2);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,grey);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.5,-2,3);
    glScalef(basex-12,20,2);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,grey);
    glPopMatrix();

    //handle

    glPushMatrix();
    glTranslatef(2.5,1.75,4);
    glScalef(.5,2,1);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,white);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.5,1.75,4);
    glScalef(.5,2,1);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,white);
    glPopMatrix();


    glPopMatrix();


}




void closet(){

    //closet
    glPushMatrix();
    glScalef(.4,.7,.4);
    glRotatef(90,0,1,0);
    glTranslatef(15,.5,-65);
    closet(18,7,26,0,0,0);
    glPopMatrix();
    //closet end


}











void book(float color[])
{
    //side cover
    glPushMatrix();
    glTranslatef(0,0,20);
    glScalef(2.5,5,.2);
    drawCube(color[0], color[1], color[2]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,21);
    glScalef(2.5,5,.2);
    drawCube(color[0], color[1], color[2]);
    glPopMatrix();
    //side cover end

    //back cover
    glPushMatrix();
    glTranslatef(2.3,0,20);
    glScalef(.2,5,1);
    drawCube(color[0], color[1], color[2]);
    glPopMatrix();
    //back cover end

    //pages
    glPushMatrix();
    glTranslatef(0,0,20);
    glScalef(2.4,4.7,1);
    drawCube(1,1,1);
    glPopMatrix();
    //pages end
}


void books(){
    glPushMatrix();
    glTranslatef(-28, -9, 18);
    glScalef(.6,.6,.5);
    book(blue);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-28, -9, 17.5);
    glScalef(.6,.6,.5);
    book(green);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, -9, 17);
    glScalef(.6,.6,.5);
    book(yellow);
    glPopMatrix();
}


void bookshelf(){



    //base
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,5);
    //back side
    glPushMatrix();
    glTranslatef(-28, -9, 13);
    glScalef(.3,17,25);
    drawCube(1,1,1);
    glPopMatrix();
    //back side end

    //right and left side
    glPushMatrix();
    glTranslatef(-28, -9, 13);
    glScalef(3,17,.3);
    drawCube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, -9, 38);
    glScalef(3,17,.3);
    drawCube(1,1,1);
    glPopMatrix();
    //right and left side end

    //top and bottom side
    glPushMatrix();
    glTranslatef(-28, 8, 13);
    glScalef(3,.3,25.2);
    drawCube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, -9, 13);
    glScalef(3,.3,25);
    drawCube(1,1,1);
    glPopMatrix();
    //top and bottom side end


    //middle horizontal side
    glPushMatrix();
    glTranslatef(-28,2, 13);
    glScalef(3,.3,25.2);
    drawCube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, -3, 13);
    glScalef(3,.3,25);
    drawCube(1,1,1);
    glPopMatrix();
    //middle horizontal side end

    //middle vertical side
    glPushMatrix();
    glTranslatef(-28, -9, 23);
    glScalef(3,17,.3);
    drawCube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, -9, 33);
    glScalef(3,17,.3);
    drawCube(1,1,1);
    glPopMatrix();
    //middle vertical side end

    glDisable(GL_TEXTURE_2D);

    //books

    //bottom shelf

    glPushMatrix();
    glTranslatef(-28, -9, 23);
    glScalef(.8,.8,.6);
    book(blue);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, -9, 24);
    glScalef(.8,.8,.6);
    book(green);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, -9, 25);
    glScalef(.8,.8,.6);
    book(yellow);
    glPopMatrix();




    glPushMatrix();
    glTranslatef(-28, -9, 18);
    glScalef(.8,.8,.6);
    book(blue);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-28, -9, 17);
    glScalef(.8,.8,.6);
    book(green);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, -9, 16);
    glScalef(.8,.8,.6);
    book(yellow);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, -9, 15);
    glScalef(.8,.8,.6);
    book(red);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, -9, 14);
    glScalef(.8,.8,.6);
    book(green);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, -9, 13);
    glScalef(.8,.8,.6);
    book(blue);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-28, -9, 8);
    glScalef(.8,.8,.6);
    book(blue);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, -9, 7);
    glScalef(.8,.8,.6);
    book(red);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, -9, 6);
    glScalef(.8,.8,.6);
    book(blue);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, -9, 5);
    glScalef(.8,.8,.6);
    book(green);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, -9, 4);
    glScalef(.8,.8,.6);
    book(yellow);
    glPopMatrix();
    //bottom shelf end



    //middle shelf
    float y = -2.5;

    glPushMatrix();
    glTranslatef(-28, y, 23);
    glScalef(.8,.8,.6);
    book(blue);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-28, y, 24);
    glScalef(.8,.8,.6);
    book(green);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, y, 25);
    glScalef(.8,.8,.6);
    book(yellow);
    glPopMatrix();




    glPushMatrix();
    glTranslatef(-28, y, 18);
    glScalef(.8,.8,.6);
    book(blue);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-28, y, 17);
    glScalef(.8,.8,.6);
    book(green);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, y, 16);
    glScalef(.8,.8,.6);
    book(yellow);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, y, 15);
    glScalef(.8,.8,.6);
    book(red);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, y, 14);
    glScalef(.8,.8,.6);
    book(green);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, y, 13);
    glScalef(.8,.8,.6);
    book(blue);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, -9, 12);
    glScalef(.8,.8,.6);
    book(red);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-28, y, 8);
    glScalef(.8,.8,.6);
    book(blue);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, y, 7);
    glScalef(.8,.8,.6);
    book(red);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, y, 6);
    glScalef(.8,.8,.6);
    book(blue);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, y, 5);
    glScalef(.8,.8,.6);
    book(green);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, y, 4);
    glScalef(.8,.8,.6);
    book(yellow);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, y, 3);
    glScalef(.8,.8,.6);
    book(red);
    glPopMatrix();
    //middle shelf end

    //top shelf
    float yy = 3;

    glPushMatrix();
    glTranslatef(-28, yy, 22);
    glScalef(.8,.8,.6);
    book(red);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, yy, 23);
    glScalef(.8,.8,.6);
    book(blue);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-28, yy, 24);
    glScalef(.8,.8,.6);
    book(green);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, yy, 25);
    glScalef(.8,.8,.6);
    book(yellow);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-28, 8.7, 15);
    glScalef(.8,.8,.6);
    glRotatef(20,1,0,0);
    book(blue);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, 8.7, 14);
    glScalef(.8,.8,.6);
    glRotatef(20,1,0,0);
    book(red);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, 8.7, 13);
    glScalef(.8,.8,.6);
    glRotatef(20,1,0,0);
    book(green);
    glPopMatrix();




    glPushMatrix();
    glTranslatef(-28, yy, 8);
    glScalef(.8,.8,.6);
    book(blue);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, yy, 7);
    glScalef(.8,.8,.6);
    book(red);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, yy, 6);
    glScalef(.8,.8,.6);
    book(blue);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, yy, 5);
    glScalef(.8,.8,.6);
    book(green);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, yy, 4);
    glScalef(.8,.8,.6);
    book(yellow);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-28, yy, 3);
    glScalef(.8,.8,.6);
    book(red);
    glPopMatrix();

    //books end
}


void monitor(float px, float py, float pz,   float monitor_screen[])
{

    glPushMatrix();
    glTranslatef(px,py,pz);

    //monitor
    glPushMatrix();
    glTranslatef(0,-1,0);
    glScalef(4,3.5,.2);
    dCube(0,0,0,1,1,1,plastic_black);
    glPopMatrix();

    //display

    glPushMatrix();

    glTranslatef(.2,-.8,0.1);
    glScalef(3.7,3.2,.11);
    dCube(0,0,0,1,1,1,monitor_screen);

    glPopMatrix();

    //stand vertical
    glPushMatrix();
    glTranslatef(1.5,-2,-.2);
    glScalef(1,3,.2);
    dCube(0,0,0,1,1,1,plastic_black);
    glPopMatrix();


    //stand base
    glPushMatrix();
    glTranslatef(1.25,-2,-.5);
    glScalef(1.5,.2,1);
    dCube(0,0,0,1,1,1,plastic_black);
    glPopMatrix();



    glPopMatrix();
}

void keyboard(float px, float py, float pz)
{

    glPushMatrix();
    glTranslatef(px,py,pz);

    //base
    glPushMatrix();

    glScalef(1.5,.2,.7);
    dCube(0,0,0,1,1,1,plastic_black);
    glPopMatrix();



    //keys part 1
    glPushMatrix();
    glTranslatef(1.1,0.2,0.1);
    glScalef(.3,.1,.5);
    dCube(0,0,0,1,1,1,tiles_white);
    glPopMatrix();



    //keys part2
    glPushMatrix();
    glTranslatef(0.07,0.2,0.1);
    glScalef(1,.1,.5);
    dCube(0,0,0,1,1,1,tiles_white);
    glPopMatrix();




    glPopMatrix();
}

void pctable(int basex, int basey,float legsize, float px, float py, float pz )
{

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
    glPushMatrix();
    glTranslatef(px,py,pz);


    //base
    glPushMatrix();
    glScalef(basex, 1, basey);
    glTranslatef(-0.55,0,-0.5);
    dCube(0,0,0,1,1,1,table_wood);
    glPopMatrix();


    //legs
    glPushMatrix();
    glTranslatef(5,-2.5,3);
    glScalef(.5,legsize,.5);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,table_wood);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6,-2.5,3);
    glScalef(.5,legsize,.5);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,table_wood);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,-2.5,-3);
    glScalef(.5,legsize,.5);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,table_wood);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6,-2.5,-3);
    glScalef(.5,legsize,.5);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,table_wood);
    glPopMatrix();


    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void chair(int basex, int basey,float legsize, float topsize, float px, float py, float pz )
{


    glPushMatrix();
    glTranslatef(px,py,pz);


    //base
    glPushMatrix();
    glScalef(basex, 1, basey);
    glTranslatef(-0.5,0,-0.5);
    dCube(0,0,0,1,1,1,chair_wood);
    glPopMatrix();


    //legs
    glPushMatrix();
    glTranslatef(3,-2.5,3);
    glScalef(1,legsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,chair_wood);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3,-2.5,3);
    glScalef(1,legsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,chair_wood);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3,-2.5,-3);
    glScalef(1,legsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,chair_wood);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3,-2.5,-3);
    glScalef(1,legsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,chair_wood);
    glPopMatrix();

    //leg top

    glPushMatrix();
    glTranslatef(3,3,-3);
    glScalef(1,topsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,chair_wood);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3,3,-3);
    glScalef(1,topsize,1);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,chair_wood);
    glPopMatrix();


    //top leg connector
    glPushMatrix();
    glTranslatef(0,4.5,-3);
    glScalef(5,3,1);
    glTranslatef(-0.5, -0.5, -0.5);
    dCube(0,0,0,1,1,1,chair_wood);
    glPopMatrix();


    glPopMatrix();


}

void macmini(){
    glPushMatrix();
    glTranslatef(-8,0, 40);
    glScalef(1.6,1.35,1.4);
    drawCube(.7,.7,.7);
    glPopMatrix();



    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 7);
    glPushMatrix();
    glTranslatef(-6.5,.4, 40.2);
    glScalef(1.4,1,.9);
    glRotatef(-90,0,1,0);
    drawCube(.7,.7,.7);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}


void libraryroom(){
    glPushMatrix();
    bookshelf();
    glPopMatrix();


}


//computer for officer
void computer(){
    //computer setup
    glPushMatrix();
    glTranslatef(-12,-3, 16);
    pctable(12,7,7,0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,0, 16);
    monitor(0,0,0,white);
    glPopMatrix();

    glPushMatrix();
    glScalef(1.3,1,1);
    glTranslatef(-7,-2, 20);
    keyboard(0,0,-2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5,-2,-25);
    macmini();
    glPopMatrix();


    glPushMatrix();
    glScalef(.4,.7,.4);
    glTranslatef(-28,-7,53);
    glRotatef(180,0,1,0);
    chair(7,7,6,8,0,0,0);
    glPopMatrix();

    //computer setup end
}

//all about gates
void gate(void)
{
    int i;
    GLfloat ambient1[] = {.5, .5, 1, 1};
    GLfloat specular1[] = {1, 1, 1, 1};
    GLfloat diffuse1[] = {.5, .5, .5, 1};
    GLfloat mat_shininess[] = {120};
    matprop(ambient1, diffuse1, specular1, mat_shininess);
    glPushMatrix();
    // if flag mgo=1 the open the main gate
    if (mgo == 1)
        glTranslated(1.5, 0, 0);
    glTranslated(-1.3, 0, 6);
    // top frame of the main gate
    glPushMatrix();
    glTranslated(0, 1.5, 0);
    glScaled(1.7, .04, .04);
    glutSolidCube(1);
    glPopMatrix();
    // bottom frame of main gate
    glPushMatrix();
    glTranslated(0, .05, 0);
    glScaled(1.7, .04, .04);
    glutSolidCube(1);
    glPopMatrix();
    // left frame of the main gate
    glPushMatrix();
    glTranslated(-.8, .75, 0);
    glScaled(.04, 1.5, .04);
    glutSolidCube(1);
    glPopMatrix();
    // right frame of the main gate
    glPushMatrix();
    glTranslated(.8, .75, 0);
    glScaled(.04, 1.5, .04);
    glutSolidCube(1);
    glPopMatrix();
    // horizantal pipes of the main gate
    for (i = 1; i <= 3; i++)
    {
        glPushMatrix();
        glTranslated(-.85, .4 * i, 0);
        glRotated(90, 0, 1, 0);
        gluCylinder(Cylinder, .02, .02, 1.7, 32, 32);
        glPopMatrix();
    }
    // vertical strips of the main gate
    for (i = 1; i <= 5; i++)
    {
        glPushMatrix();
        glTranslated(-.9 + .3 * i, .75, 0);
        glScaled(.2, 1.5, .02);
        glutSolidCube(1);
        glPopMatrix();
    }
    glPopMatrix();
}

void sgate(void)
{
    int i;
    GLfloat ambient1[] = {1, .5, 1, 1};
    GLfloat specular1[] = {1, 1, 1, 1};
    GLfloat diffuse1[] = {.5, .5, .5, 1};
    GLfloat mat_shininess[] = {120};
    matprop(ambient1, diffuse1, specular1, mat_shininess);
    glPushMatrix();
    // to open the sub gate
    glTranslated(5.75 - .25, .05, 6);
    glRotated(sgo, 0, 1, 0);
    glTranslated(-5.75 + .25, -.05, -6);
    // to translate sub gate to required position
    glTranslated(5.75, .05, 6);
    // top edge of the sub gate
    glPushMatrix();
    glTranslated(0, 1.5, 0);
    glScaled(.5, .08, .08);
    glutSolidCube(1);
    glPopMatrix();
    // bottom edge of the sub gate
    glPushMatrix();
    glTranslated(0, .05, 0);
    glScaled(.5, .08, .08);
    glutSolidCube(1);
    glPopMatrix();
    // left edge of the sub gate
    glPushMatrix();
    glTranslated(-.25, .85, 0);
    glScaled(.04, 1.7, .04);
    glutSolidCube(1);
    glPopMatrix();
    // right edge of the sub gate
    glPushMatrix();
    glTranslated(.25, .8, 0);
    glScaled(.04, 1.6, .04);
    glutSolidCube(1);
    glPopMatrix();
    // vertical pipes of the sub gate
    for (i = 1; i <= 4; i++)
    {
        glPushMatrix();
        glTranslated(-.25 + .1 * i, 0, 0);
        glRotated(-90, 1, 0, 0);
        gluCylinder(Cylinder, .01, .01, 1.5, 32, 32);
        glPopMatrix();
    }
    // horizantal pipes of the sub gate
    for (i = 1; i <= 4; i++)
    {
        glPushMatrix();
        glTranslated(-.25, .05 + .3 * i, 0);
        glRotated(90, 0, 1, 0);
        gluCylinder(Cylinder, .02, .02, .5, 32, 32);
        glPopMatrix();
    }
    glPopMatrix();
}


//all about door
void make_door(double thickness)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 10);
    glPushMatrix();
    glTranslated(2, .5 * thickness, 2);
    glScaled(4.0, thickness, 4.0);
    drawCube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void door()
{

    glPushMatrix();
    glTranslated(2.3, 0, (2 - .05));
    glRotated(-tro, 0, 1, 0);
    glTranslated(-2.3, 0, -(2 - .05));
    glPushMatrix();
    glTranslated(1.927, 0, 2);
    glScaled(.09, .525, 1);
    glRotated(-90.0, 1, 0, 0);
    make_door(0.02);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void door2()
{

    glPushMatrix();
    glTranslated(2.3, 0, (2 - .05));
    glRotated(-tro2, 0, 1, 0);
    glTranslated(-2.3, 0, -(2 - .05));
    glPushMatrix();
    glTranslated(1.927, 0, 2);
    glScaled(.09, .525, 1);
    glRotated(-90.0, 1, 0, 0);
    make_door(0.02);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void door3()
{

    glPushMatrix();
    glTranslated(2.3, 0, (2 - .05));
    glRotated(-tro3, 0, 1, 0);
    glTranslated(-2.3, 0, -(2 - .05));
    glPushMatrix();
    glTranslated(1.927, 0, 2);
    glScaled(.09, .525, 1);
    glRotated(-90.0, 1, 0, 0);
    make_door(0.02);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

//all about door end







//all about fan
void fanwing(float winglen)
{
    glPushMatrix();
    glRotated(90, 1, 0, 0);
    glRotated(90, 0, 1, 0);
    glScaled(1, 15, 1);
    gluCylinder(Cylinder, .01, .01, 1, 4, 1);
    glPopMatrix();
}
void fanbottom()
{
    glPushMatrix();
    glTranslated(1, 3.2, 1);
    glPushMatrix();
    glRotated(90, 1, 0, 0);
    gluCylinder(Cylinder, .2, .2, .05, 128, 16);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, -.05, 0);
    glRotated(90, 1, 0, 0);
    gluCylinder(Cylinder, .2, .15, .1, 128, 16);
    glPopMatrix();


    GLUquadric *qobj = gluNewQuadric();
    glPushMatrix();
    glTranslated(0, -.1, 0);
    glRotatef(270, 1, 0, 0);
    gluSphere(qobj, .2, 20, 20);
    gluDeleteQuadric(qobj);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.1, 0.0, 0);
    fanwing(.6);
    glPopMatrix();

    glPushMatrix();
    glRotated(120, 0, 1, 0);
    glTranslated(.1, 0, 0);
    fanwing(.6);
    glPopMatrix();

    glPushMatrix();
    glRotated(240, 0, 1, 0);
    glTranslated(0.1, 0.0, 0);
    fanwing(.6);
    glPopMatrix();
    glPopMatrix();
}
void ceiling_fan(void)
{
    glPushMatrix();
    glTranslated(2.5, 1.9, 0);
    glScaled(.5, .5, .5);
    GLfloat mat_ambient[] = {.5, 0, 0, 1};
    GLfloat mat_specular[] = {0, 1, 1, 0};
    GLfloat mat_diffuse[] = {.8, 1, .8, 1};
    GLfloat mat_shininess[] = {50};
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glPushMatrix();
    glTranslated(1, 0, 1);
    glRotated(angle, 0, 1, 0);
    glTranslated(-1, 0, -1);
    fanbottom();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1, 3.3, 1);
    glRotated(-90, 1, 0, 0);
    gluCylinder(Cylinder, .1, 0.005, .25, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1, 4, 1);
    glRotated(90, 1, 0, 0);
    gluCylinder(Cylinder, .006, 0.006, .6, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1, 3.96, 1);
    glRotated(90, 1, 0, 0);
    gluCylinder(Cylinder, .1, 0.005, .25, 16, 16);
    glPopMatrix();
    glPopMatrix();
    if (flag == 1)
    glutPostRedisplay();
}

//all about fan end


//all about drawing room window

void grills(){
    int i;
    GLfloat ambient1[] = {.3, .3, .3, 1};
    GLfloat specular1[] = {1, 1, 1, 1};
    GLfloat diffuse1[] = {.5, .5, .5, 1};
    GLfloat mat_shininess[] = {120};
    matprop(ambient1, diffuse1, specular1, mat_shininess);
    glPushMatrix();
    // if flag mgo=1 the open the main gate

    glTranslated(-1.3, 0, 6);
    // top frame of the main gate
    glPushMatrix();
    glTranslated(0, 1.5, 0);
    glScaled(1.7, .04, .04);
    glutSolidCube(1);
    glPopMatrix();
    // bottom frame of main gate
    glPushMatrix();
    glTranslated(0, .05, 0);
    glScaled(1.7, .04, .04);
    glutSolidCube(1);
    glPopMatrix();
    // left frame of the main gate
    glPushMatrix();
    glTranslated(-.8, .75, 0);
    glScaled(.04, 1.5, .04);
    glutSolidCube(1);
    glPopMatrix();
    // right frame of the main gate
    glPushMatrix();
    glTranslated(.8, .75, 0);
    glScaled(.04, 1.5, .04);
    glutSolidCube(1);
    glPopMatrix();
    // horizantal pipes of the main gate
    for (i = 1; i <= 3; i++)
    {
        glPushMatrix();
        glTranslated(-.85, .4 * i, 0);
        glRotated(90, 0, 1, 0);
        gluCylinder(Cylinder, .02, .02, 1.7, 32, 32);
        glPopMatrix();
    }
    // vertical strips of the main gate
    for (i = 1; i <= 5; i++)
    {
        glPushMatrix();
        glTranslated(-.9 + .3 * i, .75, 0);
        // glScaled(.2, 1.5, .02);
        glScaled(.04, 1.5, .04);
        glutSolidCube(1);
        glPopMatrix();
    }
    glPopMatrix();
}


void make_wdoor(double thickness)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 20);
    glPushMatrix();
    glTranslated(2, .5 * thickness, 2);
    glScaled(4.0, thickness, 4.0);
    drawCube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void windowdoor()
{

    glPushMatrix();
    glTranslated(2.3, 0, (2 - .05));
    glRotated(-wtro, 0, 1, 0);
    glTranslated(-2.3, 0, -(2 - .05));
    glPushMatrix();
    glTranslated(1.927, 0, 2);
    glScaled(.09, .525, 1);
    glRotated(-90.0, 1, 0, 0);
    make_wdoor(0.02);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();


}






// all about drawing room window

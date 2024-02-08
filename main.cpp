#include <bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <windows.h>
#include "BmpLoader.h"
#include "module1.h"
#include "drawing_dining_Room.h"
#define GL_CLAMP_TO_EDGE 0x812F

using namespace std;

double Txval = 0, Tyval = 0, Tzval = 0;
double windowHeight = 700, windowWidth = 700;

void day_night_transition();
// GLfloat eyeX = 0, eyeY = 5, eyeZ = 20;
// GLfloat x=0,y=0,z=0;
// GLfloat xaxis = 2, lookY = 0, lookZ = 0;
// double rollAngle = 0;

// munna
GLfloat beta =0.0;

float camx=17,camy=17,camz=0,up_x=0.0, up_y=1.0, up_z=0.0, atm_door=0, main_door=0;
double eyex = 0, eyey = 20, eyez = 145, cash_z=37.95;



// float camx=-29,camy=-9,camz=19,up_x=0.0, up_y=1.0, up_z=0.0; //test

// double eyex = 0, eyey = 5, eyez = 20;

// double eyex = 5, eyey = 20, eyez = 30; //test

bool atmDoorOpen=false, atmDoorClose=true;

double x = 0, y = 0, z = 0;
double xaxis = 0, yaxis = 1, zaxis = 0;
double scaleX = 1, scaleY = 1, scaleZ = 1;
GLfloat alpha = 0.0, theta = 0.0, axis_x = 0.0, axis_y = 1.0;
GLboolean bRotate = true, uRotate = false;
// GLdouble eX = 5,eY = 3, eZ = 10, cX = 2, cY = 0, cZ = 0, uX = 0, uY = 0, uZ = 0;

// bRotate = !bRotate;
// uRotate = false;
//         axis_x = 0.0;
//         axis_y = 1.0;

double lpan = 0, rpan = 0, fdist = 0;
double dx = 2, dy = 0, dz = 0;
double yaw = 0, pitch = 0, roll = 0;
double PI = 3.14;

double sx = 1, sy = 1, sz = 1;
float door_z1 = 56.9, door_x1 = -19.5,door_z2 = 56.9, door_x2 = -19.5,door_z3 = 56.9, door_x3 = -19.5;
bool door1_status = false, wdoor = false,wdoor_status = false;

bool fan = false;
bool fan_flag = false;
bool sun_status = false;


float lm = 0.6;
GLfloat light_ambient[] = {lm, lm, lm, 1.0};
GLfloat light_diffuse[] = {0.1, 0.1, 0.1, 1.0};
GLfloat light_specular[] = {0.1, 0.1, 0.1, 1.0};
GLfloat light_position[] = {0.0, 8.0, 10.0, 1.0};

GLfloat light_ambient2[] = {0.0, 0.0, 0.0, 1.0};
GLfloat light_diffuse2[] = {0.0, 0.0, 0.0, 1.0};
GLfloat light_specular2[] = {0.0, 0.0, 0.0, 1.0};
// GLfloat light_position2[] = {0.0, 5.0, 5.0, 1.0};
GLfloat light_position2[] = {0, 0, 0, 1.0};



// GLfloat mat_ambient[4];
float table_lamp = 0, table_lamp_street = 0;


GLboolean l1 = false;
GLboolean l2 = false;
GLboolean l_spot = false;




static void getNormal3p
(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}



void LoadTexture(const char*filename,int rep = 0)//, int rep = 1
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if(rep)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }
    else
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }


    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}


//Sreya's Path
/*
void texture_function()
{
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\4532-wood-texture.bmp",1);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\grass.bmp",2);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\exterior-modern-granules-wall-texture.bmp",3);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\barrel.bmp",4);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\img6.bmp",5);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\road2.bmp",6);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\aa.bmp",7);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\wall7.bmp",8);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\chocolate.bmp",9);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\door.bmp",10);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\floor3.bmp",11);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\sunset.bmp",12);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\sky_3..bmp",13);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\soil_2.bmp",14);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\night_sky.bmp",15);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\wood1.bmp",16);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\wood.bmp",17);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\leaf6.bmp",18);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\night_sky2.bmp",19);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\window1.bmp",20);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\cash_counter.bmp",21);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\ucb.bmp",22);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\atm.bmp",23);
    LoadTexture("D:\\7th semester\\CGIPL\\Final_Project_try2\\texture_images\\vault2.bmp",24);

}*/
//joy's path

void texture_function()
{
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\4532-wood-texture.bmp",1);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\grass.bmp",2);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\exterior-modern-granules-wall-texture.bmp",3);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\barrel.bmp",4);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\img6.bmp",5);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\road2.bmp",6);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\aa.bmp",7);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\wall7.bmp",8);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\chocolate.bmp",9);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\door.bmp",10);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\floor3.bmp",11);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\sunset.bmp",12);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\sky_3.bmp",13);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\soil_2.bmp",14);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\night_sky.bmp",15);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\wood1.bmp",16);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\wood.bmp",17);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\leaf6.bmp",18);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\night_sky2.bmp",19);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\window1.bmp",20);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\cash_counter.bmp",21);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\ucb.bmp",22);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\atm.bmp",23);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\vault2.bmp",24);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\window.bmp",25);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\ucb_atm.bmp",26);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\upay.bmp",27);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\note2.bmp",28);
    LoadTexture("C:\\Users\\User\\Desktop\\CGIPL\\CGIPL FINAL\\sreya_cgipl\\sreya_cgipl\\texture_images\\card.bmp",29);

}

void sky()
{
    GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat mat_ambient[] = {.5, 1.0, 1.0, 1.0};
    GLfloat mat_diffuse[] = {.5, 1.0, 1.0, 1.0};
    GLfloat mat_specular[] = {.5, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {60};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glEnable(GL_TEXTURE_2D);

    GLUquadric *qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GL_TRUE);

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, 13);
    glRotatef(270, 1, 0, 0);
    gluSphere(qobj, 1000, 20, 20);
    gluDeleteQuadric(qobj);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}
float night_sky_rad=1100;
void night_sky()
{
    GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat mat_ambient[] = {.5, 1.0, 1.0, 1.0};
    GLfloat mat_diffuse[] = {.5, 1.0, 1.0, 1.0};
    GLfloat mat_specular[] = {.5, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {60};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glEnable(GL_TEXTURE_2D);

    GLUquadric *qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GL_TRUE);

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, 19);
    glRotatef(270, 1, 0, 0);
    gluSphere(qobj, night_sky_rad, 20, 20);
    gluDeleteQuadric(qobj);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}

void atm(){

    float t_y = -9;
    float s_y = 22;

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 25);
    glTranslatef(-13, t_y, 49.75);
    glRotatef(atm_door, 0, 1, 0);
    glScalef(5.7, 14.7, .2);
    drawCube(1, 1, 1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void mainDoor(){
    float t_y = -9;
    float s_y = 22;
    //main gate left
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 25);
    glTranslatef(7.52, t_y, 49.5);
    glRotatef(main_door, 0, 1, 0);
    glScalef(5, 15, .1);
    drawCube(1, 1, 1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //main gate right
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 25);
    glTranslatef(17.6, t_y, 49.5);
    glRotatef(180+(main_door*(-1)), 0, 1, 0);
    glScalef(5, 15, .1);
    drawCube(1, 1, 1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();



}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // glFrustum(-8, 7, -7, 7, 10, 100);

    // glFrustum(-8 + lpan, 7 + rpan, -7, 7, 8 + fdist, 100);
    // glFrustum(-10 + lpan, 10 + rpan, -10, 10, 7 + fdist, 100); // testing
    // gluPerspective(90, 1, .1, 100);
    gluPerspective(90, 1, .09, 100000000); //test

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // gluLookAt(0,3,20,  2,0,0,  0,1,0);
    // gluLookAt(eyex, eyey, eyez, x + dx, y + dy, z + dz, xaxis, yaxis, zaxis);
    gluLookAt(eyex,eyey,eyez,camx,camy,camz,up_x,up_y,up_z);

    glViewport(0, 0, 1900, 1000);

    // glRotatef(-90, 0, 1, 0);
    // glRotatef( theta, axis_x, axis_y, 0.0 );

    glScalef(scaleX, scaleY, scaleZ);

    glPushMatrix();
    Walls();
    glPopMatrix();


    //sky
    glPushMatrix();
    glTranslatef(3,3,3);
    glRotatef( theta, axis_x, axis_y, 0.0 );
    sky();
    glPopMatrix();
    //sky end

    glPushMatrix();
    glRotatef(-90,0,1,0);
    glTranslatef(-11.5,-3,-21);
    //topShelf();
    //windowShelf();
    window();
    //leftCabinet();

    glPopMatrix();


    // all about exhaust fan
    //glPushMatrix();
    //glRotatef(-90,0,1,0);
    //glTranslatef(-14,-2.5,-20.5);
    //glPushMatrix();
    //glTranslatef(-4.8, 8.3, 2);
    //glRotatef(83.5, 0, 1, 0);
    //glutSolidTorus(.3, 1.3, 15, 20);
    //glPopMatrix();

    //glPushMatrix();
    //glTranslatef(-4.8, 8.3, 2);
    //glScalef(.04, .04, .04);
    //glRotatef(83.5, 0, 1, 0);
    //exhaust_fan();
    //glPopMatrix();
    //glPopMatrix();
    // all about exhaust fan end


    //Sitting area sofa right side
    glPushMatrix();
    glRotatef(180,0,1,0);
    glTranslatef(-2,0,-72);
    double_sofa();
    glPopMatrix();

    //Sitting area sofa left side
    glPushMatrix();
    glRotatef(360,0,1,0);
    glTranslatef(30,0,12);
    double_sofa();
    glPopMatrix();




    // //sitting area right side table
    glPushMatrix();
    glScalef(6,8,10);
    glTranslatef(-1.9,-1,3.7);
    cot(.6, .9, .06, .35, .009);
    glPopMatrix();


    //sitting area left side table
    glPushMatrix();
    glScalef(6,8,10);
    glTranslatef(-4.4,-1,3.8);
    cot(.6, .9, .06, .35, .009);
    glPopMatrix();
    //sitting area  table end
    //sitting area end


    //Manager's  room




    //manager's room closet
    glPushMatrix();
    glTranslatef(-10,1,43);
    glRotatef(270,0,1,0);
    closet();
    glPopMatrix();

    //Manger's room

    glPushMatrix();
    libraryroom();
    glPopMatrix();


    //manager's room pc
    glPushMatrix();
    glTranslatef(-23,1,35);
    glRotatef(180,0,1,0);
    glScalef(.7,1,1);
    computer();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-15,5,13);
    glScalef(4,4,4);
    glRotatef(-90,1,0,0);
    glutSolidCone(0.5, 0.5, 500,500);
    glPopMatrix();

    glPushMatrix();
    tableLamp();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15,27,24);
    glRotatef(90,1,0,0);
    books();
    glPopMatrix();

    glPushMatrix();
    glScalef(6,6,6);
    glTranslatef(-5,-1.7,4);
    ceiling_fan();
    glPopMatrix();

    //Manager's room end

    //testing a computer
    glPushMatrix();
    glTranslatef(12,2,2);
    glRotatef(85,0,1,0);
    glScalef(.6,1,.8);
    computer();
    glPopMatrix();


    //testing a computer2
    glPushMatrix();
    glTranslatef(12,2,8);
    glRotatef(85,0,1,0);
    glScalef(.6,1,.8);
    computer();
    glPopMatrix();


    //testing a computer3
    glPushMatrix();
    glTranslatef(12,2,14);
    glRotatef(85,0,1,0);
    glScalef(.6,1,.8);
    computer();
    glPopMatrix();


    //testing a computer4
    glPushMatrix();
    glTranslatef(12,2,20);
    glRotatef(85,0,1,0);
    glScalef(.6,1,.8);
    computer();
    glPopMatrix();

    //tree, road, car
    glPushMatrix();
    glTranslatef(-48,-6,60);
    tree();
    glPopMatrix();

    //MY CODE TREE CHANGE
    glPushMatrix();
    glTranslatef(-48,-6,90);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-48,-6,85);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-48,-6,80);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-48,-6,70);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-48,-6,75);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-48,-6,65);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-48,-6,95);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-48,-6,55);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-48,-6,50);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(23,-10,68);
    glScalef(3,6,3);
    tree2();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-48,-6,100);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-45,-6,100);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-35,-6,100);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(23,-10,60);
    glScalef(3,6,3);
    tree2();
    glPopMatrix();

    glPushMatrix();
    glScalef(.6,.5,.58);
    glTranslatef(-80,-9,109);
    glRotatef(90,0,1,0);
    drive_way();
    glPopMatrix();
    //tree, road, car end

    //gate and doors
    glPushMatrix();
    glTranslatef(-9,-10,57);
    glScalef(6,6,4);
    gate();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(door_x1,-18,door_z1);
    glScalef(10,9,15);
    glRotatef(90,0,1,0);
    door();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,0,-35);
    glPushMatrix();
    glTranslatef(door_x2,-18,door_z2);
    glScalef(10,9,15);
    glRotatef(90,0,1,0);
    door2();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,23.3);
    glPushMatrix();
    glTranslatef(door_x3,-18,door_z3);
    glScalef(10,9,15);
    glRotatef(90,0,1,0);
    door3();
    glPopMatrix();
    glPopMatrix();
    //gate and doors end

    //main road
    glPushMatrix();
    road();
    glPopMatrix();
    //main road end





    //street light
    glPushMatrix();
    streetlight();
    glPopMatrix();
    //street light end


    //sun
    //glPushMatrix();
    //sun();
    //glPopMatrix();
    //sun end

    //night sky
    glPushMatrix();
    glRotatef( theta, axis_x, axis_y, 0.0 );
    night_sky();
    glPopMatrix();
    //night sky end


    //cash counter
    glPushMatrix();
    glTranslatef(6,-2,-100);
    glScalef(1.2,1.1,1);
    cash_counter();
    glPopMatrix();

    glPushMatrix();
    atm();
    glPopMatrix();

    glPushMatrix();
    mainDoor();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-3.88, -5.5, cash_z);
    glScalef(0.04, 0.05, 0.05);
    //glRotated()
    atm_cash();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.94, -4.2, cash_z-10.3);
    glScalef(0.025, 0.05, 0.15);
    //glRotated()
    atm_card();
    glPopMatrix();



    glutSwapBuffers();
}




void light()
{

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void light2()
{
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient2);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse2);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular2);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position2);
}





void Roll(bool clock = true) {
    if(clock)alpha+=5;
    else alpha-=5;
    up_x = -sin(PI*alpha/180.0);
    up_y = cos(PI*alpha/180);
}
void Yaw(bool clock = true)
{
    if(clock) theta+=5;
    else theta-=5;
    GLfloat dx = 0;     //look_x - eye_x;
    GLfloat dy = 0;     //look_y - eye_y;
    GLfloat dz = -eyez;
    //GLfloat dz = 0;

    GLfloat new_x = dx*cos(theta*PI/180.0)+dz*sin(theta*PI/180.0);
    GLfloat new_y = dy;
    GLfloat new_z = -dx*sin(theta*PI/180.0) +dz*cos(theta*PI/180.0);

    camx = new_x;
    camy = new_y;
    camz = new_z;
}
void Pitch(bool clock = true) {
    // Translate to origin
    if(clock)beta+=5;
    else beta-=5;

    GLfloat dx = 0;//look_x - eye_x;
    GLfloat dy = 0;//look_y - eye_y;
    GLfloat dz = -eyez;
    //GLfloat dz = 0;

    GLfloat new_x = dx;
    GLfloat new_y = dy*cos(beta*PI/180.0)-dz*sin(beta*PI/180.0);
    GLfloat new_z = dy*sin(beta*PI/180.0) +dz*cos(beta*PI/180.0);

    camx = new_x;
    camy = new_y;
    camz = new_z;


    up_z = sin(PI*beta/180.0);
    up_y = cos(PI*beta/180);

}




void specialKey(int key, int x, int y) {

    switch (key)
    {

    case GLUT_KEY_RIGHT:
        camx+=3;
        break;
    case GLUT_KEY_LEFT:
        camx-=3;
        break;
    case GLUT_KEY_UP:
        eyez--;
        camz--;
        break;
    case GLUT_KEY_DOWN:
        eyez++;
        camz++;
        break;
    case GLUT_KEY_F1:
        if (mgo == 0)
            mgo = 1;
        else
            mgo = 0;
        break;
    case GLUT_KEY_F3:
        if (tro == 0){
            tro = 90;
            door_z1+=2;
            door_x1-=1.6;
        }
        else{
            tro = 0;
            door_z1-=2;
            door_x1 = -19.5;
        }
        break;

    case GLUT_KEY_F4:
        if (tro2 == 0){
            tro2 = 90;
            door_z2+=2;
            door_x2-=1.6;
        }
        else{
            tro2 = 0;
            door_z2-=2;
            door_x2 = -19.5;
        }
        break;




    case GLUT_KEY_F2:
        if (tro3 == 0){
            tro3 = 90;
            door_z3+=2;
            door_x3-=1.6;
        }
        else{
            tro3 = 0;
            door_z3-=2;
            door_x3 = -19.5;
        }
        break;






    case GLUT_KEY_F5:
        if(table_lamp == 0){
            spotlight1(1);
            table_lamp = 1;
        }
        break;
    case GLUT_KEY_F6:
        if(table_lamp == 1){
            spotlight1(0);
            table_lamp = 0;
        }
        break;

    case GLUT_KEY_F7:
        if(table_lamp_street == 0){
            spotlight2(1);
            table_lamp_street = 1;
        }
        break;
    case GLUT_KEY_F8:
        if(table_lamp_street == 1){
            spotlight2(0);
            table_lamp_street = 0;
        }
        break;
    case GLUT_KEY_F9:
        light_ambient[0] = 0.6;light_ambient[1] = 0.6;light_ambient[2] = 0.6;light_ambient[3] = 1;
        light_specular[0] = 0.1;light_specular[1] = 0.1;light_specular[2] = 0.1;light_specular[3] = 1;
        light_diffuse[0] = 0.1;light_diffuse[1] = 0.1;light_diffuse[2] = 0.1;light_diffuse[3] = 1;
        light();
        l1 = true;
        break;

    case GLUT_KEY_F10:
        light_ambient[0] = 0.0;light_ambient[1] = 0.0;light_ambient[2] = 0.0;light_ambient[3] = 1.0;
        light_specular[0] = 0.0;light_specular[1] = 0.0;light_specular[2] = 0.0;light_specular[3] = 1.0;
        light_diffuse[0] = 0.0;light_diffuse[1] = 0.0;light_diffuse[2] = 0.0;light_diffuse[3] = 1.0;
        light();
        l1 =false;
        break;



    case GLUT_KEY_F11:
        if(!fan_flag) fan_flag = true;
        else fan_flag = false;
        break;

    case GLUT_KEY_F12:
        //day-night transition
        day_night_transition();
    //day-night transition end
        break;

    case 27:
        exit(1);
    }

    glutPostRedisplay();
}



void myKeyboardFunc(unsigned char key, int x, int y)
{



    switch (key){

    case '.':
        if(atm_door) atm_door=0;
        else atm_door=-90;
        break;
    case '/':
        if(main_door) main_door=0;
        else main_door=-90;
        break;
    case 'w':
        wdoor  =true;
        break;
    case 'W':
        wdoor_status = true;
        break;

    case 'z':
        scaleX+=0.2;
        scaleY+=0.2;
        scaleZ+=0.2;
        break;
    case 'Z':
        scaleX -=0.2;
        scaleY -=0.2;
        scaleZ -=0.2;
        break;

    // case 'z':
    //     eyey++;
    //     camz--;
    //     break;
    // case 'Z':
    //     eyey--;
    //     camz++;
    //     break;

    case 'x':
        eyex++;
        camx++;
        break;
    case 'X':
        eyex--;
        camx--;
        break;


    case 'c':
        eyey++;
        break;
    case 'C':
        eyey--;
        break;


    case 'y':
        Yaw(false);
        break;
    case 'Y':
        Yaw(true);
        break;

    case 'p':
        Pitch(true);
        break;
    case 'P':
        Pitch(false);
        break;

    case 'r':
        Roll(false);
        break;

    case 'R':
        Roll(true);
        break;

    // case 'S':
    // case 's':
    //     bRotate = !bRotate;
    //     uRotate = false;
    //     axis_x = 0.0;
    //     axis_y = 1.0;
    //     break;


    //library room
    case '3':
        eyey = 9;
        eyez = 39;
        eyex = -4;
        camx = -20;
        camy = 0;
        camz = 0;
        break;
    //library room end

    //dining room
    case '4':
        eyey = 11;
        eyez = 28;
        eyex = 4;
        camx = 40;
        camy = 0;
        camz = 0;
        break;
    //dining room end

    //drawing room
    case '1':
        eyey = 11;
        eyez = 50;
        eyex = 1;
        camx = 60;
        camy = 0;
        camz = 0;
        break;
    //drawing room end

    //bed room
    case '2':
        eyey = 11;
        eyez = 10;
        eyex = -4;
        camx = -8.5;
        camy = 5;
        camz = 0;
        break;
    //bed room end

    //kitchen room
    case '5':
        eyey = 11;
        eyez = -7;
        eyex = 1;
        camx = 58;
        camy = 0;
        camz = 0;
        break;
    //kitchen room end


    //front view
    case '6':
        eyey = 20;
        eyez = 145;
        eyex = 0;
        camx = 17;
        camy = 17;
        camz = 0;
        break;
    //front view end

    //top view
    case '7':
        eyey = 100;
        eyez = 0;
        eyex = 1;
        camx = 0;
        camy = 0;
        camz = 0;
        break;
    //top view end

    //back view
    case '8':
        camx=-5,camy=-15,camz=13,up_x=0.0, up_y=1.0, up_z=0.0, atm_door=0, main_door=0, eyex = -3, eyey = 0, eyez = 49;
//        eyey = 20;
//        eyez = -120;
//        eyex = 0;
//        camx = 0;
//        camy = 0;
//        camz = 0;
        break;
    //back view end

    //right view
    case '9':

        camx=-20,camy=-15,camz=12,up_x=0.0, up_y=1.0, up_z=0.0, atm_door=0, main_door=0, eyex = 0, eyey = 0, eyez = 48;
        break;


//        eyey = 20;
//        eyez = 0;
//        eyex = 120;
//        camx = 0;
//        camy = 0;
//        camz = 0;
//        break;
    //right view end

    //left view
    case '0':
        eyey = 20;
        eyez = 0;
        eyex = -120;
        camx = 0;
        camy = 0;
        camz = 0;
        break;
    //left view end





    // fan switch
    case '-':
        if (fan)
            fan = false;
        else
            fan = true;
        break;
    case ',':
        if(cash_z==39.95) cash_z-=2;
        else cash_z+=2;

        break;
    case 27: // Escape key
        exit(1);
    }
}

void animate()
{

    if(atmDoorOpen) atmDoorClose=true,atmDoorOpen=false;
    if(atmDoorClose)atmDoorOpen=true, atmDoorClose=false;
    if (bRotate == true)
    {
        theta += 0.05;
        if (theta > 360.0)
            theta -= 360.0 * floor(theta / 360.0);
        // cout<<axis_x<<"   "<<axis_y<<endl;
    }

    if (uRotate == true)
    {
        alpha += 0.05;
        if (alpha > 360.0)
            alpha -= 360.0 * floor(alpha / 360.0);
    }

    if(lm < 0.09){
        sun_status = true;
        spotlight2(1);
        table_lamp_street = 1;
    }
    if(lm >= .36){
        spotlight2(0);
        table_lamp_street = 0;
    }

    if(sun_y >= 600){
        sun_status = false;
    }

    if (fan)
        speed += 30;

    if(fan_flag)angle += 30;





    glutPostRedisplay();
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // glutInitWindowPosition(500, 200);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1920, 1080);

    glutCreateWindow("Final-Project");
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glutSpecialFunc(specialKey);
    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    light();

    texture_function();



    cout<<"Key mapings: "<<endl;
    cout<<"  Fan on/off: 0"<<endl;
    cout<<"  Sphere rotation: s/S"<<endl;
    cout<<"  light-1 enable: 1"<<endl;
    cout<<"    light-1 ambient effect: 4"<<endl;
    cout<<"    light-1 ambient effect: 5"<<endl;
    cout<<"    light-1 ambient effect: 6"<<endl;
    cout<<"  light-2 enable: 2"<<endl;
    cout<<"    light-2 ambient effect: 7"<<endl;
    cout<<"    light-2 ambient effect: 8"<<endl;
    cout<<"    light-2 ambient effect: 9"<<endl;
    cout<<"  spotlight enable: 3"<<endl;
    cout<<"    spotlight ambient effect: ,"<<endl;
    cout<<"    spotlight ambient effect: ."<<endl;
    cout<<"    spotlight ambient effect: /"<<endl;

    glutMainLoop();

    return 0;
}


void day_night_transition(){
    if(!sun_status){
        lm -= .004;
        light_ambient[0] = lm;
        light_ambient[1] = lm;
        light_ambient[2] = lm;
        light();
        sun_y -= 7;
        night_sky_rad -= 1;
    }

    if(sun_status){
        lm += .004;
        light_ambient[0] = lm;
        light_ambient[1] = lm;
        light_ambient[2] = lm;
        light();
        sun_y += 5;
        night_sky_rad += 1;
    }



}

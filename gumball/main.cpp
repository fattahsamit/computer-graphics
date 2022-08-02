#include<windows.h>
#define GL_SILENCE_DEPRECATION
#include<iostream>
#include<GL/GLUT.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>


void init(void){
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50, 50, -50, 50, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    int i=0;
    for(i; i<=100; i++){
        float v=(float)i/100;
        float angle=2.0f*3.1416f*v;
        float x=rx*cos(angle);
        float y=-ry*sin(angle);
        glVertex2f(cx+x,cy+y);
    }
    glEnd();
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //ears outline
    glColor3f(0,0,0);
    circle(4.2,7.2,3,12);
    glPushMatrix();
    glColor3f(0,0,0);
    glRotatef(25,0,0,1);
    circle(4.2,7.2,-6,10);
    glPopMatrix();

    //ear1
    glColor3f(0.00,0.67,0.80);
    circle(4,7,3,12);

    //ear2
    glPushMatrix();
    glColor3f(0.00,0.67,0.80);
    glRotatef(25,0,0,1);
    circle(4,7,-6,10);
    glPopMatrix();

    //head outline
    glColor3f(0,0,0);
    circle(13.2,15.7,0,0);
    glColor3f(0,0,0);
    circle(13.2,9.2,2.5,-7);

    //head
    glColor3f(0.00,0.67,0.80);
    circle(13,15.5,0,0);
    glColor3f(0.00,0.67,0.80);
    circle(13,9,2.5,-7);

    glPushMatrix();
    glColor3f(0,0,0);
    glRotatef(9,0,0,1);
    circle(10.2,5.2,2,-8.5);
    //teeth
    glColor3f(1,1,1);
    circle(10,5,2,-8.5);
    glPopMatrix();

    //eye
    glPushMatrix();
    glColor3f(0,0,0);
    glRotatef(9,0,0,1);
    circle(4.4,6.2,5,4);
    glColor3f(1,1,1);
    circle(4.2,6,5,4);
    glColor3f(0,0,0);
    circle(2.4,4,5,4);

    //eye2
    glColor3f(0,0,0);
    circle(4.4,6.2,-5,2);
    glColor3f(1,1,1);
    circle(4.2,6,-5,2);
    glColor3f(0,0,0);
    circle(2.4,4,-5,2);
    glPopMatrix();


    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(0,12);
    glVertex2f(5,13);

    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-4,12);
    glVertex2f(-9,9);


    glutSwapBuffers();
}


int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("gumball");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}

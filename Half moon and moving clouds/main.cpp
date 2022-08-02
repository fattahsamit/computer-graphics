#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include<math.h>
#include <stdlib.h>

float v, angle, x, y, p = -10;

void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20.0, 20.0, -20.0, 20.0);
}

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    int i=0;

    for(i; i<=100; i++){
        v = (float)i/100;
        angle = 2.0f*3.1416f*v;
        x = rx*cos(angle);
        y = -ry*sin(angle);
        printf("v = %.2f, x = %.2f, y = %.2f\n", v, x, y);
        glVertex2f(cx+x, cy+y);
    }

    if(p <= 20){
        p = p + 0.001;
        }
    else{
        p = -10;
    }

    glEnd();
}

void Draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 0.0f);
    circle(5,5,3,9);
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(5,5,4,10);

    glColor3f(0.65, 0.65, 0.65);
    circle(3, 3, p, 9);
    glColor3f(0.65, 0.65, 0.65);
    circle(3, 3, p+2.5, 9);
    glColor3f(0.65, 0.65, 0.65);
    circle(3, 3, p-2.5,8);
    glColor3f(0.65, 0.65, 0.65);
    circle(3, 3, p, 7);
    glColor3f(0.65, 0.65, 0.65);
    circle(3, 3, p+4, 7);
    glColor3f(0.65, 0.65, 0.65);
    circle(3, 3, p+5, 8);

    glColor3f(0.65, 0.65, 0.65);
    circle(3, 3, p-13, -4);
    glColor3f(0.65, 0.65, 0.65);
    circle(3, 3, p-15.5, -3);
    glColor3f(0.65, 0.65, 0.65);
    circle(3, 3, p-10.5, -3);
    glColor3f(0.65, 0.65, 0.65);
    circle(3, 3, p-13, -2);
    glColor3f(0.65, 0.65, 0.65);
    circle(3, 3, p-9, -4);
    glColor3f(0.65, 0.65, 0.65);
    circle(3, 3, p-9, -2);
    glColor3f(0.65, 0.65, 0.65);
    circle(3, 3, p-6, -3);

    glColor3f(0.65, 0.65, 0.65);
    circle(2, 2, p-18.5, 9);
    glColor3f(0.65, 0.65, 0.65);
    circle(2, 2, p-16.5, 8);
    glColor3f(0.65, 0.65, 0.65);
    circle(2, 2, p-18, 7);
    glColor3f(0.65, 0.65, 0.65);
    circle(2, 2, p-20, 7);
    glColor3f(0.65, 0.65, 0.65);
    circle(1.5, 1.5, p-20, 9);
    glColor3f(0.65, 0.65, 0.65);
    circle(2, 2, p-21.5, 8);

    glutPostRedisplay();
    glutSwapBuffers();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("half moon and moving clouds");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}

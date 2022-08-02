#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
float p = -10;

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
  //gluOrtho2D(0.0,300.0,0.0,300.0);
}


void Draw(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f( 0.0 ,0.5, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f (-10, -1);
    glVertex2f (10, -1);
    glVertex2f (10, -10);
    glVertex2f (-10, -10);
    glEnd();

    glColor3f( 1.0 ,0.4, 0.0);
    glBegin(GL_QUADS);
    glVertex2f (p, 1);
    glVertex2f (p+10, 1);
    glVertex2f (p+8, -1);
    glVertex2f (p+2, -1);
    glEnd();

    glColor3f( 0.0 ,0.5, 0.0);
    glBegin(GL_QUADS);
    glVertex2f (p+6.5, 4);
    glVertex2f (p+8, 4);
    glVertex2f (p+8, 1);
    glVertex2f (p+6.5, 1);
    glEnd();

    glColor3f( 1.0 ,0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f (p+5.5, 3);
    glVertex2f (p+6.5, 4);
    glVertex2f (p+6.5, 2);
    glVertex2f (p+5.5, 3);
    glEnd();

    if(p<=10){
        p=p+0.0005;
    }
    else{
        p = -10;
    }

    glutPostRedisplay();
    glutSwapBuffers();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Moving Boat");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}

#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
float p = -10;

void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
  //gluOrtho2D(0.0,300.0,0.0,300.0);
}


void Draw(){
    /*
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 1 ,0, 0);
    glBegin(GL_QUADS);
    glVertex2f (p, 3);
    glVertex2f (p+3, 3);
    glVertex2f (p+3, -3);
    glVertex2f (p, -3);
    glEnd();

    if(p<=10){
        p=p+0.0005;
    }
    else{
        p = -10;
    }

    glutPostRedisplay();
    */

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 0 ,1, 0);
    glBegin(GL_QUADS);
    glVertex2f (3, p);
    glVertex2f (3, p+3);
    glVertex2f (-3, p+3);
    glVertex2f (-3, p);
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
    glutCreateWindow("Object Movement");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}

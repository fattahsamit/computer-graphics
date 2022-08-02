#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
  //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //1st body
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.53, 0.42, 0.0);
    glVertex3f (0.56, 0.34, 0.0);
    glVertex3f (0.59, 0.42, 0.0);
    glVertex3f (0.67, 0.45, 0.0);
    glVertex3f (0.59, 0.48, 0.0);
    glVertex3f (0.56, 0.56, 0.0);
    glVertex3f (0.53, 0.48, 0.0);
    glVertex3f (0.45, 0.45, 0.0);
    glEnd();

    //2nd body
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.31, 0.42, 0.0);
    glVertex3f (0.34, 0.34, 0.0);
    glVertex3f (0.37, 0.42, 0.0);
    glVertex3f (0.45, 0.45, 0.0);
    glVertex3f (0.37, 0.48, 0.0);
    glVertex3f (0.34, 0.56, 0.0);
    glVertex3f (0.31, 0.48, 0.0);
    glVertex3f (0.23, 0.45, 0.0);
    glEnd();

    //3rd body
    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.42, 0.53, 0.0);
    glVertex3f (0.45, 0.45, 0.0);
    glVertex3f (0.48, 0.53, 0.0);
    glVertex3f (0.56, 0.56, 0.0);
    glVertex3f (0.48, 0.59, 0.0);
    glVertex3f (0.45, 0.67, 0.0);
    glVertex3f (0.42, 0.59, 0.0);
    glVertex3f (0.34, 0.56, 0.0);
    glEnd();

    //4th body
    glColor3f (0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f (0.42, 0.31, 0.0);
    glVertex3f (0.45, 0.23, 0.0);
    glVertex3f (0.48, 0.31, 0.0);
    glVertex3f (0.56, 0.34, 0.0);
    glVertex3f (0.48, 0.37, 0.0);
    glVertex3f (0.45, 0.45, 0.0);
    glVertex3f (0.42, 0.37, 0.0);
    glVertex3f (0.34, 0.34, 0.0);
    glEnd();


    glutSwapBuffers();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("stars");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}

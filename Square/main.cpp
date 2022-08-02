#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
  //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void Draw()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0, 1, 0);
   glBegin(GL_POLYGON);
   glVertex2f(0.25,0.25);
   glVertex2f(0.25,0.75);
   glVertex2f(0.75,0.75);
   glVertex2f(0.75,0.25);
   glEnd();

   glColor3f(1, 0, 0);
   glBegin(GL_POLYGON);
   glVertex2f(0.30,0.30);
   glVertex2f(0.70,0.30);
   glVertex2f(0.70,0.70);
   glVertex2f(0.30,0.70);
   glEnd();

glutSwapBuffers();
}

int main(int argc,char **argv){


    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Square");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
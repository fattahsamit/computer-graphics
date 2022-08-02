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
    //white
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 1 ,1, 1);
    glBegin(GL_POLYGON);
    glVertex3f (0.25, 0.25, 0.0);
    glVertex3f (0.75, 0.25, 0.0);
    glVertex3f (0.75, 0.60, 0.0);
    glVertex3f (0.25, 0.60, 0.0);
    glEnd();

    //green roof
    glColor3f( 0 ,1, 0);
    glBegin(GL_POLYGON);
    glVertex3f (0.25, 0.60, 0.0);
    glVertex3f (0.75, 0.60, 0.0);
    glVertex3f (0.50, 0.80, 0.0);
    glEnd();

    //blue door
    glColor3f( 0 ,0, 1);
    glBegin(GL_POLYGON);
    glVertex3f (0.45, 0.25, 0.0);
    glVertex3f (0.55, 0.25, 0.0);
    glVertex3f (0.55, 0.50, 0.0);
    glVertex3f (0.45, 0.50, 0.0);
    glEnd();

    //red window left
    glColor3f( 1 ,0, 0);
    glBegin(GL_POLYGON);
    glVertex3f (0.30, 0.35, 0.0);
    glVertex3f (0.40, 0.35, 0.0);
    glVertex3f (0.40, 0.45, 0.0);
    glVertex3f (0.30, 0.45, 0.0);
    glEnd();

    //red window right
    glColor3f( 1 ,0, 0);
    glBegin(GL_POLYGON);
    glVertex3f (0.60, 0.35, 0.0);
    glVertex3f (0.70, 0.35, 0.0);
    glVertex3f (0.70, 0.45, 0.0);
    glVertex3f (0.60, 0.45, 0.0);
    glEnd();

glutSwapBuffers();
}

int main(int argc,char **argv){


    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("House");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}

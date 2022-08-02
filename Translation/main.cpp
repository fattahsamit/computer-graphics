#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

float tx=0.0;
float ty=0.0;
void init(void){
    glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
    glMatrixMode(GL_PROJECTION); // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
    glLoadIdentity();
    glOrtho(-100.0, 100, -100.0, 100.0, -1.0, 1.0);
    //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}

void Draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glColor3f( 1 ,0, 0);
    glTranslatef(tx,ty,0);
    glRectf(-25.0,-25.0,25.0,25.0);
    glPopMatrix();
    glEnd();
    glutSwapBuffers();
}

void spe_key(int key,int x,int y){
    switch(key){
    case GLUT_KEY_LEFT:
    tx-=5;
    glutPostRedisplay();
    break;

    case GLUT_KEY_RIGHT:
    tx+=5;
    glutPostRedisplay();
    break;

    case GLUT_KEY_DOWN:
    ty-=5;
    glutPostRedisplay();
    break;

    case GLUT_KEY_UP:
    ty+=5;
    glutPostRedisplay();
    break;

    default:
    break;
    }
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Translation");
    init();
    glutDisplayFunc(Draw);
    glutSpecialFunc(spe_key);
    glutMainLoop();
    return 0;
}

#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

static GLfloat spin=0.0;
float tx=0.0;
float ty=0.0;

void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100, -100.0, 100.0, -1.0, 1.0);
}

void spinDisplay_left(void){
    spin=spin+1;
    if(spin>360){
        spin=spin-360.0;
    }
    glutPostRedisplay();
}

void Draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glColor3f( 1 ,0, 0);
    glRotatef(spin,0.0,0.0,1.0);
    //glTranslatef(tx,ty,0);
    glRectf(-25.0,-25.0,25.0,25.0);
    glPopMatrix();
    spinDisplay_left();
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
    glutCreateWindow("Spin");
    init();
    glutDisplayFunc(Draw);
    glutSpecialFunc(spe_key);
    glutMainLoop();
    return 0;
}

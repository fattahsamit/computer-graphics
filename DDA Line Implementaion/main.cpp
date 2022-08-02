#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <stdlib.h>

int x1, y1, x2, y2, dx, dy;
float ix, iy, step;

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    gluOrtho2D(0.0,300.0,0.0,300.0);
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 1 ,0, 0);

    dx = abs(x2-x1);
    dy = abs(y2-y1);

    if(abs(dx)>abs(dy)){
        step = abs(dx);
    }
    else{
        step = abs(dy);
    }

    ix = dx/step;
    iy = dy/step;

    float x = x1, y = y1;

    glBegin(GL_POINTS);
    glVertex2i(abs(x),abs(y));

    int i;
    for(i=0; i<step; i++){
        x = x + ix;
        y = y + iy;

        printf("%1f %1f %1f %1f %1f\n",x,y,step,ix,iy);

        glVertex2i(abs(x),abs(y));
    }

    glEnd();

    glutSwapBuffers();
}

int main(int argc,char **argv){

    printf("Please Enter X1 Value:");
    scanf("%d",&x1);
    printf("Please Enter Y1 Value:");
    scanf("%d",&y1);
    printf("Please Enter X2 Value:");
    scanf("%d",&x2);
    printf("Please Enter Y2 Value:");
    scanf("%d",&y2);

    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("DDA Line Implementation");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}

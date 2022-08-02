#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

int c = 0;
void init(void)
{
    glClearColor(0, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 800, 0,600);
}

void drawSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    if (c == 0){
        glColor3f(1, 1, 1);
        c = 1;
        }
    else{
        glColor3f(0, 0, 0);
        c = 0;
        }
    glBegin(GL_POLYGON);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glVertex2i(x4, y4);
    glEnd();
}

void chessboard()
{
    glClear(GL_COLOR_BUFFER_BIT);
    GLint x, y;
    for (x = 0; x <= 800; x += 100){
            for (y = 0; y <= 600; y += 75){
                drawSquare(x, y + 75, x + 100, y + 75, x + 100, y, x, y);
                }
            }
    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Chess Board");
    init();
    glutDisplayFunc(chessboard);
    glutMainLoop();
    return 0;
}

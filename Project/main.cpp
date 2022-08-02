#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

float p = 0, q =902, c=0, c1 = 0, c2 = 902;

void init(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 902.0, 0.0, 684.0);
}

void Sky(){
    glColor3f(0.3,0.5,0.90);
    glBegin(GL_QUADS);
    glVertex2i(0,684);
    glVertex2i(902,684);
    glVertex2i(902,0);
    glVertex2i(0,0);
    glEnd();
}

void homeWindow3(int x,int y){
    glColor3f(0.50,0.56,0.46);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+14,y);
    glVertex2i(x+14,y+13);
    glVertex2i(x,y+13);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(x,y+17);
    glVertex2i(x+14,y+17);
    glVertex2i(x+14,y+30);
    glVertex2i(x,y+30);
    glEnd();
}

void Home(){
    //roof
    glColor3f(0.53,0.11,0.13);
    glBegin(GL_TRIANGLES);
    glVertex2i(69,405);
    glVertex2i(20,385);
    glVertex2i(118,385);
    glEnd();

    glColor3f(0.2,0.2,0.2);
    glBegin(GL_QUADS);
    glVertex2i(20,379);
    glVertex2i(118,379);
    glVertex2i(118,385);
    glVertex2i(20,385);
    glEnd();

    glColor3f(0.75,0.79,0.73);
    glBegin(GL_QUADS);
    glVertex2i(28,370);
    glVertex2i(110,370);
    glVertex2i(110,379);
    glVertex2i(28,379);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(10,330);
    glVertex2i(130,330);
    glVertex2i(130,370);
    glVertex2i(10,370);
    glEnd();

    glColor3f(0.2,0.2,0.2);
    glBegin(GL_QUADS);
    glVertex2i(0,309);
    glVertex2i(141,309);
    glVertex2i(141,331);
    glVertex2i(0,331);
    glEnd();

    glColor3f(0.75,0.79,0.73);
    glBegin(GL_QUADS);
    glVertex2i(5,257);
    glVertex2i(137,257);
    glVertex2i(137,309);
    glVertex2i(5,309);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(52,257);
    glVertex2i(87,257);
    glVertex2i(87,287);
    glVertex2i(52,287);
    glEnd();

    int HomeStripe3=-1;
    for(int i=5;i>=0;i--)
    {
        HomeStripe3+=18;
        homeWindow3(HomeStripe3,335);
    }
}

void Hospital(){
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_QUADS);
    glVertex2i(167,257);
    glVertex2i(181,257);
    glVertex2i(181,400);
    glVertex2i(167,400);
    glEnd();

    glColor3f(0.2,0.2,0.2);
    glBegin(GL_QUADS);
    glVertex2i(435,257);
    glVertex2i(435,400);
    glVertex2i(420,400);
    glVertex2i(420,257);
    glEnd();

    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    glVertex2i(181,381);
    glVertex2i(420,381);
    glVertex2i(420,400);
    glVertex2i(181,400);
    glEnd();

    glColor3f(0.3,0.3,0.30);
    glBegin(GL_QUADS);
    glVertex2i(181,258);
    glVertex2i(420,258);
    glVertex2i(420,381);
    glVertex2i(181,381);
    glEnd();

    glColor3f(0.2,0.2,0.2);//new
    glBegin(GL_QUADS);
    glVertex2i(151,390);
    glVertex2i(181,390);
    glVertex2i(181,401);
    glVertex2i(151,401);
    glEnd();

    glColor3f(0.2,0.2,0.2);
    glBegin(GL_QUADS);
    glVertex2i(420,390);
    glVertex2i(449,390);
    glVertex2i(449,401);
    glVertex2i(420,401);
    glEnd();

    glColor3f(0.11,0.11,0.11);
    glBegin(GL_QUADS);
    glVertex2i(151,415);
    glVertex2i(151,400);
    glVertex2i(449,400);
    glVertex2i(449,415);
    glEnd();

    //middle long stripe
    glColor3f(0.75,0.79,0.73);
    glBegin(GL_QUADS);
    glVertex2i(263,257);
    glVertex2i(339,257);
    glVertex2i(339,400);
    glVertex2i(263,400);
    glEnd();

    //Door
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(286,257);
    glVertex2i(318,257);
    glVertex2i(318,298);
    glVertex2i(286,298);
    glEnd();
}

void drawCircle(GLfloat x, GLfloat y, GLfloat radius){
    int i;
    int triangleAmount = 50;
    GLfloat twicePi = 2.0f*3.1416;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y);
    for(i = 0; i <= triangleAmount; i++){
        glVertex2d(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void HotelAboveWindow1(int x,int y){
    glColor3ub(1,1,1);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+17,y);
    glVertex2i(x+17,y+21);
    glVertex2i(x,y+21);
    glEnd();
}

void Hotel(){
    //down part
    glColor3ub(300,302,302);
    glBegin(GL_QUADS);
    glVertex2i(449,257);
    glVertex2i(644,257);
    glVertex2i(644,289);
    glVertex2i(449,289);
    glEnd();

    //left side part
    glColor3ub(90,90,90);
    glBegin(GL_QUADS);
    glVertex2i(473,289);
    glVertex2i(500,289);
    glVertex2i(500,413);
    glVertex2i(473,413);
    glEnd();

    glColor3ub(170,170,170);
    glBegin(GL_QUADS);
    glVertex2i(500,289);
    glVertex2i(617,289);
    glVertex2i(617,408);
    glVertex2i(500,408);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(526,408);
    glVertex2i(600,408);
    glVertex2i(600,423);
    glVertex2i(526,423);
    glEnd();

    int HotelAboveStripe1=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe1+=24;
        HotelAboveWindow1(HotelAboveStripe1,377);
    }

    int HotelAboveStripe2=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe2+=24;
        HotelAboveWindow1(HotelAboveStripe2,350);
    }

    int HotelAboveStripe3=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe3+=24;
        HotelAboveWindow1(HotelAboveStripe3,323);
    }

    int HotelAboveStripe4=498;
    for(int i=3;i>=0;i--)
    {
        HotelAboveStripe4+=24;
        HotelAboveWindow1(HotelAboveStripe4,295);
    }
}

void Door(){
    glColor3f(0.3,0.5,0.3);
    drawCircle(547.0f,282.0f,22.0f);

    // door
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(524,258);
    glVertex2i(570,258);
    glVertex2i(570,281);
    glVertex2i(524,281);
    glEnd();

    // door middle
    glColor3f(0.40,0.20,0);
    glBegin(GL_QUADS);
    glVertex2i(528,280);
    glVertex2i(546,280);
    glVertex2i(546,257);
    glVertex2i(528,257);
    glEnd();

    // door middle
    glColor3f(0.40,0.20,0);
    glBegin(GL_QUADS);
    glVertex2i(548,257);
    glVertex2i(565,257);
    glVertex2i(565,280);
    glVertex2i(548,280);
    glEnd();
}

void SchoolWindow1(int x,int y){
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+20,y);
    glVertex2i(x+20,y+17);
    glVertex2i(x,y+17);
    glEnd();
}

void School(){
    glColor3f(0.85,0.85,0.85);
    glBegin(GL_QUADS);
    glVertex2i(643,257);
    glVertex2i(884,257);
    glVertex2i(884,405);
    glVertex2i(643,405);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(640,405);
    glVertex2i(887,405);
    glVertex2i(887,412);
    glVertex2i(640,412);
    glEnd();

    glColor3ub(90,30,30);
    glBegin(GL_QUADS);
    glVertex2i(640,412);
    glVertex2i(887,412);
    glVertex2i(837,462);
    glVertex2i(690,462);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(648,265);
    glVertex2i(719,265);
    glVertex2i(719,275);
    glVertex2i(648,275);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(808,265);
    glVertex2i(879,265);
    glVertex2i(879,275);
    glVertex2i(808,275);
    glEnd();

    int SchoolStripe1=623;
    for(int i=2;i>=0;i--){
        SchoolStripe1+=25;
        SchoolWindow1(SchoolStripe1,330);
    }

    int SchoolStripe2=623;
    for(int i=2;i>=0;i--){
        SchoolStripe2+=25;
        SchoolWindow1(SchoolStripe2,305);
    }

    int SchoolStripe3=623;
    for(int i=2;i>=0;i--){
        SchoolStripe3+=25;
        SchoolWindow1(SchoolStripe3,280);
    }

    int SchoolStripe4=783;
    for(int i=2;i>=0;i--){
        SchoolStripe4+=25;
        SchoolWindow1(SchoolStripe4,330);
    }

    int SchoolStripe5=783;
    for(int i=2;i>=0;i--){
        SchoolStripe5+=25;
        SchoolWindow1(SchoolStripe5,305);
    }

    int SchoolStripe6=783;
    for(int i=2;i>=0;i--){
        SchoolStripe6+=25;
        SchoolWindow1(SchoolStripe6,280);
    }
    int SchoolStripe7=623;
    for(int i=2;i>=0;i--){
        SchoolStripe7+=25;
        SchoolWindow1(SchoolStripe7,355);
    }


    int SchoolStripe8=623;
    for(int i=2;i>=0;i--){
        SchoolStripe8+=25;
        SchoolWindow1(SchoolStripe8,380);
    }

    int SchoolStripe9=783;
    for(int i=2;i>=0;i--){
        SchoolStripe9+=25;
        SchoolWindow1(SchoolStripe9,355);
    }

    int SchoolStripe10=783;
    for(int i=2;i>=0;i--){
        SchoolStripe10+=25;
        SchoolWindow1(SchoolStripe10,380);
    }

    int SchoolStripe11=704;
    for(int i=2;i>=0;i--){
        SchoolStripe11+=25;
        SchoolWindow1(SchoolStripe11,355);
    }

    int SchoolStripe12=704;
    for(int i=2;i>=0;i--){
        SchoolStripe12+=25;
        SchoolWindow1(SchoolStripe12,380);
    }
}

void SchoolDoor(){
    glColor3ub(94,94,94);
    glBegin(GL_QUADS);
    glVertex2i(728,257);
    glVertex2i(797,257);
    glVertex2i(797,321);
    glVertex2i(728,321);
    glEnd();

    glColor3ub(79,34,34);
    glBegin(GL_TRIANGLES);
    glVertex2i(722,321);
    glVertex2i(803,321);
    glVertex2i(763,347);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(743,257);
    glVertex2i(782,257);
    glVertex2i(782,295);
    glVertex2i(743,295);
    glEnd();
}

void Sun(){
    glColor3f(0.9,0.9,0);
    drawCircle(624.0f,615.0f,40.0f);
}

void HouseFrontTree(){
    for(float i=0; i<5*130;i+=245){
        glColor3ub(204,102,0);
        glBegin(GL_QUADS);
        glVertex2i(140+i,256);
        glVertex2i(148+i,256);
        glVertex2i(148+i,285);
        glVertex2i(140+i,285);
        glEnd();

        glColor3ub(37,90,27);
        drawCircle(144.0f+i,288.0f,10.0f);
        drawCircle(150.0f+i,281.0f,9.0f);
        drawCircle(157.0f+i,286.0f,7.0f);
        drawCircle(134.0f+i,291.0f,12.0f);
        drawCircle(138.0f+i,300.0f,13.0f);
        drawCircle(144.0f+i,299.0f,7.0f);
        drawCircle(150.0f+i,299.0f,10.0f);
     }
}

void Road(){
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(0,148);
    glVertex2i(902,148);
    glVertex2i(902,47);
    glVertex2i(0,47);
    glEnd();
    glPopMatrix();

    for(int i=0;i<120*8;i+=120){
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,95);
        glVertex2i(35+i,95);
        glVertex2i(35+i,100);
        glVertex2i(0+i,100);
        glEnd();
        glPopMatrix();
    }
}

void RoadGrass(){
    glPushMatrix();
    glColor3ub(0,153,0);
    glBegin(GL_QUADS);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(902.0,0.0,0.0);
    glVertex3f(902.0,47.0,0.0);
    glVertex3f(0.0,47.0,0.0);
    glEnd();
    glPopMatrix();
}

void BetweenRoadAndBuldings(){
    glPushMatrix();
    glColor3ub(0,153,0);
    glBegin(GL_QUADS);
    glVertex3f(0.0,220.0,0.0);
    glVertex3f(902.0,220.0,0.0);
    glVertex3f(902.0,258.0,0.0);
    glVertex3f(0.0,258.0,0.0);
    glEnd();
    glPopMatrix();
}

void RoadTree(){
    for(float i=0; i<5*130;i+=245){
        glPushMatrix();
        glColor3ub(204,102,0);
        glBegin(GL_QUADS);
        glVertex2i(250+i,0);
        glVertex2i(258+i,0);
        glVertex2i(258+i,50);
        glVertex2i(250+i,50);
        glEnd();
        glPopMatrix();

        glColor3f(0.04,0.20,0);
        drawCircle(255.0f+i,68.0f,10.0f);
        drawCircle(260.0f+i,61.0f,9.0f);
        drawCircle(267.0f+i,66.0f,7.0f);
        drawCircle(243.0f+i,71.0f,12.0f);
        drawCircle(248.0f+i,60.0f,13.0f);
        drawCircle(244.0f+i,79.0f,7.0f);
        drawCircle(260.0f+i,79.0f,10.0f);
     }
}

void Cloud(){
    glColor3f(1,1,1);
    drawCircle(c+200.0f,610.0f,25.0f);
    drawCircle(c+170.0f,615.0f,38.0f);
    drawCircle(c+139.0f,610.0f,35.0f);
    drawCircle(c+111.0f,598.0f,25.0f);

    drawCircle(c+597.0f,590.0f,20.0f);
    drawCircle(c+572.0f,600.0f,30.0f);
    drawCircle(c+539.0f,600.0f,35.0f);
    drawCircle(c+502.0f,590.0f,23.0f);

    glColor3f(1,1,1);
    drawCircle(c+497.0f,490.0f,20.0f);
    drawCircle(c+472.0f,500.0f,30.0f);
    drawCircle(c+439.0f,500.0f,35.0f);
    drawCircle(c+402.0f,490.0f,23.0f);

    glColor3f(1,1,1);
    drawCircle(c+97.0f,490.0f,20.0f);
    drawCircle(c+72.0f,500.0f,30.0f);
    drawCircle(c+39.0f,500.0f,35.0f);
    drawCircle(c+02.0f,490.0f,23.0f);

    if(c<=950){
        c=c+0.008;
    }
    else{
        c = 0;
    }

    glutPostRedisplay();
}

void Boat1(){
    glColor3f(0.6 ,0.2, 0.0);
    glBegin(GL_QUADS);
    glVertex2f (p, 175);
    glVertex2f (p+90, 175);
    glVertex2f (p+80, 165);
    glVertex2f (p+10, 165);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f (p+30, 185);
    glVertex2f (p+60, 185);
    glVertex2f (p+65, 175);
    glVertex2f (p+25, 175);
    glEnd();

    if(p<=950){
        p=p+0.05;
    }
    else{
        p = 0;
    }

    glutPostRedisplay();
}

void Boat2(){
    glColor3f(0.6 ,0.2, 0.0);
    glBegin(GL_QUADS);
    glVertex2f (q, 205);
    glVertex2f (q-90, 205);
    glVertex2f (q-80, 195);
    glVertex2f (q-10, 195);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f (q-30, 215);
    glVertex2f (q-60, 215);
    glVertex2f (q-65, 205);
    glVertex2f (q-25, 205);
    glEnd();

    if(q>=0){
        q = q-0.05;
    }
    else{
        q = 920;
    }

    glutPostRedisplay();
}

void Car1(){
    //body
    glColor3f(1 ,0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f (c1, 90);
    glVertex2f (c1+80, 90);
    glVertex2f (c1+80, 65);
    glVertex2f (c1, 65);
    glEnd();

    //tire1
    glColor3ub(48,48,46);
    drawCircle(c1+20,65,12);
    glColor3ub(255,255,255);
    drawCircle(c1+20,65,7);
    glColor3ub(0,0,0);

    //tire2
    glColor3ub(48,48,46);
    drawCircle(c1+60,65,12);
    glColor3ub(255,255,255);
    drawCircle(c1+60,65,7);
    glColor3ub(0,0,0);

    if(c1<=950){
        c1 = c1+0.2;
    }
    else{
        c1 = 0;
    }

    glutPostRedisplay();
}

void Car2(){
    //body
    glColor3f(0 , 0, 1);
    glBegin(GL_QUADS);
    glVertex2f (c2, 140);
    glVertex2f (c2-80, 140);
    glVertex2f (c2-80, 115);
    glVertex2f (c2, 115);
    glEnd();

    //tire1
    glColor3ub(48,48,46);
    drawCircle(c2-20,115,12);
    glColor3ub(255,255,255);
    drawCircle(c2-20,115,7);
    glColor3ub(0,0,0);

    //tire2
    glColor3ub(48,48,46);
    drawCircle(c2-60,115,12);
    glColor3ub(255,255,255);
    drawCircle(c2-60,115,7);
    glColor3ub(0,0,0);

    if(c2>=0){
        c2 = c2-0.2;
    }
    else{
        c2 = 920;
    }

    glutPostRedisplay();
}

void Draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    Sky();
    Home();
    Hospital();
    Hotel();
    Door();

    School();
    SchoolDoor();
    HouseFrontTree();

    Road();
    RoadGrass();
    BetweenRoadAndBuldings();

    Sun();
    Cloud();

    Boat1();
    Boat2();

    Car1();
    Car2();
    RoadTree();

    glFlush ();
    glutSwapBuffers();
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowSize(902,684);
    glutInitWindowPosition(250, 30);
    glutCreateWindow("City");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}

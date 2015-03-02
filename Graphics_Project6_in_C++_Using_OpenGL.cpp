Graphics proj6->

#include <iostream>
#include <cmath>
#include <math.h>
#ifdef __APPLE__
# include <GLUT/glut.h>
#else
# include <GL/glut.h>
#endif
using namespace std;

//Global variables
char menu[300];
/*********************************/

void drawMPattern(float minX,float maxX,float minY,float maxY,char vertex){
glColor3f(0,0,0);
if(vertex==x){
for(int i=minY;i<maxY;i+=10){
glBegin(GL_LINE_STRIP);
glVertex3f(minX,maxY,0);
glVertex3f(maxX,maxY,0);
glVertex3f(maxX,minY,0);
glVertex3f(minX,minY,0);
glVertex3f(minX,maxY,0);
glEnd();

} 
}
else{
for(int i=minY;i<maxY;i+=10){
glBegin(GL_LINE_STRIP);
glVertex3f(minX,minY,0);
glVertex3f(minX,maxY,0);
glVertex3f(maxX,maxY,0);
glVertex3f(maxX,minY,0);
glVertex3f(minX,minY,0);
glEnd();

}
}
glFlush();
}

void glPrint(float x, float y, char *string)
{
glColor3f( 0, 0, 1 );
glRasterPos2f(x, y);
int len, i;
len = (int)strlen(string);
for (i = 0; i < len; i++) {
glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
}
}

void printFooterM(){
glPrint(-.65,-.68,(char *)\"(c) 2012 Abel Gancsos\");
}

void printFooterS(){
glPrint(.58,-.98,(char*)\"(c) 2012 Abel Gancsos\");
}


void drawSierpinski(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(1.0, 1.0, 0.0, 0.0);
printFooterS();

glColor3f(1,0,0);
glBegin(GL_TRIANGLES);
glVertex3f(-.8,-.8,0);
glVertex3f(0,.8,0);
glVertex3f(.8,-.8,0);
glEnd();

glutSwapBuffers();
glFlush();
}

void drawMeander(void){
glClearColor(0.0, 1.0, 0.0, 0.0);
glClear(GL_COLOR_BUFFER_BIT);
printFooterM();

glColor3f(.732,.561,.561); 


//Left column
glBegin(GL_POLYGON);
glVertex3f(-1,.7,0);
glVertex3f(-.7,.7,0);
glVertex3f(-.7,-.7,0);
glVertex3f(-1,-.7,0);
glEnd();

//Draw pattern on left
for(float i=-.7;i<=.7;){
glColor3f(1,0,0);

glBegin(GL_LINE_STRIP);
glVertex3f(-.8,i,0);
i+=.10;
glVertex3f(-.8,i,0);
glVertex3f(-.9,i,0);
i+=.10;
glVertex3f(-.9,i,0);
glVertex3f(-.8,i,0);
glEnd();
}

drawMPattern(-.7,-1,-.7,.7,y); //Draw pattern 
glColor3f(.732,.561,.561); //Reset color

//Top column
glBegin(GL_POLYGON);
glVertex3f(-1,1,0);
glVertex3f(1,1,0);
glVertex3f(1,.7,0);
glVertex3f(-1,.7,0);
glEnd();

//Draw pattern on top
for(float i=-1;i<=1;){
glColor3f(1,0,0);

glBegin(GL_LINE_STRIP);
glVertex3f(i,.75,0);
i+=.10;
glVertex3f(i,.75,0);
glVertex3f(i,.9,0);
i+=.10;
glVertex3f(i,.9,0);
glVertex3f(i,.75,0);
glEnd();
}

drawMPattern(-1,1,.7,1,x); //Draw pattern
glColor3f(.732,.561,.561); //Reset color

//Right column
glBegin(GL_POLYGON);
glVertex3f(1,.7,0);
glVertex3f(.7,.7,0);
glVertex3f(.7,-.7,0);
glVertex3f(1,-.7,0);
glEnd();

//Draw pattern on right
for(float i=-.7;i<=.7;){
glColor3f(1,0,0);

glBegin(GL_LINE_STRIP);
glVertex3f(.8,i,0);
i+=.10;
glVertex3f(.8,i,0);
glVertex3f(.9,i,0);
i+=.10;
glVertex3f(.9,i,0);
glVertex3f(.8,i,0);
glEnd();
}

drawMPattern(.7,1,-.7,.7,y); //Draw pattern
glColor3f(.732,.561,.561); //Reset color

//Bottom column
glBegin(GL_POLYGON);
glVertex3f(-1,-1,0);
glVertex3f(1,-1,0);
glVertex3f(1,-.7,0);
glVertex3f(-1,-.7,0);
glEnd();

//Draw pattern on bottom
for(float i=-1;i<=1;){
glColor3f(1,0,0);

glBegin(GL_LINE_STRIP);
glVertex3f(i,-.9,0);
i+=.10;
glVertex3f(i,-.9,0);
glVertex3f(i,-.8,0);
i+=.10;
glVertex3f(i,-.8,0);
glVertex3f(i,-.9,0);
glEnd();
}

drawMPattern(-1,1,-1,-.7,x); //Draw pattern
glColor3f(.732,.561,.561); //Reset color

glutSwapBuffers();
glFlush();
}

void meander(){
glutDisplayFunc(drawMeander);
}

void sierpinski(){
glutDisplayFunc(drawSierpinski);
}

void setup(void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
}

void keyInput(unsigned char key, int x, int y)
{
switch(key)
{
case 27://ESC
exit(0);
break;
//Others

case s:
sierpinski();
break;

case m:
meander();
break;
default:
break;
}
}

void refresh(){
glutPostRedisplay();
}

int main(int argc, char **argv)
{
int option;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(800, 600);
glutInitWindowPosition(400,200);
glutCreateWindow(\"Sierpinski/Meander\"); 
setup();
sierpinski();
glutIdleFunc(refresh);
glutKeyboardFunc(keyInput);
glutMainLoop();
return 0; 
}

/*
	Name:Test2
	Class:Graphics
	Professor:Dr. John Najarian
	Author:Abel Gancsos
	Description:This is the code for questions 1,2,and 4 on Test2
*/
#include <iostream>
#include <math.h>
#include <cmath>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
#define PI 3.1415926535897932384626433832795
using namespace std;

void drawWindows(float x,float y,float size){
	float myX=x,myY=y;
	glBegin(GL_LINE_STRIP);
	glVertex3f(x,y,0);
	glVertex3f(x+size,y,0);
	glVertex3f(x+size,y+size,0);
	glVertex3f(x,y+size,0);
	glVertex3f(x,y,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(myX,myY+.05,0);
	glVertex3f(myX+size,myY+.05,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(myX+.05,myY,0);
	glVertex3f(myX+.05,myY+size,0);
	glEnd();
}

void glPrint(float x, float y, char *string)
{
        glColor3f( 1, 1, 1 );
        glRasterPos2f(x, y);
        int len, i;
        len = (int)strlen(string);
        for (i = 0; i < len; i++) {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
        }
}

void draw1(void){
	//Initials
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	
	//A
        glBegin(GL_LINE_STRIP);
        glVertex3f(-1,-.8,0);
        glVertex3f(-.5,.8,0);
        glVertex3f(-.25,-.8,0);
	glVertex3f(-.5,0,0);
	glVertex3f(-1,-.8,0);
        glEnd();

	//G
	glBegin(GL_LINE_STRIP);
	glVertex3f(.5,.8,0);
	glVertex3f(0,.8,0);
	glVertex3f(0,-.8,0);
	glVertex3f(.5,-.8,0);
	glVertex3f(.5,0,0);
	glVertex3f(.25,0,0);
	glEnd();
        glFlush();
}

void draw2(void){
	//Ship
	glClear(GL_COLOR_BUFFER_BIT);

	//Ship
	glColor3f(1,0,0);

	//Base
	glBegin(GL_POLYGON);
	glVertex3f(-1,-.2,0);
	glVertex3f(1,-.2,0);
	glVertex3f(.9,-.4,0);
	glVertex3f(-.8,-.4,0);
	glEnd();

	//Center
	glBegin(GL_POLYGON);
	glVertex3f(-.5,.2,0);
	glVertex3f(.5,.2,0);
	glVertex3f(.5,-.2,0);
	glVertex3f(-.5,-.2,0);
	glEnd();

	//Steam pipes
	glBegin(GL_POLYGON);
	glVertex3f(-.2,.8,0);
	glVertex3f(-.1,.8,0);
	glVertex3f(-.1,.2,0);
	glVertex3f(-.2,.2,0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(.1,.8,0);
	glVertex3f(.2,.8,0);
	glVertex3f(.2,.2,0);
	glVertex3f(.1,.2,0);
	glEnd();

	//Sea
	glColor3f(0,0,.5);
	glBegin(GL_POLYGON);
	glVertex3f(-1,-.4,0);
	glVertex3f(1,-.4,0);
	glVertex3f(1,-1,0);
	glVertex3f(-1,-1,0);
	glEnd();
	glColor3f(0,0,0);
	glFlush();
}

void draw4(void){
	//Lamp Shade
	glClear(GL_COLOR_BUFFER_BIT);

	float theta, alpha;
    	float radiusTop = .8;
    	float radiusBottom = -.8;
    	float colorP=.5;
    	glBegin(GL_QUAD_STRIP);
    	glVertex3f((R/2)*cos(theta),2,(R/2)*sine(theta));
	glVertex3f(R*cos(theta),0,R*sine(theta));
	theta+=.o5;
	for(;theta<=2*PI;theta+=.05){
		glVertex3f((R/2)*cos(theta),2,(R/2)*sin(theta));
		glVertex3f(R*cos(theta),0,R*sin(theta));
		theta+=.05;
		glVertex3f((R/2)*cos(theta),2,(R/2)*sin(theta));
		glVertex(R*cos(theta),0,R*sin(theta));
	}              
    	
     
	glEnd();
	glFlush();
}



void q1(){
	glutDisplayFunc(draw1);
}

void q2(){
	glutDisplayFunc(draw2);
}

void q4(){
	glutDisplayFunc(draw4);
}

void setup(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void keyInput(unsigned char key, int x, int y)
{
	static float eyeX=0,eyeY=0,eyeZ=0;
	switch(key)
	{
		case 27:
			exit(0);
			break;
		case 1:
			q1();
			break;
		case 2:
			q2();
			break;

		case 4:
			q4();
			break;
		case u:
        		eyeY+=10.0;
        		break;
		default:
			break;
	}
}

void refresh(){
	glPrint(-1,-.95,(char*)\"(c) 2012 Abel Gancsos\");
	glPrint(.75,-.95,(char*)\"1-Q1  2-Q2  4-Q4\");
	glutSwapBuffers();
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
    	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);
    	glutInitWindowSize(1001, 501);
    	glutInitWindowPosition(0,0);
    	glutCreateWindow(\"test2\");
    	setup();
	q1();
    	glutKeyboardFunc(keyInput);
	glutIdleFunc(refresh);
	glutMainLoop();
    	return 0;  
}


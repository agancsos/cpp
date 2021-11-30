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
void green();
/*********************************/
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
 
void printHeader(){
	glPrint(-.5,0,(char*)"SpasmVision");
}

void drawYellow(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 0.0, 0.0);
	printHeader();
 	glutSwapBuffers();
	glutSwapBuffers();
 	glFlush();
	green();
}

void drawGreen(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,1.0,0.0,0.0);
	
	printHeader();
	glColor3f(1,1,1);	

	//Left column
	glBegin(GL_POLYGON);
	glVertex3f(-1,.7,0);
	glVertex3f(-.7,.7,0);
	glVertex3f(-.7,-.7,0);
	glVertex3f(-1,-.7,0);
	glEnd();

	//Top column
	glBegin(GL_POLYGON);
        glVertex3f(-1,1,0);
        glVertex3f(1,1,0);
        glVertex3f(1,.7,0);
        glVertex3f(-1,.7,0);
        glEnd();

	//Right column
	glBegin(GL_POLYGON);
        glVertex3f(1,.7,0);
        glVertex3f(.7,.7,0);
        glVertex3f(.7,-.7,0);
        glVertex3f(1,-.7,0);
        glEnd();

	//Bottom column
	glBegin(GL_POLYGON);
        glVertex3f(-1,-1,0);
        glVertex3f(1,-1,0);
        glVertex3f(1,-.7,0);
        glVertex3f(-1,-.7,0);
        glEnd();

	glutSwapBuffers();
	glFlush();
	glutDisplayFunc(drawYellow);
}
 
void yellow(){
	glutDisplayFunc(drawYellow);
}

void green(){
	glutDisplayFunc(drawGreen);
}

void drawScene(void)
{
	green();
}
 
void flash(){
 	glutDisplayFunc(drawScene);
}
 
void setup(void)
{
 	glClearColor(0.0, 1.0, 0.0, 0.0);
 
}
 
void keyInput(unsigned char key, int x, int y)
{
 	switch(key)
 	{
 		case 27://ESC
 			exit(0);
 			break;
 		//Others
 		default:
 			break;
 	}
}
 
void refresh(){
 	glutPostRedisplay();
}
 
int main(int argc, char **argv)
{
 	glutInit(&argc, argv);
 	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 	glutInitWindowSize(800, 600);
 	glutInitWindowPosition(400,200);
 	glutCreateWindow("SpasmVision");
 	setup();
 	flash();
 	glutIdleFunc(refresh);
 	glutKeyboardFunc(keyInput);
 	glutMainLoop();
 	return 0; 
}


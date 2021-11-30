
/*
	 Author: Abel Gancsos
*/

#include <iostream>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
#include <cmath>
#include <fstream>
using namespace std;

void glPrint(float x, float y, float r, float g, float b,char *string);
void refresh();
void animate(void);
void setup();

GLfloat xangle=33,yangle=50,zangle=30;
float xRotated,yRotated,zRotated;

float enterx[16000],entery[16000],enterz[16000];

void getCoords(){
	float cord;
	int ei=0;
        ifstream myfile("/Volumes/DK/enterprise/test.txt");
        if(myfile.is_open()){                                                                                                  
                while(myfile.good()&& ei<1600){
                        myfile>>cord;
                        enterx[ei]=cord;
                        myfile>>cord;
                        entery[ei]=cord;
                        myfile>>cord;
                        enterz[ei]=cord;
                        ei++;
                }

                myfile.close();
	}
}

/*       Q9 Functions    */
//Starfield
void drawStarField(int max){

	float x2,y2,r2,g2,b2;
	for(int i=0;i<max;i++){
		r2=(float)rand()/(float) RAND_MAX;
        	g2=(float)rand()/(float) RAND_MAX;
                b2=(float)rand()/(float) RAND_MAX;

                x2=(float)((max/4)*rand()/(float) RAND_MAX);
                y2=(float)((max/4)*rand()/(float) RAND_MAX);
		glColor3f(r2,g2,b2);
		glBegin(GL_POINTS);
                glVertex2f(x2, y2);
                glVertex2f(-x2, y2);
                glVertex2f(x2, -y2);
                glVertex2f(-x2, -y2);
                glEnd();
	}
	glFlush();
}
/**********************/

//Torus
void drawTorus(float xRotated,float yRotated,float zRotated){
	GLdouble innerRaidus=0.2;
	GLdouble outterRaidus=0.6;
	GLint sides=50;
	GLint rings=50;
        glRotatef(xRotated,1.0,0.0,0.0);
        glRotatef(yRotated,0.0,1.0,0.0);
        glRotatef(zRotated,0.0,0.0,1.0);
	glColor3f(0.8,0.2,0.1);
	glutWireTorus(innerRaidus,outterRaidus,sides,rings);
	glFlush();
}
/*************************/

//Enterprise-working on
void drawEnter(){
	glColor3f(0.0,1.0,0.0);

	glBegin(GL_LINES);
	for(int i=0;i<16000;i++){
		glVertex3f((float)enterx[i]/30,(float)entery[i]/30,(float)enterz[i]/1);
	}
	glEnd();
	glFlush();
	
}
/*************************/
void q9(void){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glLoadIdentity();
	glPrint(-1.0,-0.95,0.5,0.5,0.5,(char*)"(c) 2012 Abel Gancsos");  //copyright
	glPopMatrix();
	drawStarField(400);
	drawTorus(xangle,yangle,zangle);
	drawEnter();
	glFlush();
	glutIdleFunc(animate);
	sleep(1);
}

/*************************/

void glPrint(float x, float y, float r, float g, float b,char *string)
{
	glColor3f(r,g,b);
	glRasterPos2f(x, y);
	int len, i;
	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}
}

void refresh(){
	glutPostRedisplay();
}

void animate(void){
        yangle+=0.20;
	setup();
        glutDisplayFunc(q9);
	refresh();
}

void setup(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void keyInput(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(0);
			break;
		case '9':
			glutDisplayFunc(q9);
			refresh();
			break;
		default:
			break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(400,200);
	glutCreateWindow("Enterprise");
	setup();
	glScalef(2.0,2.0,1.0);
	getCoords();
	refresh();
	glutDisplayFunc(q9);
	glutPostRedisplay();
	glutKeyboardFunc(keyInput);
	glutMainLoop();
	return 0;
}


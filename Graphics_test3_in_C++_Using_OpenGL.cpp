/*
	Author:Abel Gancsos
	Name:test3.cpp
	Date:2012-11-26
	Class:Graphics
	Professor:Dr. John Najarian
*/
#include <iostream>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
using namespace std;

void refresh(void);
void keyInput(unsigned char key, int x, int y);
static float squareColor[3] = {1.0, 0.0, 0.0};
void glPrint(float x, float y, float r, float g, float b, char *string)
{
        glColor3f(r,g,b);
        glRasterPos2f(x, y);
        int len, i;
        len = (int)strlen(string);
        for (i = 0; i < len; i++) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
        }
}

void glPrint2(float x, float y, float r, float g, float b, char *string)
{
        glColor3f(r,g,b);
        glRasterPos2f(x, y);
        int len, i;
        len = (int)strlen(string);
        for (i = 0; i < len; i++) {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
        }
}


void drawWin2(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glPrint(-1.0,0.0,0.9,0.9,0.9,(char*)\"Gancsos\");
}

void draw1(void){
	//2 Windows with first name and last name
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Screen 1
	glPrint(-1.0,0.0,0.9,0.9,0.9,(char*)\"Abel\");
	glFlush();

	//Screen 2
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(900,400);
        glutCreateWindow(\"Test3|Abel Gancsos|Graphics\");
        glClearColor(1.0, 1.0, 1.0, 0.0);
	glutDisplayFunc(drawWin2);
	glFlush();

}

void draw2(void){
	//List of first initial
	glClear(GL_COLOR_BUFFER_BIT);
	int max=6;
	float x[6]={0.0,-0.7,0.0,0.7,0.0};
	float y[6]={0.7,-0.7,0.0,-0.7,0.0};
	glBegin(GL_POLYGON);
	for(int i=0;i<max;i++){
		glVertex3f(x[i],y[i],0);
	}
	glEnd();	
}

/*                 Q4   Functions                                                  */
void printInteraction(void){
	cout << \"Interaction:\" << endl;
	cout << \"Press the right mouse button to see options.\" << endl; 
}
void colorMenu(int id){
	if (id==2){
		squareColor[0] = 1.0; squareColor[1] = 0.0; squareColor[2] = 0.0; 
	}
	if (id==3){
		squareColor[0] = 0.0; squareColor[1] = 0.0; squareColor[2] = 1.0; 
	}
	if (id==4){
		squareColor[0] = 0.0; squareColor[1] = 1.0; squareColor[2] = 0.0; 
	}
	glutPostRedisplay();
}

void resize(int w, int h){
	glViewport(100, 100, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-80.0, 80.0, -7.00, 50.0, 1.0, 100.0);
	// gluPerspective(90.0, 1.0, 5.0, 100.0);
	// gluPerspective(90.0, (float)w/(float)h, 5.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void topMenu(int id){
	if (id==1) exit(0);
}
void makeMenu(void){
	int subMenu;
	subMenu = glutCreateMenu(colorMenu);
	glutAddMenuEntry(\"Red\", 2);
	glutAddMenuEntry(\"Blue\",3);
	glutAddMenuEntry(\"Green\",4);
	glutCreateMenu(topMenu);
	glutAddSubMenu(\"Color\", subMenu);
	glutAddMenuEntry(\"Quit\",1);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void draw4(void){
	//Teapot using Furstrum and mouse pull down
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3fv(squareColor);
	glutSolidTeapot(0.5);
	glFlush();
}

/***********************************************************************************************/
void drawSpecial(void){
	float r,g,b;
	float x,y;
	int max=2000;
	for(float i=-1;i<max;i+=.002){
		r=(float)rand()/(float) (RAND_MAX);
		g=(float)rand()/(float) (RAND_MAX);
		b=(float)rand()/(float) (RAND_MAX);

		x=(float)rand()/(float) (RAND_MAX);
		y=(float)rand()/(float) (RAND_MAX);
		if(x>=.90) x=.90;
		if(y>=.90) y=.90;

		glColor3f(r,g,b);
		glBegin(GL_POINTS);
		glVertex2f(i,y);
		glEnd();	
	}
}

void refresh(){
	//Print copyright
	glPrint2(-1.0,-0.95,0.7,0.7,0.7,(char*)\"(c) 2012 Abel Gancsos\");
	
	//Print menu
	glPrint2(-1.0,0.95,0.7,0.7,0.7,(char*)\"ESC-Escape 1-Q1 2-Q2 4-Q4 r-Red g-Green b-Blue B-Black\");
	glutPostRedisplay();
	glFlush();
}

void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void keyInput(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(0);
			break;
		case 1:
			glutDisplayFunc(draw1);
			break;
		case 2:
                        glutDisplayFunc(draw2);
                        break;
		case 4:
                        glutDisplayFunc(draw4);
                        break;
		case r:
                        glClearColor(1.0, 0.0, 0.0, 0.0);
                        break;
		case g:
                        glClearColor(0.0, 1.0, 0.0, 0.0);
                        break;
		case b:
                        glClearColor(0.0, 0.0, 1.0, 0.0);
                        break;
		case w:
                        glClearColor(1.0, 1.0, 1.0, 0.0);
                        break;
		case B:
                        glClearColor(0.0, 0.0, 0.0, 0.0);
                        break;
		case s:
			glutDisplayFunc(drawSpecial);
			break;
		default:
			break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
    	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    	glutInitWindowSize(500, 500);
    	glutInitWindowPosition(400,400);
    	glutCreateWindow(\"Test3|Abel Gancsos|Graphics\");
    	setup();
	glutDisplayFunc(draw1);
	refresh();
    	glutKeyboardFunc(keyInput);
	glutIdleFunc(refresh);	
	makeMenu();
	glutMainLoop();
    	return 0;
}


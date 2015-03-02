#include <iostream>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
#include <cmath>
using namespace std;

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
void drawPointTriangle(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
     	glPrint(-1.0,-0.95,0.9,0.9,0.9,(char*)\"(c) 2012 Abel Gancsos\");
	glPrint(-1.0,0.95,0.9,0.9,0.9,(char*)\"ESC-Escape 2-Q2\");

	glBegin(GL_POINTS);
	float hypx=-0.6;
	float hypy=-0.8;
	//My algorithm
	for(float t = -0.8;t<=1 && t<=0.8;t+=0.001){
		for(float s=-1.0;s<=1;s+=0.001){ 
			// Pixel Point = s*A + (1-s)*t*B + (1-s)*(1-t)*C 
			float r,g,b;
			r=(float)rand()/(float) (RAND_MAX);
			g=(float)rand()/(float) (RAND_MAX);
			b=(float)rand()/(float) (RAND_MAX);
	
			float x1=s*sin(60)/s*cos(120);
			float y1=t*cos(60)*s*sin(120);

			float x2=-y1;
			float y2=-x1;

			float x3=-(y2*cos(60));
			float y3=x2*sin(30);

			hypx+=0.0001;
			hypy+=0.0001;

			glColor3f(r,g,b);
			glVertex3f(x1,y1,0);
			glVertex3f(x2+0.19,y2+0.19,0);
			if(hypy<0.45 && hypy>-0.45){
				glVertex3f(hypx,hypy,0);
			}
		}
	}
	glEnd();
	glFlush();
}

void refresh(){
	glutPostRedisplay();
	glFlush();
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
		case 2:
			glutDisplayFunc(drawPointTriangle);
			refresh();
			break;
		default:
			break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0,0);
	glutCreateWindow(\"project10\");
	setup();
	srand((unsigned)time(NULL));
	glutDisplayFunc(drawPointTriangle);
	refresh();
	glutKeyboardFunc(keyInput);
	//glutIdleFunc(refresh);
	glutMainLoop();
	return 0;
}


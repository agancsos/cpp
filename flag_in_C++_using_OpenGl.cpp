/*
 The following code has been modified from the original to work on ALL systems, not just windows.... 
 -_-

 */

/*
 Name:Experiment_2.1
 Author:Abel Gancsos
 Class:Computer Graphics
 Instructor:Dr. Najarian
 Description:To practice with OpenGl by making a 256 X 256 window at (0,0)
*/

#include <iostream>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
using namespace std;

void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix ();

    //Red
    glBegin(GL_POLYGON);
    glVertex3f(.20, .20, 0.0);
    glVertex3f(.80, .20, 0.0);
    glVertex3f(.80, .80, 0.0);
    glVertex3f(.20, .80, 0.0);
    glEnd();

    glColor3f(1.0, 0.6, 1.0);

    //Pink bottom-right
    glBegin(GL_POLYGON);
    glVertex3f(.20, .10, 0.0);
    glVertex3f(.80, .10, 0.0);
    glVertex3f(.80, -.50, 0.0);
    glVertex3f(.20, -.50, 0.0);
    glEnd();

    glColor3f(1.0, 0.6, 1.0);

    //Pink top-left
    glBegin(GL_POLYGON);
    glVertex3f(-.50, .20, 0.0);
    glVertex3f(.10, .20, 0.0);
    glVertex3f(.10, .80, 0.0);
    glVertex3f(-.50, .80, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);

    //Red-bottom-left
    glBegin(GL_POLYGON);
    glVertex3f(-.50, .10, 0.0);
    glVertex3f(.10, .10, 0.0);
    glVertex3f(.10, -.50, 0.0);
    glVertex3f(-.50, -.50, 0.0);
    glEnd();
    
    glPopMatrix ();
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
		default:
			break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(0,0);
    glutCreateWindow(\"Experiment_2.1\");
    setup();
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(keyInput);
	glutMainLoop();
    return 0;  
}


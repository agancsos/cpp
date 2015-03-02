
#include <iostream>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
using namespace std;


void drawHungarian(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix ();
    
    glColor3f(0.9, 0.0, 0.0);
    //Red
    glBegin(GL_POLYGON);
    glVertex3f(-1, .2, 0);
    glVertex3f(1, .2, 0);
    glVertex3f(1, 1, 0);
    glVertex3f(-1, 1, 0);
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    //White
    glBegin(GL_POLYGON);
    glVertex3f(-1, -.5, 0);
    glVertex3f(1, -.5, 0);
    glVertex3f(1, .2, 0);
    glVertex3f(-1, .2, 0);
    glEnd();
    
    glColor3f(0.0, .4, 0.03);
    //Green
    glBegin(GL_POLYGON);
    glVertex3f(-1, -1, 0);
    glVertex3f(1, -1, 0);
    glVertex3f(1, -.4, 0);
    glVertex3f(-1, -.4, 0);
    glEnd();
    
    glPopMatrix ();
    glFlush();
}

void drawItalian(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix ();
    
    glColor3f(0.0, 0.4, 0.0);
    //Green
    glBegin(GL_POLYGON);
    glVertex3f(-1, 1, 0);
    glVertex3f(-.3, 1, 0);
    glVertex3f(-.3, -1, 0);
    glVertex3f(-1, -1, 0);
    glEnd();
    
    glColor3f(1.0, 1.0, 1.0);
    //White
    glBegin(GL_POLYGON);
    glVertex3f(-.3, 1, 0);
    glVertex3f(.3, 1, 0);
    glVertex3f(.3, -1, 0);
    glVertex3f(-.3, -1, 0);
    glEnd();
    
    glColor3f(1.0, 0.0, 0.03);
    //Red
    glBegin(GL_POLYGON);
    glVertex3f(.3, 1, 0);
    glVertex3f(1, 1, 0);
    glVertex3f(1, -1, 0);
    glVertex3f(.3, -1, 0);
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
    int option;
	glutInit(&argc, argv);
    cout<<\"1-Hungarian  2-Italian: \";
    cin>>option;
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 245);
    glutInitWindowPosition(50,50);
    if(option==1){
        glutCreateWindow(\"Hungary\");
    }
    else{
        glutCreateWindow(\"Italian\");
    }
    setup();
    if(option==1){
        glutDisplayFunc(drawHungarian);
    }
    else{
        glutDisplayFunc(drawItalian);
    }
    glutKeyboardFunc(keyInput);
	glutMainLoop();
    return 0;
}


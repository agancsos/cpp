#include <iostream>
#include <cmath>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
using namespace std;

void drawGirl(void){
    glClear(GL_COLOR_BUFFER_BIT);
    
    //Circle
    float radius=3;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    
    for (int i=0; i<360; i++)
    {
        float degInRad2 = i*(10);
        glVertex3f(cos(degInRad2)*radius,sin(degInRad2)*radius,0);
    }
    glEnd();
    
    
    //Triangle
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(-.5, -.5, 0);
    glVertex3f(0, .5, 0);
    glVertex3f(.5, -.5, 0);
    glEnd();
    
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
		default:
			break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50,50);
    glutCreateWindow(\"Ancient\");
    setup();
    glutDisplayFunc(drawGirl);
    glutKeyboardFunc(keyInput);
	glutMainLoop();
    return 0;
}


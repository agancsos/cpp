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
    
    //Head
    float radius=.3;
    glColor3f(.93, .80, .68);
    glBegin(GL_LINE_LOOP);
    
    for (int i=0; i<360; i+=1)
    {
        float degInRad2 = i+.20;
        glVertex2f(0+cos(degInRad2)*radius,.7+sin(degInRad2)*radius);
    }
    glEnd();
    
    
    //Body
    glColor3f(1, 1, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(-.5, -.4, 0);
    glVertex3f(0, .4, 0);
    glVertex3f(.5, -.4, 0);
    glEnd();
    
    //Eyes
    glColor3f(.63, .32, .18);
    radius=.03;
    glBegin(GL_LINE_LOOP);
    for (int i=0; i<360; i+=10)
    {
        float degInRad2 = i+.20;
        glVertex2f(-.08+cos(degInRad2)*radius,.75+sin(degInRad2)*radius);
    }
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    for (int i=0; i<360; i+=10)
    {
        float degInRad2 = i+.20;
        glVertex2f(.08+cos(degInRad2)*radius,.75+sin(degInRad2)*radius);
    }
    glEnd();

    //Lips
    radius=.1;
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    for (int i=0; i<20; i+=5)
    {
        float degInRad2 = i+.20;
        glVertex2f(-.01+cos(degInRad2)*radius,.6+sin(degInRad2)*radius);
    }
    glEnd();
    
    //Legs
    glColor3f(.93, .80, .68);
    glBegin(GL_POLYGON);
    glVertex3f(-.1, -.4, 0);
    glVertex3f(-.1, -.9, 0);
    glVertex3f(-.05, -.9, 0);
    glVertex3f(-.05, -.4, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-.01, -.4, 0);
    glVertex3f(-.01, -.9, 0);
    glVertex3f(.035, -.9, 0);
    glVertex3f(.035, -.4, 0);
    glEnd();

    //Arms
    glColor3f(.93, .80, .68);
    glBegin(GL_POLYGON);
    glVertex3f(-.3, -.1, 0);
    glVertex3f(-.7, .5, 0);
    glVertex3f(-.62, .55, 0);
    glVertex3f(-.25, 0, 0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(.3, -.1, 0);
    glVertex3f(.7, .5, 0);
    glVertex3f(.62, .55, 0);
    glVertex3f(.25, 0, 0);
    glEnd();

    glFlush();
}

void setup(void)
{
	glClearColor(.75, .75, .75, 0.0);
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
    glutCreateWindow(\"Beautiful\");
    setup();
    glutDisplayFunc(drawGirl);
    glutKeyboardFunc(keyInput);
	glutMainLoop();
    return 0;
}


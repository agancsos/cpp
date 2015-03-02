
#include <iostream>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
using namespace std;

static float x,y,height,width;

void drawSquare(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix ();
    
    //Red
    glBegin(GL_POLYGON);
    glVertex3f(x, y, 0.0);
    glVertex3f((x+width), y, 0.0);
    glVertex3f((x+width), (y+height), 0.0);
    glVertex3f(x, (y+height), 0.0);
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
    
    cout<<\"Enter x-origin: \";
    cin>>x;
    cout<<endl;
    cout<<\"Enter y-origin: \";
    cin>>y;
    cout<<endl;
    cout<<\"Enter height: \";
    cin>>height;
    cout<<endl;
    cout<<\"Enter width: \";
    cin>>width;
    
    height/=100;
    width/=100;
    
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 640);
    glutInitWindowPosition(50,50);
    glutCreateWindow(\"Squares\");
    setup();
    glutDisplayFunc(drawSquare);
    glutKeyboardFunc(keyInput);
	glutMainLoop();
    return 0;  
}


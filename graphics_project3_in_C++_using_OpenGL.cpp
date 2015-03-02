#include <iostream>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
#include <cmath>
using namespace std;

static int day=1;
static float hx1;
static float hx2;
static float hy1;
static float hy2;
void drawScene(void)
{
	if(day==1){
		day=0;
		glClear(GL_COLOR_BUFFER_BIT);
		//Draw Horizon
		glColor3f(.5,.8,1);
		glBegin(GL_POLYGON);
		glVertex3f(-1,1,0);
		glVertex3f(1,1,0);
		glVertex3f(1,.50,0);
		glVertex3f(-1,.50,0);
		glEnd();
		
		float x1,y1,x2,y2;
		float angle;
		double radius=0.1;
		
		x1 = 0,y1=0.9;
		glColor3f(1.0,1.0,0);
		
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1,y1);
		
		for (angle=1.0f;angle<3*3.24f;angle+=0.5)
		{
			x2 = x1+sin(angle)*radius;
			y2 = y1+cos(angle)*radius+.0025;
			glVertex2f(x2,y2);
		}
		
		glEnd();
		
		
		//Draw Road
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(-1, 0, 0);
		glVertex3f(1, 0, 0);
		glEnd();
		
		glColor3f(1, 1, 0);
		glBegin(GL_LINES);
		glVertex3f(-1, -.125, 0);
		glVertex3f(1, -.125, 0);
		glEnd();
		
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(-1, -.25, 0);
		glVertex3f(1, -.25, 0);
		glEnd();
		
		//Draw Lamp
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(-.92, 0, 0);
		glVertex3f(-.92, .25, 0);
		glEnd();
		
		glBegin(GL_LINES);
		glVertex3f(-.88, 0, 0);
		glVertex3f(-.88, .25, 0);
		glEnd();
		
		x1 = -.9,y1=0.25;
		glColor3f(0.0,0.0,0);
		
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1,y1);
		
		for (angle=1.0f;angle<3*3.24f;angle+=0.5)
		{
			x2 = x1+sin(angle)*radius;
			y2 = y1+cos(angle)*radius+.0025;
			glVertex2f(x2,y2);
		}
		
		glEnd();

		//Draw Lamp
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(.92, 0, 0);
		glVertex3f(.92, .25, 0);
		glEnd();
		
		glBegin(GL_LINES);
		glVertex3f(.88, 0, 0);
		glVertex3f(.88, .25, 0);
		glEnd();
		
		x1 = .9,y1=0.25;
		glColor3f(0.0,0.0,0);
		
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1,y1);
		
		for (angle=1.0f;angle<3*3.24f;angle+=0.5)
		{
			x2 = x1+sin(angle)*radius;
			y2 = y1+cos(angle)*radius+.0025;
			glVertex2f(x2,y2);
		}
		
		glEnd();


		//Draw houses
		hx1=-.8;
		hy1=-.25;
        for(int i=0;i<2;i++){
			
			float r;
			float g;
			float b;
			
			r=(float)rand()/(float) (RAND_MAX);
			g=(float)rand()/(float) (RAND_MAX);
			b=(float)rand()/(float) (RAND_MAX);
			
			float height, width,
			x=hx1, y=hy1,roof ; 
			height=1-(float)rand()/(float) (RAND_MAX);  
			width=(float)rand()/(float) (RAND_MAX);
			roof = .20 ;
			glColor3f(r, g, b);
			glBegin(GL_POLYGON);   // Main house 
			glVertex3f(x, y , 0.0);     // Bottom left
			glVertex3f(x+width, y, 0.0);     // Bottom right 
			glVertex3f(x+width, y+height, 0.0);
			glVertex3f(x+width/2, y+height+roof, 0.0);     // Roof peak   
			glVertex3f(x, y+height, 0.0);
			glEnd();   
			
			//Now draw door 
			float doorwidth , doorheight;
			doorwidth =width/4; doorheight=height/3;
			glColor3f(0, 0, 0);       
			glRectf(x+width/2-doorwidth/2,y,
					x+width/2+doorwidth/2,  y+doorheight );
			
			//Now draw window
			if(height>=.35){
				glColor3f(0, 0, 0);
				glBegin(GL_LINES);
				glVertex3f(hx1, y+height, 0);
				glVertex3f(hx1+width, y+height, 0);
				glEnd();
				
				glBegin(GL_LINES);
				glVertex3f(hx1, y+height-.25, 0);
				glVertex3f(hx1+width, y+height-.25, 0);
				glEnd();
				
				glBegin(GL_LINES);
				glVertex3f(hx1+width/2, y+height-.25, 0);
				glVertex3f(hx1+width/2, y+height, 0);
				glEnd();
				
				glBegin(GL_LINES);
				glVertex3f(hx1, ((y+height)+(y+height-.25))/2, 0);
				glVertex3f(hx1+width, ((y+height)+(y+height-.25))/2, 0);
				glEnd();
			}
			
			hx1+=width+.20;
			
		}


	}
	
	else{
		day=1;
		glClear(GL_COLOR_BUFFER_BIT);
		//Draw Horizon
		glColor3f(0,0,0);
		glBegin(GL_POLYGON);
		glVertex3f(-1,1,0);
		glVertex3f(1,1,0);
		glVertex3f(1,.50,0);
		glVertex3f(-1,.50,0);
		glEnd();
		
		float x1,y1,x2,y2;
		float angle;
		double radius=0.1;
		
		x1 = 0,y1=0.9;
		glColor3f(.75,.75,.75);
		
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1,y1);
		
		for (angle=1.0f;angle<3*3.24f;angle+=0.5)
		{
			x2 = x1+sin(angle)*radius;
			y2 = y1+cos(angle)*radius+.0025;
			glVertex2f(x2,y2);
		}
		
		glEnd();
		
		
		//Draw Road
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(-1, 0, 0);
		glVertex3f(1, 0, 0);
		glEnd();
		
		glColor3f(1, 1, 0);
		glBegin(GL_LINES);
		glVertex3f(-1, -.125, 0);
		glVertex3f(1, -.125, 0);
		glEnd();
		
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(-1, -.25, 0);
		glVertex3f(1, -.25, 0);
		glEnd();
		
		//Draw Lamp
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(-.92, 0, 0);
		glVertex3f(-.92, .25, 0);
		glEnd();
		
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(-.88, 0, 0);
		glVertex3f(-.88, .25, 0);
		glEnd();
		
		x1 = -.9,y1=0.25;
		glColor3f(1.0,1.0,0);
		
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1,y1);
		
		for (angle=1.0f;angle<3*3.24f;angle+=0.5)
		{
			x2 = x1+sin(angle)*radius;
			y2 = y1+cos(angle)*radius+.0025;
			glVertex2f(x2,y2);
		}
		
		glEnd();
		
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(-.92, 0, 0);
		glVertex3f(-.92, .25, 0);
		glEnd();
		
		glBegin(GL_LINES);
		glVertex3f(-.88, 0, 0);
		glVertex3f(-.88, .25, 0);
		glEnd();
		
		x1 = -.9,y1=0.25;
		glColor3f(1.0,1.0,0);
		
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1,y1);
		
		for (angle=1.0f;angle<3*3.24f;angle+=0.5)
		{
			x2 = x1+sin(angle)*radius;
			y2 = y1+cos(angle)*radius+.0025;
			glVertex2f(x2,y2);
		}
		
		glEnd();
		
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(.92, 0, 0);
		glVertex3f(.92, .25, 0);
		glEnd();
		
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(.88, 0, 0);
		glVertex3f(.88, .25, 0);
		glEnd();
		
		x1 = -.9,y1=0.25;
		glColor3f(1.0,1.0,0);
		
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1,y1);
		
		for (angle=1.0f;angle<3*3.24f;angle+=0.5)
		{
			x2 = x1+sin(angle)*radius;
			y2 = y1+cos(angle)*radius+.0025;
			glVertex2f(x2,y2);
		}
		
		glEnd();
		
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex3f(.92, 0, 0);
		glVertex3f(.92, .25, 0);
		glEnd();
		
		glBegin(GL_LINES);
		glVertex3f(.88, 0, 0);
		glVertex3f(.88, .25, 0);
		glEnd();
		
		x1 = .9,y1=0.25;
		glColor3f(1.0,1.0,0);
		
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1,y1);
		
		for (angle=1.0f;angle<3*3.24f;angle+=0.5)
		{
			x2 = x1+sin(angle)*radius;
			y2 = y1+cos(angle)*radius+.0025;
			glVertex2f(x2,y2);
		}
		
		glEnd();

        //Draw houses
		hx1=-.8;
		hy1=-.25;
        for(int i=0;i<2;i++){
			
			float r;
			float g;
			float b;
			
			r=(float)rand()/(float) (RAND_MAX);
			g=(float)rand()/(float) (RAND_MAX);
			b=(float)rand()/(float) (RAND_MAX);
			
			float height, width,
			x=hx1, y=hy1,roof ; 
			height=1-(float)rand()/(float) (RAND_MAX);  
			width=(float)rand()/(float) (RAND_MAX);
			roof = .20 ;
			glColor3f(r, g, b);
			glBegin(GL_POLYGON);   // Main house 
			glVertex3f(x, y , 0.0);     // Bottom left
			glVertex3f(x+width, y, 0.0);     // Bottom right 
			glVertex3f(x+width, y+height, 0.0);
			glVertex3f(x+width/2, y+height+roof, 0.0);     // Roof peak   
			glVertex3f(x, y+height, 0.0);
			glEnd();   
			
			//Now draw door 
			float doorwidth , doorheight;
			doorwidth =width/4; doorheight=height/3;
			glColor3f(0, 0, 0);       
			glRectf(x+width/2-doorwidth/2,y,
					x+width/2+doorwidth/2,  y+doorheight );
			
			//Now draw window
			if(height>=.35){
				glColor3f(0, 0, 0);
				glBegin(GL_LINES);
				glVertex3f(hx1, y+height, 0);
				glVertex3f(hx1+width, y+height, 0);
				glEnd();
				
				glBegin(GL_LINES);
				glVertex3f(hx1, y+height-.25, 0);
				glVertex3f(hx1+width, y+height-.25, 0);
				glEnd();
				
				glBegin(GL_LINES);
				glVertex3f(hx1+width/2, y+height-.25, 0);
				glVertex3f(hx1+width/2, y+height, 0);
				glEnd();
				
				glBegin(GL_LINES);
				glVertex3f(hx1, ((y+height)+(y+height-.25))/2, 0);
				glVertex3f(hx1+width, ((y+height)+(y+height-.25))/2, 0);
				glEnd();
			}
			
			hx1+=width+.20;
			
		}
		

	}
	glFlush();

	sleep(2);
}

void flash(){
	glutDisplayFunc(drawScene);
	sleep(2);
	glutPostRedisplay();
	glutSwapBuffers();

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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0,0);
    glutCreateWindow(\"Project3\");
    setup();
	flash();
    //glutDisplayFunc(drawScene);
	glutPostRedisplay();
	glutSwapBuffers();
    glutKeyboardFunc(keyInput);
	glutIdleFunc(flash);  //Used to flash the lamp
	glutMainLoop();
    return 0;  
}


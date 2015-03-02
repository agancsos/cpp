
#include <iostream>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
#include <time.h>
using namespace std;

void setup(void) 
{
	glClearColor(0.0, 0.0, 0.0, 0.0); 
}

void animate(){
	glutPostRedisplay();
}

void drawScene1(void)
{
	// Clear screen to background color.
	glClear(GL_COLOR_BUFFER_BIT);
	
	int max=1000;
	float r;
	float g;
	float b;
	float x1;
	float y1;
	
	for(int i=0;i<max;i++){
		r=(float)rand()/(float) (RAND_MAX);
		g=(float)rand()/(float) (RAND_MAX);
		b=(float)rand()/(float) (RAND_MAX);
		
		x1=100 * (float)rand()/(float) (RAND_MAX);
		y1=100 * (float)rand()/(float) RAND_MAX;
		
		glColor3f(r, g, b);
		glBegin(GL_POINTS);
		glVertex2f(x1, y1);
		glEnd();
		glFlush(); 

	}


}

void drawScene2(void){
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	
	int max=1000;
	float r;
	float g;
	float b;
	float x1;
	float y1;
	float z1;
	float zsize;
	float xsize;
	float ysize;
	
	for(int i=0;i<max;i++){
		r=(float)rand()/(float) (RAND_MAX);
			g=(float)rand()/(float) (RAND_MAX);
			b=(float)rand()/(float) (RAND_MAX);
			
			x1=100 * (float)rand()/(float) (RAND_MAX);
			y1=100 * (float)rand()/(float) RAND_MAX;
			z1=100 * (float)rand()/(float) RAND_MAX;

			
			xsize=100 * (float)rand()/(float) RAND_MAX;
			ysize=100 * (float)rand()/(float) RAND_MAX;
	
			zsize=100 * (float)rand()/(float) RAND_MAX;
			zsize=100 * (float)rand()/(float) RAND_MAX;

			
			glColor3f(r, g, b);
			glBegin(GL_POLYGON);
			glVertex3f(x1, y1,0);
			glVertex3f((x1+xsize), y1,0);
			glVertex3f((x1+xsize), (y1+ysize), 0);
			glVertex3f(x1, (x1+ysize), 0);
			glEnd();
			glFlush(); 
	}
	sleep(2);
}

void resize(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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

void drawScene2b(){
	glutDisplayFunc(drawScene2);
	glutPostRedisplay();
	glutSwapBuffers();
}

void drawScene3b(){
	glutDisplayFunc(drawScene1);
	sleep(2);
	glutPostRedisplay();
	glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
	srand((unsigned)time(0));
	int option;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH); 
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	
	cout<<\"1-1000 Dots  2-SS1  3-SS2: \";
	cin>>option;
	
	if(option==1){
		glutCreateWindow(\"1000 Dots\");

	}
	
	else if(option==2){
			glutCreateWindow(\"SS1\");
	}
	
	else{
		glutCreateWindow(\"SS2\");

	}
	
	setup(); 
	
	if(option==1){
		glutDisplayFunc(drawScene1);
	}
	
	else if(option==2){
			drawScene2b();
			glutReshapeFunc(resize);  
			glutKeyboardFunc(keyInput);

		    glutIdleFunc(drawScene2b);
	}
	
	else{
		drawScene3b();
		glutReshapeFunc(resize);  
		glutKeyboardFunc(keyInput);
		glutIdleFunc(drawScene3b);

		
	}	
	glutReshapeFunc(resize);  
	glutKeyboardFunc(keyInput);
	glutMainLoop(); 
	
	
	return 0;  
}


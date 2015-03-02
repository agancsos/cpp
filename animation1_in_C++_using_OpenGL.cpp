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

void drawScene2b(){
	glutDisplayFunc(drawScene2);
	glutPostRedisplay();
	glutSwapBuffers();
}

int main(){
	srand((unsigned)time(0));
        glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH); 
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
      drawScene2b();
      glutReshapeFunc(resize);  
      glutKeyboardFunc(keyInput);
      glutIdleFunc(drawScene2b);
}

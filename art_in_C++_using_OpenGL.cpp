void art(void){
	glClear(GL_COLOR_BUFFER_BIT);
	
	int max=1000;
	float r;
	float g;
	float b;
	float x1;
	float y1;
	float xsize;
	float ysize;
	
		for(int i=0;i<max;i++){
			r=(float)rand()/(float) (RAND_MAX);
			g=(float)rand()/(float) (RAND_MAX);
			b=(float)rand()/(float) (RAND_MAX);
			
			x1=100 * (float)rand()/(float) (RAND_MAX);
			y1=100 * (float)rand()/(float) RAND_MAX;
			
			xsize=100 * (float)rand()/(float) RAND_MAX;
			ysize=100 * (float)rand()/(float) RAND_MAX;
			
			glColor3f(r, g, b);
			glBegin(GL_POLYGON);
			glVertex3f(x1, y1,0);
			glVertex3f((x1+xsize), y1, 0);
			glVertex3f((x1+xsize), (y1+ysize), 0);
			glVertex3f(x1, (x1+ysize), 0);
			glEnd();
			glFlush(); 
			
		}	
}


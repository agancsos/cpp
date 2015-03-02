void chickenpox(void)
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


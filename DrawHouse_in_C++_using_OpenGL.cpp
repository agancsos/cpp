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


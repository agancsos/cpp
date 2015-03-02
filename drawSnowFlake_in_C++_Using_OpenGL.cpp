void drawKoch(float dir,float len,int n){
	float pi=.0174533;
	float dirRad = 0.0174533 * dir;
	float newX = mOldX + len * cos(dirRad);
	float newY = mOldY + len * sin(dirRad);
	
	if (n == 0)
	{

		//Draw initial
		glVertex2f(mOldX, mOldY);
		glVertex2f(newX, newY);
	
		//Rotate 3 times
		glVertex2f(-mOldY-.025*len*sin(pi*90),-mOldX-cos(pi*90));
                glVertex2f(-newY-.025*len*sin(pi*90),-newX-cos(pi*90));

                glVertex2f(mOldY+2.8*oLen*sin(pi*160),mOldX+1.04*oLen*cos(pi*160));
		glVertex2f(newY+2.8*-0.4*sin(pi*160),newX+1.04*oLen*cos(pi*160));


                glVertex2f((mOldX-.025*oLen+cos(pi*90)),-(mOldY+1*oLen+cos(pi*90)));
                glVertex2f((newX-.025*oLen+cos(pi*90)),-(newY+1*oLen+cos(pi*90)));

		mOldX = newX;
                mOldY = newY;
	}
	else if(n<10){
		n--;        
		len /= 3.0; 	
		drawKoch(dir,len,n);
		
		dir += 60.0;
		drawKoch(dir,len,n);
		
		dir -= 120.0;
		drawKoch(dir,len,n);
		
		dir += 60.0;
		drawKoch(dir,len,n);
	}
	else{
		glPrint(-0.2,0.0,0.9,0.9,0.9,(char*)\"ERROR.  Level is too high...\");
	}
}


void drawSnowflake(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	char levelMenu[500]=\"Level: \";

	//Set up level menu
	if(myLevel<0) myLevel=0;       //Not allowed to be negative
	else if(myLevel>9) myLevel=9; //Not allowed to be larger than 4
	
	if(myLevel==0) strcat(levelMenu,(char*)\"0\");
        if(myLevel==1) strcat(levelMenu,(char*)\"1\");
        if(myLevel==2) strcat(levelMenu,(char*)\"2\");
        if(myLevel==3) strcat(levelMenu,(char*)\"3\");
        if(myLevel==4) strcat(levelMenu,(char*)\"4\");
        if(myLevel==5) strcat(levelMenu,(char*)\"5\");
        if(myLevel==6) strcat(levelMenu,(char*)\"6\");
        if(myLevel==7) strcat(levelMenu,(char*)\"7\");
        if(myLevel==8) strcat(levelMenu,(char*)\"8\");
        if(myLevel==9) strcat(levelMenu,(char*)\"9\");

        else if(myLevel>9) strcat(levelMenu,(char*)\"ERROR\");

	glPrint(-1.0,-0.95,0.9,0.9,0.9,(char*)\"(c) 2012 Abel Gancsos\");   //Copyright
	glPrint(-1.0,0.95,0.9,0.9,0.9,(char*)\"ESC-Quit U-Increase  D-Decrease\");   //Instructions
	glPrint(0.8,0.95,0.9,0.9,0.9,(char*)levelMenu);                  //Level menu
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	drawKoch(0.0,oLen,myLevel);
	glEnd();
	glFlush();
}


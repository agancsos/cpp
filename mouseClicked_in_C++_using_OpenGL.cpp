void mouseClick(int button,int state,int x,int y){
	float tx=(float)x/500;
	float ty=1-(float)y/500;
	int cButton=0;
	if(state==GLUT_UP){
		if(tx>-1 && ty>=.9 && ty<=.95) cButton=1;
                if(tx>-1 && ty>=.8 && ty<=.85) cButton=2;
                if(tx>-1 && ty>=.7 && ty<=.75) cButton=3;
                if(tx>-1 && ty>=.6 && ty<=.65) cButton=4;
                if(tx>-1 && ty>=.5 && ty<=.55) cButton=5;
                if(tx>-1 && ty>=.4 && ty<=.45) cButton=6;

		switch(cButton){
			case 1:
				break;

			case 2:
				break;

			case 3:
				break;

			case 4:
				break;
	
			case 5:
				break;

			case 6:
				exit(0);
				break;
		}

	}
}


/*
	Authors:Abel Gancsos,Christopher McKim
*/
#include <iostream>
#include <cmath>
#include <math.h>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
using namespace std;

//Global variables
char cmd;
float value,currentx,currenty,steps=.10;
float linesx[500]={0};
float linesy[500]={0};
int vertical=1,draw=1,initial=1,angle=90,linei=0;
char menu[300];
/*********************************/

//Draw turtles
void drawTurtle(float x,float y){
	float radangle=((float)angle/180)*3.14;
    	glColor3f(1,1,1);	
	glBegin(GL_LINE_STRIP);
	glVertex3d(x,y,0);
	//glVertex3d(x+(cos(radangle)*(.10))+(sin(radangle)*(.10)),(y+(sin(radangle)*(.10))+(cos(radangle)*(.10))),0);
	//glVertex3d(x-(cos(radangle)*(.10))+(sin(radangle)*(.10)),(y-(sin(radangle)*(.10))+(cos(radangle)*(.10))),0);
	glVertex3f(x-.10,y-.10,0);
	glVertex3f(x+.10,y-.10,0);
	glVertex3f(x,y,0);
	glEnd();
	glFlush();
}
/*********************************/

void glPrint(float x, float y, char *string)
{
  	glColor3f( 1, 1, 1 );
  	glRasterPos2f(x, y);
  	int len, i;
  	len = (int)strlen(string);
  	for (i = 0; i < len; i++) {
    		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
  	}
}

void printMenu(){
	//Set up menu
        strcpy(menu,\"y-angle+ u-angle- angle p-toggle f-move i-f+ d-f- Steps: \");
        char temp[5];

        //Restrict steps increment
        if(steps<0)steps=.10;
        if(steps>.80)steps=.80;

        //Restrict angles
        if(angle<30)angle=0;
        if(angle>360)angle=360;

        sprintf(temp,\"%.3f\",steps);
        strcat(menu,temp);
        strcat(menu,\" Toggle: \");
        char temp2[3];
        if(draw==1)strcpy(temp2,\"ON\");
        else if(draw==0)strcpy(temp2,\"OFF\");
        strcat(menu,temp2);
        char temp3[4];
        sprintf(temp,\"%d\",angle);
        strcpy(temp3,temp);
        strcat(menu,\" Angle: \");
        strcat(menu,temp3);
        /**********************************************************************************/

        glPrint(-1,.97,menu);  //Print menu
}

void forward(float a){
	float radangle = ((float)angle/180) * 3.14;
	linei++;
	currentx=currentx+a*cos(radangle);
	currenty=currenty+a*sin(radangle);
	if(draw==1){
		linesx[linei]=currentx;
		linesy[linei]=currenty;		
	}
	else{
		linesx[linei]=-5.0;
		linesy[linei]=-5.0;
	}
}

void plot(float *a,float *b){
	glColor3f(1,1,1);
	int i;
	//Go through coordinate arrays
	for(i=1;i<=linei;i++){
		if(a[i-1]!=-5.0 && a[i]!=-5.0){
			glBegin(GL_LINES);
			glVertex3f(a[i-1],b[i-1],0);
			glVertex3f(a[i],b[i],0);
			glEnd();
               }
	}
	drawTurtle(currentx,currenty);
}

void left(float a){
}

void right(float a){
}

void toggle(){
	if(draw==0){
		draw=1;
		linei++;
		linesx[linei]=currentx;
		linesy[linei]=currenty;
	}
	else{
		draw=0;
	}
}


void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	plot(linesx,linesy);
	printMenu();
	glutSwapBuffers();
	glFlush();
}

void flash(){
	glutDisplayFunc(drawScene);
}

void setup(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

}

void keyInput(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27://ESC
			exit(0);
			break;
		case 112://p
			toggle();
			break;
		case 108://l
			left(angle);
			break;	
		case 114://r
			right(angle);
			break;
		case 102://f
			forward(steps);
			break;
		case 105://i
			steps+=.10;
			break;
		case 100://d
			steps-=.10;
			break;
		case 111://o
			currentx=0;
			currenty=0;
			break;
		case 121://y
			angle+=30;
			break;
		case 117://u
			angle-=30;
			break;
		case 113://q
			/*currentx=0;
			currenty=0;
			linei=1;
			linesx={0};
			linesy={0}; */
			break;
		default:
			break;
	}
}

void refresh(){
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	currentx=0;
	currenty=0;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(400,200);
	glutCreateWindow(\"logos\");
	setup();
	flash();
	glutIdleFunc(refresh); 
	glutKeyboardFunc(keyInput);
	glutMainLoop();
    	return 0;  
}


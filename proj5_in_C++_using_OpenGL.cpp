
	
#include <iostream>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
#include <cmath>
#include <math.h>
using namespace std;

int option;

void glGalactic(float a,float b){
	float xmin=a,xmax=b;
	int max=abs(b-a);
	float xs[max];
	float ys[max];
	for(int i=xmin;i<xmax;i++){
		xs[i]=sin(i);
		float p1=(10-pow((float)i,3));
		ys[i]=cos((float)(p1,-3));
	}

	glBegin(GL_LINE_STRIP);
	for(int i=xmin;i<xmax;i++){
		glVertex2f(xs[i],ys[i]);
	}
	glEnd();
	glFlush();
}

void glFermatSpiral(float a, float b, float thetaStart, float thetaEnd, unsigned int samples = 200 )
{
    glBegin( GL_LINE_STRIP );
    float dt = (thetaEnd - thetaStart) / (float)samples;
    for( unsigned int i = 0; i <= samples; ++i )
    {
        float theta = thetaStart + (i * dt);
        float r = sqrt( theta );

        float x = r * cos( theta );
        float y = r * sin( theta );
        glVertex2f( x, y );

        x = -r * cos( theta );
        y = -r * sin( theta );

        glVertex2f( x, y );
    }

    glEnd();
    glFlush();
}

void pic1(void){
	glClear(GL_COLOR_BUFFER_BIT);
	float r,g,b;
	for(int x=0;x<640;x++){
		
		r=(float)rand()/(float) (RAND_MAX);
		g=(float)rand()/(float) (RAND_MAX);
		b=(float)rand()/(float) (RAND_MAX);
		
        float x2=(float)x/(float) 100;
		glColor3f(r,g,b);
		glBegin(GL_POINTS);
		glVertex2d(x2,x2);
        glEnd();
        glFlush();

	}

}

void pic2(void){
	glClear(GL_COLOR_BUFFER_BIT);
	float x[2000],y[2000],t;
	float tlo=-3.14159,thi=3.14159;
	float delta_t=(thi-tlo)/2000;
	int i=0;
	for(t=tlo;t<thi;t=t+delta_t){
		x[i]=6*cos(t)+5*cos(3*t);
		y[i]=6*sin(t)-5*sin(3*t);
		i++;
	}

	float xmax=x[0] , ymax=y[0], xmin=x[0], ymin=y[0]; 
  
  	for (i=0 ; i < 2000 ; ++i )
     	{if (x[i] < xmin )  xmin = x[i] ;
      	if (x[i] > xmax )  xmax = x[i] ; 
      	if (y[i] < ymin )  ymin = y[i] ;
      	if (y[i] > ymax )  ymax = y[i] ;
     	} 
      	for (i=0 ; i < 2000 ; ++i )
      	{  x[i] = (x[i]-xmin) / (xmax-xmin);
         y[i] = (y[i]-ymin) / (ymax-ymin);
      	} ;
     
   	glBegin(GL_LINE_STRIP);
   	for (i=0 ; i < 2000 ; ++i )
      		glVertex3f(x[i], y[i], 0.0);
   		glEnd();

	glFlush();
}

void pic3(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glFermatSpiral(0.05, 0.2, 1.0, 25.0);
	gluOrtho2D(-4, 4, -4, 4);
}

void pic4(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glGalactic(-10,10);
}

void pic1b(){
	glutDisplayFunc(pic1);
}

void pic2b(){
	glutDisplayFunc(pic2);
}

void pic3b(){
	glutDisplayFunc(pic3);
}

void pic4b(){
	glutDisplayFunc(pic4);
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
	glutInit(&argc, argv);
	
	//Prompt for option
	cout<<\"1- A  2-B   3-C   4-D: \";
	cin>>option;
	
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	//Set up window
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(320,240);
    glutCreateWindow(\"proj5\");
	
    setup(); //Set up background
	
	if(option==1){
		pic1b();
	}
	
	else if(option==2){
		pic2b();
	}
	
	else if(option==3){
		pic3b();
	}
	
	else if(option==4){
		pic4b();
	}
	else{
		cout<<\"Input is invalid...\"<<endl;
	}
	
	//Continue to setup
	glutPostRedisplay();
    glutKeyboardFunc(keyInput);
	glutMainLoop();
    return 0;  
}


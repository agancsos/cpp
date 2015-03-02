void draw2(void){
        //Ship
        glClear(GL_COLOR_BUFFER_BIT);

        //Ship
        glColor3f(1,0,0);

        //Base
        glBegin(GL_POLYGON);
        glVertex3f(-1,-.2,0);
        glVertex3f(1,-.2,0);
        glVertex3f(.9,-.4,0);
        glVertex3f(-.8,-.4,0);
        glEnd();

        //Center
        glBegin(GL_POLYGON);
        glVertex3f(-.5,.2,0);
        glVertex3f(.5,.2,0);
        glVertex3f(.5,-.2,0);
        glVertex3f(-.5,-.2,0);
        glEnd();

        //Steam pipes
        glBegin(GL_POLYGON);
        glVertex3f(-.2,.8,0);
        glVertex3f(-.1,.8,0);
        glVertex3f(-.1,.2,0);
        glVertex3f(-.2,.2,0);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex3f(.1,.8,0);
        glVertex3f(.2,.8,0);
        glVertex3f(.2,.2,0);
        glVertex3f(.1,.2,0);
        glEnd();

        //Sea
        glColor3f(0,0,.5);
        glBegin(GL_POLYGON);
        glVertex3f(-1,-.4,0);
        glVertex3f(1,-.4,0);
        glVertex3f(1,-1,0);
        glVertex3f(-1,-1,0);

        glEnd();
        glColor3f(0,0,0);
        glFlush();
}


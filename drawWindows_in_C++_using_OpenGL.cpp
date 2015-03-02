void drawWindows(float x,float y,float size){
        float myX=x,myY=y;
        glBegin(GL_LINE_STRIP);
        glVertex3f(x,y,0);
        glVertex3f(x+size,y,0);
        glVertex3f(x+size,y+size,0);
        glVertex3f(x,y+size,0);
        glVertex3f(x,y,0);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(myX,myY+.05,0);
        glVertex3f(myX+size,myY+.05,0);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(myX+.05,myY,0);
        glVertex3f(myX+.05,myY+size,0);
        glEnd();
}

void button(float x,float y,char* title){
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);
                glVertex3f(x,y,0);
                glVertex3f(x+.40,y,0);
                glVertex3f(x+.40,y+.10,0);
                glVertex3f(x,y+.10,0);
        glEnd();
        glPrint(x,y+.04,.5,.5,.5,title);
}


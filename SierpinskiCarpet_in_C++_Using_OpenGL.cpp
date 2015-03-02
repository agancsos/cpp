void sierpinskicarpet(int level,float x,float y,float height,float width){
        if (level == 0) {
                glBegin(GL_POLYGON);
                glVertex3f(x,y,0);
                glVertex3f(x+width,y,0);
                glVertex3f(x+width,y+height,0);
                glVertex3f(x,y+height,0);
                glEnd();
        }
        else {
            float wid = width / 3;
            float heig = height / 3;
            float x1 = x  - 2 * wid;
            float y1 = y - 2 * heig;                                                                                           
            float x2 = x + wid;
            float y2 = y + heig;
            float x3 = x + 4 * wid;
            float y3 = y + 4 * heig;

            alg2a(level-1, x1, y1, wid, heig);
            alg2a(level-1, x2, y1, wid, heig);
            alg2a(level-1, x3, y1, wid, heig);
            alg2a(level-1, x1, y2, wid, heig);
            alg2a(level-1, x1, y3, wid, heig);
            alg2a(level-1, x2, y3, wid, heig);
            alg2a(level-1, x3, y3, wid, heig);
            alg2a(level-1, x3, y2, wid, heig);
            glBegin(GL_POLYGON);
                glVertex3f(x,y,0);
                glVertex3f(x+width,y,0);
                glVertex3f(x+width,y+height,0);
                glVertex3f(x,y+height,0);
                glEnd();
        }
}


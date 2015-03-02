for (float t=.8;t>0;t-=.001){
                float r,g,b;
                        r=(float)rand()/(float) (RAND_MAX);
                        g=(float)rand()/(float) (RAND_MAX);
                        b=(float)rand()/(float) (RAND_MAX);
                float B=.8-t;
                for(float s=B;s<=t;s+=.001){
                        glColor3f(r,g,b);
                        glVertex3f(s,tan(60)*s+B,0);
                }
        }


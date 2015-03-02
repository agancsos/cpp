void sierpinskiRec(point2 a, point2 b, point2 c, int m){
        point2 v0, v1, v2;
        int j;
        if(m>0){
                for(j=0; j<2; j++) v0[j]=(a[j]+b[j])/2;
                for(j=0; j<2; j++) v1[j]=(a[j]+c[j])/2;
                for(j=0; j<2; j++) v2[j]=(b[j]+c[j])/2;
                alg1a(a, v0, v1, m-1);
                alg1a(c, v1, v2, m-1);
                alg1a(b, v2, v0, m-1);
        }
        else{
                glBegin(GL_TRIANGLES);
                glVertex2fv(a);
                glVertex2fv(b);
                glVertex2fv(c);
                glEnd();
        }
}


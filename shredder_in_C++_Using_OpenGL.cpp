void shredder(point2 a, point2 b, point2 c,point2 d, int m){
        point2 v0, v1, v2, v3;
        int j;
        if(m>0){
                for(j=0; j<2; j++) v0[j]=(a[j]+b[j])/2;
                for(j=0; j<2; j++) v1[j]=(a[j]+c[j])/2;
                for(j=0; j<2; j++) v2[j]=(b[j]+c[j])/2;
                for(j=0; j<2; j++) v3[j]=(c[j]+d[j])/2;

                alg2a(a, v0, v1, v3, m-1);
                alg2a(c, v1, v2, v3, m-1);
                alg2a(b, v2, v3, v3, m-1);
                alg2a(d, v3, v0, v3, m-1);

        }
        else{
                glBegin(GL_POLYGON);
                glVertex2fv(a);
                glVertex2fv(b);
                glVertex2fv(c);
                glVertex2fv(d);
                glEnd();
        }
}


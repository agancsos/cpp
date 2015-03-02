void cracked(point2 a, point2 b, point2 c,point2 d, int m){
        point2 v0, v1, v2, v3;
        int j;
        if(m>0){
                for(j=0; j<2; j++) v0[j]=(a[j]+b[j])/3;
                for(j=0; j<2; j++) v1[j]=(a[j]+c[j])/3;
                for(j=0; j<2; j++) v2[j]=(b[j]+c[j])/3;
                for(j=0; j<2; j++) v3[j]=(b[j]+d[j])/3;

                alg2a(a, v0, v1, v2, m-1);
                alg2a(b, v1, v2, v3, m-1);
                alg2a(c, v2, v3, v0, m-1);
                alg2a(d, v3, v0, v1, m-1);

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


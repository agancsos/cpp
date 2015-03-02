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


void glPrint(float x, float y, float r, float g, float b,char *string)
{
        glColor3f(r,g,b);
        glRasterPos2f(x, y);
        int len, i;
        len = (int)strlen(string);
        for (i = 0; i < len; i++) {
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
        }
}



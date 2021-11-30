/*
 Name       : PalindromeGUI
 Author     : Abel Gancsos
 Start Date : 2014-04-06
 End   Date : 2014-04-06
 Description: This is a GUI for the popular problem to find palindromes written in the C language 
              using OpenGL and Glut.  This GUI is compiled in a Unix environment and is guarenteed
              to run in a Unix/MacOS X machine.
 Notes      : The package also include a Bash system script to compile the source code.
*/ 
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

//Global variables
char menu[300];
char version[10]="v. 1.0.0";
char user_buffer[2000000]="";
char flipped_text[2000000]="";
void clear_array(char* array);
/*********************************/
void glPrint(float x, float y,float r,float g,float b, char *string,int font){
 /*
  GLUT_BITMAP_8_BY_13
  GLUT_BITMAP_9_BY_15
  GLUT_BITMAP_TIMES_ROMAN_10
  GLUT_BITMAP_TIMES_ROMAN_24
  GLUT_BITMAP_HELVETICA_10
  GLUT_BITMAP_HELVETICA_12
  GLUT_BITMAP_HELVETICA_18
 */
 glColor3f(r,g,b);
 glRasterPos2f(x, y);
 int len, i;
 len = (int)strlen(string);
 for (i =0;i<len;i++){
  if(font==1){
   glutBitmapCharacter(GLUT_BITMAP_8_BY_13,string[i]);
  }
  else if(font==2){
   glutBitmapCharacter(GLUT_BITMAP_9_BY_15,string[i]);
  }
  else if(font==3){
   glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,string[i]);
  }
  else if(font==4){
   glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
  }
  else if(font==5){
   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,string[i]);
  }
  else if(font==6){
   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string[i]);
  }
  else if(font==7){
   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
  }
  else{
   glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
  }
 }
}
char* year(){
 time_t now = time(NULL);
 char* all=ctime(&now);
 char* final="";
 char year[5];
 memcpy(year,&all[strlen(all)-5],4);
 year[4]='\0';
 final=(char*)year;
 return final;
}
void file_get_contents(char* path){
 FILE *fopen(), *fp;
 char c;
 user_buffer[0]='\0';
 flipped_text[0]='\0';
 if(access(path,F_OK) != -1) {
  fp = fopen(path,"r");
  int i=0;
  c=getc(fp);
  while (c!=EOF){
   user_buffer[i]=(char)c;
   c=getc(fp);
   i++;
  }
  user_buffer[i]='\0';
  fclose(fp);  
 } 
 else{
  glPrint(-0.5,.8,1.0,0.0,0.0,(char*)"Error... input.txt does not exist",4);
 }
}
char* flip_text(char* text){
 char* final="";
 int i=strlen(text)-1;
 int j=0;
 while(i>=0){
  final[j]=text[i];
  i--;
  j++;
 }
 return final;
}
void extract_flipped(char* text,char flipped[]){
 int i=strlen(text)-1;
 int j=0;
 while(i>=0){
  flipped[j]=text[i];
  i--;
  j++;
 }
 flipped[j]='\0';
}
int pal(char* text,char flipped[]){
 int i=0;
 int total=0;
 while(i<strlen(text)){
  //printf("I: %d   Text: %c  Reverse: %c   Total:%d\n",i,text[i],flipped[i+1],total);
  if(text[i]==flipped[i+1]){
   total++;
  }
  i++;
 }
 if(total==strlen(text)-1){
  return 1;
 }
 return 0;
}
void printBox(float x,float y,float bgr,float bgg,float bgb,float height,float length,char* text,int font_style){
 glColor3f(bgr,bgg,bgb);
 glBegin(GL_POLYGON);
 glVertex3f(x,y,1);
 glVertex3f(x+length,y,1);
 glVertex3f(x+length,y+height,1);
 glVertex3f(x,y+height,1);
 glVertex3f(x,y,1);
 glEnd();
 glPrint(x,y+(height/2),1.0-bgr,1.0-bgg,1.0-bgb,text,font_style);
}
void printMenu(){
 char copyright[40]="(c) ";
 strcat((char*)copyright,(char*)year());
 strcat(copyright," Abel Gancsos");
 glPrint(-1.0,-0.98,1.0,1.0,1.0,(char*)copyright,1);
 glPrint(0.83,-0.98,1.0,1.0,1.0,(char*)version,1);
 glPrint(-1.0,0.95,1.0,1.0,1.0,(char*)"Menu: Update input.txt and watch the GUI update",6);
}
void drawScene(void){
 glClear(GL_COLOR_BUFFER_BIT);
 printMenu();
 
 clear_array(user_buffer);
 clear_array(flipped_text);
 file_get_contents("input.txt");
 extract_flipped(user_buffer,flipped_text);

 glPrint(-0.8,0.5,1.0,1.0,1.0,(char*)"Your text: ",7);
 glPrint(-0.5,.5,1.0,1.0,1.0,(char*)user_buffer,7);
 
 glPrint(-0.8,0.0,1.0,1.0,1.0,(char*)"Reverse  : ",7);
 glPrint(-0.5,0.0,1.0,1.0,1.0,(char*)flipped_text,7);

 //Check if palindrome
 if(pal((char*)user_buffer,flipped_text)==1){
  printBox(-0.8,-0.5,0.0,1.0,0.0,0.20,1.5,(char*)"Palindrome",7);
 }
 else if(pal((char*)user_buffer,flipped_text)==0){
  printBox(-0.8,-0.5,1.0,0.0,0.0,0.20,1.5,(char*)"Not Palindrome",7);
 }

 glFlush();
}
void clear_array(char* array){
 int i=0;
 while(i<strlen(array)){
  array[i]='\0';
  i++;
 }
}
void flash(){
 glutDisplayFunc(drawScene);
}
void setup(void){
 glClearColor(0.0, 0.0, 0.0, 0.0);
}
void keyInput(unsigned char key, int x, int y){
 switch(key){
  case 27://ESC
   exit(0);
   break;
  case 'r':
   break;
  //Others
  default:
   break;
 }
}
void refresh(){
 glutPostRedisplay();
}

int main(int argc, char **argv){
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(800, 600);
 glutInitWindowPosition(400,200);
 glutCreateWindow("PalindromeGUI");
 setup();
 flash();
 glutIdleFunc(refresh); 
 glutKeyboardFunc(keyInput);
 glutMainLoop();
 return 0;  
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
//Global variables
int option=0,max=10,complete_flag=0;
char original[100000]="";
int  values[100000]={};
char* deck[52]={"AH","AS","AD","AC","KH","KS","KD","KC",
                         "JH","JS","JD","JC",
                         "QH","QS","QD","QC","10H","10S","10D",
                         "10C","9H","9S","9D","9C","8H","8S","8D",
                         "8C","7H","7S","7D","7C","6H","6S","6D",
                         "6C","5H","5S","5D","5C","4H","4S","4D",
                         "4C","3H","3S","3D","3C","2H","2S","2D","2C"};
/*********************************/
/*
 Name: resume_questions.c
 Author: Abel Gancsos
 Date Assigned:
 Date Started: Sunday, September 22, 2013 16:00:00
 Date Completed: Tuesday, September24, 2013 22:43:00
 Description: 
              Given a list of ints with value 1 through 1000000 which one value that is repeated which val it is. 
              Given a char string which is the first char in the string that is not repeated. 
              Given a deck of cards enumerated by ints shuffle the deck.
 Keynotes:
              For all buffers, the max is 10 by default when printing, but this can be increased.
              Navigation and controls are done through keyboard input.
              User can change value via files. DO NOT DELETE FILES!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
              You can change background-color:
                                              Black->'B'
                                               Blue->'b'
                                             Purple->'p'
*/
void glPrint(float x, float y, float r, float g, float b, char *string){
   glColor3f(r,g,b);
   glRasterPos2f(x, y);
   int len, i;
   len = (int)strlen(string);
   for (i = 0; i < len; i++) {
      glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
   }
}

void printMenu(){
 char menu[200]="ESC: quit r: Refresh  s: Shuffle  h: Home  1: Problem 1   2: Problem 2   3: Problem 3";
 time_t now_time=time(NULL);
 char* now_string=ctime(&now_time);
 char year[4];
 char copy[80]="(c) ";
 char max_string[20]="Max: ";

 memcpy(year,&now_string[20],4);
 year[4]='\0';
 strcat(copy,year);
 strcat(copy," Abel Gancsos"); 
 if(option==1){
   glPrint(0.80,0.95,0.5,0.5,0.5,(char*)"Problem 1");  //current 
 }
 else if(option==2){
   glPrint(0.80,0.95,0.5,0.5,0.5,(char*)"Problem 2");  //current
 }
 else if(option==3){
   glPrint(0.80,0.95,0.5,0.5,0.5,(char*)"Problem 3");  //current
 }
 else{
  glPrint(0.90,0.95,0.5,0.5,0.5,(char*)"HOME"); //current
 }
 char c[3]="";
 sprintf(c,"%d",max);
 strcat(max_string,c);
 glPrint(-1.0,0.95,0.5,0.5,0.5,(char*)menu);     //menu
 glPrint(-1.0,0.85,0.5,0.5,0.5,(char*)"Colors: B-Black  b-Blue  p-Purple");    //colors
 glPrint(-1.0,-0.95,0.5,0.5,0.5,(char*)copy);  //copyright
}

//Helper functions
int search_array(int value,int array[],int local_max){
 int i=0;
 int total=0;
 while(i<local_max){
  if(value==array[i]){
   total++;
  }
  i++;
 }
 return total;
}

int search_string(char character,char array[]){
 int i=0,local_max=sizeof(array),final=0;
 while(i<local_max){
  if(character==array[i]){
   final++;
  }
  i++;
 }
 return final;
}

void get_int_file(int max_array){
 FILE *fopen(), *fp;
 int i=0;
 char buff[255];
 char pattern[100000]="";
 fp = fopen("q1.txt","r");
 if(fp==NULL){
  puts("Cannot open file for reading");
  exit(EXIT_FAILURE);
 }
 while(i<max){
  strcat(pattern,"\%d ");
  i++;
 }
 fgets(buff, sizeof(buff), fp);
 sscanf(buff, "%d %d %d %d %d %d %d %d %d", &values[0],&values[1],
        &values[2],&values[3],&values[4],&values[5],&values[6],
        &values[7],&values[8],&values[9]);
 fclose(fp);
}

void get_string_file(int max_array){
 FILE *fopen(), *fp;
 char c[10];
 int i=0;
 fp=fopen("q2.txt","r");
 if(fp==NULL){
  puts("Cannot open file for reading");
  exit(EXIT_FAILURE);
 }
 c[0] = getc(fp);
 while (c[0]!= EOF){
  c[0]=getc(fp);
  if(i<max_array){
   strcat(original,c);
  }
  i++;
 }
 fclose(fp);
 original[sizeof(original)]='\0';
}

void draw_deck(float start_x,float start_y,float card_height){
 int i=0,card_i=0;
 float card_width=card_height/2,original_x=start_x;
 while(i<4){
  int j=0;
  while(j<13){
   glBegin(GL_POLYGON);
   glColor3f(1.0,1.0,1.0);
   glVertex3f(start_x,start_y,0.0);
   glVertex3f(start_x+card_width,start_y,0.0);
   glVertex3f(start_x+card_width,start_y-card_height,0.0);
   glVertex3f(start_x,start_y-card_height,0.0);
   glVertex3f(start_x,start_y,0.0);
   glEnd();
   glPrint(start_x,start_y-card_height/2.0+0.03,0.4,0.0,0.0,(char*)deck[card_i]);
   start_x=start_x+card_width*2.0;
   j++;
   card_i++;
  }
  start_x=original_x;
  start_y=start_y-card_height*2.0;
  i++;
 }
 card_i=0;
}

void shuffle_cards(){
 char* split_1[26]={};
 char* split_2[26]={};
 int i=0,i1=0,i2=0;
 while(i1<26){
  split_1[i1]=deck[i];
  i++;
  i1++;
 }
 i=26;
 while(i2<26){
  split_2[i2]=deck[i];
  i++;
  i2++;
 }
 i=0;
 i1=0;
 i2=0;
 while(i<52){
  if(i==0 || i%2==0 && split_1[i1]){
   deck[i]=split_1[i1];
   i1++;
  }
  if(i>0 && i%2>0 && split_2[i2]){
   deck[i]=split_2[i2];
   i2++;
  }
  i++;
 }
 //Switch first and last
 int rand_temp=rand()%52;
 char* temp=deck[0];
 deck[0]=deck[rand_temp];
 deck[rand_temp]=temp;
 
 temp=deck[51];
 rand_temp=rand()%52;
 deck[51]=deck[rand_temp];
 deck[rand_temp]=temp;
}
/***********************************************************************/

void drawQ1(void){
 if(complete_flag==0){
  glClear(GL_COLOR_BUFFER_BIT);
  printMenu();
 }
 if(complete_flag==0){
  get_int_file(max);
  int i=0,next_index=0;
  int repeated_values[1000000]={};
  char values_string[1000000]="Repeated values: ";
  char original_values[100000]="Original values: ";
  i=0;
  while(i<sizeof(values) && values[i]){
   char c[20];
   sprintf(c,"%d",values[i]);
   strcat(original_values,c);
   strcat(original_values," ");
   i++;
  }

  //Go through list
  i=0;
  while(i<max){
   int test_value=values[i];
   if(search_array(test_value,values,max)>1 && values[i] && search_array(test_value,repeated_values,max)==0){
    repeated_values[next_index]=values[i];
    next_index++;
   }
   i++;
  }
  i=0;
  while(i<next_index){
   char c[20];
   sprintf(c,"%d",repeated_values[i]);
   strcat(values_string,c);
   strcat(values_string," ");
   i++;
  }
  complete_flag=1;
  glPrint(-0.95,0.5,0.5,0.5,0.5,(char*)original_values);
  glPrint(-0.95,0.0,0.5,0.5,0.5,(char*)values_string);
 }
 glFlush();
}

void drawQ2(void){
 if(complete_flag==0){
  glClear(GL_COLOR_BUFFER_BIT);
  printMenu();
 }
 if(complete_flag==0){
  int i=0,next_index=0;
  get_string_file(max);
  original[sizeof(original)]='\0'; 
  char final_char[100]="First non-repeated: ";
  char repeated_chars[1000]={};
  char original_string[1000]="Original values: ";
  //Go through string
  i=0;
  while(i<sizeof(original) && original[i]){
   if(search_string(original[i],original)==1){
    repeated_chars[next_index]=original[i];
    next_index++;
   }
   i++;
  }
  complete_flag=1;
  strcat(original_string,original);
  char final_c[10]="";
  final_c[0]=repeated_chars[0];
  strcat(final_char,final_c);
  glPrint(-0.95,0.5,0.5,0.5,0.5,(char*)original_string);
  glPrint(-0.95,0.0,0.5,0.5,0.5,(char*)final_char);
 }
 glFlush();
}

void drawQ3(void){
 glClear(GL_COLOR_BUFFER_BIT);
 printMenu();
 if(complete_flag!=1){
  shuffle_cards();
  complete_flag=1;
 }
 draw_deck(-0.98,0.7,0.15);
 glFlush();
}

void drawScene(void){
 glClear(GL_COLOR_BUFFER_BIT);
 printMenu();
 glPrint(-0.5,0.0,0.5,0.5,0.5,(char*)"Welcome to my resume...");  //copyright
 glFlush();
}

void flash(){
 glutDisplayFunc(drawScene);
}

void setup(void){
 glClearColor(0.0, 0.0, 0.0, 0.0);
}
void refresh(){
 glutSwapBuffers();
 glutPostRedisplay();
}

void keyInput(unsigned char key, int x, int y){
 switch(key)
 {
  case 27://ESC
   exit(0);
   break;
  //Others
  case 'h':
   option=0;
   complete_flag=0;
   glutDisplayFunc(drawScene);
   refresh();
   break;
  case '1':
   option=1;
   values[0]='\0';
   complete_flag=0;
   glutDisplayFunc(drawQ1);
   refresh();
   break;
  case 'r':
   complete_flag=0;
   original[0]='\0';
   refresh();
   break;
  case 's':
   complete_flag=0;
   shuffle_cards();
   refresh();
   break;
  case 'b':
   glClearColor(0.0, 0.0, 0.45, 0.0);
   complete_flag=0;
   original[0]='\0';
   refresh();
   break;
  case 'B':
   glClearColor(0.0, 0.0, 0.0, 0.0);
   complete_flag=0;
   original[0]='\0';
   refresh();
   break;
  case 'p':
   glClearColor(0.63, 0.125, 0.941, 0.0);
   complete_flag=0;
   original[0]='\0';
   refresh();
   break;
  case '2':
   option=2;
   complete_flag=0;
   original[0]='\0';
   glutDisplayFunc(drawQ2);
   refresh();
   break;
  case '3':
   option=3;
   complete_flag=0;
   glutDisplayFunc(drawQ3);
   refresh();
   break;
  case 'u':
   max++;
   refresh();
   break;
  case 'd':
   if(max>1){
    max--;
   }
   refresh();
   break;
  default:
   break;
 }
}

int main(int argc, char **argv){
 srand(time(NULL));
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(800, 600);
 glutInitWindowPosition(400,200);
 glutCreateWindow("resume_questions");
 setup();
 flash();
 glutIdleFunc(refresh); 
 glutKeyboardFunc(keyInput);
 glutMainLoop();
 return 0;  
}


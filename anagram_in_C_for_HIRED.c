#include <stdio.h>
#include <string.h>

void check_anagrams(char** first,char** second,int matches){
 int main_counter=0;
 while(main_counter<matches){
  char* current_string1=first[main_counter];
  char* current_string2=second[main_counter];
  int string_char=0;
  int found_flag=0;
  if(strlen(current_string1)!=strlen(current_string2)){
   printf(\"0
\");
  }
  else{
   found_flag=0;
   while(string_char<strlen(current_string1)){
    char check_char=current_string1[string_char];
    int string_char2=0;
    while(string_char2<strlen(current_string2)){
     if(check_char==current_string2[string_char2]){
      found_flag++;
     }
     string_char2++;
    }
    string_char++;
   }
   if(found_flag>=strlen(current_string1)){
    printf(\"1
\");
   }
   else{
    printf(\"0
\");
   }
  }
  main_counter++;
 }
}
int main(){
 char* string1[]={\"test\",\"last\",\"cast\",\"gabby\",\"love\"};
 char* string2[]={\"sett\",\"slat\",\"castt\",\"ybbag\",\"lov\"};
 char** test_first=string1;
 char** test_second=string2;
 check_anagrams(test_first,test_second,5);
 return 0;
}

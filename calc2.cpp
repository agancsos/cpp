/*
 Name       : calc2
 Author     : Abel Gancsos
 (c)        : Abel Gancsos Productions
 Version    : v. 1.0.0
 Description:
*/

/*
 Release Notes:
  * Initial release
  * Multiplication is handled by x
  * Pow is only calculated as the first operator
  * Flags:
    * -h     : Help menu
    * -binary: Convert value to binary
    * -hex   : Convert value to hex
    * -v     : Print stepped calculations
    * -base  : convert value to base string
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class CALC2{
 public:
  float final; 
  CALC2();
  ~CALC2();
  vector<float>values;
  vector<char*>operators;
  bool isOp(string a);
  bool verbose;
  float calculate();
  string binary(float a);
  string hex(float a);
  string baseCalc(float a,int base);
};
string CALC2::baseCalc(float a,int base){
 string final = "",temp = "";
 if(operators.size() > 0){
  a = calculate();
 }
 while((int(a) / base) > 0 && (int(a) % base) >= 0){
  if(verbose){
   cout << (int(a) / 16) << endl;
   cout << "Remainder: " << (int(a) % 16) << endl;
  }
  temp += to_string((int(a) % base));
  a = (int(a) / base);
 }
 if(verbose){
  cout << (int(a) / 16) << endl;
  cout << "Remainder: " << (int(a) % 16) << endl;
 }
 temp += to_string((int(a) % base));
 for(int i = temp.length()-1;i >= 0; i--){
  final += temp[i];
 }
 return final;
}
string CALC2::hex(float a){
 string final = "",temp = "";
 if(operators.size() > 0){
  a = calculate();
 }
 if(verbose){
  cout << a << endl;
 }
 while((int(a) / 16) > 0 && (int(a) % 16) >= 0){
  if(verbose){
   cout << (int(a) / 16) << endl;
   cout << "Remainder: " << (int(a) % 16) << endl;
  }
  if((int(a) % 16) == 10){
   temp += "A";
  }
  else if((int(a) % 16) == 11){
   temp += "B";
  }
  else if((int(a) % 16) == 12){
   temp += "C";
  }
  else if((int(a) % 16) == 13){
   temp += "D";
  }
  else if((int(a) % 16) == 14){
   temp += "E";
  }
  else if((int(a) % 16) == 15){
   temp += "F";
  }
  else{
   temp += to_string((int(a) % 16));
  }
  a = (int(a) / 16);
 }
 if(verbose){
  cout << "Temp: " << temp << endl;
  cout << (int(a) / 16) << endl;
  cout << "Remainder: " << (int(a) % 16) << endl;
 }
 if((int(a) % 16) == 10){
  temp += "A";
 }
 else if((int(a) % 16) == 11){
  temp += "B";
 }
 else if((int(a) % 16) == 12){
  temp += "C";
 }
 else if((int(a) % 16) == 13){
  temp += "D";
 }
 else if((int(a) % 16) == 14){
  temp += "E";
 }
 else if((int(a) % 16) == 15){
  temp += "F";
 }
 else{
  temp += to_string((int(a) % 16));
 }
 for(int i = temp.length()-1;i >= 0; i--){
  final += temp[i];
 }
 return final;
}
string CALC2::binary(float a){
 string final = "",temp = "";
 if(operators.size() == 0){
  while((int(a) / 2) > 0 && int(a) % 2 >= 0){
   if(verbose){
    cout << (int(a) / 2) << endl;
    cout << "Remainder: " << (int(a) % 2) << endl;
   }
   if((int(a) % 2) > 0){
    temp += "1";
   }
   else{
    temp += "0";
   }
   a = (int(a) / 2);
  }
  if(verbose){
   cout << (int(a) / 16) << endl;
   cout << "Remainder: " << (int(a) % 2) << endl;
  }
  if((int(a) % 2) > 0){
   temp += "1";
  }
 }
 else if(operators.size() > 0){
  float a2 = calculate();
  while((int(a2) / 2) > 0 && int(a2) % 2 >= 0){
   if((int(a2) % 2) > 0){
    temp += "1";
   }
   else{
    temp += "0";
   }
   a2 = (int(a2) / 2);
  }
  if((int(a2) % 2) > 0){
   temp += "1";
  }
 }
 for(int i = temp.length()-1;i >= 0; i--){
  final += temp[i];
 }
 return final;
}
CALC2::CALC2(){
 final = 0;
 verbose = false;
}
CALC2::~CALC2(){
}
float CALC2::calculate(){
 int start = 0;
 for(int i = 0; i < operators.size(); i++){
  if(i == 0){
   if(strcmp(operators[i],"+") == 0){
    final += (values[start] + values[start + 1]);
   }
   else if(strcmp(operators[i],"-") == 0){
    final += (values[start] - values[start + 1]);
   }
   else if(strcmp(operators[i],"x") == 0){
    final += (values[start] * values[start + 1]);
   }
   else if(strcmp(operators[i],"/") == 0){
    final += (values[start] / values[start + 1]);
   }
   else if(strcmp(operators[i],"^") == 0){
    float temp = values[start];
    for(int j = 0; j < values[start + 1] - 1; j++){
     temp *= values[start];
    }
    final += temp;
   }
   start++;
  }
  else{
   if(strcmp(operators[i],"+") == 0){
    final += values[start];;
   }
   else if(strcmp(operators[i],"-") == 0){
    final -= values[start];
   }
   else if(strcmp(operators[i],"x") == 0){
    final *= values[start];
   }
   else if(strcmp(operators[i],"/") == 0){
    final /= values[start];
   }
   else if(strcmp(operators[i],"^") == 0){
    float temp = values[start];
    for(int j = 0; j < values[start + 1]; j++){
     temp *= values[start];
    }
    final += 0;
   }
  }
  start++;
 }
 return final;
}
bool CALC2::isOp(string a){
 if(strcmp(a.c_str(),"^") == 0 || strcmp(a.c_str(),"x") == 0 || strcmp(a.c_str(),"+") == 0 || strcmp(a.c_str(),"/") == 0 || strcmp(a.c_str(),"-") == 0){
  return true;
 }
 return false;
}
void menu(){
 cout << "* Author : Abel Gancsos" << endl;
 cout << "* Version: v. 1.0.0" << endl;
 cout << "* Operators: " << endl;
 cout << "  * +: Addition" << endl;
 cout << "  * -: Subtraction" << endl;
 cout << "  * x: Multiplication" << endl;
 cout << "  * /: Division" << endl;
 cout << "  * ^: Exponential" << endl;
 cout << "* Flags: " << endl;
 cout << "  * -h     : Help menu" << endl;
 cout << "  * -binary: Convert value to binary" << endl;
 cout << "  * -hex   : Convert value to hex" << endl;
 cout << "  * -v     : Print any stepped calculations" << endl;
 cout << "  * -base  : Convert value to a base string" << endl;
 cout << "* Notes:" << endl;
 cout << "  * Exponential will only work in the following examples:" << endl;
 cout << "    * 2 ^ 2" << endl;
 cout << "    * 2 ^ 2 + 5" << endl;
}
int main(int argc,char** argv){
 bool help = false,binary = false,hex = false,base = false;
 int baseValue = 10;
 CALC2 session = CALC2();
 if((argc - 1) > 0){
  for(int i = 1; i < argc; i++){
   if(strcmp(argv[i]," ") != 0){
    if(session.isOp(string(argv[i]))){
     session.operators.push_back(argv[i]);
    }
    else if(strcmp(argv[i],"-h") == 0){
     help = true;
    }
    else if(strcmp(argv[i],"-binary") == 0){
     binary = true;
     hex = false;
     base = false;
    }
    else if(strcmp(argv[i],"-hex") == 0){
     hex = true;
     binary = false;
     base = false;
    }
    else if(strcmp(argv[i],"-base") == 0){
     base = true;
     if((argc - 1) > i){
      baseValue = atoi(argv[i + 1]);
     }
     hex = false;
     binary = false;
    }
    else if(strcmp(argv[i],"-v") == 0){
     session.verbose = true;
    }
    else{
     session.values.push_back(atof(argv[i]));
    }
   }
  }
  if(help){
   menu();
  }
  else{
   if(binary && !hex && !base){
    cout << session.binary(session.values[0]) << endl;
   }
   else if(hex && !binary && !base){
    cout << session.hex(session.values[0]) << endl;
   }
   else if(base && !hex && !binary){
    cout << session.baseCalc(session.values[0],baseValue) << endl;
   }
   else{
    session.final = session.calculate();
    cout << session.final << endl;
   }
  }
 }
 else{
  menu();
 }
 return 0;
}

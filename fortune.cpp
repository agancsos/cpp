/*
 Name       : fortune
 Author     : Abel Gancsos
 (c)        : Abel Gancsos Productions
 Version    : v. 1.0.0
 Description:
*/

/*
 Release Notes:
  * Initial release
  * Flags:
    * -h: Help menu
    * -o: Option
    * -q: Question to ask
    * -c: Path to config file
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

vector<string> splitString(string mstr,char delim){
 vector<string>final;
 string buffer = "";
 for(int i = 0; i < mstr.length(); i++){
  if(mstr[i] == delim || i == mstr.length()-1){
   if(i == mstr.length() -1 && mstr[i] != delim){
    buffer += mstr[i];
   }
   final.push_back(buffer);
   buffer = "";
  }
  else{
   buffer += mstr[i];
  }
 }
 return final;
}
string rightPad(string mstr,int mlen,string pad){
 string final = "";
 if(mstr.length() > mlen){
  return mstr.substr(0,mlen);
 }
 else{
  for(int i = mstr.length(); i < mlen; i++){
   final += pad;
  }
  return (mstr + final);
 }
 return "";
}
string readTextFromFile(string path){
 string final = "",line;
 ifstream myfile (path.c_str());
 if(myfile.is_open()){
  while(getline(myfile,line)){
   final += (line + "\n");
  }
  myfile.close();
  return final;
 }
 else{
  cout << "Unable to open config file: " << path << endl;
  return "";
 }
 return "";
}
class FORTUNE{
 public:
  FORTUNE();
  ~FORTUNE();
  string configFile;
  string wishText;
  string response;
  vector<string>options;
  vector<string>values;
  string option;
  string ask();
};
FORTUNE::FORTUNE(){
 configFile = "c:\\temp\\fortune.conf";
 wishText = "";
 response = "";
 option = "";
}
FORTUNE::~FORTUNE(){
}
string FORTUNE::ask(){
 string fileRaw = "";
 fileRaw = readTextFromFile(configFile);
 vector<string>params = splitString(fileRaw,'\n');
 for(int i = 0; i < params.size(); i++){
  if(splitString(params[i],'=').size() > 1){
   options.push_back(splitString(params[i],'=')[0]);
   values.push_back(splitString(params[i],'=')[1]);
  }
 }
 if(option == ""){
  cout << "Pick fortune:: ";
  for(int i = 0; i < options.size();i++){
   cout << (i + 1) << " (" << splitString(options[i],'=')[0] + ") ";
  }
  cout << " : ";
  cin >> option;
  cout << endl;
 }
 int index = atoi(option.c_str());
 if(index > options.size()){
  cout << "Invalid option..." << endl;
 }
 else{
  cout << "Fortune: " << values[index-1] << endl;
 }
 return "";
}
void menu(){
 cout << rightPad("",60,"=") << endl;
 cout << "* Name   : fortune" << endl;
 cout << "* Author : Abel Gancsos" << endl;
 cout << "* (c)    : Abel Gancsos Productions" << endl;
 cout << "* Version: v. 1.0.0" << endl;
 cout << "* Flags:" << endl;
 cout << "  * -h: Help menu" << endl;
 cout << "  * -q: Question" << endl;
 cout << "  * -c: Config file path" << endl;
 cout << "  * -o: Value for options" << endl;
 cout << "* Config file:" << endl;
 cout << "  * [option]=[value]" << endl;
 cout << rightPad("",60,"=") << endl;
}
int main(int argc,char** argv){
 bool help = false;
 FORTUNE session = FORTUNE();
 if((argc - 1) > 0){
  for(int i = 0; i < argc; i++){
   if(strcmp("-h",argv[i]) == 0){
    help = true;
   }
   else if(strcmp("-c",argv[i]) == 0){
    session.configFile = argv[i + 1];
   }
   else if(strcmp("-q",argv[i]) == 0){
    session.wishText = argv[i + 1];
   }
   else if(strcmp("-o",argv[i]) == 0){
    session.option = argv[i + 1];
   }
  }
 }
 else{
  cout << "Enter question to ask: ";
  cin >> session.wishText;
  cout << endl; 
 }
 if(help){
  menu();
 }
 else{
  cout << session.ask();
 }
 return 0;
}

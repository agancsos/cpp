#include <iostream>
#include <string>
#include <vector>
#include "AMGString/amgstring.h"
#include "AMGExtractor/amgextractor.h"
using namespace std;

void menu(){
	cout << AMGString("").padRight(80,"=") << endl;
	cout << "* Name   : MET Data" << endl;
	cout << "* Author : Abel Gancsos" << endl;
	cout << "* Version: v. 1.0.0" << endl;
	cout << "* Flags:" << endl;
	cout << "	* -f: Application file path  (default: ../resources/dat/student.dat)" << endl;
	cout << "	* -d: Delimiter for sections (default: ;)" << endl;
	cout << "* NOTES:" << endl;
	cout << "	* Inner lists should be comma-separated" << endl;
	cout << "	* Example file would be: <program>|c3,c4,c5|c1,c2|Database,ETL" << endl;
	cout << AMGString("").padRight(80,"=") << endl;
}	

int main(int argc, char **argv){
	bool help = false;

	AMGExtractor session = AMGExtractor();

	// Read parameters from the command line
	if((argc - 1) > 0){
		for(int i = 0; i < argc; i++){
			if(string(argv[i]) == "-h"){
				help = true;
			}
			else if(string(argv[i]) == "-f"){
				session.setFilePath(string(argv[i + 1]));
			}
			else if(string(argv[i]) == "-d"){
				session.setDelim(string(argv[i + 1]));
			}
		}
	}
	// Print menu if asked for
	if(help){
		menu();
	}
	else{
		session.display();
	}
    
	return 0;
}


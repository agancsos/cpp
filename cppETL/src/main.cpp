#include <iostream>
#include <string>
#include <vector>
#include "AMGString/amgstring.h"
#include "AMGSystem/amgsystem.h"
#include "AMGETL/amgetl.h"
using namespace std;

void menu(){
	cout << AMGString("").PadRight(80,"=") << endl;
	cout << "* Name   : cppETL" << endl;
	cout << "* Author : Abel Gancsos" << endl;
	cout << "* Version: v. 1.0.0" << endl;
	cout << "* Flags:" << endl;
	cout << "	* -f: Application file path" << endl;
	cout << " 	* -d: Type of records to import" << endl;
	cout << AMGString("").PadRight(80,"=") << endl;
}	

int main(int argc, char **argv){
	bool help = false;

	AMGETL session = AMGETL();

	// Read parameters from the command line
	if((argc - 1) > 0){
		for(int i = 0; i < argc; i++){
			if(string(argv[i]) == "-h"){
				help = true;
			}
			else if(string(argv[i]) == "-f"){
				session.applicationFilePath = string(argv[i + 1]);
			}
			else if(string(argv[i]) == "-d"){
				session.dataType = string(argv[i + 1]);
			}
		}
	}
	// Print menu if asked for
	if(help){
		menu();
	}
	else{
		session.Run();
	}
    
	return 0;
}

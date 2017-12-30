#include <iostream>
#include <string>
#include <vector>
#include "AMGString/amgstring.h"
#include "AMGPreparer/amgpreparer.h"
using namespace std;

void menu(){
	cout << AMGString("").padRight(80,"=") << endl;
	cout << "* Name   : Preparer" << endl;
	cout << "* Author : Abel Gancsos" << endl;
	cout << "* Version: v. 1.0.0" << endl;
	cout << "* Flags:" << endl;
	cout << "	* -max   : Max number of seasons to create (default: 1)" << endl;
	cout << "	* -season: Starting season                 (default: 1)" << endl;
	cout << "	* -disks : Number of disks to create       (default: 3)" << endl;
	cout << "	* -silent: Don't print any messages" << endl;
	cout << AMGString("").padRight(80,"=") << endl;
}	

int main(int argc, char **argv){
	bool help = false;

	AMGPreparer session = AMGPreparer();

	// Read parameters from the command line
	if((argc - 1) > 0){
		for(int i = 0; i < argc; i++){
			if(string(argv[i]) == "-h"){
				help = true;
			}
			else if(string(argv[i]) == "-max"){
				session.setMax(string(argv[i + 1]));
			}
			else if(string(argv[i]) == "-season"){
				session.setSeason(string(argv[i + 1]));
			}
			else if(string(argv[i]) == "-disks"){
                session.setDisks(string(argv[i + 1]));
            }
			else if(string(argv[i]) == "-silent"){
				session.setSilent(true);
			}
		}
	}
	// Print menu if asked for
	if(help){
		menu();
	}
	else{
		session.prepare();
	}
    
	return 0;
}

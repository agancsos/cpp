//
// Name       : cppPackage
// Author     : Abel Gancsos
// Version    : v. 1.0.0
// Description: This utility helps package a new CPP program
//

#include <iostream>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <fstream>
using namespace std;

// Packager class
class Packager{
	public:
		string basePath;
		string packageName;
		Packager();
		~Packager();
		Packager(string b);
		Packager(string b, string n);
		bool run();
};
Packager::Packager(){
	basePath = "./";
	packageName = "test";
}

Packager::~Packager(){
}

Packager::Packager(string b){
	basePath = b;
	packageName = "test";
}

Packager::Packager(string b, string n){
	basePath = b;
	packageName = n;
}

bool Packager::run(){
	try{
		// Create base directory
		try{
			mkdir((basePath + packageName).c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		}
		catch(exception &e){
		}
		// Create resources directory
        try{
            mkdir((basePath + packageName + "/resources").c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        }
        catch(exception &e){
        }
		// Create source directory
        try{
            mkdir((basePath + packageName + "/src").c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        }
        catch(exception &e){
        }
        try{
            mkdir((basePath + packageName + "/bin").c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        }
        catch(exception &e){
        }
		// Add main source file
        try{
			ofstream file((basePath + packageName + "/src/main.cpp").c_str());
			if(file.is_open()){
				file << "#include <iostream>" << endl;
				file << "using namespace std;" << endl;
				file << endl;
				file << "int main(int argc, char **argv){" << endl;
				file << "\treturn 0;" << endl;
				file << "}";
				file.close();
			}
			else{
			}
        }
        catch(exception &e){
        }
		// Add make script
        try{
            ofstream file((basePath + packageName + "/src/make.sh").c_str());
            if(file.is_open()){
                file << "#!/bin/bash" << endl;
				file << "APP_ROOT=$(dirname \"$0\")" << endl;
                file << "g++ $APP_ROOT/*.cpp \\" << endl;
                file << "\t-o $APP_ROOT/../bin/" << packageName;
                file.close();
            }
            else{
            }
        }
        catch(exception &e){
        }
	}
	catch(exception &e){
		return false;
	}
	return true;
}
/******************************************************************************/

void menu(){
	for(int i = 0; i < 80; i++){
		cout << "=";
	}
	cout << endl;
	cout << "* Name   : cppPackage" << endl;
	cout << "* Author : Abel Gancsos" << endl;	
	cout << "* Version: v. 1.0.0" << endl;	
	cout << "* Flags:" << endl;
	cout << "	* -b: Base path to create the package" << endl;
	cout << " 	* -p: Name of the package" << endl;
    for(int i = 0; i < 80; i++){    
        cout << "=";
    }
    cout << endl;
}

int main(int argc, char **argv){
	bool help = false;
	Packager session = Packager();
	if((argc - 1) > 0){
		for(int i = 0; i < argc; i++){
			if(string(argv[i]) == "-h"){
				help = true;
			}
			else if(string(argv[i]) == "-b"){
				session.basePath = string(argv[i + 1]);
			}
			else if(string(argv[i]) == "-p"){
				session.packageName = string(argv[i + 1]);
			}	
		}
	}

	if(help){
		menu();
	}
	else{
		if(session.run()){
			cout << "Created package..." << endl;
		}
		else{
			cout << "Failed to create package..." << endl;
		}
	}
	return 0;
}

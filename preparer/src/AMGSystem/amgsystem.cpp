#include "amgsystem.h"
using namespace std;

/**
	This is the default constructor
*/
AMGSystem::AMGSystem(){
}

/**
	This is the deconstructor
*/
AMGSystem::~AMGSystem(){
}

/**
	This is the common constructor
*/
AMGSystem::AMGSystem(string src){
	source = src;
}

/**
	This is the full constructor
*/
AMGSystem::AMGSystem(string src,string tar){
	source = src;
	target = tar;
}

bool AMGSystem::fileExists(string path){
	if(FILE *file = fopen(path.c_str(), "r")){
        fclose(file);
        return true;
    } 
	else{
        return false;
    }   
}

/**
	This method reads the data from the source file
*/
string  AMGSystem::readFile(){
	string mFinal = "";
	string buffer = "";
	if(source != ""){
		if(fileExists(source)){
			ifstream file(source.c_str());
			if(file.is_open()){
				while(getline(file,buffer)){
					mFinal += ("\n" + buffer);
				}
				file.close();
				return mFinal;
			}
			else{
				throw invalid_argument("Failed to open source file path...");
			}
		}
		else{
			throw invalid_argument("Source file path does not exists...");
		}
	}
	else{
		throw invalid_argument("Source file path is empty...");
	}
	return "";
}

/**
	This method writes text to the target file
*/
void AMGSystem::writeFile(string data){
	if(target != ""){
		ofstream file(target.c_str());
		if(file.is_open()){
			file << data << endl;
			file.close();
		}
		else{
			throw invalid_argument("Failed to open target file path...");
		}
	}
	else{
		throw invalid_argument("Target file path is empty...");
	}
}

/**
	This method checks if a folder exists
*/
bool AMGSystem::folderExists(string path){
	struct stat fileSystem;
	if(stat(path.c_str(),&fileSystem) != 0){
		return false;
	}
	else if(fileSystem.st_mode & S_IFDIR){
		return true;
	}
	return false;	
}

/**
	This method creates a new directory
*/
bool AMGSystem::createFolder(){
	try{
		system(("mkdir \"" + target + "\"").c_str());
	}
	catch(exception &e){
		return false;
	}
	return true;
}

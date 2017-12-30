#ifndef __AMGSYSTEM_H_INCLUDED__  
#define __AMGSYSTEM_H_INCLUDED__ 

#include <string>
#include <vector>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;

/**
	This class is a custom wrapper for system operations
*/
class AMGSystem{
	private:
        string source;
        string target;
	public:
		AMGSystem();
		~AMGSystem();
		AMGSystem(string src);
		AMGSystem(string src,string tar);
		string readFile();
		void writeFile(string data);
		bool fileExists(string path);
		bool folderExists(string path);	
		bool createFolder();
};

#endif

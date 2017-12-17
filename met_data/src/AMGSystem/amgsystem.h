#ifndef __AMGSYSTEM_H_INCLUDED__  
#define __AMGSYSTEM_H_INCLUDED__ 

#include <string>
#include <vector>
#include <fstream>
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
};

#endif

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
	public:
		string source;
		string target;
		AMGSystem();
		~AMGSystem();
		AMGSystem(string src);
		AMGSystem(string src,string tar);
		string ReadFile();
		void WriteFile(string data);
		bool FileExists(string path);
};

#endif

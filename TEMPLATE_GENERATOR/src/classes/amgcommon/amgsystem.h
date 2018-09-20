#ifndef __AMGSYSTEM_H_INCLUDED__  
#define __AMGSYSTEM_H_INCLUDED__ 

#include <iostream>
#if !defined(WIN32) && !defined(_WIN32) && !defined(__WIN32) && !defined(__CYGWIN__)
    #include <unistd.h>
#else
    #include <windows.h>
#endif
#include <string>
#include <vector>
#include <stdexcept>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
#include "amgstring.h"
using namespace std;

namespace amgcommon{
    enum class INPUT_TYPES {
        STRING,
        NUMBER,
        BOOL
    };
    

	/**
 	 * This class offers custom system operations
 	 * @author  (Abel Gancsos)
 	 * @version (v. 1.0.0)
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
			void setSource(string a);
			void setTarget(string a);
			void makeDirectory();
			string getSource();
			string getTarget();
			bool fileExists(string path);
			static void sleeper(int seconds);
            static void exitProgram();
            static bool isDigit(string a);
            static bool validateInput(string a, INPUT_TYPES b);
            static void runCommand(string cmd);
			static bool directoryExists(string path);
			static bool isWindows();
	};
}

#endif

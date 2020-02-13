#ifndef __SYSTEMSERVICE_H_INCLUDED__  
#define __SYSTEMSERVICE_H_INCLUDED__ 
#include <iostream>
#define _WINSOCKAPI_
#if !defined(WIN32) && !defined(_WIN32) && !defined(__WIN32) && !defined(__CYGWIN__)
    #include <unistd.h>
	#include <dirent.h>
#else
    #include <windows.h>
	#define __WINDOWS__
	#define __ISWINDOWS__
#endif
#include <string>
#include <vector>
#include <stdexcept>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
#include "../string.h"
#include "../enumfactory.h"
#include "../system/fileobject.h"
using namespace std;
using namespace amgcommon;

namespace amgcommon {
	namespace system {
		 class SystemService {
			private:
				static string modulePath;
			public:
				SystemService(string src = "", string tar = "");
				~SystemService();
				static string readFile(const string path);
				static void writeFile(const string path, const string data);
				static void deleteFile(const string path);
				static bool fileExists(const string path);
				static void sleeper(int seconds);
				static void exitProgram();
				static bool isDigit(string a);
				static bool validateInput(string a, InputTypes b);
				static void runCommand(string cmd);
				static string runCommand2(const string cmd);
				static bool directoryExists(string path);
				const static string getModulePath();
				static bool isWindows();
				const static string buildModuleContainerPath();
				static void setModulePath(const string a);
				static bool copyDirectoryContents(const string source, const string target);
				const static vector<shared_ptr<FileObject> > getChildren(string root, bool recurse = false);
		};
	}
}
#endif

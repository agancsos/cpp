#ifndef __FILEOBJECT_H_INCLUDED__  
#define __FILEOBJECT_H_INCLUDED__ 
#include <iostream>
using namespace std;

namespace amgcommon {
	namespace system {
		class FileObject {
			private:
				string name;
				string path;
				bool isDirectory;
			public:
				FileObject(string name = "", string path = "", bool directory = false) {
					this->name = name;
					this->path = path;
					this->isDirectory = directory;
				}
				void setName(string name) { this->name = name; }
				void setPath(string path) { this->path = path; }
				void setIsDirectory(bool directory) { this->isDirectory = directory; }
				string getName() { return name; }
				string getPath() { return path; }
				string getFullPath() { return (path + "/" + name); }
				bool getIsDirectory() { return isDirectory; }
		};
	}
}
#endif
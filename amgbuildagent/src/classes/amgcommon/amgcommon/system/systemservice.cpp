#include "systemservice.h"

namespace amgcommon {
	namespace system {
		string SystemService::modulePath = "";

		SystemService::SystemService(string src, string tar) {
			
		}
		
		SystemService::~SystemService() {
			
		}

		const string SystemService::buildModuleContainerPath() {
			string buffer = "";
			vector<string> comps = AMGString(modulePath).replaceAll("\\", "/").split("/");
			for (int i = 0; i < comps.size() - 1; i++) {
				if (i > 0) 
					buffer += "/";
				buffer += comps[i];
			}
			return buffer;
		}

		string SystemService::runCommand2(const string cmd) {
			char buffer[300];
			string result = "";
			FILE *pipe = NULL;
			#ifdef __ISWINDOWS__
				pipe = _popen(cmd.c_str(), "r");
			#else
				pipe = popen(cmd.c_str(), "r");
			#endif
			if(pipe) {
				try {
					while(fgets(buffer, sizeof(buffer), pipe) != NULL) {
						result += string(buffer);
					}
				}
				catch(...) {
					#ifdef __ISWINDOWS__
						_pclose(pipe);
					#else
						pclose(pipe);
					#endif
				}
				#ifdef __ISWINDOWS__
					_pclose(pipe);
				#else
					pclose(pipe);
				#endif
			}
			return result;
		}

		string SystemService::readFile(const string path) {
			string mFinal = "";
			string buffer = "";
			if(path != ""){
				if(fileExists(path)){
					ifstream file(path.c_str());
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
		
		void SystemService::writeFile(const string path, const string data) {
			if(path != ""){
				ofstream file(path.c_str());
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
		
		void SystemService::deleteFile(const string path) {
			if(fileExists(path)) {
				remove(path.c_str());
			}
		}
		
		bool SystemService::fileExists(const string path) {
			if(FILE *file = fopen(path.c_str(), "r")){
				fclose(file);
				return true;
			}
			else{
				return false;
			}
		}
		
		void SystemService::sleeper(int seconds) {
			#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
				Sleep(seconds * 100);
			#else
				sleep(seconds);
			#endif
		}
		
		void SystemService::exitProgram() {
			cout << "Thank you for visiting.  Please come again soon...." << endl;
			exit(0);
		}
		
		bool SystemService::isDigit(string a) {
			for(int i = 0; i < a.length(); i++){
				if(!isdigit(a[i])){
					return false;
				}
			}
			return true;
		}
		
		bool SystemService::validateInput(string a, InputTypes b) {
			switch(b){
				case InputTypes::STRING:
					return true;
				case InputTypes::NUMBER:
					return isDigit(a);
				case InputTypes::BOOL:
					if(AMGString(a).toLowerCase().get() == "1" ||
						AMGString(a).toLowerCase().get() == "yes" ||
						AMGString(a).toLowerCase().get() == "y"){
						return true;
					}
					else{
						return false;
					}
				default:
					break;
			}
			return false;
		}
		void SystemService::runCommand(string cmd) {
			if(isWindows()) {
				std::system(cmd.c_str());
			}
			else {
				std::system(cmd.c_str());
			}
		}
		
		bool SystemService::directoryExists(string path) {
			struct stat system_info;
			
			if(stat(path.c_str(), &system_info) == 0) {
				if(system_info.st_mode &S_IFDIR)
					return true;
			}
			return false;
		}
		
		bool SystemService::isWindows() {
			#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
				return true;
			#endif
			return false;
		}
		
		bool SystemService::copyDirectoryContents(const string source, const string target) {
			try {
				if(directoryExists(source) && directoryExists(target)) {
					
				}
			}
			catch(exception &e) {
				return false;
			}
			return true;
		}
		
		const vector<shared_ptr<FileObject> > SystemService::getChildren(string root, bool recurse) {
			vector<shared_ptr<FileObject> > result;
			if(directoryExists(root)) {
				#ifndef __WINDOWS__
					DIR *directory;
					struct dirent *entry;
					if((directory = opendir(root.c_str())) != NULL){
						while((entry = readdir(directory)) != NULL) {
							shared_ptr<FileObject> tempObject(new FileObject(string(entry->d_name), root, (entry->d_type == DT_REG ? false : true)));
							result.push_back(tempObject);
							if(recurse) {
								vector<shared_ptr<FileObject> > children;
								children = getChildren(tempObject->getFullPath(), recurse);
								for(shared_ptr<FileObject> cursor : children) {
									result.push_back(cursor);
								}
							}
						}
						closedir(directory);
					}
				#else
				#endif
			}
			return result;
		}

		void SystemService::setModulePath(const string a) { SystemService::modulePath = a; }
		const string SystemService::getModulePath() { return modulePath; }
	}
}

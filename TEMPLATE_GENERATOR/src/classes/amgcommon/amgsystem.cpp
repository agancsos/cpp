#include "amgsystem.h"

namespace amgcommon{
    /**
     * This method quits the program
     * @output        (Closing message)
     * @precondition  (The utiity must be running)
     * @postcondition (The program exists)
     */
    void AMGSystem::exitProgram(){
        printf("Thank you for visiting.  Please come again soon.... \n");
        exit(0);
    }

	void AMGSystem::makeDirectory() {
		if(! AMGSystem::directoryExists(target)){
			AMGSystem::runCommand("mkdir \"" + target + "\"");
		}
	}
    
    /**
     * This method checks if a string is a digit string
     * @param a String value to parse
     * @return        (True if all characters are integers, false if not)
     * @precondition  (A string value is provided)
     * @postcondition (Result is returned)
     * @todo          (hould be changed to lambda function)
     */
    bool AMGSystem::isDigit(string a){
        for(int i = 0; i < a.length(); i++){
            if(!isdigit(a[i])){
                return false;
            }
        }
        return true;
    }
    
    /**
     * This method checks if the system is Windows
     * @return True if Windows, false if not
     */
	bool AMGSystem::isWindows() {
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			return true;
        #endif
		return false;
	}
    
    /**
     * This method runs a command on the system level
     */
    void AMGSystem::runCommand(string cmd) {
		if(isWindows()) {
            system(("cmd /c \"" + cmd + "\"").c_str());
		}
		else {
            system(cmd.c_str());
        }
    }

	/**
	 * This method checks if a directory exists
	 * @param path Full path to the directory
	 * @return True if exists, false if not
	 */
	bool AMGSystem::directoryExists(string path) {
		struct stat system_info;

    	if(stat(path.c_str(), &system_info) == 0) {
    		if(system_info.st_mode &S_IFDIR)
        		return true;
		}
		return false;
	}
    
    /**
     * This method validates a user input
     * @return        (True if valid, false if not)
     * @param a Input to validate
     * @param b Input type
     * @precondition  (A string input value must be provided)
     * @postcondition (Result is returned)
     */
    bool AMGSystem::validateInput(string a, INPUT_TYPES b){
        switch(b){
            case INPUT_TYPES::STRING:
                return true;
            case INPUT_TYPES::NUMBER:
                return isDigit(a);
            case INPUT_TYPES::BOOL:
                if(AMGString(a).toLowerCase() == "1" ||
                   AMGString(a).toLowerCase() == "yes" ||
                   AMGString(a).toLowerCase() == "y"){
                    return true;
                }
                else{
                    return false;
                }
        }
        return false;
    }
    
	/**
	 * This method causes the process to sleep for a period of time
	 * @param seconds Amount of seconds to sleep
	 * @postcondition (The process waits for a period of tine)
	 */
	void AMGSystem::sleeper(int seconds){
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        	Sleep(seconds * 100);
        #else
        	sleep(seconds);
        #endif
	}

    /**
     * This is the default constructor.
     * @postcondition (A new AMGSystem object has been created.)
     */
    AMGSystem::AMGSystem(){
    }

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGSystem::~AMGSystem(){
    }

    /**
     * This is another constructor that sets the source path
     * @param src Full path for a source location
     * @precondition  (The path location exists or can be created)
     * @postcondition (A new AMGSystem object is created with the source location)
     */
    AMGSystem::AMGSystem(string src){
        source = src;
    }

    /**
     * This is another constructor that sets the source path and target path
     * @param src Full path for a source location
     * @param tar Full path for a parent target location
     * @precondition  (The source path location exists and the target location is accessible)
     * @postcondition (A new AMGSystem object is created with the source and target locations)
     */
    AMGSystem::AMGSystem(string src,string tar){
        source = src;
        target = tar;
    }

    /**
     * This is the public setter for the source path location
     * @param s Full path for a source location
     * @precondition  (The path location exists)
     * @postcondition (The value of the source location is set)
     */
    void AMGSystem::setSource(string a){
        source = a;
    }

    /**
     * This is the public setter for the target path location
     * @param t Full path for a target location
     * @precondition  (The path location exists )
     * @postcondition (The value of the target location is set)
     */
    void AMGSystem::setTarget(string a){
        target = a;
    }

    /**
     * This is the public getter for the source path location
     * @return        (Value of the source path location)
     * @precondition  (The value of the source path is not empty/null)
     * @postcondition (The value of the source path is returned)
     */
    string AMGSystem::getSource(){
        return source;
    }

    /**
     * This is the public getter for the target path location
     * @return        (Value of the target path location)
     * @precondition  (The value of the target path is not empty/null)
     * @postcondition (The value of the target path is returned)
     */
    string AMGSystem::getTarget(){
        return target;
    }

    /**
     * This method checks if the location exists
     * @param path    Full path for a location on the system
     * @return        (True if exists, false if not)
     * @precondition  (The value of the path is not empty/null)
     * @postcondition (Boolean value if the path exists on the system)
     */
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
     * This method reads text from the source path location
     * @return        (Text from the source file)
     * @precondition  (The source location exists and can be read)
     * @postcondition (Text from the file)
     */
    string AMGSystem::readFile(){
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
     * This method writes some data to the target location
     * @param data    Text to be written tot he file
     * @return        (True if successful, false if not)
     * @precondition  (The value of the path is not empty/null and can be written to)
     * @postcondition (The text has been written to the target location
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
}

#include "amgconfiguration.h"

namespace amgcommon {
    /**
     * This is the default constructor
     * @precondition  (There is a need to log information)
     * @postcondition (A new AMGConfiguration object is created)
     */
    AMGConfiguration::AMGConfiguration(){
        inputFile = "";
    }

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGConfiguration::~AMGConfiguration(){
    }

    /**
     * This is the common constructor
     * @param a Full path to the input file
     * @precondition  (There is a need to log information)
     * @postcondition (A new AMGConfiguration object is created)
     */
    AMGConfiguration::AMGConfiguration(string a){
        inputFile = a;
    }

    /**
     * This method logs data to an output file
     * @param a Name of the key to lookup
     * @precondition  (An input file must be accessible)
     * @postcondition (The configuration setting is read from the input file)
     */
    string AMGConfiguration::lookupKey(string a){
        if(AMGSystem().fileExists(inputFile)){
            try{
                string rawContent = AMGSystem(inputFile).readFile();
                vector<string> pairs = AMGString(rawContent).splitByLine();
                for(int i = 0; i < pairs.size(); i++){
                    string pair = pairs[i];
                    vector<string> comps = AMGString(pair).split("=");
                    if(comps.size() >= 2){
                        if(comps[0][0] != '#'){
                            if(comps[0] == a){
                                return AMGString(comps[1]).strip();
                            }
                        }
                    }
                }
            }
            catch(exception &e){
            }
        }
        return "";
    }

    /**
     * This method sets the value for the output file
     * @param a Full path to the output file
     * @precondition  (The AMGTracer object exists)
     * @postcondition (The value for the output file was set)
     */
    void AMGConfiguration::setInputFile(string a){
        inputFile = a;
    }

    /**
     * This method retrieves the path to the input file
     * @return Full path to the input file
     * @precondition  (An instance of the object must exist)
     * @postcondition (The full path to the input file is returned)
     */
    string AMGConfiguration::getInputFile(){
        return inputFile;
    }
}

#include "plainpropertystore.h"

namespace amgcommon {
    namespace propertystores {
        PlainPropertyStore::PlainPropertyStore(string src, string delim) : PropertyStore<string, string>(src) {
            this->delimeter = delim;
        }
            
        PlainPropertyStore::~PlainPropertyStore() {
                
        }

        string PlainPropertyStore::getProperty(string key) {
            string rawContent = readFile();
            vector<string> pairs = AMGString(rawContent).splitByLine();
            for(int i = 0; i < pairs.size(); i++){
                string pair = pairs[i];
                vector<string> comps = AMGString(pair).split(delimeter);
                if(comps.size() >= 2){
                    if(comps[0][0] != '#'){
                        if(comps[0] == key){
                            return comps[1];
                        }
                    }
                }
            }
            return "";
        }
            
        vector<string> PlainPropertyStore::getKeys() {
            vector<string> result;
            return result;
        }

        void PlainPropertyStore::setProperty(string key, string value) {
            string rawContent = readFile();
            string buffer = "";
            vector<string> pairs = AMGString(rawContent).splitByLine();
            for(int i = 0; i < pairs.size(); i++){
                string pair = pairs[i];
                vector<string> comps = AMGString(pair).split(delimeter);
                if(i > 0) {
                    buffer += "\n";
                }
                if(comps.size() >= 2){
                    if(comps[0] == key){
                        buffer += (comps[0] + " " + delimeter + comps[1]);
                    }
                    else {
                        buffer += pair;
                    }
                }
            }
            writeData(buffer);
        }

        string PlainPropertyStore::getDelimeter() { return this->delimeter; }
        void PlainPropertyStore::setDelimeter(string delim) { this->delimeter = delim; }
    }
}

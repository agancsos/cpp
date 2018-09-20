#include "amgstring.h"

namespace amgcommon{
    /**
     * This is the default constructor
     * @postcondition (A new AMGString object has been created.)
     */
    AMGString::AMGString(){
        str = "";
    }

    /**
     * This method converts the value to all lowercase
     * @precondition  (The value must be set)
     * @postcondition (The value is lowercased)
     * @return Lowercase string
     */
    string AMGString::toLowerCase(){
        string mResult = "";
        for(int i = 0; i < str.length(); i++){
            mResult += tolower(str[i]);
        }
        return mResult;
    }

    /**
     * This method converts the value to all uppercase
     * @precondition  (The value must be set)
     * @postcondition (The value is uppercased)
     * @return Uppercase string
     */
    string AMGString::toUpperCase(){
        string mResult = "";
        for(int i = 0; i < str.length(); i++){
            mResult += toupper(str[i]);
        }
        return mResult;
    }

    /**
     * This is the common constructor
     * @param str Value to set for the class
     * @precondition  (There is a string that is not empty/null)
     * @postcondition (A new AMGString object has been created from the new string)
     */
    AMGString::AMGString(string st){
        str = st;
    }

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGString::~AMGString(){
    }

    /**
     * This method pads a string
     * @param len Length of the pad
     * @param pad String to use for padding
     * @return Right-padded string
     * @precondition  (The value property of the class is not empty/null)
     * @postcondition (A new right-padded string from the value string)
     */
    string AMGString::padRight(int len, string pad){
        if(str.length() > len){
            return str.substr(0,len);
        }
        else{
            string mFinal = "";
            for(int i = str.length(); i < len; i++){
                mFinal += pad;
            }
            return (str + mFinal);
        }
    }

    /**
     * This method pads a string
     * @param len Length of the pad
     * @param pad String to use for padding
     * @return Left-padded string
     * @precondition  (The value property of the class is not empty/null)
     * @postcondition (A new left-padded string from the value string)
     */
    string AMGString::padLeft(int len, string pad){
        if(str.length() > len){
            return str.substr(0,len);
        }
        else{
            string mFinal = "";
            for(int i = str.length(); i < len; i++){
                mFinal += pad;
            }
            return (mFinal + str);
        }
    }

    /**
     * This method splits a string based on a delimeter
     * @param delim String to be used to split the string
     * @return String collection split by a delimeter
     * @precondition  (The instance of the object exists)
     * @postcondition (The string is split into a string collection)
     */
    vector<string> AMGString::split(string delim){
        vector<string> mFinal;
        string buffer = "";
        for(int i = 0; i < str.length(); i++){
            if(buffer == delim || string(1,str[i]) == delim){
                mFinal.push_back(buffer);
                buffer = "";
            }
            else{
                buffer += string(1,str[i]);
            }
        }
        if(buffer != ""){
            mFinal.push_back(buffer);
        }
        return mFinal;
    }

    /**
     * This method splits a string based on line ending
     * @return String collection of the text split by newline
     * @precondition  (The instance of the object exists)
     * @postcondition (The string is split into a string collection)
     */
    vector<string> AMGString::splitByLine(){
        vector<string> mFinal;
        string buffer = "";
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '\0' || str[i] == '\n'){
                mFinal.push_back(buffer);
                buffer = "";
            }
            else{
                buffer += string(1,str[i]);
            }
        }
        if(buffer != ""){
            mFinal.push_back(buffer);
        }
        return mFinal;
    }

    /**
     * This method replaces all occurrences of a string with a different string
     * @param search String to look for
     * @param replace String to replace text with
     * @return A string with the appropriate text
     * @precondition  (The instance of the object exists)
     * @postcondition (All occurrences of the search string are replaced)
     */
    string AMGString::replaceAll(const string search, const string replace){
        size_t start = 0;
        while((start = str.find(search, start)) != string::npos){
            str.replace(start,search.length(),replace);
            start += replace.length();
        }
        return str;
    }

    /**
     * This method strips newline characters
     * @return New text with no new line characters
     * @precondition  (The instance of the object exists)
     * @postcondition (Newline characters are replaced from the string)
     */
    string AMGString::strip(){
        string mFinal = str;
        mFinal = AMGString(mFinal).replaceAll("\n","");
        return mFinal;
    }

    /**
     * This method checks if the text contains another text
     * @param search Text to look up
     * @return True if exists, false if not
     * @precondition  (The instance of the object exists)
     * @postcondition (The result of the lookup is properly returned)
     */
    bool AMGString::contains(string search){
        if(AMGString(str).replaceAll(search,"") != str){
            return true;
        }
        return false;
    }
}

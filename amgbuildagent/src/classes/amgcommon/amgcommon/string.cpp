#include "./string.h"
namespace amgcommon{
    AMGString::AMGString(){
        str = "";
    }

    AMGString::AMGString(const AMGString &a) {
        this->str = a.str;
    }

	AMGString::AMGString(string st){
		str = st;
	}

	AMGString::AMGString(const char *a){
		str = string(a);
	}

    AMGString::~AMGString(){
    }

    AMGString AMGString::toLowerCase(){
        AMGString mResult = "";
        for(int i = 0; i < str.length(); i++){
            mResult += tolower(str[i]);
        }
        return mResult;
    }

    AMGString AMGString::toUpperCase(){
        AMGString mResult = "";
        for(int i = 0; i < str.length(); i++){
            mResult += toupper(str[i]);
        }
        return mResult;
    }

    AMGString AMGString::padRight(int len, string pad){
        if(str.length() > len){
            return str.substr(0,len);
        }
        else{
            AMGString mFinal = "";
            for(int i = str.length(); i < len; i++){
                mFinal += pad;
            }
            return (str + mFinal.get());
        }
    }

    AMGString AMGString::padLeft(int len, string pad){
        if(str.length() > len){
            return str.substr(0,len);
        }
        else{
            AMGString mFinal = "";
            for(int i = str.length(); i < len; i++){
                mFinal += pad;
            }
            return (mFinal + str);
        }
    }

    vector<string> AMGString::split(string delim){
        vector<string> mFinal;
        string buffer = "";
        for(int i = 0; i < str.length(); i++){
			if(delim == "") {
				mFinal.push_back(string(1, str[i]));
			}
            else if(buffer == delim || string(1,str[i]) == delim){
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

    vector<AMGString> AMGString::split2(string delim){
        vector<AMGString> mFinal;
        string buffer = "";
        for(int i = 0; i < str.length(); i++){
			if(delim == "") {
				mFinal.push_back(string(1, str[i]));
			}
            else if(buffer == delim || string(1,str[i]) == delim){
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

    vector<AMGString> AMGString::splitByLine2(){
        vector<AMGString> mFinal;
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

    AMGString AMGString::replaceAll(const string search, const string replace){
        size_t start = 0;
        AMGString temp = str;
        while((start = temp.get().find(search, start)) != string::npos){
            temp = temp.get().replace(start,search.length(),replace);
            start += replace.length();
        }
        return temp;
    }

    AMGString AMGString::strip(const string a){
        AMGString mFinal = str;
        mFinal = AMGString(mFinal).replaceAll("\n","");
        return mFinal;
    }

    bool AMGString::contains(string search){
        AMGString temp = str;
        if(temp.replaceAll(search,"").get() != str){
            return true;
        }
        return false;
    }
}

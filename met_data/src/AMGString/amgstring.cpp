#include "amgstring.h"

/**
	This is the default constructor
*/
AMGString::AMGString(){
	str = "";
}

/**
	This is the common constructor
*/
AMGString::AMGString(string st){
	str = st;
}

/**
	This is the deconstructor
*/
AMGString::~AMGString(){
}

/**
	This method pads a string with the specified padding at the given length
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
    This method pads a string with the specified padding at the given length
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

vector<string> AMGString::split(string delim){
	vector<string> mfinal;
	string buffer = "";
	for(int i = 0; i < str.length(); i++){
		if(buffer == delim || string(1,str[i]) == delim){
			mfinal.push_back(buffer);
			buffer = "";
		}
		else{
        	buffer += string(1,str[i]);
		}
	}
	if(buffer != ""){
		mfinal.push_back(buffer);
	}
	return mfinal;
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

string AMGString::replaceAll(const string search, const string replace){
	size_t start = 0;
	while((start = str.find(search, start)) != string::npos){
		str.replace(start,search.length(),replace);
		start += replace.length();	
	}
	return str;
}

string AMGString::strip(){
	string mFinal = str;
	mFinal = AMGString(mFinal).replaceAll("\n","");
	return mFinal;
}

bool AMGString::contains(string search){
	if(AMGString(str).replaceAll(search,"") != str){
		return true;
	}
	return false;
}


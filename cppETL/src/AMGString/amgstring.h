#ifndef __AMGSTRING_H_INCLUDED__  
#define __AMGSTRING_H_INCLUDED__ 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 	This class helps manipulate custom string objects
*/
class AMGString{
	private:
		string str;
	public:
		AMGString();
		AMGString(string st);
		~AMGString();
		string PadRight(int len, string pad);
		string PadLeft(int len, string pad);
		vector<string>Split(string delim);
		vector<string>SplitByLine();
		string ReplaceAll(string search,string replace);
		string Strip();
		bool Contains(string search);
};

#endif

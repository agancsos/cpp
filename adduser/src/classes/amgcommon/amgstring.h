#ifndef __AMGSTRING_H_INCLUDED__  
#define __AMGSTRING_H_INCLUDED__ 

#include <iostream>
#include <string>
#include <vector>
using namespace std;


namespace amgcommon{
	/**
 	 * This class helps manipulate strings
 	 * @author  (Abel Gancsos)
 	 * @version (v. 1.0.0)
 	 */
	class AMGString {
		private:
			string str;
		public:
			AMGString();
			AMGString(string st);
			~AMGString();
			string padRight(int len, string pad);
			string padLeft(int len, string pad);
			vector<string> split(string delim);
			vector<string> splitByLine();
			string replaceAll(string search,string replace);
			string strip();
			bool contains(string search);
			string toLowerCase();
			string toUpperCase();
	};
}

#endif

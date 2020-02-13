#ifndef __STRING_H_INCLUDED__  
#define __STRING_H_INCLUDED__ 

#include <iostream>
#include <string>
#include <vector>
using namespace std;


namespace amgcommon{
	class AMGString {
		private:
			string str;
		public:
			AMGString();
			AMGString(string st);
			AMGString(const AMGString &a);
			AMGString(const char *a);
			~AMGString();
			AMGString padRight(int len, string pad);
			AMGString padLeft(int len, string pad);
			vector<AMGString> split2(string delim);
			vector<AMGString> splitByLine2();
			vector<string> split(string delim);
			vector<string> splitByLine();
			AMGString replaceAll(string search,string replace);
			AMGString strip(const string a = "\n");
			bool contains(string search);
			AMGString toLowerCase();
			AMGString toUpperCase();
			AMGString & operator=(const AMGString &right) {
				this->str = right.str;
				return *this;
			}
			bool operator==(const AMGString &right) {
				return this->str == right.str;
			}
			bool operator==(const string right) {
				return this->str == right;
			}
			AMGString & operator=(const string right) {
				this->str = right;
				return *this;
			}
			AMGString & operator+(const string right) {
				return *new AMGString(this->str + right);
			}
			AMGString & operator+= (const string right) {
				this->str += right;
				return *this;
			}
			AMGString & operator+= (const AMGString &right) { 
				this->str += right.str;
				return *this;
			}
			AMGString & operator+= (const char right) {
				this->str += string(1, right);
				return *this;
			}
			friend ostream & operator<<(ostream &os, const AMGString &right) {
				os << right.str;
				return os;
			}
			int length() { return this->str.length(); }
			string get() { return this->str; }
	};
}

#endif

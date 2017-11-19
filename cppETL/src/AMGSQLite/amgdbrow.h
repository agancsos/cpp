#ifndef __AMGDBROW_H_INCLUDED__  
#define __AMGDBROW_H_INCLUDED__ 

#include <string>
#include <iostream>
#include <vector>
#include "../AMGString/amgstring.h"
#include "../AMGSystem/amgsystem.h"
using namespace std;

class AMGDBRow{
	public:
		vector<string>columns;
		vector<string>values;
		AMGDBRow();
		~AMGDBRow();
		AMGDBRow(string rawColumns, string rawValues, string delim);
		AMGDBRow(vector<string> c, vector<string> v);
		friend ostream& operator << (ostream &strm, const AMGDBRow &a);
};
#endif

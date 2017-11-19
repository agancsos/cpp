#ifndef __ABSTRACTRECORD_H_INCLUDED__  
#define __ABSTRACTRECORD_H_INCLUDED__ 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AbstractRecord{
	public:
		string name;
		AbstractRecord();
		AbstractRecord(string n);
		~AbstractRecord();
		friend ostream& operator << (ostream &strm, const AbstractRecord &a);
};

#endif

#ifndef __BASEBALLSTATRECORD_H_INCLUDED__  
#define __BASEBALLSTATRECORD_H_INCLUDED__ 

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "abstractrecord.h"
using namespace std;

class BaseballStatRecord : public AbstractRecord{
	public:
		float salary;
		int games;
		float average;
		BaseballStatRecord();
		~BaseballStatRecord();
		BaseballStatRecord(string n, float  s, int g, float a); 
		friend ostream& operator << (ostream &strm, const BaseballStatRecord &a);
};

#endif

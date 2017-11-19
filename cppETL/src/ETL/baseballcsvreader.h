#ifndef __BASEBALLCSVREADER_H_INCLUDED__  
#define __BASEBALLCSVREADER_H_INCLUDED__ 

#include <iostream>
#include <string>
#include <vector>
#include "abstractcsvreader.h"
#include "baseballstatrecord.h"
using namespace std;

class BaseballCSVReader : public AbstractCSVReader{
	public:
		BaseballCSVReader();
		~BaseballCSVReader();
		BaseballCSVReader(string path);
		vector<BaseballStatRecord> Load();
		BaseballStatRecord RowToRecord(string row);
};

#endif

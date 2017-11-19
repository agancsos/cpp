#ifndef __STOCKCSVREADER_H_INCLUDED__  
#define __STOCKCSVREADER_H_INCLUDED__ 

#include <iostream>
#include <string>
#include <vector>
#include "abstractcsvreader.h"
#include "stockstatrecord.h"
using namespace std;

class StockCSVReader : public AbstractCSVReader{
	public:
		StockCSVReader();
		~StockCSVReader();
		StockCSVReader(string path);
		vector<StockStatRecord> Load();
		StockStatRecord RowToRecord(string row);
};

#endif

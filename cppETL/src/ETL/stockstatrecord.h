#ifndef __STOCKSTATRECORD_H_INCLUDED__  
#define __STOCKSTATRECORD_H_INCLUDED__ 

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "abstractrecord.h"
using namespace std;

class StockStatRecord : public AbstractRecord{
	public:
    	string companyName;    
    	string exchangeCountry;
    	float price;
    	float exchangeRate;  
    	float sharesOutstanding;
    	float netIncome;
    	float marketValueUsd;
    	float peRatio;
		StockStatRecord();
		~StockStatRecord();
		StockStatRecord(string symbol,string name,string c,float p,float r,float s, float n); 
		friend ostream& operator << (ostream &strm, const StockStatRecord &a);
};

#endif

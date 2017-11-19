#include "stockstatrecord.h"
using namespace std;

StockStatRecord::StockStatRecord():AbstractRecord(){
	companyName = ""; 
    exchangeCountry = "";
    price = 0.0;
    exchangeRate = 0.0;  
    sharesOutstanding = 0;
    netIncome = 0.0;
    marketValueUsd = 0.0;
    peRatio = 0.0;   
}

StockStatRecord::~StockStatRecord(){
}

StockStatRecord::StockStatRecord(string symbol,string name,string c,float p,float r,float s, float n):AbstractRecord(symbol){
	companyName = name;
    exchangeCountry = c;
    price = p;
    exchangeRate = r;
    sharesOutstanding = s;
    netIncome = n;
    marketValueUsd = 0.0;
    peRatio = 0.0;
}

ostream& operator << (ostream &strm, const StockStatRecord &a) {
	char *buffer = new char[9000];
	string mFinal = "";
	sprintf(buffer, "StockStatRecord(%s,%s,EC=%s,$Price=%0.2f,$E/R=%0.2f,S/E=%0.2f,$Net=%0.2f,$Cap=%0.2f,P/E=%0.2f)",a.name.c_str(),
	a.companyName.c_str(),a.exchangeCountry.c_str(),a.price,a.exchangeRate,a.sharesOutstanding,a.netIncome,a.marketValueUsd,a.peRatio);
	mFinal = buffer;
    return strm << mFinal;
}

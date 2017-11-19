#include "stockcsvreader.h"
using namespace std;

StockCSVReader::StockCSVReader() : AbstractCSVReader(){
}

StockCSVReader::~StockCSVReader(){
}

StockCSVReader::StockCSVReader(string path) : AbstractCSVReader(path){
}

vector<StockStatRecord> StockCSVReader::Load(){
    vector<StockStatRecord> mFinal;
    vector<string> rawRecords;
    try{
		string fileData = AMGSystem(filePath).ReadFile();
		fileData = AMGString(AMGString(fileData).ReplaceAll("\r\r","\n")).ReplaceAll("\n\n","\n");
		rawRecords = AMGString(fileData).SplitByLine();
		for(int i = 0; i < rawRecords.size(); i++){
    		string tempRow = rawRecords[i];
    		// Because we are extracting the records manually, 
    		// the first row (column headers) would need to be bypassed
    		if(AMGString(tempRow).Strip() != "" &&
				!AMGString(tempRow).Contains("exchange_country") &&
				!AMGString(tempRow).Contains("Record_ID#")){
				try{
    				StockStatRecord tempRecord = RowToRecord(tempRow);
    				mFinal.push_back(tempRecord);
				}
				catch(exception &e){
				}
    		}
		}
    }
    catch(exception &e){
    }
    return mFinal;
}

StockStatRecord StockCSVReader::RowToRecord(string row){
    vector<string> comps = AMGString(row).Split(",");
    StockStatRecord mFinal = StockStatRecord();
    if(comps.size() == 7){
		try{
    		mFinal = StockStatRecord(comps[0],comps[2],comps[1],atof(comps[3].c_str()),
			atof(comps[4].c_str()),atof(comps[5].c_str()),atof(comps[6].c_str()));
    		mFinal.marketValueUsd = (mFinal.price* mFinal.exchangeRate*mFinal.sharesOutstanding);
    		if(mFinal.netIncome == 0){
				throw invalid_argument("Divide by zero...");
    		}
    		else{
				mFinal.peRatio = ((mFinal.price*mFinal.sharesOutstanding)/mFinal.netIncome);
    		}
		}
		catch(exception &e){
		}
		return mFinal;
    }
    else{
		throw invalid_argument("This is not a valid StockStatRecord...");
    }
}


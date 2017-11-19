#include "baseballcsvreader.h"
using namespace std;

BaseballCSVReader::BaseballCSVReader() : AbstractCSVReader(){
	filePath = "";
}

BaseballCSVReader::~BaseballCSVReader(){
}

BaseballCSVReader::BaseballCSVReader(string path) : AbstractCSVReader(path){
}

vector<BaseballStatRecord> BaseballCSVReader::Load(){
    vector<BaseballStatRecord> mFinal;
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
    				BaseballStatRecord tempRecord = RowToRecord(tempRow);
    				mFinal.push_back(tempRecord);
				}
				catch(exception &e){
					continue;
				}
    		}
		}
    }
    catch(exception &e){
    }
    return mFinal;
}

BaseballStatRecord BaseballCSVReader::RowToRecord(string row){
    vector<string> comps;
    BaseballStatRecord mFinal = BaseballStatRecord();
	comps = AMGString(row).Split(",");
    if(comps.size() == 134){
		try{
    		mFinal = BaseballStatRecord(comps[0],atof(comps[2].c_str()),atof(comps[5].c_str()),atof(comps[68].c_str()));
		}
		catch(exception &e){
		}
    }
    else{
		throw invalid_argument("This is not a valid BaseballStatRecord...");
    }
    return mFinal;
}


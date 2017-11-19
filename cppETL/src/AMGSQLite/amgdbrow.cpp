#include "amgdbrow.h"
using namespace std;

AMGDBRow::AMGDBRow(){
}

AMGDBRow::~AMGDBRow(){
}

AMGDBRow::AMGDBRow(string rawColumns, string rawValues, string delim){
}

AMGDBRow::AMGDBRow(vector<string> c, vector<string> v){
}

ostream& operator << (ostream &strm, const AMGDBRow &a) {
	string mFinal = "";
	for(int i = 0; i < a.values.size(); i++){
		if(i > 0){
			mFinal += "<COL>";
		}
		mFinal += a.values[i];
	}
    return strm << mFinal;
}

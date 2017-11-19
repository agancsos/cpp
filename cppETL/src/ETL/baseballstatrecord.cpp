#include "baseballstatrecord.h"
using namespace std;

BaseballStatRecord::BaseballStatRecord():AbstractRecord(){
}

BaseballStatRecord::~BaseballStatRecord(){
}

BaseballStatRecord::BaseballStatRecord(string n, float  s, int g, float a):AbstractRecord(n){
	salary = s;
	games = g;
	average = a;
}

ostream& operator << (ostream &strm, const BaseballStatRecord &a) {
	//char *buffer = new char[a.name.length() + to_string(a.salary).length() + to_string(a.games).length() + to_string(a.average).length()];
	char *buffer = new char[3000];
	string mFinal = "";
	sprintf(buffer, "BaseballStatRecord(%s,%0.2f,%d,%0.3f)",a.name.c_str(),a.salary,a.games,a.average);
	mFinal = buffer;
    return strm << mFinal;
}

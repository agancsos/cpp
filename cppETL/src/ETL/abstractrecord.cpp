#include "abstractrecord.h"
using namespace std;

AbstractRecord::AbstractRecord(){
}

AbstractRecord::AbstractRecord(string n){
	name = n;
}

AbstractRecord::~AbstractRecord(){
}

ostream& operator << (ostream &strm, const AbstractRecord &a) {
    return strm << "";
}

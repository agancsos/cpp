#include "abstractcsvreader.h"
using namespace std;

AbstractCSVReader::AbstractCSVReader(){
	filePath = "";
}

AbstractCSVReader::~AbstractCSVReader(){
}

AbstractCSVReader::AbstractCSVReader(string path){
	filePath = path;
}

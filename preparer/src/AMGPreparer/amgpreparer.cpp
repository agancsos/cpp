#include "amgpreparer.h"
using namespace std;

AMGPreparer::AMGPreparer(){
	maxSeasons = "1";
	startingSeason = "1";
	diskCount = "3";
	silent = false;
}

AMGPreparer::~AMGPreparer(){
}

AMGPreparer::AMGPreparer(string max){
    maxSeasons = max;
    startingSeason = "1";
    diskCount = "3";
	silent = false;
}

AMGPreparer::AMGPreparer(string max,string ss){
    maxSeasons = max;
    startingSeason = ss;
    diskCount = "3";
	silent = false;
}

AMGPreparer::AMGPreparer(string max,string ss,string disks){
    maxSeasons = max;
    startingSeason = ss;
    diskCount = disks;
	silent = false;
}

void AMGPreparer::dumpConfig(){
	cout << "* Max Season  : " << maxSeasons << endl;
	cout << "* Start Season: " << startingSeason << endl;
	cout << "* Disk Count  : " << diskCount << endl;
}

void AMGPreparer::prepare(){
	if(!silent){
		cout << "Preparing directory..." << endl;
		dumpConfig();
	}
	for(int i = stoi(startingSeason); i <= stoi(maxSeasons); i++){
		if(!AMGSystem().folderExists("./SEASON_" + to_string(i))){
        	if(!silent){
            	cout << "Creating season " << i << endl;
        	}
			if(AMGSystem("","./SEASON_" + to_string(i)).createFolder()){
			}		
		}
        if(!silent){
        	cout << "Preparing disks for season " << i << endl;
       	}
		for(int j = 0; j < stoi(diskCount); j++){
			if(!AMGSystem().folderExists("./SEASON_" + to_string(i) + "/DISK_" + to_string(j + 1))){	
				if(!silent){
					cout << "Creating disk " << j + 1 << " for season " << i << endl;
				}
				if(AMGSystem("","./SEASON_" + to_string(i) + "/DISK_" + to_string(j + 1)).createFolder()){
            	}
			}
		}
	}
}

void AMGPreparer::setMax(string a){
	maxSeasons = a;
}

void AMGPreparer::setSeason(string a){
	startingSeason = a;
}

void AMGPreparer::setDisks(string a){
	diskCount = a;
}

string AMGPreparer::getMax(){
	return maxSeasons;
}

string AMGPreparer::getSeason(){
	return startingSeason;
}

string AMGPreparer::getDisks(){
	return diskCount;
}

void AMGPreparer::setSilent(bool a){
	silent = a;
}

bool AMGPreparer::getSilent(){
	return silent;
}


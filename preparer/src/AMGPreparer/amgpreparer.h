#ifndef __AMGPREPARER_H_INCLUDED__  
#define __AMGPREPARER_H_INCLUDED__ 

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../AMGSystem/amgsystem.h"
using namespace std;

/**
	This class helps prepare the needed directories for DVD files
*/
class AMGPreparer{
	private:
        string maxSeasons;
        string startingSeason;
		string diskCount;
		bool silent;
		void dumpConfig();
	public:
		AMGPreparer();
		~AMGPreparer();
		AMGPreparer(string max);
		AMGPreparer(string max,string ss);
		AMGPreparer(string max,string ss,string disks);
		void prepare();
		void  setMax(string a);
		void setSeason(string a);
		void setDisks(string a);
		void setSilent(bool a);
		bool getSilent();
		string getMax();
		string getSeason();
		string getDisks();
};

#endif

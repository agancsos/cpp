#ifndef __AMGETL_H_INCLUDED__  
#define __AMGETL_H_INCLUDED__ 
#include <iostream>
#include <string>
#include <vector>
#include "../AMGString/amgstring.h"
#include "../AMGSystem/amgsystem.h"
#include "../AMGData/amgdata.h"
#include "../ETL/baseballcsvreader.h"
#include "../ETL/stockcsvreader.h"

using namespace std;

class AMGETL{
	public:
		string applicationFilePath;
		string basePath;
		string dataType;
		bool silent;
		AMGETL();
		~AMGETL();
		void Run();
};
#endif

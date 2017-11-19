#ifndef __ABSTRACTCSVREADER_H_INCLUDED__  
#define __ABSTRACTCSVREADER_H_INCLUDED__ 

#include <iostream>
#include <string>
#include <vector>
#include "../AMGString/amgstring.h"
#include "../AMGSystem/amgsystem.h"
#include "abstractrecord.h"
using namespace std;

class AbstractCSVReader{
	public:
		string filePath;
		AbstractCSVReader();
		~AbstractCSVReader();
		AbstractCSVReader(string path);
};

#endif

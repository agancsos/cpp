#ifndef __AMGEXTRACTOR_H_INCLUDED__
#define __AMGEXTRACTOR_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include "../METStudent/metstudent.h"
#include "../AMGString/amgstring.h"
#include "../AMGSystem/amgsystem.h"
using namespace std;

/**
    This class helps manipulate custom string objects
*/
class AMGExtractor{
    private:
        string file_path;
		string delim;
		METStudent student;
		vector<string> comps;
		void extractAll();
		void extractComps();
		void extractProgram();
		void extractCompleted();
		void extractCurrent();
		void extractSpecialties();
    public:
        AMGExtractor();
        AMGExtractor(string st);
		AMGExtractor(string st, string d);
        ~AMGExtractor();
		void display();
		void setFilePath(string a);
		void setDelim(string a);
		string getFilePath();
		string getDelim();
};

#endif


#ifndef __METSTUDENT_H_INCLUDED__
#define __METSTUDENT_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include "../METPerson/metperson.h"
#include "../AMGString/amgstring.h"
#include "../AMGSystem/amgsystem.h"
using namespace std;

/**
    This is a child class of METPerson and is specific to students.
*/
class METStudent : public METPerson{
    private:
        vector<string> completed;
        string program;
		vector<string> specialties;
        vector<string> current;
        int    year;
    public:
        METStudent();
        ~METStudent();
        METStudent(string f, string l, string m, int a, GENDER g, string s, string p, int y);
        void addCompleted(string a);
        void addSpecialties(string a);
        void addCurrent(string a);
        void setProgram(string a);
        void setYear(int a);
		vector<string> getCompleted();
		vector<string> getCurrent();
		vector<string> getSpecialties();
		string getProgram();
		int getYear();
};

#endif


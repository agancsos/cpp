#ifndef __METPERSON_H_INCLUDED__
#define __METPERSON_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum GENDER{
    MALE   = 1,
    FEMALE = 2,
    OTHER  = 3
};

/**
    This is a base class for any person involved with the MET program
*/
class METPerson{
    private:
        string firstName;
        string lastName;
        string middleName;
        int    age;
        GENDER sex;
        string socialSecurityNumber;
    public:
        METPerson();
        ~METPerson();
        METPerson(string f, string l, string m, int a, GENDER g, string s);
        void setFirstName(string a);
        void setLastName(string a);
        void setMiddleName(string a);
        void setAge(int a);
        void setSex(GENDER a);
        void setSocial(string a);
        string getFirstName();
        string getLastName();
        string getMiddleName();
        int getAge();
        GENDER getSex();
        string getSocial();
};

#endif

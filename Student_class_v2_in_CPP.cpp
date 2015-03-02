#include <iostream>
using namespace std;

class Student{
        public:
                Student();
                ~Student();
                void setStudent(string a, string b, string c, int d, float e);
                void printStudent();

        protected:
                string first;
                string last;
                string major;
                int age;
                float gpa;
};

Student::Student()
{
        first=\"\";
        last=\"\";
        major=\"Undeclared\";
        age=0;
        gpa=2.5;
}

Student::~Student()
{


}

void Student::setStudent(string a,string b, string c,int d, float e)
{

        first=a;
        last=b;
        major=c;
        age=d;
        gpa=e;
}

void Student::printStudent()
{

        cout<<\"First: \"<<first<<\" Last: \"<<last<<\" Major: \"<<major<<\" Age: \"<<age<<\" GPA: \"<<gpa<<endl;
}


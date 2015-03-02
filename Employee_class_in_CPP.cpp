#include <iostream>
using namespace std;

class Employee{
	public:
		Employee();
		~Employee();
		void setStudent(string ssn2,string a, string b, string c, float d, float e);
		void printStudent();

	protected:
                string ssn;
		string first;
		string last;
		string title;
		float hpw;
		float rate;
};

Student::Student()
{
	first=\"\";
	last=\"\";
	title=\"Employee\";
	hpw=0;
        rate=7.25;
        ssn=\"0\";
}

Student::~Student()
{


}

void Student::setStudent(string ssn2,string a,string b, string c,float d, float e)
{

	first=a;
	last=b;
	title=c;
	hpw=d;
	rate=e;
        ssn=ssn2
}

void Student::printStudent()
{

	cout<<\"SSN: \"<<ssn<<\" First: \"<<first<<\" Last: \"<<last<<\" Title: \"<<title<<\" HPW: \"<<hpw<<\" Rate: \"<<rate<<endl;
}


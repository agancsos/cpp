#include "metperson.h"
using namespace std;

METPerson::METPerson(){
	first_name = "";
    last_name = "";
    middle_name = "";
    age = 21;
    sex = OTHER;
    social_security_number = "000-00-0000";
}

METPerson::~METPerson(){
}

METPerson::METPerson(string f, string l, string m, int a, GENDER g, string s){
	first_name = f;
	last_name = l;
	middle_name = m;
	age = a;
	sex = g;
	social_security_number = s;
}

void METPerson::setFirstName(string a){
	first_name = a;
}

void METPerson::setLastName(string a){
	last_name = a;
}

void METPerson::setMiddleName(string a){
	middle_name = a;
}

void METPerson::setAge(int a){
	age = a;
}

void METPerson::setSex(GENDER a){
	sex = a;
}

void METPerson::setSocial(string a){
	social_security_number = a;
}

string METPerson::getFirstName(){
	return first_name;
}

string METPerson::getLastName(){
	return last_name;
}

string METPerson::getMiddleName(){
	return middle_name;
}

int METPerson::getAge(){
	return age;
}

GENDER METPerson::getSex(){
	return sex;
}

string METPerson::getSocial(){
	return social_security_number;
}


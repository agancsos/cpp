#include "metperson.h"
using namespace std;

METPerson::METPerson(){
	firstName = "";
    lastName = "";
    middleName = "";
    age = 21;
    sex = OTHER;
    socialSecurityNumber = "000-00-0000";
}

METPerson::~METPerson(){
}

METPerson::METPerson(string f, string l, string m, int a, GENDER g, string s){
	firstName = f;
	lastName = l;
	middleName = m;
	age = a;
	sex = g;
	socialSecurityNumber = s;
}

void METPerson::setFirstName(string a){
	firstName = a;
}

void METPerson::setLastName(string a){
	lastName = a;
}

void METPerson::setMiddleName(string a){
	middleName = a;
}

void METPerson::setAge(int a){
	age = a;
}

void METPerson::setSex(GENDER a){
	sex = a;
}

void METPerson::setSocial(string a){
	socialSecurityNumber = a;
}

string METPerson::getFirstName(){
	return firstName;
}

string METPerson::getLastName(){
	return lastName;
}

string METPerson::getMiddleName(){
	return middleName;
}

int METPerson::getAge(){
	return age;
}

GENDER METPerson::getSex(){
	return sex;
}

string METPerson::getSocial(){
	return socialSecurityNumber;
}


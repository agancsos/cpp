#include "metstudent.h"
using namespace std;

METStudent::METStudent(){
}

METStudent::~METStudent(){
}

METStudent::METStudent(string f, string l, string m, int a, GENDER g, string s, string p, int y) : METPerson(f,l,m,a,g,s){
	program = p;
	year = y;
}

void METStudent::addCompleted(string a){
	completed.push_back(a);
}

void METStudent::addSpecialties(string a){
	specialties.push_back(a);
}

void METStudent::addCurrent(string a){
	current.push_back(a);
}

void METStudent::setProgram(string a){
	program = a;
}

void METStudent::setYear(int a){
	year = a;
}

vector<string> METStudent::getCompleted(){
	return completed;
}

vector<string> METStudent::getCurrent(){
	return current;
}

vector<string> METStudent::getSpecialties(){
	return specialties;
}

string METStudent::getProgram(){
	return program;
}

int METStudent::getYear(){
	return year;
}


#include "amgextractor.h"
using namespace std;

AMGExtractor::AMGExtractor(){
	file_path = "../resources/dat/student.dat";
	delim = ";";
}

AMGExtractor::AMGExtractor(string st){
	file_path = st;
	delim = ";";
}

AMGExtractor::AMGExtractor(string st, string d){	
	file_path = st;
	delim = d;
}

AMGExtractor::~AMGExtractor(){
}

void AMGExtractor::extractComps(){
	student = METStudent("","","",33,MALE,"123-45-6789","",0);
	try{
		comps = AMGString(AMGString(AMGSystem(file_path).readFile()).strip()).split(delim);
	}
	catch(exception &e){
	}
}

void AMGExtractor::extractAll(){
	extractComps();
	extractProgram();
	extractCompleted();
	extractCurrent();
	extractSpecialties();
}

void AMGExtractor::extractProgram(){
	if(comps.size() > 0){
		student.setProgram(comps[0]);
	}
}

void AMGExtractor::extractCompleted(){
    if(comps.size() > 1){
		vector<string> temp = AMGString(comps[1]).split(",");
        for(int i = 0; i < temp.size(); i++){
			student.addCompleted(temp[i]);
		}
    }	
}

void AMGExtractor::extractCurrent(){
    if(comps.size() > 2){
        vector<string> temp = AMGString(comps[2]).split(",");
        for(int i = 0; i < temp.size(); i++){
            student.addCurrent(temp[i]);
        }
    }
}

void AMGExtractor::extractSpecialties(){
    if(comps.size() > 3){
        vector<string> temp = AMGString(comps[3]).split(",");
        for(int i = 0; i < temp.size(); i++){
            student.addSpecialties(temp[i]);
        }
    }
}

void AMGExtractor::display(){
	extractAll();
	cout << AMGString("").padRight(80,"-") << endl;
	cout << "# Name       : " << student.getFirstName() << " " << student.getLastName() << endl;
	cout << "# Age        : " << student.getAge() << endl; 
	cout << "# Sex        : ";
	switch(student.getSex()){
		case MALE:
			cout << "MALE";
			break;
		case FEMALE:
			cout << "FEMALE";
			break;
		case OTHER:
			cout << "OTHER";
			break;
	}
	cout << endl;
	cout << "# Program    : " << student.getProgram() << endl;
	cout << "# Completed  : " << endl;
	for(auto const &cursor : student.getCompleted()){
		cout << "\t\t# " << cursor << endl;
	}
	cout << "# Current    : " << endl;
    for(auto const &cursor : student.getCurrent()){
        cout << "\t\t# " << cursor << endl;
    }
	cout << "# Specialties: " << endl;
    for(auto const &cursor : student.getSpecialties()){
        cout << "\t\t# " << cursor << endl;
    }
    cout << AMGString("").padRight(80,"-") << endl;
}

void AMGExtractor::setFilePath(string a){
	file_path = a;
}

void AMGExtractor::setDelim(string a){
	delim = a;
}

string AMGExtractor::getFilePath(){
	return file_path;
}

string AMGExtractor::getDelim(){
	return delim;
}

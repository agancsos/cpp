#ifndef __AMGGENERATOR_H_INCLUDED__
#define __AMGGENERATOR_H_INCLUDED__

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "../amgcommon/amgcommon_all.h"
#include "sr.h"
using namespace std;
using namespace amgcommon;

namespace amggenerator { 

	enum class PROJECT_LANGUAGE {
		NONE,
		CPP,
		JAVA
	};

	static string projectLangaugeName(PROJECT_LANGUAGE a) {
		switch(a) {
			case(PROJECT_LANGUAGE::NONE):
				return "None";
			case(PROJECT_LANGUAGE::CPP):
				return "C++";
			case(PROJECT_LANGUAGE::JAVA):
				return "Java";
		}
		return "";
	}

	static PROJECT_LANGUAGE projectLanguageFromIndex(int a) {
		switch(a) {
			case(0):
				return PROJECT_LANGUAGE::NONE;
			case(1):
				return PROJECT_LANGUAGE::CPP;
			case(2):
				return PROJECT_LANGUAGE::JAVA;
		}
		return PROJECT_LANGUAGE::NONE;
	}

	static PROJECT_LANGUAGE projectLanguageFromName(string a) {
		if(AMGString(a).toLowerCase() == "cpp") 
			return PROJECT_LANGUAGE::CPP;
		else if(AMGString(a).toLowerCase() == "java")
			return PROJECT_LANGUAGE::JAVA;
		else
			return PROJECT_LANGUAGE::NONE;
	}

	class AMGGenerator {
		protected:
			virtual void createProjectFolder();
			virtual void createFolders();
			virtual void addReadme();
			virtual void addMISC();
			virtual void addMainSource();
			virtual void addCompileScripts();
			string projectName;
			string projectBase;
		public:
			AMGGenerator();
			AMGGenerator(string name);
			AMGGenerator(string name, string base);
			virtual ~AMGGenerator();
			void setName(string a);
			void setBase(string a);
			string getName();
			string getBase();
			void generate();
	};
}
#endif

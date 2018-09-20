#include "amggenerator.h"

namespace amggenerator {
	void AMGGenerator::createProjectFolder() {
		if(!AMGSystem::directoryExists(this->projectBase + "/"  + this->projectName)) {
			AMGSystem("", this->projectBase + "/" + this->projectName).makeDirectory();
		}
		else {
			printf("Error! Project already exists...\n");
		}
	}

	void AMGGenerator::createFolders() {
		vector<string> folders;
		folders.push_back("bin");
		folders.push_back("src");
		folders.push_back("lib");
		folders.push_back("doc");
		folders.push_back("resources");
		
		for(string folder : folders) {
        	if(!AMGSystem::directoryExists("./" + this->projectName + "/" + folder)) {
            	AMGSystem("", this->projectBase + "/" + this->projectName + "/" + folder).makeDirectory();
        	}
		}
	}

	void AMGGenerator::addReadme() {
	}

	void AMGGenerator::addMISC() {
	}

	void AMGGenerator::addMainSource() {
	}

    void AMGGenerator::addCompileScripts() {
    }

	AMGGenerator::AMGGenerator() {
		this->projectName = "";
		this->projectBase = "./";
	}

	AMGGenerator::AMGGenerator(string name) : AMGGenerator() {
		this->projectName = name;
	}

	AMGGenerator::AMGGenerator(string name, string base) : AMGGenerator(name) {
		this->projectBase = base;
	}

	AMGGenerator::~AMGGenerator() {
	}

	void AMGGenerator::setName(string a) {
		this->projectName = a;
	}

	void AMGGenerator::setBase(string a) {
		this->projectBase = a;
	}

	string AMGGenerator::getName() {
		return this->projectName;
	}

	string AMGGenerator::getBase() {
		return this->projectBase;
	}

	void AMGGenerator::generate() {
		this->createProjectFolder();
		this->createFolders();
		this->addReadme();
		this->addMainSource();
		this->addCompileScripts();
		this->addMISC();
	}
}

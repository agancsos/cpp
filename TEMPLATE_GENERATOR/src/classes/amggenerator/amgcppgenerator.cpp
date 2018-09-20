#include "amgcppgenerator.h"

namespace amggenerator {

	void AMGCPPGenerator::addReadme() {
		AMGSystem("", this->projectBase + "/" + this->projectName + "/README.md").writeFile(SR::cppReadMe());
	}

	void AMGCPPGenerator::addCmakeLists() {
		AMGSystem("", this->projectBase + "/"  + this->projectName + "/CMakeLists.txt").writeFile(SR::cmake(this->projectName));
	}

	void AMGCPPGenerator::addMainSource() {
		AMGSystem("", this->projectBase + "/"  + this->projectName + "/src/main.cpp").writeFile(SR::cppMain(this->projectName));
	}

	void AMGCPPGenerator::addMISC() {
		this->addCmakeLists();
	}

    void AMGCPPGenerator::addCompileScripts() {
		AMGSystem("", this->projectBase + "/"  + this->projectName + "/src/compile.bat").writeFile(SR::cppCompileBat(this->projectName));
		AMGSystem("", this->projectBase + "/"  + this->projectName + "/src/compile.sh").writeFile(SR::cppCompileBash(this->projectName));
    }

	AMGCPPGenerator::AMGCPPGenerator() : AMGGenerator() {
		this->projectName = "";
		this->projectBase = "./";
	}

	AMGCPPGenerator::AMGCPPGenerator(string name) : AMGCPPGenerator() {
		this->projectName = name;
	}

	AMGCPPGenerator::AMGCPPGenerator(string name, string base) : AMGCPPGenerator(name) {
		this->projectBase = base;
	}

	AMGCPPGenerator::~AMGCPPGenerator() {
	}
}

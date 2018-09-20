#include "amgjavagenerator.h"

namespace amggenerator {

	void AMGJAVAGenerator::addReadme() {
		AMGSystem("", this->projectBase + "/" + this->projectName + "/README.md").writeFile(SR::stdReadMe());
	}

	void AMGJAVAGenerator::addMainSource() {
	}

	void AMGJAVAGenerator::addMISC() {
	}

    void AMGJAVAGenerator::addCompileScripts() {
		AMGSystem("", this->projectBase + "/"  + this->projectName + "/src/compile.bat").writeFile(SR::javaCompileBat(this->projectName));
		AMGSystem("", this->projectBase + "/"  + this->projectName + "/src/compile.sh").writeFile(SR::javaCompileBash(this->projectName));
    }

	AMGJAVAGenerator::AMGJAVAGenerator() : AMGGenerator() {
		this->projectName = "";
		this->projectBase = "./";
	}

	AMGJAVAGenerator::AMGJAVAGenerator(string name) : AMGJAVAGenerator() {
		this->projectName = name;
	}

	AMGJAVAGenerator::AMGJAVAGenerator(string name, string base) : AMGJAVAGenerator(name) {
		this->projectBase = base;
	}

	AMGJAVAGenerator::~AMGJAVAGenerator() {
	}
}

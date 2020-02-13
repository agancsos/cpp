#include "version.h"

namespace amgcommon {
    Version::Version() {
		this->majorVersion = 0;
		this->minorVersion = 0;
		this->buildVersion = 0;
		this->buildDescription = "";
	}

    Version::Version(int major) : Version(){
		this->majorVersion = major;
	}

    Version::Version(int major, int minor) : Version(major){
		this->minorVersion = minor;
	}

    Version::Version(int major, int minor, int build) : Version(major, minor) {
		this->buildVersion = build;
	}

	Version::Version(int major, int minor, int build, string description) : Version(major, minor, build) {
		this->buildDescription = description;
	}

    Version::~Version() {
	}

	string Version::toString() {
		return (to_string(this->majorVersion) + "." + to_string(this->minorVersion) + "." + to_string(this->buildVersion));
	}

  	int Version::getMajorVersion() { return this->majorVersion; }
  	int Version::getMinorVersion() { return this->minorVersion; }
	int Version::getBuildVersion() { return this->buildVersion; }
	string Version::getBuildDescription() { return this->buildDescription; }
}

#ifndef __VERSION_H_INCLUDED__
#define __VERSION_H_INCLUDED__

#include <iostream>
#include <string>
#include <memory>
using namespace std;

namespace amgcommon {
	class Version {
		private:
			int majorVersion;
			int minorVersion;
			int buildVersion;
			string buildDescription; 
		public:
			Version();
			Version(int major);
			Version(int major, int minor);
			Version(int major, int minor, int build);
			Version(int major, int minor, int build, string description);
			~Version();
			int getMajorVersion();
			int getMinorVersion();
			int getBuildVersion();
			string getBuildDescription();
			string toString();
	};
}

#endif

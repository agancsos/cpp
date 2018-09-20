#ifndef __AMGCPPGENERATOR_H_INCLUDED__
#define __AMGCPPGENERATOR_H_INCLUDED__

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "../amgcommon/amgcommon_all.h"
#include "sr.h"
#include "amggenerator.h"
using namespace std;
using namespace amgcommon;

namespace amggenerator { 

	class AMGCPPGenerator : public AMGGenerator {
		private:
			void addReadme();
			void addCmakeLists();
			void addMainSource();
			void addCompileScripts();
			void addMISC();
		public:
			AMGCPPGenerator();
			AMGCPPGenerator(string name);
			AMGCPPGenerator(string name, string base);
			~AMGCPPGenerator();
	};
}
#endif

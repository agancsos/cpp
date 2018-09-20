#ifndef __AMGJAVAGENERATOR_H_INCLUDED__
#define __AMGJAVAGENERATOR_H_INCLUDED__

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

	class AMGJAVAGenerator : public AMGGenerator {
		private:
			void addReadme();
			void addMainSource();
			void addCompileScripts();
			void addMISC();
		public:
			AMGJAVAGenerator();
			AMGJAVAGenerator(string name);
			AMGJAVAGenerator(string name, string base);
			~AMGJAVAGenerator();
	};
}
#endif

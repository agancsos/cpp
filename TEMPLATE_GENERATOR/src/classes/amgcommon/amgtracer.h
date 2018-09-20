#ifndef __AMGTRACER_H_INCLUDED__  
#define __AMGTRACER_H_INCLUDED__ 

#include <string>
#include <vector>
#include <ctime>
#include <memory.h>
#include "amgsystem.h"
#include "amgstring.h"
#include "amgconfiguration.h"
using namespace std;

namespace amgcommon{

	enum class TRACE_CATEGORY {
		NONE = 0,
    	MISC = 1,
    	SYSTEM = 2,
    	DATABASE = 3,
    	SECURITY = 4,
    	APPLICATION = 5
	};

	/**
 	 * This class is meant to help log information to both an output file and the console
 	 */
	class AMGTracer {
		private:
			string outputFile;
    		int miscLevel;
    		int systemLevel;
    		int databaseLevel;
    		int securityLevel;
    		int applicationLevel;
    		int defaultLevel;
			shared_ptr<AMGConfiguration> configuration;
			void configure();
			bool shouldAudit(TRACE_CATEGORY category, int level);
		public:
			static string getName(TRACE_CATEGORY a);
			AMGTracer();
			AMGTracer(string a);
			AMGTracer(string a, shared_ptr<AMGConfiguration> b);
			~AMGTracer();
			void setOutputFile(string a);
			void trace(int level, TRACE_CATEGORY category, string a, bool print);
            void trace(string a, bool print);
	};
}

#endif

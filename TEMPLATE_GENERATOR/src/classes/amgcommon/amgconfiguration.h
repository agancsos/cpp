#ifndef __AMGCONFIGURATION_H_INCLUDED__  
#define __AMGCONFIGURATION_H_INCLUDED__ 

#include <string>
#include <vector>
#include "amgsystem.h"
#include "amgstring.h"
using namespace std;

namespace amgcommon{
	/**
 	 * This class offers custom system operations
 	 * @author  (Abel Gancsos)
 	 * @version (v. 1.0.0)
 	 */
	class AMGConfiguration{
    	private:
        	string inputFile;
    	public:
        	AMGConfiguration();
        	~AMGConfiguration();
        	AMGConfiguration(string a);
			string lookupKey(string a);
        	void setInputFile(string a);
        	string getInputFile();
	};
}

#endif


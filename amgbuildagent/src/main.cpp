#include <iostream>
#include <memory>
#include <string>
#include "classes/amgcommon/amgcommon_all.h"
#include "classes/amgbuildagent/amgbuildagentmain.h"
#include "classes/sr.h"
#include <time.h>
#include <stdlib.h>
using namespace std;
using namespace sr;
using namespace amgcommon;
using namespace amgbuildagent;

/**
 * This method is the main entry point from the command-line
 * @precondition  (Utility exists on a Windows/non-Windows environment)
 * @postcondition (Utility is started)
 */
int main(int argc, char **argv) {

	bool help = false;
	const shared_ptr<AMGBuildAgent> agent = AMGBuildAgent::getInstance();
    srand(time(NULL));
	SystemService::setModulePath(string(argv[0]));
	if((argc - 1) > 0) {
		for(int i = 0; i < argc; i++) {
			if(string(argv[i]) == "-h" || string(argv[i]) == "--help") {
				help = true;
			}
		}
	}
	if(help) {
		SR::helpMenu();
	}
	else {
		agent->startAgent();
	}
	return 0;
}

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <memory>
#include "classes/amgcommon/amgcommon_all.h"
#include "classes/amggenerator/amggenerator_all.h"
using namespace std;
using namespace amgcommon;
using namespace amggenerator;

#define __PRODUCT_AUTHOR_STRING__  "Abel Gancsos"
#define __PRODUCT_NAME_STRING__    "TEMPLATE GENERATOR"
#define __PRODUCT_VERSION_STRING__ "1.0.0"

/**
 * This method is displayed as a help menu for non-interactive options
 * @precondition  (Utility has been with the help switch)
 * @postcondition (Details of the utility are displayed in the system console)
 */
void helpMenu() {
    printf("%s \n", AMGString("").padLeft(80,"=").c_str());
    printf("* Name   : %s", __PRODUCT_NAME_STRING__);
    printf("* Author : %s", __PRODUCT_AUTHOR_STRING__);
    printf("* Version: v. %s \n", __PRODUCT_VERSION_STRING__);
    printf("* Flags: \n");
    printf("\t* -name    : Name of the project \n");
	printf("\t* -lang    : Switch to build a Java template (default: CPP) \n");
	printf("\t* -base    : Full path of the base folder where to create the project \n");
	printf("\t* -version : Display version information \n");
    printf("%s \n", AMGString("").padLeft(80,"=").c_str());
}

/**
 * This method is the main entry point from the command-line
 * @precondition  (Utility exists on a Windows/non-Windows environment with Java 1.8 or newer)
 * @postcondition (Utility is started)
 */
int main(int argc, char **argv) {
    bool help = false;
    bool getVersion = false;
	shared_ptr<AMGGenerator> session(new AMGCPPGenerator());
	PROJECT_LANGUAGE tempLang = PROJECT_LANGUAGE::CPP;

    if((argc - 1) > 0) {
        for(int i = 0; i < argc; i++) {
            if(string(argv[i]) == "-h") {
                help = true;
            }
			if(string(argv[i]) == "-lang") {
                tempLang = projectLanguageFromName(string(argv[i + 1]));
				if(tempLang != PROJECT_LANGUAGE::CPP) {
					switch(tempLang) {
						case(PROJECT_LANGUAGE::JAVA):
							session = shared_ptr<AMGGenerator>(new AMGJAVAGenerator(session->getName(), session->getBase()));
							break;
						default:
							break;
					}
				}
            }
            else if(string(argv[i]) == "-version") {
                getVersion = true;
            }
			else if(string(argv[i]) == "-name") {
                session->setName(string(argv[i + 1]));
            }
			else if(string(argv[i]) == "-base") {
				session->setBase(string(argv[i + 1]));
			}
        }
    }

    if(help) {
        helpMenu();
    }
    else if(getVersion) {
        printf("TEMPLATE GENERATOR Version: v.%s \n", __PRODUCT_VERSION_STRING__);
    }
    else {
		session->generate();
    }

	return 0;
}

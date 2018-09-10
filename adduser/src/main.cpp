#include <iostream>
#include <ctime>
#include <cstdlib>
#include <memory>
#include <vector>
#include <string>
#include "classes/amgcommon/amgcommon_all.h"
#include "classes/amgadduser/amgadduser_all.h"
using namespace std;
using namespace amgcommon;
using namespace amgadduser;

void helpMenu() {
	cout << AMGString("").padRight(80, "=") << endl;
	cout << "* Name      : AddUser" << endl;
	cout << "* Author    : Abel Gancsos" << endl;
	cout << "* Version   : v. " << PRODUCT_VERSION_STRING << endl;
	cout << "* Flags     :" << endl;
	cout << "\t* -username  : Username for the new account" << endl;
	cout << "\t* -password  : Password for the new account" << endl;
	cout << "\t* -first     : First name of the new account" << endl;
	cout << "\t* -last      : Last name of the new account" << endl;
	cout << "\t* -admin     : Switch to identify the account as an administrator" << endl;
    cout << AMGString("").padRight(80, "=") << endl;	
}

int main(int argc, char **argv) {

	srand(time(0));
	bool help = false;
	shared_ptr<AMGAddUser> session(new AMGAddUser());

	if((argc - 1) > 0) {
		for(int i = 0; i < argc; i++) {
			if(string(argv[i]) == "-h") {
				help = true;
			}
			else if(string(argv[i]) == "-username") {
				session->setUsername(string(argv[i + 1]));
            }
            else if(string(argv[i]) == "-password") {
                session->setPassword(string(argv[i + 1]));
            }
            else if(string(argv[i]) == "-admin") {
                session->setIsAdmin(true);
            }
            else if(string(argv[i]) == "-first") {
                session->setFirstName(string(argv[i + 1]));
            }
            else if(string(argv[i]) == "-last") {
                session->setLastName(string(argv[i + 1]));
            }
		}
	}

	if(help) {
		helpMenu();
	}
	else {
		session->createUser();
	}

	return 0;
}

#include "amgadduser.h"

namespace amgadduser {

	int AMGAddUser::getUUID() {
		return (rand() % 9999 + 1000);
	}

	void AMGAddUser::createHomeDirectory() {
		cout << "Creating user's home directory" << endl;
		try {
			AMGSystem::runCommand("dscl . -create /Users/" + this->username);
			AMGSystem::runCommand("dscl . -create /Users/" + this->username + " UserShell /bin/bash");
			AMGSystem::runCommand("dscl . -create /Users/" + this->username + " NFSHomeDirectory /Local/Users/" + this->username);
			AMGSystem::runCommand("dscl . -create /Users/" + this->username + " UniqueID " + to_string(this->getUUID()));
			cout << "Successfully created home directory..." << endl;
		}
		catch(exception &e) {
            cout << "Error creating home directory..." << endl;
            cout << e.what() << endl;
		}
	}

	void AMGAddUser::setPermissions() { 
        cout << "Setting user's permisions" << endl;
        try {
			AMGSystem::runCommand("dscl . -create /Users/" + this->username + " PrimaryGroupID 1000");
			if(this->isAdmin) {
				AMGSystem::runCommand("dscl . -append /Groups/admin GroupMembership " + this->username);
			}
            cout << "Successfully set permissions..." << endl;
        }
        catch(exception &e) {
            cout << "Error setting permissions..." << endl;
            cout << e.what() << endl;
        }
	}

	void AMGAddUser::setPassword() {
        cout << "Setting user's password" << endl;
        try {
			AMGSystem::runCommand("dscl . -passwd /Users/ " + this->username + " " + this->password);
            cout << "Successfully set password..." << endl;
        }
        catch(exception &e) {
            cout << "Error setting password..." << endl;
            cout << e.what() << endl;
        }
	}

	void AMGAddUser::setRealName() {
        cout << "Setting user's real name" << endl;
        try {
			AMGSystem::runCommand("dscl . -create /Users/" + this->username + " RealName \"" + this->firstName + " " + this->lastName + "\"");
            cout << "Successfully set real name..." << endl;
        }
        catch(exception &e) {
            cout << "Error setting real name..." << endl;
            cout << e.what() << endl;
        }
	}

	AMGAddUser::AMGAddUser() {
		this->username = "";
		this->password = "";
		this->firstName = "";
		this->lastName = "";
		this->isAdmin = false;
	}

	AMGAddUser::~AMGAddUser() {
	}

	void AMGAddUser::createUser() {
		cout << "Creating new user...." << endl;
		try {
			this->createHomeDirectory();
			this->setRealName();
			this->setPassword();
			this->setPermissions();
			cout << "Successfully created new user..." << endl;
		}
		catch(exception &e) {
			cout << "Error creating new user..." << endl;
			cout << e.what() << endl;
		}
	}

	void AMGAddUser::setUsername(string a) {
		this->username = a;
	}

	void AMGAddUser::setPassword(string a) {
		this->password = a;
	}

	void AMGAddUser::setFirstName(string a) {
		this->firstName = a;
	}

	void AMGAddUser::setLastName(string a) {
		this->lastName = a;
	}

	void AMGAddUser::setIsAdmin(bool a) {
		this->isAdmin = a;
	}

	string AMGAddUser::getUsername() {
		return this->username;
	}

	string AMGAddUser::getPassword() {
		return "";
	}

	string AMGAddUser::getFirstName() {
		return this->firstName;
	}

	string AMGAddUser::getLastName() {
		return this->lastName;
	}

	bool AMGAddUser::getIsAdmin() {
		return this->isAdmin;
	}
}

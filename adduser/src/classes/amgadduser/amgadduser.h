#ifndef __AMGADDUSER_H_INCLUDED__
#define __AMGADDUSER_H_INCLUDED__

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "classes/amgcommon/amgcommon_all.h"
using namespace std;
using namespace amgcommon;

#define PRODUCT_VERSION_STRING "1.0.0"

namespace amgadduser {
	class AMGAddUser {
		protected:
			string username;
			string password;
			string firstName;
			string lastName;
			bool isAdmin;
			virtual void createHomeDirectory();
			virtual void setPermissions();
			virtual void setPassword();
			virtual void setRealName();
			virtual int getUUID();
		public:
			AMGAddUser();
			~AMGAddUser();
			void createUser();
			void setUsername(string a);
			void setPassword(string a);
			void setFirstName(string a);
			void setLastName(string a);
			void setIsAdmin(bool a);
			string getUsername();
			string getPassword();
			string getFirstName();
			string getLastName();
			bool getIsAdmin();
	};	
}

#endif

#ifndef __AUTHSOURCE_SQLITE_INCLUDED__
#define __AUTHSOURCE_SQLITE_INCLUDED__
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "../../amgdata/amgdata_all.h"
#include "authenticationsource.h"
using namespace std;
using namespace amgdata;

namespace amgcommon {
    namespace auth {
        class AuthenticationSourceSqlite : public AuthenticationSource {
            private:
                string path;
                static shared_ptr<AuthenticationSourceSqlite> instance;
                shared_ptr<DataConnectionSQLite> source;
                string usersTable;
                string sessionTable;
            public:
                AuthenticationSourceSqlite(const string path="", const string table="");
                ~AuthenticationSourceSqlite();
                static shared_ptr<AuthenticationSourceSqlite> getInstance(const string path, const string table);
                bool isValid(const string username, const string password);
                bool isValid(const string token);
                string authenticate(const string username, const string password);
                string getUsersTable();
                string getSessionTable();
                void setPath(string a);
                void setSessionTable(const string a);
        };
    }
}
#endif

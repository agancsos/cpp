#ifndef __CONNECTION_SQLITE_H_INCLUDED__
#define __CONNECTION_SQLITE_H_INCLUDED__

#include <iostream>
#include <string>
#include <memory>
#include "interfaces/sqlite3/sqlite3.h"
#include "types/dataconnection.h"
using namespace std;
using namespace amgdata::types;

namespace amgdata {
    class DataConnectionSQLite : public DataConnection {
        private:
            sqlite3 *handler;
            void runSafeQuery(string query);
            bool connect();
            bool disconnect();
        public:
            DataConnectionSQLite(string path="");
            ~DataConnectionSQLite();
            bool runQuery(string query);
            shared_ptr<DataTable> query(string query);
            vector<string> getColumns(string query);
            string getRowId(string query, shared_ptr<DataRow> row);
            vector<string> getDatabases();
            vector<string> getTables();
            const static string getProviderName() { return "SQLite"; }
    };
}

#endif

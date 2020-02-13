#ifndef __CONNECTION_MYSQL_H_INCLUDED__
#define __CONNECTION_MYSQL_H_INCLUDED__

#include <iostream>
#include <string>
#include <memory>
#include "types/dataconnection.h"
// #include "interfaces/mysql/mysql_connection.h"
// #include "interfaces/mysql/cppconn/driver.h"
// #include "interfaces/mysql/cppconn/exception.h"
// #include "interfaces/mysql/cppconn/resultset.h"
// #include "interfaces/mysql/cppconn/statement.h"
using namespace std;
using namespace amgdata::types;
// using namespace sql;

namespace amgdata {
    class DataConnectionMySQL : public DataConnection {
        private:
            void runSafeQuery(string query);
            bool connect();
            bool disconnect();
        public:
            DataConnectionMySQL(string connectionString="");
            ~DataConnectionMySQL();
            bool runQuery(string query);
            shared_ptr<DataTable> query(string query);
            vector<string> getColumns(string query);
            string getRowId(string query, shared_ptr<DataRow> row);
            vector<string> getDatabases();
            vector<string> getTables();
            const static string getProviderName() { return "MySQL"; }
    };
}

#endif

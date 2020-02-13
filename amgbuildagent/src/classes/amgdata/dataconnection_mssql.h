#ifndef __CONNECTION_MSSQL_H_INCLUDED__
#define __CONNECTION_MSSQL_H_INCLUDED__

#include <iostream>
#include <string>
#include <memory>
#include "types/dataconnection.h"
using namespace std;
using namespace amgdata::types;

namespace amgdata {
    class DataConnectionMSSQL : public DataConnection {
        private:
            void runSafeQuery(string query);
            bool connect();
            bool disconnect();
        public:
            DataConnectionMSSQL(string connectionString="");
            ~DataConnectionMSSQL();
            bool runQuery(string query);
            shared_ptr<DataTable> query(string query);
            vector<string> getColumns(string query);
            string getRowId(string query, shared_ptr<DataRow> row);
            vector<string> getDatabases();
            vector<string> getTables();
            const static string getProviderName() { return "Microsoft SQL Server"; }
    };
}

#endif

#ifndef __CONNECTION_ORACLE_H_INCLUDED__
#define __CONNECTION_ORACLE_H_INCLUDED__

#include <iostream>
#include <string>
//#include "interfaces/oci/occi.h"
#include <memory>
#include "types/dataconnection.h"
using namespace std;
using namespace amgdata::types;
//using namespace oracle::occi;

namespace amgdata {
    class DataConnectionOracle : public DataConnection {
        private:
            //shared_ptr<Environment> env;
            //shared_ptr<Connection> handler;
            bool autoCommit;
            void runSafeQuery(string query);
            bool connect();
            bool disconnect();
        public:
            DataConnectionOracle(string connectionString="");
            ~DataConnectionOracle();
            bool runQuery(string query);
            shared_ptr<DataTable> query(string query);
            vector<string> getColumns(string query);
            string getRowId(string query, shared_ptr<DataRow> row);
            vector<string> getDatabases();
            vector<string> getTables();
            void setAutoCommit(bool a);
            bool getAutoCommit();
            const static string getProviderName() { return "Oracle"; }
    };
}

#endif

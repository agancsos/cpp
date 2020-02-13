#ifndef __CONNECTION_MONGODB_H_INCLUDED__
#define __CONNECTION_MONGODB_H_INCLUDED__

#include <iostream>
#include <string>
#include <memory>
#include "types/dataconnection.h"
using namespace std;
using namespace amgdata::types;

namespace amgdata {
    class DataConnectionMongoDb : public DataConnection {
        private:
            void runSafeQuery(string query);
            bool connect();
            bool disconnect();
            bool useLegacy;
        public:
            DataConnectionMongoDb(string connectionString="");
            ~DataConnectionMongoDb();
            bool runQuery(string query);
            shared_ptr<DataTable> query(string query);
            vector<string> getColumns(string query);
            string getRowId(string query, shared_ptr<DataRow> row);
            vector<string> getDatabases();
            vector<string> getTables();
            void setUseLegacy(bool use);
            bool getUseLegacy();
            const static string getProviderName() { return "MongoDb"; }
    };
}

#endif

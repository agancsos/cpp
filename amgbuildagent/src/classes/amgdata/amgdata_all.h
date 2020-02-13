#ifndef __AMGDATA_H_INCLUDED__
#define __AMGDATA_H_INCLUDED__
#define __FRAMEWORK_VERSION_STRING__ "1.0.0"
#include "dataconnection_sqlite.h"
#include "dataconnection_mongodb.h"
#include "dataconnection_oracle.h"
#include "dataconnection_mssql.h"
#include "dataconnection_mysql.h"
#include "types/data_types_all.h"
using namespace amgdata::types;

namespace amgdata { 
    class ConnectionFactory {
        private:
            static vector<string> providers() {
                vector<string> result;
                result.push_back(DataConnectionSQLite::getProviderName());
                result.push_back(DataConnectionMongoDb::getProviderName());
                result.push_back(DataConnectionOracle::getProviderName());
                result.push_back(DataConnectionMSSQL::getProviderName());
                result.push_back(DataConnectionMySQL::getProviderName());
                return result;
            };
        public:
            static shared_ptr<DataConnection> createConnection(string name) {
                if(name == "sqlite") {
                    return shared_ptr<DataConnectionSQLite>(new DataConnectionSQLite());
                }
                else if (name == "mongodb") {
                    return shared_ptr<DataConnection>(new DataConnectionMongoDb());
                }
                else if (name == "oracle") {
                    return shared_ptr<DataConnection>(new DataConnectionOracle());
                }
                else if (name == "mssql") {
                    return shared_ptr<DataConnection>(new DataConnectionMSSQL());
                }
                else if (name == "mysql") {
                    return shared_ptr<DataConnection>(new DataConnectionMySQL());
                }
                return nullptr;
            }
            const static vector<string> getProviders() { 
                return ConnectionFactory::providers(); 
            }
    };
}

#endif

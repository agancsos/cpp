#ifndef __DATAConnection_H_INCLUDED__
#define __DATAConnection_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <ctime>
#include "data_structures.h"
using namespace std;

namespace amgdata {
    namespace types {
        class DataConnection {
            protected:
                string databaseFile;
                string databaseName;
                string databaseUser;
                string databasePass;
                string databaseService;
                string databaseHost;
                string connectionString;
                int databasePort;
                virtual void runSafeQuery(string query) = 0;
                virtual bool connect() = 0;
                virtual bool disconnect() = 0;
            public:
                DataConnection(string connectionString="");
                virtual ~DataConnection();
                virtual bool runQuery(string query) = 0;
                virtual shared_ptr<DataTable> query(string query) = 0;
                virtual vector<string> getColumns(string query) = 0;
                virtual string getRowId(string query, shared_ptr<DataRow> row) = 0;
                const static string getProviderName();
                void setDatabaseName(string a);
                void setDatabaseUser(string a);
                void setDatabasePass(string a);
                void setDatabaseService(string a);
                void setDatabaseHost(string a);
                void setDatabasePort(int a);
                string getDatabaseName();
                string getDatabaseHost();
                string getDatabaseUser();
                string getDatabasePass();
                string getDatabaseService();
                int getDatabasePort();
                void setDatabaseFile(string a);
                string getDatabaseFile();
                string getConnectionString();
                void setConnectionString(string a);
                virtual vector<string> getDatabases() = 0;
                virtual vector<string> getTables() = 0;
        };
    }
}

#endif

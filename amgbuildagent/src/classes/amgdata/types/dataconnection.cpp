#include "dataconnection.h"

namespace amgdata {
    namespace types {
        DataConnection::DataConnection(string connectionString) { }
        DataConnection::~DataConnection() { }
        void DataConnection::runSafeQuery(string query) { }
        bool DataConnection::connect() { return false; }
        bool DataConnection::disconnect() { return true; }
        bool DataConnection::runQuery(string query) { return false; }
        shared_ptr<DataTable> DataConnection::query(string query) {
            shared_ptr<DataTable> result(new DataTable());
            return result;
        }
        vector<string> DataConnection::getColumns(string query) {
            vector<string> result;
            return result;
        }
        string DataConnection::getRowId(string query, shared_ptr<DataRow> row) { return 0; }
        void DataConnection::setDatabaseName(string a) { this->databaseName = a; }
        void DataConnection::setDatabaseUser(string a) { this->databaseUser = a; }
        void DataConnection::setDatabasePass(string a) { this->databasePass = a; }
        void DataConnection::setDatabaseService(string a) { this->databaseService = a; }
		const string DataConnection::getProviderName() { return "None"; }
        void DataConnection::setDatabaseHost(string a) { this->databaseHost = a; }
        void DataConnection::setDatabasePort(int a) { this->databasePort = a; }
        string DataConnection::getDatabaseName() { return this->databaseName; }
        string DataConnection::getDatabaseHost() { return this->databaseHost; }
        string DataConnection::getDatabaseUser() { return this->databaseUser; }
        string DataConnection::getDatabasePass() { return this->databasePass; }
        string DataConnection::getDatabaseService() { return this->databaseService; }
        int DataConnection::getDatabasePort() { return this->databasePort; }
        void DataConnection::setDatabaseFile(string a) { this->databaseFile = a; }
        string DataConnection::getDatabaseFile() { return this->databaseFile; }
        string DataConnection::getConnectionString() { return this->connectionString; }
        void DataConnection::setConnectionString(string a) { this->connectionString = a; }
    }
}

#include "dataconnection_mongodb.h"

namespace amgdata {
    /**
     * Default constructor
     */
    DataConnectionMongoDb::DataConnectionMongoDb(string connectionString) : DataConnection() {
    }

    /**
     * Deconstructor
     */
    DataConnectionMongoDb::~DataConnectionMongoDb() {

    }

    /**
     * This method executes a query without result nor logging
     * @param query Query to run
     */
    void DataConnectionMongoDb::runSafeQuery(string query) {
    }

    /**
     * This method opens a connection
     * @return True if successful, false if not
     */
    bool DataConnectionMongoDb::connect() {
        return false;
    }

    /**
     * This method closes a connection
     * @return True if successful, false if not
     */
    bool DataConnectionMongoDb::disconnect() {
        return true;
    }

    /**
     * This method runs a query
     * @param query Query to run
     * @return True if successful, false if not
     */
    bool DataConnectionMongoDb::runQuery(string query) {
        if(this->connect()) {
        }
        this->disconnect();
        return true;
    }

    /**
     * This method retrieves the records from the database
     * @param query Query to run
     * @return Results of the query
     */
    shared_ptr<DataTable> DataConnectionMongoDb::query(string query) {
        shared_ptr<DataTable> result(new DataTable());
        if(this->connect()) {
            this->disconnect();
        }
        return result;
    }

    /**
     * This method retrieves the names of the columns for a query
     * @param query Query to run
     * @return Names of the columns
     */
    vector<string> DataConnectionMongoDb::getColumns(string query) {
        vector<string> result;
        if(this->connect()) {
        }
        return result;
    }

    /**
     * This method retrieves the rowid for the given row
     * @param query Query to run
     * @param row Row to lookup
     * @return Numeric ID of the row
     */
    string DataConnectionMongoDb::getRowId(string query, shared_ptr<DataRow> row) {
        string result = "";
        return result;
    }

    vector<string> DataConnectionMongoDb::getDatabases() { 
        vector<string> result;
        return result;
    }
    vector<string> DataConnectionMongoDb::getTables() { 
        vector<string> result;
        return result;
    }

    void DataConnectionMongoDb::setUseLegacy(bool use) {
        this->useLegacy = use;
    }

    bool DataConnectionMongoDb::getUseLegacy() {
        return this->useLegacy;
    }
}
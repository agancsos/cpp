#include "dataconnection_mysql.h"
namespace amgdata {

    /**
     * Default constructor
     */
    DataConnectionMySQL::DataConnectionMySQL(string connectionString) : DataConnection(connectionString) {
        this->databaseFile = "";
        this->connectionString = connectionString;
    }

    /**
     * Deconstructor
     */
    DataConnectionMySQL::~DataConnectionMySQL() {

    }

    /**
     * This method executes a query without result nor logging
     * @param query Query to run
     */
    void DataConnectionMySQL::runSafeQuery(string query) {
    }

    /**
     * This method opens a connection
     * @return True if successful, false if not
     */
    bool DataConnectionMySQL::connect() {
        return false;
    }

    /**
     * This method closes a connection
     * @return True if successful, false if not
     */
    bool DataConnectionMySQL::disconnect() {
        return true;
    }

    /**
     * This method runs a query
     * @param query Query to run
     * @return True if successful, false if not
     */
    bool DataConnectionMySQL::runQuery(string query) {
        if(this->connect()) {
            this->disconnect();
        }
        return false;
    }

    /**
     * This method retrieves the records from the database
     * @param query Query to run
     * @return Results of the query
     */
    shared_ptr<DataTable> DataConnectionMySQL::query(string query) {
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
    vector<string> DataConnectionMySQL::getColumns(string query) {
        vector<string> result;
        if(this->connect()) {
            this->disconnect();
        }
        return result;
    }

    /**
     * This method retrieves the rowid for the given row
     * @param query Query to run
     * @param row Row to lookup
     * @return Numeric ID of the row
     */
    string DataConnectionMySQL::getRowId(string query, shared_ptr<DataRow> row) {
        string result = "";
        return result;
    }

    vector<string> DataConnectionMySQL::getDatabases() { 
        vector<string> result;
        return result;
    }
    vector<string> DataConnectionMySQL::getTables() { 
        vector<string> result;
        shared_ptr<DataTable> results = query("SELECT name FROM sqlite_master WHERE type IN ('table', 'view') ORDER BY 1 DESC");
		for(shared_ptr<DataRow> cursor : results->getRows()) {
			result.push_back(cursor->getColumns()[0]->getValue());
		}
        return result;
    }
}
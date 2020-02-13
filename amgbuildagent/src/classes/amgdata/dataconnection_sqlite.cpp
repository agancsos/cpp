#include "dataconnection_sqlite.h"
namespace amgdata {

    /**
     * Default constructor
     */
    DataConnectionSQLite::DataConnectionSQLite(string connectionString) : DataConnection(connectionString) {
        this->databaseFile = "";
        this->connectionString = connectionString;
        this->handler = nullptr;
    }

    /**
     * Deconstructor
     */
    DataConnectionSQLite::~DataConnectionSQLite() {

    }

    /**
     * This method executes a query without result nor logging
     * @param query Query to run
     */
    void DataConnectionSQLite::runSafeQuery(string query) {
        sqlite3_exec(this->handler, query.c_str(), NULL, NULL, NULL);
    }

    /**
     * This method opens a connection
     * @return True if successful, false if not
     */
    bool DataConnectionSQLite::connect() {
        if(sqlite3_open(this->databaseFile.c_str(), &this->handler) == SQLITE_OK) {
            return true;
        }
        return false;
    }

    /**
     * This method closes a connection
     * @return True if successful, false if not
     */
    bool DataConnectionSQLite::disconnect() {
        if(this->handler) {
            sqlite3_close(this->handler);
        }
        return true;
    }

    /**
     * This method runs a query
     * @param query Query to run
     * @return True if successful, false if not
     */
    bool DataConnectionSQLite::runQuery(string query) {
        if(this->connect()) {
            if(sqlite3_exec(this->handler, query.c_str(), NULL, NULL, NULL) != SQLITE_OK) {
                return false;
            }
            this->disconnect();
        }
        return true;
    }

    /**
     * This method retrieves the records from the database
     * @param query Query to run
     * @return Results of the query
     */
    shared_ptr<DataTable> DataConnectionSQLite::query(string query) {
        shared_ptr<DataTable> result(new DataTable());
        if(this->connect()) {
            sqlite3_stmt *statement;
            sqlite3_prepare_v2(this->handler, query.c_str(), query.length(), &statement, NULL);
            while(sqlite3_step(statement) == SQLITE_ROW) {
                shared_ptr<DataRow> tempRow(new DataRow());
                for(int i = 0; i < sqlite3_column_count(statement); i++) {
                    shared_ptr<DataColumn> tempColumn(new DataColumn());
                    tempColumn->setName(string(sqlite3_column_name(statement, i)));
                    tempColumn->setValue(reinterpret_cast<const char*>(sqlite3_column_text(statement, i)));
                    tempRow->addColumn(tempColumn);
                }
                result->addRow(tempRow);
            }
            sqlite3_finalize(statement);
            this->disconnect();
        }
        return result;
    }

    /**
     * This method retrieves the names of the columns for a query
     * @param query Query to run
     * @return Names of the columns
     */
    vector<string> DataConnectionSQLite::getColumns(string query) {
        vector<string> result;
        if(this->connect()) {
            sqlite3_stmt *statement;
            sqlite3_prepare_v2(this->handler, query.c_str(), query.length(), &statement, NULL);
            for(int i = 0; i < sqlite3_column_count(statement); i++) {
                result.push_back(string(sqlite3_column_name(statement, i)));
            }
            sqlite3_finalize(statement);
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
    string DataConnectionSQLite::getRowId(string query, shared_ptr<DataRow> row) {
        string result = "";
        return result;
    }

    vector<string> DataConnectionSQLite::getDatabases() { 
        vector<string> result;
        return result;
    }
    vector<string> DataConnectionSQLite::getTables() { 
        vector<string> result;
        shared_ptr<DataTable> results = query("SELECT name FROM sqlite_master WHERE type IN ('table', 'view') ORDER BY 1 DESC");
		for(shared_ptr<DataRow> cursor : results->getRows()) {
			result.push_back(cursor->getColumns()[0]->getValue());
		}
        return result;
    }
}

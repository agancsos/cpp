#include "dataconnection_oracle.h"
namespace amgdata {

    /**
     * Default constructor
     */
    DataConnectionOracle::DataConnectionOracle(string connectionString) : DataConnection(connectionString) {
        this->databaseFile = "";
        //this->connectionString = connectionString;
        //this->env = shared_ptr<Environment>(Environment::createEnvironment());
    }

    /**
     * Deconstructor
     */
    DataConnectionOracle::~DataConnectionOracle() {

    }

    /**
     * This method executes a query without result nor logging
     * @param query Query to run
     */
    void DataConnectionOracle::runSafeQuery(string query) {
        /*shared_ptr<Statement> statement(this->handler->createStatement(query));
        statement->setAutoCommit(true);
        statement->execute();
        this->handler->terminateStatement(statement.get());*/
    }

    /**
     * This method opens a connection
     * @return True if successful, false if not
     */
    bool DataConnectionOracle::connect() {
        try {
            //this->handler = shared_ptr<Connection>(this->env->createConnection(this->databaseUser, this->databasePass, this->connectionString));
        }
        catch (...) {

        }
        return false;
    }

    /**
     * This method closes a connection
     * @return True if successful, false if not
     */
    bool DataConnectionOracle::disconnect() {
        /*if (this->env != nullptr && this->handler != nullptr) {
            this->env->terminateConnection(this->handler.get());
            Environment::terminateEnvironment(this->env.get());
        }*/
        return true;
    }

    /**
     * This method runs a query
     * @param query Query to run
     * @return True if successful, false if not
     */
    bool DataConnectionOracle::runQuery(string query) {
        /*if(this-connect()) {
            shared_ptr<Statement> statement(this->handler->createStatement(query));
            if (this->autoCommit)
                statement->setAutoCommit(true);
            try {
                statement->execute();
            }
            catch (...) {
                this->handler->terminateStatement(statement.get());
                return false;
            }
            this->disconnect();
        }*/
        return false;
    }

    /**
     * This method retrieves the records from the database
     * @param query Query to run
     * @return Results of the query
     */
    shared_ptr<DataTable> DataConnectionOracle::query(string query) {
        shared_ptr<DataTable> result(new DataTable());
        /*if(this->connect()) {
            shared_ptr<Statement> statement(this->handler->createStatement(query));
            shared_ptr<ResultSet> results;
            try {
                results = shared_ptr<ResultSet>(statement->executeQuery());
                vector<MetaData> metadata = results->getColumnListMetaData();
                while (results->next()) {
                    shared_ptr<DataRow> tempRow;
                    for (int j = 0; j < metadata.size(); j++) {
                        shared_ptr<DataColumn>tempColumn;
                        tempColumn->setValue(results->getString(j));
                        tempColumn->setName(metadata[j].getString(MetaData::ATTR_NAME));
                        tempColumn->setType(metadata[j].getString(MetaData::ATTR_TYPE_NAME));
                        tempRow->addColumn(tempColumn);
                    }
                    result->addRow(tempRow);
                }
                statement->closeResultSet(results.get());
            }
            catch (...) {
                statement->closeResultSet(results.get());
            }
            this->handler->terminateStatement(statement.get());
            this->disconnect();
        }*/
        return result;
    }

    /**
     * This method retrieves the names of the columns for a query
     * @param query Query to run
     * @return Names of the columns
     */
    vector<string> DataConnectionOracle::getColumns(string query) {
        vector<string> result;
        /*if(this->connect()) {
            shared_ptr<Statement> statement(this->handler->createStatement(query));
            shared_ptr<ResultSet> results;
            try {
                results = shared_ptr<ResultSet>(statement->executeQuery());
                vector<MetaData> metadata = results->getColumnListMetaData();
                for (int i = 0; i < metadata.size(); i++) {
                    result.push_back(metadata[i].getString(MetaData::ATTR_NAME));
                }
                statement->closeResultSet(results.get());
            }
            catch (...) {
                statement->closeResultSet(results.get());
            }
            this->handler->terminateStatement(statement.get());
            this->disconnect();
        }*/
        return result;
    }

    /**
     * This method retrieves the rowid for the given row
     * @param query Query to run
     * @param row Row to lookup
     * @return Numeric ID of the row
     */
    string DataConnectionOracle::getRowId(string query, shared_ptr<DataRow> row) {
        string result = "";
        return result;
    }

    vector<string> DataConnectionOracle::getDatabases() { 
        vector<string> result;
        return result;
    }
    vector<string> DataConnectionOracle::getTables() { 
        vector<string> result;
        /*shared_ptr<DataTable> results = query("SELECT name FROM user_tables");
		for(shared_ptr<DataRow> cursor : results->getRows()) {
			result.push_back(cursor->getColumns()[0]->getValue());
		}*/
        return result;
    }

    void DataConnectionOracle::setAutoCommit(bool a) { this->autoCommit = a; }
    bool DataConnectionOracle::getAutoCommit() { return this->autoCommit; }
}

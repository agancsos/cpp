#include "datatable.h"

namespace amgdata { 
    DataTable::DataTable() {

    }

    DataTable::DataTable(vector<shared_ptr<DataRow> > rows, string name, string query) {
        this->name = name;
        this->query = query;
        this->rows = rows;
    }

    DataTable::~DataTable() {

    }

    /**
     * Getters and setters 
     */
    string DataTable::getName() { return this->name; }
    string DataTable::getQuery() { return this->query; }
    vector<shared_ptr<DataRow> > DataTable::getRows() { return this->rows; }
    string DataTable::toString() {
        string result = "";
        return result; 
    }
    void DataTable::setName(string a) { this->name = a; }
    void DataTable::setQuery(string a) { this->query = a; }
    void DataTable::addRow(shared_ptr<DataRow> row) { this->rows.push_back(row); }
}
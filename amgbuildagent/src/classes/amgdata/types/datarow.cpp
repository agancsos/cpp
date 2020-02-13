#include "datarow.h"

namespace amgdata {
    namespace types {
        DataRow::DataRow() {

        }

        DataRow::DataRow(vector<shared_ptr<DataColumn> > columns) {
            this->columns = columns;
        }

        DataRow::~DataRow() {

        }

        shared_ptr<DataColumn> DataRow::getColumn(string a) {
            for(shared_ptr<DataColumn> cursor : this->columns) {
                if(cursor->getName() == a) {
                    return cursor;
                }
            }
            return nullptr;
        }

        void DataRow::addColumn(shared_ptr<DataColumn> column) { 
            for(shared_ptr<DataColumn> cursor : this->columns) {
                if(cursor->getName() == column->getName()) {
                    return;
                }
            }
            this->columns.push_back(column); 
        }
        vector<shared_ptr<DataColumn> > DataRow::getColumns() { return this->columns; }
    }
}
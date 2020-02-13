#ifndef __DATAROW_H_INCLUDED__
#define __DATAROW_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <ctime>
#include "datacolumn.h"
using namespace std;

namespace amgdata {
    class DataRow {
        private:
            vector<shared_ptr<DataColumn> > columns;
        public:
            DataRow();
            DataRow(vector<shared_ptr<DataColumn> > columns);
            ~DataRow();
            void addColumn(shared_ptr<DataColumn> column);
            vector<shared_ptr<DataColumn> > getColumns();
            shared_ptr<DataColumn> getColumn(string a);
    };
}

#endif
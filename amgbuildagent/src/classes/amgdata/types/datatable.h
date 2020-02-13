#ifndef __DATATABLE_H_INCLUDED__
#define __DATATABLE_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <ctime>
#include "datarow.h"
using namespace std;

namespace amgdata {
    namespace types {
        class DataTable {
            private:
                string name;
                string query;
                vector<shared_ptr<DataRow> > rows;
            public:
                DataTable();
                DataTable(vector<shared_ptr<DataRow> > rows, string name = "", string query = "");
                ~DataTable();
                string getName();
                string getQuery();
                vector<shared_ptr<DataRow> > getRows();
                string toString();
                void setName(string a);
                void setQuery(string a);
                void addRow(shared_ptr<DataRow> row);
        };
    }
}

#endif
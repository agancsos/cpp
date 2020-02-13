#ifndef __DATACOLUMN_H_INCLUDED__
#define __DATACOLUMN_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <ctime>
using namespace std;

namespace amgdata {
    class DataColumn {
        private:
            string name;
            string type;
            string value;
        public:
            DataColumn(string name = "", string type = "", string value = "");
            ~DataColumn();
            string getName();
            string getType();
            string getValue();
            string toString();
            void setName(string a);
            void setType(string a);
            void setValue(string a);
    };
}

#endif
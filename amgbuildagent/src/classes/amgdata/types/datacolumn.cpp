#include "datacolumn.h"

namespace amgdata {
    namespace types {
        DataColumn::DataColumn(string name, string type, string value) {
            this->name = name;
            this->type = type;
            this->value = value;
        }

        DataColumn::~DataColumn() {

        }

        /**
         * Getters and setters
         */
        string DataColumn::getName() { return this->name; }
        string DataColumn::getType() { return this->type; }
        string DataColumn::getValue() { return this->value; }
        string DataColumn::toString() {
            string result = "";
            return result;
        }
        void DataColumn::setName(string a) { this->name = a; }
        void DataColumn::setType(string a) { this->type = a; }
        void DataColumn::setValue(string a) { this->value = a; }
    }
}
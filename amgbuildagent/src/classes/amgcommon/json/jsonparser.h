#ifndef __AMGCOMMON_JSON_JSONPARSER_H_INCLUDED__
#define __AMGCOMMON_JSON_JSONPARSER_H_INCLUDED__

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "jsonnode.h"
#include "jsonobject.h"
#include "../string.h"
#include "json_enums.h"
#include "../generics/generics_all.h"
using namespace std;
namespace amgcommon {
    namespace json {
        class JsonParser {
                private:
                    string rawJson;
                    string buffer;
                    string keyName;
                    bool isValue;
                    bool isObject;
                    bool isCollection;
                    bool isBuffing;
                    vector<Object*> collections;
                    JsonNode context;
                    vector<string> tokens;
                    JsonParser(const string rawJson = "");
                    JsonParser(const JsonParser &a);
                    JsonParser & operator= (const JsonParser &right) {
                        this->rawJson = right.rawJson;
                        return *this;
                    }
                    ~JsonParser();
                    JsonObject deserializeEx();
                    string serializeEx();
                    void reset();
                public:
                    static string serialize(JsonObject a);
                    static JsonObject deserialize(string a);
            };
    }
}

#endif

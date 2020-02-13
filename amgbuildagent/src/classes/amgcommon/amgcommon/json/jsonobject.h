#ifndef __AMGCOMMON_JSON_JSONOBJECT_H_INCLUDED__
#define __AMGCOMMON_JSON_JSONOBJECT_H_INCLUDED__

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "jsonnode.h"
using namespace std;

namespace amgcommon {
    namespace json {
        class JsonObject {
                private:
                    JsonNode root;
                    string originalJson;
                public:
                    JsonObject(string rawJson = "");
                    JsonObject(const JsonObject &a);
                    JsonObject & operator= (const JsonObject &right) {
                        this->originalJson = right.originalJson;
                        this->root = right.root;
                        return *this;
                    }
                    JsonObject *clone();
                    ~JsonObject();
                    void setKey(string path, Object *value);
                    Object *getKey(string path);
                    string toString();
                    JsonNode getRoot();
            };
    }
}

#endif

#ifndef __COMMON_JSON_JSONNODE_H_INCLUDED__
#define __COMMON_JSON_JSONNODE_H_INCLUDED__

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <regex>
#include <algorithm>
#include "json_enums.h"
#include "../string.h"
#include "../generics/generics_all.h"
using namespace std;
using namespace amgcommon::generics;
namespace amgcommon {
    namespace json {
        class JsonNode : public Object {
                private:
                    shared_ptr<Map<string, Object*> > container;
                    vector<JsonNode> children;
                public:
                    JsonNode();
                    JsonNode(const JsonNode &a);
                    ~JsonNode();
                    JsonNode *clone();
                    JsonNode & operator= (const JsonNode &right) {
                        this->type = right.type;
                        this->container = right.container;
                        this->children = right.children;
                        return *this;
                    }
                    void setKey(string name, Object *value);
                    Object *getKey(string name);
                    vector<JsonNode> getChildren();
                    void addChild(JsonNode a);
                    string toString();
                    bool lookupKey(string name);
            };
    }
}

#endif

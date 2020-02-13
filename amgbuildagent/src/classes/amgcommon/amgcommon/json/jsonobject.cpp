#include "jsonobject.h"
#include "jsonparser.h"

namespace amgcommon {
    namespace json {
        JsonObject::JsonObject(string rawJson) {
                this->originalJson = rawJson;
                this->root = JsonNode();
            }

            JsonObject::JsonObject(const JsonObject &a) {
                this->originalJson = a.originalJson;
                this->root = a.root;
            }

            JsonObject *JsonObject::clone() {
                return new JsonObject(*this);
            }

            JsonObject::~JsonObject() {
            }

            string JsonObject::toString() { 
                return this->root.toString(); 
            }

            JsonNode JsonObject::getRoot() { 
                return root; 
            }
            

            void JsonObject::setKey(string path, Object *value) { 
                this->root.setKey(path, value); 
            }

            Object *JsonObject::getKey(string path) { 
                return this->root.getKey(path); 
            }
    }
}

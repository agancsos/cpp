#include "object.h"
#include "objectcollection.h"

namespace amgcommon {	 
    namespace generics {
        Object::Object() {
            this->type = ObjectSimpleTypes::NONE;
            this->isObjectCollection = false;
        }

        Object::Object(int value) : Object() {
            this->type = ObjectSimpleTypes::INTEGER;
            this->intValue = value;
        }

        Object::Object(double value) : Object() {
            this->type = ObjectSimpleTypes::DOUBLE;
            this->doubleValue = value;
        }

        Object::Object(const Object &a) {
            this->type = a.type;
            this->isObjectCollection = a.isObjectCollection;
            switch(this->type) {
                case ObjectSimpleTypes::INTEGER:
                    this->intValue = a.intValue;
                    break;
                case ObjectSimpleTypes::DOUBLE:
                    this->doubleValue = a.doubleValue;
                    break;
                case ObjectSimpleTypes::FLOAT:
                    this->floatValue = a.floatValue;
                    break;
                case ObjectSimpleTypes::STRING:
                    this->stringValue = a.stringValue;
                    break;
                case ObjectSimpleTypes::OBJECT:
                    this->objectValue = a.objectValue;
                    break;
                case ObjectSimpleTypes::COLLECTION:
                    for (int i = 0; i < a.getItems().size(); i++) {
                        Object cursor = a.collectionValue.at(i);
                        if (cursor.getType() == ObjectSimpleTypes::OBJECT) {
                            vector<Object> myItems = cursor.getItems();
                            this->collectionValue = myItems;
                        }
                        else {
                            this->collectionValue.push_back(cursor);
                        }
                    }
                    break;
                default:
                    break;
            }
        }

        Object::Object(shared_ptr<void> value) : Object() {
            this->type = ObjectSimpleTypes::OBJECT;
            this->objectValue = value;
        }

        Object::Object(float value) : Object() {
            this->type = ObjectSimpleTypes::FLOAT;
            this->floatValue = value;
        }

        Object::Object(string value) : Object() {
            this->type = ObjectSimpleTypes::STRING;
            this->stringValue = value;
        }

        Object::Object(vector<Object*> value) : Object() {
            this->type = ObjectSimpleTypes::COLLECTION;
            vector<Object*> myItems = value;
            for (int i = 0; i < myItems.size(); i++) {
                collectionValue.push_back(Object(myItems.at(i)->clone()));
            }
        }

        Object::Object(vector<Object> value) : Object() {
            this->type = ObjectSimpleTypes::COLLECTION;
            vector<Object> myItems = value;
            for (int i = 0; i < myItems.size(); i++) {
                collectionValue.push_back(Object(myItems.at(i)));
            }
        }

        Object::Object(bool value) : Object() {
            this->type = ObjectSimpleTypes::BOOLEAN;
            this->boolValue = value;
        }

        Object::~Object() {
            
        }

        Object *Object::clone() {
            return new Object(*this);
        }

        const vector<Object> Object::getItems() const { 
            return this->collectionValue;
        }

        vector<Object*> Object::getItems2() { 
            vector<Object*> result;
            for (int i = 0; i < collectionValue.size(); i++) {
                result.push_back(collectionValue.at(i).clone());
            }
            return result;
        }

        string Object::toString() {
            if (this->type == ObjectSimpleTypes::STRING)
                return this->stringValue;
            else if (this->type == ObjectSimpleTypes::INTEGER)
                return to_string(this->intValue);
            else if (this->type == ObjectSimpleTypes::DOUBLE)
                return to_string(this->doubleValue);
            else if (this->type == ObjectSimpleTypes::FLOAT)
                return to_string(this->floatValue);
            else if (this->type == ObjectSimpleTypes::OBJECT)
                return "";
            else if (this->type == ObjectSimpleTypes::BOOLEAN)
                return (this->boolValue ? "True" : "False"); 
            else if (this->type == ObjectSimpleTypes::COLLECTION) {
                string buffer = "[";
                for (int i = 0; i < this->collectionValue.size(); i++) {
                    if (i > 0) {
                        buffer += ",";
                    }
                    buffer += this->collectionValue.at(i).toString();
                }
                buffer += "]";
                return buffer;
            }
            return "";
        }

        void Object::setIsObjectCollection(bool a) {
            this->isObjectCollection = a;
        }

        bool Object::getIsObjectCollection() {
            return this->isObjectCollection;
        }
    }
}

#ifndef __OBJECT_H_INCLUDED__
#define __OBJECT_H_INCLUDED__
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "../enumfactory.h"
using namespace std;

namespace amgcommon {
	namespace generics {
		class Object {
			protected:
				ObjectSimpleTypes type;
				int intValue;
				float floatValue;
				double doubleValue;
				bool isObjectCollection;
				bool boolValue;
				string stringValue;
				shared_ptr<void> objectValue;
				vector<Object> collectionValue;
			public:
				Object();
				Object(int value);
				Object(double value);
				Object(const Object &a);
				Object(float value);
				Object(string value);
				Object(bool value);
				~Object();
				Object(shared_ptr<void> value);
				Object(vector<Object> value);
				Object(vector<Object*> value);
				Object *clone();
				ObjectSimpleTypes getType() { return type; }
				virtual string toString();
				void setIsObjectCollection(bool a);
				bool getIsObjectCollection();
				const vector<Object> getItems() const;
				vector<Object*> getItems2();
				shared_ptr<void> getRaw() { return shared_ptr<void>(objectValue); }
				operator int() { return intValue; }
				operator double() { return doubleValue; }
				operator float() { return floatValue; }
				operator string() { return stringValue; }
				operator bool() { return boolValue; }
				Object & operator=(const Object &right) {
					this->type = right.type;
					this->isObjectCollection = right.isObjectCollection;
					switch(this->type) {
						case ObjectSimpleTypes::INTEGER:
							this->intValue = right.intValue;
							break;
						case ObjectSimpleTypes::DOUBLE:
							this->doubleValue = right.doubleValue;
							break;
						case ObjectSimpleTypes::FLOAT:
							this->floatValue = right.floatValue;
							break;
						case ObjectSimpleTypes::STRING:
							this->stringValue = right.stringValue;
							break;
						case ObjectSimpleTypes::OBJECT:
							this->objectValue = right.objectValue;
							break;
						case ObjectSimpleTypes::COLLECTION:
							for (int i = 0; i < right.getItems().size(); i++) {
								Object cursor = right.collectionValue.at(i);
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
					return *this;
				}
				bool operator== (const Object &right) const { 
					if (right.type != type) 
						return false;
					if (type == ObjectSimpleTypes::DOUBLE)
						return doubleValue == right.doubleValue;
					else if (type ==  ObjectSimpleTypes::FLOAT)
						return floatValue == right.floatValue;
					else if (type == ObjectSimpleTypes::INTEGER)
						return intValue == right.intValue;
					else if (type == ObjectSimpleTypes::STRING)
						return stringValue == right.stringValue;
					else if (type == ObjectSimpleTypes::BOOLEAN) 
						return boolValue == right.boolValue;
					else if (type == ObjectSimpleTypes::OBJECT)
						return objectValue == right.objectValue;
					else if (type == ObjectSimpleTypes::COLLECTION) {
						for (int i = 0; i < collectionValue.size(); i++){
							Object cursor = collectionValue.at(i);
							bool found = false;
							for (int j = 0; j < right.collectionValue.size(); j++){
								Object cursor2 = right.collectionValue.at(j);
								if (cursor == cursor2) {
									found = true;
								}
							}
							if (!found) 
								return false;
						}	
					}
					return true;
				}
		};
	}
}
#endif

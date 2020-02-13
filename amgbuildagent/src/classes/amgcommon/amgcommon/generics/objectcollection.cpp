#include "objectcollection.h"

namespace amgcommon {
	namespace generics {
		ObjectCollection::ObjectCollection() {
			this->isObjectCollection = false;
			this->type = ObjectSimpleTypes::COLLECTION;
		}

		ObjectCollection::ObjectCollection(vector<Object*> a) : ObjectCollection() {
			for (int i = 0; i < a.size(); i++) {
				this->objectCollection.push_back(a.at(i));
			}
		}

		ObjectCollection::ObjectCollection(const ObjectCollection &a) : ObjectCollection() {
			this->isObjectCollection = a.isObjectCollection;
			for (int i = 0; i < a.objectCollection.size(); i++) {
				this->objectCollection.push_back(a.objectCollection.at(i));
			}
		}

		ObjectCollection::~ObjectCollection() {
			
		}

		bool ObjectCollection::contains(const Object &a) {
			for (int i = 0; i < objectCollection.size(); i++){
				Object *cursor = objectCollection.at(i);
				if (*cursor == a) {
					return true;
				}
			}
			return false;
		}

		vector<Object*> ObjectCollection::getObjects() {
			return this->objectCollection;
		}

		ObjectCollection *ObjectCollection::clone() {
			return new ObjectCollection(*this);
		}

		Object *ObjectCollection::remove(Object &item) {
			for (int i = 0; i < this->objectCollection.size(); i++) {
				Object *cursor = this->objectCollection.at(i);
				if (*cursor == item) {
					this->objectCollection.erase(this->objectCollection.begin() + i);
					return cursor;
				}
			}		
			return nullptr;
		}

		Object *ObjectCollection::remove(int a) {
			for (int i = 0; i < this->objectCollection.size(); i++) {
				Object *cursor = this->objectCollection.at(i);
				if (i == a) {
					this->objectCollection.erase(this->objectCollection.begin() + i);
					return cursor;
				}
			}
			return nullptr;
		}

		Object *ObjectCollection::get(int a) {
			for (int i = 0; i < objectCollection.size(); i++){
				Object *cursor = this->objectCollection.at(i);
				if (i == a) {
					return cursor;
				}
			}
			return nullptr;
		}

		string ObjectCollection::toString() { 
			string buffer = "[";
			for (int i = 0; i < this->objectCollection.size(); i++) {
				if (i > 0) {
					buffer += ",";
				}
				buffer += this->objectCollection.at(i)->toString();
			}		
			buffer += "]";
			return buffer;
		}

		int ObjectCollection::count() { 
			return objectCollection.size();
		}
		
		void ObjectCollection::add(Object &item) { 
			this->objectCollection.push_back(item.clone());
		}

		const vector<Object*> ObjectCollection::getCollectionValue() const { 
			return this->objectCollection; 
		}
	}
}

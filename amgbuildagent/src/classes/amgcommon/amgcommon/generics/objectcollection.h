#ifndef __OBJECTCOLLECTION_H_INCLUDED__
#define __OBJECTCOLLECTION_H_INCLUDED__
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "../enumfactory.h"
#include "generic_types.h"
using namespace std;

namespace amgcommon {
    namespace generics {
        class ObjectCollection : public Object {
                private:
                    vector<Object*> objectCollection;
                public:
                    ObjectCollection();
                    ObjectCollection(vector<Object*> a);
                    ~ObjectCollection();
                    ObjectCollection(const ObjectCollection &a);
                    void add(Object &item);
                    Object *remove(Object &item);
                    Object *remove(int a);
                    Object *get(int a);
                    int count();
                    vector<Object*> getObjects();
                    ObjectCollection *clone();
                    bool contains(const Object &a);
                    string toString();
                    const vector<Object*> getCollectionValue() const;
                    ObjectCollection & operator= (const ObjectCollection &right) {
                        this->type = ObjectSimpleTypes::COLLECTION;
                        for (int i = 0; i < right.objectCollection.size(); i++) {
                            this->objectCollection.push_back(right.objectCollection.at(i));
                        }
                        return *this;
                    }
                    bool operator== (const ObjectCollection &right) {
                        for (int i = 0; i < collectionValue.size(); i++){
                            Object cursor = collectionValue.at(i);
                            if (!ObjectCollection(right).contains(cursor)){ 
                                return false;
                            }
                        }
                        return true;
                    } 
            };
    }
}
#endif

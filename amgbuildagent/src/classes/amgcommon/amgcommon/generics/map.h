#ifndef __MAP_H_INCLUDED__
#define __MAP_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "mapelement.h"
using namespace std;

namespace amgcommon {
    namespace generics {
        template <class T, class T2>
            class Map {
                private:
                    vector<MapElement<T,T2> > elements;
                    bool ensure(T key);
                public:
                    Map();
                    Map(const Map<T, T2> &a);
                    Map<T,T2> *clone();
                    ~Map();
                    void add(T key,T2 value);
                    void replace(T key,T2 value);
                    MapElement<T,T2> remove(T key);
                    MapElement<T,T2> getElement(T key);
                    vector<MapElement<T,T2> > getElements();
                    bool contains(T key);
            };

            template <class T, class T2>
            Map<T, T2>::Map(const Map<T, T2> &a) {
                this->elements = a.elements;
            }

            template <class T, class T2>
            bool Map<T,T2>::contains(T key) {
                for (int i = 0; i < elements.size(); i++) {
                    MapElement<T,T2> cursor = this->elements.at(i);
                    if (cursor.getKey() == key) {
                        return true;
                    }
                }
                return false;
            }

            template <class T, class T2>
            bool Map<T,T2>::ensure(T key) {
                for (int i = 0; i < elements.size(); i++) {
                    MapElement<T,T2>  cursor = this->elements.at(i);
                    if (cursor.getKey() == key) {
                        return false;
                    }
                }
                return true;
            }
            
            template <class T, class T2>
            Map<T,T2>::Map() {
            }

            template <class T, class T2>
            Map<T,T2> *Map<T,T2>::clone() {
                return new Map<T,T2>(*this);
            } 

            template <class T, class T2>
            Map<T,T2>::~Map() {
            }

            template <class T, class T2>
            void Map<T,T2>::add(T key,T2 value) {
                if (this->ensure(key)) {
                    this->elements.push_back(MapElement<T, T2>(key, value));
                }
            }

            template <class T, class T2>
            MapElement<T,T2> Map<T,T2>::remove(T key) {
                for (int i = 0; i < elements.size(); i++) {
                    shared_ptr<MapElement<T,T2> > cursor = this->elements.at(i);
                    if (cursor->getKey() == key) {
                        this->elements.erase(elements.begin() + i);
                    }
                }
                return MapElement<T,T2>();
            }

            template <class T, class T2>
            void Map<T,T2>::replace(T key, T2 value) {
                for (int i = 0; i < elements.size(); i++) {
                    MapElement<T,T2> cursor = this->elements.at(i);
                    if (cursor.getKey() == key) {
                        cursor.setValue(value);
                    }
                }
            }

            template <class T, class T2>
            MapElement<T,T2> Map<T,T2>::getElement(T key) {
                for (int i = 0; i < elements.size(); i++) {
                    MapElement<T,T2> cursor = this->elements.at(i);
                    if (cursor.getKey() == key) {
                        return cursor;
                    }
                }
                return MapElement<T,T2>();
            }

            template <class T, class T2>
            vector<MapElement<T,T2> > Map<T,T2>::getElements() {
                vector<MapElement<T,T2> > result;
                for (int i = 0; i < elements.size(); i++) {
                    result.push_back(elements.at(i));
                }
                return result;
            }
    }
}

#endif

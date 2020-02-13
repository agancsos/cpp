#ifndef __MAPELEMENT_H_INCLUDED__
#define __MAPELEMENT_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

namespace amgcommon {
    namespace generics {
        template <class T,class T2>
        class MapElement {
            private:
                T key;
                T2 value;
            public:
                MapElement();
                MapElement(T key, const T2 value);
                MapElement(const MapElement<T, T2> &a);
                ~MapElement();
                void setValue(T2 a);
                T getKey();
                T2 getValue();
                MapElement<T,T2> *clone();
        };

        template <class T, class T2>
        MapElement<T, T2>::MapElement(const MapElement<T, T2> &a) {
            this->key = a.key;
            this->value = a.value;
        }

        template <class T, class T2>
        T MapElement<T,T2>::getKey() { 
            return this->key; 
        }

        template <class T, class T2>
        MapElement<T,T2> *MapElement<T,T2>::clone() {
            return new MapElement<T,T2>(*this);
        }

        template <class T, class T2>
        MapElement<T,T2>::MapElement() {
        }

        template <class T, class T2>
        MapElement<T,T2>::MapElement(T key, const T2 value) {
            this->key = key;
            this->value = value;
        }

        template <class T, class T2>
        MapElement<T,T2>::~MapElement() {
        }

        template <class T, class T2>
        void MapElement<T,T2>::setValue(T2 a) { 
            this->value = a; 
        }
        
        template <class T, class T2>
        T2 MapElement<T,T2>::getValue() { 
            return this->value; 
        }
    }
}
#endif
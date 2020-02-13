#ifndef __JSONPROPERTYSTORE_H_INCLUDED__  
#define __JSONPROPERTYSTORE_H_INCLUDED__ 

#include <string>
#include <vector>
#include "propertystore.h"
#include "../json/json_all.h"
using namespace std;
using namespace amgcommon::json;

namespace amgcommon{
	namespace propertystores {
		template <class T, class T2>
		class JsonPropertyStore : public PropertyStore<T, T2> {
			private:
				shared_ptr<JsonObject> container;
				string readFile();
				void writeData(string data);
			public:
				JsonPropertyStore(string src = "");
				T2 getProperty(T key);
				void setProperty(T key, T2 value);
		};

		template <class T, class T2>
		JsonPropertyStore<T,T2>::JsonPropertyStore(string src) : PropertyStore<T, T2>(src) {
			this->container = shared_ptr<JsonObject>(JsonParser::deserialize(src).clone());
		}

		template <class T, class T2>
		T2 JsonPropertyStore<T,T2>::getProperty(T key) {
			return this->container->getKey(key);
		}

		template <class T, class T2>
		void JsonPropertyStore<T,T2>::setProperty(T key, T2 value) {
			this->container->setKey(key, value);
		}
	}
}

#endif

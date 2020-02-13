#ifndef __PLAINPROPERTYSTORE_H_INCLUDED__  
#define __PLAINPROPERTYSTORE_H_INCLUDED__ 

#include <string>
#include <vector>
#include "propertystore.h"
using namespace std;

namespace amgcommon{
	namespace propertystores {
		class PlainPropertyStore : public PropertyStore<string, string> {
			private:
				string delimeter;
			public:
				PlainPropertyStore(string src = "", string delim = ":");
				~PlainPropertyStore();
				string getProperty(string key);
				void setProperty(string key, string value);
				string getDelimeter();
				void setDelimeter(string delim);
				vector<string> getKeys();
		};
	}
}

#endif


#ifndef __PROPERTYSTORE_H_INCLUDED__
#define __PROPERTYSTORE_H_INCLUDED__
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include "../system/systemservice.h"
#include "../string.h"
using namespace std;
using namespace amgcommon::system;

namespace amgcommon {
	namespace propertystores {
		template <class T, class T2>
			class PropertyStore {
				public:
					PropertyStore(string src = "");
					virtual ~PropertyStore();
					string getSource();
					void setSource(string src);
					virtual T2 getProperty(T key) = 0;
					virtual void setProperty(T key, T2 value) = 0;
					virtual vector<T> getKeys();
				protected:
					string source;
					string readFile();
					void writeData(string data);
			};
			
			template <class T, class T2>
			PropertyStore<T,T2>::PropertyStore(string src) {
				this->source = src;
			}
			
			template <class T, class T2>
			PropertyStore<T,T2>:: ~PropertyStore() {
				
			}
			
			template <class T, class T2>
			string PropertyStore<T,T2>::readFile() {
				if(SystemService::fileExists(source)) {
					return SystemService::readFile(source);
				}
				return "";
			}
			
			template <class T, class T2>
			void PropertyStore<T,T2>::writeData(string data) {
				SystemService::writeFile(this->source, data);
			}
			
			template <class T, class T2>
			string PropertyStore<T,T2>::getSource() { return this->source; }
			
			template <class T, class T2>
			void PropertyStore<T,T2>::setSource(string src) { this->source = src; }
			
			template <class T, class T2>
			vector<T> PropertyStore<T,T2>::getKeys() {
				vector<string> result;
				return result;
			}
	}
}
#endif

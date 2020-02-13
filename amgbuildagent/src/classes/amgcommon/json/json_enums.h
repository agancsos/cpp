#ifndef __JSON_ENUMS_H_INCLUDED__
#define __JSON_ENUMS_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <memory>
#include "../string.h"
#define __DEBUG__ false
namespace amgcommon {
    namespace json {
        enum class JsonTokenType { 
                NONE = 0, 
                NULL_TYPE = 1, 
                START_END_STRING = 2, 
                INTEGER = 3, 
                START_OBJECT = 4, 
                END_OBJECT = 5, 
                START_COLLECTION = 6, 
                END_COLLECTION = 7, 
                START_VALUE = 8,
                NONTERMINAL = 9,
                COLLECTION_INDEX = 10
            };

            class JsonTokenTypeHelper {
                public:
                    const static string getName(const JsonTokenType a);
                    const static JsonTokenType getLexical(const string a);
            };

            enum class JsonNodeType { 
                NONE = 0, 
                NULL_TYPE = 1, 
                STRING = 2, 
                INTEGER = 3, 
                OBJECT = 4,  
                COLLECTION = 5
            };

            class JsonNodeTypeHelper {
                public:
                    const static string getName(const JsonNodeType a);
            };
    }
}
#endif
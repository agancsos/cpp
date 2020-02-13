#include "json_enums.h"
namespace amgcommon {
    namespace json {
        const string JsonTokenTypeHelper::getName(const JsonTokenType a) {
                switch(a) {
                    case JsonTokenType::NONE:
                        return "None";
                    case JsonTokenType::NULL_TYPE:
                        return "Null";
                    case JsonTokenType::START_END_STRING:
                        return "SEString";
                    case JsonTokenType::START_COLLECTION:
                        return "SCollection";
                    case JsonTokenType::END_COLLECTION:
                        return "ECollection";
                    case JsonTokenType::START_OBJECT:
                        return "SObject";
                    case JsonTokenType::END_OBJECT:
                        return "EObject";
                    case JsonTokenType::INTEGER:
                        return "Integer";
                    case JsonTokenType::START_VALUE:
                        return "SValue";
                    case JsonTokenType::COLLECTION_INDEX:
                        return "Index";
                    case JsonTokenType::NONTERMINAL:
                        return "Nonterminal";
                    default:
                        return "";
                }
            }

            const JsonTokenType JsonTokenTypeHelper::getLexical(const string a) {
                smatch matches;
                regex pattern("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
                if(a != "") {
                    if(a == "{")
                        return JsonTokenType::START_OBJECT;
                    else if(a == "}")
                        return JsonTokenType::END_OBJECT;
                    else if(a == "[") 
                        return JsonTokenType::START_COLLECTION;
                    else if(a == "]") 
                        return JsonTokenType::END_COLLECTION;
                    else if(a == ":")
                        return JsonTokenType::START_VALUE;
                    else if(AMGString(a).toLowerCase().get() == "null" || AMGString(a).toLowerCase().get() == "nan")
                        return JsonTokenType::NULL_TYPE;
                    else if(a == "\"")
                        return JsonTokenType::START_END_STRING;
                    else if(a == ",")
                        return JsonTokenType::COLLECTION_INDEX;
                    else if(regex_search(a, matches, pattern) == true)
                        return JsonTokenType::INTEGER;
                    else 
                        return JsonTokenType::NONTERMINAL;

                }
                return JsonTokenType::NONE;
            }

            const string JsonNodeTypeHelper::getName(JsonNodeType a) {
                switch(a) {
                    case JsonNodeType::NONE:
                        return "None";
                    case JsonNodeType::NULL_TYPE:
                        return "Null";
                    case JsonNodeType::STRING:
                        return "String";
                    case JsonNodeType::COLLECTION:
                        return "Collection";
                    case JsonNodeType::OBJECT:
                        return "Object";
                    case JsonNodeType::INTEGER:
                        return "Integer";
                    default:
                        return "";
                }
            }
    }
}

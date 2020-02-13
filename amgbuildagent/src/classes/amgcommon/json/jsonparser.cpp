#include "jsonparser.h"
#include "../system/diagnostics.h"

// https://www.regular-expressions.info/stdregex.html
namespace amgcommon {
    namespace json {
        JsonParser::JsonParser(const string rawJson) {
                this->rawJson = rawJson;
                this->tokens = AMGString(this->rawJson).split("");
                this->buffer = "";
                this->isValue = false;
                this->isObject = false;
                this->isCollection = false;
                this->isBuffing = false;
                this->context = JsonNode();
            }

            JsonParser::JsonParser(const JsonParser &a) {
                this->rawJson = a.rawJson;
            }

            void JsonParser::reset() {
                this->buffer = "";
                this->keyName = "";
                this->isBuffing = false;
                this->isValue = false;
                this->isObject = false;
            }

            JsonParser::~JsonParser() {
            }

            /**
             * This is the core method for the parser.  Basically, itterate through the tokens (characters)
             * and look up the token type based on the ISO for the JSON language.  If the current item being
             * parsed is an Object, just continue to buffer until the end object token is found.  If the node
             * is in collection mode, add the item.  In all scenarios, reset the context appropriately and continue.
             * @preturns JsonObject representation of the JSON.
             */
            JsonObject JsonParser::deserializeEx() {
                JsonObject result = JsonObject();
                this->context = result.getRoot();

                for(string token : tokens) {
                    string token2 = AMGString(token).strip().get();
                    JsonTokenType tokenType = JsonTokenTypeHelper::getLexical(token2);
                    if(tokenType == JsonTokenType::NONE)
                        continue;
                    else if(isObject && tokenType != JsonTokenType::END_OBJECT) {
                        buffer += token2;
                        continue;
                    }
                    else if (isBuffing && tokenType != JsonTokenType::START_END_STRING) {
                        buffer += token2;
                        continue;
                    }
                    switch(tokenType) {
                        // Construct 
                        case JsonTokenType::START_END_STRING:
                            if(!isBuffing) {
                                isBuffing = true;
                            }
                            else {
                                isBuffing = false;
                                if(isValue) {
                                    isValue = false;
                                    if (keyName != "") {
                                        // Convert to boolean if needed
                                        if (AMGString(buffer).toLowerCase().get() == "true")
                                            context.setKey(keyName, new Object(true));
                                        else if (AMGString(buffer).toLowerCase().get() == "false")
                                            context.setKey(keyName, new Object(false));

                                        context.setKey(keyName, new Object((buffer)));
                                        reset();
                                    }
                                }
                                else {
                                    keyName = buffer;
                                    buffer = "";
                                }
                            }
                            break;
                        case JsonTokenType::START_COLLECTION:
                            if(!isCollection && isValue && !isBuffing) {
                                collections.clear();
                                isCollection = true;
                            }
                            break;
                        case JsonTokenType::END_COLLECTION:
                            if(isCollection) {
                                ObjectCollection *collection = new ObjectCollection(collections);
                                collection->setIsObjectCollection(context.getIsObjectCollection());
                                context.setKey(keyName, collection);
                                reset();
                                this->context.setIsObjectCollection(false);
                                isCollection = false;
                                collections.clear();
                            }
                            break;
                        case JsonTokenType::START_OBJECT:
                            if(!isObject && isValue && !isBuffing) {
                                isObject = true;
                                if (isCollection && !context.getIsObjectCollection()) {
                                    context.setIsObjectCollection(true);
                                }
                            }
                            break;
                        case JsonTokenType::COLLECTION_INDEX:
                            if(isCollection && isBuffing) {
                                collections.push_back(new Object(buffer));
                            }
                            else if(!isBuffing && !isCollection) {
                                context.setKey(keyName, new Object(buffer));
                                reset();
                            }
                            break;
                        case JsonTokenType::END_OBJECT:
                            if(isObject) {
                                isObject = false;
                                try {
                                    JsonObject childObject = JsonParser::deserialize(buffer);
                                    JsonNode *childNode = childObject.getRoot().clone();
                                    if (childNode) {
                                        if (isCollection) {
                                            this->collections.push_back(childNode);
                                        }
                                        else {
                                            context.setKey(keyName, childNode);
                                            reset();
                                        }
                                    }
                                }
                                catch (exception &e) {
                                    cout << e.what() << endl;
                                }
                            }
                            break;
                        case JsonTokenType::NULL_TYPE:
                            context.setKey(keyName, nullptr);
                            reset();
                            break;
                        case JsonTokenType::INTEGER:
                            if(isCollection && token2 != "") {
                                collections.push_back(new Object(stod(token2)));
                            }
                            else {
                                if(isValue && !isCollection) {
                                    context.setKey(keyName, new Object(stod(token2)));
                                    reset();
                                }
                            }
                            break;
                        case JsonTokenType::START_VALUE:
                            if(keyName != "") {
                                isValue = true;
                                buffer = "";    
                            }
                            break;
                        default:
                            break;
                    }
                }
                return result;
            }

            /**
             * This method converts a JSON string to a JSON object
             * @param a String to convert from
             * @return JSON object
             */
            JsonObject JsonParser::deserialize(string a) {
                return JsonParser(a).deserializeEx();
            }

            /**
             * This method converts a JSON object to it's original JSON text
             * @param a Object to convert to JSON text
             * @return JSON of the object
             */
            string JsonParser::serialize(JsonObject a) { 
                return a.getRoot().toString();
            }
    }
}

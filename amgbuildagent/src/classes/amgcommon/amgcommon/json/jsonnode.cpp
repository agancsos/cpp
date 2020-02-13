#include "jsonnode.h"
namespace amgcommon {
    namespace json {
        JsonNode::JsonNode() {
                this->type = ObjectSimpleTypes::OBJECT;
                this->container = shared_ptr<Map<string, Object*> >(new Map<string, Object*>());
                this->isObjectCollection = false;
            }

            JsonNode::JsonNode(const JsonNode &a) : JsonNode() {
                this->type = a.type;
                this->container = a.container;
                this->children = a.children;
            }

            JsonNode *JsonNode::clone() {
                return new JsonNode(*this);
            }

            JsonNode::~JsonNode() {
            }

            void JsonNode::addChild(JsonNode a) {
                if (find(this->children.begin(), this->children.end(), a) == this->children.end()) {
                    this->children.push_back(a);
                }
            }

            void JsonNode::setKey(string name, Object *value) {
                if (name != "") {
                    if(this->container->contains(name)) {
                        this->container->replace(name, value);
                    }
                    else {
                        this->container->add(name, value);
                    }
                }
            }
            
            Object *JsonNode::getKey(string name) {
                vector<string> comps = AMGString(name).split(".");
                if (comps.size() == 1) {
                    if (container->contains(name)) {
                        MapElement<string, Object*> myElement = container->getElement(name);
                        Object *nodeValue = myElement.getValue();
                        return nodeValue;
                    }
                    return new Object();
                }
                JsonNode context = *this;
                for (int i = 0; i < comps.size() - 1; i++) {
                    if (context) {
                        if (context.lookupKey(AMGString(comps[i]).strip().get())) {
                            Object *value = context.getKey(AMGString(comps[i]).strip().get());
                            context = *dynamic_cast<JsonNode*>(value);
                        }		
                    }
                }
                return context.getKey(comps[comps.size() - 1]);
            }
            
            string JsonNode::toString() {
                string result = "{";      
                for(int itemIndex = 0; itemIndex < container->getElements().size(); itemIndex++) {
                    vector<MapElement<string, Object*> > myItems = this->container->getElements();
                    MapElement<string, Object*> pair = myItems.at(itemIndex);
                    if (pair.getKey() != "") {
                        if(itemIndex > 0) {
                            result = result +  ", ";
                        }
                        try {
                            result = result + ("\"" + pair.getKey() + "\" : ");
                            if (pair.getValue()->getType() == ObjectSimpleTypes::STRING) {
                                result = result +  "\"";
                            }
                            Object *value = pair.getValue();
                            if (value->getType() == ObjectSimpleTypes::COLLECTION) {
                                ObjectCollection *values = dynamic_cast<ObjectCollection*>(value);
                                result += values->toString();
                            }
                            else {
                                result = result + value->toString();
                            }
                            if (pair.getValue()->getType() == ObjectSimpleTypes::STRING) {
                                result = result + "\"";
                            }
                        }
                        catch(exception &e) {
                            cout << pair.getKey() << " : " << e.what() << endl;
                        }
                    }
                }
                result = result + "}";
                return result;
            }

            vector<JsonNode> JsonNode::getChildren() { 
                return this->children; 
            }
            
            bool JsonNode::lookupKey(string name) { 
                return this->container->contains(name); 
            }
    }
}

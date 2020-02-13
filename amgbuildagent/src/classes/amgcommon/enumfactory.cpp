#include "enumfactory.h"

namespace amgcommon {
    const string InputTypeHelper::getTypeName(InputTypes a) {
        switch(a) {
            case InputTypes::STRING:
                return "String";
            case InputTypes::NUMBER:
                return "Number";
            case InputTypes::BOOL:
                return "Boolean";
            default:
                return "";
        }
    }
}
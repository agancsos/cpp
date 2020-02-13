#ifndef __AMGENUMS_H_INCLUDED__
#define __AMGENUMS_H_INCLUDED__

#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

namespace amgcommon {
    enum class InputTypes {
		NONE = 0,
        STRING = 1,
        NUMBER = 2,
        BOOL = 3
    };

    enum class ObjectSimpleTypes {
		NONE = 0,
		INTEGER = 1,
		FLOAT = 2,
		DOUBLE = 3,
		STRING = 4,
		OBJECT = 5,
		COLLECTION = 6,
		BOOLEAN = 7
	};

	class InputTypeHelper {
		public:
			const static string getTypeName(InputTypes a);
	};
}
#endif

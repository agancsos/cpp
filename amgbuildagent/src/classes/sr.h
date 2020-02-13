#ifndef __SR_H_INCLUDED__
#define __PRODUCT_AUTHOR_STRING__ "Abel Gancsos"
#define __PRODUCT_NAME_STRING__   "AMGBuildAgent"
#define __AGENT_VERSION_STRING__  "1.0.0"
#define __SR_H_INCLUDED__
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace sr {
	class SR {
		public:
			static void helpMenu();
			static string padRight(string str, int length, string pad);
	};
}
#endif

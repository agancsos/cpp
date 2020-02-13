#ifndef __AMGAGENTSOCKET_H_INCLUDED__
#define __AMGAGENTSOCKET_H_INCLUDED__
#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <dirent.h>
#include "../amgcommon/amgcommon_all.h"
#include "../amgbuildagent/amgbuilder.h"
#include "../amgnet/amgnet_all.h"
using namespace std;
using namespace amgcommon;
using namespace amgnet;

namespace amgbuildagent {
	template<class T>
    class AMGAgentSocket : public ServerSocket<T> {
		public:
			AMGAgentSocket(int p = 0, string name = "");
			~AMGAgentSocket();
			void startServer();
	};
}
#endif

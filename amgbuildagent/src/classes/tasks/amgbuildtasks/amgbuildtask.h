#ifndef __AMGBUILDTASK_H_INCLUDED__
#define __AMGBUILDTASK_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <dirent.h>
#include "../../amgcommon/amgcommon_all.h"
using namespace std;
using namespace amgcommon;
using namespace amgcommon::propertystores;
namespace amgbuildtasks {
	class AMGBuildTask {
		protected:
            const string FILE_NAMES[3] = {"compile", "run", "unit_test"};
            const string EXTENSIONS[4] = { "sh", "bat", "py", "pl" };
            shared_ptr<JsonObject> configuration;
            shared_ptr<PlainPropertyStore> agentConfiguration;
			string getApplicationBase();
			string basePath;
		public:
			AMGBuildTask();
			AMGBuildTask(shared_ptr<JsonObject> configuration);
			virtual ~AMGBuildTask();
			virtual bool invoke() = 0;
			virtual string getTaskName() = 0;
	};
}

#endif

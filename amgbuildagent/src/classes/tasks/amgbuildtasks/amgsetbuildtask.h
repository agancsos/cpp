#ifndef __AMGSETBUILDTASK_H_INCLUDED__
#define __AMGSETBUILDTASK_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "amgbuildtask.h"
using namespace std;

namespace amgbuildtasks {
    class AMGSetBuildTask : public AMGBuildTask {
		private:
			string generateBuildNumber();
        public:
            AMGSetBuildTask();
			AMGSetBuildTask(shared_ptr<JsonObject> a);
            ~AMGSetBuildTask();
            bool invoke();
			string getTaskName();
    };
}

#endif

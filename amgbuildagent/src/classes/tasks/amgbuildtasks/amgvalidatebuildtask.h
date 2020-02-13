#ifndef __AMGVALIDATEBUILDTASK_H_INCLUDED__
#define __AMGVALIDATEBUILDTASK_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "amgbuildtask.h"
using namespace std;
namespace amgbuildtasks {
    class AMGValidateBuildTask : public AMGBuildTask {
        public:
            AMGValidateBuildTask();
			AMGValidateBuildTask(shared_ptr<JsonObject> a);
            ~AMGValidateBuildTask();
            bool invoke();
			string getTaskName();
    };
}

#endif

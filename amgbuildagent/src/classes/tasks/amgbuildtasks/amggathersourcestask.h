#ifndef __AMGGATHERSOURCESTASK_H_INCLUDED__
#define __AMGGATHERSOURCESTASK_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "amgbuildtask.h"
using namespace std;

namespace amgbuildtasks {
    class AMGGatherSourcesTask : public AMGBuildTask {
        public:
            AMGGatherSourcesTask();
			AMGGatherSourcesTask(shared_ptr<JsonObject> a);
            ~AMGGatherSourcesTask();
            bool invoke();
			string getTaskName();
    };
}

#endif

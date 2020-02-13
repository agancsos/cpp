#ifndef __AMGPROBETASK_H_INCLUDED__
#define __AMGPROBETASK_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "amgbuildtask.h"
using namespace std;

namespace amgbuildtasks {
    class AMGProbeTask : public AMGBuildTask {
        public:
            AMGProbeTask();
			AMGProbeTask(shared_ptr<JsonObject> a);
            ~AMGProbeTask();
            bool invoke();
            string getTaskName();
    };
}

#endif

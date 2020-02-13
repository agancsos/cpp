#ifndef __AMGRUNTESTSTASK_H_INCLUDED__
#define __AMGRUNTESTSTASK_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "amgbuildtask.h"
using namespace std;

namespace amgbuildtasks {
    class AMGRunTestsTask : public AMGBuildTask {
        public:
            AMGRunTestsTask();
			AMGRunTestsTask(shared_ptr<JsonObject> a);
			AMGRunTestsTask(string path);
            ~AMGRunTestsTask();
            bool invoke();
			string getTaskName();
    };
}

#endif

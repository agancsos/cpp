#ifndef __AMGCOMPILETASK_H_INCLUDED__
#define __AMGCOMPILETASK_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "amgbuildtask.h"
using namespace std;

namespace amgbuildtasks {
    class AMGCompileTask : public AMGBuildTask {
        public:
            AMGCompileTask();
			AMGCompileTask(shared_ptr<JsonObject> a);
            ~AMGCompileTask();
            bool invoke();
            string getTaskName();
    };
}

#endif

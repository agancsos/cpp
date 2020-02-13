#include "amgsetbuildtask.h"

namespace amgbuildtasks {
    AMGSetBuildTask::AMGSetBuildTask(shared_ptr<JsonObject> a) : AMGSetBuildTask() {
        this->configuration = a;
    }

    /**
     * This method tries to generate a new build number
     * @return Build number
     */
    string AMGSetBuildTask::generateBuildNumber() {
        string build = "";
        build = to_string((rand() % 9999) + 1000);
        return build;
    }


    AMGSetBuildTask::AMGSetBuildTask() {
    }

    AMGSetBuildTask::~AMGSetBuildTask() {
    }

    /**
     * This method gathers all the sources based on the build definition
     */
    bool AMGSetBuildTask::invoke() {
		string version = "0.0.0.0";
		if(this->generateBuildNumber() != "") {
        	try {
                string tempVersion = *this->configuration->getKey("Version");
				if (tempVersion!= "") {
					version = tempVersion;
				}
				else {	
					version = this->generateBuildNumber();
				}

        	}
        	catch(exception &e) {
    	       	return false;
        	}
		}
		return true;
    }

	string AMGSetBuildTask::getTaskName() { return "Set build number"; }
}

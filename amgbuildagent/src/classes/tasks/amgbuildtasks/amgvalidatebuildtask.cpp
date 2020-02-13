#include "amgvalidatebuildtask.h"

namespace amgbuildtasks {
    AMGValidateBuildTask::AMGValidateBuildTask() {
    }

	AMGValidateBuildTask::AMGValidateBuildTask(shared_ptr<JsonObject> a) : AMGValidateBuildTask() {
		this->configuration = a;		
	}

    AMGValidateBuildTask::~AMGValidateBuildTask() {
    }

    /**
     * This method checks if the build is valid
     */
    bool AMGValidateBuildTask::invoke() {
        try {
            string requiredKeys[4] = { "ApplicationName", "ApplicationBase", "SourceLocation", "TargetLocation" };
            for(string cursor : requiredKeys) {
                string cursorValue = *this->configuration->getKey(cursor);
                if(cursorValue == "") {
                    return false;
                }
            }
        }
        catch(exception &e) {
            return false;
        }
        return true;
    }

    string AMGValidateBuildTask::getTaskName() { return "Validate build"; }
}

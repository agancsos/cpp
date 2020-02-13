#include "amggathersourcestask.h"

namespace amgbuildtasks {
    AMGGatherSourcesTask::AMGGatherSourcesTask() {
    }

    AMGGatherSourcesTask::~AMGGatherSourcesTask() {
    }

	AMGGatherSourcesTask::AMGGatherSourcesTask(shared_ptr<JsonObject> a) : AMGGatherSourcesTask() {
        this->configuration = a;
    }

    /**
     * This method gathers all the sources based on the build definition
     */
    bool AMGGatherSourcesTask::invoke() {
        try {
            string sourceLocation = *this->configuration->getKey("SourceLocation");
            string targetLocation = *this->configuration->getKey("TargetLocation");
            if(SystemService::directoryExists(sourceLocation)) {
                if(SystemService::directoryExists(targetLocation)) {
                    return SystemService::copyDirectoryContents(sourceLocation,targetLocation);
                }
            }
        }
        catch(exception &e) {
            return false;
        }
        return true;
    }

    string AMGGatherSourcesTask::getTaskName() { return "Gather sources"; }
}

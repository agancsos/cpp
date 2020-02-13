#include "amgbuildtask.h"

namespace amgbuildtasks {

	AMGBuildTask::AMGBuildTask() {
	}

	AMGBuildTask::AMGBuildTask(shared_ptr<JsonObject> configuration) {
		this->configuration = configuration;
	}

	AMGBuildTask::~AMGBuildTask() {
	}

    string AMGBuildTask::getApplicationBase() { 
		return ((string)*this->configuration->getKey("ApplicationBase")); 
	}
}

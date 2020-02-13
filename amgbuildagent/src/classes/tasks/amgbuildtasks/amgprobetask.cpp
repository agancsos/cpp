#include "amgprobetask.h"

namespace amgbuildtasks {
    AMGProbeTask::AMGProbeTask() {
    }

    AMGProbeTask::AMGProbeTask(shared_ptr<JsonObject> a) : AMGProbeTask() {
        this->configuration = a;
    }

    AMGProbeTask::~AMGProbeTask() {
    }

    /**
     * This method probes the application directory for a run script
     */
    bool AMGProbeTask::invoke() {
        try {
			const vector<shared_ptr<FileObject> > objects = SystemService::getChildren(this->basePath, true);
			for(shared_ptr<FileObject> cursor : objects) {
				if(SystemService::isWindows()) {
					if(cursor->getName() == "run.bat") {
						try{
							SystemService::runCommand("cd \"" + cursor->getPath() + "\" && ./" + cursor->getName());
						}
						catch(exception &e) {
						}
					}
				}
				else {
					if(cursor->getName() == "run.sh"){
						try {
							SystemService::runCommand("cd \"" + cursor->getPath() + "\" && ./" + cursor->getName());
						}
						catch(exception &e) {
						}
					}
				}
			}
        }
        catch(exception &e) {
            return false;
        }
        return true;
    }

    string AMGProbeTask::getTaskName() { return "Probing for run script"; }
}

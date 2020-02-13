#include "amgcompiletask.h"

namespace amgbuildtasks {
    AMGCompileTask::AMGCompileTask() {
    }

    AMGCompileTask::AMGCompileTask(shared_ptr<JsonObject> a) : AMGCompileTask() {
        this->configuration = a;
    }

    AMGCompileTask::~AMGCompileTask() {
    }

    /**
     * This method searches for a compile script
     */
    bool AMGCompileTask::invoke() {
        try {
			const vector<shared_ptr<FileObject> > objects = SystemService::getChildren(this->basePath, true);
			for(shared_ptr<FileObject> cursor : objects) {
				if(SystemService::isWindows()) {
					if(cursor->getName() == "compile.bat") {
						try {
							SystemService::runCommand("cd \"" + cursor->getPath() + "\" && ./" + cursor->getName());
						}
						catch(exception &e) {
							
						}
					}
				}
				else {
					if(cursor->getName() == "compile.sh"){
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

    string AMGCompileTask::getTaskName() { return "Compile"; }
}

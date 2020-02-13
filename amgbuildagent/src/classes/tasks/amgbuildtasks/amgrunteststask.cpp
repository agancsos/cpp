#include "amgrunteststask.h"

namespace amgbuildtasks {
	AMGRunTestsTask::AMGRunTestsTask() {
	}

	AMGRunTestsTask::AMGRunTestsTask(string path) {
		this->basePath = path;
	}

    AMGRunTestsTask::AMGRunTestsTask(shared_ptr<JsonObject> a) : AMGRunTestsTask() {
        this->configuration = a;
    }

	AMGRunTestsTask::~AMGRunTestsTask() {
	}

    /**
     * This method runs the Unit Tests for the application
     */
	bool AMGRunTestsTask::invoke() {
		try {
			const vector<shared_ptr<FileObject> > objects = SystemService::getChildren(this->basePath, true);
			for(shared_ptr<FileObject> cursor : objects) {
				if(AMGString(cursor->getName()).contains("unit_tests")) {
					if(SystemService::isWindows()) {
						if(AMGString(cursor->getName()).contains(".bat")) {
							try{
								SystemService::runCommand("cd \"" + cursor->getPath() + "\" && ./" + cursor->getName());
							}
							catch(exception &e) {
								
							}
						}
					}
					else {
						// Run Unit Tests based on extension
						if(AMGString(cursor->getName()).contains(".sh")){
							try {
								SystemService::runCommand("cd \"" + cursor->getPath() + "\" && ./" + cursor->getName());
							}
							catch(exception &e) {
								
							}
						}
						else if(AMGString(cursor->getName()).contains(".pl")){
							try {
								SystemService::runCommand("cd \"" + cursor->getPath() + "\" && perl ./" + cursor->getName());
							}
							catch(exception &e) {
								
							}
						}
						else if(AMGString(cursor->getName()).contains(".py")){
							try {
								SystemService::runCommand("cd \"" + cursor->getPath() + "\" && python ./" + cursor->getName());
							}
							catch(exception &e) {
								
							}
						}
						else if(AMGString(cursor->getName()).contains(".lua")){
							try {
								SystemService::runCommand("cd \"" + cursor->getPath() + "\" && lua ./" + cursor->getName());
							}
							catch(exception &e) {
								
							}
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

	string AMGRunTestsTask::getTaskName() { return "Running Unit Tests"; }
}

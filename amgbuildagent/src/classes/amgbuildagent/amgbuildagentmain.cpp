#include "amgbuildagentmain.h"

namespace amgbuildagent {    
	shared_ptr<AMGBuildAgent> AMGBuildAgent::instance = nullptr;
	
	AMGBuildAgent::AMGBuildAgent() {	
        this->agentBase = "/app";
        this->logfileBase = "/logs";
		this->serverPort = /*48557*/ 4444;
        this->logger = shared_ptr<TraceService>(new TraceService(this->logfileBase + "/" + this->logfileName));
        this->config = shared_ptr<PlainPropertyStore>(new PlainPropertyStore(SystemService::getModulePath() + this->configfileName));
		this->configure();
	}
    
	void AMGBuildAgent::configure() {
		this->readConfiguration();
		this->rolloverLogs();	
	}
    
	const shared_ptr<AMGBuildAgent> AMGBuildAgent::getInstance() {
		if (AMGBuildAgent::instance == nullptr) {
			AMGBuildAgent::instance = shared_ptr<AMGBuildAgent>(new AMGBuildAgent());
		}
		return AMGBuildAgent::instance;
	}

    void AMGBuildAgent::run(string configFile) {
		shared_ptr<AMGBuilder> builder(new AMGBuilder(configFile, this->config));
		if (this->config->getProperty("SAFEMODE") != "1") {
			builder->run();
		}
		else {
			this->logger->traceInformational("SAEMODE is enabled...");
		}
	}

    void AMGBuildAgent::startAgent() {
		this->configure();
		this->logger->traceInformational("Starting Agent...");
		#ifdef __ISWINDOWS__
			AMGAgentSocket<SOCKET> *socket = new AMGAgentSocket<SOCKET>(this->serverPort, "");
			socket->startServer();
		#else
			AMGAgentSocket<int> *socket = new AMGAgentSocket<int>(this->serverPort, "");
			socket->startServer();
		#endif
		this->logger->traceInformational("Agent started...");
	}

    void AMGBuildAgent::setAgentBase(string a) {
		this->agentBase = a;
        this->logger = shared_ptr<TraceService>(new TraceService(this->logfileBase + "/" + this->logfileName));
        this->config = shared_ptr<PlainPropertyStore>(new PlainPropertyStore(this->agentBase + "/" + this->configfileName));
	}
	
    string AMGBuildAgent::getAgentBase() {
		return this->agentBase;
	}


	/**
     * This method rolls over logs so that the buffer doesn't get too large
     */
    void AMGBuildAgent::rolloverLogs() {
        if(SystemService::directoryExists(this->logfileBase)) {
            DIR *directory;
            struct dirent *entry;
            if((directory = opendir(this->logfileBase.c_str())) != NULL){
                while((entry = readdir(directory)) != NULL) {
                    if(SystemService::fileExists(this->logfileBase + "/" + string(entry->d_name))) {
                        string fileWithoutExt = AMGString(string(entry->d_name)).split(".")[0];
                        string fileWithoutName = AMGString(fileWithoutExt).replaceAll(AMGString(this->logfileName).split(".")[0], "").get();

                        // Latest log file becomes the first archive
                        if(fileWithoutName == "") {
                            rename((this->logfileBase + "/" + string(entry->d_name)).c_str(),
                                (this->logfileBase + "/" + (AMGString(this->logfileName).split(".")[0] + "1" + AMGString(this->logfileName).split(".")[1])).c_str());
                        }
                        else {
                            // Check if logfile has a number
                            if(SystemService::validateInput(fileWithoutName, InputTypes::NUMBER)) {
                                // Increase the archive number
                                string newArchive = to_string(stoi(fileWithoutName) + 1);
                                rename((this->logfileBase + "/" + string(entry->d_name)).c_str(),
                                    (this->logfileBase + "/" + AMGString(this->logfileName).split(".")[0] +
                                        newArchive + AMGString(this->logfileName).split(".")[1]).c_str());
                            }
                        }
                    }
                }
                closedir(directory);
            }
        }
    }

    /**
     * This method reads in the configuration file
     */
    void AMGBuildAgent::readConfiguration() {
        if(this->config->getProperty("Agent.LogfileBase") != "") {
            this->logfileBase = this->config->getProperty("Agent.LogfileBase");
            this->logger = shared_ptr<TraceService>(new TraceService(this->logfileBase + "/" + this->logfileName));
        }

        if(this->config->getProperty("Agent.TraceLevel") != "") {
            if(SystemService::validateInput(this->config->getProperty("Agent.TraceLevel"), InputTypes::NUMBER)) {
                this->logger->setTraceLevel((TraceLevel)stoi(this->config->getProperty("Agent.TraceLevel")));
            }
        }
    }
}


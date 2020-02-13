#include "traceservice.h"

namespace amgcommon {
    namespace system {
        void TraceService::trace(string message, bool print) {
            if(print)
                cout << message << endl;
            try {
                string traceText = "";
                if(SystemService::fileExists(logFilePath)){
                    traceText = SystemService::readFile(logFilePath);
                    traceText += "\n";
                }
                time_t now = time(0);
                traceText += AMGString(string(ctime(&now))).strip().get();
                traceText += (" " + message);
                SystemService::writeFile(logFilePath, traceText);
            }
            catch(exception &e) {

            }
        }
        
        TraceService::TraceService(string path, TraceLevel level) {
            this->logFilePath = path;
            this->level = level;
        }

        TraceService::~TraceService() {

        }

        const string TraceLevelHelper::getTraceLevelName(TraceLevel a) {
            switch(a) {
                case (TraceLevel::NONE):
                    return "None";
                case (TraceLevel::DEBUG):
                    return "Debug";
                case (TraceLevel::ERROR):
                    return "Error";
                case (TraceLevel::VERBOSE):
                    return "Verbose";
                case (TraceLevel::INFORMATIONAL):
                    return "Informational";
                case (TraceLevel::WARNING):
                    return "Warning";
                default:
                    return "";
            }
        }

        void TraceService::traceInformational(string message) {
            if((int)level > 2)
                trace( "INFO | " + message, false);
        }

        void TraceService::traceWarning(string message) {
            if((int)level > 1)
                trace( "WARN | " + message, false);
        }

        void TraceService::traceError(string message) {
            if((int)level > 0)
                trace( "ERROR | " + message, false);
        }

        void TraceService::traceVerbose(string message) {
            if((int)level > 3)
                trace( "VERB | " + message, true);
        }

        void TraceService::traceDebug(string message) {
            trace( "INFO | " + message, true);
        }

        void TraceService::setLogFilePath(string a) { this->logFilePath = a; }
        void TraceService::setTraceLevel(TraceLevel a) { this->level = a; }
        string TraceService::getLogFilePath() { return this->logFilePath; }
        TraceLevel TraceService::getTraceLevel() { return this->level; }
    }
}

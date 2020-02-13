#ifndef __TRACER_SERVICE_H_INCLUDED__
#define __TRACER_SERVICE_H_INCLUDED__
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <ctime>
#include <vector>
#include "systemservice.h"
#include "../string.h"
#undef ERROR
using namespace std;

namespace amgcommon {
    namespace system {
        enum class TraceLevel {
            NONE = 0,
            WARNING = 1,
            ERROR = 2,
            INFORMATIONAL = 3,
            VERBOSE = 4,
            DEBUG = 5
        };

        class TraceLevelHelper {
            public:
                const static string getTraceLevelName(TraceLevel a);
        };

        class TraceService {
            private:
                string logFilePath;
                TraceLevel level;
                void trace(string message, bool print = false);
            public:
                TraceService(string path = "", TraceLevel level = TraceLevel::INFORMATIONAL);
                ~TraceService();
                void traceInformational(string message);
                void traceWarning(string message);
                void traceError(string message);
                void traceVerbose(string message);
                void traceDebug(string message);
                void setLogFilePath(string a);
                void setTraceLevel(TraceLevel a);
                string getLogFilePath();
                TraceLevel getTraceLevel();
        };
    }
}
#endif

#include "amgtracer.h"

namespace amgcommon{
    /**
     * This is the default constructor
     * @precondition  (There is a need to log information)
     * @postcondition (A new AMGTracer object is created)
     */
    AMGTracer::AMGTracer(){
        this->outputFile = "";
        this->miscLevel = 1;
        this->systemLevel = 1;
        this->databaseLevel = 1;
        this->securityLevel = 1;
        this->applicationLevel = 1;
        this->defaultLevel = 1;
        this->configuration = shared_ptr<AMGConfiguration>(new AMGConfiguration());
		this->configure();
    }

    /**
     * This is the common constructor
     * @param a Full path to the output file
     * @precondition  (There is a need to log information)
     * @postcondition (A new AMGTracer object is created)
     */
    AMGTracer::AMGTracer(string a) : AMGTracer(){
        this->outputFile = a;
		this->configure();
    }

    string AMGTracer::getName(TRACE_CATEGORY a) {
		switch(a) {
			case TRACE_CATEGORY::APPLICATION:
				return "Application";
			case TRACE_CATEGORY::SYSTEM:
				return "System";
			case TRACE_CATEGORY::SECURITY:
				return "Security";
			case TRACE_CATEGORY::MISC:
				return "MISC";
			case TRACE_CATEGORY::NONE:
				return "None";
			case TRACE_CATEGORY::DATABASE:
				return "Database";
		}
	}

    /**
     * This is the common constructor
     * @param a Full path to the output file
	 * @param b Configuration
     * @precondition  (There is a need to log information)
     * @postcondition (A new AMGTracer object is created)
     */
    AMGTracer::AMGTracer(string a, shared_ptr<AMGConfiguration> b) : AMGTracer(a){
        this->configuration = b;
		this->configure();
    }

    void AMGTracer::configure() {
        this->applicationLevel = (configuration->lookupKey("TraceLevel.Application") != "" ? stoi(configuration->lookupKey("TraceLevel.Application")) : this->applicationLevel);
        this->databaseLevel = (configuration->lookupKey("TraceLevel.Database") != "" ? stoi(configuration->lookupKey("TraceLevel.Database")) : this->databaseLevel);
        this->systemLevel = (configuration->lookupKey("TraceLevel.System") != "" ? stoi(configuration->lookupKey("TraceLevel.System")) : this->systemLevel);
        this->securityLevel = (configuration->lookupKey("TraceLevel.security") != "" ? stoi(configuration->lookupKey("TraceLevel.Security")) : this->securityLevel);
        this->miscLevel = (configuration->lookupKey("TraceLevel.MISC") != "" ? stoi(configuration->lookupKey("TraceLevel.MISC")) : this->miscLevel);
	}

    bool AMGTracer::shouldAudit(TRACE_CATEGORY category, int level) {
        switch(category) {
            case TRACE_CATEGORY::APPLICATION:
                if(level <= this->applicationLevel){
                    return true;
                }
            case TRACE_CATEGORY::SECURITY:
                if(level <= this->securityLevel) {
                    return true;
                }
            case TRACE_CATEGORY::SYSTEM:
                if(level <= this->systemLevel){
                    return true;
                }
            case TRACE_CATEGORY::DATABASE:
                if(level <= this->databaseLevel) {
                    return true;
                }
            case TRACE_CATEGORY::MISC:
                if(level <= this->applicationLevel) {
                    return true;
                }
            default:
                if(level <= this->defaultLevel) {
                    return true;
                }
        }
        return false;
	}


    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGTracer::~AMGTracer(){
    }

    /**
     * This method sets the value for the output file
     * @param a Full path to the output file
     * @precondition  (The AMGTracer object exists)
     * @postcondition (The value for the output file was set)
     */
    void AMGTracer::setOutputFile(string a){
        outputFile = a;
    }

    void AMGTracer::trace(int level, TRACE_CATEGORY category, string a, bool print) {
		if(this->shouldAudit(category, level)) {
			this->trace((AMGTracer::getName(category) + "\t" + to_string(level) + "\t" + a), print);
		}
	}

    /**
     * This method logs data to an output file
     * @param a Value to b appended in th file
     * @param print Option to print details to the console
     * @precondition  (An output file must be accessible)
     * @postcondition (The data was appended to the output file)
     */
    void AMGTracer::trace(string a, bool print){
        if(print){
            cout << a << endl;
        }
        try{
            string traceText = "";
            if(AMGSystem().fileExists(outputFile)){
                traceText = AMGSystem(outputFile).readFile();
                traceText += "\n";
            }
            time_t now = time(0);
            traceText += AMGString(string(ctime(&now))).strip();
            traceText += (" " + a);
            AMGSystem("",outputFile).writeFile(traceText);
        }
        catch(exception &e){
        }
    }
}

# README                                    
## ABOUT                               
* NAME       : AMGBuildAgent
* Author     : Abel Gancsos
* Version    : v. 1.0.0

## SYNOPSIS                 
This utility is meant to build and test applications as long as the dependencies are installed on the system.  The basic dependencies that are required on any build agent include:
* GCC
* G++
* CMAKE
* Valgrind (Linux)

If any of these are missing, the utility can be used to install missing dependencies using one of the flags below.  The name must be a valid package otherwise the utility will naturally fail with the system.

During the build, the Agent first checks if there are any "run scripts" (run.bat | run.sh) available on the root of the application.  These scripts must include full instructions to compile and any additional tests that should be ran.  If any of these files exist, it validates if the script is valid for the current operating system and if the script is valid it will execute it on the system level.  If none of the scripts exist, the Agent then attempts to probe the directory for necessary  scripts to compile and to run Unit Tests.  If the Agent find any script with the proper name (compile or unit_test), it will attempt to find which language it was written in.  Currently, the Agent only supports the below script languages, but would be added to in the future.  The Agent will then execute the scripts as-is; however, the plan for future releases includes building each application without the required scripts.  This is to say that the Agent should be able to detect any files that require compilation and then use the proper command-line compiler to build the application.

* Perl
* Batch
* Bash
* Python

## Assumptions
* There is a fundamental need to constantly test ongoing applications.
* Linux, Unix, and non-Windows are mostly used for application designs.
* The term application refers to any piece of software that is meant to run on the system level.
* Specific instructions for building and running will be provided in optional scripts
* The run script will be used to perform all operations of the build
* The compile script will be used to perform all compilation operations of the build
* Any unit test scripts will be used to perform all operations of a test.                    

## Implemenation description

## FLAGS

## Configuration
The following keys can be used in the amgagent.conf file.  Note that this file must be in the directory where the binary is located.


_________________________________________________________________________________________________________________________________________________________________________
| Name                      | Description                                        | Valid Values                                      | Default Value                    |
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
| Agent.Localfilebase       | Base directory for the agent                       | Full path to the log directory                   | The agent base                    |
| Agent.TraceLevel          | Level of tracing for the agent component           | 0-4                                              | 1                                 |
| Agent.ManualBuild         | Enable manual build                                | 1 or 0                                           | 0                                 |
| Agent.UnitTets            | Enable Unit Tests                                  | 1 or 0                                           | 0                                 |
| Agent.BypassDispatch      | Run the Agent, but not the payload                 | 1 or 0                                           | 0                                 |
| Agent.ServicePort         | Port to use for the service                        |                                                  | 3362                              |
_________________________________________________________________________________________________________________________________________________________________________

## Build definition
_________________________________________________________________________________________________________________________________________________________________________
| Name                      | Description                                        | Valid Values                                      | Default Value                    |
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
| TraceLevel                | Level of tracing for the builds                    | 0-4                                               |1                                 |      
| ApplicationBase           | Base path for the application                      |                                                   |                                  |      
| ApplicationName           | Name of the application                            |                                                   |                                  |      
| SourceLocation            | Full path for the source code                      |                                                   |                                  |      
| TargetLocation            | Full path for the target                           |                                                   |                                  |      
_________________________________________________________________________________________________________________________________________________________________________


### Trace Levels
* 0 : None
* 1 : Errors
* 2 : Warnings
* 3 : Informational
* 4 : Verbose

## PREREQUISITES
### G++ compiler
#### Windows
Should come with Visual Studio 2017 in the form of devenv, but you can also try using Bloodshed Dev C++
#### Mac
Should come with XCode command-line tools
#### Linux
Should be installable using internal package installer
### CMake
#### Windows
Should come with Visual Studio 2017 
#### Mac
Can be installed from https://cmake.org/download/
#### Linux
Can be installed from https://cmake.org/download/
## Build
This can be built either using one of the run scripts or manually using the following instructions

#ifndef __AMGGENERATORSR_H_INCLUDED__
#define __AMGGENERATORSR_H_INCLUDED__

#include <iostream>
#include <string>
using namespace std;

namespace amggenerator {
	class SR {
		public:
			static string cppReadMe(){
				return "# README\n"
					"## ABOUT\n"
					"* NAME       : \n"
					"* Author     : \n"
					"* Version    : \n\n"
					"## SYNOPSIS \n\n"
					"## Assumptions \n\n"
					"## Implemenation description\n\n"
					"## FLAGS \n\n"
					"## Configuration \n\n"
					"## PREREQUISITES\n"
					"### G++ compiler\n"
					"#### Windows\n"
					"Should come with Visual Studio 2017 in the form of devenv, but you can also try using Bloodshed Dev C++ \n"
					"#### Mac\n"
					"Should come with XCode command-line tools\n"
					"#### Linux\n"
					"Should be installable using internal package installer\n"
					"### CMake\n"
					"#### Windows\n"
					"Should come with Visual Studio 2017\n"
					"#### Mac\n"
					"Can be installed from https://cmake.org/download/\n"
					"#### Linux\n"
					"Can be installed from https://cmake.org/download/\n"
					"## Build \n"
					"This can be built either using one of the run scripts or manually using the following instructions\n";
			}

			static string stdReadMe() {
				return "# README\n"
					"## ABOUT\n"
					"* NAME       : \n"
					"* Author     : \n"
					"* Version    : \n\n"
					"## SYNOPSIS \n\n"
					"## Assumptions \n\n"
					"## Implemenation description\n\n"
					"## FLAGS \n\n"
					"## Configuration \n\n"
					"## PREREQUISITES\n";
			}
			
			static string cmake(string name) {
				return "cmake_minimum_required(VERSION 3.10)\n"
					"project(" + name + ")\n"    
					"file(GLOB_RECURSE sources src/main.cpp src/classes/*.cpp src/classes/*.h)\n"
					"file(GLOB_RECURSE data resources/*)\n"
					"list(FILTER sources EXCLUDE REGEX \"src/classes/\\._.\\\")\n"
					"add_executable(" + name + " ${sources} ${data})\n"
					"target_compile_options(" + name + " PUBLIC -std=c++11)\n"
					"target_include_directories(" + name + " PUBLIC src)\n"
					"file(COPY ${data} DESTINATION resources)\n"
					"install(TARGETS " + name + " DESTINATION bin)\n"
					"install(DIRECTORY resources DESTINATION bin)\n"
					"set(CPACK_PACKAGE_NAME \"" + name + "\")\n"
					"set(CPACK_PACKAGE_VERSION \"1.0.0\")\n"
					"set(CPACK_MONOLITHIC_INSTALL 1)\n"
					"include(CPack)";
			}

			static string cppMain(string name) {
				return "#include <iostream>\n"
					"#include <stdio.h>\n"
					"#include <string>\n"
					"#include <vector>\n"
					"#include <memory>\n"
					"using namespace std;\n"
					"\n"
					"#define __PRODUCT_AUTHOR_STRING__  \"\"\n"
					"#define __PRODUCT_NAME_STRING__    \"" + name + "\"\n"
					"#define __PRODUCT_VERSION_STRING__ \"1.0.0\"\n"
					"\n"
					"void helpMenu() {\n"
    				"	printf(\"* Name   : %s\\n\", __PRODUCT_NAME_STRING__);\n"
    				"	printf(\"* Author : %s\\n\", __PRODUCT_AUTHOR_STRING__);\n"
    				"	printf(\"* Version: v. %s \\n\", __PRODUCT_VERSION_STRING__);\n"
    				"	printf(\"* Flags: \\n\");\n"
					"}\n"
					"\n"
					"int main(int argc, char **argv) {\n"
    				"	bool help = false;\n"
    				"	bool getVersion = false;\n"
    				"\n"
					"	if((argc - 1) > 0) {\n"
        			"		for(int i = 0; i < argc; i++) {\n"
            		"			if(string(argv[i]) == \"-h\") {\n"
                	"				help = true;\n"
            		"			}\n"
            		"			else if(string(argv[i]) == \"-version\") {\n"
                	"				getVersion = true;\n"
            		"			}\n"
        			"		}\n"
    				"	}\n"
					"\n"
    				"	if(help) {\n"
        			"		helpMenu();\n"
    				"	}\n"
    				"	else if(getVersion) {\n"
        			"		printf(\"" + name + " Version: v.%s \\n\", __PRODUCT_VERSION_STRING__);\n"
    				"	}\n"
    				"	else {\n"
    				"	}\n\n"

    				"	return 0;\n"
					"}";
			
			}

			static string cppCompileBat(string name) {
				return "@echo off\n"
					"set APP_ROOT=\".\"\n"
					"set VS_PATH=\"C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\Common7\\IDE\"\n"
					"set CMAKE_PATH=%VS_PATH%\"\\CommonExtensions\\Microsoft\\CMake\\CMake\\bin\"\n"
					"set TARGET_NAME=\"" + name + "\"\n"
					"set PROJECT_NAME=\"" + name + "\"\n"
					"set DEBUG=0\n"
					"\n"
					"rmdir /S /Q /S %APP_ROOT%\\..\\bin\\*\n"
					"cd %APP_ROOT%\\..\\bin && %CMAKE_PATH%\\cmake ..\\\"\n"
					"cd %APP_ROOT%\\..\\bin & %VS_PATH%\\devenv.exe %PROJECT_NAME%.sln /build\n"
					"if %DEBUG% <> \"1\" (\n"
    				"	rmdir /S /Q %APP_ROOT%\\..\\bin\\amgvending.dir\n"
    				"	rmdir /S /Q %APP_ROOT%\\..\\bin\\CMakeFiles\n"
    				"	rmdir /S /Q %APP_ROOT%\\..\\bin\\Win32\n"
    				"	rmdir /S /Q %APP_ROOT%\\..\\bin\\.vs\n"
    				"	del /S /Q %APP_ROOT%\\..\\bin\\*.cmake\n"
    				"	del /S /Q %APP_ROOT%\\..\\bin\\*.sln\n"
    				"	del /S /Q %APP_ROOT%\\..\\bin\\CMake*.txt\n"
    				"	del /S /Q %APP_ROOT%\\..\\bin\\*.vcxproj*\n"
    				"	xcopy /S /Q %APP_ROOT%\\..\\bin\\Debug\\%TARGET_NAME%.exe %APP_ROOT%\\..\\bin\"\n"
    				"	rmdir /S /Q %APP_ROOT%\\..\\bin\\Debug\n"
					")\n";
			}

			static string cppCompileBash(string name) {
				return "!#/bin/bash\n"
					"APP_ROOT2=$(dirname \"$0\")\n"
					"CMAKE_PATH=\"\"\n"
					"DEBUG=0\n"
					"rm -fR $APP_ROOT2/../bin/*\n"
					"cd $APP_ROOT2/../bin && $CMAKE_PATH/cmake ../\n"
					"	cd $APP_ROOT2/../bin && make\n"
					"\n"
					"if [ $DEBUG -eq 1 ]; then\n"
					"	rm $APP_ROOT2/../bin/*.cmake\n"
					"	rm -fR $APP_ROOT2/../bin/CMakeFiles\n"
					"	rm $APP_ROOT2/../bin/Makefile\n"
					"	rm $APP_ROOT2/../bin/CMake*.txt\n"
					"fi";
			}

			static string javaCompileBat(string name) {
				return "";
			}

			static string javaCompileBash(string name) {
				return "";
			}
	};
}
#endif

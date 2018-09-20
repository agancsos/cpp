cmake_minimum_required(VERSION 3.10)
project()
file(GLOB_RECURSE sources src/main.cpp src/classes/*.cpp src/classes/*.h)
file(GLOB_RECURSE data resources/*)
list(FILTER sources EXCLUDE REGEX "src/classes/\._.\")
add_executable( ${sources} ${data})
target_compile_options( PUBLIC -std=c++11)
target_include_directories( PUBLIC src)
file(COPY ${data} DESTINATION resources)
install(TARGETS  DESTINATION bin)
install(DIRECTORY resources DESTINATION bin)
set(CPACK_PACKAGE_NAME "")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_MONOLITHIC_INSTALL 1)
include(CPack)
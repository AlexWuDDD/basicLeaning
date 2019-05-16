# CMakeList.txt : CMake project for CppConcurrency, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

add_definitions(-std=c++11)

# Add source to this project's executable.
add_executable (testConcurrency main.cpp)

# TODO: Add tests and install targets if needed.

target_link_libraries(testConcurrency pthread)

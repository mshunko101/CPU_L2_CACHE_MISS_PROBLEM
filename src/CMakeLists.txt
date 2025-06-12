cmake_minimum_required(VERSION 3.14)

project(bbs_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES ./*.cpp ./*.h )
add_executable(bbs_tests ${SOURCES} bbs_tests.cpp)



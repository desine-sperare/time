cmake_minimum_required(VERSION 3.5.0)
project(time VERSION 1.0.0 LANGUAGES CXX)

#include(CTest)
#enable_testing()
include_directories(./include)

set(SOURCE_LIB ./src/time.cpp)

add_library(time ${SOURCE_LIB})

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)

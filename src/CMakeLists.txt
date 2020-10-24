cmake_minimum_required(VERSION 2.8.12)
project(fid)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

include(ExternalProject)

ExternalProject_Add(oatpp
    GIT_REPOSITORY https://github.com/oatpp/oatpp
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${LIB_DIR})

add_executable(test1 ${PROJECT_SOURCE_DIR}/app/test1.cpp)
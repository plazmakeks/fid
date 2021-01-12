cmake_minimum_required(VERSION 3.16)
project(oatpp-test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_PROJECT_VERSION_MAJOR 0)
set(CMAKE_PROJECT_VERSION_MINOR 1)
set(CMAKE_PROJECT_VERSION_PATCH 0)

add_compile_options(-Wall -Wextra -pedantic)

add_subdirectory(src/api)
add_subdirectory(src/apps)
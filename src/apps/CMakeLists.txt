set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

add_executable(rest-api rest-api.cpp)

link_directories(/usr/local/lib/oatpp-1.2.0)

target_link_libraries(rest-api fid-rest)
target_include_directories(rest-api PUBLIC /usr/local/include/oatpp-1.2.0)
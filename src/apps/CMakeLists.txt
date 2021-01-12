set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

add_executable(rest-api rest-api.cpp)

target_link_libraries(rest-api oatpp-test-rest)
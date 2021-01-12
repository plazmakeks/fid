file(GLOB_RECURSE SRCS 
    src/*.h
    src/*.cpp
    include/*.h)

find_package(oatpp 1.2.5 REQUIRED)
find_package(oatpp-swagger 1.2.5 REQUIRED)

message(STATUS "---oatpp---")
message(STATUS "oatpp found " ${oatpp_FOUND})
message(STATUS "oatpp include dirs " ${oatpp_INCLUDE_DIRS})
message(STATUS "oatpp libraries " ${oatpp_LIBRARIES})
message(STATUS "oatpp definitions " ${oatpp_DEFINITIONS})
message(STATUS "oatpp-swagger---")
message(STATUS "oatpp-swagger found " ${oatpp-swagger_FOUND})
message(STATUS "oatpp include dirs " ${oatpp-swagger_INCLUDE_DIRS})
message(STATUS "oatpp libraries " ${oatpp-swagger_LIBRARIES})
message(STATUS "oatpp definitions " ${oatpp-swagger_DEFINITIONS})


add_definitions(-DOATPP_SWAGGER_RES_PATH="${OATPP_BASE_DIR}/bin/oatpp-swagger/res")

add_library(oatpp-test-rest ${SRCS})
target_link_libraries(oatpp-test-rest PUBLIC oatpp::oatpp oatpp::oatpp-swagger)
set_target_properties(oatpp-test-rest PROPERTIES LINKER_LANGUAGE CXX)

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR}/include " " ${oatpp_INCLUDE_DIRS} " " ${oatpp-swagger_INCLUDE_DIRS})
message(STATUS ${oatpp_LIBRARIES} " " ${oatpp-swagger_LIBRARIES})

target_include_directories(oatpp-test-rest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${oatpp_INCLUDE_DIRS} ${oatpp-swagger_INCLUDE_DIRS})
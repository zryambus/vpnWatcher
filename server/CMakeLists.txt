cmake_minimum_required(VERSION 2.8)

project(server)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES src/*.cpp)

include_directories(../common ${CMAKE_CURRENT_BINARY_DIR}/common)

include_directories(../shared/include ${CMAKE_CURRENT_BINARY_DIR}/shared)

add_subdirectory(../shared/external/pistache ${CMAKE_CURRENT_BINARY_DIR}/shared)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} net_static)

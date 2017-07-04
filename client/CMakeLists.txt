project(client)

set(CMAKE_CXX_STANDARD 11)

include_directories(../common/include ${CMAKE_CURRENT_BINARY_DIR}/common)
include_directories(../shared/include ${CMAKE_CURRENT_BINARY_DIR}/shared)

add_subdirectory(../common ${CMAKE_CURRENT_BINARY_DIR}/common)

add_executable(${PROJECT_NAME} src/main.cpp src/main.cpp)
target_link_libraries(${PROJECT_NAME} pistache common)
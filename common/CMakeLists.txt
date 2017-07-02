set(CMAKE_CXX_STANDARD 11)

add_subdirectory(../shared/external/cryptopp ${CMAKE_CURRENT_BINARY_DIR}/cryptopp)

include_directories(../shared/include ${CMAKE_CURRENT_BINARY_DIR}/shared)

file(GLOB COMMON_HEADERS include/*.h)
file(GLOB COMMON_SOURCES src/*.cpp)

add_library(common ${COMMON_HEADERS} ${COMMON_SOURCES})
target_link_libraries(common cryptopp-static)

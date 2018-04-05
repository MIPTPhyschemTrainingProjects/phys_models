cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -fopenmp")
set(CMAKE_INCLUDE_PATH  ${PROJECT_SOURCE_DIR}/src)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(TESTS_DIR tests)

add_subdirectory(${CMAKE_INCLUDE_PATH}/cpp)
add_subdirectory(${TESTS_DIR}/cpp)
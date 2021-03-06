cmake_minimum_required(VERSION 2.9)

####################################
# TAKEN FROM GOOGLETEST DOCUMENTAION
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()
####################################

project(phys_models)

set(PVERSION 0.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -fopenmp")
set(SOURCES_DIR src)
set(TESTS_DIR tests)

include_directories(${SOURCES_DIR}/cpp)
include_directories(${TESTS_DIR}/cpp)

project(MaterialDot-lib)
    add_library(MaterialDot-lib ${SOURCES_DIR}/cpp/MaterialDot.cpp)
    target_link_libraries(MaterialDot-lib Vector-lib)

project(MaterialDot-test)
    add_executable(MaterialDot-test ${TESTS_DIR}/cpp/MaterialDot_TEST.cpp)
    target_link_libraries(MaterialDot-test MaterialDot-lib gtest_main Vector-lib)
    add_test(NAME MaterialDot-tests COMMAND MaterialDot-test)

project(PhysicsModel)
    add_library(PhysicsModel-lib ${SOURCES_DIR}/cpp/PhysicsModel.hpp)
    set_target_properties(PhysicsModel-lib PROPERTIES LINKER_LANGUAGE CXX)

project(Vector-lib)
    add_library(Vector-lib ${SOURCES_DIR}/cpp/Vector.cpp)

project(Vector-test)
    add_executable(Vector-test ${TESTS_DIR}/cpp/Vector_TEST.cpp)
    target_link_libraries(Vector-test Vector-lib gtest_main)
    add_test(NAME Vector-tests COMMAND Vector-test)

project(SpringModel)
    add_executable(SpringModel ${SOURCES_DIR}/cpp/models/SpringModel.cpp)
    target_link_libraries(SpringModel PhysicsModel-lib MaterialDot-lib)

project(TwoStarsModel)
    add_executable(TwoStarsModel ${SOURCES_DIR}/cpp/models/TwoStarsModel.cpp)
    target_link_libraries(TwoStarsModel PhysicsModel-lib MaterialDot-lib)
    
project(Leonardo_Jonas)
    add_executable(Leonardo_Jonas ${SOURCES_DIR}/cpp/models/Leonardo_Jonas.cpp)
    target_link_libraries(Leonardo_Jonas PhysicsModel-lib MaterialDot-lib)

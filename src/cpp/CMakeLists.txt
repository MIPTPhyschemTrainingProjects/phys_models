set(PVERSION 0.4)

project(MaterialDot-lib)
add_library(MaterialDot-lib ${CMAKE_INCLUDE_PATH}/cpp/MaterialDot.cpp)
target_link_libraries(MaterialDot-lib Vector-lib)

project(PhysicsModel)
add_library(PhysicsModel-lib ${CMAKE_INCLUDE_PATH}/cpp/PhysicsModel.hpp)
set_target_properties(PhysicsModel-lib PROPERTIES LINKER_LANGUAGE CXX)

project(Vector-lib)
add_library(Vector-lib ${CMAKE_INCLUDE_PATH}/cpp/Vector.cpp)

project(SpringModel)
add_executable(SpringModel ${CMAKE_INCLUDE_PATH}/cpp/models/SpringModel.cpp)
target_link_libraries(SpringModel PhysicsModel-lib MaterialDot-lib)

project(TwoStarsModel)
add_executable(TwoStarsModel ${CMAKE_INCLUDE_PATH}/cpp/models/TwoStarsModel.cpp)
target_link_libraries(TwoStarsModel PhysicsModel-lib MaterialDot-lib)

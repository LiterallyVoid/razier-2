cmake_minimum_required(VERSION 2.8)

project(razier-2)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -pg")

file(GLOB SOURCE_FILES src/*.cpp)

add_subdirectory(deps/glfw)
include_directories(deps/glfw/include)

find_package(Box2D REQUIRED)
include_directories(${Box2D_INCLUDE_DIRS})

add_executable(razier-2
  ${SOURCE_FILES})

target_link_libraries(razier-2 GL glfw png Box2D ${GLFW_LIBRARIES} ${Box2D_LIBRARIES})

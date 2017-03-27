cmake_minimum_required(VERSION 3.6)

project(conduits VERSION 1.0.0 LANGUAGES CXX)

set(RELEASE_PATH "${CMAKE_CURRENT_BINARY_DIR}/lib" CACHE STRING "Library destination")

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${RELEASE_PATH})
set(CMAKE_THREAD_PREFER_PTHREAD)
set(EXECUTABLE_OUTPUT_PATH build)

# External dependency information
set(EXTERNAL_LIBS ${CMAKE_SOURCE_DIR}/external/lib)
set(EXTERNAL_INCLUDE ${CMAKE_SOURCE_DIR}/external/include)

# Find source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Include header files
set(CONDUITS_INCLUDE ${CMAKE_SOURCE_DIR}/src)
include_directories(${CONDUITS_INCLUDE})

# Create shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC")

enable_testing()

add_subdirectory(test/util)

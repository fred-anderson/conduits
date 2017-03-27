cmake_minimum_required(VERSION 3.6)
project(util LANGUAGES CXX)

file(GLOB_RECURSE UTIL_TEST_SRCS cpp *.cpp)

include_directories(${CONDUITS_INCLUDE} ${EXTERNAL_INCLUDE})

find_package(Threads REQUIRED)
link_directories(${EXTERNAL_LIB})

add_executable(${PROJECT_NAME} ${UTIL_TEST_SRCS})
target_link_libraries(${PROJECT_NAME} conduits Threads::Threads
                      ${EXTERNAL_LIBS}/libgtest.a ${EXTERNAL_LIBS}/libgmock.a)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME} "--gtest_output=xml:test_output.xml")

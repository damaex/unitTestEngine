cmake_minimum_required(VERSION 2.6.4)
project(unitTestEngine)

set(CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()

add_subdirectory(${PROJECT_SOURCE_DIR}/engine)
add_subdirectory(${PROJECT_SOURCE_DIR}/testLib)
add_subdirectory(${PROJECT_SOURCE_DIR}/tests)

add_test(unit ${PROJECT_BINARY_DIR}/tests/Tests)
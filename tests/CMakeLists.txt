
set(TEST_SOURCES

        ${PROJECT_SOURCE_DIR}/tests/engineTest.cpp
        ${PROJECT_SOURCE_DIR}/tests/libraryTest.cpp)

message(STATUS ${UNITTESTENGINE_LINK_DIRECTORY})
message(STATUS ${UNITTESTENGINE_INCLUDE_DIR})
link_directories(${UNITTESTENGINE_LINK_DIRECTORY})

include_directories(
        ${UNITTESTENGINE_INCLUDE_DIR}
        ${PROJECT_SOURCE_DIR}/testLib
)

if (MSVC)
    add_library(
        Tests SHARED
        ${TEST_SOURCES}
    )
else (MSVC)
    if(CMAKE_GENERATOR MATCHES "Xcode")
        find_package(XCTest REQUIRED)
        xctest_add_bundle(Tests testLib
            ${TEST_SOURCES})
        target_include_directories(Tests PRIVATE ${UNITTESTENGINE_INCLUDE_DIR})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -x objective-c++")
    else(CMAKE_GENERATOR MATCHES "Xcode")
        add_executable(
            Tests
            ${TEST_SOURCES}
        )
    endif(CMAKE_GENERATOR MATCHES "Xcode")
endif (MSVC)

if (NOT MSVC)
    if(CMAKE_GENERATOR MATCHES "Xcode")
        xctest_add_test(XCTest.testLib Tests)
    else(CMAKE_GENERATOR MATCHES "Xcode")
        target_compile_definitions(Tests PRIVATE GTEST=1)
        add_dependencies(Tests googletest)
    endif(CMAKE_GENERATOR MATCHES "Xcode")
endif (NOT MSVC)

if(NOT CMAKE_GENERATOR MATCHES "Xcode")
    target_link_libraries(
        Tests
        ${UNITTESTENGINE_LIBRARYS}
        testLib
    )
endif (NOT CMAKE_GENERATOR MATCHES "Xcode")

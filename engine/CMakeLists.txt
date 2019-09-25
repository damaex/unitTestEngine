set (UNITTESTENGINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
find_package (Threads)

if (MSVC)
    if ("$ENV{VCINSTALLDIR}" STREQUAL "")
        string(REGEX REPLACE "bin.*$" "" VCINSTALLDIR "${CMAKE_C_COMPILER}")
        message(STATUS "Guessed MSVC directory: ${VCINSTALLDIR}")
    else ("$ENV{VCINSTALLDIR}" STREQUAL "")
        file(TO_CMAKE_PATH "$ENV{VCINSTALLDIR}" VCINSTALLDIR)
        message(STATUS "Using VCINSTALLDIR: ${VCINSTALLDIR}")
    endif ("$ENV{VCINSTALLDIR}" STREQUAL "")

    set(UNITTESTENGINE_LINK_DIRECTORY ${VCINSTALLDIR}UnitTest/lib PARENT_SCOPE)
    set(UNITTESTENGINE_INCLUDE_DIR ${UNITTESTENGINE_INCLUDE_DIR} ${VCINSTALLDIR}UnitTest/include PARENT_SCOPE)
else (MSVC)
    if(CMAKE_GENERATOR MATCHES "Xcode")
        find_package(XCTest REQUIRED)
        set(UNITTESTENGINE_INCLUDE_DIR ${UNITTESTENGINE_INCLUDE_DIR} PARENT_SCOPE)
    else(CMAKE_GENERATOR MATCHES "Xcode")
        set(GOOGLETEST_ROOT engine/googletest/googletest CACHE STRING "Google Test source root")

        include_directories(
                ${CMAKE_CURRENT_SOURCE_DIR}/../${GOOGLETEST_ROOT}
                ${CMAKE_CURRENT_SOURCE_DIR}/../${GOOGLETEST_ROOT}/include
        )

        set(
                GOOGLETEST_SOURCES
                ${CMAKE_CURRENT_SOURCE_DIR}/../${GOOGLETEST_ROOT}/src/gtest-all.cc
                ${CMAKE_CURRENT_SOURCE_DIR}/../${GOOGLETEST_ROOT}/src/gtest_main.cc
        )

        foreach (_source ${GOOGLETEST_SOURCES})
            set_source_files_properties(${_source} PROPERTIES GENERATED 1)
        endforeach ()

        add_library(googletest ${GOOGLETEST_SOURCES})
        set(UNITTESTENGINE_LIBRARYS googletest ${CMAKE_THREAD_LIBS_INIT} PARENT_SCOPE)
        set(UNITTESTENGINE_INCLUDE_DIR ${UNITTESTENGINE_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../${GOOGLETEST_ROOT}/include ${CMAKE_CURRENT_SOURCE_DIR}/../${GOOGLETEST_ROOT} PARENT_SCOPE)
    endif(CMAKE_GENERATOR MATCHES "Xcode")
endif (MSVC)

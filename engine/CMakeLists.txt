set (UNITTESTENGINE_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/engine)
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
    set(GOOGLETEST_ROOT engine/googletest/googletest CACHE STRING "Google Test source root")

    include_directories(
            ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
            ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    )

    set(
            GOOGLETEST_SOURCES
            ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
            ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    )

    foreach (_source ${GOOGLETEST_SOURCES})
        set_source_files_properties(${_source} PROPERTIES GENERATED 1)
    endforeach ()

    add_library(googletest ${GOOGLETEST_SOURCES})
    set(UNITTESTENGINE_LIBRARYS googletest ${CMAKE_THREAD_LIBS_INIT} PARENT_SCOPE)
    set(UNITTESTENGINE_INCLUDE_DIR ${UNITTESTENGINE_INCLUDE_DIR} ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT} PARENT_SCOPE)
endif (MSVC)
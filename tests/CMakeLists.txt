
set(TEST_SOURCES

        ${PROJECT_SOURCE_DIR}/tests/engineTest.cpp
        ${PROJECT_SOURCE_DIR}/tests/libraryTest.cpp)

message(STATUS ${UNITTESTENGINE_LINK_DIRECTORY})
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
    add_executable(
            Tests
            ${TEST_SOURCES}
    )
endif (MSVC)

if (NOT MSVC)
    target_compile_definitions(Tests PRIVATE GTEST=1)
    add_dependencies(Tests googletest)
endif (NOT MSVC)

target_link_libraries(
        Tests
        ${UNITTESTENGINE_LIBRARYS}
        testLib
)

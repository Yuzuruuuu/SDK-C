cmake_minimum_required(VERSION 3.14)

project(ncsdk)

aux_source_directory(src SRC_LIST)

add_library(ncsdk SHARED ${SRC_LIST})

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

target_include_directories(ncsdk PUBLIC 
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
                           ${CMAKE_CURRENT_SOURCE_DIR}/third_party
                           )


include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    DOWNLOAD_EXTRACT_TIMESTAMP True
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

aux_source_directory(tests TEST_LIST)

add_executable(ncsdk_test ${TEST_LIST})

target_link_libraries(ncsdk_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(ncsdk_test)
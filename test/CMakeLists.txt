cmake_minimum_required(VERSION 3.14)

project(ncsdk_test)


add_subdirectory(../src ncsdk)


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


aux_source_directory(. SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

if(MSVC)
    target_compile_definitions(${PROJECT_NAME} PUBLIC _CRT_SECURE_NO_WARNINGS)
    target_compile_options(${PROJECT_NAME} PUBLIC /W4)
else()
    target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wextra -pedantic)
endif()


target_link_libraries(${PROJECT_NAME} GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})


target_link_libraries(${PROJECT_NAME} ncsdk)
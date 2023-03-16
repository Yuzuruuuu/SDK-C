cmake_minimum_required(VERSION 3.14)

project(ncsdk)

# Add dependencies.
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../third_party/argparse argparse)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../third_party/libwebsockets libwebsockets)

aux_source_directory(. SRC_LIST)

add_library(${PROJECT_NAME} STATIC ${SRC_LIST})

target_include_directories(${PROJECT_NAME} PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/../include)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PUBLIC _DEBUG)
endif()

if(MSVC)
    target_compile_definitions(${PROJECT_NAME} PUBLIC _CRT_SECURE_NO_WARNINGS)
    target_compile_options(${PROJECT_NAME} PUBLIC /W4)
else()
    target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wextra -pedantic)
endif()

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 11)

target_include_directories(${PROJECT_NAME} PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/json.h)

target_link_libraries(${PROJECT_NAME} PUBLIC argparse websockets)
cmake_minimum_required(VERSION 3.14)

project(ncsdk)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()

if(MSVC)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif()

aux_source_directory(. SRC_LIST)

add_library(ncsdk STATIC ${SRC_LIST})

set_target_properties(ncsdk PROPERTIES 
                      C_STANDARD 11)

target_include_directories(ncsdk PUBLIC
                           ${CMAKE_CURRENT_BINARY_DIR}
                           ${CMAKE_CURRENT_SOURCE_DIR}/../include
                           ${CMAKE_CURRENT_SOURCE_DIR}/../third_party
                           )
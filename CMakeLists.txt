cmake_minimum_required(VERSION 3.10)

project(ncsdk)

aux_source_directory(src SRC_LIST)

add_library(ncsdk SHARED ${SRC_LIST})

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

target_include_directories(ncsdk PUBLIC 
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
                           ${CMAKE_CURRENT_SOURCE_DIR}/third_party
                           )
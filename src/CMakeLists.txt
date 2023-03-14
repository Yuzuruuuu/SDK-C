cmake_minimum_required(VERSION 3.14)

project(ncsdk)

# Add dependencies.
add_subdirectory(../third_party/argparse/ argparse)
add_subdirectory(../third_party/wic/ wic)

# Set build arguments.
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()

if(MSVC)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

aux_source_directory(. SRC_LIST)

add_library(${PROJECT_NAME} STATIC ${SRC_LIST})

target_include_directories(${PROJECT_NAME} PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/../include/
                           )

# Link dependencies.
target_link_libraries(${PROJECT_NAME} PUBLIC 
                      argparse
                      wic
                      )

# Add dependency include directories.
target_include_directories(${PROJECT_NAME} PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/json.h/
                           )
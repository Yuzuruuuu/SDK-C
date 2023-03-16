cmake_minimum_required(VERSION 3.14)

project(ncsdk_examples)


add_subdirectory(../src ncsdk)

get_target_property(NCSDK_SOURCE_DIR ncsdk SOURCE_DIR)

include_directories(${NCSDK_SOURCE_DIR}/../include/user_only)


# log_messages
aux_source_directory(./log_messages SRC_LIST)

add_executable(log_messages ${SRC_LIST})

target_link_libraries(log_messages ncsdk)
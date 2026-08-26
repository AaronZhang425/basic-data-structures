cmake_minimum_required(VERSION 3.10)

project(data_structures VERSION 0.1)

add_executable(data_structures_tester
    src/main.c
)

target_include_directories(
    data_structures_tester PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
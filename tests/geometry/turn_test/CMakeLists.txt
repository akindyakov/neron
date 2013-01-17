cmake_minimum_required(VERSION 2.8)

project(turn_shape_test)

include_directories(${MAP_GEOMETRY_LIB_DIR})

include_directories(headers)

set(SOURCE_LIB circle_drow_test.cpp
               contout_drow_test.cpp
               line_drow_test.cpp      )

add_library(drow_sample_lib STATIC ${SOURCE_LIB})

add_executable(turn_shape_test turn_shape_main.cpp)

target_link_libraries(turn_shape_test drow_sample_lib)

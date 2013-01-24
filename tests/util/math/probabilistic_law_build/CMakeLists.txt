cmake_minimum_required(VERSION 2.8)

project(prob_law_build)

add_library(neron_util_math SHARED IMPORTED)
set_property(TARGET neron_util PROPERTY
               IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/lib/util/math.a)

add_executable(main prob_law_build.cpp}

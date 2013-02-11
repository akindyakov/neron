cmake_minimum_required(VERSION 2.8)

project(create_shadow_test)

#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/tests)

set(SHADOW_TEST_SRC_ROOT ${TESTS}/util/geometry/shadow_test/)
set(GENERAL_TEST_SRC_ROOT ${TESTS}/util/geometry/general_test_src/)

include_directories(${HEADERS})
include_directories(${SHADOW_TEST_SRC_ROOT})
include_directories(${OpenCV_INCLUDE_DIR})
#include_directories(${TESTS}/util/geometry/general_test_src/}

aux_source_directory(${SHADOW_TEST_SRC_ROOT}  SHADOW_TEST_SRC )
aux_source_directory(${GENERAL_TEST_SRC_ROOT} SHADOW_TEST_SRC )

add_executable(create_shadow_test ${SHADOW_TEST_SRC})

target_link_libraries(create_shadow_test ${REQUIRED_LIBRARIES} Neron)

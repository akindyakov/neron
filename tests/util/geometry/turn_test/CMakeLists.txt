cmake_minimum_required(VERSION 2.8)

project(turn_shape_test)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/tests)

set(TURN_SHAPE_TEST_SRC_ROOT ${TESTS}/util/geometry/turn_test/)

include_directories(${HEADERS})
include_directories(${TURN_SHAPE_TEST_SRC_ROOT})

aux_source_directory( ${TURN_SHAPE_TEST_SRC_ROOT}  TURN_SHAPE_TEST_SRC )
aux_source_directory( ${TURN_SHAPE_TEST_SRC_ROOT}/src TURN_SHAPE_TEST_SRC )

add_executable(turn_shape_test ${TURN_SHAPE_TEST_SRC})

target_link_libraries(turn_shape_test ${REQUIRED_LIBRARIES} Neron)

# ----------------------------------------------------------------------------
#  Root CMake file for Neron proj
# ----------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.8)

include(cmake/proj_dependings.cmake)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} cmake/)
project(Neron)

set(LIBRARIES)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(SOURCE_ROOT ${CMAKE_SOURCE_DIR}/src)
set(HEADERS ${CMAKE_SOURCE_DIR})

find_package(OpenCV REQUIRED)
message(STATUS ${OpenCV_FOUND})
set( REQUIRED_LIBRARIES ${OpenCV_LIBS} ) 

include_directories(${HEADERS})

#aux_source_directory( ${SOURCE_ROOT}/agents SOURCES )
#aux_source_directory( ${SOURCE_ROOT}/links SOURCES )
aux_source_directory( ${SOURCE_ROOT}/map SOURCES )
aux_source_directory( ${SOURCE_ROOT}/util/geometry SOURCES )
aux_source_directory( ${SOURCE_ROOT}/util/math SOURCES )

add_library(Neron SHARED ${SOURCES})
target_link_libraries( Neron ${REQUIRED_LIBRARIES} )

file( COPY ${HEADERS}/include DESTINATION ${CMAKE_BINARY_DIR} )

#add_subdirectory(tests/geometry/intersection_test/ EXECUTABLE_OUTPUT_PATH)
#add_subdirectory(tests/geometry/turn_test/ EXECUTABLE_OUTPUT_PATH)
#add_subdirectory(tests/map/create_map_test/ EXECUTABLE_OUTPUT_PATH)
#add_subdirectory(tests/util/math/probabilistic_law_build/ EXECUTABLE_OUTPUT_PATH)

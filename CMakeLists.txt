# ----------------------------------------------------------------------------
#  Root CMake file for Neron proj
# ----------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.8)

include(cmake/proj_dependings.cmake)

set(LIBRARIES)

foreach(LIBRARY${LIBRARIES})
   message(STATUS "Check the ${LIBRARY} is instaled: " ${${LIBRARY}_FOUND})
   find_library("${LIBRARY}_FOUND"${LIBRARY})
   
   if ("${${LIBRARY}_FOUND}" STREQUAL "${LIBRARY}_FOUND-NOTFOUND")
      message(STATUS "Add library sources")
      add_subdirectory(../${LIBRARY} lib/${LIBRARY})
   endif()
endforeach()

project(Neron)

set( REQUIRED_LIBRARIES 
      my_addition_lib
      boost_thread 
      boost_system )

set(BIN_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

set(SOURCE_ROOT "${CMAKE_SOURCE_DIR}/src")

aux_source_directory( ${SOURCE_ROOT} SOURCES )

link_directories()
add_library(Neron SHARED ${SOURCES})
target_link_libraries( Neron ${REQUIRED_LIBRARIES} )

add_subdirectory(tests/geometry/intersection_test/ EXECUTABLE_OUTPUT_PATH)
add_subdirectory(tests/geometry/turn_test/ EXECUTABLE_OUTPUT_PATH)
add_subdirectory(tests/map/create_map_test/ EXECUTABLE_OUTPUT_PATH)
add_subdirectory(tests/util/math/probabilistic_law_build/ EXECUTABLE_OUTPUT_PATH)

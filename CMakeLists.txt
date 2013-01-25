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
      boost_shared_ptr )

set(BIN_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(SOURCE_ROOT ${CMAKE_SOURCE_DIR}/src)
set(HEADERS ${CMAKE_SOURCE_DIR})

include_directories(${HEADERS})

#aux_source_directory( ${SOURCE_ROOT}/agents SOURCES )
#aux_source_directory( ${SOURCE_ROOT}/links SOURCES )
aux_source_directory( ${SOURCE_ROOT}/map SOURCES )
aux_source_directory( ${SOURCE_ROOT}/util/geometry SOURCES )
aux_source_directory( ${SOURCE_ROOT}/util/math SOURCES )

add_library(Neron SHARED ${SOURCES})
target_link_libraries( Neron ${REQUIRED_LIBRARIES} )

#add_subdirectory(tests/geometry/intersection_test/ EXECUTABLE_OUTPUT_PATH)
#add_subdirectory(tests/geometry/turn_test/ EXECUTABLE_OUTPUT_PATH)
#add_subdirectory(tests/map/create_map_test/ EXECUTABLE_OUTPUT_PATH)
#add_subdirectory(tests/util/math/probabilistic_law_build/ EXECUTABLE_OUTPUT_PATH)

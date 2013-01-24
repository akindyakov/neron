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

project(Neron CXX)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

set(SOURCE_LIB )
set(SOURCE_EXE main.cpp)

add_subdirectory(tests/geometry/intersection_test/ EXECUTABLE_OUTPUT_PATH)
add_subdirectory(tests/geometry/turn_test/ EXECUTABLE_OUTPUT_PATH)

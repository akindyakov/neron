# ----------------------------------------------------------------------------
#  Root CMake file for Neron proj
# ----------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.8)

include(cmake/proj_dependings.cmake)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} cmake/)
project(Neron)

set(LIBRARIES)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/tests)

set(SOURCE_ROOT ${CMAKE_SOURCE_DIR}/src)
set(HEADERS ${CMAKE_SOURCE_DIR})
set(TESTS ${CMAKE_SOURCE_DIR}/tests)
set(OTHER_LIB ${CMAKE_SOURCE_DIR}/other)

#lib not included to neron sources

   # Open Source Computer Vision Library 
   # URL: www.opencv.org
   find_package(OpenCV REQUIRED)
   list( APPEND HEADERS ${OpenCV_INCLUDE_DIR} )
   list( APPEND REQUIRED_LIBRARIES ${OpenCV_LIBS} ) 
   
   # BOOST C++ libraries
   # URL: www.boost.org
   find_package(Boost REQUIRED)
   list( APPEND HEADERS ${Boost_LIBRARY_DIRS} )
   list( APPEND REQUIRED_LIBRARIES ${boost_smart_ptr} )

#lib included in neron sources
   
   # tiny xml lib 
   # www.sourceforge.net/projects/tinyxml
   add_subdirectory( ${OTHER_LIB} )
   #include( ${OTHER_LIB} )
   list( APPEND HEADERS ${neron_tinyxml_include_dir} )
   list( APPEND REQUIRED_LIBRARIES ${neron_tiny_xml_lib} ) 
   message( STATUS ${neron_tinyxml_include_dir} )

include_directories(${HEADERS})

aux_source_directory( ${SOURCE_ROOT}/map SOURCES )
aux_source_directory( ${SOURCE_ROOT}/util SOURCES )
aux_source_directory( ${SOURCE_ROOT}/util/geometry SOURCES )
aux_source_directory( ${SOURCE_ROOT}/util/math SOURCES )

add_library( Neron SHARED ${SOURCES} )
target_link_libraries( Neron ${REQUIRED_LIBRARIES} )

file( COPY ${CMAKE_SOURCE_DIR}/include DESTINATION ${CMAKE_BINARY_DIR} )
file( COPY ${CMAKE_SOURCE_DIR}/README DESTINATION ${CMAKE_BINARY_DIR}/README )

#add_subdirectory( tests/util/geometry/turn_test ${EXECUTABLE_OUTPUT_PATH} )
#add_subdirectory( tests/util/geometry/shadow_test ${EXECUTABLE_OUTPUT_PATH}/shadow )
add_subdirectory( tests/util/geometry/turn_test )
add_subdirectory( tests/util/geometry/shadow_test )

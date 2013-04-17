project( tiny_xml_lib )

set( _LOCAL_TINY_XML_LIB_ROOT ${OTHER_LIB}/tinyxml )
include_directories(${_LOCAL_TINY_XML_LIB_ROOT})

aux_source_directory( ${_LOCAL_TINY_XML_LIB_ROOT}  _LOCAL_TINYXML_SRC )

add_library( tiny_xml_lib STATIC ${_LOCAL_TINYXML_SRC} )

set( TINY_XML_LIB_HEADERS ${_LOCAL_TINY_XML_LIB_ROOT} PARENT_SCOPE )
set( TINY_XML_LIB tiny_xml_lib PARENT_SCOPE ) 

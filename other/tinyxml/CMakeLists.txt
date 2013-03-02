project(neron_tiny_xml_lib)

set( NERON_TINY_XML_LIB_ROOT ${OTHER_LIB}/tinyxml )

include_directories(${NERON_TINY_XML_LIB_ROOT})

set( neron_tinyxml_include_dir ${NERON_TINY_XML_LIB_ROOT} )
aux_source_directory( ${NERON_TINY_XML_LIB_ROOT}  NERON_TINYXML_SRC )

add_library( neron_tiny_xml_lib SHARED ${SOURCES} )

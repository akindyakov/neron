
set( _LOCAL_OTHER_LIB_HEADERS )
set( _LOCAL_OTHER_LIB_LIST    ) 

# tiny xml lib 
# www.sourceforge.net/projects/tinyxml
   add_subdirectory( ${OTHER_LIB}/tinyxml )
   list( APPEND _LOCAL_OTHER_LIB_HEADERS ${TINY_XML_LIB_HEADERS} )
   list( APPEND _LOCAL_OTHER_LIB_LIST ${TINY_XML_LIB} ) 


#set all other lib to parrent scope
   set( OTHER_LIB_HEADERS ${_LOCAL_OTHER_LIB_HEADERS} PARENT_SCOPE )
   set( OTHER_LIB_LIST    ${_LOCAL_OTHER_LIB_LIST}    PARENT_SCOPE ) 

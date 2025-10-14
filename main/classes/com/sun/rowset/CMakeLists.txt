#machine generated

add_subdirectory("internal")
add_subdirectory("providers")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.com.sun.rowset_SRCS)
file(GLOB classes.com.sun.rowset_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.com.sun.rowset_HEADERS}) 
list(LENGTH classes.com.sun.rowset_SRCS classes.com.sun.rowset_SRCS_LENGTH)
if(classes.com.sun.rowset_SRCS_LENGTH)
	add_library(classes.com.sun.rowset OBJECT "${classes.com.sun.rowset_SRCS}" "${classes.com.sun.rowset_HEADERS}")
	jcpp_enable_bigobj(classes.com.sun.rowset)
endif()
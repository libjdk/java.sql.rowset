#machine generated

add_subdirectory("serial")
add_subdirectory("spi")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.javax.sql.rowset_SRCS)
file(GLOB classes.javax.sql.rowset_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.javax.sql.rowset_HEADERS}) 
list(LENGTH classes.javax.sql.rowset_SRCS classes.javax.sql.rowset_SRCS_LENGTH)
if(classes.javax.sql.rowset_SRCS_LENGTH)
	add_library(classes.javax.sql.rowset OBJECT "${classes.javax.sql.rowset_SRCS}" "${classes.javax.sql.rowset_HEADERS}")
	jcpp_enable_bigobj(classes.javax.sql.rowset)
endif()
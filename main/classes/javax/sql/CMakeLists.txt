#machine generated

add_subdirectory("rowset")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.javax.sql_SRCS)
file(GLOB classes.javax.sql_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.javax.sql_HEADERS}) 
list(LENGTH classes.javax.sql_SRCS classes.javax.sql_SRCS_LENGTH)
if(classes.javax.sql_SRCS_LENGTH)
	add_library(classes.javax.sql OBJECT "${classes.javax.sql_SRCS}" "${classes.javax.sql_HEADERS}")
	jcpp_enable_bigobj(classes.javax.sql)
endif()
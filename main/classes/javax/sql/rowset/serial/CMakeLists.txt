#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.javax.sql.rowset.ser_2_SRCS)
file(GLOB classes.javax.sql.rowset.ser_2_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.javax.sql.rowset.ser_2_HEADERS}) 
list(LENGTH classes.javax.sql.rowset.ser_2_SRCS classes.javax.sql.rowset.ser_2_SRCS_LENGTH)
if(classes.javax.sql.rowset.ser_2_SRCS_LENGTH)
	add_library(classes.javax.sql.rowset.ser_2 OBJECT "${classes.javax.sql.rowset.ser_2_SRCS}" "${classes.javax.sql.rowset.ser_2_HEADERS}")
	jcpp_enable_bigobj(classes.javax.sql.rowset.ser_2)
endif()
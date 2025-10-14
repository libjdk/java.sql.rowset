#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.javax.sql.rowset.spi_SRCS)
file(GLOB classes.javax.sql.rowset.spi_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.javax.sql.rowset.spi_HEADERS}) 
list(LENGTH classes.javax.sql.rowset.spi_SRCS classes.javax.sql.rowset.spi_SRCS_LENGTH)
if(classes.javax.sql.rowset.spi_SRCS_LENGTH)
	add_library(classes.javax.sql.rowset.spi OBJECT "${classes.javax.sql.rowset.spi_SRCS}" "${classes.javax.sql.rowset.spi_HEADERS}")
	jcpp_enable_bigobj(classes.javax.sql.rowset.spi)
endif()
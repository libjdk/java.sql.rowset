#ifndef _javax_sql_rowset_spi_XmlReader_h_
#define _javax_sql_rowset_spi_XmlReader_h_
//$ interface javax.sql.rowset.spi.XmlReader
//$ extends javax.sql.RowSetReader

#include <javax/sql/RowSetReader.h>

namespace java {
	namespace io {
		class Reader;
	}
}
namespace javax {
	namespace sql {
		namespace rowset {
			class WebRowSet;
		}
	}
}

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

class $import XmlReader : public ::javax::sql::RowSetReader {
	$interface(XmlReader, $NO_CLASS_INIT, ::javax::sql::RowSetReader)
public:
	virtual void readXML(::javax::sql::rowset::WebRowSet* caller, ::java::io::Reader* reader) {}
};

			} // spi
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_spi_XmlReader_h_
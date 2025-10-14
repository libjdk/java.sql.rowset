#ifndef _javax_sql_rowset_spi_XmlWriter_h_
#define _javax_sql_rowset_spi_XmlWriter_h_
//$ interface javax.sql.rowset.spi.XmlWriter
//$ extends javax.sql.RowSetWriter

#include <javax/sql/RowSetWriter.h>

namespace java {
	namespace io {
		class Writer;
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

class $import XmlWriter : public ::javax::sql::RowSetWriter {
	$interface(XmlWriter, $NO_CLASS_INIT, ::javax::sql::RowSetWriter)
public:
	virtual void writeXML(::javax::sql::rowset::WebRowSet* caller, ::java::io::Writer* writer) {}
};

			} // spi
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_spi_XmlWriter_h_
#ifndef _javax_sql_rowset_spi_TransactionalWriter_h_
#define _javax_sql_rowset_spi_TransactionalWriter_h_
//$ interface javax.sql.rowset.spi.TransactionalWriter
//$ extends javax.sql.RowSetWriter

#include <javax/sql/RowSetWriter.h>

namespace java {
	namespace sql {
		class Savepoint;
	}
}

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

class $export TransactionalWriter : public ::javax::sql::RowSetWriter {
	$interface(TransactionalWriter, $NO_CLASS_INIT, ::javax::sql::RowSetWriter)
public:
	virtual void commit() {}
	virtual void rollback() {}
	virtual void rollback(::java::sql::Savepoint* s) {}
};

			} // spi
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_spi_TransactionalWriter_h_
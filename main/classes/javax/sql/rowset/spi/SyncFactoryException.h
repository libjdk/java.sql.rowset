#ifndef _javax_sql_rowset_spi_SyncFactoryException_h_
#define _javax_sql_rowset_spi_SyncFactoryException_h_
//$ class javax.sql.rowset.spi.SyncFactoryException
//$ extends java.sql.SQLException

#include <java/sql/SQLException.h>

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

class $export SyncFactoryException : public ::java::sql::SQLException {
	$class(SyncFactoryException, $NO_CLASS_INIT, ::java::sql::SQLException)
public:
	SyncFactoryException();
	void init$();
	void init$($String* msg);
	static const int64_t serialVersionUID = (int64_t)0xC3915E7C5EAD1B20;
	SyncFactoryException(const SyncFactoryException& e);
	virtual void throw$() override;
	inline SyncFactoryException* operator ->() {
		return (SyncFactoryException*)throwing$;
	}
};

			} // spi
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_spi_SyncFactoryException_h_
#ifndef _com_sun_rowset_RowSetFactoryImpl_h_
#define _com_sun_rowset_RowSetFactoryImpl_h_
//$ class com.sun.rowset.RowSetFactoryImpl
//$ extends javax.sql.rowset.RowSetFactory

#include <javax/sql/rowset/RowSetFactory.h>

namespace javax {
	namespace sql {
		namespace rowset {
			class CachedRowSet;
			class FilteredRowSet;
			class JdbcRowSet;
			class JoinRowSet;
			class WebRowSet;
		}
	}
}

namespace com {
	namespace sun {
		namespace rowset {

class RowSetFactoryImpl : public ::javax::sql::rowset::RowSetFactory {
	$class(RowSetFactoryImpl, $NO_CLASS_INIT, ::javax::sql::rowset::RowSetFactory)
public:
	RowSetFactoryImpl();
	void init$();
	virtual ::javax::sql::rowset::CachedRowSet* createCachedRowSet() override;
	virtual ::javax::sql::rowset::FilteredRowSet* createFilteredRowSet() override;
	virtual ::javax::sql::rowset::JdbcRowSet* createJdbcRowSet() override;
	virtual ::javax::sql::rowset::JoinRowSet* createJoinRowSet() override;
	virtual ::javax::sql::rowset::WebRowSet* createWebRowSet() override;
};

		} // rowset
	} // sun
} // com

#endif // _com_sun_rowset_RowSetFactoryImpl_h_
#ifndef _javax_sql_rowset_RowSetFactory_h_
#define _javax_sql_rowset_RowSetFactory_h_
//$ interface javax.sql.rowset.RowSetFactory
//$ extends java.lang.Object

#include <java/lang/Object.h>

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

namespace javax {
	namespace sql {
		namespace rowset {

class $export RowSetFactory : public ::java::lang::Object {
	$interface(RowSetFactory, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::javax::sql::rowset::CachedRowSet* createCachedRowSet() {return nullptr;}
	virtual ::javax::sql::rowset::FilteredRowSet* createFilteredRowSet() {return nullptr;}
	virtual ::javax::sql::rowset::JdbcRowSet* createJdbcRowSet() {return nullptr;}
	virtual ::javax::sql::rowset::JoinRowSet* createJoinRowSet() {return nullptr;}
	virtual ::javax::sql::rowset::WebRowSet* createWebRowSet() {return nullptr;}
};

		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_RowSetFactory_h_
#ifndef _javax_sql_rowset_FilteredRowSet_h_
#define _javax_sql_rowset_FilteredRowSet_h_
//$ interface javax.sql.rowset.FilteredRowSet
//$ extends javax.sql.rowset.WebRowSet

#include <javax/sql/rowset/WebRowSet.h>

namespace javax {
	namespace sql {
		namespace rowset {
			class Predicate;
		}
	}
}

namespace javax {
	namespace sql {
		namespace rowset {

class $import FilteredRowSet : public ::javax::sql::rowset::WebRowSet {
	$interface(FilteredRowSet, $NO_CLASS_INIT, ::javax::sql::rowset::WebRowSet)
public:
	using ::javax::sql::rowset::WebRowSet::execute;
	virtual ::javax::sql::rowset::Predicate* getFilter() {return nullptr;}
	virtual void setFilter(::javax::sql::rowset::Predicate* p) {}
};

		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_FilteredRowSet_h_
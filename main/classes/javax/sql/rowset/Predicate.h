#ifndef _javax_sql_rowset_Predicate_h_
#define _javax_sql_rowset_Predicate_h_
//$ interface javax.sql.rowset.Predicate
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace javax {
	namespace sql {
		class RowSet;
	}
}

namespace javax {
	namespace sql {
		namespace rowset {

class $export Predicate : public ::java::lang::Object {
	$interface(Predicate, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual bool evaluate(::javax::sql::RowSet* rs) {return false;}
	virtual bool evaluate(Object$* value, int32_t column) {return false;}
	virtual bool evaluate(Object$* value, $String* columnName) {return false;}
};

		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_Predicate_h_
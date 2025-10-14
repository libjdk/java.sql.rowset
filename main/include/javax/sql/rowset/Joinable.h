#ifndef _javax_sql_rowset_Joinable_h_
#define _javax_sql_rowset_Joinable_h_
//$ interface javax.sql.rowset.Joinable
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace javax {
	namespace sql {
		namespace rowset {

class $import Joinable : public ::java::lang::Object {
	$interface(Joinable, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual $ints* getMatchColumnIndexes() {return nullptr;}
	virtual $StringArray* getMatchColumnNames() {return nullptr;}
	virtual void setMatchColumn(int32_t columnIdx) {}
	virtual void setMatchColumn($ints* columnIdxes) {}
	virtual void setMatchColumn($String* columnName) {}
	virtual void setMatchColumn($StringArray* columnNames) {}
	virtual void unsetMatchColumn(int32_t columnIdx) {}
	virtual void unsetMatchColumn($ints* columnIdxes) {}
	virtual void unsetMatchColumn($String* columnName) {}
	virtual void unsetMatchColumn($StringArray* columnName) {}
};

		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_Joinable_h_
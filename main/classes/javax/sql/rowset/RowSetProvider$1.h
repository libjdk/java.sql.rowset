#ifndef _javax_sql_rowset_RowSetProvider$1_h_
#define _javax_sql_rowset_RowSetProvider$1_h_
//$ class javax.sql.rowset.RowSetProvider$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace javax {
	namespace sql {
		namespace rowset {

class RowSetProvider$1 : public ::java::security::PrivilegedAction {
	$class(RowSetProvider$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	RowSetProvider$1();
	void init$();
	virtual $Object* run() override;
};

		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_RowSetProvider$1_h_
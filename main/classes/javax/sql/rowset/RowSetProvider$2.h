#ifndef _javax_sql_rowset_RowSetProvider$2_h_
#define _javax_sql_rowset_RowSetProvider$2_h_
//$ class javax.sql.rowset.RowSetProvider$2
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace javax {
	namespace sql {
		namespace rowset {

class RowSetProvider$2 : public ::java::security::PrivilegedAction {
	$class(RowSetProvider$2, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	RowSetProvider$2();
	void init$($String* val$propName);
	virtual $Object* run() override;
	$String* val$propName = nullptr;
};

		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_RowSetProvider$2_h_
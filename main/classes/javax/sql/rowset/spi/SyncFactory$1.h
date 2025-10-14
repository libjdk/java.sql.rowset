#ifndef _javax_sql_rowset_spi_SyncFactory$1_h_
#define _javax_sql_rowset_spi_SyncFactory$1_h_
//$ class javax.sql.rowset.spi.SyncFactory$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

class SyncFactory$1 : public ::java::security::PrivilegedAction {
	$class(SyncFactory$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	SyncFactory$1();
	void init$();
	virtual $Object* run() override;
};

			} // spi
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_spi_SyncFactory$1_h_
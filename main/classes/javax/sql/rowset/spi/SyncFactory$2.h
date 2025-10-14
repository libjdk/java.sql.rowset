#ifndef _javax_sql_rowset_spi_SyncFactory$2_h_
#define _javax_sql_rowset_spi_SyncFactory$2_h_
//$ class javax.sql.rowset.spi.SyncFactory$2
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

class SyncFactory$2 : public ::java::security::PrivilegedAction {
	$class(SyncFactory$2, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	SyncFactory$2();
	void init$();
	virtual $Object* run() override;
};

			} // spi
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_spi_SyncFactory$2_h_
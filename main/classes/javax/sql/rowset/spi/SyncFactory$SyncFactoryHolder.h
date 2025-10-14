#ifndef _javax_sql_rowset_spi_SyncFactory$SyncFactoryHolder_h_
#define _javax_sql_rowset_spi_SyncFactory$SyncFactoryHolder_h_
//$ class javax.sql.rowset.spi.SyncFactory$SyncFactoryHolder
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {
				class SyncFactory;
			}
		}
	}
}

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

class SyncFactory$SyncFactoryHolder : public ::java::lang::Object {
	$class(SyncFactory$SyncFactoryHolder, 0, ::java::lang::Object)
public:
	SyncFactory$SyncFactoryHolder();
	void init$();
	static ::javax::sql::rowset::spi::SyncFactory* factory;
};

			} // spi
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_spi_SyncFactory$SyncFactoryHolder_h_
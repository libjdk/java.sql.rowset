#ifndef _javax_sql_rowset_spi_SyncProviderException_h_
#define _javax_sql_rowset_spi_SyncProviderException_h_
//$ class javax.sql.rowset.spi.SyncProviderException
//$ extends java.sql.SQLException

#include <java/sql/SQLException.h>

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {
				class SyncResolver;
			}
		}
	}
}

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

class $import SyncProviderException : public ::java::sql::SQLException {
	$class(SyncProviderException, $NO_CLASS_INIT, ::java::sql::SQLException)
public:
	SyncProviderException();
	void init$();
	void init$($String* msg);
	void init$(::javax::sql::rowset::spi::SyncResolver* syncResolver);
	virtual ::javax::sql::rowset::spi::SyncResolver* getSyncResolver();
	virtual void setSyncResolver(::javax::sql::rowset::spi::SyncResolver* syncResolver);
	::javax::sql::rowset::spi::SyncResolver* syncResolver = nullptr;
	static const int64_t serialVersionUID = (int64_t)0xF2F4C62D783AD84C;
	SyncProviderException(const SyncProviderException& e);
	virtual void throw$() override;
	inline SyncProviderException* operator ->() {
		return (SyncProviderException*)throwing$;
	}
};

			} // spi
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_spi_SyncProviderException_h_
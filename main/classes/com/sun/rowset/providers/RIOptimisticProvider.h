#ifndef _com_sun_rowset_providers_RIOptimisticProvider_h_
#define _com_sun_rowset_providers_RIOptimisticProvider_h_
//$ class com.sun.rowset.providers.RIOptimisticProvider
//$ extends javax.sql.rowset.spi.SyncProvider
//$ implements java.io.Serializable

#include <java/io/Serializable.h>
#include <javax/sql/rowset/spi/SyncProvider.h>

namespace com {
	namespace sun {
		namespace rowset {
			class JdbcRowSetResourceBundle;
		}
	}
}
namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {
				class CachedRowSetReader;
				class CachedRowSetWriter;
			}
		}
	}
}
namespace java {
	namespace io {
		class ObjectInputStream;
	}
}
namespace javax {
	namespace sql {
		class RowSetReader;
		class RowSetWriter;
	}
}

namespace com {
	namespace sun {
		namespace rowset {
			namespace providers {

class RIOptimisticProvider : public ::javax::sql::rowset::spi::SyncProvider, public ::java::io::Serializable {
	$class(RIOptimisticProvider, $NO_CLASS_INIT, ::javax::sql::rowset::spi::SyncProvider, ::java::io::Serializable)
public:
	RIOptimisticProvider();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$();
	virtual int32_t getDataSourceLock() override;
	virtual int32_t getProviderGrade() override;
	virtual $String* getProviderID() override;
	virtual ::javax::sql::RowSetReader* getRowSetReader() override;
	virtual ::javax::sql::RowSetWriter* getRowSetWriter() override;
	virtual $String* getVendor() override;
	virtual $String* getVersion() override;
	void readObject(::java::io::ObjectInputStream* ois);
	virtual void setDataSourceLock(int32_t datasource_lock) override;
	virtual int32_t supportsUpdatableView() override;
	virtual $String* toString() override;
	::com::sun::rowset::internal::CachedRowSetReader* reader = nullptr;
	::com::sun::rowset::internal::CachedRowSetWriter* writer = nullptr;
	$String* providerID = nullptr;
	$String* vendorName = nullptr;
	$String* versionNumber = nullptr;
	::com::sun::rowset::JdbcRowSetResourceBundle* resBundle = nullptr;
	static const int64_t serialVersionUID = (int64_t)0xD4608434FF16B5F0;
};

			} // providers
		} // rowset
	} // sun
} // com

#endif // _com_sun_rowset_providers_RIOptimisticProvider_h_
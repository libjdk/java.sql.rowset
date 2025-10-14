#ifndef _com_sun_rowset_providers_RIXMLProvider_h_
#define _com_sun_rowset_providers_RIXMLProvider_h_
//$ class com.sun.rowset.providers.RIXMLProvider
//$ extends javax.sql.rowset.spi.SyncProvider

#include <javax/sql/rowset/spi/SyncProvider.h>

namespace com {
	namespace sun {
		namespace rowset {
			class JdbcRowSetResourceBundle;
		}
	}
}
namespace javax {
	namespace sql {
		class RowSetReader;
		class RowSetWriter;
	}
}
namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {
				class XmlReader;
				class XmlWriter;
			}
		}
	}
}

namespace com {
	namespace sun {
		namespace rowset {
			namespace providers {

class RIXMLProvider : public ::javax::sql::rowset::spi::SyncProvider {
	$class(RIXMLProvider, $NO_CLASS_INIT, ::javax::sql::rowset::spi::SyncProvider)
public:
	RIXMLProvider();
	void init$();
	virtual int32_t getDataSourceLock() override;
	virtual int32_t getProviderGrade() override;
	virtual $String* getProviderID() override;
	virtual ::javax::sql::RowSetReader* getRowSetReader() override;
	virtual ::javax::sql::RowSetWriter* getRowSetWriter() override;
	virtual $String* getVendor() override;
	virtual $String* getVersion() override;
	::javax::sql::rowset::spi::XmlReader* getXmlReader();
	::javax::sql::rowset::spi::XmlWriter* getXmlWriter();
	virtual void setDataSourceLock(int32_t lock) override;
	void setXmlReader(::javax::sql::rowset::spi::XmlReader* reader);
	void setXmlWriter(::javax::sql::rowset::spi::XmlWriter* writer);
	virtual int32_t supportsUpdatableView() override;
	$String* providerID = nullptr;
	$String* vendorName = nullptr;
	$String* versionNumber = nullptr;
	::com::sun::rowset::JdbcRowSetResourceBundle* resBundle = nullptr;
	::javax::sql::rowset::spi::XmlReader* xmlReader = nullptr;
	::javax::sql::rowset::spi::XmlWriter* xmlWriter = nullptr;
};

			} // providers
		} // rowset
	} // sun
} // com

#endif // _com_sun_rowset_providers_RIXMLProvider_h_
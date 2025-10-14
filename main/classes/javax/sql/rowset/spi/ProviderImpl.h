#ifndef _javax_sql_rowset_spi_ProviderImpl_h_
#define _javax_sql_rowset_spi_ProviderImpl_h_
//$ class javax.sql.rowset.spi.ProviderImpl
//$ extends javax.sql.rowset.spi.SyncProvider

#include <javax/sql/rowset/spi/SyncProvider.h>

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

class ProviderImpl : public ::javax::sql::rowset::spi::SyncProvider {
	$class(ProviderImpl, $NO_CLASS_INIT, ::javax::sql::rowset::spi::SyncProvider)
public:
	ProviderImpl();
	void init$();
	virtual $String* getClassname();
	virtual int32_t getDataSourceLock() override;
	virtual int32_t getIndex();
	virtual int32_t getProviderGrade() override;
	virtual $String* getProviderID() override;
	virtual ::javax::sql::RowSetReader* getRowSetReader() override;
	virtual ::javax::sql::RowSetWriter* getRowSetWriter() override;
	virtual $String* getVendor() override;
	virtual $String* getVersion() override;
	virtual void setClassname($String* classname);
	virtual void setDataSourceLock(int32_t param) override;
	virtual void setIndex(int32_t i);
	virtual void setVendor($String* vendor);
	virtual void setVersion($String* providerVer);
	virtual int32_t supportsUpdatableView() override;
	$String* className = nullptr;
	$String* vendorName = nullptr;
	$String* ver = nullptr;
	int32_t index = 0;
};

			} // spi
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_spi_ProviderImpl_h_
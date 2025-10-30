#include <com/sun/rowset/providers/RIXMLProvider.h>

#include <com/sun/rowset/JdbcRowSetResourceBundle.h>
#include <java/io/IOException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <javax/sql/RowSetReader.h>
#include <javax/sql/RowSetWriter.h>
#include <javax/sql/rowset/spi/SyncProvider.h>
#include <javax/sql/rowset/spi/XmlReader.h>
#include <javax/sql/rowset/spi/XmlWriter.h>
#include <jcpp.h>

#undef DATASOURCE_NO_LOCK
#undef GRADE_NONE
#undef NONUPDATABLE_VIEW_SYNC

using $JdbcRowSetResourceBundle = ::com::sun::rowset::JdbcRowSetResourceBundle;
using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $RowSetReader = ::javax::sql::RowSetReader;
using $RowSetWriter = ::javax::sql::RowSetWriter;
using $SyncProvider = ::javax::sql::rowset::spi::SyncProvider;
using $XmlReader = ::javax::sql::rowset::spi::XmlReader;
using $XmlWriter = ::javax::sql::rowset::spi::XmlWriter;

namespace com {
	namespace sun {
		namespace rowset {
			namespace providers {

$FieldInfo _RIXMLProvider_FieldInfo_[] = {
	{"providerID", "Ljava/lang/String;", nullptr, $PRIVATE, $field(RIXMLProvider, providerID)},
	{"vendorName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(RIXMLProvider, vendorName)},
	{"versionNumber", "Ljava/lang/String;", nullptr, $PRIVATE, $field(RIXMLProvider, versionNumber)},
	{"resBundle", "Lcom/sun/rowset/JdbcRowSetResourceBundle;", nullptr, $PRIVATE, $field(RIXMLProvider, resBundle)},
	{"xmlReader", "Ljavax/sql/rowset/spi/XmlReader;", nullptr, $PRIVATE, $field(RIXMLProvider, xmlReader)},
	{"xmlWriter", "Ljavax/sql/rowset/spi/XmlWriter;", nullptr, $PRIVATE, $field(RIXMLProvider, xmlWriter)},
	{}
};

$MethodInfo _RIXMLProvider_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RIXMLProvider::*)()>(&RIXMLProvider::init$))},
	{"getDataSourceLock", "()I", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.spi.SyncProviderException"},
	{"getProviderGrade", "()I", nullptr, $PUBLIC},
	{"getProviderID", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getRowSetReader", "()Ljavax/sql/RowSetReader;", nullptr, $PUBLIC},
	{"getRowSetWriter", "()Ljavax/sql/RowSetWriter;", nullptr, $PUBLIC},
	{"getVendor", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getVersion", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getXmlReader", "()Ljavax/sql/rowset/spi/XmlReader;", nullptr, $PUBLIC, $method(static_cast<$XmlReader*(RIXMLProvider::*)()>(&RIXMLProvider::getXmlReader)), "java.sql.SQLException"},
	{"getXmlWriter", "()Ljavax/sql/rowset/spi/XmlWriter;", nullptr, $PUBLIC, $method(static_cast<$XmlWriter*(RIXMLProvider::*)()>(&RIXMLProvider::getXmlWriter)), "java.sql.SQLException"},
	{"setDataSourceLock", "(I)V", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.spi.SyncProviderException"},
	{"setXmlReader", "(Ljavax/sql/rowset/spi/XmlReader;)V", nullptr, $PUBLIC, $method(static_cast<void(RIXMLProvider::*)($XmlReader*)>(&RIXMLProvider::setXmlReader)), "java.sql.SQLException"},
	{"setXmlWriter", "(Ljavax/sql/rowset/spi/XmlWriter;)V", nullptr, $PUBLIC, $method(static_cast<void(RIXMLProvider::*)($XmlWriter*)>(&RIXMLProvider::setXmlWriter)), "java.sql.SQLException"},
	{"supportsUpdatableView", "()I", nullptr, $PUBLIC},
	{}
};

$ClassInfo _RIXMLProvider_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"com.sun.rowset.providers.RIXMLProvider",
	"javax.sql.rowset.spi.SyncProvider",
	nullptr,
	_RIXMLProvider_FieldInfo_,
	_RIXMLProvider_MethodInfo_
};

$Object* allocate$RIXMLProvider($Class* clazz) {
	return $of($alloc(RIXMLProvider));
}

void RIXMLProvider::init$() {
	$SyncProvider::init$();
	$set(this, providerID, "com.sun.rowset.providers.RIXMLProvider"_s);
	$set(this, vendorName, "Oracle Corporation"_s);
	$set(this, versionNumber, "1.0"_s);
	$set(this, providerID, $of(this)->getClass()->getName());
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

$String* RIXMLProvider::getProviderID() {
	return this->providerID;
}

void RIXMLProvider::setXmlReader($XmlReader* reader) {
	$set(this, xmlReader, reader);
}

void RIXMLProvider::setXmlWriter($XmlWriter* writer) {
	$set(this, xmlWriter, writer);
}

$XmlReader* RIXMLProvider::getXmlReader() {
	return this->xmlReader;
}

$XmlWriter* RIXMLProvider::getXmlWriter() {
	return this->xmlWriter;
}

int32_t RIXMLProvider::getProviderGrade() {
	return $SyncProvider::GRADE_NONE;
}

int32_t RIXMLProvider::supportsUpdatableView() {
	return $SyncProvider::NONUPDATABLE_VIEW_SYNC;
}

int32_t RIXMLProvider::getDataSourceLock() {
	return $SyncProvider::DATASOURCE_NO_LOCK;
}

void RIXMLProvider::setDataSourceLock(int32_t lock) {
	$useLocalCurrentObjectStackCache();
	$throwNew($UnsupportedOperationException, $($nc($of($($nc(this->resBundle)->handleGetObject("rixml.unsupp"_s))))->toString()));
}

$RowSetWriter* RIXMLProvider::getRowSetWriter() {
	return nullptr;
}

$RowSetReader* RIXMLProvider::getRowSetReader() {
	return nullptr;
}

$String* RIXMLProvider::getVersion() {
	return this->versionNumber;
}

$String* RIXMLProvider::getVendor() {
	return this->vendorName;
}

RIXMLProvider::RIXMLProvider() {
}

$Class* RIXMLProvider::load$($String* name, bool initialize) {
	$loadClass(RIXMLProvider, name, initialize, &_RIXMLProvider_ClassInfo_, allocate$RIXMLProvider);
	return class$;
}

$Class* RIXMLProvider::class$ = nullptr;

			} // providers
		} // rowset
	} // sun
} // com
#include <javax/sql/rowset/spi/ProviderImpl.h>

#include <javax/sql/RowSetReader.h>
#include <javax/sql/RowSetWriter.h>
#include <javax/sql/rowset/spi/SyncFactory.h>
#include <javax/sql/rowset/spi/SyncFactoryException.h>
#include <javax/sql/rowset/spi/SyncProvider.h>
#include <javax/sql/rowset/spi/SyncProviderException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RowSetReader = ::javax::sql::RowSetReader;
using $RowSetWriter = ::javax::sql::RowSetWriter;
using $SyncFactory = ::javax::sql::rowset::spi::SyncFactory;
using $SyncFactoryException = ::javax::sql::rowset::spi::SyncFactoryException;
using $SyncProvider = ::javax::sql::rowset::spi::SyncProvider;
using $SyncProviderException = ::javax::sql::rowset::spi::SyncProviderException;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

$FieldInfo _ProviderImpl_FieldInfo_[] = {
	{"className", "Ljava/lang/String;", nullptr, $PRIVATE, $field(ProviderImpl, className)},
	{"vendorName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(ProviderImpl, vendorName)},
	{"ver", "Ljava/lang/String;", nullptr, $PRIVATE, $field(ProviderImpl, ver)},
	{"index", "I", nullptr, $PRIVATE, $field(ProviderImpl, index)},
	{}
};

$MethodInfo _ProviderImpl_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(ProviderImpl::*)()>(&ProviderImpl::init$))},
	{"getClassname", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getDataSourceLock", "()I", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.spi.SyncProviderException"},
	{"getIndex", "()I", nullptr, $PUBLIC},
	{"getProviderGrade", "()I", nullptr, $PUBLIC},
	{"getProviderID", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getRowSetReader", "()Ljavax/sql/RowSetReader;", nullptr, $PUBLIC},
	{"getRowSetWriter", "()Ljavax/sql/RowSetWriter;", nullptr, $PUBLIC},
	{"getVendor", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getVersion", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"setClassname", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"setDataSourceLock", "(I)V", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.spi.SyncProviderException"},
	{"setIndex", "(I)V", nullptr, $PUBLIC},
	{"setVendor", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"setVersion", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"supportsUpdatableView", "()I", nullptr, $PUBLIC},
	{}
};

$ClassInfo _ProviderImpl_ClassInfo_ = {
	$ACC_SUPER,
	"javax.sql.rowset.spi.ProviderImpl",
	"javax.sql.rowset.spi.SyncProvider",
	nullptr,
	_ProviderImpl_FieldInfo_,
	_ProviderImpl_MethodInfo_
};

$Object* allocate$ProviderImpl($Class* clazz) {
	return $of($alloc(ProviderImpl));
}

void ProviderImpl::init$() {
	$SyncProvider::init$();
	$set(this, className, nullptr);
	$set(this, vendorName, nullptr);
	$set(this, ver, nullptr);
}

void ProviderImpl::setClassname($String* classname) {
	$set(this, className, classname);
}

$String* ProviderImpl::getClassname() {
	return this->className;
}

void ProviderImpl::setVendor($String* vendor) {
	$set(this, vendorName, vendor);
}

$String* ProviderImpl::getVendor() {
	return this->vendorName;
}

void ProviderImpl::setVersion($String* providerVer) {
	$set(this, ver, providerVer);
}

$String* ProviderImpl::getVersion() {
	return this->ver;
}

void ProviderImpl::setIndex(int32_t i) {
	this->index = i;
}

int32_t ProviderImpl::getIndex() {
	return this->index;
}

int32_t ProviderImpl::getDataSourceLock() {
	$useLocalCurrentObjectStackCache();
	int32_t dsLock = 0;
	try {
		dsLock = $nc($($SyncFactory::getInstance(this->className)))->getDataSourceLock();
	} catch ($SyncFactoryException& sfEx) {
		$throwNew($SyncProviderException, $(sfEx->getMessage()));
	}
	return dsLock;
}

int32_t ProviderImpl::getProviderGrade() {
	int32_t grade = 0;
	try {
		grade = $nc($($SyncFactory::getInstance(this->className)))->getProviderGrade();
	} catch ($SyncFactoryException& sfEx) {
	}
	return grade;
}

$String* ProviderImpl::getProviderID() {
	return this->className;
}

$RowSetReader* ProviderImpl::getRowSetReader() {
	$useLocalCurrentObjectStackCache();
	$var($RowSetReader, rsReader, nullptr);
	try {
		$assign(rsReader, $nc($($SyncFactory::getInstance(this->className)))->getRowSetReader());
	} catch ($SyncFactoryException& sfEx) {
	}
	return rsReader;
}

$RowSetWriter* ProviderImpl::getRowSetWriter() {
	$useLocalCurrentObjectStackCache();
	$var($RowSetWriter, rsWriter, nullptr);
	try {
		$assign(rsWriter, $nc($($SyncFactory::getInstance(this->className)))->getRowSetWriter());
	} catch ($SyncFactoryException& sfEx) {
	}
	return rsWriter;
}

void ProviderImpl::setDataSourceLock(int32_t param) {
	$useLocalCurrentObjectStackCache();
	try {
		$nc($($SyncFactory::getInstance(this->className)))->setDataSourceLock(param);
	} catch ($SyncFactoryException& sfEx) {
		$throwNew($SyncProviderException, $(sfEx->getMessage()));
	}
}

int32_t ProviderImpl::supportsUpdatableView() {
	int32_t view = 0;
	try {
		view = $nc($($SyncFactory::getInstance(this->className)))->supportsUpdatableView();
	} catch ($SyncFactoryException& sfEx) {
	}
	return view;
}

ProviderImpl::ProviderImpl() {
}

$Class* ProviderImpl::load$($String* name, bool initialize) {
	$loadClass(ProviderImpl, name, initialize, &_ProviderImpl_ClassInfo_, allocate$ProviderImpl);
	return class$;
}

$Class* ProviderImpl::class$ = nullptr;

			} // spi
		} // rowset
	} // sql
} // javax
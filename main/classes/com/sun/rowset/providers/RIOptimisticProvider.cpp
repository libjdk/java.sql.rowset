#include <com/sun/rowset/providers/RIOptimisticProvider.h>

#include <com/sun/rowset/JdbcRowSetResourceBundle.h>
#include <com/sun/rowset/internal/CachedRowSetReader.h>
#include <com/sun/rowset/internal/CachedRowSetWriter.h>
#include <java/io/IOException.h>
#include <java/io/ObjectInputStream.h>
#include <java/sql/SQLException.h>
#include <javax/sql/RowSetReader.h>
#include <javax/sql/RowSetWriter.h>
#include <javax/sql/rowset/spi/SyncProvider.h>
#include <javax/sql/rowset/spi/SyncProviderException.h>
#include <javax/sql/rowset/spi/TransactionalWriter.h>
#include <jcpp.h>

#undef DATASOURCE_NO_LOCK
#undef GRADE_CHECK_MODIFIED_AT_COMMIT
#undef NONUPDATABLE_VIEW_SYNC

using $JdbcRowSetResourceBundle = ::com::sun::rowset::JdbcRowSetResourceBundle;
using $CachedRowSetReader = ::com::sun::rowset::internal::CachedRowSetReader;
using $CachedRowSetWriter = ::com::sun::rowset::internal::CachedRowSetWriter;
using $IOException = ::java::io::IOException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $SQLException = ::java::sql::SQLException;
using $RowSetReader = ::javax::sql::RowSetReader;
using $RowSetWriter = ::javax::sql::RowSetWriter;
using $SyncProvider = ::javax::sql::rowset::spi::SyncProvider;
using $SyncProviderException = ::javax::sql::rowset::spi::SyncProviderException;
using $TransactionalWriter = ::javax::sql::rowset::spi::TransactionalWriter;

namespace com {
	namespace sun {
		namespace rowset {
			namespace providers {

$FieldInfo _RIOptimisticProvider_FieldInfo_[] = {
	{"reader", "Lcom/sun/rowset/internal/CachedRowSetReader;", nullptr, $PRIVATE, $field(RIOptimisticProvider, reader)},
	{"writer", "Lcom/sun/rowset/internal/CachedRowSetWriter;", nullptr, $PRIVATE, $field(RIOptimisticProvider, writer)},
	{"providerID", "Ljava/lang/String;", nullptr, $PRIVATE, $field(RIOptimisticProvider, providerID)},
	{"vendorName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(RIOptimisticProvider, vendorName)},
	{"versionNumber", "Ljava/lang/String;", nullptr, $PRIVATE, $field(RIOptimisticProvider, versionNumber)},
	{"resBundle", "Lcom/sun/rowset/JdbcRowSetResourceBundle;", nullptr, $PRIVATE, $field(RIOptimisticProvider, resBundle)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(RIOptimisticProvider, serialVersionUID)},
	{}
};

$MethodInfo _RIOptimisticProvider_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RIOptimisticProvider::*)()>(&RIOptimisticProvider::init$))},
	{"getDataSourceLock", "()I", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.spi.SyncProviderException"},
	{"getProviderGrade", "()I", nullptr, $PUBLIC},
	{"getProviderID", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getRowSetReader", "()Ljavax/sql/RowSetReader;", nullptr, $PUBLIC},
	{"getRowSetWriter", "()Ljavax/sql/RowSetWriter;", nullptr, $PUBLIC},
	{"getVendor", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getVersion", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(RIOptimisticProvider::*)($ObjectInputStream*)>(&RIOptimisticProvider::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"setDataSourceLock", "(I)V", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.spi.SyncProviderException"},
	{"supportsUpdatableView", "()I", nullptr, $PUBLIC},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _RIOptimisticProvider_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"com.sun.rowset.providers.RIOptimisticProvider",
	"javax.sql.rowset.spi.SyncProvider",
	"java.io.Serializable",
	_RIOptimisticProvider_FieldInfo_,
	_RIOptimisticProvider_MethodInfo_
};

$Object* allocate$RIOptimisticProvider($Class* clazz) {
	return $of($alloc(RIOptimisticProvider));
}

int32_t RIOptimisticProvider::hashCode() {
	 return this->$SyncProvider::hashCode();
}

bool RIOptimisticProvider::equals(Object$* arg0) {
	 return this->$SyncProvider::equals(arg0);
}

$Object* RIOptimisticProvider::clone() {
	 return this->$SyncProvider::clone();
}

$String* RIOptimisticProvider::toString() {
	 return this->$SyncProvider::toString();
}

void RIOptimisticProvider::finalize() {
	this->$SyncProvider::finalize();
}

void RIOptimisticProvider::init$() {
	$SyncProvider::init$();
	$set(this, providerID, "com.sun.rowset.providers.RIOptimisticProvider"_s);
	$set(this, vendorName, "Oracle Corporation"_s);
	$set(this, versionNumber, "1.0"_s);
	$set(this, providerID, $of(this)->getClass()->getName());
	$set(this, reader, $new($CachedRowSetReader));
	$set(this, writer, $new($CachedRowSetWriter));
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

$String* RIOptimisticProvider::getProviderID() {
	return this->providerID;
}

$RowSetWriter* RIOptimisticProvider::getRowSetWriter() {
	try {
		$nc(this->writer)->setReader(this->reader);
	} catch ($SQLException& e) {
	}
	return this->writer;
}

$RowSetReader* RIOptimisticProvider::getRowSetReader() {
	return this->reader;
}

int32_t RIOptimisticProvider::getProviderGrade() {
	return $SyncProvider::GRADE_CHECK_MODIFIED_AT_COMMIT;
}

void RIOptimisticProvider::setDataSourceLock(int32_t datasource_lock) {
	$useLocalCurrentObjectStackCache();
	if (datasource_lock != $SyncProvider::DATASOURCE_NO_LOCK) {
		$throwNew($SyncProviderException, $($nc($of($($nc(this->resBundle)->handleGetObject("riop.locking"_s))))->toString()));
	}
}

int32_t RIOptimisticProvider::getDataSourceLock() {
	return $SyncProvider::DATASOURCE_NO_LOCK;
}

int32_t RIOptimisticProvider::supportsUpdatableView() {
	return $SyncProvider::NONUPDATABLE_VIEW_SYNC;
}

$String* RIOptimisticProvider::getVersion() {
	return this->versionNumber;
}

$String* RIOptimisticProvider::getVendor() {
	return this->vendorName;
}

void RIOptimisticProvider::readObject($ObjectInputStream* ois) {
	$nc(ois)->defaultReadObject();
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

RIOptimisticProvider::RIOptimisticProvider() {
}

$Class* RIOptimisticProvider::load$($String* name, bool initialize) {
	$loadClass(RIOptimisticProvider, name, initialize, &_RIOptimisticProvider_ClassInfo_, allocate$RIOptimisticProvider);
	return class$;
}

$Class* RIOptimisticProvider::class$ = nullptr;

			} // providers
		} // rowset
	} // sun
} // com
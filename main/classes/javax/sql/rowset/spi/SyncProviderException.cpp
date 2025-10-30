#include <javax/sql/rowset/spi/SyncProviderException.h>

#include <com/sun/rowset/internal/SyncResolverImpl.h>
#include <java/sql/SQLException.h>
#include <javax/sql/rowset/spi/SyncResolver.h>
#include <jcpp.h>

using $SyncResolverImpl = ::com::sun::rowset::internal::SyncResolverImpl;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $SQLException = ::java::sql::SQLException;
using $SyncResolver = ::javax::sql::rowset::spi::SyncResolver;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

$FieldInfo _SyncProviderException_FieldInfo_[] = {
	{"syncResolver", "Ljavax/sql/rowset/spi/SyncResolver;", nullptr, $PRIVATE, $field(SyncProviderException, syncResolver)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(SyncProviderException, serialVersionUID)},
	{}
};

$MethodInfo _SyncProviderException_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SyncProviderException::*)()>(&SyncProviderException::init$))},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(SyncProviderException::*)($String*)>(&SyncProviderException::init$))},
	{"<init>", "(Ljavax/sql/rowset/spi/SyncResolver;)V", nullptr, $PUBLIC, $method(static_cast<void(SyncProviderException::*)($SyncResolver*)>(&SyncProviderException::init$))},
	{"getSyncResolver", "()Ljavax/sql/rowset/spi/SyncResolver;", nullptr, $PUBLIC},
	{"setSyncResolver", "(Ljavax/sql/rowset/spi/SyncResolver;)V", nullptr, $PUBLIC},
	{}
};

$ClassInfo _SyncProviderException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.sql.rowset.spi.SyncProviderException",
	"java.sql.SQLException",
	nullptr,
	_SyncProviderException_FieldInfo_,
	_SyncProviderException_MethodInfo_
};

$Object* allocate$SyncProviderException($Class* clazz) {
	return $of($alloc(SyncProviderException));
}

void SyncProviderException::init$() {
	$SQLException::init$();
	$set(this, syncResolver, nullptr);
}

void SyncProviderException::init$($String* msg) {
	$SQLException::init$(msg);
	$set(this, syncResolver, nullptr);
}

void SyncProviderException::init$($SyncResolver* syncResolver) {
	$SQLException::init$();
	$set(this, syncResolver, nullptr);
	if (syncResolver == nullptr) {
		$throwNew($IllegalArgumentException, "Cannot instantiate a SyncProviderException with a null SyncResolver object"_s);
	} else {
		$set(this, syncResolver, syncResolver);
	}
}

$SyncResolver* SyncProviderException::getSyncResolver() {
	if (this->syncResolver != nullptr) {
		return this->syncResolver;
	} else {
		try {
			$set(this, syncResolver, $new($SyncResolverImpl));
		} catch ($SQLException& sqle) {
		}
		return this->syncResolver;
	}
}

void SyncProviderException::setSyncResolver($SyncResolver* syncResolver) {
	if (syncResolver == nullptr) {
		$throwNew($IllegalArgumentException, "Cannot set a null SyncResolver object"_s);
	} else {
		$set(this, syncResolver, syncResolver);
	}
}

SyncProviderException::SyncProviderException() {
}

SyncProviderException::SyncProviderException(const SyncProviderException& e) : $SQLException(e) {
}

void SyncProviderException::throw$() {
	throw *this;
}

$Class* SyncProviderException::load$($String* name, bool initialize) {
	$loadClass(SyncProviderException, name, initialize, &_SyncProviderException_ClassInfo_, allocate$SyncProviderException);
	return class$;
}

$Class* SyncProviderException::class$ = nullptr;

			} // spi
		} // rowset
	} // sql
} // javax
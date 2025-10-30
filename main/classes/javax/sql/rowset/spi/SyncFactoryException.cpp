#include <javax/sql/rowset/spi/SyncFactoryException.h>

#include <java/sql/SQLException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SQLException = ::java::sql::SQLException;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

$FieldInfo _SyncFactoryException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(SyncFactoryException, serialVersionUID)},
	{}
};

$MethodInfo _SyncFactoryException_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SyncFactoryException::*)()>(&SyncFactoryException::init$))},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(SyncFactoryException::*)($String*)>(&SyncFactoryException::init$))},
	{}
};

$ClassInfo _SyncFactoryException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.sql.rowset.spi.SyncFactoryException",
	"java.sql.SQLException",
	nullptr,
	_SyncFactoryException_FieldInfo_,
	_SyncFactoryException_MethodInfo_
};

$Object* allocate$SyncFactoryException($Class* clazz) {
	return $of($alloc(SyncFactoryException));
}

void SyncFactoryException::init$() {
	$SQLException::init$();
}

void SyncFactoryException::init$($String* msg) {
	$SQLException::init$(msg);
}

SyncFactoryException::SyncFactoryException() {
}

SyncFactoryException::SyncFactoryException(const SyncFactoryException& e) : $SQLException(e) {
}

void SyncFactoryException::throw$() {
	throw *this;
}

$Class* SyncFactoryException::load$($String* name, bool initialize) {
	$loadClass(SyncFactoryException, name, initialize, &_SyncFactoryException_ClassInfo_, allocate$SyncFactoryException);
	return class$;
}

$Class* SyncFactoryException::class$ = nullptr;

			} // spi
		} // rowset
	} // sql
} // javax
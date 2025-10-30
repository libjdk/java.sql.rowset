#include <javax/sql/rowset/spi/SyncFactory$1.h>

#include <javax/sql/rowset/spi/SyncFactory.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $SyncFactory = ::javax::sql::rowset::spi::SyncFactory;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

$MethodInfo _SyncFactory$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(SyncFactory$1::*)()>(&SyncFactory$1::init$))},
	{"run", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _SyncFactory$1_EnclosingMethodInfo_ = {
	"javax.sql.rowset.spi.SyncFactory",
	"initMapIfNecessary",
	"()V"
};

$InnerClassInfo _SyncFactory$1_InnerClassesInfo_[] = {
	{"javax.sql.rowset.spi.SyncFactory$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SyncFactory$1_ClassInfo_ = {
	$ACC_SUPER,
	"javax.sql.rowset.spi.SyncFactory$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_SyncFactory$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/String;>;",
	&_SyncFactory$1_EnclosingMethodInfo_,
	_SyncFactory$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.sql.rowset.spi.SyncFactory"
};

$Object* allocate$SyncFactory$1($Class* clazz) {
	return $of($alloc(SyncFactory$1));
}

void SyncFactory$1::init$() {
}

$Object* SyncFactory$1::run() {
	return $of($System::getProperty("rowset.properties"_s));
}

SyncFactory$1::SyncFactory$1() {
}

$Class* SyncFactory$1::load$($String* name, bool initialize) {
	$loadClass(SyncFactory$1, name, initialize, &_SyncFactory$1_ClassInfo_, allocate$SyncFactory$1);
	return class$;
}

$Class* SyncFactory$1::class$ = nullptr;

			} // spi
		} // rowset
	} // sql
} // javax
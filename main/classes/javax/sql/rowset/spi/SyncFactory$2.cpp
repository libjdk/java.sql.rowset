#include <javax/sql/rowset/spi/SyncFactory$2.h>

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

$MethodInfo _SyncFactory$2_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(SyncFactory$2::*)()>(&SyncFactory$2::init$))},
	{"run", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _SyncFactory$2_EnclosingMethodInfo_ = {
	"javax.sql.rowset.spi.SyncFactory",
	"initMapIfNecessary",
	"()V"
};

$InnerClassInfo _SyncFactory$2_InnerClassesInfo_[] = {
	{"javax.sql.rowset.spi.SyncFactory$2", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SyncFactory$2_ClassInfo_ = {
	$ACC_SUPER,
	"javax.sql.rowset.spi.SyncFactory$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_SyncFactory$2_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/String;>;",
	&_SyncFactory$2_EnclosingMethodInfo_,
	_SyncFactory$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.sql.rowset.spi.SyncFactory"
};

$Object* allocate$SyncFactory$2($Class* clazz) {
	return $of($alloc(SyncFactory$2));
}

void SyncFactory$2::init$() {
}

$Object* SyncFactory$2::run() {
	return $of($System::getProperty("rowset.provider.classname"_s));
}

SyncFactory$2::SyncFactory$2() {
}

$Class* SyncFactory$2::load$($String* name, bool initialize) {
	$loadClass(SyncFactory$2, name, initialize, &_SyncFactory$2_ClassInfo_, allocate$SyncFactory$2);
	return class$;
}

$Class* SyncFactory$2::class$ = nullptr;

			} // spi
		} // rowset
	} // sql
} // javax
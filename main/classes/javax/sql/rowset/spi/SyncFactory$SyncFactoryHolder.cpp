#include <javax/sql/rowset/spi/SyncFactory$SyncFactoryHolder.h>

#include <javax/sql/rowset/spi/SyncFactory.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SyncFactory = ::javax::sql::rowset::spi::SyncFactory;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

$FieldInfo _SyncFactory$SyncFactoryHolder_FieldInfo_[] = {
	{"factory", "Ljavax/sql/rowset/spi/SyncFactory;", nullptr, $STATIC | $FINAL, $staticField(SyncFactory$SyncFactoryHolder, factory)},
	{}
};

$MethodInfo _SyncFactory$SyncFactoryHolder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(SyncFactory$SyncFactoryHolder::*)()>(&SyncFactory$SyncFactoryHolder::init$))},
	{}
};

$InnerClassInfo _SyncFactory$SyncFactoryHolder_InnerClassesInfo_[] = {
	{"javax.sql.rowset.spi.SyncFactory$SyncFactoryHolder", "javax.sql.rowset.spi.SyncFactory", "SyncFactoryHolder", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _SyncFactory$SyncFactoryHolder_ClassInfo_ = {
	$ACC_SUPER,
	"javax.sql.rowset.spi.SyncFactory$SyncFactoryHolder",
	"java.lang.Object",
	nullptr,
	_SyncFactory$SyncFactoryHolder_FieldInfo_,
	_SyncFactory$SyncFactoryHolder_MethodInfo_,
	nullptr,
	nullptr,
	_SyncFactory$SyncFactoryHolder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.sql.rowset.spi.SyncFactory"
};

$Object* allocate$SyncFactory$SyncFactoryHolder($Class* clazz) {
	return $of($alloc(SyncFactory$SyncFactoryHolder));
}

$SyncFactory* SyncFactory$SyncFactoryHolder::factory = nullptr;

void SyncFactory$SyncFactoryHolder::init$() {
}

void clinit$SyncFactory$SyncFactoryHolder($Class* class$) {
	$assignStatic(SyncFactory$SyncFactoryHolder::factory, $new($SyncFactory));
}

SyncFactory$SyncFactoryHolder::SyncFactory$SyncFactoryHolder() {
}

$Class* SyncFactory$SyncFactoryHolder::load$($String* name, bool initialize) {
	$loadClass(SyncFactory$SyncFactoryHolder, name, initialize, &_SyncFactory$SyncFactoryHolder_ClassInfo_, clinit$SyncFactory$SyncFactoryHolder, allocate$SyncFactory$SyncFactoryHolder);
	return class$;
}

$Class* SyncFactory$SyncFactoryHolder::class$ = nullptr;

			} // spi
		} // rowset
	} // sql
} // javax
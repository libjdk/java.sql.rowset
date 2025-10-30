#include <com/sun/rowset/CachedRowSetImpl$1.h>

#include <com/sun/rowset/CachedRowSetImpl.h>
#include <javax/sql/rowset/spi/SyncFactory.h>
#include <javax/sql/rowset/spi/SyncProvider.h>
#include <jcpp.h>

#undef DEFAULT_SYNC_PROVIDER

using $CachedRowSetImpl = ::com::sun::rowset::CachedRowSetImpl;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $SyncFactory = ::javax::sql::rowset::spi::SyncFactory;
using $SyncProvider = ::javax::sql::rowset::spi::SyncProvider;

namespace com {
	namespace sun {
		namespace rowset {

$FieldInfo _CachedRowSetImpl$1_FieldInfo_[] = {
	{"this$0", "Lcom/sun/rowset/CachedRowSetImpl;", nullptr, $FINAL | $SYNTHETIC, $field(CachedRowSetImpl$1, this$0)},
	{}
};

$MethodInfo _CachedRowSetImpl$1_MethodInfo_[] = {
	{"<init>", "(Lcom/sun/rowset/CachedRowSetImpl;)V", nullptr, 0, $method(static_cast<void(CachedRowSetImpl$1::*)($CachedRowSetImpl*)>(&CachedRowSetImpl$1::init$))},
	{"run", "()Ljavax/sql/rowset/spi/SyncProvider;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.spi.SyncFactoryException"},
	{}
};

$EnclosingMethodInfo _CachedRowSetImpl$1_EnclosingMethodInfo_ = {
	"com.sun.rowset.CachedRowSetImpl",
	"<init>",
	"()V"
};

$InnerClassInfo _CachedRowSetImpl$1_InnerClassesInfo_[] = {
	{"com.sun.rowset.CachedRowSetImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _CachedRowSetImpl$1_ClassInfo_ = {
	$ACC_SUPER,
	"com.sun.rowset.CachedRowSetImpl$1",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	_CachedRowSetImpl$1_FieldInfo_,
	_CachedRowSetImpl$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedExceptionAction<Ljavax/sql/rowset/spi/SyncProvider;>;",
	&_CachedRowSetImpl$1_EnclosingMethodInfo_,
	_CachedRowSetImpl$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"com.sun.rowset.CachedRowSetImpl"
};

$Object* allocate$CachedRowSetImpl$1($Class* clazz) {
	return $of($alloc(CachedRowSetImpl$1));
}

void CachedRowSetImpl$1::init$($CachedRowSetImpl* this$0) {
	$set(this, this$0, this$0);
}

$Object* CachedRowSetImpl$1::run() {
	return $of($SyncFactory::getInstance(this->this$0->DEFAULT_SYNC_PROVIDER));
}

CachedRowSetImpl$1::CachedRowSetImpl$1() {
}

$Class* CachedRowSetImpl$1::load$($String* name, bool initialize) {
	$loadClass(CachedRowSetImpl$1, name, initialize, &_CachedRowSetImpl$1_ClassInfo_, allocate$CachedRowSetImpl$1);
	return class$;
}

$Class* CachedRowSetImpl$1::class$ = nullptr;

		} // rowset
	} // sun
} // com
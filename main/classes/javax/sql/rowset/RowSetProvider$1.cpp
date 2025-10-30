#include <javax/sql/rowset/RowSetProvider$1.h>

#include <java/lang/ClassLoader.h>
#include <javax/sql/rowset/RowSetProvider.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $RowSetProvider = ::javax::sql::rowset::RowSetProvider;

namespace javax {
	namespace sql {
		namespace rowset {

$MethodInfo _RowSetProvider$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(RowSetProvider$1::*)()>(&RowSetProvider$1::init$))},
	{"run", "()Ljava/lang/ClassLoader;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _RowSetProvider$1_EnclosingMethodInfo_ = {
	"javax.sql.rowset.RowSetProvider",
	"getContextClassLoader",
	"()Ljava/lang/ClassLoader;"
};

$InnerClassInfo _RowSetProvider$1_InnerClassesInfo_[] = {
	{"javax.sql.rowset.RowSetProvider$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RowSetProvider$1_ClassInfo_ = {
	$ACC_SUPER,
	"javax.sql.rowset.RowSetProvider$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_RowSetProvider$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/ClassLoader;>;",
	&_RowSetProvider$1_EnclosingMethodInfo_,
	_RowSetProvider$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.sql.rowset.RowSetProvider"
};

$Object* allocate$RowSetProvider$1($Class* clazz) {
	return $of($alloc(RowSetProvider$1));
}

void RowSetProvider$1::init$() {
}

$Object* RowSetProvider$1::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ClassLoader, cl, nullptr);
	$assign(cl, $($Thread::currentThread())->getContextClassLoader());
	if (cl == nullptr) {
		$assign(cl, $ClassLoader::getSystemClassLoader());
	}
	return $of(cl);
}

RowSetProvider$1::RowSetProvider$1() {
}

$Class* RowSetProvider$1::load$($String* name, bool initialize) {
	$loadClass(RowSetProvider$1, name, initialize, &_RowSetProvider$1_ClassInfo_, allocate$RowSetProvider$1);
	return class$;
}

$Class* RowSetProvider$1::class$ = nullptr;

		} // rowset
	} // sql
} // javax
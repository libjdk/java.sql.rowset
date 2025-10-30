#include <javax/sql/rowset/RowSetProvider$2.h>

#include <javax/sql/rowset/RowSetProvider.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $RowSetProvider = ::javax::sql::rowset::RowSetProvider;

namespace javax {
	namespace sql {
		namespace rowset {

$FieldInfo _RowSetProvider$2_FieldInfo_[] = {
	{"val$propName", "Ljava/lang/String;", nullptr, $FINAL | $SYNTHETIC, $field(RowSetProvider$2, val$propName)},
	{}
};

$MethodInfo _RowSetProvider$2_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", "()V", 0, $method(static_cast<void(RowSetProvider$2::*)($String*)>(&RowSetProvider$2::init$))},
	{"run", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _RowSetProvider$2_EnclosingMethodInfo_ = {
	"javax.sql.rowset.RowSetProvider",
	"getSystemProperty",
	"(Ljava/lang/String;)Ljava/lang/String;"
};

$InnerClassInfo _RowSetProvider$2_InnerClassesInfo_[] = {
	{"javax.sql.rowset.RowSetProvider$2", nullptr, nullptr, 0},
	{}
};

$ClassInfo _RowSetProvider$2_ClassInfo_ = {
	$ACC_SUPER,
	"javax.sql.rowset.RowSetProvider$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_RowSetProvider$2_FieldInfo_,
	_RowSetProvider$2_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/String;>;",
	&_RowSetProvider$2_EnclosingMethodInfo_,
	_RowSetProvider$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.sql.rowset.RowSetProvider"
};

$Object* allocate$RowSetProvider$2($Class* clazz) {
	return $of($alloc(RowSetProvider$2));
}

void RowSetProvider$2::init$($String* val$propName) {
	$set(this, val$propName, val$propName);
}

$Object* RowSetProvider$2::run() {
	return $of($System::getProperty(this->val$propName));
}

RowSetProvider$2::RowSetProvider$2() {
}

$Class* RowSetProvider$2::load$($String* name, bool initialize) {
	$loadClass(RowSetProvider$2, name, initialize, &_RowSetProvider$2_ClassInfo_, allocate$RowSetProvider$2);
	return class$;
}

$Class* RowSetProvider$2::class$ = nullptr;

		} // rowset
	} // sql
} // javax
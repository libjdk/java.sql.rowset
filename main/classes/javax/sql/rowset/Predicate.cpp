#include <javax/sql/rowset/Predicate.h>

#include <javax/sql/RowSet.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RowSet = ::javax::sql::RowSet;

namespace javax {
	namespace sql {
		namespace rowset {

$MethodInfo _Predicate_MethodInfo_[] = {
	{"evaluate", "(Ljavax/sql/RowSet;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{"evaluate", "(Ljava/lang/Object;I)Z", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"evaluate", "(Ljava/lang/Object;Ljava/lang/String;)Z", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{}
};

$ClassInfo _Predicate_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"javax.sql.rowset.Predicate",
	nullptr,
	nullptr,
	nullptr,
	_Predicate_MethodInfo_
};

$Object* allocate$Predicate($Class* clazz) {
	return $of($alloc(Predicate));
}

$Class* Predicate::load$($String* name, bool initialize) {
	$loadClass(Predicate, name, initialize, &_Predicate_ClassInfo_, allocate$Predicate);
	return class$;
}

$Class* Predicate::class$ = nullptr;

		} // rowset
	} // sql
} // javax
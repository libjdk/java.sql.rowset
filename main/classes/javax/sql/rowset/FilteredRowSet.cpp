#include <javax/sql/rowset/FilteredRowSet.h>

#include <javax/sql/rowset/Predicate.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Predicate = ::javax::sql::rowset::Predicate;
using $WebRowSet = ::javax::sql::rowset::WebRowSet;

namespace javax {
	namespace sql {
		namespace rowset {

$MethodInfo _FilteredRowSet_MethodInfo_[] = {
	{"getFilter", "()Ljavax/sql/rowset/Predicate;", nullptr, $PUBLIC | $ABSTRACT},
	{"setFilter", "(Ljavax/sql/rowset/Predicate;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{}
};

$ClassInfo _FilteredRowSet_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"javax.sql.rowset.FilteredRowSet",
	nullptr,
	"javax.sql.rowset.WebRowSet",
	nullptr,
	_FilteredRowSet_MethodInfo_
};

$Object* allocate$FilteredRowSet($Class* clazz) {
	return $of($alloc(FilteredRowSet));
}

$Class* FilteredRowSet::load$($String* name, bool initialize) {
	$loadClass(FilteredRowSet, name, initialize, &_FilteredRowSet_ClassInfo_, allocate$FilteredRowSet);
	return class$;
}

$Class* FilteredRowSet::class$ = nullptr;

		} // rowset
	} // sql
} // javax
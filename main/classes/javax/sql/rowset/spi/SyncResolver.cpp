#include <javax/sql/rowset/spi/SyncResolver.h>

#include <jcpp.h>

#undef DELETE_ROW_CONFLICT
#undef INSERT_ROW_CONFLICT
#undef NO_ROW_CONFLICT
#undef UPDATE_ROW_CONFLICT

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RowSet = ::javax::sql::RowSet;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

$FieldInfo _SyncResolver_FieldInfo_[] = {
	{"UPDATE_ROW_CONFLICT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SyncResolver, UPDATE_ROW_CONFLICT)},
	{"DELETE_ROW_CONFLICT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SyncResolver, DELETE_ROW_CONFLICT)},
	{"INSERT_ROW_CONFLICT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SyncResolver, INSERT_ROW_CONFLICT)},
	{"NO_ROW_CONFLICT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SyncResolver, NO_ROW_CONFLICT)},
	{}
};

$MethodInfo _SyncResolver_MethodInfo_[] = {
	{"getConflictValue", "(I)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"getConflictValue", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"getStatus", "()I", nullptr, $PUBLIC | $ABSTRACT},
	{"nextConflict", "()Z", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"previousConflict", "()Z", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"setResolvedValue", "(ILjava/lang/Object;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"setResolvedValue", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{}
};

$ClassInfo _SyncResolver_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"javax.sql.rowset.spi.SyncResolver",
	nullptr,
	"javax.sql.RowSet",
	_SyncResolver_FieldInfo_,
	_SyncResolver_MethodInfo_
};

$Object* allocate$SyncResolver($Class* clazz) {
	return $of($alloc(SyncResolver));
}

$Class* SyncResolver::load$($String* name, bool initialize) {
	$loadClass(SyncResolver, name, initialize, &_SyncResolver_ClassInfo_, allocate$SyncResolver);
	return class$;
}

$Class* SyncResolver::class$ = nullptr;

			} // spi
		} // rowset
	} // sql
} // javax
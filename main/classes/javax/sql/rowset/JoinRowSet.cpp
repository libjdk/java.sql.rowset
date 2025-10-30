#include <javax/sql/rowset/JoinRowSet.h>

#include <java/util/Collection.h>
#include <javax/sql/RowSet.h>
#include <javax/sql/rowset/CachedRowSet.h>
#include <jcpp.h>

#undef CROSS_JOIN
#undef FULL_JOIN
#undef INNER_JOIN
#undef LEFT_OUTER_JOIN
#undef RIGHT_OUTER_JOIN

using $RowSetArray = $Array<::javax::sql::RowSet>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collection = ::java::util::Collection;
using $RowSet = ::javax::sql::RowSet;
using $CachedRowSet = ::javax::sql::rowset::CachedRowSet;
using $Joinable = ::javax::sql::rowset::Joinable;
using $WebRowSet = ::javax::sql::rowset::WebRowSet;

namespace javax {
	namespace sql {
		namespace rowset {

$FieldInfo _JoinRowSet_FieldInfo_[] = {
	{"CROSS_JOIN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(JoinRowSet, CROSS_JOIN)},
	{"INNER_JOIN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(JoinRowSet, INNER_JOIN)},
	{"LEFT_OUTER_JOIN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(JoinRowSet, LEFT_OUTER_JOIN)},
	{"RIGHT_OUTER_JOIN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(JoinRowSet, RIGHT_OUTER_JOIN)},
	{"FULL_JOIN", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(JoinRowSet, FULL_JOIN)},
	{}
};

$MethodInfo _JoinRowSet_MethodInfo_[] = {
	{"addRowSet", "(Ljavax/sql/rowset/Joinable;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"addRowSet", "(Ljavax/sql/RowSet;I)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"addRowSet", "(Ljavax/sql/RowSet;Ljava/lang/String;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"addRowSet", "([Ljavax/sql/RowSet;[I)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"addRowSet", "([Ljavax/sql/RowSet;[Ljava/lang/String;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"getJoinType", "()I", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"getRowSetNames", "()[Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"getRowSets", "()Ljava/util/Collection;", "()Ljava/util/Collection<*>;", $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"getWhereClause", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"setJoinType", "(I)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"supportsCrossJoin", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"supportsFullJoin", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"supportsInnerJoin", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"supportsLeftOuterJoin", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"supportsRightOuterJoin", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"toCachedRowSet", "()Ljavax/sql/rowset/CachedRowSet;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{}
};

$ClassInfo _JoinRowSet_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"javax.sql.rowset.JoinRowSet",
	nullptr,
	"javax.sql.rowset.WebRowSet",
	_JoinRowSet_FieldInfo_,
	_JoinRowSet_MethodInfo_
};

$Object* allocate$JoinRowSet($Class* clazz) {
	return $of($alloc(JoinRowSet));
}

$Class* JoinRowSet::load$($String* name, bool initialize) {
	$loadClass(JoinRowSet, name, initialize, &_JoinRowSet_ClassInfo_, allocate$JoinRowSet);
	return class$;
}

$Class* JoinRowSet::class$ = nullptr;

		} // rowset
	} // sql
} // javax
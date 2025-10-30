#include <javax/sql/rowset/JdbcRowSet.h>

#include <java/sql/Savepoint.h>
#include <javax/sql/RowSet.h>
#include <javax/sql/rowset/RowSetWarning.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Savepoint = ::java::sql::Savepoint;
using $RowSet = ::javax::sql::RowSet;
using $Joinable = ::javax::sql::rowset::Joinable;
using $RowSetWarning = ::javax::sql::rowset::RowSetWarning;

namespace javax {
	namespace sql {
		namespace rowset {

$MethodInfo _JdbcRowSet_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"commit", "()V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"getAutoCommit", "()Z", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"getRowSetWarnings", "()Ljavax/sql/rowset/RowSetWarning;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"getShowDeleted", "()Z", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"rollback", "()V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"rollback", "(Ljava/sql/Savepoint;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"setAutoCommit", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"setShowDeleted", "(Z)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _JdbcRowSet_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"javax.sql.rowset.JdbcRowSet",
	nullptr,
	"javax.sql.RowSet,javax.sql.rowset.Joinable",
	nullptr,
	_JdbcRowSet_MethodInfo_
};

$Object* allocate$JdbcRowSet($Class* clazz) {
	return $of($alloc(JdbcRowSet));
}

int32_t JdbcRowSet::hashCode() {
	 return this->$RowSet::hashCode();
}

bool JdbcRowSet::equals(Object$* arg0) {
	 return this->$RowSet::equals(arg0);
}

$Object* JdbcRowSet::clone() {
	 return this->$RowSet::clone();
}

$String* JdbcRowSet::toString() {
	 return this->$RowSet::toString();
}

void JdbcRowSet::finalize() {
	this->$RowSet::finalize();
}

$Class* JdbcRowSet::load$($String* name, bool initialize) {
	$loadClass(JdbcRowSet, name, initialize, &_JdbcRowSet_ClassInfo_, allocate$JdbcRowSet);
	return class$;
}

$Class* JdbcRowSet::class$ = nullptr;

		} // rowset
	} // sql
} // javax
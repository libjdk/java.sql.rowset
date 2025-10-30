#include <javax/sql/rowset/spi/TransactionalWriter.h>

#include <java/sql/Savepoint.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Savepoint = ::java::sql::Savepoint;
using $RowSetWriter = ::javax::sql::RowSetWriter;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

$MethodInfo _TransactionalWriter_MethodInfo_[] = {
	{"commit", "()V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"rollback", "()V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"rollback", "(Ljava/sql/Savepoint;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{}
};

$ClassInfo _TransactionalWriter_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"javax.sql.rowset.spi.TransactionalWriter",
	nullptr,
	"javax.sql.RowSetWriter",
	nullptr,
	_TransactionalWriter_MethodInfo_
};

$Object* allocate$TransactionalWriter($Class* clazz) {
	return $of($alloc(TransactionalWriter));
}

$Class* TransactionalWriter::load$($String* name, bool initialize) {
	$loadClass(TransactionalWriter, name, initialize, &_TransactionalWriter_ClassInfo_, allocate$TransactionalWriter);
	return class$;
}

$Class* TransactionalWriter::class$ = nullptr;

			} // spi
		} // rowset
	} // sql
} // javax
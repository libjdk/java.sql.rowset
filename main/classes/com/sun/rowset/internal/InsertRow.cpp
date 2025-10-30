#include <com/sun/rowset/internal/InsertRow.h>

#include <com/sun/rowset/JdbcRowSetResourceBundle.h>
#include <com/sun/rowset/internal/BaseRow.h>
#include <java/io/IOException.h>
#include <java/io/ObjectInputStream.h>
#include <java/sql/ResultSetMetaData.h>
#include <java/sql/SQLException.h>
#include <java/util/BitSet.h>
#include <javax/sql/RowSetMetaData.h>
#include <jcpp.h>

using $JdbcRowSetResourceBundle = ::com::sun::rowset::JdbcRowSetResourceBundle;
using $BaseRow = ::com::sun::rowset::internal::BaseRow;
using $IOException = ::java::io::IOException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $ResultSetMetaData = ::java::sql::ResultSetMetaData;
using $SQLException = ::java::sql::SQLException;
using $BitSet = ::java::util::BitSet;
using $RowSetMetaData = ::javax::sql::RowSetMetaData;

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

$FieldInfo _InsertRow_FieldInfo_[] = {
	{"colsInserted", "Ljava/util/BitSet;", nullptr, $PRIVATE, $field(InsertRow, colsInserted)},
	{"cols", "I", nullptr, $PRIVATE, $field(InsertRow, cols)},
	{"resBundle", "Lcom/sun/rowset/JdbcRowSetResourceBundle;", nullptr, $PRIVATE, $field(InsertRow, resBundle)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(InsertRow, serialVersionUID)},
	{}
};

$MethodInfo _InsertRow_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(InsertRow::*)(int32_t)>(&InsertRow::init$))},
	{"getColumnObject", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"initInsertRow", "()V", nullptr, $PUBLIC},
	{"isCompleteRow", "(Ljavax/sql/RowSetMetaData;)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"markColInserted", "(I)V", nullptr, $PROTECTED},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(InsertRow::*)($ObjectInputStream*)>(&InsertRow::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"setColumnObject", "(ILjava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};

$ClassInfo _InsertRow_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.rowset.internal.InsertRow",
	"com.sun.rowset.internal.BaseRow",
	nullptr,
	_InsertRow_FieldInfo_,
	_InsertRow_MethodInfo_
};

$Object* allocate$InsertRow($Class* clazz) {
	return $of($alloc(InsertRow));
}

void InsertRow::init$(int32_t numCols) {
	$BaseRow::init$();
	$set(this, origVals, $new($ObjectArray, numCols));
	$set(this, colsInserted, $new($BitSet, numCols));
	this->cols = numCols;
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

void InsertRow::markColInserted(int32_t col) {
	$nc(this->colsInserted)->set(col);
}

bool InsertRow::isCompleteRow($RowSetMetaData* RowSetMD) {
	for (int32_t i = 0; i < this->cols; ++i) {
		bool var$0 = $nc(this->colsInserted)->get(i) == false;
		if (var$0 && $nc(RowSetMD)->isNullable(i + 1) == $ResultSetMetaData::columnNoNulls) {
			return false;
		}
	}
	return true;
}

void InsertRow::initInsertRow() {
	for (int32_t i = 0; i < this->cols; ++i) {
		$nc(this->colsInserted)->clear(i);
	}
}

$Object* InsertRow::getColumnObject(int32_t idx) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->colsInserted)->get(idx - 1) == false) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("insertrow.novalue"_s))))->toString()));
	}
	return $of(($nc(this->origVals)->get(idx - 1)));
}

void InsertRow::setColumnObject(int32_t idx, Object$* val) {
	$nc(this->origVals)->set(idx - 1, val);
	markColInserted(idx - 1);
}

void InsertRow::readObject($ObjectInputStream* ois) {
	$nc(ois)->defaultReadObject();
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

InsertRow::InsertRow() {
}

$Class* InsertRow::load$($String* name, bool initialize) {
	$loadClass(InsertRow, name, initialize, &_InsertRow_ClassInfo_, allocate$InsertRow);
	return class$;
}

$Class* InsertRow::class$ = nullptr;

			} // internal
		} // rowset
	} // sun
} // com
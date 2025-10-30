#include <com/sun/rowset/internal/Row.h>

#include <com/sun/rowset/internal/BaseRow.h>
#include <java/util/BitSet.h>
#include <jcpp.h>

using $BaseRow = ::com::sun::rowset::internal::BaseRow;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $BitSet = ::java::util::BitSet;

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

$FieldInfo _Row_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(Row, serialVersionUID)},
	{"currentVals", "[Ljava/lang/Object;", nullptr, $PRIVATE, $field(Row, currentVals)},
	{"colsChanged", "Ljava/util/BitSet;", nullptr, $PRIVATE, $field(Row, colsChanged)},
	{"deleted", "Z", nullptr, $PRIVATE, $field(Row, deleted)},
	{"updated", "Z", nullptr, $PRIVATE, $field(Row, updated)},
	{"inserted", "Z", nullptr, $PRIVATE, $field(Row, inserted)},
	{"numCols", "I", nullptr, $PRIVATE, $field(Row, numCols)},
	{}
};

$MethodInfo _Row_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(Row::*)(int32_t)>(&Row::init$))},
	{"<init>", "(I[Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(static_cast<void(Row::*)(int32_t,$ObjectArray*)>(&Row::init$))},
	{"clearDeleted", "()V", nullptr, $PUBLIC},
	{"clearInserted", "()V", nullptr, $PUBLIC},
	{"clearUpdated", "()V", nullptr, $PUBLIC},
	{"getColUpdated", "(I)Z", nullptr, $PUBLIC},
	{"getColumnObject", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getCurrentRow", "()Lcom/sun/rowset/internal/BaseRow;", nullptr, $PUBLIC},
	{"getDeleted", "()Z", nullptr, $PUBLIC},
	{"getInserted", "()Z", nullptr, $PUBLIC},
	{"getUpdated", "()Z", nullptr, $PUBLIC},
	{"initColumnObject", "(ILjava/lang/Object;)V", nullptr, $PUBLIC},
	{"moveCurrentToOrig", "()V", nullptr, $PUBLIC},
	{"setColUpdated", "(I)V", nullptr, $PRIVATE, $method(static_cast<void(Row::*)(int32_t)>(&Row::setColUpdated))},
	{"setColumnObject", "(ILjava/lang/Object;)V", nullptr, $PUBLIC},
	{"setDeleted", "()V", nullptr, $PUBLIC},
	{"setInserted", "()V", nullptr, $PUBLIC},
	{"setUpdated", "()V", nullptr, $PUBLIC},
	{}
};

$ClassInfo _Row_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.rowset.internal.Row",
	"com.sun.rowset.internal.BaseRow",
	nullptr,
	_Row_FieldInfo_,
	_Row_MethodInfo_
};

$Object* allocate$Row($Class* clazz) {
	return $of($alloc(Row));
}

void Row::init$(int32_t numCols) {
	$BaseRow::init$();
	$set(this, origVals, $new($ObjectArray, numCols));
	$set(this, currentVals, $new($ObjectArray, numCols));
	$set(this, colsChanged, $new($BitSet, numCols));
	this->numCols = numCols;
}

void Row::init$(int32_t numCols, $ObjectArray* vals) {
	$BaseRow::init$();
	$set(this, origVals, $new($ObjectArray, numCols));
	$System::arraycopy(vals, 0, this->origVals, 0, numCols);
	$set(this, currentVals, $new($ObjectArray, numCols));
	$set(this, colsChanged, $new($BitSet, numCols));
	this->numCols = numCols;
}

void Row::initColumnObject(int32_t idx, Object$* val) {
	$nc(this->origVals)->set(idx - 1, val);
}

void Row::setColumnObject(int32_t idx, Object$* val) {
	$nc(this->currentVals)->set(idx - 1, val);
	setColUpdated(idx - 1);
}

$Object* Row::getColumnObject(int32_t columnIndex) {
	if (getColUpdated(columnIndex - 1)) {
		return $of(($nc(this->currentVals)->get(columnIndex - 1)));
	} else {
		return $of(($nc(this->origVals)->get(columnIndex - 1)));
	}
}

bool Row::getColUpdated(int32_t idx) {
	return $nc(this->colsChanged)->get(idx);
}

void Row::setDeleted() {
	this->deleted = true;
}

bool Row::getDeleted() {
	return (this->deleted);
}

void Row::clearDeleted() {
	this->deleted = false;
}

void Row::setInserted() {
	this->inserted = true;
}

bool Row::getInserted() {
	return (this->inserted);
}

void Row::clearInserted() {
	this->inserted = false;
}

bool Row::getUpdated() {
	return (this->updated);
}

void Row::setUpdated() {
	for (int32_t i = 0; i < this->numCols; ++i) {
		if (getColUpdated(i) == true) {
			this->updated = true;
			return;
		}
	}
}

void Row::setColUpdated(int32_t idx) {
	$nc(this->colsChanged)->set(idx);
}

void Row::clearUpdated() {
	this->updated = false;
	for (int32_t i = 0; i < this->numCols; ++i) {
		$nc(this->currentVals)->set(i, nullptr);
		$nc(this->colsChanged)->clear(i);
	}
}

void Row::moveCurrentToOrig() {
	for (int32_t i = 0; i < this->numCols; ++i) {
		if (getColUpdated(i) == true) {
			$nc(this->origVals)->set(i, $nc(this->currentVals)->get(i));
			$nc(this->currentVals)->set(i, nullptr);
			$nc(this->colsChanged)->clear(i);
		}
	}
	this->updated = false;
}

$BaseRow* Row::getCurrentRow() {
	return nullptr;
}

Row::Row() {
}

$Class* Row::load$($String* name, bool initialize) {
	$loadClass(Row, name, initialize, &_Row_ClassInfo_, allocate$Row);
	return class$;
}

$Class* Row::class$ = nullptr;

			} // internal
		} // rowset
	} // sun
} // com
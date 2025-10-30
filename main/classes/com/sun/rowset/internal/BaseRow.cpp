#include <com/sun/rowset/internal/BaseRow.h>

#include <java/io/Serializable.h>
#include <java/util/Arrays.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Arrays = ::java::util::Arrays;

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

$FieldInfo _BaseRow_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(BaseRow, serialVersionUID)},
	{"origVals", "[Ljava/lang/Object;", nullptr, $PROTECTED, $field(BaseRow, origVals)},
	{}
};

$MethodInfo _BaseRow_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(BaseRow::*)()>(&BaseRow::init$))},
	{"getColumnObject", "(I)Ljava/lang/Object;", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"getOrigRow", "()[Ljava/lang/Object;", nullptr, $PUBLIC},
	{"setColumnObject", "(ILjava/lang/Object;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _BaseRow_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"com.sun.rowset.internal.BaseRow",
	"java.lang.Object",
	"java.io.Serializable,java.lang.Cloneable",
	_BaseRow_FieldInfo_,
	_BaseRow_MethodInfo_
};

$Object* allocate$BaseRow($Class* clazz) {
	return $of($alloc(BaseRow));
}

int32_t BaseRow::hashCode() {
	 return this->$Serializable::hashCode();
}

bool BaseRow::equals(Object$* arg0) {
	 return this->$Serializable::equals(arg0);
}

$Object* BaseRow::clone() {
	 return this->$Serializable::clone();
}

$String* BaseRow::toString() {
	 return this->$Serializable::toString();
}

void BaseRow::finalize() {
	this->$Serializable::finalize();
}

void BaseRow::init$() {
}

$ObjectArray* BaseRow::getOrigRow() {
	$var($ObjectArray, origRow, this->origVals);
	return (origRow == nullptr) ? ($ObjectArray*)nullptr : $Arrays::copyOf(origRow, $nc(origRow)->length);
}

BaseRow::BaseRow() {
}

$Class* BaseRow::load$($String* name, bool initialize) {
	$loadClass(BaseRow, name, initialize, &_BaseRow_ClassInfo_, allocate$BaseRow);
	return class$;
}

$Class* BaseRow::class$ = nullptr;

			} // internal
		} // rowset
	} // sun
} // com
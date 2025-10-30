#include <javax/sql/rowset/serial/SerialException.h>

#include <java/sql/SQLException.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SQLException = ::java::sql::SQLException;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace serial {

$FieldInfo _SerialException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(SerialException, serialVersionUID)},
	{}
};

$MethodInfo _SerialException_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SerialException::*)()>(&SerialException::init$))},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(SerialException::*)($String*)>(&SerialException::init$))},
	{}
};

$ClassInfo _SerialException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.sql.rowset.serial.SerialException",
	"java.sql.SQLException",
	nullptr,
	_SerialException_FieldInfo_,
	_SerialException_MethodInfo_
};

$Object* allocate$SerialException($Class* clazz) {
	return $of($alloc(SerialException));
}

void SerialException::init$() {
	$SQLException::init$();
}

void SerialException::init$($String* msg) {
	$SQLException::init$(msg);
}

SerialException::SerialException() {
}

SerialException::SerialException(const SerialException& e) : $SQLException(e) {
}

void SerialException::throw$() {
	throw *this;
}

$Class* SerialException::load$($String* name, bool initialize) {
	$loadClass(SerialException, name, initialize, &_SerialException_ClassInfo_, allocate$SerialException);
	return class$;
}

$Class* SerialException::class$ = nullptr;

			} // serial
		} // rowset
	} // sql
} // javax
#include <javax/sql/rowset/serial/SerialDatalink.h>

#include <java/io/Serializable.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/net/MalformedURLException.h>
#include <java/net/URL.h>
#include <javax/sql/rowset/serial/SerialException.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $MalformedURLException = ::java::net::MalformedURLException;
using $URL = ::java::net::URL;
using $SerialException = ::javax::sql::rowset::serial::SerialException;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace serial {

$FieldInfo _SerialDatalink_FieldInfo_[] = {
	{"url", "Ljava/net/URL;", nullptr, $PRIVATE, $field(SerialDatalink, url)},
	{"baseType", "I", nullptr, $PRIVATE, $field(SerialDatalink, baseType)},
	{"baseTypeName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(SerialDatalink, baseTypeName)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(SerialDatalink, serialVersionUID)},
	{}
};

$MethodInfo _SerialDatalink_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/net/URL;)V", nullptr, $PUBLIC, $method(static_cast<void(SerialDatalink::*)($URL*)>(&SerialDatalink::init$)), "javax.sql.rowset.serial.SerialException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getDatalink", "()Ljava/net/URL;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _SerialDatalink_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.sql.rowset.serial.SerialDatalink",
	"java.lang.Object",
	"java.io.Serializable,java.lang.Cloneable",
	_SerialDatalink_FieldInfo_,
	_SerialDatalink_MethodInfo_
};

$Object* allocate$SerialDatalink($Class* clazz) {
	return $of($alloc(SerialDatalink));
}

$String* SerialDatalink::toString() {
	 return this->$Serializable::toString();
}

void SerialDatalink::finalize() {
	this->$Serializable::finalize();
}

void SerialDatalink::init$($URL* url) {
	if (url == nullptr) {
		$throwNew($SerialException, "Cannot serialize empty URL instance"_s);
	}
	$set(this, url, url);
}

$URL* SerialDatalink::getDatalink() {
	$useLocalCurrentObjectStackCache();
	$var($URL, aURL, nullptr);
	try {
		$assign(aURL, $new($URL, $($nc((this->url))->toString())));
	} catch ($MalformedURLException& e) {
		$throwNew($SerialException, $$str({"MalformedURLException: "_s, $(e->getMessage())}));
	}
	return aURL;
}

bool SerialDatalink::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if ($instanceOf(SerialDatalink, obj)) {
		$var(SerialDatalink, sdl, $cast(SerialDatalink, obj));
		return $nc(this->url)->equals($nc(sdl)->url);
	}
	return false;
}

int32_t SerialDatalink::hashCode() {
	return 31 + $nc(this->url)->hashCode();
}

$Object* SerialDatalink::clone() {
	try {
		$var(SerialDatalink, sdl, $cast(SerialDatalink, $Serializable::clone()));
		return $of(sdl);
	} catch ($CloneNotSupportedException& ex) {
		$throwNew($InternalError);
	}
	$shouldNotReachHere();
}

SerialDatalink::SerialDatalink() {
}

$Class* SerialDatalink::load$($String* name, bool initialize) {
	$loadClass(SerialDatalink, name, initialize, &_SerialDatalink_ClassInfo_, allocate$SerialDatalink);
	return class$;
}

$Class* SerialDatalink::class$ = nullptr;

			} // serial
		} // rowset
	} // sql
} // javax
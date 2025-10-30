#include <javax/sql/rowset/serial/SerialRef.h>

#include <java/io/ObjectInputStream$GetField.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream$PutField.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/sql/Ref.h>
#include <java/sql/SQLException.h>
#include <java/util/Hashtable.h>
#include <java/util/Map.h>
#include <javax/sql/rowset/serial/SerialException.h>
#include <jcpp.h>

using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectInputStream$GetField = ::java::io::ObjectInputStream$GetField;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ObjectOutputStream$PutField = ::java::io::ObjectOutputStream$PutField;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Ref = ::java::sql::Ref;
using $SQLException = ::java::sql::SQLException;
using $Hashtable = ::java::util::Hashtable;
using $Map = ::java::util::Map;
using $SerialException = ::javax::sql::rowset::serial::SerialException;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace serial {

$FieldInfo _SerialRef_FieldInfo_[] = {
	{"baseTypeName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(SerialRef, baseTypeName)},
	{"object", "Ljava/lang/Object;", nullptr, $PRIVATE, $field(SerialRef, object)},
	{"reference", "Ljava/sql/Ref;", nullptr, $PRIVATE, $field(SerialRef, reference)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(SerialRef, serialVersionUID)},
	{}
};

$MethodInfo _SerialRef_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/sql/Ref;)V", nullptr, $PUBLIC, $method(static_cast<void(SerialRef::*)($Ref*)>(&SerialRef::init$)), "javax.sql.rowset.serial.SerialException,java.sql.SQLException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getBaseTypeName", "()Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"getObject", "(Ljava/util/Map;)Ljava/lang/Object;", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)Ljava/lang/Object;", $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"getObject", "()Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(SerialRef::*)($ObjectInputStream*)>(&SerialRef::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"setObject", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(SerialRef::*)($ObjectOutputStream*)>(&SerialRef::writeObject)), "java.io.IOException"},
	{}
};

$ClassInfo _SerialRef_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.sql.rowset.serial.SerialRef",
	"java.lang.Object",
	"java.sql.Ref,java.io.Serializable,java.lang.Cloneable",
	_SerialRef_FieldInfo_,
	_SerialRef_MethodInfo_
};

$Object* allocate$SerialRef($Class* clazz) {
	return $of($alloc(SerialRef));
}

$String* SerialRef::toString() {
	 return this->$Ref::toString();
}

void SerialRef::finalize() {
	this->$Ref::finalize();
}

void SerialRef::init$($Ref* ref) {
	if (ref == nullptr) {
		$throwNew($SQLException, "Cannot instantiate a SerialRef object with a null Ref object"_s);
	}
	$set(this, reference, ref);
	$set(this, object, ref);
	if ($nc(ref)->getBaseTypeName() == nullptr) {
		$throwNew($SQLException, "Cannot instantiate a SerialRef object that returns a null base type name"_s);
	} else {
		$set(this, baseTypeName, ref->getBaseTypeName());
	}
}

$String* SerialRef::getBaseTypeName() {
	return this->baseTypeName;
}

$Object* SerialRef::getObject($Map* map$renamed) {
	$var($Map, map, map$renamed);
	$assign(map, $new($Hashtable, map));
	if (this->object != nullptr) {
		return $of(map->get(this->object));
	} else {
		$throwNew($SerialException, "The object is not set"_s);
	}
}

$Object* SerialRef::getObject() {
	$useLocalCurrentObjectStackCache();
	if (this->reference != nullptr) {
		try {
			return $of($nc(this->reference)->getObject());
		} catch ($SQLException& e) {
			$throwNew($SerialException, $$str({"SQLException: "_s, $(e->getMessage())}));
		}
	}
	if (this->object != nullptr) {
		return $of(this->object);
	}
	$throwNew($SerialException, "The object is not set"_s);
}

void SerialRef::setObject(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	try {
		$nc(this->reference)->setObject(obj);
	} catch ($SQLException& e) {
		$throwNew($SerialException, $$str({"SQLException: "_s, $(e->getMessage())}));
	}
	$set(this, object, obj);
}

bool SerialRef::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if ($instanceOf(SerialRef, obj)) {
		$var(SerialRef, ref, $cast(SerialRef, obj));
		bool var$0 = $nc(this->baseTypeName)->equals($nc(ref)->baseTypeName);
		return var$0 && $nc($of(this->object))->equals($nc(ref)->object);
	}
	return false;
}

int32_t SerialRef::hashCode() {
	int32_t var$0 = (31 + $nc($of(this->object))->hashCode()) * 31;
	return var$0 + $nc(this->baseTypeName)->hashCode();
}

$Object* SerialRef::clone() {
	try {
		$var(SerialRef, ref, $cast(SerialRef, $Ref::clone()));
		$set($nc(ref), reference, nullptr);
		return $of(ref);
	} catch ($CloneNotSupportedException& ex) {
		$throwNew($InternalError);
	}
	$shouldNotReachHere();
}

void SerialRef::readObject($ObjectInputStream* s) {
	$var($ObjectInputStream$GetField, fields, $nc(s)->readFields());
	$set(this, object, $nc(fields)->get("object"_s, ($Object*)nullptr));
	$set(this, baseTypeName, $cast($String, fields->get("baseTypeName"_s, ($Object*)nullptr)));
	$set(this, reference, $cast($Ref, fields->get("reference"_s, ($Object*)nullptr)));
}

void SerialRef::writeObject($ObjectOutputStream* s) {
	$var($ObjectOutputStream$PutField, fields, $nc(s)->putFields());
	$nc(fields)->put("baseTypeName"_s, $of(this->baseTypeName));
	fields->put("object"_s, this->object);
	fields->put("reference"_s, $instanceOf($Serializable, this->reference) ? $of(this->reference) : ($Object*)nullptr);
	s->writeFields();
}

SerialRef::SerialRef() {
}

$Class* SerialRef::load$($String* name, bool initialize) {
	$loadClass(SerialRef, name, initialize, &_SerialRef_ClassInfo_, allocate$SerialRef);
	return class$;
}

$Class* SerialRef::class$ = nullptr;

			} // serial
		} // rowset
	} // sql
} // javax
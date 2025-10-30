#include <javax/sql/rowset/serial/SerialArray.h>

#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream$GetField.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream$PutField.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/net/URL.h>
#include <java/sql/Array.h>
#include <java/sql/Blob.h>
#include <java/sql/Clob.h>
#include <java/sql/ResultSet.h>
#include <java/sql/SQLException.h>
#include <java/sql/Struct.h>
#include <java/sql/Types.h>
#include <java/util/Arrays.h>
#include <java/util/Map.h>
#include <javax/sql/rowset/serial/SerialBlob.h>
#include <javax/sql/rowset/serial/SerialClob.h>
#include <javax/sql/rowset/serial/SerialDatalink.h>
#include <javax/sql/rowset/serial/SerialException.h>
#include <javax/sql/rowset/serial/SerialJavaObject.h>
#include <javax/sql/rowset/serial/SerialStruct.h>
#include <jcpp.h>

#undef ARRAY
#undef BLOB
#undef CLOB
#undef DATALINK
#undef JAVA_OBJECT
#undef STRUCT

using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectInputStream$GetField = ::java::io::ObjectInputStream$GetField;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ObjectOutputStream$PutField = ::java::io::ObjectOutputStream$PutField;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $URL = ::java::net::URL;
using $1Array = ::java::sql::Array;
using $Blob = ::java::sql::Blob;
using $Clob = ::java::sql::Clob;
using $ResultSet = ::java::sql::ResultSet;
using $SQLException = ::java::sql::SQLException;
using $Struct = ::java::sql::Struct;
using $Types = ::java::sql::Types;
using $Arrays = ::java::util::Arrays;
using $Map = ::java::util::Map;
using $SerialBlob = ::javax::sql::rowset::serial::SerialBlob;
using $SerialClob = ::javax::sql::rowset::serial::SerialClob;
using $SerialDatalink = ::javax::sql::rowset::serial::SerialDatalink;
using $SerialException = ::javax::sql::rowset::serial::SerialException;
using $SerialJavaObject = ::javax::sql::rowset::serial::SerialJavaObject;
using $SerialStruct = ::javax::sql::rowset::serial::SerialStruct;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace serial {

$FieldInfo _SerialArray_FieldInfo_[] = {
	{"elements", "[Ljava/lang/Object;", nullptr, $PRIVATE, $field(SerialArray, elements)},
	{"baseType", "I", nullptr, $PRIVATE, $field(SerialArray, baseType)},
	{"baseTypeName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(SerialArray, baseTypeName)},
	{"len", "I", nullptr, $PRIVATE, $field(SerialArray, len)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(SerialArray, serialVersionUID)},
	{}
};

$MethodInfo _SerialArray_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/sql/Array;Ljava/util/Map;)V", "(Ljava/sql/Array;Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)V", $PUBLIC, $method(static_cast<void(SerialArray::*)($1Array*,$Map*)>(&SerialArray::init$)), "javax.sql.rowset.serial.SerialException,java.sql.SQLException"},
	{"<init>", "(Ljava/sql/Array;)V", nullptr, $PUBLIC, $method(static_cast<void(SerialArray::*)($1Array*)>(&SerialArray::init$)), "javax.sql.rowset.serial.SerialException,java.sql.SQLException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"free", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getArray", "()Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"getArray", "(Ljava/util/Map;)Ljava/lang/Object;", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)Ljava/lang/Object;", $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"getArray", "(JI)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"getArray", "(JILjava/util/Map;)Ljava/lang/Object;", "(JILjava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)Ljava/lang/Object;", $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"getBaseType", "()I", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"getBaseTypeName", "()Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"getResultSet", "(JI)Ljava/sql/ResultSet;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"getResultSet", "(Ljava/util/Map;)Ljava/sql/ResultSet;", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)Ljava/sql/ResultSet;", $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"getResultSet", "()Ljava/sql/ResultSet;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"getResultSet", "(JILjava/util/Map;)Ljava/sql/ResultSet;", "(JILjava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)Ljava/sql/ResultSet;", $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"isValid", "()V", nullptr, $PRIVATE, $method(static_cast<void(SerialArray::*)()>(&SerialArray::isValid)), "javax.sql.rowset.serial.SerialException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(SerialArray::*)($ObjectInputStream*)>(&SerialArray::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(SerialArray::*)($ObjectOutputStream*)>(&SerialArray::writeObject)), "java.io.IOException"},
	{}
};

$ClassInfo _SerialArray_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.sql.rowset.serial.SerialArray",
	"java.lang.Object",
	"java.sql.Array,java.io.Serializable,java.lang.Cloneable",
	_SerialArray_FieldInfo_,
	_SerialArray_MethodInfo_
};

$Object* allocate$SerialArray($Class* clazz) {
	return $of($alloc(SerialArray));
}

$String* SerialArray::toString() {
	 return this->$1Array::toString();
}

void SerialArray::finalize() {
	this->$1Array::finalize();
}

void SerialArray::init$($1Array* array, $Map* map) {
	$useLocalCurrentObjectStackCache();
	if ((array == nullptr) || (map == nullptr)) {
		$throwNew($SQLException, "Cannot instantiate a SerialArray object with null parameters"_s);
	}
	if (($set(this, elements, $cast($ObjectArray, $nc(array)->getArray()))) == nullptr) {
		$throwNew($SQLException, "Invalid Array object. Calls to Array.getArray() return null value which cannot be serialized"_s);
	}
	$set(this, elements, $cast($ObjectArray, $nc(array)->getArray(map)));
	this->baseType = array->getBaseType();
	$set(this, baseTypeName, array->getBaseTypeName());
	this->len = $nc(this->elements)->length;
	switch (this->baseType) {
	case $Types::STRUCT:
		{
			for (int32_t i = 0; i < this->len; ++i) {
				$nc(this->elements)->set(i, $$new($SerialStruct, $cast($Struct, $nc(this->elements)->get(i)), map));
			}
			break;
		}
	case $Types::ARRAY:
		{
			for (int32_t i = 0; i < this->len; ++i) {
				$nc(this->elements)->set(i, $$new(SerialArray, $cast($1Array, $nc(this->elements)->get(i)), map));
			}
			break;
		}
	case $Types::BLOB:
		{
			for (int32_t i = 0; i < this->len; ++i) {
				$nc(this->elements)->set(i, $$new($SerialBlob, $cast($Blob, $nc(this->elements)->get(i))));
			}
			break;
		}
	case $Types::CLOB:
		{
			for (int32_t i = 0; i < this->len; ++i) {
				$nc(this->elements)->set(i, $$new($SerialClob, $cast($Clob, $nc(this->elements)->get(i))));
			}
			break;
		}
	case $Types::DATALINK:
		{
			for (int32_t i = 0; i < this->len; ++i) {
				$nc(this->elements)->set(i, $$new($SerialDatalink, $cast($URL, $nc(this->elements)->get(i))));
			}
			break;
		}
	case $Types::JAVA_OBJECT:
		{
			for (int32_t i = 0; i < this->len; ++i) {
				$nc(this->elements)->set(i, $$new($SerialJavaObject, $nc(this->elements)->get(i)));
			}
		}
	}
}

void SerialArray::free() {
	if (this->elements != nullptr) {
		$set(this, elements, nullptr);
		$set(this, baseTypeName, nullptr);
	}
}

void SerialArray::init$($1Array* array) {
	$useLocalCurrentObjectStackCache();
	if (array == nullptr) {
		$throwNew($SQLException, "Cannot instantiate a SerialArray object with a null Array object"_s);
	}
	if (($set(this, elements, $cast($ObjectArray, $nc(array)->getArray()))) == nullptr) {
		$throwNew($SQLException, "Invalid Array object. Calls to Array.getArray() return null value which cannot be serialized"_s);
	}
	this->baseType = $nc(array)->getBaseType();
	$set(this, baseTypeName, array->getBaseTypeName());
	this->len = $nc(this->elements)->length;
	switch (this->baseType) {
	case $Types::BLOB:
		{
			for (int32_t i = 0; i < this->len; ++i) {
				$nc(this->elements)->set(i, $$new($SerialBlob, $cast($Blob, $nc(this->elements)->get(i))));
			}
			break;
		}
	case $Types::CLOB:
		{
			for (int32_t i = 0; i < this->len; ++i) {
				$nc(this->elements)->set(i, $$new($SerialClob, $cast($Clob, $nc(this->elements)->get(i))));
			}
			break;
		}
	case $Types::DATALINK:
		{
			for (int32_t i = 0; i < this->len; ++i) {
				$nc(this->elements)->set(i, $$new($SerialDatalink, $cast($URL, $nc(this->elements)->get(i))));
			}
			break;
		}
	case $Types::JAVA_OBJECT:
		{
			for (int32_t i = 0; i < this->len; ++i) {
				$nc(this->elements)->set(i, $$new($SerialJavaObject, $nc(this->elements)->get(i)));
			}
			break;
		}
	}
}

$Object* SerialArray::getArray() {
	isValid();
	$var($Object, dst, $new($ObjectArray, this->len));
	$System::arraycopy($of(this->elements), 0, dst, 0, this->len);
	return $of(dst);
}

$Object* SerialArray::getArray($Map* map) {
	isValid();
	$var($ObjectArray, dst, $new($ObjectArray, this->len));
	$System::arraycopy($of(this->elements), 0, dst, 0, this->len);
	return $of(dst);
}

$Object* SerialArray::getArray(int64_t index, int32_t count) {
	isValid();
	$var($Object, dst, $new($ObjectArray, count));
	$System::arraycopy($of(this->elements), (int32_t)index, dst, 0, count);
	return $of(dst);
}

$Object* SerialArray::getArray(int64_t index, int32_t count, $Map* map) {
	isValid();
	$var($Object, dst, $new($ObjectArray, count));
	$System::arraycopy($of(this->elements), (int32_t)index, dst, 0, count);
	return $of(dst);
}

int32_t SerialArray::getBaseType() {
	isValid();
	return this->baseType;
}

$String* SerialArray::getBaseTypeName() {
	isValid();
	return this->baseTypeName;
}

$ResultSet* SerialArray::getResultSet(int64_t index, int32_t count) {
	$useLocalCurrentObjectStackCache();
	$var($SerialException, se, $new($SerialException));
	se->initCause($$new($UnsupportedOperationException));
	$throw(se);
	$shouldNotReachHere();
}

$ResultSet* SerialArray::getResultSet($Map* map) {
	$useLocalCurrentObjectStackCache();
	$var($SerialException, se, $new($SerialException));
	se->initCause($$new($UnsupportedOperationException));
	$throw(se);
	$shouldNotReachHere();
}

$ResultSet* SerialArray::getResultSet() {
	$useLocalCurrentObjectStackCache();
	$var($SerialException, se, $new($SerialException));
	se->initCause($$new($UnsupportedOperationException));
	$throw(se);
	$shouldNotReachHere();
}

$ResultSet* SerialArray::getResultSet(int64_t index, int32_t count, $Map* map) {
	$useLocalCurrentObjectStackCache();
	$var($SerialException, se, $new($SerialException));
	se->initCause($$new($UnsupportedOperationException));
	$throw(se);
	$shouldNotReachHere();
}

bool SerialArray::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if ($instanceOf(SerialArray, obj)) {
		$var(SerialArray, sa, $cast(SerialArray, obj));
		bool var$0 = this->baseType == $nc(sa)->baseType && $nc(this->baseTypeName)->equals(sa->baseTypeName);
		return var$0 && $Arrays::equals(this->elements, sa->elements);
	}
	return false;
}

int32_t SerialArray::hashCode() {
	int32_t var$0 = (((31 + $Arrays::hashCode(this->elements)) * 31 + this->len) * 31 + this->baseType) * 31;
	return var$0 + $nc(this->baseTypeName)->hashCode();
}

$Object* SerialArray::clone() {
	try {
		$var(SerialArray, sa, $cast(SerialArray, $1Array::clone()));
		$set($nc(sa), elements, (this->elements != nullptr) ? $Arrays::copyOf(this->elements, this->len) : ($ObjectArray*)nullptr);
		return $of(sa);
	} catch ($CloneNotSupportedException& ex) {
		$throwNew($InternalError);
	}
	$shouldNotReachHere();
}

void SerialArray::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectInputStream$GetField, fields, $nc(s)->readFields());
	$var($ObjectArray, tmp, $cast($ObjectArray, $nc(fields)->get("elements"_s, ($Object*)nullptr)));
	if (tmp == nullptr) {
		$throwNew($InvalidObjectException, "elements is null and should not be!"_s);
	}
	$set(this, elements, $cast($ObjectArray, $nc(tmp)->clone()));
	this->len = fields->get("len"_s, 0);
	if ($nc(this->elements)->length != this->len) {
		$throwNew($InvalidObjectException, "elements is not the expected size"_s);
	}
	this->baseType = fields->get("baseType"_s, 0);
	$set(this, baseTypeName, $cast($String, fields->get("baseTypeName"_s, ($Object*)nullptr)));
}

void SerialArray::writeObject($ObjectOutputStream* s) {
	$var($ObjectOutputStream$PutField, fields, $nc(s)->putFields());
	$nc(fields)->put("elements"_s, $of(this->elements));
	fields->put("len"_s, this->len);
	fields->put("baseType"_s, this->baseType);
	fields->put("baseTypeName"_s, $of(this->baseTypeName));
	s->writeFields();
}

void SerialArray::isValid() {
	if (this->elements == nullptr) {
		$throwNew($SerialException, "Error: You cannot call a method on a SerialArray instance once free() has been called."_s);
	}
}

SerialArray::SerialArray() {
}

$Class* SerialArray::load$($String* name, bool initialize) {
	$loadClass(SerialArray, name, initialize, &_SerialArray_ClassInfo_, allocate$SerialArray);
	return class$;
}

$Class* SerialArray::class$ = nullptr;

			} // serial
		} // rowset
	} // sql
} // javax
#include <javax/sql/rowset/serial/SerialStruct.h>

#include <java/io/ObjectInputStream$GetField.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream$PutField.h>
#include <java/io/ObjectOutputStream.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/sql/Array.h>
#include <java/sql/Blob.h>
#include <java/sql/Clob.h>
#include <java/sql/Ref.h>
#include <java/sql/SQLData.h>
#include <java/sql/SQLException.h>
#include <java/sql/SQLOutput.h>
#include <java/sql/Struct.h>
#include <java/util/Arrays.h>
#include <java/util/Map.h>
#include <java/util/Vector.h>
#include <javax/sql/rowset/serial/SQLOutputImpl.h>
#include <javax/sql/rowset/serial/SerialArray.h>
#include <javax/sql/rowset/serial/SerialBlob.h>
#include <javax/sql/rowset/serial/SerialClob.h>
#include <javax/sql/rowset/serial/SerialException.h>
#include <javax/sql/rowset/serial/SerialRef.h>
#include <jcpp.h>

using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectInputStream$GetField = ::java::io::ObjectInputStream$GetField;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ObjectOutputStream$PutField = ::java::io::ObjectOutputStream$PutField;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $1Array = ::java::sql::Array;
using $Blob = ::java::sql::Blob;
using $Clob = ::java::sql::Clob;
using $Ref = ::java::sql::Ref;
using $SQLData = ::java::sql::SQLData;
using $SQLException = ::java::sql::SQLException;
using $SQLOutput = ::java::sql::SQLOutput;
using $Struct = ::java::sql::Struct;
using $Arrays = ::java::util::Arrays;
using $Map = ::java::util::Map;
using $Vector = ::java::util::Vector;
using $SQLOutputImpl = ::javax::sql::rowset::serial::SQLOutputImpl;
using $SerialArray = ::javax::sql::rowset::serial::SerialArray;
using $SerialBlob = ::javax::sql::rowset::serial::SerialBlob;
using $SerialClob = ::javax::sql::rowset::serial::SerialClob;
using $SerialException = ::javax::sql::rowset::serial::SerialException;
using $SerialRef = ::javax::sql::rowset::serial::SerialRef;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace serial {

$FieldInfo _SerialStruct_FieldInfo_[] = {
	{"SQLTypeName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(SerialStruct, SQLTypeName)},
	{"attribs", "[Ljava/lang/Object;", nullptr, $PRIVATE, $field(SerialStruct, attribs)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(SerialStruct, serialVersionUID)},
	{}
};

$MethodInfo _SerialStruct_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/sql/Struct;Ljava/util/Map;)V", "(Ljava/sql/Struct;Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)V", $PUBLIC, $method(static_cast<void(SerialStruct::*)($Struct*,$Map*)>(&SerialStruct::init$)), "javax.sql.rowset.serial.SerialException"},
	{"<init>", "(Ljava/sql/SQLData;Ljava/util/Map;)V", "(Ljava/sql/SQLData;Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)V", $PUBLIC, $method(static_cast<void(SerialStruct::*)($SQLData*,$Map*)>(&SerialStruct::init$)), "javax.sql.rowset.serial.SerialException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getAttributes", "()[Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"getAttributes", "(Ljava/util/Map;)[Ljava/lang/Object;", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)[Ljava/lang/Object;", $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"getSQLTypeName", "()Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"mapToSerial", "(Ljava/util/Map;)V", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)V", $PRIVATE, $method(static_cast<void(SerialStruct::*)($Map*)>(&SerialStruct::mapToSerial)), "javax.sql.rowset.serial.SerialException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(SerialStruct::*)($ObjectInputStream*)>(&SerialStruct::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(SerialStruct::*)($ObjectOutputStream*)>(&SerialStruct::writeObject)), "java.io.IOException"},
	{}
};

$ClassInfo _SerialStruct_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.sql.rowset.serial.SerialStruct",
	"java.lang.Object",
	"java.sql.Struct,java.io.Serializable,java.lang.Cloneable",
	_SerialStruct_FieldInfo_,
	_SerialStruct_MethodInfo_
};

$Object* allocate$SerialStruct($Class* clazz) {
	return $of($alloc(SerialStruct));
}

$String* SerialStruct::toString() {
	 return this->$Struct::toString();
}

void SerialStruct::finalize() {
	this->$Struct::finalize();
}

void SerialStruct::init$($Struct* in, $Map* map) {
	$useLocalCurrentObjectStackCache();
	try {
		$set(this, SQLTypeName, $nc(in)->getSQLTypeName());
		$nc($System::out)->println($$str({"SQLTypeName: "_s, this->SQLTypeName}));
		$set(this, attribs, in->getAttributes(map));
		mapToSerial(map);
	} catch ($SQLException& e) {
		$throwNew($SerialException, $(e->getMessage()));
	}
}

void SerialStruct::init$($SQLData* in, $Map* map) {
	$useLocalCurrentObjectStackCache();
	try {
		$set(this, SQLTypeName, $nc(in)->getSQLTypeName());
		$var($Vector, tmp, $new($Vector));
		in->writeSQL($$new($SQLOutputImpl, tmp, map));
		$set(this, attribs, tmp->toArray());
	} catch ($SQLException& e) {
		$throwNew($SerialException, $(e->getMessage()));
	}
}

$String* SerialStruct::getSQLTypeName() {
	return this->SQLTypeName;
}

$ObjectArray* SerialStruct::getAttributes() {
	$var($ObjectArray, val, this->attribs);
	return (val == nullptr) ? ($ObjectArray*)nullptr : $Arrays::copyOf(val, $nc(val)->length);
}

$ObjectArray* SerialStruct::getAttributes($Map* map) {
	$var($ObjectArray, val, this->attribs);
	return (val == nullptr) ? ($ObjectArray*)nullptr : $Arrays::copyOf(val, $nc(val)->length);
}

void SerialStruct::mapToSerial($Map* map) {
	$useLocalCurrentObjectStackCache();
	try {
		for (int32_t i = 0; i < $nc(this->attribs)->length; ++i) {
			if ($instanceOf($Struct, $nc(this->attribs)->get(i))) {
				$nc(this->attribs)->set(i, $$new(SerialStruct, $cast($Struct, $nc(this->attribs)->get(i)), map));
			} else if ($instanceOf($SQLData, $nc(this->attribs)->get(i))) {
				$nc(this->attribs)->set(i, $$new(SerialStruct, $cast($SQLData, $nc(this->attribs)->get(i)), map));
			} else if ($instanceOf($Blob, $nc(this->attribs)->get(i))) {
				$nc(this->attribs)->set(i, $$new($SerialBlob, $cast($Blob, $nc(this->attribs)->get(i))));
			} else if ($instanceOf($Clob, $nc(this->attribs)->get(i))) {
				$nc(this->attribs)->set(i, $$new($SerialClob, $cast($Clob, $nc(this->attribs)->get(i))));
			} else if ($instanceOf($Ref, $nc(this->attribs)->get(i))) {
				$nc(this->attribs)->set(i, $$new($SerialRef, $cast($Ref, $nc(this->attribs)->get(i))));
			} else if ($instanceOf($1Array, $nc(this->attribs)->get(i))) {
				$nc(this->attribs)->set(i, $$new($SerialArray, $cast($1Array, $nc(this->attribs)->get(i)), map));
			}
		}
	} catch ($SQLException& e) {
		$throwNew($SerialException, $(e->getMessage()));
	}
	return;
}

bool SerialStruct::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if ($instanceOf(SerialStruct, obj)) {
		$var(SerialStruct, ss, $cast(SerialStruct, obj));
		bool var$0 = $nc(this->SQLTypeName)->equals($nc(ss)->SQLTypeName);
		return var$0 && $Arrays::equals(this->attribs, $nc(ss)->attribs);
	}
	return false;
}

int32_t SerialStruct::hashCode() {
	int32_t var$0 = ((31 + $Arrays::hashCode(this->attribs)) * 31) * 31;
	return var$0 + $nc(this->SQLTypeName)->hashCode();
}

$Object* SerialStruct::clone() {
	try {
		$var(SerialStruct, ss, $cast(SerialStruct, $Struct::clone()));
		$set($nc(ss), attribs, $Arrays::copyOf(this->attribs, $nc(this->attribs)->length));
		return $of(ss);
	} catch ($CloneNotSupportedException& ex) {
		$throwNew($InternalError);
	}
	$shouldNotReachHere();
}

void SerialStruct::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectInputStream$GetField, fields, $nc(s)->readFields());
	$var($ObjectArray, tmp, $cast($ObjectArray, $nc(fields)->get("attribs"_s, ($Object*)nullptr)));
	$set(this, attribs, tmp == nullptr ? ($ObjectArray*)nullptr : $cast($ObjectArray, $nc(tmp)->clone()));
	$set(this, SQLTypeName, $cast($String, fields->get("SQLTypeName"_s, ($Object*)nullptr)));
}

void SerialStruct::writeObject($ObjectOutputStream* s) {
	$var($ObjectOutputStream$PutField, fields, $nc(s)->putFields());
	$nc(fields)->put("attribs"_s, $of(this->attribs));
	fields->put("SQLTypeName"_s, $of(this->SQLTypeName));
	s->writeFields();
}

SerialStruct::SerialStruct() {
}

$Class* SerialStruct::load$($String* name, bool initialize) {
	$loadClass(SerialStruct, name, initialize, &_SerialStruct_ClassInfo_, allocate$SerialStruct);
	return class$;
}

$Class* SerialStruct::class$ = nullptr;

			} // serial
		} // rowset
	} // sql
} // javax
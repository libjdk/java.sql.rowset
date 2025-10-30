#include <javax/sql/rowset/serial/SQLInputImpl.h>

#include <java/io/InputStream.h>
#include <java/io/Reader.h>
#include <java/math/BigDecimal.h>
#include <java/net/URL.h>
#include <java/sql/Array.h>
#include <java/sql/Blob.h>
#include <java/sql/Clob.h>
#include <java/sql/Date.h>
#include <java/sql/NClob.h>
#include <java/sql/Ref.h>
#include <java/sql/RowId.h>
#include <java/sql/SQLData.h>
#include <java/sql/SQLException.h>
#include <java/sql/SQLInput.h>
#include <java/sql/SQLXML.h>
#include <java/sql/Struct.h>
#include <java/sql/Time.h>
#include <java/sql/Timestamp.h>
#include <java/util/Arrays.h>
#include <java/util/Map.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <jcpp.h>

using $InputStream = ::java::io::InputStream;
using $Reader = ::java::io::Reader;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Short = ::java::lang::Short;
using $BigDecimal = ::java::math::BigDecimal;
using $URL = ::java::net::URL;
using $1Array = ::java::sql::Array;
using $Blob = ::java::sql::Blob;
using $Clob = ::java::sql::Clob;
using $Date = ::java::sql::Date;
using $NClob = ::java::sql::NClob;
using $Ref = ::java::sql::Ref;
using $RowId = ::java::sql::RowId;
using $SQLData = ::java::sql::SQLData;
using $SQLException = ::java::sql::SQLException;
using $SQLInput = ::java::sql::SQLInput;
using $SQLXML = ::java::sql::SQLXML;
using $Struct = ::java::sql::Struct;
using $Time = ::java::sql::Time;
using $Timestamp = ::java::sql::Timestamp;
using $Arrays = ::java::util::Arrays;
using $Map = ::java::util::Map;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace serial {

$FieldInfo _SQLInputImpl_FieldInfo_[] = {
	{"lastValueWasNull", "Z", nullptr, $PRIVATE, $field(SQLInputImpl, lastValueWasNull)},
	{"idx", "I", nullptr, $PRIVATE, $field(SQLInputImpl, idx)},
	{"attrib", "[Ljava/lang/Object;", nullptr, $PRIVATE, $field(SQLInputImpl, attrib)},
	{"map", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;", $PRIVATE, $field(SQLInputImpl, map)},
	{}
};

$MethodInfo _SQLInputImpl_MethodInfo_[] = {
	{"<init>", "([Ljava/lang/Object;Ljava/util/Map;)V", "([Ljava/lang/Object;Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)V", $PUBLIC, $method(static_cast<void(SQLInputImpl::*)($ObjectArray*,$Map*)>(&SQLInputImpl::init$)), "java.sql.SQLException"},
	{"getNextAttribute", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(static_cast<$Object*(SQLInputImpl::*)()>(&SQLInputImpl::getNextAttribute)), "java.sql.SQLException"},
	{"readArray", "()Ljava/sql/Array;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readAsciiStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readBigDecimal", "()Ljava/math/BigDecimal;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readBinaryStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readBlob", "()Ljava/sql/Blob;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readBoolean", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readByte", "()B", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readBytes", "()[B", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readCharacterStream", "()Ljava/io/Reader;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readClob", "()Ljava/sql/Clob;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readDate", "()Ljava/sql/Date;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readDouble", "()D", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readFloat", "()F", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readInt", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readLong", "()J", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readNClob", "()Ljava/sql/NClob;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readNString", "()Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readObject", "()Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readRef", "()Ljava/sql/Ref;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readRowId", "()Ljava/sql/RowId;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readSQLXML", "()Ljava/sql/SQLXML;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readShort", "()S", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readString", "()Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readTime", "()Ljava/sql/Time;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readTimestamp", "()Ljava/sql/Timestamp;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readURL", "()Ljava/net/URL;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"wasNull", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{}
};

$ClassInfo _SQLInputImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.sql.rowset.serial.SQLInputImpl",
	"java.lang.Object",
	"java.sql.SQLInput",
	_SQLInputImpl_FieldInfo_,
	_SQLInputImpl_MethodInfo_
};

$Object* allocate$SQLInputImpl($Class* clazz) {
	return $of($alloc(SQLInputImpl));
}

void SQLInputImpl::init$($ObjectArray* attributes, $Map* map) {
	if ((attributes == nullptr) || (map == nullptr)) {
		$throwNew($SQLException, "Cannot instantiate a SQLInputImpl object with null parameters"_s);
	}
	$set(this, attrib, $Arrays::copyOf(attributes, $nc(attributes)->length));
	this->idx = -1;
	$set(this, map, map);
}

$Object* SQLInputImpl::getNextAttribute() {
	if (++this->idx >= $nc(this->attrib)->length) {
		$throwNew($SQLException, "SQLInputImpl exception: Invalid read position"_s);
	} else {
		this->lastValueWasNull = $nc(this->attrib)->get(this->idx) == nullptr;
		return $of($nc(this->attrib)->get(this->idx));
	}
}

$String* SQLInputImpl::readString() {
	return $cast($String, getNextAttribute());
}

bool SQLInputImpl::readBoolean() {
	$var($Boolean, attrib, $cast($Boolean, getNextAttribute()));
	return (attrib == nullptr) ? false : $nc(attrib)->booleanValue();
}

int8_t SQLInputImpl::readByte() {
	$var($Byte, attrib, $cast($Byte, getNextAttribute()));
	return (attrib == nullptr) ? (int8_t)0 : $nc(attrib)->byteValue();
}

int16_t SQLInputImpl::readShort() {
	$var($Short, attrib, $cast($Short, getNextAttribute()));
	return (attrib == nullptr) ? (int16_t)0 : $nc(attrib)->shortValue();
}

int32_t SQLInputImpl::readInt() {
	$var($Integer, attrib, $cast($Integer, getNextAttribute()));
	return (attrib == nullptr) ? 0 : $nc(attrib)->intValue();
}

int64_t SQLInputImpl::readLong() {
	$var($Long, attrib, $cast($Long, getNextAttribute()));
	return (attrib == nullptr) ? (int64_t)0 : $nc(attrib)->longValue();
}

float SQLInputImpl::readFloat() {
	$var($Float, attrib, $cast($Float, getNextAttribute()));
	return (attrib == nullptr) ? (float)0 : $nc(attrib)->floatValue();
}

double SQLInputImpl::readDouble() {
	$var($Double, attrib, $cast($Double, getNextAttribute()));
	return (attrib == nullptr) ? (double)0 : $nc(attrib)->doubleValue();
}

$BigDecimal* SQLInputImpl::readBigDecimal() {
	return $cast($BigDecimal, getNextAttribute());
}

$bytes* SQLInputImpl::readBytes() {
	return $cast($bytes, getNextAttribute());
}

$Date* SQLInputImpl::readDate() {
	return $cast($Date, getNextAttribute());
}

$Time* SQLInputImpl::readTime() {
	return $cast($Time, getNextAttribute());
}

$Timestamp* SQLInputImpl::readTimestamp() {
	return $cast($Timestamp, getNextAttribute());
}

$Reader* SQLInputImpl::readCharacterStream() {
	return $cast($Reader, getNextAttribute());
}

$InputStream* SQLInputImpl::readAsciiStream() {
	return $cast($InputStream, getNextAttribute());
}

$InputStream* SQLInputImpl::readBinaryStream() {
	return $cast($InputStream, getNextAttribute());
}

$Object* SQLInputImpl::readObject() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Object, attrib, getNextAttribute());
	if ($instanceOf($Struct, attrib)) {
		$var($Struct, s, $cast($Struct, attrib));
		$Class* c = $cast($Class, $nc(this->map)->get($($nc(s)->getSQLTypeName())));
		if (c != nullptr) {
			$var($SQLData, obj, nullptr);
			try {
				$ReflectUtil::checkPackageAccess(c);
				$var($Object, tmp, c->newInstance());
				$assign(obj, $cast($SQLData, tmp));
			} catch ($Exception& ex) {
				$throwNew($SQLException, "Unable to Instantiate: "_s, static_cast<$Throwable*>(ex));
			}
			$var($ObjectArray, attribs, $nc(s)->getAttributes(this->map));
			$var(SQLInputImpl, sqlInput, $new(SQLInputImpl, attribs, this->map));
			$nc(obj)->readSQL(sqlInput, $(s->getSQLTypeName()));
			return $of(obj);
		}
	}
	return $of(attrib);
}

$Ref* SQLInputImpl::readRef() {
	return $cast($Ref, getNextAttribute());
}

$Blob* SQLInputImpl::readBlob() {
	return $cast($Blob, getNextAttribute());
}

$Clob* SQLInputImpl::readClob() {
	return $cast($Clob, getNextAttribute());
}

$1Array* SQLInputImpl::readArray() {
	return $cast($1Array, getNextAttribute());
}

bool SQLInputImpl::wasNull() {
	return this->lastValueWasNull;
}

$URL* SQLInputImpl::readURL() {
	return $cast($URL, getNextAttribute());
}

$NClob* SQLInputImpl::readNClob() {
	return $cast($NClob, getNextAttribute());
}

$String* SQLInputImpl::readNString() {
	return $cast($String, getNextAttribute());
}

$SQLXML* SQLInputImpl::readSQLXML() {
	return $cast($SQLXML, getNextAttribute());
}

$RowId* SQLInputImpl::readRowId() {
	return $cast($RowId, getNextAttribute());
}

SQLInputImpl::SQLInputImpl() {
}

$Class* SQLInputImpl::load$($String* name, bool initialize) {
	$loadClass(SQLInputImpl, name, initialize, &_SQLInputImpl_ClassInfo_, allocate$SQLInputImpl);
	return class$;
}

$Class* SQLInputImpl::class$ = nullptr;

			} // serial
		} // rowset
	} // sql
} // javax
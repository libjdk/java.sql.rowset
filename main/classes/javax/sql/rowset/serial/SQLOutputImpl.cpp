#include <javax/sql/rowset/serial/SQLOutputImpl.h>

#include <java/io/BufferedReader.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/Reader.h>
#include <java/lang/StringBuffer.h>
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
#include <java/sql/SQLXML.h>
#include <java/sql/Struct.h>
#include <java/sql/Time.h>
#include <java/sql/Timestamp.h>
#include <java/util/Map.h>
#include <java/util/Vector.h>
#include <javax/sql/rowset/serial/SerialArray.h>
#include <javax/sql/rowset/serial/SerialBlob.h>
#include <javax/sql/rowset/serial/SerialClob.h>
#include <javax/sql/rowset/serial/SerialDatalink.h>
#include <javax/sql/rowset/serial/SerialRef.h>
#include <javax/sql/rowset/serial/SerialStruct.h>
#include <jcpp.h>

using $BufferedReader = ::java::io::BufferedReader;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $Reader = ::java::io::Reader;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Short = ::java::lang::Short;
using $StringBuffer = ::java::lang::StringBuffer;
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
using $SQLOutput = ::java::sql::SQLOutput;
using $SQLXML = ::java::sql::SQLXML;
using $Struct = ::java::sql::Struct;
using $Time = ::java::sql::Time;
using $Timestamp = ::java::sql::Timestamp;
using $Map = ::java::util::Map;
using $Vector = ::java::util::Vector;
using $SerialArray = ::javax::sql::rowset::serial::SerialArray;
using $SerialBlob = ::javax::sql::rowset::serial::SerialBlob;
using $SerialClob = ::javax::sql::rowset::serial::SerialClob;
using $SerialDatalink = ::javax::sql::rowset::serial::SerialDatalink;
using $SerialRef = ::javax::sql::rowset::serial::SerialRef;
using $SerialStruct = ::javax::sql::rowset::serial::SerialStruct;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace serial {

$FieldInfo _SQLOutputImpl_FieldInfo_[] = {
	{"attribs", "Ljava/util/Vector;", nullptr, $PRIVATE, $field(SQLOutputImpl, attribs)},
	{"map", "Ljava/util/Map;", nullptr, $PRIVATE, $field(SQLOutputImpl, map)},
	{}
};

$MethodInfo _SQLOutputImpl_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Vector;Ljava/util/Map;)V", "(Ljava/util/Vector<*>;Ljava/util/Map<Ljava/lang/String;*>;)V", $PUBLIC, $method(static_cast<void(SQLOutputImpl::*)($Vector*,$Map*)>(&SQLOutputImpl::init$)), "java.sql.SQLException"},
	{"writeArray", "(Ljava/sql/Array;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeAsciiStream", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeBigDecimal", "(Ljava/math/BigDecimal;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeBinaryStream", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeBlob", "(Ljava/sql/Blob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeBoolean", "(Z)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeByte", "(B)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeBytes", "([B)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeCharacterStream", "(Ljava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeClob", "(Ljava/sql/Clob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeDate", "(Ljava/sql/Date;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeDouble", "(D)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeFloat", "(F)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeInt", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeLong", "(J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeNClob", "(Ljava/sql/NClob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeNString", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeObject", "(Ljava/sql/SQLData;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeRef", "(Ljava/sql/Ref;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeRowId", "(Ljava/sql/RowId;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeSQLXML", "(Ljava/sql/SQLXML;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeShort", "(S)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeString", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeStruct", "(Ljava/sql/Struct;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeTime", "(Ljava/sql/Time;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeTimestamp", "(Ljava/sql/Timestamp;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeURL", "(Ljava/net/URL;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{}
};

$ClassInfo _SQLOutputImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.sql.rowset.serial.SQLOutputImpl",
	"java.lang.Object",
	"java.sql.SQLOutput",
	_SQLOutputImpl_FieldInfo_,
	_SQLOutputImpl_MethodInfo_
};

$Object* allocate$SQLOutputImpl($Class* clazz) {
	return $of($alloc(SQLOutputImpl));
}

void SQLOutputImpl::init$($Vector* attributes, $Map* map) {
	if ((attributes == nullptr) || (map == nullptr)) {
		$throwNew($SQLException, "Cannot instantiate a SQLOutputImpl instance with null parameters"_s);
	}
	$set(this, attribs, attributes);
	$set(this, map, map);
}

void SQLOutputImpl::writeString($String* x) {
	$nc(this->attribs)->add(x);
}

void SQLOutputImpl::writeBoolean(bool x) {
	$nc(this->attribs)->add($($Boolean::valueOf(x)));
}

void SQLOutputImpl::writeByte(int8_t x) {
	$nc(this->attribs)->add($($Byte::valueOf(x)));
}

void SQLOutputImpl::writeShort(int16_t x) {
	$nc(this->attribs)->add($($Short::valueOf(x)));
}

void SQLOutputImpl::writeInt(int32_t x) {
	$nc(this->attribs)->add($($Integer::valueOf(x)));
}

void SQLOutputImpl::writeLong(int64_t x) {
	$nc(this->attribs)->add($($Long::valueOf(x)));
}

void SQLOutputImpl::writeFloat(float x) {
	$nc(this->attribs)->add($($Float::valueOf(x)));
}

void SQLOutputImpl::writeDouble(double x) {
	$nc(this->attribs)->add($($Double::valueOf(x)));
}

void SQLOutputImpl::writeBigDecimal($BigDecimal* x) {
	$nc(this->attribs)->add(x);
}

void SQLOutputImpl::writeBytes($bytes* x) {
	$nc(this->attribs)->add(x);
}

void SQLOutputImpl::writeDate($Date* x) {
	$nc(this->attribs)->add(x);
}

void SQLOutputImpl::writeTime($Time* x) {
	$nc(this->attribs)->add(x);
}

void SQLOutputImpl::writeTimestamp($Timestamp* x) {
	$nc(this->attribs)->add(x);
}

void SQLOutputImpl::writeCharacterStream($Reader* x) {
	$useLocalCurrentObjectStackCache();
	$var($BufferedReader, bufReader, $new($BufferedReader, x));
	try {
		int32_t i = 0;
		while ((i = bufReader->read()) != -1) {
			char16_t ch = (char16_t)i;
			$var($StringBuffer, strBuf, $new($StringBuffer));
			strBuf->append(ch);
			$var($String, str, $new($String, strBuf));
			$var($String, strLine, bufReader->readLine());
			writeString($(str->concat(strLine)));
		}
	} catch ($IOException& ioe) {
	}
}

void SQLOutputImpl::writeAsciiStream($InputStream* x) {
	$useLocalCurrentObjectStackCache();
	$var($BufferedReader, bufReader, $new($BufferedReader, $$new($InputStreamReader, x)));
	try {
		int32_t i = 0;
		while ((i = bufReader->read()) != -1) {
			char16_t ch = (char16_t)i;
			$var($StringBuffer, strBuf, $new($StringBuffer));
			strBuf->append(ch);
			$var($String, str, $new($String, strBuf));
			$var($String, strLine, bufReader->readLine());
			writeString($(str->concat(strLine)));
		}
	} catch ($IOException& ioe) {
		$throwNew($SQLException, $(ioe->getMessage()));
	}
}

void SQLOutputImpl::writeBinaryStream($InputStream* x) {
	$useLocalCurrentObjectStackCache();
	$var($BufferedReader, bufReader, $new($BufferedReader, $$new($InputStreamReader, x)));
	try {
		int32_t i = 0;
		while ((i = bufReader->read()) != -1) {
			char16_t ch = (char16_t)i;
			$var($StringBuffer, strBuf, $new($StringBuffer));
			strBuf->append(ch);
			$var($String, str, $new($String, strBuf));
			$var($String, strLine, bufReader->readLine());
			writeString($(str->concat(strLine)));
		}
	} catch ($IOException& ioe) {
		$throwNew($SQLException, $(ioe->getMessage()));
	}
}

void SQLOutputImpl::writeObject($SQLData* x) {
	if (x == nullptr) {
		$nc(this->attribs)->add(nullptr);
	} else {
		$nc(this->attribs)->add($$new($SerialStruct, x, this->map));
	}
}

void SQLOutputImpl::writeRef($Ref* x) {
	if (x == nullptr) {
		$nc(this->attribs)->add(nullptr);
	} else {
		$nc(this->attribs)->add($$new($SerialRef, x));
	}
}

void SQLOutputImpl::writeBlob($Blob* x) {
	if (x == nullptr) {
		$nc(this->attribs)->add(nullptr);
	} else {
		$nc(this->attribs)->add($$new($SerialBlob, x));
	}
}

void SQLOutputImpl::writeClob($Clob* x) {
	if (x == nullptr) {
		$nc(this->attribs)->add(nullptr);
	} else {
		$nc(this->attribs)->add($$new($SerialClob, x));
	}
}

void SQLOutputImpl::writeStruct($Struct* x) {
	$var($SerialStruct, s, $new($SerialStruct, x, this->map));
	$nc(this->attribs)->add(s);
}

void SQLOutputImpl::writeArray($1Array* x) {
	if (x == nullptr) {
		$nc(this->attribs)->add(nullptr);
	} else {
		$nc(this->attribs)->add($$new($SerialArray, x, this->map));
	}
}

void SQLOutputImpl::writeURL($URL* url) {
	if (url == nullptr) {
		$nc(this->attribs)->add(nullptr);
	} else {
		$nc(this->attribs)->add($$new($SerialDatalink, url));
	}
}

void SQLOutputImpl::writeNString($String* x) {
	$nc(this->attribs)->add(x);
}

void SQLOutputImpl::writeNClob($NClob* x) {
	$nc(this->attribs)->add(x);
}

void SQLOutputImpl::writeRowId($RowId* x) {
	$nc(this->attribs)->add(x);
}

void SQLOutputImpl::writeSQLXML($SQLXML* x) {
	$nc(this->attribs)->add(x);
}

SQLOutputImpl::SQLOutputImpl() {
}

$Class* SQLOutputImpl::load$($String* name, bool initialize) {
	$loadClass(SQLOutputImpl, name, initialize, &_SQLOutputImpl_ClassInfo_, allocate$SQLOutputImpl);
	return class$;
}

$Class* SQLOutputImpl::class$ = nullptr;

			} // serial
		} // rowset
	} // sql
} // javax
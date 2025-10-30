#include <javax/sql/rowset/serial/SerialBlob.h>

#include <java/io/ByteArrayInputStream.h>
#include <java/io/InputStream.h>
#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream$GetField.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream$PutField.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/sql/Blob.h>
#include <java/sql/SQLException.h>
#include <java/util/Arrays.h>
#include <javax/sql/rowset/serial/SerialException.h>
#include <jcpp.h>

using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $InputStream = ::java::io::InputStream;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectInputStream$GetField = ::java::io::ObjectInputStream$GetField;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ObjectOutputStream$PutField = ::java::io::ObjectOutputStream$PutField;
using $OutputStream = ::java::io::OutputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Blob = ::java::sql::Blob;
using $SQLException = ::java::sql::SQLException;
using $Arrays = ::java::util::Arrays;
using $SerialException = ::javax::sql::rowset::serial::SerialException;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace serial {

$FieldInfo _SerialBlob_FieldInfo_[] = {
	{"buf", "[B", nullptr, $PRIVATE, $field(SerialBlob, buf)},
	{"blob", "Ljava/sql/Blob;", nullptr, $PRIVATE, $field(SerialBlob, blob)},
	{"len", "J", nullptr, $PRIVATE, $field(SerialBlob, len)},
	{"origLen", "J", nullptr, $PRIVATE, $field(SerialBlob, origLen)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(SerialBlob, serialVersionUID)},
	{}
};

$MethodInfo _SerialBlob_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "([B)V", nullptr, $PUBLIC, $method(static_cast<void(SerialBlob::*)($bytes*)>(&SerialBlob::init$)), "javax.sql.rowset.serial.SerialException,java.sql.SQLException"},
	{"<init>", "(Ljava/sql/Blob;)V", nullptr, $PUBLIC, $method(static_cast<void(SerialBlob::*)($Blob*)>(&SerialBlob::init$)), "javax.sql.rowset.serial.SerialException,java.sql.SQLException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"free", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getBinaryStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"getBinaryStream", "(JJ)Ljava/io/InputStream;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getBytes", "(JI)[B", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"isValid", "()V", nullptr, $PRIVATE, $method(static_cast<void(SerialBlob::*)()>(&SerialBlob::isValid)), "javax.sql.rowset.serial.SerialException"},
	{"length", "()J", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"position", "([BJ)J", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException,java.sql.SQLException"},
	{"position", "(Ljava/sql/Blob;J)J", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException,java.sql.SQLException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(SerialBlob::*)($ObjectInputStream*)>(&SerialBlob::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"setBinaryStream", "(J)Ljava/io/OutputStream;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException,java.sql.SQLException"},
	{"setBytes", "(J[B)I", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException,java.sql.SQLException"},
	{"setBytes", "(J[BII)I", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException,java.sql.SQLException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"truncate", "(J)V", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(SerialBlob::*)($ObjectOutputStream*)>(&SerialBlob::writeObject)), "java.io.IOException"},
	{}
};

$ClassInfo _SerialBlob_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.sql.rowset.serial.SerialBlob",
	"java.lang.Object",
	"java.sql.Blob,java.io.Serializable,java.lang.Cloneable",
	_SerialBlob_FieldInfo_,
	_SerialBlob_MethodInfo_
};

$Object* allocate$SerialBlob($Class* clazz) {
	return $of($alloc(SerialBlob));
}

$String* SerialBlob::toString() {
	 return this->$Blob::toString();
}

void SerialBlob::finalize() {
	this->$Blob::finalize();
}

void SerialBlob::init$($bytes* b) {
	this->len = $nc(b)->length;
	$set(this, buf, $new($bytes, (int32_t)this->len));
	for (int32_t i = 0; i < this->len; ++i) {
		$nc(this->buf)->set(i, b->get(i));
	}
	this->origLen = this->len;
}

void SerialBlob::init$($Blob* blob) {
	if (blob == nullptr) {
		$throwNew($SQLException, "Cannot instantiate a SerialBlob object with a null Blob object"_s);
	}
	this->len = $nc(blob)->length();
	$set(this, buf, blob->getBytes(1, (int32_t)this->len));
	$set(this, blob, blob);
	this->origLen = this->len;
}

$bytes* SerialBlob::getBytes(int64_t pos, int32_t length) {
	isValid();
	if (length > this->len) {
		length = (int32_t)this->len;
	}
	if (pos < 1 || this->len - pos < 0) {
		$throwNew($SerialException, "Invalid arguments: position cannot be less than 1 or greater than the length of the SerialBlob"_s);
	}
	--pos;
	$var($bytes, b, $new($bytes, length));
	for (int32_t i = 0; i < length; ++i) {
		b->set(i, $nc(this->buf)->get((int32_t)pos));
		++pos;
	}
	return b;
}

int64_t SerialBlob::length() {
	isValid();
	return this->len;
}

$InputStream* SerialBlob::getBinaryStream() {
	isValid();
	$var($InputStream, stream, $new($ByteArrayInputStream, this->buf));
	return stream;
}

int64_t SerialBlob::position($bytes* pattern, int64_t start) {
	isValid();
	if (start < 1 || start > this->len) {
		return -1;
	}
	int32_t pos = (int32_t)start - 1;
	int32_t i = 0;
	int64_t patlen = $nc(pattern)->length;
	while (pos < this->len) {
		if (pattern->get(i) == $nc(this->buf)->get(pos)) {
			if (i + 1 == patlen) {
				return (pos + 1) - (patlen - 1);
			}
			++i;
			++pos;
		} else if (pattern->get(i) != $nc(this->buf)->get(pos)) {
			++pos;
		}
	}
	return -1;
}

int64_t SerialBlob::position($Blob* pattern, int64_t start) {
	isValid();
	return position($($nc(pattern)->getBytes(1, (int32_t)(pattern->length()))), start);
}

int32_t SerialBlob::setBytes(int64_t pos, $bytes* bytes) {
	return setBytes(pos, bytes, 0, $nc(bytes)->length);
}

int32_t SerialBlob::setBytes(int64_t pos, $bytes* bytes, int32_t offset, int32_t length) {
	isValid();
	if (offset < 0 || offset > $nc(bytes)->length) {
		$throwNew($SerialException, "Invalid offset in byte array set"_s);
	}
	if (pos < 1 || pos > this->length()) {
		$throwNew($SerialException, "Invalid position in BLOB object set"_s);
	}
	if ((int64_t)(length) > this->origLen) {
		$throwNew($SerialException, "Buffer is not sufficient to hold the value"_s);
	}
	if ((length + offset) > $nc(bytes)->length) {
		$throwNew($SerialException, "Invalid OffSet. Cannot have combined offset and length that is greater that the Blob buffer"_s);
	}
	int32_t i = 0;
	--pos;
	while (i < length || (offset + i + 1) < ($nc(bytes)->length - offset)) {
		$nc(this->buf)->set((int32_t)pos + i, bytes->get(offset + i));
		++i;
	}
	return i;
}

$OutputStream* SerialBlob::setBinaryStream(int64_t pos) {
	isValid();
	if (this->blob != nullptr) {
		return $nc(this->blob)->setBinaryStream(pos);
	} else {
		$throwNew($SerialException, "Unsupported operation. SerialBlob cannot return a writable binary stream, unless instantiated with a Blob object that provides a setBinaryStream() implementation"_s);
	}
}

void SerialBlob::truncate(int64_t length) {
	isValid();
	if (length > this->len) {
		$throwNew($SerialException, "Length more than what can be truncated"_s);
	} else if ((int32_t)length == 0) {
		$set(this, buf, $new($bytes, 0));
		this->len = length;
	} else {
		this->len = length;
		$set(this, buf, this->getBytes(1, (int32_t)this->len));
	}
}

$InputStream* SerialBlob::getBinaryStream(int64_t pos, int64_t length) {
	isValid();
	if (pos < 1 || pos > this->length()) {
		$throwNew($SerialException, "Invalid position in BLOB object set"_s);
	}
	if (length < 1 || length > this->len - pos + 1) {
		$throwNew($SerialException, "length is < 1 or pos + length > total number of bytes"_s);
	}
	return $new($ByteArrayInputStream, this->buf, (int32_t)pos - 1, (int32_t)length);
}

void SerialBlob::free() {
	if (this->buf != nullptr) {
		$set(this, buf, nullptr);
		if (this->blob != nullptr) {
			$nc(this->blob)->free();
		}
		$set(this, blob, nullptr);
	}
}

bool SerialBlob::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if ($instanceOf(SerialBlob, obj)) {
		$var(SerialBlob, sb, $cast(SerialBlob, obj));
		if (this->len == $nc(sb)->len) {
			return $Arrays::equals(this->buf, sb->buf);
		}
	}
	return false;
}

int32_t SerialBlob::hashCode() {
	return ((31 + $Arrays::hashCode(this->buf)) * 31 + (int32_t)this->len) * 31 + (int32_t)this->origLen;
}

$Object* SerialBlob::clone() {
	try {
		$var(SerialBlob, sb, $cast(SerialBlob, $Blob::clone()));
		$set($nc(sb), buf, (this->buf != nullptr) ? $Arrays::copyOf(this->buf, (int32_t)this->len) : ($bytes*)nullptr);
		$set(sb, blob, nullptr);
		return $of(sb);
	} catch ($CloneNotSupportedException& ex) {
		$throwNew($InternalError);
	}
	$shouldNotReachHere();
}

void SerialBlob::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectInputStream$GetField, fields, $nc(s)->readFields());
	$var($bytes, tmp, $cast($bytes, $nc(fields)->get("buf"_s, ($Object*)nullptr)));
	if (tmp == nullptr) {
		$throwNew($InvalidObjectException, "buf is null and should not be!"_s);
	}
	$set(this, buf, $cast($bytes, $nc(tmp)->clone()));
	this->len = fields->get("len"_s, (int64_t)0);
	if ($nc(this->buf)->length != this->len) {
		$throwNew($InvalidObjectException, "buf is not the expected size"_s);
	}
	this->origLen = fields->get("origLen"_s, (int64_t)0);
	$set(this, blob, $cast($Blob, fields->get("blob"_s, ($Object*)nullptr)));
}

void SerialBlob::writeObject($ObjectOutputStream* s) {
	$var($ObjectOutputStream$PutField, fields, $nc(s)->putFields());
	$nc(fields)->put("buf"_s, $of(this->buf));
	fields->put("len"_s, this->len);
	fields->put("origLen"_s, this->origLen);
	fields->put("blob"_s, $instanceOf($Serializable, this->blob) ? $of(this->blob) : ($Object*)nullptr);
	s->writeFields();
}

void SerialBlob::isValid() {
	if (this->buf == nullptr) {
		$throwNew($SerialException, "Error: You cannot call a method on a SerialBlob instance once free() has been called."_s);
	}
}

SerialBlob::SerialBlob() {
}

$Class* SerialBlob::load$($String* name, bool initialize) {
	$loadClass(SerialBlob, name, initialize, &_SerialBlob_ClassInfo_, allocate$SerialBlob);
	return class$;
}

$Class* SerialBlob::class$ = nullptr;

			} // serial
		} // rowset
	} // sql
} // javax
#include <javax/sql/rowset/serial/SerialClob.h>

#include <java/io/BufferedReader.h>
#include <java/io/CharArrayReader.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InvalidObjectException.h>
#include <java/io/ObjectInputStream$GetField.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream$PutField.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Reader.h>
#include <java/io/Serializable.h>
#include <java/io/Writer.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/lang/StringIndexOutOfBoundsException.h>
#include <java/sql/Clob.h>
#include <java/sql/SQLException.h>
#include <java/util/Arrays.h>
#include <javax/sql/rowset/serial/SerialException.h>
#include <jcpp.h>

using $BufferedReader = ::java::io::BufferedReader;
using $CharArrayReader = ::java::io::CharArrayReader;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InvalidObjectException = ::java::io::InvalidObjectException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectInputStream$GetField = ::java::io::ObjectInputStream$GetField;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ObjectOutputStream$PutField = ::java::io::ObjectOutputStream$PutField;
using $OutputStream = ::java::io::OutputStream;
using $Reader = ::java::io::Reader;
using $Serializable = ::java::io::Serializable;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $StringIndexOutOfBoundsException = ::java::lang::StringIndexOutOfBoundsException;
using $Clob = ::java::sql::Clob;
using $SQLException = ::java::sql::SQLException;
using $Arrays = ::java::util::Arrays;
using $SerialException = ::javax::sql::rowset::serial::SerialException;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace serial {

$FieldInfo _SerialClob_FieldInfo_[] = {
	{"buf", "[C", nullptr, $PRIVATE, $field(SerialClob, buf)},
	{"clob", "Ljava/sql/Clob;", nullptr, $PRIVATE, $field(SerialClob, clob)},
	{"len", "J", nullptr, $PRIVATE, $field(SerialClob, len)},
	{"origLen", "J", nullptr, $PRIVATE, $field(SerialClob, origLen)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(SerialClob, serialVersionUID)},
	{}
};

$MethodInfo _SerialClob_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "([C)V", nullptr, $PUBLIC, $method(static_cast<void(SerialClob::*)($chars*)>(&SerialClob::init$)), "javax.sql.rowset.serial.SerialException,java.sql.SQLException"},
	{"<init>", "(Ljava/sql/Clob;)V", nullptr, $PUBLIC, $method(static_cast<void(SerialClob::*)($Clob*)>(&SerialClob::init$)), "javax.sql.rowset.serial.SerialException,java.sql.SQLException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"free", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getAsciiStream", "()Ljava/io/InputStream;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException,java.sql.SQLException"},
	{"getCharacterStream", "()Ljava/io/Reader;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"getCharacterStream", "(JJ)Ljava/io/Reader;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getSubString", "(JI)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"isValid", "()V", nullptr, $PRIVATE, $method(static_cast<void(SerialClob::*)()>(&SerialClob::isValid)), "javax.sql.rowset.serial.SerialException"},
	{"length", "()J", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"position", "(Ljava/lang/String;J)J", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException,java.sql.SQLException"},
	{"position", "(Ljava/sql/Clob;J)J", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException,java.sql.SQLException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(SerialClob::*)($ObjectInputStream*)>(&SerialClob::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"setAsciiStream", "(J)Ljava/io/OutputStream;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException,java.sql.SQLException"},
	{"setCharacterStream", "(J)Ljava/io/Writer;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException,java.sql.SQLException"},
	{"setString", "(JLjava/lang/String;)I", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"setString", "(JLjava/lang/String;II)I", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"truncate", "(J)V", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(SerialClob::*)($ObjectOutputStream*)>(&SerialClob::writeObject)), "java.io.IOException"},
	{}
};

$ClassInfo _SerialClob_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.sql.rowset.serial.SerialClob",
	"java.lang.Object",
	"java.sql.Clob,java.io.Serializable,java.lang.Cloneable",
	_SerialClob_FieldInfo_,
	_SerialClob_MethodInfo_
};

$Object* allocate$SerialClob($Class* clazz) {
	return $of($alloc(SerialClob));
}

$String* SerialClob::toString() {
	 return this->$Clob::toString();
}

void SerialClob::finalize() {
	this->$Clob::finalize();
}

void SerialClob::init$($chars* ch) {
	this->len = $nc(ch)->length;
	$set(this, buf, $new($chars, (int32_t)this->len));
	for (int32_t i = 0; i < this->len; ++i) {
		$nc(this->buf)->set(i, ch->get(i));
	}
	this->origLen = this->len;
	$set(this, clob, nullptr);
}

void SerialClob::init$($Clob* clob) {
	$useLocalCurrentObjectStackCache();
	if (clob == nullptr) {
		$throwNew($SQLException, "Cannot instantiate a SerialClob object with a null Clob object"_s);
	}
	this->len = $nc(clob)->length();
	$set(this, clob, clob);
	$set(this, buf, $new($chars, (int32_t)this->len));
	int32_t read = 0;
	int32_t offset = 0;
	try {
		$var($Reader, charStream, clob->getCharacterStream());
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					if (charStream == nullptr) {
						$throwNew($SQLException, "Invalid Clob object. The call to getCharacterStream returned null which cannot be serialized."_s);
					}
					{
						$var($InputStream, asciiStream, clob->getAsciiStream());
						{
							$var($Throwable, var$1, nullptr);
							try {
								try {
									if (asciiStream == nullptr) {
										$throwNew($SQLException, "Invalid Clob object. The call to getAsciiStream returned null which cannot be serialized."_s);
									}
								} catch ($Throwable& t$) {
									if (asciiStream != nullptr) {
										try {
											asciiStream->close();
										} catch ($Throwable& x2) {
											t$->addSuppressed(x2);
										}
									}
									$throw(t$);
								}
							} catch ($Throwable& var$2) {
								$assign(var$1, var$2);
							} /*finally*/ {
								if (asciiStream != nullptr) {
									asciiStream->close();
								}
							}
							if (var$1 != nullptr) {
								$throw(var$1);
							}
						}
					}
					{
						$var($Reader, reader, $new($BufferedReader, charStream));
						{
							$var($Throwable, var$3, nullptr);
							try {
								try {
									do {
										read = reader->read(this->buf, offset, (int32_t)(this->len - offset));
										offset += read;
									} while (read > 0);
								} catch ($Throwable& t$) {
									try {
										reader->close();
									} catch ($Throwable& x2) {
										t$->addSuppressed(x2);
									}
									$throw(t$);
								}
							} catch ($Throwable& var$4) {
								$assign(var$3, var$4);
							} /*finally*/ {
								reader->close();
							}
							if (var$3 != nullptr) {
								$throw(var$3);
							}
						}
					}
				} catch ($Throwable& t$) {
					if (charStream != nullptr) {
						try {
							charStream->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$5) {
				$assign(var$0, var$5);
			} /*finally*/ {
				if (charStream != nullptr) {
					charStream->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	} catch ($IOException& ex) {
		$throwNew($SerialException, $$str({"SerialClob: "_s, $(ex->getMessage())}));
	}
	this->origLen = this->len;
}

int64_t SerialClob::length() {
	isValid();
	return this->len;
}

$Reader* SerialClob::getCharacterStream() {
	isValid();
	return static_cast<$Reader*>($new($CharArrayReader, this->buf));
}

$InputStream* SerialClob::getAsciiStream() {
	isValid();
	if (this->clob != nullptr) {
		return $nc(this->clob)->getAsciiStream();
	} else {
		$throwNew($SerialException, "Unsupported operation. SerialClob cannot return a the CLOB value as an ascii stream, unless instantiated with a fully implemented Clob object."_s);
	}
}

$String* SerialClob::getSubString(int64_t pos, int32_t length) {
	$useLocalCurrentObjectStackCache();
	isValid();
	if (pos < 1 || pos > this->length()) {
		$throwNew($SerialException, "Invalid position in SerialClob object set"_s);
	}
	if ((pos - 1) + length > this->length()) {
		$throwNew($SerialException, "Invalid position and substring length"_s);
	}
	try {
		return $new($String, this->buf, (int32_t)pos - 1, length);
	} catch ($StringIndexOutOfBoundsException& e) {
		$throwNew($SerialException, $$str({"StringIndexOutOfBoundsException: "_s, $(e->getMessage())}));
	}
	$shouldNotReachHere();
}

int64_t SerialClob::position($String* searchStr, int64_t start) {
	isValid();
	if (start < 1 || start > this->len) {
		return -1;
	}
	$var($chars, pattern, $nc(searchStr)->toCharArray());
	int32_t pos = (int32_t)start - 1;
	int32_t i = 0;
	int64_t patlen = pattern->length;
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

int64_t SerialClob::position($Clob* searchStr, int64_t start) {
	isValid();
	return position($($nc(searchStr)->getSubString(1, (int32_t)searchStr->length())), start);
}

int32_t SerialClob::setString(int64_t pos, $String* str) {
	return (setString(pos, str, 0, $nc(str)->length()));
}

int32_t SerialClob::setString(int64_t pos, $String* str, int32_t offset, int32_t length) {
	$useLocalCurrentObjectStackCache();
	isValid();
	$var($String, temp, $nc(str)->substring(offset));
	$var($chars, cPattern, temp->toCharArray());
	if (offset < 0 || offset > str->length()) {
		$throwNew($SerialException, "Invalid offset in byte array set"_s);
	}
	if (pos < 1 || pos > this->length()) {
		$throwNew($SerialException, "Invalid position in Clob object set"_s);
	}
	if ((int64_t)(length) > this->origLen) {
		$throwNew($SerialException, "Buffer is not sufficient to hold the value"_s);
	}
	if ((length + offset) > str->length()) {
		$throwNew($SerialException, "Invalid OffSet. Cannot have combined offset  and length that is greater that the Blob buffer"_s);
	}
	int32_t i = 0;
	--pos;
	while (i < length || (offset + i + 1) < (str->length() - offset)) {
		$nc(this->buf)->set((int32_t)pos + i, cPattern->get(offset + i));
		++i;
	}
	return i;
}

$OutputStream* SerialClob::setAsciiStream(int64_t pos) {
	isValid();
	if (this->clob != nullptr) {
		return $nc(this->clob)->setAsciiStream(pos);
	} else {
		$throwNew($SerialException, "Unsupported operation. SerialClob cannot return a writable ascii stream\n unless instantiated with a Clob object that has a setAsciiStream() implementation"_s);
	}
}

$Writer* SerialClob::setCharacterStream(int64_t pos) {
	isValid();
	if (this->clob != nullptr) {
		return $nc(this->clob)->setCharacterStream(pos);
	} else {
		$throwNew($SerialException, "Unsupported operation. SerialClob cannot return a writable character stream\n unless instantiated with a Clob object that has a setCharacterStream implementation"_s);
	}
}

void SerialClob::truncate(int64_t length) {
	isValid();
	if (length > this->len) {
		$throwNew($SerialException, "Length more than what can be truncated"_s);
	} else {
		this->len = length;
		if (this->len == 0) {
			$set(this, buf, $new($chars, 0));
		} else {
			$set(this, buf, $nc(($(this->getSubString(1, (int32_t)this->len))))->toCharArray());
		}
	}
}

$Reader* SerialClob::getCharacterStream(int64_t pos, int64_t length) {
	isValid();
	if (pos < 1 || pos > this->len) {
		$throwNew($SerialException, "Invalid position in Clob object set"_s);
	}
	if ((pos - 1) + length > this->len) {
		$throwNew($SerialException, "Invalid position and substring length"_s);
	}
	if (length <= 0) {
		$throwNew($SerialException, "Invalid length specified"_s);
	}
	return $new($CharArrayReader, this->buf, (int32_t)pos, (int32_t)length);
}

void SerialClob::free() {
	if (this->buf != nullptr) {
		$set(this, buf, nullptr);
		if (this->clob != nullptr) {
			$nc(this->clob)->free();
		}
		$set(this, clob, nullptr);
	}
}

bool SerialClob::equals(Object$* obj) {
	if ($equals(this, obj)) {
		return true;
	}
	if ($instanceOf(SerialClob, obj)) {
		$var(SerialClob, sc, $cast(SerialClob, obj));
		if (this->len == $nc(sc)->len) {
			return $Arrays::equals(this->buf, sc->buf);
		}
	}
	return false;
}

int32_t SerialClob::hashCode() {
	return ((31 + $Arrays::hashCode(this->buf)) * 31 + (int32_t)this->len) * 31 + (int32_t)this->origLen;
}

$Object* SerialClob::clone() {
	try {
		$var(SerialClob, sc, $cast(SerialClob, $Clob::clone()));
		$set($nc(sc), buf, (this->buf != nullptr) ? $Arrays::copyOf(this->buf, (int32_t)this->len) : ($chars*)nullptr);
		$set(sc, clob, nullptr);
		return $of(sc);
	} catch ($CloneNotSupportedException& ex) {
		$throwNew($InternalError);
	}
	$shouldNotReachHere();
}

void SerialClob::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectInputStream$GetField, fields, $nc(s)->readFields());
	$var($chars, tmp, $cast($chars, $nc(fields)->get("buf"_s, ($Object*)nullptr)));
	if (tmp == nullptr) {
		$throwNew($InvalidObjectException, "buf is null and should not be!"_s);
	}
	$set(this, buf, $cast($chars, $nc(tmp)->clone()));
	this->len = fields->get("len"_s, (int64_t)0);
	if ($nc(this->buf)->length != this->len) {
		$throwNew($InvalidObjectException, "buf is not the expected size"_s);
	}
	this->origLen = fields->get("origLen"_s, (int64_t)0);
	$set(this, clob, $cast($Clob, fields->get("clob"_s, ($Object*)nullptr)));
}

void SerialClob::writeObject($ObjectOutputStream* s) {
	$var($ObjectOutputStream$PutField, fields, $nc(s)->putFields());
	$nc(fields)->put("buf"_s, $of(this->buf));
	fields->put("len"_s, this->len);
	fields->put("origLen"_s, this->origLen);
	fields->put("clob"_s, $instanceOf($Serializable, this->clob) ? $of(this->clob) : ($Object*)nullptr);
	s->writeFields();
}

void SerialClob::isValid() {
	if (this->buf == nullptr) {
		$throwNew($SerialException, "Error: You cannot call a method on a SerialClob instance once free() has been called."_s);
	}
}

SerialClob::SerialClob() {
}

$Class* SerialClob::load$($String* name, bool initialize) {
	$loadClass(SerialClob, name, initialize, &_SerialClob_ClassInfo_, allocate$SerialClob);
	return class$;
}

$Class* SerialClob::class$ = nullptr;

			} // serial
		} // rowset
	} // sql
} // javax
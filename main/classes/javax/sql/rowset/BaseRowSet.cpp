#include <javax/sql/rowset/BaseRowSet.h>

#include <java/io/InputStream.h>
#include <java/io/Reader.h>
#include <java/io/Serializable.h>
#include <java/math/BigDecimal.h>
#include <java/net/URL.h>
#include <java/sql/Array.h>
#include <java/sql/Blob.h>
#include <java/sql/Clob.h>
#include <java/sql/Connection.h>
#include <java/sql/Date.h>
#include <java/sql/NClob.h>
#include <java/sql/Ref.h>
#include <java/sql/ResultSet.h>
#include <java/sql/RowId.h>
#include <java/sql/SQLException.h>
#include <java/sql/SQLFeatureNotSupportedException.h>
#include <java/sql/SQLXML.h>
#include <java/sql/Time.h>
#include <java/sql/Timestamp.h>
#include <java/util/Calendar.h>
#include <java/util/Hashtable.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/Vector.h>
#include <javax/sql/RowSet.h>
#include <javax/sql/RowSetEvent.h>
#include <javax/sql/RowSetListener.h>
#include <javax/sql/rowset/serial/SerialArray.h>
#include <javax/sql/rowset/serial/SerialBlob.h>
#include <javax/sql/rowset/serial/SerialClob.h>
#include <javax/sql/rowset/serial/SerialRef.h>
#include <jcpp.h>

#undef ASCII_STREAM_PARAM
#undef BINARY_STREAM_PARAM
#undef CONCUR_READ_ONLY
#undef CONCUR_UPDATABLE
#undef FETCH_FORWARD
#undef FETCH_REVERSE
#undef FETCH_UNKNOWN
#undef TRANSACTION_NONE
#undef TRANSACTION_READ_COMMITTED
#undef TRANSACTION_READ_UNCOMMITTED
#undef TRANSACTION_REPEATABLE_READ
#undef TRANSACTION_SERIALIZABLE
#undef TYPE_FORWARD_ONLY
#undef TYPE_SCROLL_INSENSITIVE
#undef TYPE_SCROLL_SENSITIVE
#undef UNICODE_STREAM_PARAM
#undef URL

using $InputStream = ::java::io::InputStream;
using $Reader = ::java::io::Reader;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $Cloneable = ::java::lang::Cloneable;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Double = ::java::lang::Double;
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
using $Connection = ::java::sql::Connection;
using $Date = ::java::sql::Date;
using $NClob = ::java::sql::NClob;
using $Ref = ::java::sql::Ref;
using $ResultSet = ::java::sql::ResultSet;
using $RowId = ::java::sql::RowId;
using $SQLException = ::java::sql::SQLException;
using $SQLFeatureNotSupportedException = ::java::sql::SQLFeatureNotSupportedException;
using $SQLXML = ::java::sql::SQLXML;
using $Time = ::java::sql::Time;
using $Timestamp = ::java::sql::Timestamp;
using $Calendar = ::java::util::Calendar;
using $Hashtable = ::java::util::Hashtable;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Vector = ::java::util::Vector;
using $RowSet = ::javax::sql::RowSet;
using $RowSetEvent = ::javax::sql::RowSetEvent;
using $RowSetListener = ::javax::sql::RowSetListener;
using $SerialArray = ::javax::sql::rowset::serial::SerialArray;
using $SerialBlob = ::javax::sql::rowset::serial::SerialBlob;
using $SerialClob = ::javax::sql::rowset::serial::SerialClob;
using $SerialRef = ::javax::sql::rowset::serial::SerialRef;

namespace javax {
	namespace sql {
		namespace rowset {

$CompoundAttribute _BaseRowSet_MethodAnnotations_setUnicodeStream128[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _BaseRowSet_FieldInfo_[] = {
	{"UNICODE_STREAM_PARAM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(BaseRowSet, UNICODE_STREAM_PARAM)},
	{"BINARY_STREAM_PARAM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(BaseRowSet, BINARY_STREAM_PARAM)},
	{"ASCII_STREAM_PARAM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(BaseRowSet, ASCII_STREAM_PARAM)},
	{"binaryStream", "Ljava/io/InputStream;", nullptr, $PROTECTED, $field(BaseRowSet, binaryStream)},
	{"unicodeStream", "Ljava/io/InputStream;", nullptr, $PROTECTED, $field(BaseRowSet, unicodeStream)},
	{"asciiStream", "Ljava/io/InputStream;", nullptr, $PROTECTED, $field(BaseRowSet, asciiStream)},
	{"charStream", "Ljava/io/Reader;", nullptr, $PROTECTED, $field(BaseRowSet, charStream)},
	{"command", "Ljava/lang/String;", nullptr, $PRIVATE, $field(BaseRowSet, command)},
	{"URL", "Ljava/lang/String;", nullptr, $PRIVATE, $field(BaseRowSet, URL)},
	{"dataSource", "Ljava/lang/String;", nullptr, $PRIVATE, $field(BaseRowSet, dataSource)},
	{"username", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(BaseRowSet, username)},
	{"password", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(BaseRowSet, password)},
	{"rowSetType", "I", nullptr, $PRIVATE, $field(BaseRowSet, rowSetType)},
	{"showDeleted", "Z", nullptr, $PRIVATE, $field(BaseRowSet, showDeleted)},
	{"queryTimeout", "I", nullptr, $PRIVATE, $field(BaseRowSet, queryTimeout)},
	{"maxRows", "I", nullptr, $PRIVATE, $field(BaseRowSet, maxRows)},
	{"maxFieldSize", "I", nullptr, $PRIVATE, $field(BaseRowSet, maxFieldSize)},
	{"concurrency", "I", nullptr, $PRIVATE, $field(BaseRowSet, concurrency)},
	{"readOnly", "Z", nullptr, $PRIVATE, $field(BaseRowSet, readOnly)},
	{"escapeProcessing", "Z", nullptr, $PRIVATE, $field(BaseRowSet, escapeProcessing)},
	{"isolation", "I", nullptr, $PRIVATE, $field(BaseRowSet, isolation)},
	{"fetchDir", "I", nullptr, $PRIVATE, $field(BaseRowSet, fetchDir)},
	{"fetchSize", "I", nullptr, $PRIVATE, $field(BaseRowSet, fetchSize)},
	{"map", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;", $PRIVATE, $field(BaseRowSet, map)},
	{"listeners", "Ljava/util/Vector;", "Ljava/util/Vector<Ljavax/sql/RowSetListener;>;", $PRIVATE, $field(BaseRowSet, listeners)},
	{"params", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Ljava/lang/Integer;Ljava/lang/Object;>;", $PRIVATE, $field(BaseRowSet, params)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(BaseRowSet, serialVersionUID)},
	{}
};

$MethodInfo _BaseRowSet_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(BaseRowSet::*)()>(&BaseRowSet::init$))},
	{"addRowSetListener", "(Ljavax/sql/RowSetListener;)V", nullptr, $PUBLIC},
	{"checkParamIndex", "(I)V", nullptr, $PRIVATE, $method(static_cast<void(BaseRowSet::*)(int32_t)>(&BaseRowSet::checkParamIndex)), "java.sql.SQLException"},
	{"checkforRowSetInterface", "()V", nullptr, $PRIVATE, $method(static_cast<void(BaseRowSet::*)()>(&BaseRowSet::checkforRowSetInterface)), "java.sql.SQLException"},
	{"clearParameters", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getCommand", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getConcurrency", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getDataSourceName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getEscapeProcessing", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getFetchDirection", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getFetchSize", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getMaxFieldSize", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getMaxRows", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getParams", "()[Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getPassword", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getQueryTimeout", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getShowDeleted", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTransactionIsolation", "()I", nullptr, $PUBLIC},
	{"getType", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTypeMap", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;", $PUBLIC},
	{"getUrl", "()Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getUsername", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"initParams", "()V", nullptr, $PROTECTED},
	{"isReadOnly", "()Z", nullptr, $PUBLIC},
	{"notifyCursorMoved", "()V", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"notifyRowChanged", "()V", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"notifyRowSetChanged", "()V", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"removeRowSetListener", "(Ljavax/sql/RowSetListener;)V", nullptr, $PUBLIC},
	{"setArray", "(ILjava/sql/Array;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setAsciiStream", "(ILjava/io/InputStream;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setAsciiStream", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setAsciiStream", "(Ljava/lang/String;Ljava/io/InputStream;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setAsciiStream", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBigDecimal", "(ILjava/math/BigDecimal;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBigDecimal", "(Ljava/lang/String;Ljava/math/BigDecimal;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBinaryStream", "(ILjava/io/InputStream;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBinaryStream", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBinaryStream", "(Ljava/lang/String;Ljava/io/InputStream;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBinaryStream", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBlob", "(ILjava/sql/Blob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBlob", "(ILjava/io/InputStream;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBlob", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBlob", "(Ljava/lang/String;Ljava/io/InputStream;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBlob", "(Ljava/lang/String;Ljava/sql/Blob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBlob", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBoolean", "(IZ)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBoolean", "(Ljava/lang/String;Z)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setByte", "(IB)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setByte", "(Ljava/lang/String;B)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBytes", "(I[B)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBytes", "(Ljava/lang/String;[B)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setCharacterStream", "(ILjava/io/Reader;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setCharacterStream", "(ILjava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setClob", "(ILjava/sql/Clob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setClob", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setClob", "(ILjava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setClob", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setClob", "(Ljava/lang/String;Ljava/sql/Clob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setClob", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setCommand", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setConcurrency", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setDataSourceName", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setDate", "(ILjava/sql/Date;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setDate", "(ILjava/sql/Date;Ljava/util/Calendar;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setDate", "(Ljava/lang/String;Ljava/sql/Date;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setDate", "(Ljava/lang/String;Ljava/sql/Date;Ljava/util/Calendar;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setDouble", "(ID)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setDouble", "(Ljava/lang/String;D)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setEscapeProcessing", "(Z)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setFetchDirection", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setFetchSize", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setFloat", "(IF)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setFloat", "(Ljava/lang/String;F)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setInt", "(II)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setInt", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setLong", "(IJ)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setLong", "(Ljava/lang/String;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setMaxFieldSize", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setMaxRows", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNCharacterStream", "(ILjava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNCharacterStream", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNClob", "(Ljava/lang/String;Ljava/sql/NClob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNClob", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNClob", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNClob", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNClob", "(ILjava/sql/NClob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNClob", "(ILjava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNString", "(ILjava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNString", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNull", "(II)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNull", "(IILjava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNull", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNull", "(Ljava/lang/String;ILjava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setObject", "(ILjava/lang/Object;II)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setObject", "(ILjava/lang/Object;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setObject", "(ILjava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setObject", "(Ljava/lang/String;Ljava/lang/Object;II)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setObject", "(Ljava/lang/String;Ljava/lang/Object;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setObject", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setPassword", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"setQueryTimeout", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setReadOnly", "(Z)V", nullptr, $PUBLIC},
	{"setRef", "(ILjava/sql/Ref;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setRowId", "(ILjava/sql/RowId;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setRowId", "(Ljava/lang/String;Ljava/sql/RowId;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setSQLXML", "(ILjava/sql/SQLXML;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setSQLXML", "(Ljava/lang/String;Ljava/sql/SQLXML;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setShort", "(IS)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setShort", "(Ljava/lang/String;S)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setShowDeleted", "(Z)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setString", "(ILjava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setString", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setTime", "(ILjava/sql/Time;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setTime", "(ILjava/sql/Time;Ljava/util/Calendar;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setTime", "(Ljava/lang/String;Ljava/sql/Time;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setTime", "(Ljava/lang/String;Ljava/sql/Time;Ljava/util/Calendar;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setTimestamp", "(ILjava/sql/Timestamp;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setTimestamp", "(ILjava/sql/Timestamp;Ljava/util/Calendar;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setTimestamp", "(Ljava/lang/String;Ljava/sql/Timestamp;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setTimestamp", "(Ljava/lang/String;Ljava/sql/Timestamp;Ljava/util/Calendar;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setTransactionIsolation", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setType", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setTypeMap", "(Ljava/util/Map;)V", "(Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)V", $PUBLIC},
	{"setURL", "(ILjava/net/URL;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setUnicodeStream", "(ILjava/io/InputStream;I)V", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.sql.SQLException", nullptr, _BaseRowSet_MethodAnnotations_setUnicodeStream128},
	{"setUrl", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setUsername", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _BaseRowSet_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"javax.sql.rowset.BaseRowSet",
	"java.lang.Object",
	"java.io.Serializable,java.lang.Cloneable",
	_BaseRowSet_FieldInfo_,
	_BaseRowSet_MethodInfo_
};

$Object* allocate$BaseRowSet($Class* clazz) {
	return $of($alloc(BaseRowSet));
}

int32_t BaseRowSet::hashCode() {
	 return this->$Serializable::hashCode();
}

bool BaseRowSet::equals(Object$* arg0) {
	 return this->$Serializable::equals(arg0);
}

$Object* BaseRowSet::clone() {
	 return this->$Serializable::clone();
}

$String* BaseRowSet::toString() {
	 return this->$Serializable::toString();
}

void BaseRowSet::finalize() {
	this->$Serializable::finalize();
}

void BaseRowSet::init$() {
	this->rowSetType = $ResultSet::TYPE_SCROLL_INSENSITIVE;
	this->showDeleted = false;
	this->queryTimeout = 0;
	this->maxRows = 0;
	this->maxFieldSize = 0;
	this->concurrency = $ResultSet::CONCUR_UPDATABLE;
	this->escapeProcessing = true;
	this->fetchDir = $ResultSet::FETCH_FORWARD;
	this->fetchSize = 0;
	$set(this, listeners, $new($Vector));
}

void BaseRowSet::initParams() {
	$set(this, params, $new($Hashtable));
}

void BaseRowSet::addRowSetListener($RowSetListener* listener) {
	$nc(this->listeners)->add(listener);
}

void BaseRowSet::removeRowSetListener($RowSetListener* listener) {
	$nc(this->listeners)->remove($of(listener));
}

void BaseRowSet::checkforRowSetInterface() {
	if (($instanceOf($RowSet, this)) == false) {
		$throwNew($SQLException, "The class extending abstract class BaseRowSet must implement javax.sql.RowSet or one of it\'s sub-interfaces."_s);
	}
}

void BaseRowSet::notifyCursorMoved() {
	$useLocalCurrentObjectStackCache();
	checkforRowSetInterface();
	if ($nc(this->listeners)->isEmpty() == false) {
		$var($RowSetEvent, event, $new($RowSetEvent, $cast($RowSet, this)));
		{
			$var($Iterator, i$, $nc(this->listeners)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($RowSetListener, rsl, $cast($RowSetListener, i$->next()));
				{
					$nc(rsl)->cursorMoved(event);
				}
			}
		}
	}
}

void BaseRowSet::notifyRowChanged() {
	$useLocalCurrentObjectStackCache();
	checkforRowSetInterface();
	if ($nc(this->listeners)->isEmpty() == false) {
		$var($RowSetEvent, event, $new($RowSetEvent, $cast($RowSet, this)));
		{
			$var($Iterator, i$, $nc(this->listeners)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($RowSetListener, rsl, $cast($RowSetListener, i$->next()));
				{
					$nc(rsl)->rowChanged(event);
				}
			}
		}
	}
}

void BaseRowSet::notifyRowSetChanged() {
	$useLocalCurrentObjectStackCache();
	checkforRowSetInterface();
	if ($nc(this->listeners)->isEmpty() == false) {
		$var($RowSetEvent, event, $new($RowSetEvent, $cast($RowSet, this)));
		{
			$var($Iterator, i$, $nc(this->listeners)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($RowSetListener, rsl, $cast($RowSetListener, i$->next()));
				{
					$nc(rsl)->rowSetChanged(event);
				}
			}
		}
	}
}

$String* BaseRowSet::getCommand() {
	return this->command;
}

void BaseRowSet::setCommand($String* cmd) {
	if (cmd == nullptr) {
		$set(this, command, nullptr);
	} else if ($nc(cmd)->length() == 0) {
		$throwNew($SQLException, "Invalid command string detected. Cannot be of length less than 0"_s);
	} else {
		if (this->params == nullptr) {
			$throwNew($SQLException, "Set initParams() before setCommand"_s);
		}
		$nc(this->params)->clear();
		$set(this, command, cmd);
	}
}

$String* BaseRowSet::getUrl() {
	return this->URL;
}

void BaseRowSet::setUrl($String* url$renamed) {
	$var($String, url, url$renamed);
	if (url == nullptr) {
		$assign(url, nullptr);
	} else if ($nc(url)->length() < 1) {
		$throwNew($SQLException, "Invalid url string detected. Cannot be of length less than 1"_s);
	} else {
		$set(this, URL, url);
	}
	$set(this, dataSource, nullptr);
}

$String* BaseRowSet::getDataSourceName() {
	return this->dataSource;
}

void BaseRowSet::setDataSourceName($String* name) {
	if (name == nullptr) {
		$set(this, dataSource, nullptr);
	} else if ($nc(name)->isEmpty()) {
		$throwNew($SQLException, "DataSource name cannot be empty string"_s);
	} else {
		$set(this, dataSource, name);
	}
	$set(this, URL, nullptr);
}

$String* BaseRowSet::getUsername() {
	return this->username;
}

void BaseRowSet::setUsername($String* name) {
	if (name == nullptr) {
		$set(this, username, nullptr);
	} else {
		$set(this, username, name);
	}
}

$String* BaseRowSet::getPassword() {
	return this->password;
}

void BaseRowSet::setPassword($String* pass) {
	if (pass == nullptr) {
		$set(this, password, nullptr);
	} else {
		$set(this, password, pass);
	}
}

void BaseRowSet::setType(int32_t type) {
	if ((type != $ResultSet::TYPE_FORWARD_ONLY) && (type != $ResultSet::TYPE_SCROLL_INSENSITIVE) && (type != $ResultSet::TYPE_SCROLL_SENSITIVE)) {
		$throwNew($SQLException, "Invalid type of RowSet set. Must be either ResultSet.TYPE_FORWARD_ONLY or ResultSet.TYPE_SCROLL_INSENSITIVE or ResultSet.TYPE_SCROLL_SENSITIVE."_s);
	}
	this->rowSetType = type;
}

int32_t BaseRowSet::getType() {
	return this->rowSetType;
}

void BaseRowSet::setConcurrency(int32_t concurrency) {
	if ((concurrency != $ResultSet::CONCUR_READ_ONLY) && (concurrency != $ResultSet::CONCUR_UPDATABLE)) {
		$throwNew($SQLException, "Invalid concurrency set. Must be either ResultSet.CONCUR_READ_ONLY or ResultSet.CONCUR_UPDATABLE."_s);
	}
	this->concurrency = concurrency;
}

bool BaseRowSet::isReadOnly() {
	return this->readOnly;
}

void BaseRowSet::setReadOnly(bool value) {
	this->readOnly = value;
}

int32_t BaseRowSet::getTransactionIsolation() {
	return this->isolation;
}

void BaseRowSet::setTransactionIsolation(int32_t level) {
	if ((level != $Connection::TRANSACTION_NONE) && (level != $Connection::TRANSACTION_READ_COMMITTED) && (level != $Connection::TRANSACTION_READ_UNCOMMITTED) && (level != $Connection::TRANSACTION_REPEATABLE_READ) && (level != $Connection::TRANSACTION_SERIALIZABLE)) {
		$throwNew($SQLException, "Invalid transaction isolation set. Must be either Connection.TRANSACTION_NONE or Connection.TRANSACTION_READ_UNCOMMITTED or Connection.TRANSACTION_READ_COMMITTED or Connection.TRANSACTION_REPEATABLE_READ or Connection.TRANSACTION_SERIALIZABLE"_s);
	}
	this->isolation = level;
}

$Map* BaseRowSet::getTypeMap() {
	return this->map;
}

void BaseRowSet::setTypeMap($Map* map) {
	$set(this, map, map);
}

int32_t BaseRowSet::getMaxFieldSize() {
	return this->maxFieldSize;
}

void BaseRowSet::setMaxFieldSize(int32_t max) {
	$useLocalCurrentObjectStackCache();
	if (max < 0) {
		$throwNew($SQLException, $$str({"Invalid max field size set. Cannot be of value: "_s, $$str(max)}));
	}
	this->maxFieldSize = max;
}

int32_t BaseRowSet::getMaxRows() {
	return this->maxRows;
}

void BaseRowSet::setMaxRows(int32_t max) {
	$useLocalCurrentObjectStackCache();
	if (max < 0) {
		$throwNew($SQLException, $$str({"Invalid max row size set. Cannot be of value: "_s, $$str(max)}));
	} else if (max < this->getFetchSize()) {
		$throwNew($SQLException, "Invalid max row size set. Cannot be less than the fetchSize."_s);
	}
	this->maxRows = max;
}

void BaseRowSet::setEscapeProcessing(bool enable) {
	this->escapeProcessing = enable;
}

int32_t BaseRowSet::getQueryTimeout() {
	return this->queryTimeout;
}

void BaseRowSet::setQueryTimeout(int32_t seconds) {
	$useLocalCurrentObjectStackCache();
	if (seconds < 0) {
		$throwNew($SQLException, $$str({"Invalid query timeout value set. Cannot be of value: "_s, $$str(seconds)}));
	}
	this->queryTimeout = seconds;
}

bool BaseRowSet::getShowDeleted() {
	return this->showDeleted;
}

void BaseRowSet::setShowDeleted(bool value) {
	this->showDeleted = value;
}

bool BaseRowSet::getEscapeProcessing() {
	return this->escapeProcessing;
}

void BaseRowSet::setFetchDirection(int32_t direction) {
	if (((getType() == $ResultSet::TYPE_FORWARD_ONLY) && (direction != $ResultSet::FETCH_FORWARD)) || ((direction != $ResultSet::FETCH_FORWARD) && (direction != $ResultSet::FETCH_REVERSE) && (direction != $ResultSet::FETCH_UNKNOWN))) {
		$throwNew($SQLException, "Invalid Fetch Direction"_s);
	}
	this->fetchDir = direction;
}

int32_t BaseRowSet::getFetchDirection() {
	return (this->fetchDir);
}

void BaseRowSet::setFetchSize(int32_t rows) {
	$useLocalCurrentObjectStackCache();
	if (getMaxRows() == 0 && rows >= 0) {
		this->fetchSize = rows;
		return;
	}
	if ((rows < 0) || (rows > getMaxRows())) {
		$throwNew($SQLException, $$str({"Invalid fetch size set. Cannot be of value: "_s, $$str(rows)}));
	}
	this->fetchSize = rows;
}

int32_t BaseRowSet::getFetchSize() {
	return this->fetchSize;
}

int32_t BaseRowSet::getConcurrency() {
	return this->concurrency;
}

void BaseRowSet::checkParamIndex(int32_t idx) {
	if (idx < 1) {
		$throwNew($SQLException, "Invalid Parameter Index"_s);
	}
}

void BaseRowSet::setNull(int32_t parameterIndex, int32_t sqlType) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, nullVal, nullptr);
	checkParamIndex(parameterIndex);
	$assign(nullVal, $new($ObjectArray, 2));
	nullVal->set(0, nullptr);
	nullVal->set(1, $($Integer::valueOf(sqlType)));
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setNull"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), nullVal);
}

void BaseRowSet::setNull(int32_t parameterIndex, int32_t sqlType, $String* typeName) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, nullVal, nullptr);
	checkParamIndex(parameterIndex);
	$assign(nullVal, $new($ObjectArray, 3));
	nullVal->set(0, nullptr);
	nullVal->set(1, $($Integer::valueOf(sqlType)));
	nullVal->set(2, typeName);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setNull"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), nullVal);
}

void BaseRowSet::setBoolean(int32_t parameterIndex, bool x) {
	$useLocalCurrentObjectStackCache();
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setNull"_s);
	}
	$var($Object, var$0, $of($Integer::valueOf(parameterIndex - 1)));
	$nc(this->params)->put(var$0, $($Boolean::valueOf(x)));
}

void BaseRowSet::setByte(int32_t parameterIndex, int8_t x) {
	$useLocalCurrentObjectStackCache();
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setByte"_s);
	}
	$var($Object, var$0, $of($Integer::valueOf(parameterIndex - 1)));
	$nc(this->params)->put(var$0, $($Byte::valueOf(x)));
}

void BaseRowSet::setShort(int32_t parameterIndex, int16_t x) {
	$useLocalCurrentObjectStackCache();
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setShort"_s);
	}
	$var($Object, var$0, $of($Integer::valueOf(parameterIndex - 1)));
	$nc(this->params)->put(var$0, $($Short::valueOf(x)));
}

void BaseRowSet::setInt(int32_t parameterIndex, int32_t x) {
	$useLocalCurrentObjectStackCache();
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setInt"_s);
	}
	$var($Object, var$0, $of($Integer::valueOf(parameterIndex - 1)));
	$nc(this->params)->put(var$0, $($Integer::valueOf(x)));
}

void BaseRowSet::setLong(int32_t parameterIndex, int64_t x) {
	$useLocalCurrentObjectStackCache();
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setLong"_s);
	}
	$var($Object, var$0, $of($Integer::valueOf(parameterIndex - 1)));
	$nc(this->params)->put(var$0, $($Long::valueOf(x)));
}

void BaseRowSet::setFloat(int32_t parameterIndex, float x) {
	$useLocalCurrentObjectStackCache();
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setFloat"_s);
	}
	$var($Object, var$0, $of($Integer::valueOf(parameterIndex - 1)));
	$nc(this->params)->put(var$0, $($Float::valueOf(x)));
}

void BaseRowSet::setDouble(int32_t parameterIndex, double x) {
	$useLocalCurrentObjectStackCache();
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setDouble"_s);
	}
	$var($Object, var$0, $of($Integer::valueOf(parameterIndex - 1)));
	$nc(this->params)->put(var$0, $($Double::valueOf(x)));
}

void BaseRowSet::setBigDecimal(int32_t parameterIndex, $BigDecimal* x) {
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setBigDecimal"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), x);
}

void BaseRowSet::setString(int32_t parameterIndex, $String* x) {
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setString"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), x);
}

void BaseRowSet::setBytes(int32_t parameterIndex, $bytes* x) {
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setBytes"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), x);
}

void BaseRowSet::setDate(int32_t parameterIndex, $Date* x) {
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setDate"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), x);
}

void BaseRowSet::setTime(int32_t parameterIndex, $Time* x) {
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setTime"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), x);
}

void BaseRowSet::setTimestamp(int32_t parameterIndex, $Timestamp* x) {
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setTimestamp"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), x);
}

void BaseRowSet::setAsciiStream(int32_t parameterIndex, $InputStream* x, int32_t length) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, asciiStream, nullptr);
	checkParamIndex(parameterIndex);
	$assign(asciiStream, $new($ObjectArray, 3));
	asciiStream->set(0, x);
	asciiStream->set(1, $($Integer::valueOf(length)));
	asciiStream->set(2, $($Integer::valueOf(BaseRowSet::ASCII_STREAM_PARAM)));
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setAsciiStream"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), asciiStream);
}

void BaseRowSet::setAsciiStream(int32_t parameterIndex, $InputStream* x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setBinaryStream(int32_t parameterIndex, $InputStream* x, int32_t length) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, binaryStream, nullptr);
	checkParamIndex(parameterIndex);
	$assign(binaryStream, $new($ObjectArray, 3));
	binaryStream->set(0, x);
	binaryStream->set(1, $($Integer::valueOf(length)));
	binaryStream->set(2, $($Integer::valueOf(BaseRowSet::BINARY_STREAM_PARAM)));
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setBinaryStream"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), binaryStream);
}

void BaseRowSet::setBinaryStream(int32_t parameterIndex, $InputStream* x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setUnicodeStream(int32_t parameterIndex, $InputStream* x, int32_t length) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, unicodeStream, nullptr);
	checkParamIndex(parameterIndex);
	$assign(unicodeStream, $new($ObjectArray, 3));
	unicodeStream->set(0, x);
	unicodeStream->set(1, $($Integer::valueOf(length)));
	unicodeStream->set(2, $($Integer::valueOf(BaseRowSet::UNICODE_STREAM_PARAM)));
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setUnicodeStream"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), unicodeStream);
}

void BaseRowSet::setCharacterStream(int32_t parameterIndex, $Reader* reader, int32_t length) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, charStream, nullptr);
	checkParamIndex(parameterIndex);
	$assign(charStream, $new($ObjectArray, 2));
	charStream->set(0, reader);
	charStream->set(1, $($Integer::valueOf(length)));
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setCharacterStream"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), charStream);
}

void BaseRowSet::setCharacterStream(int32_t parameterIndex, $Reader* reader) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType, int32_t scale) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, obj, nullptr);
	checkParamIndex(parameterIndex);
	$assign(obj, $new($ObjectArray, 3));
	obj->set(0, x);
	obj->set(1, $($Integer::valueOf(targetSqlType)));
	obj->set(2, $($Integer::valueOf(scale)));
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setObject"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), obj);
}

void BaseRowSet::setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, obj, nullptr);
	checkParamIndex(parameterIndex);
	$assign(obj, $new($ObjectArray, 2));
	obj->set(0, x);
	obj->set(1, $($Integer::valueOf(targetSqlType)));
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setObject"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), obj);
}

void BaseRowSet::setObject(int32_t parameterIndex, Object$* x) {
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setObject"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), x);
}

void BaseRowSet::setRef(int32_t parameterIndex, $Ref* ref) {
	$useLocalCurrentObjectStackCache();
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setRef"_s);
	}
	$var($Object, var$0, $of($Integer::valueOf(parameterIndex - 1)));
	$nc(this->params)->put(var$0, $$new($SerialRef, ref));
}

void BaseRowSet::setBlob(int32_t parameterIndex, $Blob* x) {
	$useLocalCurrentObjectStackCache();
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setBlob"_s);
	}
	$var($Object, var$0, $of($Integer::valueOf(parameterIndex - 1)));
	$nc(this->params)->put(var$0, $$new($SerialBlob, x));
}

void BaseRowSet::setClob(int32_t parameterIndex, $Clob* x) {
	$useLocalCurrentObjectStackCache();
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setClob"_s);
	}
	$var($Object, var$0, $of($Integer::valueOf(parameterIndex - 1)));
	$nc(this->params)->put(var$0, $$new($SerialClob, x));
}

void BaseRowSet::setArray(int32_t parameterIndex, $1Array* array) {
	$useLocalCurrentObjectStackCache();
	checkParamIndex(parameterIndex);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setArray"_s);
	}
	$var($Object, var$0, $of($Integer::valueOf(parameterIndex - 1)));
	$nc(this->params)->put(var$0, $$new($SerialArray, array));
}

void BaseRowSet::setDate(int32_t parameterIndex, $Date* x, $Calendar* cal) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, date, nullptr);
	checkParamIndex(parameterIndex);
	$assign(date, $new($ObjectArray, 2));
	date->set(0, x);
	date->set(1, cal);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setDate"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), date);
}

void BaseRowSet::setTime(int32_t parameterIndex, $Time* x, $Calendar* cal) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, time, nullptr);
	checkParamIndex(parameterIndex);
	$assign(time, $new($ObjectArray, 2));
	time->set(0, x);
	time->set(1, cal);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setTime"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), time);
}

void BaseRowSet::setTimestamp(int32_t parameterIndex, $Timestamp* x, $Calendar* cal) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, timestamp, nullptr);
	checkParamIndex(parameterIndex);
	$assign(timestamp, $new($ObjectArray, 2));
	timestamp->set(0, x);
	timestamp->set(1, cal);
	if (this->params == nullptr) {
		$throwNew($SQLException, "Set initParams() before setTimestamp"_s);
	}
	$nc(this->params)->put($($Integer::valueOf(parameterIndex - 1)), timestamp);
}

void BaseRowSet::clearParameters() {
	$nc(this->params)->clear();
}

$ObjectArray* BaseRowSet::getParams() {
	$useLocalCurrentObjectStackCache();
	if (this->params == nullptr) {
		initParams();
		$var($ObjectArray, paramsArray, $new($ObjectArray, $nc(this->params)->size()));
		return paramsArray;
	} else {
		$var($ObjectArray, paramsArray, $new($ObjectArray, $nc(this->params)->size()));
		for (int32_t i = 0; i < $nc(this->params)->size(); ++i) {
			paramsArray->set(i, $($nc(this->params)->get($($Integer::valueOf(i)))));
			if (paramsArray->get(i) == nullptr) {
				$throwNew($SQLException, $$str({"missing parameter: "_s, $$str((i + 1))}));
			}
		}
		return paramsArray;
	}
}

void BaseRowSet::setNull($String* parameterName, int32_t sqlType) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setNull($String* parameterName, int32_t sqlType, $String* typeName) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setBoolean($String* parameterName, bool x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setByte($String* parameterName, int8_t x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setShort($String* parameterName, int16_t x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setInt($String* parameterName, int32_t x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setLong($String* parameterName, int64_t x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setFloat($String* parameterName, float x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setDouble($String* parameterName, double x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setBigDecimal($String* parameterName, $BigDecimal* x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setString($String* parameterName, $String* x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setBytes($String* parameterName, $bytes* x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setTimestamp($String* parameterName, $Timestamp* x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setAsciiStream($String* parameterName, $InputStream* x, int32_t length) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setBinaryStream($String* parameterName, $InputStream* x, int32_t length) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setCharacterStream($String* parameterName, $Reader* reader, int32_t length) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setAsciiStream($String* parameterName, $InputStream* x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setBinaryStream($String* parameterName, $InputStream* x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setCharacterStream($String* parameterName, $Reader* reader) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setNCharacterStream(int32_t parameterIndex, $Reader* value) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setObject($String* parameterName, Object$* x, int32_t targetSqlType, int32_t scale) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setObject($String* parameterName, Object$* x, int32_t targetSqlType) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setObject($String* parameterName, Object$* x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setBlob(int32_t parameterIndex, $InputStream* inputStream, int64_t length) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setBlob(int32_t parameterIndex, $InputStream* inputStream) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setBlob($String* parameterName, $InputStream* inputStream, int64_t length) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setBlob($String* parameterName, $Blob* x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setBlob($String* parameterName, $InputStream* inputStream) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setClob(int32_t parameterIndex, $Reader* reader, int64_t length) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setClob(int32_t parameterIndex, $Reader* reader) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setClob($String* parameterName, $Reader* reader, int64_t length) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setClob($String* parameterName, $Clob* x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setClob($String* parameterName, $Reader* reader) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setDate($String* parameterName, $Date* x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setDate($String* parameterName, $Date* x, $Calendar* cal) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setTime($String* parameterName, $Time* x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setTime($String* parameterName, $Time* x, $Calendar* cal) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setTimestamp($String* parameterName, $Timestamp* x, $Calendar* cal) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setSQLXML(int32_t parameterIndex, $SQLXML* xmlObject) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setSQLXML($String* parameterName, $SQLXML* xmlObject) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setRowId(int32_t parameterIndex, $RowId* x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setRowId($String* parameterName, $RowId* x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setNString(int32_t parameterIndex, $String* value) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setNString($String* parameterName, $String* value) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setNCharacterStream(int32_t parameterIndex, $Reader* value, int64_t length) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setNCharacterStream($String* parameterName, $Reader* value, int64_t length) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setNCharacterStream($String* parameterName, $Reader* value) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setNClob($String* parameterName, $NClob* value) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setNClob($String* parameterName, $Reader* reader, int64_t length) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setNClob($String* parameterName, $Reader* reader) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setNClob(int32_t parameterIndex, $Reader* reader, int64_t length) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setNClob(int32_t parameterIndex, $NClob* value) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setNClob(int32_t parameterIndex, $Reader* reader) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

void BaseRowSet::setURL(int32_t parameterIndex, $URL* x) {
	$throwNew($SQLFeatureNotSupportedException, "Feature not supported"_s);
}

BaseRowSet::BaseRowSet() {
}

$Class* BaseRowSet::load$($String* name, bool initialize) {
	$loadClass(BaseRowSet, name, initialize, &_BaseRowSet_ClassInfo_, allocate$BaseRowSet);
	return class$;
}

$Class* BaseRowSet::class$ = nullptr;

		} // rowset
	} // sql
} // javax
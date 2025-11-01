#ifndef _javax_sql_rowset_BaseRowSet_h_
#define _javax_sql_rowset_BaseRowSet_h_
//$ class javax.sql.rowset.BaseRowSet
//$ extends java.io.Serializable
//$ implements java.lang.Cloneable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>
#include <java/lang/Cloneable.h>

#pragma push_macro("ASCII_STREAM_PARAM")
#undef ASCII_STREAM_PARAM
#pragma push_macro("BINARY_STREAM_PARAM")
#undef BINARY_STREAM_PARAM
#pragma push_macro("UNICODE_STREAM_PARAM")
#undef UNICODE_STREAM_PARAM
#pragma push_macro("URL")
#undef URL

namespace java {
	namespace io {
		class InputStream;
		class Reader;
	}
}
namespace java {
	namespace math {
		class BigDecimal;
	}
}
namespace java {
	namespace net {
		class URL;
	}
}
namespace java {
	namespace sql {
		class Array;
		class Blob;
		class Clob;
		class Date;
		class NClob;
		class Ref;
		class RowId;
		class SQLXML;
		class Time;
		class Timestamp;
	}
}
namespace java {
	namespace util {
		class Calendar;
		class Hashtable;
		class Map;
		class Vector;
	}
}
namespace javax {
	namespace sql {
		class RowSetListener;
	}
}

namespace javax {
	namespace sql {
		namespace rowset {

class $import BaseRowSet : public ::java::io::Serializable, public ::java::lang::Cloneable {
	$class(BaseRowSet, $NO_CLASS_INIT, ::java::io::Serializable, ::java::lang::Cloneable)
public:
	BaseRowSet();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$();
	virtual void addRowSetListener(::javax::sql::RowSetListener* listener);
	void checkParamIndex(int32_t idx);
	void checkforRowSetInterface();
	virtual void clearParameters();
	virtual $String* getCommand();
	virtual int32_t getConcurrency();
	virtual $String* getDataSourceName();
	virtual bool getEscapeProcessing();
	virtual int32_t getFetchDirection();
	virtual int32_t getFetchSize();
	virtual int32_t getMaxFieldSize();
	virtual int32_t getMaxRows();
	virtual $ObjectArray* getParams();
	virtual $String* getPassword();
	virtual int32_t getQueryTimeout();
	virtual bool getShowDeleted();
	virtual int32_t getTransactionIsolation();
	virtual int32_t getType();
	virtual ::java::util::Map* getTypeMap();
	virtual $String* getUrl();
	virtual $String* getUsername();
	virtual void initParams();
	virtual bool isReadOnly();
	virtual void notifyCursorMoved();
	virtual void notifyRowChanged();
	virtual void notifyRowSetChanged();
	virtual void removeRowSetListener(::javax::sql::RowSetListener* listener);
	virtual void setArray(int32_t parameterIndex, ::java::sql::Array* array);
	virtual void setAsciiStream(int32_t parameterIndex, ::java::io::InputStream* x, int32_t length);
	virtual void setAsciiStream(int32_t parameterIndex, ::java::io::InputStream* x);
	virtual void setAsciiStream($String* parameterName, ::java::io::InputStream* x, int32_t length);
	virtual void setAsciiStream($String* parameterName, ::java::io::InputStream* x);
	virtual void setBigDecimal(int32_t parameterIndex, ::java::math::BigDecimal* x);
	virtual void setBigDecimal($String* parameterName, ::java::math::BigDecimal* x);
	virtual void setBinaryStream(int32_t parameterIndex, ::java::io::InputStream* x, int32_t length);
	virtual void setBinaryStream(int32_t parameterIndex, ::java::io::InputStream* x);
	virtual void setBinaryStream($String* parameterName, ::java::io::InputStream* x, int32_t length);
	virtual void setBinaryStream($String* parameterName, ::java::io::InputStream* x);
	virtual void setBlob(int32_t parameterIndex, ::java::sql::Blob* x);
	virtual void setBlob(int32_t parameterIndex, ::java::io::InputStream* inputStream, int64_t length);
	virtual void setBlob(int32_t parameterIndex, ::java::io::InputStream* inputStream);
	virtual void setBlob($String* parameterName, ::java::io::InputStream* inputStream, int64_t length);
	virtual void setBlob($String* parameterName, ::java::sql::Blob* x);
	virtual void setBlob($String* parameterName, ::java::io::InputStream* inputStream);
	virtual void setBoolean(int32_t parameterIndex, bool x);
	virtual void setBoolean($String* parameterName, bool x);
	virtual void setByte(int32_t parameterIndex, int8_t x);
	virtual void setByte($String* parameterName, int8_t x);
	virtual void setBytes(int32_t parameterIndex, $bytes* x);
	virtual void setBytes($String* parameterName, $bytes* x);
	virtual void setCharacterStream(int32_t parameterIndex, ::java::io::Reader* reader, int32_t length);
	virtual void setCharacterStream(int32_t parameterIndex, ::java::io::Reader* reader);
	virtual void setCharacterStream($String* parameterName, ::java::io::Reader* reader, int32_t length);
	virtual void setCharacterStream($String* parameterName, ::java::io::Reader* reader);
	virtual void setClob(int32_t parameterIndex, ::java::sql::Clob* x);
	virtual void setClob(int32_t parameterIndex, ::java::io::Reader* reader, int64_t length);
	virtual void setClob(int32_t parameterIndex, ::java::io::Reader* reader);
	virtual void setClob($String* parameterName, ::java::io::Reader* reader, int64_t length);
	virtual void setClob($String* parameterName, ::java::sql::Clob* x);
	virtual void setClob($String* parameterName, ::java::io::Reader* reader);
	virtual void setCommand($String* cmd);
	virtual void setConcurrency(int32_t concurrency);
	virtual void setDataSourceName($String* name);
	virtual void setDate(int32_t parameterIndex, ::java::sql::Date* x);
	virtual void setDate(int32_t parameterIndex, ::java::sql::Date* x, ::java::util::Calendar* cal);
	virtual void setDate($String* parameterName, ::java::sql::Date* x);
	virtual void setDate($String* parameterName, ::java::sql::Date* x, ::java::util::Calendar* cal);
	virtual void setDouble(int32_t parameterIndex, double x);
	virtual void setDouble($String* parameterName, double x);
	virtual void setEscapeProcessing(bool enable);
	virtual void setFetchDirection(int32_t direction);
	virtual void setFetchSize(int32_t rows);
	virtual void setFloat(int32_t parameterIndex, float x);
	virtual void setFloat($String* parameterName, float x);
	virtual void setInt(int32_t parameterIndex, int32_t x);
	virtual void setInt($String* parameterName, int32_t x);
	virtual void setLong(int32_t parameterIndex, int64_t x);
	virtual void setLong($String* parameterName, int64_t x);
	virtual void setMaxFieldSize(int32_t max);
	virtual void setMaxRows(int32_t max);
	virtual void setNCharacterStream(int32_t parameterIndex, ::java::io::Reader* value);
	virtual void setNCharacterStream(int32_t parameterIndex, ::java::io::Reader* value, int64_t length);
	virtual void setNCharacterStream($String* parameterName, ::java::io::Reader* value, int64_t length);
	virtual void setNCharacterStream($String* parameterName, ::java::io::Reader* value);
	virtual void setNClob($String* parameterName, ::java::sql::NClob* value);
	virtual void setNClob($String* parameterName, ::java::io::Reader* reader, int64_t length);
	virtual void setNClob($String* parameterName, ::java::io::Reader* reader);
	virtual void setNClob(int32_t parameterIndex, ::java::io::Reader* reader, int64_t length);
	virtual void setNClob(int32_t parameterIndex, ::java::sql::NClob* value);
	virtual void setNClob(int32_t parameterIndex, ::java::io::Reader* reader);
	virtual void setNString(int32_t parameterIndex, $String* value);
	virtual void setNString($String* parameterName, $String* value);
	virtual void setNull(int32_t parameterIndex, int32_t sqlType);
	virtual void setNull(int32_t parameterIndex, int32_t sqlType, $String* typeName);
	virtual void setNull($String* parameterName, int32_t sqlType);
	virtual void setNull($String* parameterName, int32_t sqlType, $String* typeName);
	virtual void setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType, int32_t scale);
	virtual void setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType);
	virtual void setObject(int32_t parameterIndex, Object$* x);
	virtual void setObject($String* parameterName, Object$* x, int32_t targetSqlType, int32_t scale);
	virtual void setObject($String* parameterName, Object$* x, int32_t targetSqlType);
	virtual void setObject($String* parameterName, Object$* x);
	virtual void setPassword($String* pass);
	virtual void setQueryTimeout(int32_t seconds);
	virtual void setReadOnly(bool value);
	virtual void setRef(int32_t parameterIndex, ::java::sql::Ref* ref);
	virtual void setRowId(int32_t parameterIndex, ::java::sql::RowId* x);
	virtual void setRowId($String* parameterName, ::java::sql::RowId* x);
	virtual void setSQLXML(int32_t parameterIndex, ::java::sql::SQLXML* xmlObject);
	virtual void setSQLXML($String* parameterName, ::java::sql::SQLXML* xmlObject);
	virtual void setShort(int32_t parameterIndex, int16_t x);
	virtual void setShort($String* parameterName, int16_t x);
	virtual void setShowDeleted(bool value);
	virtual void setString(int32_t parameterIndex, $String* x);
	virtual void setString($String* parameterName, $String* x);
	virtual void setTime(int32_t parameterIndex, ::java::sql::Time* x);
	virtual void setTime(int32_t parameterIndex, ::java::sql::Time* x, ::java::util::Calendar* cal);
	virtual void setTime($String* parameterName, ::java::sql::Time* x);
	virtual void setTime($String* parameterName, ::java::sql::Time* x, ::java::util::Calendar* cal);
	virtual void setTimestamp(int32_t parameterIndex, ::java::sql::Timestamp* x);
	virtual void setTimestamp(int32_t parameterIndex, ::java::sql::Timestamp* x, ::java::util::Calendar* cal);
	virtual void setTimestamp($String* parameterName, ::java::sql::Timestamp* x);
	virtual void setTimestamp($String* parameterName, ::java::sql::Timestamp* x, ::java::util::Calendar* cal);
	virtual void setTransactionIsolation(int32_t level);
	virtual void setType(int32_t type);
	virtual void setTypeMap(::java::util::Map* map);
	virtual void setURL(int32_t parameterIndex, ::java::net::URL* x);
	virtual void setUnicodeStream(int32_t parameterIndex, ::java::io::InputStream* x, int32_t length);
	virtual void setUrl($String* url);
	virtual void setUsername($String* name);
	virtual $String* toString() override;
	static const int32_t UNICODE_STREAM_PARAM = 0;
	static const int32_t BINARY_STREAM_PARAM = 1;
	static const int32_t ASCII_STREAM_PARAM = 2;
	::java::io::InputStream* binaryStream = nullptr;
	::java::io::InputStream* unicodeStream = nullptr;
	::java::io::InputStream* asciiStream = nullptr;
	::java::io::Reader* charStream = nullptr;
	$String* command = nullptr;
	$String* URL = nullptr;
	$String* dataSource = nullptr;
	$String* username = nullptr;
	$String* password = nullptr;
	int32_t rowSetType = 0;
	bool showDeleted = false;
	int32_t queryTimeout = 0;
	int32_t maxRows = 0;
	int32_t maxFieldSize = 0;
	int32_t concurrency = 0;
	bool readOnly = false;
	bool escapeProcessing = false;
	int32_t isolation = 0;
	int32_t fetchDir = 0;
	int32_t fetchSize = 0;
	::java::util::Map* map = nullptr;
	::java::util::Vector* listeners = nullptr;
	::java::util::Hashtable* params = nullptr;
	static const int64_t serialVersionUID = (int64_t)0x43D11DA54DC2B1E0;
};

		} // rowset
	} // sql
} // javax

#pragma pop_macro("ASCII_STREAM_PARAM")
#pragma pop_macro("BINARY_STREAM_PARAM")
#pragma pop_macro("UNICODE_STREAM_PARAM")
#pragma pop_macro("URL")

#endif // _javax_sql_rowset_BaseRowSet_h_
#include <com/sun/rowset/FilteredRowSetImpl.h>

#include <com/sun/rowset/CachedRowSetImpl.h>
#include <com/sun/rowset/JdbcRowSetResourceBundle.h>
#include <com/sun/rowset/WebRowSetImpl.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Reader.h>
#include <java/io/Writer.h>
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
#include <java/sql/ResultSetMetaData.h>
#include <java/sql/RowId.h>
#include <java/sql/SQLException.h>
#include <java/sql/SQLType.h>
#include <java/sql/SQLWarning.h>
#include <java/sql/SQLXML.h>
#include <java/sql/Savepoint.h>
#include <java/sql/Statement.h>
#include <java/sql/Time.h>
#include <java/sql/Timestamp.h>
#include <java/util/Calendar.h>
#include <java/util/Collection.h>
#include <java/util/Hashtable.h>
#include <java/util/Map.h>
#include <javax/sql/RowSet.h>
#include <javax/sql/RowSetEvent.h>
#include <javax/sql/RowSetListener.h>
#include <javax/sql/RowSetMetaData.h>
#include <javax/sql/rowset/BaseRowSet.h>
#include <javax/sql/rowset/CachedRowSet.h>
#include <javax/sql/rowset/Predicate.h>
#include <javax/sql/rowset/RowSetWarning.h>
#include <javax/sql/rowset/spi/SyncProvider.h>
#include <jcpp.h>

#undef TYPE_FORWARD_ONLY

using $ByteArray = $Array<::java::lang::Byte>;
using $CachedRowSetImpl = ::com::sun::rowset::CachedRowSetImpl;
using $JdbcRowSetResourceBundle = ::com::sun::rowset::JdbcRowSetResourceBundle;
using $WebRowSetImpl = ::com::sun::rowset::WebRowSetImpl;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $OutputStream = ::java::io::OutputStream;
using $Reader = ::java::io::Reader;
using $Writer = ::java::io::Writer;
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
using $RuntimeException = ::java::lang::RuntimeException;
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
using $ResultSetMetaData = ::java::sql::ResultSetMetaData;
using $RowId = ::java::sql::RowId;
using $SQLException = ::java::sql::SQLException;
using $SQLType = ::java::sql::SQLType;
using $SQLWarning = ::java::sql::SQLWarning;
using $SQLXML = ::java::sql::SQLXML;
using $Savepoint = ::java::sql::Savepoint;
using $Statement = ::java::sql::Statement;
using $Time = ::java::sql::Time;
using $Timestamp = ::java::sql::Timestamp;
using $Calendar = ::java::util::Calendar;
using $Collection = ::java::util::Collection;
using $Hashtable = ::java::util::Hashtable;
using $Map = ::java::util::Map;
using $RowSet = ::javax::sql::RowSet;
using $RowSetEvent = ::javax::sql::RowSetEvent;
using $RowSetListener = ::javax::sql::RowSetListener;
using $RowSetMetaData = ::javax::sql::RowSetMetaData;
using $BaseRowSet = ::javax::sql::rowset::BaseRowSet;
using $CachedRowSet = ::javax::sql::rowset::CachedRowSet;
using $FilteredRowSet = ::javax::sql::rowset::FilteredRowSet;
using $Predicate = ::javax::sql::rowset::Predicate;
using $RowSetWarning = ::javax::sql::rowset::RowSetWarning;
using $SyncProvider = ::javax::sql::rowset::spi::SyncProvider;

namespace com {
	namespace sun {
		namespace rowset {

$FieldInfo _FilteredRowSetImpl_FieldInfo_[] = {
	{"p", "Ljavax/sql/rowset/Predicate;", nullptr, $PRIVATE, $field(FilteredRowSetImpl, p)},
	{"onInsertRow", "Z", nullptr, $PRIVATE, $field(FilteredRowSetImpl, onInsertRow)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(FilteredRowSetImpl, serialVersionUID)},
	{}
};

$MethodInfo _FilteredRowSetImpl_MethodInfo_[] = {
	{"*acceptChanges", "()V", nullptr, $PUBLIC},
	{"*acceptChanges", "(Ljava/sql/Connection;)V", nullptr, $PUBLIC},
	{"*addRowSetListener", "(Ljavax/sql/RowSetListener;)V", nullptr, $PUBLIC},
	{"*afterLast", "()V", nullptr, $PUBLIC},
	{"*beforeFirst", "()V", nullptr, $PUBLIC},
	{"*cancelRowUpdates", "()V", nullptr, $PUBLIC},
	{"*clearParameters", "()V", nullptr, $PUBLIC},
	{"*clearWarnings", "()V", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED},
	{"*close", "()V", nullptr, $PUBLIC},
	{"*columnUpdated", "(I)Z", nullptr, $PUBLIC},
	{"*columnUpdated", "(Ljava/lang/String;)Z", nullptr, $PUBLIC},
	{"*commit", "()V", nullptr, $PUBLIC},
	{"*createCopy", "()Ljavax/sql/rowset/CachedRowSet;", nullptr, $PUBLIC},
	{"*createCopyNoConstraints", "()Ljavax/sql/rowset/CachedRowSet;", nullptr, $PUBLIC},
	{"*createCopySchema", "()Ljavax/sql/rowset/CachedRowSet;", nullptr, $PUBLIC},
	{"*createShared", "()Ljavax/sql/RowSet;", nullptr, $PUBLIC},
	{"*deleteRow", "()V", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*execute", "(Ljava/sql/Connection;)V", nullptr, $PUBLIC},
	{"*execute", "()V", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*findColumn", "(Ljava/lang/String;)I", nullptr, $PUBLIC},
	{"*first", "()Z", nullptr, $PUBLIC},
	{"*getArray", "(I)Ljava/sql/Array;", nullptr, $PUBLIC},
	{"*getArray", "(Ljava/lang/String;)Ljava/sql/Array;", nullptr, $PUBLIC},
	{"*getAsciiStream", "(I)Ljava/io/InputStream;", nullptr, $PUBLIC},
	{"*getAsciiStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC},
	{"*getBigDecimal", "(II)Ljava/math/BigDecimal;", nullptr, $PUBLIC | $DEPRECATED},
	{"*getBigDecimal", "(Ljava/lang/String;I)Ljava/math/BigDecimal;", nullptr, $PUBLIC | $DEPRECATED},
	{"*getBigDecimal", "(I)Ljava/math/BigDecimal;", nullptr, $PUBLIC},
	{"*getBigDecimal", "(Ljava/lang/String;)Ljava/math/BigDecimal;", nullptr, $PUBLIC},
	{"*getBinaryStream", "(I)Ljava/io/InputStream;", nullptr, $PUBLIC},
	{"*getBinaryStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC},
	{"*getBlob", "(I)Ljava/sql/Blob;", nullptr, $PUBLIC},
	{"*getBlob", "(Ljava/lang/String;)Ljava/sql/Blob;", nullptr, $PUBLIC},
	{"*getBoolean", "(I)Z", nullptr, $PUBLIC},
	{"*getBoolean", "(Ljava/lang/String;)Z", nullptr, $PUBLIC},
	{"*getByte", "(I)B", nullptr, $PUBLIC},
	{"*getByte", "(Ljava/lang/String;)B", nullptr, $PUBLIC},
	{"*getBytes", "(I)[B", nullptr, $PUBLIC},
	{"*getBytes", "(Ljava/lang/String;)[B", nullptr, $PUBLIC},
	{"*getCharacterStream", "(I)Ljava/io/Reader;", nullptr, $PUBLIC},
	{"*getCharacterStream", "(Ljava/lang/String;)Ljava/io/Reader;", nullptr, $PUBLIC},
	{"*getClob", "(I)Ljava/sql/Clob;", nullptr, $PUBLIC},
	{"*getClob", "(Ljava/lang/String;)Ljava/sql/Clob;", nullptr, $PUBLIC},
	{"*getCommand", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getConcurrency", "()I", nullptr, $PUBLIC},
	{"*getCursorName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getDataSourceName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getDate", "(I)Ljava/sql/Date;", nullptr, $PUBLIC},
	{"*getDate", "(Ljava/lang/String;)Ljava/sql/Date;", nullptr, $PUBLIC},
	{"*getDate", "(ILjava/util/Calendar;)Ljava/sql/Date;", nullptr, $PUBLIC},
	{"*getDate", "(Ljava/lang/String;Ljava/util/Calendar;)Ljava/sql/Date;", nullptr, $PUBLIC},
	{"*getDouble", "(I)D", nullptr, $PUBLIC},
	{"*getDouble", "(Ljava/lang/String;)D", nullptr, $PUBLIC},
	{"*getEscapeProcessing", "()Z", nullptr, $PUBLIC},
	{"*getFetchDirection", "()I", nullptr, $PUBLIC},
	{"*getFetchSize", "()I", nullptr, $PUBLIC},
	{"*getFloat", "(I)F", nullptr, $PUBLIC},
	{"*getFloat", "(Ljava/lang/String;)F", nullptr, $PUBLIC},
	{"*getHoldability", "()I", nullptr, $PUBLIC},
	{"*getInt", "(I)I", nullptr, $PUBLIC},
	{"*getInt", "(Ljava/lang/String;)I", nullptr, $PUBLIC},
	{"*getKeyColumns", "()[I", nullptr, $PUBLIC},
	{"*getLong", "(I)J", nullptr, $PUBLIC},
	{"*getLong", "(Ljava/lang/String;)J", nullptr, $PUBLIC},
	{"*getMatchColumnIndexes", "()[I", nullptr, $PUBLIC},
	{"*getMatchColumnNames", "()[Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getMaxFieldSize", "()I", nullptr, $PUBLIC},
	{"*getMaxRows", "()I", nullptr, $PUBLIC},
	{"*getMetaData", "()Ljava/sql/ResultSetMetaData;", nullptr, $PUBLIC},
	{"*getNCharacterStream", "(I)Ljava/io/Reader;", nullptr, $PUBLIC},
	{"*getNCharacterStream", "(Ljava/lang/String;)Ljava/io/Reader;", nullptr, $PUBLIC},
	{"*getNClob", "(I)Ljava/sql/NClob;", nullptr, $PUBLIC},
	{"*getNClob", "(Ljava/lang/String;)Ljava/sql/NClob;", nullptr, $PUBLIC},
	{"*getNString", "(I)Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getNString", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getObject", "(I)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*getObject", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*getObject", "(ILjava/util/Map;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*getObject", "(Ljava/lang/String;Ljava/util/Map;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*getObject", "(ILjava/lang/Class;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*getObject", "(Ljava/lang/String;Ljava/lang/Class;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*getOriginal", "()Ljava/sql/ResultSet;", nullptr, $PUBLIC},
	{"*getOriginalRow", "()Ljava/sql/ResultSet;", nullptr, $PUBLIC},
	{"*getPageSize", "()I", nullptr, $PUBLIC},
	{"*getPassword", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getQueryTimeout", "()I", nullptr, $PUBLIC},
	{"*getRef", "(I)Ljava/sql/Ref;", nullptr, $PUBLIC},
	{"*getRef", "(Ljava/lang/String;)Ljava/sql/Ref;", nullptr, $PUBLIC},
	{"*getRow", "()I", nullptr, $PUBLIC},
	{"*getRowId", "(I)Ljava/sql/RowId;", nullptr, $PUBLIC},
	{"*getRowId", "(Ljava/lang/String;)Ljava/sql/RowId;", nullptr, $PUBLIC},
	{"*getRowSetWarnings", "()Ljavax/sql/rowset/RowSetWarning;", nullptr, $PUBLIC},
	{"*getSQLXML", "(I)Ljava/sql/SQLXML;", nullptr, $PUBLIC},
	{"*getSQLXML", "(Ljava/lang/String;)Ljava/sql/SQLXML;", nullptr, $PUBLIC},
	{"*getShort", "(I)S", nullptr, $PUBLIC},
	{"*getShort", "(Ljava/lang/String;)S", nullptr, $PUBLIC},
	{"*getShowDeleted", "()Z", nullptr, $PUBLIC},
	{"*getStatement", "()Ljava/sql/Statement;", nullptr, $PUBLIC},
	{"*getString", "(I)Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getString", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getSyncProvider", "()Ljavax/sql/rowset/spi/SyncProvider;", nullptr, $PUBLIC},
	{"*getTableName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getTime", "(I)Ljava/sql/Time;", nullptr, $PUBLIC},
	{"*getTime", "(Ljava/lang/String;)Ljava/sql/Time;", nullptr, $PUBLIC},
	{"*getTime", "(ILjava/util/Calendar;)Ljava/sql/Time;", nullptr, $PUBLIC},
	{"*getTime", "(Ljava/lang/String;Ljava/util/Calendar;)Ljava/sql/Time;", nullptr, $PUBLIC},
	{"*getTimestamp", "(I)Ljava/sql/Timestamp;", nullptr, $PUBLIC},
	{"*getTimestamp", "(Ljava/lang/String;)Ljava/sql/Timestamp;", nullptr, $PUBLIC},
	{"*getTimestamp", "(ILjava/util/Calendar;)Ljava/sql/Timestamp;", nullptr, $PUBLIC},
	{"*getTimestamp", "(Ljava/lang/String;Ljava/util/Calendar;)Ljava/sql/Timestamp;", nullptr, $PUBLIC},
	{"*getTransactionIsolation", "()I", nullptr, $PUBLIC},
	{"*getType", "()I", nullptr, $PUBLIC},
	{"*getTypeMap", "()Ljava/util/Map;", nullptr, $PUBLIC},
	{"*getURL", "(I)Ljava/net/URL;", nullptr, $PUBLIC},
	{"*getURL", "(Ljava/lang/String;)Ljava/net/URL;", nullptr, $PUBLIC},
	{"*getUnicodeStream", "(I)Ljava/io/InputStream;", nullptr, $PUBLIC | $DEPRECATED},
	{"*getUnicodeStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC | $DEPRECATED},
	{"*getUrl", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getUsername", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getWarnings", "()Ljava/sql/SQLWarning;", nullptr, $PUBLIC},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(FilteredRowSetImpl::*)()>(&FilteredRowSetImpl::init$)), "java.sql.SQLException"},
	{"<init>", "(Ljava/util/Hashtable;)V", nullptr, $PUBLIC, $method(static_cast<void(FilteredRowSetImpl::*)($Hashtable*)>(&FilteredRowSetImpl::init$)), "java.sql.SQLException"},
	{"absolute", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getFilter", "()Ljavax/sql/rowset/Predicate;", nullptr, $PUBLIC},
	{"insertRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"internalFirst", "()Z", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"internalLast", "()Z", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"internalNext", "()Z", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"internalPrevious", "()Z", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"*isAfterLast", "()Z", nullptr, $PUBLIC},
	{"*isBeforeFirst", "()Z", nullptr, $PUBLIC},
	{"*isClosed", "()Z", nullptr, $PUBLIC},
	{"*isFirst", "()Z", nullptr, $PUBLIC},
	{"*isLast", "()Z", nullptr, $PUBLIC},
	{"*isReadOnly", "()Z", nullptr, $PUBLIC},
	{"*isWrapperFor", "(Ljava/lang/Class;)Z", nullptr, $PUBLIC},
	{"*last", "()Z", nullptr, $PUBLIC},
	{"*moveToCurrentRow", "()V", nullptr, $PUBLIC},
	{"moveToInsertRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*next", "()Z", nullptr, $PUBLIC},
	{"*nextPage", "()Z", nullptr, $PUBLIC},
	{"*populate", "(Ljava/sql/ResultSet;)V", nullptr, $PUBLIC},
	{"*populate", "(Ljava/sql/ResultSet;I)V", nullptr, $PUBLIC},
	{"*previous", "()Z", nullptr, $PUBLIC},
	{"*previousPage", "()Z", nullptr, $PUBLIC},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(FilteredRowSetImpl::*)($ObjectInputStream*)>(&FilteredRowSetImpl::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"*readXml", "(Ljava/io/Reader;)V", nullptr, $PUBLIC},
	{"*readXml", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC},
	{"*refreshRow", "()V", nullptr, $PUBLIC},
	{"relative", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*release", "()V", nullptr, $PUBLIC},
	{"*removeRowSetListener", "(Ljavax/sql/RowSetListener;)V", nullptr, $PUBLIC},
	{"*restoreOriginal", "()V", nullptr, $PUBLIC},
	{"*rollback", "()V", nullptr, $PUBLIC},
	{"*rollback", "(Ljava/sql/Savepoint;)V", nullptr, $PUBLIC},
	{"*rowDeleted", "()Z", nullptr, $PUBLIC},
	{"*rowInserted", "()Z", nullptr, $PUBLIC},
	{"*rowSetPopulated", "(Ljavax/sql/RowSetEvent;I)V", nullptr, $PUBLIC},
	{"*rowUpdated", "()Z", nullptr, $PUBLIC},
	{"*setArray", "(ILjava/sql/Array;)V", nullptr, $PUBLIC},
	{"*setAsciiStream", "(Ljava/lang/String;Ljava/io/InputStream;I)V", nullptr, $PUBLIC},
	{"*setAsciiStream", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC},
	{"*setAsciiStream", "(ILjava/io/InputStream;I)V", nullptr, $PUBLIC},
	{"*setAsciiStream", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC},
	{"*setBigDecimal", "(Ljava/lang/String;Ljava/math/BigDecimal;)V", nullptr, $PUBLIC},
	{"*setBigDecimal", "(ILjava/math/BigDecimal;)V", nullptr, $PUBLIC},
	{"*setBinaryStream", "(Ljava/lang/String;Ljava/io/InputStream;I)V", nullptr, $PUBLIC},
	{"*setBinaryStream", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC},
	{"*setBinaryStream", "(ILjava/io/InputStream;I)V", nullptr, $PUBLIC},
	{"*setBinaryStream", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC},
	{"*setBlob", "(ILjava/io/InputStream;J)V", nullptr, $PUBLIC},
	{"*setBlob", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC},
	{"*setBlob", "(Ljava/lang/String;Ljava/io/InputStream;J)V", nullptr, $PUBLIC},
	{"*setBlob", "(Ljava/lang/String;Ljava/sql/Blob;)V", nullptr, $PUBLIC},
	{"*setBlob", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC},
	{"*setBlob", "(ILjava/sql/Blob;)V", nullptr, $PUBLIC},
	{"*setBoolean", "(Ljava/lang/String;Z)V", nullptr, $PUBLIC},
	{"*setBoolean", "(IZ)V", nullptr, $PUBLIC},
	{"*setByte", "(Ljava/lang/String;B)V", nullptr, $PUBLIC},
	{"*setByte", "(IB)V", nullptr, $PUBLIC},
	{"*setBytes", "(Ljava/lang/String;[B)V", nullptr, $PUBLIC},
	{"*setBytes", "(I[B)V", nullptr, $PUBLIC},
	{"*setCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;I)V", nullptr, $PUBLIC},
	{"*setCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC},
	{"*setCharacterStream", "(ILjava/io/Reader;I)V", nullptr, $PUBLIC},
	{"*setCharacterStream", "(ILjava/io/Reader;)V", nullptr, $PUBLIC},
	{"*setClob", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*setClob", "(Ljava/lang/String;Ljava/sql/Clob;)V", nullptr, $PUBLIC},
	{"*setClob", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC},
	{"*setClob", "(ILjava/io/Reader;)V", nullptr, $PUBLIC},
	{"*setClob", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*setClob", "(ILjava/sql/Clob;)V", nullptr, $PUBLIC},
	{"*setCommand", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*setConcurrency", "(I)V", nullptr, $PUBLIC},
	{"*setDataSourceName", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*setDate", "(Ljava/lang/String;Ljava/sql/Date;)V", nullptr, $PUBLIC},
	{"*setDate", "(Ljava/lang/String;Ljava/sql/Date;Ljava/util/Calendar;)V", nullptr, $PUBLIC},
	{"*setDate", "(ILjava/sql/Date;)V", nullptr, $PUBLIC},
	{"*setDate", "(ILjava/sql/Date;Ljava/util/Calendar;)V", nullptr, $PUBLIC},
	{"*setDouble", "(Ljava/lang/String;D)V", nullptr, $PUBLIC},
	{"*setDouble", "(ID)V", nullptr, $PUBLIC},
	{"*setEscapeProcessing", "(Z)V", nullptr, $PUBLIC},
	{"*setFetchDirection", "(I)V", nullptr, $PUBLIC},
	{"*setFetchSize", "(I)V", nullptr, $PUBLIC},
	{"setFilter", "(Ljavax/sql/rowset/Predicate;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setFloat", "(Ljava/lang/String;F)V", nullptr, $PUBLIC},
	{"*setFloat", "(IF)V", nullptr, $PUBLIC},
	{"*setInt", "(Ljava/lang/String;I)V", nullptr, $PUBLIC},
	{"*setInt", "(II)V", nullptr, $PUBLIC},
	{"*setKeyColumns", "([I)V", nullptr, $PUBLIC},
	{"*setLong", "(Ljava/lang/String;J)V", nullptr, $PUBLIC},
	{"*setLong", "(IJ)V", nullptr, $PUBLIC},
	{"*setMatchColumn", "([I)V", nullptr, $PUBLIC},
	{"*setMatchColumn", "([Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*setMatchColumn", "(I)V", nullptr, $PUBLIC},
	{"*setMatchColumn", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*setMaxFieldSize", "(I)V", nullptr, $PUBLIC},
	{"*setMaxRows", "(I)V", nullptr, $PUBLIC},
	{"*setMetaData", "(Ljavax/sql/RowSetMetaData;)V", nullptr, $PUBLIC},
	{"*setNCharacterStream", "(ILjava/io/Reader;)V", nullptr, $PUBLIC},
	{"*setNCharacterStream", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*setNCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*setNCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC},
	{"*setNClob", "(Ljava/lang/String;Ljava/sql/NClob;)V", nullptr, $PUBLIC},
	{"*setNClob", "(ILjava/io/Reader;)V", nullptr, $PUBLIC},
	{"*setNClob", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*setNClob", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC},
	{"*setNClob", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*setNClob", "(ILjava/sql/NClob;)V", nullptr, $PUBLIC},
	{"*setNString", "(ILjava/lang/String;)V", nullptr, $PUBLIC},
	{"*setNString", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*setNull", "(Ljava/lang/String;I)V", nullptr, $PUBLIC},
	{"*setNull", "(Ljava/lang/String;ILjava/lang/String;)V", nullptr, $PUBLIC},
	{"*setNull", "(II)V", nullptr, $PUBLIC},
	{"*setNull", "(IILjava/lang/String;)V", nullptr, $PUBLIC},
	{"*setObject", "(Ljava/lang/String;Ljava/lang/Object;II)V", nullptr, $PUBLIC},
	{"*setObject", "(Ljava/lang/String;Ljava/lang/Object;I)V", nullptr, $PUBLIC},
	{"*setObject", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"*setObject", "(ILjava/lang/Object;II)V", nullptr, $PUBLIC},
	{"*setObject", "(ILjava/lang/Object;I)V", nullptr, $PUBLIC},
	{"*setObject", "(ILjava/lang/Object;)V", nullptr, $PUBLIC},
	{"*setOriginalRow", "()V", nullptr, $PUBLIC},
	{"*setPageSize", "(I)V", nullptr, $PUBLIC},
	{"*setPassword", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*setQueryTimeout", "(I)V", nullptr, $PUBLIC},
	{"*setReadOnly", "(Z)V", nullptr, $PUBLIC},
	{"*setRef", "(ILjava/sql/Ref;)V", nullptr, $PUBLIC},
	{"*setRowId", "(ILjava/sql/RowId;)V", nullptr, $PUBLIC},
	{"*setRowId", "(Ljava/lang/String;Ljava/sql/RowId;)V", nullptr, $PUBLIC},
	{"*setSQLXML", "(ILjava/sql/SQLXML;)V", nullptr, $PUBLIC},
	{"*setSQLXML", "(Ljava/lang/String;Ljava/sql/SQLXML;)V", nullptr, $PUBLIC},
	{"*setShort", "(Ljava/lang/String;S)V", nullptr, $PUBLIC},
	{"*setShort", "(IS)V", nullptr, $PUBLIC},
	{"*setShowDeleted", "(Z)V", nullptr, $PUBLIC},
	{"*setString", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*setString", "(ILjava/lang/String;)V", nullptr, $PUBLIC},
	{"*setSyncProvider", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*setTableName", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*setTime", "(Ljava/lang/String;Ljava/sql/Time;)V", nullptr, $PUBLIC},
	{"*setTime", "(Ljava/lang/String;Ljava/sql/Time;Ljava/util/Calendar;)V", nullptr, $PUBLIC},
	{"*setTime", "(ILjava/sql/Time;)V", nullptr, $PUBLIC},
	{"*setTime", "(ILjava/sql/Time;Ljava/util/Calendar;)V", nullptr, $PUBLIC},
	{"*setTimestamp", "(Ljava/lang/String;Ljava/sql/Timestamp;Ljava/util/Calendar;)V", nullptr, $PUBLIC},
	{"*setTimestamp", "(Ljava/lang/String;Ljava/sql/Timestamp;)V", nullptr, $PUBLIC},
	{"*setTimestamp", "(ILjava/sql/Timestamp;)V", nullptr, $PUBLIC},
	{"*setTimestamp", "(ILjava/sql/Timestamp;Ljava/util/Calendar;)V", nullptr, $PUBLIC},
	{"*setTransactionIsolation", "(I)V", nullptr, $PUBLIC},
	{"*setType", "(I)V", nullptr, $PUBLIC},
	{"*setTypeMap", "(Ljava/util/Map;)V", nullptr, $PUBLIC},
	{"*setURL", "(ILjava/net/URL;)V", nullptr, $PUBLIC},
	{"*setUrl", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*setUsername", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*size", "()I", nullptr, $PUBLIC},
	{"*toCollection", "()Ljava/util/Collection;", nullptr, $PUBLIC},
	{"*toCollection", "(I)Ljava/util/Collection;", nullptr, $PUBLIC},
	{"*toCollection", "(Ljava/lang/String;)Ljava/util/Collection;", nullptr, $PUBLIC},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*undoDelete", "()V", nullptr, $PUBLIC},
	{"*undoInsert", "()V", nullptr, $PUBLIC},
	{"*undoUpdate", "()V", nullptr, $PUBLIC},
	{"*unsetMatchColumn", "([I)V", nullptr, $PUBLIC},
	{"*unsetMatchColumn", "([Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*unsetMatchColumn", "(I)V", nullptr, $PUBLIC},
	{"*unsetMatchColumn", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*unwrap", "(Ljava/lang/Class;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*updateArray", "(ILjava/sql/Array;)V", nullptr, $PUBLIC},
	{"*updateArray", "(Ljava/lang/String;Ljava/sql/Array;)V", nullptr, $PUBLIC},
	{"*updateAsciiStream", "(ILjava/io/InputStream;J)V", nullptr, $PUBLIC},
	{"*updateAsciiStream", "(Ljava/lang/String;Ljava/io/InputStream;J)V", nullptr, $PUBLIC},
	{"*updateAsciiStream", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC},
	{"*updateAsciiStream", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC},
	{"updateAsciiStream", "(ILjava/io/InputStream;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateAsciiStream", "(Ljava/lang/String;Ljava/io/InputStream;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBigDecimal", "(ILjava/math/BigDecimal;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBigDecimal", "(Ljava/lang/String;Ljava/math/BigDecimal;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*updateBinaryStream", "(ILjava/io/InputStream;J)V", nullptr, $PUBLIC},
	{"*updateBinaryStream", "(Ljava/lang/String;Ljava/io/InputStream;J)V", nullptr, $PUBLIC},
	{"*updateBinaryStream", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC},
	{"*updateBinaryStream", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC},
	{"updateBinaryStream", "(ILjava/io/InputStream;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBinaryStream", "(Ljava/lang/String;Ljava/io/InputStream;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*updateBlob", "(ILjava/sql/Blob;)V", nullptr, $PUBLIC},
	{"*updateBlob", "(Ljava/lang/String;Ljava/sql/Blob;)V", nullptr, $PUBLIC},
	{"*updateBlob", "(ILjava/io/InputStream;J)V", nullptr, $PUBLIC},
	{"*updateBlob", "(Ljava/lang/String;Ljava/io/InputStream;J)V", nullptr, $PUBLIC},
	{"*updateBlob", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC},
	{"*updateBlob", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC},
	{"updateBoolean", "(IZ)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBoolean", "(Ljava/lang/String;Z)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateByte", "(IB)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateByte", "(Ljava/lang/String;B)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBytes", "(I[B)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBytes", "(Ljava/lang/String;[B)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*updateCharacterStream", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*updateCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*updateCharacterStream", "(ILjava/io/Reader;)V", nullptr, $PUBLIC},
	{"*updateCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC},
	{"updateCharacterStream", "(ILjava/io/Reader;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*updateClob", "(ILjava/sql/Clob;)V", nullptr, $PUBLIC},
	{"*updateClob", "(Ljava/lang/String;Ljava/sql/Clob;)V", nullptr, $PUBLIC},
	{"*updateClob", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*updateClob", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*updateClob", "(ILjava/io/Reader;)V", nullptr, $PUBLIC},
	{"*updateClob", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC},
	{"updateDate", "(ILjava/sql/Date;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateDate", "(Ljava/lang/String;Ljava/sql/Date;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateDouble", "(ID)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateDouble", "(Ljava/lang/String;D)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateFloat", "(IF)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateFloat", "(Ljava/lang/String;F)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateInt", "(II)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateInt", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateLong", "(IJ)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateLong", "(Ljava/lang/String;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*updateNCharacterStream", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*updateNCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*updateNCharacterStream", "(ILjava/io/Reader;)V", nullptr, $PUBLIC},
	{"*updateNCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC},
	{"*updateNClob", "(ILjava/sql/NClob;)V", nullptr, $PUBLIC},
	{"*updateNClob", "(Ljava/lang/String;Ljava/sql/NClob;)V", nullptr, $PUBLIC},
	{"*updateNClob", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*updateNClob", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*updateNClob", "(ILjava/io/Reader;)V", nullptr, $PUBLIC},
	{"*updateNClob", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC},
	{"*updateNString", "(ILjava/lang/String;)V", nullptr, $PUBLIC},
	{"*updateNString", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*updateNull", "(I)V", nullptr, $PUBLIC},
	{"*updateNull", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*updateObject", "(ILjava/lang/Object;Ljava/sql/SQLType;I)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*updateObject", "(Ljava/lang/String;Ljava/lang/Object;Ljava/sql/SQLType;I)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*updateObject", "(ILjava/lang/Object;Ljava/sql/SQLType;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*updateObject", "(Ljava/lang/String;Ljava/lang/Object;Ljava/sql/SQLType;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"updateObject", "(ILjava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateObject", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateObject", "(ILjava/lang/Object;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateObject", "(Ljava/lang/String;Ljava/lang/Object;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*updateRef", "(ILjava/sql/Ref;)V", nullptr, $PUBLIC},
	{"*updateRef", "(Ljava/lang/String;Ljava/sql/Ref;)V", nullptr, $PUBLIC},
	{"*updateRow", "()V", nullptr, $PUBLIC},
	{"*updateRowId", "(ILjava/sql/RowId;)V", nullptr, $PUBLIC},
	{"*updateRowId", "(Ljava/lang/String;Ljava/sql/RowId;)V", nullptr, $PUBLIC},
	{"*updateSQLXML", "(ILjava/sql/SQLXML;)V", nullptr, $PUBLIC},
	{"*updateSQLXML", "(Ljava/lang/String;Ljava/sql/SQLXML;)V", nullptr, $PUBLIC},
	{"updateShort", "(IS)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateShort", "(Ljava/lang/String;S)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateString", "(ILjava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateString", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateTime", "(ILjava/sql/Time;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateTime", "(Ljava/lang/String;Ljava/sql/Time;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateTimestamp", "(ILjava/sql/Timestamp;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateTimestamp", "(Ljava/lang/String;Ljava/sql/Timestamp;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*writeXml", "(Ljava/sql/ResultSet;Ljava/io/Writer;)V", nullptr, $PUBLIC},
	{"*writeXml", "(Ljava/io/Writer;)V", nullptr, $PUBLIC},
	{"*writeXml", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC},
	{"*writeXml", "(Ljava/sql/ResultSet;Ljava/io/OutputStream;)V", nullptr, $PUBLIC},
	{"*wasNull", "()Z", nullptr, $PUBLIC},
	{}
};

$ClassInfo _FilteredRowSetImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.rowset.FilteredRowSetImpl",
	"com.sun.rowset.WebRowSetImpl",
	"javax.sql.rowset.FilteredRowSet",
	_FilteredRowSetImpl_FieldInfo_,
	_FilteredRowSetImpl_MethodInfo_
};

$Object* allocate$FilteredRowSetImpl($Class* clazz) {
	return $of($alloc(FilteredRowSetImpl));
}

void FilteredRowSetImpl::writeXml($ResultSet* rs, $Writer* writer) {
	this->$WebRowSetImpl::writeXml(rs, writer);
}

void FilteredRowSetImpl::writeXml($Writer* writer) {
	this->$WebRowSetImpl::writeXml(writer);
}

void FilteredRowSetImpl::readXml($Reader* reader) {
	this->$WebRowSetImpl::readXml(reader);
}

void FilteredRowSetImpl::readXml($InputStream* iStream) {
	this->$WebRowSetImpl::readXml(iStream);
}

void FilteredRowSetImpl::writeXml($OutputStream* oStream) {
	this->$WebRowSetImpl::writeXml(oStream);
}

void FilteredRowSetImpl::writeXml($ResultSet* rs, $OutputStream* oStream) {
	this->$WebRowSetImpl::writeXml(rs, oStream);
}

void FilteredRowSetImpl::setCommand($String* cmd) {
	this->$WebRowSetImpl::setCommand(cmd);
}

void FilteredRowSetImpl::populate($ResultSet* data) {
	this->$WebRowSetImpl::populate(data);
}

void FilteredRowSetImpl::execute($Connection* conn) {
	this->$WebRowSetImpl::execute(conn);
}

void FilteredRowSetImpl::acceptChanges() {
	this->$WebRowSetImpl::acceptChanges();
}

void FilteredRowSetImpl::acceptChanges($Connection* con) {
	this->$WebRowSetImpl::acceptChanges(con);
}

void FilteredRowSetImpl::restoreOriginal() {
	this->$WebRowSetImpl::restoreOriginal();
}

void FilteredRowSetImpl::release() {
	this->$WebRowSetImpl::release();
}

void FilteredRowSetImpl::undoDelete() {
	this->$WebRowSetImpl::undoDelete();
}

void FilteredRowSetImpl::undoInsert() {
	this->$WebRowSetImpl::undoInsert();
}

void FilteredRowSetImpl::undoUpdate() {
	this->$WebRowSetImpl::undoUpdate();
}

$RowSet* FilteredRowSetImpl::createShared() {
	 return this->$WebRowSetImpl::createShared();
}

$Object* FilteredRowSetImpl::clone() {
	 return this->$WebRowSetImpl::clone();
}

$CachedRowSet* FilteredRowSetImpl::createCopy() {
	 return this->$WebRowSetImpl::createCopy();
}

$CachedRowSet* FilteredRowSetImpl::createCopySchema() {
	 return this->$WebRowSetImpl::createCopySchema();
}

$CachedRowSet* FilteredRowSetImpl::createCopyNoConstraints() {
	 return this->$WebRowSetImpl::createCopyNoConstraints();
}

$Collection* FilteredRowSetImpl::toCollection() {
	 return this->$WebRowSetImpl::toCollection();
}

$Collection* FilteredRowSetImpl::toCollection(int32_t column) {
	 return this->$WebRowSetImpl::toCollection(column);
}

$Collection* FilteredRowSetImpl::toCollection($String* column) {
	 return this->$WebRowSetImpl::toCollection(column);
}

$SyncProvider* FilteredRowSetImpl::getSyncProvider() {
	 return this->$WebRowSetImpl::getSyncProvider();
}

void FilteredRowSetImpl::setSyncProvider($String* providerStr) {
	this->$WebRowSetImpl::setSyncProvider(providerStr);
}

void FilteredRowSetImpl::execute() {
	this->$WebRowSetImpl::execute();
}

bool FilteredRowSetImpl::next() {
	 return this->$WebRowSetImpl::next();
}

void FilteredRowSetImpl::close() {
	this->$WebRowSetImpl::close();
}

bool FilteredRowSetImpl::wasNull() {
	 return this->$WebRowSetImpl::wasNull();
}

$String* FilteredRowSetImpl::getString(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getString(columnIndex);
}

bool FilteredRowSetImpl::getBoolean(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getBoolean(columnIndex);
}

int8_t FilteredRowSetImpl::getByte(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getByte(columnIndex);
}

int16_t FilteredRowSetImpl::getShort(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getShort(columnIndex);
}

int32_t FilteredRowSetImpl::getInt(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getInt(columnIndex);
}

int64_t FilteredRowSetImpl::getLong(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getLong(columnIndex);
}

float FilteredRowSetImpl::getFloat(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getFloat(columnIndex);
}

double FilteredRowSetImpl::getDouble(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getDouble(columnIndex);
}

$BigDecimal* FilteredRowSetImpl::getBigDecimal(int32_t columnIndex, int32_t scale) {
	 return this->$WebRowSetImpl::getBigDecimal(columnIndex, scale);
}

$bytes* FilteredRowSetImpl::getBytes(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getBytes(columnIndex);
}

$Date* FilteredRowSetImpl::getDate(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getDate(columnIndex);
}

$Time* FilteredRowSetImpl::getTime(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getTime(columnIndex);
}

$Timestamp* FilteredRowSetImpl::getTimestamp(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getTimestamp(columnIndex);
}

$InputStream* FilteredRowSetImpl::getAsciiStream(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getAsciiStream(columnIndex);
}

$InputStream* FilteredRowSetImpl::getUnicodeStream(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getUnicodeStream(columnIndex);
}

$InputStream* FilteredRowSetImpl::getBinaryStream(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getBinaryStream(columnIndex);
}

$String* FilteredRowSetImpl::getString($String* columnName) {
	 return this->$WebRowSetImpl::getString(columnName);
}

bool FilteredRowSetImpl::getBoolean($String* columnName) {
	 return this->$WebRowSetImpl::getBoolean(columnName);
}

int8_t FilteredRowSetImpl::getByte($String* columnName) {
	 return this->$WebRowSetImpl::getByte(columnName);
}

int16_t FilteredRowSetImpl::getShort($String* columnName) {
	 return this->$WebRowSetImpl::getShort(columnName);
}

int32_t FilteredRowSetImpl::getInt($String* columnName) {
	 return this->$WebRowSetImpl::getInt(columnName);
}

int64_t FilteredRowSetImpl::getLong($String* columnName) {
	 return this->$WebRowSetImpl::getLong(columnName);
}

float FilteredRowSetImpl::getFloat($String* columnName) {
	 return this->$WebRowSetImpl::getFloat(columnName);
}

double FilteredRowSetImpl::getDouble($String* columnName) {
	 return this->$WebRowSetImpl::getDouble(columnName);
}

$BigDecimal* FilteredRowSetImpl::getBigDecimal($String* columnName, int32_t scale) {
	 return this->$WebRowSetImpl::getBigDecimal(columnName, scale);
}

$bytes* FilteredRowSetImpl::getBytes($String* columnName) {
	 return this->$WebRowSetImpl::getBytes(columnName);
}

$Date* FilteredRowSetImpl::getDate($String* columnName) {
	 return this->$WebRowSetImpl::getDate(columnName);
}

$Time* FilteredRowSetImpl::getTime($String* columnName) {
	 return this->$WebRowSetImpl::getTime(columnName);
}

$Timestamp* FilteredRowSetImpl::getTimestamp($String* columnName) {
	 return this->$WebRowSetImpl::getTimestamp(columnName);
}

$InputStream* FilteredRowSetImpl::getAsciiStream($String* columnName) {
	 return this->$WebRowSetImpl::getAsciiStream(columnName);
}

$InputStream* FilteredRowSetImpl::getUnicodeStream($String* columnName) {
	 return this->$WebRowSetImpl::getUnicodeStream(columnName);
}

$InputStream* FilteredRowSetImpl::getBinaryStream($String* columnName) {
	 return this->$WebRowSetImpl::getBinaryStream(columnName);
}

$SQLWarning* FilteredRowSetImpl::getWarnings() {
	 return this->$WebRowSetImpl::getWarnings();
}

void FilteredRowSetImpl::clearWarnings() {
	this->$WebRowSetImpl::clearWarnings();
}

$String* FilteredRowSetImpl::getCursorName() {
	 return this->$WebRowSetImpl::getCursorName();
}

$ResultSetMetaData* FilteredRowSetImpl::getMetaData() {
	 return this->$WebRowSetImpl::getMetaData();
}

$Object* FilteredRowSetImpl::getObject(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getObject(columnIndex);
}

$Object* FilteredRowSetImpl::getObject($String* columnName) {
	 return this->$WebRowSetImpl::getObject(columnName);
}

int32_t FilteredRowSetImpl::findColumn($String* columnName) {
	 return this->$WebRowSetImpl::findColumn(columnName);
}

$Reader* FilteredRowSetImpl::getCharacterStream(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getCharacterStream(columnIndex);
}

$Reader* FilteredRowSetImpl::getCharacterStream($String* columnName) {
	 return this->$WebRowSetImpl::getCharacterStream(columnName);
}

$BigDecimal* FilteredRowSetImpl::getBigDecimal(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getBigDecimal(columnIndex);
}

$BigDecimal* FilteredRowSetImpl::getBigDecimal($String* columnName) {
	 return this->$WebRowSetImpl::getBigDecimal(columnName);
}

int32_t FilteredRowSetImpl::size() {
	 return this->$WebRowSetImpl::size();
}

bool FilteredRowSetImpl::isBeforeFirst() {
	 return this->$WebRowSetImpl::isBeforeFirst();
}

bool FilteredRowSetImpl::isAfterLast() {
	 return this->$WebRowSetImpl::isAfterLast();
}

bool FilteredRowSetImpl::isFirst() {
	 return this->$WebRowSetImpl::isFirst();
}

bool FilteredRowSetImpl::isLast() {
	 return this->$WebRowSetImpl::isLast();
}

void FilteredRowSetImpl::beforeFirst() {
	this->$WebRowSetImpl::beforeFirst();
}

void FilteredRowSetImpl::afterLast() {
	this->$WebRowSetImpl::afterLast();
}

bool FilteredRowSetImpl::first() {
	 return this->$WebRowSetImpl::first();
}

bool FilteredRowSetImpl::last() {
	 return this->$WebRowSetImpl::last();
}

int32_t FilteredRowSetImpl::getRow() {
	 return this->$WebRowSetImpl::getRow();
}

bool FilteredRowSetImpl::previous() {
	 return this->$WebRowSetImpl::previous();
}

bool FilteredRowSetImpl::rowUpdated() {
	 return this->$WebRowSetImpl::rowUpdated();
}

bool FilteredRowSetImpl::columnUpdated(int32_t idx) {
	 return this->$WebRowSetImpl::columnUpdated(idx);
}

bool FilteredRowSetImpl::columnUpdated($String* columnName) {
	 return this->$WebRowSetImpl::columnUpdated(columnName);
}

bool FilteredRowSetImpl::rowInserted() {
	 return this->$WebRowSetImpl::rowInserted();
}

bool FilteredRowSetImpl::rowDeleted() {
	 return this->$WebRowSetImpl::rowDeleted();
}

void FilteredRowSetImpl::updateNull(int32_t columnIndex) {
	this->$WebRowSetImpl::updateNull(columnIndex);
}

void FilteredRowSetImpl::updateNull($String* columnName) {
	this->$WebRowSetImpl::updateNull(columnName);
}

void FilteredRowSetImpl::updateRow() {
	this->$WebRowSetImpl::updateRow();
}

void FilteredRowSetImpl::deleteRow() {
	this->$WebRowSetImpl::deleteRow();
}

void FilteredRowSetImpl::refreshRow() {
	this->$WebRowSetImpl::refreshRow();
}

void FilteredRowSetImpl::cancelRowUpdates() {
	this->$WebRowSetImpl::cancelRowUpdates();
}

void FilteredRowSetImpl::moveToCurrentRow() {
	this->$WebRowSetImpl::moveToCurrentRow();
}

$Statement* FilteredRowSetImpl::getStatement() {
	 return this->$WebRowSetImpl::getStatement();
}

$Object* FilteredRowSetImpl::getObject(int32_t columnIndex, $Map* map) {
	 return this->$WebRowSetImpl::getObject(columnIndex, map);
}

$Ref* FilteredRowSetImpl::getRef(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getRef(columnIndex);
}

$Blob* FilteredRowSetImpl::getBlob(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getBlob(columnIndex);
}

$Clob* FilteredRowSetImpl::getClob(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getClob(columnIndex);
}

$1Array* FilteredRowSetImpl::getArray(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getArray(columnIndex);
}

$Object* FilteredRowSetImpl::getObject($String* columnName, $Map* map) {
	 return this->$WebRowSetImpl::getObject(columnName, map);
}

$Ref* FilteredRowSetImpl::getRef($String* colName) {
	 return this->$WebRowSetImpl::getRef(colName);
}

$Blob* FilteredRowSetImpl::getBlob($String* colName) {
	 return this->$WebRowSetImpl::getBlob(colName);
}

$Clob* FilteredRowSetImpl::getClob($String* colName) {
	 return this->$WebRowSetImpl::getClob(colName);
}

$1Array* FilteredRowSetImpl::getArray($String* colName) {
	 return this->$WebRowSetImpl::getArray(colName);
}

$Date* FilteredRowSetImpl::getDate(int32_t columnIndex, $Calendar* cal) {
	 return this->$WebRowSetImpl::getDate(columnIndex, cal);
}

$Date* FilteredRowSetImpl::getDate($String* columnName, $Calendar* cal) {
	 return this->$WebRowSetImpl::getDate(columnName, cal);
}

$Time* FilteredRowSetImpl::getTime(int32_t columnIndex, $Calendar* cal) {
	 return this->$WebRowSetImpl::getTime(columnIndex, cal);
}

$Time* FilteredRowSetImpl::getTime($String* columnName, $Calendar* cal) {
	 return this->$WebRowSetImpl::getTime(columnName, cal);
}

$Timestamp* FilteredRowSetImpl::getTimestamp(int32_t columnIndex, $Calendar* cal) {
	 return this->$WebRowSetImpl::getTimestamp(columnIndex, cal);
}

$Timestamp* FilteredRowSetImpl::getTimestamp($String* columnName, $Calendar* cal) {
	 return this->$WebRowSetImpl::getTimestamp(columnName, cal);
}

void FilteredRowSetImpl::setMetaData($RowSetMetaData* md) {
	this->$WebRowSetImpl::setMetaData(md);
}

$ResultSet* FilteredRowSetImpl::getOriginal() {
	 return this->$WebRowSetImpl::getOriginal();
}

$ResultSet* FilteredRowSetImpl::getOriginalRow() {
	 return this->$WebRowSetImpl::getOriginalRow();
}

void FilteredRowSetImpl::setOriginalRow() {
	this->$WebRowSetImpl::setOriginalRow();
}

$String* FilteredRowSetImpl::getTableName() {
	 return this->$WebRowSetImpl::getTableName();
}

void FilteredRowSetImpl::setTableName($String* tabName) {
	this->$WebRowSetImpl::setTableName(tabName);
}

$ints* FilteredRowSetImpl::getKeyColumns() {
	 return this->$WebRowSetImpl::getKeyColumns();
}

void FilteredRowSetImpl::setKeyColumns($ints* keys) {
	this->$WebRowSetImpl::setKeyColumns(keys);
}

void FilteredRowSetImpl::updateRef(int32_t columnIndex, $Ref* ref) {
	this->$WebRowSetImpl::updateRef(columnIndex, ref);
}

void FilteredRowSetImpl::updateRef($String* columnName, $Ref* ref) {
	this->$WebRowSetImpl::updateRef(columnName, ref);
}

void FilteredRowSetImpl::updateClob(int32_t columnIndex, $Clob* c) {
	this->$WebRowSetImpl::updateClob(columnIndex, c);
}

void FilteredRowSetImpl::updateClob($String* columnName, $Clob* c) {
	this->$WebRowSetImpl::updateClob(columnName, c);
}

void FilteredRowSetImpl::updateBlob(int32_t columnIndex, $Blob* b) {
	this->$WebRowSetImpl::updateBlob(columnIndex, b);
}

void FilteredRowSetImpl::updateBlob($String* columnName, $Blob* b) {
	this->$WebRowSetImpl::updateBlob(columnName, b);
}

void FilteredRowSetImpl::updateArray(int32_t columnIndex, $1Array* a) {
	this->$WebRowSetImpl::updateArray(columnIndex, a);
}

void FilteredRowSetImpl::updateArray($String* columnName, $1Array* a) {
	this->$WebRowSetImpl::updateArray(columnName, a);
}

$URL* FilteredRowSetImpl::getURL(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getURL(columnIndex);
}

$URL* FilteredRowSetImpl::getURL($String* columnName) {
	 return this->$WebRowSetImpl::getURL(columnName);
}

$RowSetWarning* FilteredRowSetImpl::getRowSetWarnings() {
	 return this->$WebRowSetImpl::getRowSetWarnings();
}

void FilteredRowSetImpl::commit() {
	this->$WebRowSetImpl::commit();
}

void FilteredRowSetImpl::rollback() {
	this->$WebRowSetImpl::rollback();
}

void FilteredRowSetImpl::rollback($Savepoint* s) {
	this->$WebRowSetImpl::rollback(s);
}

void FilteredRowSetImpl::unsetMatchColumn($ints* columnIdxes) {
	this->$WebRowSetImpl::unsetMatchColumn(columnIdxes);
}

void FilteredRowSetImpl::unsetMatchColumn($StringArray* columnIdxes) {
	this->$WebRowSetImpl::unsetMatchColumn(columnIdxes);
}

$StringArray* FilteredRowSetImpl::getMatchColumnNames() {
	 return this->$WebRowSetImpl::getMatchColumnNames();
}

$ints* FilteredRowSetImpl::getMatchColumnIndexes() {
	 return this->$WebRowSetImpl::getMatchColumnIndexes();
}

void FilteredRowSetImpl::setMatchColumn($ints* columnIdxes) {
	this->$WebRowSetImpl::setMatchColumn(columnIdxes);
}

void FilteredRowSetImpl::setMatchColumn($StringArray* columnNames) {
	this->$WebRowSetImpl::setMatchColumn(columnNames);
}

void FilteredRowSetImpl::setMatchColumn(int32_t columnIdx) {
	this->$WebRowSetImpl::setMatchColumn(columnIdx);
}

void FilteredRowSetImpl::setMatchColumn($String* columnName) {
	this->$WebRowSetImpl::setMatchColumn(columnName);
}

void FilteredRowSetImpl::unsetMatchColumn(int32_t columnIdx) {
	this->$WebRowSetImpl::unsetMatchColumn(columnIdx);
}

void FilteredRowSetImpl::unsetMatchColumn($String* columnName) {
	this->$WebRowSetImpl::unsetMatchColumn(columnName);
}

void FilteredRowSetImpl::rowSetPopulated($RowSetEvent* event, int32_t numRows) {
	this->$WebRowSetImpl::rowSetPopulated(event, numRows);
}

void FilteredRowSetImpl::populate($ResultSet* data, int32_t start) {
	this->$WebRowSetImpl::populate(data, start);
}

bool FilteredRowSetImpl::nextPage() {
	 return this->$WebRowSetImpl::nextPage();
}

void FilteredRowSetImpl::setPageSize(int32_t size) {
	this->$WebRowSetImpl::setPageSize(size);
}

int32_t FilteredRowSetImpl::getPageSize() {
	 return this->$WebRowSetImpl::getPageSize();
}

bool FilteredRowSetImpl::previousPage() {
	 return this->$WebRowSetImpl::previousPage();
}

$SQLXML* FilteredRowSetImpl::getSQLXML(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getSQLXML(columnIndex);
}

$SQLXML* FilteredRowSetImpl::getSQLXML($String* colName) {
	 return this->$WebRowSetImpl::getSQLXML(colName);
}

$RowId* FilteredRowSetImpl::getRowId(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getRowId(columnIndex);
}

$RowId* FilteredRowSetImpl::getRowId($String* columnName) {
	 return this->$WebRowSetImpl::getRowId(columnName);
}

void FilteredRowSetImpl::updateRowId(int32_t columnIndex, $RowId* x) {
	this->$WebRowSetImpl::updateRowId(columnIndex, x);
}

void FilteredRowSetImpl::updateRowId($String* columnName, $RowId* x) {
	this->$WebRowSetImpl::updateRowId(columnName, x);
}

int32_t FilteredRowSetImpl::getHoldability() {
	 return this->$WebRowSetImpl::getHoldability();
}

bool FilteredRowSetImpl::isClosed() {
	 return this->$WebRowSetImpl::isClosed();
}

void FilteredRowSetImpl::updateNString(int32_t columnIndex, $String* nString) {
	this->$WebRowSetImpl::updateNString(columnIndex, nString);
}

void FilteredRowSetImpl::updateNString($String* columnName, $String* nString) {
	this->$WebRowSetImpl::updateNString(columnName, nString);
}

void FilteredRowSetImpl::updateNClob(int32_t columnIndex, $NClob* nClob) {
	this->$WebRowSetImpl::updateNClob(columnIndex, nClob);
}

void FilteredRowSetImpl::updateNClob($String* columnName, $NClob* nClob) {
	this->$WebRowSetImpl::updateNClob(columnName, nClob);
}

$NClob* FilteredRowSetImpl::getNClob(int32_t i) {
	 return this->$WebRowSetImpl::getNClob(i);
}

$NClob* FilteredRowSetImpl::getNClob($String* colName) {
	 return this->$WebRowSetImpl::getNClob(colName);
}

$Object* FilteredRowSetImpl::unwrap($Class* iface) {
	 return this->$WebRowSetImpl::unwrap(iface);
}

bool FilteredRowSetImpl::isWrapperFor($Class* interfaces) {
	 return this->$WebRowSetImpl::isWrapperFor(interfaces);
}

void FilteredRowSetImpl::setSQLXML(int32_t parameterIndex, $SQLXML* xmlObject) {
	this->$WebRowSetImpl::setSQLXML(parameterIndex, xmlObject);
}

void FilteredRowSetImpl::setSQLXML($String* parameterName, $SQLXML* xmlObject) {
	this->$WebRowSetImpl::setSQLXML(parameterName, xmlObject);
}

void FilteredRowSetImpl::setRowId(int32_t parameterIndex, $RowId* x) {
	this->$WebRowSetImpl::setRowId(parameterIndex, x);
}

void FilteredRowSetImpl::setRowId($String* parameterName, $RowId* x) {
	this->$WebRowSetImpl::setRowId(parameterName, x);
}

void FilteredRowSetImpl::setNCharacterStream(int32_t parameterIndex, $Reader* value) {
	this->$WebRowSetImpl::setNCharacterStream(parameterIndex, value);
}

void FilteredRowSetImpl::setNClob($String* parameterName, $NClob* value) {
	this->$WebRowSetImpl::setNClob(parameterName, value);
}

$Reader* FilteredRowSetImpl::getNCharacterStream(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getNCharacterStream(columnIndex);
}

$Reader* FilteredRowSetImpl::getNCharacterStream($String* columnName) {
	 return this->$WebRowSetImpl::getNCharacterStream(columnName);
}

void FilteredRowSetImpl::updateSQLXML(int32_t columnIndex, $SQLXML* xmlObject) {
	this->$WebRowSetImpl::updateSQLXML(columnIndex, xmlObject);
}

void FilteredRowSetImpl::updateSQLXML($String* columnName, $SQLXML* xmlObject) {
	this->$WebRowSetImpl::updateSQLXML(columnName, xmlObject);
}

$String* FilteredRowSetImpl::getNString(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getNString(columnIndex);
}

$String* FilteredRowSetImpl::getNString($String* columnName) {
	 return this->$WebRowSetImpl::getNString(columnName);
}

void FilteredRowSetImpl::updateNCharacterStream(int32_t columnIndex, $Reader* x, int64_t length) {
	this->$WebRowSetImpl::updateNCharacterStream(columnIndex, x, length);
}

void FilteredRowSetImpl::updateNCharacterStream($String* columnName, $Reader* x, int64_t length) {
	this->$WebRowSetImpl::updateNCharacterStream(columnName, x, length);
}

void FilteredRowSetImpl::updateNCharacterStream(int32_t columnIndex, $Reader* x) {
	this->$WebRowSetImpl::updateNCharacterStream(columnIndex, x);
}

void FilteredRowSetImpl::updateNCharacterStream($String* columnLabel, $Reader* reader) {
	this->$WebRowSetImpl::updateNCharacterStream(columnLabel, reader);
}

void FilteredRowSetImpl::updateBlob(int32_t columnIndex, $InputStream* inputStream, int64_t length) {
	this->$WebRowSetImpl::updateBlob(columnIndex, inputStream, length);
}

void FilteredRowSetImpl::updateBlob($String* columnLabel, $InputStream* inputStream, int64_t length) {
	this->$WebRowSetImpl::updateBlob(columnLabel, inputStream, length);
}

void FilteredRowSetImpl::updateBlob(int32_t columnIndex, $InputStream* inputStream) {
	this->$WebRowSetImpl::updateBlob(columnIndex, inputStream);
}

void FilteredRowSetImpl::updateBlob($String* columnLabel, $InputStream* inputStream) {
	this->$WebRowSetImpl::updateBlob(columnLabel, inputStream);
}

void FilteredRowSetImpl::updateClob(int32_t columnIndex, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::updateClob(columnIndex, reader, length);
}

void FilteredRowSetImpl::updateClob($String* columnLabel, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::updateClob(columnLabel, reader, length);
}

void FilteredRowSetImpl::updateClob(int32_t columnIndex, $Reader* reader) {
	this->$WebRowSetImpl::updateClob(columnIndex, reader);
}

void FilteredRowSetImpl::updateClob($String* columnLabel, $Reader* reader) {
	this->$WebRowSetImpl::updateClob(columnLabel, reader);
}

void FilteredRowSetImpl::updateNClob(int32_t columnIndex, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::updateNClob(columnIndex, reader, length);
}

void FilteredRowSetImpl::updateNClob($String* columnLabel, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::updateNClob(columnLabel, reader, length);
}

void FilteredRowSetImpl::updateNClob(int32_t columnIndex, $Reader* reader) {
	this->$WebRowSetImpl::updateNClob(columnIndex, reader);
}

void FilteredRowSetImpl::updateNClob($String* columnLabel, $Reader* reader) {
	this->$WebRowSetImpl::updateNClob(columnLabel, reader);
}

void FilteredRowSetImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x, int64_t length) {
	this->$WebRowSetImpl::updateAsciiStream(columnIndex, x, length);
}

void FilteredRowSetImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x, int64_t length) {
	this->$WebRowSetImpl::updateBinaryStream(columnIndex, x, length);
}

void FilteredRowSetImpl::updateCharacterStream(int32_t columnIndex, $Reader* x, int64_t length) {
	this->$WebRowSetImpl::updateCharacterStream(columnIndex, x, length);
}

void FilteredRowSetImpl::updateCharacterStream($String* columnLabel, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::updateCharacterStream(columnLabel, reader, length);
}

void FilteredRowSetImpl::updateAsciiStream($String* columnLabel, $InputStream* x, int64_t length) {
	this->$WebRowSetImpl::updateAsciiStream(columnLabel, x, length);
}

void FilteredRowSetImpl::updateBinaryStream($String* columnLabel, $InputStream* x, int64_t length) {
	this->$WebRowSetImpl::updateBinaryStream(columnLabel, x, length);
}

void FilteredRowSetImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x) {
	this->$WebRowSetImpl::updateBinaryStream(columnIndex, x);
}

void FilteredRowSetImpl::updateBinaryStream($String* columnLabel, $InputStream* x) {
	this->$WebRowSetImpl::updateBinaryStream(columnLabel, x);
}

void FilteredRowSetImpl::updateCharacterStream(int32_t columnIndex, $Reader* x) {
	this->$WebRowSetImpl::updateCharacterStream(columnIndex, x);
}

void FilteredRowSetImpl::updateCharacterStream($String* columnLabel, $Reader* reader) {
	this->$WebRowSetImpl::updateCharacterStream(columnLabel, reader);
}

void FilteredRowSetImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x) {
	this->$WebRowSetImpl::updateAsciiStream(columnIndex, x);
}

void FilteredRowSetImpl::updateAsciiStream($String* columnLabel, $InputStream* x) {
	this->$WebRowSetImpl::updateAsciiStream(columnLabel, x);
}

void FilteredRowSetImpl::setURL(int32_t parameterIndex, $URL* x) {
	this->$WebRowSetImpl::setURL(parameterIndex, x);
}

void FilteredRowSetImpl::setNClob(int32_t parameterIndex, $Reader* reader) {
	this->$WebRowSetImpl::setNClob(parameterIndex, reader);
}

void FilteredRowSetImpl::setNClob($String* parameterName, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::setNClob(parameterName, reader, length);
}

void FilteredRowSetImpl::setNClob($String* parameterName, $Reader* reader) {
	this->$WebRowSetImpl::setNClob(parameterName, reader);
}

void FilteredRowSetImpl::setNClob(int32_t parameterIndex, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::setNClob(parameterIndex, reader, length);
}

void FilteredRowSetImpl::setNClob(int32_t parameterIndex, $NClob* value) {
	this->$WebRowSetImpl::setNClob(parameterIndex, value);
}

void FilteredRowSetImpl::setNString(int32_t parameterIndex, $String* value) {
	this->$WebRowSetImpl::setNString(parameterIndex, value);
}

void FilteredRowSetImpl::setNString($String* parameterName, $String* value) {
	this->$WebRowSetImpl::setNString(parameterName, value);
}

void FilteredRowSetImpl::setNCharacterStream(int32_t parameterIndex, $Reader* value, int64_t length) {
	this->$WebRowSetImpl::setNCharacterStream(parameterIndex, value, length);
}

void FilteredRowSetImpl::setNCharacterStream($String* parameterName, $Reader* value, int64_t length) {
	this->$WebRowSetImpl::setNCharacterStream(parameterName, value, length);
}

void FilteredRowSetImpl::setNCharacterStream($String* parameterName, $Reader* value) {
	this->$WebRowSetImpl::setNCharacterStream(parameterName, value);
}

void FilteredRowSetImpl::setTimestamp($String* parameterName, $Timestamp* x, $Calendar* cal) {
	this->$WebRowSetImpl::setTimestamp(parameterName, x, cal);
}

void FilteredRowSetImpl::setClob($String* parameterName, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::setClob(parameterName, reader, length);
}

void FilteredRowSetImpl::setClob($String* parameterName, $Clob* x) {
	this->$WebRowSetImpl::setClob(parameterName, x);
}

void FilteredRowSetImpl::setClob($String* parameterName, $Reader* reader) {
	this->$WebRowSetImpl::setClob(parameterName, reader);
}

void FilteredRowSetImpl::setDate($String* parameterName, $Date* x) {
	this->$WebRowSetImpl::setDate(parameterName, x);
}

void FilteredRowSetImpl::setDate($String* parameterName, $Date* x, $Calendar* cal) {
	this->$WebRowSetImpl::setDate(parameterName, x, cal);
}

void FilteredRowSetImpl::setTime($String* parameterName, $Time* x) {
	this->$WebRowSetImpl::setTime(parameterName, x);
}

void FilteredRowSetImpl::setTime($String* parameterName, $Time* x, $Calendar* cal) {
	this->$WebRowSetImpl::setTime(parameterName, x, cal);
}

void FilteredRowSetImpl::setClob(int32_t parameterIndex, $Reader* reader) {
	this->$WebRowSetImpl::setClob(parameterIndex, reader);
}

void FilteredRowSetImpl::setClob(int32_t parameterIndex, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::setClob(parameterIndex, reader, length);
}

void FilteredRowSetImpl::setBlob(int32_t parameterIndex, $InputStream* inputStream, int64_t length) {
	this->$WebRowSetImpl::setBlob(parameterIndex, inputStream, length);
}

void FilteredRowSetImpl::setBlob(int32_t parameterIndex, $InputStream* inputStream) {
	this->$WebRowSetImpl::setBlob(parameterIndex, inputStream);
}

void FilteredRowSetImpl::setBlob($String* parameterName, $InputStream* inputStream, int64_t length) {
	this->$WebRowSetImpl::setBlob(parameterName, inputStream, length);
}

void FilteredRowSetImpl::setBlob($String* parameterName, $Blob* x) {
	this->$WebRowSetImpl::setBlob(parameterName, x);
}

void FilteredRowSetImpl::setBlob($String* parameterName, $InputStream* inputStream) {
	this->$WebRowSetImpl::setBlob(parameterName, inputStream);
}

void FilteredRowSetImpl::setObject($String* parameterName, Object$* x, int32_t targetSqlType, int32_t scale) {
	this->$WebRowSetImpl::setObject(parameterName, x, targetSqlType, scale);
}

void FilteredRowSetImpl::setObject($String* parameterName, Object$* x, int32_t targetSqlType) {
	this->$WebRowSetImpl::setObject(parameterName, x, targetSqlType);
}

void FilteredRowSetImpl::setObject($String* parameterName, Object$* x) {
	this->$WebRowSetImpl::setObject(parameterName, x);
}

void FilteredRowSetImpl::setAsciiStream($String* parameterName, $InputStream* x, int32_t length) {
	this->$WebRowSetImpl::setAsciiStream(parameterName, x, length);
}

void FilteredRowSetImpl::setBinaryStream($String* parameterName, $InputStream* x, int32_t length) {
	this->$WebRowSetImpl::setBinaryStream(parameterName, x, length);
}

void FilteredRowSetImpl::setCharacterStream($String* parameterName, $Reader* reader, int32_t length) {
	this->$WebRowSetImpl::setCharacterStream(parameterName, reader, length);
}

void FilteredRowSetImpl::setAsciiStream($String* parameterName, $InputStream* x) {
	this->$WebRowSetImpl::setAsciiStream(parameterName, x);
}

void FilteredRowSetImpl::setBinaryStream($String* parameterName, $InputStream* x) {
	this->$WebRowSetImpl::setBinaryStream(parameterName, x);
}

void FilteredRowSetImpl::setCharacterStream($String* parameterName, $Reader* reader) {
	this->$WebRowSetImpl::setCharacterStream(parameterName, reader);
}

void FilteredRowSetImpl::setBigDecimal($String* parameterName, $BigDecimal* x) {
	this->$WebRowSetImpl::setBigDecimal(parameterName, x);
}

void FilteredRowSetImpl::setString($String* parameterName, $String* x) {
	this->$WebRowSetImpl::setString(parameterName, x);
}

void FilteredRowSetImpl::setBytes($String* parameterName, $bytes* x) {
	this->$WebRowSetImpl::setBytes(parameterName, x);
}

void FilteredRowSetImpl::setTimestamp($String* parameterName, $Timestamp* x) {
	this->$WebRowSetImpl::setTimestamp(parameterName, x);
}

void FilteredRowSetImpl::setNull($String* parameterName, int32_t sqlType) {
	this->$WebRowSetImpl::setNull(parameterName, sqlType);
}

void FilteredRowSetImpl::setNull($String* parameterName, int32_t sqlType, $String* typeName) {
	this->$WebRowSetImpl::setNull(parameterName, sqlType, typeName);
}

void FilteredRowSetImpl::setBoolean($String* parameterName, bool x) {
	this->$WebRowSetImpl::setBoolean(parameterName, x);
}

void FilteredRowSetImpl::setByte($String* parameterName, int8_t x) {
	this->$WebRowSetImpl::setByte(parameterName, x);
}

void FilteredRowSetImpl::setShort($String* parameterName, int16_t x) {
	this->$WebRowSetImpl::setShort(parameterName, x);
}

void FilteredRowSetImpl::setInt($String* parameterName, int32_t x) {
	this->$WebRowSetImpl::setInt(parameterName, x);
}

void FilteredRowSetImpl::setLong($String* parameterName, int64_t x) {
	this->$WebRowSetImpl::setLong(parameterName, x);
}

void FilteredRowSetImpl::setFloat($String* parameterName, float x) {
	this->$WebRowSetImpl::setFloat(parameterName, x);
}

void FilteredRowSetImpl::setDouble($String* parameterName, double x) {
	this->$WebRowSetImpl::setDouble(parameterName, x);
}

$Object* FilteredRowSetImpl::getObject(int32_t columnIndex, $Class* type) {
	 return this->$WebRowSetImpl::getObject(columnIndex, type);
}

$Object* FilteredRowSetImpl::getObject($String* columnLabel, $Class* type) {
	 return this->$WebRowSetImpl::getObject(columnLabel, type);
}

void FilteredRowSetImpl::addRowSetListener($RowSetListener* listener) {
	this->$WebRowSetImpl::addRowSetListener(listener);
}

void FilteredRowSetImpl::removeRowSetListener($RowSetListener* listener) {
	this->$WebRowSetImpl::removeRowSetListener(listener);
}

$String* FilteredRowSetImpl::getCommand() {
	 return this->$WebRowSetImpl::getCommand();
}

$String* FilteredRowSetImpl::getUrl() {
	 return this->$WebRowSetImpl::getUrl();
}

void FilteredRowSetImpl::setUrl($String* url) {
	this->$WebRowSetImpl::setUrl(url);
}

$String* FilteredRowSetImpl::getDataSourceName() {
	 return this->$WebRowSetImpl::getDataSourceName();
}

void FilteredRowSetImpl::setDataSourceName($String* name) {
	this->$WebRowSetImpl::setDataSourceName(name);
}

$String* FilteredRowSetImpl::getUsername() {
	 return this->$WebRowSetImpl::getUsername();
}

void FilteredRowSetImpl::setUsername($String* name) {
	this->$WebRowSetImpl::setUsername(name);
}

$String* FilteredRowSetImpl::getPassword() {
	 return this->$WebRowSetImpl::getPassword();
}

void FilteredRowSetImpl::setPassword($String* pass) {
	this->$WebRowSetImpl::setPassword(pass);
}

void FilteredRowSetImpl::setType(int32_t type) {
	this->$WebRowSetImpl::setType(type);
}

int32_t FilteredRowSetImpl::getType() {
	 return this->$WebRowSetImpl::getType();
}

void FilteredRowSetImpl::setConcurrency(int32_t concurrency) {
	this->$WebRowSetImpl::setConcurrency(concurrency);
}

bool FilteredRowSetImpl::isReadOnly() {
	 return this->$WebRowSetImpl::isReadOnly();
}

void FilteredRowSetImpl::setReadOnly(bool value) {
	this->$WebRowSetImpl::setReadOnly(value);
}

int32_t FilteredRowSetImpl::getTransactionIsolation() {
	 return this->$WebRowSetImpl::getTransactionIsolation();
}

void FilteredRowSetImpl::setTransactionIsolation(int32_t level) {
	this->$WebRowSetImpl::setTransactionIsolation(level);
}

$Map* FilteredRowSetImpl::getTypeMap() {
	 return this->$WebRowSetImpl::getTypeMap();
}

void FilteredRowSetImpl::setTypeMap($Map* map) {
	this->$WebRowSetImpl::setTypeMap(map);
}

int32_t FilteredRowSetImpl::getMaxFieldSize() {
	 return this->$WebRowSetImpl::getMaxFieldSize();
}

void FilteredRowSetImpl::setMaxFieldSize(int32_t max) {
	this->$WebRowSetImpl::setMaxFieldSize(max);
}

int32_t FilteredRowSetImpl::getMaxRows() {
	 return this->$WebRowSetImpl::getMaxRows();
}

void FilteredRowSetImpl::setMaxRows(int32_t max) {
	this->$WebRowSetImpl::setMaxRows(max);
}

void FilteredRowSetImpl::setEscapeProcessing(bool enable) {
	this->$WebRowSetImpl::setEscapeProcessing(enable);
}

int32_t FilteredRowSetImpl::getQueryTimeout() {
	 return this->$WebRowSetImpl::getQueryTimeout();
}

void FilteredRowSetImpl::setQueryTimeout(int32_t seconds) {
	this->$WebRowSetImpl::setQueryTimeout(seconds);
}

bool FilteredRowSetImpl::getShowDeleted() {
	 return this->$WebRowSetImpl::getShowDeleted();
}

void FilteredRowSetImpl::setShowDeleted(bool value) {
	this->$WebRowSetImpl::setShowDeleted(value);
}

bool FilteredRowSetImpl::getEscapeProcessing() {
	 return this->$WebRowSetImpl::getEscapeProcessing();
}

void FilteredRowSetImpl::setFetchDirection(int32_t direction) {
	this->$WebRowSetImpl::setFetchDirection(direction);
}

int32_t FilteredRowSetImpl::getFetchDirection() {
	 return this->$WebRowSetImpl::getFetchDirection();
}

void FilteredRowSetImpl::setFetchSize(int32_t rows) {
	this->$WebRowSetImpl::setFetchSize(rows);
}

int32_t FilteredRowSetImpl::getFetchSize() {
	 return this->$WebRowSetImpl::getFetchSize();
}

int32_t FilteredRowSetImpl::getConcurrency() {
	 return this->$WebRowSetImpl::getConcurrency();
}

void FilteredRowSetImpl::setNull(int32_t parameterIndex, int32_t sqlType) {
	this->$WebRowSetImpl::setNull(parameterIndex, sqlType);
}

void FilteredRowSetImpl::setNull(int32_t parameterIndex, int32_t sqlType, $String* typeName) {
	this->$WebRowSetImpl::setNull(parameterIndex, sqlType, typeName);
}

void FilteredRowSetImpl::setBoolean(int32_t parameterIndex, bool x) {
	this->$WebRowSetImpl::setBoolean(parameterIndex, x);
}

void FilteredRowSetImpl::setByte(int32_t parameterIndex, int8_t x) {
	this->$WebRowSetImpl::setByte(parameterIndex, x);
}

void FilteredRowSetImpl::setShort(int32_t parameterIndex, int16_t x) {
	this->$WebRowSetImpl::setShort(parameterIndex, x);
}

void FilteredRowSetImpl::setInt(int32_t parameterIndex, int32_t x) {
	this->$WebRowSetImpl::setInt(parameterIndex, x);
}

void FilteredRowSetImpl::setLong(int32_t parameterIndex, int64_t x) {
	this->$WebRowSetImpl::setLong(parameterIndex, x);
}

void FilteredRowSetImpl::setFloat(int32_t parameterIndex, float x) {
	this->$WebRowSetImpl::setFloat(parameterIndex, x);
}

void FilteredRowSetImpl::setDouble(int32_t parameterIndex, double x) {
	this->$WebRowSetImpl::setDouble(parameterIndex, x);
}

void FilteredRowSetImpl::setBigDecimal(int32_t parameterIndex, $BigDecimal* x) {
	this->$WebRowSetImpl::setBigDecimal(parameterIndex, x);
}

void FilteredRowSetImpl::setString(int32_t parameterIndex, $String* x) {
	this->$WebRowSetImpl::setString(parameterIndex, x);
}

void FilteredRowSetImpl::setBytes(int32_t parameterIndex, $bytes* x) {
	this->$WebRowSetImpl::setBytes(parameterIndex, x);
}

void FilteredRowSetImpl::setDate(int32_t parameterIndex, $Date* x) {
	this->$WebRowSetImpl::setDate(parameterIndex, x);
}

void FilteredRowSetImpl::setTime(int32_t parameterIndex, $Time* x) {
	this->$WebRowSetImpl::setTime(parameterIndex, x);
}

void FilteredRowSetImpl::setTimestamp(int32_t parameterIndex, $Timestamp* x) {
	this->$WebRowSetImpl::setTimestamp(parameterIndex, x);
}

void FilteredRowSetImpl::setAsciiStream(int32_t parameterIndex, $InputStream* x, int32_t length) {
	this->$WebRowSetImpl::setAsciiStream(parameterIndex, x, length);
}

void FilteredRowSetImpl::setAsciiStream(int32_t parameterIndex, $InputStream* x) {
	this->$WebRowSetImpl::setAsciiStream(parameterIndex, x);
}

void FilteredRowSetImpl::setBinaryStream(int32_t parameterIndex, $InputStream* x, int32_t length) {
	this->$WebRowSetImpl::setBinaryStream(parameterIndex, x, length);
}

void FilteredRowSetImpl::setBinaryStream(int32_t parameterIndex, $InputStream* x) {
	this->$WebRowSetImpl::setBinaryStream(parameterIndex, x);
}

void FilteredRowSetImpl::setCharacterStream(int32_t parameterIndex, $Reader* reader, int32_t length) {
	this->$WebRowSetImpl::setCharacterStream(parameterIndex, reader, length);
}

void FilteredRowSetImpl::setCharacterStream(int32_t parameterIndex, $Reader* reader) {
	this->$WebRowSetImpl::setCharacterStream(parameterIndex, reader);
}

void FilteredRowSetImpl::setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType, int32_t scale) {
	this->$WebRowSetImpl::setObject(parameterIndex, x, targetSqlType, scale);
}

void FilteredRowSetImpl::setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType) {
	this->$WebRowSetImpl::setObject(parameterIndex, x, targetSqlType);
}

void FilteredRowSetImpl::setObject(int32_t parameterIndex, Object$* x) {
	this->$WebRowSetImpl::setObject(parameterIndex, x);
}

void FilteredRowSetImpl::setRef(int32_t parameterIndex, $Ref* ref) {
	this->$WebRowSetImpl::setRef(parameterIndex, ref);
}

void FilteredRowSetImpl::setBlob(int32_t parameterIndex, $Blob* x) {
	this->$WebRowSetImpl::setBlob(parameterIndex, x);
}

void FilteredRowSetImpl::setClob(int32_t parameterIndex, $Clob* x) {
	this->$WebRowSetImpl::setClob(parameterIndex, x);
}

void FilteredRowSetImpl::setArray(int32_t parameterIndex, $1Array* array) {
	this->$WebRowSetImpl::setArray(parameterIndex, array);
}

void FilteredRowSetImpl::setDate(int32_t parameterIndex, $Date* x, $Calendar* cal) {
	this->$WebRowSetImpl::setDate(parameterIndex, x, cal);
}

void FilteredRowSetImpl::setTime(int32_t parameterIndex, $Time* x, $Calendar* cal) {
	this->$WebRowSetImpl::setTime(parameterIndex, x, cal);
}

void FilteredRowSetImpl::setTimestamp(int32_t parameterIndex, $Timestamp* x, $Calendar* cal) {
	this->$WebRowSetImpl::setTimestamp(parameterIndex, x, cal);
}

void FilteredRowSetImpl::clearParameters() {
	this->$WebRowSetImpl::clearParameters();
}

int32_t FilteredRowSetImpl::hashCode() {
	 return this->$WebRowSetImpl::hashCode();
}

bool FilteredRowSetImpl::equals(Object$* arg0) {
	 return this->$WebRowSetImpl::equals(arg0);
}

$String* FilteredRowSetImpl::toString() {
	 return this->$WebRowSetImpl::toString();
}

void FilteredRowSetImpl::finalize() {
	this->$WebRowSetImpl::finalize();
}

void FilteredRowSetImpl::updateObject(int32_t arg0, Object$* arg1, $SQLType* arg2, int32_t arg3) {
	this->$WebRowSetImpl::updateObject(arg0, arg1, arg2, arg3);
}

void FilteredRowSetImpl::updateObject($String* arg0, Object$* arg1, $SQLType* arg2, int32_t arg3) {
	this->$WebRowSetImpl::updateObject(arg0, arg1, arg2, arg3);
}

void FilteredRowSetImpl::updateObject(int32_t arg0, Object$* arg1, $SQLType* arg2) {
	this->$WebRowSetImpl::updateObject(arg0, arg1, arg2);
}

void FilteredRowSetImpl::updateObject($String* arg0, Object$* arg1, $SQLType* arg2) {
	this->$WebRowSetImpl::updateObject(arg0, arg1, arg2);
}

void FilteredRowSetImpl::init$() {
	$WebRowSetImpl::init$();
	this->onInsertRow = false;
}

void FilteredRowSetImpl::init$($Hashtable* env) {
	$WebRowSetImpl::init$(env);
	this->onInsertRow = false;
}

void FilteredRowSetImpl::setFilter($Predicate* p) {
	$set(this, p, p);
}

$Predicate* FilteredRowSetImpl::getFilter() {
	return this->p;
}

bool FilteredRowSetImpl::internalNext() {
	bool bool$ = false;
	for (int32_t rows = this->getRow(); rows <= this->size(); ++rows) {
		bool$ = $WebRowSetImpl::internalNext();
		if (!bool$ || this->p == nullptr) {
			return bool$;
		}
		if ($nc(this->p)->evaluate(static_cast<$RowSet*>(static_cast<$CachedRowSet*>(static_cast<$CachedRowSetImpl*>(static_cast<$WebRowSetImpl*>(this)))))) {
			break;
		}
	}
	return bool$;
}

bool FilteredRowSetImpl::internalPrevious() {
	bool bool$ = false;
	for (int32_t rows = this->getRow(); rows > 0; --rows) {
		bool$ = $WebRowSetImpl::internalPrevious();
		if (this->p == nullptr) {
			return bool$;
		}
		if ($nc(this->p)->evaluate(static_cast<$RowSet*>(static_cast<$CachedRowSet*>(static_cast<$CachedRowSetImpl*>(static_cast<$WebRowSetImpl*>(this)))))) {
			break;
		}
	}
	return bool$;
}

bool FilteredRowSetImpl::internalFirst() {
	bool bool$ = $WebRowSetImpl::internalFirst();
	if (this->p == nullptr) {
		return bool$;
	}
	while (bool$) {
		if ($nc(this->p)->evaluate(static_cast<$RowSet*>(static_cast<$CachedRowSet*>(static_cast<$CachedRowSetImpl*>(static_cast<$WebRowSetImpl*>(this)))))) {
			break;
		}
		bool$ = $WebRowSetImpl::internalNext();
	}
	return bool$;
}

bool FilteredRowSetImpl::internalLast() {
	bool bool$ = $WebRowSetImpl::internalLast();
	if (this->p == nullptr) {
		return bool$;
	}
	while (bool$) {
		if ($nc(this->p)->evaluate(static_cast<$RowSet*>(static_cast<$CachedRowSet*>(static_cast<$CachedRowSetImpl*>(static_cast<$WebRowSetImpl*>(this)))))) {
			break;
		}
		bool$ = $WebRowSetImpl::internalPrevious();
	}
	return bool$;
}

bool FilteredRowSetImpl::relative(int32_t rows) {
	$useLocalCurrentObjectStackCache();
	bool retval = false;
	bool bool$ = false;
	bool boolval = false;
	if (getType() == $ResultSet::TYPE_FORWARD_ONLY) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.relative"_s))))->toString()));
	}
	if (rows > 0) {
		int32_t i = 0;
		while (i < (rows)) {
			if (isAfterLast()) {
				return false;
			}
			bool$ = internalNext();
			++i;
		}
		retval = bool$;
	} else {
		int32_t j = rows;
		while ((j) < 0) {
			if (isBeforeFirst()) {
				return false;
			}
			boolval = internalPrevious();
			++j;
		}
		retval = boolval;
	}
	if (rows != 0) {
		notifyCursorMoved();
	}
	return retval;
}

bool FilteredRowSetImpl::absolute(int32_t rows) {
	$useLocalCurrentObjectStackCache();
	bool retval = false;
	bool bool$ = false;
	if (rows == 0 || getType() == $ResultSet::TYPE_FORWARD_ONLY) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.absolute"_s))))->toString()));
	}
	if (rows > 0) {
		bool$ = internalFirst();
		int32_t i = 0;
		while (i < (rows - 1)) {
			if (isAfterLast()) {
				return false;
			}
			bool$ = internalNext();
			++i;
		}
		retval = bool$;
	} else {
		bool$ = internalLast();
		int32_t j = rows;
		while ((j + 1) < 0) {
			if (isBeforeFirst()) {
				return false;
			}
			bool$ = internalPrevious();
			++j;
		}
		retval = bool$;
	}
	notifyCursorMoved();
	return retval;
}

void FilteredRowSetImpl::moveToInsertRow() {
	this->onInsertRow = true;
	$WebRowSetImpl::moveToInsertRow();
}

void FilteredRowSetImpl::updateInt(int32_t columnIndex, int32_t x) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate($($of($Integer::valueOf(x))), columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateInt(columnIndex, x);
}

void FilteredRowSetImpl::updateInt($String* columnName, int32_t x) {
	this->updateInt(findColumn(columnName), x);
}

void FilteredRowSetImpl::updateBoolean(int32_t columnIndex, bool x) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate($($of($Boolean::valueOf(x))), columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateBoolean(columnIndex, x);
}

void FilteredRowSetImpl::updateBoolean($String* columnName, bool x) {
	this->updateBoolean(findColumn(columnName), x);
}

void FilteredRowSetImpl::updateByte(int32_t columnIndex, int8_t x) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate($($of($Byte::valueOf(x))), columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateByte(columnIndex, x);
}

void FilteredRowSetImpl::updateByte($String* columnName, int8_t x) {
	this->updateByte(findColumn(columnName), x);
}

void FilteredRowSetImpl::updateShort(int32_t columnIndex, int16_t x) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate($($of($Short::valueOf(x))), columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateShort(columnIndex, x);
}

void FilteredRowSetImpl::updateShort($String* columnName, int16_t x) {
	this->updateShort(findColumn(columnName), x);
}

void FilteredRowSetImpl::updateLong(int32_t columnIndex, int64_t x) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate($($of($Long::valueOf(x))), columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateLong(columnIndex, x);
}

void FilteredRowSetImpl::updateLong($String* columnName, int64_t x) {
	this->updateLong(findColumn(columnName), x);
}

void FilteredRowSetImpl::updateFloat(int32_t columnIndex, float x) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate($($of($Float::valueOf(x))), columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateFloat(columnIndex, x);
}

void FilteredRowSetImpl::updateFloat($String* columnName, float x) {
	this->updateFloat(findColumn(columnName), x);
}

void FilteredRowSetImpl::updateDouble(int32_t columnIndex, double x) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate($($of($Double::valueOf(x))), columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateDouble(columnIndex, x);
}

void FilteredRowSetImpl::updateDouble($String* columnName, double x) {
	this->updateDouble(findColumn(columnName), x);
}

void FilteredRowSetImpl::updateBigDecimal(int32_t columnIndex, $BigDecimal* x) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate($of(x), columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateBigDecimal(columnIndex, x);
}

void FilteredRowSetImpl::updateBigDecimal($String* columnName, $BigDecimal* x) {
	this->updateBigDecimal(findColumn(columnName), x);
}

void FilteredRowSetImpl::updateString(int32_t columnIndex, $String* x) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate($of(x), columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateString(columnIndex, x);
}

void FilteredRowSetImpl::updateString($String* columnName, $String* x) {
	this->updateString(findColumn(columnName), x);
}

void FilteredRowSetImpl::updateBytes(int32_t columnIndex, $bytes* x) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	$var($String, val, ""_s);
	$var($ByteArray, obj_arr, $new($ByteArray, $nc(x)->length));
	for (int32_t i = 0; i < x->length; ++i) {
		obj_arr->set(i, $($Byte::valueOf(x->get(i))));
		$assign(val, val->concat($($nc(obj_arr->get(i))->toString())));
	}
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate($of(val), columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateBytes(columnIndex, x);
}

void FilteredRowSetImpl::updateBytes($String* columnName, $bytes* x) {
	this->updateBytes(findColumn(columnName), x);
}

void FilteredRowSetImpl::updateDate(int32_t columnIndex, $Date* x) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate($of(x), columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateDate(columnIndex, x);
}

void FilteredRowSetImpl::updateDate($String* columnName, $Date* x) {
	this->updateDate(findColumn(columnName), x);
}

void FilteredRowSetImpl::updateTime(int32_t columnIndex, $Time* x) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate($of(x), columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateTime(columnIndex, x);
}

void FilteredRowSetImpl::updateTime($String* columnName, $Time* x) {
	this->updateTime(findColumn(columnName), x);
}

void FilteredRowSetImpl::updateTimestamp(int32_t columnIndex, $Timestamp* x) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate($of(x), columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateTimestamp(columnIndex, x);
}

void FilteredRowSetImpl::updateTimestamp($String* columnName, $Timestamp* x) {
	this->updateTimestamp(findColumn(columnName), x);
}

void FilteredRowSetImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x, int32_t length) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate($of(x), columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateAsciiStream(columnIndex, x, length);
}

void FilteredRowSetImpl::updateAsciiStream($String* columnName, $InputStream* x, int32_t length) {
	this->updateAsciiStream(findColumn(columnName), x, length);
}

void FilteredRowSetImpl::updateCharacterStream(int32_t columnIndex, $Reader* x, int32_t length) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate($of(x), columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateCharacterStream(columnIndex, x, length);
}

void FilteredRowSetImpl::updateCharacterStream($String* columnName, $Reader* reader, int32_t length) {
	this->updateCharacterStream(findColumn(columnName), reader, length);
}

void FilteredRowSetImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x, int32_t length) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate($of(x), columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateBinaryStream(columnIndex, x, length);
}

void FilteredRowSetImpl::updateBinaryStream($String* columnName, $InputStream* x, int32_t length) {
	this->updateBinaryStream(findColumn(columnName), x, length);
}

void FilteredRowSetImpl::updateObject(int32_t columnIndex, Object$* x) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate(x, columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateObject(columnIndex, x);
}

void FilteredRowSetImpl::updateObject($String* columnName, Object$* x) {
	this->updateObject(findColumn(columnName), x);
}

void FilteredRowSetImpl::updateObject(int32_t columnIndex, Object$* x, int32_t scale) {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	if (this->onInsertRow) {
		if (this->p != nullptr) {
			bool$ = $nc(this->p)->evaluate(x, columnIndex);
			if (!bool$) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("filteredrowsetimpl.notallowed"_s))))->toString()));
			}
		}
	}
	$WebRowSetImpl::updateObject(columnIndex, x, scale);
}

void FilteredRowSetImpl::updateObject($String* columnName, Object$* x, int32_t scale) {
	this->updateObject(findColumn(columnName), x, scale);
}

void FilteredRowSetImpl::insertRow() {
	this->onInsertRow = false;
	$WebRowSetImpl::insertRow();
}

void FilteredRowSetImpl::readObject($ObjectInputStream* ois) {
	$nc(ois)->defaultReadObject();
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

FilteredRowSetImpl::FilteredRowSetImpl() {
}

$Class* FilteredRowSetImpl::load$($String* name, bool initialize) {
	$loadClass(FilteredRowSetImpl, name, initialize, &_FilteredRowSetImpl_ClassInfo_, allocate$FilteredRowSetImpl);
	return class$;
}

$Class* FilteredRowSetImpl::class$ = nullptr;

		} // rowset
	} // sun
} // com
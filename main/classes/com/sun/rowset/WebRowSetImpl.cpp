#include <com/sun/rowset/WebRowSetImpl.h>

#include <com/sun/rowset/CachedRowSetImpl.h>
#include <com/sun/rowset/JdbcRowSetResourceBundle.h>
#include <com/sun/rowset/internal/WebRowSetXmlReader.h>
#include <com/sun/rowset/internal/WebRowSetXmlWriter.h>
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
#include <javax/sql/rowset/CachedRowSet.h>
#include <javax/sql/rowset/RowSetWarning.h>
#include <javax/sql/rowset/WebRowSet.h>
#include <javax/sql/rowset/spi/SyncFactory.h>
#include <javax/sql/rowset/spi/SyncProvider.h>
#include <jcpp.h>

#undef ROWSET_SYNC_PROVIDER

using $CachedRowSetImpl = ::com::sun::rowset::CachedRowSetImpl;
using $JdbcRowSetResourceBundle = ::com::sun::rowset::JdbcRowSetResourceBundle;
using $WebRowSetXmlReader = ::com::sun::rowset::internal::WebRowSetXmlReader;
using $WebRowSetXmlWriter = ::com::sun::rowset::internal::WebRowSetXmlWriter;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $OutputStream = ::java::io::OutputStream;
using $Reader = ::java::io::Reader;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
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
using $CachedRowSet = ::javax::sql::rowset::CachedRowSet;
using $RowSetWarning = ::javax::sql::rowset::RowSetWarning;
using $WebRowSet = ::javax::sql::rowset::WebRowSet;
using $SyncFactory = ::javax::sql::rowset::spi::SyncFactory;
using $SyncProvider = ::javax::sql::rowset::spi::SyncProvider;

namespace com {
	namespace sun {
		namespace rowset {

$FieldInfo _WebRowSetImpl_FieldInfo_[] = {
	{"xmlReader", "Lcom/sun/rowset/internal/WebRowSetXmlReader;", nullptr, $PRIVATE, $field(WebRowSetImpl, xmlReader)},
	{"xmlWriter", "Lcom/sun/rowset/internal/WebRowSetXmlWriter;", nullptr, $PRIVATE, $field(WebRowSetImpl, xmlWriter)},
	{"curPosBfrWrite", "I", nullptr, $PRIVATE, $field(WebRowSetImpl, curPosBfrWrite)},
	{"provider", "Ljavax/sql/rowset/spi/SyncProvider;", nullptr, $PRIVATE, $field(WebRowSetImpl, provider)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(WebRowSetImpl, serialVersionUID)},
	{}
};

$MethodInfo _WebRowSetImpl_MethodInfo_[] = {
	{"*absolute", "(I)Z", nullptr, $PUBLIC},
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
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(WebRowSetImpl::*)()>(&WebRowSetImpl::init$)), "java.sql.SQLException"},
	{"<init>", "(Ljava/util/Hashtable;)V", nullptr, $PUBLIC, $method(static_cast<void(WebRowSetImpl::*)($Hashtable*)>(&WebRowSetImpl::init$)), "java.sql.SQLException"},
	{"*insertRow", "()V", nullptr, $PUBLIC},
	{"*isAfterLast", "()Z", nullptr, $PUBLIC},
	{"*isBeforeFirst", "()Z", nullptr, $PUBLIC},
	{"*isClosed", "()Z", nullptr, $PUBLIC},
	{"*isFirst", "()Z", nullptr, $PUBLIC},
	{"*isLast", "()Z", nullptr, $PUBLIC},
	{"*isReadOnly", "()Z", nullptr, $PUBLIC},
	{"*isWrapperFor", "(Ljava/lang/Class;)Z", nullptr, $PUBLIC},
	{"*last", "()Z", nullptr, $PUBLIC},
	{"*moveToCurrentRow", "()V", nullptr, $PUBLIC},
	{"*moveToInsertRow", "()V", nullptr, $PUBLIC},
	{"*next", "()Z", nullptr, $PUBLIC},
	{"*nextPage", "()Z", nullptr, $PUBLIC},
	{"*populate", "(Ljava/sql/ResultSet;)V", nullptr, $PUBLIC},
	{"*populate", "(Ljava/sql/ResultSet;I)V", nullptr, $PUBLIC},
	{"*previous", "()Z", nullptr, $PUBLIC},
	{"*previousPage", "()Z", nullptr, $PUBLIC},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetImpl::*)($ObjectInputStream*)>(&WebRowSetImpl::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readXml", "(Ljava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readXml", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException,java.io.IOException"},
	{"*refreshRow", "()V", nullptr, $PUBLIC},
	{"*relative", "(I)Z", nullptr, $PUBLIC},
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
	{"*updateAsciiStream", "(ILjava/io/InputStream;I)V", nullptr, $PUBLIC},
	{"*updateAsciiStream", "(Ljava/lang/String;Ljava/io/InputStream;I)V", nullptr, $PUBLIC},
	{"*updateAsciiStream", "(ILjava/io/InputStream;J)V", nullptr, $PUBLIC},
	{"*updateAsciiStream", "(Ljava/lang/String;Ljava/io/InputStream;J)V", nullptr, $PUBLIC},
	{"*updateAsciiStream", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC},
	{"*updateAsciiStream", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC},
	{"*updateBigDecimal", "(ILjava/math/BigDecimal;)V", nullptr, $PUBLIC},
	{"*updateBigDecimal", "(Ljava/lang/String;Ljava/math/BigDecimal;)V", nullptr, $PUBLIC},
	{"*updateBinaryStream", "(ILjava/io/InputStream;I)V", nullptr, $PUBLIC},
	{"*updateBinaryStream", "(Ljava/lang/String;Ljava/io/InputStream;I)V", nullptr, $PUBLIC},
	{"*updateBinaryStream", "(ILjava/io/InputStream;J)V", nullptr, $PUBLIC},
	{"*updateBinaryStream", "(Ljava/lang/String;Ljava/io/InputStream;J)V", nullptr, $PUBLIC},
	{"*updateBinaryStream", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC},
	{"*updateBinaryStream", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC},
	{"*updateBlob", "(ILjava/sql/Blob;)V", nullptr, $PUBLIC},
	{"*updateBlob", "(Ljava/lang/String;Ljava/sql/Blob;)V", nullptr, $PUBLIC},
	{"*updateBlob", "(ILjava/io/InputStream;J)V", nullptr, $PUBLIC},
	{"*updateBlob", "(Ljava/lang/String;Ljava/io/InputStream;J)V", nullptr, $PUBLIC},
	{"*updateBlob", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC},
	{"*updateBlob", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC},
	{"*updateBoolean", "(IZ)V", nullptr, $PUBLIC},
	{"*updateBoolean", "(Ljava/lang/String;Z)V", nullptr, $PUBLIC},
	{"*updateByte", "(IB)V", nullptr, $PUBLIC},
	{"*updateByte", "(Ljava/lang/String;B)V", nullptr, $PUBLIC},
	{"*updateBytes", "(I[B)V", nullptr, $PUBLIC},
	{"*updateBytes", "(Ljava/lang/String;[B)V", nullptr, $PUBLIC},
	{"*updateCharacterStream", "(ILjava/io/Reader;I)V", nullptr, $PUBLIC},
	{"*updateCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;I)V", nullptr, $PUBLIC},
	{"*updateCharacterStream", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*updateCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*updateCharacterStream", "(ILjava/io/Reader;)V", nullptr, $PUBLIC},
	{"*updateCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC},
	{"*updateClob", "(ILjava/sql/Clob;)V", nullptr, $PUBLIC},
	{"*updateClob", "(Ljava/lang/String;Ljava/sql/Clob;)V", nullptr, $PUBLIC},
	{"*updateClob", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*updateClob", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*updateClob", "(ILjava/io/Reader;)V", nullptr, $PUBLIC},
	{"*updateClob", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC},
	{"*updateDate", "(ILjava/sql/Date;)V", nullptr, $PUBLIC},
	{"*updateDate", "(Ljava/lang/String;Ljava/sql/Date;)V", nullptr, $PUBLIC},
	{"*updateDouble", "(ID)V", nullptr, $PUBLIC},
	{"*updateDouble", "(Ljava/lang/String;D)V", nullptr, $PUBLIC},
	{"*updateFloat", "(IF)V", nullptr, $PUBLIC},
	{"*updateFloat", "(Ljava/lang/String;F)V", nullptr, $PUBLIC},
	{"*updateInt", "(II)V", nullptr, $PUBLIC},
	{"*updateInt", "(Ljava/lang/String;I)V", nullptr, $PUBLIC},
	{"*updateLong", "(IJ)V", nullptr, $PUBLIC},
	{"*updateLong", "(Ljava/lang/String;J)V", nullptr, $PUBLIC},
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
	{"*updateObject", "(ILjava/lang/Object;I)V", nullptr, $PUBLIC},
	{"*updateObject", "(ILjava/lang/Object;)V", nullptr, $PUBLIC},
	{"*updateObject", "(Ljava/lang/String;Ljava/lang/Object;I)V", nullptr, $PUBLIC},
	{"*updateObject", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"*updateObject", "(ILjava/lang/Object;Ljava/sql/SQLType;I)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*updateObject", "(Ljava/lang/String;Ljava/lang/Object;Ljava/sql/SQLType;I)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*updateObject", "(ILjava/lang/Object;Ljava/sql/SQLType;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*updateObject", "(Ljava/lang/String;Ljava/lang/Object;Ljava/sql/SQLType;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*updateRef", "(ILjava/sql/Ref;)V", nullptr, $PUBLIC},
	{"*updateRef", "(Ljava/lang/String;Ljava/sql/Ref;)V", nullptr, $PUBLIC},
	{"*updateRow", "()V", nullptr, $PUBLIC},
	{"*updateRowId", "(ILjava/sql/RowId;)V", nullptr, $PUBLIC},
	{"*updateRowId", "(Ljava/lang/String;Ljava/sql/RowId;)V", nullptr, $PUBLIC},
	{"*updateSQLXML", "(ILjava/sql/SQLXML;)V", nullptr, $PUBLIC},
	{"*updateSQLXML", "(Ljava/lang/String;Ljava/sql/SQLXML;)V", nullptr, $PUBLIC},
	{"*updateShort", "(IS)V", nullptr, $PUBLIC},
	{"*updateShort", "(Ljava/lang/String;S)V", nullptr, $PUBLIC},
	{"*updateString", "(ILjava/lang/String;)V", nullptr, $PUBLIC},
	{"*updateString", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*updateTime", "(ILjava/sql/Time;)V", nullptr, $PUBLIC},
	{"*updateTime", "(Ljava/lang/String;Ljava/sql/Time;)V", nullptr, $PUBLIC},
	{"*updateTimestamp", "(ILjava/sql/Timestamp;)V", nullptr, $PUBLIC},
	{"*updateTimestamp", "(Ljava/lang/String;Ljava/sql/Timestamp;)V", nullptr, $PUBLIC},
	{"*wasNull", "()Z", nullptr, $PUBLIC},
	{"writeXml", "(Ljava/sql/ResultSet;Ljava/io/Writer;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeXml", "(Ljava/io/Writer;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeXml", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException,java.io.IOException"},
	{"writeXml", "(Ljava/sql/ResultSet;Ljava/io/OutputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException,java.io.IOException"},
	{}
};

$ClassInfo _WebRowSetImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.rowset.WebRowSetImpl",
	"com.sun.rowset.CachedRowSetImpl",
	"javax.sql.rowset.WebRowSet",
	_WebRowSetImpl_FieldInfo_,
	_WebRowSetImpl_MethodInfo_
};

$Object* allocate$WebRowSetImpl($Class* clazz) {
	return $of($alloc(WebRowSetImpl));
}

void WebRowSetImpl::setCommand($String* cmd) {
	this->$CachedRowSetImpl::setCommand(cmd);
}

void WebRowSetImpl::populate($ResultSet* data) {
	this->$CachedRowSetImpl::populate(data);
}

void WebRowSetImpl::execute($Connection* conn) {
	this->$CachedRowSetImpl::execute(conn);
}

void WebRowSetImpl::acceptChanges() {
	this->$CachedRowSetImpl::acceptChanges();
}

void WebRowSetImpl::acceptChanges($Connection* con) {
	this->$CachedRowSetImpl::acceptChanges(con);
}

void WebRowSetImpl::restoreOriginal() {
	this->$CachedRowSetImpl::restoreOriginal();
}

void WebRowSetImpl::release() {
	this->$CachedRowSetImpl::release();
}

void WebRowSetImpl::undoDelete() {
	this->$CachedRowSetImpl::undoDelete();
}

void WebRowSetImpl::undoInsert() {
	this->$CachedRowSetImpl::undoInsert();
}

void WebRowSetImpl::undoUpdate() {
	this->$CachedRowSetImpl::undoUpdate();
}

$RowSet* WebRowSetImpl::createShared() {
	 return this->$CachedRowSetImpl::createShared();
}

$Object* WebRowSetImpl::clone() {
	 return this->$CachedRowSetImpl::clone();
}

$CachedRowSet* WebRowSetImpl::createCopy() {
	 return this->$CachedRowSetImpl::createCopy();
}

$CachedRowSet* WebRowSetImpl::createCopySchema() {
	 return this->$CachedRowSetImpl::createCopySchema();
}

$CachedRowSet* WebRowSetImpl::createCopyNoConstraints() {
	 return this->$CachedRowSetImpl::createCopyNoConstraints();
}

$Collection* WebRowSetImpl::toCollection() {
	 return this->$CachedRowSetImpl::toCollection();
}

$Collection* WebRowSetImpl::toCollection(int32_t column) {
	 return this->$CachedRowSetImpl::toCollection(column);
}

$Collection* WebRowSetImpl::toCollection($String* column) {
	 return this->$CachedRowSetImpl::toCollection(column);
}

$SyncProvider* WebRowSetImpl::getSyncProvider() {
	 return this->$CachedRowSetImpl::getSyncProvider();
}

void WebRowSetImpl::setSyncProvider($String* providerStr) {
	this->$CachedRowSetImpl::setSyncProvider(providerStr);
}

void WebRowSetImpl::execute() {
	this->$CachedRowSetImpl::execute();
}

bool WebRowSetImpl::next() {
	 return this->$CachedRowSetImpl::next();
}

void WebRowSetImpl::close() {
	this->$CachedRowSetImpl::close();
}

bool WebRowSetImpl::wasNull() {
	 return this->$CachedRowSetImpl::wasNull();
}

$String* WebRowSetImpl::getString(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getString(columnIndex);
}

bool WebRowSetImpl::getBoolean(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getBoolean(columnIndex);
}

int8_t WebRowSetImpl::getByte(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getByte(columnIndex);
}

int16_t WebRowSetImpl::getShort(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getShort(columnIndex);
}

int32_t WebRowSetImpl::getInt(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getInt(columnIndex);
}

int64_t WebRowSetImpl::getLong(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getLong(columnIndex);
}

float WebRowSetImpl::getFloat(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getFloat(columnIndex);
}

double WebRowSetImpl::getDouble(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getDouble(columnIndex);
}

$BigDecimal* WebRowSetImpl::getBigDecimal(int32_t columnIndex, int32_t scale) {
	 return this->$CachedRowSetImpl::getBigDecimal(columnIndex, scale);
}

$bytes* WebRowSetImpl::getBytes(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getBytes(columnIndex);
}

$Date* WebRowSetImpl::getDate(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getDate(columnIndex);
}

$Time* WebRowSetImpl::getTime(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getTime(columnIndex);
}

$Timestamp* WebRowSetImpl::getTimestamp(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getTimestamp(columnIndex);
}

$InputStream* WebRowSetImpl::getAsciiStream(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getAsciiStream(columnIndex);
}

$InputStream* WebRowSetImpl::getUnicodeStream(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getUnicodeStream(columnIndex);
}

$InputStream* WebRowSetImpl::getBinaryStream(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getBinaryStream(columnIndex);
}

$String* WebRowSetImpl::getString($String* columnName) {
	 return this->$CachedRowSetImpl::getString(columnName);
}

bool WebRowSetImpl::getBoolean($String* columnName) {
	 return this->$CachedRowSetImpl::getBoolean(columnName);
}

int8_t WebRowSetImpl::getByte($String* columnName) {
	 return this->$CachedRowSetImpl::getByte(columnName);
}

int16_t WebRowSetImpl::getShort($String* columnName) {
	 return this->$CachedRowSetImpl::getShort(columnName);
}

int32_t WebRowSetImpl::getInt($String* columnName) {
	 return this->$CachedRowSetImpl::getInt(columnName);
}

int64_t WebRowSetImpl::getLong($String* columnName) {
	 return this->$CachedRowSetImpl::getLong(columnName);
}

float WebRowSetImpl::getFloat($String* columnName) {
	 return this->$CachedRowSetImpl::getFloat(columnName);
}

double WebRowSetImpl::getDouble($String* columnName) {
	 return this->$CachedRowSetImpl::getDouble(columnName);
}

$BigDecimal* WebRowSetImpl::getBigDecimal($String* columnName, int32_t scale) {
	 return this->$CachedRowSetImpl::getBigDecimal(columnName, scale);
}

$bytes* WebRowSetImpl::getBytes($String* columnName) {
	 return this->$CachedRowSetImpl::getBytes(columnName);
}

$Date* WebRowSetImpl::getDate($String* columnName) {
	 return this->$CachedRowSetImpl::getDate(columnName);
}

$Time* WebRowSetImpl::getTime($String* columnName) {
	 return this->$CachedRowSetImpl::getTime(columnName);
}

$Timestamp* WebRowSetImpl::getTimestamp($String* columnName) {
	 return this->$CachedRowSetImpl::getTimestamp(columnName);
}

$InputStream* WebRowSetImpl::getAsciiStream($String* columnName) {
	 return this->$CachedRowSetImpl::getAsciiStream(columnName);
}

$InputStream* WebRowSetImpl::getUnicodeStream($String* columnName) {
	 return this->$CachedRowSetImpl::getUnicodeStream(columnName);
}

$InputStream* WebRowSetImpl::getBinaryStream($String* columnName) {
	 return this->$CachedRowSetImpl::getBinaryStream(columnName);
}

$SQLWarning* WebRowSetImpl::getWarnings() {
	 return this->$CachedRowSetImpl::getWarnings();
}

void WebRowSetImpl::clearWarnings() {
	this->$CachedRowSetImpl::clearWarnings();
}

$String* WebRowSetImpl::getCursorName() {
	 return this->$CachedRowSetImpl::getCursorName();
}

$ResultSetMetaData* WebRowSetImpl::getMetaData() {
	 return this->$CachedRowSetImpl::getMetaData();
}

$Object* WebRowSetImpl::getObject(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getObject(columnIndex);
}

$Object* WebRowSetImpl::getObject($String* columnName) {
	 return this->$CachedRowSetImpl::getObject(columnName);
}

int32_t WebRowSetImpl::findColumn($String* columnName) {
	 return this->$CachedRowSetImpl::findColumn(columnName);
}

$Reader* WebRowSetImpl::getCharacterStream(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getCharacterStream(columnIndex);
}

$Reader* WebRowSetImpl::getCharacterStream($String* columnName) {
	 return this->$CachedRowSetImpl::getCharacterStream(columnName);
}

$BigDecimal* WebRowSetImpl::getBigDecimal(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getBigDecimal(columnIndex);
}

$BigDecimal* WebRowSetImpl::getBigDecimal($String* columnName) {
	 return this->$CachedRowSetImpl::getBigDecimal(columnName);
}

int32_t WebRowSetImpl::size() {
	 return this->$CachedRowSetImpl::size();
}

bool WebRowSetImpl::isBeforeFirst() {
	 return this->$CachedRowSetImpl::isBeforeFirst();
}

bool WebRowSetImpl::isAfterLast() {
	 return this->$CachedRowSetImpl::isAfterLast();
}

bool WebRowSetImpl::isFirst() {
	 return this->$CachedRowSetImpl::isFirst();
}

bool WebRowSetImpl::isLast() {
	 return this->$CachedRowSetImpl::isLast();
}

void WebRowSetImpl::beforeFirst() {
	this->$CachedRowSetImpl::beforeFirst();
}

void WebRowSetImpl::afterLast() {
	this->$CachedRowSetImpl::afterLast();
}

bool WebRowSetImpl::first() {
	 return this->$CachedRowSetImpl::first();
}

bool WebRowSetImpl::last() {
	 return this->$CachedRowSetImpl::last();
}

int32_t WebRowSetImpl::getRow() {
	 return this->$CachedRowSetImpl::getRow();
}

bool WebRowSetImpl::absolute(int32_t row) {
	 return this->$CachedRowSetImpl::absolute(row);
}

bool WebRowSetImpl::relative(int32_t rows) {
	 return this->$CachedRowSetImpl::relative(rows);
}

bool WebRowSetImpl::previous() {
	 return this->$CachedRowSetImpl::previous();
}

bool WebRowSetImpl::rowUpdated() {
	 return this->$CachedRowSetImpl::rowUpdated();
}

bool WebRowSetImpl::columnUpdated(int32_t idx) {
	 return this->$CachedRowSetImpl::columnUpdated(idx);
}

bool WebRowSetImpl::columnUpdated($String* columnName) {
	 return this->$CachedRowSetImpl::columnUpdated(columnName);
}

bool WebRowSetImpl::rowInserted() {
	 return this->$CachedRowSetImpl::rowInserted();
}

bool WebRowSetImpl::rowDeleted() {
	 return this->$CachedRowSetImpl::rowDeleted();
}

void WebRowSetImpl::updateNull(int32_t columnIndex) {
	this->$CachedRowSetImpl::updateNull(columnIndex);
}

void WebRowSetImpl::updateBoolean(int32_t columnIndex, bool x) {
	this->$CachedRowSetImpl::updateBoolean(columnIndex, x);
}

void WebRowSetImpl::updateByte(int32_t columnIndex, int8_t x) {
	this->$CachedRowSetImpl::updateByte(columnIndex, x);
}

void WebRowSetImpl::updateShort(int32_t columnIndex, int16_t x) {
	this->$CachedRowSetImpl::updateShort(columnIndex, x);
}

void WebRowSetImpl::updateInt(int32_t columnIndex, int32_t x) {
	this->$CachedRowSetImpl::updateInt(columnIndex, x);
}

void WebRowSetImpl::updateLong(int32_t columnIndex, int64_t x) {
	this->$CachedRowSetImpl::updateLong(columnIndex, x);
}

void WebRowSetImpl::updateFloat(int32_t columnIndex, float x) {
	this->$CachedRowSetImpl::updateFloat(columnIndex, x);
}

void WebRowSetImpl::updateDouble(int32_t columnIndex, double x) {
	this->$CachedRowSetImpl::updateDouble(columnIndex, x);
}

void WebRowSetImpl::updateBigDecimal(int32_t columnIndex, $BigDecimal* x) {
	this->$CachedRowSetImpl::updateBigDecimal(columnIndex, x);
}

void WebRowSetImpl::updateString(int32_t columnIndex, $String* x) {
	this->$CachedRowSetImpl::updateString(columnIndex, x);
}

void WebRowSetImpl::updateBytes(int32_t columnIndex, $bytes* x) {
	this->$CachedRowSetImpl::updateBytes(columnIndex, x);
}

void WebRowSetImpl::updateDate(int32_t columnIndex, $Date* x) {
	this->$CachedRowSetImpl::updateDate(columnIndex, x);
}

void WebRowSetImpl::updateTime(int32_t columnIndex, $Time* x) {
	this->$CachedRowSetImpl::updateTime(columnIndex, x);
}

void WebRowSetImpl::updateTimestamp(int32_t columnIndex, $Timestamp* x) {
	this->$CachedRowSetImpl::updateTimestamp(columnIndex, x);
}

void WebRowSetImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x, int32_t length) {
	this->$CachedRowSetImpl::updateAsciiStream(columnIndex, x, length);
}

void WebRowSetImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x, int32_t length) {
	this->$CachedRowSetImpl::updateBinaryStream(columnIndex, x, length);
}

void WebRowSetImpl::updateCharacterStream(int32_t columnIndex, $Reader* x, int32_t length) {
	this->$CachedRowSetImpl::updateCharacterStream(columnIndex, x, length);
}

void WebRowSetImpl::updateObject(int32_t columnIndex, Object$* x, int32_t scale) {
	this->$CachedRowSetImpl::updateObject(columnIndex, x, scale);
}

void WebRowSetImpl::updateObject(int32_t columnIndex, Object$* x) {
	this->$CachedRowSetImpl::updateObject(columnIndex, x);
}

void WebRowSetImpl::updateNull($String* columnName) {
	this->$CachedRowSetImpl::updateNull(columnName);
}

void WebRowSetImpl::updateBoolean($String* columnName, bool x) {
	this->$CachedRowSetImpl::updateBoolean(columnName, x);
}

void WebRowSetImpl::updateByte($String* columnName, int8_t x) {
	this->$CachedRowSetImpl::updateByte(columnName, x);
}

void WebRowSetImpl::updateShort($String* columnName, int16_t x) {
	this->$CachedRowSetImpl::updateShort(columnName, x);
}

void WebRowSetImpl::updateInt($String* columnName, int32_t x) {
	this->$CachedRowSetImpl::updateInt(columnName, x);
}

void WebRowSetImpl::updateLong($String* columnName, int64_t x) {
	this->$CachedRowSetImpl::updateLong(columnName, x);
}

void WebRowSetImpl::updateFloat($String* columnName, float x) {
	this->$CachedRowSetImpl::updateFloat(columnName, x);
}

void WebRowSetImpl::updateDouble($String* columnName, double x) {
	this->$CachedRowSetImpl::updateDouble(columnName, x);
}

void WebRowSetImpl::updateBigDecimal($String* columnName, $BigDecimal* x) {
	this->$CachedRowSetImpl::updateBigDecimal(columnName, x);
}

void WebRowSetImpl::updateString($String* columnName, $String* x) {
	this->$CachedRowSetImpl::updateString(columnName, x);
}

void WebRowSetImpl::updateBytes($String* columnName, $bytes* x) {
	this->$CachedRowSetImpl::updateBytes(columnName, x);
}

void WebRowSetImpl::updateDate($String* columnName, $Date* x) {
	this->$CachedRowSetImpl::updateDate(columnName, x);
}

void WebRowSetImpl::updateTime($String* columnName, $Time* x) {
	this->$CachedRowSetImpl::updateTime(columnName, x);
}

void WebRowSetImpl::updateTimestamp($String* columnName, $Timestamp* x) {
	this->$CachedRowSetImpl::updateTimestamp(columnName, x);
}

void WebRowSetImpl::updateAsciiStream($String* columnName, $InputStream* x, int32_t length) {
	this->$CachedRowSetImpl::updateAsciiStream(columnName, x, length);
}

void WebRowSetImpl::updateBinaryStream($String* columnName, $InputStream* x, int32_t length) {
	this->$CachedRowSetImpl::updateBinaryStream(columnName, x, length);
}

void WebRowSetImpl::updateCharacterStream($String* columnName, $Reader* reader, int32_t length) {
	this->$CachedRowSetImpl::updateCharacterStream(columnName, reader, length);
}

void WebRowSetImpl::updateObject($String* columnName, Object$* x, int32_t scale) {
	this->$CachedRowSetImpl::updateObject(columnName, x, scale);
}

void WebRowSetImpl::updateObject($String* columnName, Object$* x) {
	this->$CachedRowSetImpl::updateObject(columnName, x);
}

void WebRowSetImpl::insertRow() {
	this->$CachedRowSetImpl::insertRow();
}

void WebRowSetImpl::updateRow() {
	this->$CachedRowSetImpl::updateRow();
}

void WebRowSetImpl::deleteRow() {
	this->$CachedRowSetImpl::deleteRow();
}

void WebRowSetImpl::refreshRow() {
	this->$CachedRowSetImpl::refreshRow();
}

void WebRowSetImpl::cancelRowUpdates() {
	this->$CachedRowSetImpl::cancelRowUpdates();
}

void WebRowSetImpl::moveToInsertRow() {
	this->$CachedRowSetImpl::moveToInsertRow();
}

void WebRowSetImpl::moveToCurrentRow() {
	this->$CachedRowSetImpl::moveToCurrentRow();
}

$Statement* WebRowSetImpl::getStatement() {
	 return this->$CachedRowSetImpl::getStatement();
}

$Object* WebRowSetImpl::getObject(int32_t columnIndex, $Map* map) {
	 return this->$CachedRowSetImpl::getObject(columnIndex, map);
}

$Ref* WebRowSetImpl::getRef(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getRef(columnIndex);
}

$Blob* WebRowSetImpl::getBlob(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getBlob(columnIndex);
}

$Clob* WebRowSetImpl::getClob(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getClob(columnIndex);
}

$1Array* WebRowSetImpl::getArray(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getArray(columnIndex);
}

$Object* WebRowSetImpl::getObject($String* columnName, $Map* map) {
	 return this->$CachedRowSetImpl::getObject(columnName, map);
}

$Ref* WebRowSetImpl::getRef($String* colName) {
	 return this->$CachedRowSetImpl::getRef(colName);
}

$Blob* WebRowSetImpl::getBlob($String* colName) {
	 return this->$CachedRowSetImpl::getBlob(colName);
}

$Clob* WebRowSetImpl::getClob($String* colName) {
	 return this->$CachedRowSetImpl::getClob(colName);
}

$1Array* WebRowSetImpl::getArray($String* colName) {
	 return this->$CachedRowSetImpl::getArray(colName);
}

$Date* WebRowSetImpl::getDate(int32_t columnIndex, $Calendar* cal) {
	 return this->$CachedRowSetImpl::getDate(columnIndex, cal);
}

$Date* WebRowSetImpl::getDate($String* columnName, $Calendar* cal) {
	 return this->$CachedRowSetImpl::getDate(columnName, cal);
}

$Time* WebRowSetImpl::getTime(int32_t columnIndex, $Calendar* cal) {
	 return this->$CachedRowSetImpl::getTime(columnIndex, cal);
}

$Time* WebRowSetImpl::getTime($String* columnName, $Calendar* cal) {
	 return this->$CachedRowSetImpl::getTime(columnName, cal);
}

$Timestamp* WebRowSetImpl::getTimestamp(int32_t columnIndex, $Calendar* cal) {
	 return this->$CachedRowSetImpl::getTimestamp(columnIndex, cal);
}

$Timestamp* WebRowSetImpl::getTimestamp($String* columnName, $Calendar* cal) {
	 return this->$CachedRowSetImpl::getTimestamp(columnName, cal);
}

void WebRowSetImpl::setMetaData($RowSetMetaData* md) {
	this->$CachedRowSetImpl::setMetaData(md);
}

$ResultSet* WebRowSetImpl::getOriginal() {
	 return this->$CachedRowSetImpl::getOriginal();
}

$ResultSet* WebRowSetImpl::getOriginalRow() {
	 return this->$CachedRowSetImpl::getOriginalRow();
}

void WebRowSetImpl::setOriginalRow() {
	this->$CachedRowSetImpl::setOriginalRow();
}

$String* WebRowSetImpl::getTableName() {
	 return this->$CachedRowSetImpl::getTableName();
}

void WebRowSetImpl::setTableName($String* tabName) {
	this->$CachedRowSetImpl::setTableName(tabName);
}

$ints* WebRowSetImpl::getKeyColumns() {
	 return this->$CachedRowSetImpl::getKeyColumns();
}

void WebRowSetImpl::setKeyColumns($ints* keys) {
	this->$CachedRowSetImpl::setKeyColumns(keys);
}

void WebRowSetImpl::updateRef(int32_t columnIndex, $Ref* ref) {
	this->$CachedRowSetImpl::updateRef(columnIndex, ref);
}

void WebRowSetImpl::updateRef($String* columnName, $Ref* ref) {
	this->$CachedRowSetImpl::updateRef(columnName, ref);
}

void WebRowSetImpl::updateClob(int32_t columnIndex, $Clob* c) {
	this->$CachedRowSetImpl::updateClob(columnIndex, c);
}

void WebRowSetImpl::updateClob($String* columnName, $Clob* c) {
	this->$CachedRowSetImpl::updateClob(columnName, c);
}

void WebRowSetImpl::updateBlob(int32_t columnIndex, $Blob* b) {
	this->$CachedRowSetImpl::updateBlob(columnIndex, b);
}

void WebRowSetImpl::updateBlob($String* columnName, $Blob* b) {
	this->$CachedRowSetImpl::updateBlob(columnName, b);
}

void WebRowSetImpl::updateArray(int32_t columnIndex, $1Array* a) {
	this->$CachedRowSetImpl::updateArray(columnIndex, a);
}

void WebRowSetImpl::updateArray($String* columnName, $1Array* a) {
	this->$CachedRowSetImpl::updateArray(columnName, a);
}

$URL* WebRowSetImpl::getURL(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getURL(columnIndex);
}

$URL* WebRowSetImpl::getURL($String* columnName) {
	 return this->$CachedRowSetImpl::getURL(columnName);
}

$RowSetWarning* WebRowSetImpl::getRowSetWarnings() {
	 return this->$CachedRowSetImpl::getRowSetWarnings();
}

void WebRowSetImpl::commit() {
	this->$CachedRowSetImpl::commit();
}

void WebRowSetImpl::rollback() {
	this->$CachedRowSetImpl::rollback();
}

void WebRowSetImpl::rollback($Savepoint* s) {
	this->$CachedRowSetImpl::rollback(s);
}

void WebRowSetImpl::unsetMatchColumn($ints* columnIdxes) {
	this->$CachedRowSetImpl::unsetMatchColumn(columnIdxes);
}

void WebRowSetImpl::unsetMatchColumn($StringArray* columnIdxes) {
	this->$CachedRowSetImpl::unsetMatchColumn(columnIdxes);
}

$StringArray* WebRowSetImpl::getMatchColumnNames() {
	 return this->$CachedRowSetImpl::getMatchColumnNames();
}

$ints* WebRowSetImpl::getMatchColumnIndexes() {
	 return this->$CachedRowSetImpl::getMatchColumnIndexes();
}

void WebRowSetImpl::setMatchColumn($ints* columnIdxes) {
	this->$CachedRowSetImpl::setMatchColumn(columnIdxes);
}

void WebRowSetImpl::setMatchColumn($StringArray* columnNames) {
	this->$CachedRowSetImpl::setMatchColumn(columnNames);
}

void WebRowSetImpl::setMatchColumn(int32_t columnIdx) {
	this->$CachedRowSetImpl::setMatchColumn(columnIdx);
}

void WebRowSetImpl::setMatchColumn($String* columnName) {
	this->$CachedRowSetImpl::setMatchColumn(columnName);
}

void WebRowSetImpl::unsetMatchColumn(int32_t columnIdx) {
	this->$CachedRowSetImpl::unsetMatchColumn(columnIdx);
}

void WebRowSetImpl::unsetMatchColumn($String* columnName) {
	this->$CachedRowSetImpl::unsetMatchColumn(columnName);
}

void WebRowSetImpl::rowSetPopulated($RowSetEvent* event, int32_t numRows) {
	this->$CachedRowSetImpl::rowSetPopulated(event, numRows);
}

void WebRowSetImpl::populate($ResultSet* data, int32_t start) {
	this->$CachedRowSetImpl::populate(data, start);
}

bool WebRowSetImpl::nextPage() {
	 return this->$CachedRowSetImpl::nextPage();
}

void WebRowSetImpl::setPageSize(int32_t size) {
	this->$CachedRowSetImpl::setPageSize(size);
}

int32_t WebRowSetImpl::getPageSize() {
	 return this->$CachedRowSetImpl::getPageSize();
}

bool WebRowSetImpl::previousPage() {
	 return this->$CachedRowSetImpl::previousPage();
}

$SQLXML* WebRowSetImpl::getSQLXML(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getSQLXML(columnIndex);
}

$SQLXML* WebRowSetImpl::getSQLXML($String* colName) {
	 return this->$CachedRowSetImpl::getSQLXML(colName);
}

$RowId* WebRowSetImpl::getRowId(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getRowId(columnIndex);
}

$RowId* WebRowSetImpl::getRowId($String* columnName) {
	 return this->$CachedRowSetImpl::getRowId(columnName);
}

void WebRowSetImpl::updateRowId(int32_t columnIndex, $RowId* x) {
	this->$CachedRowSetImpl::updateRowId(columnIndex, x);
}

void WebRowSetImpl::updateRowId($String* columnName, $RowId* x) {
	this->$CachedRowSetImpl::updateRowId(columnName, x);
}

int32_t WebRowSetImpl::getHoldability() {
	 return this->$CachedRowSetImpl::getHoldability();
}

bool WebRowSetImpl::isClosed() {
	 return this->$CachedRowSetImpl::isClosed();
}

void WebRowSetImpl::updateNString(int32_t columnIndex, $String* nString) {
	this->$CachedRowSetImpl::updateNString(columnIndex, nString);
}

void WebRowSetImpl::updateNString($String* columnName, $String* nString) {
	this->$CachedRowSetImpl::updateNString(columnName, nString);
}

void WebRowSetImpl::updateNClob(int32_t columnIndex, $NClob* nClob) {
	this->$CachedRowSetImpl::updateNClob(columnIndex, nClob);
}

void WebRowSetImpl::updateNClob($String* columnName, $NClob* nClob) {
	this->$CachedRowSetImpl::updateNClob(columnName, nClob);
}

$NClob* WebRowSetImpl::getNClob(int32_t i) {
	 return this->$CachedRowSetImpl::getNClob(i);
}

$NClob* WebRowSetImpl::getNClob($String* colName) {
	 return this->$CachedRowSetImpl::getNClob(colName);
}

$Object* WebRowSetImpl::unwrap($Class* iface) {
	 return this->$CachedRowSetImpl::unwrap(iface);
}

bool WebRowSetImpl::isWrapperFor($Class* interfaces) {
	 return this->$CachedRowSetImpl::isWrapperFor(interfaces);
}

void WebRowSetImpl::setSQLXML(int32_t parameterIndex, $SQLXML* xmlObject) {
	this->$CachedRowSetImpl::setSQLXML(parameterIndex, xmlObject);
}

void WebRowSetImpl::setSQLXML($String* parameterName, $SQLXML* xmlObject) {
	this->$CachedRowSetImpl::setSQLXML(parameterName, xmlObject);
}

void WebRowSetImpl::setRowId(int32_t parameterIndex, $RowId* x) {
	this->$CachedRowSetImpl::setRowId(parameterIndex, x);
}

void WebRowSetImpl::setRowId($String* parameterName, $RowId* x) {
	this->$CachedRowSetImpl::setRowId(parameterName, x);
}

void WebRowSetImpl::setNCharacterStream(int32_t parameterIndex, $Reader* value) {
	this->$CachedRowSetImpl::setNCharacterStream(parameterIndex, value);
}

void WebRowSetImpl::setNClob($String* parameterName, $NClob* value) {
	this->$CachedRowSetImpl::setNClob(parameterName, value);
}

$Reader* WebRowSetImpl::getNCharacterStream(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getNCharacterStream(columnIndex);
}

$Reader* WebRowSetImpl::getNCharacterStream($String* columnName) {
	 return this->$CachedRowSetImpl::getNCharacterStream(columnName);
}

void WebRowSetImpl::updateSQLXML(int32_t columnIndex, $SQLXML* xmlObject) {
	this->$CachedRowSetImpl::updateSQLXML(columnIndex, xmlObject);
}

void WebRowSetImpl::updateSQLXML($String* columnName, $SQLXML* xmlObject) {
	this->$CachedRowSetImpl::updateSQLXML(columnName, xmlObject);
}

$String* WebRowSetImpl::getNString(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getNString(columnIndex);
}

$String* WebRowSetImpl::getNString($String* columnName) {
	 return this->$CachedRowSetImpl::getNString(columnName);
}

void WebRowSetImpl::updateNCharacterStream(int32_t columnIndex, $Reader* x, int64_t length) {
	this->$CachedRowSetImpl::updateNCharacterStream(columnIndex, x, length);
}

void WebRowSetImpl::updateNCharacterStream($String* columnName, $Reader* x, int64_t length) {
	this->$CachedRowSetImpl::updateNCharacterStream(columnName, x, length);
}

void WebRowSetImpl::updateNCharacterStream(int32_t columnIndex, $Reader* x) {
	this->$CachedRowSetImpl::updateNCharacterStream(columnIndex, x);
}

void WebRowSetImpl::updateNCharacterStream($String* columnLabel, $Reader* reader) {
	this->$CachedRowSetImpl::updateNCharacterStream(columnLabel, reader);
}

void WebRowSetImpl::updateBlob(int32_t columnIndex, $InputStream* inputStream, int64_t length) {
	this->$CachedRowSetImpl::updateBlob(columnIndex, inputStream, length);
}

void WebRowSetImpl::updateBlob($String* columnLabel, $InputStream* inputStream, int64_t length) {
	this->$CachedRowSetImpl::updateBlob(columnLabel, inputStream, length);
}

void WebRowSetImpl::updateBlob(int32_t columnIndex, $InputStream* inputStream) {
	this->$CachedRowSetImpl::updateBlob(columnIndex, inputStream);
}

void WebRowSetImpl::updateBlob($String* columnLabel, $InputStream* inputStream) {
	this->$CachedRowSetImpl::updateBlob(columnLabel, inputStream);
}

void WebRowSetImpl::updateClob(int32_t columnIndex, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::updateClob(columnIndex, reader, length);
}

void WebRowSetImpl::updateClob($String* columnLabel, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::updateClob(columnLabel, reader, length);
}

void WebRowSetImpl::updateClob(int32_t columnIndex, $Reader* reader) {
	this->$CachedRowSetImpl::updateClob(columnIndex, reader);
}

void WebRowSetImpl::updateClob($String* columnLabel, $Reader* reader) {
	this->$CachedRowSetImpl::updateClob(columnLabel, reader);
}

void WebRowSetImpl::updateNClob(int32_t columnIndex, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::updateNClob(columnIndex, reader, length);
}

void WebRowSetImpl::updateNClob($String* columnLabel, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::updateNClob(columnLabel, reader, length);
}

void WebRowSetImpl::updateNClob(int32_t columnIndex, $Reader* reader) {
	this->$CachedRowSetImpl::updateNClob(columnIndex, reader);
}

void WebRowSetImpl::updateNClob($String* columnLabel, $Reader* reader) {
	this->$CachedRowSetImpl::updateNClob(columnLabel, reader);
}

void WebRowSetImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x, int64_t length) {
	this->$CachedRowSetImpl::updateAsciiStream(columnIndex, x, length);
}

void WebRowSetImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x, int64_t length) {
	this->$CachedRowSetImpl::updateBinaryStream(columnIndex, x, length);
}

void WebRowSetImpl::updateCharacterStream(int32_t columnIndex, $Reader* x, int64_t length) {
	this->$CachedRowSetImpl::updateCharacterStream(columnIndex, x, length);
}

void WebRowSetImpl::updateCharacterStream($String* columnLabel, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::updateCharacterStream(columnLabel, reader, length);
}

void WebRowSetImpl::updateAsciiStream($String* columnLabel, $InputStream* x, int64_t length) {
	this->$CachedRowSetImpl::updateAsciiStream(columnLabel, x, length);
}

void WebRowSetImpl::updateBinaryStream($String* columnLabel, $InputStream* x, int64_t length) {
	this->$CachedRowSetImpl::updateBinaryStream(columnLabel, x, length);
}

void WebRowSetImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x) {
	this->$CachedRowSetImpl::updateBinaryStream(columnIndex, x);
}

void WebRowSetImpl::updateBinaryStream($String* columnLabel, $InputStream* x) {
	this->$CachedRowSetImpl::updateBinaryStream(columnLabel, x);
}

void WebRowSetImpl::updateCharacterStream(int32_t columnIndex, $Reader* x) {
	this->$CachedRowSetImpl::updateCharacterStream(columnIndex, x);
}

void WebRowSetImpl::updateCharacterStream($String* columnLabel, $Reader* reader) {
	this->$CachedRowSetImpl::updateCharacterStream(columnLabel, reader);
}

void WebRowSetImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x) {
	this->$CachedRowSetImpl::updateAsciiStream(columnIndex, x);
}

void WebRowSetImpl::updateAsciiStream($String* columnLabel, $InputStream* x) {
	this->$CachedRowSetImpl::updateAsciiStream(columnLabel, x);
}

void WebRowSetImpl::setURL(int32_t parameterIndex, $URL* x) {
	this->$CachedRowSetImpl::setURL(parameterIndex, x);
}

void WebRowSetImpl::setNClob(int32_t parameterIndex, $Reader* reader) {
	this->$CachedRowSetImpl::setNClob(parameterIndex, reader);
}

void WebRowSetImpl::setNClob($String* parameterName, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::setNClob(parameterName, reader, length);
}

void WebRowSetImpl::setNClob($String* parameterName, $Reader* reader) {
	this->$CachedRowSetImpl::setNClob(parameterName, reader);
}

void WebRowSetImpl::setNClob(int32_t parameterIndex, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::setNClob(parameterIndex, reader, length);
}

void WebRowSetImpl::setNClob(int32_t parameterIndex, $NClob* value) {
	this->$CachedRowSetImpl::setNClob(parameterIndex, value);
}

void WebRowSetImpl::setNString(int32_t parameterIndex, $String* value) {
	this->$CachedRowSetImpl::setNString(parameterIndex, value);
}

void WebRowSetImpl::setNString($String* parameterName, $String* value) {
	this->$CachedRowSetImpl::setNString(parameterName, value);
}

void WebRowSetImpl::setNCharacterStream(int32_t parameterIndex, $Reader* value, int64_t length) {
	this->$CachedRowSetImpl::setNCharacterStream(parameterIndex, value, length);
}

void WebRowSetImpl::setNCharacterStream($String* parameterName, $Reader* value, int64_t length) {
	this->$CachedRowSetImpl::setNCharacterStream(parameterName, value, length);
}

void WebRowSetImpl::setNCharacterStream($String* parameterName, $Reader* value) {
	this->$CachedRowSetImpl::setNCharacterStream(parameterName, value);
}

void WebRowSetImpl::setTimestamp($String* parameterName, $Timestamp* x, $Calendar* cal) {
	this->$CachedRowSetImpl::setTimestamp(parameterName, x, cal);
}

void WebRowSetImpl::setClob($String* parameterName, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::setClob(parameterName, reader, length);
}

void WebRowSetImpl::setClob($String* parameterName, $Clob* x) {
	this->$CachedRowSetImpl::setClob(parameterName, x);
}

void WebRowSetImpl::setClob($String* parameterName, $Reader* reader) {
	this->$CachedRowSetImpl::setClob(parameterName, reader);
}

void WebRowSetImpl::setDate($String* parameterName, $Date* x) {
	this->$CachedRowSetImpl::setDate(parameterName, x);
}

void WebRowSetImpl::setDate($String* parameterName, $Date* x, $Calendar* cal) {
	this->$CachedRowSetImpl::setDate(parameterName, x, cal);
}

void WebRowSetImpl::setTime($String* parameterName, $Time* x) {
	this->$CachedRowSetImpl::setTime(parameterName, x);
}

void WebRowSetImpl::setTime($String* parameterName, $Time* x, $Calendar* cal) {
	this->$CachedRowSetImpl::setTime(parameterName, x, cal);
}

void WebRowSetImpl::setClob(int32_t parameterIndex, $Reader* reader) {
	this->$CachedRowSetImpl::setClob(parameterIndex, reader);
}

void WebRowSetImpl::setClob(int32_t parameterIndex, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::setClob(parameterIndex, reader, length);
}

void WebRowSetImpl::setBlob(int32_t parameterIndex, $InputStream* inputStream, int64_t length) {
	this->$CachedRowSetImpl::setBlob(parameterIndex, inputStream, length);
}

void WebRowSetImpl::setBlob(int32_t parameterIndex, $InputStream* inputStream) {
	this->$CachedRowSetImpl::setBlob(parameterIndex, inputStream);
}

void WebRowSetImpl::setBlob($String* parameterName, $InputStream* inputStream, int64_t length) {
	this->$CachedRowSetImpl::setBlob(parameterName, inputStream, length);
}

void WebRowSetImpl::setBlob($String* parameterName, $Blob* x) {
	this->$CachedRowSetImpl::setBlob(parameterName, x);
}

void WebRowSetImpl::setBlob($String* parameterName, $InputStream* inputStream) {
	this->$CachedRowSetImpl::setBlob(parameterName, inputStream);
}

void WebRowSetImpl::setObject($String* parameterName, Object$* x, int32_t targetSqlType, int32_t scale) {
	this->$CachedRowSetImpl::setObject(parameterName, x, targetSqlType, scale);
}

void WebRowSetImpl::setObject($String* parameterName, Object$* x, int32_t targetSqlType) {
	this->$CachedRowSetImpl::setObject(parameterName, x, targetSqlType);
}

void WebRowSetImpl::setObject($String* parameterName, Object$* x) {
	this->$CachedRowSetImpl::setObject(parameterName, x);
}

void WebRowSetImpl::setAsciiStream($String* parameterName, $InputStream* x, int32_t length) {
	this->$CachedRowSetImpl::setAsciiStream(parameterName, x, length);
}

void WebRowSetImpl::setBinaryStream($String* parameterName, $InputStream* x, int32_t length) {
	this->$CachedRowSetImpl::setBinaryStream(parameterName, x, length);
}

void WebRowSetImpl::setCharacterStream($String* parameterName, $Reader* reader, int32_t length) {
	this->$CachedRowSetImpl::setCharacterStream(parameterName, reader, length);
}

void WebRowSetImpl::setAsciiStream($String* parameterName, $InputStream* x) {
	this->$CachedRowSetImpl::setAsciiStream(parameterName, x);
}

void WebRowSetImpl::setBinaryStream($String* parameterName, $InputStream* x) {
	this->$CachedRowSetImpl::setBinaryStream(parameterName, x);
}

void WebRowSetImpl::setCharacterStream($String* parameterName, $Reader* reader) {
	this->$CachedRowSetImpl::setCharacterStream(parameterName, reader);
}

void WebRowSetImpl::setBigDecimal($String* parameterName, $BigDecimal* x) {
	this->$CachedRowSetImpl::setBigDecimal(parameterName, x);
}

void WebRowSetImpl::setString($String* parameterName, $String* x) {
	this->$CachedRowSetImpl::setString(parameterName, x);
}

void WebRowSetImpl::setBytes($String* parameterName, $bytes* x) {
	this->$CachedRowSetImpl::setBytes(parameterName, x);
}

void WebRowSetImpl::setTimestamp($String* parameterName, $Timestamp* x) {
	this->$CachedRowSetImpl::setTimestamp(parameterName, x);
}

void WebRowSetImpl::setNull($String* parameterName, int32_t sqlType) {
	this->$CachedRowSetImpl::setNull(parameterName, sqlType);
}

void WebRowSetImpl::setNull($String* parameterName, int32_t sqlType, $String* typeName) {
	this->$CachedRowSetImpl::setNull(parameterName, sqlType, typeName);
}

void WebRowSetImpl::setBoolean($String* parameterName, bool x) {
	this->$CachedRowSetImpl::setBoolean(parameterName, x);
}

void WebRowSetImpl::setByte($String* parameterName, int8_t x) {
	this->$CachedRowSetImpl::setByte(parameterName, x);
}

void WebRowSetImpl::setShort($String* parameterName, int16_t x) {
	this->$CachedRowSetImpl::setShort(parameterName, x);
}

void WebRowSetImpl::setInt($String* parameterName, int32_t x) {
	this->$CachedRowSetImpl::setInt(parameterName, x);
}

void WebRowSetImpl::setLong($String* parameterName, int64_t x) {
	this->$CachedRowSetImpl::setLong(parameterName, x);
}

void WebRowSetImpl::setFloat($String* parameterName, float x) {
	this->$CachedRowSetImpl::setFloat(parameterName, x);
}

void WebRowSetImpl::setDouble($String* parameterName, double x) {
	this->$CachedRowSetImpl::setDouble(parameterName, x);
}

$Object* WebRowSetImpl::getObject(int32_t columnIndex, $Class* type) {
	 return this->$CachedRowSetImpl::getObject(columnIndex, type);
}

$Object* WebRowSetImpl::getObject($String* columnLabel, $Class* type) {
	 return this->$CachedRowSetImpl::getObject(columnLabel, type);
}

void WebRowSetImpl::addRowSetListener($RowSetListener* listener) {
	this->$CachedRowSetImpl::addRowSetListener(listener);
}

void WebRowSetImpl::removeRowSetListener($RowSetListener* listener) {
	this->$CachedRowSetImpl::removeRowSetListener(listener);
}

$String* WebRowSetImpl::getCommand() {
	 return this->$CachedRowSetImpl::getCommand();
}

$String* WebRowSetImpl::getUrl() {
	 return this->$CachedRowSetImpl::getUrl();
}

void WebRowSetImpl::setUrl($String* url) {
	this->$CachedRowSetImpl::setUrl(url);
}

$String* WebRowSetImpl::getDataSourceName() {
	 return this->$CachedRowSetImpl::getDataSourceName();
}

void WebRowSetImpl::setDataSourceName($String* name) {
	this->$CachedRowSetImpl::setDataSourceName(name);
}

$String* WebRowSetImpl::getUsername() {
	 return this->$CachedRowSetImpl::getUsername();
}

void WebRowSetImpl::setUsername($String* name) {
	this->$CachedRowSetImpl::setUsername(name);
}

$String* WebRowSetImpl::getPassword() {
	 return this->$CachedRowSetImpl::getPassword();
}

void WebRowSetImpl::setPassword($String* pass) {
	this->$CachedRowSetImpl::setPassword(pass);
}

void WebRowSetImpl::setType(int32_t type) {
	this->$CachedRowSetImpl::setType(type);
}

int32_t WebRowSetImpl::getType() {
	 return this->$CachedRowSetImpl::getType();
}

void WebRowSetImpl::setConcurrency(int32_t concurrency) {
	this->$CachedRowSetImpl::setConcurrency(concurrency);
}

bool WebRowSetImpl::isReadOnly() {
	 return this->$CachedRowSetImpl::isReadOnly();
}

void WebRowSetImpl::setReadOnly(bool value) {
	this->$CachedRowSetImpl::setReadOnly(value);
}

int32_t WebRowSetImpl::getTransactionIsolation() {
	 return this->$CachedRowSetImpl::getTransactionIsolation();
}

void WebRowSetImpl::setTransactionIsolation(int32_t level) {
	this->$CachedRowSetImpl::setTransactionIsolation(level);
}

$Map* WebRowSetImpl::getTypeMap() {
	 return this->$CachedRowSetImpl::getTypeMap();
}

void WebRowSetImpl::setTypeMap($Map* map) {
	this->$CachedRowSetImpl::setTypeMap(map);
}

int32_t WebRowSetImpl::getMaxFieldSize() {
	 return this->$CachedRowSetImpl::getMaxFieldSize();
}

void WebRowSetImpl::setMaxFieldSize(int32_t max) {
	this->$CachedRowSetImpl::setMaxFieldSize(max);
}

int32_t WebRowSetImpl::getMaxRows() {
	 return this->$CachedRowSetImpl::getMaxRows();
}

void WebRowSetImpl::setMaxRows(int32_t max) {
	this->$CachedRowSetImpl::setMaxRows(max);
}

void WebRowSetImpl::setEscapeProcessing(bool enable) {
	this->$CachedRowSetImpl::setEscapeProcessing(enable);
}

int32_t WebRowSetImpl::getQueryTimeout() {
	 return this->$CachedRowSetImpl::getQueryTimeout();
}

void WebRowSetImpl::setQueryTimeout(int32_t seconds) {
	this->$CachedRowSetImpl::setQueryTimeout(seconds);
}

bool WebRowSetImpl::getShowDeleted() {
	 return this->$CachedRowSetImpl::getShowDeleted();
}

void WebRowSetImpl::setShowDeleted(bool value) {
	this->$CachedRowSetImpl::setShowDeleted(value);
}

bool WebRowSetImpl::getEscapeProcessing() {
	 return this->$CachedRowSetImpl::getEscapeProcessing();
}

void WebRowSetImpl::setFetchDirection(int32_t direction) {
	this->$CachedRowSetImpl::setFetchDirection(direction);
}

int32_t WebRowSetImpl::getFetchDirection() {
	 return this->$CachedRowSetImpl::getFetchDirection();
}

void WebRowSetImpl::setFetchSize(int32_t rows) {
	this->$CachedRowSetImpl::setFetchSize(rows);
}

int32_t WebRowSetImpl::getFetchSize() {
	 return this->$CachedRowSetImpl::getFetchSize();
}

int32_t WebRowSetImpl::getConcurrency() {
	 return this->$CachedRowSetImpl::getConcurrency();
}

void WebRowSetImpl::setNull(int32_t parameterIndex, int32_t sqlType) {
	this->$CachedRowSetImpl::setNull(parameterIndex, sqlType);
}

void WebRowSetImpl::setNull(int32_t parameterIndex, int32_t sqlType, $String* typeName) {
	this->$CachedRowSetImpl::setNull(parameterIndex, sqlType, typeName);
}

void WebRowSetImpl::setBoolean(int32_t parameterIndex, bool x) {
	this->$CachedRowSetImpl::setBoolean(parameterIndex, x);
}

void WebRowSetImpl::setByte(int32_t parameterIndex, int8_t x) {
	this->$CachedRowSetImpl::setByte(parameterIndex, x);
}

void WebRowSetImpl::setShort(int32_t parameterIndex, int16_t x) {
	this->$CachedRowSetImpl::setShort(parameterIndex, x);
}

void WebRowSetImpl::setInt(int32_t parameterIndex, int32_t x) {
	this->$CachedRowSetImpl::setInt(parameterIndex, x);
}

void WebRowSetImpl::setLong(int32_t parameterIndex, int64_t x) {
	this->$CachedRowSetImpl::setLong(parameterIndex, x);
}

void WebRowSetImpl::setFloat(int32_t parameterIndex, float x) {
	this->$CachedRowSetImpl::setFloat(parameterIndex, x);
}

void WebRowSetImpl::setDouble(int32_t parameterIndex, double x) {
	this->$CachedRowSetImpl::setDouble(parameterIndex, x);
}

void WebRowSetImpl::setBigDecimal(int32_t parameterIndex, $BigDecimal* x) {
	this->$CachedRowSetImpl::setBigDecimal(parameterIndex, x);
}

void WebRowSetImpl::setString(int32_t parameterIndex, $String* x) {
	this->$CachedRowSetImpl::setString(parameterIndex, x);
}

void WebRowSetImpl::setBytes(int32_t parameterIndex, $bytes* x) {
	this->$CachedRowSetImpl::setBytes(parameterIndex, x);
}

void WebRowSetImpl::setDate(int32_t parameterIndex, $Date* x) {
	this->$CachedRowSetImpl::setDate(parameterIndex, x);
}

void WebRowSetImpl::setTime(int32_t parameterIndex, $Time* x) {
	this->$CachedRowSetImpl::setTime(parameterIndex, x);
}

void WebRowSetImpl::setTimestamp(int32_t parameterIndex, $Timestamp* x) {
	this->$CachedRowSetImpl::setTimestamp(parameterIndex, x);
}

void WebRowSetImpl::setAsciiStream(int32_t parameterIndex, $InputStream* x, int32_t length) {
	this->$CachedRowSetImpl::setAsciiStream(parameterIndex, x, length);
}

void WebRowSetImpl::setAsciiStream(int32_t parameterIndex, $InputStream* x) {
	this->$CachedRowSetImpl::setAsciiStream(parameterIndex, x);
}

void WebRowSetImpl::setBinaryStream(int32_t parameterIndex, $InputStream* x, int32_t length) {
	this->$CachedRowSetImpl::setBinaryStream(parameterIndex, x, length);
}

void WebRowSetImpl::setBinaryStream(int32_t parameterIndex, $InputStream* x) {
	this->$CachedRowSetImpl::setBinaryStream(parameterIndex, x);
}

void WebRowSetImpl::setCharacterStream(int32_t parameterIndex, $Reader* reader, int32_t length) {
	this->$CachedRowSetImpl::setCharacterStream(parameterIndex, reader, length);
}

void WebRowSetImpl::setCharacterStream(int32_t parameterIndex, $Reader* reader) {
	this->$CachedRowSetImpl::setCharacterStream(parameterIndex, reader);
}

void WebRowSetImpl::setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType, int32_t scale) {
	this->$CachedRowSetImpl::setObject(parameterIndex, x, targetSqlType, scale);
}

void WebRowSetImpl::setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType) {
	this->$CachedRowSetImpl::setObject(parameterIndex, x, targetSqlType);
}

void WebRowSetImpl::setObject(int32_t parameterIndex, Object$* x) {
	this->$CachedRowSetImpl::setObject(parameterIndex, x);
}

void WebRowSetImpl::setRef(int32_t parameterIndex, $Ref* ref) {
	this->$CachedRowSetImpl::setRef(parameterIndex, ref);
}

void WebRowSetImpl::setBlob(int32_t parameterIndex, $Blob* x) {
	this->$CachedRowSetImpl::setBlob(parameterIndex, x);
}

void WebRowSetImpl::setClob(int32_t parameterIndex, $Clob* x) {
	this->$CachedRowSetImpl::setClob(parameterIndex, x);
}

void WebRowSetImpl::setArray(int32_t parameterIndex, $1Array* array) {
	this->$CachedRowSetImpl::setArray(parameterIndex, array);
}

void WebRowSetImpl::setDate(int32_t parameterIndex, $Date* x, $Calendar* cal) {
	this->$CachedRowSetImpl::setDate(parameterIndex, x, cal);
}

void WebRowSetImpl::setTime(int32_t parameterIndex, $Time* x, $Calendar* cal) {
	this->$CachedRowSetImpl::setTime(parameterIndex, x, cal);
}

void WebRowSetImpl::setTimestamp(int32_t parameterIndex, $Timestamp* x, $Calendar* cal) {
	this->$CachedRowSetImpl::setTimestamp(parameterIndex, x, cal);
}

void WebRowSetImpl::clearParameters() {
	this->$CachedRowSetImpl::clearParameters();
}

int32_t WebRowSetImpl::hashCode() {
	 return this->$CachedRowSetImpl::hashCode();
}

bool WebRowSetImpl::equals(Object$* arg0) {
	 return this->$CachedRowSetImpl::equals(arg0);
}

$String* WebRowSetImpl::toString() {
	 return this->$CachedRowSetImpl::toString();
}

void WebRowSetImpl::finalize() {
	this->$CachedRowSetImpl::finalize();
}

void WebRowSetImpl::updateObject(int32_t arg0, Object$* arg1, $SQLType* arg2, int32_t arg3) {
	this->$CachedRowSetImpl::updateObject(arg0, arg1, arg2, arg3);
}

void WebRowSetImpl::updateObject($String* arg0, Object$* arg1, $SQLType* arg2, int32_t arg3) {
	this->$CachedRowSetImpl::updateObject(arg0, arg1, arg2, arg3);
}

void WebRowSetImpl::updateObject(int32_t arg0, Object$* arg1, $SQLType* arg2) {
	this->$CachedRowSetImpl::updateObject(arg0, arg1, arg2);
}

void WebRowSetImpl::updateObject($String* arg0, Object$* arg1, $SQLType* arg2) {
	this->$CachedRowSetImpl::updateObject(arg0, arg1, arg2);
}

void WebRowSetImpl::init$() {
	$CachedRowSetImpl::init$();
	$set(this, xmlReader, $new($WebRowSetXmlReader));
	$set(this, xmlWriter, $new($WebRowSetXmlWriter));
}

void WebRowSetImpl::init$($Hashtable* env) {
	$useLocalCurrentObjectStackCache();
	$CachedRowSetImpl::init$();
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
	if (env == nullptr) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("webrowsetimpl.nullhash"_s))))->toString()));
	}
	$init($SyncFactory);
	$var($String, providerName, $cast($String, $nc(env)->get($SyncFactory::ROWSET_SYNC_PROVIDER)));
	$set(this, provider, $SyncFactory::getInstance(providerName));
}

void WebRowSetImpl::writeXml($ResultSet* rs, $Writer* writer) {
	this->populate(rs);
	this->curPosBfrWrite = this->getRow();
	this->writeXml(writer);
}

void WebRowSetImpl::writeXml($Writer* writer) {
	$useLocalCurrentObjectStackCache();
	if (this->xmlWriter != nullptr) {
		this->curPosBfrWrite = this->getRow();
		$nc(this->xmlWriter)->writeXML(static_cast<$WebRowSet*>(this), writer);
	} else {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("webrowsetimpl.invalidwr"_s))))->toString()));
	}
}

void WebRowSetImpl::readXml($Reader* reader) {
	$useLocalCurrentObjectStackCache();
	try {
		if (reader != nullptr) {
			$nc(this->xmlReader)->readXML(static_cast<$WebRowSet*>(this), reader);
			if (this->curPosBfrWrite == 0) {
				this->beforeFirst();
			} else {
				this->absolute(this->curPosBfrWrite);
			}
		} else {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("webrowsetimpl.invalidrd"_s))))->toString()));
		}
	} catch ($Exception& e) {
		$throwNew($SQLException, $(e->getMessage()));
	}
}

void WebRowSetImpl::readXml($InputStream* iStream) {
	$useLocalCurrentObjectStackCache();
	if (iStream != nullptr) {
		$nc(this->xmlReader)->readXML(static_cast<$WebRowSet*>(this), iStream);
		if (this->curPosBfrWrite == 0) {
			this->beforeFirst();
		} else {
			this->absolute(this->curPosBfrWrite);
		}
	} else {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("webrowsetimpl.invalidrd"_s))))->toString()));
	}
}

void WebRowSetImpl::writeXml($OutputStream* oStream) {
	$useLocalCurrentObjectStackCache();
	if (this->xmlWriter != nullptr) {
		this->curPosBfrWrite = this->getRow();
		$nc(this->xmlWriter)->writeXML(static_cast<$WebRowSet*>(this), oStream);
	} else {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("webrowsetimpl.invalidwr"_s))))->toString()));
	}
}

void WebRowSetImpl::writeXml($ResultSet* rs, $OutputStream* oStream) {
	this->populate(rs);
	this->curPosBfrWrite = this->getRow();
	this->writeXml(oStream);
}

void WebRowSetImpl::readObject($ObjectInputStream* ois) {
	$nc(ois)->defaultReadObject();
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

WebRowSetImpl::WebRowSetImpl() {
}

$Class* WebRowSetImpl::load$($String* name, bool initialize) {
	$loadClass(WebRowSetImpl, name, initialize, &_WebRowSetImpl_ClassInfo_, allocate$WebRowSetImpl);
	return class$;
}

$Class* WebRowSetImpl::class$ = nullptr;

		} // rowset
	} // sun
} // com
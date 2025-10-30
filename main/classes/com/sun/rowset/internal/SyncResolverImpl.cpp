#include <com/sun/rowset/internal/SyncResolverImpl.h>

#include <com/sun/rowset/CachedRowSetImpl.h>
#include <com/sun/rowset/JdbcRowSetResourceBundle.h>
#include <com/sun/rowset/internal/BaseRow.h>
#include <com/sun/rowset/internal/CachedRowSetReader.h>
#include <com/sun/rowset/internal/CachedRowSetWriter.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Reader.h>
#include <java/lang/UnsupportedOperationException.h>
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
#include <java/util/ArrayList.h>
#include <java/util/Calendar.h>
#include <java/util/Collection.h>
#include <java/util/Map.h>
#include <javax/sql/RowSet.h>
#include <javax/sql/RowSetEvent.h>
#include <javax/sql/RowSetInternal.h>
#include <javax/sql/RowSetListener.h>
#include <javax/sql/RowSetMetaData.h>
#include <javax/sql/rowset/BaseRowSet.h>
#include <javax/sql/rowset/CachedRowSet.h>
#include <javax/sql/rowset/RowSetMetaDataImpl.h>
#include <javax/sql/rowset/RowSetWarning.h>
#include <javax/sql/rowset/spi/SyncProvider.h>
#include <javax/sql/rowset/spi/SyncProviderException.h>
#include <javax/sql/rowset/spi/SyncResolver.h>
#include <jcpp.h>

#undef NO_ROW_CONFLICT

using $CachedRowSetImpl = ::com::sun::rowset::CachedRowSetImpl;
using $JdbcRowSetResourceBundle = ::com::sun::rowset::JdbcRowSetResourceBundle;
using $BaseRow = ::com::sun::rowset::internal::BaseRow;
using $CachedRowSetReader = ::com::sun::rowset::internal::CachedRowSetReader;
using $CachedRowSetWriter = ::com::sun::rowset::internal::CachedRowSetWriter;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Reader = ::java::io::Reader;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
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
using $ArrayList = ::java::util::ArrayList;
using $Calendar = ::java::util::Calendar;
using $Collection = ::java::util::Collection;
using $Map = ::java::util::Map;
using $RowSet = ::javax::sql::RowSet;
using $RowSetEvent = ::javax::sql::RowSetEvent;
using $RowSetInternal = ::javax::sql::RowSetInternal;
using $RowSetListener = ::javax::sql::RowSetListener;
using $RowSetMetaData = ::javax::sql::RowSetMetaData;
using $BaseRowSet = ::javax::sql::rowset::BaseRowSet;
using $CachedRowSet = ::javax::sql::rowset::CachedRowSet;
using $RowSetMetaDataImpl = ::javax::sql::rowset::RowSetMetaDataImpl;
using $RowSetWarning = ::javax::sql::rowset::RowSetWarning;
using $SyncProvider = ::javax::sql::rowset::spi::SyncProvider;
using $SyncProviderException = ::javax::sql::rowset::spi::SyncProviderException;
using $SyncResolver = ::javax::sql::rowset::spi::SyncResolver;

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

$CompoundAttribute _SyncResolverImpl_MethodAnnotations_getBigDecimal27[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _SyncResolverImpl_MethodAnnotations_getBigDecimal28[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _SyncResolverImpl_MethodAnnotations_getUnicodeStream95[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _SyncResolverImpl_MethodAnnotations_getUnicodeStream96[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _SyncResolverImpl_FieldInfo_[] = {
	{"crsRes", "Lcom/sun/rowset/CachedRowSetImpl;", nullptr, $PRIVATE, $field(SyncResolverImpl, crsRes)},
	{"crsSync", "Lcom/sun/rowset/CachedRowSetImpl;", nullptr, $PRIVATE, $field(SyncResolverImpl, crsSync)},
	{"stats", "Ljava/util/ArrayList;", "Ljava/util/ArrayList<*>;", $PRIVATE, $field(SyncResolverImpl, stats)},
	{"crw", "Lcom/sun/rowset/internal/CachedRowSetWriter;", nullptr, $PRIVATE, $field(SyncResolverImpl, crw)},
	{"rowStatus", "I", nullptr, $PRIVATE, $field(SyncResolverImpl, rowStatus)},
	{"sz", "I", nullptr, $PRIVATE, $field(SyncResolverImpl, sz)},
	{"con", "Ljava/sql/Connection;", nullptr, $PRIVATE | $TRANSIENT, $field(SyncResolverImpl, con)},
	{"row", "Ljavax/sql/rowset/CachedRowSet;", nullptr, $PRIVATE, $field(SyncResolverImpl, row)},
	{"resBundle", "Lcom/sun/rowset/JdbcRowSetResourceBundle;", nullptr, $PRIVATE, $field(SyncResolverImpl, resBundle)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(SyncResolverImpl, serialVersionUID)},
	{}
};

$MethodInfo _SyncResolverImpl_MethodInfo_[] = {
	{"*addRowSetListener", "(Ljavax/sql/RowSetListener;)V", nullptr, $PUBLIC},
	{"*clearParameters", "()V", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*getCommand", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getConcurrency", "()I", nullptr, $PUBLIC},
	{"*getDataSourceName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getEscapeProcessing", "()Z", nullptr, $PUBLIC},
	{"*getFetchDirection", "()I", nullptr, $PUBLIC},
	{"*getFetchSize", "()I", nullptr, $PUBLIC},
	{"*getHoldability", "()I", nullptr, $PUBLIC},
	{"*getMaxFieldSize", "()I", nullptr, $PUBLIC},
	{"*getMaxRows", "()I", nullptr, $PUBLIC},
	{"*getNCharacterStream", "(I)Ljava/io/Reader;", nullptr, $PUBLIC},
	{"*getNCharacterStream", "(Ljava/lang/String;)Ljava/io/Reader;", nullptr, $PUBLIC},
	{"*getNClob", "(I)Ljava/sql/NClob;", nullptr, $PUBLIC},
	{"*getNClob", "(Ljava/lang/String;)Ljava/sql/NClob;", nullptr, $PUBLIC},
	{"*getNString", "(I)Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getNString", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getObject", "(ILjava/lang/Class;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*getObject", "(Ljava/lang/String;Ljava/lang/Class;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*getPassword", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getQueryTimeout", "()I", nullptr, $PUBLIC},
	{"*getRowId", "(I)Ljava/sql/RowId;", nullptr, $PUBLIC},
	{"*getRowId", "(Ljava/lang/String;)Ljava/sql/RowId;", nullptr, $PUBLIC},
	{"*getSQLXML", "(I)Ljava/sql/SQLXML;", nullptr, $PUBLIC},
	{"*getSQLXML", "(Ljava/lang/String;)Ljava/sql/SQLXML;", nullptr, $PUBLIC},
	{"*getTransactionIsolation", "()I", nullptr, $PUBLIC},
	{"*getType", "()I", nullptr, $PUBLIC},
	{"*getTypeMap", "()Ljava/util/Map;", nullptr, $PUBLIC},
	{"*getUrl", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getUsername", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SyncResolverImpl::*)()>(&SyncResolverImpl::init$)), "java.sql.SQLException"},
	{"absolute", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"acceptChanges", "()V", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.spi.SyncProviderException"},
	{"acceptChanges", "(Ljava/sql/Connection;)V", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.spi.SyncProviderException"},
	{"afterLast", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"beforeFirst", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"buildCachedRow", "()Ljavax/sql/rowset/CachedRowSet;", nullptr, $PRIVATE, $method(static_cast<$CachedRowSet*(SyncResolverImpl::*)()>(&SyncResolverImpl::buildCachedRow)), "java.sql.SQLException"},
	{"cancelRowUpdates", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"clearWarnings", "()V", nullptr, $PUBLIC},
	{"clone", "()Ljava/lang/Object;", nullptr, $PROTECTED, nullptr, "java.lang.CloneNotSupportedException"},
	{"close", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"columnUpdated", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"columnUpdated", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"commit", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"createCopy", "()Ljavax/sql/rowset/CachedRowSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"createCopyNoConstraints", "()Ljavax/sql/rowset/CachedRowSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"createCopySchema", "()Ljavax/sql/rowset/CachedRowSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"createShared", "()Ljavax/sql/RowSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"deleteRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"execute", "(Ljava/sql/Connection;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"execute", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"findColumn", "(Ljava/lang/String;)I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"first", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getArray", "(I)Ljava/sql/Array;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getArray", "(Ljava/lang/String;)Ljava/sql/Array;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getAsciiStream", "(I)Ljava/io/InputStream;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getAsciiStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getBigDecimal", "(II)Ljava/math/BigDecimal;", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.sql.SQLException", nullptr, _SyncResolverImpl_MethodAnnotations_getBigDecimal27},
	{"getBigDecimal", "(Ljava/lang/String;I)Ljava/math/BigDecimal;", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.sql.SQLException", nullptr, _SyncResolverImpl_MethodAnnotations_getBigDecimal28},
	{"getBigDecimal", "(I)Ljava/math/BigDecimal;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getBigDecimal", "(Ljava/lang/String;)Ljava/math/BigDecimal;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getBinaryStream", "(I)Ljava/io/InputStream;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getBinaryStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getBlob", "(I)Ljava/sql/Blob;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getBlob", "(Ljava/lang/String;)Ljava/sql/Blob;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getBoolean", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getBoolean", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getByte", "(I)B", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getByte", "(Ljava/lang/String;)B", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getBytes", "(I)[B", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getBytes", "(Ljava/lang/String;)[B", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getCharacterStream", "(I)Ljava/io/Reader;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getCharacterStream", "(Ljava/lang/String;)Ljava/io/Reader;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getClob", "(I)Ljava/sql/Clob;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getClob", "(Ljava/lang/String;)Ljava/sql/Clob;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getConflictValue", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getConflictValue", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getConnection", "()Ljava/sql/Connection;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getCurrentRow", "()Lcom/sun/rowset/internal/BaseRow;", nullptr, $PROTECTED},
	{"getCursorName", "()Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getDate", "(I)Ljava/sql/Date;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getDate", "(Ljava/lang/String;)Ljava/sql/Date;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getDate", "(ILjava/util/Calendar;)Ljava/sql/Date;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getDate", "(Ljava/lang/String;Ljava/util/Calendar;)Ljava/sql/Date;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getDouble", "(I)D", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getDouble", "(Ljava/lang/String;)D", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getFloat", "(I)F", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getFloat", "(Ljava/lang/String;)F", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getInt", "(I)I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getInt", "(Ljava/lang/String;)I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getKeyColumns", "()[I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getLong", "(I)J", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getLong", "(Ljava/lang/String;)J", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getMatchColumnIndexes", "()[I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getMatchColumnNames", "()[Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getMetaData", "()Ljava/sql/ResultSetMetaData;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getObject", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getObject", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getObject", "(ILjava/util/Map;)Ljava/lang/Object;", "(ILjava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)Ljava/lang/Object;", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getObject", "(Ljava/lang/String;Ljava/util/Map;)Ljava/lang/Object;", "(Ljava/lang/String;Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)Ljava/lang/Object;", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getOriginal", "()Ljava/sql/ResultSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getOriginalRow", "()Ljava/sql/ResultSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getPageSize", "()I", nullptr, $PUBLIC},
	{"getRef", "(I)Ljava/sql/Ref;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getRef", "(Ljava/lang/String;)Ljava/sql/Ref;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getRow", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getRowSetWarnings", "()Ljavax/sql/rowset/RowSetWarning;", nullptr, $PUBLIC},
	{"getShort", "(I)S", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getShort", "(Ljava/lang/String;)S", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getStatement", "()Ljava/sql/Statement;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getStatus", "()I", nullptr, $PUBLIC},
	{"getString", "(I)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getString", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getSyncProvider", "()Ljavax/sql/rowset/spi/SyncProvider;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTableName", "()Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTime", "(I)Ljava/sql/Time;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTime", "(Ljava/lang/String;)Ljava/sql/Time;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTime", "(ILjava/util/Calendar;)Ljava/sql/Time;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTime", "(Ljava/lang/String;Ljava/util/Calendar;)Ljava/sql/Time;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTimestamp", "(I)Ljava/sql/Timestamp;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTimestamp", "(Ljava/lang/String;)Ljava/sql/Timestamp;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTimestamp", "(ILjava/util/Calendar;)Ljava/sql/Timestamp;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTimestamp", "(Ljava/lang/String;Ljava/util/Calendar;)Ljava/sql/Timestamp;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getURL", "(I)Ljava/net/URL;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getURL", "(Ljava/lang/String;)Ljava/net/URL;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getUnicodeStream", "(I)Ljava/io/InputStream;", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.sql.SQLException", nullptr, _SyncResolverImpl_MethodAnnotations_getUnicodeStream95},
	{"getUnicodeStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.sql.SQLException", nullptr, _SyncResolverImpl_MethodAnnotations_getUnicodeStream96},
	{"getWarnings", "()Ljava/sql/SQLWarning;", nullptr, $PUBLIC},
	{"insertRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"internalFirst", "()Z", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"internalLast", "()Z", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"internalNext", "()Z", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"internalPrevious", "()Z", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"isAfterLast", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isBeforeFirst", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*isClosed", "()Z", nullptr, $PUBLIC},
	{"isFirst", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isLast", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*isReadOnly", "()Z", nullptr, $PUBLIC},
	{"*isWrapperFor", "(Ljava/lang/Class;)Z", nullptr, $PUBLIC},
	{"last", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"moveToCurrentRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"moveToInsertRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"next", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"nextConflict", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"nextPage", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"populate", "(Ljava/sql/ResultSet;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"populate", "(Ljava/sql/ResultSet;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"previous", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"previousConflict", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"previousPage", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(SyncResolverImpl::*)($ObjectInputStream*)>(&SyncResolverImpl::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"refreshRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"relative", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"release", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"removeCurrentRow", "()V", nullptr, $PROTECTED},
	{"*removeRowSetListener", "(Ljavax/sql/RowSetListener;)V", nullptr, $PUBLIC},
	{"restoreOriginal", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"rollback", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"rollback", "(Ljava/sql/Savepoint;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"rowDeleted", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"rowInserted", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"rowSetPopulated", "(Ljavax/sql/RowSetEvent;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"rowUpdated", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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
	{"setCachedRowSet", "(Ljavax/sql/rowset/CachedRowSet;)V", nullptr, 0},
	{"setCachedRowSetResolver", "(Ljavax/sql/rowset/CachedRowSet;)V", nullptr, 0},
	{"setCachedRowSetWriter", "(Lcom/sun/rowset/internal/CachedRowSetWriter;)V", nullptr, 0},
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
	{"setCommand", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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
	{"setKeyColumns", "([I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setLong", "(Ljava/lang/String;J)V", nullptr, $PUBLIC},
	{"*setLong", "(IJ)V", nullptr, $PUBLIC},
	{"setMatchColumn", "([I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setMatchColumn", "([Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setMatchColumn", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setMatchColumn", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setMaxFieldSize", "(I)V", nullptr, $PUBLIC},
	{"*setMaxRows", "(I)V", nullptr, $PUBLIC},
	{"setMetaData", "(Ljavax/sql/RowSetMetaData;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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
	{"setOriginal", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setOriginalRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setPageSize", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setPassword", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*setQueryTimeout", "(I)V", nullptr, $PUBLIC},
	{"*setReadOnly", "(Z)V", nullptr, $PUBLIC},
	{"*setRef", "(ILjava/sql/Ref;)V", nullptr, $PUBLIC},
	{"setResolvedValue", "(ILjava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setResolvedValue", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setRowId", "(ILjava/sql/RowId;)V", nullptr, $PUBLIC},
	{"*setRowId", "(Ljava/lang/String;Ljava/sql/RowId;)V", nullptr, $PUBLIC},
	{"*setSQLXML", "(ILjava/sql/SQLXML;)V", nullptr, $PUBLIC},
	{"*setSQLXML", "(Ljava/lang/String;Ljava/sql/SQLXML;)V", nullptr, $PUBLIC},
	{"*setShort", "(Ljava/lang/String;S)V", nullptr, $PUBLIC},
	{"*setShort", "(IS)V", nullptr, $PUBLIC},
	{"setStatus", "(Ljava/util/ArrayList;)V", nullptr, 0},
	{"*setString", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*setString", "(ILjava/lang/String;)V", nullptr, $PUBLIC},
	{"setSyncProvider", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setTableName", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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
	{"size", "()I", nullptr, $PUBLIC},
	{"toCollection", "()Ljava/util/Collection;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"toCollection", "(I)Ljava/util/Collection;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"toCollection", "(Ljava/lang/String;)Ljava/util/Collection;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"undoDelete", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"undoInsert", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"undoUpdate", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"unsetMatchColumn", "([I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"unsetMatchColumn", "([Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"unsetMatchColumn", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"unsetMatchColumn", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*unwrap", "(Ljava/lang/Class;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"updateArray", "(ILjava/sql/Array;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateArray", "(Ljava/lang/String;Ljava/sql/Array;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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
	{"*updateBlob", "(ILjava/io/InputStream;J)V", nullptr, $PUBLIC},
	{"*updateBlob", "(Ljava/lang/String;Ljava/io/InputStream;J)V", nullptr, $PUBLIC},
	{"*updateBlob", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC},
	{"*updateBlob", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC},
	{"updateBlob", "(ILjava/sql/Blob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBlob", "(Ljava/lang/String;Ljava/sql/Blob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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
	{"*updateClob", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*updateClob", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*updateClob", "(ILjava/io/Reader;)V", nullptr, $PUBLIC},
	{"*updateClob", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC},
	{"updateClob", "(ILjava/sql/Clob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateClob", "(Ljava/lang/String;Ljava/sql/Clob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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
	{"updateNCharacterStream", "(ILjava/io/Reader;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateNCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*updateNClob", "(ILjava/sql/NClob;)V", nullptr, $PUBLIC},
	{"*updateNClob", "(Ljava/lang/String;Ljava/sql/NClob;)V", nullptr, $PUBLIC},
	{"*updateNClob", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*updateNClob", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC},
	{"*updateNClob", "(ILjava/io/Reader;)V", nullptr, $PUBLIC},
	{"*updateNClob", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC},
	{"*updateNString", "(ILjava/lang/String;)V", nullptr, $PUBLIC},
	{"*updateNString", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"updateNull", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateNull", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*updateObject", "(ILjava/lang/Object;Ljava/sql/SQLType;I)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*updateObject", "(Ljava/lang/String;Ljava/lang/Object;Ljava/sql/SQLType;I)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*updateObject", "(ILjava/lang/Object;Ljava/sql/SQLType;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"*updateObject", "(Ljava/lang/String;Ljava/lang/Object;Ljava/sql/SQLType;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"updateObject", "(ILjava/lang/Object;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateObject", "(ILjava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateObject", "(Ljava/lang/String;Ljava/lang/Object;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateObject", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateRef", "(ILjava/sql/Ref;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateRef", "(Ljava/lang/String;Ljava/sql/Ref;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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
	{"wasNull", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeData", "(Ljavax/sql/rowset/CachedRowSet;)V", nullptr, $PRIVATE, $method(static_cast<void(SyncResolverImpl::*)($CachedRowSet*)>(&SyncResolverImpl::writeData)), "java.sql.SQLException"},
	{}
};

$ClassInfo _SyncResolverImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.rowset.internal.SyncResolverImpl",
	"com.sun.rowset.CachedRowSetImpl",
	"javax.sql.rowset.spi.SyncResolver",
	_SyncResolverImpl_FieldInfo_,
	_SyncResolverImpl_MethodInfo_
};

$Object* allocate$SyncResolverImpl($Class* clazz) {
	return $of($alloc(SyncResolverImpl));
}

$SQLXML* SyncResolverImpl::getSQLXML(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getSQLXML(columnIndex);
}

$SQLXML* SyncResolverImpl::getSQLXML($String* colName) {
	 return this->$CachedRowSetImpl::getSQLXML(colName);
}

$RowId* SyncResolverImpl::getRowId(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getRowId(columnIndex);
}

$RowId* SyncResolverImpl::getRowId($String* columnName) {
	 return this->$CachedRowSetImpl::getRowId(columnName);
}

void SyncResolverImpl::updateRowId(int32_t columnIndex, $RowId* x) {
	this->$CachedRowSetImpl::updateRowId(columnIndex, x);
}

void SyncResolverImpl::updateRowId($String* columnName, $RowId* x) {
	this->$CachedRowSetImpl::updateRowId(columnName, x);
}

int32_t SyncResolverImpl::getHoldability() {
	 return this->$CachedRowSetImpl::getHoldability();
}

bool SyncResolverImpl::isClosed() {
	 return this->$CachedRowSetImpl::isClosed();
}

void SyncResolverImpl::updateNString(int32_t columnIndex, $String* nString) {
	this->$CachedRowSetImpl::updateNString(columnIndex, nString);
}

void SyncResolverImpl::updateNString($String* columnName, $String* nString) {
	this->$CachedRowSetImpl::updateNString(columnName, nString);
}

void SyncResolverImpl::updateNClob(int32_t columnIndex, $NClob* nClob) {
	this->$CachedRowSetImpl::updateNClob(columnIndex, nClob);
}

void SyncResolverImpl::updateNClob($String* columnName, $NClob* nClob) {
	this->$CachedRowSetImpl::updateNClob(columnName, nClob);
}

$NClob* SyncResolverImpl::getNClob(int32_t i) {
	 return this->$CachedRowSetImpl::getNClob(i);
}

$NClob* SyncResolverImpl::getNClob($String* colName) {
	 return this->$CachedRowSetImpl::getNClob(colName);
}

$Object* SyncResolverImpl::unwrap($Class* iface) {
	 return this->$CachedRowSetImpl::unwrap(iface);
}

bool SyncResolverImpl::isWrapperFor($Class* interfaces) {
	 return this->$CachedRowSetImpl::isWrapperFor(interfaces);
}

void SyncResolverImpl::setSQLXML(int32_t parameterIndex, $SQLXML* xmlObject) {
	this->$CachedRowSetImpl::setSQLXML(parameterIndex, xmlObject);
}

void SyncResolverImpl::setSQLXML($String* parameterName, $SQLXML* xmlObject) {
	this->$CachedRowSetImpl::setSQLXML(parameterName, xmlObject);
}

void SyncResolverImpl::setRowId(int32_t parameterIndex, $RowId* x) {
	this->$CachedRowSetImpl::setRowId(parameterIndex, x);
}

void SyncResolverImpl::setRowId($String* parameterName, $RowId* x) {
	this->$CachedRowSetImpl::setRowId(parameterName, x);
}

void SyncResolverImpl::setNCharacterStream(int32_t parameterIndex, $Reader* value) {
	this->$CachedRowSetImpl::setNCharacterStream(parameterIndex, value);
}

void SyncResolverImpl::setNClob($String* parameterName, $NClob* value) {
	this->$CachedRowSetImpl::setNClob(parameterName, value);
}

$Reader* SyncResolverImpl::getNCharacterStream(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getNCharacterStream(columnIndex);
}

$Reader* SyncResolverImpl::getNCharacterStream($String* columnName) {
	 return this->$CachedRowSetImpl::getNCharacterStream(columnName);
}

void SyncResolverImpl::updateSQLXML(int32_t columnIndex, $SQLXML* xmlObject) {
	this->$CachedRowSetImpl::updateSQLXML(columnIndex, xmlObject);
}

void SyncResolverImpl::updateSQLXML($String* columnName, $SQLXML* xmlObject) {
	this->$CachedRowSetImpl::updateSQLXML(columnName, xmlObject);
}

$String* SyncResolverImpl::getNString(int32_t columnIndex) {
	 return this->$CachedRowSetImpl::getNString(columnIndex);
}

$String* SyncResolverImpl::getNString($String* columnName) {
	 return this->$CachedRowSetImpl::getNString(columnName);
}

void SyncResolverImpl::updateNCharacterStream(int32_t columnIndex, $Reader* x, int64_t length) {
	this->$CachedRowSetImpl::updateNCharacterStream(columnIndex, x, length);
}

void SyncResolverImpl::updateNCharacterStream($String* columnName, $Reader* x, int64_t length) {
	this->$CachedRowSetImpl::updateNCharacterStream(columnName, x, length);
}

void SyncResolverImpl::updateNCharacterStream(int32_t columnIndex, $Reader* x) {
	this->$CachedRowSetImpl::updateNCharacterStream(columnIndex, x);
}

void SyncResolverImpl::updateNCharacterStream($String* columnLabel, $Reader* reader) {
	this->$CachedRowSetImpl::updateNCharacterStream(columnLabel, reader);
}

void SyncResolverImpl::updateBlob(int32_t columnIndex, $InputStream* inputStream, int64_t length) {
	this->$CachedRowSetImpl::updateBlob(columnIndex, inputStream, length);
}

void SyncResolverImpl::updateBlob($String* columnLabel, $InputStream* inputStream, int64_t length) {
	this->$CachedRowSetImpl::updateBlob(columnLabel, inputStream, length);
}

void SyncResolverImpl::updateBlob(int32_t columnIndex, $InputStream* inputStream) {
	this->$CachedRowSetImpl::updateBlob(columnIndex, inputStream);
}

void SyncResolverImpl::updateBlob($String* columnLabel, $InputStream* inputStream) {
	this->$CachedRowSetImpl::updateBlob(columnLabel, inputStream);
}

void SyncResolverImpl::updateClob(int32_t columnIndex, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::updateClob(columnIndex, reader, length);
}

void SyncResolverImpl::updateClob($String* columnLabel, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::updateClob(columnLabel, reader, length);
}

void SyncResolverImpl::updateClob(int32_t columnIndex, $Reader* reader) {
	this->$CachedRowSetImpl::updateClob(columnIndex, reader);
}

void SyncResolverImpl::updateClob($String* columnLabel, $Reader* reader) {
	this->$CachedRowSetImpl::updateClob(columnLabel, reader);
}

void SyncResolverImpl::updateNClob(int32_t columnIndex, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::updateNClob(columnIndex, reader, length);
}

void SyncResolverImpl::updateNClob($String* columnLabel, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::updateNClob(columnLabel, reader, length);
}

void SyncResolverImpl::updateNClob(int32_t columnIndex, $Reader* reader) {
	this->$CachedRowSetImpl::updateNClob(columnIndex, reader);
}

void SyncResolverImpl::updateNClob($String* columnLabel, $Reader* reader) {
	this->$CachedRowSetImpl::updateNClob(columnLabel, reader);
}

void SyncResolverImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x, int64_t length) {
	this->$CachedRowSetImpl::updateAsciiStream(columnIndex, x, length);
}

void SyncResolverImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x, int64_t length) {
	this->$CachedRowSetImpl::updateBinaryStream(columnIndex, x, length);
}

void SyncResolverImpl::updateCharacterStream(int32_t columnIndex, $Reader* x, int64_t length) {
	this->$CachedRowSetImpl::updateCharacterStream(columnIndex, x, length);
}

void SyncResolverImpl::updateCharacterStream($String* columnLabel, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::updateCharacterStream(columnLabel, reader, length);
}

void SyncResolverImpl::updateAsciiStream($String* columnLabel, $InputStream* x, int64_t length) {
	this->$CachedRowSetImpl::updateAsciiStream(columnLabel, x, length);
}

void SyncResolverImpl::updateBinaryStream($String* columnLabel, $InputStream* x, int64_t length) {
	this->$CachedRowSetImpl::updateBinaryStream(columnLabel, x, length);
}

void SyncResolverImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x) {
	this->$CachedRowSetImpl::updateBinaryStream(columnIndex, x);
}

void SyncResolverImpl::updateBinaryStream($String* columnLabel, $InputStream* x) {
	this->$CachedRowSetImpl::updateBinaryStream(columnLabel, x);
}

void SyncResolverImpl::updateCharacterStream(int32_t columnIndex, $Reader* x) {
	this->$CachedRowSetImpl::updateCharacterStream(columnIndex, x);
}

void SyncResolverImpl::updateCharacterStream($String* columnLabel, $Reader* reader) {
	this->$CachedRowSetImpl::updateCharacterStream(columnLabel, reader);
}

void SyncResolverImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x) {
	this->$CachedRowSetImpl::updateAsciiStream(columnIndex, x);
}

void SyncResolverImpl::updateAsciiStream($String* columnLabel, $InputStream* x) {
	this->$CachedRowSetImpl::updateAsciiStream(columnLabel, x);
}

void SyncResolverImpl::setURL(int32_t parameterIndex, $URL* x) {
	this->$CachedRowSetImpl::setURL(parameterIndex, x);
}

void SyncResolverImpl::setNClob(int32_t parameterIndex, $Reader* reader) {
	this->$CachedRowSetImpl::setNClob(parameterIndex, reader);
}

void SyncResolverImpl::setNClob($String* parameterName, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::setNClob(parameterName, reader, length);
}

void SyncResolverImpl::setNClob($String* parameterName, $Reader* reader) {
	this->$CachedRowSetImpl::setNClob(parameterName, reader);
}

void SyncResolverImpl::setNClob(int32_t parameterIndex, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::setNClob(parameterIndex, reader, length);
}

void SyncResolverImpl::setNClob(int32_t parameterIndex, $NClob* value) {
	this->$CachedRowSetImpl::setNClob(parameterIndex, value);
}

void SyncResolverImpl::setNString(int32_t parameterIndex, $String* value) {
	this->$CachedRowSetImpl::setNString(parameterIndex, value);
}

void SyncResolverImpl::setNString($String* parameterName, $String* value) {
	this->$CachedRowSetImpl::setNString(parameterName, value);
}

void SyncResolverImpl::setNCharacterStream(int32_t parameterIndex, $Reader* value, int64_t length) {
	this->$CachedRowSetImpl::setNCharacterStream(parameterIndex, value, length);
}

void SyncResolverImpl::setNCharacterStream($String* parameterName, $Reader* value, int64_t length) {
	this->$CachedRowSetImpl::setNCharacterStream(parameterName, value, length);
}

void SyncResolverImpl::setNCharacterStream($String* parameterName, $Reader* value) {
	this->$CachedRowSetImpl::setNCharacterStream(parameterName, value);
}

void SyncResolverImpl::setTimestamp($String* parameterName, $Timestamp* x, $Calendar* cal) {
	this->$CachedRowSetImpl::setTimestamp(parameterName, x, cal);
}

void SyncResolverImpl::setClob($String* parameterName, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::setClob(parameterName, reader, length);
}

void SyncResolverImpl::setClob($String* parameterName, $Clob* x) {
	this->$CachedRowSetImpl::setClob(parameterName, x);
}

void SyncResolverImpl::setClob($String* parameterName, $Reader* reader) {
	this->$CachedRowSetImpl::setClob(parameterName, reader);
}

void SyncResolverImpl::setDate($String* parameterName, $Date* x) {
	this->$CachedRowSetImpl::setDate(parameterName, x);
}

void SyncResolverImpl::setDate($String* parameterName, $Date* x, $Calendar* cal) {
	this->$CachedRowSetImpl::setDate(parameterName, x, cal);
}

void SyncResolverImpl::setTime($String* parameterName, $Time* x) {
	this->$CachedRowSetImpl::setTime(parameterName, x);
}

void SyncResolverImpl::setTime($String* parameterName, $Time* x, $Calendar* cal) {
	this->$CachedRowSetImpl::setTime(parameterName, x, cal);
}

void SyncResolverImpl::setClob(int32_t parameterIndex, $Reader* reader) {
	this->$CachedRowSetImpl::setClob(parameterIndex, reader);
}

void SyncResolverImpl::setClob(int32_t parameterIndex, $Reader* reader, int64_t length) {
	this->$CachedRowSetImpl::setClob(parameterIndex, reader, length);
}

void SyncResolverImpl::setBlob(int32_t parameterIndex, $InputStream* inputStream, int64_t length) {
	this->$CachedRowSetImpl::setBlob(parameterIndex, inputStream, length);
}

void SyncResolverImpl::setBlob(int32_t parameterIndex, $InputStream* inputStream) {
	this->$CachedRowSetImpl::setBlob(parameterIndex, inputStream);
}

void SyncResolverImpl::setBlob($String* parameterName, $InputStream* inputStream, int64_t length) {
	this->$CachedRowSetImpl::setBlob(parameterName, inputStream, length);
}

void SyncResolverImpl::setBlob($String* parameterName, $Blob* x) {
	this->$CachedRowSetImpl::setBlob(parameterName, x);
}

void SyncResolverImpl::setBlob($String* parameterName, $InputStream* inputStream) {
	this->$CachedRowSetImpl::setBlob(parameterName, inputStream);
}

void SyncResolverImpl::setObject($String* parameterName, Object$* x, int32_t targetSqlType, int32_t scale) {
	this->$CachedRowSetImpl::setObject(parameterName, x, targetSqlType, scale);
}

void SyncResolverImpl::setObject($String* parameterName, Object$* x, int32_t targetSqlType) {
	this->$CachedRowSetImpl::setObject(parameterName, x, targetSqlType);
}

void SyncResolverImpl::setObject($String* parameterName, Object$* x) {
	this->$CachedRowSetImpl::setObject(parameterName, x);
}

void SyncResolverImpl::setAsciiStream($String* parameterName, $InputStream* x, int32_t length) {
	this->$CachedRowSetImpl::setAsciiStream(parameterName, x, length);
}

void SyncResolverImpl::setBinaryStream($String* parameterName, $InputStream* x, int32_t length) {
	this->$CachedRowSetImpl::setBinaryStream(parameterName, x, length);
}

void SyncResolverImpl::setCharacterStream($String* parameterName, $Reader* reader, int32_t length) {
	this->$CachedRowSetImpl::setCharacterStream(parameterName, reader, length);
}

void SyncResolverImpl::setAsciiStream($String* parameterName, $InputStream* x) {
	this->$CachedRowSetImpl::setAsciiStream(parameterName, x);
}

void SyncResolverImpl::setBinaryStream($String* parameterName, $InputStream* x) {
	this->$CachedRowSetImpl::setBinaryStream(parameterName, x);
}

void SyncResolverImpl::setCharacterStream($String* parameterName, $Reader* reader) {
	this->$CachedRowSetImpl::setCharacterStream(parameterName, reader);
}

void SyncResolverImpl::setBigDecimal($String* parameterName, $BigDecimal* x) {
	this->$CachedRowSetImpl::setBigDecimal(parameterName, x);
}

void SyncResolverImpl::setString($String* parameterName, $String* x) {
	this->$CachedRowSetImpl::setString(parameterName, x);
}

void SyncResolverImpl::setBytes($String* parameterName, $bytes* x) {
	this->$CachedRowSetImpl::setBytes(parameterName, x);
}

void SyncResolverImpl::setTimestamp($String* parameterName, $Timestamp* x) {
	this->$CachedRowSetImpl::setTimestamp(parameterName, x);
}

void SyncResolverImpl::setNull($String* parameterName, int32_t sqlType) {
	this->$CachedRowSetImpl::setNull(parameterName, sqlType);
}

void SyncResolverImpl::setNull($String* parameterName, int32_t sqlType, $String* typeName) {
	this->$CachedRowSetImpl::setNull(parameterName, sqlType, typeName);
}

void SyncResolverImpl::setBoolean($String* parameterName, bool x) {
	this->$CachedRowSetImpl::setBoolean(parameterName, x);
}

void SyncResolverImpl::setByte($String* parameterName, int8_t x) {
	this->$CachedRowSetImpl::setByte(parameterName, x);
}

void SyncResolverImpl::setShort($String* parameterName, int16_t x) {
	this->$CachedRowSetImpl::setShort(parameterName, x);
}

void SyncResolverImpl::setInt($String* parameterName, int32_t x) {
	this->$CachedRowSetImpl::setInt(parameterName, x);
}

void SyncResolverImpl::setLong($String* parameterName, int64_t x) {
	this->$CachedRowSetImpl::setLong(parameterName, x);
}

void SyncResolverImpl::setFloat($String* parameterName, float x) {
	this->$CachedRowSetImpl::setFloat(parameterName, x);
}

void SyncResolverImpl::setDouble($String* parameterName, double x) {
	this->$CachedRowSetImpl::setDouble(parameterName, x);
}

$Object* SyncResolverImpl::getObject(int32_t columnIndex, $Class* type) {
	 return this->$CachedRowSetImpl::getObject(columnIndex, type);
}

$Object* SyncResolverImpl::getObject($String* columnLabel, $Class* type) {
	 return this->$CachedRowSetImpl::getObject(columnLabel, type);
}

void SyncResolverImpl::addRowSetListener($RowSetListener* listener) {
	this->$CachedRowSetImpl::addRowSetListener(listener);
}

void SyncResolverImpl::removeRowSetListener($RowSetListener* listener) {
	this->$CachedRowSetImpl::removeRowSetListener(listener);
}

$String* SyncResolverImpl::getCommand() {
	 return this->$CachedRowSetImpl::getCommand();
}

$String* SyncResolverImpl::getUrl() {
	 return this->$CachedRowSetImpl::getUrl();
}

void SyncResolverImpl::setUrl($String* url) {
	this->$CachedRowSetImpl::setUrl(url);
}

$String* SyncResolverImpl::getDataSourceName() {
	 return this->$CachedRowSetImpl::getDataSourceName();
}

void SyncResolverImpl::setDataSourceName($String* name) {
	this->$CachedRowSetImpl::setDataSourceName(name);
}

$String* SyncResolverImpl::getUsername() {
	 return this->$CachedRowSetImpl::getUsername();
}

void SyncResolverImpl::setUsername($String* name) {
	this->$CachedRowSetImpl::setUsername(name);
}

$String* SyncResolverImpl::getPassword() {
	 return this->$CachedRowSetImpl::getPassword();
}

void SyncResolverImpl::setPassword($String* pass) {
	this->$CachedRowSetImpl::setPassword(pass);
}

void SyncResolverImpl::setType(int32_t type) {
	this->$CachedRowSetImpl::setType(type);
}

int32_t SyncResolverImpl::getType() {
	 return this->$CachedRowSetImpl::getType();
}

void SyncResolverImpl::setConcurrency(int32_t concurrency) {
	this->$CachedRowSetImpl::setConcurrency(concurrency);
}

bool SyncResolverImpl::isReadOnly() {
	 return this->$CachedRowSetImpl::isReadOnly();
}

void SyncResolverImpl::setReadOnly(bool value) {
	this->$CachedRowSetImpl::setReadOnly(value);
}

int32_t SyncResolverImpl::getTransactionIsolation() {
	 return this->$CachedRowSetImpl::getTransactionIsolation();
}

void SyncResolverImpl::setTransactionIsolation(int32_t level) {
	this->$CachedRowSetImpl::setTransactionIsolation(level);
}

$Map* SyncResolverImpl::getTypeMap() {
	 return this->$CachedRowSetImpl::getTypeMap();
}

void SyncResolverImpl::setTypeMap($Map* map) {
	this->$CachedRowSetImpl::setTypeMap(map);
}

int32_t SyncResolverImpl::getMaxFieldSize() {
	 return this->$CachedRowSetImpl::getMaxFieldSize();
}

void SyncResolverImpl::setMaxFieldSize(int32_t max) {
	this->$CachedRowSetImpl::setMaxFieldSize(max);
}

int32_t SyncResolverImpl::getMaxRows() {
	 return this->$CachedRowSetImpl::getMaxRows();
}

void SyncResolverImpl::setMaxRows(int32_t max) {
	this->$CachedRowSetImpl::setMaxRows(max);
}

void SyncResolverImpl::setEscapeProcessing(bool enable) {
	this->$CachedRowSetImpl::setEscapeProcessing(enable);
}

int32_t SyncResolverImpl::getQueryTimeout() {
	 return this->$CachedRowSetImpl::getQueryTimeout();
}

void SyncResolverImpl::setQueryTimeout(int32_t seconds) {
	this->$CachedRowSetImpl::setQueryTimeout(seconds);
}

bool SyncResolverImpl::getEscapeProcessing() {
	 return this->$CachedRowSetImpl::getEscapeProcessing();
}

void SyncResolverImpl::setFetchDirection(int32_t direction) {
	this->$CachedRowSetImpl::setFetchDirection(direction);
}

int32_t SyncResolverImpl::getFetchDirection() {
	 return this->$CachedRowSetImpl::getFetchDirection();
}

void SyncResolverImpl::setFetchSize(int32_t rows) {
	this->$CachedRowSetImpl::setFetchSize(rows);
}

int32_t SyncResolverImpl::getFetchSize() {
	 return this->$CachedRowSetImpl::getFetchSize();
}

int32_t SyncResolverImpl::getConcurrency() {
	 return this->$CachedRowSetImpl::getConcurrency();
}

void SyncResolverImpl::setNull(int32_t parameterIndex, int32_t sqlType) {
	this->$CachedRowSetImpl::setNull(parameterIndex, sqlType);
}

void SyncResolverImpl::setNull(int32_t parameterIndex, int32_t sqlType, $String* typeName) {
	this->$CachedRowSetImpl::setNull(parameterIndex, sqlType, typeName);
}

void SyncResolverImpl::setBoolean(int32_t parameterIndex, bool x) {
	this->$CachedRowSetImpl::setBoolean(parameterIndex, x);
}

void SyncResolverImpl::setByte(int32_t parameterIndex, int8_t x) {
	this->$CachedRowSetImpl::setByte(parameterIndex, x);
}

void SyncResolverImpl::setShort(int32_t parameterIndex, int16_t x) {
	this->$CachedRowSetImpl::setShort(parameterIndex, x);
}

void SyncResolverImpl::setInt(int32_t parameterIndex, int32_t x) {
	this->$CachedRowSetImpl::setInt(parameterIndex, x);
}

void SyncResolverImpl::setLong(int32_t parameterIndex, int64_t x) {
	this->$CachedRowSetImpl::setLong(parameterIndex, x);
}

void SyncResolverImpl::setFloat(int32_t parameterIndex, float x) {
	this->$CachedRowSetImpl::setFloat(parameterIndex, x);
}

void SyncResolverImpl::setDouble(int32_t parameterIndex, double x) {
	this->$CachedRowSetImpl::setDouble(parameterIndex, x);
}

void SyncResolverImpl::setBigDecimal(int32_t parameterIndex, $BigDecimal* x) {
	this->$CachedRowSetImpl::setBigDecimal(parameterIndex, x);
}

void SyncResolverImpl::setString(int32_t parameterIndex, $String* x) {
	this->$CachedRowSetImpl::setString(parameterIndex, x);
}

void SyncResolverImpl::setBytes(int32_t parameterIndex, $bytes* x) {
	this->$CachedRowSetImpl::setBytes(parameterIndex, x);
}

void SyncResolverImpl::setDate(int32_t parameterIndex, $Date* x) {
	this->$CachedRowSetImpl::setDate(parameterIndex, x);
}

void SyncResolverImpl::setTime(int32_t parameterIndex, $Time* x) {
	this->$CachedRowSetImpl::setTime(parameterIndex, x);
}

void SyncResolverImpl::setTimestamp(int32_t parameterIndex, $Timestamp* x) {
	this->$CachedRowSetImpl::setTimestamp(parameterIndex, x);
}

void SyncResolverImpl::setAsciiStream(int32_t parameterIndex, $InputStream* x, int32_t length) {
	this->$CachedRowSetImpl::setAsciiStream(parameterIndex, x, length);
}

void SyncResolverImpl::setAsciiStream(int32_t parameterIndex, $InputStream* x) {
	this->$CachedRowSetImpl::setAsciiStream(parameterIndex, x);
}

void SyncResolverImpl::setBinaryStream(int32_t parameterIndex, $InputStream* x, int32_t length) {
	this->$CachedRowSetImpl::setBinaryStream(parameterIndex, x, length);
}

void SyncResolverImpl::setBinaryStream(int32_t parameterIndex, $InputStream* x) {
	this->$CachedRowSetImpl::setBinaryStream(parameterIndex, x);
}

void SyncResolverImpl::setCharacterStream(int32_t parameterIndex, $Reader* reader, int32_t length) {
	this->$CachedRowSetImpl::setCharacterStream(parameterIndex, reader, length);
}

void SyncResolverImpl::setCharacterStream(int32_t parameterIndex, $Reader* reader) {
	this->$CachedRowSetImpl::setCharacterStream(parameterIndex, reader);
}

void SyncResolverImpl::setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType, int32_t scale) {
	this->$CachedRowSetImpl::setObject(parameterIndex, x, targetSqlType, scale);
}

void SyncResolverImpl::setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType) {
	this->$CachedRowSetImpl::setObject(parameterIndex, x, targetSqlType);
}

void SyncResolverImpl::setObject(int32_t parameterIndex, Object$* x) {
	this->$CachedRowSetImpl::setObject(parameterIndex, x);
}

void SyncResolverImpl::setRef(int32_t parameterIndex, $Ref* ref) {
	this->$CachedRowSetImpl::setRef(parameterIndex, ref);
}

void SyncResolverImpl::setBlob(int32_t parameterIndex, $Blob* x) {
	this->$CachedRowSetImpl::setBlob(parameterIndex, x);
}

void SyncResolverImpl::setClob(int32_t parameterIndex, $Clob* x) {
	this->$CachedRowSetImpl::setClob(parameterIndex, x);
}

void SyncResolverImpl::setArray(int32_t parameterIndex, $1Array* array) {
	this->$CachedRowSetImpl::setArray(parameterIndex, array);
}

void SyncResolverImpl::setDate(int32_t parameterIndex, $Date* x, $Calendar* cal) {
	this->$CachedRowSetImpl::setDate(parameterIndex, x, cal);
}

void SyncResolverImpl::setTime(int32_t parameterIndex, $Time* x, $Calendar* cal) {
	this->$CachedRowSetImpl::setTime(parameterIndex, x, cal);
}

void SyncResolverImpl::setTimestamp(int32_t parameterIndex, $Timestamp* x, $Calendar* cal) {
	this->$CachedRowSetImpl::setTimestamp(parameterIndex, x, cal);
}

void SyncResolverImpl::clearParameters() {
	this->$CachedRowSetImpl::clearParameters();
}

int32_t SyncResolverImpl::hashCode() {
	 return this->$CachedRowSetImpl::hashCode();
}

bool SyncResolverImpl::equals(Object$* arg0) {
	 return this->$CachedRowSetImpl::equals(arg0);
}

$String* SyncResolverImpl::toString() {
	 return this->$CachedRowSetImpl::toString();
}

void SyncResolverImpl::finalize() {
	this->$CachedRowSetImpl::finalize();
}

void SyncResolverImpl::updateObject(int32_t arg0, Object$* arg1, $SQLType* arg2, int32_t arg3) {
	this->$CachedRowSetImpl::updateObject(arg0, arg1, arg2, arg3);
}

void SyncResolverImpl::updateObject($String* arg0, Object$* arg1, $SQLType* arg2, int32_t arg3) {
	this->$CachedRowSetImpl::updateObject(arg0, arg1, arg2, arg3);
}

void SyncResolverImpl::updateObject(int32_t arg0, Object$* arg1, $SQLType* arg2) {
	this->$CachedRowSetImpl::updateObject(arg0, arg1, arg2);
}

void SyncResolverImpl::updateObject($String* arg0, Object$* arg1, $SQLType* arg2) {
	this->$CachedRowSetImpl::updateObject(arg0, arg1, arg2);
}

void SyncResolverImpl::init$() {
	$CachedRowSetImpl::init$();
	try {
		$set(this, crsSync, $new($CachedRowSetImpl));
		$set(this, crsRes, $new($CachedRowSetImpl));
		$set(this, crw, $new($CachedRowSetWriter));
		$set(this, row, $new($CachedRowSetImpl));
		this->rowStatus = 1;
		try {
			$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
		} catch ($IOException& ioe) {
			$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
		}
	} catch ($SQLException& sqle) {
	}
}

int32_t SyncResolverImpl::getStatus() {
	return this->stats != nullptr ? $nc(($cast($Integer, $($nc(this->stats)->get(this->rowStatus - 1)))))->intValue() : $SyncResolver::NO_ROW_CONFLICT;
}

$Object* SyncResolverImpl::getConflictValue(int32_t index) {
	try {
		return $of($nc(this->crsRes)->getObject(index));
	} catch ($SQLException& sqle) {
		$throwNew($SQLException, $(sqle->getMessage()));
	} catch ($Exception& e) {
		$throwNew($SQLException, "Problem obtaining conflicted value!"_s, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

$Object* SyncResolverImpl::getConflictValue($String* columnName) {
	try {
		return $of($nc(this->crsRes)->getObject(columnName));
	} catch ($SQLException& sqle) {
		$throwNew($SQLException, $(sqle->getMessage()));
	} catch ($Exception& e) {
		$throwNew($SQLException, "Problem obtaining conflicted value!"_s, static_cast<$Throwable*>(e));
	}
	$shouldNotReachHere();
}

void SyncResolverImpl::setResolvedValue(int32_t index, Object$* obj) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($ResultSetMetaData, rsmd, $nc(this->crsSync)->getMetaData());
		if (index <= 0 || rsmd == nullptr || index > $nc(rsmd)->getColumnCount()) {
			$throwNew($SQLException, $$str({$($nc($of($($nc(this->resBundle)->handleGetObject("syncrsimpl.indexval"_s))))->toString()), $$str(index)}));
		}
		if ($nc(this->crsRes)->getObject(index) == nullptr) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("syncrsimpl.noconflict"_s))))->toString()));
		}
	} catch ($SQLException& sqle) {
		$throwNew($SQLException, $(sqle->getMessage()));
	}
	try {
		bool bool$ = true;
		bool var$0 = $nc(($($nc($of(($($nc(this->crsSync)->getObject(index)))))->toString())))->equals($($nc($of(obj))->toString()));
		if (var$0 || $nc(($($nc($of(($($nc(this->crsRes)->getObject(index)))))->toString())))->equals($($nc($of(obj))->toString()))) {
			$nc(this->crsRes)->updateNull(index);
			$nc(this->crsRes)->updateRow();
			if ($nc(this->row)->size() != 1) {
				$set(this, row, buildCachedRow());
			}
			$nc(this->row)->updateObject(index, obj);
			$nc(this->row)->updateRow();
			for (int32_t j = 1; j < $nc($($nc(this->crsRes)->getMetaData()))->getColumnCount(); ++j) {
				if ($nc(this->crsRes)->getObject(j) != nullptr) {
					bool$ = false;
					break;
				}
			}
			if (bool$) {
				try {
					writeData(this->row);
				} catch ($SyncProviderException& spe) {
					$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("syncrsimpl.syncnotpos"_s))))->toString()));
				}
			}
		} else {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("syncrsimpl.valtores"_s))))->toString()));
		}
	} catch ($SQLException& sqle) {
		$throwNew($SQLException, $(sqle->getMessage()));
	}
}

void SyncResolverImpl::writeData($CachedRowSet* row) {
	$useLocalCurrentObjectStackCache();
	$nc(this->crw)->updateResolvedConflictToDB(row, $($nc($($nc(this->crw)->getReader()))->connect(static_cast<$RowSetInternal*>(this->crsSync))));
}

$CachedRowSet* SyncResolverImpl::buildCachedRow() {
	$useLocalCurrentObjectStackCache();
	int32_t iColCount = 0;
	$var($CachedRowSetImpl, crsRow, $new($CachedRowSetImpl));
	$var($RowSetMetaDataImpl, rsmd, $new($RowSetMetaDataImpl));
	$var($RowSetMetaDataImpl, rsmdWrite, $cast($RowSetMetaDataImpl, $nc(this->crsSync)->getMetaData()));
	$var($RowSetMetaDataImpl, rsmdRow, $new($RowSetMetaDataImpl));
	iColCount = $nc(rsmdWrite)->getColumnCount();
	rsmdRow->setColumnCount(iColCount);
	for (int32_t i = 1; i <= iColCount; ++i) {
		rsmdRow->setColumnType(i, rsmdWrite->getColumnType(i));
		rsmdRow->setColumnName(i, $(rsmdWrite->getColumnName(i)));
		rsmdRow->setNullable(i, $ResultSetMetaData::columnNullableUnknown);
		try {
			rsmdRow->setCatalogName(i, $(rsmdWrite->getCatalogName(i)));
			rsmdRow->setSchemaName(i, $(rsmdWrite->getSchemaName(i)));
		} catch ($SQLException& e) {
			e->printStackTrace();
		}
	}
	crsRow->setMetaData(rsmdRow);
	crsRow->moveToInsertRow();
	for (int32_t col = 1; col <= $nc($($nc(this->crsSync)->getMetaData()))->getColumnCount(); ++col) {
		crsRow->updateObject(col, $($nc(this->crsSync)->getObject(col)));
	}
	crsRow->insertRow();
	crsRow->moveToCurrentRow();
	crsRow->absolute(1);
	crsRow->setOriginalRow();
	try {
		crsRow->setUrl($($nc(this->crsSync)->getUrl()));
	} catch ($SQLException& sqle) {
	}
	try {
		crsRow->setDataSourceName($($nc(this->crsSync)->getCommand()));
	} catch ($SQLException& sqle) {
	}
	try {
		if ($nc(this->crsSync)->getTableName() != nullptr) {
			crsRow->setTableName($($nc(this->crsSync)->getTableName()));
		}
	} catch ($SQLException& sqle) {
	}
	try {
		if ($nc(this->crsSync)->getCommand() != nullptr) {
			crsRow->setCommand($($nc(this->crsSync)->getCommand()));
		}
	} catch ($SQLException& sqle) {
	}
	try {
		crsRow->setKeyColumns($($nc(this->crsSync)->getKeyColumns()));
	} catch ($SQLException& sqle) {
	}
	return crsRow;
}

void SyncResolverImpl::setResolvedValue($String* columnName, Object$* obj) {
	$throwNew($SQLException, "Method not supported"_s);
}

void SyncResolverImpl::setCachedRowSet($CachedRowSet* crs) {
	$set(this, crsSync, $cast($CachedRowSetImpl, crs));
}

void SyncResolverImpl::setCachedRowSetResolver($CachedRowSet* crs) {
	try {
		$set(this, crsRes, $cast($CachedRowSetImpl, crs));
		$nc(this->crsRes)->afterLast();
		this->sz = $nc(this->crsRes)->size();
	} catch ($SQLException& sqle) {
	}
}

void SyncResolverImpl::setStatus($ArrayList* status) {
	$set(this, stats, status);
}

void SyncResolverImpl::setCachedRowSetWriter($CachedRowSetWriter* CRWriter) {
	$set(this, crw, CRWriter);
}

bool SyncResolverImpl::nextConflict() {
	$useLocalCurrentObjectStackCache();
	bool bool$ = false;
	$nc(this->crsSync)->setShowDeleted(true);
	while ($nc(this->crsSync)->next()) {
		$nc(this->crsRes)->previous();
		++this->rowStatus;
		if ((this->rowStatus - 1) >= $nc(this->stats)->size()) {
			bool$ = false;
			break;
		}
		if ($nc(($cast($Integer, $($nc(this->stats)->get(this->rowStatus - 1)))))->intValue() == $SyncResolver::NO_ROW_CONFLICT) {
		} else {
			bool$ = true;
			break;
		}
	}
	$nc(this->crsSync)->setShowDeleted(false);
	return bool$;
}

bool SyncResolverImpl::previousConflict() {
	return false;
}

void SyncResolverImpl::setCommand($String* cmd) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::populate($ResultSet* data) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::execute($Connection* conn) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::acceptChanges() {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::acceptChanges($Connection* con) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::restoreOriginal() {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::release() {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::undoDelete() {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::undoInsert() {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::undoUpdate() {
	$throwNew($UnsupportedOperationException);
}

$RowSet* SyncResolverImpl::createShared() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Object* SyncResolverImpl::clone() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$CachedRowSet* SyncResolverImpl::createCopy() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$CachedRowSet* SyncResolverImpl::createCopySchema() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$CachedRowSet* SyncResolverImpl::createCopyNoConstraints() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Collection* SyncResolverImpl::toCollection() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Collection* SyncResolverImpl::toCollection(int32_t column) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Collection* SyncResolverImpl::toCollection($String* column) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$SyncProvider* SyncResolverImpl::getSyncProvider() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void SyncResolverImpl::setSyncProvider($String* providerStr) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::execute() {
	$throwNew($UnsupportedOperationException);
}

bool SyncResolverImpl::next() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::internalNext() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void SyncResolverImpl::close() {
	$throwNew($UnsupportedOperationException);
}

bool SyncResolverImpl::wasNull() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$BaseRow* SyncResolverImpl::getCurrentRow() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void SyncResolverImpl::removeCurrentRow() {
	$throwNew($UnsupportedOperationException);
}

$String* SyncResolverImpl::getString(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::getBoolean(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

int8_t SyncResolverImpl::getByte(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

int16_t SyncResolverImpl::getShort(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

int32_t SyncResolverImpl::getInt(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

int64_t SyncResolverImpl::getLong(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

float SyncResolverImpl::getFloat(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

double SyncResolverImpl::getDouble(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$BigDecimal* SyncResolverImpl::getBigDecimal(int32_t columnIndex, int32_t scale) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$bytes* SyncResolverImpl::getBytes(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Date* SyncResolverImpl::getDate(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Time* SyncResolverImpl::getTime(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Timestamp* SyncResolverImpl::getTimestamp(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$InputStream* SyncResolverImpl::getAsciiStream(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$InputStream* SyncResolverImpl::getUnicodeStream(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$InputStream* SyncResolverImpl::getBinaryStream(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$String* SyncResolverImpl::getString($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::getBoolean($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

int8_t SyncResolverImpl::getByte($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

int16_t SyncResolverImpl::getShort($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

int32_t SyncResolverImpl::getInt($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

int64_t SyncResolverImpl::getLong($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

float SyncResolverImpl::getFloat($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

double SyncResolverImpl::getDouble($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$BigDecimal* SyncResolverImpl::getBigDecimal($String* columnName, int32_t scale) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$bytes* SyncResolverImpl::getBytes($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Date* SyncResolverImpl::getDate($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Time* SyncResolverImpl::getTime($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Timestamp* SyncResolverImpl::getTimestamp($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$InputStream* SyncResolverImpl::getAsciiStream($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$InputStream* SyncResolverImpl::getUnicodeStream($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$InputStream* SyncResolverImpl::getBinaryStream($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$SQLWarning* SyncResolverImpl::getWarnings() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void SyncResolverImpl::clearWarnings() {
	$throwNew($UnsupportedOperationException);
}

$String* SyncResolverImpl::getCursorName() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$ResultSetMetaData* SyncResolverImpl::getMetaData() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Object* SyncResolverImpl::getObject(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Object* SyncResolverImpl::getObject($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

int32_t SyncResolverImpl::findColumn($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Reader* SyncResolverImpl::getCharacterStream(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Reader* SyncResolverImpl::getCharacterStream($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$BigDecimal* SyncResolverImpl::getBigDecimal(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$BigDecimal* SyncResolverImpl::getBigDecimal($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

int32_t SyncResolverImpl::size() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::isBeforeFirst() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::isAfterLast() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::isFirst() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::isLast() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void SyncResolverImpl::beforeFirst() {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::afterLast() {
	$throwNew($UnsupportedOperationException);
}

bool SyncResolverImpl::first() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::internalFirst() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::last() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::internalLast() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

int32_t SyncResolverImpl::getRow() {
	return $nc(this->crsSync)->getRow();
}

bool SyncResolverImpl::absolute(int32_t row) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::relative(int32_t rows) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::previous() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::internalPrevious() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::rowUpdated() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::columnUpdated(int32_t idx) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::columnUpdated($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::rowInserted() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::rowDeleted() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void SyncResolverImpl::updateNull(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateBoolean(int32_t columnIndex, bool x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateByte(int32_t columnIndex, int8_t x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateShort(int32_t columnIndex, int16_t x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateInt(int32_t columnIndex, int32_t x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateLong(int32_t columnIndex, int64_t x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateFloat(int32_t columnIndex, float x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateDouble(int32_t columnIndex, double x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateBigDecimal(int32_t columnIndex, $BigDecimal* x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateString(int32_t columnIndex, $String* x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateBytes(int32_t columnIndex, $bytes* x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateDate(int32_t columnIndex, $Date* x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateTime(int32_t columnIndex, $Time* x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateTimestamp(int32_t columnIndex, $Timestamp* x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x, int32_t length) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x, int32_t length) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateCharacterStream(int32_t columnIndex, $Reader* x, int32_t length) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateObject(int32_t columnIndex, Object$* x, int32_t scale) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateObject(int32_t columnIndex, Object$* x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateNull($String* columnName) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateBoolean($String* columnName, bool x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateByte($String* columnName, int8_t x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateShort($String* columnName, int16_t x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateInt($String* columnName, int32_t x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateLong($String* columnName, int64_t x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateFloat($String* columnName, float x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateDouble($String* columnName, double x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateBigDecimal($String* columnName, $BigDecimal* x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateString($String* columnName, $String* x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateBytes($String* columnName, $bytes* x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateDate($String* columnName, $Date* x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateTime($String* columnName, $Time* x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateTimestamp($String* columnName, $Timestamp* x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateAsciiStream($String* columnName, $InputStream* x, int32_t length) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateBinaryStream($String* columnName, $InputStream* x, int32_t length) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateCharacterStream($String* columnName, $Reader* reader, int32_t length) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateObject($String* columnName, Object$* x, int32_t scale) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateObject($String* columnName, Object$* x) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::insertRow() {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateRow() {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::deleteRow() {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::refreshRow() {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::cancelRowUpdates() {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::moveToInsertRow() {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::moveToCurrentRow() {
	$throwNew($UnsupportedOperationException);
}

$Statement* SyncResolverImpl::getStatement() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Object* SyncResolverImpl::getObject(int32_t columnIndex, $Map* map) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Ref* SyncResolverImpl::getRef(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Blob* SyncResolverImpl::getBlob(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Clob* SyncResolverImpl::getClob(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$1Array* SyncResolverImpl::getArray(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Object* SyncResolverImpl::getObject($String* columnName, $Map* map) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Ref* SyncResolverImpl::getRef($String* colName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Blob* SyncResolverImpl::getBlob($String* colName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Clob* SyncResolverImpl::getClob($String* colName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$1Array* SyncResolverImpl::getArray($String* colName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Date* SyncResolverImpl::getDate(int32_t columnIndex, $Calendar* cal) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Date* SyncResolverImpl::getDate($String* columnName, $Calendar* cal) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Time* SyncResolverImpl::getTime(int32_t columnIndex, $Calendar* cal) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Time* SyncResolverImpl::getTime($String* columnName, $Calendar* cal) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Timestamp* SyncResolverImpl::getTimestamp(int32_t columnIndex, $Calendar* cal) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Timestamp* SyncResolverImpl::getTimestamp($String* columnName, $Calendar* cal) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$Connection* SyncResolverImpl::getConnection() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void SyncResolverImpl::setMetaData($RowSetMetaData* md) {
	$throwNew($UnsupportedOperationException);
}

$ResultSet* SyncResolverImpl::getOriginal() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$ResultSet* SyncResolverImpl::getOriginalRow() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void SyncResolverImpl::setOriginalRow() {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::setOriginal() {
	$throwNew($UnsupportedOperationException);
}

$String* SyncResolverImpl::getTableName() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void SyncResolverImpl::setTableName($String* tabName) {
	$throwNew($UnsupportedOperationException);
}

$ints* SyncResolverImpl::getKeyColumns() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void SyncResolverImpl::setKeyColumns($ints* keys) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateRef(int32_t columnIndex, $Ref* ref) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateRef($String* columnName, $Ref* ref) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateClob(int32_t columnIndex, $Clob* c) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateClob($String* columnName, $Clob* c) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateBlob(int32_t columnIndex, $Blob* b) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateBlob($String* columnName, $Blob* b) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateArray(int32_t columnIndex, $1Array* a) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::updateArray($String* columnName, $1Array* a) {
	$throwNew($UnsupportedOperationException);
}

$URL* SyncResolverImpl::getURL(int32_t columnIndex) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$URL* SyncResolverImpl::getURL($String* columnName) {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$RowSetWarning* SyncResolverImpl::getRowSetWarnings() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void SyncResolverImpl::commit() {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::rollback() {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::rollback($Savepoint* s) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::unsetMatchColumn($ints* columnIdxes) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::unsetMatchColumn($StringArray* columnIdxes) {
	$throwNew($UnsupportedOperationException);
}

$StringArray* SyncResolverImpl::getMatchColumnNames() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

$ints* SyncResolverImpl::getMatchColumnIndexes() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void SyncResolverImpl::setMatchColumn($ints* columnIdxes) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::setMatchColumn($StringArray* columnNames) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::setMatchColumn(int32_t columnIdx) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::setMatchColumn($String* columnName) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::unsetMatchColumn(int32_t columnIdx) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::unsetMatchColumn($String* columnName) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::rowSetPopulated($RowSetEvent* event, int32_t numRows) {
	$throwNew($UnsupportedOperationException);
}

void SyncResolverImpl::populate($ResultSet* data, int32_t start) {
	$throwNew($UnsupportedOperationException);
}

bool SyncResolverImpl::nextPage() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void SyncResolverImpl::setPageSize(int32_t size) {
	$throwNew($UnsupportedOperationException);
}

int32_t SyncResolverImpl::getPageSize() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

bool SyncResolverImpl::previousPage() {
	$throwNew($UnsupportedOperationException);
	$shouldNotReachHere();
}

void SyncResolverImpl::updateNCharacterStream(int32_t columnIndex, $Reader* x, int32_t length) {
	$throwNew($UnsupportedOperationException, "Operation not yet supported"_s);
}

void SyncResolverImpl::updateNCharacterStream($String* columnName, $Reader* x, int32_t length) {
	$throwNew($UnsupportedOperationException, "Operation not yet supported"_s);
}

void SyncResolverImpl::readObject($ObjectInputStream* ois) {
	$nc(ois)->defaultReadObject();
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

SyncResolverImpl::SyncResolverImpl() {
}

$Class* SyncResolverImpl::load$($String* name, bool initialize) {
	$loadClass(SyncResolverImpl, name, initialize, &_SyncResolverImpl_ClassInfo_, allocate$SyncResolverImpl);
	return class$;
}

$Class* SyncResolverImpl::class$ = nullptr;

			} // internal
		} // rowset
	} // sun
} // com
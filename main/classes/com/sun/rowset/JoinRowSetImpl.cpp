#include <com/sun/rowset/JoinRowSetImpl.h>

#include <com/sun/rowset/CachedRowSetImpl.h>
#include <com/sun/rowset/JdbcRowSetImpl.h>
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
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Calendar.h>
#include <java/util/Collection.h>
#include <java/util/Map.h>
#include <java/util/Vector.h>
#include <javax/sql/RowSet.h>
#include <javax/sql/RowSetEvent.h>
#include <javax/sql/RowSetListener.h>
#include <javax/sql/RowSetMetaData.h>
#include <javax/sql/rowset/CachedRowSet.h>
#include <javax/sql/rowset/JoinRowSet.h>
#include <javax/sql/rowset/Joinable.h>
#include <javax/sql/rowset/RowSetMetaDataImpl.h>
#include <javax/sql/rowset/RowSetWarning.h>
#include <javax/sql/rowset/WebRowSet.h>
#include <javax/sql/rowset/spi/SyncProvider.h>
#include <jcpp.h>

#undef CROSS_JOIN
#undef FULL_JOIN
#undef INNER_JOIN
#undef LEFT_OUTER_JOIN
#undef RIGHT_OUTER_JOIN

using $RowSetArray = $Array<::javax::sql::RowSet>;
using $CachedRowSetImpl = ::com::sun::rowset::CachedRowSetImpl;
using $JdbcRowSetImpl = ::com::sun::rowset::JdbcRowSetImpl;
using $JdbcRowSetResourceBundle = ::com::sun::rowset::JdbcRowSetResourceBundle;
using $WebRowSetImpl = ::com::sun::rowset::WebRowSetImpl;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $OutputStream = ::java::io::OutputStream;
using $Reader = ::java::io::Reader;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
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
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Calendar = ::java::util::Calendar;
using $Collection = ::java::util::Collection;
using $Map = ::java::util::Map;
using $Vector = ::java::util::Vector;
using $RowSet = ::javax::sql::RowSet;
using $RowSetEvent = ::javax::sql::RowSetEvent;
using $RowSetListener = ::javax::sql::RowSetListener;
using $RowSetMetaData = ::javax::sql::RowSetMetaData;
using $BaseRowSet = ::javax::sql::rowset::BaseRowSet;
using $CachedRowSet = ::javax::sql::rowset::CachedRowSet;
using $JoinRowSet = ::javax::sql::rowset::JoinRowSet;
using $Joinable = ::javax::sql::rowset::Joinable;
using $RowSetMetaDataImpl = ::javax::sql::rowset::RowSetMetaDataImpl;
using $RowSetWarning = ::javax::sql::rowset::RowSetWarning;
using $WebRowSet = ::javax::sql::rowset::WebRowSet;
using $SyncProvider = ::javax::sql::rowset::spi::SyncProvider;

namespace com {
	namespace sun {
		namespace rowset {

$CompoundAttribute _JoinRowSetImpl_MethodAnnotations_getBigDecimal27[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _JoinRowSetImpl_MethodAnnotations_getBigDecimal28[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _JoinRowSetImpl_MethodAnnotations_getUnicodeStream88[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _JoinRowSetImpl_MethodAnnotations_getUnicodeStream89[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _JoinRowSetImpl_FieldInfo_[] = {
	{"vecRowSetsInJOIN", "Ljava/util/Vector;", "Ljava/util/Vector<Lcom/sun/rowset/CachedRowSetImpl;>;", $PRIVATE, $field(JoinRowSetImpl, vecRowSetsInJOIN)},
	{"crsInternal", "Lcom/sun/rowset/CachedRowSetImpl;", nullptr, $PRIVATE, $field(JoinRowSetImpl, crsInternal)},
	{"vecJoinType", "Ljava/util/Vector;", "Ljava/util/Vector<Ljava/lang/Integer;>;", $PRIVATE, $field(JoinRowSetImpl, vecJoinType)},
	{"vecTableNames", "Ljava/util/Vector;", "Ljava/util/Vector<Ljava/lang/String;>;", $PRIVATE, $field(JoinRowSetImpl, vecTableNames)},
	{"iMatchKey", "I", nullptr, $PRIVATE, $field(JoinRowSetImpl, iMatchKey)},
	{"strMatchKey", "Ljava/lang/String;", nullptr, $PRIVATE, $field(JoinRowSetImpl, strMatchKey)},
	{"supportedJOINs", "[Z", nullptr, 0, $field(JoinRowSetImpl, supportedJOINs)},
	{"wrs", "Ljavax/sql/rowset/WebRowSet;", nullptr, $PRIVATE, $field(JoinRowSetImpl, wrs)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(JoinRowSetImpl, serialVersionUID)},
	{}
};

$MethodInfo _JoinRowSetImpl_MethodInfo_[] = {
	{"*acceptChanges", "(Ljava/sql/Connection;)V", nullptr, $PUBLIC},
	{"*clearParameters", "()V", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED},
	{"*columnUpdated", "(Ljava/lang/String;)Z", nullptr, $PUBLIC},
	{"*commit", "()V", nullptr, $PUBLIC},
	{"*createCopy", "()Ljavax/sql/rowset/CachedRowSet;", nullptr, $PUBLIC},
	{"*createCopyNoConstraints", "()Ljavax/sql/rowset/CachedRowSet;", nullptr, $PUBLIC},
	{"*createShared", "()Ljavax/sql/RowSet;", nullptr, $PUBLIC},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*getCommand", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getConcurrency", "()I", nullptr, $PUBLIC},
	{"*getDataSourceName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getEscapeProcessing", "()Z", nullptr, $PUBLIC},
	{"*getFetchDirection", "()I", nullptr, $PUBLIC},
	{"*getFetchSize", "()I", nullptr, $PUBLIC},
	{"*getHoldability", "()I", nullptr, $PUBLIC},
	{"*getMatchColumnIndexes", "()[I", nullptr, $PUBLIC},
	{"*getMatchColumnNames", "()[Ljava/lang/String;", nullptr, $PUBLIC},
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
	{"*getPageSize", "()I", nullptr, $PUBLIC},
	{"*getPassword", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getQueryTimeout", "()I", nullptr, $PUBLIC},
	{"*getRowId", "(I)Ljava/sql/RowId;", nullptr, $PUBLIC},
	{"*getRowId", "(Ljava/lang/String;)Ljava/sql/RowId;", nullptr, $PUBLIC},
	{"*getRowSetWarnings", "()Ljavax/sql/rowset/RowSetWarning;", nullptr, $PUBLIC},
	{"*getSQLXML", "(I)Ljava/sql/SQLXML;", nullptr, $PUBLIC},
	{"*getSQLXML", "(Ljava/lang/String;)Ljava/sql/SQLXML;", nullptr, $PUBLIC},
	{"*getShowDeleted", "()Z", nullptr, $PUBLIC},
	{"*getTableName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getTransactionIsolation", "()I", nullptr, $PUBLIC},
	{"*getType", "()I", nullptr, $PUBLIC},
	{"*getTypeMap", "()Ljava/util/Map;", nullptr, $PUBLIC},
	{"*getUrl", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getUsername", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(JoinRowSetImpl::*)()>(&JoinRowSetImpl::init$)), "java.sql.SQLException"},
	{"absolute", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"acceptChanges", "()V", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.spi.SyncProviderException"},
	{"addRowSet", "(Ljavax/sql/rowset/Joinable;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"addRowSet", "(Ljavax/sql/RowSet;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"addRowSet", "(Ljavax/sql/RowSet;Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"addRowSet", "([Ljavax/sql/RowSet;[I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"addRowSet", "([Ljavax/sql/RowSet;[Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"addRowSetListener", "(Ljavax/sql/RowSetListener;)V", nullptr, $PUBLIC},
	{"afterLast", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"beforeFirst", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"cancelRowUpdates", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"checkforMatchColumn", "(Ljavax/sql/rowset/Joinable;)Z", nullptr, $PRIVATE, $method(static_cast<bool(JoinRowSetImpl::*)($Joinable*)>(&JoinRowSetImpl::checkforMatchColumn)), "java.sql.SQLException"},
	{"clearWarnings", "()V", nullptr, $PUBLIC},
	{"close", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"columnUpdated", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"createCopySchema", "()Ljavax/sql/rowset/CachedRowSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"createWebRowSet", "()Ljavax/sql/rowset/WebRowSet;", nullptr, $PRIVATE, $method(static_cast<$WebRowSet*(JoinRowSetImpl::*)()>(&JoinRowSetImpl::createWebRowSet)), "java.sql.SQLException"},
	{"deleteRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"execute", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"execute", "(Ljava/sql/Connection;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"findColumn", "(Ljava/lang/String;)I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"first", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getArray", "(I)Ljava/sql/Array;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getArray", "(Ljava/lang/String;)Ljava/sql/Array;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getAsciiStream", "(I)Ljava/io/InputStream;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getAsciiStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getBigDecimal", "(II)Ljava/math/BigDecimal;", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.sql.SQLException", nullptr, _JoinRowSetImpl_MethodAnnotations_getBigDecimal27},
	{"getBigDecimal", "(Ljava/lang/String;I)Ljava/math/BigDecimal;", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.sql.SQLException", nullptr, _JoinRowSetImpl_MethodAnnotations_getBigDecimal28},
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
	{"getJoinType", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getKeyColumns", "()[I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getLong", "(I)J", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getLong", "(Ljava/lang/String;)J", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getMetaData", "()Ljava/sql/ResultSetMetaData;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getObject", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getObject", "(ILjava/util/Map;)Ljava/lang/Object;", "(ILjava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)Ljava/lang/Object;", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getObject", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getObject", "(Ljava/lang/String;Ljava/util/Map;)Ljava/lang/Object;", "(Ljava/lang/String;Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)Ljava/lang/Object;", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getOriginal", "()Ljava/sql/ResultSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getOriginalRow", "()Ljava/sql/ResultSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getRef", "(I)Ljava/sql/Ref;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getRef", "(Ljava/lang/String;)Ljava/sql/Ref;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getRow", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getRowSetNames", "()[Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getRowSets", "()Ljava/util/Collection;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getShort", "(I)S", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getShort", "(Ljava/lang/String;)S", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getStatement", "()Ljava/sql/Statement;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getString", "(I)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getString", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getSyncProvider", "()Ljavax/sql/rowset/spi/SyncProvider;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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
	{"getUnicodeStream", "(I)Ljava/io/InputStream;", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.sql.SQLException", nullptr, _JoinRowSetImpl_MethodAnnotations_getUnicodeStream88},
	{"getUnicodeStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.sql.SQLException", nullptr, _JoinRowSetImpl_MethodAnnotations_getUnicodeStream89},
	{"getWarnings", "()Ljava/sql/SQLWarning;", nullptr, $PUBLIC},
	{"getWhereClause", "()Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"initJOIN", "(Ljavax/sql/rowset/CachedRowSet;)V", nullptr, $PRIVATE, $method(static_cast<void(JoinRowSetImpl::*)($CachedRowSet*)>(&JoinRowSetImpl::initJOIN)), "java.sql.SQLException"},
	{"insertRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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
	{"*nextPage", "()Z", nullptr, $PUBLIC},
	{"*populate", "(Ljava/sql/ResultSet;)V", nullptr, $PUBLIC},
	{"*populate", "(Ljava/sql/ResultSet;I)V", nullptr, $PUBLIC},
	{"previous", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*previousPage", "()Z", nullptr, $PUBLIC},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(JoinRowSetImpl::*)($ObjectInputStream*)>(&JoinRowSetImpl::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readXml", "(Ljava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readXml", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException,java.io.IOException"},
	{"refreshRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"relative", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*release", "()V", nullptr, $PUBLIC},
	{"removeRowSetListener", "(Ljavax/sql/RowSetListener;)V", nullptr, $PUBLIC},
	{"*restoreOriginal", "()V", nullptr, $PUBLIC},
	{"*rollback", "()V", nullptr, $PUBLIC},
	{"*rollback", "(Ljava/sql/Savepoint;)V", nullptr, $PUBLIC},
	{"rowDeleted", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"rowInserted", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*rowSetPopulated", "(Ljavax/sql/RowSetEvent;I)V", nullptr, $PUBLIC},
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
	{"setJoinType", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setKeyColumns", "([I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setLong", "(Ljava/lang/String;J)V", nullptr, $PUBLIC},
	{"*setLong", "(IJ)V", nullptr, $PUBLIC},
	{"*setMatchColumn", "([I)V", nullptr, $PUBLIC},
	{"*setMatchColumn", "([Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*setMatchColumn", "(I)V", nullptr, $PUBLIC},
	{"*setMatchColumn", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
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
	{"setOriginalRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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
	{"setSyncProvider", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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
	{"size", "()I", nullptr, $PUBLIC},
	{"supportsCrossJoin", "()Z", nullptr, $PUBLIC},
	{"supportsFullJoin", "()Z", nullptr, $PUBLIC},
	{"supportsInnerJoin", "()Z", nullptr, $PUBLIC},
	{"supportsLeftOuterJoin", "()Z", nullptr, $PUBLIC},
	{"supportsRightOuterJoin", "()Z", nullptr, $PUBLIC},
	{"toCachedRowSet", "()Ljavax/sql/rowset/CachedRowSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"toCollection", "()Ljava/util/Collection;", "()Ljava/util/Collection<*>;", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"toCollection", "(I)Ljava/util/Collection;", "(I)Ljava/util/Collection<*>;", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"toCollection", "(Ljava/lang/String;)Ljava/util/Collection;", "(Ljava/lang/String;)Ljava/util/Collection<*>;", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*undoDelete", "()V", nullptr, $PUBLIC},
	{"*undoInsert", "()V", nullptr, $PUBLIC},
	{"*undoUpdate", "()V", nullptr, $PUBLIC},
	{"*unsetMatchColumn", "([I)V", nullptr, $PUBLIC},
	{"*unsetMatchColumn", "([Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*unsetMatchColumn", "(I)V", nullptr, $PUBLIC},
	{"*unsetMatchColumn", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
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
	{"writeXml", "(Ljava/sql/ResultSet;Ljava/io/Writer;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeXml", "(Ljava/io/Writer;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeXml", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException,java.io.IOException"},
	{"writeXml", "(Ljava/sql/ResultSet;Ljava/io/OutputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException,java.io.IOException"},
	{}
};

$ClassInfo _JoinRowSetImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.rowset.JoinRowSetImpl",
	"com.sun.rowset.WebRowSetImpl",
	"javax.sql.rowset.JoinRowSet",
	_JoinRowSetImpl_FieldInfo_,
	_JoinRowSetImpl_MethodInfo_
};

$Object* allocate$JoinRowSetImpl($Class* clazz) {
	return $of($alloc(JoinRowSetImpl));
}

void JoinRowSetImpl::setCommand($String* cmd) {
	this->$WebRowSetImpl::setCommand(cmd);
}

void JoinRowSetImpl::populate($ResultSet* data) {
	this->$WebRowSetImpl::populate(data);
}

void JoinRowSetImpl::acceptChanges($Connection* con) {
	this->$WebRowSetImpl::acceptChanges(con);
}

void JoinRowSetImpl::restoreOriginal() {
	this->$WebRowSetImpl::restoreOriginal();
}

void JoinRowSetImpl::release() {
	this->$WebRowSetImpl::release();
}

void JoinRowSetImpl::undoDelete() {
	this->$WebRowSetImpl::undoDelete();
}

void JoinRowSetImpl::undoInsert() {
	this->$WebRowSetImpl::undoInsert();
}

void JoinRowSetImpl::undoUpdate() {
	this->$WebRowSetImpl::undoUpdate();
}

$RowSet* JoinRowSetImpl::createShared() {
	 return this->$WebRowSetImpl::createShared();
}

$Object* JoinRowSetImpl::clone() {
	 return this->$WebRowSetImpl::clone();
}

$CachedRowSet* JoinRowSetImpl::createCopy() {
	 return this->$WebRowSetImpl::createCopy();
}

$CachedRowSet* JoinRowSetImpl::createCopyNoConstraints() {
	 return this->$WebRowSetImpl::createCopyNoConstraints();
}

bool JoinRowSetImpl::columnUpdated($String* columnName) {
	 return this->$WebRowSetImpl::columnUpdated(columnName);
}

$String* JoinRowSetImpl::getTableName() {
	 return this->$WebRowSetImpl::getTableName();
}

void JoinRowSetImpl::setTableName($String* tabName) {
	this->$WebRowSetImpl::setTableName(tabName);
}

$RowSetWarning* JoinRowSetImpl::getRowSetWarnings() {
	 return this->$WebRowSetImpl::getRowSetWarnings();
}

void JoinRowSetImpl::commit() {
	this->$WebRowSetImpl::commit();
}

void JoinRowSetImpl::rollback() {
	this->$WebRowSetImpl::rollback();
}

void JoinRowSetImpl::rollback($Savepoint* s) {
	this->$WebRowSetImpl::rollback(s);
}

void JoinRowSetImpl::unsetMatchColumn($ints* columnIdxes) {
	this->$WebRowSetImpl::unsetMatchColumn(columnIdxes);
}

void JoinRowSetImpl::unsetMatchColumn($StringArray* columnIdxes) {
	this->$WebRowSetImpl::unsetMatchColumn(columnIdxes);
}

$StringArray* JoinRowSetImpl::getMatchColumnNames() {
	 return this->$WebRowSetImpl::getMatchColumnNames();
}

$ints* JoinRowSetImpl::getMatchColumnIndexes() {
	 return this->$WebRowSetImpl::getMatchColumnIndexes();
}

void JoinRowSetImpl::setMatchColumn($ints* columnIdxes) {
	this->$WebRowSetImpl::setMatchColumn(columnIdxes);
}

void JoinRowSetImpl::setMatchColumn($StringArray* columnNames) {
	this->$WebRowSetImpl::setMatchColumn(columnNames);
}

void JoinRowSetImpl::setMatchColumn(int32_t columnIdx) {
	this->$WebRowSetImpl::setMatchColumn(columnIdx);
}

void JoinRowSetImpl::setMatchColumn($String* columnName) {
	this->$WebRowSetImpl::setMatchColumn(columnName);
}

void JoinRowSetImpl::unsetMatchColumn(int32_t columnIdx) {
	this->$WebRowSetImpl::unsetMatchColumn(columnIdx);
}

void JoinRowSetImpl::unsetMatchColumn($String* columnName) {
	this->$WebRowSetImpl::unsetMatchColumn(columnName);
}

void JoinRowSetImpl::rowSetPopulated($RowSetEvent* event, int32_t numRows) {
	this->$WebRowSetImpl::rowSetPopulated(event, numRows);
}

void JoinRowSetImpl::populate($ResultSet* data, int32_t start) {
	this->$WebRowSetImpl::populate(data, start);
}

bool JoinRowSetImpl::nextPage() {
	 return this->$WebRowSetImpl::nextPage();
}

void JoinRowSetImpl::setPageSize(int32_t size) {
	this->$WebRowSetImpl::setPageSize(size);
}

int32_t JoinRowSetImpl::getPageSize() {
	 return this->$WebRowSetImpl::getPageSize();
}

bool JoinRowSetImpl::previousPage() {
	 return this->$WebRowSetImpl::previousPage();
}

$SQLXML* JoinRowSetImpl::getSQLXML(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getSQLXML(columnIndex);
}

$SQLXML* JoinRowSetImpl::getSQLXML($String* colName) {
	 return this->$WebRowSetImpl::getSQLXML(colName);
}

$RowId* JoinRowSetImpl::getRowId(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getRowId(columnIndex);
}

$RowId* JoinRowSetImpl::getRowId($String* columnName) {
	 return this->$WebRowSetImpl::getRowId(columnName);
}

void JoinRowSetImpl::updateRowId(int32_t columnIndex, $RowId* x) {
	this->$WebRowSetImpl::updateRowId(columnIndex, x);
}

void JoinRowSetImpl::updateRowId($String* columnName, $RowId* x) {
	this->$WebRowSetImpl::updateRowId(columnName, x);
}

int32_t JoinRowSetImpl::getHoldability() {
	 return this->$WebRowSetImpl::getHoldability();
}

bool JoinRowSetImpl::isClosed() {
	 return this->$WebRowSetImpl::isClosed();
}

void JoinRowSetImpl::updateNString(int32_t columnIndex, $String* nString) {
	this->$WebRowSetImpl::updateNString(columnIndex, nString);
}

void JoinRowSetImpl::updateNString($String* columnName, $String* nString) {
	this->$WebRowSetImpl::updateNString(columnName, nString);
}

void JoinRowSetImpl::updateNClob(int32_t columnIndex, $NClob* nClob) {
	this->$WebRowSetImpl::updateNClob(columnIndex, nClob);
}

void JoinRowSetImpl::updateNClob($String* columnName, $NClob* nClob) {
	this->$WebRowSetImpl::updateNClob(columnName, nClob);
}

$NClob* JoinRowSetImpl::getNClob(int32_t i) {
	 return this->$WebRowSetImpl::getNClob(i);
}

$NClob* JoinRowSetImpl::getNClob($String* colName) {
	 return this->$WebRowSetImpl::getNClob(colName);
}

$Object* JoinRowSetImpl::unwrap($Class* iface) {
	 return this->$WebRowSetImpl::unwrap(iface);
}

bool JoinRowSetImpl::isWrapperFor($Class* interfaces) {
	 return this->$WebRowSetImpl::isWrapperFor(interfaces);
}

void JoinRowSetImpl::setSQLXML(int32_t parameterIndex, $SQLXML* xmlObject) {
	this->$WebRowSetImpl::setSQLXML(parameterIndex, xmlObject);
}

void JoinRowSetImpl::setSQLXML($String* parameterName, $SQLXML* xmlObject) {
	this->$WebRowSetImpl::setSQLXML(parameterName, xmlObject);
}

void JoinRowSetImpl::setRowId(int32_t parameterIndex, $RowId* x) {
	this->$WebRowSetImpl::setRowId(parameterIndex, x);
}

void JoinRowSetImpl::setRowId($String* parameterName, $RowId* x) {
	this->$WebRowSetImpl::setRowId(parameterName, x);
}

void JoinRowSetImpl::setNCharacterStream(int32_t parameterIndex, $Reader* value) {
	this->$WebRowSetImpl::setNCharacterStream(parameterIndex, value);
}

void JoinRowSetImpl::setNClob($String* parameterName, $NClob* value) {
	this->$WebRowSetImpl::setNClob(parameterName, value);
}

$Reader* JoinRowSetImpl::getNCharacterStream(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getNCharacterStream(columnIndex);
}

$Reader* JoinRowSetImpl::getNCharacterStream($String* columnName) {
	 return this->$WebRowSetImpl::getNCharacterStream(columnName);
}

void JoinRowSetImpl::updateSQLXML(int32_t columnIndex, $SQLXML* xmlObject) {
	this->$WebRowSetImpl::updateSQLXML(columnIndex, xmlObject);
}

void JoinRowSetImpl::updateSQLXML($String* columnName, $SQLXML* xmlObject) {
	this->$WebRowSetImpl::updateSQLXML(columnName, xmlObject);
}

$String* JoinRowSetImpl::getNString(int32_t columnIndex) {
	 return this->$WebRowSetImpl::getNString(columnIndex);
}

$String* JoinRowSetImpl::getNString($String* columnName) {
	 return this->$WebRowSetImpl::getNString(columnName);
}

void JoinRowSetImpl::updateNCharacterStream(int32_t columnIndex, $Reader* x, int64_t length) {
	this->$WebRowSetImpl::updateNCharacterStream(columnIndex, x, length);
}

void JoinRowSetImpl::updateNCharacterStream($String* columnName, $Reader* x, int64_t length) {
	this->$WebRowSetImpl::updateNCharacterStream(columnName, x, length);
}

void JoinRowSetImpl::updateNCharacterStream(int32_t columnIndex, $Reader* x) {
	this->$WebRowSetImpl::updateNCharacterStream(columnIndex, x);
}

void JoinRowSetImpl::updateNCharacterStream($String* columnLabel, $Reader* reader) {
	this->$WebRowSetImpl::updateNCharacterStream(columnLabel, reader);
}

void JoinRowSetImpl::updateBlob(int32_t columnIndex, $InputStream* inputStream, int64_t length) {
	this->$WebRowSetImpl::updateBlob(columnIndex, inputStream, length);
}

void JoinRowSetImpl::updateBlob($String* columnLabel, $InputStream* inputStream, int64_t length) {
	this->$WebRowSetImpl::updateBlob(columnLabel, inputStream, length);
}

void JoinRowSetImpl::updateBlob(int32_t columnIndex, $InputStream* inputStream) {
	this->$WebRowSetImpl::updateBlob(columnIndex, inputStream);
}

void JoinRowSetImpl::updateBlob($String* columnLabel, $InputStream* inputStream) {
	this->$WebRowSetImpl::updateBlob(columnLabel, inputStream);
}

void JoinRowSetImpl::updateClob(int32_t columnIndex, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::updateClob(columnIndex, reader, length);
}

void JoinRowSetImpl::updateClob($String* columnLabel, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::updateClob(columnLabel, reader, length);
}

void JoinRowSetImpl::updateClob(int32_t columnIndex, $Reader* reader) {
	this->$WebRowSetImpl::updateClob(columnIndex, reader);
}

void JoinRowSetImpl::updateClob($String* columnLabel, $Reader* reader) {
	this->$WebRowSetImpl::updateClob(columnLabel, reader);
}

void JoinRowSetImpl::updateNClob(int32_t columnIndex, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::updateNClob(columnIndex, reader, length);
}

void JoinRowSetImpl::updateNClob($String* columnLabel, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::updateNClob(columnLabel, reader, length);
}

void JoinRowSetImpl::updateNClob(int32_t columnIndex, $Reader* reader) {
	this->$WebRowSetImpl::updateNClob(columnIndex, reader);
}

void JoinRowSetImpl::updateNClob($String* columnLabel, $Reader* reader) {
	this->$WebRowSetImpl::updateNClob(columnLabel, reader);
}

void JoinRowSetImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x, int64_t length) {
	this->$WebRowSetImpl::updateAsciiStream(columnIndex, x, length);
}

void JoinRowSetImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x, int64_t length) {
	this->$WebRowSetImpl::updateBinaryStream(columnIndex, x, length);
}

void JoinRowSetImpl::updateCharacterStream(int32_t columnIndex, $Reader* x, int64_t length) {
	this->$WebRowSetImpl::updateCharacterStream(columnIndex, x, length);
}

void JoinRowSetImpl::updateCharacterStream($String* columnLabel, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::updateCharacterStream(columnLabel, reader, length);
}

void JoinRowSetImpl::updateAsciiStream($String* columnLabel, $InputStream* x, int64_t length) {
	this->$WebRowSetImpl::updateAsciiStream(columnLabel, x, length);
}

void JoinRowSetImpl::updateBinaryStream($String* columnLabel, $InputStream* x, int64_t length) {
	this->$WebRowSetImpl::updateBinaryStream(columnLabel, x, length);
}

void JoinRowSetImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x) {
	this->$WebRowSetImpl::updateBinaryStream(columnIndex, x);
}

void JoinRowSetImpl::updateBinaryStream($String* columnLabel, $InputStream* x) {
	this->$WebRowSetImpl::updateBinaryStream(columnLabel, x);
}

void JoinRowSetImpl::updateCharacterStream(int32_t columnIndex, $Reader* x) {
	this->$WebRowSetImpl::updateCharacterStream(columnIndex, x);
}

void JoinRowSetImpl::updateCharacterStream($String* columnLabel, $Reader* reader) {
	this->$WebRowSetImpl::updateCharacterStream(columnLabel, reader);
}

void JoinRowSetImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x) {
	this->$WebRowSetImpl::updateAsciiStream(columnIndex, x);
}

void JoinRowSetImpl::updateAsciiStream($String* columnLabel, $InputStream* x) {
	this->$WebRowSetImpl::updateAsciiStream(columnLabel, x);
}

void JoinRowSetImpl::setURL(int32_t parameterIndex, $URL* x) {
	this->$WebRowSetImpl::setURL(parameterIndex, x);
}

void JoinRowSetImpl::setNClob(int32_t parameterIndex, $Reader* reader) {
	this->$WebRowSetImpl::setNClob(parameterIndex, reader);
}

void JoinRowSetImpl::setNClob($String* parameterName, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::setNClob(parameterName, reader, length);
}

void JoinRowSetImpl::setNClob($String* parameterName, $Reader* reader) {
	this->$WebRowSetImpl::setNClob(parameterName, reader);
}

void JoinRowSetImpl::setNClob(int32_t parameterIndex, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::setNClob(parameterIndex, reader, length);
}

void JoinRowSetImpl::setNClob(int32_t parameterIndex, $NClob* value) {
	this->$WebRowSetImpl::setNClob(parameterIndex, value);
}

void JoinRowSetImpl::setNString(int32_t parameterIndex, $String* value) {
	this->$WebRowSetImpl::setNString(parameterIndex, value);
}

void JoinRowSetImpl::setNString($String* parameterName, $String* value) {
	this->$WebRowSetImpl::setNString(parameterName, value);
}

void JoinRowSetImpl::setNCharacterStream(int32_t parameterIndex, $Reader* value, int64_t length) {
	this->$WebRowSetImpl::setNCharacterStream(parameterIndex, value, length);
}

void JoinRowSetImpl::setNCharacterStream($String* parameterName, $Reader* value, int64_t length) {
	this->$WebRowSetImpl::setNCharacterStream(parameterName, value, length);
}

void JoinRowSetImpl::setNCharacterStream($String* parameterName, $Reader* value) {
	this->$WebRowSetImpl::setNCharacterStream(parameterName, value);
}

void JoinRowSetImpl::setTimestamp($String* parameterName, $Timestamp* x, $Calendar* cal) {
	this->$WebRowSetImpl::setTimestamp(parameterName, x, cal);
}

void JoinRowSetImpl::setClob($String* parameterName, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::setClob(parameterName, reader, length);
}

void JoinRowSetImpl::setClob($String* parameterName, $Clob* x) {
	this->$WebRowSetImpl::setClob(parameterName, x);
}

void JoinRowSetImpl::setClob($String* parameterName, $Reader* reader) {
	this->$WebRowSetImpl::setClob(parameterName, reader);
}

void JoinRowSetImpl::setDate($String* parameterName, $Date* x) {
	this->$WebRowSetImpl::setDate(parameterName, x);
}

void JoinRowSetImpl::setDate($String* parameterName, $Date* x, $Calendar* cal) {
	this->$WebRowSetImpl::setDate(parameterName, x, cal);
}

void JoinRowSetImpl::setTime($String* parameterName, $Time* x) {
	this->$WebRowSetImpl::setTime(parameterName, x);
}

void JoinRowSetImpl::setTime($String* parameterName, $Time* x, $Calendar* cal) {
	this->$WebRowSetImpl::setTime(parameterName, x, cal);
}

void JoinRowSetImpl::setClob(int32_t parameterIndex, $Reader* reader) {
	this->$WebRowSetImpl::setClob(parameterIndex, reader);
}

void JoinRowSetImpl::setClob(int32_t parameterIndex, $Reader* reader, int64_t length) {
	this->$WebRowSetImpl::setClob(parameterIndex, reader, length);
}

void JoinRowSetImpl::setBlob(int32_t parameterIndex, $InputStream* inputStream, int64_t length) {
	this->$WebRowSetImpl::setBlob(parameterIndex, inputStream, length);
}

void JoinRowSetImpl::setBlob(int32_t parameterIndex, $InputStream* inputStream) {
	this->$WebRowSetImpl::setBlob(parameterIndex, inputStream);
}

void JoinRowSetImpl::setBlob($String* parameterName, $InputStream* inputStream, int64_t length) {
	this->$WebRowSetImpl::setBlob(parameterName, inputStream, length);
}

void JoinRowSetImpl::setBlob($String* parameterName, $Blob* x) {
	this->$WebRowSetImpl::setBlob(parameterName, x);
}

void JoinRowSetImpl::setBlob($String* parameterName, $InputStream* inputStream) {
	this->$WebRowSetImpl::setBlob(parameterName, inputStream);
}

void JoinRowSetImpl::setObject($String* parameterName, Object$* x, int32_t targetSqlType, int32_t scale) {
	this->$WebRowSetImpl::setObject(parameterName, x, targetSqlType, scale);
}

void JoinRowSetImpl::setObject($String* parameterName, Object$* x, int32_t targetSqlType) {
	this->$WebRowSetImpl::setObject(parameterName, x, targetSqlType);
}

void JoinRowSetImpl::setObject($String* parameterName, Object$* x) {
	this->$WebRowSetImpl::setObject(parameterName, x);
}

void JoinRowSetImpl::setAsciiStream($String* parameterName, $InputStream* x, int32_t length) {
	this->$WebRowSetImpl::setAsciiStream(parameterName, x, length);
}

void JoinRowSetImpl::setBinaryStream($String* parameterName, $InputStream* x, int32_t length) {
	this->$WebRowSetImpl::setBinaryStream(parameterName, x, length);
}

void JoinRowSetImpl::setCharacterStream($String* parameterName, $Reader* reader, int32_t length) {
	this->$WebRowSetImpl::setCharacterStream(parameterName, reader, length);
}

void JoinRowSetImpl::setAsciiStream($String* parameterName, $InputStream* x) {
	this->$WebRowSetImpl::setAsciiStream(parameterName, x);
}

void JoinRowSetImpl::setBinaryStream($String* parameterName, $InputStream* x) {
	this->$WebRowSetImpl::setBinaryStream(parameterName, x);
}

void JoinRowSetImpl::setCharacterStream($String* parameterName, $Reader* reader) {
	this->$WebRowSetImpl::setCharacterStream(parameterName, reader);
}

void JoinRowSetImpl::setBigDecimal($String* parameterName, $BigDecimal* x) {
	this->$WebRowSetImpl::setBigDecimal(parameterName, x);
}

void JoinRowSetImpl::setString($String* parameterName, $String* x) {
	this->$WebRowSetImpl::setString(parameterName, x);
}

void JoinRowSetImpl::setBytes($String* parameterName, $bytes* x) {
	this->$WebRowSetImpl::setBytes(parameterName, x);
}

void JoinRowSetImpl::setTimestamp($String* parameterName, $Timestamp* x) {
	this->$WebRowSetImpl::setTimestamp(parameterName, x);
}

void JoinRowSetImpl::setNull($String* parameterName, int32_t sqlType) {
	this->$WebRowSetImpl::setNull(parameterName, sqlType);
}

void JoinRowSetImpl::setNull($String* parameterName, int32_t sqlType, $String* typeName) {
	this->$WebRowSetImpl::setNull(parameterName, sqlType, typeName);
}

void JoinRowSetImpl::setBoolean($String* parameterName, bool x) {
	this->$WebRowSetImpl::setBoolean(parameterName, x);
}

void JoinRowSetImpl::setByte($String* parameterName, int8_t x) {
	this->$WebRowSetImpl::setByte(parameterName, x);
}

void JoinRowSetImpl::setShort($String* parameterName, int16_t x) {
	this->$WebRowSetImpl::setShort(parameterName, x);
}

void JoinRowSetImpl::setInt($String* parameterName, int32_t x) {
	this->$WebRowSetImpl::setInt(parameterName, x);
}

void JoinRowSetImpl::setLong($String* parameterName, int64_t x) {
	this->$WebRowSetImpl::setLong(parameterName, x);
}

void JoinRowSetImpl::setFloat($String* parameterName, float x) {
	this->$WebRowSetImpl::setFloat(parameterName, x);
}

void JoinRowSetImpl::setDouble($String* parameterName, double x) {
	this->$WebRowSetImpl::setDouble(parameterName, x);
}

$Object* JoinRowSetImpl::getObject(int32_t columnIndex, $Class* type) {
	 return this->$WebRowSetImpl::getObject(columnIndex, type);
}

$Object* JoinRowSetImpl::getObject($String* columnLabel, $Class* type) {
	 return this->$WebRowSetImpl::getObject(columnLabel, type);
}

$String* JoinRowSetImpl::getCommand() {
	 return this->$WebRowSetImpl::getCommand();
}

$String* JoinRowSetImpl::getUrl() {
	 return this->$WebRowSetImpl::getUrl();
}

void JoinRowSetImpl::setUrl($String* url) {
	this->$WebRowSetImpl::setUrl(url);
}

$String* JoinRowSetImpl::getDataSourceName() {
	 return this->$WebRowSetImpl::getDataSourceName();
}

void JoinRowSetImpl::setDataSourceName($String* name) {
	this->$WebRowSetImpl::setDataSourceName(name);
}

$String* JoinRowSetImpl::getUsername() {
	 return this->$WebRowSetImpl::getUsername();
}

void JoinRowSetImpl::setUsername($String* name) {
	this->$WebRowSetImpl::setUsername(name);
}

$String* JoinRowSetImpl::getPassword() {
	 return this->$WebRowSetImpl::getPassword();
}

void JoinRowSetImpl::setPassword($String* pass) {
	this->$WebRowSetImpl::setPassword(pass);
}

void JoinRowSetImpl::setType(int32_t type) {
	this->$WebRowSetImpl::setType(type);
}

int32_t JoinRowSetImpl::getType() {
	 return this->$WebRowSetImpl::getType();
}

void JoinRowSetImpl::setConcurrency(int32_t concurrency) {
	this->$WebRowSetImpl::setConcurrency(concurrency);
}

bool JoinRowSetImpl::isReadOnly() {
	 return this->$WebRowSetImpl::isReadOnly();
}

void JoinRowSetImpl::setReadOnly(bool value) {
	this->$WebRowSetImpl::setReadOnly(value);
}

int32_t JoinRowSetImpl::getTransactionIsolation() {
	 return this->$WebRowSetImpl::getTransactionIsolation();
}

void JoinRowSetImpl::setTransactionIsolation(int32_t level) {
	this->$WebRowSetImpl::setTransactionIsolation(level);
}

$Map* JoinRowSetImpl::getTypeMap() {
	 return this->$WebRowSetImpl::getTypeMap();
}

void JoinRowSetImpl::setTypeMap($Map* map) {
	this->$WebRowSetImpl::setTypeMap(map);
}

int32_t JoinRowSetImpl::getMaxFieldSize() {
	 return this->$WebRowSetImpl::getMaxFieldSize();
}

void JoinRowSetImpl::setMaxFieldSize(int32_t max) {
	this->$WebRowSetImpl::setMaxFieldSize(max);
}

int32_t JoinRowSetImpl::getMaxRows() {
	 return this->$WebRowSetImpl::getMaxRows();
}

void JoinRowSetImpl::setMaxRows(int32_t max) {
	this->$WebRowSetImpl::setMaxRows(max);
}

void JoinRowSetImpl::setEscapeProcessing(bool enable) {
	this->$WebRowSetImpl::setEscapeProcessing(enable);
}

int32_t JoinRowSetImpl::getQueryTimeout() {
	 return this->$WebRowSetImpl::getQueryTimeout();
}

void JoinRowSetImpl::setQueryTimeout(int32_t seconds) {
	this->$WebRowSetImpl::setQueryTimeout(seconds);
}

bool JoinRowSetImpl::getShowDeleted() {
	 return this->$WebRowSetImpl::getShowDeleted();
}

void JoinRowSetImpl::setShowDeleted(bool value) {
	this->$WebRowSetImpl::setShowDeleted(value);
}

bool JoinRowSetImpl::getEscapeProcessing() {
	 return this->$WebRowSetImpl::getEscapeProcessing();
}

void JoinRowSetImpl::setFetchDirection(int32_t direction) {
	this->$WebRowSetImpl::setFetchDirection(direction);
}

int32_t JoinRowSetImpl::getFetchDirection() {
	 return this->$WebRowSetImpl::getFetchDirection();
}

void JoinRowSetImpl::setFetchSize(int32_t rows) {
	this->$WebRowSetImpl::setFetchSize(rows);
}

int32_t JoinRowSetImpl::getFetchSize() {
	 return this->$WebRowSetImpl::getFetchSize();
}

int32_t JoinRowSetImpl::getConcurrency() {
	 return this->$WebRowSetImpl::getConcurrency();
}

void JoinRowSetImpl::setNull(int32_t parameterIndex, int32_t sqlType) {
	this->$WebRowSetImpl::setNull(parameterIndex, sqlType);
}

void JoinRowSetImpl::setNull(int32_t parameterIndex, int32_t sqlType, $String* typeName) {
	this->$WebRowSetImpl::setNull(parameterIndex, sqlType, typeName);
}

void JoinRowSetImpl::setBoolean(int32_t parameterIndex, bool x) {
	this->$WebRowSetImpl::setBoolean(parameterIndex, x);
}

void JoinRowSetImpl::setByte(int32_t parameterIndex, int8_t x) {
	this->$WebRowSetImpl::setByte(parameterIndex, x);
}

void JoinRowSetImpl::setShort(int32_t parameterIndex, int16_t x) {
	this->$WebRowSetImpl::setShort(parameterIndex, x);
}

void JoinRowSetImpl::setInt(int32_t parameterIndex, int32_t x) {
	this->$WebRowSetImpl::setInt(parameterIndex, x);
}

void JoinRowSetImpl::setLong(int32_t parameterIndex, int64_t x) {
	this->$WebRowSetImpl::setLong(parameterIndex, x);
}

void JoinRowSetImpl::setFloat(int32_t parameterIndex, float x) {
	this->$WebRowSetImpl::setFloat(parameterIndex, x);
}

void JoinRowSetImpl::setDouble(int32_t parameterIndex, double x) {
	this->$WebRowSetImpl::setDouble(parameterIndex, x);
}

void JoinRowSetImpl::setBigDecimal(int32_t parameterIndex, $BigDecimal* x) {
	this->$WebRowSetImpl::setBigDecimal(parameterIndex, x);
}

void JoinRowSetImpl::setString(int32_t parameterIndex, $String* x) {
	this->$WebRowSetImpl::setString(parameterIndex, x);
}

void JoinRowSetImpl::setBytes(int32_t parameterIndex, $bytes* x) {
	this->$WebRowSetImpl::setBytes(parameterIndex, x);
}

void JoinRowSetImpl::setDate(int32_t parameterIndex, $Date* x) {
	this->$WebRowSetImpl::setDate(parameterIndex, x);
}

void JoinRowSetImpl::setTime(int32_t parameterIndex, $Time* x) {
	this->$WebRowSetImpl::setTime(parameterIndex, x);
}

void JoinRowSetImpl::setTimestamp(int32_t parameterIndex, $Timestamp* x) {
	this->$WebRowSetImpl::setTimestamp(parameterIndex, x);
}

void JoinRowSetImpl::setAsciiStream(int32_t parameterIndex, $InputStream* x, int32_t length) {
	this->$WebRowSetImpl::setAsciiStream(parameterIndex, x, length);
}

void JoinRowSetImpl::setAsciiStream(int32_t parameterIndex, $InputStream* x) {
	this->$WebRowSetImpl::setAsciiStream(parameterIndex, x);
}

void JoinRowSetImpl::setBinaryStream(int32_t parameterIndex, $InputStream* x, int32_t length) {
	this->$WebRowSetImpl::setBinaryStream(parameterIndex, x, length);
}

void JoinRowSetImpl::setBinaryStream(int32_t parameterIndex, $InputStream* x) {
	this->$WebRowSetImpl::setBinaryStream(parameterIndex, x);
}

void JoinRowSetImpl::setCharacterStream(int32_t parameterIndex, $Reader* reader, int32_t length) {
	this->$WebRowSetImpl::setCharacterStream(parameterIndex, reader, length);
}

void JoinRowSetImpl::setCharacterStream(int32_t parameterIndex, $Reader* reader) {
	this->$WebRowSetImpl::setCharacterStream(parameterIndex, reader);
}

void JoinRowSetImpl::setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType, int32_t scale) {
	this->$WebRowSetImpl::setObject(parameterIndex, x, targetSqlType, scale);
}

void JoinRowSetImpl::setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType) {
	this->$WebRowSetImpl::setObject(parameterIndex, x, targetSqlType);
}

void JoinRowSetImpl::setObject(int32_t parameterIndex, Object$* x) {
	this->$WebRowSetImpl::setObject(parameterIndex, x);
}

void JoinRowSetImpl::setRef(int32_t parameterIndex, $Ref* ref) {
	this->$WebRowSetImpl::setRef(parameterIndex, ref);
}

void JoinRowSetImpl::setBlob(int32_t parameterIndex, $Blob* x) {
	this->$WebRowSetImpl::setBlob(parameterIndex, x);
}

void JoinRowSetImpl::setClob(int32_t parameterIndex, $Clob* x) {
	this->$WebRowSetImpl::setClob(parameterIndex, x);
}

void JoinRowSetImpl::setArray(int32_t parameterIndex, $1Array* array) {
	this->$WebRowSetImpl::setArray(parameterIndex, array);
}

void JoinRowSetImpl::setDate(int32_t parameterIndex, $Date* x, $Calendar* cal) {
	this->$WebRowSetImpl::setDate(parameterIndex, x, cal);
}

void JoinRowSetImpl::setTime(int32_t parameterIndex, $Time* x, $Calendar* cal) {
	this->$WebRowSetImpl::setTime(parameterIndex, x, cal);
}

void JoinRowSetImpl::setTimestamp(int32_t parameterIndex, $Timestamp* x, $Calendar* cal) {
	this->$WebRowSetImpl::setTimestamp(parameterIndex, x, cal);
}

void JoinRowSetImpl::clearParameters() {
	this->$WebRowSetImpl::clearParameters();
}

int32_t JoinRowSetImpl::hashCode() {
	 return this->$WebRowSetImpl::hashCode();
}

bool JoinRowSetImpl::equals(Object$* arg0) {
	 return this->$WebRowSetImpl::equals(arg0);
}

$String* JoinRowSetImpl::toString() {
	 return this->$WebRowSetImpl::toString();
}

void JoinRowSetImpl::finalize() {
	this->$WebRowSetImpl::finalize();
}

void JoinRowSetImpl::updateObject(int32_t arg0, Object$* arg1, $SQLType* arg2, int32_t arg3) {
	this->$WebRowSetImpl::updateObject(arg0, arg1, arg2, arg3);
}

void JoinRowSetImpl::updateObject($String* arg0, Object$* arg1, $SQLType* arg2, int32_t arg3) {
	this->$WebRowSetImpl::updateObject(arg0, arg1, arg2, arg3);
}

void JoinRowSetImpl::updateObject(int32_t arg0, Object$* arg1, $SQLType* arg2) {
	this->$WebRowSetImpl::updateObject(arg0, arg1, arg2);
}

void JoinRowSetImpl::updateObject($String* arg0, Object$* arg1, $SQLType* arg2) {
	this->$WebRowSetImpl::updateObject(arg0, arg1, arg2);
}

void JoinRowSetImpl::init$() {
	$WebRowSetImpl::init$();
	$set(this, vecRowSetsInJOIN, $new($Vector));
	$set(this, crsInternal, $new($CachedRowSetImpl));
	$set(this, vecJoinType, $new($Vector));
	$set(this, vecTableNames, $new($Vector));
	this->iMatchKey = -1;
	$set(this, strMatchKey, nullptr);
	$set(this, supportedJOINs, $new($booleans, {
		false,
		true,
		false,
		false,
		false
	}));
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

void JoinRowSetImpl::addRowSet($Joinable* rowset) {
	$useLocalCurrentObjectStackCache();
	bool boolColId = false;
	bool boolColName = false;
	boolColId = false;
	boolColName = false;
	$var($CachedRowSetImpl, cRowset, nullptr);
	if (!($instanceOf($RowSet, rowset))) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("joinrowsetimpl.notinstance"_s))))->toString()));
	}
	if ($instanceOf($JdbcRowSetImpl, rowset)) {
		$assign(cRowset, $new($CachedRowSetImpl));
		cRowset->populate($cast($RowSet, rowset));
		if (cRowset->size() == 0) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("joinrowsetimpl.emptyrowset"_s))))->toString()));
		}
		try {
			int32_t matchColumnCount = 0;
			for (int32_t i = 0; i < $nc($($nc(rowset)->getMatchColumnIndexes()))->length; ++i) {
				if ($nc($(rowset->getMatchColumnIndexes()))->get(i) != -1) {
					++matchColumnCount;
				} else {
					break;
				}
			}
			$var($ints, pCol, $new($ints, matchColumnCount));
			for (int32_t i = 0; i < matchColumnCount; ++i) {
				pCol->set(i, $nc($($nc(rowset)->getMatchColumnIndexes()))->get(i));
			}
			cRowset->setMatchColumn(pCol);
		} catch ($SQLException& sqle) {
		}
	} else {
		$assign(cRowset, $cast($CachedRowSetImpl, rowset));
		if ($nc(cRowset)->size() == 0) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("joinrowsetimpl.emptyrowset"_s))))->toString()));
		}
	}
	try {
		this->iMatchKey = $nc(($($nc(cRowset)->getMatchColumnIndexes())))->get(0);
	} catch ($SQLException& sqle) {
		boolColId = true;
	}
	try {
		$set(this, strMatchKey, $nc(($($nc(cRowset)->getMatchColumnNames())))->get(0));
	} catch ($SQLException& sqle) {
		boolColName = true;
	}
	if (boolColId && boolColName) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("joinrowsetimpl.matchnotset"_s))))->toString()));
	} else if (boolColId) {
		$var($ArrayList, indices, $new($ArrayList));
		for (int32_t i = 0; i < $nc($($nc(cRowset)->getMatchColumnNames()))->length; ++i) {
			if (($set(this, strMatchKey, $nc(($(cRowset->getMatchColumnNames())))->get(i))) != nullptr) {
				this->iMatchKey = cRowset->findColumn(this->strMatchKey);
				indices->add($($Integer::valueOf(this->iMatchKey)));
			} else {
				break;
			}
		}
		$var($ints, indexes, $new($ints, indices->size()));
		for (int32_t i = 0; i < indices->size(); ++i) {
			indexes->set(i, $nc(($cast($Integer, $(indices->get(i)))))->intValue());
		}
		$nc(cRowset)->setMatchColumn(indexes);
	} else {
	}
	initJOIN(cRowset);
}

void JoinRowSetImpl::addRowSet($RowSet* rowset, int32_t columnIdx) {
	$nc(($cast($CachedRowSetImpl, rowset)))->setMatchColumn(columnIdx);
	addRowSet($cast($Joinable, rowset));
}

void JoinRowSetImpl::addRowSet($RowSet* rowset, $String* columnName) {
	$nc(($cast($CachedRowSetImpl, rowset)))->setMatchColumn(columnName);
	addRowSet($cast($Joinable, rowset));
}

void JoinRowSetImpl::addRowSet($RowSetArray* rowset, $ints* columnIdx) {
	$useLocalCurrentObjectStackCache();
	if ($nc(rowset)->length != $nc(columnIdx)->length) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("joinrowsetimpl.numnotequal"_s))))->toString()));
	} else {
		for (int32_t i = 0; i < rowset->length; ++i) {
			$nc(($cast($CachedRowSetImpl, rowset->get(i))))->setMatchColumn(columnIdx->get(i));
			addRowSet($cast($Joinable, rowset->get(i)));
		}
	}
}

void JoinRowSetImpl::addRowSet($RowSetArray* rowset, $StringArray* columnName) {
	$useLocalCurrentObjectStackCache();
	if ($nc(rowset)->length != $nc(columnName)->length) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("joinrowsetimpl.numnotequal"_s))))->toString()));
	} else {
		for (int32_t i = 0; i < rowset->length; ++i) {
			$nc(($cast($CachedRowSetImpl, rowset->get(i))))->setMatchColumn(columnName->get(i));
			addRowSet($cast($Joinable, rowset->get(i)));
		}
	}
}

$Collection* JoinRowSetImpl::getRowSets() {
	return static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>(this->vecRowSetsInJOIN)));
}

$StringArray* JoinRowSetImpl::getRowSetNames() {
	$useLocalCurrentObjectStackCache();
	$var($ObjectArray, arr, $nc(this->vecTableNames)->toArray());
	$var($StringArray, strArr, $new($StringArray, $nc(arr)->length));
	for (int32_t i = 0; i < arr->length; ++i) {
		strArr->set(i, $($nc($of(arr->get(i)))->toString()));
	}
	return strArr;
}

$CachedRowSet* JoinRowSetImpl::toCachedRowSet() {
	return this->crsInternal;
}

bool JoinRowSetImpl::supportsCrossJoin() {
	return $nc(this->supportedJOINs)->get($JoinRowSet::CROSS_JOIN);
}

bool JoinRowSetImpl::supportsInnerJoin() {
	return $nc(this->supportedJOINs)->get($JoinRowSet::INNER_JOIN);
}

bool JoinRowSetImpl::supportsLeftOuterJoin() {
	return $nc(this->supportedJOINs)->get($JoinRowSet::LEFT_OUTER_JOIN);
}

bool JoinRowSetImpl::supportsRightOuterJoin() {
	return $nc(this->supportedJOINs)->get($JoinRowSet::RIGHT_OUTER_JOIN);
}

bool JoinRowSetImpl::supportsFullJoin() {
	return $nc(this->supportedJOINs)->get($JoinRowSet::FULL_JOIN);
}

void JoinRowSetImpl::setJoinType(int32_t type) {
	$useLocalCurrentObjectStackCache();
	if (type >= $JoinRowSet::CROSS_JOIN && type <= $JoinRowSet::FULL_JOIN) {
		if (type != $JoinRowSet::INNER_JOIN) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("joinrowsetimpl.notsupported"_s))))->toString()));
		} else {
			$var($Integer, Intgr, $Integer::valueOf($JoinRowSet::INNER_JOIN));
			$nc(this->vecJoinType)->add(Intgr);
		}
	} else {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("joinrowsetimpl.notdefined"_s))))->toString()));
	}
}

bool JoinRowSetImpl::checkforMatchColumn($Joinable* rs) {
	$var($ints, i, $nc(rs)->getMatchColumnIndexes());
	if ($nc(i)->length <= 0) {
		return false;
	}
	return true;
}

void JoinRowSetImpl::initJOIN($CachedRowSet* rowset) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($CachedRowSetImpl, cRowset, $cast($CachedRowSetImpl, rowset));
		$var($CachedRowSetImpl, crsTemp, $new($CachedRowSetImpl));
		$var($RowSetMetaDataImpl, rsmd, $new($RowSetMetaDataImpl));
		if ($nc(this->vecRowSetsInJOIN)->isEmpty()) {
			$set(this, crsInternal, $cast($CachedRowSetImpl, $nc(rowset)->createCopy()));
			$nc(this->crsInternal)->setMetaData($cast($RowSetMetaDataImpl, $($nc(cRowset)->getMetaData())));
			$nc(this->vecRowSetsInJOIN)->add(cRowset);
		} else {
			int32_t var$0 = $nc(this->vecRowSetsInJOIN)->size();
			if ((var$0 - $nc(this->vecJoinType)->size()) == 2) {
				setJoinType($JoinRowSet::INNER_JOIN);
			} else {
				int32_t var$2 = $nc(this->vecRowSetsInJOIN)->size();
				if ((var$2 - $nc(this->vecJoinType)->size()) == 1) {
				}
			}
			$nc(this->vecTableNames)->add($($nc(this->crsInternal)->getTableName()));
			$nc(this->vecTableNames)->add($($nc(cRowset)->getTableName()));
			int32_t rowCount2 = $nc(cRowset)->size();
			int32_t rowCount1 = $nc(this->crsInternal)->size();
			int32_t matchColumnCount = 0;
			for (int32_t i = 0; i < $nc($($nc(this->crsInternal)->getMatchColumnIndexes()))->length; ++i) {
				if ($nc($($nc(this->crsInternal)->getMatchColumnIndexes()))->get(i) != -1) {
					++matchColumnCount;
				} else {
					break;
				}
			}
			int32_t var$3 = $nc($($nc(this->crsInternal)->getMetaData()))->getColumnCount();
			rsmd->setColumnCount(var$3 + $nc($(cRowset->getMetaData()))->getColumnCount() - matchColumnCount);
			crsTemp->setMetaData(rsmd);
			$nc(this->crsInternal)->beforeFirst();
			cRowset->beforeFirst();
			for (int32_t i = 1; i <= rowCount1; ++i) {
				if ($nc(this->crsInternal)->isAfterLast()) {
					break;
				}
				if ($nc(this->crsInternal)->next()) {
					cRowset->beforeFirst();
					for (int32_t j = 1; j <= rowCount2; ++j) {
						if (cRowset->isAfterLast()) {
							break;
						}
						if (cRowset->next()) {
							bool match = true;
							for (int32_t k = 0; k < matchColumnCount; ++k) {
								if (!$nc($of($($nc(this->crsInternal)->getObject($nc($($nc(this->crsInternal)->getMatchColumnIndexes()))->get(k)))))->equals($(cRowset->getObject($nc($(cRowset->getMatchColumnIndexes()))->get(k))))) {
									match = false;
									break;
								}
							}
							if (match) {
								int32_t p = 0;
								int32_t colc = 0;
								crsTemp->moveToInsertRow();
								for (p = 1; p <= $nc($($nc(this->crsInternal)->getMetaData()))->getColumnCount(); ++p) {
									match = false;
									for (int32_t k = 0; k < matchColumnCount; ++k) {
										if (p == $nc($($nc(this->crsInternal)->getMatchColumnIndexes()))->get(k)) {
											match = true;
											break;
										}
									}
									if (!match) {
										crsTemp->updateObject(++colc, $($nc(this->crsInternal)->getObject(p)));
										rsmd->setColumnName(colc, $($nc($($nc(this->crsInternal)->getMetaData()))->getColumnName(p)));
										rsmd->setTableName(colc, $($nc(this->crsInternal)->getTableName()));
										rsmd->setColumnType(p, $nc($($nc(this->crsInternal)->getMetaData()))->getColumnType(p));
										rsmd->setAutoIncrement(p, $nc($($nc(this->crsInternal)->getMetaData()))->isAutoIncrement(p));
										rsmd->setCaseSensitive(p, $nc($($nc(this->crsInternal)->getMetaData()))->isCaseSensitive(p));
										rsmd->setCatalogName(p, $($nc($($nc(this->crsInternal)->getMetaData()))->getCatalogName(p)));
										rsmd->setColumnDisplaySize(p, $nc($($nc(this->crsInternal)->getMetaData()))->getColumnDisplaySize(p));
										rsmd->setColumnLabel(p, $($nc($($nc(this->crsInternal)->getMetaData()))->getColumnLabel(p)));
										rsmd->setColumnType(p, $nc($($nc(this->crsInternal)->getMetaData()))->getColumnType(p));
										rsmd->setColumnTypeName(p, $($nc($($nc(this->crsInternal)->getMetaData()))->getColumnTypeName(p)));
										rsmd->setCurrency(p, $nc($($nc(this->crsInternal)->getMetaData()))->isCurrency(p));
										rsmd->setNullable(p, $nc($($nc(this->crsInternal)->getMetaData()))->isNullable(p));
										rsmd->setPrecision(p, $nc($($nc(this->crsInternal)->getMetaData()))->getPrecision(p));
										rsmd->setScale(p, $nc($($nc(this->crsInternal)->getMetaData()))->getScale(p));
										rsmd->setSchemaName(p, $($nc($($nc(this->crsInternal)->getMetaData()))->getSchemaName(p)));
										rsmd->setSearchable(p, $nc($($nc(this->crsInternal)->getMetaData()))->isSearchable(p));
										rsmd->setSigned(p, $nc($($nc(this->crsInternal)->getMetaData()))->isSigned(p));
									} else {
										crsTemp->updateObject(++colc, $($nc(this->crsInternal)->getObject(p)));
										rsmd->setColumnName(colc, $($nc($($nc(this->crsInternal)->getMetaData()))->getColumnName(p)));
										$var($String, var$4, $$str({$($nc(this->crsInternal)->getTableName()), "#"_s}));
										rsmd->setTableName(colc, $$concat(var$4, $(cRowset->getTableName())));
										rsmd->setColumnType(p, $nc($($nc(this->crsInternal)->getMetaData()))->getColumnType(p));
										rsmd->setAutoIncrement(p, $nc($($nc(this->crsInternal)->getMetaData()))->isAutoIncrement(p));
										rsmd->setCaseSensitive(p, $nc($($nc(this->crsInternal)->getMetaData()))->isCaseSensitive(p));
										rsmd->setCatalogName(p, $($nc($($nc(this->crsInternal)->getMetaData()))->getCatalogName(p)));
										rsmd->setColumnDisplaySize(p, $nc($($nc(this->crsInternal)->getMetaData()))->getColumnDisplaySize(p));
										rsmd->setColumnLabel(p, $($nc($($nc(this->crsInternal)->getMetaData()))->getColumnLabel(p)));
										rsmd->setColumnType(p, $nc($($nc(this->crsInternal)->getMetaData()))->getColumnType(p));
										rsmd->setColumnTypeName(p, $($nc($($nc(this->crsInternal)->getMetaData()))->getColumnTypeName(p)));
										rsmd->setCurrency(p, $nc($($nc(this->crsInternal)->getMetaData()))->isCurrency(p));
										rsmd->setNullable(p, $nc($($nc(this->crsInternal)->getMetaData()))->isNullable(p));
										rsmd->setPrecision(p, $nc($($nc(this->crsInternal)->getMetaData()))->getPrecision(p));
										rsmd->setScale(p, $nc($($nc(this->crsInternal)->getMetaData()))->getScale(p));
										rsmd->setSchemaName(p, $($nc($($nc(this->crsInternal)->getMetaData()))->getSchemaName(p)));
										rsmd->setSearchable(p, $nc($($nc(this->crsInternal)->getMetaData()))->isSearchable(p));
										rsmd->setSigned(p, $nc($($nc(this->crsInternal)->getMetaData()))->isSigned(p));
									}
								}
								for (int32_t q = 1; q <= $nc($(cRowset->getMetaData()))->getColumnCount(); ++q) {
									match = false;
									for (int32_t k = 0; k < matchColumnCount; ++k) {
										if (q == $nc($(cRowset->getMatchColumnIndexes()))->get(k)) {
											match = true;
											break;
										}
									}
									if (!match) {
										crsTemp->updateObject(++colc, $(cRowset->getObject(q)));
										rsmd->setColumnName(colc, $($nc($(cRowset->getMetaData()))->getColumnName(q)));
										rsmd->setTableName(colc, $(cRowset->getTableName()));
										rsmd->setColumnType(p + q - 1, $nc($(cRowset->getMetaData()))->getColumnType(q));
										rsmd->setAutoIncrement(p + q - 1, $nc($(cRowset->getMetaData()))->isAutoIncrement(q));
										rsmd->setCaseSensitive(p + q - 1, $nc($(cRowset->getMetaData()))->isCaseSensitive(q));
										rsmd->setCatalogName(p + q - 1, $($nc($(cRowset->getMetaData()))->getCatalogName(q)));
										rsmd->setColumnDisplaySize(p + q - 1, $nc($(cRowset->getMetaData()))->getColumnDisplaySize(q));
										rsmd->setColumnLabel(p + q - 1, $($nc($(cRowset->getMetaData()))->getColumnLabel(q)));
										rsmd->setColumnType(p + q - 1, $nc($(cRowset->getMetaData()))->getColumnType(q));
										rsmd->setColumnTypeName(p + q - 1, $($nc($(cRowset->getMetaData()))->getColumnTypeName(q)));
										rsmd->setCurrency(p + q - 1, $nc($(cRowset->getMetaData()))->isCurrency(q));
										rsmd->setNullable(p + q - 1, $nc($(cRowset->getMetaData()))->isNullable(q));
										rsmd->setPrecision(p + q - 1, $nc($(cRowset->getMetaData()))->getPrecision(q));
										rsmd->setScale(p + q - 1, $nc($(cRowset->getMetaData()))->getScale(q));
										rsmd->setSchemaName(p + q - 1, $($nc($(cRowset->getMetaData()))->getSchemaName(q)));
										rsmd->setSearchable(p + q - 1, $nc($(cRowset->getMetaData()))->isSearchable(q));
										rsmd->setSigned(p + q - 1, $nc($(cRowset->getMetaData()))->isSigned(q));
									} else {
										--p;
									}
								}
								crsTemp->insertRow();
								crsTemp->moveToCurrentRow();
							} else {
							}
						}
					}
				}
			}
			crsTemp->setMetaData(rsmd);
			crsTemp->setOriginal();
			$var($ints, pCol, $new($ints, matchColumnCount));
			for (int32_t i = 0; i < matchColumnCount; ++i) {
				pCol->set(i, $nc($($nc(this->crsInternal)->getMatchColumnIndexes()))->get(i));
			}
			$set(this, crsInternal, $cast($CachedRowSetImpl, crsTemp->createCopy()));
			$nc(this->crsInternal)->setMatchColumn(pCol);
			$nc(this->crsInternal)->setMetaData(rsmd);
			$nc(this->vecRowSetsInJOIN)->add(cRowset);
		}
	} catch ($SQLException& sqle) {
		sqle->printStackTrace();
		$throwNew($SQLException, $$str({$($nc($of($($nc(this->resBundle)->handleGetObject("joinrowsetimpl.initerror"_s))))->toString()), sqle}));
	} catch ($Exception& e) {
		e->printStackTrace();
		$throwNew($SQLException, $$str({$($nc($of($($nc(this->resBundle)->handleGetObject("joinrowsetimpl.genericerr"_s))))->toString()), e}));
	}
}

$String* JoinRowSetImpl::getWhereClause() {
	$useLocalCurrentObjectStackCache();
	$var($String, strWhereClause, "Select "_s);
	$var($String, whereClause, nullptr);
	$var($String, tabName, ""_s);
	$var($String, strTabName, ""_s);
	int32_t sz = 0;
	int32_t cols = 0;
	int32_t j = 0;
	$var($CachedRowSetImpl, crs, nullptr);
	sz = $nc(this->vecRowSetsInJOIN)->size();
	for (int32_t i = 0; i < sz; ++i) {
		$assign(crs, $cast($CachedRowSetImpl, $nc(this->vecRowSetsInJOIN)->get(i)));
		cols = $nc($($nc(crs)->getMetaData()))->getColumnCount();
		$assign(tabName, tabName->concat($(crs->getTableName())));
		$assign(strTabName, strTabName->concat($$str({tabName, ", "_s})));
		j = 1;
		while (j < cols) {
			$assign(strWhereClause, strWhereClause->concat($$str({tabName, "."_s, $($nc($(crs->getMetaData()))->getColumnName(j++))})));
			$assign(strWhereClause, strWhereClause->concat(", "_s));
		}
	}
	$assign(strWhereClause, strWhereClause->substring(0, strWhereClause->lastIndexOf((int32_t)u',')));
	$assign(strWhereClause, strWhereClause->concat(" from "_s));
	$assign(strWhereClause, strWhereClause->concat(strTabName));
	$assign(strWhereClause, strWhereClause->substring(0, strWhereClause->lastIndexOf((int32_t)u',')));
	$assign(strWhereClause, strWhereClause->concat(" where "_s));
	for (int32_t i = 0; i < sz; ++i) {
		$assign(strWhereClause, strWhereClause->concat($nc($($nc(($cast($CachedRowSetImpl, $($nc(this->vecRowSetsInJOIN)->get(i)))))->getMatchColumnNames()))->get(0)));
		if (i % 2 != 0) {
			$assign(strWhereClause, strWhereClause->concat("="_s));
		} else {
			$assign(strWhereClause, strWhereClause->concat(" and"_s));
		}
		$assign(strWhereClause, strWhereClause->concat(" "_s));
	}
	return strWhereClause;
}

bool JoinRowSetImpl::next() {
	return $nc(this->crsInternal)->next();
}

void JoinRowSetImpl::close() {
	$nc(this->crsInternal)->close();
}

bool JoinRowSetImpl::wasNull() {
	return $nc(this->crsInternal)->wasNull();
}

$String* JoinRowSetImpl::getString(int32_t columnIndex) {
	return $nc(this->crsInternal)->getString(columnIndex);
}

bool JoinRowSetImpl::getBoolean(int32_t columnIndex) {
	return $nc(this->crsInternal)->getBoolean(columnIndex);
}

int8_t JoinRowSetImpl::getByte(int32_t columnIndex) {
	return $nc(this->crsInternal)->getByte(columnIndex);
}

int16_t JoinRowSetImpl::getShort(int32_t columnIndex) {
	return $nc(this->crsInternal)->getShort(columnIndex);
}

int32_t JoinRowSetImpl::getInt(int32_t columnIndex) {
	return $nc(this->crsInternal)->getInt(columnIndex);
}

int64_t JoinRowSetImpl::getLong(int32_t columnIndex) {
	return $nc(this->crsInternal)->getLong(columnIndex);
}

float JoinRowSetImpl::getFloat(int32_t columnIndex) {
	return $nc(this->crsInternal)->getFloat(columnIndex);
}

double JoinRowSetImpl::getDouble(int32_t columnIndex) {
	return $nc(this->crsInternal)->getDouble(columnIndex);
}

$BigDecimal* JoinRowSetImpl::getBigDecimal(int32_t columnIndex, int32_t scale) {
	return $nc(this->crsInternal)->getBigDecimal(columnIndex);
}

$bytes* JoinRowSetImpl::getBytes(int32_t columnIndex) {
	return $nc(this->crsInternal)->getBytes(columnIndex);
}

$Date* JoinRowSetImpl::getDate(int32_t columnIndex) {
	return $nc(this->crsInternal)->getDate(columnIndex);
}

$Time* JoinRowSetImpl::getTime(int32_t columnIndex) {
	return $nc(this->crsInternal)->getTime(columnIndex);
}

$Timestamp* JoinRowSetImpl::getTimestamp(int32_t columnIndex) {
	return $nc(this->crsInternal)->getTimestamp(columnIndex);
}

$InputStream* JoinRowSetImpl::getAsciiStream(int32_t columnIndex) {
	return $nc(this->crsInternal)->getAsciiStream(columnIndex);
}

$InputStream* JoinRowSetImpl::getUnicodeStream(int32_t columnIndex) {
	return $nc(this->crsInternal)->getUnicodeStream(columnIndex);
}

$InputStream* JoinRowSetImpl::getBinaryStream(int32_t columnIndex) {
	return $nc(this->crsInternal)->getBinaryStream(columnIndex);
}

$String* JoinRowSetImpl::getString($String* columnName) {
	return $nc(this->crsInternal)->getString(columnName);
}

bool JoinRowSetImpl::getBoolean($String* columnName) {
	return $nc(this->crsInternal)->getBoolean(columnName);
}

int8_t JoinRowSetImpl::getByte($String* columnName) {
	return $nc(this->crsInternal)->getByte(columnName);
}

int16_t JoinRowSetImpl::getShort($String* columnName) {
	return $nc(this->crsInternal)->getShort(columnName);
}

int32_t JoinRowSetImpl::getInt($String* columnName) {
	return $nc(this->crsInternal)->getInt(columnName);
}

int64_t JoinRowSetImpl::getLong($String* columnName) {
	return $nc(this->crsInternal)->getLong(columnName);
}

float JoinRowSetImpl::getFloat($String* columnName) {
	return $nc(this->crsInternal)->getFloat(columnName);
}

double JoinRowSetImpl::getDouble($String* columnName) {
	return $nc(this->crsInternal)->getDouble(columnName);
}

$BigDecimal* JoinRowSetImpl::getBigDecimal($String* columnName, int32_t scale) {
	return $nc(this->crsInternal)->getBigDecimal(columnName);
}

$bytes* JoinRowSetImpl::getBytes($String* columnName) {
	return $nc(this->crsInternal)->getBytes(columnName);
}

$Date* JoinRowSetImpl::getDate($String* columnName) {
	return $nc(this->crsInternal)->getDate(columnName);
}

$Time* JoinRowSetImpl::getTime($String* columnName) {
	return $nc(this->crsInternal)->getTime(columnName);
}

$Timestamp* JoinRowSetImpl::getTimestamp($String* columnName) {
	return $nc(this->crsInternal)->getTimestamp(columnName);
}

$InputStream* JoinRowSetImpl::getAsciiStream($String* columnName) {
	return $nc(this->crsInternal)->getAsciiStream(columnName);
}

$InputStream* JoinRowSetImpl::getUnicodeStream($String* columnName) {
	return $nc(this->crsInternal)->getUnicodeStream(columnName);
}

$InputStream* JoinRowSetImpl::getBinaryStream($String* columnName) {
	return $nc(this->crsInternal)->getBinaryStream(columnName);
}

$SQLWarning* JoinRowSetImpl::getWarnings() {
	return $nc(this->crsInternal)->getWarnings();
}

void JoinRowSetImpl::clearWarnings() {
	$nc(this->crsInternal)->clearWarnings();
}

$String* JoinRowSetImpl::getCursorName() {
	return $nc(this->crsInternal)->getCursorName();
}

$ResultSetMetaData* JoinRowSetImpl::getMetaData() {
	return $nc(this->crsInternal)->getMetaData();
}

$Object* JoinRowSetImpl::getObject(int32_t columnIndex) {
	return $of($nc(this->crsInternal)->getObject(columnIndex));
}

$Object* JoinRowSetImpl::getObject(int32_t columnIndex, $Map* map) {
	return $of($nc(this->crsInternal)->getObject(columnIndex, map));
}

$Object* JoinRowSetImpl::getObject($String* columnName) {
	return $of($nc(this->crsInternal)->getObject(columnName));
}

$Object* JoinRowSetImpl::getObject($String* columnName, $Map* map) {
	return $of($nc(this->crsInternal)->getObject(columnName, map));
}

$Reader* JoinRowSetImpl::getCharacterStream(int32_t columnIndex) {
	return $nc(this->crsInternal)->getCharacterStream(columnIndex);
}

$Reader* JoinRowSetImpl::getCharacterStream($String* columnName) {
	return $nc(this->crsInternal)->getCharacterStream(columnName);
}

$BigDecimal* JoinRowSetImpl::getBigDecimal(int32_t columnIndex) {
	return $nc(this->crsInternal)->getBigDecimal(columnIndex);
}

$BigDecimal* JoinRowSetImpl::getBigDecimal($String* columnName) {
	return $nc(this->crsInternal)->getBigDecimal(columnName);
}

int32_t JoinRowSetImpl::size() {
	return $nc(this->crsInternal)->size();
}

bool JoinRowSetImpl::isBeforeFirst() {
	return $nc(this->crsInternal)->isBeforeFirst();
}

bool JoinRowSetImpl::isAfterLast() {
	return $nc(this->crsInternal)->isAfterLast();
}

bool JoinRowSetImpl::isFirst() {
	return $nc(this->crsInternal)->isFirst();
}

bool JoinRowSetImpl::isLast() {
	return $nc(this->crsInternal)->isLast();
}

void JoinRowSetImpl::beforeFirst() {
	$nc(this->crsInternal)->beforeFirst();
}

void JoinRowSetImpl::afterLast() {
	$nc(this->crsInternal)->afterLast();
}

bool JoinRowSetImpl::first() {
	return $nc(this->crsInternal)->first();
}

bool JoinRowSetImpl::last() {
	return $nc(this->crsInternal)->last();
}

int32_t JoinRowSetImpl::getRow() {
	return $nc(this->crsInternal)->getRow();
}

bool JoinRowSetImpl::absolute(int32_t row) {
	return $nc(this->crsInternal)->absolute(row);
}

bool JoinRowSetImpl::relative(int32_t rows) {
	return $nc(this->crsInternal)->relative(rows);
}

bool JoinRowSetImpl::previous() {
	return $nc(this->crsInternal)->previous();
}

int32_t JoinRowSetImpl::findColumn($String* columnName) {
	return $nc(this->crsInternal)->findColumn(columnName);
}

bool JoinRowSetImpl::rowUpdated() {
	return $nc(this->crsInternal)->rowUpdated();
}

bool JoinRowSetImpl::columnUpdated(int32_t indexColumn) {
	return $nc(this->crsInternal)->columnUpdated(indexColumn);
}

bool JoinRowSetImpl::rowInserted() {
	return $nc(this->crsInternal)->rowInserted();
}

bool JoinRowSetImpl::rowDeleted() {
	return $nc(this->crsInternal)->rowDeleted();
}

void JoinRowSetImpl::updateNull(int32_t columnIndex) {
	$nc(this->crsInternal)->updateNull(columnIndex);
}

void JoinRowSetImpl::updateBoolean(int32_t columnIndex, bool x) {
	$nc(this->crsInternal)->updateBoolean(columnIndex, x);
}

void JoinRowSetImpl::updateByte(int32_t columnIndex, int8_t x) {
	$nc(this->crsInternal)->updateByte(columnIndex, x);
}

void JoinRowSetImpl::updateShort(int32_t columnIndex, int16_t x) {
	$nc(this->crsInternal)->updateShort(columnIndex, x);
}

void JoinRowSetImpl::updateInt(int32_t columnIndex, int32_t x) {
	$nc(this->crsInternal)->updateInt(columnIndex, x);
}

void JoinRowSetImpl::updateLong(int32_t columnIndex, int64_t x) {
	$nc(this->crsInternal)->updateLong(columnIndex, x);
}

void JoinRowSetImpl::updateFloat(int32_t columnIndex, float x) {
	$nc(this->crsInternal)->updateFloat(columnIndex, x);
}

void JoinRowSetImpl::updateDouble(int32_t columnIndex, double x) {
	$nc(this->crsInternal)->updateDouble(columnIndex, x);
}

void JoinRowSetImpl::updateBigDecimal(int32_t columnIndex, $BigDecimal* x) {
	$nc(this->crsInternal)->updateBigDecimal(columnIndex, x);
}

void JoinRowSetImpl::updateString(int32_t columnIndex, $String* x) {
	$nc(this->crsInternal)->updateString(columnIndex, x);
}

void JoinRowSetImpl::updateBytes(int32_t columnIndex, $bytes* x) {
	$nc(this->crsInternal)->updateBytes(columnIndex, x);
}

void JoinRowSetImpl::updateDate(int32_t columnIndex, $Date* x) {
	$nc(this->crsInternal)->updateDate(columnIndex, x);
}

void JoinRowSetImpl::updateTime(int32_t columnIndex, $Time* x) {
	$nc(this->crsInternal)->updateTime(columnIndex, x);
}

void JoinRowSetImpl::updateTimestamp(int32_t columnIndex, $Timestamp* x) {
	$nc(this->crsInternal)->updateTimestamp(columnIndex, x);
}

void JoinRowSetImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x, int32_t length) {
	$nc(this->crsInternal)->updateAsciiStream(columnIndex, x, length);
}

void JoinRowSetImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x, int32_t length) {
	$nc(this->crsInternal)->updateBinaryStream(columnIndex, x, length);
}

void JoinRowSetImpl::updateCharacterStream(int32_t columnIndex, $Reader* x, int32_t length) {
	$nc(this->crsInternal)->updateCharacterStream(columnIndex, x, length);
}

void JoinRowSetImpl::updateObject(int32_t columnIndex, Object$* x, int32_t scale) {
	$nc(this->crsInternal)->updateObject(columnIndex, x, scale);
}

void JoinRowSetImpl::updateObject(int32_t columnIndex, Object$* x) {
	$nc(this->crsInternal)->updateObject(columnIndex, x);
}

void JoinRowSetImpl::updateNull($String* columnName) {
	$nc(this->crsInternal)->updateNull(columnName);
}

void JoinRowSetImpl::updateBoolean($String* columnName, bool x) {
	$nc(this->crsInternal)->updateBoolean(columnName, x);
}

void JoinRowSetImpl::updateByte($String* columnName, int8_t x) {
	$nc(this->crsInternal)->updateByte(columnName, x);
}

void JoinRowSetImpl::updateShort($String* columnName, int16_t x) {
	$nc(this->crsInternal)->updateShort(columnName, x);
}

void JoinRowSetImpl::updateInt($String* columnName, int32_t x) {
	$nc(this->crsInternal)->updateInt(columnName, x);
}

void JoinRowSetImpl::updateLong($String* columnName, int64_t x) {
	$nc(this->crsInternal)->updateLong(columnName, x);
}

void JoinRowSetImpl::updateFloat($String* columnName, float x) {
	$nc(this->crsInternal)->updateFloat(columnName, x);
}

void JoinRowSetImpl::updateDouble($String* columnName, double x) {
	$nc(this->crsInternal)->updateDouble(columnName, x);
}

void JoinRowSetImpl::updateBigDecimal($String* columnName, $BigDecimal* x) {
	$nc(this->crsInternal)->updateBigDecimal(columnName, x);
}

void JoinRowSetImpl::updateString($String* columnName, $String* x) {
	$nc(this->crsInternal)->updateString(columnName, x);
}

void JoinRowSetImpl::updateBytes($String* columnName, $bytes* x) {
	$nc(this->crsInternal)->updateBytes(columnName, x);
}

void JoinRowSetImpl::updateDate($String* columnName, $Date* x) {
	$nc(this->crsInternal)->updateDate(columnName, x);
}

void JoinRowSetImpl::updateTime($String* columnName, $Time* x) {
	$nc(this->crsInternal)->updateTime(columnName, x);
}

void JoinRowSetImpl::updateTimestamp($String* columnName, $Timestamp* x) {
	$nc(this->crsInternal)->updateTimestamp(columnName, x);
}

void JoinRowSetImpl::updateAsciiStream($String* columnName, $InputStream* x, int32_t length) {
	$nc(this->crsInternal)->updateAsciiStream(columnName, x, length);
}

void JoinRowSetImpl::updateBinaryStream($String* columnName, $InputStream* x, int32_t length) {
	$nc(this->crsInternal)->updateBinaryStream(columnName, x, length);
}

void JoinRowSetImpl::updateCharacterStream($String* columnName, $Reader* x, int32_t length) {
	$nc(this->crsInternal)->updateCharacterStream(columnName, x, length);
}

void JoinRowSetImpl::updateObject($String* columnName, Object$* x, int32_t scale) {
	$nc(this->crsInternal)->updateObject(columnName, x, scale);
}

void JoinRowSetImpl::updateObject($String* columnName, Object$* x) {
	$nc(this->crsInternal)->updateObject(columnName, x);
}

void JoinRowSetImpl::insertRow() {
	$nc(this->crsInternal)->insertRow();
}

void JoinRowSetImpl::updateRow() {
	$nc(this->crsInternal)->updateRow();
}

void JoinRowSetImpl::deleteRow() {
	$nc(this->crsInternal)->deleteRow();
}

void JoinRowSetImpl::refreshRow() {
	$nc(this->crsInternal)->refreshRow();
}

void JoinRowSetImpl::cancelRowUpdates() {
	$nc(this->crsInternal)->cancelRowUpdates();
}

void JoinRowSetImpl::moveToInsertRow() {
	$nc(this->crsInternal)->moveToInsertRow();
}

void JoinRowSetImpl::moveToCurrentRow() {
	$nc(this->crsInternal)->moveToCurrentRow();
}

$Statement* JoinRowSetImpl::getStatement() {
	return $nc(this->crsInternal)->getStatement();
}

$Ref* JoinRowSetImpl::getRef(int32_t columnIndex) {
	return $nc(this->crsInternal)->getRef(columnIndex);
}

$Blob* JoinRowSetImpl::getBlob(int32_t columnIndex) {
	return $nc(this->crsInternal)->getBlob(columnIndex);
}

$Clob* JoinRowSetImpl::getClob(int32_t columnIndex) {
	return $nc(this->crsInternal)->getClob(columnIndex);
}

$1Array* JoinRowSetImpl::getArray(int32_t columnIndex) {
	return $nc(this->crsInternal)->getArray(columnIndex);
}

$Ref* JoinRowSetImpl::getRef($String* columnName) {
	return $nc(this->crsInternal)->getRef(columnName);
}

$Blob* JoinRowSetImpl::getBlob($String* columnName) {
	return $nc(this->crsInternal)->getBlob(columnName);
}

$Clob* JoinRowSetImpl::getClob($String* columnName) {
	return $nc(this->crsInternal)->getClob(columnName);
}

$1Array* JoinRowSetImpl::getArray($String* columnName) {
	return $nc(this->crsInternal)->getArray(columnName);
}

$Date* JoinRowSetImpl::getDate(int32_t columnIndex, $Calendar* cal) {
	return $nc(this->crsInternal)->getDate(columnIndex, cal);
}

$Date* JoinRowSetImpl::getDate($String* columnName, $Calendar* cal) {
	return $nc(this->crsInternal)->getDate(columnName, cal);
}

$Time* JoinRowSetImpl::getTime(int32_t columnIndex, $Calendar* cal) {
	return $nc(this->crsInternal)->getTime(columnIndex, cal);
}

$Time* JoinRowSetImpl::getTime($String* columnName, $Calendar* cal) {
	return $nc(this->crsInternal)->getTime(columnName, cal);
}

$Timestamp* JoinRowSetImpl::getTimestamp(int32_t columnIndex, $Calendar* cal) {
	return $nc(this->crsInternal)->getTimestamp(columnIndex, cal);
}

$Timestamp* JoinRowSetImpl::getTimestamp($String* columnName, $Calendar* cal) {
	return $nc(this->crsInternal)->getTimestamp(columnName, cal);
}

void JoinRowSetImpl::setMetaData($RowSetMetaData* md) {
	$nc(this->crsInternal)->setMetaData(md);
}

$ResultSet* JoinRowSetImpl::getOriginal() {
	return $nc(this->crsInternal)->getOriginal();
}

$ResultSet* JoinRowSetImpl::getOriginalRow() {
	return $nc(this->crsInternal)->getOriginalRow();
}

void JoinRowSetImpl::setOriginalRow() {
	$nc(this->crsInternal)->setOriginalRow();
}

$ints* JoinRowSetImpl::getKeyColumns() {
	return $nc(this->crsInternal)->getKeyColumns();
}

void JoinRowSetImpl::setKeyColumns($ints* cols) {
	$nc(this->crsInternal)->setKeyColumns(cols);
}

void JoinRowSetImpl::updateRef(int32_t columnIndex, $Ref* ref) {
	$nc(this->crsInternal)->updateRef(columnIndex, ref);
}

void JoinRowSetImpl::updateRef($String* columnName, $Ref* ref) {
	$nc(this->crsInternal)->updateRef(columnName, ref);
}

void JoinRowSetImpl::updateClob(int32_t columnIndex, $Clob* c) {
	$nc(this->crsInternal)->updateClob(columnIndex, c);
}

void JoinRowSetImpl::updateClob($String* columnName, $Clob* c) {
	$nc(this->crsInternal)->updateClob(columnName, c);
}

void JoinRowSetImpl::updateBlob(int32_t columnIndex, $Blob* b) {
	$nc(this->crsInternal)->updateBlob(columnIndex, b);
}

void JoinRowSetImpl::updateBlob($String* columnName, $Blob* b) {
	$nc(this->crsInternal)->updateBlob(columnName, b);
}

void JoinRowSetImpl::updateArray(int32_t columnIndex, $1Array* a) {
	$nc(this->crsInternal)->updateArray(columnIndex, a);
}

void JoinRowSetImpl::updateArray($String* columnName, $1Array* a) {
	$nc(this->crsInternal)->updateArray(columnName, a);
}

void JoinRowSetImpl::execute() {
	$nc(this->crsInternal)->execute();
}

void JoinRowSetImpl::execute($Connection* conn) {
	$nc(this->crsInternal)->execute(conn);
}

$URL* JoinRowSetImpl::getURL(int32_t columnIndex) {
	return $nc(this->crsInternal)->getURL(columnIndex);
}

$URL* JoinRowSetImpl::getURL($String* columnName) {
	return $nc(this->crsInternal)->getURL(columnName);
}

void JoinRowSetImpl::writeXml($ResultSet* rs, $Writer* writer) {
	$set(this, wrs, $new($WebRowSetImpl));
	$nc(this->wrs)->populate(rs);
	$nc(this->wrs)->writeXml(writer);
}

void JoinRowSetImpl::writeXml($Writer* writer) {
	$nc($(createWebRowSet()))->writeXml(writer);
}

void JoinRowSetImpl::readXml($Reader* reader) {
	$set(this, wrs, $new($WebRowSetImpl));
	$nc(this->wrs)->readXml(reader);
	$set(this, crsInternal, $cast($CachedRowSetImpl, this->wrs));
}

void JoinRowSetImpl::readXml($InputStream* iStream) {
	$set(this, wrs, $new($WebRowSetImpl));
	$nc(this->wrs)->readXml(iStream);
	$set(this, crsInternal, $cast($CachedRowSetImpl, this->wrs));
}

void JoinRowSetImpl::writeXml($OutputStream* oStream) {
	$nc($(createWebRowSet()))->writeXml(oStream);
}

void JoinRowSetImpl::writeXml($ResultSet* rs, $OutputStream* oStream) {
	$set(this, wrs, $new($WebRowSetImpl));
	$nc(this->wrs)->populate(rs);
	$nc(this->wrs)->writeXml(oStream);
}

$WebRowSet* JoinRowSetImpl::createWebRowSet() {
	if (this->wrs != nullptr) {
		return this->wrs;
	} else {
		$set(this, wrs, $new($WebRowSetImpl));
		$nc(this->crsInternal)->beforeFirst();
		$nc(this->wrs)->populate(this->crsInternal);
		return this->wrs;
	}
}

int32_t JoinRowSetImpl::getJoinType() {
	if (this->vecJoinType == nullptr) {
		this->setJoinType($JoinRowSet::INNER_JOIN);
	}
	$var($Integer, i, $cast($Integer, $nc(this->vecJoinType)->get($nc(this->vecJoinType)->size() - 1)));
	return $nc(i)->intValue();
}

void JoinRowSetImpl::addRowSetListener($RowSetListener* listener) {
	$nc(this->crsInternal)->addRowSetListener(listener);
}

void JoinRowSetImpl::removeRowSetListener($RowSetListener* listener) {
	$nc(this->crsInternal)->removeRowSetListener(listener);
}

$Collection* JoinRowSetImpl::toCollection() {
	return $nc(this->crsInternal)->toCollection();
}

$Collection* JoinRowSetImpl::toCollection(int32_t column) {
	return $nc(this->crsInternal)->toCollection(column);
}

$Collection* JoinRowSetImpl::toCollection($String* column) {
	return $nc(this->crsInternal)->toCollection(column);
}

$CachedRowSet* JoinRowSetImpl::createCopySchema() {
	return $nc(this->crsInternal)->createCopySchema();
}

void JoinRowSetImpl::setSyncProvider($String* providerStr) {
	$nc(this->crsInternal)->setSyncProvider(providerStr);
}

void JoinRowSetImpl::acceptChanges() {
	$nc(this->crsInternal)->acceptChanges();
}

$SyncProvider* JoinRowSetImpl::getSyncProvider() {
	return $nc(this->crsInternal)->getSyncProvider();
}

void JoinRowSetImpl::readObject($ObjectInputStream* ois) {
	$nc(ois)->defaultReadObject();
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

JoinRowSetImpl::JoinRowSetImpl() {
}

$Class* JoinRowSetImpl::load$($String* name, bool initialize) {
	$loadClass(JoinRowSetImpl, name, initialize, &_JoinRowSetImpl_ClassInfo_, allocate$JoinRowSetImpl);
	return class$;
}

$Class* JoinRowSetImpl::class$ = nullptr;

		} // rowset
	} // sun
} // com
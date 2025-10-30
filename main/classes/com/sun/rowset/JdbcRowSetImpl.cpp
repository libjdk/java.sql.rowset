#include <com/sun/rowset/JdbcRowSetImpl.h>

#include <com/sun/rowset/JdbcRowSetResourceBundle.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Reader.h>
#include <java/math/BigDecimal.h>
#include <java/net/URL.h>
#include <java/sql/Array.h>
#include <java/sql/Blob.h>
#include <java/sql/Clob.h>
#include <java/sql/Connection.h>
#include <java/sql/DatabaseMetaData.h>
#include <java/sql/Date.h>
#include <java/sql/DriverManager.h>
#include <java/sql/NClob.h>
#include <java/sql/ParameterMetaData.h>
#include <java/sql/PreparedStatement.h>
#include <java/sql/Ref.h>
#include <java/sql/ResultSet.h>
#include <java/sql/ResultSetMetaData.h>
#include <java/sql/RowId.h>
#include <java/sql/SQLException.h>
#include <java/sql/SQLFeatureNotSupportedException.h>
#include <java/sql/SQLWarning.h>
#include <java/sql/SQLXML.h>
#include <java/sql/Savepoint.h>
#include <java/sql/Statement.h>
#include <java/sql/Time.h>
#include <java/sql/Timestamp.h>
#include <java/util/Calendar.h>
#include <java/util/Map.h>
#include <java/util/Vector.h>
#include <javax/naming/Context.h>
#include <javax/naming/InitialContext.h>
#include <javax/naming/NamingException.h>
#include <javax/sql/DataSource.h>
#include <javax/sql/RowSetListener.h>
#include <javax/sql/RowSetMetaData.h>
#include <javax/sql/rowset/BaseRowSet.h>
#include <javax/sql/rowset/RowSetMetaDataImpl.h>
#include <javax/sql/rowset/RowSetWarning.h>
#include <jcpp.h>

#undef ASCII_STREAM_PARAM
#undef BINARY_STREAM_PARAM
#undef CONCUR_READ_ONLY
#undef CONCUR_UPDATABLE
#undef HOLD_CURSORS_OVER_COMMIT
#undef TRANSACTION_READ_COMMITTED
#undef TYPE_FORWARD_ONLY
#undef TYPE_SCROLL_INSENSITIVE
#undef UNICODE_STREAM_PARAM

using $IntegerArray = $Array<::java::lang::Integer>;
using $JdbcRowSetResourceBundle = ::com::sun::rowset::JdbcRowSetResourceBundle;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $BigDecimal = ::java::math::BigDecimal;
using $URL = ::java::net::URL;
using $1Array = ::java::sql::Array;
using $Blob = ::java::sql::Blob;
using $Clob = ::java::sql::Clob;
using $Connection = ::java::sql::Connection;
using $DatabaseMetaData = ::java::sql::DatabaseMetaData;
using $Date = ::java::sql::Date;
using $DriverManager = ::java::sql::DriverManager;
using $NClob = ::java::sql::NClob;
using $ParameterMetaData = ::java::sql::ParameterMetaData;
using $PreparedStatement = ::java::sql::PreparedStatement;
using $Ref = ::java::sql::Ref;
using $ResultSet = ::java::sql::ResultSet;
using $ResultSetMetaData = ::java::sql::ResultSetMetaData;
using $RowId = ::java::sql::RowId;
using $SQLException = ::java::sql::SQLException;
using $SQLFeatureNotSupportedException = ::java::sql::SQLFeatureNotSupportedException;
using $SQLWarning = ::java::sql::SQLWarning;
using $SQLXML = ::java::sql::SQLXML;
using $Savepoint = ::java::sql::Savepoint;
using $Statement = ::java::sql::Statement;
using $Time = ::java::sql::Time;
using $Timestamp = ::java::sql::Timestamp;
using $Calendar = ::java::util::Calendar;
using $Map = ::java::util::Map;
using $Vector = ::java::util::Vector;
using $Context = ::javax::naming::Context;
using $InitialContext = ::javax::naming::InitialContext;
using $NamingException = ::javax::naming::NamingException;
using $DataSource = ::javax::sql::DataSource;
using $RowSetListener = ::javax::sql::RowSetListener;
using $RowSetMetaData = ::javax::sql::RowSetMetaData;
using $BaseRowSet = ::javax::sql::rowset::BaseRowSet;
using $JdbcRowSet = ::javax::sql::rowset::JdbcRowSet;
using $RowSetMetaDataImpl = ::javax::sql::rowset::RowSetMetaDataImpl;
using $RowSetWarning = ::javax::sql::rowset::RowSetWarning;

namespace com {
	namespace sun {
		namespace rowset {

$CompoundAttribute _JdbcRowSetImpl_MethodAnnotations_getBigDecimal24[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _JdbcRowSetImpl_MethodAnnotations_getBigDecimal25[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _JdbcRowSetImpl_MethodAnnotations_getUnicodeStream102[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _JdbcRowSetImpl_MethodAnnotations_getUnicodeStream103[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _JdbcRowSetImpl_FieldInfo_[] = {
	{"conn", "Ljava/sql/Connection;", nullptr, $PRIVATE, $field(JdbcRowSetImpl, conn)},
	{"ps", "Ljava/sql/PreparedStatement;", nullptr, $PRIVATE, $field(JdbcRowSetImpl, ps)},
	{"rs", "Ljava/sql/ResultSet;", nullptr, $PRIVATE, $field(JdbcRowSetImpl, rs)},
	{"rowsMD", "Ljavax/sql/rowset/RowSetMetaDataImpl;", nullptr, $PRIVATE, $field(JdbcRowSetImpl, rowsMD)},
	{"resMD", "Ljava/sql/ResultSetMetaData;", nullptr, $PRIVATE, $field(JdbcRowSetImpl, resMD)},
	{"iMatchColumns", "Ljava/util/Vector;", "Ljava/util/Vector<Ljava/lang/Integer;>;", $PRIVATE, $field(JdbcRowSetImpl, iMatchColumns)},
	{"strMatchColumns", "Ljava/util/Vector;", "Ljava/util/Vector<Ljava/lang/String;>;", $PRIVATE, $field(JdbcRowSetImpl, strMatchColumns)},
	{"resBundle", "Lcom/sun/rowset/JdbcRowSetResourceBundle;", nullptr, $PROTECTED | $TRANSIENT, $field(JdbcRowSetImpl, resBundle)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(JdbcRowSetImpl, serialVersionUID)},
	{}
};

$MethodInfo _JdbcRowSetImpl_MethodInfo_[] = {
	{"*addRowSetListener", "(Ljavax/sql/RowSetListener;)V", nullptr, $PUBLIC},
	{"*clearParameters", "()V", nullptr, $PUBLIC},
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*getCommand", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getDataSourceName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getEscapeProcessing", "()Z", nullptr, $PUBLIC},
	{"*getFetchSize", "()I", nullptr, $PUBLIC},
	{"*getMaxFieldSize", "()I", nullptr, $PUBLIC},
	{"*getMaxRows", "()I", nullptr, $PUBLIC},
	{"*getPassword", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getQueryTimeout", "()I", nullptr, $PUBLIC},
	{"*getShowDeleted", "()Z", nullptr, $PUBLIC},
	{"*getTransactionIsolation", "()I", nullptr, $PUBLIC},
	{"*getTypeMap", "()Ljava/util/Map;", nullptr, $PUBLIC},
	{"*getUrl", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getUsername", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(JdbcRowSetImpl::*)()>(&JdbcRowSetImpl::init$))},
	{"<init>", "(Ljava/sql/Connection;)V", nullptr, $PUBLIC, $method(static_cast<void(JdbcRowSetImpl::*)($Connection*)>(&JdbcRowSetImpl::init$)), "java.sql.SQLException"},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(JdbcRowSetImpl::*)($String*,$String*,$String*)>(&JdbcRowSetImpl::init$)), "java.sql.SQLException"},
	{"<init>", "(Ljava/sql/ResultSet;)V", nullptr, $PUBLIC, $method(static_cast<void(JdbcRowSetImpl::*)($ResultSet*)>(&JdbcRowSetImpl::init$)), "java.sql.SQLException"},
	{"absolute", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"afterLast", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"beforeFirst", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"cancelRowUpdates", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"checkState", "()V", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"checkTypeConcurrency", "()V", nullptr, $PRIVATE, $method(static_cast<void(JdbcRowSetImpl::*)()>(&JdbcRowSetImpl::checkTypeConcurrency)), "java.sql.SQLException"},
	{"clearWarnings", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"close", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"commit", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"connect", "()Ljava/sql/Connection;", nullptr, $PRIVATE, $method(static_cast<$Connection*(JdbcRowSetImpl::*)()>(&JdbcRowSetImpl::connect)), "java.sql.SQLException"},
	{"decodeParams", "([Ljava/lang/Object;Ljava/sql/PreparedStatement;)V", nullptr, $PRIVATE, $method(static_cast<void(JdbcRowSetImpl::*)($ObjectArray*,$PreparedStatement*)>(&JdbcRowSetImpl::decodeParams)), "java.sql.SQLException"},
	{"deleteRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"execute", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"findColumn", "(Ljava/lang/String;)I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"first", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getArray", "(I)Ljava/sql/Array;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getArray", "(Ljava/lang/String;)Ljava/sql/Array;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getAsciiStream", "(I)Ljava/io/InputStream;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getAsciiStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getAutoCommit", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getBigDecimal", "(II)Ljava/math/BigDecimal;", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.sql.SQLException", nullptr, _JdbcRowSetImpl_MethodAnnotations_getBigDecimal24},
	{"getBigDecimal", "(Ljava/lang/String;I)Ljava/math/BigDecimal;", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.sql.SQLException", nullptr, _JdbcRowSetImpl_MethodAnnotations_getBigDecimal25},
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
	{"getConcurrency", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getConnection", "()Ljava/sql/Connection;", nullptr, $PROTECTED},
	{"getCursorName", "()Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getDatabaseMetaData", "()Ljava/sql/DatabaseMetaData;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getDate", "(I)Ljava/sql/Date;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getDate", "(Ljava/lang/String;)Ljava/sql/Date;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getDate", "(ILjava/util/Calendar;)Ljava/sql/Date;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getDate", "(Ljava/lang/String;Ljava/util/Calendar;)Ljava/sql/Date;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getDouble", "(I)D", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getDouble", "(Ljava/lang/String;)D", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getFetchDirection", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getFloat", "(I)F", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getFloat", "(Ljava/lang/String;)F", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getHoldability", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getInt", "(I)I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getInt", "(Ljava/lang/String;)I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getLong", "(I)J", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getLong", "(Ljava/lang/String;)J", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getMatchColumnIndexes", "()[I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getMatchColumnNames", "()[Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getMetaData", "()Ljava/sql/ResultSetMetaData;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getNCharacterStream", "(I)Ljava/io/Reader;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getNCharacterStream", "(Ljava/lang/String;)Ljava/io/Reader;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getNClob", "(I)Ljava/sql/NClob;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getNClob", "(Ljava/lang/String;)Ljava/sql/NClob;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getNString", "(I)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getNString", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getObject", "(I)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getObject", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getObject", "(ILjava/util/Map;)Ljava/lang/Object;", "(ILjava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)Ljava/lang/Object;", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getObject", "(Ljava/lang/String;Ljava/util/Map;)Ljava/lang/Object;", "(Ljava/lang/String;Ljava/util/Map<Ljava/lang/String;Ljava/lang/Class<*>;>;)Ljava/lang/Object;", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getObject", "(ILjava/lang/Class;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(ILjava/lang/Class<TT;>;)TT;", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getObject", "(Ljava/lang/String;Ljava/lang/Class;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/lang/String;Ljava/lang/Class<TT;>;)TT;", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getParameterMetaData", "()Ljava/sql/ParameterMetaData;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getPreparedStatement", "()Ljava/sql/PreparedStatement;", nullptr, $PROTECTED},
	{"getRef", "(I)Ljava/sql/Ref;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getRef", "(Ljava/lang/String;)Ljava/sql/Ref;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getResultSet", "()Ljava/sql/ResultSet;", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"getRow", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getRowId", "(I)Ljava/sql/RowId;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getRowId", "(Ljava/lang/String;)Ljava/sql/RowId;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getRowSetWarnings", "()Ljavax/sql/rowset/RowSetWarning;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getSQLXML", "(I)Ljava/sql/SQLXML;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getSQLXML", "(Ljava/lang/String;)Ljava/sql/SQLXML;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getShort", "(I)S", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getShort", "(Ljava/lang/String;)S", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getStatement", "()Ljava/sql/Statement;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getString", "(I)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getString", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTime", "(I)Ljava/sql/Time;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTime", "(Ljava/lang/String;)Ljava/sql/Time;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTime", "(ILjava/util/Calendar;)Ljava/sql/Time;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTime", "(Ljava/lang/String;Ljava/util/Calendar;)Ljava/sql/Time;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTimestamp", "(I)Ljava/sql/Timestamp;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTimestamp", "(Ljava/lang/String;)Ljava/sql/Timestamp;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTimestamp", "(ILjava/util/Calendar;)Ljava/sql/Timestamp;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTimestamp", "(Ljava/lang/String;Ljava/util/Calendar;)Ljava/sql/Timestamp;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getType", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getURL", "(I)Ljava/net/URL;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getURL", "(Ljava/lang/String;)Ljava/net/URL;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getUnicodeStream", "(I)Ljava/io/InputStream;", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.sql.SQLException", nullptr, _JdbcRowSetImpl_MethodAnnotations_getUnicodeStream102},
	{"getUnicodeStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.sql.SQLException", nullptr, _JdbcRowSetImpl_MethodAnnotations_getUnicodeStream103},
	{"getWarnings", "()Ljava/sql/SQLWarning;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"initMetaData", "(Ljavax/sql/RowSetMetaData;Ljava/sql/ResultSetMetaData;)V", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"insertRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isAfterLast", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isBeforeFirst", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isClosed", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isFirst", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isLast", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*isReadOnly", "()Z", nullptr, $PUBLIC},
	{"isWrapperFor", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"last", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"moveToCurrentRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"moveToInsertRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"next", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"prepare", "()Ljava/sql/PreparedStatement;", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"previous", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(JdbcRowSetImpl::*)($ObjectInputStream*)>(&JdbcRowSetImpl::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"refreshRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"relative", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*removeRowSetListener", "(Ljavax/sql/RowSetListener;)V", nullptr, $PUBLIC},
	{"rollback", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"rollback", "(Ljava/sql/Savepoint;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"rowDeleted", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"rowInserted", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"rowUpdated", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setArray", "(ILjava/sql/Array;)V", nullptr, $PUBLIC},
	{"*setAsciiStream", "(ILjava/io/InputStream;I)V", nullptr, $PUBLIC},
	{"*setAsciiStream", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC},
	{"setAsciiStream", "(Ljava/lang/String;Ljava/io/InputStream;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setAsciiStream", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setAutoCommit", "(Z)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setBigDecimal", "(ILjava/math/BigDecimal;)V", nullptr, $PUBLIC},
	{"setBigDecimal", "(Ljava/lang/String;Ljava/math/BigDecimal;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setBinaryStream", "(ILjava/io/InputStream;I)V", nullptr, $PUBLIC},
	{"*setBinaryStream", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC},
	{"setBinaryStream", "(Ljava/lang/String;Ljava/io/InputStream;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBinaryStream", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setBlob", "(ILjava/sql/Blob;)V", nullptr, $PUBLIC},
	{"setBlob", "(ILjava/io/InputStream;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBlob", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBlob", "(Ljava/lang/String;Ljava/io/InputStream;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBlob", "(Ljava/lang/String;Ljava/sql/Blob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setBlob", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setBoolean", "(IZ)V", nullptr, $PUBLIC},
	{"setBoolean", "(Ljava/lang/String;Z)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setByte", "(IB)V", nullptr, $PUBLIC},
	{"setByte", "(Ljava/lang/String;B)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setBytes", "(I[B)V", nullptr, $PUBLIC},
	{"setBytes", "(Ljava/lang/String;[B)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setCharacterStream", "(ILjava/io/Reader;I)V", nullptr, $PUBLIC},
	{"*setCharacterStream", "(ILjava/io/Reader;)V", nullptr, $PUBLIC},
	{"setCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setClob", "(ILjava/sql/Clob;)V", nullptr, $PUBLIC},
	{"setClob", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setClob", "(Ljava/lang/String;Ljava/sql/Clob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setClob", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setClob", "(ILjava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setClob", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setCommand", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setConcurrency", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setConnection", "(Ljava/sql/Connection;)V", nullptr, $PROTECTED},
	{"setDataSourceName", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setDate", "(ILjava/sql/Date;)V", nullptr, $PUBLIC},
	{"*setDate", "(ILjava/sql/Date;Ljava/util/Calendar;)V", nullptr, $PUBLIC},
	{"setDate", "(Ljava/lang/String;Ljava/sql/Date;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setDate", "(Ljava/lang/String;Ljava/sql/Date;Ljava/util/Calendar;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setDouble", "(ID)V", nullptr, $PUBLIC},
	{"setDouble", "(Ljava/lang/String;D)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setEscapeProcessing", "(Z)V", nullptr, $PUBLIC},
	{"setFetchDirection", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setFetchSize", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setFloat", "(IF)V", nullptr, $PUBLIC},
	{"setFloat", "(Ljava/lang/String;F)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setInt", "(II)V", nullptr, $PUBLIC},
	{"setInt", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setLong", "(IJ)V", nullptr, $PUBLIC},
	{"setLong", "(Ljava/lang/String;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setMatchColumn", "([I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setMatchColumn", "([Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setMatchColumn", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setMatchColumn", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setMaxFieldSize", "(I)V", nullptr, $PUBLIC},
	{"*setMaxRows", "(I)V", nullptr, $PUBLIC},
	{"setNCharacterStream", "(ILjava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNCharacterStream", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNClob", "(Ljava/lang/String;Ljava/sql/NClob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNClob", "(ILjava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNClob", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNClob", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNClob", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNClob", "(ILjava/sql/NClob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNString", "(ILjava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNString", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setNull", "(II)V", nullptr, $PUBLIC},
	{"*setNull", "(IILjava/lang/String;)V", nullptr, $PUBLIC},
	{"setNull", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNull", "(Ljava/lang/String;ILjava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setObject", "(ILjava/lang/Object;II)V", nullptr, $PUBLIC},
	{"*setObject", "(ILjava/lang/Object;I)V", nullptr, $PUBLIC},
	{"*setObject", "(ILjava/lang/Object;)V", nullptr, $PUBLIC},
	{"setObject", "(Ljava/lang/String;Ljava/lang/Object;II)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setObject", "(Ljava/lang/String;Ljava/lang/Object;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setObject", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setParams", "()V", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"setPassword", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"setPreparedStatement", "(Ljava/sql/PreparedStatement;)V", nullptr, $PROTECTED},
	{"setProperties", "(Ljava/sql/PreparedStatement;)V", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"*setQueryTimeout", "(I)V", nullptr, $PUBLIC},
	{"*setReadOnly", "(Z)V", nullptr, $PUBLIC},
	{"*setRef", "(ILjava/sql/Ref;)V", nullptr, $PUBLIC},
	{"setResultSet", "(Ljava/sql/ResultSet;)V", nullptr, $PROTECTED},
	{"setRowId", "(ILjava/sql/RowId;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setRowId", "(Ljava/lang/String;Ljava/sql/RowId;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setSQLXML", "(ILjava/sql/SQLXML;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setSQLXML", "(Ljava/lang/String;Ljava/sql/SQLXML;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setShort", "(IS)V", nullptr, $PUBLIC},
	{"setShort", "(Ljava/lang/String;S)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setShowDeleted", "(Z)V", nullptr, $PUBLIC},
	{"*setString", "(ILjava/lang/String;)V", nullptr, $PUBLIC},
	{"setString", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setTime", "(ILjava/sql/Time;)V", nullptr, $PUBLIC},
	{"*setTime", "(ILjava/sql/Time;Ljava/util/Calendar;)V", nullptr, $PUBLIC},
	{"setTime", "(Ljava/lang/String;Ljava/sql/Time;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setTime", "(Ljava/lang/String;Ljava/sql/Time;Ljava/util/Calendar;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setTimestamp", "(ILjava/sql/Timestamp;)V", nullptr, $PUBLIC},
	{"*setTimestamp", "(ILjava/sql/Timestamp;Ljava/util/Calendar;)V", nullptr, $PUBLIC},
	{"setTimestamp", "(Ljava/lang/String;Ljava/sql/Timestamp;Ljava/util/Calendar;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setTimestamp", "(Ljava/lang/String;Ljava/sql/Timestamp;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setTransactionIsolation", "(I)V", nullptr, $PUBLIC},
	{"setType", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setTypeMap", "(Ljava/util/Map;)V", nullptr, $PUBLIC},
	{"setURL", "(ILjava/net/URL;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setUrl", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setUsername", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"unsetMatchColumn", "([I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"unsetMatchColumn", "([Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"unsetMatchColumn", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"unsetMatchColumn", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"unwrap", "(Ljava/lang/Class;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/lang/Class<TT;>;)TT;", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateArray", "(ILjava/sql/Array;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateArray", "(Ljava/lang/String;Ljava/sql/Array;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateAsciiStream", "(ILjava/io/InputStream;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateAsciiStream", "(Ljava/lang/String;Ljava/io/InputStream;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateAsciiStream", "(ILjava/io/InputStream;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateAsciiStream", "(Ljava/lang/String;Ljava/io/InputStream;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateAsciiStream", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateAsciiStream", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBigDecimal", "(ILjava/math/BigDecimal;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBigDecimal", "(Ljava/lang/String;Ljava/math/BigDecimal;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBinaryStream", "(ILjava/io/InputStream;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBinaryStream", "(Ljava/lang/String;Ljava/io/InputStream;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBinaryStream", "(ILjava/io/InputStream;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBinaryStream", "(Ljava/lang/String;Ljava/io/InputStream;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBinaryStream", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBinaryStream", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBlob", "(ILjava/sql/Blob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBlob", "(Ljava/lang/String;Ljava/sql/Blob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBlob", "(ILjava/io/InputStream;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBlob", "(Ljava/lang/String;Ljava/io/InputStream;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBlob", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBlob", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBoolean", "(IZ)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBoolean", "(Ljava/lang/String;Z)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateByte", "(IB)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateByte", "(Ljava/lang/String;B)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBytes", "(I[B)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateBytes", "(Ljava/lang/String;[B)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateCharacterStream", "(ILjava/io/Reader;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateCharacterStream", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateCharacterStream", "(ILjava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateClob", "(ILjava/sql/Clob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateClob", "(Ljava/lang/String;Ljava/sql/Clob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateClob", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateClob", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateClob", "(ILjava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateClob", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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
	{"updateNCharacterStream", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateNCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateNCharacterStream", "(ILjava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateNCharacterStream", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateNClob", "(ILjava/sql/NClob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateNClob", "(Ljava/lang/String;Ljava/sql/NClob;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateNClob", "(ILjava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateNClob", "(Ljava/lang/String;Ljava/io/Reader;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateNClob", "(ILjava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateNClob", "(Ljava/lang/String;Ljava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateNString", "(ILjava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateNString", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateNull", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateNull", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateObject", "(ILjava/lang/Object;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateObject", "(ILjava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateObject", "(Ljava/lang/String;Ljava/lang/Object;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateObject", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateRef", "(ILjava/sql/Ref;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateRef", "(Ljava/lang/String;Ljava/sql/Ref;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateRowId", "(ILjava/sql/RowId;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateRowId", "(Ljava/lang/String;Ljava/sql/RowId;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateSQLXML", "(ILjava/sql/SQLXML;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateSQLXML", "(Ljava/lang/String;Ljava/sql/SQLXML;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateShort", "(IS)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateShort", "(Ljava/lang/String;S)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateString", "(ILjava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateString", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateTime", "(ILjava/sql/Time;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateTime", "(Ljava/lang/String;Ljava/sql/Time;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateTimestamp", "(ILjava/sql/Timestamp;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"updateTimestamp", "(Ljava/lang/String;Ljava/sql/Timestamp;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"wasNull", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{}
};

$ClassInfo _JdbcRowSetImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.rowset.JdbcRowSetImpl",
	"javax.sql.rowset.BaseRowSet",
	"javax.sql.rowset.JdbcRowSet",
	_JdbcRowSetImpl_FieldInfo_,
	_JdbcRowSetImpl_MethodInfo_
};

$Object* allocate$JdbcRowSetImpl($Class* clazz) {
	return $of($alloc(JdbcRowSetImpl));
}

void JdbcRowSetImpl::addRowSetListener($RowSetListener* listener) {
	this->$BaseRowSet::addRowSetListener(listener);
}

void JdbcRowSetImpl::removeRowSetListener($RowSetListener* listener) {
	this->$BaseRowSet::removeRowSetListener(listener);
}

$String* JdbcRowSetImpl::getCommand() {
	 return this->$BaseRowSet::getCommand();
}

$String* JdbcRowSetImpl::getUrl() {
	 return this->$BaseRowSet::getUrl();
}

$String* JdbcRowSetImpl::getDataSourceName() {
	 return this->$BaseRowSet::getDataSourceName();
}

$String* JdbcRowSetImpl::getUsername() {
	 return this->$BaseRowSet::getUsername();
}

$String* JdbcRowSetImpl::getPassword() {
	 return this->$BaseRowSet::getPassword();
}

bool JdbcRowSetImpl::isReadOnly() {
	 return this->$BaseRowSet::isReadOnly();
}

void JdbcRowSetImpl::setReadOnly(bool value) {
	this->$BaseRowSet::setReadOnly(value);
}

int32_t JdbcRowSetImpl::getTransactionIsolation() {
	 return this->$BaseRowSet::getTransactionIsolation();
}

void JdbcRowSetImpl::setTransactionIsolation(int32_t level) {
	this->$BaseRowSet::setTransactionIsolation(level);
}

$Map* JdbcRowSetImpl::getTypeMap() {
	 return this->$BaseRowSet::getTypeMap();
}

void JdbcRowSetImpl::setTypeMap($Map* map) {
	this->$BaseRowSet::setTypeMap(map);
}

int32_t JdbcRowSetImpl::getMaxFieldSize() {
	 return this->$BaseRowSet::getMaxFieldSize();
}

void JdbcRowSetImpl::setMaxFieldSize(int32_t max) {
	this->$BaseRowSet::setMaxFieldSize(max);
}

int32_t JdbcRowSetImpl::getMaxRows() {
	 return this->$BaseRowSet::getMaxRows();
}

void JdbcRowSetImpl::setMaxRows(int32_t max) {
	this->$BaseRowSet::setMaxRows(max);
}

void JdbcRowSetImpl::setEscapeProcessing(bool enable) {
	this->$BaseRowSet::setEscapeProcessing(enable);
}

int32_t JdbcRowSetImpl::getQueryTimeout() {
	 return this->$BaseRowSet::getQueryTimeout();
}

void JdbcRowSetImpl::setQueryTimeout(int32_t seconds) {
	this->$BaseRowSet::setQueryTimeout(seconds);
}

bool JdbcRowSetImpl::getShowDeleted() {
	 return this->$BaseRowSet::getShowDeleted();
}

void JdbcRowSetImpl::setShowDeleted(bool value) {
	this->$BaseRowSet::setShowDeleted(value);
}

bool JdbcRowSetImpl::getEscapeProcessing() {
	 return this->$BaseRowSet::getEscapeProcessing();
}

int32_t JdbcRowSetImpl::getFetchSize() {
	 return this->$BaseRowSet::getFetchSize();
}

void JdbcRowSetImpl::setNull(int32_t parameterIndex, int32_t sqlType) {
	this->$BaseRowSet::setNull(parameterIndex, sqlType);
}

void JdbcRowSetImpl::setNull(int32_t parameterIndex, int32_t sqlType, $String* typeName) {
	this->$BaseRowSet::setNull(parameterIndex, sqlType, typeName);
}

void JdbcRowSetImpl::setBoolean(int32_t parameterIndex, bool x) {
	this->$BaseRowSet::setBoolean(parameterIndex, x);
}

void JdbcRowSetImpl::setByte(int32_t parameterIndex, int8_t x) {
	this->$BaseRowSet::setByte(parameterIndex, x);
}

void JdbcRowSetImpl::setShort(int32_t parameterIndex, int16_t x) {
	this->$BaseRowSet::setShort(parameterIndex, x);
}

void JdbcRowSetImpl::setInt(int32_t parameterIndex, int32_t x) {
	this->$BaseRowSet::setInt(parameterIndex, x);
}

void JdbcRowSetImpl::setLong(int32_t parameterIndex, int64_t x) {
	this->$BaseRowSet::setLong(parameterIndex, x);
}

void JdbcRowSetImpl::setFloat(int32_t parameterIndex, float x) {
	this->$BaseRowSet::setFloat(parameterIndex, x);
}

void JdbcRowSetImpl::setDouble(int32_t parameterIndex, double x) {
	this->$BaseRowSet::setDouble(parameterIndex, x);
}

void JdbcRowSetImpl::setBigDecimal(int32_t parameterIndex, $BigDecimal* x) {
	this->$BaseRowSet::setBigDecimal(parameterIndex, x);
}

void JdbcRowSetImpl::setString(int32_t parameterIndex, $String* x) {
	this->$BaseRowSet::setString(parameterIndex, x);
}

void JdbcRowSetImpl::setBytes(int32_t parameterIndex, $bytes* x) {
	this->$BaseRowSet::setBytes(parameterIndex, x);
}

void JdbcRowSetImpl::setDate(int32_t parameterIndex, $Date* x) {
	this->$BaseRowSet::setDate(parameterIndex, x);
}

void JdbcRowSetImpl::setTime(int32_t parameterIndex, $Time* x) {
	this->$BaseRowSet::setTime(parameterIndex, x);
}

void JdbcRowSetImpl::setTimestamp(int32_t parameterIndex, $Timestamp* x) {
	this->$BaseRowSet::setTimestamp(parameterIndex, x);
}

void JdbcRowSetImpl::setAsciiStream(int32_t parameterIndex, $InputStream* x, int32_t length) {
	this->$BaseRowSet::setAsciiStream(parameterIndex, x, length);
}

void JdbcRowSetImpl::setAsciiStream(int32_t parameterIndex, $InputStream* x) {
	this->$BaseRowSet::setAsciiStream(parameterIndex, x);
}

void JdbcRowSetImpl::setBinaryStream(int32_t parameterIndex, $InputStream* x, int32_t length) {
	this->$BaseRowSet::setBinaryStream(parameterIndex, x, length);
}

void JdbcRowSetImpl::setBinaryStream(int32_t parameterIndex, $InputStream* x) {
	this->$BaseRowSet::setBinaryStream(parameterIndex, x);
}

void JdbcRowSetImpl::setCharacterStream(int32_t parameterIndex, $Reader* reader, int32_t length) {
	this->$BaseRowSet::setCharacterStream(parameterIndex, reader, length);
}

void JdbcRowSetImpl::setCharacterStream(int32_t parameterIndex, $Reader* reader) {
	this->$BaseRowSet::setCharacterStream(parameterIndex, reader);
}

void JdbcRowSetImpl::setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType, int32_t scale) {
	this->$BaseRowSet::setObject(parameterIndex, x, targetSqlType, scale);
}

void JdbcRowSetImpl::setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType) {
	this->$BaseRowSet::setObject(parameterIndex, x, targetSqlType);
}

void JdbcRowSetImpl::setObject(int32_t parameterIndex, Object$* x) {
	this->$BaseRowSet::setObject(parameterIndex, x);
}

void JdbcRowSetImpl::setRef(int32_t parameterIndex, $Ref* ref) {
	this->$BaseRowSet::setRef(parameterIndex, ref);
}

void JdbcRowSetImpl::setBlob(int32_t parameterIndex, $Blob* x) {
	this->$BaseRowSet::setBlob(parameterIndex, x);
}

void JdbcRowSetImpl::setClob(int32_t parameterIndex, $Clob* x) {
	this->$BaseRowSet::setClob(parameterIndex, x);
}

void JdbcRowSetImpl::setArray(int32_t parameterIndex, $1Array* array) {
	this->$BaseRowSet::setArray(parameterIndex, array);
}

void JdbcRowSetImpl::setDate(int32_t parameterIndex, $Date* x, $Calendar* cal) {
	this->$BaseRowSet::setDate(parameterIndex, x, cal);
}

void JdbcRowSetImpl::setTime(int32_t parameterIndex, $Time* x, $Calendar* cal) {
	this->$BaseRowSet::setTime(parameterIndex, x, cal);
}

void JdbcRowSetImpl::setTimestamp(int32_t parameterIndex, $Timestamp* x, $Calendar* cal) {
	this->$BaseRowSet::setTimestamp(parameterIndex, x, cal);
}

void JdbcRowSetImpl::clearParameters() {
	this->$BaseRowSet::clearParameters();
}

int32_t JdbcRowSetImpl::hashCode() {
	 return this->$BaseRowSet::hashCode();
}

bool JdbcRowSetImpl::equals(Object$* arg0) {
	 return this->$BaseRowSet::equals(arg0);
}

$Object* JdbcRowSetImpl::clone() {
	 return this->$BaseRowSet::clone();
}

$String* JdbcRowSetImpl::toString() {
	 return this->$BaseRowSet::toString();
}

void JdbcRowSetImpl::finalize() {
	this->$BaseRowSet::finalize();
}

void JdbcRowSetImpl::init$() {
	$useLocalCurrentObjectStackCache();
	$BaseRowSet::init$();
	$set(this, conn, nullptr);
	$set(this, ps, nullptr);
	$set(this, rs, nullptr);
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
	initParams();
	try {
		setShowDeleted(false);
	} catch ($SQLException& sqle) {
		$var($String, var$0, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.setshowdeleted"_s))))->toString()));
		$nc($System::err)->println($$concat(var$0, $(sqle->getLocalizedMessage())));
	}
	try {
		setQueryTimeout(0);
	} catch ($SQLException& sqle) {
		$var($String, var$1, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.setquerytimeout"_s))))->toString()));
		$nc($System::err)->println($$concat(var$1, $(sqle->getLocalizedMessage())));
	}
	try {
		setMaxRows(0);
	} catch ($SQLException& sqle) {
		$var($String, var$2, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.setmaxrows"_s))))->toString()));
		$nc($System::err)->println($$concat(var$2, $(sqle->getLocalizedMessage())));
	}
	try {
		setMaxFieldSize(0);
	} catch ($SQLException& sqle) {
		$var($String, var$3, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.setmaxfieldsize"_s))))->toString()));
		$nc($System::err)->println($$concat(var$3, $(sqle->getLocalizedMessage())));
	}
	try {
		setEscapeProcessing(true);
	} catch ($SQLException& sqle) {
		$var($String, var$4, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.setescapeprocessing"_s))))->toString()));
		$nc($System::err)->println($$concat(var$4, $(sqle->getLocalizedMessage())));
	}
	try {
		setConcurrency($ResultSet::CONCUR_UPDATABLE);
	} catch ($SQLException& sqle) {
		$var($String, var$5, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.setconcurrency"_s))))->toString()));
		$nc($System::err)->println($$concat(var$5, $(sqle->getLocalizedMessage())));
	}
	setTypeMap(nullptr);
	try {
		setType($ResultSet::TYPE_SCROLL_INSENSITIVE);
	} catch ($SQLException& sqle) {
		$var($String, var$6, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.settype"_s))))->toString()));
		$nc($System::err)->println($$concat(var$6, $(sqle->getLocalizedMessage())));
	}
	setReadOnly(true);
	try {
		setTransactionIsolation($Connection::TRANSACTION_READ_COMMITTED);
	} catch ($SQLException& sqle) {
		$var($String, var$7, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.settransactionisolation"_s))))->toString()));
		$nc($System::err)->println($$concat(var$7, $(sqle->getLocalizedMessage())));
	}
	$set(this, iMatchColumns, $new($Vector, 10));
	for (int32_t i = 0; i < 10; ++i) {
		$nc(this->iMatchColumns)->add(i, $($Integer::valueOf(-1)));
	}
	$set(this, strMatchColumns, $new($Vector, 10));
	for (int32_t j = 0; j < 10; ++j) {
		$nc(this->strMatchColumns)->add(j, nullptr);
	}
}

void JdbcRowSetImpl::init$($Connection* con) {
	$useLocalCurrentObjectStackCache();
	$BaseRowSet::init$();
	$set(this, conn, con);
	$set(this, ps, nullptr);
	$set(this, rs, nullptr);
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
	initParams();
	setShowDeleted(false);
	setQueryTimeout(0);
	setMaxRows(0);
	setMaxFieldSize(0);
	setParams();
	setReadOnly(true);
	setTransactionIsolation($Connection::TRANSACTION_READ_COMMITTED);
	setEscapeProcessing(true);
	setTypeMap(nullptr);
	$set(this, iMatchColumns, $new($Vector, 10));
	for (int32_t i = 0; i < 10; ++i) {
		$nc(this->iMatchColumns)->add(i, $($Integer::valueOf(-1)));
	}
	$set(this, strMatchColumns, $new($Vector, 10));
	for (int32_t j = 0; j < 10; ++j) {
		$nc(this->strMatchColumns)->add(j, nullptr);
	}
}

void JdbcRowSetImpl::init$($String* url, $String* user, $String* password) {
	$useLocalCurrentObjectStackCache();
	$BaseRowSet::init$();
	$set(this, conn, nullptr);
	$set(this, ps, nullptr);
	$set(this, rs, nullptr);
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
	initParams();
	setUsername(user);
	setPassword(password);
	setUrl(url);
	setShowDeleted(false);
	setQueryTimeout(0);
	setMaxRows(0);
	setMaxFieldSize(0);
	setParams();
	setReadOnly(true);
	setTransactionIsolation($Connection::TRANSACTION_READ_COMMITTED);
	setEscapeProcessing(true);
	setTypeMap(nullptr);
	$set(this, iMatchColumns, $new($Vector, 10));
	for (int32_t i = 0; i < 10; ++i) {
		$nc(this->iMatchColumns)->add(i, $($Integer::valueOf(-1)));
	}
	$set(this, strMatchColumns, $new($Vector, 10));
	for (int32_t j = 0; j < 10; ++j) {
		$nc(this->strMatchColumns)->add(j, nullptr);
	}
}

void JdbcRowSetImpl::init$($ResultSet* res) {
	$useLocalCurrentObjectStackCache();
	$BaseRowSet::init$();
	$set(this, conn, nullptr);
	$set(this, ps, nullptr);
	$set(this, rs, res);
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
	initParams();
	setShowDeleted(false);
	setQueryTimeout(0);
	setMaxRows(0);
	setMaxFieldSize(0);
	setParams();
	setReadOnly(true);
	setTransactionIsolation($Connection::TRANSACTION_READ_COMMITTED);
	setEscapeProcessing(true);
	setTypeMap(nullptr);
	$set(this, resMD, $nc(this->rs)->getMetaData());
	$set(this, rowsMD, $new($RowSetMetaDataImpl));
	initMetaData(this->rowsMD, this->resMD);
	$set(this, iMatchColumns, $new($Vector, 10));
	for (int32_t i = 0; i < 10; ++i) {
		$nc(this->iMatchColumns)->add(i, $($Integer::valueOf(-1)));
	}
	$set(this, strMatchColumns, $new($Vector, 10));
	for (int32_t j = 0; j < 10; ++j) {
		$nc(this->strMatchColumns)->add(j, nullptr);
	}
}

void JdbcRowSetImpl::initMetaData($RowSetMetaData* md, $ResultSetMetaData* rsmd) {
	$useLocalCurrentObjectStackCache();
	int32_t numCols = $nc(rsmd)->getColumnCount();
	$nc(md)->setColumnCount(numCols);
	for (int32_t col = 1; col <= numCols; ++col) {
		md->setAutoIncrement(col, rsmd->isAutoIncrement(col));
		md->setCaseSensitive(col, rsmd->isCaseSensitive(col));
		md->setCurrency(col, rsmd->isCurrency(col));
		md->setNullable(col, rsmd->isNullable(col));
		md->setSigned(col, rsmd->isSigned(col));
		md->setSearchable(col, rsmd->isSearchable(col));
		md->setColumnDisplaySize(col, rsmd->getColumnDisplaySize(col));
		md->setColumnLabel(col, $(rsmd->getColumnLabel(col)));
		md->setColumnName(col, $(rsmd->getColumnName(col)));
		md->setSchemaName(col, $(rsmd->getSchemaName(col)));
		md->setPrecision(col, rsmd->getPrecision(col));
		md->setScale(col, rsmd->getScale(col));
		md->setTableName(col, $(rsmd->getTableName(col)));
		md->setCatalogName(col, $(rsmd->getCatalogName(col)));
		md->setColumnType(col, rsmd->getColumnType(col));
		md->setColumnTypeName(col, $(rsmd->getColumnTypeName(col)));
	}
}

void JdbcRowSetImpl::checkState() {
	$useLocalCurrentObjectStackCache();
	if (this->conn == nullptr && this->ps == nullptr && this->rs == nullptr) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.invalstate"_s))))->toString()));
	}
}

void JdbcRowSetImpl::execute() {
	prepare();
	setProperties(this->ps);
	decodeParams($(getParams()), this->ps);
	$set(this, rs, $nc(this->ps)->executeQuery());
	notifyRowSetChanged();
}

void JdbcRowSetImpl::setProperties($PreparedStatement* ps) {
	$useLocalCurrentObjectStackCache();
	try {
		$nc(ps)->setEscapeProcessing(getEscapeProcessing());
	} catch ($SQLException& ex) {
		$var($String, var$0, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.setescapeprocessing"_s))))->toString()));
		$nc($System::err)->println($$concat(var$0, $(ex->getLocalizedMessage())));
	}
	try {
		$nc(ps)->setMaxFieldSize(getMaxFieldSize());
	} catch ($SQLException& ex) {
		$var($String, var$1, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.setmaxfieldsize"_s))))->toString()));
		$nc($System::err)->println($$concat(var$1, $(ex->getLocalizedMessage())));
	}
	try {
		$nc(ps)->setMaxRows(getMaxRows());
	} catch ($SQLException& ex) {
		$var($String, var$2, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.setmaxrows"_s))))->toString()));
		$nc($System::err)->println($$concat(var$2, $(ex->getLocalizedMessage())));
	}
	try {
		$nc(ps)->setQueryTimeout(getQueryTimeout());
	} catch ($SQLException& ex) {
		$var($String, var$3, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.setquerytimeout"_s))))->toString()));
		$nc($System::err)->println($$concat(var$3, $(ex->getLocalizedMessage())));
	}
}

$Connection* JdbcRowSetImpl::connect() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->conn != nullptr) {
		return this->conn;
	} else if (getDataSourceName() != nullptr) {
		try {
			$var($Context, ctx, $new($InitialContext));
			$var($DataSource, ds, $cast($DataSource, ctx->lookup($(getDataSourceName()))));
			bool var$0 = getUsername() != nullptr;
			if (var$0 && !$nc($(getUsername()))->isEmpty()) {
				$var($String, var$1, getUsername());
				return $nc(ds)->getConnection(var$1, $(getPassword()));
			} else {
				return $nc(ds)->getConnection();
			}
		} catch ($NamingException& ex) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.connect"_s))))->toString()));
		}
	} else if (getUrl() != nullptr) {
		$var($String, var$2, getUrl());
		$var($String, var$3, getUsername());
		return $DriverManager::getConnection(var$2, var$3, $(getPassword()));
	} else {
		return nullptr;
	}
}

$PreparedStatement* JdbcRowSetImpl::prepare() {
	$useLocalCurrentObjectStackCache();
	$set(this, conn, connect());
	try {
		$var($Map, aMap, getTypeMap());
		if (aMap != nullptr) {
			$nc(this->conn)->setTypeMap(aMap);
		}
		$set(this, ps, $nc(this->conn)->prepareStatement($(getCommand()), $ResultSet::TYPE_SCROLL_INSENSITIVE, $ResultSet::CONCUR_UPDATABLE));
	} catch ($SQLException& ex) {
		$var($String, var$0, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.prepare"_s))))->toString()));
		$nc($System::err)->println($$concat(var$0, $(ex->getLocalizedMessage())));
		if (this->ps != nullptr) {
			$nc(this->ps)->close();
		}
		if (this->conn != nullptr) {
			$nc(this->conn)->close();
		}
		$throwNew($SQLException, $(ex->getMessage()));
	}
	return this->ps;
}

void JdbcRowSetImpl::decodeParams($ObjectArray* params, $PreparedStatement* ps) {
	$useLocalCurrentObjectStackCache();
	int32_t arraySize = 0;
	$var($ObjectArray, param, nullptr);
	for (int32_t i = 0; i < $nc(params)->length; ++i) {
		if ($instanceOf($ObjectArray, params->get(i))) {
			$assign(param, $cast($ObjectArray, params->get(i)));
			if ($nc(param)->length == 2) {
				if (param->get(0) == nullptr) {
					$nc(ps)->setNull(i + 1, $nc(($cast($Integer, param->get(1))))->intValue());
					continue;
				}
				if ($instanceOf($Date, param->get(0)) || $instanceOf($Time, param->get(0)) || $instanceOf($Timestamp, param->get(0))) {
					$nc($System::err)->println($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.detecteddate"_s)));
					if ($instanceOf($Calendar, param->get(1))) {
						$nc($System::err)->println($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.detectedcalendar"_s)));
						$nc(ps)->setDate(i + 1, $cast($Date, param->get(0)), $cast($Calendar, param->get(1)));
						continue;
					} else {
						$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.paramtype"_s))))->toString()));
					}
				}
				if ($instanceOf($Reader, param->get(0))) {
					$nc(ps)->setCharacterStream(i + 1, $cast($Reader, param->get(0)), $nc(($cast($Integer, param->get(1))))->intValue());
					continue;
				}
				if ($instanceOf($Integer, param->get(1))) {
					$nc(ps)->setObject(i + 1, param->get(0), $nc(($cast($Integer, param->get(1))))->intValue());
					continue;
				}
			} else if (param->length == 3) {
				if (param->get(0) == nullptr) {
					$nc(ps)->setNull(i + 1, $nc(($cast($Integer, param->get(1))))->intValue(), $cast($String, param->get(2)));
					continue;
				}
				if ($instanceOf($InputStream, param->get(0))) {
					switch ($nc(($cast($Integer, param->get(2))))->intValue()) {
					case JdbcRowSetImpl::UNICODE_STREAM_PARAM:
						{
							$nc(ps)->setUnicodeStream(i + 1, $cast($InputStream, param->get(0)), $nc(($cast($Integer, param->get(1))))->intValue());
							break;
						}
					case JdbcRowSetImpl::BINARY_STREAM_PARAM:
						{
							$nc(ps)->setBinaryStream(i + 1, $cast($InputStream, param->get(0)), $nc(($cast($Integer, param->get(1))))->intValue());
							break;
						}
					case JdbcRowSetImpl::ASCII_STREAM_PARAM:
						{
							$nc(ps)->setAsciiStream(i + 1, $cast($InputStream, param->get(0)), $nc(($cast($Integer, param->get(1))))->intValue());
							break;
						}
					default:
						{
							$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.paramtype"_s))))->toString()));
						}
					}
				}
				if ($instanceOf($Integer, param->get(1)) && $instanceOf($Integer, param->get(2))) {
					int32_t var$0 = i + 1;
					$var($Object, var$1, param->get(0));
					int32_t var$2 = $nc(($cast($Integer, param->get(1))))->intValue();
					$nc(ps)->setObject(var$0, var$1, var$2, $nc(($cast($Integer, param->get(2))))->intValue());
					continue;
				}
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.paramtype"_s))))->toString()));
			} else {
				$nc(ps)->setObject(i + 1, params->get(i));
				continue;
			}
		} else {
			$nc(ps)->setObject(i + 1, params->get(i));
		}
	}
}

bool JdbcRowSetImpl::next() {
	checkState();
	bool b = $nc(this->rs)->next();
	notifyCursorMoved();
	return b;
}

void JdbcRowSetImpl::close() {
	if (this->rs != nullptr) {
		$nc(this->rs)->close();
	}
	if (this->ps != nullptr) {
		$nc(this->ps)->close();
	}
	if (this->conn != nullptr) {
		$nc(this->conn)->close();
	}
}

bool JdbcRowSetImpl::wasNull() {
	checkState();
	return $nc(this->rs)->wasNull();
}

$String* JdbcRowSetImpl::getString(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getString(columnIndex);
}

bool JdbcRowSetImpl::getBoolean(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getBoolean(columnIndex);
}

int8_t JdbcRowSetImpl::getByte(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getByte(columnIndex);
}

int16_t JdbcRowSetImpl::getShort(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getShort(columnIndex);
}

int32_t JdbcRowSetImpl::getInt(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getInt(columnIndex);
}

int64_t JdbcRowSetImpl::getLong(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getLong(columnIndex);
}

float JdbcRowSetImpl::getFloat(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getFloat(columnIndex);
}

double JdbcRowSetImpl::getDouble(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getDouble(columnIndex);
}

$BigDecimal* JdbcRowSetImpl::getBigDecimal(int32_t columnIndex, int32_t scale) {
	checkState();
	return $nc(this->rs)->getBigDecimal(columnIndex, scale);
}

$bytes* JdbcRowSetImpl::getBytes(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getBytes(columnIndex);
}

$Date* JdbcRowSetImpl::getDate(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getDate(columnIndex);
}

$Time* JdbcRowSetImpl::getTime(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getTime(columnIndex);
}

$Timestamp* JdbcRowSetImpl::getTimestamp(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getTimestamp(columnIndex);
}

$InputStream* JdbcRowSetImpl::getAsciiStream(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getAsciiStream(columnIndex);
}

$InputStream* JdbcRowSetImpl::getUnicodeStream(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getUnicodeStream(columnIndex);
}

$InputStream* JdbcRowSetImpl::getBinaryStream(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getBinaryStream(columnIndex);
}

$String* JdbcRowSetImpl::getString($String* columnName) {
	return getString(findColumn(columnName));
}

bool JdbcRowSetImpl::getBoolean($String* columnName) {
	return getBoolean(findColumn(columnName));
}

int8_t JdbcRowSetImpl::getByte($String* columnName) {
	return getByte(findColumn(columnName));
}

int16_t JdbcRowSetImpl::getShort($String* columnName) {
	return getShort(findColumn(columnName));
}

int32_t JdbcRowSetImpl::getInt($String* columnName) {
	return getInt(findColumn(columnName));
}

int64_t JdbcRowSetImpl::getLong($String* columnName) {
	return getLong(findColumn(columnName));
}

float JdbcRowSetImpl::getFloat($String* columnName) {
	return getFloat(findColumn(columnName));
}

double JdbcRowSetImpl::getDouble($String* columnName) {
	return getDouble(findColumn(columnName));
}

$BigDecimal* JdbcRowSetImpl::getBigDecimal($String* columnName, int32_t scale) {
	return getBigDecimal(findColumn(columnName), scale);
}

$bytes* JdbcRowSetImpl::getBytes($String* columnName) {
	return getBytes(findColumn(columnName));
}

$Date* JdbcRowSetImpl::getDate($String* columnName) {
	return getDate(findColumn(columnName));
}

$Time* JdbcRowSetImpl::getTime($String* columnName) {
	return getTime(findColumn(columnName));
}

$Timestamp* JdbcRowSetImpl::getTimestamp($String* columnName) {
	return getTimestamp(findColumn(columnName));
}

$InputStream* JdbcRowSetImpl::getAsciiStream($String* columnName) {
	return getAsciiStream(findColumn(columnName));
}

$InputStream* JdbcRowSetImpl::getUnicodeStream($String* columnName) {
	return getUnicodeStream(findColumn(columnName));
}

$InputStream* JdbcRowSetImpl::getBinaryStream($String* columnName) {
	return getBinaryStream(findColumn(columnName));
}

$SQLWarning* JdbcRowSetImpl::getWarnings() {
	checkState();
	return $nc(this->rs)->getWarnings();
}

void JdbcRowSetImpl::clearWarnings() {
	checkState();
	$nc(this->rs)->clearWarnings();
}

$String* JdbcRowSetImpl::getCursorName() {
	checkState();
	return $nc(this->rs)->getCursorName();
}

$ResultSetMetaData* JdbcRowSetImpl::getMetaData() {
	checkState();
	try {
		checkState();
	} catch ($SQLException& sqle) {
		prepare();
		return $nc(this->ps)->getMetaData();
	}
	return $nc(this->rs)->getMetaData();
}

$Object* JdbcRowSetImpl::getObject(int32_t columnIndex) {
	checkState();
	return $of($nc(this->rs)->getObject(columnIndex));
}

$Object* JdbcRowSetImpl::getObject($String* columnName) {
	return $of(getObject(findColumn(columnName)));
}

int32_t JdbcRowSetImpl::findColumn($String* columnName) {
	checkState();
	return $nc(this->rs)->findColumn(columnName);
}

$Reader* JdbcRowSetImpl::getCharacterStream(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getCharacterStream(columnIndex);
}

$Reader* JdbcRowSetImpl::getCharacterStream($String* columnName) {
	return getCharacterStream(findColumn(columnName));
}

$BigDecimal* JdbcRowSetImpl::getBigDecimal(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getBigDecimal(columnIndex);
}

$BigDecimal* JdbcRowSetImpl::getBigDecimal($String* columnName) {
	return getBigDecimal(findColumn(columnName));
}

bool JdbcRowSetImpl::isBeforeFirst() {
	checkState();
	return $nc(this->rs)->isBeforeFirst();
}

bool JdbcRowSetImpl::isAfterLast() {
	checkState();
	return $nc(this->rs)->isAfterLast();
}

bool JdbcRowSetImpl::isFirst() {
	checkState();
	return $nc(this->rs)->isFirst();
}

bool JdbcRowSetImpl::isLast() {
	checkState();
	return $nc(this->rs)->isLast();
}

void JdbcRowSetImpl::beforeFirst() {
	checkState();
	$nc(this->rs)->beforeFirst();
	notifyCursorMoved();
}

void JdbcRowSetImpl::afterLast() {
	checkState();
	$nc(this->rs)->afterLast();
	notifyCursorMoved();
}

bool JdbcRowSetImpl::first() {
	checkState();
	bool b = $nc(this->rs)->first();
	notifyCursorMoved();
	return b;
}

bool JdbcRowSetImpl::last() {
	checkState();
	bool b = $nc(this->rs)->last();
	notifyCursorMoved();
	return b;
}

int32_t JdbcRowSetImpl::getRow() {
	checkState();
	return $nc(this->rs)->getRow();
}

bool JdbcRowSetImpl::absolute(int32_t row) {
	checkState();
	bool b = $nc(this->rs)->absolute(row);
	notifyCursorMoved();
	return b;
}

bool JdbcRowSetImpl::relative(int32_t rows) {
	checkState();
	bool b = $nc(this->rs)->relative(rows);
	notifyCursorMoved();
	return b;
}

bool JdbcRowSetImpl::previous() {
	checkState();
	bool b = $nc(this->rs)->previous();
	notifyCursorMoved();
	return b;
}

void JdbcRowSetImpl::setFetchDirection(int32_t direction) {
	checkState();
	$nc(this->rs)->setFetchDirection(direction);
}

int32_t JdbcRowSetImpl::getFetchDirection() {
	try {
		checkState();
	} catch ($SQLException& sqle) {
		$BaseRowSet::getFetchDirection();
	}
	return $nc(this->rs)->getFetchDirection();
}

void JdbcRowSetImpl::setFetchSize(int32_t rows) {
	checkState();
	$nc(this->rs)->setFetchSize(rows);
}

int32_t JdbcRowSetImpl::getType() {
	try {
		checkState();
	} catch ($SQLException& sqle) {
		return $BaseRowSet::getType();
	}
	if (this->rs == nullptr) {
		return $BaseRowSet::getType();
	} else {
		int32_t rstype = $nc(this->rs)->getType();
		return rstype;
	}
}

int32_t JdbcRowSetImpl::getConcurrency() {
	try {
		checkState();
	} catch ($SQLException& sqle) {
		$BaseRowSet::getConcurrency();
	}
	return $nc(this->rs)->getConcurrency();
}

bool JdbcRowSetImpl::rowUpdated() {
	checkState();
	return $nc(this->rs)->rowUpdated();
}

bool JdbcRowSetImpl::rowInserted() {
	checkState();
	return $nc(this->rs)->rowInserted();
}

bool JdbcRowSetImpl::rowDeleted() {
	checkState();
	return $nc(this->rs)->rowDeleted();
}

void JdbcRowSetImpl::updateNull(int32_t columnIndex) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateNull(columnIndex);
}

void JdbcRowSetImpl::updateBoolean(int32_t columnIndex, bool x) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateBoolean(columnIndex, x);
}

void JdbcRowSetImpl::updateByte(int32_t columnIndex, int8_t x) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateByte(columnIndex, x);
}

void JdbcRowSetImpl::updateShort(int32_t columnIndex, int16_t x) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateShort(columnIndex, x);
}

void JdbcRowSetImpl::updateInt(int32_t columnIndex, int32_t x) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateInt(columnIndex, x);
}

void JdbcRowSetImpl::updateLong(int32_t columnIndex, int64_t x) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateLong(columnIndex, x);
}

void JdbcRowSetImpl::updateFloat(int32_t columnIndex, float x) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateFloat(columnIndex, x);
}

void JdbcRowSetImpl::updateDouble(int32_t columnIndex, double x) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateDouble(columnIndex, x);
}

void JdbcRowSetImpl::updateBigDecimal(int32_t columnIndex, $BigDecimal* x) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateBigDecimal(columnIndex, x);
}

void JdbcRowSetImpl::updateString(int32_t columnIndex, $String* x) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateString(columnIndex, x);
}

void JdbcRowSetImpl::updateBytes(int32_t columnIndex, $bytes* x) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateBytes(columnIndex, x);
}

void JdbcRowSetImpl::updateDate(int32_t columnIndex, $Date* x) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateDate(columnIndex, x);
}

void JdbcRowSetImpl::updateTime(int32_t columnIndex, $Time* x) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateTime(columnIndex, x);
}

void JdbcRowSetImpl::updateTimestamp(int32_t columnIndex, $Timestamp* x) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateTimestamp(columnIndex, x);
}

void JdbcRowSetImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x, int32_t length) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateAsciiStream(columnIndex, x, length);
}

void JdbcRowSetImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x, int32_t length) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateBinaryStream(columnIndex, x, length);
}

void JdbcRowSetImpl::updateCharacterStream(int32_t columnIndex, $Reader* x, int32_t length) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateCharacterStream(columnIndex, x, length);
}

void JdbcRowSetImpl::updateObject(int32_t columnIndex, Object$* x, int32_t scale) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateObject(columnIndex, x, scale);
}

void JdbcRowSetImpl::updateObject(int32_t columnIndex, Object$* x) {
	checkState();
	checkTypeConcurrency();
	$nc(this->rs)->updateObject(columnIndex, x);
}

void JdbcRowSetImpl::updateNull($String* columnName) {
	updateNull(findColumn(columnName));
}

void JdbcRowSetImpl::updateBoolean($String* columnName, bool x) {
	updateBoolean(findColumn(columnName), x);
}

void JdbcRowSetImpl::updateByte($String* columnName, int8_t x) {
	updateByte(findColumn(columnName), x);
}

void JdbcRowSetImpl::updateShort($String* columnName, int16_t x) {
	updateShort(findColumn(columnName), x);
}

void JdbcRowSetImpl::updateInt($String* columnName, int32_t x) {
	updateInt(findColumn(columnName), x);
}

void JdbcRowSetImpl::updateLong($String* columnName, int64_t x) {
	updateLong(findColumn(columnName), x);
}

void JdbcRowSetImpl::updateFloat($String* columnName, float x) {
	updateFloat(findColumn(columnName), x);
}

void JdbcRowSetImpl::updateDouble($String* columnName, double x) {
	updateDouble(findColumn(columnName), x);
}

void JdbcRowSetImpl::updateBigDecimal($String* columnName, $BigDecimal* x) {
	updateBigDecimal(findColumn(columnName), x);
}

void JdbcRowSetImpl::updateString($String* columnName, $String* x) {
	updateString(findColumn(columnName), x);
}

void JdbcRowSetImpl::updateBytes($String* columnName, $bytes* x) {
	updateBytes(findColumn(columnName), x);
}

void JdbcRowSetImpl::updateDate($String* columnName, $Date* x) {
	updateDate(findColumn(columnName), x);
}

void JdbcRowSetImpl::updateTime($String* columnName, $Time* x) {
	updateTime(findColumn(columnName), x);
}

void JdbcRowSetImpl::updateTimestamp($String* columnName, $Timestamp* x) {
	updateTimestamp(findColumn(columnName), x);
}

void JdbcRowSetImpl::updateAsciiStream($String* columnName, $InputStream* x, int32_t length) {
	updateAsciiStream(findColumn(columnName), x, length);
}

void JdbcRowSetImpl::updateBinaryStream($String* columnName, $InputStream* x, int32_t length) {
	updateBinaryStream(findColumn(columnName), x, length);
}

void JdbcRowSetImpl::updateCharacterStream($String* columnName, $Reader* reader, int32_t length) {
	updateCharacterStream(findColumn(columnName), reader, length);
}

void JdbcRowSetImpl::updateObject($String* columnName, Object$* x, int32_t scale) {
	updateObject(findColumn(columnName), x, scale);
}

void JdbcRowSetImpl::updateObject($String* columnName, Object$* x) {
	updateObject(findColumn(columnName), x);
}

void JdbcRowSetImpl::insertRow() {
	checkState();
	$nc(this->rs)->insertRow();
	notifyRowChanged();
}

void JdbcRowSetImpl::updateRow() {
	checkState();
	$nc(this->rs)->updateRow();
	notifyRowChanged();
}

void JdbcRowSetImpl::deleteRow() {
	checkState();
	$nc(this->rs)->deleteRow();
	notifyRowChanged();
}

void JdbcRowSetImpl::refreshRow() {
	checkState();
	$nc(this->rs)->refreshRow();
}

void JdbcRowSetImpl::cancelRowUpdates() {
	checkState();
	$nc(this->rs)->cancelRowUpdates();
	notifyRowChanged();
}

void JdbcRowSetImpl::moveToInsertRow() {
	checkState();
	$nc(this->rs)->moveToInsertRow();
}

void JdbcRowSetImpl::moveToCurrentRow() {
	checkState();
	$nc(this->rs)->moveToCurrentRow();
}

$Statement* JdbcRowSetImpl::getStatement() {
	if (this->rs != nullptr) {
		return $nc(this->rs)->getStatement();
	} else {
		return nullptr;
	}
}

$Object* JdbcRowSetImpl::getObject(int32_t i, $Map* map) {
	checkState();
	return $of($nc(this->rs)->getObject(i, map));
}

$Ref* JdbcRowSetImpl::getRef(int32_t i) {
	checkState();
	return $nc(this->rs)->getRef(i);
}

$Blob* JdbcRowSetImpl::getBlob(int32_t i) {
	checkState();
	return $nc(this->rs)->getBlob(i);
}

$Clob* JdbcRowSetImpl::getClob(int32_t i) {
	checkState();
	return $nc(this->rs)->getClob(i);
}

$1Array* JdbcRowSetImpl::getArray(int32_t i) {
	checkState();
	return $nc(this->rs)->getArray(i);
}

$Object* JdbcRowSetImpl::getObject($String* colName, $Map* map) {
	return $of(getObject(findColumn(colName), map));
}

$Ref* JdbcRowSetImpl::getRef($String* colName) {
	return getRef(findColumn(colName));
}

$Blob* JdbcRowSetImpl::getBlob($String* colName) {
	return getBlob(findColumn(colName));
}

$Clob* JdbcRowSetImpl::getClob($String* colName) {
	return getClob(findColumn(colName));
}

$1Array* JdbcRowSetImpl::getArray($String* colName) {
	return getArray(findColumn(colName));
}

$Date* JdbcRowSetImpl::getDate(int32_t columnIndex, $Calendar* cal) {
	checkState();
	return $nc(this->rs)->getDate(columnIndex, cal);
}

$Date* JdbcRowSetImpl::getDate($String* columnName, $Calendar* cal) {
	return getDate(findColumn(columnName), cal);
}

$Time* JdbcRowSetImpl::getTime(int32_t columnIndex, $Calendar* cal) {
	checkState();
	return $nc(this->rs)->getTime(columnIndex, cal);
}

$Time* JdbcRowSetImpl::getTime($String* columnName, $Calendar* cal) {
	return getTime(findColumn(columnName), cal);
}

$Timestamp* JdbcRowSetImpl::getTimestamp(int32_t columnIndex, $Calendar* cal) {
	checkState();
	return $nc(this->rs)->getTimestamp(columnIndex, cal);
}

$Timestamp* JdbcRowSetImpl::getTimestamp($String* columnName, $Calendar* cal) {
	return getTimestamp(findColumn(columnName), cal);
}

void JdbcRowSetImpl::updateRef(int32_t columnIndex, $Ref* ref) {
	checkState();
	$nc(this->rs)->updateRef(columnIndex, ref);
}

void JdbcRowSetImpl::updateRef($String* columnName, $Ref* ref) {
	updateRef(findColumn(columnName), ref);
}

void JdbcRowSetImpl::updateClob(int32_t columnIndex, $Clob* c) {
	checkState();
	$nc(this->rs)->updateClob(columnIndex, c);
}

void JdbcRowSetImpl::updateClob($String* columnName, $Clob* c) {
	updateClob(findColumn(columnName), c);
}

void JdbcRowSetImpl::updateBlob(int32_t columnIndex, $Blob* b) {
	checkState();
	$nc(this->rs)->updateBlob(columnIndex, b);
}

void JdbcRowSetImpl::updateBlob($String* columnName, $Blob* b) {
	updateBlob(findColumn(columnName), b);
}

void JdbcRowSetImpl::updateArray(int32_t columnIndex, $1Array* a) {
	checkState();
	$nc(this->rs)->updateArray(columnIndex, a);
}

void JdbcRowSetImpl::updateArray($String* columnName, $1Array* a) {
	updateArray(findColumn(columnName), a);
}

$URL* JdbcRowSetImpl::getURL(int32_t columnIndex) {
	checkState();
	return $nc(this->rs)->getURL(columnIndex);
}

$URL* JdbcRowSetImpl::getURL($String* columnName) {
	return getURL(findColumn(columnName));
}

$RowSetWarning* JdbcRowSetImpl::getRowSetWarnings() {
	return nullptr;
}

void JdbcRowSetImpl::unsetMatchColumn($ints* columnIdxes) {
	$useLocalCurrentObjectStackCache();
	int32_t i_val = 0;
	for (int32_t j = 0; j < $nc(columnIdxes)->length; ++j) {
		i_val = ($Integer::parseInt($($nc(($cast($Integer, $($nc(this->iMatchColumns)->get(j)))))->toString())));
		if (columnIdxes->get(j) != i_val) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.matchcols"_s))))->toString()));
		}
	}
	for (int32_t i = 0; i < $nc(columnIdxes)->length; ++i) {
		$nc(this->iMatchColumns)->set(i, $($Integer::valueOf(-1)));
	}
}

void JdbcRowSetImpl::unsetMatchColumn($StringArray* columnIdxes) {
	$useLocalCurrentObjectStackCache();
	for (int32_t j = 0; j < $nc(columnIdxes)->length; ++j) {
		if (!$nc(columnIdxes->get(j))->equals($($nc(this->strMatchColumns)->get(j)))) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.matchcols"_s))))->toString()));
		}
	}
	for (int32_t i = 0; i < $nc(columnIdxes)->length; ++i) {
		$nc(this->strMatchColumns)->set(i, nullptr);
	}
}

$StringArray* JdbcRowSetImpl::getMatchColumnNames() {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, str_temp, $new($StringArray, $nc(this->strMatchColumns)->size()));
	if ($nc(this->strMatchColumns)->get(0) == nullptr) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.setmatchcols"_s))))->toString()));
	}
	$nc(this->strMatchColumns)->copyInto(str_temp);
	return str_temp;
}

$ints* JdbcRowSetImpl::getMatchColumnIndexes() {
	$useLocalCurrentObjectStackCache();
	$var($IntegerArray, int_temp, $new($IntegerArray, $nc(this->iMatchColumns)->size()));
	$var($ints, i_temp, $new($ints, $nc(this->iMatchColumns)->size()));
	int32_t i_val = 0;
	i_val = $nc(($cast($Integer, $($nc(this->iMatchColumns)->get(0)))))->intValue();
	if (i_val == -1) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.setmatchcols"_s))))->toString()));
	}
	$nc(this->iMatchColumns)->copyInto(int_temp);
	for (int32_t i = 0; i < int_temp->length; ++i) {
		i_temp->set(i, $nc((int_temp->get(i)))->intValue());
	}
	return i_temp;
}

void JdbcRowSetImpl::setMatchColumn($ints* columnIdxes) {
	$useLocalCurrentObjectStackCache();
	for (int32_t j = 0; j < $nc(columnIdxes)->length; ++j) {
		if (columnIdxes->get(j) < 0) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.matchcols1"_s))))->toString()));
		}
	}
	for (int32_t i = 0; i < $nc(columnIdxes)->length; ++i) {
		$nc(this->iMatchColumns)->add(i, $($Integer::valueOf(columnIdxes->get(i))));
	}
}

void JdbcRowSetImpl::setMatchColumn($StringArray* columnNames) {
	$useLocalCurrentObjectStackCache();
	for (int32_t j = 0; j < $nc(columnNames)->length; ++j) {
		if (columnNames->get(j) == nullptr || $nc(columnNames->get(j))->isEmpty()) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.matchcols2"_s))))->toString()));
		}
	}
	for (int32_t i = 0; i < $nc(columnNames)->length; ++i) {
		$nc(this->strMatchColumns)->add(i, columnNames->get(i));
	}
}

void JdbcRowSetImpl::setMatchColumn(int32_t columnIdx) {
	$useLocalCurrentObjectStackCache();
	if (columnIdx < 0) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.matchcols1"_s))))->toString()));
	} else {
		$nc(this->iMatchColumns)->set(0, $($Integer::valueOf(columnIdx)));
	}
}

void JdbcRowSetImpl::setMatchColumn($String* columnName$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, columnName, columnName$renamed);
	if (columnName == nullptr || $nc(($assign(columnName, $nc(columnName)->trim())))->isEmpty()) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.matchcols2"_s))))->toString()));
	} else {
		$nc(this->strMatchColumns)->set(0, columnName);
	}
}

void JdbcRowSetImpl::unsetMatchColumn(int32_t columnIdx) {
	$useLocalCurrentObjectStackCache();
	if (!$nc(($cast($Integer, $($nc(this->iMatchColumns)->get(0)))))->equals($($Integer::valueOf(columnIdx)))) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.unsetmatch"_s))))->toString()));
	} else if ($nc(this->strMatchColumns)->get(0) != nullptr) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.usecolname"_s))))->toString()));
	} else {
		$nc(this->iMatchColumns)->set(0, $($Integer::valueOf(-1)));
	}
}

void JdbcRowSetImpl::unsetMatchColumn($String* columnName$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, columnName, columnName$renamed);
	$assign(columnName, $nc(columnName)->trim());
	if (!($nc(($cast($String, $($nc(this->strMatchColumns)->get(0)))))->equals(columnName))) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.unsetmatch"_s))))->toString()));
	} else if ($nc(($cast($Integer, $($nc(this->iMatchColumns)->get(0)))))->intValue() > 0) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.usecolid"_s))))->toString()));
	} else {
		$nc(this->strMatchColumns)->set(0, nullptr);
	}
}

$DatabaseMetaData* JdbcRowSetImpl::getDatabaseMetaData() {
	$var($Connection, con, connect());
	return $nc(con)->getMetaData();
}

$ParameterMetaData* JdbcRowSetImpl::getParameterMetaData() {
	prepare();
	return ($nc(this->ps)->getParameterMetaData());
}

void JdbcRowSetImpl::commit() {
	$nc(this->conn)->commit();
	if ($nc(this->conn)->getHoldability() != $ResultSet::HOLD_CURSORS_OVER_COMMIT) {
		$set(this, rs, nullptr);
	}
}

void JdbcRowSetImpl::setAutoCommit(bool autoCommit) {
	if (this->conn != nullptr) {
		$nc(this->conn)->setAutoCommit(autoCommit);
	} else {
		$set(this, conn, connect());
		$nc(this->conn)->setAutoCommit(autoCommit);
	}
}

bool JdbcRowSetImpl::getAutoCommit() {
	return $nc(this->conn)->getAutoCommit();
}

void JdbcRowSetImpl::rollback() {
	$nc(this->conn)->rollback();
	$set(this, rs, nullptr);
}

void JdbcRowSetImpl::rollback($Savepoint* s) {
	$nc(this->conn)->rollback(s);
}

void JdbcRowSetImpl::setParams() {
	if (this->rs == nullptr) {
		setType($ResultSet::TYPE_SCROLL_INSENSITIVE);
		setConcurrency($ResultSet::CONCUR_UPDATABLE);
	} else {
		setType($nc(this->rs)->getType());
		setConcurrency($nc(this->rs)->getConcurrency());
	}
}

void JdbcRowSetImpl::checkTypeConcurrency() {
	$useLocalCurrentObjectStackCache();
	bool var$0 = $nc(this->rs)->getType() == $ResultSet::TYPE_FORWARD_ONLY;
	if (var$0 || $nc(this->rs)->getConcurrency() == $ResultSet::CONCUR_READ_ONLY) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.resnotupd"_s))))->toString()));
	}
}

$Connection* JdbcRowSetImpl::getConnection() {
	return this->conn;
}

void JdbcRowSetImpl::setConnection($Connection* connection) {
	$set(this, conn, connection);
}

$PreparedStatement* JdbcRowSetImpl::getPreparedStatement() {
	return this->ps;
}

void JdbcRowSetImpl::setPreparedStatement($PreparedStatement* preparedStatement) {
	$set(this, ps, preparedStatement);
}

$ResultSet* JdbcRowSetImpl::getResultSet() {
	checkState();
	return this->rs;
}

void JdbcRowSetImpl::setResultSet($ResultSet* resultSet) {
	$set(this, rs, resultSet);
}

void JdbcRowSetImpl::setCommand($String* command) {
	if (getCommand() != nullptr) {
		if (!$nc($(getCommand()))->equals(command)) {
			$BaseRowSet::setCommand(command);
			$set(this, ps, nullptr);
			$set(this, rs, nullptr);
		}
	} else {
		$BaseRowSet::setCommand(command);
	}
}

void JdbcRowSetImpl::setDataSourceName($String* dsName) {
	if (getDataSourceName() != nullptr) {
		if (!$nc($(getDataSourceName()))->equals(dsName)) {
			$BaseRowSet::setDataSourceName(dsName);
			$set(this, conn, nullptr);
			$set(this, ps, nullptr);
			$set(this, rs, nullptr);
		}
	} else {
		$BaseRowSet::setDataSourceName(dsName);
	}
}

void JdbcRowSetImpl::setUrl($String* url) {
	if (getUrl() != nullptr) {
		if (!$nc($(getUrl()))->equals(url)) {
			$BaseRowSet::setUrl(url);
			$set(this, conn, nullptr);
			$set(this, ps, nullptr);
			$set(this, rs, nullptr);
		}
	} else {
		$BaseRowSet::setUrl(url);
	}
}

void JdbcRowSetImpl::setUsername($String* uname) {
	if (getUsername() != nullptr) {
		if (!$nc($(getUsername()))->equals(uname)) {
			$BaseRowSet::setUsername(uname);
			$set(this, conn, nullptr);
			$set(this, ps, nullptr);
			$set(this, rs, nullptr);
		}
	} else {
		$BaseRowSet::setUsername(uname);
	}
}

void JdbcRowSetImpl::setPassword($String* password) {
	if (getPassword() != nullptr) {
		if (!$nc($(getPassword()))->equals(password)) {
			$BaseRowSet::setPassword(password);
			$set(this, conn, nullptr);
			$set(this, ps, nullptr);
			$set(this, rs, nullptr);
		}
	} else {
		$BaseRowSet::setPassword(password);
	}
}

void JdbcRowSetImpl::setType(int32_t type) {
	int32_t oldVal = 0;
	try {
		oldVal = getType();
	} catch ($SQLException& ex) {
		oldVal = 0;
	}
	if (oldVal != type) {
		$BaseRowSet::setType(type);
	}
}

void JdbcRowSetImpl::setConcurrency(int32_t concur) {
	int32_t oldVal = 0;
	try {
		oldVal = getConcurrency();
	} catch ($NullPointerException& ex) {
		oldVal = 0;
	}
	if (oldVal != concur) {
		$BaseRowSet::setConcurrency(concur);
	}
}

$SQLXML* JdbcRowSetImpl::getSQLXML(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
	$shouldNotReachHere();
}

$SQLXML* JdbcRowSetImpl::getSQLXML($String* colName) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
	$shouldNotReachHere();
}

$RowId* JdbcRowSetImpl::getRowId(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
	$shouldNotReachHere();
}

$RowId* JdbcRowSetImpl::getRowId($String* columnName) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
	$shouldNotReachHere();
}

void JdbcRowSetImpl::updateRowId(int32_t columnIndex, $RowId* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateRowId($String* columnName, $RowId* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

int32_t JdbcRowSetImpl::getHoldability() {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
	$shouldNotReachHere();
}

bool JdbcRowSetImpl::isClosed() {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
	$shouldNotReachHere();
}

void JdbcRowSetImpl::updateNString(int32_t columnIndex, $String* nString) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateNString($String* columnName, $String* nString) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateNClob(int32_t columnIndex, $NClob* nClob) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateNClob($String* columnName, $NClob* nClob) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

$NClob* JdbcRowSetImpl::getNClob(int32_t i) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
	$shouldNotReachHere();
}

$NClob* JdbcRowSetImpl::getNClob($String* colName) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
	$shouldNotReachHere();
}

$Object* JdbcRowSetImpl::unwrap($Class* iface) {
	return $of(nullptr);
}

bool JdbcRowSetImpl::isWrapperFor($Class* interfaces) {
	return false;
}

void JdbcRowSetImpl::setSQLXML(int32_t parameterIndex, $SQLXML* xmlObject) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setSQLXML($String* parameterName, $SQLXML* xmlObject) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setRowId(int32_t parameterIndex, $RowId* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setRowId($String* parameterName, $RowId* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setNString(int32_t parameterIndex, $String* value) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setNCharacterStream(int32_t parameterIndex, $Reader* value) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setNClob($String* parameterName, $NClob* value) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

$Reader* JdbcRowSetImpl::getNCharacterStream(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
	$shouldNotReachHere();
}

$Reader* JdbcRowSetImpl::getNCharacterStream($String* columnName) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
	$shouldNotReachHere();
}

void JdbcRowSetImpl::updateSQLXML(int32_t columnIndex, $SQLXML* xmlObject) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateSQLXML($String* columnName, $SQLXML* xmlObject) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

$String* JdbcRowSetImpl::getNString(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
	$shouldNotReachHere();
}

$String* JdbcRowSetImpl::getNString($String* columnName) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
	$shouldNotReachHere();
}

void JdbcRowSetImpl::updateNCharacterStream(int32_t columnIndex, $Reader* x, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateNCharacterStream($String* columnName, $Reader* x, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateNCharacterStream(int32_t columnIndex, $Reader* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateNCharacterStream($String* columnLabel, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateBlob(int32_t columnIndex, $InputStream* inputStream, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateBlob($String* columnLabel, $InputStream* inputStream, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateBlob(int32_t columnIndex, $InputStream* inputStream) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateBlob($String* columnLabel, $InputStream* inputStream) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateClob(int32_t columnIndex, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateClob($String* columnLabel, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateClob(int32_t columnIndex, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateClob($String* columnLabel, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateNClob(int32_t columnIndex, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateNClob($String* columnLabel, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateNClob(int32_t columnIndex, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateNClob($String* columnLabel, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateCharacterStream(int32_t columnIndex, $Reader* x, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateAsciiStream($String* columnLabel, $InputStream* x, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateAsciiStream($String* columnLabel, $InputStream* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateBinaryStream($String* columnLabel, $InputStream* x, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateBinaryStream($String* columnLabel, $InputStream* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateCharacterStream($String* columnLabel, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateCharacterStream(int32_t columnIndex, $Reader* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::updateCharacterStream($String* columnLabel, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setURL(int32_t parameterIndex, $URL* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setNClob(int32_t parameterIndex, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setNClob($String* parameterName, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setNClob($String* parameterName, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setNClob(int32_t parameterIndex, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setNClob(int32_t parameterIndex, $NClob* value) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setNString($String* parameterName, $String* value) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setNCharacterStream(int32_t parameterIndex, $Reader* value, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setNCharacterStream($String* parameterName, $Reader* value, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setNCharacterStream($String* parameterName, $Reader* value) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setTimestamp($String* parameterName, $Timestamp* x, $Calendar* cal) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setClob($String* parameterName, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setClob($String* parameterName, $Clob* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setClob($String* parameterName, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setDate($String* parameterName, $Date* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setDate($String* parameterName, $Date* x, $Calendar* cal) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setTime($String* parameterName, $Time* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setTime($String* parameterName, $Time* x, $Calendar* cal) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setClob(int32_t parameterIndex, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setClob(int32_t parameterIndex, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setBlob(int32_t parameterIndex, $InputStream* inputStream, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setBlob(int32_t parameterIndex, $InputStream* inputStream) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setBlob($String* parameterName, $InputStream* inputStream, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setBlob($String* parameterName, $Blob* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setBlob($String* parameterName, $InputStream* inputStream) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setObject($String* parameterName, Object$* x, int32_t targetSqlType, int32_t scale) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setObject($String* parameterName, Object$* x, int32_t targetSqlType) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setObject($String* parameterName, Object$* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setAsciiStream($String* parameterName, $InputStream* x, int32_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setBinaryStream($String* parameterName, $InputStream* x, int32_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setCharacterStream($String* parameterName, $Reader* reader, int32_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setAsciiStream($String* parameterName, $InputStream* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setBinaryStream($String* parameterName, $InputStream* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setCharacterStream($String* parameterName, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setBigDecimal($String* parameterName, $BigDecimal* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setString($String* parameterName, $String* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setBytes($String* parameterName, $bytes* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setTimestamp($String* parameterName, $Timestamp* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setNull($String* parameterName, int32_t sqlType) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setNull($String* parameterName, int32_t sqlType, $String* typeName) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setBoolean($String* parameterName, bool x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setByte($String* parameterName, int8_t x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setShort($String* parameterName, int16_t x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setInt($String* parameterName, int32_t x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setLong($String* parameterName, int64_t x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setFloat($String* parameterName, float x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::setDouble($String* parameterName, double x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("jdbcrowsetimpl.featnotsupp"_s))))->toString()));
}

void JdbcRowSetImpl::readObject($ObjectInputStream* ois) {
	$nc(ois)->defaultReadObject();
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
	}
}

$Object* JdbcRowSetImpl::getObject(int32_t columnIndex, $Class* type) {
	$throwNew($SQLFeatureNotSupportedException, "Not supported yet."_s);
	$shouldNotReachHere();
}

$Object* JdbcRowSetImpl::getObject($String* columnLabel, $Class* type) {
	$throwNew($SQLFeatureNotSupportedException, "Not supported yet."_s);
	$shouldNotReachHere();
}

JdbcRowSetImpl::JdbcRowSetImpl() {
}

$Class* JdbcRowSetImpl::load$($String* name, bool initialize) {
	$loadClass(JdbcRowSetImpl, name, initialize, &_JdbcRowSetImpl_ClassInfo_, allocate$JdbcRowSetImpl);
	return class$;
}

$Class* JdbcRowSetImpl::class$ = nullptr;

		} // rowset
	} // sun
} // com
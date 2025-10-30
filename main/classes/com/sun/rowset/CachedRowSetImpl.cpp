#include <com/sun/rowset/CachedRowSetImpl.h>

#include <com/sun/rowset/CachedRowSetImpl$1.h>
#include <com/sun/rowset/JdbcRowSetResourceBundle.h>
#include <com/sun/rowset/internal/BaseRow.h>
#include <com/sun/rowset/internal/CachedRowSetReader.h>
#include <com/sun/rowset/internal/CachedRowSetWriter.h>
#include <com/sun/rowset/internal/InsertRow.h>
#include <com/sun/rowset/internal/Row.h>
#include <com/sun/rowset/providers/RIOptimisticProvider.h>
#include <java/io/ByteArrayInputStream.h>
#include <java/io/ByteArrayOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/InputStreamReader.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/OptionalDataException.h>
#include <java/io/OutputStream.h>
#include <java/io/Reader.h>
#include <java/io/StreamCorruptedException.h>
#include <java/io/StringBufferInputStream.h>
#include <java/io/StringReader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityException.h>
#include <java/math/BigDecimal.h>
#include <java/net/URL.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/BasicPermission.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/sql/Array.h>
#include <java/sql/Blob.h>
#include <java/sql/Clob.h>
#include <java/sql/Connection.h>
#include <java/sql/DatabaseMetaData.h>
#include <java/sql/Date.h>
#include <java/sql/NClob.h>
#include <java/sql/Ref.h>
#include <java/sql/ResultSet.h>
#include <java/sql/ResultSetMetaData.h>
#include <java/sql/RowId.h>
#include <java/sql/SQLData.h>
#include <java/sql/SQLException.h>
#include <java/sql/SQLFeatureNotSupportedException.h>
#include <java/sql/SQLInput.h>
#include <java/sql/SQLWarning.h>
#include <java/sql/SQLXML.h>
#include <java/sql/Savepoint.h>
#include <java/sql/Statement.h>
#include <java/sql/Struct.h>
#include <java/sql/Time.h>
#include <java/sql/Timestamp.h>
#include <java/sql/Types.h>
#include <java/text/DateFormat.h>
#include <java/text/MessageFormat.h>
#include <java/text/ParseException.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractList.h>
#include <java/util/Arrays.h>
#include <java/util/Calendar.h>
#include <java/util/Collection.h>
#include <java/util/Date.h>
#include <java/util/Hashtable.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/TreeMap.h>
#include <java/util/Vector.h>
#include <javax/sql/RowSet.h>
#include <javax/sql/RowSetEvent.h>
#include <javax/sql/RowSetInternal.h>
#include <javax/sql/RowSetListener.h>
#include <javax/sql/RowSetMetaData.h>
#include <javax/sql/RowSetReader.h>
#include <javax/sql/RowSetWriter.h>
#include <javax/sql/rowset/BaseRowSet.h>
#include <javax/sql/rowset/CachedRowSet.h>
#include <javax/sql/rowset/RowSetMetaDataImpl.h>
#include <javax/sql/rowset/RowSetWarning.h>
#include <javax/sql/rowset/serial/SQLInputImpl.h>
#include <javax/sql/rowset/serial/SerialArray.h>
#include <javax/sql/rowset/serial/SerialBlob.h>
#include <javax/sql/rowset/serial/SerialClob.h>
#include <javax/sql/rowset/serial/SerialRef.h>
#include <javax/sql/rowset/serial/SerialStruct.h>
#include <javax/sql/rowset/spi/SyncFactory.h>
#include <javax/sql/rowset/spi/SyncFactoryException.h>
#include <javax/sql/rowset/spi/SyncProvider.h>
#include <javax/sql/rowset/spi/SyncProviderException.h>
#include <javax/sql/rowset/spi/TransactionalWriter.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <jcpp.h>

#undef ARRAY
#undef BIGINT
#undef BINARY
#undef BIT
#undef BLOB
#undef BOOLEAN
#undef CHAR
#undef CLOB
#undef CONCUR_READ_ONLY
#undef CONCUR_UPDATABLE
#undef DATALINK
#undef DATE
#undef DAY_OF_MONTH
#undef DECIMAL
#undef DEFAULT_SYNC_PROVIDER
#undef DOUBLE
#undef FLOAT
#undef HOUR_OF_DAY
#undef INTEGER
#undef LONGVARBINARY
#undef LONGVARCHAR
#undef MINUTE
#undef MONTH
#undef NUMERIC
#undef REAL
#undef REF
#undef ROWSET_SYNC_PROVIDER
#undef RSMD
#undef SECOND
#undef SMALLINT
#undef TIME
#undef TIMESTAMP
#undef TINYINT
#undef TRANSACTION_READ_COMMITTED
#undef TYPE_FORWARD_ONLY
#undef TYPE_SCROLL_INSENSITIVE
#undef US_ASCII
#undef VARBINARY
#undef VARCHAR
#undef YEAR

using $IntegerArray = $Array<::java::lang::Integer>;
using $PermissionArray = $Array<::java::security::Permission>;
using $CachedRowSetImpl$1 = ::com::sun::rowset::CachedRowSetImpl$1;
using $JdbcRowSetResourceBundle = ::com::sun::rowset::JdbcRowSetResourceBundle;
using $BaseRow = ::com::sun::rowset::internal::BaseRow;
using $CachedRowSetReader = ::com::sun::rowset::internal::CachedRowSetReader;
using $CachedRowSetWriter = ::com::sun::rowset::internal::CachedRowSetWriter;
using $InsertRow = ::com::sun::rowset::internal::InsertRow;
using $Row = ::com::sun::rowset::internal::Row;
using $RIOptimisticProvider = ::com::sun::rowset::providers::RIOptimisticProvider;
using $ByteArrayInputStream = ::java::io::ByteArrayInputStream;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $InputStreamReader = ::java::io::InputStreamReader;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $OptionalDataException = ::java::io::OptionalDataException;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $StreamCorruptedException = ::java::io::StreamCorruptedException;
using $StringBufferInputStream = ::java::io::StringBufferInputStream;
using $StringReader = ::java::io::StringReader;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Double = ::java::lang::Double;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $RuntimeException = ::java::lang::RuntimeException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityException = ::java::lang::SecurityException;
using $Short = ::java::lang::Short;
using $BigDecimal = ::java::math::BigDecimal;
using $URL = ::java::net::URL;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $BasicPermission = ::java::security::BasicPermission;
using $Permission = ::java::security::Permission;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $1Array = ::java::sql::Array;
using $Blob = ::java::sql::Blob;
using $Clob = ::java::sql::Clob;
using $Connection = ::java::sql::Connection;
using $DatabaseMetaData = ::java::sql::DatabaseMetaData;
using $1Date = ::java::sql::Date;
using $NClob = ::java::sql::NClob;
using $Ref = ::java::sql::Ref;
using $ResultSet = ::java::sql::ResultSet;
using $ResultSetMetaData = ::java::sql::ResultSetMetaData;
using $RowId = ::java::sql::RowId;
using $SQLData = ::java::sql::SQLData;
using $SQLException = ::java::sql::SQLException;
using $SQLFeatureNotSupportedException = ::java::sql::SQLFeatureNotSupportedException;
using $SQLInput = ::java::sql::SQLInput;
using $SQLWarning = ::java::sql::SQLWarning;
using $SQLXML = ::java::sql::SQLXML;
using $Savepoint = ::java::sql::Savepoint;
using $Statement = ::java::sql::Statement;
using $Struct = ::java::sql::Struct;
using $Time = ::java::sql::Time;
using $Timestamp = ::java::sql::Timestamp;
using $Types = ::java::sql::Types;
using $DateFormat = ::java::text::DateFormat;
using $MessageFormat = ::java::text::MessageFormat;
using $ParseException = ::java::text::ParseException;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractList = ::java::util::AbstractList;
using $Arrays = ::java::util::Arrays;
using $Calendar = ::java::util::Calendar;
using $Collection = ::java::util::Collection;
using $Date = ::java::util::Date;
using $Hashtable = ::java::util::Hashtable;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $TreeMap = ::java::util::TreeMap;
using $Vector = ::java::util::Vector;
using $RowSet = ::javax::sql::RowSet;
using $RowSetEvent = ::javax::sql::RowSetEvent;
using $RowSetInternal = ::javax::sql::RowSetInternal;
using $RowSetListener = ::javax::sql::RowSetListener;
using $RowSetMetaData = ::javax::sql::RowSetMetaData;
using $RowSetReader = ::javax::sql::RowSetReader;
using $RowSetWriter = ::javax::sql::RowSetWriter;
using $BaseRowSet = ::javax::sql::rowset::BaseRowSet;
using $CachedRowSet = ::javax::sql::rowset::CachedRowSet;
using $RowSetMetaDataImpl = ::javax::sql::rowset::RowSetMetaDataImpl;
using $RowSetWarning = ::javax::sql::rowset::RowSetWarning;
using $SQLInputImpl = ::javax::sql::rowset::serial::SQLInputImpl;
using $SerialArray = ::javax::sql::rowset::serial::SerialArray;
using $SerialBlob = ::javax::sql::rowset::serial::SerialBlob;
using $SerialClob = ::javax::sql::rowset::serial::SerialClob;
using $SerialRef = ::javax::sql::rowset::serial::SerialRef;
using $SerialStruct = ::javax::sql::rowset::serial::SerialStruct;
using $SyncFactory = ::javax::sql::rowset::spi::SyncFactory;
using $SyncFactoryException = ::javax::sql::rowset::spi::SyncFactoryException;
using $SyncProvider = ::javax::sql::rowset::spi::SyncProvider;
using $SyncProviderException = ::javax::sql::rowset::spi::SyncProviderException;
using $TransactionalWriter = ::javax::sql::rowset::spi::TransactionalWriter;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;

namespace com {
	namespace sun {
		namespace rowset {

$CompoundAttribute _CachedRowSetImpl_MethodAnnotations_getBigDecimal35[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _CachedRowSetImpl_MethodAnnotations_getBigDecimal36[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _CachedRowSetImpl_MethodAnnotations_getUnicodeStream114[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _CachedRowSetImpl_MethodAnnotations_getUnicodeStream115[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _CachedRowSetImpl_FieldInfo_[] = {
	{"provider", "Ljavax/sql/rowset/spi/SyncProvider;", nullptr, $PRIVATE, $field(CachedRowSetImpl, provider)},
	{"rowSetReader", "Ljavax/sql/RowSetReader;", nullptr, $PRIVATE, $field(CachedRowSetImpl, rowSetReader)},
	{"rowSetWriter", "Ljavax/sql/RowSetWriter;", nullptr, $PRIVATE, $field(CachedRowSetImpl, rowSetWriter)},
	{"conn", "Ljava/sql/Connection;", nullptr, $PRIVATE | $TRANSIENT, $field(CachedRowSetImpl, conn)},
	{"RSMD", "Ljava/sql/ResultSetMetaData;", nullptr, $PRIVATE | $TRANSIENT, $field(CachedRowSetImpl, RSMD)},
	{"RowSetMD", "Ljavax/sql/rowset/RowSetMetaDataImpl;", nullptr, $PRIVATE, $field(CachedRowSetImpl, RowSetMD)},
	{"keyCols", "[I", nullptr, $PRIVATE, $field(CachedRowSetImpl, keyCols)},
	{"tableName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(CachedRowSetImpl, tableName)},
	{"rvh", "Ljava/util/Vector;", "Ljava/util/Vector<Ljava/lang/Object;>;", $PRIVATE, $field(CachedRowSetImpl, rvh)},
	{"cursorPos", "I", nullptr, $PRIVATE, $field(CachedRowSetImpl, cursorPos)},
	{"absolutePos", "I", nullptr, $PRIVATE, $field(CachedRowSetImpl, absolutePos)},
	{"numDeleted", "I", nullptr, $PRIVATE, $field(CachedRowSetImpl, numDeleted)},
	{"numRows", "I", nullptr, $PRIVATE, $field(CachedRowSetImpl, numRows)},
	{"insertRow", "Lcom/sun/rowset/internal/InsertRow;", nullptr, $PRIVATE, $field(CachedRowSetImpl, insertRow$)},
	{"onInsertRow", "Z", nullptr, $PRIVATE, $field(CachedRowSetImpl, onInsertRow)},
	{"currentRow", "I", nullptr, $PRIVATE, $field(CachedRowSetImpl, currentRow)},
	{"lastValueNull", "Z", nullptr, $PRIVATE, $field(CachedRowSetImpl, lastValueNull)},
	{"sqlwarn", "Ljava/sql/SQLWarning;", nullptr, $PRIVATE, $field(CachedRowSetImpl, sqlwarn)},
	{"strMatchColumn", "Ljava/lang/String;", nullptr, $PRIVATE, $field(CachedRowSetImpl, strMatchColumn)},
	{"iMatchColumn", "I", nullptr, $PRIVATE, $field(CachedRowSetImpl, iMatchColumn)},
	{"rowsetWarning", "Ljavax/sql/rowset/RowSetWarning;", nullptr, $PRIVATE, $field(CachedRowSetImpl, rowsetWarning)},
	{"DEFAULT_SYNC_PROVIDER", "Ljava/lang/String;", nullptr, $PRIVATE, $field(CachedRowSetImpl, DEFAULT_SYNC_PROVIDER)},
	{"dbmslocatorsUpdateCopy", "Z", nullptr, $PRIVATE, $field(CachedRowSetImpl, dbmslocatorsUpdateCopy)},
	{"resultSet", "Ljava/sql/ResultSet;", nullptr, $PRIVATE | $TRANSIENT, $field(CachedRowSetImpl, resultSet)},
	{"endPos", "I", nullptr, $PRIVATE, $field(CachedRowSetImpl, endPos)},
	{"prevEndPos", "I", nullptr, $PRIVATE, $field(CachedRowSetImpl, prevEndPos)},
	{"startPos", "I", nullptr, $PRIVATE, $field(CachedRowSetImpl, startPos)},
	{"startPrev", "I", nullptr, $PRIVATE, $field(CachedRowSetImpl, startPrev)},
	{"pageSize", "I", nullptr, $PRIVATE, $field(CachedRowSetImpl, pageSize)},
	{"maxRowsreached", "I", nullptr, $PRIVATE, $field(CachedRowSetImpl, maxRowsreached)},
	{"pagenotend", "Z", nullptr, $PRIVATE, $field(CachedRowSetImpl, pagenotend)},
	{"onFirstPage", "Z", nullptr, $PRIVATE, $field(CachedRowSetImpl, onFirstPage)},
	{"onLastPage", "Z", nullptr, $PRIVATE, $field(CachedRowSetImpl, onLastPage)},
	{"populatecallcount", "I", nullptr, $PRIVATE, $field(CachedRowSetImpl, populatecallcount)},
	{"totalRows", "I", nullptr, $PRIVATE, $field(CachedRowSetImpl, totalRows)},
	{"callWithCon", "Z", nullptr, $PRIVATE, $field(CachedRowSetImpl, callWithCon)},
	{"crsReader", "Lcom/sun/rowset/internal/CachedRowSetReader;", nullptr, $PRIVATE, $field(CachedRowSetImpl, crsReader)},
	{"iMatchColumns", "Ljava/util/Vector;", "Ljava/util/Vector<Ljava/lang/Integer;>;", $PRIVATE, $field(CachedRowSetImpl, iMatchColumns)},
	{"strMatchColumns", "Ljava/util/Vector;", "Ljava/util/Vector<Ljava/lang/String;>;", $PRIVATE, $field(CachedRowSetImpl, strMatchColumns)},
	{"tXWriter", "Z", nullptr, $PRIVATE, $field(CachedRowSetImpl, tXWriter)},
	{"tWriter", "Ljavax/sql/rowset/spi/TransactionalWriter;", nullptr, $PRIVATE, $field(CachedRowSetImpl, tWriter)},
	{"resBundle", "Lcom/sun/rowset/JdbcRowSetResourceBundle;", nullptr, $PROTECTED | $TRANSIENT, $field(CachedRowSetImpl, resBundle)},
	{"updateOnInsert", "Z", nullptr, $PRIVATE, $field(CachedRowSetImpl, updateOnInsert)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(CachedRowSetImpl, serialVersionUID)},
	{}
};

$MethodInfo _CachedRowSetImpl_MethodInfo_[] = {
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
	{"*getMaxFieldSize", "()I", nullptr, $PUBLIC},
	{"*getMaxRows", "()I", nullptr, $PUBLIC},
	{"*getParams", "()[Ljava/lang/Object;", nullptr, $PUBLIC},
	{"*getPassword", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getQueryTimeout", "()I", nullptr, $PUBLIC},
	{"*getShowDeleted", "()Z", nullptr, $PUBLIC},
	{"*getTransactionIsolation", "()I", nullptr, $PUBLIC},
	{"*getType", "()I", nullptr, $PUBLIC},
	{"*getTypeMap", "()Ljava/util/Map;", nullptr, $PUBLIC},
	{"*getUrl", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*getUsername", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(CachedRowSetImpl::*)()>(&CachedRowSetImpl::init$)), "java.sql.SQLException"},
	{"<init>", "(Ljava/util/Hashtable;)V", nullptr, $PUBLIC, $method(static_cast<void(CachedRowSetImpl::*)($Hashtable*)>(&CachedRowSetImpl::init$)), "java.sql.SQLException"},
	{"absolute", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"acceptChanges", "()V", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.spi.SyncProviderException"},
	{"acceptChanges", "(Ljava/sql/Connection;)V", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.spi.SyncProviderException"},
	{"afterLast", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"beforeFirst", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"buildTableName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(CachedRowSetImpl::*)($String*)>(&CachedRowSetImpl::buildTableName)), "java.sql.SQLException"},
	{"cancelRowUpdates", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"checkCursor", "()V", nullptr, $PRIVATE, $method(static_cast<void(CachedRowSetImpl::*)()>(&CachedRowSetImpl::checkCursor)), "java.sql.SQLException"},
	{"checkIndex", "(I)V", nullptr, $PRIVATE, $method(static_cast<void(CachedRowSetImpl::*)(int32_t)>(&CachedRowSetImpl::checkIndex)), "java.sql.SQLException"},
	{"checkTransactionalWriter", "()V", nullptr, $PRIVATE, $method(static_cast<void(CachedRowSetImpl::*)()>(&CachedRowSetImpl::checkTransactionalWriter))},
	{"clearWarnings", "()V", nullptr, $PUBLIC},
	{"clone", "()Ljava/lang/Object;", nullptr, $PROTECTED, nullptr, "java.lang.CloneNotSupportedException"},
	{"close", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"columnUpdated", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"columnUpdated", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"commit", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"convertBoolean", "(Ljava/lang/Object;II)Ljava/lang/Object;", nullptr, $PRIVATE, $method(static_cast<$Object*(CachedRowSetImpl::*)(Object$*,int32_t,int32_t)>(&CachedRowSetImpl::convertBoolean)), "java.sql.SQLException"},
	{"convertNumeric", "(Ljava/lang/Object;II)Ljava/lang/Object;", nullptr, $PRIVATE, $method(static_cast<$Object*(CachedRowSetImpl::*)(Object$*,int32_t,int32_t)>(&CachedRowSetImpl::convertNumeric)), "java.sql.SQLException"},
	{"convertTemporal", "(Ljava/lang/Object;II)Ljava/lang/Object;", nullptr, $PRIVATE, $method(static_cast<$Object*(CachedRowSetImpl::*)(Object$*,int32_t,int32_t)>(&CachedRowSetImpl::convertTemporal)), "java.sql.SQLException"},
	{"createCopy", "()Ljavax/sql/rowset/CachedRowSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"createCopyNoConstraints", "()Ljavax/sql/rowset/CachedRowSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"createCopySchema", "()Ljavax/sql/rowset/CachedRowSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"createShared", "()Ljavax/sql/RowSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"deleteRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"establishTransactionalWriter", "()V", nullptr, $PRIVATE, $method(static_cast<void(CachedRowSetImpl::*)()>(&CachedRowSetImpl::establishTransactionalWriter))},
	{"execute", "(Ljava/sql/Connection;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"execute", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"findColumn", "(Ljava/lang/String;)I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"first", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getArray", "(I)Ljava/sql/Array;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getArray", "(Ljava/lang/String;)Ljava/sql/Array;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getAsciiStream", "(I)Ljava/io/InputStream;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getAsciiStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getBigDecimal", "(II)Ljava/math/BigDecimal;", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.sql.SQLException", nullptr, _CachedRowSetImpl_MethodAnnotations_getBigDecimal35},
	{"getBigDecimal", "(Ljava/lang/String;I)Ljava/math/BigDecimal;", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.sql.SQLException", nullptr, _CachedRowSetImpl_MethodAnnotations_getBigDecimal36},
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
	{"getColIdxByName", "(Ljava/lang/String;)I", nullptr, $PRIVATE, $method(static_cast<int32_t(CachedRowSetImpl::*)($String*)>(&CachedRowSetImpl::getColIdxByName)), "java.sql.SQLException"},
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
	{"getHoldability", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getInt", "(I)I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getInt", "(Ljava/lang/String;)I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getKeyColumns", "()[I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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
	{"getOriginal", "()Ljava/sql/ResultSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getOriginalRow", "()Ljava/sql/ResultSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getPageSize", "()I", nullptr, $PUBLIC},
	{"getRef", "(I)Ljava/sql/Ref;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getRef", "(Ljava/lang/String;)Ljava/sql/Ref;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getRow", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getRowId", "(I)Ljava/sql/RowId;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getRowId", "(Ljava/lang/String;)Ljava/sql/RowId;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getRowSetWarnings", "()Ljavax/sql/rowset/RowSetWarning;", nullptr, $PUBLIC},
	{"getSQLXML", "(I)Ljava/sql/SQLXML;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getSQLXML", "(Ljava/lang/String;)Ljava/sql/SQLXML;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getShort", "(I)S", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getShort", "(Ljava/lang/String;)S", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getStatement", "()Ljava/sql/Statement;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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
	{"getUnicodeStream", "(I)Ljava/io/InputStream;", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.sql.SQLException", nullptr, _CachedRowSetImpl_MethodAnnotations_getUnicodeStream114},
	{"getUnicodeStream", "(Ljava/lang/String;)Ljava/io/InputStream;", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.sql.SQLException", nullptr, _CachedRowSetImpl_MethodAnnotations_getUnicodeStream115},
	{"getWarnings", "()Ljava/sql/SQLWarning;", nullptr, $PUBLIC},
	{"initContainer", "()V", nullptr, $PRIVATE, $method(static_cast<void(CachedRowSetImpl::*)()>(&CachedRowSetImpl::initContainer))},
	{"initMetaData", "(Ljavax/sql/rowset/RowSetMetaDataImpl;Ljava/sql/ResultSetMetaData;)V", nullptr, $PRIVATE, $method(static_cast<void(CachedRowSetImpl::*)($RowSetMetaDataImpl*,$ResultSetMetaData*)>(&CachedRowSetImpl::initMetaData)), "java.sql.SQLException"},
	{"initProperties", "()V", nullptr, $PRIVATE, $method(static_cast<void(CachedRowSetImpl::*)()>(&CachedRowSetImpl::initProperties)), "java.sql.SQLException"},
	{"insertRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"internalFirst", "()Z", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"internalLast", "()Z", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"internalNext", "()Z", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"internalPrevious", "()Z", nullptr, $PROTECTED, nullptr, "java.sql.SQLException"},
	{"isAfterLast", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isBeforeFirst", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isBinary", "(I)Z", nullptr, $PRIVATE, $method(static_cast<bool(CachedRowSetImpl::*)(int32_t)>(&CachedRowSetImpl::isBinary))},
	{"isBoolean", "(I)Z", nullptr, $PRIVATE, $method(static_cast<bool(CachedRowSetImpl::*)(int32_t)>(&CachedRowSetImpl::isBoolean))},
	{"isClosed", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isFirst", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isLast", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isNumeric", "(I)Z", nullptr, $PRIVATE, $method(static_cast<bool(CachedRowSetImpl::*)(int32_t)>(&CachedRowSetImpl::isNumeric))},
	{"*isReadOnly", "()Z", nullptr, $PUBLIC},
	{"isString", "(I)Z", nullptr, $PRIVATE, $method(static_cast<bool(CachedRowSetImpl::*)(int32_t)>(&CachedRowSetImpl::isString))},
	{"isTemporal", "(I)Z", nullptr, $PRIVATE, $method(static_cast<bool(CachedRowSetImpl::*)(int32_t)>(&CachedRowSetImpl::isTemporal))},
	{"isWrapperFor", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"last", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"makeRowOriginal", "(Lcom/sun/rowset/internal/Row;)V", nullptr, $PRIVATE, $method(static_cast<void(CachedRowSetImpl::*)($Row*)>(&CachedRowSetImpl::makeRowOriginal))},
	{"moveToCurrentRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"moveToInsertRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"next", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"nextPage", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"populate", "(Ljava/sql/ResultSet;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"populate", "(Ljava/sql/ResultSet;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"previous", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"previousPage", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(CachedRowSetImpl::*)($ObjectInputStream*)>(&CachedRowSetImpl::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
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
	{"*setAsciiStream", "(ILjava/io/InputStream;I)V", nullptr, $PUBLIC},
	{"*setAsciiStream", "(ILjava/io/InputStream;)V", nullptr, $PUBLIC},
	{"setAsciiStream", "(Ljava/lang/String;Ljava/io/InputStream;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setAsciiStream", "(Ljava/lang/String;Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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
	{"*setConcurrency", "(I)V", nullptr, $PUBLIC},
	{"setConnection", "(Ljava/sql/Connection;)V", nullptr, $PRIVATE, $method(static_cast<void(CachedRowSetImpl::*)($Connection*)>(&CachedRowSetImpl::setConnection))},
	{"*setDataSourceName", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*setDate", "(ILjava/sql/Date;)V", nullptr, $PUBLIC},
	{"*setDate", "(ILjava/sql/Date;Ljava/util/Calendar;)V", nullptr, $PUBLIC},
	{"setDate", "(Ljava/lang/String;Ljava/sql/Date;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setDate", "(Ljava/lang/String;Ljava/sql/Date;Ljava/util/Calendar;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setDouble", "(ID)V", nullptr, $PUBLIC},
	{"setDouble", "(Ljava/lang/String;D)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setEscapeProcessing", "(Z)V", nullptr, $PUBLIC},
	{"*setFetchDirection", "(I)V", nullptr, $PUBLIC},
	{"*setFetchSize", "(I)V", nullptr, $PUBLIC},
	{"*setFloat", "(IF)V", nullptr, $PUBLIC},
	{"setFloat", "(Ljava/lang/String;F)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setInt", "(II)V", nullptr, $PUBLIC},
	{"setInt", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setKeyColumns", "([I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setLastValueNull", "(Z)V", nullptr, $PRIVATE, $method(static_cast<void(CachedRowSetImpl::*)(bool)>(&CachedRowSetImpl::setLastValueNull))},
	{"*setLong", "(IJ)V", nullptr, $PUBLIC},
	{"setLong", "(Ljava/lang/String;J)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setMatchColumn", "([I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setMatchColumn", "([Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setMatchColumn", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setMatchColumn", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setMaxFieldSize", "(I)V", nullptr, $PUBLIC},
	{"*setMaxRows", "(I)V", nullptr, $PUBLIC},
	{"setMetaData", "(Ljavax/sql/RowSetMetaData;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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
	{"setOriginal", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setOriginalRow", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setPageSize", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setPassword", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*setQueryTimeout", "(I)V", nullptr, $PUBLIC},
	{"*setReadOnly", "(Z)V", nullptr, $PUBLIC},
	{"*setRef", "(ILjava/sql/Ref;)V", nullptr, $PUBLIC},
	{"setRowId", "(ILjava/sql/RowId;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setRowId", "(Ljava/lang/String;Ljava/sql/RowId;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setRowInserted", "(Z)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setSQLXML", "(ILjava/sql/SQLXML;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setSQLXML", "(Ljava/lang/String;Ljava/sql/SQLXML;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setShort", "(IS)V", nullptr, $PUBLIC},
	{"setShort", "(Ljava/lang/String;S)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setShowDeleted", "(Z)V", nullptr, $PUBLIC},
	{"*setString", "(ILjava/lang/String;)V", nullptr, $PUBLIC},
	{"setString", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setSyncProvider", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setTableName", "(Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setTime", "(ILjava/sql/Time;)V", nullptr, $PUBLIC},
	{"*setTime", "(ILjava/sql/Time;Ljava/util/Calendar;)V", nullptr, $PUBLIC},
	{"setTime", "(Ljava/lang/String;Ljava/sql/Time;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setTime", "(Ljava/lang/String;Ljava/sql/Time;Ljava/util/Calendar;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setTimestamp", "(ILjava/sql/Timestamp;)V", nullptr, $PUBLIC},
	{"*setTimestamp", "(ILjava/sql/Timestamp;Ljava/util/Calendar;)V", nullptr, $PUBLIC},
	{"setTimestamp", "(Ljava/lang/String;Ljava/sql/Timestamp;Ljava/util/Calendar;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setTimestamp", "(Ljava/lang/String;Ljava/sql/Timestamp;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setTransactionIsolation", "(I)V", nullptr, $PUBLIC},
	{"*setType", "(I)V", nullptr, $PUBLIC},
	{"*setTypeMap", "(Ljava/util/Map;)V", nullptr, $PUBLIC},
	{"setURL", "(ILjava/net/URL;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*setUrl", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"*setUsername", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"size", "()I", nullptr, $PUBLIC},
	{"toCollection", "()Ljava/util/Collection;", "()Ljava/util/Collection<*>;", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"toCollection", "(I)Ljava/util/Collection;", "(I)Ljava/util/Collection<*>;", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"toCollection", "(Ljava/lang/String;)Ljava/util/Collection;", "(Ljava/lang/String;)Ljava/util/Collection<*>;", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"undoDelete", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"undoInsert", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"undoUpdate", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
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

$InnerClassInfo _CachedRowSetImpl_InnerClassesInfo_[] = {
	{"com.sun.rowset.CachedRowSetImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _CachedRowSetImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.rowset.CachedRowSetImpl",
	"javax.sql.rowset.BaseRowSet",
	"javax.sql.RowSetInternal,javax.sql.rowset.CachedRowSet",
	_CachedRowSetImpl_FieldInfo_,
	_CachedRowSetImpl_MethodInfo_,
	nullptr,
	nullptr,
	_CachedRowSetImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"com.sun.rowset.CachedRowSetImpl$1"
};

$Object* allocate$CachedRowSetImpl($Class* clazz) {
	return $of($alloc(CachedRowSetImpl));
}

void CachedRowSetImpl::addRowSetListener($RowSetListener* listener) {
	this->$BaseRowSet::addRowSetListener(listener);
}

void CachedRowSetImpl::removeRowSetListener($RowSetListener* listener) {
	this->$BaseRowSet::removeRowSetListener(listener);
}

$String* CachedRowSetImpl::getCommand() {
	 return this->$BaseRowSet::getCommand();
}

$String* CachedRowSetImpl::getUrl() {
	 return this->$BaseRowSet::getUrl();
}

void CachedRowSetImpl::setUrl($String* url) {
	this->$BaseRowSet::setUrl(url);
}

$String* CachedRowSetImpl::getDataSourceName() {
	 return this->$BaseRowSet::getDataSourceName();
}

void CachedRowSetImpl::setDataSourceName($String* name) {
	this->$BaseRowSet::setDataSourceName(name);
}

$String* CachedRowSetImpl::getUsername() {
	 return this->$BaseRowSet::getUsername();
}

void CachedRowSetImpl::setUsername($String* name) {
	this->$BaseRowSet::setUsername(name);
}

$String* CachedRowSetImpl::getPassword() {
	 return this->$BaseRowSet::getPassword();
}

void CachedRowSetImpl::setPassword($String* pass) {
	this->$BaseRowSet::setPassword(pass);
}

void CachedRowSetImpl::setType(int32_t type) {
	this->$BaseRowSet::setType(type);
}

int32_t CachedRowSetImpl::getType() {
	 return this->$BaseRowSet::getType();
}

void CachedRowSetImpl::setConcurrency(int32_t concurrency) {
	this->$BaseRowSet::setConcurrency(concurrency);
}

bool CachedRowSetImpl::isReadOnly() {
	 return this->$BaseRowSet::isReadOnly();
}

void CachedRowSetImpl::setReadOnly(bool value) {
	this->$BaseRowSet::setReadOnly(value);
}

int32_t CachedRowSetImpl::getTransactionIsolation() {
	 return this->$BaseRowSet::getTransactionIsolation();
}

void CachedRowSetImpl::setTransactionIsolation(int32_t level) {
	this->$BaseRowSet::setTransactionIsolation(level);
}

$Map* CachedRowSetImpl::getTypeMap() {
	 return this->$BaseRowSet::getTypeMap();
}

void CachedRowSetImpl::setTypeMap($Map* map) {
	this->$BaseRowSet::setTypeMap(map);
}

int32_t CachedRowSetImpl::getMaxFieldSize() {
	 return this->$BaseRowSet::getMaxFieldSize();
}

void CachedRowSetImpl::setMaxFieldSize(int32_t max) {
	this->$BaseRowSet::setMaxFieldSize(max);
}

int32_t CachedRowSetImpl::getMaxRows() {
	 return this->$BaseRowSet::getMaxRows();
}

void CachedRowSetImpl::setMaxRows(int32_t max) {
	this->$BaseRowSet::setMaxRows(max);
}

void CachedRowSetImpl::setEscapeProcessing(bool enable) {
	this->$BaseRowSet::setEscapeProcessing(enable);
}

int32_t CachedRowSetImpl::getQueryTimeout() {
	 return this->$BaseRowSet::getQueryTimeout();
}

void CachedRowSetImpl::setQueryTimeout(int32_t seconds) {
	this->$BaseRowSet::setQueryTimeout(seconds);
}

bool CachedRowSetImpl::getShowDeleted() {
	 return this->$BaseRowSet::getShowDeleted();
}

void CachedRowSetImpl::setShowDeleted(bool value) {
	this->$BaseRowSet::setShowDeleted(value);
}

bool CachedRowSetImpl::getEscapeProcessing() {
	 return this->$BaseRowSet::getEscapeProcessing();
}

void CachedRowSetImpl::setFetchDirection(int32_t direction) {
	this->$BaseRowSet::setFetchDirection(direction);
}

int32_t CachedRowSetImpl::getFetchDirection() {
	 return this->$BaseRowSet::getFetchDirection();
}

void CachedRowSetImpl::setFetchSize(int32_t rows) {
	this->$BaseRowSet::setFetchSize(rows);
}

int32_t CachedRowSetImpl::getFetchSize() {
	 return this->$BaseRowSet::getFetchSize();
}

int32_t CachedRowSetImpl::getConcurrency() {
	 return this->$BaseRowSet::getConcurrency();
}

void CachedRowSetImpl::setNull(int32_t parameterIndex, int32_t sqlType) {
	this->$BaseRowSet::setNull(parameterIndex, sqlType);
}

void CachedRowSetImpl::setNull(int32_t parameterIndex, int32_t sqlType, $String* typeName) {
	this->$BaseRowSet::setNull(parameterIndex, sqlType, typeName);
}

void CachedRowSetImpl::setBoolean(int32_t parameterIndex, bool x) {
	this->$BaseRowSet::setBoolean(parameterIndex, x);
}

void CachedRowSetImpl::setByte(int32_t parameterIndex, int8_t x) {
	this->$BaseRowSet::setByte(parameterIndex, x);
}

void CachedRowSetImpl::setShort(int32_t parameterIndex, int16_t x) {
	this->$BaseRowSet::setShort(parameterIndex, x);
}

void CachedRowSetImpl::setInt(int32_t parameterIndex, int32_t x) {
	this->$BaseRowSet::setInt(parameterIndex, x);
}

void CachedRowSetImpl::setLong(int32_t parameterIndex, int64_t x) {
	this->$BaseRowSet::setLong(parameterIndex, x);
}

void CachedRowSetImpl::setFloat(int32_t parameterIndex, float x) {
	this->$BaseRowSet::setFloat(parameterIndex, x);
}

void CachedRowSetImpl::setDouble(int32_t parameterIndex, double x) {
	this->$BaseRowSet::setDouble(parameterIndex, x);
}

void CachedRowSetImpl::setBigDecimal(int32_t parameterIndex, $BigDecimal* x) {
	this->$BaseRowSet::setBigDecimal(parameterIndex, x);
}

void CachedRowSetImpl::setString(int32_t parameterIndex, $String* x) {
	this->$BaseRowSet::setString(parameterIndex, x);
}

void CachedRowSetImpl::setBytes(int32_t parameterIndex, $bytes* x) {
	this->$BaseRowSet::setBytes(parameterIndex, x);
}

void CachedRowSetImpl::setDate(int32_t parameterIndex, $1Date* x) {
	this->$BaseRowSet::setDate(parameterIndex, x);
}

void CachedRowSetImpl::setTime(int32_t parameterIndex, $Time* x) {
	this->$BaseRowSet::setTime(parameterIndex, x);
}

void CachedRowSetImpl::setTimestamp(int32_t parameterIndex, $Timestamp* x) {
	this->$BaseRowSet::setTimestamp(parameterIndex, x);
}

void CachedRowSetImpl::setAsciiStream(int32_t parameterIndex, $InputStream* x, int32_t length) {
	this->$BaseRowSet::setAsciiStream(parameterIndex, x, length);
}

void CachedRowSetImpl::setAsciiStream(int32_t parameterIndex, $InputStream* x) {
	this->$BaseRowSet::setAsciiStream(parameterIndex, x);
}

void CachedRowSetImpl::setBinaryStream(int32_t parameterIndex, $InputStream* x, int32_t length) {
	this->$BaseRowSet::setBinaryStream(parameterIndex, x, length);
}

void CachedRowSetImpl::setBinaryStream(int32_t parameterIndex, $InputStream* x) {
	this->$BaseRowSet::setBinaryStream(parameterIndex, x);
}

void CachedRowSetImpl::setCharacterStream(int32_t parameterIndex, $Reader* reader, int32_t length) {
	this->$BaseRowSet::setCharacterStream(parameterIndex, reader, length);
}

void CachedRowSetImpl::setCharacterStream(int32_t parameterIndex, $Reader* reader) {
	this->$BaseRowSet::setCharacterStream(parameterIndex, reader);
}

void CachedRowSetImpl::setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType, int32_t scale) {
	this->$BaseRowSet::setObject(parameterIndex, x, targetSqlType, scale);
}

void CachedRowSetImpl::setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType) {
	this->$BaseRowSet::setObject(parameterIndex, x, targetSqlType);
}

void CachedRowSetImpl::setObject(int32_t parameterIndex, Object$* x) {
	this->$BaseRowSet::setObject(parameterIndex, x);
}

void CachedRowSetImpl::setRef(int32_t parameterIndex, $Ref* ref) {
	this->$BaseRowSet::setRef(parameterIndex, ref);
}

void CachedRowSetImpl::setBlob(int32_t parameterIndex, $Blob* x) {
	this->$BaseRowSet::setBlob(parameterIndex, x);
}

void CachedRowSetImpl::setClob(int32_t parameterIndex, $Clob* x) {
	this->$BaseRowSet::setClob(parameterIndex, x);
}

void CachedRowSetImpl::setArray(int32_t parameterIndex, $1Array* array) {
	this->$BaseRowSet::setArray(parameterIndex, array);
}

void CachedRowSetImpl::setDate(int32_t parameterIndex, $1Date* x, $Calendar* cal) {
	this->$BaseRowSet::setDate(parameterIndex, x, cal);
}

void CachedRowSetImpl::setTime(int32_t parameterIndex, $Time* x, $Calendar* cal) {
	this->$BaseRowSet::setTime(parameterIndex, x, cal);
}

void CachedRowSetImpl::setTimestamp(int32_t parameterIndex, $Timestamp* x, $Calendar* cal) {
	this->$BaseRowSet::setTimestamp(parameterIndex, x, cal);
}

void CachedRowSetImpl::clearParameters() {
	this->$BaseRowSet::clearParameters();
}

$ObjectArray* CachedRowSetImpl::getParams() {
	 return this->$BaseRowSet::getParams();
}

int32_t CachedRowSetImpl::hashCode() {
	 return this->$BaseRowSet::hashCode();
}

bool CachedRowSetImpl::equals(Object$* arg0) {
	 return this->$BaseRowSet::equals(arg0);
}

$String* CachedRowSetImpl::toString() {
	 return this->$BaseRowSet::toString();
}

void CachedRowSetImpl::finalize() {
	this->$BaseRowSet::finalize();
}

void CachedRowSetImpl::init$() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$BaseRowSet::init$();
	$set(this, strMatchColumn, ""_s);
	this->iMatchColumn = -1;
	$set(this, DEFAULT_SYNC_PROVIDER, "com.sun.rowset.providers.RIOptimisticProvider"_s);
	this->pagenotend = true;
	this->tXWriter = false;
	$set(this, tWriter, nullptr);
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
	try {
		$var($PrivilegedExceptionAction, var$0, static_cast<$PrivilegedExceptionAction*>($new($CachedRowSetImpl$1, this)));
		$set(this, provider, $cast($SyncProvider, $AccessController::doPrivileged(var$0, ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>($$new($RuntimePermission, "accessClassInPackage.com.sun.rowset.providers"_s))}))));
	} catch ($PrivilegedActionException& pae) {
		$throw($cast($SyncFactoryException, $(pae->getException())));
	}
	if (!($instanceOf($RIOptimisticProvider, this->provider))) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalidp"_s))))->toString()));
	}
	$set(this, rowSetReader, $cast($CachedRowSetReader, $nc(this->provider)->getRowSetReader()));
	$set(this, rowSetWriter, $cast($CachedRowSetWriter, $nc(this->provider)->getRowSetWriter()));
	initParams();
	initContainer();
	initProperties();
	this->onInsertRow = false;
	$set(this, insertRow$, nullptr);
	$set(this, sqlwarn, $new($SQLWarning));
	$set(this, rowsetWarning, $new($RowSetWarning));
}

void CachedRowSetImpl::init$($Hashtable* env) {
	$useLocalCurrentObjectStackCache();
	$BaseRowSet::init$();
	$set(this, strMatchColumn, ""_s);
	this->iMatchColumn = -1;
	$set(this, DEFAULT_SYNC_PROVIDER, "com.sun.rowset.providers.RIOptimisticProvider"_s);
	this->pagenotend = true;
	this->tXWriter = false;
	$set(this, tWriter, nullptr);
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
	if (env == nullptr) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.nullhash"_s))))->toString()));
	}
	$init($SyncFactory);
	$var($String, providerName, $cast($String, $nc(env)->get($SyncFactory::ROWSET_SYNC_PROVIDER)));
	$set(this, provider, $SyncFactory::getInstance(providerName));
	$set(this, rowSetReader, $nc(this->provider)->getRowSetReader());
	$set(this, rowSetWriter, $nc(this->provider)->getRowSetWriter());
	initParams();
	initContainer();
	initProperties();
}

void CachedRowSetImpl::initContainer() {
	$set(this, rvh, $new($Vector, 100));
	this->cursorPos = 0;
	this->absolutePos = 0;
	this->numRows = 0;
	this->numDeleted = 0;
}

void CachedRowSetImpl::initProperties() {
	$useLocalCurrentObjectStackCache();
	if (this->resBundle == nullptr) {
		try {
			$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
		} catch ($IOException& ioe) {
			$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
		}
	}
	setShowDeleted(false);
	setQueryTimeout(0);
	setMaxRows(0);
	setMaxFieldSize(0);
	setType($ResultSet::TYPE_SCROLL_INSENSITIVE);
	setConcurrency($ResultSet::CONCUR_UPDATABLE);
	bool var$0 = ($nc(this->rvh)->size() > 0);
	if (var$0 && (isReadOnly() == false)) {
		setReadOnly(false);
	} else {
		setReadOnly(true);
	}
	setTransactionIsolation($Connection::TRANSACTION_READ_COMMITTED);
	setEscapeProcessing(true);
	checkTransactionalWriter();
	$set(this, iMatchColumns, $new($Vector, 10));
	for (int32_t i = 0; i < 10; ++i) {
		$nc(this->iMatchColumns)->add(i, $($Integer::valueOf(-1)));
	}
	$set(this, strMatchColumns, $new($Vector, 10));
	for (int32_t j = 0; j < 10; ++j) {
		$nc(this->strMatchColumns)->add(j, nullptr);
	}
}

void CachedRowSetImpl::checkTransactionalWriter() {
	$useLocalCurrentObjectStackCache();
	if (this->rowSetWriter != nullptr) {
		$Class* c = $nc($of(this->rowSetWriter))->getClass();
		if (c != nullptr) {
			$var($ClassArray, theInterfaces, c->getInterfaces());
			for (int32_t i = 0; i < theInterfaces->length; ++i) {
				if ($nc(($($nc(theInterfaces->get(i))->getName())))->indexOf("TransactionalWriter"_s) > 0) {
					this->tXWriter = true;
					establishTransactionalWriter();
				}
			}
		}
	}
}

void CachedRowSetImpl::establishTransactionalWriter() {
	$set(this, tWriter, $cast($TransactionalWriter, $nc(this->provider)->getRowSetWriter()));
}

void CachedRowSetImpl::setCommand($String* cmd) {
	$useLocalCurrentObjectStackCache();
	$BaseRowSet::setCommand(cmd);
	if (!$nc($(buildTableName(cmd)))->isEmpty()) {
		this->setTableName($(buildTableName(cmd)));
	}
}

void CachedRowSetImpl::populate($ResultSet* data) {
	$useLocalCurrentObjectStackCache();
	int32_t rowsFetched = 0;
	$var($Row, currentRow, nullptr);
	int32_t numCols = 0;
	int32_t i = 0;
	$var($Map, map, getTypeMap());
	$var($Object, obj, nullptr);
	int32_t mRows = 0;
	if (data == nullptr) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.populate"_s))))->toString()));
	}
	$set(this, resultSet, data);
	$set(this, RSMD, $nc(data)->getMetaData());
	$set(this, RowSetMD, $new($RowSetMetaDataImpl));
	initMetaData(this->RowSetMD, this->RSMD);
	$set(this, RSMD, nullptr);
	numCols = $nc(this->RowSetMD)->getColumnCount();
	mRows = this->getMaxRows();
	rowsFetched = 0;
	$assign(currentRow, nullptr);
	while (data->next()) {
		$assign(currentRow, $new($Row, numCols));
		if (rowsFetched > mRows && mRows > 0) {
			$nc(this->rowsetWarning)->setNextWarning($$new($RowSetWarning, "Populating rows setting has exceeded max row setting"_s));
		}
		for (i = 1; i <= numCols; ++i) {
			if (map == nullptr || $nc(map)->isEmpty()) {
				$assign(obj, data->getObject(i));
			} else {
				$assign(obj, data->getObject(i, map));
			}
			if ($instanceOf($Struct, obj)) {
				$assign(obj, $new($SerialStruct, $cast($Struct, obj), map));
			} else if ($instanceOf($SQLData, obj)) {
				$assign(obj, $new($SerialStruct, $cast($SQLData, obj), map));
			} else if ($instanceOf($Blob, obj)) {
				$assign(obj, $new($SerialBlob, $cast($Blob, obj)));
			} else if ($instanceOf($Clob, obj)) {
				$assign(obj, $new($SerialClob, $cast($Clob, obj)));
			} else if ($instanceOf($1Array, obj)) {
				if (map != nullptr) {
					$assign(obj, $new($SerialArray, $cast($1Array, obj), map));
				} else {
					$assign(obj, $new($SerialArray, $cast($1Array, obj)));
				}
			}
			currentRow->initColumnObject(i, obj);
		}
		++rowsFetched;
		$nc(this->rvh)->add(currentRow);
	}
	this->numRows = rowsFetched;
	notifyRowSetChanged();
}

void CachedRowSetImpl::initMetaData($RowSetMetaDataImpl* md, $ResultSetMetaData* rsmd) {
	$useLocalCurrentObjectStackCache();
	int32_t numCols = $nc(rsmd)->getColumnCount();
	$nc(md)->setColumnCount(numCols);
	for (int32_t col = 1; col <= numCols; ++col) {
		md->setAutoIncrement(col, rsmd->isAutoIncrement(col));
		if (rsmd->isAutoIncrement(col)) {
			this->updateOnInsert = true;
		}
		md->setCaseSensitive(col, rsmd->isCaseSensitive(col));
		md->setCurrency(col, rsmd->isCurrency(col));
		md->setNullable(col, rsmd->isNullable(col));
		md->setSigned(col, rsmd->isSigned(col));
		md->setSearchable(col, rsmd->isSearchable(col));
		int32_t size = rsmd->getColumnDisplaySize(col);
		if (size < 0) {
			size = 0;
		}
		md->setColumnDisplaySize(col, size);
		md->setColumnLabel(col, $(rsmd->getColumnLabel(col)));
		md->setColumnName(col, $(rsmd->getColumnName(col)));
		md->setSchemaName(col, $(rsmd->getSchemaName(col)));
		int32_t precision = rsmd->getPrecision(col);
		if (precision < 0) {
			precision = 0;
		}
		md->setPrecision(col, precision);
		int32_t scale = rsmd->getScale(col);
		if (scale < 0) {
			scale = 0;
		}
		md->setScale(col, scale);
		md->setTableName(col, $(rsmd->getTableName(col)));
		md->setCatalogName(col, $(rsmd->getCatalogName(col)));
		md->setColumnType(col, rsmd->getColumnType(col));
		md->setColumnTypeName(col, $(rsmd->getColumnTypeName(col)));
	}
	if (this->conn != nullptr) {
		this->dbmslocatorsUpdateCopy = $nc($($nc(this->conn)->getMetaData()))->locatorsUpdateCopy();
	}
}

void CachedRowSetImpl::execute($Connection* conn) {
	setConnection(conn);
	if (getPageSize() != 0) {
		$set(this, crsReader, $cast($CachedRowSetReader, $nc(this->provider)->getRowSetReader()));
		$nc(this->crsReader)->setStartPosition(1);
		this->callWithCon = true;
		$nc(this->crsReader)->readData(static_cast<$RowSetInternal*>(this));
	} else {
		$nc(this->rowSetReader)->readData(static_cast<$RowSetInternal*>(this));
	}
	$set(this, RowSetMD, $cast($RowSetMetaDataImpl, this->getMetaData()));
	if (conn != nullptr) {
		this->dbmslocatorsUpdateCopy = $nc($(conn->getMetaData()))->locatorsUpdateCopy();
	}
}

void CachedRowSetImpl::setConnection($Connection* connection) {
	$set(this, conn, connection);
}

void CachedRowSetImpl::acceptChanges() {
	$useLocalCurrentObjectStackCache();
	if (this->onInsertRow == true) {
		$throwNew($SyncProviderException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalidop"_s))))->toString()));
	}
	int32_t saveCursorPos = this->cursorPos;
	bool success = false;
	bool conflict = false;
	try {
		if (this->rowSetWriter != nullptr) {
			saveCursorPos = this->cursorPos;
			conflict = $nc(this->rowSetWriter)->writeData(static_cast<$RowSetInternal*>(this));
			this->cursorPos = saveCursorPos;
		}
		if (this->tXWriter) {
			if (!conflict) {
				$set(this, tWriter, $cast($TransactionalWriter, this->rowSetWriter));
				$nc(this->tWriter)->rollback();
				success = false;
			} else {
				$set(this, tWriter, $cast($TransactionalWriter, this->rowSetWriter));
				if ($instanceOf($CachedRowSetWriter, this->tWriter)) {
					$nc(($cast($CachedRowSetWriter, this->tWriter)))->commit(this, this->updateOnInsert);
				} else {
					$nc(this->tWriter)->commit();
				}
				success = true;
			}
		}
		if (success == true) {
			setOriginal();
		} else if (!(success)) {
			$throwNew($SyncProviderException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.accfailed"_s))))->toString()));
		}
	} catch ($SyncProviderException& spe) {
		$throw(spe);
	} catch ($SQLException& e) {
		e->printStackTrace();
		$throwNew($SyncProviderException, $(e->getMessage()));
	} catch ($SecurityException& e) {
		$throwNew($SyncProviderException, $(e->getMessage()));
	}
}

void CachedRowSetImpl::acceptChanges($Connection* con) {
	setConnection(con);
	acceptChanges();
}

void CachedRowSetImpl::restoreOriginal() {
	$useLocalCurrentObjectStackCache();
	$var($Row, currentRow, nullptr);
	{
		$var($Iterator, i, $nc(this->rvh)->iterator());
		for (; $nc(i)->hasNext();) {
			$assign(currentRow, $cast($Row, i->next()));
			if ($nc(currentRow)->getInserted() == true) {
				i->remove();
				--this->numRows;
			} else {
				if (currentRow->getDeleted() == true) {
					currentRow->clearDeleted();
				}
				if (currentRow->getUpdated() == true) {
					currentRow->clearUpdated();
				}
			}
		}
	}
	this->cursorPos = 0;
	notifyRowSetChanged();
}

void CachedRowSetImpl::release() {
	initContainer();
	notifyRowSetChanged();
}

void CachedRowSetImpl::undoDelete() {
	$useLocalCurrentObjectStackCache();
	if (getShowDeleted() == false) {
		return;
	}
	checkCursor();
	if (this->onInsertRow == true) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalidcp"_s))))->toString()));
	}
	$var($Row, currentRow, $cast($Row, getCurrentRow()));
	if ($nc(currentRow)->getDeleted() == true) {
		currentRow->clearDeleted();
		--this->numDeleted;
		notifyRowChanged();
	}
}

void CachedRowSetImpl::undoInsert() {
	$useLocalCurrentObjectStackCache();
	checkCursor();
	if (this->onInsertRow == true) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalidcp"_s))))->toString()));
	}
	$var($Row, currentRow, $cast($Row, getCurrentRow()));
	if ($nc(currentRow)->getInserted() == true) {
		$nc(this->rvh)->remove(this->cursorPos - 1);
		--this->numRows;
		notifyRowChanged();
	} else {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.illegalop"_s))))->toString()));
	}
}

void CachedRowSetImpl::undoUpdate() {
	moveToCurrentRow();
	undoDelete();
	undoInsert();
}

$RowSet* CachedRowSetImpl::createShared() {
	$useLocalCurrentObjectStackCache();
	$var($RowSet, clone, nullptr);
	try {
		$assign(clone, $cast($RowSet, this->clone()));
	} catch ($CloneNotSupportedException& ex) {
		$throwNew($SQLException, $(ex->getMessage()));
	}
	return clone;
}

$Object* CachedRowSetImpl::clone() {
	return $of(($BaseRowSet::clone()));
}

$CachedRowSet* CachedRowSetImpl::createCopy() {
	$useLocalCurrentObjectStackCache();
	$var($ObjectOutputStream, out, nullptr);
	$var($ByteArrayOutputStream, bOut, $new($ByteArrayOutputStream));
	try {
		$assign(out, $new($ObjectOutputStream, bOut));
		out->writeObject(this);
	} catch ($IOException& ex) {
		$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.clonefail"_s))))->toString());
		$throwNew($SQLException, $($MessageFormat::format(var$0, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
	}
	$var($ObjectInputStream, in, nullptr);
	try {
		$var($ByteArrayInputStream, bIn, $new($ByteArrayInputStream, $(bOut->toByteArray())));
		$assign(in, $new($ObjectInputStream, bIn));
	} catch ($StreamCorruptedException& ex) {
		$var($String, var$1, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.clonefail"_s))))->toString());
		$throwNew($SQLException, $($MessageFormat::format(var$1, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
	} catch ($IOException& ex) {
		$var($String, var$2, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.clonefail"_s))))->toString());
		$throwNew($SQLException, $($MessageFormat::format(var$2, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
	}
	try {
		$var(CachedRowSetImpl, crsTemp, $cast(CachedRowSetImpl, $nc(in)->readObject()));
		$set($nc(crsTemp), resBundle, this->resBundle);
		return (static_cast<$CachedRowSet*>(crsTemp));
	} catch ($ClassNotFoundException& ex) {
		$var($String, var$3, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.clonefail"_s))))->toString());
		$throwNew($SQLException, $($MessageFormat::format(var$3, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
	} catch ($OptionalDataException& ex) {
		$var($String, var$4, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.clonefail"_s))))->toString());
		$throwNew($SQLException, $($MessageFormat::format(var$4, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
	} catch ($IOException& ex) {
		$var($String, var$5, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.clonefail"_s))))->toString());
		$throwNew($SQLException, $($MessageFormat::format(var$5, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
	}
	$shouldNotReachHere();
}

$CachedRowSet* CachedRowSetImpl::createCopySchema() {
	int32_t nRows = this->numRows;
	this->numRows = 0;
	$var($CachedRowSet, crs, this->createCopy());
	this->numRows = nRows;
	return crs;
}

$CachedRowSet* CachedRowSetImpl::createCopyNoConstraints() {
	$useLocalCurrentObjectStackCache();
	$var(CachedRowSetImpl, crs, nullptr);
	$assign(crs, $cast(CachedRowSetImpl, this->createCopy()));
	$nc(crs)->initProperties();
	try {
		crs->unsetMatchColumn($(crs->getMatchColumnIndexes()));
	} catch ($SQLException& sqle) {
	}
	try {
		crs->unsetMatchColumn($(crs->getMatchColumnNames()));
	} catch ($SQLException& sqle) {
	}
	return crs;
}

$Collection* CachedRowSetImpl::toCollection() {
	$useLocalCurrentObjectStackCache();
	$var($TreeMap, tMap, $new($TreeMap));
	for (int32_t i = 0; i < this->numRows; ++i) {
		$var($Object, var$0, $of($Integer::valueOf(i)));
		tMap->put(var$0, $($nc(this->rvh)->get(i)));
	}
	return (tMap->values());
}

$Collection* CachedRowSetImpl::toCollection(int32_t column) {
	$useLocalCurrentObjectStackCache();
	int32_t nRows = this->numRows;
	$var($Vector, vec, $new($Vector, nRows));
	$var(CachedRowSetImpl, crsTemp, nullptr);
	$assign(crsTemp, $cast(CachedRowSetImpl, this->createCopy()));
	while (nRows != 0) {
		$nc(crsTemp)->next();
		vec->add($(crsTemp->getObject(column)));
		--nRows;
	}
	return static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>(vec)));
}

$Collection* CachedRowSetImpl::toCollection($String* column) {
	return toCollection(getColIdxByName(column));
}

$SyncProvider* CachedRowSetImpl::getSyncProvider() {
	return this->provider;
}

void CachedRowSetImpl::setSyncProvider($String* providerStr) {
	$set(this, provider, $SyncFactory::getInstance(providerStr));
	$set(this, rowSetReader, $nc(this->provider)->getRowSetReader());
	$set(this, rowSetWriter, $nc(this->provider)->getRowSetWriter());
}

void CachedRowSetImpl::execute() {
	execute(nullptr);
}

bool CachedRowSetImpl::next() {
	$useLocalCurrentObjectStackCache();
	if (this->cursorPos < 0 || this->cursorPos >= this->numRows + 1) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalidcp"_s))))->toString()));
	}
	bool ret = this->internalNext();
	notifyCursorMoved();
	return ret;
}

bool CachedRowSetImpl::internalNext() {
	bool ret = false;
	bool var$0 = false;
	do {
		if (this->cursorPos < this->numRows) {
			++this->cursorPos;
			ret = true;
		} else if (this->cursorPos == this->numRows) {
			++this->cursorPos;
			ret = false;
			break;
		}
		var$0 = (getShowDeleted() == false);
	} while (var$0 && (rowDeleted() == true));
	if (ret == true) {
		++this->absolutePos;
	} else {
		this->absolutePos = 0;
	}
	return ret;
}

void CachedRowSetImpl::close() {
	this->cursorPos = 0;
	this->absolutePos = 0;
	this->numRows = 0;
	this->numDeleted = 0;
	initProperties();
	$nc(this->rvh)->clear();
}

bool CachedRowSetImpl::wasNull() {
	return this->lastValueNull;
}

void CachedRowSetImpl::setLastValueNull(bool value) {
	this->lastValueNull = value;
}

void CachedRowSetImpl::checkIndex(int32_t idx) {
	$useLocalCurrentObjectStackCache();
	if (idx < 1 || this->RowSetMD == nullptr || idx > $nc(this->RowSetMD)->getColumnCount()) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalidcol"_s))))->toString()));
	}
}

void CachedRowSetImpl::checkCursor() {
	$useLocalCurrentObjectStackCache();
	bool var$0 = isAfterLast() == true;
	if (var$0 || isBeforeFirst() == true) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalidcp"_s))))->toString()));
	}
}

int32_t CachedRowSetImpl::getColIdxByName($String* name) {
	$useLocalCurrentObjectStackCache();
	$set(this, RowSetMD, $cast($RowSetMetaDataImpl, this->getMetaData()));
	int32_t cols = $nc(this->RowSetMD)->getColumnCount();
	if (this->RowSetMD != nullptr) {
		for (int32_t i = 1; i <= cols; ++i) {
			$var($String, colName, $nc(this->RowSetMD)->getColumnName(i));
			if (colName != nullptr) {
				if ($nc(name)->equalsIgnoreCase(colName)) {
					return (i);
				} else {
					continue;
				}
			}
		}
	}
	$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalcolnm"_s))))->toString()));
}

$BaseRow* CachedRowSetImpl::getCurrentRow() {
	if (this->onInsertRow == true) {
		return static_cast<$BaseRow*>(this->insertRow$);
	} else {
		return ($cast($BaseRow, $nc(this->rvh)->get(this->cursorPos - 1)));
	}
}

void CachedRowSetImpl::removeCurrentRow() {
	$nc(($cast($Row, $(getCurrentRow()))))->setDeleted();
	$nc(this->rvh)->remove(this->cursorPos - 1);
	--this->numRows;
}

$String* CachedRowSetImpl::getString(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return nullptr;
	}
	return $nc($of(value))->toString();
}

bool CachedRowSetImpl::getBoolean(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return false;
	}
	if ($instanceOf($Boolean, value)) {
		return $nc(($cast($Boolean, value)))->booleanValue();
	}
	try {
		return $Double::compare($Double::parseDouble($($nc($of(value))->toString())), (double)0) != 0;
	} catch ($NumberFormatException& ex) {
		$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.boolfail"_s))))->toString());
		$throwNew($SQLException, $($MessageFormat::format(var$0, $$new($ObjectArray, {
			$($of($nc($($nc($of(value))->toString()))->trim())),
			$($of($Integer::valueOf(columnIndex)))
		}))));
	}
	$shouldNotReachHere();
}

int8_t CachedRowSetImpl::getByte(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return (int8_t)0;
	}
	try {
		return ($nc(($($Byte::valueOf($($nc($of(value))->toString())))))->byteValue());
	} catch ($NumberFormatException& ex) {
		$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.bytefail"_s))))->toString());
		$throwNew($SQLException, $($MessageFormat::format(var$0, $$new($ObjectArray, {
			$($of($nc($($nc($of(value))->toString()))->trim())),
			$($of($Integer::valueOf(columnIndex)))
		}))));
	}
	$shouldNotReachHere();
}

int16_t CachedRowSetImpl::getShort(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return (int16_t)0;
	}
	try {
		return ($nc(($($Short::valueOf($($nc($($nc($of(value))->toString()))->trim())))))->shortValue());
	} catch ($NumberFormatException& ex) {
		$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.shortfail"_s))))->toString());
		$throwNew($SQLException, $($MessageFormat::format(var$0, $$new($ObjectArray, {
			$($of($nc($($nc($of(value))->toString()))->trim())),
			$($of($Integer::valueOf(columnIndex)))
		}))));
	}
	$shouldNotReachHere();
}

int32_t CachedRowSetImpl::getInt(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return 0;
	}
	try {
		return ($nc(($($Integer::valueOf($($nc($($nc($of(value))->toString()))->trim())))))->intValue());
	} catch ($NumberFormatException& ex) {
		$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.intfail"_s))))->toString());
		$throwNew($SQLException, $($MessageFormat::format(var$0, $$new($ObjectArray, {
			$($of($nc($($nc($of(value))->toString()))->trim())),
			$($of($Integer::valueOf(columnIndex)))
		}))));
	}
	$shouldNotReachHere();
}

int64_t CachedRowSetImpl::getLong(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return (int64_t)0;
	}
	try {
		return ($nc(($($Long::valueOf($($nc($($nc($of(value))->toString()))->trim())))))->longValue());
	} catch ($NumberFormatException& ex) {
		$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.longfail"_s))))->toString());
		$throwNew($SQLException, $($MessageFormat::format(var$0, $$new($ObjectArray, {
			$($of($nc($($nc($of(value))->toString()))->trim())),
			$($of($Integer::valueOf(columnIndex)))
		}))));
	}
	$shouldNotReachHere();
}

float CachedRowSetImpl::getFloat(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return (float)0;
	}
	try {
		return $Float::parseFloat($($nc($of(value))->toString()));
	} catch ($NumberFormatException& ex) {
		$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.floatfail"_s))))->toString());
		$throwNew($SQLException, $($MessageFormat::format(var$0, $$new($ObjectArray, {
			$($of($nc($($nc($of(value))->toString()))->trim())),
			$($of($Integer::valueOf(columnIndex)))
		}))));
	}
	$shouldNotReachHere();
}

double CachedRowSetImpl::getDouble(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return (double)0;
	}
	try {
		return $Double::parseDouble($($nc($($nc($of(value))->toString()))->trim()));
	} catch ($NumberFormatException& ex) {
		$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.doublefail"_s))))->toString());
		$throwNew($SQLException, $($MessageFormat::format(var$0, $$new($ObjectArray, {
			$($of($nc($($nc($of(value))->toString()))->trim())),
			$($of($Integer::valueOf(columnIndex)))
		}))));
	}
	$shouldNotReachHere();
}

$BigDecimal* CachedRowSetImpl::getBigDecimal(int32_t columnIndex, int32_t scale) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, nullptr);
	$var($BigDecimal, bDecimal, nullptr);
	$var($BigDecimal, retVal, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return ($new($BigDecimal, 0));
	}
	$assign(bDecimal, this->getBigDecimal(columnIndex));
	$assign(retVal, $nc(bDecimal)->setScale(scale));
	return retVal;
}

$bytes* CachedRowSetImpl::getBytes(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	if (isBinary($nc(this->RowSetMD)->getColumnType(columnIndex)) == false) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
	}
	return ($cast($bytes, $nc($(getCurrentRow()))->getColumnObject(columnIndex)));
}

$1Date* CachedRowSetImpl::getDate(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return nullptr;
	}
	switch ($nc(this->RowSetMD)->getColumnType(columnIndex)) {
	case $Types::DATE:
		{
			{
				int64_t sec = $nc(($cast($1Date, value)))->getTime();
				return $new($1Date, sec);
			}
		}
	case $Types::TIMESTAMP:
		{
			{
				int64_t sec = $nc(($cast($Timestamp, value)))->getTime();
				return $new($1Date, sec);
			}
		}
	case $Types::CHAR:
		{}
	case $Types::VARCHAR:
		{}
	case $Types::LONGVARCHAR:
		{
			{
				try {
					$var($DateFormat, df, $DateFormat::getDateInstance());
					return (($cast($1Date, $nc(df)->parse($($nc($of(value))->toString())))));
				} catch ($ParseException& ex) {
					$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.datefail"_s))))->toString());
					$throwNew($SQLException, $($MessageFormat::format(var$0, $$new($ObjectArray, {
						$($of($nc($($nc($of(value))->toString()))->trim())),
						$($of($Integer::valueOf(columnIndex)))
					}))));
				}
			}
		}
	default:
		{
			{
				$var($String, var$1, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.datefail"_s))))->toString());
				$throwNew($SQLException, $($MessageFormat::format(var$1, $$new($ObjectArray, {
					$($of($nc($($nc($of(value))->toString()))->trim())),
					$($of($Integer::valueOf(columnIndex)))
				}))));
			}
		}
	}
	$shouldNotReachHere();
}

$Time* CachedRowSetImpl::getTime(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return nullptr;
	}
	switch ($nc(this->RowSetMD)->getColumnType(columnIndex)) {
	case $Types::TIME:
		{
			{
				return $cast($Time, value);
			}
		}
	case $Types::TIMESTAMP:
		{
			{
				int64_t sec = $nc(($cast($Timestamp, value)))->getTime();
				return $new($Time, sec);
			}
		}
	case $Types::CHAR:
		{}
	case $Types::VARCHAR:
		{}
	case $Types::LONGVARCHAR:
		{
			{
				try {
					$var($DateFormat, tf, $DateFormat::getTimeInstance());
					return (($cast($Time, $nc(tf)->parse($($nc($of(value))->toString())))));
				} catch ($ParseException& ex) {
					$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.timefail"_s))))->toString());
					$throwNew($SQLException, $($MessageFormat::format(var$0, $$new($ObjectArray, {
						$($of($nc($($nc($of(value))->toString()))->trim())),
						$($of($Integer::valueOf(columnIndex)))
					}))));
				}
			}
		}
	default:
		{
			{
				$var($String, var$1, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.timefail"_s))))->toString());
				$throwNew($SQLException, $($MessageFormat::format(var$1, $$new($ObjectArray, {
					$($of($nc($($nc($of(value))->toString()))->trim())),
					$($of($Integer::valueOf(columnIndex)))
				}))));
			}
		}
	}
	$shouldNotReachHere();
}

$Timestamp* CachedRowSetImpl::getTimestamp(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return nullptr;
	}
	switch ($nc(this->RowSetMD)->getColumnType(columnIndex)) {
	case $Types::TIMESTAMP:
		{
			{
				return $cast($Timestamp, value);
			}
		}
	case $Types::TIME:
		{
			{
				int64_t sec = $nc(($cast($Time, value)))->getTime();
				return $new($Timestamp, sec);
			}
		}
	case $Types::DATE:
		{
			{
				int64_t sec = $nc(($cast($1Date, value)))->getTime();
				return $new($Timestamp, sec);
			}
		}
	case $Types::CHAR:
		{}
	case $Types::VARCHAR:
		{}
	case $Types::LONGVARCHAR:
		{
			{
				try {
					$var($DateFormat, tf, $DateFormat::getTimeInstance());
					return (($cast($Timestamp, $nc(tf)->parse($($nc($of(value))->toString())))));
				} catch ($ParseException& ex) {
					$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.timefail"_s))))->toString());
					$throwNew($SQLException, $($MessageFormat::format(var$0, $$new($ObjectArray, {
						$($of($nc($($nc($of(value))->toString()))->trim())),
						$($of($Integer::valueOf(columnIndex)))
					}))));
				}
			}
		}
	default:
		{
			{
				$var($String, var$1, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.timefail"_s))))->toString());
				$throwNew($SQLException, $($MessageFormat::format(var$1, $$new($ObjectArray, {
					$($of($nc($($nc($of(value))->toString()))->trim())),
					$($of($Integer::valueOf(columnIndex)))
				}))));
			}
		}
	}
	$shouldNotReachHere();
}

$InputStream* CachedRowSetImpl::getAsciiStream(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, nullptr);
	$set(this, asciiStream, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		this->lastValueNull = true;
		return nullptr;
	}
	if (isString($nc(this->RowSetMD)->getColumnType(columnIndex))) {
		$init($StandardCharsets);
		$set(this, asciiStream, $new($ByteArrayInputStream, $($nc(($cast($String, value)))->getBytes($StandardCharsets::US_ASCII))));
	} else {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
	}
	return this->asciiStream;
}

$InputStream* CachedRowSetImpl::getUnicodeStream(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$set(this, unicodeStream, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	bool var$0 = isBinary($nc(this->RowSetMD)->getColumnType(columnIndex)) == false;
	if (var$0 && isString($nc(this->RowSetMD)->getColumnType(columnIndex)) == false) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
	}
	$var($Object, value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		this->lastValueNull = true;
		return nullptr;
	}
	$set(this, unicodeStream, $new($StringBufferInputStream, $($nc($of(value))->toString())));
	return this->unicodeStream;
}

$InputStream* CachedRowSetImpl::getBinaryStream(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$set(this, binaryStream, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	if (isBinary($nc(this->RowSetMD)->getColumnType(columnIndex)) == false) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
	}
	$var($Object, value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		this->lastValueNull = true;
		return nullptr;
	}
	$set(this, binaryStream, $new($ByteArrayInputStream, $cast($bytes, value)));
	return this->binaryStream;
}

$String* CachedRowSetImpl::getString($String* columnName) {
	return getString(getColIdxByName(columnName));
}

bool CachedRowSetImpl::getBoolean($String* columnName) {
	return getBoolean(getColIdxByName(columnName));
}

int8_t CachedRowSetImpl::getByte($String* columnName) {
	return getByte(getColIdxByName(columnName));
}

int16_t CachedRowSetImpl::getShort($String* columnName) {
	return getShort(getColIdxByName(columnName));
}

int32_t CachedRowSetImpl::getInt($String* columnName) {
	return getInt(getColIdxByName(columnName));
}

int64_t CachedRowSetImpl::getLong($String* columnName) {
	return getLong(getColIdxByName(columnName));
}

float CachedRowSetImpl::getFloat($String* columnName) {
	return getFloat(getColIdxByName(columnName));
}

double CachedRowSetImpl::getDouble($String* columnName) {
	return getDouble(getColIdxByName(columnName));
}

$BigDecimal* CachedRowSetImpl::getBigDecimal($String* columnName, int32_t scale) {
	return getBigDecimal(getColIdxByName(columnName), scale);
}

$bytes* CachedRowSetImpl::getBytes($String* columnName) {
	return getBytes(getColIdxByName(columnName));
}

$1Date* CachedRowSetImpl::getDate($String* columnName) {
	return getDate(getColIdxByName(columnName));
}

$Time* CachedRowSetImpl::getTime($String* columnName) {
	return getTime(getColIdxByName(columnName));
}

$Timestamp* CachedRowSetImpl::getTimestamp($String* columnName) {
	return getTimestamp(getColIdxByName(columnName));
}

$InputStream* CachedRowSetImpl::getAsciiStream($String* columnName) {
	return getAsciiStream(getColIdxByName(columnName));
}

$InputStream* CachedRowSetImpl::getUnicodeStream($String* columnName) {
	return getUnicodeStream(getColIdxByName(columnName));
}

$InputStream* CachedRowSetImpl::getBinaryStream($String* columnName) {
	return getBinaryStream(getColIdxByName(columnName));
}

$SQLWarning* CachedRowSetImpl::getWarnings() {
	return this->sqlwarn;
}

void CachedRowSetImpl::clearWarnings() {
	$set(this, sqlwarn, nullptr);
}

$String* CachedRowSetImpl::getCursorName() {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.posupdate"_s))))->toString()));
	$shouldNotReachHere();
}

$ResultSetMetaData* CachedRowSetImpl::getMetaData() {
	return static_cast<$ResultSetMetaData*>(this->RowSetMD);
}

$Object* CachedRowSetImpl::getObject(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Object, value, nullptr);
	$var($Map, map, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return $of(nullptr);
	}
	if ($instanceOf($Struct, value)) {
		$var($Struct, s, $cast($Struct, value));
		$assign(map, getTypeMap());
		$Class* c = $cast($Class, $nc(map)->get($($nc(s)->getSQLTypeName())));
		if (c != nullptr) {
			$var($SQLData, obj, nullptr);
			try {
				$ReflectUtil::checkPackageAccess(c);
				$var($Object, tmp, c->newInstance());
				$assign(obj, $cast($SQLData, tmp));
			} catch ($Exception& ex) {
				$throwNew($SQLException, "Unable to Instantiate: "_s, static_cast<$Throwable*>(ex));
			}
			$var($ObjectArray, attribs, $nc(s)->getAttributes(map));
			$var($SQLInputImpl, sqlInput, $new($SQLInputImpl, attribs, map));
			$nc(obj)->readSQL(sqlInput, $(s->getSQLTypeName()));
			return $of($of(obj));
		}
	}
	return $of(value);
}

$Object* CachedRowSetImpl::getObject($String* columnName) {
	return $of(getObject(getColIdxByName(columnName)));
}

int32_t CachedRowSetImpl::findColumn($String* columnName) {
	return getColIdxByName(columnName);
}

$Reader* CachedRowSetImpl::getCharacterStream(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	if (isBinary($nc(this->RowSetMD)->getColumnType(columnIndex))) {
		$var($Object, value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
		if (value == nullptr) {
			this->lastValueNull = true;
			return nullptr;
		}
		$set(this, charStream, $new($InputStreamReader, $$new($ByteArrayInputStream, $cast($bytes, value))));
	} else if (isString($nc(this->RowSetMD)->getColumnType(columnIndex))) {
		$var($Object, value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
		if (value == nullptr) {
			this->lastValueNull = true;
			return nullptr;
		}
		$set(this, charStream, $new($StringReader, $($nc($of(value))->toString())));
	} else {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
	}
	return this->charStream;
}

$Reader* CachedRowSetImpl::getCharacterStream($String* columnName) {
	return getCharacterStream(getColIdxByName(columnName));
}

$BigDecimal* CachedRowSetImpl::getBigDecimal(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return nullptr;
	}
	try {
		return ($new($BigDecimal, $($nc($($nc($of(value))->toString()))->trim())));
	} catch ($NumberFormatException& ex) {
		$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.doublefail"_s))))->toString());
		$throwNew($SQLException, $($MessageFormat::format(var$0, $$new($ObjectArray, {
			$($of($nc($($nc($of(value))->toString()))->trim())),
			$($of($Integer::valueOf(columnIndex)))
		}))));
	}
	$shouldNotReachHere();
}

$BigDecimal* CachedRowSetImpl::getBigDecimal($String* columnName) {
	return getBigDecimal(getColIdxByName(columnName));
}

int32_t CachedRowSetImpl::size() {
	return this->numRows;
}

bool CachedRowSetImpl::isBeforeFirst() {
	if (this->cursorPos == 0 && this->numRows > 0) {
		return true;
	} else {
		return false;
	}
}

bool CachedRowSetImpl::isAfterLast() {
	if (this->cursorPos == this->numRows + 1 && this->numRows > 0) {
		return true;
	} else {
		return false;
	}
}

bool CachedRowSetImpl::isFirst() {
	int32_t saveCursorPos = this->cursorPos;
	int32_t saveAbsoluteCursorPos = this->absolutePos;
	internalFirst();
	if (this->cursorPos == saveCursorPos) {
		return true;
	} else {
		this->cursorPos = saveCursorPos;
		this->absolutePos = saveAbsoluteCursorPos;
		return false;
	}
}

bool CachedRowSetImpl::isLast() {
	int32_t saveCursorPos = this->cursorPos;
	int32_t saveAbsoluteCursorPos = this->absolutePos;
	bool saveShowDeleted = getShowDeleted();
	setShowDeleted(true);
	internalLast();
	if (this->cursorPos == saveCursorPos) {
		setShowDeleted(saveShowDeleted);
		return true;
	} else {
		setShowDeleted(saveShowDeleted);
		this->cursorPos = saveCursorPos;
		this->absolutePos = saveAbsoluteCursorPos;
		return false;
	}
}

void CachedRowSetImpl::beforeFirst() {
	$useLocalCurrentObjectStackCache();
	if (getType() == $ResultSet::TYPE_FORWARD_ONLY) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.beforefirst"_s))))->toString()));
	}
	this->cursorPos = 0;
	this->absolutePos = 0;
	notifyCursorMoved();
}

void CachedRowSetImpl::afterLast() {
	if (this->numRows > 0) {
		this->cursorPos = this->numRows + 1;
		this->absolutePos = 0;
		notifyCursorMoved();
	}
}

bool CachedRowSetImpl::first() {
	$useLocalCurrentObjectStackCache();
	if (getType() == $ResultSet::TYPE_FORWARD_ONLY) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.first"_s))))->toString()));
	}
	bool ret = this->internalFirst();
	notifyCursorMoved();
	return ret;
}

bool CachedRowSetImpl::internalFirst() {
	bool ret = false;
	if (this->numRows > 0) {
		this->cursorPos = 1;
		bool var$0 = (getShowDeleted() == false);
		if (var$0 && (rowDeleted() == true)) {
			ret = internalNext();
		} else {
			ret = true;
		}
	}
	if (ret == true) {
		this->absolutePos = 1;
	} else {
		this->absolutePos = 0;
	}
	return ret;
}

bool CachedRowSetImpl::last() {
	$useLocalCurrentObjectStackCache();
	if (getType() == $ResultSet::TYPE_FORWARD_ONLY) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.last"_s))))->toString()));
	}
	bool ret = this->internalLast();
	notifyCursorMoved();
	return ret;
}

bool CachedRowSetImpl::internalLast() {
	bool ret = false;
	if (this->numRows > 0) {
		this->cursorPos = this->numRows;
		bool var$0 = (getShowDeleted() == false);
		if (var$0 && (rowDeleted() == true)) {
			ret = internalPrevious();
		} else {
			ret = true;
		}
	}
	if (ret == true) {
		this->absolutePos = this->numRows - this->numDeleted;
	} else {
		this->absolutePos = 0;
	}
	return ret;
}

int32_t CachedRowSetImpl::getRow() {
	bool var$0 = this->numRows > 0 && this->cursorPos > 0 && this->cursorPos < (this->numRows + 1);
	if (var$0) {
		bool var$1 = getShowDeleted() == false;
		var$0 = (var$1 && rowDeleted() == false);
	}
	if (var$0) {
		return this->absolutePos;
	} else if (getShowDeleted() == true) {
		return this->cursorPos;
	} else {
		return 0;
	}
}

bool CachedRowSetImpl::absolute(int32_t row) {
	$useLocalCurrentObjectStackCache();
	if (row == 0 || getType() == $ResultSet::TYPE_FORWARD_ONLY) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.absolute"_s))))->toString()));
	}
	if (row > 0) {
		if (row > this->numRows) {
			afterLast();
			return false;
		} else if (this->absolutePos <= 0) {
			internalFirst();
		}
	} else if (this->cursorPos + row < 0) {
		beforeFirst();
		return false;
	} else if (this->absolutePos >= 0) {
		internalLast();
	}
	while (this->absolutePos != row) {
		if (this->absolutePos < row) {
			if (!internalNext()) {
				break;
			}
		} else if (!internalPrevious()) {
			break;
		}
	}
	notifyCursorMoved();
	bool var$0 = isAfterLast();
	if (var$0 || isBeforeFirst()) {
		return false;
	} else {
		return true;
	}
}

bool CachedRowSetImpl::relative(int32_t rows) {
	$useLocalCurrentObjectStackCache();
	bool var$1 = this->numRows == 0 || isBeforeFirst();
	bool var$0 = var$1 || isAfterLast();
	if (var$0 || getType() == $ResultSet::TYPE_FORWARD_ONLY) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.relative"_s))))->toString()));
	}
	if (rows == 0) {
		return true;
	}
	if (rows > 0) {
		if (this->cursorPos + rows > this->numRows) {
			afterLast();
		} else {
			for (int32_t i = 0; i < rows; ++i) {
				if (!internalNext()) {
					break;
				}
			}
		}
	} else if (this->cursorPos + rows < 0) {
		beforeFirst();
	} else {
		for (int32_t i = rows; i < 0; ++i) {
			if (!internalPrevious()) {
				break;
			}
		}
	}
	notifyCursorMoved();
	bool var$2 = isAfterLast();
	if (var$2 || isBeforeFirst()) {
		return false;
	} else {
		return true;
	}
}

bool CachedRowSetImpl::previous() {
	$useLocalCurrentObjectStackCache();
	if (getType() == $ResultSet::TYPE_FORWARD_ONLY) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.last"_s))))->toString()));
	}
	if (this->cursorPos < 0 || this->cursorPos > this->numRows + 1) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalidcp"_s))))->toString()));
	}
	bool ret = this->internalPrevious();
	notifyCursorMoved();
	return ret;
}

bool CachedRowSetImpl::internalPrevious() {
	bool ret = false;
	bool var$0 = false;
	do {
		if (this->cursorPos > 1) {
			--this->cursorPos;
			ret = true;
		} else if (this->cursorPos == 1) {
			--this->cursorPos;
			ret = false;
			break;
		}
		var$0 = (getShowDeleted() == false);
	} while (var$0 && (rowDeleted() == true));
	if (ret == true) {
		--this->absolutePos;
	} else {
		this->absolutePos = 0;
	}
	return ret;
}

bool CachedRowSetImpl::rowUpdated() {
	$useLocalCurrentObjectStackCache();
	checkCursor();
	if (this->onInsertRow == true) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalidop"_s))))->toString()));
	}
	return ($nc(($cast($Row, $(getCurrentRow()))))->getUpdated());
}

bool CachedRowSetImpl::columnUpdated(int32_t idx) {
	$useLocalCurrentObjectStackCache();
	checkCursor();
	if (this->onInsertRow == true) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalidop"_s))))->toString()));
	}
	return ($nc(($cast($Row, $(getCurrentRow()))))->getColUpdated(idx - 1));
}

bool CachedRowSetImpl::columnUpdated($String* columnName) {
	return columnUpdated(getColIdxByName(columnName));
}

bool CachedRowSetImpl::rowInserted() {
	$useLocalCurrentObjectStackCache();
	checkCursor();
	if (this->onInsertRow == true) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalidop"_s))))->toString()));
	}
	return ($nc(($cast($Row, $(getCurrentRow()))))->getInserted());
}

bool CachedRowSetImpl::rowDeleted() {
	$useLocalCurrentObjectStackCache();
	bool var$0 = isAfterLast() == true;
	if (var$0 || isBeforeFirst() == true || this->onInsertRow == true) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalidcp"_s))))->toString()));
	}
	return ($nc(($cast($Row, $(getCurrentRow()))))->getDeleted());
}

bool CachedRowSetImpl::isNumeric(int32_t type) {
	switch (type) {
	case $Types::NUMERIC:
		{}
	case $Types::DECIMAL:
		{}
	case $Types::BIT:
		{}
	case $Types::TINYINT:
		{}
	case $Types::SMALLINT:
		{}
	case $Types::INTEGER:
		{}
	case $Types::BIGINT:
		{}
	case $Types::REAL:
		{}
	case $Types::DOUBLE:
		{}
	case $Types::FLOAT:
		{
			return true;
		}
	default:
		{
			return false;
		}
	}
}

bool CachedRowSetImpl::isString(int32_t type) {
	switch (type) {
	case $Types::CHAR:
		{}
	case $Types::VARCHAR:
		{}
	case $Types::LONGVARCHAR:
		{
			return true;
		}
	default:
		{
			return false;
		}
	}
}

bool CachedRowSetImpl::isBinary(int32_t type) {
	switch (type) {
	case $Types::BINARY:
		{}
	case $Types::VARBINARY:
		{}
	case $Types::LONGVARBINARY:
		{
			return true;
		}
	default:
		{
			return false;
		}
	}
}

bool CachedRowSetImpl::isTemporal(int32_t type) {
	switch (type) {
	case $Types::DATE:
		{}
	case $Types::TIME:
		{}
	case $Types::TIMESTAMP:
		{
			return true;
		}
	default:
		{
			return false;
		}
	}
}

bool CachedRowSetImpl::isBoolean(int32_t type) {
	switch (type) {
	case $Types::BIT:
		{}
	case $Types::BOOLEAN:
		{
			return true;
		}
	default:
		{
			return false;
		}
	}
}

$Object* CachedRowSetImpl::convertNumeric(Object$* srcObj, int32_t srcType, int32_t trgType) {
	$useLocalCurrentObjectStackCache();
	if (srcType == trgType) {
		return $of(srcObj);
	}
	bool var$0 = isNumeric(trgType) == false;
	if (var$0 && isString(trgType) == false) {
		$throwNew($SQLException, $$str({$($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()), $$str(trgType)}));
	}
	try {
		{
			$var($Integer, i, nullptr)
			switch (trgType) {
			case $Types::BIT:
				{
					$assign(i, $Integer::valueOf($($nc($($nc($of(srcObj))->toString()))->trim())));
					return $of($nc(i)->equals($($Integer::valueOf(0))) ? $Boolean::valueOf(false) : $Boolean::valueOf(true));
				}
			case $Types::TINYINT:
				{
					return $of($Byte::valueOf($($nc($($nc($of(srcObj))->toString()))->trim())));
				}
			case $Types::SMALLINT:
				{
					return $of($Short::valueOf($($nc($($nc($of(srcObj))->toString()))->trim())));
				}
			case $Types::INTEGER:
				{
					return $of($Integer::valueOf($($nc($($nc($of(srcObj))->toString()))->trim())));
				}
			case $Types::BIGINT:
				{
					return $of($Long::valueOf($($nc($($nc($of(srcObj))->toString()))->trim())));
				}
			case $Types::NUMERIC:
				{}
			case $Types::DECIMAL:
				{
					return $of($new($BigDecimal, $($nc($($nc($of(srcObj))->toString()))->trim())));
				}
			case $Types::REAL:
				{}
			case $Types::FLOAT:
				{
					return $of($Float::valueOf($($nc($($nc($of(srcObj))->toString()))->trim())));
				}
			case $Types::DOUBLE:
				{
					return $of($Double::valueOf($($nc($($nc($of(srcObj))->toString()))->trim())));
				}
			case $Types::CHAR:
				{}
			case $Types::VARCHAR:
				{}
			case $Types::LONGVARCHAR:
				{
					return $of($nc($of(srcObj))->toString());
				}
			default:
				{
					$throwNew($SQLException, $$str({$($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()), $$str(trgType)}));
				}
			}
		}
	} catch ($NumberFormatException& ex) {
		$throwNew($SQLException, $$str({$($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()), $$str(trgType)}));
	}
	$shouldNotReachHere();
}

$Object* CachedRowSetImpl::convertTemporal(Object$* srcObj, int32_t srcType, int32_t trgType) {
	$useLocalCurrentObjectStackCache();
	if (srcType == trgType) {
		return $of(srcObj);
	}
	bool var$0 = isNumeric(trgType) == true;
	if (!var$0) {
		bool var$1 = isString(trgType) == false;
		var$0 = (var$1 && isTemporal(trgType) == false);
	}
	if (var$0) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
	}
	try {
		switch (trgType) {
		case $Types::DATE:
			{
				if (srcType == $Types::TIMESTAMP) {
					return $of($new($1Date, $nc(($cast($Timestamp, srcObj)))->getTime()));
				} else {
					$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
				}
			}
		case $Types::TIMESTAMP:
			{
				if (srcType == $Types::TIME) {
					return $of($new($Timestamp, $nc(($cast($Time, srcObj)))->getTime()));
				} else {
					return $of($new($Timestamp, $nc(($cast($1Date, srcObj)))->getTime()));
				}
			}
		case $Types::TIME:
			{
				if (srcType == $Types::TIMESTAMP) {
					return $of($new($Time, $nc(($cast($Timestamp, srcObj)))->getTime()));
				} else {
					$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
				}
			}
		case $Types::CHAR:
			{}
		case $Types::VARCHAR:
			{}
		case $Types::LONGVARCHAR:
			{
				return $of($nc($of(srcObj))->toString());
			}
		default:
			{
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
			}
		}
	} catch ($NumberFormatException& ex) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
	}
	$shouldNotReachHere();
}

$Object* CachedRowSetImpl::convertBoolean(Object$* srcObj, int32_t srcType, int32_t trgType) {
	$useLocalCurrentObjectStackCache();
	if (srcType == trgType) {
		return $of(srcObj);
	}
	bool var$0 = isNumeric(trgType) == true;
	if (!var$0) {
		bool var$1 = isString(trgType) == false;
		var$0 = (var$1 && isBoolean(trgType) == false);
	}
	if (var$0) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
	}
	try {
		{
			$var($Integer, i, nullptr)
			switch (trgType) {
			case $Types::BIT:
				{
					$assign(i, $Integer::valueOf($($nc($($nc($of(srcObj))->toString()))->trim())));
					return $of($nc(i)->equals($($Integer::valueOf(0))) ? $Boolean::valueOf(false) : $Boolean::valueOf(true));
				}
			case $Types::BOOLEAN:
				{
					return $of($Boolean::valueOf($($nc($($nc($of(srcObj))->toString()))->trim())));
				}
			default:
				{
					$throwNew($SQLException, $$str({$($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()), $$str(trgType)}));
				}
			}
		}
	} catch ($NumberFormatException& ex) {
		$throwNew($SQLException, $$str({$($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()), $$str(trgType)}));
	}
	$shouldNotReachHere();
}

void CachedRowSetImpl::updateNull(int32_t columnIndex) {
	checkIndex(columnIndex);
	checkCursor();
	$var($BaseRow, row, getCurrentRow());
	$nc(row)->setColumnObject(columnIndex, nullptr);
}

void CachedRowSetImpl::updateBoolean(int32_t columnIndex, bool x) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	$var($Object, var$0, $of($Boolean::valueOf(x)));
	$var($Object, obj, convertBoolean(var$0, $Types::BIT, $nc(this->RowSetMD)->getColumnType(columnIndex)));
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, obj);
}

void CachedRowSetImpl::updateByte(int32_t columnIndex, int8_t x) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	$var($Object, var$0, $of($Byte::valueOf(x)));
	$var($Object, obj, convertNumeric(var$0, $Types::TINYINT, $nc(this->RowSetMD)->getColumnType(columnIndex)));
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, obj);
}

void CachedRowSetImpl::updateShort(int32_t columnIndex, int16_t x) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	$var($Object, var$0, $of($Short::valueOf(x)));
	$var($Object, obj, convertNumeric(var$0, $Types::SMALLINT, $nc(this->RowSetMD)->getColumnType(columnIndex)));
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, obj);
}

void CachedRowSetImpl::updateInt(int32_t columnIndex, int32_t x) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	$var($Object, var$0, $of($Integer::valueOf(x)));
	$var($Object, obj, convertNumeric(var$0, $Types::INTEGER, $nc(this->RowSetMD)->getColumnType(columnIndex)));
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, obj);
}

void CachedRowSetImpl::updateLong(int32_t columnIndex, int64_t x) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	$var($Object, var$0, $of($Long::valueOf(x)));
	$var($Object, obj, convertNumeric(var$0, $Types::BIGINT, $nc(this->RowSetMD)->getColumnType(columnIndex)));
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, obj);
}

void CachedRowSetImpl::updateFloat(int32_t columnIndex, float x) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	$var($Object, var$0, $of($Float::valueOf(x)));
	$var($Object, obj, convertNumeric(var$0, $Types::REAL, $nc(this->RowSetMD)->getColumnType(columnIndex)));
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, obj);
}

void CachedRowSetImpl::updateDouble(int32_t columnIndex, double x) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	$var($Object, var$0, $of($Double::valueOf(x)));
	$var($Object, obj, convertNumeric(var$0, $Types::DOUBLE, $nc(this->RowSetMD)->getColumnType(columnIndex)));
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, obj);
}

void CachedRowSetImpl::updateBigDecimal(int32_t columnIndex, $BigDecimal* x) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	$var($Object, obj, convertNumeric(x, $Types::NUMERIC, $nc(this->RowSetMD)->getColumnType(columnIndex)));
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, obj);
}

void CachedRowSetImpl::updateString(int32_t columnIndex, $String* x) {
	checkIndex(columnIndex);
	checkCursor();
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, x);
}

void CachedRowSetImpl::updateBytes(int32_t columnIndex, $bytes* x) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	if (isBinary($nc(this->RowSetMD)->getColumnType(columnIndex)) == false) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
	}
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, x);
}

void CachedRowSetImpl::updateDate(int32_t columnIndex, $1Date* x) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	$var($Object, obj, convertTemporal(x, $Types::DATE, $nc(this->RowSetMD)->getColumnType(columnIndex)));
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, obj);
}

void CachedRowSetImpl::updateTime(int32_t columnIndex, $Time* x) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	$var($Object, obj, convertTemporal(x, $Types::TIME, $nc(this->RowSetMD)->getColumnType(columnIndex)));
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, obj);
}

void CachedRowSetImpl::updateTimestamp(int32_t columnIndex, $Timestamp* x) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	$var($Object, obj, convertTemporal(x, $Types::TIMESTAMP, $nc(this->RowSetMD)->getColumnType(columnIndex)));
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, obj);
}

void CachedRowSetImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x, int32_t length) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	bool var$0 = isString($nc(this->RowSetMD)->getColumnType(columnIndex)) == false;
	if (var$0 && isBinary($nc(this->RowSetMD)->getColumnType(columnIndex)) == false) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
	}
	$var($bytes, buf, $new($bytes, length));
	try {
		int32_t charsRead = 0;
		do {
			charsRead += $nc(x)->read(buf, charsRead, length - charsRead);
		} while (charsRead != length);
	} catch ($IOException& ex) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.asciistream"_s))))->toString()));
	}
	$var($String, str, $new($String, buf));
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, str);
}

void CachedRowSetImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x, int32_t length) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	if (isBinary($nc(this->RowSetMD)->getColumnType(columnIndex)) == false) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
	}
	$var($bytes, buf, $new($bytes, length));
	try {
		int32_t bytesRead = 0;
		do {
			bytesRead += $nc(x)->read(buf, bytesRead, length - bytesRead);
		} while (bytesRead != -1);
	} catch ($IOException& ex) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.binstream"_s))))->toString()));
	}
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, buf);
}

void CachedRowSetImpl::updateCharacterStream(int32_t columnIndex, $Reader* x, int32_t length) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	bool var$0 = isString($nc(this->RowSetMD)->getColumnType(columnIndex)) == false;
	if (var$0 && isBinary($nc(this->RowSetMD)->getColumnType(columnIndex)) == false) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
	}
	$var($chars, buf, $new($chars, length));
	try {
		int32_t charsRead = 0;
		do {
			charsRead += $nc(x)->read(buf, charsRead, length - charsRead);
		} while (charsRead != length);
	} catch ($IOException& ex) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.binstream"_s))))->toString()));
	}
	$var($String, str, $new($String, buf));
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, str);
}

void CachedRowSetImpl::updateObject(int32_t columnIndex, Object$* x, int32_t scale) {
	checkIndex(columnIndex);
	checkCursor();
	int32_t type = $nc(this->RowSetMD)->getColumnType(columnIndex);
	if (type == $Types::DECIMAL || type == $Types::NUMERIC) {
		$nc(($cast($BigDecimal, x)))->setScale(scale);
	}
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, x);
}

void CachedRowSetImpl::updateObject(int32_t columnIndex, Object$* x) {
	checkIndex(columnIndex);
	checkCursor();
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, x);
}

void CachedRowSetImpl::updateNull($String* columnName) {
	updateNull(getColIdxByName(columnName));
}

void CachedRowSetImpl::updateBoolean($String* columnName, bool x) {
	updateBoolean(getColIdxByName(columnName), x);
}

void CachedRowSetImpl::updateByte($String* columnName, int8_t x) {
	updateByte(getColIdxByName(columnName), x);
}

void CachedRowSetImpl::updateShort($String* columnName, int16_t x) {
	updateShort(getColIdxByName(columnName), x);
}

void CachedRowSetImpl::updateInt($String* columnName, int32_t x) {
	updateInt(getColIdxByName(columnName), x);
}

void CachedRowSetImpl::updateLong($String* columnName, int64_t x) {
	updateLong(getColIdxByName(columnName), x);
}

void CachedRowSetImpl::updateFloat($String* columnName, float x) {
	updateFloat(getColIdxByName(columnName), x);
}

void CachedRowSetImpl::updateDouble($String* columnName, double x) {
	updateDouble(getColIdxByName(columnName), x);
}

void CachedRowSetImpl::updateBigDecimal($String* columnName, $BigDecimal* x) {
	updateBigDecimal(getColIdxByName(columnName), x);
}

void CachedRowSetImpl::updateString($String* columnName, $String* x) {
	updateString(getColIdxByName(columnName), x);
}

void CachedRowSetImpl::updateBytes($String* columnName, $bytes* x) {
	updateBytes(getColIdxByName(columnName), x);
}

void CachedRowSetImpl::updateDate($String* columnName, $1Date* x) {
	updateDate(getColIdxByName(columnName), x);
}

void CachedRowSetImpl::updateTime($String* columnName, $Time* x) {
	updateTime(getColIdxByName(columnName), x);
}

void CachedRowSetImpl::updateTimestamp($String* columnName, $Timestamp* x) {
	updateTimestamp(getColIdxByName(columnName), x);
}

void CachedRowSetImpl::updateAsciiStream($String* columnName, $InputStream* x, int32_t length) {
	updateAsciiStream(getColIdxByName(columnName), x, length);
}

void CachedRowSetImpl::updateBinaryStream($String* columnName, $InputStream* x, int32_t length) {
	updateBinaryStream(getColIdxByName(columnName), x, length);
}

void CachedRowSetImpl::updateCharacterStream($String* columnName, $Reader* reader, int32_t length) {
	updateCharacterStream(getColIdxByName(columnName), reader, length);
}

void CachedRowSetImpl::updateObject($String* columnName, Object$* x, int32_t scale) {
	updateObject(getColIdxByName(columnName), x, scale);
}

void CachedRowSetImpl::updateObject($String* columnName, Object$* x) {
	updateObject(getColIdxByName(columnName), x);
}

void CachedRowSetImpl::insertRow() {
	$useLocalCurrentObjectStackCache();
	int32_t pos = 0;
	if (this->onInsertRow == false || $nc(this->insertRow$)->isCompleteRow(this->RowSetMD) == false) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.failedins"_s))))->toString()));
	}
	$var($ObjectArray, toInsert, getParams());
	for (int32_t i = 0; i < $nc(toInsert)->length; ++i) {
		$nc(this->insertRow$)->setColumnObject(i + 1, toInsert->get(i));
	}
	int32_t var$0 = $nc(this->RowSetMD)->getColumnCount();
	$var($Row, insRow, $new($Row, var$0, $($nc(this->insertRow$)->getOrigRow())));
	insRow->setInserted();
	if (this->currentRow >= this->numRows || this->currentRow < 0) {
		pos = this->numRows;
	} else {
		pos = this->currentRow;
	}
	$nc(this->rvh)->add(pos, insRow);
	++this->numRows;
	notifyRowChanged();
}

void CachedRowSetImpl::updateRow() {
	$useLocalCurrentObjectStackCache();
	if (this->onInsertRow == true) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.updateins"_s))))->toString()));
	}
	$nc(($cast($Row, $(getCurrentRow()))))->setUpdated();
	notifyRowChanged();
}

void CachedRowSetImpl::deleteRow() {
	checkCursor();
	$nc(($cast($Row, $(getCurrentRow()))))->setDeleted();
	++this->numDeleted;
	notifyRowChanged();
}

void CachedRowSetImpl::refreshRow() {
	$useLocalCurrentObjectStackCache();
	checkCursor();
	if (this->onInsertRow == true) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalidcp"_s))))->toString()));
	}
	$var($Row, currentRow, $cast($Row, getCurrentRow()));
	$nc(currentRow)->clearUpdated();
}

void CachedRowSetImpl::cancelRowUpdates() {
	$useLocalCurrentObjectStackCache();
	checkCursor();
	if (this->onInsertRow == true) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalidcp"_s))))->toString()));
	}
	$var($Row, currentRow, $cast($Row, getCurrentRow()));
	if ($nc(currentRow)->getUpdated() == true) {
		currentRow->clearUpdated();
		notifyRowChanged();
	}
}

void CachedRowSetImpl::moveToInsertRow() {
	$useLocalCurrentObjectStackCache();
	if (getConcurrency() == $ResultSet::CONCUR_READ_ONLY) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.movetoins"_s))))->toString()));
	}
	if (this->insertRow$ == nullptr) {
		if (this->RowSetMD == nullptr) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.movetoins1"_s))))->toString()));
		}
		int32_t numCols = $nc(this->RowSetMD)->getColumnCount();
		if (numCols > 0) {
			$set(this, insertRow$, $new($InsertRow, numCols));
		} else {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.movetoins2"_s))))->toString()));
		}
	}
	this->onInsertRow = true;
	this->currentRow = this->cursorPos;
	this->cursorPos = -1;
	$nc(this->insertRow$)->initInsertRow();
}

void CachedRowSetImpl::moveToCurrentRow() {
	if (this->onInsertRow == false) {
		return;
	} else {
		this->cursorPos = this->currentRow;
		this->onInsertRow = false;
	}
}

$Statement* CachedRowSetImpl::getStatement() {
	return nullptr;
}

$Object* CachedRowSetImpl::getObject(int32_t columnIndex, $Map* map) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Object, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return $of(nullptr);
	}
	if ($instanceOf($Struct, value)) {
		$var($Struct, s, $cast($Struct, value));
		$Class* c = $cast($Class, $nc(map)->get($($nc(s)->getSQLTypeName())));
		if (c != nullptr) {
			$var($SQLData, obj, nullptr);
			try {
				$ReflectUtil::checkPackageAccess(c);
				$var($Object, tmp, c->newInstance());
				$assign(obj, $cast($SQLData, tmp));
			} catch ($Exception& ex) {
				$throwNew($SQLException, "Unable to Instantiate: "_s, static_cast<$Throwable*>(ex));
			}
			$var($ObjectArray, attribs, $nc(s)->getAttributes(map));
			$var($SQLInputImpl, sqlInput, $new($SQLInputImpl, attribs, map));
			$nc(obj)->readSQL(sqlInput, $(s->getSQLTypeName()));
			return $of($of(obj));
		}
	}
	return $of(value);
}

$Ref* CachedRowSetImpl::getRef(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($Ref, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	if ($nc(this->RowSetMD)->getColumnType(columnIndex) != $Types::REF) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
	}
	setLastValueNull(false);
	$assign(value, ($cast($Ref, $nc($(getCurrentRow()))->getColumnObject(columnIndex))));
	if (value == nullptr) {
		setLastValueNull(true);
		return nullptr;
	}
	return value;
}

$Blob* CachedRowSetImpl::getBlob(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($Blob, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	if ($nc(this->RowSetMD)->getColumnType(columnIndex) != $Types::BLOB) {
		$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.type"_s))))->toString());
		$nc($System::out)->println($($MessageFormat::format(var$0, $$new($ObjectArray, {$($of($Integer::valueOf($nc(this->RowSetMD)->getColumnType(columnIndex))))}))));
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
	}
	setLastValueNull(false);
	$assign(value, ($cast($Blob, $nc($(getCurrentRow()))->getColumnObject(columnIndex))));
	if (value == nullptr) {
		setLastValueNull(true);
		return nullptr;
	}
	return value;
}

$Clob* CachedRowSetImpl::getClob(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($Clob, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	if ($nc(this->RowSetMD)->getColumnType(columnIndex) != $Types::CLOB) {
		$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.type"_s))))->toString());
		$nc($System::out)->println($($MessageFormat::format(var$0, $$new($ObjectArray, {$($of($Integer::valueOf($nc(this->RowSetMD)->getColumnType(columnIndex))))}))));
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
	}
	setLastValueNull(false);
	$assign(value, ($cast($Clob, $nc($(getCurrentRow()))->getColumnObject(columnIndex))));
	if (value == nullptr) {
		setLastValueNull(true);
		return nullptr;
	}
	return value;
}

$1Array* CachedRowSetImpl::getArray(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($1Array, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	if ($nc(this->RowSetMD)->getColumnType(columnIndex) != $Types::ARRAY) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
	}
	setLastValueNull(false);
	$assign(value, ($cast($1Array, $nc($(getCurrentRow()))->getColumnObject(columnIndex))));
	if (value == nullptr) {
		setLastValueNull(true);
		return nullptr;
	}
	return value;
}

$Object* CachedRowSetImpl::getObject($String* columnName, $Map* map) {
	return $of(getObject(getColIdxByName(columnName), map));
}

$Ref* CachedRowSetImpl::getRef($String* colName) {
	return getRef(getColIdxByName(colName));
}

$Blob* CachedRowSetImpl::getBlob($String* colName) {
	return getBlob(getColIdxByName(colName));
}

$Clob* CachedRowSetImpl::getClob($String* colName) {
	return getClob(getColIdxByName(colName));
}

$1Array* CachedRowSetImpl::getArray($String* colName) {
	return getArray(getColIdxByName(colName));
}

$1Date* CachedRowSetImpl::getDate(int32_t columnIndex, $Calendar* cal) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return nullptr;
	}
	$assign(value, convertTemporal(value, $nc(this->RowSetMD)->getColumnType(columnIndex), $Types::DATE));
	$var($Calendar, defaultCal, $Calendar::getInstance());
	$nc(defaultCal)->setTime($cast($Date, value));
	$nc(cal)->set($Calendar::YEAR, defaultCal->get($Calendar::YEAR));
	cal->set($Calendar::MONTH, defaultCal->get($Calendar::MONTH));
	cal->set($Calendar::DAY_OF_MONTH, defaultCal->get($Calendar::DAY_OF_MONTH));
	return $new($1Date, $nc($(cal->getTime()))->getTime());
}

$1Date* CachedRowSetImpl::getDate($String* columnName, $Calendar* cal) {
	return getDate(getColIdxByName(columnName), cal);
}

$Time* CachedRowSetImpl::getTime(int32_t columnIndex, $Calendar* cal) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return nullptr;
	}
	$assign(value, convertTemporal(value, $nc(this->RowSetMD)->getColumnType(columnIndex), $Types::TIME));
	$var($Calendar, defaultCal, $Calendar::getInstance());
	$nc(defaultCal)->setTime($cast($Date, value));
	$nc(cal)->set($Calendar::HOUR_OF_DAY, defaultCal->get($Calendar::HOUR_OF_DAY));
	cal->set($Calendar::MINUTE, defaultCal->get($Calendar::MINUTE));
	cal->set($Calendar::SECOND, defaultCal->get($Calendar::SECOND));
	return $new($Time, $nc($(cal->getTime()))->getTime());
}

$Time* CachedRowSetImpl::getTime($String* columnName, $Calendar* cal) {
	return getTime(getColIdxByName(columnName), cal);
}

$Timestamp* CachedRowSetImpl::getTimestamp(int32_t columnIndex, $Calendar* cal) {
	$useLocalCurrentObjectStackCache();
	$var($Object, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	setLastValueNull(false);
	$assign(value, $nc($(getCurrentRow()))->getColumnObject(columnIndex));
	if (value == nullptr) {
		setLastValueNull(true);
		return nullptr;
	}
	$assign(value, convertTemporal(value, $nc(this->RowSetMD)->getColumnType(columnIndex), $Types::TIMESTAMP));
	$var($Calendar, defaultCal, $Calendar::getInstance());
	$nc(defaultCal)->setTime($cast($Date, value));
	$nc(cal)->set($Calendar::YEAR, defaultCal->get($Calendar::YEAR));
	cal->set($Calendar::MONTH, defaultCal->get($Calendar::MONTH));
	cal->set($Calendar::DAY_OF_MONTH, defaultCal->get($Calendar::DAY_OF_MONTH));
	cal->set($Calendar::HOUR_OF_DAY, defaultCal->get($Calendar::HOUR_OF_DAY));
	cal->set($Calendar::MINUTE, defaultCal->get($Calendar::MINUTE));
	cal->set($Calendar::SECOND, defaultCal->get($Calendar::SECOND));
	return $new($Timestamp, $nc($(cal->getTime()))->getTime());
}

$Timestamp* CachedRowSetImpl::getTimestamp($String* columnName, $Calendar* cal) {
	return getTimestamp(getColIdxByName(columnName), cal);
}

$Connection* CachedRowSetImpl::getConnection() {
	return this->conn;
}

void CachedRowSetImpl::setMetaData($RowSetMetaData* md) {
	$set(this, RowSetMD, $cast($RowSetMetaDataImpl, md));
}

$ResultSet* CachedRowSetImpl::getOriginal() {
	$useLocalCurrentObjectStackCache();
	$var(CachedRowSetImpl, crs, $new(CachedRowSetImpl));
	$set(crs, RowSetMD, this->RowSetMD);
	crs->numRows = this->numRows;
	crs->cursorPos = 0;
	int32_t colCount = $nc(this->RowSetMD)->getColumnCount();
	$var($Row, orig, nullptr);
	{
		$var($Iterator, i, $nc(this->rvh)->iterator());
		for (; $nc(i)->hasNext();) {
			$assign(orig, $new($Row, colCount, $($nc(($cast($Row, $(i->next()))))->getOrigRow())));
			$nc(crs->rvh)->add(orig);
		}
	}
	return static_cast<$ResultSet*>(crs);
}

$ResultSet* CachedRowSetImpl::getOriginalRow() {
	$useLocalCurrentObjectStackCache();
	$var(CachedRowSetImpl, crs, $new(CachedRowSetImpl));
	$set(crs, RowSetMD, this->RowSetMD);
	crs->numRows = 1;
	crs->cursorPos = 0;
	crs->setTypeMap($(this->getTypeMap()));
	int32_t var$0 = $nc(this->RowSetMD)->getColumnCount();
	$var($Row, orig, $new($Row, var$0, $($nc($(getCurrentRow()))->getOrigRow())));
	$nc(crs->rvh)->add(orig);
	return static_cast<$ResultSet*>(crs);
}

void CachedRowSetImpl::setOriginalRow() {
	$useLocalCurrentObjectStackCache();
	if (this->onInsertRow == true) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalidop"_s))))->toString()));
	}
	$var($Row, row, $cast($Row, getCurrentRow()));
	makeRowOriginal(row);
	if ($nc(row)->getDeleted() == true) {
		removeCurrentRow();
	}
}

void CachedRowSetImpl::makeRowOriginal($Row* row) {
	if ($nc(row)->getInserted() == true) {
		row->clearInserted();
	}
	if ($nc(row)->getUpdated() == true) {
		row->moveCurrentToOrig();
	}
}

void CachedRowSetImpl::setOriginal() {
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i, $nc(this->rvh)->iterator());
		for (; $nc(i)->hasNext();) {
			$var($Row, row, $cast($Row, i->next()));
			makeRowOriginal(row);
			if ($nc(row)->getDeleted() == true) {
				i->remove();
				--this->numRows;
			}
		}
	}
	this->numDeleted = 0;
	notifyRowSetChanged();
}

$String* CachedRowSetImpl::getTableName() {
	return this->tableName;
}

void CachedRowSetImpl::setTableName($String* tabName) {
	$useLocalCurrentObjectStackCache();
	if (tabName == nullptr) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.tablename"_s))))->toString()));
	} else {
		$set(this, tableName, tabName);
	}
}

$ints* CachedRowSetImpl::getKeyColumns() {
	$var($ints, keyColumns, this->keyCols);
	return (keyColumns == nullptr) ? ($ints*)nullptr : $Arrays::copyOf(keyColumns, $nc(keyColumns)->length);
}

void CachedRowSetImpl::setKeyColumns($ints* keys) {
	$useLocalCurrentObjectStackCache();
	int32_t numCols = 0;
	if (this->RowSetMD != nullptr) {
		numCols = $nc(this->RowSetMD)->getColumnCount();
		if ($nc(keys)->length > numCols) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.keycols"_s))))->toString()));
		}
	}
	$set(this, keyCols, $new($ints, $nc(keys)->length));
	for (int32_t i = 0; i < keys->length; ++i) {
		if (this->RowSetMD != nullptr && (keys->get(i) <= 0 || keys->get(i) > numCols)) {
			$throwNew($SQLException, $$str({$($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalidcol"_s))))->toString()), $$str(keys->get(i))}));
		}
		$nc(this->keyCols)->set(i, keys->get(i));
	}
}

void CachedRowSetImpl::updateRef(int32_t columnIndex, $Ref* ref) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, $$new($SerialRef, ref));
}

void CachedRowSetImpl::updateRef($String* columnName, $Ref* ref) {
	updateRef(getColIdxByName(columnName), ref);
}

void CachedRowSetImpl::updateClob(int32_t columnIndex, $Clob* c) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	if (this->dbmslocatorsUpdateCopy) {
		$nc($(getCurrentRow()))->setColumnObject(columnIndex, $$new($SerialClob, c));
	} else {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotsupp"_s))))->toString()));
	}
}

void CachedRowSetImpl::updateClob($String* columnName, $Clob* c) {
	updateClob(getColIdxByName(columnName), c);
}

void CachedRowSetImpl::updateBlob(int32_t columnIndex, $Blob* b) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	if (this->dbmslocatorsUpdateCopy) {
		$nc($(getCurrentRow()))->setColumnObject(columnIndex, $$new($SerialBlob, b));
	} else {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotsupp"_s))))->toString()));
	}
}

void CachedRowSetImpl::updateBlob($String* columnName, $Blob* b) {
	updateBlob(getColIdxByName(columnName), b);
}

void CachedRowSetImpl::updateArray(int32_t columnIndex, $1Array* a) {
	$useLocalCurrentObjectStackCache();
	checkIndex(columnIndex);
	checkCursor();
	$nc($(getCurrentRow()))->setColumnObject(columnIndex, $$new($SerialArray, a));
}

void CachedRowSetImpl::updateArray($String* columnName, $1Array* a) {
	updateArray(getColIdxByName(columnName), a);
}

$URL* CachedRowSetImpl::getURL(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$var($URL, value, nullptr);
	checkIndex(columnIndex);
	checkCursor();
	if ($nc(this->RowSetMD)->getColumnType(columnIndex) != $Types::DATALINK) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.dtypemismt"_s))))->toString()));
	}
	setLastValueNull(false);
	$assign(value, ($cast($URL, $nc($(getCurrentRow()))->getColumnObject(columnIndex))));
	if (value == nullptr) {
		setLastValueNull(true);
		return nullptr;
	}
	return value;
}

$URL* CachedRowSetImpl::getURL($String* columnName) {
	return getURL(getColIdxByName(columnName));
}

$RowSetWarning* CachedRowSetImpl::getRowSetWarnings() {
	try {
		notifyCursorMoved();
	} catch ($SQLException& e) {
	}
	return this->rowsetWarning;
}

$String* CachedRowSetImpl::buildTableName($String* command$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, command, command$renamed);
	int32_t indexFrom = 0;
	int32_t indexComma = 0;
	$var($String, strTablename, ""_s);
	$assign(command, $nc(command)->trim());
	if ($(command->toLowerCase())->startsWith("select"_s)) {
		indexFrom = $(command->toLowerCase())->indexOf("from"_s);
		indexComma = command->indexOf((int32_t)u',', indexFrom);
		if (indexComma == -1) {
			int32_t var$0 = indexFrom + "from"_s->length();
			$assign(strTablename, ($(command->substring(var$0, command->length())))->trim());
			$var($String, tabName, strTablename);
			int32_t idxWhere = $(tabName->toLowerCase())->indexOf("where"_s);
			if (idxWhere != -1) {
				$assign(tabName, $(tabName->substring(0, idxWhere))->trim());
			}
			$assign(strTablename, tabName);
		} else {
		}
	} else if ($(command->toLowerCase())->startsWith("insert"_s)) {
	} else if ($(command->toLowerCase())->startsWith("update"_s)) {
	}
	return strTablename;
}

void CachedRowSetImpl::commit() {
	$nc(this->conn)->commit();
}

void CachedRowSetImpl::rollback() {
	$nc(this->conn)->rollback();
}

void CachedRowSetImpl::rollback($Savepoint* s) {
	$nc(this->conn)->rollback(s);
}

void CachedRowSetImpl::unsetMatchColumn($ints* columnIdxes) {
	$useLocalCurrentObjectStackCache();
	int32_t i_val = 0;
	for (int32_t j = 0; j < $nc(columnIdxes)->length; ++j) {
		i_val = ($Integer::parseInt($($nc(($cast($Integer, $($nc(this->iMatchColumns)->get(j)))))->toString())));
		if (columnIdxes->get(j) != i_val) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.matchcols"_s))))->toString()));
		}
	}
	for (int32_t i = 0; i < $nc(columnIdxes)->length; ++i) {
		$nc(this->iMatchColumns)->set(i, $($Integer::valueOf(-1)));
	}
}

void CachedRowSetImpl::unsetMatchColumn($StringArray* columnIdxes) {
	$useLocalCurrentObjectStackCache();
	for (int32_t j = 0; j < $nc(columnIdxes)->length; ++j) {
		if (!$nc(columnIdxes->get(j))->equals($($nc(this->strMatchColumns)->get(j)))) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.matchcols"_s))))->toString()));
		}
	}
	for (int32_t i = 0; i < $nc(columnIdxes)->length; ++i) {
		$nc(this->strMatchColumns)->set(i, nullptr);
	}
}

$StringArray* CachedRowSetImpl::getMatchColumnNames() {
	$useLocalCurrentObjectStackCache();
	$var($StringArray, str_temp, $new($StringArray, $nc(this->strMatchColumns)->size()));
	if ($nc(this->strMatchColumns)->get(0) == nullptr) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.setmatchcols"_s))))->toString()));
	}
	$nc(this->strMatchColumns)->copyInto(str_temp);
	return str_temp;
}

$ints* CachedRowSetImpl::getMatchColumnIndexes() {
	$useLocalCurrentObjectStackCache();
	$var($IntegerArray, int_temp, $new($IntegerArray, $nc(this->iMatchColumns)->size()));
	$var($ints, i_temp, $new($ints, $nc(this->iMatchColumns)->size()));
	int32_t i_val = 0;
	i_val = $nc(($cast($Integer, $($nc(this->iMatchColumns)->get(0)))))->intValue();
	if (i_val == -1) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.setmatchcols"_s))))->toString()));
	}
	$nc(this->iMatchColumns)->copyInto(int_temp);
	for (int32_t i = 0; i < int_temp->length; ++i) {
		i_temp->set(i, $nc((int_temp->get(i)))->intValue());
	}
	return i_temp;
}

void CachedRowSetImpl::setMatchColumn($ints* columnIdxes) {
	$useLocalCurrentObjectStackCache();
	for (int32_t j = 0; j < $nc(columnIdxes)->length; ++j) {
		if (columnIdxes->get(j) < 0) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.matchcols1"_s))))->toString()));
		}
	}
	for (int32_t i = 0; i < $nc(columnIdxes)->length; ++i) {
		$nc(this->iMatchColumns)->add(i, $($Integer::valueOf(columnIdxes->get(i))));
	}
}

void CachedRowSetImpl::setMatchColumn($StringArray* columnNames) {
	$useLocalCurrentObjectStackCache();
	for (int32_t j = 0; j < $nc(columnNames)->length; ++j) {
		if (columnNames->get(j) == nullptr || $nc(columnNames->get(j))->isEmpty()) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.matchcols2"_s))))->toString()));
		}
	}
	for (int32_t i = 0; i < $nc(columnNames)->length; ++i) {
		$nc(this->strMatchColumns)->add(i, columnNames->get(i));
	}
}

void CachedRowSetImpl::setMatchColumn(int32_t columnIdx) {
	$useLocalCurrentObjectStackCache();
	if (columnIdx < 0) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.matchcols1"_s))))->toString()));
	} else {
		$nc(this->iMatchColumns)->set(0, $($Integer::valueOf(columnIdx)));
	}
}

void CachedRowSetImpl::setMatchColumn($String* columnName$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, columnName, columnName$renamed);
	if (columnName == nullptr || $nc(($assign(columnName, $nc(columnName)->trim())))->isEmpty()) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.matchcols2"_s))))->toString()));
	} else {
		$nc(this->strMatchColumns)->set(0, columnName);
	}
}

void CachedRowSetImpl::unsetMatchColumn(int32_t columnIdx) {
	$useLocalCurrentObjectStackCache();
	if (!$nc(($cast($Integer, $($nc(this->iMatchColumns)->get(0)))))->equals($($Integer::valueOf(columnIdx)))) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.unsetmatch"_s))))->toString()));
	} else if ($nc(this->strMatchColumns)->get(0) != nullptr) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.unsetmatch1"_s))))->toString()));
	} else {
		$nc(this->iMatchColumns)->set(0, $($Integer::valueOf(-1)));
	}
}

void CachedRowSetImpl::unsetMatchColumn($String* columnName$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, columnName, columnName$renamed);
	$assign(columnName, $nc(columnName)->trim());
	if (!($nc(($cast($String, $($nc(this->strMatchColumns)->get(0)))))->equals(columnName))) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.unsetmatch"_s))))->toString()));
	} else if ($nc(($cast($Integer, $($nc(this->iMatchColumns)->get(0)))))->intValue() > 0) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.unsetmatch2"_s))))->toString()));
	} else {
		$nc(this->strMatchColumns)->set(0, nullptr);
	}
}

void CachedRowSetImpl::rowSetPopulated($RowSetEvent* event$renamed, int32_t numRows) {
	$useLocalCurrentObjectStackCache();
	$var($RowSetEvent, event, event$renamed);
	if (numRows < 0 || numRows < getFetchSize()) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.numrows"_s))))->toString()));
	}
	if ($mod(size(), numRows) == 0) {
		$var($RowSetEvent, event_temp, $new($RowSetEvent, this));
		$assign(event, event_temp);
		notifyRowSetChanged();
	}
}

void CachedRowSetImpl::populate($ResultSet* data, int32_t start) {
	$useLocalCurrentObjectStackCache();
	int32_t rowsFetched = 0;
	$var($Row, currentRow, nullptr);
	int32_t numCols = 0;
	int32_t i = 0;
	$var($Map, map, getTypeMap());
	$var($Object, obj, nullptr);
	int32_t mRows = 0;
	this->cursorPos = 0;
	if (this->populatecallcount == 0) {
		if (start < 0) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.startpos"_s))))->toString()));
		}
		if (getMaxRows() == 0) {
			$nc(data)->absolute(start);
			while (data->next()) {
				++this->totalRows;
			}
			++this->totalRows;
		}
		this->startPos = start;
	}
	this->populatecallcount = this->populatecallcount + 1;
	$set(this, resultSet, data);
	bool var$0 = (this->endPos - this->startPos) >= getMaxRows();
	if (var$0 && (getMaxRows() > 0)) {
		this->endPos = this->prevEndPos;
		this->pagenotend = false;
		return;
	}
	if ((this->maxRowsreached != getMaxRows() || this->maxRowsreached != this->totalRows) && this->pagenotend) {
		this->startPrev = start - getPageSize();
	}
	if (this->pageSize == 0) {
		this->prevEndPos = this->endPos;
		this->endPos = start + getMaxRows();
	} else {
		this->prevEndPos = this->endPos;
		this->endPos = start + getPageSize();
	}
	if (start == 1) {
		$nc(this->resultSet)->beforeFirst();
	} else {
		$nc(this->resultSet)->absolute(start - 1);
	}
	if (this->pageSize == 0) {
		$set(this, rvh, $new($Vector, getMaxRows()));
	} else {
		$set(this, rvh, $new($Vector, getPageSize()));
	}
	if (data == nullptr) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.populate"_s))))->toString()));
	}
	$set(this, RSMD, $nc(data)->getMetaData());
	$set(this, RowSetMD, $new($RowSetMetaDataImpl));
	initMetaData(this->RowSetMD, this->RSMD);
	$set(this, RSMD, nullptr);
	numCols = $nc(this->RowSetMD)->getColumnCount();
	mRows = this->getMaxRows();
	rowsFetched = 0;
	$assign(currentRow, nullptr);
	if (!data->next() && mRows == 0) {
		this->endPos = this->prevEndPos;
		this->pagenotend = false;
		return;
	}
	data->previous();
	while (data->next()) {
		$assign(currentRow, $new($Row, numCols));
		if (this->pageSize == 0) {
			if (rowsFetched >= mRows && mRows > 0) {
				$nc(this->rowsetWarning)->setNextException($$new($SQLException, "Populating rows setting has exceeded max row setting"_s));
				break;
			}
		} else if ((rowsFetched >= this->pageSize) || (this->maxRowsreached >= mRows && mRows > 0)) {
			$nc(this->rowsetWarning)->setNextException($$new($SQLException, "Populating rows setting has exceeded max row setting"_s));
			break;
		}
		for (i = 1; i <= numCols; ++i) {
			if (map == nullptr) {
				$assign(obj, data->getObject(i));
			} else {
				$assign(obj, data->getObject(i, map));
			}
			if ($instanceOf($Struct, obj)) {
				$assign(obj, $new($SerialStruct, $cast($Struct, obj), map));
			} else if ($instanceOf($SQLData, obj)) {
				$assign(obj, $new($SerialStruct, $cast($SQLData, obj), map));
			} else if ($instanceOf($Blob, obj)) {
				$assign(obj, $new($SerialBlob, $cast($Blob, obj)));
			} else if ($instanceOf($Clob, obj)) {
				$assign(obj, $new($SerialClob, $cast($Clob, obj)));
			} else if ($instanceOf($1Array, obj)) {
				$assign(obj, $new($SerialArray, $cast($1Array, obj), map));
			}
			currentRow->initColumnObject(i, obj);
		}
		++rowsFetched;
		++this->maxRowsreached;
		$nc(this->rvh)->add(currentRow);
	}
	this->numRows = rowsFetched;
	notifyRowSetChanged();
}

bool CachedRowSetImpl::nextPage() {
	$useLocalCurrentObjectStackCache();
	if (this->populatecallcount == 0) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.nextpage"_s))))->toString()));
	}
	this->onFirstPage = false;
	if (this->callWithCon) {
		$nc(this->crsReader)->setStartPosition(this->endPos);
		$nc(this->crsReader)->readData(static_cast<$RowSetInternal*>(this));
		$set(this, resultSet, nullptr);
	} else {
		populate(this->resultSet, this->endPos);
	}
	return this->pagenotend;
}

void CachedRowSetImpl::setPageSize(int32_t size) {
	$useLocalCurrentObjectStackCache();
	if (size < 0) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.pagesize"_s))))->toString()));
	}
	bool var$0 = size > getMaxRows();
	if (var$0 && getMaxRows() != 0) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.pagesize1"_s))))->toString()));
	}
	this->pageSize = size;
}

int32_t CachedRowSetImpl::getPageSize() {
	return this->pageSize;
}

bool CachedRowSetImpl::previousPage() {
	$useLocalCurrentObjectStackCache();
	int32_t pS = 0;
	int32_t mR = 0;
	int32_t rem = 0;
	pS = getPageSize();
	mR = this->maxRowsreached;
	if (this->populatecallcount == 0) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.nextpage"_s))))->toString()));
	}
	if (!this->callWithCon) {
		if ($nc(this->resultSet)->getType() == $ResultSet::TYPE_FORWARD_ONLY) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.fwdonly"_s))))->toString()));
		}
	}
	this->pagenotend = true;
	if (this->startPrev < this->startPos) {
		this->onFirstPage = true;
		return false;
	}
	if (this->onFirstPage) {
		return false;
	}
	rem = $mod(mR, pS);
	if (rem == 0) {
		this->maxRowsreached -= (2 * pS);
		if (this->callWithCon) {
			$nc(this->crsReader)->setStartPosition(this->startPrev);
			$nc(this->crsReader)->readData(static_cast<$RowSetInternal*>(this));
			$set(this, resultSet, nullptr);
		} else {
			populate(this->resultSet, this->startPrev);
		}
		return true;
	} else {
		this->maxRowsreached -= (pS + rem);
		if (this->callWithCon) {
			$nc(this->crsReader)->setStartPosition(this->startPrev);
			$nc(this->crsReader)->readData(static_cast<$RowSetInternal*>(this));
			$set(this, resultSet, nullptr);
		} else {
			populate(this->resultSet, this->startPrev);
		}
		return true;
	}
}

void CachedRowSetImpl::setRowInserted(bool insertFlag) {
	$useLocalCurrentObjectStackCache();
	checkCursor();
	if (this->onInsertRow == true) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.invalidop"_s))))->toString()));
	}
	if (insertFlag) {
		$nc(($cast($Row, $(getCurrentRow()))))->setInserted();
	} else {
		$nc(($cast($Row, $(getCurrentRow()))))->clearInserted();
	}
}

$SQLXML* CachedRowSetImpl::getSQLXML(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
	$shouldNotReachHere();
}

$SQLXML* CachedRowSetImpl::getSQLXML($String* colName) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
	$shouldNotReachHere();
}

$RowId* CachedRowSetImpl::getRowId(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
	$shouldNotReachHere();
}

$RowId* CachedRowSetImpl::getRowId($String* columnName) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
	$shouldNotReachHere();
}

void CachedRowSetImpl::updateRowId(int32_t columnIndex, $RowId* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
}

void CachedRowSetImpl::updateRowId($String* columnName, $RowId* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
}

int32_t CachedRowSetImpl::getHoldability() {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
	$shouldNotReachHere();
}

bool CachedRowSetImpl::isClosed() {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
	$shouldNotReachHere();
}

void CachedRowSetImpl::updateNString(int32_t columnIndex, $String* nString) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
}

void CachedRowSetImpl::updateNString($String* columnName, $String* nString) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
}

void CachedRowSetImpl::updateNClob(int32_t columnIndex, $NClob* nClob) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
}

void CachedRowSetImpl::updateNClob($String* columnName, $NClob* nClob) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
}

$NClob* CachedRowSetImpl::getNClob(int32_t i) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
	$shouldNotReachHere();
}

$NClob* CachedRowSetImpl::getNClob($String* colName) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
	$shouldNotReachHere();
}

$Object* CachedRowSetImpl::unwrap($Class* iface) {
	return $of(nullptr);
}

bool CachedRowSetImpl::isWrapperFor($Class* interfaces) {
	return false;
}

void CachedRowSetImpl::setSQLXML(int32_t parameterIndex, $SQLXML* xmlObject) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
}

void CachedRowSetImpl::setSQLXML($String* parameterName, $SQLXML* xmlObject) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
}

void CachedRowSetImpl::setRowId(int32_t parameterIndex, $RowId* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
}

void CachedRowSetImpl::setRowId($String* parameterName, $RowId* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
}

void CachedRowSetImpl::setNCharacterStream(int32_t parameterIndex, $Reader* value) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setNClob($String* parameterName, $NClob* value) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
}

$Reader* CachedRowSetImpl::getNCharacterStream(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
	$shouldNotReachHere();
}

$Reader* CachedRowSetImpl::getNCharacterStream($String* columnName) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
	$shouldNotReachHere();
}

void CachedRowSetImpl::updateSQLXML(int32_t columnIndex, $SQLXML* xmlObject) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
}

void CachedRowSetImpl::updateSQLXML($String* columnName, $SQLXML* xmlObject) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
}

$String* CachedRowSetImpl::getNString(int32_t columnIndex) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
	$shouldNotReachHere();
}

$String* CachedRowSetImpl::getNString($String* columnName) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
	$shouldNotReachHere();
}

void CachedRowSetImpl::updateNCharacterStream(int32_t columnIndex, $Reader* x, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
}

void CachedRowSetImpl::updateNCharacterStream($String* columnName, $Reader* x, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.opnotysupp"_s))))->toString()));
}

void CachedRowSetImpl::updateNCharacterStream(int32_t columnIndex, $Reader* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateNCharacterStream($String* columnLabel, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateBlob(int32_t columnIndex, $InputStream* inputStream, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateBlob($String* columnLabel, $InputStream* inputStream, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateBlob(int32_t columnIndex, $InputStream* inputStream) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateBlob($String* columnLabel, $InputStream* inputStream) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateClob(int32_t columnIndex, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateClob($String* columnLabel, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateClob(int32_t columnIndex, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateClob($String* columnLabel, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateNClob(int32_t columnIndex, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateNClob($String* columnLabel, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateNClob(int32_t columnIndex, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateNClob($String* columnLabel, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x, int64_t length) {
}

void CachedRowSetImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x, int64_t length) {
}

void CachedRowSetImpl::updateCharacterStream(int32_t columnIndex, $Reader* x, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateCharacterStream($String* columnLabel, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateAsciiStream($String* columnLabel, $InputStream* x, int64_t length) {
}

void CachedRowSetImpl::updateBinaryStream($String* columnLabel, $InputStream* x, int64_t length) {
}

void CachedRowSetImpl::updateBinaryStream(int32_t columnIndex, $InputStream* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateBinaryStream($String* columnLabel, $InputStream* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateCharacterStream(int32_t columnIndex, $Reader* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateCharacterStream($String* columnLabel, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateAsciiStream(int32_t columnIndex, $InputStream* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::updateAsciiStream($String* columnLabel, $InputStream* x) {
}

void CachedRowSetImpl::setURL(int32_t parameterIndex, $URL* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setNClob(int32_t parameterIndex, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setNClob($String* parameterName, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setNClob($String* parameterName, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setNClob(int32_t parameterIndex, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setNClob(int32_t parameterIndex, $NClob* value) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setNString(int32_t parameterIndex, $String* value) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setNString($String* parameterName, $String* value) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setNCharacterStream(int32_t parameterIndex, $Reader* value, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setNCharacterStream($String* parameterName, $Reader* value, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setNCharacterStream($String* parameterName, $Reader* value) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setTimestamp($String* parameterName, $Timestamp* x, $Calendar* cal) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setClob($String* parameterName, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setClob($String* parameterName, $Clob* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setClob($String* parameterName, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setDate($String* parameterName, $1Date* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setDate($String* parameterName, $1Date* x, $Calendar* cal) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setTime($String* parameterName, $Time* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setTime($String* parameterName, $Time* x, $Calendar* cal) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setClob(int32_t parameterIndex, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setClob(int32_t parameterIndex, $Reader* reader, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setBlob(int32_t parameterIndex, $InputStream* inputStream, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setBlob(int32_t parameterIndex, $InputStream* inputStream) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setBlob($String* parameterName, $InputStream* inputStream, int64_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setBlob($String* parameterName, $Blob* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setBlob($String* parameterName, $InputStream* inputStream) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setObject($String* parameterName, Object$* x, int32_t targetSqlType, int32_t scale) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setObject($String* parameterName, Object$* x, int32_t targetSqlType) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setObject($String* parameterName, Object$* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setAsciiStream($String* parameterName, $InputStream* x, int32_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setBinaryStream($String* parameterName, $InputStream* x, int32_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setCharacterStream($String* parameterName, $Reader* reader, int32_t length) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setAsciiStream($String* parameterName, $InputStream* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setBinaryStream($String* parameterName, $InputStream* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setCharacterStream($String* parameterName, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setBigDecimal($String* parameterName, $BigDecimal* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setString($String* parameterName, $String* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setBytes($String* parameterName, $bytes* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setTimestamp($String* parameterName, $Timestamp* x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setNull($String* parameterName, int32_t sqlType) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setNull($String* parameterName, int32_t sqlType, $String* typeName) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setBoolean($String* parameterName, bool x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setByte($String* parameterName, int8_t x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setShort($String* parameterName, int16_t x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setInt($String* parameterName, int32_t x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setLong($String* parameterName, int64_t x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setFloat($String* parameterName, float x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::setDouble($String* parameterName, double x) {
	$useLocalCurrentObjectStackCache();
	$throwNew($SQLFeatureNotSupportedException, $($nc($of($($nc(this->resBundle)->handleGetObject("cachedrowsetimpl.featnotsupp"_s))))->toString()));
}

void CachedRowSetImpl::readObject($ObjectInputStream* ois) {
	$nc(ois)->defaultReadObject();
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

$Object* CachedRowSetImpl::getObject(int32_t columnIndex, $Class* type) {
	$throwNew($SQLFeatureNotSupportedException, "Not supported yet."_s);
	$shouldNotReachHere();
}

$Object* CachedRowSetImpl::getObject($String* columnLabel, $Class* type) {
	$throwNew($SQLFeatureNotSupportedException, "Not supported yet."_s);
	$shouldNotReachHere();
}

CachedRowSetImpl::CachedRowSetImpl() {
}

$Class* CachedRowSetImpl::load$($String* name, bool initialize) {
	$loadClass(CachedRowSetImpl, name, initialize, &_CachedRowSetImpl_ClassInfo_, allocate$CachedRowSetImpl);
	return class$;
}

$Class* CachedRowSetImpl::class$ = nullptr;

		} // rowset
	} // sun
} // com
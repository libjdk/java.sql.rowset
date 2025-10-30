#include <com/sun/rowset/internal/WebRowSetXmlWriter.h>

#include <com/sun/rowset/JdbcRowSetResourceBundle.h>
#include <java/io/IOException.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/OutputStreamWriter.h>
#include <java/io/Writer.h>
#include <java/math/BigDecimal.h>
#include <java/sql/Date.h>
#include <java/sql/ResultSet.h>
#include <java/sql/ResultSetMetaData.h>
#include <java/sql/SQLException.h>
#include <java/sql/Time.h>
#include <java/sql/Timestamp.h>
#include <java/sql/Types.h>
#include <java/text/MessageFormat.h>
#include <java/util/Iterator.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/Stack.h>
#include <javax/sql/RowSet.h>
#include <javax/sql/RowSetInternal.h>
#include <javax/sql/rowset/CachedRowSet.h>
#include <javax/sql/rowset/WebRowSet.h>
#include <javax/sql/rowset/spi/SyncProvider.h>
#include <javax/sql/rowset/spi/XmlWriter.h>
#include <jcpp.h>

#undef BIGINT
#undef BINARY
#undef BIT
#undef BOOLEAN
#undef CHAR
#undef DATE
#undef DECIMAL
#undef DOUBLE
#undef FLOAT
#undef INTEGER
#undef LONGVARBINARY
#undef LONGVARCHAR
#undef NUMERIC
#undef REAL
#undef SMALLINT
#undef TIME
#undef TIMESTAMP
#undef TINYINT
#undef VARBINARY
#undef VARCHAR

using $JdbcRowSetResourceBundle = ::com::sun::rowset::JdbcRowSetResourceBundle;
using $IOException = ::java::io::IOException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $OutputStream = ::java::io::OutputStream;
using $OutputStreamWriter = ::java::io::OutputStreamWriter;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $Writer = ::java::io::Writer;
using $Boolean = ::java::lang::Boolean;
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
using $1Date = ::java::sql::Date;
using $ResultSet = ::java::sql::ResultSet;
using $ResultSetMetaData = ::java::sql::ResultSetMetaData;
using $SQLException = ::java::sql::SQLException;
using $Time = ::java::sql::Time;
using $Timestamp = ::java::sql::Timestamp;
using $Types = ::java::sql::Types;
using $MessageFormat = ::java::text::MessageFormat;
using $Date = ::java::util::Date;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Stack = ::java::util::Stack;
using $Vector = ::java::util::Vector;
using $RowSet = ::javax::sql::RowSet;
using $RowSetInternal = ::javax::sql::RowSetInternal;
using $CachedRowSet = ::javax::sql::rowset::CachedRowSet;
using $WebRowSet = ::javax::sql::rowset::WebRowSet;
using $SyncProvider = ::javax::sql::rowset::spi::SyncProvider;
using $XmlWriter = ::javax::sql::rowset::spi::XmlWriter;

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

$FieldInfo _WebRowSetXmlWriter_FieldInfo_[] = {
	{"writer", "Ljava/io/Writer;", nullptr, $PRIVATE | $TRANSIENT, $field(WebRowSetXmlWriter, writer)},
	{"stack", "Ljava/util/Stack;", "Ljava/util/Stack<Ljava/lang/String;>;", $PRIVATE, $field(WebRowSetXmlWriter, stack)},
	{"resBundle", "Lcom/sun/rowset/JdbcRowSetResourceBundle;", nullptr, $PRIVATE, $field(WebRowSetXmlWriter, resBundle)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(WebRowSetXmlWriter, serialVersionUID)},
	{}
};

$MethodInfo _WebRowSetXmlWriter_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(WebRowSetXmlWriter::*)()>(&WebRowSetXmlWriter::init$))},
	{"beginSection", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)($String*)>(&WebRowSetXmlWriter::beginSection)), "java.io.IOException"},
	{"beginTag", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)($String*)>(&WebRowSetXmlWriter::beginTag)), "java.io.IOException"},
	{"emptyTag", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)($String*)>(&WebRowSetXmlWriter::emptyTag)), "java.io.IOException"},
	{"endHeader", "()V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)()>(&WebRowSetXmlWriter::endHeader)), "java.io.IOException"},
	{"endSection", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)($String*)>(&WebRowSetXmlWriter::endSection)), "java.io.IOException"},
	{"endSection", "()V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)()>(&WebRowSetXmlWriter::endSection)), "java.io.IOException"},
	{"endTag", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)($String*)>(&WebRowSetXmlWriter::endTag)), "java.io.IOException"},
	{"getTag", "()Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(WebRowSetXmlWriter::*)()>(&WebRowSetXmlWriter::getTag))},
	{"processSpecialCharacters", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(WebRowSetXmlWriter::*)($String*)>(&WebRowSetXmlWriter::processSpecialCharacters))},
	{"propBoolean", "(Ljava/lang/String;Z)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)($String*,bool)>(&WebRowSetXmlWriter::propBoolean)), "java.io.IOException"},
	{"propInteger", "(Ljava/lang/String;I)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)($String*,int32_t)>(&WebRowSetXmlWriter::propInteger)), "java.io.IOException"},
	{"propString", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)($String*,$String*)>(&WebRowSetXmlWriter::propString)), "java.io.IOException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)($ObjectInputStream*)>(&WebRowSetXmlWriter::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"setTag", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)($String*)>(&WebRowSetXmlWriter::setTag))},
	{"startHeader", "()V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)()>(&WebRowSetXmlWriter::startHeader)), "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeBigDecimal", "(Ljava/math/BigDecimal;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)($BigDecimal*)>(&WebRowSetXmlWriter::writeBigDecimal)), "java.io.IOException"},
	{"writeBoolean", "(Z)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)(bool)>(&WebRowSetXmlWriter::writeBoolean)), "java.io.IOException"},
	{"writeData", "(Ljavax/sql/rowset/WebRowSet;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)($WebRowSet*)>(&WebRowSetXmlWriter::writeData)), "java.io.IOException"},
	{"writeData", "(Ljavax/sql/RowSetInternal;)Z", nullptr, $PUBLIC},
	{"writeDouble", "(D)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)(double)>(&WebRowSetXmlWriter::writeDouble)), "java.io.IOException"},
	{"writeEmptyString", "()V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)()>(&WebRowSetXmlWriter::writeEmptyString)), "java.io.IOException"},
	{"writeFloat", "(F)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)(float)>(&WebRowSetXmlWriter::writeFloat)), "java.io.IOException"},
	{"writeIndent", "(I)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)(int32_t)>(&WebRowSetXmlWriter::writeIndent)), "java.io.IOException"},
	{"writeInteger", "(I)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)(int32_t)>(&WebRowSetXmlWriter::writeInteger)), "java.io.IOException"},
	{"writeLong", "(J)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)(int64_t)>(&WebRowSetXmlWriter::writeLong)), "java.io.IOException"},
	{"writeMetaData", "(Ljavax/sql/rowset/WebRowSet;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)($WebRowSet*)>(&WebRowSetXmlWriter::writeMetaData)), "java.io.IOException"},
	{"writeNull", "()V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)()>(&WebRowSetXmlWriter::writeNull)), "java.io.IOException"},
	{"writeProperties", "(Ljavax/sql/rowset/WebRowSet;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)($WebRowSet*)>(&WebRowSetXmlWriter::writeProperties)), "java.io.IOException"},
	{"writeRowSet", "(Ljavax/sql/rowset/WebRowSet;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)($WebRowSet*)>(&WebRowSetXmlWriter::writeRowSet)), "java.sql.SQLException"},
	{"writeShort", "(S)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)(int16_t)>(&WebRowSetXmlWriter::writeShort)), "java.io.IOException"},
	{"writeString", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)($String*)>(&WebRowSetXmlWriter::writeString)), "java.io.IOException"},
	{"writeStringData", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)($String*)>(&WebRowSetXmlWriter::writeStringData)), "java.io.IOException"},
	{"writeValue", "(ILjavax/sql/RowSet;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlWriter::*)(int32_t,$RowSet*)>(&WebRowSetXmlWriter::writeValue)), "java.io.IOException"},
	{"writeXML", "(Ljavax/sql/rowset/WebRowSet;Ljava/io/Writer;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"writeXML", "(Ljavax/sql/rowset/WebRowSet;Ljava/io/OutputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{}
};

$ClassInfo _WebRowSetXmlWriter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.rowset.internal.WebRowSetXmlWriter",
	"java.lang.Object",
	"javax.sql.rowset.spi.XmlWriter,java.io.Serializable",
	_WebRowSetXmlWriter_FieldInfo_,
	_WebRowSetXmlWriter_MethodInfo_
};

$Object* allocate$WebRowSetXmlWriter($Class* clazz) {
	return $of($alloc(WebRowSetXmlWriter));
}

int32_t WebRowSetXmlWriter::hashCode() {
	 return this->$XmlWriter::hashCode();
}

bool WebRowSetXmlWriter::equals(Object$* arg0) {
	 return this->$XmlWriter::equals(arg0);
}

$Object* WebRowSetXmlWriter::clone() {
	 return this->$XmlWriter::clone();
}

$String* WebRowSetXmlWriter::toString() {
	 return this->$XmlWriter::toString();
}

void WebRowSetXmlWriter::finalize() {
	this->$XmlWriter::finalize();
}

void WebRowSetXmlWriter::init$() {
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

void WebRowSetXmlWriter::writeXML($WebRowSet* caller, $Writer* wrt) {
	$set(this, stack, $new($Stack));
	$set(this, writer, wrt);
	writeRowSet(caller);
}

void WebRowSetXmlWriter::writeXML($WebRowSet* caller, $OutputStream* oStream) {
	$set(this, stack, $new($Stack));
	$set(this, writer, $new($OutputStreamWriter, oStream));
	writeRowSet(caller);
}

void WebRowSetXmlWriter::writeRowSet($WebRowSet* caller) {
	$useLocalCurrentObjectStackCache();
	try {
		startHeader();
		writeProperties(caller);
		writeMetaData(caller);
		writeData(caller);
		endHeader();
	} catch ($IOException& ex) {
		$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("wrsxmlwriter.ioex"_s))))->toString());
		$throwNew($SQLException, $($MessageFormat::format(var$0, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
	}
}

void WebRowSetXmlWriter::startHeader() {
	setTag("webRowSet"_s);
	$nc(this->writer)->write("<?xml version=\"1.0\"?>\n"_s);
	$nc(this->writer)->write("<webRowSet xmlns=\"http://java.sun.com/xml/ns/jdbc\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"_s);
	$nc(this->writer)->write("xsi:schemaLocation=\"http://java.sun.com/xml/ns/jdbc http://java.sun.com/xml/ns/jdbc/webrowset.xsd\">\n"_s);
}

void WebRowSetXmlWriter::endHeader() {
	endTag("webRowSet"_s);
}

void WebRowSetXmlWriter::writeProperties($WebRowSet* caller) {
	$useLocalCurrentObjectStackCache();
	beginSection("properties"_s);
	try {
		propString("command"_s, $(processSpecialCharacters($($nc(caller)->getCommand()))));
		propInteger("concurrency"_s, $nc(caller)->getConcurrency());
		propString("datasource"_s, $($nc(caller)->getDataSourceName()));
		propBoolean("escape-processing"_s, $nc(caller)->getEscapeProcessing());
		try {
			propInteger("fetch-direction"_s, $nc(caller)->getFetchDirection());
		} catch ($SQLException& sqle) {
		}
		propInteger("fetch-size"_s, $nc(caller)->getFetchSize());
		propInteger("isolation-level"_s, $nc(caller)->getTransactionIsolation());
		beginSection("key-columns"_s);
		$var($ints, kc, $nc(caller)->getKeyColumns());
		for (int32_t i = 0; kc != nullptr && i < kc->length; ++i) {
			propInteger("column"_s, kc->get(i));
		}
		endSection("key-columns"_s);
		beginSection("map"_s);
		$var($Map, typeMap, caller->getTypeMap());
		if (typeMap != nullptr) {
			{
				$var($Iterator, i$, $nc($(typeMap->entrySet()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Map$Entry, mm, $cast($Map$Entry, i$->next()));
					{
						propString("type"_s, $cast($String, $($nc(mm)->getKey())));
						propString("class"_s, $($nc(($cast($Class, $($nc(mm)->getValue()))))->getName()));
					}
				}
			}
		}
		endSection("map"_s);
		propInteger("max-field-size"_s, caller->getMaxFieldSize());
		propInteger("max-rows"_s, caller->getMaxRows());
		propInteger("query-timeout"_s, caller->getQueryTimeout());
		propBoolean("read-only"_s, caller->isReadOnly());
		int32_t itype = caller->getType();
		$var($String, strType, ""_s);
		if (itype == 1003) {
			$assign(strType, "ResultSet.TYPE_FORWARD_ONLY"_s);
		} else if (itype == 1004) {
			$assign(strType, "ResultSet.TYPE_SCROLL_INSENSITIVE"_s);
		} else if (itype == 1005) {
			$assign(strType, "ResultSet.TYPE_SCROLL_SENSITIVE"_s);
		}
		propString("rowset-type"_s, strType);
		propBoolean("show-deleted"_s, caller->getShowDeleted());
		propString("table-name"_s, $(caller->getTableName()));
		propString("url"_s, $(caller->getUrl()));
		beginSection("sync-provider"_s);
		$var($String, strProviderInstance, $nc($of(($(caller->getSyncProvider()))))->toString());
		$var($String, strProvider, $nc(strProviderInstance)->substring(0, $nc($($nc($of(($(caller->getSyncProvider()))))->toString()))->indexOf((int32_t)u'@')));
		propString("sync-provider-name"_s, strProvider);
		propString("sync-provider-vendor"_s, "Oracle Corporation"_s);
		propString("sync-provider-version"_s, "1.0"_s);
		propInteger("sync-provider-grade"_s, $nc($(caller->getSyncProvider()))->getProviderGrade());
		propInteger("data-source-lock"_s, $nc($(caller->getSyncProvider()))->getDataSourceLock());
		endSection("sync-provider"_s);
	} catch ($SQLException& ex) {
		$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("wrsxmlwriter.sqlex"_s))))->toString());
		$throwNew($IOException, $($MessageFormat::format(var$0, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
	}
	endSection("properties"_s);
}

void WebRowSetXmlWriter::writeMetaData($WebRowSet* caller) {
	$useLocalCurrentObjectStackCache();
	int32_t columnCount = 0;
	beginSection("metadata"_s);
	try {
		$var($ResultSetMetaData, rsmd, $nc(caller)->getMetaData());
		columnCount = $nc(rsmd)->getColumnCount();
		propInteger("column-count"_s, columnCount);
		for (int32_t colIndex = 1; colIndex <= columnCount; ++colIndex) {
			beginSection("column-definition"_s);
			propInteger("column-index"_s, colIndex);
			propBoolean("auto-increment"_s, rsmd->isAutoIncrement(colIndex));
			propBoolean("case-sensitive"_s, rsmd->isCaseSensitive(colIndex));
			propBoolean("currency"_s, rsmd->isCurrency(colIndex));
			propInteger("nullable"_s, rsmd->isNullable(colIndex));
			propBoolean("signed"_s, rsmd->isSigned(colIndex));
			propBoolean("searchable"_s, rsmd->isSearchable(colIndex));
			propInteger("column-display-size"_s, rsmd->getColumnDisplaySize(colIndex));
			propString("column-label"_s, $(rsmd->getColumnLabel(colIndex)));
			propString("column-name"_s, $(rsmd->getColumnName(colIndex)));
			propString("schema-name"_s, $(rsmd->getSchemaName(colIndex)));
			propInteger("column-precision"_s, rsmd->getPrecision(colIndex));
			propInteger("column-scale"_s, rsmd->getScale(colIndex));
			propString("table-name"_s, $(rsmd->getTableName(colIndex)));
			propString("catalog-name"_s, $(rsmd->getCatalogName(colIndex)));
			propInteger("column-type"_s, rsmd->getColumnType(colIndex));
			propString("column-type-name"_s, $(rsmd->getColumnTypeName(colIndex)));
			endSection("column-definition"_s);
		}
	} catch ($SQLException& ex) {
		$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("wrsxmlwriter.sqlex"_s))))->toString());
		$throwNew($IOException, $($MessageFormat::format(var$0, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
	}
	endSection("metadata"_s);
}

void WebRowSetXmlWriter::writeData($WebRowSet* caller) {
	$useLocalCurrentObjectStackCache();
	$var($ResultSet, rs, nullptr);
	try {
		$var($ResultSetMetaData, rsmd, $nc(caller)->getMetaData());
		int32_t columnCount = $nc(rsmd)->getColumnCount();
		int32_t i = 0;
		beginSection("data"_s);
		caller->beforeFirst();
		caller->setShowDeleted(true);
		while (caller->next()) {
			bool var$0 = caller->rowDeleted();
			if (var$0 && caller->rowInserted()) {
				beginSection("modifyRow"_s);
			} else if (caller->rowDeleted()) {
				beginSection("deleteRow"_s);
			} else if (caller->rowInserted()) {
				beginSection("insertRow"_s);
			} else {
				beginSection("currentRow"_s);
			}
			for (i = 1; i <= columnCount; ++i) {
				if (caller->columnUpdated(i)) {
					$assign(rs, caller->getOriginalRow());
					$nc(rs)->next();
					beginTag("columnValue"_s);
					writeValue(i, $cast($RowSet, rs));
					endTag("columnValue"_s);
					beginTag("updateRow"_s);
					writeValue(i, caller);
					endTag("updateRow"_s);
				} else {
					beginTag("columnValue"_s);
					writeValue(i, caller);
					endTag("columnValue"_s);
				}
			}
			endSection();
		}
		endSection("data"_s);
	} catch ($SQLException& ex) {
		$var($String, var$1, $nc($of($($nc(this->resBundle)->handleGetObject("wrsxmlwriter.sqlex"_s))))->toString());
		$throwNew($IOException, $($MessageFormat::format(var$1, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
	}
}

void WebRowSetXmlWriter::writeValue(int32_t idx, $RowSet* caller) {
	$useLocalCurrentObjectStackCache();
	try {
		int32_t type = $nc($($nc(caller)->getMetaData()))->getColumnType(idx);
		{
			bool b = false;
			int16_t s = 0;
			int32_t i = 0;
			int64_t l = 0;
			float f = 0;
			double d = 0;
			$var($1Date, date, nullptr)
			$var($Time, time, nullptr)
			$var($Timestamp, ts, nullptr)
			switch (type) {
			case $Types::BIT:
				{}
			case $Types::BOOLEAN:
				{
					b = caller->getBoolean(idx);
					if (caller->wasNull()) {
						writeNull();
					} else {
						writeBoolean(b);
					}
					break;
				}
			case $Types::TINYINT:
				{}
			case $Types::SMALLINT:
				{
					s = caller->getShort(idx);
					if (caller->wasNull()) {
						writeNull();
					} else {
						writeShort(s);
					}
					break;
				}
			case $Types::INTEGER:
				{
					i = caller->getInt(idx);
					if (caller->wasNull()) {
						writeNull();
					} else {
						writeInteger(i);
					}
					break;
				}
			case $Types::BIGINT:
				{
					l = caller->getLong(idx);
					if (caller->wasNull()) {
						writeNull();
					} else {
						writeLong(l);
					}
					break;
				}
			case $Types::REAL:
				{}
			case $Types::FLOAT:
				{
					f = caller->getFloat(idx);
					if (caller->wasNull()) {
						writeNull();
					} else {
						writeFloat(f);
					}
					break;
				}
			case $Types::DOUBLE:
				{
					d = caller->getDouble(idx);
					if (caller->wasNull()) {
						writeNull();
					} else {
						writeDouble(d);
					}
					break;
				}
			case $Types::NUMERIC:
				{}
			case $Types::DECIMAL:
				{
					writeBigDecimal($(caller->getBigDecimal(idx)));
					break;
				}
			case $Types::BINARY:
				{}
			case $Types::VARBINARY:
				{}
			case $Types::LONGVARBINARY:
				{
					break;
				}
			case $Types::DATE:
				{
					$assign(date, caller->getDate(idx));
					if (caller->wasNull()) {
						writeNull();
					} else {
						writeLong($nc(date)->getTime());
					}
					break;
				}
			case $Types::TIME:
				{
					$assign(time, caller->getTime(idx));
					if (caller->wasNull()) {
						writeNull();
					} else {
						writeLong($nc(time)->getTime());
					}
					break;
				}
			case $Types::TIMESTAMP:
				{
					$assign(ts, caller->getTimestamp(idx));
					if (caller->wasNull()) {
						writeNull();
					} else {
						writeLong($nc(ts)->getTime());
					}
					break;
				}
			case $Types::CHAR:
				{}
			case $Types::VARCHAR:
				{}
			case $Types::LONGVARCHAR:
				{
					writeStringData($(caller->getString(idx)));
					break;
				}
			default:
				{
					$nc($System::out)->println($($nc($of($($nc(this->resBundle)->handleGetObject("wsrxmlwriter.notproper"_s))))->toString()));
				}
			}
		}
	} catch ($SQLException& ex) {
		$var($String, var$0, $($nc($of($($nc(this->resBundle)->handleGetObject("wrsxmlwriter.failedwrite"_s))))->toString()));
		$throwNew($IOException, $$concat(var$0, $(ex->getMessage())));
	}
}

void WebRowSetXmlWriter::beginSection($String* tag) {
	setTag(tag);
	writeIndent($nc(this->stack)->size());
	$nc(this->writer)->write($$str({"<"_s, tag, ">\n"_s}));
}

void WebRowSetXmlWriter::endSection($String* tag) {
	$useLocalCurrentObjectStackCache();
	writeIndent($nc(this->stack)->size());
	$var($String, beginTag, getTag());
	if ($nc(beginTag)->indexOf("webRowSet"_s) != -1) {
		$assign(beginTag, "webRowSet"_s);
	}
	if ($nc(tag)->equals(beginTag)) {
		$nc(this->writer)->write($$str({"</"_s, beginTag, ">\n"_s}));
	} else {
	}
	$nc(this->writer)->flush();
}

void WebRowSetXmlWriter::endSection() {
	$useLocalCurrentObjectStackCache();
	writeIndent($nc(this->stack)->size());
	$var($String, beginTag, getTag());
	$nc(this->writer)->write($$str({"</"_s, beginTag, ">\n"_s}));
	$nc(this->writer)->flush();
}

void WebRowSetXmlWriter::beginTag($String* tag) {
	setTag(tag);
	writeIndent($nc(this->stack)->size());
	$nc(this->writer)->write($$str({"<"_s, tag, ">"_s}));
}

void WebRowSetXmlWriter::endTag($String* tag) {
	$useLocalCurrentObjectStackCache();
	$var($String, beginTag, getTag());
	if ($nc(tag)->equals(beginTag)) {
		$nc(this->writer)->write($$str({"</"_s, beginTag, ">\n"_s}));
	} else {
	}
	$nc(this->writer)->flush();
}

void WebRowSetXmlWriter::emptyTag($String* tag) {
	$nc(this->writer)->write($$str({"<"_s, tag, "/>"_s}));
}

void WebRowSetXmlWriter::setTag($String* tag) {
	$nc(this->stack)->push(tag);
}

$String* WebRowSetXmlWriter::getTag() {
	return $cast($String, $nc(this->stack)->pop());
}

void WebRowSetXmlWriter::writeNull() {
	emptyTag("null"_s);
}

void WebRowSetXmlWriter::writeStringData($String* s$renamed) {
	$var($String, s, s$renamed);
	if (s == nullptr) {
		writeNull();
	} else if ($nc(s)->isEmpty()) {
		writeEmptyString();
	} else {
		$assign(s, processSpecialCharacters(s));
		$nc(this->writer)->write(s);
	}
}

void WebRowSetXmlWriter::writeString($String* s) {
	if (s != nullptr) {
		$nc(this->writer)->write(s);
	} else {
		writeNull();
	}
}

void WebRowSetXmlWriter::writeShort(int16_t s) {
	$nc(this->writer)->write($($Short::toString(s)));
}

void WebRowSetXmlWriter::writeLong(int64_t l) {
	$nc(this->writer)->write($($Long::toString(l)));
}

void WebRowSetXmlWriter::writeInteger(int32_t i) {
	$nc(this->writer)->write($($Integer::toString(i)));
}

void WebRowSetXmlWriter::writeBoolean(bool b) {
	$useLocalCurrentObjectStackCache();
	$nc(this->writer)->write($($nc($($Boolean::valueOf(b)))->toString()));
}

void WebRowSetXmlWriter::writeFloat(float f) {
	$nc(this->writer)->write($($Float::toString(f)));
}

void WebRowSetXmlWriter::writeDouble(double d) {
	$nc(this->writer)->write($($Double::toString(d)));
}

void WebRowSetXmlWriter::writeBigDecimal($BigDecimal* bd) {
	if (bd != nullptr) {
		$nc(this->writer)->write($(bd->toString()));
	} else {
		emptyTag("null"_s);
	}
}

void WebRowSetXmlWriter::writeIndent(int32_t tabs) {
	for (int32_t i = 1; i < tabs; ++i) {
		$nc(this->writer)->write("  "_s);
	}
}

void WebRowSetXmlWriter::propString($String* tag, $String* s) {
	beginTag(tag);
	writeString(s);
	endTag(tag);
}

void WebRowSetXmlWriter::propInteger($String* tag, int32_t i) {
	beginTag(tag);
	writeInteger(i);
	endTag(tag);
}

void WebRowSetXmlWriter::propBoolean($String* tag, bool b) {
	beginTag(tag);
	writeBoolean(b);
	endTag(tag);
}

void WebRowSetXmlWriter::writeEmptyString() {
	emptyTag("emptyString"_s);
}

bool WebRowSetXmlWriter::writeData($RowSetInternal* caller) {
	return false;
}

$String* WebRowSetXmlWriter::processSpecialCharacters($String* s$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, s, s$renamed);
	if (s == nullptr) {
		return nullptr;
	}
	$var($chars, charStr, $nc(s)->toCharArray());
	$var($String, specialStr, ""_s);
	for (int32_t i = 0; i < charStr->length; ++i) {
		if (charStr->get(i) == u'&') {
			$assign(specialStr, specialStr->concat("&amp;"_s));
		} else if (charStr->get(i) == u'<') {
			$assign(specialStr, specialStr->concat("&lt;"_s));
		} else if (charStr->get(i) == u'>') {
			$assign(specialStr, specialStr->concat("&gt;"_s));
		} else if (charStr->get(i) == u'\'') {
			$assign(specialStr, specialStr->concat("&apos;"_s));
		} else if (charStr->get(i) == u'\"') {
			$assign(specialStr, specialStr->concat("&quot;"_s));
		} else {
			$assign(specialStr, specialStr->concat($($String::valueOf(charStr->get(i)))));
		}
	}
	$assign(s, specialStr);
	return s;
}

void WebRowSetXmlWriter::readObject($ObjectInputStream* ois) {
	$nc(ois)->defaultReadObject();
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

WebRowSetXmlWriter::WebRowSetXmlWriter() {
}

$Class* WebRowSetXmlWriter::load$($String* name, bool initialize) {
	$loadClass(WebRowSetXmlWriter, name, initialize, &_WebRowSetXmlWriter_ClassInfo_, allocate$WebRowSetXmlWriter);
	return class$;
}

$Class* WebRowSetXmlWriter::class$ = nullptr;

			} // internal
		} // rowset
	} // sun
} // com
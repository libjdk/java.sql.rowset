#include <com/sun/rowset/internal/XmlReaderContentHandler.h>

#include <com/sun/rowset/JdbcRowSetResourceBundle.h>
#include <com/sun/rowset/WebRowSetImpl.h>
#include <com/sun/rowset/internal/Row.h>
#include <java/io/IOException.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/math/BigDecimal.h>
#include <java/sql/Date.h>
#include <java/sql/ResultSetMetaData.h>
#include <java/sql/SQLException.h>
#include <java/sql/Time.h>
#include <java/sql/Timestamp.h>
#include <java/sql/Types.h>
#include <java/text/MessageFormat.h>
#include <java/util/AbstractMap.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/Map.h>
#include <java/util/Vector.h>
#include <javax/sql/RowSet.h>
#include <javax/sql/RowSetMetaData.h>
#include <javax/sql/rowset/BaseRowSet.h>
#include <javax/sql/rowset/RowSetMetaDataImpl.h>
#include <org/xml/sax/Attributes.h>
#include <org/xml/sax/SAXException.h>
#include <org/xml/sax/SAXParseException.h>
#include <org/xml/sax/helpers/DefaultHandler.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <jcpp.h>

#undef BIGINT
#undef BINARY
#undef BIT
#undef BOOLEAN
#undef CHAR
#undef DATA
#undef DATE
#undef DECIMAL
#undef DOUBLE
#undef FLOAT
#undef INITIAL
#undef INTEGER
#undef LONGVARBINARY
#undef LONGVARCHAR
#undef METADATA
#undef NUMERIC
#undef PROPERTIES
#undef REAL
#undef SMALLINT
#undef TIME
#undef TIMESTAMP
#undef TINYINT
#undef VARBINARY
#undef VARCHAR

using $CachedRowSetImpl = ::com::sun::rowset::CachedRowSetImpl;
using $JdbcRowSetResourceBundle = ::com::sun::rowset::JdbcRowSetResourceBundle;
using $WebRowSetImpl = ::com::sun::rowset::WebRowSetImpl;
using $Row = ::com::sun::rowset::internal::Row;
using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Double = ::java::lang::Double;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $Short = ::java::lang::Short;
using $BigDecimal = ::java::math::BigDecimal;
using $Date = ::java::sql::Date;
using $ResultSetMetaData = ::java::sql::ResultSetMetaData;
using $SQLException = ::java::sql::SQLException;
using $Time = ::java::sql::Time;
using $Timestamp = ::java::sql::Timestamp;
using $Types = ::java::sql::Types;
using $MessageFormat = ::java::text::MessageFormat;
using $AbstractMap = ::java::util::AbstractMap;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $Map = ::java::util::Map;
using $Vector = ::java::util::Vector;
using $RowSet = ::javax::sql::RowSet;
using $RowSetMetaData = ::javax::sql::RowSetMetaData;
using $BaseRowSet = ::javax::sql::rowset::BaseRowSet;
using $RowSetMetaDataImpl = ::javax::sql::rowset::RowSetMetaDataImpl;
using $Attributes = ::org::xml::sax::Attributes;
using $SAXException = ::org::xml::sax::SAXException;
using $SAXParseException = ::org::xml::sax::SAXParseException;
using $DefaultHandler = ::org::xml::sax::helpers::DefaultHandler;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

$FieldInfo _XmlReaderContentHandler_FieldInfo_[] = {
	{"propMap", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/Integer;>;", $PRIVATE, $field(XmlReaderContentHandler, propMap)},
	{"colDefMap", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/Integer;>;", $PRIVATE, $field(XmlReaderContentHandler, colDefMap)},
	{"dataMap", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/Integer;>;", $PRIVATE, $field(XmlReaderContentHandler, dataMap)},
	{"typeMap", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/String;Ljava/lang/Class<*>;>;", $PRIVATE, $field(XmlReaderContentHandler, typeMap)},
	{"updates", "Ljava/util/Vector;", "Ljava/util/Vector<[Ljava/lang/Object;>;", $PRIVATE, $field(XmlReaderContentHandler, updates)},
	{"keyCols", "Ljava/util/Vector;", "Ljava/util/Vector<Ljava/lang/String;>;", $PRIVATE, $field(XmlReaderContentHandler, keyCols)},
	{"columnValue", "Ljava/lang/String;", nullptr, $PRIVATE, $field(XmlReaderContentHandler, columnValue)},
	{"propertyValue", "Ljava/lang/String;", nullptr, $PRIVATE, $field(XmlReaderContentHandler, propertyValue)},
	{"metaDataValue", "Ljava/lang/String;", nullptr, $PRIVATE, $field(XmlReaderContentHandler, metaDataValue)},
	{"tag", "I", nullptr, $PRIVATE, $field(XmlReaderContentHandler, tag)},
	{"state", "I", nullptr, $PRIVATE, $field(XmlReaderContentHandler, state)},
	{"rs", "Lcom/sun/rowset/WebRowSetImpl;", nullptr, $PRIVATE, $field(XmlReaderContentHandler, rs)},
	{"nullVal", "Z", nullptr, $PRIVATE, $field(XmlReaderContentHandler, nullVal)},
	{"emptyStringVal", "Z", nullptr, $PRIVATE, $field(XmlReaderContentHandler, emptyStringVal)},
	{"md", "Ljavax/sql/RowSetMetaData;", nullptr, $PRIVATE, $field(XmlReaderContentHandler, md)},
	{"idx", "I", nullptr, $PRIVATE, $field(XmlReaderContentHandler, idx)},
	{"lastval", "Ljava/lang/String;", nullptr, $PRIVATE, $field(XmlReaderContentHandler, lastval)},
	{"Key_map", "Ljava/lang/String;", nullptr, $PRIVATE, $field(XmlReaderContentHandler, Key_map)},
	{"Value_map", "Ljava/lang/String;", nullptr, $PRIVATE, $field(XmlReaderContentHandler, Value_map)},
	{"tempStr", "Ljava/lang/String;", nullptr, $PRIVATE, $field(XmlReaderContentHandler, tempStr)},
	{"tempUpdate", "Ljava/lang/String;", nullptr, $PRIVATE, $field(XmlReaderContentHandler, tempUpdate)},
	{"tempCommand", "Ljava/lang/String;", nullptr, $PRIVATE, $field(XmlReaderContentHandler, tempCommand)},
	{"upd", "[Ljava/lang/Object;", nullptr, $PRIVATE, $field(XmlReaderContentHandler, upd)},
	{"properties", "[Ljava/lang/String;", nullptr, $PRIVATE, $field(XmlReaderContentHandler, properties)},
	{"CommandTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, CommandTag)},
	{"ConcurrencyTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, ConcurrencyTag)},
	{"DatasourceTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, DatasourceTag)},
	{"EscapeProcessingTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, EscapeProcessingTag)},
	{"FetchDirectionTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, FetchDirectionTag)},
	{"FetchSizeTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, FetchSizeTag)},
	{"IsolationLevelTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, IsolationLevelTag)},
	{"KeycolsTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, KeycolsTag)},
	{"MapTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, MapTag)},
	{"MaxFieldSizeTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, MaxFieldSizeTag)},
	{"MaxRowsTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, MaxRowsTag)},
	{"QueryTimeoutTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, QueryTimeoutTag)},
	{"ReadOnlyTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, ReadOnlyTag)},
	{"RowsetTypeTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, RowsetTypeTag)},
	{"ShowDeletedTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, ShowDeletedTag)},
	{"TableNameTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, TableNameTag)},
	{"UrlTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, UrlTag)},
	{"PropNullTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, PropNullTag)},
	{"PropColumnTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, PropColumnTag)},
	{"PropTypeTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, PropTypeTag)},
	{"PropClassTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, PropClassTag)},
	{"SyncProviderTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, SyncProviderTag)},
	{"SyncProviderNameTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, SyncProviderNameTag)},
	{"SyncProviderVendorTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, SyncProviderVendorTag)},
	{"SyncProviderVersionTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, SyncProviderVersionTag)},
	{"SyncProviderGradeTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, SyncProviderGradeTag)},
	{"DataSourceLock", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, DataSourceLock)},
	{"colDef", "[Ljava/lang/String;", nullptr, $PRIVATE, $field(XmlReaderContentHandler, colDef)},
	{"ColumnCountTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, ColumnCountTag)},
	{"ColumnDefinitionTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, ColumnDefinitionTag)},
	{"ColumnIndexTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, ColumnIndexTag)},
	{"AutoIncrementTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, AutoIncrementTag)},
	{"CaseSensitiveTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, CaseSensitiveTag)},
	{"CurrencyTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, CurrencyTag)},
	{"NullableTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, NullableTag)},
	{"SignedTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, SignedTag)},
	{"SearchableTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, SearchableTag)},
	{"ColumnDisplaySizeTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, ColumnDisplaySizeTag)},
	{"ColumnLabelTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, ColumnLabelTag)},
	{"ColumnNameTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, ColumnNameTag)},
	{"SchemaNameTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, SchemaNameTag)},
	{"ColumnPrecisionTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, ColumnPrecisionTag)},
	{"ColumnScaleTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, ColumnScaleTag)},
	{"MetaTableNameTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, MetaTableNameTag)},
	{"CatalogNameTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, CatalogNameTag)},
	{"ColumnTypeTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, ColumnTypeTag)},
	{"ColumnTypeNameTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, ColumnTypeNameTag)},
	{"MetaNullTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, MetaNullTag)},
	{"data", "[Ljava/lang/String;", nullptr, $PRIVATE, $field(XmlReaderContentHandler, data)},
	{"RowTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, RowTag)},
	{"ColTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, ColTag)},
	{"InsTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, InsTag)},
	{"DelTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, DelTag)},
	{"InsDelTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, InsDelTag)},
	{"UpdTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, UpdTag)},
	{"NullTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, NullTag)},
	{"EmptyStringTag", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, EmptyStringTag)},
	{"INITIAL", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, INITIAL)},
	{"PROPERTIES", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, PROPERTIES)},
	{"METADATA", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, METADATA)},
	{"DATA", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(XmlReaderContentHandler, DATA)},
	{"resBundle", "Lcom/sun/rowset/JdbcRowSetResourceBundle;", nullptr, $PRIVATE, $field(XmlReaderContentHandler, resBundle)},
	{}
};

$MethodInfo _XmlReaderContentHandler_MethodInfo_[] = {
	{"<init>", "(Ljavax/sql/RowSet;)V", nullptr, $PUBLIC, $method(static_cast<void(XmlReaderContentHandler::*)($RowSet*)>(&XmlReaderContentHandler::init$))},
	{"applyUpdates", "()V", nullptr, $PRIVATE, $method(static_cast<void(XmlReaderContentHandler::*)()>(&XmlReaderContentHandler::applyUpdates)), "org.xml.sax.SAXException"},
	{"characters", "([CII)V", nullptr, $PUBLIC, nullptr, "org.xml.sax.SAXException"},
	{"endDocument", "()V", nullptr, $PUBLIC, nullptr, "org.xml.sax.SAXException"},
	{"endElement", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, nullptr, "org.xml.sax.SAXException"},
	{"error", "(Lorg/xml/sax/SAXParseException;)V", nullptr, $PUBLIC, nullptr, "org.xml.sax.SAXParseException"},
	{"getBigDecimalValue", "(Ljava/lang/String;)Ljava/math/BigDecimal;", nullptr, $PRIVATE, $method(static_cast<$BigDecimal*(XmlReaderContentHandler::*)($String*)>(&XmlReaderContentHandler::getBigDecimalValue))},
	{"getBinaryValue", "(Ljava/lang/String;)[B", nullptr, $PRIVATE, $method(static_cast<$bytes*(XmlReaderContentHandler::*)($String*)>(&XmlReaderContentHandler::getBinaryValue))},
	{"getBooleanValue", "(Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(static_cast<bool(XmlReaderContentHandler::*)($String*)>(&XmlReaderContentHandler::getBooleanValue))},
	{"getByteValue", "(Ljava/lang/String;)B", nullptr, $PRIVATE, $method(static_cast<int8_t(XmlReaderContentHandler::*)($String*)>(&XmlReaderContentHandler::getByteValue))},
	{"getDateValue", "(Ljava/lang/String;)Ljava/sql/Date;", nullptr, $PRIVATE, $method(static_cast<$Date*(XmlReaderContentHandler::*)($String*)>(&XmlReaderContentHandler::getDateValue))},
	{"getDoubleValue", "(Ljava/lang/String;)D", nullptr, $PRIVATE, $method(static_cast<double(XmlReaderContentHandler::*)($String*)>(&XmlReaderContentHandler::getDoubleValue))},
	{"getEmptyStringValue", "()Z", nullptr, $PRIVATE, $method(static_cast<bool(XmlReaderContentHandler::*)()>(&XmlReaderContentHandler::getEmptyStringValue))},
	{"getFloatValue", "(Ljava/lang/String;)F", nullptr, $PRIVATE, $method(static_cast<float(XmlReaderContentHandler::*)($String*)>(&XmlReaderContentHandler::getFloatValue))},
	{"getIntegerValue", "(Ljava/lang/String;)I", nullptr, $PRIVATE, $method(static_cast<int32_t(XmlReaderContentHandler::*)($String*)>(&XmlReaderContentHandler::getIntegerValue))},
	{"getLongValue", "(Ljava/lang/String;)J", nullptr, $PRIVATE, $method(static_cast<int64_t(XmlReaderContentHandler::*)($String*)>(&XmlReaderContentHandler::getLongValue))},
	{"getNullValue", "()Z", nullptr, $PRIVATE, $method(static_cast<bool(XmlReaderContentHandler::*)()>(&XmlReaderContentHandler::getNullValue))},
	{"getPresentRow", "(Lcom/sun/rowset/WebRowSetImpl;)Lcom/sun/rowset/internal/Row;", nullptr, $PRIVATE, $method(static_cast<$Row*(XmlReaderContentHandler::*)($WebRowSetImpl*)>(&XmlReaderContentHandler::getPresentRow)), "java.sql.SQLException"},
	{"getShortValue", "(Ljava/lang/String;)S", nullptr, $PRIVATE, $method(static_cast<int16_t(XmlReaderContentHandler::*)($String*)>(&XmlReaderContentHandler::getShortValue))},
	{"getState", "()I", nullptr, $PRIVATE, $method(static_cast<int32_t(XmlReaderContentHandler::*)()>(&XmlReaderContentHandler::getState))},
	{"getStringValue", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(XmlReaderContentHandler::*)($String*)>(&XmlReaderContentHandler::getStringValue))},
	{"getTag", "()I", nullptr, $PRIVATE, $method(static_cast<int32_t(XmlReaderContentHandler::*)()>(&XmlReaderContentHandler::getTag))},
	{"getTimeValue", "(Ljava/lang/String;)Ljava/sql/Time;", nullptr, $PRIVATE, $method(static_cast<$Time*(XmlReaderContentHandler::*)($String*)>(&XmlReaderContentHandler::getTimeValue))},
	{"getTimestampValue", "(Ljava/lang/String;)Ljava/sql/Timestamp;", nullptr, $PRIVATE, $method(static_cast<$Timestamp*(XmlReaderContentHandler::*)($String*)>(&XmlReaderContentHandler::getTimestampValue))},
	{"initMaps", "()V", nullptr, $PRIVATE, $method(static_cast<void(XmlReaderContentHandler::*)()>(&XmlReaderContentHandler::initMaps))},
	{"insertValue", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(XmlReaderContentHandler::*)($String*)>(&XmlReaderContentHandler::insertValue)), "java.sql.SQLException"},
	{"notationDecl", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"setDataValue", "([CII)V", nullptr, $PRIVATE, $method(static_cast<void(XmlReaderContentHandler::*)($chars*,int32_t,int32_t)>(&XmlReaderContentHandler::setDataValue)), "java.sql.SQLException"},
	{"setEmptyStringValue", "(Z)V", nullptr, $PRIVATE, $method(static_cast<void(XmlReaderContentHandler::*)(bool)>(&XmlReaderContentHandler::setEmptyStringValue))},
	{"setMetaDataValue", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(XmlReaderContentHandler::*)($String*)>(&XmlReaderContentHandler::setMetaDataValue)), "java.sql.SQLException"},
	{"setNullValue", "(Z)V", nullptr, $PRIVATE, $method(static_cast<void(XmlReaderContentHandler::*)(bool)>(&XmlReaderContentHandler::setNullValue))},
	{"setPropertyValue", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(XmlReaderContentHandler::*)($String*)>(&XmlReaderContentHandler::setPropertyValue)), "java.sql.SQLException"},
	{"setState", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(XmlReaderContentHandler::*)($String*)>(&XmlReaderContentHandler::setState)), "org.xml.sax.SAXException"},
	{"setTag", "(I)V", nullptr, $PRIVATE, $method(static_cast<void(XmlReaderContentHandler::*)(int32_t)>(&XmlReaderContentHandler::setTag))},
	{"startDocument", "()V", nullptr, $PUBLIC, nullptr, "org.xml.sax.SAXException"},
	{"startElement", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Lorg/xml/sax/Attributes;)V", nullptr, $PUBLIC, nullptr, "org.xml.sax.SAXException"},
	{"unparsedEntityDecl", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"warning", "(Lorg/xml/sax/SAXParseException;)V", nullptr, $PUBLIC, nullptr, "org.xml.sax.SAXParseException"},
	{}
};

$ClassInfo _XmlReaderContentHandler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.rowset.internal.XmlReaderContentHandler",
	"org.xml.sax.helpers.DefaultHandler",
	nullptr,
	_XmlReaderContentHandler_FieldInfo_,
	_XmlReaderContentHandler_MethodInfo_
};

$Object* allocate$XmlReaderContentHandler($Class* clazz) {
	return $of($alloc(XmlReaderContentHandler));
}

void XmlReaderContentHandler::init$($RowSet* r) {
	$DefaultHandler::init$();
	$set(this, properties, $new($StringArray, {
		"command"_s,
		"concurrency"_s,
		"datasource"_s,
		"escape-processing"_s,
		"fetch-direction"_s,
		"fetch-size"_s,
		"isolation-level"_s,
		"key-columns"_s,
		"map"_s,
		"max-field-size"_s,
		"max-rows"_s,
		"query-timeout"_s,
		"read-only"_s,
		"rowset-type"_s,
		"show-deleted"_s,
		"table-name"_s,
		"url"_s,
		"null"_s,
		"column"_s,
		"type"_s,
		"class"_s,
		"sync-provider"_s,
		"sync-provider-name"_s,
		"sync-provider-vendor"_s,
		"sync-provider-version"_s,
		"sync-provider-grade"_s,
		"data-source-lock"_s
	}));
	$set(this, colDef, $new($StringArray, {
		"column-count"_s,
		"column-definition"_s,
		"column-index"_s,
		"auto-increment"_s,
		"case-sensitive"_s,
		"currency"_s,
		"nullable"_s,
		"signed"_s,
		"searchable"_s,
		"column-display-size"_s,
		"column-label"_s,
		"column-name"_s,
		"schema-name"_s,
		"column-precision"_s,
		"column-scale"_s,
		"table-name"_s,
		"catalog-name"_s,
		"column-type"_s,
		"column-type-name"_s,
		"null"_s
	}));
	$set(this, data, $new($StringArray, {
		"currentRow"_s,
		"columnValue"_s,
		"insertRow"_s,
		"deleteRow"_s,
		"insdel"_s,
		"updateRow"_s,
		"null"_s,
		"emptyString"_s
	}));
	$set(this, rs, $cast($WebRowSetImpl, r));
	initMaps();
	$set(this, updates, $new($Vector));
	$set(this, columnValue, ""_s);
	$set(this, propertyValue, ""_s);
	$set(this, metaDataValue, ""_s);
	this->nullVal = false;
	this->idx = 0;
	$set(this, tempStr, ""_s);
	$set(this, tempUpdate, ""_s);
	$set(this, tempCommand, ""_s);
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

void XmlReaderContentHandler::initMaps() {
	$useLocalCurrentObjectStackCache();
	int32_t items = 0;
	int32_t i = 0;
	$set(this, propMap, $new($HashMap));
	items = $nc(this->properties)->length;
	for (i = 0; i < items; ++i) {
		$nc(this->propMap)->put($nc(this->properties)->get(i), $($Integer::valueOf(i)));
	}
	$set(this, colDefMap, $new($HashMap));
	items = $nc(this->colDef)->length;
	for (i = 0; i < items; ++i) {
		$nc(this->colDefMap)->put($nc(this->colDef)->get(i), $($Integer::valueOf(i)));
	}
	$set(this, dataMap, $new($HashMap));
	items = $nc(this->data)->length;
	for (i = 0; i < items; ++i) {
		$nc(this->dataMap)->put($nc(this->data)->get(i), $($Integer::valueOf(i)));
	}
	$set(this, typeMap, $new($HashMap));
}

void XmlReaderContentHandler::startDocument() {
}

void XmlReaderContentHandler::endDocument() {
}

void XmlReaderContentHandler::startElement($String* uri, $String* lName, $String* qName, $Attributes* attributes) {
	$useLocalCurrentObjectStackCache();
	int32_t tag = 0;
	$var($String, name, ""_s);
	$assign(name, lName);
	switch (getState()) {
	case XmlReaderContentHandler::PROPERTIES:
		{
			$set(this, tempCommand, ""_s);
			tag = $nc(($cast($Integer, $($nc(this->propMap)->get(name)))))->intValue();
			if (tag == XmlReaderContentHandler::PropNullTag) {
				setNullValue(true);
			} else {
				setTag(tag);
			}
			break;
		}
	case XmlReaderContentHandler::METADATA:
		{
			tag = $nc(($cast($Integer, $($nc(this->colDefMap)->get(name)))))->intValue();
			if (tag == XmlReaderContentHandler::MetaNullTag) {
				setNullValue(true);
			} else {
				setTag(tag);
			}
			break;
		}
	case XmlReaderContentHandler::DATA:
		{
			$set(this, tempStr, ""_s);
			$set(this, tempUpdate, ""_s);
			if ($nc(this->dataMap)->get(name) == nullptr) {
				tag = XmlReaderContentHandler::NullTag;
			} else if ($nc(($cast($Integer, $($nc(this->dataMap)->get(name)))))->intValue() == XmlReaderContentHandler::EmptyStringTag) {
				tag = XmlReaderContentHandler::EmptyStringTag;
			} else {
				tag = $nc(($cast($Integer, $($nc(this->dataMap)->get(name)))))->intValue();
			}
			if (tag == XmlReaderContentHandler::NullTag) {
				setNullValue(true);
			} else if (tag == XmlReaderContentHandler::EmptyStringTag) {
				setEmptyStringValue(true);
			} else {
				setTag(tag);
				if (tag == XmlReaderContentHandler::RowTag || tag == XmlReaderContentHandler::DelTag || tag == XmlReaderContentHandler::InsTag) {
					this->idx = 0;
					try {
						$nc(this->rs)->moveToInsertRow();
					} catch ($SQLException& ex) {
					}
				}
			}
			break;
		}
	default:
		{
			setState(name);
		}
	}
}

void XmlReaderContentHandler::endElement($String* uri, $String* lName, $String* qName) {
	$useLocalCurrentObjectStackCache();
	int32_t tag = 0;
	$var($String, name, ""_s);
	$assign(name, lName);
	switch (getState()) {
	case XmlReaderContentHandler::PROPERTIES:
		{
			if ($nc(name)->equals("properties"_s)) {
				this->state = XmlReaderContentHandler::INITIAL;
				break;
			}
			try {
				tag = $nc(($cast($Integer, $($nc(this->propMap)->get(name)))))->intValue();
				switch (tag) {
				case XmlReaderContentHandler::KeycolsTag:
					{
						if (this->keyCols != nullptr) {
							$var($ints, i, $new($ints, $nc(this->keyCols)->size()));
							for (int32_t j = 0; j < i->length; ++j) {
								i->set(j, $Integer::parseInt($cast($String, $($nc(this->keyCols)->elementAt(j)))));
							}
							$nc(this->rs)->setKeyColumns(i);
						}
						break;
					}
				case XmlReaderContentHandler::PropClassTag:
					{
						try {
							$nc(this->typeMap)->put(this->Key_map, $ReflectUtil::forName(this->Value_map));
						} catch ($ClassNotFoundException& ex) {
							$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.errmap"_s))))->toString());
							$throwNew($SAXException, $($MessageFormat::format(var$0, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
						}
						break;
					}
				case XmlReaderContentHandler::MapTag:
					{
						$nc(this->rs)->setTypeMap(this->typeMap);
						break;
					}
				default:
					{
						break;
					}
				}
				if (getNullValue()) {
					setPropertyValue(nullptr);
					setNullValue(false);
				} else {
					setPropertyValue(this->propertyValue);
				}
			} catch ($SQLException& ex) {
				$throwNew($SAXException, $(ex->getMessage()));
			}
			$set(this, propertyValue, ""_s);
			setTag(-1);
			break;
		}
	case XmlReaderContentHandler::METADATA:
		{
			if ($nc(name)->equals("metadata"_s)) {
				try {
					$nc(this->rs)->setMetaData(this->md);
					this->state = XmlReaderContentHandler::INITIAL;
				} catch ($SQLException& ex) {
					$var($String, var$1, $nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.errmetadata"_s))))->toString());
					$throwNew($SAXException, $($MessageFormat::format(var$1, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
				}
			} else {
				try {
					if (getNullValue()) {
						setMetaDataValue(nullptr);
						setNullValue(false);
					} else {
						setMetaDataValue(this->metaDataValue);
					}
				} catch ($SQLException& ex) {
					$var($String, var$2, $nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.errmetadata"_s))))->toString());
					$throwNew($SAXException, $($MessageFormat::format(var$2, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
				}
				$set(this, metaDataValue, ""_s);
			}
			setTag(-1);
			break;
		}
	case XmlReaderContentHandler::DATA:
		{
			if ($nc(name)->equals("data"_s)) {
				this->state = XmlReaderContentHandler::INITIAL;
				return;
			}
			if ($nc(this->dataMap)->get(name) == nullptr) {
				tag = XmlReaderContentHandler::NullTag;
			} else {
				tag = $nc(($cast($Integer, $($nc(this->dataMap)->get(name)))))->intValue();
			}
			switch (tag) {
			case XmlReaderContentHandler::ColTag:
				{
					try {
						++this->idx;
						if (getNullValue()) {
							insertValue(nullptr);
							setNullValue(false);
						} else {
							insertValue(this->tempStr);
						}
						$set(this, columnValue, ""_s);
					} catch ($SQLException& ex) {
						$var($String, var$3, $nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.errinsertval"_s))))->toString());
						$throwNew($SAXException, $($MessageFormat::format(var$3, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
					}
					break;
				}
			case XmlReaderContentHandler::RowTag:
				{
					try {
						$nc(this->rs)->insertRow();
						$nc(this->rs)->moveToCurrentRow();
						$nc(this->rs)->next();
						$nc(this->rs)->setOriginalRow();
						applyUpdates();
					} catch ($SQLException& ex) {
						$var($String, var$4, $nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.errconstr"_s))))->toString());
						$throwNew($SAXException, $($MessageFormat::format(var$4, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
					}
					break;
				}
			case XmlReaderContentHandler::DelTag:
				{
					try {
						$nc(this->rs)->insertRow();
						$nc(this->rs)->moveToCurrentRow();
						$nc(this->rs)->next();
						$nc(this->rs)->setOriginalRow();
						applyUpdates();
						$nc(this->rs)->deleteRow();
					} catch ($SQLException& ex) {
						$var($String, var$5, $nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.errdel"_s))))->toString());
						$throwNew($SAXException, $($MessageFormat::format(var$5, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
					}
					break;
				}
			case XmlReaderContentHandler::InsTag:
				{
					try {
						$nc(this->rs)->insertRow();
						$nc(this->rs)->moveToCurrentRow();
						$nc(this->rs)->next();
						applyUpdates();
					} catch ($SQLException& ex) {
						$var($String, var$6, $nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.errinsert"_s))))->toString());
						$throwNew($SAXException, $($MessageFormat::format(var$6, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
					}
					break;
				}
			case XmlReaderContentHandler::InsDelTag:
				{
					try {
						$nc(this->rs)->insertRow();
						$nc(this->rs)->moveToCurrentRow();
						$nc(this->rs)->next();
						$nc(this->rs)->setOriginalRow();
						applyUpdates();
					} catch ($SQLException& ex) {
						$var($String, var$7, $nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.errinsdel"_s))))->toString());
						$throwNew($SAXException, $($MessageFormat::format(var$7, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
					}
					break;
				}
			case XmlReaderContentHandler::UpdTag:
				{
					try {
						if (getNullValue()) {
							insertValue(nullptr);
							setNullValue(false);
						} else if (getEmptyStringValue()) {
							insertValue(""_s);
							setEmptyStringValue(false);
						} else {
							$nc(this->updates)->add(this->upd);
						}
					} catch ($SQLException& ex) {
						$var($String, var$8, $nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.errupdate"_s))))->toString());
						$throwNew($SAXException, $($MessageFormat::format(var$8, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
					}
					break;
				}
			default:
				{
					break;
				}
			}
		}
	default:
		{
			break;
		}
	}
}

void XmlReaderContentHandler::applyUpdates() {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->updates)->size() > 0) {
		try {
			$var($ObjectArray, upd, nullptr);
			$var($Iterator, i, $nc(this->updates)->iterator());
			while ($nc(i)->hasNext()) {
				$assign(upd, $cast($ObjectArray, i->next()));
				this->idx = $nc(($cast($Integer, $nc(upd)->get(0))))->intValue();
				if (!($nc(this->lastval)->equals(upd->get(1)))) {
					insertValue(($cast($String, upd->get(1))));
				}
			}
			$nc(this->rs)->updateRow();
		} catch ($SQLException& ex) {
			$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.errupdrow"_s))))->toString());
			$throwNew($SAXException, $($MessageFormat::format(var$0, $$new($ObjectArray, {$($of(ex->getMessage()))}))));
		}
		$nc(this->updates)->removeAllElements();
	}
}

void XmlReaderContentHandler::characters($chars* ch, int32_t start, int32_t length) {
	$useLocalCurrentObjectStackCache();
	try {
		switch (getState()) {
		case XmlReaderContentHandler::PROPERTIES:
			{
				$set(this, propertyValue, $new($String, ch, start, length));
				$set(this, tempCommand, $nc(this->tempCommand)->concat(this->propertyValue));
				$set(this, propertyValue, this->tempCommand);
				if (this->tag == XmlReaderContentHandler::PropTypeTag) {
					$set(this, Key_map, this->propertyValue);
				} else if (this->tag == XmlReaderContentHandler::PropClassTag) {
					$set(this, Value_map, this->propertyValue);
				}
				break;
			}
		case XmlReaderContentHandler::METADATA:
			{
				if (this->tag == -1) {
					break;
				}
				$set(this, metaDataValue, $new($String, ch, start, length));
				break;
			}
		case XmlReaderContentHandler::DATA:
			{
				setDataValue(ch, start, length);
				break;
			}
		default:
			{
			}
		}
	} catch ($SQLException& ex) {
		$var($String, var$0, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.chars"_s))))->toString()));
		$throwNew($SAXException, $$concat(var$0, $(ex->getMessage())));
	}
}

void XmlReaderContentHandler::setState($String* s) {
	if ($nc(s)->equals("webRowSet"_s)) {
		this->state = XmlReaderContentHandler::INITIAL;
	} else if (s->equals("properties"_s)) {
		if (this->state != XmlReaderContentHandler::PROPERTIES) {
			this->state = XmlReaderContentHandler::PROPERTIES;
		} else {
			this->state = XmlReaderContentHandler::INITIAL;
		}
	} else if (s->equals("metadata"_s)) {
		if (this->state != XmlReaderContentHandler::METADATA) {
			this->state = XmlReaderContentHandler::METADATA;
		} else {
			this->state = XmlReaderContentHandler::INITIAL;
		}
	} else if (s->equals("data"_s)) {
		if (this->state != XmlReaderContentHandler::DATA) {
			this->state = XmlReaderContentHandler::DATA;
		} else {
			this->state = XmlReaderContentHandler::INITIAL;
		}
	}
}

int32_t XmlReaderContentHandler::getState() {
	return this->state;
}

void XmlReaderContentHandler::setTag(int32_t t) {
	this->tag = t;
}

int32_t XmlReaderContentHandler::getTag() {
	return this->tag;
}

void XmlReaderContentHandler::setNullValue(bool n) {
	this->nullVal = n;
}

bool XmlReaderContentHandler::getNullValue() {
	return this->nullVal;
}

void XmlReaderContentHandler::setEmptyStringValue(bool e) {
	this->emptyStringVal = e;
}

bool XmlReaderContentHandler::getEmptyStringValue() {
	return this->emptyStringVal;
}

$String* XmlReaderContentHandler::getStringValue($String* s) {
	return s;
}

int32_t XmlReaderContentHandler::getIntegerValue($String* s) {
	return $Integer::parseInt(s);
}

bool XmlReaderContentHandler::getBooleanValue($String* s) {
	return $nc($($Boolean::valueOf(s)))->booleanValue();
}

$BigDecimal* XmlReaderContentHandler::getBigDecimalValue($String* s) {
	return $new($BigDecimal, s);
}

int8_t XmlReaderContentHandler::getByteValue($String* s) {
	return $Byte::parseByte(s);
}

int16_t XmlReaderContentHandler::getShortValue($String* s) {
	return $Short::parseShort(s);
}

int64_t XmlReaderContentHandler::getLongValue($String* s) {
	return $Long::parseLong(s);
}

float XmlReaderContentHandler::getFloatValue($String* s) {
	return $Float::parseFloat(s);
}

double XmlReaderContentHandler::getDoubleValue($String* s) {
	return $Double::parseDouble(s);
}

$bytes* XmlReaderContentHandler::getBinaryValue($String* s) {
	return $nc(s)->getBytes();
}

$Date* XmlReaderContentHandler::getDateValue($String* s) {
	return $new($Date, getLongValue(s));
}

$Time* XmlReaderContentHandler::getTimeValue($String* s) {
	return $new($Time, getLongValue(s));
}

$Timestamp* XmlReaderContentHandler::getTimestampValue($String* s) {
	return $new($Timestamp, getLongValue(s));
}

void XmlReaderContentHandler::setPropertyValue($String* s) {
	$useLocalCurrentObjectStackCache();
	bool nullValue = getNullValue();
	switch (getTag()) {
	case XmlReaderContentHandler::CommandTag:
		{
			if (nullValue) {
			} else {
				$nc(this->rs)->setCommand(s);
			}
			break;
		}
	case XmlReaderContentHandler::ConcurrencyTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue"_s))))->toString()));
			} else {
				$nc(this->rs)->setConcurrency(getIntegerValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::DatasourceTag:
		{
			if (nullValue) {
				$nc(this->rs)->setDataSourceName(nullptr);
			} else {
				$nc(this->rs)->setDataSourceName(s);
			}
			break;
		}
	case XmlReaderContentHandler::EscapeProcessingTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue"_s))))->toString()));
			} else {
				$nc(this->rs)->setEscapeProcessing(getBooleanValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::FetchDirectionTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue"_s))))->toString()));
			} else {
				$nc(this->rs)->setFetchDirection(getIntegerValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::FetchSizeTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue"_s))))->toString()));
			} else {
				$nc(this->rs)->setFetchSize(getIntegerValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::IsolationLevelTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue"_s))))->toString()));
			} else {
				$nc(this->rs)->setTransactionIsolation(getIntegerValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::KeycolsTag:
		{
			break;
		}
	case XmlReaderContentHandler::PropColumnTag:
		{
			if (this->keyCols == nullptr) {
				$set(this, keyCols, $new($Vector));
			}
			$nc(this->keyCols)->add(s);
			break;
		}
	case XmlReaderContentHandler::MapTag:
		{
			break;
		}
	case XmlReaderContentHandler::MaxFieldSizeTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue"_s))))->toString()));
			} else {
				$nc(this->rs)->setMaxFieldSize(getIntegerValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::MaxRowsTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue"_s))))->toString()));
			} else {
				$nc(this->rs)->setMaxRows(getIntegerValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::QueryTimeoutTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue"_s))))->toString()));
			} else {
				$nc(this->rs)->setQueryTimeout(getIntegerValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::ReadOnlyTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue"_s))))->toString()));
			} else {
				$nc(this->rs)->setReadOnly(getBooleanValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::RowsetTypeTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue"_s))))->toString()));
			} else {
				$var($String, strType, getStringValue(s));
				int32_t iType = 0;
				if ($($nc(strType)->trim())->equals("ResultSet.TYPE_SCROLL_INSENSITIVE"_s)) {
					iType = 1004;
				} else if ($(strType->trim())->equals("ResultSet.TYPE_SCROLL_SENSITIVE"_s)) {
					iType = 1005;
				} else if ($(strType->trim())->equals("ResultSet.TYPE_FORWARD_ONLY"_s)) {
					iType = 1003;
				}
				$nc(this->rs)->setType(iType);
			}
			break;
		}
	case XmlReaderContentHandler::ShowDeletedTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue"_s))))->toString()));
			} else {
				$nc(this->rs)->setShowDeleted(getBooleanValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::TableNameTag:
		{
			if (nullValue) {
			} else {
				$nc(this->rs)->setTableName(s);
			}
			break;
		}
	case XmlReaderContentHandler::UrlTag:
		{
			if (nullValue) {
				$nc(this->rs)->setUrl(nullptr);
			} else {
				$nc(this->rs)->setUrl(s);
			}
			break;
		}
	case XmlReaderContentHandler::SyncProviderNameTag:
		{
			if (nullValue) {
				$nc(this->rs)->setSyncProvider(nullptr);
			} else {
				$var($String, str, $nc(s)->substring(0, s->indexOf((int32_t)u'@') + 1));
				$nc(this->rs)->setSyncProvider(str);
			}
			break;
		}
	case XmlReaderContentHandler::SyncProviderVendorTag:
		{
			break;
		}
	case XmlReaderContentHandler::SyncProviderVersionTag:
		{
			break;
		}
	case XmlReaderContentHandler::SyncProviderGradeTag:
		{
			break;
		}
	case XmlReaderContentHandler::DataSourceLock:
		{
			break;
		}
	default:
		{
			break;
		}
	}
}

void XmlReaderContentHandler::setMetaDataValue($String* s) {
	$useLocalCurrentObjectStackCache();
	bool nullValue = getNullValue();
	switch (getTag()) {
	case XmlReaderContentHandler::ColumnCountTag:
		{
			$set(this, md, $new($RowSetMetaDataImpl));
			this->idx = 0;
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue1"_s))))->toString()));
			} else {
				$nc(this->md)->setColumnCount(getIntegerValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::ColumnDefinitionTag:
		{
			break;
		}
	case XmlReaderContentHandler::ColumnIndexTag:
		{
			++this->idx;
			break;
		}
	case XmlReaderContentHandler::AutoIncrementTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue1"_s))))->toString()));
			} else {
				$nc(this->md)->setAutoIncrement(this->idx, getBooleanValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::CaseSensitiveTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue1"_s))))->toString()));
			} else {
				$nc(this->md)->setCaseSensitive(this->idx, getBooleanValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::CurrencyTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue1"_s))))->toString()));
			} else {
				$nc(this->md)->setCurrency(this->idx, getBooleanValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::NullableTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue1"_s))))->toString()));
			} else {
				$nc(this->md)->setNullable(this->idx, getIntegerValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::SignedTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue1"_s))))->toString()));
			} else {
				$nc(this->md)->setSigned(this->idx, getBooleanValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::SearchableTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue1"_s))))->toString()));
			} else {
				$nc(this->md)->setSearchable(this->idx, getBooleanValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::ColumnDisplaySizeTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue1"_s))))->toString()));
			} else {
				$nc(this->md)->setColumnDisplaySize(this->idx, getIntegerValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::ColumnLabelTag:
		{
			if (nullValue) {
				$nc(this->md)->setColumnLabel(this->idx, nullptr);
			} else {
				$nc(this->md)->setColumnLabel(this->idx, s);
			}
			break;
		}
	case XmlReaderContentHandler::ColumnNameTag:
		{
			if (nullValue) {
				$nc(this->md)->setColumnName(this->idx, nullptr);
			} else {
				$nc(this->md)->setColumnName(this->idx, s);
			}
			break;
		}
	case XmlReaderContentHandler::SchemaNameTag:
		{
			if (nullValue) {
				$nc(this->md)->setSchemaName(this->idx, nullptr);
			} else {
				$nc(this->md)->setSchemaName(this->idx, s);
			}
			break;
		}
	case XmlReaderContentHandler::ColumnPrecisionTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue1"_s))))->toString()));
			} else {
				$nc(this->md)->setPrecision(this->idx, getIntegerValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::ColumnScaleTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue1"_s))))->toString()));
			} else {
				$nc(this->md)->setScale(this->idx, getIntegerValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::MetaTableNameTag:
		{
			if (nullValue) {
				$nc(this->md)->setTableName(this->idx, nullptr);
			} else {
				$nc(this->md)->setTableName(this->idx, s);
			}
			break;
		}
	case XmlReaderContentHandler::CatalogNameTag:
		{
			if (nullValue) {
				$nc(this->md)->setCatalogName(this->idx, nullptr);
			} else {
				$nc(this->md)->setCatalogName(this->idx, s);
			}
			break;
		}
	case XmlReaderContentHandler::ColumnTypeTag:
		{
			if (nullValue) {
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.badvalue1"_s))))->toString()));
			} else {
				$nc(this->md)->setColumnType(this->idx, getIntegerValue(s));
			}
			break;
		}
	case XmlReaderContentHandler::ColumnTypeNameTag:
		{
			if (nullValue) {
				$nc(this->md)->setColumnTypeName(this->idx, nullptr);
			} else {
				$nc(this->md)->setColumnTypeName(this->idx, s);
			}
			break;
		}
	default:
		{
			break;
		}
	}
}

void XmlReaderContentHandler::setDataValue($chars* ch, int32_t start, int32_t len) {
	$useLocalCurrentObjectStackCache();
	switch (getTag()) {
	case XmlReaderContentHandler::ColTag:
		{
			$set(this, columnValue, $new($String, ch, start, len));
			$set(this, tempStr, $nc(this->tempStr)->concat(this->columnValue));
			break;
		}
	case XmlReaderContentHandler::UpdTag:
		{
			$set(this, upd, $new($ObjectArray, 2));
			$set(this, tempUpdate, $nc(this->tempUpdate)->concat($$new($String, ch, start, len)));
			$nc(this->upd)->set(0, $($Integer::valueOf(this->idx)));
			$nc(this->upd)->set(1, this->tempUpdate);
			$set(this, lastval, $cast($String, $nc(this->upd)->get(1)));
			break;
		}
	case XmlReaderContentHandler::InsTag:
		{}
	}
}

void XmlReaderContentHandler::insertValue($String* s) {
	$useLocalCurrentObjectStackCache();
	if (getNullValue()) {
		$nc(this->rs)->updateNull(this->idx);
		return;
	}
	int32_t type = $nc($($nc(this->rs)->getMetaData()))->getColumnType(this->idx);
	switch (type) {
	case $Types::BIT:
		{
			$nc(this->rs)->updateBoolean(this->idx, getBooleanValue(s));
			break;
		}
	case $Types::BOOLEAN:
		{
			$nc(this->rs)->updateBoolean(this->idx, getBooleanValue(s));
			break;
		}
	case $Types::SMALLINT:
		{}
	case $Types::TINYINT:
		{
			$nc(this->rs)->updateShort(this->idx, getShortValue(s));
			break;
		}
	case $Types::INTEGER:
		{
			$nc(this->rs)->updateInt(this->idx, getIntegerValue(s));
			break;
		}
	case $Types::BIGINT:
		{
			$nc(this->rs)->updateLong(this->idx, getLongValue(s));
			break;
		}
	case $Types::REAL:
		{}
	case $Types::FLOAT:
		{
			$nc(this->rs)->updateFloat(this->idx, getFloatValue(s));
			break;
		}
	case $Types::DOUBLE:
		{
			$nc(this->rs)->updateDouble(this->idx, getDoubleValue(s));
			break;
		}
	case $Types::NUMERIC:
		{}
	case $Types::DECIMAL:
		{
			$nc(this->rs)->updateObject(this->idx, $($of(getBigDecimalValue(s))));
			break;
		}
	case $Types::BINARY:
		{}
	case $Types::VARBINARY:
		{}
	case $Types::LONGVARBINARY:
		{
			$nc(this->rs)->updateBytes(this->idx, $(getBinaryValue(s)));
			break;
		}
	case $Types::DATE:
		{
			$nc(this->rs)->updateDate(this->idx, $(getDateValue(s)));
			break;
		}
	case $Types::TIME:
		{
			$nc(this->rs)->updateTime(this->idx, $(getTimeValue(s)));
			break;
		}
	case $Types::TIMESTAMP:
		{
			$nc(this->rs)->updateTimestamp(this->idx, $(getTimestampValue(s)));
			break;
		}
	case $Types::CHAR:
		{}
	case $Types::VARCHAR:
		{}
	case $Types::LONGVARCHAR:
		{
			$nc(this->rs)->updateString(this->idx, $(getStringValue(s)));
			break;
		}
	default:
		{}
	}
}

void XmlReaderContentHandler::error($SAXParseException* e) {
	$throw(e);
}

void XmlReaderContentHandler::warning($SAXParseException* err) {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("xmlrch.warning"_s))))->toString());
	$nc($System::out)->println($($MessageFormat::format(var$0, $$new($ObjectArray, {
		$($of($nc(err)->getMessage())),
		$($of($Integer::valueOf(err->getLineNumber()))),
		$($of(err->getSystemId()))
	}))));
}

void XmlReaderContentHandler::notationDecl($String* name, $String* publicId, $String* systemId) {
}

void XmlReaderContentHandler::unparsedEntityDecl($String* name, $String* publicId, $String* systemId, $String* notationName) {
}

$Row* XmlReaderContentHandler::getPresentRow($WebRowSetImpl* rs) {
	return nullptr;
}

XmlReaderContentHandler::XmlReaderContentHandler() {
}

$Class* XmlReaderContentHandler::load$($String* name, bool initialize) {
	$loadClass(XmlReaderContentHandler, name, initialize, &_XmlReaderContentHandler_ClassInfo_, allocate$XmlReaderContentHandler);
	return class$;
}

$Class* XmlReaderContentHandler::class$ = nullptr;

			} // internal
		} // rowset
	} // sun
} // com
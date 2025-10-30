#include <javax/sql/rowset/RowSetMetaDataImpl.h>

#include <java/lang/reflect/Field.h>
#include <java/math/BigDecimal.h>
#include <java/sql/Blob.h>
#include <java/sql/Clob.h>
#include <java/sql/Date.h>
#include <java/sql/ResultSetMetaData.h>
#include <java/sql/SQLException.h>
#include <java/sql/Time.h>
#include <java/sql/Timestamp.h>
#include <java/sql/Types.h>
#include <javax/sql/RowSetMetaData.h>
#include <javax/sql/rowset/RowSetMetaDataImpl$ColInfo.h>
#include <jcpp.h>

#undef BIGINT
#undef BINARY
#undef BIT
#undef BLOB
#undef CLOB
#undef DATE
#undef DECIMAL
#undef DOUBLE
#undef FLOAT
#undef INTEGER
#undef LONGVARBINARY
#undef MAX_VALUE
#undef NUMERIC
#undef REAL
#undef SMALLINT
#undef TIME
#undef TIMESTAMP
#undef TINYINT
#undef VARBINARY

using $FieldArray = $Array<::java::lang::reflect::Field>;
using $RowSetMetaDataImpl$ColInfoArray = $Array<::javax::sql::rowset::RowSetMetaDataImpl$ColInfo>;
using $Serializable = ::java::io::Serializable;
using $Boolean = ::java::lang::Boolean;
using $Byte = ::java::lang::Byte;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Float = ::java::lang::Float;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Short = ::java::lang::Short;
using $Field = ::java::lang::reflect::Field;
using $BigDecimal = ::java::math::BigDecimal;
using $Blob = ::java::sql::Blob;
using $Clob = ::java::sql::Clob;
using $Date = ::java::sql::Date;
using $ResultSetMetaData = ::java::sql::ResultSetMetaData;
using $SQLException = ::java::sql::SQLException;
using $Time = ::java::sql::Time;
using $Timestamp = ::java::sql::Timestamp;
using $Types = ::java::sql::Types;
using $RowSetMetaData = ::javax::sql::RowSetMetaData;
using $RowSetMetaDataImpl$ColInfo = ::javax::sql::rowset::RowSetMetaDataImpl$ColInfo;

namespace javax {
	namespace sql {
		namespace rowset {

$FieldInfo _RowSetMetaDataImpl_FieldInfo_[] = {
	{"colCount", "I", nullptr, $PRIVATE, $field(RowSetMetaDataImpl, colCount)},
	{"colInfo", "[Ljavax/sql/rowset/RowSetMetaDataImpl$ColInfo;", nullptr, $PRIVATE, $field(RowSetMetaDataImpl, colInfo)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(RowSetMetaDataImpl, serialVersionUID)},
	{}
};

$MethodInfo _RowSetMetaDataImpl_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RowSetMetaDataImpl::*)()>(&RowSetMetaDataImpl::init$))},
	{"checkColRange", "(I)V", nullptr, $PRIVATE, $method(static_cast<void(RowSetMetaDataImpl::*)(int32_t)>(&RowSetMetaDataImpl::checkColRange)), "java.sql.SQLException"},
	{"checkColType", "(I)V", nullptr, $PRIVATE, $method(static_cast<void(RowSetMetaDataImpl::*)(int32_t)>(&RowSetMetaDataImpl::checkColType)), "java.sql.SQLException"},
	{"getCatalogName", "(I)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getColumnClassName", "(I)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getColumnCount", "()I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getColumnDisplaySize", "(I)I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getColumnLabel", "(I)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getColumnName", "(I)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getColumnType", "(I)I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getColumnTypeName", "(I)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getPrecision", "(I)I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getScale", "(I)I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getSchemaName", "(I)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"getTableName", "(I)Ljava/lang/String;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isAutoIncrement", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isCaseSensitive", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isCurrency", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isDefinitelyWritable", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isNullable", "(I)I", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isReadOnly", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isSearchable", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isSigned", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isWrapperFor", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PUBLIC, nullptr, "java.sql.SQLException"},
	{"isWritable", "(I)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setAutoIncrement", "(IZ)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setCaseSensitive", "(IZ)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setCatalogName", "(ILjava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setColumnCount", "(I)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setColumnDisplaySize", "(II)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setColumnLabel", "(ILjava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setColumnName", "(ILjava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setColumnType", "(II)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setColumnTypeName", "(ILjava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setCurrency", "(IZ)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setNullable", "(II)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setPrecision", "(II)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setScale", "(II)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setSchemaName", "(ILjava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setSearchable", "(IZ)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setSigned", "(IZ)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setTableName", "(ILjava/lang/String;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"unwrap", "(Ljava/lang/Class;)Ljava/lang/Object;", "<T:Ljava/lang/Object;>(Ljava/lang/Class<TT;>;)TT;", $PUBLIC, nullptr, "java.sql.SQLException"},
	{}
};

$InnerClassInfo _RowSetMetaDataImpl_InnerClassesInfo_[] = {
	{"javax.sql.rowset.RowSetMetaDataImpl$ColInfo", "javax.sql.rowset.RowSetMetaDataImpl", "ColInfo", $PRIVATE},
	{}
};

$ClassInfo _RowSetMetaDataImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.sql.rowset.RowSetMetaDataImpl",
	"java.lang.Object",
	"javax.sql.RowSetMetaData,java.io.Serializable",
	_RowSetMetaDataImpl_FieldInfo_,
	_RowSetMetaDataImpl_MethodInfo_,
	nullptr,
	nullptr,
	_RowSetMetaDataImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"javax.sql.rowset.RowSetMetaDataImpl$ColInfo"
};

$Object* allocate$RowSetMetaDataImpl($Class* clazz) {
	return $of($alloc(RowSetMetaDataImpl));
}

int32_t RowSetMetaDataImpl::hashCode() {
	 return this->$RowSetMetaData::hashCode();
}

bool RowSetMetaDataImpl::equals(Object$* arg0) {
	 return this->$RowSetMetaData::equals(arg0);
}

$Object* RowSetMetaDataImpl::clone() {
	 return this->$RowSetMetaData::clone();
}

$String* RowSetMetaDataImpl::toString() {
	 return this->$RowSetMetaData::toString();
}

void RowSetMetaDataImpl::finalize() {
	this->$RowSetMetaData::finalize();
}

void RowSetMetaDataImpl::init$() {
}

void RowSetMetaDataImpl::checkColRange(int32_t col) {
	$useLocalCurrentObjectStackCache();
	if (col <= 0 || col > this->colCount) {
		$throwNew($SQLException, $$str({"Invalid column index :"_s, $$str(col)}));
	}
}

void RowSetMetaDataImpl::checkColType(int32_t SQLType) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	try {
		$load($Types);
		$Class* c = $Types::class$;
		$var($FieldArray, publicFields, $nc(c)->getFields());
		int32_t fieldValue = 0;
		for (int32_t i = 0; i < $nc(publicFields)->length; ++i) {
			fieldValue = $nc(publicFields->get(i))->getInt(c);
			if (fieldValue == SQLType) {
				return;
			}
		}
	} catch ($Exception& e) {
		$throwNew($SQLException, $(e->getMessage()));
	}
	$throwNew($SQLException, "Invalid SQL type for column"_s);
}

void RowSetMetaDataImpl::setColumnCount(int32_t columnCount) {
	$useLocalCurrentObjectStackCache();
	if (columnCount <= 0) {
		$throwNew($SQLException, "Invalid column count. Cannot be less or equal to zero"_s);
	}
	this->colCount = columnCount;
	if (!(this->colCount == $Integer::MAX_VALUE)) {
		$set(this, colInfo, $new($RowSetMetaDataImpl$ColInfoArray, this->colCount + 1));
		for (int32_t i = 1; i <= this->colCount; ++i) {
			$nc(this->colInfo)->set(i, $$new($RowSetMetaDataImpl$ColInfo, this));
		}
	}
}

void RowSetMetaDataImpl::setAutoIncrement(int32_t columnIndex, bool property) {
	checkColRange(columnIndex);
	$nc($nc(this->colInfo)->get(columnIndex))->autoIncrement = property;
}

void RowSetMetaDataImpl::setCaseSensitive(int32_t columnIndex, bool property) {
	checkColRange(columnIndex);
	$nc($nc(this->colInfo)->get(columnIndex))->caseSensitive = property;
}

void RowSetMetaDataImpl::setSearchable(int32_t columnIndex, bool property) {
	checkColRange(columnIndex);
	$nc($nc(this->colInfo)->get(columnIndex))->searchable = property;
}

void RowSetMetaDataImpl::setCurrency(int32_t columnIndex, bool property) {
	checkColRange(columnIndex);
	$nc($nc(this->colInfo)->get(columnIndex))->currency = property;
}

void RowSetMetaDataImpl::setNullable(int32_t columnIndex, int32_t property) {
	if ((property < $ResultSetMetaData::columnNoNulls) || property > $ResultSetMetaData::columnNullableUnknown) {
		$throwNew($SQLException, "Invalid nullable constant set. Must be either columnNoNulls, columnNullable or columnNullableUnknown"_s);
	}
	checkColRange(columnIndex);
	$nc($nc(this->colInfo)->get(columnIndex))->nullable = property;
}

void RowSetMetaDataImpl::setSigned(int32_t columnIndex, bool property) {
	checkColRange(columnIndex);
	$nc($nc(this->colInfo)->get(columnIndex))->signed$ = property;
}

void RowSetMetaDataImpl::setColumnDisplaySize(int32_t columnIndex, int32_t size) {
	if (size < 0) {
		$throwNew($SQLException, "Invalid column display size. Cannot be less than zero"_s);
	}
	checkColRange(columnIndex);
	$nc($nc(this->colInfo)->get(columnIndex))->columnDisplaySize = size;
}

void RowSetMetaDataImpl::setColumnLabel(int32_t columnIndex, $String* label) {
	checkColRange(columnIndex);
	if (label != nullptr) {
		$set($nc($nc(this->colInfo)->get(columnIndex)), columnLabel, label);
	} else {
		$set($nc($nc(this->colInfo)->get(columnIndex)), columnLabel, ""_s);
	}
}

void RowSetMetaDataImpl::setColumnName(int32_t columnIndex, $String* columnName) {
	checkColRange(columnIndex);
	if (columnName != nullptr) {
		$set($nc($nc(this->colInfo)->get(columnIndex)), columnName, columnName);
	} else {
		$set($nc($nc(this->colInfo)->get(columnIndex)), columnName, ""_s);
	}
}

void RowSetMetaDataImpl::setSchemaName(int32_t columnIndex, $String* schemaName) {
	checkColRange(columnIndex);
	if (schemaName != nullptr) {
		$set($nc($nc(this->colInfo)->get(columnIndex)), schemaName, schemaName);
	} else {
		$set($nc($nc(this->colInfo)->get(columnIndex)), schemaName, ""_s);
	}
}

void RowSetMetaDataImpl::setPrecision(int32_t columnIndex, int32_t precision) {
	if (precision < 0) {
		$throwNew($SQLException, "Invalid precision value. Cannot be less than zero"_s);
	}
	checkColRange(columnIndex);
	$nc($nc(this->colInfo)->get(columnIndex))->colPrecision = precision;
}

void RowSetMetaDataImpl::setScale(int32_t columnIndex, int32_t scale) {
	if (scale < 0) {
		$throwNew($SQLException, "Invalid scale size. Cannot be less than zero"_s);
	}
	checkColRange(columnIndex);
	$nc($nc(this->colInfo)->get(columnIndex))->colScale = scale;
}

void RowSetMetaDataImpl::setTableName(int32_t columnIndex, $String* tableName) {
	checkColRange(columnIndex);
	if (tableName != nullptr) {
		$set($nc($nc(this->colInfo)->get(columnIndex)), tableName, tableName);
	} else {
		$set($nc($nc(this->colInfo)->get(columnIndex)), tableName, ""_s);
	}
}

void RowSetMetaDataImpl::setCatalogName(int32_t columnIndex, $String* catalogName) {
	checkColRange(columnIndex);
	if (catalogName != nullptr) {
		$set($nc($nc(this->colInfo)->get(columnIndex)), catName, catalogName);
	} else {
		$set($nc($nc(this->colInfo)->get(columnIndex)), catName, ""_s);
	}
}

void RowSetMetaDataImpl::setColumnType(int32_t columnIndex, int32_t SQLType) {
	checkColType(SQLType);
	checkColRange(columnIndex);
	$nc($nc(this->colInfo)->get(columnIndex))->colType = SQLType;
}

void RowSetMetaDataImpl::setColumnTypeName(int32_t columnIndex, $String* typeName) {
	checkColRange(columnIndex);
	if (typeName != nullptr) {
		$set($nc($nc(this->colInfo)->get(columnIndex)), colTypeName, typeName);
	} else {
		$set($nc($nc(this->colInfo)->get(columnIndex)), colTypeName, ""_s);
	}
}

int32_t RowSetMetaDataImpl::getColumnCount() {
	return this->colCount;
}

bool RowSetMetaDataImpl::isAutoIncrement(int32_t columnIndex) {
	checkColRange(columnIndex);
	return $nc($nc(this->colInfo)->get(columnIndex))->autoIncrement;
}

bool RowSetMetaDataImpl::isCaseSensitive(int32_t columnIndex) {
	checkColRange(columnIndex);
	return $nc($nc(this->colInfo)->get(columnIndex))->caseSensitive;
}

bool RowSetMetaDataImpl::isSearchable(int32_t columnIndex) {
	checkColRange(columnIndex);
	return $nc($nc(this->colInfo)->get(columnIndex))->searchable;
}

bool RowSetMetaDataImpl::isCurrency(int32_t columnIndex) {
	checkColRange(columnIndex);
	return $nc($nc(this->colInfo)->get(columnIndex))->currency;
}

int32_t RowSetMetaDataImpl::isNullable(int32_t columnIndex) {
	checkColRange(columnIndex);
	return $nc($nc(this->colInfo)->get(columnIndex))->nullable;
}

bool RowSetMetaDataImpl::isSigned(int32_t columnIndex) {
	checkColRange(columnIndex);
	return $nc($nc(this->colInfo)->get(columnIndex))->signed$;
}

int32_t RowSetMetaDataImpl::getColumnDisplaySize(int32_t columnIndex) {
	checkColRange(columnIndex);
	return $nc($nc(this->colInfo)->get(columnIndex))->columnDisplaySize;
}

$String* RowSetMetaDataImpl::getColumnLabel(int32_t columnIndex) {
	checkColRange(columnIndex);
	return $nc($nc(this->colInfo)->get(columnIndex))->columnLabel;
}

$String* RowSetMetaDataImpl::getColumnName(int32_t columnIndex) {
	checkColRange(columnIndex);
	return $nc($nc(this->colInfo)->get(columnIndex))->columnName;
}

$String* RowSetMetaDataImpl::getSchemaName(int32_t columnIndex) {
	checkColRange(columnIndex);
	$var($String, str, ""_s);
	if ($nc($nc(this->colInfo)->get(columnIndex))->schemaName == nullptr) {
	} else {
		$assign(str, $nc($nc(this->colInfo)->get(columnIndex))->schemaName);
	}
	return str;
}

int32_t RowSetMetaDataImpl::getPrecision(int32_t columnIndex) {
	checkColRange(columnIndex);
	return $nc($nc(this->colInfo)->get(columnIndex))->colPrecision;
}

int32_t RowSetMetaDataImpl::getScale(int32_t columnIndex) {
	checkColRange(columnIndex);
	return $nc($nc(this->colInfo)->get(columnIndex))->colScale;
}

$String* RowSetMetaDataImpl::getTableName(int32_t columnIndex) {
	checkColRange(columnIndex);
	return $nc($nc(this->colInfo)->get(columnIndex))->tableName;
}

$String* RowSetMetaDataImpl::getCatalogName(int32_t columnIndex) {
	checkColRange(columnIndex);
	$var($String, str, ""_s);
	if ($nc($nc(this->colInfo)->get(columnIndex))->catName == nullptr) {
	} else {
		$assign(str, $nc($nc(this->colInfo)->get(columnIndex))->catName);
	}
	return str;
}

int32_t RowSetMetaDataImpl::getColumnType(int32_t columnIndex) {
	checkColRange(columnIndex);
	return $nc($nc(this->colInfo)->get(columnIndex))->colType;
}

$String* RowSetMetaDataImpl::getColumnTypeName(int32_t columnIndex) {
	checkColRange(columnIndex);
	return $nc($nc(this->colInfo)->get(columnIndex))->colTypeName;
}

bool RowSetMetaDataImpl::isReadOnly(int32_t columnIndex) {
	checkColRange(columnIndex);
	return $nc($nc(this->colInfo)->get(columnIndex))->readOnly;
}

bool RowSetMetaDataImpl::isWritable(int32_t columnIndex) {
	checkColRange(columnIndex);
	return $nc($nc(this->colInfo)->get(columnIndex))->writable;
}

bool RowSetMetaDataImpl::isDefinitelyWritable(int32_t columnIndex) {
	checkColRange(columnIndex);
	return true;
}

$String* RowSetMetaDataImpl::getColumnClassName(int32_t columnIndex) {
	$var($String, className, $String::class$->getName());
	int32_t sqlType = getColumnType(columnIndex);
	switch (sqlType) {
	case $Types::NUMERIC:
		{}
	case $Types::DECIMAL:
		{
			$load($BigDecimal);
			$assign(className, $BigDecimal::class$->getName());
			break;
		}
	case $Types::BIT:
		{
			$load($Boolean);
			$assign(className, $Boolean::class$->getName());
			break;
		}
	case $Types::TINYINT:
		{
			$load($Byte);
			$assign(className, $Byte::class$->getName());
			break;
		}
	case $Types::SMALLINT:
		{
			$load($Short);
			$assign(className, $Short::class$->getName());
			break;
		}
	case $Types::INTEGER:
		{
			$load($Integer);
			$assign(className, $Integer::class$->getName());
			break;
		}
	case $Types::BIGINT:
		{
			$load($Long);
			$assign(className, $Long::class$->getName());
			break;
		}
	case $Types::REAL:
		{
			$load($Float);
			$assign(className, $Float::class$->getName());
			break;
		}
	case $Types::FLOAT:
		{}
	case $Types::DOUBLE:
		{
			$load($Double);
			$assign(className, $Double::class$->getName());
			break;
		}
	case $Types::BINARY:
		{}
	case $Types::VARBINARY:
		{}
	case $Types::LONGVARBINARY:
		{
			$assign(className, "byte[]"_s);
			break;
		}
	case $Types::DATE:
		{
			$load($Date);
			$assign(className, $Date::class$->getName());
			break;
		}
	case $Types::TIME:
		{
			$load($Time);
			$assign(className, $Time::class$->getName());
			break;
		}
	case $Types::TIMESTAMP:
		{
			$load($Timestamp);
			$assign(className, $Timestamp::class$->getName());
			break;
		}
	case $Types::BLOB:
		{
			$load($Blob);
			$assign(className, $Blob::class$->getName());
			break;
		}
	case $Types::CLOB:
		{
			$load($Clob);
			$assign(className, $Clob::class$->getName());
			break;
		}
	}
	return className;
}

$Object* RowSetMetaDataImpl::unwrap($Class* iface) {
	if (isWrapperFor(iface)) {
		return $of($nc(iface)->cast(this));
	} else {
		$throwNew($SQLException, $$str({"unwrap failed for:"_s, iface}));
	}
}

bool RowSetMetaDataImpl::isWrapperFor($Class* interfaces) {
	return $nc(interfaces)->isInstance(this);
}

RowSetMetaDataImpl::RowSetMetaDataImpl() {
}

$Class* RowSetMetaDataImpl::load$($String* name, bool initialize) {
	$loadClass(RowSetMetaDataImpl, name, initialize, &_RowSetMetaDataImpl_ClassInfo_, allocate$RowSetMetaDataImpl);
	return class$;
}

$Class* RowSetMetaDataImpl::class$ = nullptr;

		} // rowset
	} // sql
} // javax
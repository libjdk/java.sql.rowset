#include <javax/sql/rowset/RowSetMetaDataImpl$ColInfo.h>

#include <javax/sql/rowset/RowSetMetaDataImpl.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RowSetMetaDataImpl = ::javax::sql::rowset::RowSetMetaDataImpl;

namespace javax {
	namespace sql {
		namespace rowset {

$FieldInfo _RowSetMetaDataImpl$ColInfo_FieldInfo_[] = {
	{"this$0", "Ljavax/sql/rowset/RowSetMetaDataImpl;", nullptr, $FINAL | $SYNTHETIC, $field(RowSetMetaDataImpl$ColInfo, this$0)},
	{"autoIncrement", "Z", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, autoIncrement)},
	{"caseSensitive", "Z", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, caseSensitive)},
	{"currency", "Z", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, currency)},
	{"nullable", "I", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, nullable)},
	{"signed", "Z", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, signed$)},
	{"searchable", "Z", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, searchable)},
	{"columnDisplaySize", "I", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, columnDisplaySize)},
	{"columnLabel", "Ljava/lang/String;", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, columnLabel)},
	{"columnName", "Ljava/lang/String;", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, columnName)},
	{"schemaName", "Ljava/lang/String;", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, schemaName)},
	{"colPrecision", "I", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, colPrecision)},
	{"colScale", "I", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, colScale)},
	{"tableName", "Ljava/lang/String;", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, tableName)},
	{"catName", "Ljava/lang/String;", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, catName)},
	{"colType", "I", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, colType)},
	{"colTypeName", "Ljava/lang/String;", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, colTypeName)},
	{"readOnly", "Z", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, readOnly)},
	{"writable", "Z", nullptr, $PUBLIC, $field(RowSetMetaDataImpl$ColInfo, writable)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(RowSetMetaDataImpl$ColInfo, serialVersionUID)},
	{}
};

$MethodInfo _RowSetMetaDataImpl$ColInfo_MethodInfo_[] = {
	{"<init>", "(Ljavax/sql/rowset/RowSetMetaDataImpl;)V", nullptr, $PRIVATE, $method(static_cast<void(RowSetMetaDataImpl$ColInfo::*)($RowSetMetaDataImpl*)>(&RowSetMetaDataImpl$ColInfo::init$))},
	{}
};

$InnerClassInfo _RowSetMetaDataImpl$ColInfo_InnerClassesInfo_[] = {
	{"javax.sql.rowset.RowSetMetaDataImpl$ColInfo", "javax.sql.rowset.RowSetMetaDataImpl", "ColInfo", $PRIVATE},
	{}
};

$ClassInfo _RowSetMetaDataImpl$ColInfo_ClassInfo_ = {
	$ACC_SUPER,
	"javax.sql.rowset.RowSetMetaDataImpl$ColInfo",
	"java.lang.Object",
	"java.io.Serializable",
	_RowSetMetaDataImpl$ColInfo_FieldInfo_,
	_RowSetMetaDataImpl$ColInfo_MethodInfo_,
	nullptr,
	nullptr,
	_RowSetMetaDataImpl$ColInfo_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"javax.sql.rowset.RowSetMetaDataImpl"
};

$Object* allocate$RowSetMetaDataImpl$ColInfo($Class* clazz) {
	return $of($alloc(RowSetMetaDataImpl$ColInfo));
}

void RowSetMetaDataImpl$ColInfo::init$($RowSetMetaDataImpl* this$0) {
	$set(this, this$0, this$0);
	$set(this, tableName, ""_s);
	this->readOnly = false;
	this->writable = true;
}

RowSetMetaDataImpl$ColInfo::RowSetMetaDataImpl$ColInfo() {
}

$Class* RowSetMetaDataImpl$ColInfo::load$($String* name, bool initialize) {
	$loadClass(RowSetMetaDataImpl$ColInfo, name, initialize, &_RowSetMetaDataImpl$ColInfo_ClassInfo_, allocate$RowSetMetaDataImpl$ColInfo);
	return class$;
}

$Class* RowSetMetaDataImpl$ColInfo::class$ = nullptr;

		} // rowset
	} // sql
} // javax
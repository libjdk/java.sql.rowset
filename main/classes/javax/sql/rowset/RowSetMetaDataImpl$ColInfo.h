#ifndef _javax_sql_rowset_RowSetMetaDataImpl$ColInfo_h_
#define _javax_sql_rowset_RowSetMetaDataImpl$ColInfo_h_
//$ class javax.sql.rowset.RowSetMetaDataImpl$ColInfo
//$ extends java.io.Serializable

#include <java/io/Serializable.h>

namespace javax {
	namespace sql {
		namespace rowset {
			class RowSetMetaDataImpl;
		}
	}
}

namespace javax {
	namespace sql {
		namespace rowset {

class RowSetMetaDataImpl$ColInfo : public ::java::io::Serializable {
	$class(RowSetMetaDataImpl$ColInfo, $NO_CLASS_INIT, ::java::io::Serializable)
public:
	RowSetMetaDataImpl$ColInfo();
	void init$(::javax::sql::rowset::RowSetMetaDataImpl* this$0);
	::javax::sql::rowset::RowSetMetaDataImpl* this$0 = nullptr;
	bool autoIncrement = false;
	bool caseSensitive = false;
	bool currency = false;
	int32_t nullable = 0;
	bool signed$ = false;
	bool searchable = false;
	int32_t columnDisplaySize = 0;
	$String* columnLabel = nullptr;
	$String* columnName = nullptr;
	$String* schemaName = nullptr;
	int32_t colPrecision = 0;
	int32_t colScale = 0;
	$String* tableName = nullptr;
	$String* catName = nullptr;
	int32_t colType = 0;
	$String* colTypeName = nullptr;
	bool readOnly = false;
	bool writable = false;
	static const int64_t serialVersionUID = (int64_t)0x4C335D2CDA6D5DB3;
};

		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_RowSetMetaDataImpl$ColInfo_h_
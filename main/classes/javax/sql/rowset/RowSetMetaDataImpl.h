#ifndef _javax_sql_rowset_RowSetMetaDataImpl_h_
#define _javax_sql_rowset_RowSetMetaDataImpl_h_
//$ class javax.sql.rowset.RowSetMetaDataImpl
//$ extends javax.sql.RowSetMetaData
//$ implements java.io.Serializable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>
#include <javax/sql/RowSetMetaData.h>

namespace javax {
	namespace sql {
		namespace rowset {
			class RowSetMetaDataImpl$ColInfo;
		}
	}
}

namespace javax {
	namespace sql {
		namespace rowset {

class $export RowSetMetaDataImpl : public ::javax::sql::RowSetMetaData, public ::java::io::Serializable {
	$class(RowSetMetaDataImpl, $NO_CLASS_INIT, ::javax::sql::RowSetMetaData, ::java::io::Serializable)
public:
	RowSetMetaDataImpl();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$();
	void checkColRange(int32_t col);
	void checkColType(int32_t SQLType);
	virtual $String* getCatalogName(int32_t columnIndex) override;
	virtual $String* getColumnClassName(int32_t columnIndex) override;
	virtual int32_t getColumnCount() override;
	virtual int32_t getColumnDisplaySize(int32_t columnIndex) override;
	virtual $String* getColumnLabel(int32_t columnIndex) override;
	virtual $String* getColumnName(int32_t columnIndex) override;
	virtual int32_t getColumnType(int32_t columnIndex) override;
	virtual $String* getColumnTypeName(int32_t columnIndex) override;
	virtual int32_t getPrecision(int32_t columnIndex) override;
	virtual int32_t getScale(int32_t columnIndex) override;
	virtual $String* getSchemaName(int32_t columnIndex) override;
	virtual $String* getTableName(int32_t columnIndex) override;
	virtual bool isAutoIncrement(int32_t columnIndex) override;
	virtual bool isCaseSensitive(int32_t columnIndex) override;
	virtual bool isCurrency(int32_t columnIndex) override;
	virtual bool isDefinitelyWritable(int32_t columnIndex) override;
	virtual int32_t isNullable(int32_t columnIndex) override;
	virtual bool isReadOnly(int32_t columnIndex) override;
	virtual bool isSearchable(int32_t columnIndex) override;
	virtual bool isSigned(int32_t columnIndex) override;
	virtual bool isWrapperFor($Class* interfaces) override;
	virtual bool isWritable(int32_t columnIndex) override;
	virtual void setAutoIncrement(int32_t columnIndex, bool property) override;
	virtual void setCaseSensitive(int32_t columnIndex, bool property) override;
	virtual void setCatalogName(int32_t columnIndex, $String* catalogName) override;
	virtual void setColumnCount(int32_t columnCount) override;
	virtual void setColumnDisplaySize(int32_t columnIndex, int32_t size) override;
	virtual void setColumnLabel(int32_t columnIndex, $String* label) override;
	virtual void setColumnName(int32_t columnIndex, $String* columnName) override;
	virtual void setColumnType(int32_t columnIndex, int32_t SQLType) override;
	virtual void setColumnTypeName(int32_t columnIndex, $String* typeName) override;
	virtual void setCurrency(int32_t columnIndex, bool property) override;
	virtual void setNullable(int32_t columnIndex, int32_t property) override;
	virtual void setPrecision(int32_t columnIndex, int32_t precision) override;
	virtual void setScale(int32_t columnIndex, int32_t scale) override;
	virtual void setSchemaName(int32_t columnIndex, $String* schemaName) override;
	virtual void setSearchable(int32_t columnIndex, bool property) override;
	virtual void setSigned(int32_t columnIndex, bool property) override;
	virtual void setTableName(int32_t columnIndex, $String* tableName) override;
	virtual $String* toString() override;
	virtual $Object* unwrap($Class* iface) override;
	int32_t colCount = 0;
	$Array<::javax::sql::rowset::RowSetMetaDataImpl$ColInfo>* colInfo = nullptr;
	static const int64_t serialVersionUID = (int64_t)0x5FABB86613F6F18B;
};

		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_RowSetMetaDataImpl_h_
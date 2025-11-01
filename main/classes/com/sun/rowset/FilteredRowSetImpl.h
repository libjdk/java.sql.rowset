#ifndef _com_sun_rowset_FilteredRowSetImpl_h_
#define _com_sun_rowset_FilteredRowSetImpl_h_
//$ class com.sun.rowset.FilteredRowSetImpl
//$ extends com.sun.rowset.WebRowSetImpl
//$ implements javax.sql.rowset.FilteredRowSet

#include <com/sun/rowset/WebRowSetImpl.h>
#include <java/lang/Array.h>
#include <javax/sql/rowset/FilteredRowSet.h>

namespace java {
	namespace io {
		class InputStream;
		class ObjectInputStream;
		class Reader;
	}
}
namespace java {
	namespace math {
		class BigDecimal;
	}
}
namespace java {
	namespace sql {
		class Date;
		class Time;
		class Timestamp;
	}
}
namespace java {
	namespace util {
		class Hashtable;
	}
}
namespace javax {
	namespace sql {
		namespace rowset {
			class Predicate;
		}
	}
}

namespace com {
	namespace sun {
		namespace rowset {

class FilteredRowSetImpl : public ::com::sun::rowset::WebRowSetImpl, public ::javax::sql::rowset::FilteredRowSet {
	$class(FilteredRowSetImpl, $NO_CLASS_INIT, ::com::sun::rowset::WebRowSetImpl, ::javax::sql::rowset::FilteredRowSet)
public:
	FilteredRowSetImpl();
	virtual void acceptChanges() override;
	virtual void acceptChanges(::java::sql::Connection* con) override;
	virtual void addRowSetListener(::javax::sql::RowSetListener* listener) override;
	virtual void afterLast() override;
	virtual void beforeFirst() override;
	virtual void cancelRowUpdates() override;
	virtual void clearParameters() override;
	virtual void clearWarnings() override;
	virtual $Object* clone() override;
	virtual void close() override;
	virtual bool columnUpdated(int32_t idx) override;
	virtual bool columnUpdated($String* columnName) override;
	virtual void commit() override;
	virtual ::javax::sql::rowset::CachedRowSet* createCopy() override;
	virtual ::javax::sql::rowset::CachedRowSet* createCopyNoConstraints() override;
	virtual ::javax::sql::rowset::CachedRowSet* createCopySchema() override;
	virtual ::javax::sql::RowSet* createShared() override;
	virtual void deleteRow() override;
	virtual bool equals(Object$* arg0) override;
	virtual void execute(::java::sql::Connection* conn) override;
	virtual void execute() override;
	virtual void finalize() override;
	virtual int32_t findColumn($String* columnName) override;
	virtual bool first() override;
	virtual ::java::sql::Array* getArray(int32_t columnIndex) override;
	virtual ::java::sql::Array* getArray($String* colName) override;
	virtual ::java::io::InputStream* getAsciiStream(int32_t columnIndex) override;
	virtual ::java::io::InputStream* getAsciiStream($String* columnName) override;
	virtual ::java::math::BigDecimal* getBigDecimal(int32_t columnIndex, int32_t scale) override;
	virtual ::java::math::BigDecimal* getBigDecimal($String* columnName, int32_t scale) override;
	virtual ::java::math::BigDecimal* getBigDecimal(int32_t columnIndex) override;
	virtual ::java::math::BigDecimal* getBigDecimal($String* columnName) override;
	virtual ::java::io::InputStream* getBinaryStream(int32_t columnIndex) override;
	virtual ::java::io::InputStream* getBinaryStream($String* columnName) override;
	virtual ::java::sql::Blob* getBlob(int32_t columnIndex) override;
	virtual ::java::sql::Blob* getBlob($String* colName) override;
	virtual bool getBoolean(int32_t columnIndex) override;
	virtual bool getBoolean($String* columnName) override;
	virtual int8_t getByte(int32_t columnIndex) override;
	virtual int8_t getByte($String* columnName) override;
	virtual $bytes* getBytes(int32_t columnIndex) override;
	virtual $bytes* getBytes($String* columnName) override;
	virtual ::java::io::Reader* getCharacterStream(int32_t columnIndex) override;
	virtual ::java::io::Reader* getCharacterStream($String* columnName) override;
	virtual ::java::sql::Clob* getClob(int32_t columnIndex) override;
	virtual ::java::sql::Clob* getClob($String* colName) override;
	virtual $String* getCommand() override;
	virtual int32_t getConcurrency() override;
	virtual $String* getCursorName() override;
	virtual $String* getDataSourceName() override;
	virtual ::java::sql::Date* getDate(int32_t columnIndex) override;
	virtual ::java::sql::Date* getDate($String* columnName) override;
	virtual ::java::sql::Date* getDate(int32_t columnIndex, ::java::util::Calendar* cal) override;
	virtual ::java::sql::Date* getDate($String* columnName, ::java::util::Calendar* cal) override;
	virtual double getDouble(int32_t columnIndex) override;
	virtual double getDouble($String* columnName) override;
	virtual bool getEscapeProcessing() override;
	virtual int32_t getFetchDirection() override;
	virtual int32_t getFetchSize() override;
	virtual float getFloat(int32_t columnIndex) override;
	virtual float getFloat($String* columnName) override;
	virtual int32_t getHoldability() override;
	virtual int32_t getInt(int32_t columnIndex) override;
	virtual int32_t getInt($String* columnName) override;
	virtual $ints* getKeyColumns() override;
	virtual int64_t getLong(int32_t columnIndex) override;
	virtual int64_t getLong($String* columnName) override;
	virtual $ints* getMatchColumnIndexes() override;
	virtual $StringArray* getMatchColumnNames() override;
	virtual int32_t getMaxFieldSize() override;
	virtual int32_t getMaxRows() override;
	virtual ::java::sql::ResultSetMetaData* getMetaData() override;
	virtual ::java::io::Reader* getNCharacterStream(int32_t columnIndex) override;
	virtual ::java::io::Reader* getNCharacterStream($String* columnName) override;
	virtual ::java::sql::NClob* getNClob(int32_t i) override;
	virtual ::java::sql::NClob* getNClob($String* colName) override;
	virtual $String* getNString(int32_t columnIndex) override;
	virtual $String* getNString($String* columnName) override;
	virtual $Object* getObject(int32_t columnIndex) override;
	virtual $Object* getObject($String* columnName) override;
	virtual $Object* getObject(int32_t columnIndex, ::java::util::Map* map) override;
	virtual $Object* getObject($String* columnName, ::java::util::Map* map) override;
	virtual $Object* getObject(int32_t columnIndex, $Class* type) override;
	virtual $Object* getObject($String* columnLabel, $Class* type) override;
	virtual ::java::sql::ResultSet* getOriginal() override;
	virtual ::java::sql::ResultSet* getOriginalRow() override;
	virtual int32_t getPageSize() override;
	virtual $String* getPassword() override;
	virtual int32_t getQueryTimeout() override;
	virtual ::java::sql::Ref* getRef(int32_t columnIndex) override;
	virtual ::java::sql::Ref* getRef($String* colName) override;
	virtual int32_t getRow() override;
	virtual ::java::sql::RowId* getRowId(int32_t columnIndex) override;
	virtual ::java::sql::RowId* getRowId($String* columnName) override;
	virtual ::javax::sql::rowset::RowSetWarning* getRowSetWarnings() override;
	virtual ::java::sql::SQLXML* getSQLXML(int32_t columnIndex) override;
	virtual ::java::sql::SQLXML* getSQLXML($String* colName) override;
	virtual int16_t getShort(int32_t columnIndex) override;
	virtual int16_t getShort($String* columnName) override;
	virtual bool getShowDeleted() override;
	virtual ::java::sql::Statement* getStatement() override;
	virtual $String* getString(int32_t columnIndex) override;
	virtual $String* getString($String* columnName) override;
	virtual ::javax::sql::rowset::spi::SyncProvider* getSyncProvider() override;
	virtual $String* getTableName() override;
	virtual ::java::sql::Time* getTime(int32_t columnIndex) override;
	virtual ::java::sql::Time* getTime($String* columnName) override;
	virtual ::java::sql::Time* getTime(int32_t columnIndex, ::java::util::Calendar* cal) override;
	virtual ::java::sql::Time* getTime($String* columnName, ::java::util::Calendar* cal) override;
	virtual ::java::sql::Timestamp* getTimestamp(int32_t columnIndex) override;
	virtual ::java::sql::Timestamp* getTimestamp($String* columnName) override;
	virtual ::java::sql::Timestamp* getTimestamp(int32_t columnIndex, ::java::util::Calendar* cal) override;
	virtual ::java::sql::Timestamp* getTimestamp($String* columnName, ::java::util::Calendar* cal) override;
	virtual int32_t getTransactionIsolation() override;
	virtual int32_t getType() override;
	virtual ::java::util::Map* getTypeMap() override;
	virtual ::java::net::URL* getURL(int32_t columnIndex) override;
	virtual ::java::net::URL* getURL($String* columnName) override;
	virtual ::java::io::InputStream* getUnicodeStream(int32_t columnIndex) override;
	virtual ::java::io::InputStream* getUnicodeStream($String* columnName) override;
	virtual $String* getUrl() override;
	virtual $String* getUsername() override;
	virtual ::java::sql::SQLWarning* getWarnings() override;
	virtual int32_t hashCode() override;
	void init$();
	void init$(::java::util::Hashtable* env);
	virtual bool absolute(int32_t rows) override;
	virtual ::javax::sql::rowset::Predicate* getFilter() override;
	virtual void insertRow() override;
	virtual bool internalFirst() override;
	virtual bool internalLast() override;
	virtual bool internalNext() override;
	virtual bool internalPrevious() override;
	virtual bool isAfterLast() override;
	virtual bool isBeforeFirst() override;
	virtual bool isClosed() override;
	virtual bool isFirst() override;
	virtual bool isLast() override;
	virtual bool isReadOnly() override;
	virtual bool isWrapperFor($Class* interfaces) override;
	virtual bool last() override;
	virtual void moveToCurrentRow() override;
	virtual void moveToInsertRow() override;
	virtual bool next() override;
	virtual bool nextPage() override;
	virtual void populate(::java::sql::ResultSet* data) override;
	virtual void populate(::java::sql::ResultSet* data, int32_t start) override;
	virtual bool previous() override;
	virtual bool previousPage() override;
	void readObject(::java::io::ObjectInputStream* ois);
	virtual void readXml(::java::io::Reader* reader) override;
	virtual void readXml(::java::io::InputStream* iStream) override;
	virtual void refreshRow() override;
	virtual bool relative(int32_t rows) override;
	virtual void release() override;
	virtual void removeRowSetListener(::javax::sql::RowSetListener* listener) override;
	virtual void restoreOriginal() override;
	virtual void rollback() override;
	virtual void rollback(::java::sql::Savepoint* s) override;
	virtual bool rowDeleted() override;
	virtual bool rowInserted() override;
	virtual void rowSetPopulated(::javax::sql::RowSetEvent* event, int32_t numRows) override;
	virtual bool rowUpdated() override;
	virtual void setArray(int32_t parameterIndex, ::java::sql::Array* array) override;
	virtual void setAsciiStream($String* parameterName, ::java::io::InputStream* x, int32_t length) override;
	virtual void setAsciiStream($String* parameterName, ::java::io::InputStream* x) override;
	virtual void setAsciiStream(int32_t parameterIndex, ::java::io::InputStream* x, int32_t length) override;
	virtual void setAsciiStream(int32_t parameterIndex, ::java::io::InputStream* x) override;
	virtual void setBigDecimal($String* parameterName, ::java::math::BigDecimal* x) override;
	virtual void setBigDecimal(int32_t parameterIndex, ::java::math::BigDecimal* x) override;
	virtual void setBinaryStream($String* parameterName, ::java::io::InputStream* x, int32_t length) override;
	virtual void setBinaryStream($String* parameterName, ::java::io::InputStream* x) override;
	virtual void setBinaryStream(int32_t parameterIndex, ::java::io::InputStream* x, int32_t length) override;
	virtual void setBinaryStream(int32_t parameterIndex, ::java::io::InputStream* x) override;
	virtual void setBlob(int32_t parameterIndex, ::java::io::InputStream* inputStream, int64_t length) override;
	virtual void setBlob(int32_t parameterIndex, ::java::io::InputStream* inputStream) override;
	virtual void setBlob($String* parameterName, ::java::io::InputStream* inputStream, int64_t length) override;
	virtual void setBlob($String* parameterName, ::java::sql::Blob* x) override;
	virtual void setBlob($String* parameterName, ::java::io::InputStream* inputStream) override;
	virtual void setBlob(int32_t parameterIndex, ::java::sql::Blob* x) override;
	virtual void setBoolean($String* parameterName, bool x) override;
	virtual void setBoolean(int32_t parameterIndex, bool x) override;
	virtual void setByte($String* parameterName, int8_t x) override;
	virtual void setByte(int32_t parameterIndex, int8_t x) override;
	virtual void setBytes($String* parameterName, $bytes* x) override;
	virtual void setBytes(int32_t parameterIndex, $bytes* x) override;
	virtual void setCharacterStream($String* parameterName, ::java::io::Reader* reader, int32_t length) override;
	virtual void setCharacterStream($String* parameterName, ::java::io::Reader* reader) override;
	virtual void setCharacterStream(int32_t parameterIndex, ::java::io::Reader* reader, int32_t length) override;
	virtual void setCharacterStream(int32_t parameterIndex, ::java::io::Reader* reader) override;
	virtual void setClob($String* parameterName, ::java::io::Reader* reader, int64_t length) override;
	virtual void setClob($String* parameterName, ::java::sql::Clob* x) override;
	virtual void setClob($String* parameterName, ::java::io::Reader* reader) override;
	virtual void setClob(int32_t parameterIndex, ::java::io::Reader* reader) override;
	virtual void setClob(int32_t parameterIndex, ::java::io::Reader* reader, int64_t length) override;
	virtual void setClob(int32_t parameterIndex, ::java::sql::Clob* x) override;
	virtual void setCommand($String* cmd) override;
	virtual void setConcurrency(int32_t concurrency) override;
	virtual void setDataSourceName($String* name) override;
	virtual void setDate($String* parameterName, ::java::sql::Date* x) override;
	virtual void setDate($String* parameterName, ::java::sql::Date* x, ::java::util::Calendar* cal) override;
	virtual void setDate(int32_t parameterIndex, ::java::sql::Date* x) override;
	virtual void setDate(int32_t parameterIndex, ::java::sql::Date* x, ::java::util::Calendar* cal) override;
	virtual void setDouble($String* parameterName, double x) override;
	virtual void setDouble(int32_t parameterIndex, double x) override;
	virtual void setEscapeProcessing(bool enable) override;
	virtual void setFetchDirection(int32_t direction) override;
	virtual void setFetchSize(int32_t rows) override;
	virtual void setFilter(::javax::sql::rowset::Predicate* p) override;
	virtual void setFloat($String* parameterName, float x) override;
	virtual void setFloat(int32_t parameterIndex, float x) override;
	virtual void setInt($String* parameterName, int32_t x) override;
	virtual void setInt(int32_t parameterIndex, int32_t x) override;
	virtual void setKeyColumns($ints* keys) override;
	virtual void setLong($String* parameterName, int64_t x) override;
	virtual void setLong(int32_t parameterIndex, int64_t x) override;
	virtual void setMatchColumn($ints* columnIdxes) override;
	virtual void setMatchColumn($StringArray* columnNames) override;
	virtual void setMatchColumn(int32_t columnIdx) override;
	virtual void setMatchColumn($String* columnName) override;
	virtual void setMaxFieldSize(int32_t max) override;
	virtual void setMaxRows(int32_t max) override;
	virtual void setMetaData(::javax::sql::RowSetMetaData* md) override;
	virtual void setNCharacterStream(int32_t parameterIndex, ::java::io::Reader* value) override;
	virtual void setNCharacterStream(int32_t parameterIndex, ::java::io::Reader* value, int64_t length) override;
	virtual void setNCharacterStream($String* parameterName, ::java::io::Reader* value, int64_t length) override;
	virtual void setNCharacterStream($String* parameterName, ::java::io::Reader* value) override;
	virtual void setNClob($String* parameterName, ::java::sql::NClob* value) override;
	virtual void setNClob(int32_t parameterIndex, ::java::io::Reader* reader) override;
	virtual void setNClob($String* parameterName, ::java::io::Reader* reader, int64_t length) override;
	virtual void setNClob($String* parameterName, ::java::io::Reader* reader) override;
	virtual void setNClob(int32_t parameterIndex, ::java::io::Reader* reader, int64_t length) override;
	virtual void setNClob(int32_t parameterIndex, ::java::sql::NClob* value) override;
	virtual void setNString(int32_t parameterIndex, $String* value) override;
	virtual void setNString($String* parameterName, $String* value) override;
	virtual void setNull($String* parameterName, int32_t sqlType) override;
	virtual void setNull($String* parameterName, int32_t sqlType, $String* typeName) override;
	virtual void setNull(int32_t parameterIndex, int32_t sqlType) override;
	virtual void setNull(int32_t parameterIndex, int32_t sqlType, $String* typeName) override;
	virtual void setObject($String* parameterName, Object$* x, int32_t targetSqlType, int32_t scale) override;
	virtual void setObject($String* parameterName, Object$* x, int32_t targetSqlType) override;
	virtual void setObject($String* parameterName, Object$* x) override;
	virtual void setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType, int32_t scale) override;
	virtual void setObject(int32_t parameterIndex, Object$* x, int32_t targetSqlType) override;
	virtual void setObject(int32_t parameterIndex, Object$* x) override;
	virtual void setOriginalRow() override;
	virtual void setPageSize(int32_t size) override;
	virtual void setPassword($String* pass) override;
	virtual void setQueryTimeout(int32_t seconds) override;
	virtual void setReadOnly(bool value) override;
	virtual void setRef(int32_t parameterIndex, ::java::sql::Ref* ref) override;
	virtual void setRowId(int32_t parameterIndex, ::java::sql::RowId* x) override;
	virtual void setRowId($String* parameterName, ::java::sql::RowId* x) override;
	virtual void setSQLXML(int32_t parameterIndex, ::java::sql::SQLXML* xmlObject) override;
	virtual void setSQLXML($String* parameterName, ::java::sql::SQLXML* xmlObject) override;
	virtual void setShort($String* parameterName, int16_t x) override;
	virtual void setShort(int32_t parameterIndex, int16_t x) override;
	virtual void setShowDeleted(bool value) override;
	virtual void setString($String* parameterName, $String* x) override;
	virtual void setString(int32_t parameterIndex, $String* x) override;
	virtual void setSyncProvider($String* providerStr) override;
	virtual void setTableName($String* tabName) override;
	virtual void setTime($String* parameterName, ::java::sql::Time* x) override;
	virtual void setTime($String* parameterName, ::java::sql::Time* x, ::java::util::Calendar* cal) override;
	virtual void setTime(int32_t parameterIndex, ::java::sql::Time* x) override;
	virtual void setTime(int32_t parameterIndex, ::java::sql::Time* x, ::java::util::Calendar* cal) override;
	virtual void setTimestamp($String* parameterName, ::java::sql::Timestamp* x, ::java::util::Calendar* cal) override;
	virtual void setTimestamp($String* parameterName, ::java::sql::Timestamp* x) override;
	virtual void setTimestamp(int32_t parameterIndex, ::java::sql::Timestamp* x) override;
	virtual void setTimestamp(int32_t parameterIndex, ::java::sql::Timestamp* x, ::java::util::Calendar* cal) override;
	virtual void setTransactionIsolation(int32_t level) override;
	virtual void setType(int32_t type) override;
	virtual void setTypeMap(::java::util::Map* map) override;
	virtual void setURL(int32_t parameterIndex, ::java::net::URL* x) override;
	virtual void setUrl($String* url) override;
	virtual void setUsername($String* name) override;
	virtual int32_t size() override;
	virtual ::java::util::Collection* toCollection() override;
	virtual ::java::util::Collection* toCollection(int32_t column) override;
	virtual ::java::util::Collection* toCollection($String* column) override;
	virtual $String* toString() override;
	virtual void undoDelete() override;
	virtual void undoInsert() override;
	virtual void undoUpdate() override;
	virtual void unsetMatchColumn($ints* columnIdxes) override;
	virtual void unsetMatchColumn($StringArray* columnIdxes) override;
	virtual void unsetMatchColumn(int32_t columnIdx) override;
	virtual void unsetMatchColumn($String* columnName) override;
	virtual $Object* unwrap($Class* iface) override;
	virtual void updateArray(int32_t columnIndex, ::java::sql::Array* a) override;
	virtual void updateArray($String* columnName, ::java::sql::Array* a) override;
	virtual void updateAsciiStream(int32_t columnIndex, ::java::io::InputStream* x, int64_t length) override;
	virtual void updateAsciiStream($String* columnLabel, ::java::io::InputStream* x, int64_t length) override;
	virtual void updateAsciiStream(int32_t columnIndex, ::java::io::InputStream* x) override;
	virtual void updateAsciiStream($String* columnLabel, ::java::io::InputStream* x) override;
	virtual void updateAsciiStream(int32_t columnIndex, ::java::io::InputStream* x, int32_t length) override;
	virtual void updateAsciiStream($String* columnName, ::java::io::InputStream* x, int32_t length) override;
	virtual void updateBigDecimal(int32_t columnIndex, ::java::math::BigDecimal* x) override;
	virtual void updateBigDecimal($String* columnName, ::java::math::BigDecimal* x) override;
	virtual void updateBinaryStream(int32_t columnIndex, ::java::io::InputStream* x, int64_t length) override;
	virtual void updateBinaryStream($String* columnLabel, ::java::io::InputStream* x, int64_t length) override;
	virtual void updateBinaryStream(int32_t columnIndex, ::java::io::InputStream* x) override;
	virtual void updateBinaryStream($String* columnLabel, ::java::io::InputStream* x) override;
	virtual void updateBinaryStream(int32_t columnIndex, ::java::io::InputStream* x, int32_t length) override;
	virtual void updateBinaryStream($String* columnName, ::java::io::InputStream* x, int32_t length) override;
	virtual void updateBlob(int32_t columnIndex, ::java::sql::Blob* b) override;
	virtual void updateBlob($String* columnName, ::java::sql::Blob* b) override;
	virtual void updateBlob(int32_t columnIndex, ::java::io::InputStream* inputStream, int64_t length) override;
	virtual void updateBlob($String* columnLabel, ::java::io::InputStream* inputStream, int64_t length) override;
	virtual void updateBlob(int32_t columnIndex, ::java::io::InputStream* inputStream) override;
	virtual void updateBlob($String* columnLabel, ::java::io::InputStream* inputStream) override;
	virtual void updateBoolean(int32_t columnIndex, bool x) override;
	virtual void updateBoolean($String* columnName, bool x) override;
	virtual void updateByte(int32_t columnIndex, int8_t x) override;
	virtual void updateByte($String* columnName, int8_t x) override;
	virtual void updateBytes(int32_t columnIndex, $bytes* x) override;
	virtual void updateBytes($String* columnName, $bytes* x) override;
	virtual void updateCharacterStream(int32_t columnIndex, ::java::io::Reader* x, int64_t length) override;
	virtual void updateCharacterStream($String* columnLabel, ::java::io::Reader* reader, int64_t length) override;
	virtual void updateCharacterStream(int32_t columnIndex, ::java::io::Reader* x) override;
	virtual void updateCharacterStream($String* columnLabel, ::java::io::Reader* reader) override;
	virtual void updateCharacterStream(int32_t columnIndex, ::java::io::Reader* x, int32_t length) override;
	virtual void updateCharacterStream($String* columnName, ::java::io::Reader* reader, int32_t length) override;
	virtual void updateClob(int32_t columnIndex, ::java::sql::Clob* c) override;
	virtual void updateClob($String* columnName, ::java::sql::Clob* c) override;
	virtual void updateClob(int32_t columnIndex, ::java::io::Reader* reader, int64_t length) override;
	virtual void updateClob($String* columnLabel, ::java::io::Reader* reader, int64_t length) override;
	virtual void updateClob(int32_t columnIndex, ::java::io::Reader* reader) override;
	virtual void updateClob($String* columnLabel, ::java::io::Reader* reader) override;
	virtual void updateDate(int32_t columnIndex, ::java::sql::Date* x) override;
	virtual void updateDate($String* columnName, ::java::sql::Date* x) override;
	virtual void updateDouble(int32_t columnIndex, double x) override;
	virtual void updateDouble($String* columnName, double x) override;
	virtual void updateFloat(int32_t columnIndex, float x) override;
	virtual void updateFloat($String* columnName, float x) override;
	virtual void updateInt(int32_t columnIndex, int32_t x) override;
	virtual void updateInt($String* columnName, int32_t x) override;
	virtual void updateLong(int32_t columnIndex, int64_t x) override;
	virtual void updateLong($String* columnName, int64_t x) override;
	virtual void updateNCharacterStream(int32_t columnIndex, ::java::io::Reader* x, int64_t length) override;
	virtual void updateNCharacterStream($String* columnName, ::java::io::Reader* x, int64_t length) override;
	virtual void updateNCharacterStream(int32_t columnIndex, ::java::io::Reader* x) override;
	virtual void updateNCharacterStream($String* columnLabel, ::java::io::Reader* reader) override;
	virtual void updateNClob(int32_t columnIndex, ::java::sql::NClob* nClob) override;
	virtual void updateNClob($String* columnName, ::java::sql::NClob* nClob) override;
	virtual void updateNClob(int32_t columnIndex, ::java::io::Reader* reader, int64_t length) override;
	virtual void updateNClob($String* columnLabel, ::java::io::Reader* reader, int64_t length) override;
	virtual void updateNClob(int32_t columnIndex, ::java::io::Reader* reader) override;
	virtual void updateNClob($String* columnLabel, ::java::io::Reader* reader) override;
	virtual void updateNString(int32_t columnIndex, $String* nString) override;
	virtual void updateNString($String* columnName, $String* nString) override;
	virtual void updateNull(int32_t columnIndex) override;
	virtual void updateNull($String* columnName) override;
	virtual void updateObject(int32_t arg0, Object$* arg1, ::java::sql::SQLType* arg2, int32_t arg3) override;
	virtual void updateObject($String* arg0, Object$* arg1, ::java::sql::SQLType* arg2, int32_t arg3) override;
	virtual void updateObject(int32_t arg0, Object$* arg1, ::java::sql::SQLType* arg2) override;
	virtual void updateObject($String* arg0, Object$* arg1, ::java::sql::SQLType* arg2) override;
	virtual void updateObject(int32_t columnIndex, Object$* x) override;
	virtual void updateObject($String* columnName, Object$* x) override;
	virtual void updateObject(int32_t columnIndex, Object$* x, int32_t scale) override;
	virtual void updateObject($String* columnName, Object$* x, int32_t scale) override;
	virtual void updateRef(int32_t columnIndex, ::java::sql::Ref* ref) override;
	virtual void updateRef($String* columnName, ::java::sql::Ref* ref) override;
	virtual void updateRow() override;
	virtual void updateRowId(int32_t columnIndex, ::java::sql::RowId* x) override;
	virtual void updateRowId($String* columnName, ::java::sql::RowId* x) override;
	virtual void updateSQLXML(int32_t columnIndex, ::java::sql::SQLXML* xmlObject) override;
	virtual void updateSQLXML($String* columnName, ::java::sql::SQLXML* xmlObject) override;
	virtual void updateShort(int32_t columnIndex, int16_t x) override;
	virtual void updateShort($String* columnName, int16_t x) override;
	virtual void updateString(int32_t columnIndex, $String* x) override;
	virtual void updateString($String* columnName, $String* x) override;
	virtual void updateTime(int32_t columnIndex, ::java::sql::Time* x) override;
	virtual void updateTime($String* columnName, ::java::sql::Time* x) override;
	virtual void updateTimestamp(int32_t columnIndex, ::java::sql::Timestamp* x) override;
	virtual void updateTimestamp($String* columnName, ::java::sql::Timestamp* x) override;
	virtual bool wasNull() override;
	virtual void writeXml(::java::sql::ResultSet* rs, ::java::io::Writer* writer) override;
	virtual void writeXml(::java::io::Writer* writer) override;
	virtual void writeXml(::java::io::OutputStream* oStream) override;
	virtual void writeXml(::java::sql::ResultSet* rs, ::java::io::OutputStream* oStream) override;
	::javax::sql::rowset::Predicate* p = nullptr;
	bool onInsertRow = false;
	static const int64_t serialVersionUID = (int64_t)0x55BE47B69B44FEF0;
};

		} // rowset
	} // sun
} // com

#endif // _com_sun_rowset_FilteredRowSetImpl_h_
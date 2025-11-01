#ifndef _javax_sql_rowset_CachedRowSet_h_
#define _javax_sql_rowset_CachedRowSet_h_
//$ interface javax.sql.rowset.CachedRowSet
//$ extends javax.sql.RowSet,javax.sql.rowset.Joinable

#include <java/lang/Array.h>
#include <javax/sql/RowSet.h>
#include <javax/sql/rowset/Joinable.h>

#pragma push_macro("COMMIT_ON_ACCEPT_CHANGES")
#undef COMMIT_ON_ACCEPT_CHANGES

namespace java {
	namespace sql {
		class Connection;
		class ResultSet;
		class Savepoint;
	}
}
namespace java {
	namespace util {
		class Collection;
	}
}
namespace javax {
	namespace sql {
		class RowSetEvent;
		class RowSetMetaData;
	}
}
namespace javax {
	namespace sql {
		namespace rowset {
			class RowSetWarning;
		}
	}
}
namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {
				class SyncProvider;
			}
		}
	}
}

namespace javax {
	namespace sql {
		namespace rowset {

class $export CachedRowSet : public ::javax::sql::RowSet, public ::javax::sql::rowset::Joinable {
	$interface(CachedRowSet, $NO_CLASS_INIT, ::javax::sql::RowSet, ::javax::sql::rowset::Joinable)
public:
	virtual void acceptChanges() {}
	virtual void acceptChanges(::java::sql::Connection* con) {}
	virtual $Object* clone() override;
	virtual bool columnUpdated(int32_t idx) {return false;}
	virtual bool columnUpdated($String* columnName) {return false;}
	virtual void commit() {}
	virtual ::javax::sql::rowset::CachedRowSet* createCopy() {return nullptr;}
	virtual ::javax::sql::rowset::CachedRowSet* createCopyNoConstraints() {return nullptr;}
	virtual ::javax::sql::rowset::CachedRowSet* createCopySchema() {return nullptr;}
	virtual ::javax::sql::RowSet* createShared() {return nullptr;}
	using ::javax::sql::RowSet::execute;
	virtual bool equals(Object$* arg0) override;
	virtual void execute(::java::sql::Connection* conn) {}
	virtual void finalize() override;
	virtual $ints* getKeyColumns() {return nullptr;}
	virtual ::java::sql::ResultSet* getOriginal() {return nullptr;}
	virtual ::java::sql::ResultSet* getOriginalRow() {return nullptr;}
	virtual int32_t getPageSize() {return 0;}
	virtual ::javax::sql::rowset::RowSetWarning* getRowSetWarnings() {return nullptr;}
	virtual bool getShowDeleted() {return false;}
	virtual ::javax::sql::rowset::spi::SyncProvider* getSyncProvider() {return nullptr;}
	virtual $String* getTableName() {return nullptr;}
	virtual int32_t hashCode() override;
	virtual bool nextPage() {return false;}
	virtual void populate(::java::sql::ResultSet* data) {}
	virtual void populate(::java::sql::ResultSet* rs, int32_t startRow) {}
	virtual bool previousPage() {return false;}
	virtual void release() {}
	virtual void restoreOriginal() {}
	virtual void rollback() {}
	virtual void rollback(::java::sql::Savepoint* s) {}
	virtual void rowSetPopulated(::javax::sql::RowSetEvent* event, int32_t numRows) {}
	virtual void setKeyColumns($ints* keys) {}
	virtual void setMetaData(::javax::sql::RowSetMetaData* md) {}
	virtual void setOriginalRow() {}
	virtual void setPageSize(int32_t size) {}
	virtual void setShowDeleted(bool b) {}
	virtual void setSyncProvider($String* provider) {}
	virtual void setTableName($String* tabName) {}
	virtual int32_t size() {return 0;}
	virtual ::java::util::Collection* toCollection() {return nullptr;}
	virtual ::java::util::Collection* toCollection(int32_t column) {return nullptr;}
	virtual ::java::util::Collection* toCollection($String* column) {return nullptr;}
	virtual $String* toString() override;
	virtual void undoDelete() {}
	virtual void undoInsert() {}
	virtual void undoUpdate() {}
	static const bool COMMIT_ON_ACCEPT_CHANGES = true;
};

		} // rowset
	} // sql
} // javax

#pragma pop_macro("COMMIT_ON_ACCEPT_CHANGES")

#endif // _javax_sql_rowset_CachedRowSet_h_
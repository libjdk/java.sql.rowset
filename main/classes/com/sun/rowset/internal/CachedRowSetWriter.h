#ifndef _com_sun_rowset_internal_CachedRowSetWriter_h_
#define _com_sun_rowset_internal_CachedRowSetWriter_h_
//$ class com.sun.rowset.internal.CachedRowSetWriter
//$ extends javax.sql.rowset.spi.TransactionalWriter
//$ implements java.io.Serializable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>
#include <javax/sql/rowset/spi/TransactionalWriter.h>

namespace com {
	namespace sun {
		namespace rowset {
			class CachedRowSetImpl;
			class JdbcRowSetResourceBundle;
		}
	}
}
namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {
				class CachedRowSetReader;
			}
		}
	}
}
namespace java {
	namespace io {
		class ObjectInputStream;
	}
}
namespace java {
	namespace sql {
		class Connection;
		class DatabaseMetaData;
		class PreparedStatement;
		class ResultSet;
		class ResultSetMetaData;
		class Savepoint;
	}
}
namespace java {
	namespace util {
		class ArrayList;
	}
}
namespace javax {
	namespace sql {
		class RowSetInternal;
	}
}
namespace javax {
	namespace sql {
		namespace rowset {
			class CachedRowSet;
		}
	}
}

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

class CachedRowSetWriter : public ::javax::sql::rowset::spi::TransactionalWriter, public ::java::io::Serializable {
	$class(CachedRowSetWriter, $NO_CLASS_INIT, ::javax::sql::rowset::spi::TransactionalWriter, ::java::io::Serializable)
public:
	CachedRowSetWriter();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$();
	void buildKeyDesc(::javax::sql::rowset::CachedRowSet* crs);
	$String* buildTableName(::java::sql::DatabaseMetaData* dbmd, $String* catalog, $String* schema, $String* table);
	$String* buildWhereClause($String* whereClause, ::java::sql::ResultSet* rs);
	virtual void commit() override;
	virtual void commit(::com::sun::rowset::CachedRowSetImpl* crs, bool updateRowset);
	bool deleteOriginalRow(::javax::sql::rowset::CachedRowSet* crs, ::com::sun::rowset::CachedRowSetImpl* crsRes);
	virtual ::com::sun::rowset::internal::CachedRowSetReader* getReader();
	void initSQLStatements(::javax::sql::rowset::CachedRowSet* caller);
	bool insertNewRow(::javax::sql::rowset::CachedRowSet* crs, ::java::sql::PreparedStatement* pstmt, ::com::sun::rowset::CachedRowSetImpl* crsRes);
	bool isPKNameValid($String* pk, ::java::sql::ResultSetMetaData* rsmd);
	void readObject(::java::io::ObjectInputStream* ois);
	virtual void rollback() override;
	virtual void rollback(::java::sql::Savepoint* s) override;
	virtual void setReader(::com::sun::rowset::internal::CachedRowSetReader* reader);
	virtual $String* toString() override;
	bool updateOriginalRow(::javax::sql::rowset::CachedRowSet* crs);
	virtual void updateResolvedConflictToDB(::javax::sql::rowset::CachedRowSet* crs, ::java::sql::Connection* con);
	virtual bool writeData(::javax::sql::RowSetInternal* caller) override;
	::java::sql::Connection* con = nullptr;
	$String* selectCmd = nullptr;
	$String* updateCmd = nullptr;
	$String* updateWhere = nullptr;
	$String* deleteCmd = nullptr;
	$String* deleteWhere = nullptr;
	$String* insertCmd = nullptr;
	$ints* keyCols = nullptr;
	$ObjectArray* params = nullptr;
	::com::sun::rowset::internal::CachedRowSetReader* reader = nullptr;
	::java::sql::ResultSetMetaData* callerMd = nullptr;
	int32_t callerColumnCount = 0;
	::com::sun::rowset::CachedRowSetImpl* crsResolve = nullptr;
	::java::util::ArrayList* status = nullptr;
	int32_t iChangedValsInDbAndCRS = 0;
	int32_t iChangedValsinDbOnly = 0;
	::com::sun::rowset::JdbcRowSetResourceBundle* resBundle = nullptr;
	static const int64_t serialVersionUID = (int64_t)0x89F481E63ED50A28;
};

			} // internal
		} // rowset
	} // sun
} // com

#endif // _com_sun_rowset_internal_CachedRowSetWriter_h_
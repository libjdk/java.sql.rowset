#ifndef _javax_sql_rowset_JdbcRowSet_h_
#define _javax_sql_rowset_JdbcRowSet_h_
//$ interface javax.sql.rowset.JdbcRowSet
//$ extends javax.sql.RowSet,javax.sql.rowset.Joinable

#include <javax/sql/RowSet.h>
#include <javax/sql/rowset/Joinable.h>

namespace java {
	namespace sql {
		class Savepoint;
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

class $import JdbcRowSet : public ::javax::sql::RowSet, public ::javax::sql::rowset::Joinable {
	$interface(JdbcRowSet, $NO_CLASS_INIT, ::javax::sql::RowSet, ::javax::sql::rowset::Joinable)
public:
	virtual $Object* clone() override;
	virtual void commit() {}
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual bool getAutoCommit() {return false;}
	virtual ::javax::sql::rowset::RowSetWarning* getRowSetWarnings() {return nullptr;}
	virtual bool getShowDeleted() {return false;}
	virtual int32_t hashCode() override;
	virtual void rollback() {}
	virtual void rollback(::java::sql::Savepoint* s) {}
	virtual void setAutoCommit(bool autoCommit) {}
	virtual void setShowDeleted(bool b) {}
	virtual $String* toString() override;
};

		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_JdbcRowSet_h_
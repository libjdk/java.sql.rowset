#ifndef _javax_sql_rowset_RowSetWarning_h_
#define _javax_sql_rowset_RowSetWarning_h_
//$ class javax.sql.rowset.RowSetWarning
//$ extends java.sql.SQLException

#include <java/sql/SQLException.h>

namespace javax {
	namespace sql {
		namespace rowset {

class $import RowSetWarning : public ::java::sql::SQLException {
	$class(RowSetWarning, $NO_CLASS_INIT, ::java::sql::SQLException)
public:
	RowSetWarning();
	void init$($String* reason);
	void init$();
	void init$($String* reason, $String* SQLState);
	void init$($String* reason, $String* SQLState, int32_t vendorCode);
	virtual ::javax::sql::rowset::RowSetWarning* getNextWarning();
	virtual void setNextWarning(::javax::sql::rowset::RowSetWarning* warning);
	static const int64_t serialVersionUID = (int64_t)0x5CAE34448B2F1AA6;
	RowSetWarning(const RowSetWarning& e);
	virtual void throw$() override;
	inline RowSetWarning* operator ->() {
		return (RowSetWarning*)throwing$;
	}
};

		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_RowSetWarning_h_
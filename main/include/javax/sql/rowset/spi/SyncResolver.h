#ifndef _javax_sql_rowset_spi_SyncResolver_h_
#define _javax_sql_rowset_spi_SyncResolver_h_
//$ interface javax.sql.rowset.spi.SyncResolver
//$ extends javax.sql.RowSet

#include <javax/sql/RowSet.h>

#pragma push_macro("DELETE_ROW_CONFLICT")
#undef DELETE_ROW_CONFLICT
#pragma push_macro("INSERT_ROW_CONFLICT")
#undef INSERT_ROW_CONFLICT
#pragma push_macro("NO_ROW_CONFLICT")
#undef NO_ROW_CONFLICT
#pragma push_macro("UPDATE_ROW_CONFLICT")
#undef UPDATE_ROW_CONFLICT

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

class $import SyncResolver : public ::javax::sql::RowSet {
	$interface(SyncResolver, $NO_CLASS_INIT, ::javax::sql::RowSet)
public:
	virtual $Object* getConflictValue(int32_t index) {return nullptr;}
	virtual $Object* getConflictValue($String* columnName) {return nullptr;}
	virtual int32_t getStatus() {return 0;}
	virtual bool nextConflict() {return false;}
	virtual bool previousConflict() {return false;}
	virtual void setResolvedValue(int32_t index, Object$* obj) {}
	virtual void setResolvedValue($String* columnName, Object$* obj) {}
	static const int32_t UPDATE_ROW_CONFLICT = 0;
	static const int32_t DELETE_ROW_CONFLICT = 1;
	static const int32_t INSERT_ROW_CONFLICT = 2;
	static const int32_t NO_ROW_CONFLICT = 3;
};

			} // spi
		} // rowset
	} // sql
} // javax

#pragma pop_macro("DELETE_ROW_CONFLICT")
#pragma pop_macro("INSERT_ROW_CONFLICT")
#pragma pop_macro("NO_ROW_CONFLICT")
#pragma pop_macro("UPDATE_ROW_CONFLICT")

#endif // _javax_sql_rowset_spi_SyncResolver_h_
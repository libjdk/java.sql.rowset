#ifndef _javax_sql_rowset_spi_SyncProvider_h_
#define _javax_sql_rowset_spi_SyncProvider_h_
//$ class javax.sql.rowset.spi.SyncProvider
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("DATASOURCE_DB_LOCK")
#undef DATASOURCE_DB_LOCK
#pragma push_macro("DATASOURCE_NO_LOCK")
#undef DATASOURCE_NO_LOCK
#pragma push_macro("DATASOURCE_ROW_LOCK")
#undef DATASOURCE_ROW_LOCK
#pragma push_macro("DATASOURCE_TABLE_LOCK")
#undef DATASOURCE_TABLE_LOCK
#pragma push_macro("GRADE_CHECK_ALL_AT_COMMIT")
#undef GRADE_CHECK_ALL_AT_COMMIT
#pragma push_macro("GRADE_CHECK_MODIFIED_AT_COMMIT")
#undef GRADE_CHECK_MODIFIED_AT_COMMIT
#pragma push_macro("GRADE_LOCK_WHEN_LOADED")
#undef GRADE_LOCK_WHEN_LOADED
#pragma push_macro("GRADE_LOCK_WHEN_MODIFIED")
#undef GRADE_LOCK_WHEN_MODIFIED
#pragma push_macro("GRADE_NONE")
#undef GRADE_NONE
#pragma push_macro("NONUPDATABLE_VIEW_SYNC")
#undef NONUPDATABLE_VIEW_SYNC
#pragma push_macro("UPDATABLE_VIEW_SYNC")
#undef UPDATABLE_VIEW_SYNC

namespace javax {
	namespace sql {
		class RowSetReader;
		class RowSetWriter;
	}
}

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

class $import SyncProvider : public ::java::lang::Object {
	$class(SyncProvider, $NO_CLASS_INIT, ::java::lang::Object)
public:
	SyncProvider();
	void init$();
	virtual int32_t getDataSourceLock() {return 0;}
	virtual int32_t getProviderGrade() {return 0;}
	virtual $String* getProviderID() {return nullptr;}
	virtual ::javax::sql::RowSetReader* getRowSetReader() {return nullptr;}
	virtual ::javax::sql::RowSetWriter* getRowSetWriter() {return nullptr;}
	virtual $String* getVendor() {return nullptr;}
	virtual $String* getVersion() {return nullptr;}
	virtual void setDataSourceLock(int32_t datasource_lock) {}
	virtual int32_t supportsUpdatableView() {return 0;}
	static const int32_t GRADE_NONE = 1;
	static const int32_t GRADE_CHECK_MODIFIED_AT_COMMIT = 2;
	static const int32_t GRADE_CHECK_ALL_AT_COMMIT = 3;
	static const int32_t GRADE_LOCK_WHEN_MODIFIED = 4;
	static const int32_t GRADE_LOCK_WHEN_LOADED = 5;
	static const int32_t DATASOURCE_NO_LOCK = 1;
	static const int32_t DATASOURCE_ROW_LOCK = 2;
	static const int32_t DATASOURCE_TABLE_LOCK = 3;
	static const int32_t DATASOURCE_DB_LOCK = 4;
	static const int32_t UPDATABLE_VIEW_SYNC = 5;
	static const int32_t NONUPDATABLE_VIEW_SYNC = 6;
};

			} // spi
		} // rowset
	} // sql
} // javax

#pragma pop_macro("DATASOURCE_DB_LOCK")
#pragma pop_macro("DATASOURCE_NO_LOCK")
#pragma pop_macro("DATASOURCE_ROW_LOCK")
#pragma pop_macro("DATASOURCE_TABLE_LOCK")
#pragma pop_macro("GRADE_CHECK_ALL_AT_COMMIT")
#pragma pop_macro("GRADE_CHECK_MODIFIED_AT_COMMIT")
#pragma pop_macro("GRADE_LOCK_WHEN_LOADED")
#pragma pop_macro("GRADE_LOCK_WHEN_MODIFIED")
#pragma pop_macro("GRADE_NONE")
#pragma pop_macro("NONUPDATABLE_VIEW_SYNC")
#pragma pop_macro("UPDATABLE_VIEW_SYNC")

#endif // _javax_sql_rowset_spi_SyncProvider_h_
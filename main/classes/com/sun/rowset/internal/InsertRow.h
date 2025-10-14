#ifndef _com_sun_rowset_internal_InsertRow_h_
#define _com_sun_rowset_internal_InsertRow_h_
//$ class com.sun.rowset.internal.InsertRow
//$ extends com.sun.rowset.internal.BaseRow

#include <com/sun/rowset/internal/BaseRow.h>

namespace com {
	namespace sun {
		namespace rowset {
			class JdbcRowSetResourceBundle;
		}
	}
}
namespace java {
	namespace io {
		class ObjectInputStream;
	}
}
namespace java {
	namespace util {
		class BitSet;
	}
}
namespace javax {
	namespace sql {
		class RowSetMetaData;
	}
}

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

class InsertRow : public ::com::sun::rowset::internal::BaseRow {
	$class(InsertRow, $NO_CLASS_INIT, ::com::sun::rowset::internal::BaseRow)
public:
	InsertRow();
	void init$(int32_t numCols);
	virtual $Object* getColumnObject(int32_t idx) override;
	virtual void initInsertRow();
	virtual bool isCompleteRow(::javax::sql::RowSetMetaData* RowSetMD);
	virtual void markColInserted(int32_t col);
	void readObject(::java::io::ObjectInputStream* ois);
	virtual void setColumnObject(int32_t idx, Object$* val) override;
	::java::util::BitSet* colsInserted = nullptr;
	int32_t cols = 0;
	::com::sun::rowset::JdbcRowSetResourceBundle* resBundle = nullptr;
	static const int64_t serialVersionUID = (int64_t)0x0ECB8BFD98630D60;
};

			} // internal
		} // rowset
	} // sun
} // com

#endif // _com_sun_rowset_internal_InsertRow_h_
#ifndef _com_sun_rowset_internal_Row_h_
#define _com_sun_rowset_internal_Row_h_
//$ class com.sun.rowset.internal.Row
//$ extends com.sun.rowset.internal.BaseRow

#include <com/sun/rowset/internal/BaseRow.h>
#include <java/lang/Array.h>

namespace java {
	namespace util {
		class BitSet;
	}
}

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

class Row : public ::com::sun::rowset::internal::BaseRow {
	$class(Row, $NO_CLASS_INIT, ::com::sun::rowset::internal::BaseRow)
public:
	Row();
	void init$(int32_t numCols);
	void init$(int32_t numCols, $ObjectArray* vals);
	virtual void clearDeleted();
	virtual void clearInserted();
	virtual void clearUpdated();
	virtual bool getColUpdated(int32_t idx);
	virtual $Object* getColumnObject(int32_t columnIndex) override;
	virtual ::com::sun::rowset::internal::BaseRow* getCurrentRow();
	virtual bool getDeleted();
	virtual bool getInserted();
	virtual bool getUpdated();
	virtual void initColumnObject(int32_t idx, Object$* val);
	virtual void moveCurrentToOrig();
	void setColUpdated(int32_t idx);
	virtual void setColumnObject(int32_t idx, Object$* val) override;
	virtual void setDeleted();
	virtual void setInserted();
	virtual void setUpdated();
	static const int64_t serialVersionUID = (int64_t)0x460D990BA30B5C4A;
	$ObjectArray* currentVals = nullptr;
	::java::util::BitSet* colsChanged = nullptr;
	bool deleted = false;
	bool updated = false;
	bool inserted = false;
	int32_t numCols = 0;
};

			} // internal
		} // rowset
	} // sun
} // com

#endif // _com_sun_rowset_internal_Row_h_
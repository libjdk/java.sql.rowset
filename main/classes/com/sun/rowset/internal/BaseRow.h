#ifndef _com_sun_rowset_internal_BaseRow_h_
#define _com_sun_rowset_internal_BaseRow_h_
//$ class com.sun.rowset.internal.BaseRow
//$ extends java.io.Serializable
//$ implements java.lang.Cloneable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>
#include <java/lang/Cloneable.h>

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

class BaseRow : public ::java::io::Serializable, public ::java::lang::Cloneable {
	$class(BaseRow, $NO_CLASS_INIT, ::java::io::Serializable, ::java::lang::Cloneable)
public:
	BaseRow();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$();
	virtual $Object* getColumnObject(int32_t idx) {return nullptr;}
	virtual $ObjectArray* getOrigRow();
	virtual void setColumnObject(int32_t idx, Object$* obj) {}
	virtual $String* toString() override;
	static const int64_t serialVersionUID = (int64_t)0x399EEA4D2384060E;
	$ObjectArray* origVals = nullptr;
};

			} // internal
		} // rowset
	} // sun
} // com

#endif // _com_sun_rowset_internal_BaseRow_h_
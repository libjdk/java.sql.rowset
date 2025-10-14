#ifndef _com_sun_rowset_CachedRowSetImpl$1_h_
#define _com_sun_rowset_CachedRowSetImpl$1_h_
//$ class com.sun.rowset.CachedRowSetImpl$1
//$ extends java.security.PrivilegedExceptionAction

#include <java/security/PrivilegedExceptionAction.h>

namespace com {
	namespace sun {
		namespace rowset {
			class CachedRowSetImpl;
		}
	}
}

namespace com {
	namespace sun {
		namespace rowset {

class CachedRowSetImpl$1 : public ::java::security::PrivilegedExceptionAction {
	$class(CachedRowSetImpl$1, $NO_CLASS_INIT, ::java::security::PrivilegedExceptionAction)
public:
	CachedRowSetImpl$1();
	void init$(::com::sun::rowset::CachedRowSetImpl* this$0);
	virtual $Object* run() override;
	::com::sun::rowset::CachedRowSetImpl* this$0 = nullptr;
};

		} // rowset
	} // sun
} // com

#endif // _com_sun_rowset_CachedRowSetImpl$1_h_
#ifndef _com_sun_rowset_JdbcRowSetResourceBundle_h_
#define _com_sun_rowset_JdbcRowSetResourceBundle_h_
//$ class com.sun.rowset.JdbcRowSetResourceBundle
//$ extends java.io.Serializable

#include <java/io/Serializable.h>

#pragma push_macro("DOT")
#undef DOT
#pragma push_macro("PATH")
#undef PATH
#pragma push_macro("PROPERTIES")
#undef PROPERTIES
#pragma push_macro("SLASH")
#undef SLASH
#pragma push_macro("UNDERSCORE")
#undef UNDERSCORE

namespace java {
	namespace util {
		class Enumeration;
		class PropertyResourceBundle;
	}
}

namespace com {
	namespace sun {
		namespace rowset {

class JdbcRowSetResourceBundle : public ::java::io::Serializable {
	$class(JdbcRowSetResourceBundle, 0, ::java::io::Serializable)
public:
	JdbcRowSetResourceBundle();
	void init$();
	static ::com::sun::rowset::JdbcRowSetResourceBundle* getJdbcRowSetResourceBundle();
	virtual ::java::util::Enumeration* getKeys();
	virtual $Object* handleGetObject($String* key);
	static $String* fileName;
	::java::util::PropertyResourceBundle* propResBundle = nullptr;
	static $volatile(::com::sun::rowset::JdbcRowSetResourceBundle*) jpResBundle;
	static $String* PROPERTIES;
	static $String* UNDERSCORE;
	static $String* DOT;
	static $String* SLASH;
	static $String* PATH;
	static const int64_t serialVersionUID = (int64_t)0x060DB107DB34BC52;
};

		} // rowset
	} // sun
} // com

#pragma pop_macro("DOT")
#pragma pop_macro("PATH")
#pragma pop_macro("PROPERTIES")
#pragma pop_macro("SLASH")
#pragma pop_macro("UNDERSCORE")

#endif // _com_sun_rowset_JdbcRowSetResourceBundle_h_
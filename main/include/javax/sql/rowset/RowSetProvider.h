#ifndef _javax_sql_rowset_RowSetProvider_h_
#define _javax_sql_rowset_RowSetProvider_h_
//$ class javax.sql.rowset.RowSetProvider
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("ROWSET_DEBUG_PROPERTY")
#undef ROWSET_DEBUG_PROPERTY
#pragma push_macro("ROWSET_FACTORY_IMPL")
#undef ROWSET_FACTORY_IMPL
#pragma push_macro("ROWSET_FACTORY_NAME")
#undef ROWSET_FACTORY_NAME

namespace java {
	namespace lang {
		class ClassLoader;
	}
}
namespace javax {
	namespace sql {
		namespace rowset {
			class RowSetFactory;
		}
	}
}

namespace javax {
	namespace sql {
		namespace rowset {

class $import RowSetProvider : public ::java::lang::Object {
	$class(RowSetProvider, 0, ::java::lang::Object)
public:
	RowSetProvider();
	void init$();
	static ::javax::sql::rowset::RowSetFactory* defaultRowSetFactory();
	static ::java::lang::ClassLoader* getContextClassLoader();
	static $Class* getFactoryClass($String* factoryClassName, ::java::lang::ClassLoader* cl, bool doFallback);
	static $String* getSystemProperty($String* propName);
	static ::javax::sql::rowset::RowSetFactory* loadViaServiceLoader();
	static ::javax::sql::rowset::RowSetFactory* newFactory();
	static ::javax::sql::rowset::RowSetFactory* newFactory($String* factoryClassName, ::java::lang::ClassLoader* cl);
	static void trace($String* msg);
	static $String* ROWSET_DEBUG_PROPERTY;
	static $String* ROWSET_FACTORY_IMPL;
	static $String* ROWSET_FACTORY_NAME;
	static bool debug;
};

		} // rowset
	} // sql
} // javax

#pragma pop_macro("ROWSET_DEBUG_PROPERTY")
#pragma pop_macro("ROWSET_FACTORY_IMPL")
#pragma pop_macro("ROWSET_FACTORY_NAME")

#endif // _javax_sql_rowset_RowSetProvider_h_
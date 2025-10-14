#ifndef _javax_sql_rowset_spi_SyncFactory_h_
#define _javax_sql_rowset_spi_SyncFactory_h_
//$ class javax.sql.rowset.spi.SyncFactory
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("ROWSET_PROPERTIES")
#undef ROWSET_PROPERTIES
#pragma push_macro("ROWSET_SYNC_PROVIDER")
#undef ROWSET_SYNC_PROVIDER
#pragma push_macro("ROWSET_SYNC_PROVIDER_VERSION")
#undef ROWSET_SYNC_PROVIDER_VERSION
#pragma push_macro("ROWSET_SYNC_VENDOR")
#undef ROWSET_SYNC_VENDOR
#pragma push_macro("SET_SYNCFACTORY_PERMISSION")
#undef SET_SYNCFACTORY_PERMISSION

namespace java {
	namespace lang {
		class Void;
	}
}
namespace java {
	namespace sql {
		class SQLPermission;
	}
}
namespace java {
	namespace util {
		class Enumeration;
		class Hashtable;
		class Properties;
	}
}
namespace java {
	namespace util {
		namespace logging {
			class Level;
			class Logger;
		}
	}
}
namespace javax {
	namespace naming {
		class Context;
		class NamingEnumeration;
	}
}
namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {
				class ProviderImpl;
				class SyncProvider;
			}
		}
	}
}

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

class $export SyncFactory : public ::java::lang::Object {
	$class(SyncFactory, 0, ::java::lang::Object)
public:
	SyncFactory();
	void init$();
	static void enumerateBindings(::javax::naming::NamingEnumeration* bindings, ::java::util::Properties* properties);
	static ::javax::sql::rowset::spi::SyncProvider* getInstance($String* providerID);
	static ::java::util::logging::Logger* getLogger();
	static $StringArray* getPropertyNames(bool append);
	static $StringArray* getPropertyNames(bool append, $String* propertyIndex);
	static ::java::util::Enumeration* getRegisteredProviders();
	static ::javax::sql::rowset::spi::SyncFactory* getSyncFactory();
	static void initJNDIContext();
	static void initMapIfNecessary();
	static ::java::lang::Void* lambda$initMapIfNecessary$0(::java::util::Properties* properties);
	static ::java::util::Properties* parseJNDIContext();
	static void parseProperties(::java::util::Properties* p);
	static void registerProvider($String* providerID);
	static void setJNDIContext(::javax::naming::Context* ctx);
	static void setLogger(::java::util::logging::Logger* logger);
	static void setLogger(::java::util::logging::Logger* logger, ::java::util::logging::Level* level);
	static void showImpl(::javax::sql::rowset::spi::ProviderImpl* impl);
	static void unregisterProvider($String* providerID);
	static $String* ROWSET_SYNC_PROVIDER;
	static $String* ROWSET_SYNC_VENDOR;
	static $String* ROWSET_SYNC_PROVIDER_VERSION;
	static $String* ROWSET_PROPERTIES;
	static ::java::sql::SQLPermission* SET_SYNCFACTORY_PERMISSION;
	static ::javax::naming::Context* ic;
	static $volatile(::java::util::logging::Logger*) rsLogger;
	static ::java::util::Hashtable* implementations;
	static $String* colon;
	static $String* strFileSep;
	static bool debug;
	static int32_t providerImplIndex;
	static bool lazyJNDICtxRefresh;
};

			} // spi
		} // rowset
	} // sql
} // javax

#pragma pop_macro("ROWSET_PROPERTIES")
#pragma pop_macro("ROWSET_SYNC_PROVIDER")
#pragma pop_macro("ROWSET_SYNC_PROVIDER_VERSION")
#pragma pop_macro("ROWSET_SYNC_VENDOR")
#pragma pop_macro("SET_SYNCFACTORY_PERMISSION")

#endif // _javax_sql_rowset_spi_SyncFactory_h_
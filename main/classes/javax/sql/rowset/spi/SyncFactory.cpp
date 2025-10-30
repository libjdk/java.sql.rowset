#include <javax/sql/rowset/spi/SyncFactory.h>

#include <com/sun/rowset/providers/RIOptimisticProvider.h>
#include <java/io/FileInputStream.h>
#include <java/io/FileNotFoundException.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/Module.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/SecurityException.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessControlException.h>
#include <java/security/AccessController.h>
#include <java/security/BasicPermission.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/sql/SQLPermission.h>
#include <java/util/Enumeration.h>
#include <java/util/Hashtable.h>
#include <java/util/Properties.h>
#include <java/util/PropertyPermission.h>
#include <java/util/StringTokenizer.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/Logger.h>
#include <javax/naming/Binding.h>
#include <javax/naming/Context.h>
#include <javax/naming/NamingEnumeration.h>
#include <javax/naming/NamingException.h>
#include <javax/naming/NotContextException.h>
#include <javax/sql/rowset/spi/ProviderImpl.h>
#include <javax/sql/rowset/spi/SyncFactory$1.h>
#include <javax/sql/rowset/spi/SyncFactory$2.h>
#include <javax/sql/rowset/spi/SyncFactory$SyncFactoryHolder.h>
#include <javax/sql/rowset/spi/SyncFactoryException.h>
#include <javax/sql/rowset/spi/SyncProvider.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <jcpp.h>

#undef ROWSET_PROPERTIES
#undef ROWSET_SYNC_PROVIDER
#undef ROWSET_SYNC_PROVIDER_VERSION
#undef ROWSET_SYNC_VENDOR
#undef SET_SYNCFACTORY_PERMISSION

using $PermissionArray = $Array<::java::security::Permission>;
using $RIOptimisticProvider = ::com::sun::rowset::providers::RIOptimisticProvider;
using $FileInputStream = ::java::io::FileInputStream;
using $FileNotFoundException = ::java::io::FileNotFoundException;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InstantiationException = ::java::lang::InstantiationException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NullPointerException = ::java::lang::NullPointerException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityException = ::java::lang::SecurityException;
using $SecurityManager = ::java::lang::SecurityManager;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessControlException = ::java::security::AccessControlException;
using $AccessController = ::java::security::AccessController;
using $BasicPermission = ::java::security::BasicPermission;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $SQLPermission = ::java::sql::SQLPermission;
using $Enumeration = ::java::util::Enumeration;
using $Hashtable = ::java::util::Hashtable;
using $Properties = ::java::util::Properties;
using $PropertyPermission = ::java::util::PropertyPermission;
using $StringTokenizer = ::java::util::StringTokenizer;
using $Level = ::java::util::logging::Level;
using $Logger = ::java::util::logging::Logger;
using $Binding = ::javax::naming::Binding;
using $Context = ::javax::naming::Context;
using $NameClassPair = ::javax::naming::NameClassPair;
using $NamingEnumeration = ::javax::naming::NamingEnumeration;
using $NamingException = ::javax::naming::NamingException;
using $NotContextException = ::javax::naming::NotContextException;
using $ProviderImpl = ::javax::sql::rowset::spi::ProviderImpl;
using $SyncFactory$1 = ::javax::sql::rowset::spi::SyncFactory$1;
using $SyncFactory$2 = ::javax::sql::rowset::spi::SyncFactory$2;
using $SyncFactory$SyncFactoryHolder = ::javax::sql::rowset::spi::SyncFactory$SyncFactoryHolder;
using $SyncFactoryException = ::javax::sql::rowset::spi::SyncFactoryException;
using $SyncProvider = ::javax::sql::rowset::spi::SyncProvider;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

class SyncFactory$$Lambda$lambda$initMapIfNecessary$0 : public $PrivilegedExceptionAction {
	$class(SyncFactory$$Lambda$lambda$initMapIfNecessary$0, $NO_CLASS_INIT, $PrivilegedExceptionAction)
public:
	void init$($Properties* properties) {
		$set(this, properties, properties);
	}
	virtual $Object* run() override {
		 return $of(SyncFactory::lambda$initMapIfNecessary$0(properties));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SyncFactory$$Lambda$lambda$initMapIfNecessary$0>());
	}
	$Properties* properties = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SyncFactory$$Lambda$lambda$initMapIfNecessary$0::fieldInfos[2] = {
	{"properties", "Ljava/util/Properties;", nullptr, $PUBLIC, $field(SyncFactory$$Lambda$lambda$initMapIfNecessary$0, properties)},
	{}
};
$MethodInfo SyncFactory$$Lambda$lambda$initMapIfNecessary$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/Properties;)V", nullptr, $PUBLIC, $method(static_cast<void(SyncFactory$$Lambda$lambda$initMapIfNecessary$0::*)($Properties*)>(&SyncFactory$$Lambda$lambda$initMapIfNecessary$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SyncFactory$$Lambda$lambda$initMapIfNecessary$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"javax.sql.rowset.spi.SyncFactory$$Lambda$lambda$initMapIfNecessary$0",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	fieldInfos,
	methodInfos
};
$Class* SyncFactory$$Lambda$lambda$initMapIfNecessary$0::load$($String* name, bool initialize) {
	$loadClass(SyncFactory$$Lambda$lambda$initMapIfNecessary$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SyncFactory$$Lambda$lambda$initMapIfNecessary$0::class$ = nullptr;

$FieldInfo _SyncFactory_FieldInfo_[] = {
	{"ROWSET_SYNC_PROVIDER", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(SyncFactory, ROWSET_SYNC_PROVIDER)},
	{"ROWSET_SYNC_VENDOR", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(SyncFactory, ROWSET_SYNC_VENDOR)},
	{"ROWSET_SYNC_PROVIDER_VERSION", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(SyncFactory, ROWSET_SYNC_PROVIDER_VERSION)},
	{"ROWSET_PROPERTIES", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(SyncFactory, ROWSET_PROPERTIES)},
	{"SET_SYNCFACTORY_PERMISSION", "Ljava/sql/SQLPermission;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(SyncFactory, SET_SYNCFACTORY_PERMISSION)},
	{"ic", "Ljavax/naming/Context;", nullptr, $PRIVATE | $STATIC, $staticField(SyncFactory, ic)},
	{"rsLogger", "Ljava/util/logging/Logger;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(SyncFactory, rsLogger)},
	{"implementations", "Ljava/util/Hashtable;", "Ljava/util/Hashtable<Ljava/lang/String;Ljavax/sql/rowset/spi/SyncProvider;>;", $PRIVATE | $STATIC, $staticField(SyncFactory, implementations)},
	{"colon", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(SyncFactory, colon)},
	{"strFileSep", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(SyncFactory, strFileSep)},
	{"debug", "Z", nullptr, $PRIVATE | $STATIC, $staticField(SyncFactory, debug)},
	{"providerImplIndex", "I", nullptr, $PRIVATE | $STATIC, $staticField(SyncFactory, providerImplIndex)},
	{"lazyJNDICtxRefresh", "Z", nullptr, $PRIVATE | $STATIC, $staticField(SyncFactory, lazyJNDICtxRefresh)},
	{}
};

$MethodInfo _SyncFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(SyncFactory::*)()>(&SyncFactory::init$))},
	{"enumerateBindings", "(Ljavax/naming/NamingEnumeration;Ljava/util/Properties;)V", "(Ljavax/naming/NamingEnumeration<*>;Ljava/util/Properties;)V", $PRIVATE | $STATIC, $method(static_cast<void(*)($NamingEnumeration*,$Properties*)>(&SyncFactory::enumerateBindings)), "javax.naming.NamingException"},
	{"getInstance", "(Ljava/lang/String;)Ljavax/sql/rowset/spi/SyncProvider;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$SyncProvider*(*)($String*)>(&SyncFactory::getInstance)), "javax.sql.rowset.spi.SyncFactoryException"},
	{"getLogger", "()Ljava/util/logging/Logger;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Logger*(*)()>(&SyncFactory::getLogger)), "javax.sql.rowset.spi.SyncFactoryException"},
	{"getPropertyNames", "(Z)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$StringArray*(*)(bool)>(&SyncFactory::getPropertyNames))},
	{"getPropertyNames", "(ZLjava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$StringArray*(*)(bool,$String*)>(&SyncFactory::getPropertyNames))},
	{"getRegisteredProviders", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljavax/sql/rowset/spi/SyncProvider;>;", $PUBLIC | $STATIC, $method(static_cast<$Enumeration*(*)()>(&SyncFactory::getRegisteredProviders)), "javax.sql.rowset.spi.SyncFactoryException"},
	{"getSyncFactory", "()Ljavax/sql/rowset/spi/SyncFactory;", nullptr, $PUBLIC | $STATIC, $method(static_cast<SyncFactory*(*)()>(&SyncFactory::getSyncFactory))},
	{"initJNDIContext", "()V", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $method(static_cast<void(*)()>(&SyncFactory::initJNDIContext)), "javax.sql.rowset.spi.SyncFactoryException"},
	{"initMapIfNecessary", "()V", nullptr, $PRIVATE | $STATIC | $SYNCHRONIZED, $method(static_cast<void(*)()>(&SyncFactory::initMapIfNecessary)), "javax.sql.rowset.spi.SyncFactoryException"},
	{"lambda$initMapIfNecessary$0", "(Ljava/util/Properties;)Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Void*(*)($Properties*)>(&SyncFactory::lambda$initMapIfNecessary$0)), "java.lang.Exception"},
	{"parseJNDIContext", "()Ljava/util/Properties;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Properties*(*)()>(&SyncFactory::parseJNDIContext)), "javax.naming.NamingException"},
	{"parseProperties", "(Ljava/util/Properties;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($Properties*)>(&SyncFactory::parseProperties))},
	{"registerProvider", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $method(static_cast<void(*)($String*)>(&SyncFactory::registerProvider)), "javax.sql.rowset.spi.SyncFactoryException"},
	{"setJNDIContext", "(Ljavax/naming/Context;)V", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $method(static_cast<void(*)($Context*)>(&SyncFactory::setJNDIContext)), "javax.sql.rowset.spi.SyncFactoryException"},
	{"setLogger", "(Ljava/util/logging/Logger;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($Logger*)>(&SyncFactory::setLogger))},
	{"setLogger", "(Ljava/util/logging/Logger;Ljava/util/logging/Level;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($Logger*,$Level*)>(&SyncFactory::setLogger))},
	{"showImpl", "(Ljavax/sql/rowset/spi/ProviderImpl;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($ProviderImpl*)>(&SyncFactory::showImpl))},
	{"unregisterProvider", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $method(static_cast<void(*)($String*)>(&SyncFactory::unregisterProvider)), "javax.sql.rowset.spi.SyncFactoryException"},
	{}
};

$InnerClassInfo _SyncFactory_InnerClassesInfo_[] = {
	{"javax.sql.rowset.spi.SyncFactory$SyncFactoryHolder", "javax.sql.rowset.spi.SyncFactory", "SyncFactoryHolder", $PRIVATE | $STATIC},
	{"javax.sql.rowset.spi.SyncFactory$2", nullptr, nullptr, 0},
	{"javax.sql.rowset.spi.SyncFactory$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _SyncFactory_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.sql.rowset.spi.SyncFactory",
	"java.lang.Object",
	nullptr,
	_SyncFactory_FieldInfo_,
	_SyncFactory_MethodInfo_,
	nullptr,
	nullptr,
	_SyncFactory_InnerClassesInfo_,
	nullptr,
	nullptr,
	"javax.sql.rowset.spi.SyncFactory$SyncFactoryHolder,javax.sql.rowset.spi.SyncFactory$2,javax.sql.rowset.spi.SyncFactory$1"
};

$Object* allocate$SyncFactory($Class* clazz) {
	return $of($alloc(SyncFactory));
}

$String* SyncFactory::ROWSET_SYNC_PROVIDER = nullptr;
$String* SyncFactory::ROWSET_SYNC_VENDOR = nullptr;
$String* SyncFactory::ROWSET_SYNC_PROVIDER_VERSION = nullptr;
$String* SyncFactory::ROWSET_PROPERTIES = nullptr;
$SQLPermission* SyncFactory::SET_SYNCFACTORY_PERMISSION = nullptr;
$Context* SyncFactory::ic = nullptr;
$volatile($Logger*) SyncFactory::rsLogger = nullptr;
$Hashtable* SyncFactory::implementations = nullptr;
$String* SyncFactory::colon = nullptr;
$String* SyncFactory::strFileSep = nullptr;
bool SyncFactory::debug = false;
int32_t SyncFactory::providerImplIndex = 0;
bool SyncFactory::lazyJNDICtxRefresh = false;

void SyncFactory::init$() {
}

void SyncFactory::registerProvider($String* providerID) {
	$load(SyncFactory);
	$synchronized(class$) {
		$init(SyncFactory);
		$var($ProviderImpl, impl, $new($ProviderImpl));
		impl->setClassname(providerID);
		initMapIfNecessary();
		$nc(SyncFactory::implementations)->put(providerID, impl);
	}
}

SyncFactory* SyncFactory::getSyncFactory() {
	$init(SyncFactory);
	$init($SyncFactory$SyncFactoryHolder);
	return $SyncFactory$SyncFactoryHolder::factory;
}

void SyncFactory::unregisterProvider($String* providerID) {
	$load(SyncFactory);
	$synchronized(class$) {
		$init(SyncFactory);
		initMapIfNecessary();
		if ($nc(SyncFactory::implementations)->containsKey(providerID)) {
			$nc(SyncFactory::implementations)->remove(providerID);
		}
	}
}

void SyncFactory::initMapIfNecessary() {
	$load(SyncFactory);
	$synchronized(class$) {
		$init(SyncFactory);
		$useLocalCurrentObjectStackCache();
		$beforeCallerSensitive();
		$var($Properties, properties, $new($Properties));
		if (SyncFactory::implementations == nullptr) {
			$assignStatic(SyncFactory::implementations, $new($Hashtable));
			try {
				$var($String, strRowsetProperties, nullptr);
				try {
					$var($PrivilegedAction, var$0, static_cast<$PrivilegedAction*>($new($SyncFactory$1)));
					$assign(strRowsetProperties, $cast($String, $AccessController::doPrivileged(var$0, ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>($$new($PropertyPermission, "rowset.properties"_s, "read"_s))}))));
				} catch ($Exception& ex) {
					$nc($System::out)->println($$str({"errorget rowset.properties: "_s, ex}));
					$assign(strRowsetProperties, nullptr);
				}
				if (strRowsetProperties != nullptr) {
					$assignStatic(SyncFactory::ROWSET_PROPERTIES, strRowsetProperties);
					{
						$var($FileInputStream, fis, $new($FileInputStream, SyncFactory::ROWSET_PROPERTIES));
						{
							$var($Throwable, var$1, nullptr);
							try {
								try {
									properties->load(static_cast<$InputStream*>(fis));
								} catch ($Throwable& t$) {
									try {
										fis->close();
									} catch ($Throwable& x2) {
										t$->addSuppressed(x2);
									}
									$throw(t$);
								}
							} catch ($Throwable& var$2) {
								$assign(var$1, var$2);
							} /*finally*/ {
								fis->close();
							}
							if (var$1 != nullptr) {
								$throw(var$1);
							}
						}
					}
					parseProperties(properties);
				}
				$assignStatic(SyncFactory::ROWSET_PROPERTIES, $str({"javax"_s, SyncFactory::strFileSep, "sql"_s, SyncFactory::strFileSep, "rowset"_s, SyncFactory::strFileSep, "rowset.properties"_s}));
				try {
					$AccessController::doPrivileged(static_cast<$PrivilegedExceptionAction*>($$new(SyncFactory$$Lambda$lambda$initMapIfNecessary$0, properties)));
				} catch ($PrivilegedActionException& ex) {
					$var($Throwable, e, ex->getException());
					if ($instanceOf($SyncFactoryException, e)) {
						$throw($cast($SyncFactoryException, e));
					} else {
						$var($SyncFactoryException, sfe, $new($SyncFactoryException));
						sfe->initCause($(ex->getException()));
						$throw(sfe);
					}
				}
				parseProperties(properties);
			} catch ($FileNotFoundException& e) {
				$throwNew($SyncFactoryException, $$str({"Cannot locate properties file: "_s, e}));
			} catch ($IOException& e) {
				$throwNew($SyncFactoryException, $$str({"IOException: "_s, e}));
			}
			properties->clear();
			$var($String, providerImpls, nullptr);
			try {
				$var($PrivilegedAction, var$3, static_cast<$PrivilegedAction*>($new($SyncFactory$2)));
				$assign(providerImpls, $cast($String, $AccessController::doPrivileged(var$3, ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>($$new($PropertyPermission, SyncFactory::ROWSET_SYNC_PROVIDER, "read"_s))}))));
			} catch ($Exception& ex) {
				$assign(providerImpls, nullptr);
			}
			if (providerImpls != nullptr) {
				int32_t i = 0;
				if (providerImpls->indexOf(SyncFactory::colon) > 0) {
					$var($StringTokenizer, tokenizer, $new($StringTokenizer, providerImpls, SyncFactory::colon));
					while (tokenizer->hasMoreElements()) {
						properties->put($$str({SyncFactory::ROWSET_SYNC_PROVIDER, "."_s, $$str(i)}), $(tokenizer->nextToken()));
						++i;
					}
				} else {
					properties->put(SyncFactory::ROWSET_SYNC_PROVIDER, providerImpls);
				}
				parseProperties(properties);
			}
		}
	}
}

void SyncFactory::parseProperties($Properties* p) {
	$init(SyncFactory);
	$useLocalCurrentObjectStackCache();
	$var($ProviderImpl, impl, nullptr);
	$var($String, key, nullptr);
	$var($StringArray, propertyNames, nullptr);
	{
		$var($Enumeration, e, $nc(p)->propertyNames());
		for (; $nc(e)->hasMoreElements();) {
			$var($String, str, $cast($String, e->nextElement()));
			int32_t w = $nc(str)->length();
			if (str->startsWith(SyncFactory::ROWSET_SYNC_PROVIDER)) {
				$assign(impl, $new($ProviderImpl));
				impl->setIndex(SyncFactory::providerImplIndex++);
				if (w == $nc((SyncFactory::ROWSET_SYNC_PROVIDER))->length()) {
					$assign(propertyNames, getPropertyNames(false));
				} else {
					$assign(propertyNames, getPropertyNames(true, $(str->substring(w - 1))));
				}
				$assign(key, p->getProperty($nc(propertyNames)->get(0)));
				impl->setClassname(key);
				impl->setVendor($(p->getProperty($nc(propertyNames)->get(1))));
				impl->setVersion($(p->getProperty($nc(propertyNames)->get(2))));
				$nc(SyncFactory::implementations)->put(key, impl);
			}
		}
	}
}

$StringArray* SyncFactory::getPropertyNames(bool append) {
	$init(SyncFactory);
	return getPropertyNames(append, nullptr);
}

$StringArray* SyncFactory::getPropertyNames(bool append, $String* propertyIndex) {
	$init(SyncFactory);
	$useLocalCurrentObjectStackCache();
	$var($String, dot, "."_s);
	$var($StringArray, propertyNames, $new($StringArray, {
		SyncFactory::ROWSET_SYNC_PROVIDER,
		SyncFactory::ROWSET_SYNC_VENDOR,
		SyncFactory::ROWSET_SYNC_PROVIDER_VERSION
	}));
	if (append) {
		for (int32_t i = 0; i < propertyNames->length; ++i) {
			propertyNames->set(i, $$str({propertyNames->get(i), dot, propertyIndex}));
		}
		return propertyNames;
	} else {
		return propertyNames;
	}
}

void SyncFactory::showImpl($ProviderImpl* impl) {
	$init(SyncFactory);
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println("Provider implementation:"_s);
	$nc($System::out)->println($$str({"Classname: "_s, $($nc(impl)->getClassname())}));
	$nc($System::out)->println($$str({"Vendor: "_s, $($nc(impl)->getVendor())}));
	$nc($System::out)->println($$str({"Version: "_s, $($nc(impl)->getVersion())}));
	$nc($System::out)->println($$str({"Impl index: "_s, $$str($nc(impl)->getIndex())}));
}

$SyncProvider* SyncFactory::getInstance($String* providerID) {
	$init(SyncFactory);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (providerID == nullptr) {
		$throwNew($SyncFactoryException, "The providerID cannot be null"_s);
	}
	initMapIfNecessary();
	initJNDIContext();
	$var($ProviderImpl, impl, $cast($ProviderImpl, $nc(SyncFactory::implementations)->get(providerID)));
	if (impl == nullptr) {
		return $new($RIOptimisticProvider);
	}
	try {
		$ReflectUtil::checkPackageAccess(providerID);
	} catch ($AccessControlException& e) {
		$var($SyncFactoryException, sfe, $new($SyncFactoryException));
		sfe->initCause(e);
		$throw(sfe);
	}
	$Class* c = nullptr;
	try {
		$var($ClassLoader, cl, $($Thread::currentThread())->getContextClassLoader());
		c = $Class::forName(providerID, true, cl);
		$var($Object, result, $nc(c)->newInstance());
		return $cast($SyncProvider, result);
	} catch ($IllegalAccessException& e) {
		$throwNew($SyncFactoryException, $$str({"IllegalAccessException: "_s, $(e->getMessage())}));
	} catch ($InstantiationException& e) {
		$throwNew($SyncFactoryException, $$str({"IllegalAccessException: "_s, $(e->getMessage())}));
	} catch ($ClassNotFoundException& e) {
		$throwNew($SyncFactoryException, $$str({"IllegalAccessException: "_s, $(e->getMessage())}));
	}
	$shouldNotReachHere();
}

$Enumeration* SyncFactory::getRegisteredProviders() {
	$init(SyncFactory);
	initMapIfNecessary();
	return $nc(SyncFactory::implementations)->elements();
}

void SyncFactory::setLogger($Logger* logger) {
	$init(SyncFactory);
	$var($SecurityManager, sec, $System::getSecurityManager());
	if (sec != nullptr) {
		sec->checkPermission(SyncFactory::SET_SYNCFACTORY_PERMISSION);
	}
	if (logger == nullptr) {
		$throwNew($NullPointerException, "You must provide a Logger"_s);
	}
	$assignStatic(SyncFactory::rsLogger, logger);
}

void SyncFactory::setLogger($Logger* logger, $Level* level) {
	$init(SyncFactory);
	$var($SecurityManager, sec, $System::getSecurityManager());
	if (sec != nullptr) {
		sec->checkPermission(SyncFactory::SET_SYNCFACTORY_PERMISSION);
	}
	if (logger == nullptr) {
		$throwNew($NullPointerException, "You must provide a Logger"_s);
	}
	$nc(logger)->setLevel(level);
	$assignStatic(SyncFactory::rsLogger, logger);
}

$Logger* SyncFactory::getLogger() {
	$init(SyncFactory);
	$var($Logger, result, SyncFactory::rsLogger);
	if (result == nullptr) {
		$throwNew($SyncFactoryException, "(SyncFactory) : No logger has been set"_s);
	}
	return result;
}

void SyncFactory::setJNDIContext($Context* ctx) {
	$load(SyncFactory);
	$synchronized(class$) {
		$init(SyncFactory);
		$var($SecurityManager, sec, $System::getSecurityManager());
		if (sec != nullptr) {
			sec->checkPermission(SyncFactory::SET_SYNCFACTORY_PERMISSION);
		}
		if (ctx == nullptr) {
			$throwNew($SyncFactoryException, "Invalid JNDI context supplied"_s);
		}
		$assignStatic(SyncFactory::ic, ctx);
	}
}

void SyncFactory::initJNDIContext() {
	$load(SyncFactory);
	$synchronized(class$) {
		$init(SyncFactory);
		$useLocalCurrentObjectStackCache();
		if ((SyncFactory::ic != nullptr) && (SyncFactory::lazyJNDICtxRefresh == false)) {
			try {
				parseProperties($(parseJNDIContext()));
				SyncFactory::lazyJNDICtxRefresh = true;
			} catch ($NamingException& e) {
				e->printStackTrace();
				$throwNew($SyncFactoryException, $$str({"SPI: NamingException: "_s, $(e->getExplanation())}));
			} catch ($Exception& e) {
				e->printStackTrace();
				$throwNew($SyncFactoryException, $$str({"SPI: Exception: "_s, $(e->getMessage())}));
			}
		}
	}
}

$Properties* SyncFactory::parseJNDIContext() {
	$init(SyncFactory);
	$useLocalCurrentObjectStackCache();
	$var($NamingEnumeration, bindings, $nc(SyncFactory::ic)->listBindings(""_s));
	$var($Properties, properties, $new($Properties));
	enumerateBindings(bindings, properties);
	return properties;
}

void SyncFactory::enumerateBindings($NamingEnumeration* bindings, $Properties* properties) {
	$init(SyncFactory);
	$useLocalCurrentObjectStackCache();
	bool syncProviderObj = false;
	try {
		$var($Binding, bd, nullptr);
		$var($Object, elementObj, nullptr);
		$var($String, element, nullptr);
		while ($nc(bindings)->hasMore()) {
			$assign(bd, $cast($Binding, bindings->next()));
			$assign(element, $nc(bd)->getName());
			$assign(elementObj, bd->getObject());
			if (!($instanceOf($Context, $($nc(SyncFactory::ic)->lookup(element))))) {
				if ($instanceOf($SyncProvider, $($nc(SyncFactory::ic)->lookup(element)))) {
					syncProviderObj = true;
				}
			}
			if (syncProviderObj) {
				$var($SyncProvider, sync, $cast($SyncProvider, elementObj));
				$nc(properties)->put(SyncFactory::ROWSET_SYNC_PROVIDER, $($nc(sync)->getProviderID()));
				syncProviderObj = false;
			}
		}
	} catch ($NotContextException& e) {
		$nc(bindings)->next();
		enumerateBindings(bindings, properties);
	}
}

$Void* SyncFactory::lambda$initMapIfNecessary$0($Properties* properties) {
	$init(SyncFactory);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($InputStream, in, $nc($(SyncFactory::class$->getModule()))->getResourceAsStream(SyncFactory::ROWSET_PROPERTIES));
	if (in == nullptr) {
		$throwNew($SyncFactoryException, $$str({"Resource "_s, SyncFactory::ROWSET_PROPERTIES, " not found"_s}));
	}
	{
		$var($InputStream, twrVar0$, in);
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$nc(properties)->load(in);
				} catch ($Throwable& t$) {
					if (twrVar0$ != nullptr) {
						try {
							twrVar0$->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				if (twrVar0$ != nullptr) {
					twrVar0$->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
	return nullptr;
}

void clinit$SyncFactory($Class* class$) {
	$assignStatic(SyncFactory::ROWSET_SYNC_PROVIDER, "rowset.provider.classname"_s);
	$assignStatic(SyncFactory::ROWSET_SYNC_VENDOR, "rowset.provider.vendor"_s);
	$assignStatic(SyncFactory::ROWSET_SYNC_PROVIDER_VERSION, "rowset.provider.version"_s);
	$assignStatic(SyncFactory::ROWSET_PROPERTIES, "rowset.properties"_s);
	$assignStatic(SyncFactory::SET_SYNCFACTORY_PERMISSION, $new($SQLPermission, "setSyncFactory"_s));
	$assignStatic(SyncFactory::colon, ":"_s);
	$assignStatic(SyncFactory::strFileSep, "/"_s);
	SyncFactory::debug = false;
	SyncFactory::providerImplIndex = 0;
	SyncFactory::lazyJNDICtxRefresh = false;
}

SyncFactory::SyncFactory() {
}

$Class* SyncFactory::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SyncFactory$$Lambda$lambda$initMapIfNecessary$0::classInfo$.name)) {
			return SyncFactory$$Lambda$lambda$initMapIfNecessary$0::load$(name, initialize);
		}
	}
	$loadClass(SyncFactory, name, initialize, &_SyncFactory_ClassInfo_, clinit$SyncFactory, allocate$SyncFactory);
	return class$;
}

$Class* SyncFactory::class$ = nullptr;

			} // spi
		} // rowset
	} // sql
} // javax
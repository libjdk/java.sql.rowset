#include <java.sql.rowset.h>

#include <java.logging.h>
#include <java.naming.h>
#include <java.sql.h>
#include <java.base.h>
#include <java.security.sasl.h>
#include <java.transaction.xa.h>
#include <java.xml.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>
#include <module-info>

#include <com/sun/rowset/CachedRowSetImpl.h>
#include <com/sun/rowset/CachedRowSetImpl$1.h>
#include <com/sun/rowset/FilteredRowSetImpl.h>
#include <com/sun/rowset/JdbcRowSetImpl.h>
#include <com/sun/rowset/JdbcRowSetResourceBundle.h>
#include <com/sun/rowset/JoinRowSetImpl.h>
#include <com/sun/rowset/RowSetFactoryImpl.h>
#include <com/sun/rowset/WebRowSetImpl.h>
#include <com/sun/rowset/internal/BaseRow.h>
#include <com/sun/rowset/internal/CachedRowSetReader.h>
#include <com/sun/rowset/internal/CachedRowSetWriter.h>
#include <com/sun/rowset/internal/InsertRow.h>
#include <com/sun/rowset/internal/Row.h>
#include <com/sun/rowset/internal/SyncResolverImpl.h>
#include <com/sun/rowset/internal/WebRowSetXmlReader.h>
#include <com/sun/rowset/internal/WebRowSetXmlWriter.h>
#include <com/sun/rowset/internal/XmlErrorHandler.h>
#include <com/sun/rowset/internal/XmlReaderContentHandler.h>
#include <com/sun/rowset/internal/XmlResolver.h>
#include <com/sun/rowset/providers/RIOptimisticProvider.h>
#include <com/sun/rowset/providers/RIXMLProvider.h>
#include <javax/sql/rowset/BaseRowSet.h>
#include <javax/sql/rowset/CachedRowSet.h>
#include <javax/sql/rowset/FilteredRowSet.h>
#include <javax/sql/rowset/JdbcRowSet.h>
#include <javax/sql/rowset/JoinRowSet.h>
#include <javax/sql/rowset/Joinable.h>
#include <javax/sql/rowset/Predicate.h>
#include <javax/sql/rowset/RowSetFactory.h>
#include <javax/sql/rowset/RowSetMetaDataImpl.h>
#include <javax/sql/rowset/RowSetMetaDataImpl$ColInfo.h>
#include <javax/sql/rowset/RowSetProvider.h>
#include <javax/sql/rowset/RowSetProvider$1.h>
#include <javax/sql/rowset/RowSetProvider$2.h>
#include <javax/sql/rowset/RowSetWarning.h>
#include <javax/sql/rowset/WebRowSet.h>
#include <javax/sql/rowset/serial/SQLInputImpl.h>
#include <javax/sql/rowset/serial/SQLOutputImpl.h>
#include <javax/sql/rowset/serial/SerialArray.h>
#include <javax/sql/rowset/serial/SerialBlob.h>
#include <javax/sql/rowset/serial/SerialClob.h>
#include <javax/sql/rowset/serial/SerialDatalink.h>
#include <javax/sql/rowset/serial/SerialException.h>
#include <javax/sql/rowset/serial/SerialJavaObject.h>
#include <javax/sql/rowset/serial/SerialRef.h>
#include <javax/sql/rowset/serial/SerialStruct.h>
#include <javax/sql/rowset/spi/ProviderImpl.h>
#include <javax/sql/rowset/spi/SyncFactory.h>
#include <javax/sql/rowset/spi/SyncFactory$1.h>
#include <javax/sql/rowset/spi/SyncFactory$2.h>
#include <javax/sql/rowset/spi/SyncFactory$SyncFactoryHolder.h>
#include <javax/sql/rowset/spi/SyncFactoryException.h>
#include <javax/sql/rowset/spi/SyncProvider.h>
#include <javax/sql/rowset/spi/SyncProviderException.h>
#include <javax/sql/rowset/spi/SyncResolver.h>
#include <javax/sql/rowset/spi/TransactionalWriter.h>
#include <javax/sql/rowset/spi/XmlReader.h>
#include <javax/sql/rowset/spi/XmlWriter.h>


#define $classEntry(name, clazz) {name, clazz::load$, $getMark(clazz)}
::java::lang::ClassEntry _java$sql$rowset_classes_[] = {
	$classEntry("com.sun.rowset.CachedRowSetImpl", ::com::sun::rowset::CachedRowSetImpl),
	$classEntry("com.sun.rowset.CachedRowSetImpl$1", ::com::sun::rowset::CachedRowSetImpl$1),
	$classEntry("com.sun.rowset.FilteredRowSetImpl", ::com::sun::rowset::FilteredRowSetImpl),
	$classEntry("com.sun.rowset.JdbcRowSetImpl", ::com::sun::rowset::JdbcRowSetImpl),
	$classEntry("com.sun.rowset.JdbcRowSetResourceBundle", ::com::sun::rowset::JdbcRowSetResourceBundle),
	$classEntry("com.sun.rowset.JoinRowSetImpl", ::com::sun::rowset::JoinRowSetImpl),
	$classEntry("com.sun.rowset.RowSetFactoryImpl", ::com::sun::rowset::RowSetFactoryImpl),
	$classEntry("com.sun.rowset.WebRowSetImpl", ::com::sun::rowset::WebRowSetImpl),
	$classEntry("com.sun.rowset.internal.BaseRow", ::com::sun::rowset::internal::BaseRow),
	$classEntry("com.sun.rowset.internal.CachedRowSetReader", ::com::sun::rowset::internal::CachedRowSetReader),
	$classEntry("com.sun.rowset.internal.CachedRowSetWriter", ::com::sun::rowset::internal::CachedRowSetWriter),
	$classEntry("com.sun.rowset.internal.InsertRow", ::com::sun::rowset::internal::InsertRow),
	$classEntry("com.sun.rowset.internal.Row", ::com::sun::rowset::internal::Row),
	$classEntry("com.sun.rowset.internal.SyncResolverImpl", ::com::sun::rowset::internal::SyncResolverImpl),
	$classEntry("com.sun.rowset.internal.WebRowSetXmlReader", ::com::sun::rowset::internal::WebRowSetXmlReader),
	$classEntry("com.sun.rowset.internal.WebRowSetXmlWriter", ::com::sun::rowset::internal::WebRowSetXmlWriter),
	$classEntry("com.sun.rowset.internal.XmlErrorHandler", ::com::sun::rowset::internal::XmlErrorHandler),
	$classEntry("com.sun.rowset.internal.XmlReaderContentHandler", ::com::sun::rowset::internal::XmlReaderContentHandler),
	$classEntry("com.sun.rowset.internal.XmlResolver", ::com::sun::rowset::internal::XmlResolver),
	$classEntry("com.sun.rowset.providers.RIOptimisticProvider", ::com::sun::rowset::providers::RIOptimisticProvider),
	$classEntry("com.sun.rowset.providers.RIXMLProvider", ::com::sun::rowset::providers::RIXMLProvider),
	$classEntry("javax.sql.rowset.BaseRowSet", ::javax::sql::rowset::BaseRowSet),
	$classEntry("javax.sql.rowset.CachedRowSet", ::javax::sql::rowset::CachedRowSet),
	$classEntry("javax.sql.rowset.FilteredRowSet", ::javax::sql::rowset::FilteredRowSet),
	$classEntry("javax.sql.rowset.JdbcRowSet", ::javax::sql::rowset::JdbcRowSet),
	$classEntry("javax.sql.rowset.JoinRowSet", ::javax::sql::rowset::JoinRowSet),
	$classEntry("javax.sql.rowset.Joinable", ::javax::sql::rowset::Joinable),
	$classEntry("javax.sql.rowset.Predicate", ::javax::sql::rowset::Predicate),
	$classEntry("javax.sql.rowset.RowSetFactory", ::javax::sql::rowset::RowSetFactory),
	$classEntry("javax.sql.rowset.RowSetMetaDataImpl", ::javax::sql::rowset::RowSetMetaDataImpl),
	$classEntry("javax.sql.rowset.RowSetMetaDataImpl$ColInfo", ::javax::sql::rowset::RowSetMetaDataImpl$ColInfo),
	$classEntry("javax.sql.rowset.RowSetProvider", ::javax::sql::rowset::RowSetProvider),
	$classEntry("javax.sql.rowset.RowSetProvider$1", ::javax::sql::rowset::RowSetProvider$1),
	$classEntry("javax.sql.rowset.RowSetProvider$2", ::javax::sql::rowset::RowSetProvider$2),
	$classEntry("javax.sql.rowset.RowSetWarning", ::javax::sql::rowset::RowSetWarning),
	$classEntry("javax.sql.rowset.WebRowSet", ::javax::sql::rowset::WebRowSet),
	$classEntry("javax.sql.rowset.serial.SQLInputImpl", ::javax::sql::rowset::serial::SQLInputImpl),
	$classEntry("javax.sql.rowset.serial.SQLOutputImpl", ::javax::sql::rowset::serial::SQLOutputImpl),
	$classEntry("javax.sql.rowset.serial.SerialArray", ::javax::sql::rowset::serial::SerialArray),
	$classEntry("javax.sql.rowset.serial.SerialBlob", ::javax::sql::rowset::serial::SerialBlob),
	$classEntry("javax.sql.rowset.serial.SerialClob", ::javax::sql::rowset::serial::SerialClob),
	$classEntry("javax.sql.rowset.serial.SerialDatalink", ::javax::sql::rowset::serial::SerialDatalink),
	$classEntry("javax.sql.rowset.serial.SerialException", ::javax::sql::rowset::serial::SerialException),
	$classEntry("javax.sql.rowset.serial.SerialJavaObject", ::javax::sql::rowset::serial::SerialJavaObject),
	$classEntry("javax.sql.rowset.serial.SerialRef", ::javax::sql::rowset::serial::SerialRef),
	$classEntry("javax.sql.rowset.serial.SerialStruct", ::javax::sql::rowset::serial::SerialStruct),
	$classEntry("javax.sql.rowset.spi.ProviderImpl", ::javax::sql::rowset::spi::ProviderImpl),
	$classEntry("javax.sql.rowset.spi.SyncFactory", ::javax::sql::rowset::spi::SyncFactory),
	$classEntry("javax.sql.rowset.spi.SyncFactory$1", ::javax::sql::rowset::spi::SyncFactory$1),
	$classEntry("javax.sql.rowset.spi.SyncFactory$2", ::javax::sql::rowset::spi::SyncFactory$2),
	$classEntry("javax.sql.rowset.spi.SyncFactory$SyncFactoryHolder", ::javax::sql::rowset::spi::SyncFactory$SyncFactoryHolder),
	$classEntry("javax.sql.rowset.spi.SyncFactoryException", ::javax::sql::rowset::spi::SyncFactoryException),
	$classEntry("javax.sql.rowset.spi.SyncProvider", ::javax::sql::rowset::spi::SyncProvider),
	$classEntry("javax.sql.rowset.spi.SyncProviderException", ::javax::sql::rowset::spi::SyncProviderException),
	$classEntry("javax.sql.rowset.spi.SyncResolver", ::javax::sql::rowset::spi::SyncResolver),
	$classEntry("javax.sql.rowset.spi.TransactionalWriter", ::javax::sql::rowset::spi::TransactionalWriter),
	$classEntry("javax.sql.rowset.spi.XmlReader", ::javax::sql::rowset::spi::XmlReader),
	$classEntry("javax.sql.rowset.spi.XmlWriter", ::javax::sql::rowset::spi::XmlWriter)
};

const char* _java$sql$rowset_packages_[] = {
	"com.sun.rowset",
	"com.sun.rowset.internal",
	"com.sun.rowset.providers",
	"javax.sql.rowset",
	"javax.sql.rowset.serial",
	"javax.sql.rowset.spi"
};

void java$sql$rowset$PreloadClass(void* eventData) {
	::java::lang::PreloadClassEvent* event = (::java::lang::PreloadClassEvent*)eventData;
	int32_t length = $lengthOf(_java$sql$rowset_classes_);
	for (int i = 0; i < length; i++) {
		::java::lang::ClassEntry* classEntry = &_java$sql$rowset_classes_[i];
		if (event->preinit) {
			if ($hasFlag(classEntry->mark, $PREINIT)) {
				classEntry->loader(nullptr, true);
				continue;
			}
		}
		if (event->preload) {
			if ($hasFlag(classEntry->mark, $PRELOAD) || $hasFlag(classEntry->mark, $PREINIT)) {
				classEntry->loader(nullptr, false);
			}
		}
	}
}

void java$sql$rowset$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$sql$rowset$PreloadClass(eventData);
	}
	if (eventType == JCPP_LIB_EVENT_TYPE_THREAD_START) {
		$onLibThreadStart(eventData);
	}
}

$StringArray* java$sql$rowset$GetPackages() {
	int32_t length = $lengthOf(_java$sql$rowset_packages_);
	$var($StringArray, packages, $new($StringArray, length));
	for (int32_t i = 0; i < length; i++) {
		packages->set(i, $str(_java$sql$rowset_packages_[i]));
	}
	return packages;
}

::java::lang::ClassEntry* java$sql$rowset$GetClassEntry($String* name) {
	int32_t begin = 0;
	int32_t end = $lengthOf(_java$sql$rowset_classes_) - 1;
	while (begin <= end) {
		int32_t mid = begin + (end - begin) / 2;
		::java::lang::ClassEntry* classEntry = &_java$sql$rowset_classes_[mid];
		int32_t ret = name->compareTo(classEntry->name);
		if (ret < 0) {
			end = mid - 1;
		} else if (ret > 0) {
			begin = mid + 1;
		} else {
			return classEntry;
		}
	}
	return nullptr;
}

$bytes* java$sql$rowset$GetResource($String* name) {
	return nullptr;
}

void java$sql$rowset::init() {
	::java$logging::init();
	::java$naming::init();
	::java$sql::init();
	::java$base::init();
	::java$security$sasl::init();
	::java$transaction$xa::init();
	::java$xml::init();
	::java::lang::Library lib = {
		"java.sql.rowset", "17.35", "",
		&_java$sql$rowset_ModuleInfo_,
		java$sql$rowset$LibEventAction,
		java$sql$rowset$GetPackages,
		java$sql$rowset$GetClassEntry,
		java$sql$rowset$GetResource
	};
	$System::addLibrary(&lib);
}
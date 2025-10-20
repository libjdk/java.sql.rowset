#include <java.sql.rowset.test.h>

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

void java$sql$rowset$test$PreloadClass(void* eventData) {
}

void java$sql$rowset$test$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$sql$rowset$test$PreloadClass(eventData);
	}
	if (eventType == JCPP_LIB_EVENT_TYPE_THREAD_START) {
		$onLibThreadStart(eventData);
	}
}

$StringArray* java$sql$rowset$test$GetPackages() {
	return nullptr;
}

::java::lang::ClassEntry* java$sql$rowset$test$GetClassEntry($String* name) {
	return nullptr;
}

$bytes* java$sql$rowset$test$GetResource($String* name) {
	return nullptr;
}

void java$sql$rowset$test::init() {
	::java$sql$rowset::init();
	::java$logging::init();
	::java$naming::init();
	::java$sql::init();
	::java$base::init();
	::java$security$sasl::init();
	::java$transaction$xa::init();
	::java$xml::init();
	::java::lang::Library lib = {
		"java.sql.rowset.test", "17.35", "",
		nullptr,
		java$sql$rowset$test$LibEventAction,
		java$sql$rowset$test$GetPackages,
		java$sql$rowset$test$GetClassEntry,
		java$sql$rowset$test$GetResource
	};
	$System::addLibrary(&lib);
	$System::init();
}
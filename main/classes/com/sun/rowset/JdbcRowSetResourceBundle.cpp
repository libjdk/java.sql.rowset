#include <com/sun/rowset/JdbcRowSetResourceBundle.h>

#include <java/lang/Module.h>
#include <java/util/Enumeration.h>
#include <java/util/Locale.h>
#include <java/util/PropertyResourceBundle.h>
#include <java/util/ResourceBundle.h>
#include <jcpp.h>

#undef DOT
#undef PATH
#undef PROPERTIES
#undef SLASH
#undef UNDERSCORE

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $Enumeration = ::java::util::Enumeration;
using $Locale = ::java::util::Locale;
using $PropertyResourceBundle = ::java::util::PropertyResourceBundle;
using $ResourceBundle = ::java::util::ResourceBundle;

namespace com {
	namespace sun {
		namespace rowset {

$FieldInfo _JdbcRowSetResourceBundle_FieldInfo_[] = {
	{"fileName", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(JdbcRowSetResourceBundle, fileName)},
	{"propResBundle", "Ljava/util/PropertyResourceBundle;", nullptr, $PRIVATE | $TRANSIENT, $field(JdbcRowSetResourceBundle, propResBundle)},
	{"jpResBundle", "Lcom/sun/rowset/JdbcRowSetResourceBundle;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(JdbcRowSetResourceBundle, jpResBundle)},
	{"PROPERTIES", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JdbcRowSetResourceBundle, PROPERTIES)},
	{"UNDERSCORE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JdbcRowSetResourceBundle, UNDERSCORE)},
	{"DOT", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JdbcRowSetResourceBundle, DOT)},
	{"SLASH", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JdbcRowSetResourceBundle, SLASH)},
	{"PATH", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(JdbcRowSetResourceBundle, PATH)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(JdbcRowSetResourceBundle, serialVersionUID)},
	{}
};

$MethodInfo _JdbcRowSetResourceBundle_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(JdbcRowSetResourceBundle::*)()>(&JdbcRowSetResourceBundle::init$)), "java.io.IOException"},
	{"getJdbcRowSetResourceBundle", "()Lcom/sun/rowset/JdbcRowSetResourceBundle;", nullptr, $PUBLIC | $STATIC, $method(static_cast<JdbcRowSetResourceBundle*(*)()>(&JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle)), "java.io.IOException"},
	{"getKeys", "()Ljava/util/Enumeration;", nullptr, $PUBLIC},
	{"handleGetObject", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _JdbcRowSetResourceBundle_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.rowset.JdbcRowSetResourceBundle",
	"java.lang.Object",
	"java.io.Serializable",
	_JdbcRowSetResourceBundle_FieldInfo_,
	_JdbcRowSetResourceBundle_MethodInfo_
};

$Object* allocate$JdbcRowSetResourceBundle($Class* clazz) {
	return $of($alloc(JdbcRowSetResourceBundle));
}

$String* JdbcRowSetResourceBundle::fileName = nullptr;
$volatile(JdbcRowSetResourceBundle*) JdbcRowSetResourceBundle::jpResBundle = nullptr;
$String* JdbcRowSetResourceBundle::PROPERTIES = nullptr;
$String* JdbcRowSetResourceBundle::UNDERSCORE = nullptr;
$String* JdbcRowSetResourceBundle::DOT = nullptr;
$String* JdbcRowSetResourceBundle::SLASH = nullptr;
$String* JdbcRowSetResourceBundle::PATH = nullptr;

void JdbcRowSetResourceBundle::init$() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Locale, locale, $Locale::getDefault());
	$set(this, propResBundle, $cast($PropertyResourceBundle, $ResourceBundle::getBundle(JdbcRowSetResourceBundle::PATH, locale, $(JdbcRowSetResourceBundle::class$->getModule()))));
}

JdbcRowSetResourceBundle* JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle() {
	$init(JdbcRowSetResourceBundle);
	if (JdbcRowSetResourceBundle::jpResBundle == nullptr) {
		$synchronized(JdbcRowSetResourceBundle::class$) {
			if (JdbcRowSetResourceBundle::jpResBundle == nullptr) {
				$assignStatic(JdbcRowSetResourceBundle::jpResBundle, $new(JdbcRowSetResourceBundle));
			}
		}
	}
	return JdbcRowSetResourceBundle::jpResBundle;
}

$Enumeration* JdbcRowSetResourceBundle::getKeys() {
	return $nc(this->propResBundle)->getKeys();
}

$Object* JdbcRowSetResourceBundle::handleGetObject($String* key) {
	return $of($nc(this->propResBundle)->handleGetObject(key));
}

JdbcRowSetResourceBundle::JdbcRowSetResourceBundle() {
}

void clinit$JdbcRowSetResourceBundle($Class* class$) {
	$assignStatic(JdbcRowSetResourceBundle::PROPERTIES, "properties"_s);
	$assignStatic(JdbcRowSetResourceBundle::UNDERSCORE, "_"_s);
	$assignStatic(JdbcRowSetResourceBundle::DOT, "."_s);
	$assignStatic(JdbcRowSetResourceBundle::SLASH, "/"_s);
	$assignStatic(JdbcRowSetResourceBundle::PATH, "com/sun/rowset/RowSetResourceBundle"_s);
}

$Class* JdbcRowSetResourceBundle::load$($String* name, bool initialize) {
	$loadClass(JdbcRowSetResourceBundle, name, initialize, &_JdbcRowSetResourceBundle_ClassInfo_, clinit$JdbcRowSetResourceBundle, allocate$JdbcRowSetResourceBundle);
	return class$;
}

$Class* JdbcRowSetResourceBundle::class$ = nullptr;

		} // rowset
	} // sun
} // com